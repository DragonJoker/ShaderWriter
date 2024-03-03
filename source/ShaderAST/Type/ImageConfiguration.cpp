/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/ImageConfiguration.hpp"

namespace ast::type
{
	ImageConfiguration::ImageConfiguration( type::Kind newSampledType
		, ImageDim newDimension
		, ImageFormat newFormat
		, Trinary newIsSampled
		, bool newIsArrayed
		, bool newIsMS
		, AccessKind newAccessKind )noexcept
		: sampledType{ newSampledType }
		, dimension{ newDimension }
		, format{ newFormat }
		, isSampled{ newIsSampled }
		, isArrayed{ newIsArrayed }
		, isMS{ newIsMS }
		, accessKind{ newAccessKind }
	{
		assert( ( this->sampledType == type::Kind::eHalf && isFloatFormat( format ) )
			|| ( this->sampledType == type::Kind::eVec2H && isFloatFormat( format ) )
			|| ( this->sampledType == type::Kind::eVec4H && isFloatFormat( format ) )
			|| ( this->sampledType == type::Kind::eFloat && isFloatFormat( format ) )
			|| ( this->sampledType == type::Kind::eVec2F && isFloatFormat( format ) )
			|| ( this->sampledType == type::Kind::eVec4F && isFloatFormat( format ) )
			|| ( this->sampledType == type::Kind::eInt && isSIntFormat( format ) )
			|| ( this->sampledType == type::Kind::eVec2I && isSIntFormat( format ) )
			|| ( this->sampledType == type::Kind::eVec4I && isSIntFormat( format ) )
			|| ( this->sampledType == type::Kind::eUInt && isUIntFormat( format ) )
			|| ( this->sampledType == type::Kind::eVec2U && isUIntFormat( format ) )
			|| ( this->sampledType == type::Kind::eVec4U && isUIntFormat( format ) )
			|| ( format == ImageFormat::eUnknown ) );
	}

	size_t getHash( type::ImageConfiguration const & config )noexcept
	{
		size_t result = std::hash< type::ImageDim >{}( config.dimension );
		result = hashCombine( result, config.format );
		result = hashCombine( result, config.isSampled );
		result = hashCombine( result, config.isArrayed );
		result = hashCombine( result, config.isMS );
		result = hashCombine( result, config.accessKind );
		return result;
	}

	size_t getHash( type::ImageConfiguration const & config
		, bool isComparison )noexcept
	{
		auto result = getHash( config );
		result = hashCombine( result, isComparison );
		return result;
	}
}
