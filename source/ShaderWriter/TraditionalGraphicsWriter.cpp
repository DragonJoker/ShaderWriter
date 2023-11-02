/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TraditionalGraphicsWriter.hpp"

namespace sdw
{
	TraditionalGraphicsWriter::TraditionalGraphicsWriter( ShaderAllocator * allocator )
		: PipelineWriter{ ast::ShaderStage::eTraditionalGraphics, allocator }
	{
	}

	TraditionalGraphicsWriter::TraditionalGraphicsWriter( ShaderBuilder & builder )
		: PipelineWriter{ builder }
	{
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
	/**
	*name
	*	Fragment Shader.
	*/
	/**@{*/
	void TraditionalGraphicsWriter::implementEntryPoint( FragmentMainFuncT< VoidT, VoidT > const & function )
	{
		implementEntryPointT( function );
	}

	void TraditionalGraphicsWriter::implementEntryPoint( ast::FragmentOrigin origin
		, ast::FragmentCenter center
		, FragmentMainFuncT< VoidT, VoidT > const & function )
	{
		implementEntryPointT( origin, center, function );
	}
	/**@}*/
}
