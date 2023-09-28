/*
See LICENSE file in root folder
*/
#include "ShaderWriter/VertexWriter.hpp"

namespace sdw
{
	VertexWriter::VertexWriter( ShaderAllocator * allocator )
		: ShaderWriter{ ast::ShaderStage::eVertex, allocator }
	{
	}

	void VertexWriter::implementMain( VertexMainFuncT< VoidT, VoidT > const & function )
	{
		implementMainT( function );
	}
}
