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
		: Expr{ getExprTypesCache( argList )
			, getCompositeType( getExprTypesCache( argList ), composite, component )
			, Kind::eCompositeConstruct
			, ( isExprConstant( argList )
				? Flag::eConstant
				: Flag::eNone ) }
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

	CompositeConstruct::CompositeConstruct( ExprPtr image
		, ExprPtr sampler )
		: Expr{ getExprTypesCache( image, sampler )
			, getCombinedType( image->getType(), sampler->getType() )
			, Kind::eCompositeConstruct
			, ( isExprConstant( image, sampler )
				? Flag::eConstant
				: Flag::eNone ) }
		, m_composite{ CompositeType::eCombine }
		, m_component{ type::Kind::eCombinedImage }
	{
		m_argList.emplace_back( std::move( image ) );
		m_argList.emplace_back( std::move( sampler ) );
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
		case ast::expr::CompositeType::eCombine:
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
		, type::ImageConfiguration config
		, bool isComparison )
	{
		return cache.getCombinedImage( config, isComparison );
	}

	type::TypePtr getCombinedType( type::TypePtr image
		, type::TypePtr sampler )
	{
		image = getNonArrayTypeRec( image );
		sampler = getNonArrayTypeRec( sampler );

		if ( image->getKind() != type::Kind::eSampledImage )
		{
			throw std::runtime_error{ "combine(splImage, sampler): Missing sampled image 1st parameter." };
		}

		if ( sampler->getKind() != type::Kind::eSampler )
		{
			throw std::runtime_error{ "combine(splImage, sampler): Missing sampler 2nd parameter" };
		}

		auto & imgType = static_cast< ast::type::SampledImage const & >( *image );
		auto & splType = static_cast< ast::type::Sampler const & >( *sampler );
		return getCompositeType( image->getCache()
			, imgType.getConfig()
			, splType.isComparison() );
	}

	type::TypePtr getCompositeType( type::TypesCache & cache
		, CompositeType composite
		, type::Kind component )
	{
		assert( composite != CompositeType::eCombine && isScalarType( component ) );
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
