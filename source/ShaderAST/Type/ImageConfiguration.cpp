/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/ImageConfiguration.hpp"

namespace ast::type
{
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
	}
}
