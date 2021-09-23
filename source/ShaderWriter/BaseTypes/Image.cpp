/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Image.hpp"

namespace sdw
{
	Image::Image( ast::type::ImageFormat format
		, ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	Image::operator uint32_t()
	{
		return 0u;
	}
}
