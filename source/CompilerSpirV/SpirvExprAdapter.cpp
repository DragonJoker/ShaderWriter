/*
See LICENSE file in root folder
*/
#include "SpirvExprAdapter.hpp"
#include "SpirvExprEvaluator.hpp"

#include "SpirvTextureAccessConfig.hpp"
#include "SpirvTextureAccessNames.hpp"

#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace spirv
{
	//*************************************************************************

	namespace
	{
		ast::expr::CompositeType getCompositeType( uint32_t count )
		{
			ast::expr::CompositeType result = ast::expr::CompositeType::eScalar;

			switch ( count )
			{
			case 2:
				result = ast::expr::CompositeType::eVec2;
				break;
			case 3:
				result = ast::expr::CompositeType::eVec3;
				break;
			case 4:
				result = ast::expr::CompositeType::eVec4;
				break;
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

	void ExprAdapter::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		auto scalarType = expr->getComponent();
		ast::expr::ExprList args;

		if ( expr->getArgList().size() == 1u
			&& !isScalarType( expr->getArgList().front()->getType()->getKind() ) )
		{
			auto newArg = doMakeAlias( doSubmit( expr->getArgList().front().get() ) );
			auto count = getComponentCount( newArg->getType()->getKind() );

			for ( auto i = 0u; i < count; ++i )
			{
				args.emplace_back( ast::expr::makeSwizzle( doSubmit( newArg.get() )
					, ast::expr::SwizzleKind( i ) ) );
			}

			if ( newArg->getType()->getKind() != expr->getType()->getKind() )
			{
				auto dstType = m_cache.getBasicType( getScalarType( expr->getType()->getKind() ) );

				for ( auto & arg : args )
				{
					arg = ast::expr::makeCast( dstType
						, std::move( arg ) );
				}
			}
		}
		else
		{
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

		m_result = ast::expr::makeCompositeConstruct( expr->getComposite()
			, expr->getComponent()
			, std::move( args ) );
	}

	void ExprAdapter::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		auto it = m_context.defines.find( expr->getVariable()->getName() );

		if ( it != m_context.defines.end() )
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

		m_result = ast::expr::makeImageAccessCall( expr->getType()
			, expr->getImageAccess()
			, std::move( args ) );
	}

	void ExprAdapter::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		auto intrinsic = expr->getIntrinsic();

		if ( intrinsic >= ast::expr::Intrinsic::eMatrixCompMult2x2F
			&& intrinsic <= ast::expr::Intrinsic::eMatrixCompMult4x4D )
		{
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
			args.emplace( args.begin() + config.imageOperandsIndex - 1u, std::move( args.back() ) );
			args.pop_back();
		}
		else if ( getBias( kind ) == spv::ImageOperandsBiasMask )
		{
			// Bias is the last parameter in GLSL, but it has to be the first one after the ImageOperands in SPIR-V.
			if ( args.size() > config.imageOperandsIndex + 1u )
			{
				args.emplace( args.begin() + config.imageOperandsIndex, std::move( args.back() ) );
				args.pop_back();
			}
		}

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

	bool needsAlias( ast::expr::Kind kind )
	{
		return kind != ast::expr::Kind::eIdentifier
			&& kind != ast::expr::Kind::eSwizzle
			&& kind != ast::expr::Kind::eLiteral
			&& kind != ast::expr::Kind::eMbrSelect;
	}

	ast::expr::ExprPtr ExprAdapter::doMakeAlias( ast::expr::ExprPtr expr )
	{
		if ( !needsAlias( expr->getKind() ) )
		{
			return expr;
		}

		auto var = ast::var::makeVariable( expr->getType()
			, "tmp_" + std::to_string( m_config.aliasId++ )
			, ast::var::Flag::eLocale | ast::var::Flag::eImplicit );
		m_container->addStmt( ast::stmt::makeSimple( ast::expr::makeInit( ast::expr::makeIdentifier( m_cache, var ), std::move( expr ) ) ) );
		return ast::expr::makeIdentifier( m_cache, var );
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
				assert( "TODO" );
			}
			else if ( lhsScalar )
			{
				result = rhs->getType();
				ast::expr::ExprList args;
				auto count = getComponentCount( result->getKind() );
				auto alias = doMakeAlias( doSubmit( lhs.get() ) );

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
				auto alias = doMakeAlias( doSubmit( rhs.get() ) );

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
			//result = doWriteMatrixBinaryOperation( operation
			//	, resType
			//	, lhs
			//	, rhs );
			if ( op == spv::OpMatrixTimesVector )
			{
				type = rhsExpr->getType();
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
		case 4:
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

	//*************************************************************************
}
