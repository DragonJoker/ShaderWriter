/*
See LICENSE file in root folder
*/
#include "ShaderWriter/ModernGraphicsWriterNV.hpp"

namespace sdw
{
	ModernGraphicsWriterNV::ModernGraphicsWriterNV( ShaderAllocator * allocator )
		: PipelineWriter{ ast::ShaderStage::eModernGraphicsNV, allocator }
	{
	}

	ModernGraphicsWriterNV::ModernGraphicsWriterNV( ShaderBuilder & builder )
		: PipelineWriter{ builder }
	{
	}
	/**
	*name
	*	Fragment Shader.
	*/
	/**@{*/
	void ModernGraphicsWriterNV::implementEntryPoint( FragmentMainFuncT< VoidT, VoidT > const & function )
	{
		implementEntryPointT( function );
	}

	void ModernGraphicsWriterNV::implementEntryPoint( ast::FragmentOrigin origin
		, ast::FragmentCenter center
		, FragmentMainFuncT< VoidT, VoidT > const & function )
	{
		implementEntryPointT( origin, center, function );
	}
	/**@}*/
}
