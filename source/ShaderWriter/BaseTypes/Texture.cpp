/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Texture.hpp"

namespace sdw
{
	Texture::Texture( ast::type::ImageFormat /*format*/
		, ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	Texture::operator uint32_t()
	{
		return 0u;
	}
}
