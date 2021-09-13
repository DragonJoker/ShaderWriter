/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/ImageConfiguration.hpp"

namespace ast::type
{
	ImageConfiguration::ImageConfiguration( type::Kind newSampledType
		, ImageDim newDimension
		, ImageFormat newFormat
		, Trinary newIsDepth
		, Trinary newIsSampled
		, bool newIsArrayed
		, bool newIsMS
		, AccessKind newAccessKind )noexcept
		: sampledType{ newSampledType }
		, dimension{ newDimension }
		, format{ newFormat }
		, isDepth{ newIsDepth }
		, isSampled{ newIsSampled }
		, isArrayed{ newIsArrayed }
		, isMS{ newIsMS }
		, accessKind{ newAccessKind }
	{
		assert( ( this->sampledType == type::Kind::eHalf && isFloatFormat( format ) )
			|| ( this->sampledType == type::Kind::eFloat && isFloatFormat( format ) )
			|| ( this->sampledType == type::Kind::eInt && isSIntFormat( format ) )
			|| ( this->sampledType == type::Kind::eUInt && isUIntFormat( format ) )
			|| ( format == ImageFormat::eUnknown ) );
	}

	size_t getHash( type::ImageConfiguration const & config )noexcept
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
