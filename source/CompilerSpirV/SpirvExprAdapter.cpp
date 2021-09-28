/*
See LICENSE file in root folder
*/
#include "SpirvExprAdapter.hpp"
#include "SpirvExprEvaluator.hpp"

#include "SpirvGetSwizzleComponents.hpp"
#include "SpirvTextureAccessConfig.hpp"
#include "SpirvTextureAccessNames.hpp"
#include "SpirvMakeAccessChain.hpp"

#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <stdexcept>

namespace spirv
{
	//*************************************************************************

	namespace
	{
		ast::expr::CompositeType getCompositeType( uint32_t count )
		{
			using ast::expr::CompositeType;
			CompositeType result = CompositeType::eScalar;

			switch ( count )
			{
			case 2:
				result = CompositeType::eVec2;
				break;
			case 3:
				result = CompositeType::eVec3;
				break;
			case 4:
				result = CompositeType::eVec4;
				break;
			}

			return result;
		}

		bool needsAlias( ast::expr::Kind kind
			, bool uniform
			, bool param )
		{
			using ast::expr::Kind;
			return ( uniform || kind != Kind::eIdentifier )
				&& ( param || kind != Kind::eMbrSelect )
				&& ( param || kind != Kind::eLiteral )
				&& ( param || kind != Kind::eSwizzle );
		}

		bool isShaderVariable( ast::expr::Expr const & expr )
		{
			return expr.getKind() == ast::expr::Kind::eIdentifier
				&& ( static_cast< ast::expr::Identifier const & >( expr ).getVariable()->isUniform()
				|| static_cast< ast::expr::Identifier const & >( expr ).getVariable()->isShaderInput()
				|| static_cast< ast::expr::Identifier const & >( expr ).getVariable()->isShaderOutput() );
		}

		ast::type::TypePtr getExpectedReturnType( ast::expr::ImageAccessCall * expr )
		{
			auto result = expr->getType();

			if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageLoad1DF
				&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageLoad2DMSArrayU )
			{
				auto scalar = ast::type::getScalarType( result->getKind() );
				auto components = ast::type::getComponentCount( result );

				if ( components != 4u )
				{
					result = result->getCache().getVec4Type( scalar );
				}
			}

			return result;
		}
	}

	//*************************************************************************

	ast::expr::ExprPtr ExprAdapter::submit( ast::expr::Expr * expr
		, ast::stmt::Container * container
		, PreprocContext const & context
		, ModuleConfig const & config )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis
		{
			expr->getCache(),
			container,
			context,
			config,
			result
		};
		expr->accept( &vis );
		return result;
	}

	ExprAdapter::ExprAdapter( ast::type::TypesCache & cache
		, ast::stmt::Container * container
		, PreprocContext const & context
		, ModuleConfig const & config
		, ast::expr::ExprPtr & result )
		: ExprCloner{ result }
		, m_cache{ cache }
		, m_container{ container }
		, m_context{ context }
		, m_config{ config }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ m_cache, m_container, m_context, m_config, result };
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitAddAssignExpr( ast::expr::AddAssign * expr )
	{
		m_result = doWriteBinaryOperation( ast::expr::Kind::eAdd
			, expr->getType()
			, expr->getLHS()
			, expr->getRHS() );
		m_result = ast::expr::makeAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, std::move( m_result ) );
	}

	void ExprAdapter::visitAddExpr( ast::expr::Add * expr )
	{
		m_result = doWriteBinaryOperation( ast::expr::Kind::eAdd
			, expr->getType()
			, expr->getLHS()
			, expr->getRHS() );
	}

	void ExprAdapter::visitDivideAssignExpr( ast::expr::DivideAssign * expr )
	{
		m_result = doWriteBinaryOperation( ast::expr::Kind::eDivide
			, expr->getType()
			, expr->getLHS()
			, expr->getRHS() );
		m_result = ast::expr::makeAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, std::move( m_result ) );
	}

	void ExprAdapter::visitDivideExpr( ast::expr::Divide * expr )
	{
		m_result = doWriteBinaryOperation( ast::expr::Kind::eDivide
			, expr->getType()
			, expr->getLHS()
			, expr->getRHS() );
	}

	void ExprAdapter::visitMinusAssignExpr( ast::expr::MinusAssign * expr )
	{
		m_result = doWriteBinaryOperation( ast::expr::Kind::eMinus
			, expr->getType()
			, expr->getLHS()
			, expr->getRHS() );
		m_result = ast::expr::makeAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, std::move( m_result ) );
	}

	void ExprAdapter::visitMinusExpr( ast::expr::Minus * expr )
	{
		m_result = doWriteBinaryOperation( ast::expr::Kind::eMinus
			, expr->getType()
			, expr->getLHS()
			, expr->getRHS() );
	}

	void ExprAdapter::visitTimesAssignExpr( ast::expr::TimesAssign * expr )
	{
		m_result = doWriteBinaryOperation( ast::expr::Kind::eTimes
			, expr->getType()
			, expr->getLHS()
			, expr->getRHS() );
		m_result = ast::expr::makeAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, std::move( m_result ) );
	}

	void ExprAdapter::visitTimesExpr( ast::expr::Times * expr )
	{
		m_result = doWriteBinaryOperation( ast::expr::Kind::eTimes
			, expr->getType()
			, expr->getLHS()
			, expr->getRHS() );
	}

	void ExprAdapter::visitCastExpr( ast::expr::Cast * expr )
	{
		auto dstScalarType = getScalarType( expr->getType()->getKind() );
		auto srcScalarType = getScalarType( expr->getOperand()->getType()->getKind() );
#if !defined( NDEBUG )
		auto dstComponents = getComponentCount( expr->getType()->getKind() );
		auto srcComponents = getComponentCount( expr->getOperand()->getType()->getKind() );
#endif

		if ( dstScalarType == ast::type::Kind::eBoolean
			&& srcScalarType != ast::type::Kind::eBoolean )
		{
			// Conversion to bool scalar or vector type.
			assert( dstComponents == srcComponents );
			m_result = makeToBoolCast( m_cache
				, doSubmit( expr->getOperand() ) );
		}
		else if ( srcScalarType == ast::type::Kind::eBoolean
			&& dstScalarType != ast::type::Kind::eBoolean )
		{
			// Conversion from bool scalar or vector type.
			assert( dstComponents == srcComponents );
			m_result = makeFromBoolCast( m_cache
				, doSubmit( expr->getOperand() )
				, dstScalarType );
		}
		else
		{
			ExprCloner::visitCastExpr( expr );
		}
	}

	void ExprAdapter::visitPreDecrementExpr( ast::expr::PreDecrement * expr )
	{
		auto newOp = doSubmit( expr->getOperand() );
		auto subExpr = doWriteBinaryOperation( ast::expr::Kind::eMinus
			, expr->getType()
			, newOp.get()
			, makeOne( m_cache, expr->getType()->getKind() ).get() );
		auto assignExpr = ast::expr::makeAssign( expr->getType()
			, ExprCloner::submit( newOp )
			, std::move( subExpr ) );
		m_result = ast::expr::makeComma( std::move( assignExpr )
			, std::move( newOp ) );
		m_result->updateFlag( ast::expr::Flag::eImplicit
			, true );
	}

	void ExprAdapter::visitPreIncrementExpr( ast::expr::PreIncrement * expr )
	{
		auto newOp = doSubmit( expr->getOperand() );
		auto addExpr = doWriteBinaryOperation( ast::expr::Kind::eAdd
			, expr->getType()
			, newOp.get()
			, makeOne( m_cache, expr->getType()->getKind() ).get() );
		auto assignExpr = ast::expr::makeAssign( expr->getType()
			, ExprCloner::submit( newOp )
			, std::move( addExpr ) );
		m_result = ast::expr::makeComma( std::move( assignExpr )
			, std::move( newOp ) );
		m_result->updateFlag( ast::expr::Flag::eImplicit
			, true );
	}

	void ExprAdapter::visitPostDecrementExpr( ast::expr::PostDecrement * expr )
	{
		auto aliasVar = createTmpVar( expr->getType()
			, m_config.aliasId );
		auto aliasExpr = ast::expr::makeAssign( expr->getType()
			, ast::expr::makeIdentifier( m_cache, aliasVar )
			, doSubmit( expr->getOperand() ) );
		auto subExpr = doWriteBinaryOperation( ast::expr::Kind::eMinus
			, expr->getType()
			, expr->getOperand()
			, makeOne( m_cache, expr->getType()->getKind() ).get() );
		auto assignExpr = ast::expr::makeAssign( expr->getType()
			, doSubmit( expr->getOperand() )
			, std::move( subExpr ) );
		auto lhs = ast::expr::makeComma( std::move( aliasExpr )
			, std::move( assignExpr ) );
		lhs->updateFlag( ast::expr::Flag::eImplicit
			, true );
		m_result = ast::expr::makeComma( std::move( lhs )
			, ast::expr::makeIdentifier( m_cache, aliasVar ) );
		m_result->updateFlag( ast::expr::Flag::eImplicit
			, true );
	}

	void ExprAdapter::visitPostIncrementExpr( ast::expr::PostIncrement * expr )
	{
		auto aliasVar = createTmpVar( expr->getType()
			, m_config.aliasId );
		auto aliasExpr = ast::expr::makeAssign( expr->getType()
			, ast::expr::makeIdentifier( m_cache, aliasVar )
			, doSubmit( expr->getOperand() ) );
		auto addExpr = doWriteBinaryOperation( ast::expr::Kind::eAdd
			, expr->getType()
			, expr->getOperand()
			, makeOne( m_cache, expr->getType()->getKind() ).get() );
		auto assignExpr = ast::expr::makeAssign( expr->getType()
			, doSubmit( expr->getOperand() )
			, std::move( addExpr ) );
		auto lhs = ast::expr::makeComma( std::move( aliasExpr )
			, std::move( assignExpr ) );
		lhs->updateFlag( ast::expr::Flag::eImplicit
			, true );
		m_result = ast::expr::makeComma( std::move( lhs )
			, ast::expr::makeIdentifier( m_cache, aliasVar ) );
		m_result->updateFlag( ast::expr::Flag::eImplicit
			, true );
	}

	void ExprAdapter::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		ast::expr::ExprList args;

		if ( expr->getArgList().size() == 1u
			&& !isScalarType( expr->getArgList().front()->getType()->getKind() ) )
		{
			auto & arg = *expr->getArgList().front();
			auto argType = arg.getType();
			ast::var::VariablePtr alias;
			ast::expr::ExprPtr argAlias = doMakeAlias( doSubmit( &arg ), false, alias );

			if ( isVectorType( argType->getKind() ) )
			{
				doConstructVector( expr
					, argAlias
					, expr->getType()->getKind()
					, args );
			}
			else if ( isMatrixType( argType->getKind() ) )
			{
				doConstructMatrix( expr
					, argAlias
					, expr->getType()->getKind()
					, args );
			}
			else
			{
				// TODO: Struct or array.
			}
		}
		else
		{
			doConstructOther( expr, args );
		}

		m_result = ast::expr::makeCompositeConstruct( expr->getComposite()
			, expr->getComponent()
			, std::move( args ) );
	}

	void ExprAdapter::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		ast::expr::ExprList args;

		struct OutputParam
		{
			ast::expr::ExprPtr param;
			ast::var::VariablePtr alias;
		};
		std::vector< OutputParam > outputParams;
		auto fnType = std::static_pointer_cast< ast::type::Function >( expr->getFn()->getType() );
		auto it = fnType->begin();

		for ( auto & arg : expr->getArgList() )
		{
			auto kind = getNonArrayKind( arg->getType() );
			auto param = *( it++ );

			if ( isSamplerType( kind )
				|| isSampledImageType( kind )
				|| isImageType( kind ) )
			{
				if ( arg->getKind() == ast::expr::Kind::eArrayAccess )
				{
					ast::var::VariablePtr alias;
					auto newExpr = doSubmit( arg.get() );
					ast::expr::ExprPtr aliasExpr;

					if ( doMakeAlias( std::move( newExpr ), true, aliasExpr, alias ) )
					{
						auto argIdent = ast::findIdentifier( arg, kind, ast::var::Flag::eUniform );

						if ( argIdent )
						{
							// For samplers and imges, the eUniform flag from the function parameter must be removed,
							// since the alias can't have it.
							param->updateFlag( ast::var::Flag::eUniform, false );
							//// Then the eConstant flag must be added, to match
							//auto aliaIdent
							//( aliasExpr )->getVariable()->updateFlag( ast::var::Flag::eConstant, true );
						}
					}

					args.emplace_back( std::move( aliasExpr ) );

					if ( param->isOutputParam()
						&& alias )
					{
						outputParams.push_back( { doSubmit( arg.get() ), alias } );
					}
				}
				else
				{
					// Images/Samplers/SampledImages are uniform constant pointers.
					args.emplace_back( doSubmit( arg.get() ) );
				}
			}
			else
			{
				ast::var::VariablePtr alias;
				args.emplace_back( doMakeAlias( doSubmit( arg.get() ), true, alias ) );

				if ( param->isOutputParam()
					&& alias )
				{
					outputParams.push_back( { doSubmit( arg.get() ), alias } );
				}
			}
		}

		if ( expr->isMember() )
		{
			m_result = ast::expr::makeMemberFnCall( expr->getType()
				, std::make_unique< ast::expr::Identifier >( *expr->getFn() )
				, doSubmit( expr->getInstance() )
				, std::move( args ) );
		}
		else
		{
			m_result = ast::expr::makeFnCall( expr->getType()
				, std::make_unique< ast::expr::Identifier >( *expr->getFn() )
				, std::move( args ) );
		}

		if ( expr->getType()->getKind() != ast::type::Kind::eVoid )
		{
			// Store function result into a return alias, that will be the final result.
			auto var = createTmpVar( expr->getType()
				, m_config.aliasId );
			m_container->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( m_cache, var ), std::move( m_result ) ) ) );
			m_result = ast::expr::makeIdentifier( m_cache, var );
		}

		for ( auto & var : outputParams )
		{
			m_container->addStmt( ast::stmt::makeSimple( std::move( m_result ) ) );
			m_result = ast::expr::makeAssign( var.alias->getType()
				, std::move( var.param )
				, ast::expr::makeIdentifier( m_cache, var.alias ) );
		}
	}

	void ExprAdapter::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		auto it = m_context.constExprs.find( expr->getVariable()->getName() );

		if ( it != m_context.constExprs.end() )
		{
			if ( it->second->getKind() == ast::expr::Kind::eLiteral )
			{
				m_result = getLiteral( expr, m_context );
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

	void ExprAdapter::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		auto dstType = expr->getType();
		auto srcType = getExpectedReturnType( expr );
		m_result = ast::expr::makeImageAccessCall( srcType
			, expr->getImageAccess()
			, std::move( args ) );

		if ( srcType != dstType )
		{
			assert( ast::type::getScalarType( srcType->getKind() ) == ast::type::getScalarType( dstType->getKind() ) );
			auto dstCount = ast::type::getComponentCount( dstType );

			if ( dstCount == 1u )
			{
				m_result = ast::expr::makeSwizzle( std::move( m_result )
					, ast::expr::SwizzleKind::e0 );
			}
			else if ( dstCount == 2u )
			{
				m_result = ast::expr::makeSwizzle( std::move( m_result )
					, ast::expr::SwizzleKind::e01 );
			}
			else if ( dstCount == 3u )
			{
				m_result = ast::expr::makeSwizzle( std::move( m_result )
					, ast::expr::SwizzleKind::e012 );
			}
		}
	}

	void ExprAdapter::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		auto intrinsic = expr->getIntrinsic();

		if ( intrinsic >= ast::expr::Intrinsic::eMatrixCompMult2x2F
			&& intrinsic <= ast::expr::Intrinsic::eMatrixCompMult4x4D )
		{
			assert( expr->getArgList().size() == 2u );
			m_result = doWriteMatrixBinaryOperation( ast::expr::Kind::eTimes
				, expr->getType()
				, expr->getArgList()[0].get()
				, expr->getArgList()[1].get() );
		}
		else
		{
			ExprCloner::visitIntrinsicCallExpr( expr );
		}
	}

	void ExprAdapter::visitQuestionExpr( ast::expr::Question * expr )
	{
		auto condComponents = getComponentCount( expr->getCtrlExpr()->getType()->getKind() );
		auto opsComponents = getComponentCount( expr->getTrueExpr()->getType()->getKind() );

		if ( condComponents == opsComponents )
		{
			ExprCloner::visitQuestionExpr( expr );
		}
		else
		{
			assert( condComponents == 1u );
			ast::expr::ExprList args;
			ast::var::VariablePtr alias;
			args.emplace_back( doMakeAlias( doSubmit( expr->getCtrlExpr() ), false, alias ) );
			m_result = ast::expr::makeQuestion( expr->getType()
				, doSubmit( ast::expr::makeCompositeConstruct( getCompositeType( opsComponents )
					, expr->getCtrlExpr()->getType()->getKind()
					, std::move( args ) ).get() )
				, doSubmit( expr->getTrueExpr() )
				, doSubmit( expr->getFalseExpr() ) );
		}
	}

	void ExprAdapter::visitSwizzleExpr( ast::expr::Swizzle * expr )
	{
		auto outerComponentsCount = getComponentCount( expr->getOuterExpr()->getType()->getKind() );
		auto innerComponentsCount = getComponentCount( expr->getType()->getKind() );

		// Remove unnecessary swizzles
		if ( outerComponentsCount == innerComponentsCount
			&& ( expr->getSwizzle() == ast::expr::SwizzleKind::e0
				|| expr->getSwizzle() == ast::expr::SwizzleKind::e01
				|| expr->getSwizzle() == ast::expr::SwizzleKind::e012
				|| expr->getSwizzle() == ast::expr::SwizzleKind::e0123 ) )
		{
			m_result = doSubmit( expr->getOuterExpr() );
		}
		else
		{
			ExprCloner::visitSwizzleExpr( expr );
		}
	}

	void ExprAdapter::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		auto kind = expr->getTextureAccess();
		IntrinsicConfig config;
		getSpirVConfig( kind, config );
		auto op = getSpirVName( kind );
		auto returnType = expr->getType();
		auto count = getComponentCount( returnType->getKind() );

		if ( config.returnComponentsCount != ~( 0u ) && config.returnComponentsCount != count )
		{
			assert( config.returnComponentsCount > count );
			returnType = m_cache.getVector( getScalarType( returnType->getKind() ), config.returnComponentsCount );
		}

		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( submit( arg.get(), m_container, m_context, m_config ) );
		}

		if ( op == spv::OpImageGather )
		{
			if ( !hasComp( kind ) )
			{
				// Comp parameter of textureGather can be implicitly 0, in GLSL.
				// Hence add it to args.
				args.emplace_back( ast::expr::makeLiteral( m_cache, 0 ) );
				kind = getCompAccess( kind );
			}

			// Comp parameter is the last one in GLSL whilst it is the last before
			// optional ones in SPIR-V, hence we move it to the right place.
			auto compArg = std::move( args.back() );
			args.pop_back();
			args.emplace( args.begin() + ( config.imageOperandsIndex - 1u ), std::move( compArg ) );
		}
		else if ( getBias( kind ) == spv::ImageOperandsBiasMask )
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

		if ( config.returnComponentsCount != ~( 0u ) && config.returnComponentsCount != count )
		{
			ast::expr::SwizzleKind swizzleKind;

			switch ( count )
			{
			case 1:
				swizzleKind = ast::expr::SwizzleKind::e0;
				break;
			case 2:
				swizzleKind = ast::expr::SwizzleKind::e01;
				break;
			case 3:
				swizzleKind = ast::expr::SwizzleKind::e012;
				break;
			case 4:
				swizzleKind = ast::expr::SwizzleKind::e0123;
				break;
			}

			m_result = ast::expr::makeSwizzle( std::move( m_result ), swizzleKind );
		}
	}

	bool ExprAdapter::doMakeAlias( ast::expr::ExprPtr expr
		, bool param
		, ast::expr::ExprPtr & aliasExpr
		, ast::var::VariablePtr & alias )
	{
		auto kind = getNonArrayKind( expr->getType() );

		if ( isSamplerType( kind )
			|| isSampledImageType( kind )
			|| isImageType( kind )
			|| !needsAlias( expr->getKind()
				, isShaderVariable( *expr )
				, param ) )
		{
			aliasExpr = std::move( expr );
			return false;
		}

		alias = createTmpVar( expr->getType()
			, m_config.aliasId );
		m_container->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( m_cache, alias ), std::move( expr ) ) ) );
		aliasExpr = ast::expr::makeIdentifier( m_cache, alias );
		return true;
	}

	ast::expr::ExprPtr ExprAdapter::doMakeAlias( ast::expr::ExprPtr expr
		, bool param
		, ast::var::VariablePtr & alias )
	{
		ast::expr::ExprPtr result;
		doMakeAlias( std::move( expr ), param, result, alias );
		return result;
	}

	ast::type::TypePtr ExprAdapter::doPromoteScalar( ast::expr::ExprPtr & lhs
		, ast::expr::ExprPtr & rhs )
	{
		auto lhsScalar = isScalarType( lhs->getType()->getKind() );
		auto rhsScalar = isScalarType( rhs->getType()->getKind() );
		auto result = lhs->getType();

		if ( !lhsScalar || !rhsScalar )
		{
			if ( !lhsScalar && !rhsScalar )
			{
				assert( lhs->getType()->getKind() == rhs->getType()->getKind()
					&& "TODO" );
			}
			else if ( lhsScalar )
			{
				result = rhs->getType();
				ast::expr::ExprList args;
				auto count = getComponentCount( result->getKind() );
				ast::var::VariablePtr aliasVar;
				auto alias = doMakeAlias( doSubmit( lhs.get() ), false, aliasVar );

				for ( auto i = 0u; i < count; ++i )
				{
					args.emplace_back( doSubmit( alias.get() ) );
				}

				lhs = ast::expr::makeCompositeConstruct( getCompositeType( getComponentCount( result->getKind() ) )
					, args.back()->getType()->getKind()
					, std::move( args ) );
			}
			else if ( rhsScalar )
			{
				result = lhs->getType();
				ast::expr::ExprList args;
				auto count = getComponentCount( result->getKind() );
				ast::var::VariablePtr aliasVar;
				auto alias = doMakeAlias( doSubmit( rhs.get() ), false, aliasVar );

				for ( auto i = 0u; i < count; ++i )
				{
					args.emplace_back( doSubmit( alias.get() ) );
				}

				rhs = ast::expr::makeCompositeConstruct( getCompositeType( getComponentCount( result->getKind() ) )
					, args.back()->getType()->getKind()
					, std::move( args ) );
			}
		}

		return result;
	}

	ast::expr::ExprPtr ExprAdapter::doWriteBinaryOperation( ast::expr::Kind operation
		, ast::type::TypePtr resType
		, ast::expr::Expr * lhs
		, ast::expr::Expr * rhs )
	{
		bool needMatchingVectors;
		bool switchParams;
		auto op = getBinOpCode( operation
			, lhs->getType()->getKind()
			, rhs->getType()->getKind()
			, switchParams
			, needMatchingVectors );

		if ( switchParams )
		{
			std::swap( lhs, rhs );
		}

		auto lhsType = lhs->getType();
		auto rhsType = rhs->getType();
		bool lhsMat = isMatrixType( lhsType->getKind() );
		bool rhsMat = isMatrixType( rhsType->getKind() );
		auto lhsExpr = doSubmit( lhs );
		auto rhsExpr = doSubmit( rhs );
		auto type = lhsExpr->getType();
		ast::expr::ExprPtr result;

		if ( lhsMat || rhsMat )
		{
			if ( op == spv::OpMatrixTimesVector )
			{
				type = rhsExpr->getType();
			}

			ast::expr::ExprList args;
			ast::var::VariablePtr lhsAlias, rhsAlias;
			lhsExpr = doMakeAlias( std::move( lhsExpr ), false, lhsAlias );
			rhsExpr = doMakeAlias( std::move( rhsExpr ), false, rhsAlias );

			switch ( operation )
			{
			case ast::expr::Kind::eAdd:
			case ast::expr::Kind::eDivide:
			case ast::expr::Kind::eMinus:
				result = doWriteMatrixBinaryOperation( operation
					, resType
					, lhsExpr.get()
					, rhsExpr.get() );
				break;
			case ast::expr::Kind::eTimes:
				result = ast::expr::makeTimes( type
					, std::move( lhsExpr )
					, std::move( rhsExpr ) );
				break;
			default:
				assert( false && "Unsupported binary operation" );
				break;
			}
		}
		else
		{
			if ( needMatchingVectors )
			{
				type = doPromoteScalar( lhsExpr, rhsExpr );
			}

			ast::expr::ExprList args;

			switch ( operation )
			{
			case ast::expr::Kind::eAdd:
				result = ast::expr::makeAdd( type
					, std::move( lhsExpr )
					, std::move( rhsExpr ) );
				break;
			case ast::expr::Kind::eDivide:
				result = ast::expr::makeDivide( type
					, std::move( lhsExpr )
					, std::move( rhsExpr ) );
				break;
			case ast::expr::Kind::eMinus:
				result = ast::expr::makeMinus( type
					, std::move( lhsExpr )
					, std::move( rhsExpr ) );
				break;
			case ast::expr::Kind::eTimes:
				result = ast::expr::makeTimes( type
					, std::move( lhsExpr )
					, std::move( rhsExpr ) );
				break;
			default:
				assert( false && "Unsupported binary operation" );
				break;
			}
		}

		return result;
	}

	ast::expr::ExprPtr ExprAdapter::doWriteMatrixBinaryOperation( ast::expr::Kind operation
		, ast::type::TypePtr resType
		, ast::expr::Expr * lhs
		, ast::expr::Expr * rhs )
	{
			// one time set up...
		auto lhsType = lhs->getType();
		auto rhsType = rhs->getType();
		bool lhsMat = isMatrixType( lhsType->getKind() );
		bool rhsMat = isMatrixType( rhsType->getKind() );
		auto lhsColumns = getComponentCount( lhsType->getKind() );
		auto rhsColumns = getComponentCount( rhsType->getKind() );
		auto lhsRows = getComponentCount( getComponentType( lhsType->getKind() ) );
		auto rhsRows = getComponentCount( getComponentType( rhsType->getKind() ) );
		auto numCols = lhsMat ? lhsColumns : rhsColumns;
		auto numRows = lhsMat ? lhsRows : rhsRows;
		auto scalarType = getScalarType( resType->getKind() );
		auto vecType = m_cache.getVector( scalarType, numRows );
		ast::expr::CompositeType composite;

		switch ( numRows )
		{
		case 1:
			composite = ast::expr::CompositeType::eScalar;
			break;
		case 2:
			composite = ast::expr::CompositeType::eVec2;
			break;
		case 3:
			composite = ast::expr::CompositeType::eVec3;
			break;
		default:
			composite = ast::expr::CompositeType::eVec4;
			break;
		}

		ast::expr::ExprPtr smearVec;

		if ( isScalarType( lhsType->getKind() ) )
		{
			if ( composite == ast::expr::CompositeType::eScalar )
			{
				smearVec = doSubmit( lhs );
			}
			else
			{
				ast::expr::ExprList params;
				params.emplace_back( doSubmit( lhs ) );
				smearVec = ast::expr::makeCompositeConstruct( composite
					, lhsType->getKind()
					, std::move( params ) );
			}
		}
		else if ( isScalarType( rhsType->getKind() ) )
		{
			if ( composite == ast::expr::CompositeType::eScalar )
			{
				smearVec = doSubmit( rhs );
			}
			else
			{
				ast::expr::ExprList params;
				params.emplace_back( doSubmit( rhs ) );
				smearVec = ast::expr::makeCompositeConstruct( composite
					, rhsType->getKind()
					, std::move( params ) );
			}
		}

		ast::expr::ExprList args;

		// do each vector op
		for ( unsigned int c = 0; c < numCols; ++c )
		{
			std::vector<unsigned int> indexes;
			indexes.push_back( c );
			auto lhsVec = lhsMat
				? ast::expr::makeArrayAccess( vecType, doSubmit( lhs ), ast::expr::makeLiteral( m_cache, c ) )
				: ast::ExprCloner::submit( smearVec.get() );
			auto rhsVec = rhsMat
				? ast::expr::makeArrayAccess( vecType, doSubmit( rhs ), ast::expr::makeLiteral( m_cache, c ) )
				: ast::ExprCloner::submit( smearVec.get() );

			switch ( operation )
			{
			case ast::expr::Kind::eAdd:
				args.emplace_back( ast::expr::makeAdd( vecType
					, std::move( lhsVec )
					, std::move( rhsVec ) ) );
				break;
			case ast::expr::Kind::eDivide:
				args.emplace_back( ast::expr::makeDivide( vecType
					, std::move( lhsVec )
					, std::move( rhsVec ) ) );
				break;
			case ast::expr::Kind::eMinus:
				args.emplace_back( ast::expr::makeMinus( vecType
					, std::move( lhsVec )
					, std::move( rhsVec ) ) );
				break;
			case ast::expr::Kind::eTimes:
				args.emplace_back( ast::expr::makeTimes( vecType
					, std::move( lhsVec )
					, std::move( rhsVec ) ) );
				break;
			default:
				assert( false && "Unsupported binary operation" );
				break;
			}
		}

		switch ( composite )
		{
		case ast::expr::CompositeType::eScalar:
			switch ( numCols )
			{
			case 1:
				composite = ast::expr::CompositeType::eScalar;
				break;
			case 2:
				composite = ast::expr::CompositeType::eVec2;
				break;
			case 3:
				composite = ast::expr::CompositeType::eVec3;
				break;
			case 4:
				composite = ast::expr::CompositeType::eVec4;
				break;
			}
			break;
		case ast::expr::CompositeType::eVec2:
			switch ( numCols )
			{
			case 1:
				composite = ast::expr::CompositeType::eVec2;
				break;
			case 2:
				composite = ast::expr::CompositeType::eMat2x2;
				break;
			case 3:
				composite = ast::expr::CompositeType::eMat3x2;
				break;
			case 4:
				composite = ast::expr::CompositeType::eMat4x2;
				break;
			}
			break;
		case ast::expr::CompositeType::eVec3:
			switch ( numCols )
			{
			case 1:
				composite = ast::expr::CompositeType::eVec3;
				break;
			case 2:
				composite = ast::expr::CompositeType::eMat2x3;
				break;
			case 3:
				composite = ast::expr::CompositeType::eMat3x3;
				break;
			case 4:
				composite = ast::expr::CompositeType::eMat4x3;
				break;
			}
			break;
		case ast::expr::CompositeType::eVec4:
			switch ( numCols )
			{
			case 1:
				composite = ast::expr::CompositeType::eVec4;
				break;
			case 2:
				composite = ast::expr::CompositeType::eMat2x4;
				break;
			case 3:
				composite = ast::expr::CompositeType::eMat3x4;
				break;
			case 4:
				composite = ast::expr::CompositeType::eMat4x4;
				break;
			}
			break;
		default:
			break;
		}

		// put the pieces together
		if ( composite != ast::expr::CompositeType::eScalar )
		{
			return ast::expr::makeCompositeConstruct( composite
				, scalarType
				, std::move( args ) );
		}

		assert( args.size() == 1u );
		return std::move( args[0] );
	}

	void ExprAdapter::doConstructVector( ast::expr::CompositeConstruct * expr
		, ast::expr::ExprPtr const & newArg
		, ast::type::Kind destKind
		, ast::expr::ExprList & args )
	{
		auto count = getComponentCount( newArg->getType()->getKind() );

		for ( auto i = 0u; i < count; ++i )
		{
			args.emplace_back( ast::expr::makeSwizzle( doSubmit( newArg.get() )
				, ast::expr::SwizzleKind::fromOffset( i ) ) );
		}

		if ( newArg->getType()->getKind() != expr->getType()->getKind() )
		{
			auto dstType = m_cache.getBasicType( getScalarType( expr->getType()->getKind() ) );

			for ( auto & arg : args )
			{
				arg = doSubmit( ast::expr::makeCast( dstType
					, std::move( arg ) ).get() );
			}
		}
	}

	void ExprAdapter::doConstructMatrix( ast::expr::CompositeConstruct * expr
		, ast::expr::ExprPtr const & newArg
		, ast::type::Kind destKind
		, ast::expr::ExprList & args )
	{
		auto scalarType = getScalarType( destKind );
		auto srcColumnCount = getComponentCount( newArg->getType()->getKind() );
		auto srcRowCount = getComponentCount( getComponentType( newArg->getType()->getKind() ) );
		auto dstColumnCount = getComponentCount( destKind );
		auto dstRowCount = getComponentCount( getComponentType( destKind ) );
		auto minColumnCount = std::min( srcColumnCount, dstColumnCount );

		for ( auto col = 0u; col < minColumnCount; ++col )
		{
			auto arrayAccess = ast::expr::makeArrayAccess( m_cache.getVector( scalarType, srcRowCount )
				, doSubmit( newArg.get() )
				, ast::expr::makeLiteral( m_cache, col ) );

			if ( dstRowCount < srcRowCount )
			{
				args.emplace_back( ast::expr::makeSwizzle( std::move( arrayAccess )
					, getSwizzleComponents( dstRowCount ) ) );
			}
			else if ( dstRowCount == srcRowCount )
			{
				args.emplace_back( std::move( arrayAccess ) );
			}
			else
			{
				ast::expr::ExprList compositeArgs;
				compositeArgs.emplace_back( std::move( arrayAccess ) );

				for ( auto row = srcRowCount; row < dstRowCount; ++row )
				{
					if ( row == col )
					{
						switch ( scalarType )
						{
						case ast::type::Kind::eInt:
							compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 1 ) );
							break;
						case ast::type::Kind::eUInt:
							compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 1u ) );
							break;
						case ast::type::Kind::eFloat:
							compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 1.0f ) );
							break;
						case ast::type::Kind::eDouble:
							compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 1.0 ) );
							break;
						default:
							break;
						}
					}
					else
					{
						switch ( scalarType )
						{
						case ast::type::Kind::eInt:
							compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0 ) );
							break;
						case ast::type::Kind::eUInt:
							compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0u ) );
							break;
						case ast::type::Kind::eFloat:
							compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0.0f ) );
							break;
						case ast::type::Kind::eDouble:
							compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0.0 ) );
							break;
						default:
							break;
						}
					}
				}

				args.emplace_back( ast::expr::makeCompositeConstruct( getCompositeType( dstRowCount )
					, scalarType
					, std::move( compositeArgs ) ) );
			}
		}

		for ( auto col = minColumnCount; col < dstColumnCount; ++col )
		{
		}
	}

	void ExprAdapter::doConstructOther( ast::expr::CompositeConstruct * expr
		, ast::expr::ExprList & args )
	{
		auto scalarType = expr->getComponent();

		for ( auto & arg : expr->getArgList() )
		{
			auto newArg = doSubmit( arg.get() );

			if ( isScalarType( newArg->getType()->getKind() ) )
			{
				auto argTypeKind = getScalarType( newArg->getType()->getKind() );

				if ( argTypeKind != scalarType )
				{
					newArg = ast::expr::makeCast( m_cache.getBasicType( scalarType )
						, std::move( newArg ) );
				}
			}

			args.emplace_back( std::move( newArg ) );
		}
	}

	//*************************************************************************
}
