/*
See LICENSE file in root folder
*/
#include "ShaderWriter/MeshWriterNV.hpp"

namespace sdw
{
	MeshWriterNV::MeshWriterNV( ShaderAllocator * allocator )
		: ShaderWriter{ ast::ShaderStage::eMeshNV, allocator }
	{
	}
}
