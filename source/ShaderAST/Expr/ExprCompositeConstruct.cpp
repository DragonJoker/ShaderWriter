/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprCompositeConstruct.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

#include <cassert>
#include <stdexcept>

namespace ast::expr
{
	//*************************************************************************

	namespace
	{
		uint32_t getTotalComponentCount( type::Kind kind )
		{
			auto result = 1u;

			do
			{
				result *= getComponentCount( kind );
				kind = getComponentType( kind );
			}
			while ( isVectorType( kind ) );

			return result;
		}
	}

	//*************************************************************************

	CompositeConstruct::CompositeConstruct( CompositeType composite
		, type::Kind component
		, ExprList && argList )
		: Expr
		{
			getExprTypesCache( argList ),
			getCompositeType( getExprTypesCache( argList ), composite, component ),
			Kind::eCompositeConstruct,
			( isExprConstant( argList )
				? Flag::eConstant
				: Flag::eNone )
		}
		, m_composite{ composite }
		, m_component{ component }
		, m_argList{ std::move( argList ) }
	{
		uint32_t paramsComponentsCount{};

		for ( auto & arg : m_argList )
		{
			paramsComponentsCount += getTotalComponentCount( arg->getType()->getKind() );
		}

		if ( paramsComponentsCount != 1u
			&& paramsComponentsCount < getComponentCount( m_composite ) )
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
		case ast::expr::CompositeType::eScalar:
			result = 1u;
			break;
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

	type::TypePtr getCompositeType( type::TypesCache & cache
		, CompositeType composite
		, type::Kind component )
	{
		assert( isScalarType( component ) );
		type::TypePtr result;

		switch ( composite )
		{
		case expr::CompositeType::eScalar:
			switch ( component )
			{
			case type::Kind::eBoolean:
				result = cache.getBool();
				break;
			case type::Kind::eInt:
				result = cache.getInt();
				break;
			case type::Kind::eUInt:
				result = cache.getUInt32();
				break;
			case type::Kind::eUInt64:
				result = cache.getUInt64();
				break;
			case type::Kind::eHalf:
				result = cache.getHalf();
				break;
			case type::Kind::eFloat:
				result = cache.getFloat();
				break;
			case type::Kind::eDouble:
				result = cache.getDouble();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eVec2:
			switch ( component )
			{
			case type::Kind::eBoolean:
				result = cache.getVec2B();
				break;
			case type::Kind::eInt:
				result = cache.getVec2I();
				break;
			case type::Kind::eUInt:
				result = cache.getVec2U32();
				break;
			case type::Kind::eUInt64:
				result = cache.getVec2U64();
				break;
			case type::Kind::eHalf:
				result = cache.getVec2H();
				break;
			case type::Kind::eFloat:
				result = cache.getVec2F();
				break;
			case type::Kind::eDouble:
				result = cache.getVec2D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eVec3:
			switch ( component )
			{
			case type::Kind::eBoolean:
				result = cache.getVec3B();
				break;
			case type::Kind::eInt:
				result = cache.getVec3I();
				break;
			case type::Kind::eUInt:
				result = cache.getVec3U32();
				break;
			case type::Kind::eUInt64:
				result = cache.getVec3U64();
				break;
			case type::Kind::eFloat:
				result = cache.getVec3F();
				break;
			case type::Kind::eDouble:
				result = cache.getVec3D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eVec4:
			switch ( component )
			{
			case type::Kind::eBoolean:
				result = cache.getVec4B();
				break;
			case type::Kind::eInt:
				result = cache.getVec4I();
				break;
			case type::Kind::eUInt:
				result = cache.getVec4U32();
				break;
			case type::Kind::eUInt64:
				result = cache.getVec4U64();
				break;
			case type::Kind::eHalf:
				result = cache.getVec4H();
				break;
			case type::Kind::eFloat:
				result = cache.getVec4F();
				break;
			case type::Kind::eDouble:
				result = cache.getVec4D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eMat2x2:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = cache.getMat2x2F();
				break;
			case type::Kind::eDouble:
				result = cache.getMat2x2D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eMat2x3:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = cache.getMat2x3F();
				break;
			case type::Kind::eDouble:
				result = cache.getMat2x3D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eMat2x4:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = cache.getMat2x4F();
				break;
			case type::Kind::eDouble:
				result = cache.getMat2x4D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eMat3x2:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = cache.getMat3x2F();
				break;
			case type::Kind::eDouble:
				result = cache.getMat3x2D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eMat3x3:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = cache.getMat3x3F();
				break;
			case type::Kind::eDouble:
				result = cache.getMat3x3D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eMat3x4:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = cache.getMat3x4F();
				break;
			case type::Kind::eDouble:
				result = cache.getMat3x4D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eMat4x2:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = cache.getMat4x2F();
				break;
			case type::Kind::eDouble:
				result = cache.getMat4x2D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eMat4x3:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = cache.getMat4x3F();
				break;
			case type::Kind::eDouble:
				result = cache.getMat4x3D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		case expr::CompositeType::eMat4x4:
			assert( isFloatType( component )
				|| isDoubleType( component ) );
			switch ( component )
			{
			case type::Kind::eFloat:
				result = cache.getMat4x4F();
				break;
			case type::Kind::eDouble:
				result = cache.getMat4x4D();
				break;
			default:
				AST_Failure( "Unsupported type::Kind" );
				break;
			}
			break;
		default:
			AST_Failure( "Unsupported type::Kind" );
			break;
		}

		return result;
	}

	//*************************************************************************
}
