/*
See LICENSE file in root folder
*/
#include "ShaderWriter/ModernGraphicsWriterNV.hpp"

namespace sdw
{
	ModernGraphicsWriterNV::ModernGraphicsWriterNV( ShaderAllocator * allocator )
		: GraphicsPipelineWriter{ ast::ShaderStage::eModernGraphicsNV, allocator }
	{
	}

	ModernGraphicsWriterNV::ModernGraphicsWriterNV( ShaderBuilder & builder )
		: GraphicsPipelineWriter{ builder }
	{
		if ( builder.getType() != ast::ShaderStage::eModernGraphicsNV )
		{
			throw std::logic_error{ "Can't create a ModernGraphicsWriterNV from this kind of builder." };
		}
	}
}
