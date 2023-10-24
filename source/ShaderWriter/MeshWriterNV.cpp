/*
See LICENSE file in root folder
*/
#include "ShaderWriter/MeshWriterNV.hpp"

namespace sdw
{
	MeshWriterNV::MeshWriterNV( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eMeshNV, allocator }
	{
	}
}
