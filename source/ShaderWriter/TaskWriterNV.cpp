/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TaskWriterNV.hpp"

namespace sdw
{
	TaskWriterNV::TaskWriterNV( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eTaskNV, allocator }
	{
	}

	TaskWriterNV::TaskWriterNV( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eTaskNV, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eTaskNV
			&& builder.getType() != ast::ShaderStage::eModernGraphicsNV )
		{
			throw std::logic_error{ "Can't create a TaskWriterNV from this kind of builder." };
		}
	}
}
