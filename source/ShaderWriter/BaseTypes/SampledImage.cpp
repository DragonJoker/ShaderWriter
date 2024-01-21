/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/SampledImage.hpp"

namespace sdw
{
	SampledImage::SampledImage( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}
}
