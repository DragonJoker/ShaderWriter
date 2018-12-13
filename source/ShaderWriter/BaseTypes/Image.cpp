/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Image.hpp"

namespace sdw
{
	Image::Image( ast::type::ImageFormat format
		, Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
		, m_format{ format }
	{
	}

	Image::Image( Image const & rhs )
		: Value{ rhs.getShader(), makeExpr( *rhs.getShader(), rhs ) }
		, m_format{ rhs.m_format }
	{
	}

	Image::operator uint32_t()
	{
		return 0u;
	}
}
