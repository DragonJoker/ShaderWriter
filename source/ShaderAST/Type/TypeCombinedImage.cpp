/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeCombinedImage.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	CombinedImage::CombinedImage( TypesCache & cache
		, ImageConfiguration config
		, bool isComparison )
		: Type{ cache, Kind::eCombinedImage }
		, m_imageType{ cache.getImage( std::move( config ) ) }
		, m_samplerType{ cache.getSampler( isComparison ) }
	{
	}
}
