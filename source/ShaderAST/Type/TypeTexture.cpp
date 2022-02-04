/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeTexture.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	Texture::Texture( TypesCache & cache
		, ImageConfiguration config
		, bool isComparison )
		: Type{ cache, Kind::eTexture }
		, m_imageType{ cache.getImage( std::move( config ) ) }
		, m_samplerType{ cache.getSampler( isComparison ) }
	{
	}
}
