/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeSampledImage.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	SampledImage::SampledImage( TypesCache & typesCache
		, ImageConfiguration config
		, Trinary comparison )
		: Type{ typesCache, Kind::eSampledImage }
		, m_imageType{ typesCache.getImage( std::move( config ) ) }
		, m_depth{ comparison }
	{
	}
}
