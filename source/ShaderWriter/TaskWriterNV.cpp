/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TaskWriterNV.hpp"

namespace sdw
{
	TaskWriterNV::TaskWriterNV( ShaderAllocator * allocator )
		: ShaderWriter{ ast::ShaderStage::eTaskNV, allocator }
	{
	}

	//*************************************************************************
}
