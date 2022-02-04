/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeSampledImage.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	SampledImage::SampledImage( TypesCache & cache
		, ImageConfiguration config
		, Trinary comparison )
		: Type{ cache, Kind::eSampledImage }
		, m_imageType{ cache.getImage( std::move( config ) ) }
		, m_depth{ comparison }
	{
	}
}
