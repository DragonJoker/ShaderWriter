/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/SampledImage.hpp"

namespace sdw
{
	SampledImage::SampledImage( ast::type::ImageFormat /*format*/
		, ShaderWriter & writer
		, expr::ExprPtr expr )
		: Value{ writer, std::move( expr ) }
	{
	}

	SampledImage::operator uint32_t()
	{
		return 0u;
	}
}
