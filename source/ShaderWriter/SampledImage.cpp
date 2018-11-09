/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SampledImage.hpp"

namespace sdw
{
	SampledImage::SampledImage( Shader * shader
		, expr::ExprPtr expr
		, ast::type::ImageFormat format )
		: Value{ shader, std::move( expr ) }
		, m_format{ format }
	{
	}

	SampledImage::operator uint32_t()
	{
		return 0u;
	}
}
