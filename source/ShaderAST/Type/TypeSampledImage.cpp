/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeSampledImage.hpp"

namespace ast::type
{
	SampledImage::SampledImage( ImageConfiguration config )
		: Type{ Kind::eSampledImage }
		, m_imageType{ makeImageType( std::move( config ) ) }
		, m_samplerType{ makeSamplerType( getConfig().isDepth == Trinary::eTrue ) }
	{
	}
}
