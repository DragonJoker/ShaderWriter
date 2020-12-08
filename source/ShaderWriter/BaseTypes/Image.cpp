/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Image.hpp"

namespace sdw
{
	Image::Image( ast::type::ImageFormat format
		, ShaderWriter & writer
		, expr::ExprPtr expr )
		: Value{ writer, std::move( expr ) }
		, m_format{ format }
	{
	}

	Image::Image( Image const & rhs )
		: Value{ *rhs.getWriter(), makeExpr( *rhs.getWriter(), rhs ) }
		, m_format{ rhs.m_format }
	{
	}

	Image::operator uint32_t()
	{
		return 0u;
	}
}
