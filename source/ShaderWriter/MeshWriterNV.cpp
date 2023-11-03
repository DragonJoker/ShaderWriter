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

	MeshWriterNV::MeshWriterNV( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eMeshNV, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eMeshNV
			&& builder.getType() != ast::ShaderStage::eModernGraphicsNV )
		{
			throw std::logic_error{ "Can't create a MeshWriterNV from this kind of builder." };
		}
	}
}
