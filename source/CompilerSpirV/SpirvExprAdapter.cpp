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
	ast::expr::ExprPtr ExprAdapter::submit( ast::expr::Expr * expr
		, ast::stmt::Container * container
		, AdaptationData & adaptationData )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ expr->getCache()
			, container
			, adaptationData
			, result };
		expr->accept( &vis );
		return result;
	}

	ExprAdapter::ExprAdapter( ast::type::TypesCache & cache
		, ast::stmt::Container * container
		, AdaptationData & adaptationData
		, ast::expr::ExprPtr & result )
		: ExprCloner{ result }
		, m_cache{ cache }
		, m_container{ container }
		, m_adaptationData{ adaptationData }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ m_cache, m_container, m_adaptationData, result };
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		auto it = m_adaptationData.context.constExprs.find( expr->getVariable()->getId() );

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
			m_result = ExprCloner::submit( expr );
		}
	}

	void ExprAdapter::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		auto outer = expr->getOuterExpr();

		if ( outer->getKind() == ast::expr::Kind::eIdentifier
			&& static_cast< ast::expr::Identifier const & >( *outer ).getVariable() == m_adaptationData.geomOutput )
		{
			assert( m_adaptationData.geomOutputs.size() > expr->getMemberIndex() );
			m_result = ast::expr::makeIdentifier( m_cache
				, m_adaptationData.geomOutputs[expr->getMemberIndex()] );
		}
		else if ( outer->getKind() == ast::expr::Kind::eArrayAccess
			&& static_cast< ast::expr::ArrayAccess const & >( *outer ).getLHS()->getKind() == ast::expr::Kind::eIdentifier
			&& static_cast< ast::expr::Identifier const & >( *static_cast< ast::expr::ArrayAccess const & >( *outer ).getLHS() ).getVariable() == m_adaptationData.geomInput )
		{
			assert( m_adaptationData.geomInputs.size() > expr->getMemberIndex() );
			m_result = ast::expr::makeArrayAccess( expr->getType()
				, ast::expr::makeIdentifier( m_cache, m_adaptationData.geomInputs[expr->getMemberIndex()] )
				, doSubmit( static_cast< ast::expr::ArrayAccess const & >( *outer ).getRHS() ) );
		}
		else
		{
			ExprCloner::visitMbrSelectExpr( expr );
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
			args.emplace_back( submit( arg.get(), m_container, m_adaptationData ) );
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
