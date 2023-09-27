/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeCombinedImage.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	CombinedImage::CombinedImage( TypesCache & typesCache
		, ImageConfiguration config
		, bool isComparison )
		: Type{ typesCache, Kind::eCombinedImage }
		, m_imageType{ typesCache.getImage( std::move( config ) ) }
		, m_samplerType{ typesCache.getSampler( isComparison ) }
	{
	}
}
