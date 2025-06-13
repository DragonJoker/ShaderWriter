/*
See LICENSE file in root folder
*/
#include "SpirVExprAdapter.hpp"

#include "SpirVGetSwizzleComponents.hpp"
#include "SpirVCombinedImageAccessConfig.hpp"
#include "SpirVCombinedImageAccessNames.hpp"
#include "SpirVMakeAccessChain.hpp"

#include <ShaderAST/ShaderLog.hpp>
#include <ShaderAST/Expr/MakeIntrinsic.hpp>
#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>

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

		static bool isMemoryLayoutDependent( ast::type::TypePtr type )
		{
			return getStructType( type )
				|| isArrayType( type )
				|| isMatrixType( type );
		}

		static ast::var::VariablePtr makeFunctionAlias( AdaptationData & adaptationData
			, ast::type::TypePtr type )
		{
			TraceFunc;
			auto result = ast::var::makeVariable( adaptationData.config.nextVarId
				, type
				, "functmp_" + std::to_string( adaptationData.config.aliasId ) );
			++adaptationData.config.aliasId;
			return result;
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

	void ExprAdapter::visitAliasExpr( ast::expr::Alias const * expr )
	{
		if ( isExplicitLayoutNeeded( m_adaptationData.config.getSpirVVersion(), *expr->getAliasedExpr() )
			&& adapt::isMemoryLayoutDependent( expr->getType() ) )
		{
			auto ident = &expr->getIdentifier();
			auto type = expr->getType();

			if ( m_adaptationData.config.getSpirVVersion() >= v1_4 )
			{
				m_result = m_exprCache.makeAlias( expr->getType()
					, m_exprCache.makeIdentifier( *ident )
					, m_exprCache.makeCast( expr->getType(), ast::ExprCloner::submit( m_exprCache, expr->getAliasedExpr() ) ) );
			}
			else
			{
				ast::expr::ExprList inits;

				if ( auto structType = getStructType( expr->getType() ) )
				{
					for ( uint32_t index = 0u; index < structType->size(); ++index )
					{
						inits.emplace_back( m_exprCache.makeMbrSelect( ast::ExprCloner::submit( m_exprCache, expr->getAliasedExpr() )
							, index, 0 ) );
					}
				}
				else if ( isArrayType( expr->getType() ) )
				{
					if ( auto arrayType = &static_cast< ast::type::Array const & >( *expr->getType() );
						arrayType->getArraySize() == ast::type::UnknownArraySize )
					{
						ast::Logger::logError( "Unsupported dynamic array conversion" );
						ExprCloner::visitAliasExpr( expr );
					}
					else
					{
						auto elementType = arrayType->getType();
						for ( uint32_t index = 0u; index < arrayType->getArraySize(); ++index )
						{
							inits.emplace_back( ast::resolveConstants( m_exprCache, *m_exprCache.makeArrayAccess( elementType
								, ast::ExprCloner::submit( m_exprCache, expr->getAliasedExpr() )
								, m_exprCache.makeLiteral( m_typesCache, index ) ) ) );
						}
					}
				}
				else if ( isMatrixType( expr->getType() ) )
				{
					auto columnCount = getComponentCount( expr->getType() );
					auto componentType = m_typesCache.getBasicType( getComponentType( expr->getType() ) );
					for ( uint32_t index = 0u; index < columnCount; ++index )
					{
						inits.emplace_back( ast::resolveConstants( m_exprCache, *m_exprCache.makeArrayAccess( componentType
							, ast::ExprCloner::submit( m_exprCache, expr->getAliasedExpr() )
							, m_exprCache.makeLiteral( m_typesCache, index ) ) ) );
					}
				}
				else
				{
					ast::Logger::logError( "Unsupported memory layout dependent type" );
					AST_Failure( "Unsupported memory layout dependent type" );
					ExprCloner::visitAliasExpr( expr );
				}

				if ( !inits.empty() )
				{
					m_result = m_exprCache.makeInit( m_exprCache.makeIdentifier( *ident )
						, m_exprCache.makeAggrInit( expr->getType(), std::move( inits ) ) );
				}
			}
		}
		else
		{
			ExprCloner::visitAliasExpr( expr );
		}
	}

	void ExprAdapter::visitAssignExpr( ast::expr::Assign const * expr )
	{
		TraceFunc;
		auto lhs = expr->getLHS();
		auto rhs = expr->getRHS();
		auto type = expr->getType();

		if ( adapt::isMemoryLayoutDependent( type )
			&& isExplicitLayoutNeeded( m_adaptationData.config.getSpirVVersion(), *lhs )
				!= isExplicitLayoutNeeded( m_adaptationData.config.getSpirVVersion(), *rhs ) )
		{
			auto & stmtCache = m_container->getStmtCache();

			if ( auto structType = getStructType( type ) )
			{
				for ( uint32_t index = 0u; index < structType->size() - 1u; ++index )
				{
					auto mbr = structType->getMember( index );
					m_container->addStmt( stmtCache.makeSimple( m_exprCache.makeAssign( mbr.type
						, m_exprCache.makeMbrSelect( ast::ExprCloner::submit( m_exprCache, lhs ), index, 0 )
						, m_exprCache.makeMbrSelect( ast::ExprCloner::submit( m_exprCache, rhs ), index, 0 ) ) ) );
				}

				auto index = uint32_t( structType->size() - 1u );
				auto mbr = structType->getMember( index );
				m_result = m_exprCache.makeAssign( mbr.type
					, m_exprCache.makeMbrSelect( ast::ExprCloner::submit( m_exprCache, lhs ), index, 0 )
					, m_exprCache.makeMbrSelect( ast::ExprCloner::submit( m_exprCache, rhs ), index, 0 ) );
			}
			else if ( isArrayType( type ) )
			{
				if ( auto arrayType = &static_cast< ast::type::Array const & >( *type );
					arrayType->getArraySize() == ast::type::UnknownArraySize )
				{
					ast::Logger::logError( "Unsupported dynamic array conversion" );
					ExprCloner::visitAssignExpr( expr );
				}
				else
				{
					auto elementType = arrayType->getType();
					for ( uint32_t index = 0u; index < arrayType->getArraySize() - 1u; ++index )
					{
						m_container->addStmt( stmtCache.makeSimple( m_exprCache.makeAssign( elementType
							, ast::resolveConstants( m_exprCache, *m_exprCache.makeArrayAccess( elementType, ast::ExprCloner::submit( m_exprCache, lhs ), m_exprCache.makeLiteral( m_typesCache, index ) ) )
							, ast::resolveConstants( m_exprCache, *m_exprCache.makeArrayAccess( elementType, ast::ExprCloner::submit( m_exprCache, rhs ), m_exprCache.makeLiteral( m_typesCache, index ) ) ) ) ) );
					}

					m_result = m_exprCache.makeAssign( elementType
						, ast::resolveConstants( m_exprCache, *m_exprCache.makeArrayAccess( elementType, ast::ExprCloner::submit( m_exprCache, lhs ), m_exprCache.makeLiteral( m_typesCache, arrayType->getArraySize() - 1u ) ) )
						, ast::resolveConstants( m_exprCache, *m_exprCache.makeArrayAccess( elementType, ast::ExprCloner::submit( m_exprCache, rhs ), m_exprCache.makeLiteral( m_typesCache, arrayType->getArraySize() - 1u ) ) ) );
				}
			}
			else if ( isMatrixType( type ) )
			{
				auto columnCount = getComponentCount( type );
				auto componentType = m_typesCache.getBasicType( getComponentType( type ) );
				for ( uint32_t index = 0u; index < columnCount - 1u; ++index )
				{
					m_container->addStmt( stmtCache.makeSimple( m_exprCache.makeAssign( componentType
						, ast::resolveConstants( m_exprCache, *m_exprCache.makeArrayAccess( componentType, ast::ExprCloner::submit( m_exprCache, lhs ), m_exprCache.makeLiteral( m_typesCache, index ) ) )
						, ast::resolveConstants( m_exprCache, *m_exprCache.makeArrayAccess( componentType, ast::ExprCloner::submit( m_exprCache, rhs ), m_exprCache.makeLiteral( m_typesCache, index ) ) ) ) ) );
				}

				m_result = m_exprCache.makeAssign( componentType
					, ast::resolveConstants( m_exprCache, *m_exprCache.makeArrayAccess( componentType, ast::ExprCloner::submit( m_exprCache, lhs ), m_exprCache.makeLiteral( m_typesCache, columnCount - 1u ) ) )
					, ast::resolveConstants( m_exprCache, *m_exprCache.makeArrayAccess( componentType, ast::ExprCloner::submit( m_exprCache, rhs ), m_exprCache.makeLiteral( m_typesCache, columnCount - 1u ) ) ) );
			}
			else
			{
				ast::Logger::logError( "Unsupported memory layout dependent type" );
				AST_Failure( "Unsupported memory layout dependent type" );
				ExprCloner::visitAssignExpr( expr );
			}
		}

		if ( !m_result
			&& lhs->getKind() == ast::expr::Kind::eMbrSelect )
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
					AST_Assert( builtinExpr );

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
							, doSubmit( rhs ) );
					}
					else
					{
						m_result = m_exprCache.makeArrayAccess( m_typesCache.getUInt32()
							, ExprCloner::submit( m_exprCache, *builtinExpr )
							, ExprCloner::submit( m_exprCache, *baseIndex ) );
						m_result = m_exprCache.makeAssign( mbr.type
							, std::move( m_result )
							, m_exprCache.makeSwizzle( doSubmit( rhs )
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
								, m_exprCache.makeSwizzle( doSubmit( rhs )
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
								, m_exprCache.makeSwizzle( doSubmit( rhs )
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
			var->isPatchOutput() && var->isBuiltin() )
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
				AST_Assert( rayDesc->getType()->getRawKind() == ast::type::Kind::eRayDesc );
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
				&& expr->isOutput()
				&& ( !expr->isBuiltin()
					|| isPerVertex( adapt::getBuiltin( *expr ), m_adaptationData.config.stage ) ) )
			{
				auto type = m_result->getType();
				AST_Assert( type->getKind() == ast::type::Kind::eArray );
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
			AST_Assert( arg != nullptr );
		}
#endif

		m_result = m_exprCache.makeCombinedImageAccessCall( returnType
			, kind
			, std::move( args ) );
	}
}
