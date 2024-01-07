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
		: EntryPointWriter{ ast::ShaderStage::eVertex, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eVertex
			&& builder.getType() != ast::ShaderStage::eTraditionalGraphics )
		{
			throw ast::Exception{ "Can't create a VertexWriter from this kind of builder." };
		}
	}

	void VertexWriter::implementMain( VertexMainFuncT< VoidT, VoidT > const & function )
	{
		implementMainT( function );
	}
}
