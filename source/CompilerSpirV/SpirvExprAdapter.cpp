/*
See LICENSE file in root folder
*/
#include "SpirvExprAdapter.hpp"
#include "SpirvExprEvaluator.hpp"

#include "SpirvGetSwizzleComponents.hpp"
#include "SpirvTextureAccessConfig.hpp"
#include "SpirvTextureAccessNames.hpp"
#include "SpirvMakeAccessChain.hpp"

#include <ShaderAST/Expr/MakeIntrinsic.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <stdexcept>

namespace spirv
{
	namespace
	{
		ast::Builtin getBuiltin( ast::expr::MbrSelect * expr )
		{
			auto mbr = expr->getOuterType()->getMember( expr->getMemberIndex() );
			return mbr.builtin;
		}
	}

	ast::expr::ExprPtr ExprAdapter::submit( ast::expr::Expr * expr
		, ast::stmt::Container * container
		, ast::stmt::Container * ioDeclarations
		, AdaptationData & adaptationData )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ expr->getCache()
			, container
			, ioDeclarations
			, adaptationData
			, result };
		expr->accept( &vis );

		if ( expr->isNonUniform() )
		{
			result->updateFlag( ast::expr::Flag::eNonUniform );
		}

		return result;
	}

	ExprAdapter::ExprAdapter( ast::type::TypesCache & cache
		, ast::stmt::Container * container
		, ast::stmt::Container * ioDeclarations
		, AdaptationData & adaptationData
		, ast::expr::ExprPtr & result )
		: ExprCloner{ result }
		, m_cache{ cache }
		, m_container{ container }
		, m_ioDeclarations{ ioDeclarations }
		, m_adaptationData{ adaptationData }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ m_cache, m_container, m_ioDeclarations, m_adaptationData, result };
		expr->accept( &vis );

		if ( expr->isNonUniform() )
		{
			result->updateFlag( ast::expr::Flag::eNonUniform );
		}

		return result;
	}

	void ExprAdapter::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		auto var = expr->getVariable();
		auto it = m_adaptationData.context.constExprs.find( var->getId() );

		if ( it != m_adaptationData.context.constExprs.end() )
		{
			if ( it->second->getKind() == ast::expr::Kind::eLiteral )
			{
				m_result = getLiteral( expr, m_adaptationData.context );
			}
			else
			{
				m_result = ExprCloner::submit( it->second );
			}
		}
		else
		{
			if ( var->isShaderOutput()
				&& var->isBuiltin() )
			{
				auto & cache = var->getType()->getCache();

				if ( var->getName() == "gl_TessLevelOuter" )
				{
					var->updateType( cache.getArray( getNonArrayType( var->getType() ), 4u ) );
				}
				else if ( var->getName() == "gl_TessLevelInner" )
				{
					var->updateType( cache.getArray( getNonArrayType( var->getType() ), 2u ) );
				}
			}

			m_result = m_adaptationData.config.processPending( expr->getVariable()
				, m_ioDeclarations );

			if ( !m_result )
			{
				m_result = ExprCloner::submit( expr );
			}
		}
	}

	void ExprAdapter::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		if ( expr->getIntrinsic() == ast::expr::Intrinsic::eTraceRay )
		{
			auto payLoad = std::move( args.back() );
			args.pop_back();
			auto rayDesc = std::move( args.back() );
			args.pop_back();
			// Replace RayDesc parameter with its four members
			assert( rayDesc->getType()->getRawKind() == ast::type::Kind::eRayDesc );
			uint32_t index = 0u;
			for ( auto mbr : *getStructType( rayDesc->getType() ) )
			{
				args.push_back( ast::expr::makeMbrSelect( ExprCloner::submit( rayDesc ), index++, 0u ) );
			}
			// Extract location from RayPayload type, to set it as last param.
			args.push_back( ast::expr::makeLiteral( m_cache
				, int( static_cast< ast::type::RayPayload const & >( *payLoad->getType() ).getLocation() ) ) );
		}

		m_result = ast::expr::makeIntrinsicCall( expr->getType()
			, expr->getIntrinsic()
			, std::move( args ) );
	}

	void ExprAdapter::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		m_result = m_adaptationData.config.processPendingMbr( expr->getOuterExpr()
			, expr->getMemberIndex()
			, *expr
			, *this
			, m_ioDeclarations );

		if ( !m_result )
		{
			m_result = ast::expr::makeMbrSelect( doSubmit( expr->getOuterExpr() )
				, expr->getMemberIndex()
				, expr->getMemberFlags() );
		}
		else
		{
			auto arraySize = getArraySize( m_result->getType() );

			if ( arraySize != ast::type::NotArray
				&& arraySize != getArraySize( expr->getType() )
				&& expr->isShaderOutput()
				&& ( !expr->isBuiltin()
					|| isPerVertex( getBuiltin( expr ), m_adaptationData.config.stage ) ) )
			{
				auto type = m_result->getType();
				assert( type->getKind() == ast::type::Kind::eArray );
				m_result = ast::expr::makeArrayAccess( static_cast< ast::type::Array const & >( *type ).getType()
					, std::move( m_result )
					, m_adaptationData.config.processPending( ast::Builtin::eInvocationID
						, *this
						, m_ioDeclarations ) );
			}
		}
	}

	void ExprAdapter::visitStreamAppendExpr( ast::expr::StreamAppend * expr )
	{
		m_result = ast::expr::makeEmitVertex( m_cache );
	}

	void ExprAdapter::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		auto kind = expr->getTextureAccess();
		IntrinsicConfig config;
		getSpirVConfig( kind, config );
		auto returnType = expr->getType();

		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		if ( getBias( kind ) == spv::ImageOperandsBiasMask )
		{
			// Bias is the last parameter in GLSL, but it has to be the first one after the ImageOperands in SPIR-V.
			if ( args.size() > config.imageOperandsIndex + 1u )
			{
				auto biasArg = std::move( args.back() );
				args.pop_back();
				args.emplace( args.begin() + config.imageOperandsIndex, std::move( biasArg ) );
			}
		}

#if !defined( NDEBUG )
		for ( auto & arg : args )
		{
			assert( arg != nullptr );
		}
#endif

		m_result = ast::expr::makeTextureAccessCall( returnType
			, kind
			, std::move( args ) );
	}
}
