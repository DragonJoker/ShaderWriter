/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprCompositeConstruct.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	//*************************************************************************

	CompositeConstruct::CompositeConstruct( CompositeType composite
		, type::Kind component
		, ExprList && argList )
		: Expr{ getCompositeType( composite, component ), Kind::eCompositeConstruct }
		, m_composite{ composite }
		, m_component{ component }
		, m_argList{ std::move( argList ) }
	{
		uint32_t paramsComponentsCount{};

		for ( auto & arg : m_argList )
		{
			paramsComponentsCount += getComponentCount( arg->getType()->getKind() );
		}

		if ( paramsComponentsCount != 1u
			&& paramsComponentsCount != getComponentCount( m_composite ) )
		{
			throw std::runtime_error{ "The total arguments components count must match the composite type components count" };
		}
	}

	void CompositeConstruct::accept( VisitorPtr vis )
	{
		vis->visitCompositeConstructExpr( this );
	}

	//*************************************************************************

	uint32_t getComponentCount( CompositeType value )
	{
		uint32_t result{};

		switch ( value )
		{
		case ast::expr::CompositeType::eVec2:
			result = 2u;
			break;
		case ast::expr::CompositeType::eVec3:
			result = 3u;
			break;
		case ast::expr::CompositeType::eVec4:
			result = 4u;
			break;
		case ast::expr::CompositeType::eMat2x2:
			result = 4u;
			break;
		case ast::expr::CompositeType::eMat2x3:
			result = 6u;
			break;
		case ast::expr::CompositeType::eMat2x4:
			result = 8u;
			break;
		case ast::expr::CompositeType::eMat3x2:
			result = 6u;
			break;
		case ast::expr::CompositeType::eMat3x3:
			result = 9u;
			break;
		case ast::expr::CompositeType::eMat3x4:
			result = 12u;
			break;
		case ast::expr::CompositeType::eMat4x2:
			result = 8u;
			break;
		case ast::expr::CompositeType::eMat4x3:
			result = 12u;
			break;
		case ast::expr::CompositeType::eMat4x4:
			result = 16u;
			break;
		}

		return result;
	}

	type::TypePtr getCompositeType( CompositeType composite
		, type::Kind component )
	{
		assert( isScalarType( component ) );
		type::TypePtr result;

		switch ( composite )
		{
		case expr::CompositeType::eVec2:
			switch ( component )
			{
			case type::Kind::eBoolean:
				result = type::getVec2B();
				break;
			case type::Kind::eInt:
				result = type::getVec2I();
				break;
			case type::Kind::eUInt:
				result = type::getVec2U();
				break;
			case type::Kind::eFloat:
				result = type::getVec2F();
				break;
			case type::Kind::eDouble:
				result = type::getVec2D();
				break;
			case type::Kind::eHalf:
				result = type::makeType( type::Kind::eVec2H );
				break;
			}
			break;
		case expr::CompositeType::eVec3:
			switch ( component )
			{
			case type::Kind::eBoolean:
				result = type::getVec3B();
				break;
			case type::Kind::eInt:
				result = type::getVec3I();
				break;
			case type::Kind::eUInt:
				result = type::getVec3U();
				break;
			case type::Kind::eFloat:
				result = type::getVec3F();
				break;
			case type::Kind::eDouble:
				result = type::getVec3D();
				break;
			case type::Kind::eHalf:
				result = type::makeType( type::Kind::eVec3H );
				break;
			}
			break;
		case expr::CompositeType::eVec4:
			switch ( component )
			{
			case type::Kind::eBoolean:
				result = type::getVec4B();
				break;
			case type::Kind::eInt:
				result = type::getVec4I();
				break;
			case type::Kind::eUInt:
				result = type::getVec4U();
				break;
			case type::Kind::eFloat:
				result = type::getVec4F();
				break;
			case type::Kind::eDouble:
				result = type::getVec4D();
				break;
			case type::Kind::eHalf:
				result = type::makeType( type::Kind::eVec4H );
				break;
			}
			break;
		case expr::CompositeType::eMat2x2:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = type::getMat2x2F();
				break;
			case type::Kind::eDouble:
				result = type::getMat2x2D();
				break;
			}
			break;
		case expr::CompositeType::eMat2x3:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = type::getMat2x3F();
				break;
			case type::Kind::eDouble:
				result = type::getMat2x3D();
				break;
			}
			break;
		case expr::CompositeType::eMat2x4:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = type::getMat2x4F();
				break;
			case type::Kind::eDouble:
				result = type::getMat2x4D();
				break;
			}
			break;
		case expr::CompositeType::eMat3x2:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = type::getMat3x2F();
				break;
			case type::Kind::eDouble:
				result = type::getMat3x2D();
				break;
			}
			break;
		case expr::CompositeType::eMat3x3:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = type::getMat3x3F();
				break;
			case type::Kind::eDouble:
				result = type::getMat3x3D();
				break;
			}
			break;
		case expr::CompositeType::eMat3x4:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = type::getMat3x4F();
				break;
			case type::Kind::eDouble:
				result = type::getMat3x4D();
				break;
			}
			break;
		case expr::CompositeType::eMat4x2:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = type::getMat4x2F();
				break;
			case type::Kind::eDouble:
				result = type::getMat4x2D();
				break;
			}
			break;
		case expr::CompositeType::eMat4x3:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = type::getMat4x3F();
				break;
			case type::Kind::eDouble:
				result = type::getMat4x3D();
				break;
			}
			break;
		case expr::CompositeType::eMat4x4:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = type::getMat4x4F();
				break;
			case type::Kind::eDouble:
				result = type::getMat4x4D();
				break;
			}
			break;
		}

		return result;
	}

	//*************************************************************************
}
