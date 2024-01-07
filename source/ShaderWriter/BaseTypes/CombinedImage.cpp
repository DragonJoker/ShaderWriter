/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/CombinedImage.hpp"

namespace sdw
{
	CombinedImage::CombinedImage( ast::type::ImageFormat /*format*/
		, ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}
}
