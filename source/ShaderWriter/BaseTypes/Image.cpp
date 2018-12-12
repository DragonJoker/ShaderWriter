/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Image.hpp"

namespace sdw
{
	Image::Image( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	Image::Image( Image const & rhs )
		: Value{ rhs.getShader(), makeExpr( *rhs.getShader(), rhs ) }
	{
	}

	Image::operator uint32_t()
	{
		return 0u;
	}
}
