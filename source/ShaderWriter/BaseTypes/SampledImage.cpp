/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/SampledImage.hpp"

namespace sdw
{
	SampledImage::SampledImage( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	SampledImage::operator uint32_t()
	{
		return 0u;
	}
}
