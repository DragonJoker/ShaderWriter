/*
See LICENSE file in root folder
*/
#include "ShaderWriter/VertexWriter.hpp"

namespace sdw
{
	VertexWriter::VertexWriter( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eVertex, allocator }
	{
	}

	VertexWriter::VertexWriter( ShaderBuilder & builder )
		: EntryPointWriter{ builder }
	{
	}

	void VertexWriter::implementMain( VertexMainFuncT< VoidT, VoidT > const & function )
	{
		implementMainT( function );
	}
}
