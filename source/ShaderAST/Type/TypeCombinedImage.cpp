/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeCombinedImage.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	CombinedImage::CombinedImage( TypesCache & typesCache
		, ImageConfiguration const & config
		, bool isComparison )
		: Type{ typesCache, Kind::eCombinedImage, false }
		, m_imageType{ typesCache.getImage( config ) }
		, m_samplerType{ typesCache.getSampler( isComparison ) }
	{
	}
}
