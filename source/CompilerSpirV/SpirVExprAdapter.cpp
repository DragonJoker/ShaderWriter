/*
See LICENSE file in root folder
*/
#include "SpirVExprAdapter.hpp"

#include "SpirVGetSwizzleComponents.hpp"
#include "SpirVCombinedImageAccessConfig.hpp"
#include "SpirVCombinedImageAccessNames.hpp"
#include "SpirVMakeAccessChain.hpp"

#include <ShaderAST/Expr/MakeIntrinsic.hpp>
#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <stdexcept>

namespace spirv
{
	namespace adapt
	{
		static ast::Builtin getBuiltin( ast::expr::MbrSelect const & expr )
		{
			auto mbr = expr.getOuterType()->getMember( expr.getMemberIndex() );
			return mbr.builtin;
		}
	}

	ast::expr::ExprPtr ExprAdapter::submit( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::expr::Expr const & expr
		, ast::stmt::Container * container
		, ast::stmt::Container * ioDeclarations
		, AdaptationData & adaptationData )
	{
		ast::expr::ExprPtr result{};
		ExprAdapter vis{ exprCache
			, typesCache
			, container
			, ioDeclarations
			, adaptationData
			, result };
		expr.accept( &vis );

		if ( expr.isNonUniform() )
		{
			result->updateFlag( ast::expr::Flag::eNonUniform );
		}

		return result;
	}

	ExprAdapter::ExprAdapter( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::stmt::Container * container
		, ast::stmt::Container * ioDeclarations
		, AdaptationData & adaptationData
		, ast::expr::ExprPtr & result )
		: ExprCloner{ exprCache, result }
		, m_typesCache{ typesCache }
		, m_container{ container }
		, m_ioDeclarations{ ioDeclarations }
		, m_adaptationData{ adaptationData }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr const & expr )
	{
		return submit( m_exprCache, m_typesCache, expr, m_container, m_ioDeclarations, m_adaptationData );
	}

	void ExprAdapter::visitAssignExpr( ast::expr::Assign const * expr )
	{
		TraceFunc;

		if ( auto lhs = expr->getLHS();
			lhs->getKind() == ast::expr::Kind::eMbrSelect )
		{
			auto & mbrSelect = static_cast< ast::expr::MbrSelect const & >( *lhs );

			if ( auto outer = mbrSelect.getOuterExpr();
				outer->getKind() == ast::expr::Kind::eArrayAccess )
			{
				auto structType = mbrSelect.getOuterType();
				auto mbr = structType->getMember( mbrSelect.getMemberIndex() );

				if ( mbr.builtin == ast::Builtin::ePrimitiveIndicesNV )
				{
					auto builtinExpr = m_adaptationData.config.processPending( m_exprCache, mbr.builtin, m_container );
					assert( builtinExpr );

					// Compute base index, based on declared type of builtin
					auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( *outer );
					auto index = arrayAccess.getRHS();
					ast::expr::ExprPtr multiplier{};

					switch ( mbr.type->getKind() )
					{
					case ast::type::Kind::eUInt32:
						break;
					case ast::type::Kind::eVec2U32:
						multiplier = m_exprCache.makeLiteral( m_typesCache, 2u );
						break;
					case ast::type::Kind::eVec3U32:
						multiplier = m_exprCache.makeLiteral( m_typesCache, 3u );
						break;
					default:
						AST_Failure( "Unsupported type for gl_PrimitiveIndicesNV" );
						break;
					}

					auto baseIndex = doSubmit( index );

					if ( multiplier )
					{
						baseIndex = m_exprCache.makeTimes( m_typesCache.getUInt32()
							, doSubmit( index )
							, std::move( multiplier ) );
					}

					auto componentCount = getComponentCount( mbr.type );

					if ( componentCount == 1u )
					{
						m_result = m_exprCache.makeArrayAccess( m_typesCache.getUInt32()
							, ExprCloner::submit( m_exprCache, *builtinExpr )
							, std::move( baseIndex ) );
						m_result = m_exprCache.makeAssign( mbr.type
							, std::move( m_result )
							, doSubmit( expr->getRHS() ) );
					}
					else
					{
						m_result = m_exprCache.makeArrayAccess( m_typesCache.getUInt32()
							, ExprCloner::submit( m_exprCache, *builtinExpr )
							, ExprCloner::submit( m_exprCache, *baseIndex ) );
						m_result = m_exprCache.makeAssign( mbr.type
							, std::move( m_result )
							, m_exprCache.makeSwizzle( doSubmit( expr->getRHS() )
								, ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e0 } ) );

						if ( componentCount >= 2u )
						{
							m_container->addStmt( m_container->getStmtCache().makeSimple( std::move( m_result ) ) );
							m_result = m_exprCache.makeArrayAccess( m_typesCache.getUInt32()
								, ExprCloner::submit( m_exprCache, *builtinExpr )
								, m_exprCache.makeAdd( m_typesCache.getUInt32()
									, ExprCloner::submit( m_exprCache, *baseIndex )
									, m_exprCache.makeLiteral( m_typesCache, 1u ) ) );
							m_result = m_exprCache.makeAssign( mbr.type
								, std::move( m_result )
								, m_exprCache.makeSwizzle( doSubmit( expr->getRHS() )
									, ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e1 } ) );
						}

						if ( componentCount >= 3u )
						{
							m_container->addStmt( m_container->getStmtCache().makeSimple( std::move( m_result ) ) );
							m_result = m_exprCache.makeArrayAccess( m_typesCache.getUInt32()
								, ExprCloner::submit( m_exprCache, *builtinExpr )
								, m_exprCache.makeAdd( m_typesCache.getUInt32()
									, ExprCloner::submit( m_exprCache, *baseIndex )
									, m_exprCache.makeLiteral( m_typesCache, 2u ) ) );
							m_result = m_exprCache.makeAssign( mbr.type
								, std::move( m_result )
								, m_exprCache.makeSwizzle( doSubmit( expr->getRHS() )
									, ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e2 } ) );
						}
					}
				}
			}
		}

		if ( !m_result )
		{
			ExprCloner::visitAssignExpr( expr );
		}
	}

	void ExprAdapter::visitFnCallExpr( ast::expr::FnCall const * expr )
	{
		auto funcVar = expr->getFn()->getVariable();

		if ( auto it = m_adaptationData.funcVarReplacements.find( funcVar->getId() );
			it != m_adaptationData.funcVarReplacements.end() )
		{
			funcVar = it->second;
		}

		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( *arg ) );
		}

		if ( expr->isMember() )
		{
			m_result = m_exprCache.makeMemberFnCall( expr->getType()
				, m_exprCache.makeIdentifier( m_typesCache, funcVar )
				, doSubmit( expr->getInstance() )
				, std::move( args ) );
		}
		else
		{
			m_result = m_exprCache.makeFnCall( expr->getType()
				, m_exprCache.makeIdentifier( m_typesCache, funcVar )
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitIdentifierExpr( ast::expr::Identifier const * expr )
	{
		TraceFunc;

		if ( auto var = expr->getVariable();
			var->isShaderOutput() && var->isBuiltin() )
		{
			auto & typesCache = var->getType()->getTypesCache();

			if ( var->getName() == "gl_TessLevelOuter" )
			{
				var->updateType( typesCache.getArray( getNonArrayType( var->getType() ), 4u ) );
			}
			else if ( var->getName() == "gl_TessLevelInner" )
			{
				var->updateType( typesCache.getArray( getNonArrayType( var->getType() ), 2u ) );
			}
		}

		m_result = m_adaptationData.config.processPending( m_exprCache
			, expr->getVariable()
			, m_ioDeclarations );

		if ( !m_result )
		{
			m_result = ExprCloner::submit( m_exprCache, expr );
		}
	}

	void ExprAdapter::visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )
	{
		TraceFunc;
		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( *arg ) );
		}

		if ( expr->getIntrinsic() == ast::expr::Intrinsic::eSetMeshOutputCountsNV )
		{
			auto numPrimitives = std::move( args.back() );
			args.pop_back();
			args.pop_back();
			auto type = numPrimitives->getType();
			++m_adaptationData.config.nextVarId;
			auto var = ast::var::makeBuiltin( m_adaptationData.config.nextVarId
				, ast::Builtin::ePrimitiveCountNV
				, type
				, ast::var::Flag::eShaderOutput );
			auto ident = m_exprCache.makeIdentifier( m_typesCache, var );
			m_adaptationData.config.addPendingOutput( var, ast::type::Struct::InvalidLocation );
			m_result = m_exprCache.makeAssign( type
				, doSubmit( ident.get() )
				, std::move( numPrimitives ) );
		}
		else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eDispatchMeshNV )
		{
			auto numTasks = std::move( args.back() );
			args.pop_back();
			auto type = numTasks->getType();
			++m_adaptationData.config.nextVarId;
			auto var = ast::var::makeBuiltin( m_adaptationData.config.nextVarId
				, ast::Builtin::eTaskCountNV
				, type
				, ast::var::Flag::eShaderOutput );
			auto ident = m_exprCache.makeIdentifier( m_typesCache, var );
			m_adaptationData.config.addPendingOutput( var, ast::type::Struct::InvalidLocation );
			m_result = m_exprCache.makeAssign( type
				, doSubmit( ident.get() )
				, std::move( numTasks ) );
		}
		else
		{
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
					args.push_back( m_exprCache.makeMbrSelect( ExprCloner::submit( m_exprCache, *rayDesc ), index, 0u ) );
					++index;
				}
				// Move the RayPayload back to last parameter.
				args.push_back( std::move( payLoad ) );
			}
			else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eReportIntersection )
			{
				// Remove unused HitAttribute last param.
				args.pop_back();
			}

			m_result = m_exprCache.makeIntrinsicCall( expr->getType()
				, expr->getIntrinsic()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitMbrSelectExpr( ast::expr::MbrSelect const * expr )
	{
		TraceFunc;
		m_result = m_adaptationData.config.processPendingMbr( m_exprCache
			, *expr->getOuterExpr()
			, expr->getMemberIndex()
			, *expr
			, *this
			, m_ioDeclarations );

		if ( !m_result )
		{
			m_result = m_exprCache.makeMbrSelect( doSubmit( expr->getOuterExpr() )
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
					|| isPerVertex( adapt::getBuiltin( *expr ), m_adaptationData.config.stage ) ) )
			{
				auto type = m_result->getType();
				assert( type->getKind() == ast::type::Kind::eArray );
				m_result = m_exprCache.makeArrayAccess( static_cast< ast::type::Array const & >( *type ).getType()
					, std::move( m_result )
					, m_adaptationData.config.processPending( m_exprCache
						, ast::Builtin::eInvocationID
						, m_ioDeclarations ) );
			}
		}
	}

	void ExprAdapter::visitStreamAppendExpr( ast::expr::StreamAppend const * expr )
	{
		TraceFunc;
		m_result = makeEmitVertex( m_exprCache, m_typesCache );
	}

	void ExprAdapter::visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )
	{
		TraceFunc;
		auto kind = expr->getCombinedImageAccess();
		IntrinsicConfig config;
		getSpirVConfig( kind, config );
		auto returnType = expr->getType();

		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( *arg ) );
		}

		if ( getBias( kind ) == spv::ImageOperandsBiasMask
			&& args.size() > config.imageOperandsIndex + 1ULL )
		{
			// Bias is the last parameter in GLSL, but it has to be the first one after the ImageOperands in SPIR-V.
			auto biasArg = std::move( args.back() );
			args.pop_back();
			args.emplace( args.begin() + config.imageOperandsIndex, std::move( biasArg ) );
		}

#if !defined( NDEBUG )
		for ( auto const & arg : args )
		{
			assert( arg != nullptr );
		}
#endif

		m_result = m_exprCache.makeCombinedImageAccessCall( returnType
			, kind
			, std::move( args ) );
	}
}
