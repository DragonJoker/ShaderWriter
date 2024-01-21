/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/CombinedImage.hpp"

namespace sdw
{
	CombinedImage::CombinedImage( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}
}
