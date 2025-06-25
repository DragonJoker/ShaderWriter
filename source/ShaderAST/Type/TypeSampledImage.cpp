/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeSampledImage.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	SampledImage::SampledImage( TypesCache & typesCache
		, ImageConfiguration const & config
		, Trinary comparison )
		: Type{ typesCache, Kind::eSampledImage, false }
		, m_imageType{ typesCache.getImage( config ) }
		, m_depth{ comparison }
	{
	}
}
