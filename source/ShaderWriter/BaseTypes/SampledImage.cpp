/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/SampledImage.hpp"

namespace sdw
{
	SampledImage::SampledImage( ast::type::ImageFormat format
		, Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
		, m_format{ format }
	{
	}

	SampledImage::operator uint32_t()
	{
		return 0u;
	}
}
