/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GraphicsPipelineWriter.hpp"

#include <ShaderAST/Stmt/StmtDemote.hpp>
#include <ShaderAST/Stmt/StmtTerminateInvocation.hpp>

namespace sdw
{
	GraphicsPipelineWriter::GraphicsPipelineWriter( ast::ShaderStage type
		, ShaderAllocator * allocator )
		: PipelineWriter{ type, allocator }
	{
	}

	GraphicsPipelineWriter::GraphicsPipelineWriter( ShaderBuilder & builder )
		: PipelineWriter{ builder }
	{
		if ( builder.getType() != ast::ShaderStage::eTraditionalGraphics
			&& builder.getType() != ast::ShaderStage::eModernGraphicsEXT
			&& builder.getType() != ast::ShaderStage::eModernGraphicsNV )
		{
			throw ast::Exception{ "Can't create a GraphicsPipelineWriter from this kind of builder." };
		}
	}
	/**
	*name
	*	Fragment Shader.
	*/
	/**@{*/
	void GraphicsPipelineWriter::implementEntryPoint( FragmentMainFuncT< VoidT, VoidT > const & function )
	{
		implementEntryPointT( function );
	}

	void GraphicsPipelineWriter::implementEntryPoint( ast::FragmentOrigin origin
		, ast::FragmentCenter center
		, FragmentMainFuncT< VoidT, VoidT > const & function )
	{
		implementEntryPointT( origin, center, function );
	}
	/**@}*/
}
