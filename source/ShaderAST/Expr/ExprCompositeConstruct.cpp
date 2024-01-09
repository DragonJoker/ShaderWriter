/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprCompositeConstruct.hpp"

#include "ShaderAST/Shader.hpp"
#include "ShaderAST/Expr/ExprVisitor.hpp"

#include <cassert>

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

	CompositeConstruct::CompositeConstruct( ExprCache & exprCache
		, CompositeType composite
		, type::Kind component
		, ExprList argList )
		: Expr{ exprCache
			, sizeof( CompositeConstruct )
			, getExprTypesCache( argList )
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

		for ( auto const & arg : m_argList )
		{
			paramsComponentsCount += getTotalComponentCount( arg->getType()->getKind() );
		}

		if ( paramsComponentsCount != 1u
			&& paramsComponentsCount < getComponentCount( m_composite ) )
		{
			throw Exception{ "The total arguments components count must match the composite type components count" };
		}
	}

	CompositeConstruct::CompositeConstruct( ExprCache & exprCache
		, ExprPtr image
		, ExprPtr sampler )
		: Expr{ exprCache
			, sizeof( CompositeConstruct )
			, getExprTypesCache( image, sampler )
			, getCombinedType( image->getType(), sampler->getType() )
			, Kind::eCompositeConstruct
			, ( isExprConstant( image, sampler )
				? Flag::eConstant
				: Flag::eNone ) }
		, m_composite{ CompositeType::eCombine }
		, m_component{ type::Kind::eCombinedImage }
	{
		auto & imageType = static_cast< ast::type::SampledImage & >( *getNonArrayTypeRec( image->getType() ) );
		auto & samplerType = static_cast< ast::type::Sampler const & >( *getNonArrayTypeRec( sampler->getType() ) );
		imageType.updateComparison( samplerType.isComparison() );

		m_argList.emplace_back( std::move( image ) );
		m_argList.emplace_back( std::move( sampler ) );
	}

	void CompositeConstruct::accept( VisitorPtr vis )const
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

	type::TypePtr getCompositeType( type::TypesCache & typesCache
		, type::ImageConfiguration config
		, bool isComparison )
	{
		return typesCache.getCombinedImage( config, isComparison );
	}

	type::TypePtr getCombinedType( type::TypePtr image
		, type::TypePtr sampler )
	{
		image = getNonArrayTypeRec( image );
		sampler = getNonArrayTypeRec( sampler );

		if ( image->getKind() != type::Kind::eSampledImage )
		{
			throw Exception{ "combine(splImage, sampler): Missing sampled image 1st parameter." };
		}

		if ( sampler->getKind() != type::Kind::eSampler )
		{
			throw Exception{ "combine(splImage, sampler): Missing sampler 2nd parameter" };
		}

		auto & imgType = static_cast< ast::type::SampledImage const & >( *image );
		auto & splType = static_cast< ast::type::Sampler const & >( *sampler );
		return getCompositeType( image->getTypesCache()
			, imgType.getConfig()
			, splType.isComparison() );
	}

	type::TypePtr getCompositeType( type::TypesCache & typesCache
		, CompositeType composite
		, type::Kind component )
	{
		assert( composite != CompositeType::eCombine
			&& ( isScalarType( component ) || isVectorType( component ) ) );
		type::TypePtr result;

		switch ( composite )
		{
		case expr::CompositeType::eScalar:
			switch ( component )
			{
			case type::Kind::eBoolean:
				result = typesCache.getBool();
				break;
			case type::Kind::eInt8:
				result = typesCache.getInt8();
				break;
			case type::Kind::eInt16:
				result = typesCache.getInt16();
				break;
			case type::Kind::eInt32:
				result = typesCache.getInt32();
				break;
			case type::Kind::eInt64:
				result = typesCache.getInt64();
				break;
			case type::Kind::eUInt8:
				result = typesCache.getUInt8();
				break;
			case type::Kind::eUInt16:
				result = typesCache.getUInt16();
				break;
			case type::Kind::eUInt32:
				result = typesCache.getUInt32();
				break;
			case type::Kind::eUInt64:
				result = typesCache.getUInt64();
				break;
			case type::Kind::eHalf:
				result = typesCache.getHalf();
				break;
			case type::Kind::eFloat:
				result = typesCache.getFloat();
				break;
			case type::Kind::eDouble:
				result = typesCache.getDouble();
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
				result = typesCache.getVec2B();
				break;
			case type::Kind::eInt8:
				result = typesCache.getVec2I8();
				break;
			case type::Kind::eInt16:
				result = typesCache.getVec2I16();
				break;
			case type::Kind::eInt32:
				result = typesCache.getVec2I32();
				break;
			case type::Kind::eInt64:
				result = typesCache.getVec2I64();
				break;
			case type::Kind::eUInt8:
				result = typesCache.getVec2U8();
				break;
			case type::Kind::eUInt16:
				result = typesCache.getVec2U16();
				break;
			case type::Kind::eUInt32:
				result = typesCache.getVec2U32();
				break;
			case type::Kind::eUInt64:
				result = typesCache.getVec2U64();
				break;
			case type::Kind::eHalf:
				result = typesCache.getVec2H();
				break;
			case type::Kind::eFloat:
				result = typesCache.getVec2F();
				break;
			case type::Kind::eDouble:
				result = typesCache.getVec2D();
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
				result = typesCache.getVec3B();
				break;
			case type::Kind::eInt8:
				result = typesCache.getVec3I8();
				break;
			case type::Kind::eInt16:
				result = typesCache.getVec3I16();
				break;
			case type::Kind::eInt32:
				result = typesCache.getVec3I32();
				break;
			case type::Kind::eInt64:
				result = typesCache.getVec3I64();
				break;
			case type::Kind::eUInt8:
				result = typesCache.getVec3U8();
				break;
			case type::Kind::eUInt16:
				result = typesCache.getVec3U16();
				break;
			case type::Kind::eUInt32:
				result = typesCache.getVec3U32();
				break;
			case type::Kind::eUInt64:
				result = typesCache.getVec3U64();
				break;
			case type::Kind::eFloat:
				result = typesCache.getVec3F();
				break;
			case type::Kind::eDouble:
				result = typesCache.getVec3D();
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
				result = typesCache.getVec4B();
				break;
			case type::Kind::eInt8:
				result = typesCache.getVec4I8();
				break;
			case type::Kind::eInt16:
				result = typesCache.getVec4I16();
				break;
			case type::Kind::eInt32:
				result = typesCache.getVec4I32();
				break;
			case type::Kind::eInt64:
				result = typesCache.getVec4I64();
				break;
			case type::Kind::eUInt8:
				result = typesCache.getVec4U8();
				break;
			case type::Kind::eUInt16:
				result = typesCache.getVec4U16();
				break;
			case type::Kind::eUInt32:
				result = typesCache.getVec4U32();
				break;
			case type::Kind::eUInt64:
				result = typesCache.getVec4U64();
				break;
			case type::Kind::eHalf:
				result = typesCache.getVec4H();
				break;
			case type::Kind::eFloat:
				result = typesCache.getVec4F();
				break;
			case type::Kind::eDouble:
				result = typesCache.getVec4D();
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
			case type::Kind::eVec2F:
				result = typesCache.getMat2x2F();
				break;
			case type::Kind::eDouble:
			case type::Kind::eVec2D:
				result = typesCache.getMat2x2D();
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
			case type::Kind::eVec3F:
				result = typesCache.getMat2x3F();
				break;
			case type::Kind::eDouble:
			case type::Kind::eVec3D:
				result = typesCache.getMat2x3D();
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
			case type::Kind::eVec4F:
				result = typesCache.getMat2x4F();
				break;
			case type::Kind::eDouble:
			case type::Kind::eVec4D:
				result = typesCache.getMat2x4D();
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
			case type::Kind::eVec2F:
				result = typesCache.getMat3x2F();
				break;
			case type::Kind::eDouble:
			case type::Kind::eVec2D:
				result = typesCache.getMat3x2D();
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
			case type::Kind::eVec3F:
				result = typesCache.getMat3x3F();
				break;
			case type::Kind::eDouble:
			case type::Kind::eVec3D:
				result = typesCache.getMat3x3D();
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
			case type::Kind::eVec4F:
				result = typesCache.getMat3x4F();
				break;
			case type::Kind::eDouble:
			case type::Kind::eVec4D:
				result = typesCache.getMat3x4D();
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
			case type::Kind::eVec2F:
				result = typesCache.getMat4x2F();
				break;
			case type::Kind::eDouble:
			case type::Kind::eVec2D:
				result = typesCache.getMat4x2D();
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
			case type::Kind::eVec3F:
				result = typesCache.getMat4x3F();
				break;
			case type::Kind::eDouble:
			case type::Kind::eVec3D:
				result = typesCache.getMat4x3D();
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
			case type::Kind::eVec4F:
				result = typesCache.getMat4x4F();
				break;
			case type::Kind::eDouble:
			case type::Kind::eVec4D:
				result = typesCache.getMat4x4D();
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
