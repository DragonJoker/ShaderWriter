/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/ImageConfiguration.hpp"

namespace ast::type
{
	TypePtr getType( ImageFormat format )
	{
		switch ( format )
		{
		case ImageFormat::eUnknown:
			return makeType( sampledType< ImageFormat::eUnknown > );
		case ImageFormat::eRgba32f:
			return makeType( sampledType< ImageFormat::eRgba32f > );
		case ImageFormat::eRgba16f:
			return makeType( sampledType< ImageFormat::eRgba16f > );
		case ImageFormat::eRg32f:
			return makeType( sampledType< ImageFormat::eRg32f > );
		case ImageFormat::eRg16f:
			return makeType( sampledType< ImageFormat::eRg16f > );
		case ImageFormat::eR32f:
			return makeType( sampledType< ImageFormat::eR32f > );
		case ImageFormat::eR16f:
			return makeType( sampledType< ImageFormat::eR16f > );
		case ImageFormat::eRgba32i:
			return makeType( sampledType< ImageFormat::eRgba32i > );
		case ImageFormat::eRgba16i:
			return makeType( sampledType< ImageFormat::eRgba16i > );
		case ImageFormat::eRgba8i:
			return makeType( sampledType< ImageFormat::eRgba8i > );
		case ImageFormat::eRg32i:
			return makeType( sampledType< ImageFormat::eRg32i > );
		case ImageFormat::eRg16i:
			return makeType( sampledType< ImageFormat::eRg16i > );
		case ImageFormat::eRg8i:
			return makeType( sampledType< ImageFormat::eRg8i > );
		case ImageFormat::eR32i:
			return makeType( sampledType< ImageFormat::eR32i > );
		case ImageFormat::eR16i:
			return makeType( sampledType< ImageFormat::eR16i > );
		case ImageFormat::eR8i:
			return makeType( sampledType< ImageFormat::eR8i > );
		case ImageFormat::eRgba32u:
			return makeType( sampledType< ImageFormat::eRgba32u > );
		case ImageFormat::eRgba16u:
			return makeType( sampledType< ImageFormat::eRgba16u > );
		case ImageFormat::eRgba8u:
			return makeType( sampledType< ImageFormat::eRgba8u > );
		case ImageFormat::eRg32u:
			return makeType( sampledType< ImageFormat::eRg32u > );
		case ImageFormat::eRg16u:
			return makeType( sampledType< ImageFormat::eRg16u > );
		case ImageFormat::eRg8u:
			return makeType( sampledType< ImageFormat::eRg8u > );
		case ImageFormat::eR32u:
			return makeType( sampledType< ImageFormat::eR32u > );
		case ImageFormat::eR16u:
			return makeType( sampledType< ImageFormat::eR16u > );
		case ImageFormat::eR8u:
			return makeType( sampledType< ImageFormat::eR8u > );
		default:
			assert( false && "hlsl::getType: Unsupported ImageFormat" );
			return nullptr;
		}
	}

	bool isFloatFormat( ImageFormat format )
	{
		return format == ImageFormat::eUnknown
			|| format == ImageFormat::eRgba32f
			|| format == ImageFormat::eRgba16f
			|| format == ImageFormat::eRg32f
			|| format == ImageFormat::eRg16f
			|| format == ImageFormat::eR32f
			|| format == ImageFormat::eR16f;
	}

	bool isSIntFormat( ImageFormat format )
	{
		return format == ImageFormat::eUnknown
			|| format == ImageFormat::eRgba32i
			|| format == ImageFormat::eRgba16i
			|| format == ImageFormat::eRgba8i
			|| format == ImageFormat::eRg32i
			|| format == ImageFormat::eRg16i
			|| format == ImageFormat::eRg8i
			|| format == ImageFormat::eR32i
			|| format == ImageFormat::eR16i
			|| format == ImageFormat::eR8i;
	}

	bool isUIntFormat( ImageFormat format )
	{
		return format == ImageFormat::eUnknown
			|| format == ImageFormat::eRgba32u
			|| format == ImageFormat::eRgba16u
			|| format == ImageFormat::eRgba8u
			|| format == ImageFormat::eRg32u
			|| format == ImageFormat::eRg16u
			|| format == ImageFormat::eRg8u
			|| format == ImageFormat::eR32u
			|| format == ImageFormat::eR16u
			|| format == ImageFormat::eR8u;
	}

	ImageConfiguration::ImageConfiguration( type::Kind sampledType
		, ImageDim dimension
		, ImageFormat format
		, Trinary isDepth
		, Trinary isSampled
		, bool isArrayed
		, bool isMS
		, AccessKind accessKind )
		: sampledType{ sampledType }
		, dimension{ dimension }
		, format{ format }
		, isDepth{ isDepth }
		, isSampled{ isSampled }
		, isArrayed{ isArrayed }
		, isMS{ isMS }
		, accessKind{ accessKind }
	{
		assert( ( this->sampledType == type::Kind::eFloat && isFloatFormat( format ) )
			|| ( this->sampledType == type::Kind::eInt && isSIntFormat( format ) )
			|| ( this->sampledType == type::Kind::eUInt && isUIntFormat( format ) )
			|| ( format == ImageFormat::eUnknown ) );
	}

	size_t getHash( type::ImageConfiguration const & config )
	{
		size_t result = std::hash< type::ImageDim >{}( config.dimension );
		result = hashCombine( result, config.format );
		result = hashCombine( result, config.isDepth );
		result = hashCombine( result, config.isSampled );
		result = hashCombine( result, config.isArrayed );
		result = hashCombine( result, config.isMS );
		result = hashCombine( result, config.accessKind );
		return result;
	}}
