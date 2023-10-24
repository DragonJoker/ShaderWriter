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

	//*************************************************************************
}
