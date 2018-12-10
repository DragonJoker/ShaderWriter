/*
See LICENSE file in root folder
*/
#include "SpirvExprAdapter.hpp"
#include "SpirvExprEvaluator.hpp"

#include "SpirvTextureAccessConfig.hpp"
#include "SpirvTextureAccessNames.hpp"

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
		, PreprocContext const & context
		, ModuleConfig const & config )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ result, context, config };
		expr->accept( &vis );
		return result;
	}

	ExprAdapter::ExprAdapter( ast::expr::ExprPtr & result
		, PreprocContext const & context
		, ModuleConfig const & config )
		: ExprCloner{ result }
		, m_context{ context }
		, m_config{ config }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ result, m_context, m_config };
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitAddAssignExpr( ast::expr::AddAssign * expr )
	{
		m_result = doWriteBinaryOperation( ast::expr::Kind::eAdd
			, expr->getType()
			, expr->getLHS()
			, expr->getRHS() );
		m_result = sdw::makeAssign( expr->getType()
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
		m_result = sdw::makeAssign( expr->getType()
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
		m_result = sdw::makeAssign( expr->getType()
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
		m_result = sdw::makeAssign( expr->getType()
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
		auto & cache = expr->getType()->getCache();

		for ( auto & arg : expr->getArgList() )
		{
			auto newArg = doSubmit( arg.get() );

			if ( isScalarType( newArg->getType()->getKind() ) )
			{
				auto argTypeKind = getScalarType( newArg->getType()->getKind() );

				if ( argTypeKind != scalarType )
				{
					newArg = ast::expr::makeCast( cache.makeType( scalarType )
						, std::move( newArg ) );
				}
			}

			args.emplace_back( std::move( newArg ) );
		}

		m_result = ast::expr::makeCompositeConstruct( expr->getType()->getCache()
			, expr->getComposite()
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
		auto & cache = returnType->getCache();
		auto count = getComponentCount( returnType->getKind() );

		if ( config.returnComponentsCount != ~( 0u ) && config.returnComponentsCount != count )
		{
			assert( config.returnComponentsCount > count );
			returnType = cache.getVector( getScalarType( returnType->getKind() ), config.returnComponentsCount );
		}

		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( submit( arg.get(), m_context, m_config ) );
		}

		if ( op == spv::Op::OpImageGather )
		{
			if ( !hasComp( kind ) )
			{
				// Comp parameter of textureGather can be implicitly 0, in GLSL.
				// Hence add it to args.
				args.emplace_back( ast::expr::makeLiteral( cache, 0 ) );
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

				for ( auto i = 0u; i < count; ++i )
				{
					args.emplace_back( doSubmit( lhs.get() ) );
				}

				lhs = sdw::makeCompositeCtor( getCompositeType( getComponentCount( result->getKind() ) )
					, args.back()->getType()->getKind()
					, std::move( args ) );
			}
			else if ( rhsScalar )
			{
				result = lhs->getType();
				ast::expr::ExprList args;
				auto count = getComponentCount( result->getKind() );

				for ( auto i = 0u; i < count; ++i )
				{
					args.emplace_back( doSubmit( rhs.get() ) );
				}

				rhs = sdw::makeCompositeCtor( getCompositeType( getComponentCount( result->getKind() ) )
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
		auto lhsType = lhs->getType();
		auto rhsType = rhs->getType();
		bool lhsMat = isMatrixType( lhsType->getKind() );
		bool rhsMat = isMatrixType( rhsType->getKind() );
		ast::expr::ExprPtr result;

		if ( lhsMat || rhsMat )
		{
			result = doWriteMatrixBinaryOperation( operation
				, resType
				, lhs
				, rhs );
		}
		else
		{
			auto lhsExpr = doSubmit( lhs );
			auto rhsExpr = doSubmit( rhs );
			auto type = lhsExpr->getType();

			if ( needMatchingVectors )
			{
				type = doPromoteScalar( lhsExpr, rhsExpr );
			}

			ast::expr::ExprList args;

			switch ( operation )
			{
			case ast::expr::Kind::eAdd:
				result = sdw::makeAdd( type
					, std::move( lhsExpr )
					, std::move( rhsExpr ) );
				break;
			case ast::expr::Kind::eDivide:
				result = sdw::makeDivide( type
					, std::move( lhsExpr )
					, std::move( rhsExpr ) );
				break;
			case ast::expr::Kind::eMinus:
				result = sdw::makeMinus( type
					, std::move( lhsExpr )
					, std::move( rhsExpr ) );
				break;
			case ast::expr::Kind::eTimes:
				result = sdw::makeTimes( type
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
		auto vecType = resType->getCache().getVector( scalarType, numRows );
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
				smearVec = ast::expr::makeCompositeConstruct( resType->getCache()
					, composite
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
				smearVec = ast::expr::makeCompositeConstruct( resType->getCache()
					, composite
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
				? sdw::makeArrayAccess( vecType, doSubmit( lhs ), ast::expr::makeLiteral( resType->getCache(), c ) )
				: sdw::makeExpr( smearVec );
			auto rhsVec = rhsMat
				? sdw::makeArrayAccess( vecType, doSubmit( rhs ), ast::expr::makeLiteral( resType->getCache(), c ) )
				: sdw::makeExpr( smearVec );

			switch ( operation )
			{
			case ast::expr::Kind::eAdd:
				args.emplace_back( sdw::makeAdd( vecType
					, std::move( lhsVec )
					, std::move( rhsVec ) ) );
				break;
			case ast::expr::Kind::eDivide:
				args.emplace_back( sdw::makeDivide( vecType
					, std::move( lhsVec )
					, std::move( rhsVec ) ) );
				break;
			case ast::expr::Kind::eMinus:
				args.emplace_back( sdw::makeMinus( vecType
					, std::move( lhsVec )
					, std::move( rhsVec ) ) );
				break;
			case ast::expr::Kind::eTimes:
				args.emplace_back( sdw::makeTimes( vecType
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
			return sdw::makeCompositeCtor( composite
				, scalarType
				, std::move( args ) );
		}

		assert( args.size() == 1u );
		return std::move( args[0] );
	}

	//*************************************************************************
}
