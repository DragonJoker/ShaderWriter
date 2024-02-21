/*
See LICENSE file in root folder
*/
#include "ShaderWriter/VertexWriter.hpp"

namespace sdw
{
	VertexWriter::VertexWriter( uint32_t flags
		, ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eVertex, flags, allocator }
	{
	}

	VertexWriter::VertexWriter( ShaderBuilder & builder
		, uint32_t flags )
		: EntryPointWriter{ ast::ShaderStage::eVertex, builder, flags }
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
