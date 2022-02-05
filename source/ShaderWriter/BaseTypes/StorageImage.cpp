/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/StorageImage.hpp"

namespace sdw
{
	StorageImage::StorageImage( ast::type::ImageFormat format
		, ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	StorageImage::operator uint32_t()
	{
		return 0u;
	}
}
