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
		, m_format{ format }
	{
	}

	Image::Image( Image const & rhs )
		: Value{ *rhs.getWriter(), makeExpr( *rhs.getWriter(), rhs ), rhs.isEnabled() }
		, m_format{ rhs.m_format }
	{
	}

	Image::operator uint32_t()
	{
		return 0u;
	}
}
