/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TraditionalGraphicsWriter.hpp"

namespace sdw
{
	TraditionalGraphicsWriter::TraditionalGraphicsWriter( ShaderAllocator * allocator )
		: GraphicsPipelineWriter{ ast::ShaderStage::eTraditionalGraphics, allocator }
	{
	}

	TraditionalGraphicsWriter::TraditionalGraphicsWriter( ShaderBuilder & builder )
		: GraphicsPipelineWriter{ builder }
	{
		if ( builder.getType() != ast::ShaderStage::eTraditionalGraphics )
		{
			throw ast::Exception{ "Can't create a TraditionalGraphicsWriter from this kind of builder." };
		}
	}
	/**
	*name
	*	Vertex Shader.
	*/
	/**@{*/
	void TraditionalGraphicsWriter::implementEntryPoint( VertexMainFuncT< VoidT, VoidT > const & function )
	{
		implementEntryPointT( function );
	}
	/**@}*/
}
