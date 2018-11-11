/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Type/TypeSampledImage.hpp"

namespace ast::type
{
	SampledImage::SampledImage( ImageConfiguration config
		, uint32_t arraySize )
		: Type{ Kind::eSampledImage, arraySize }
		, m_imageType{ makeImageType( std::move( config ) ) }
		, m_samplerType{ makeSamplerType( getConfig().isDepth == Trinary::eTrue ) }
	{
	}
}
