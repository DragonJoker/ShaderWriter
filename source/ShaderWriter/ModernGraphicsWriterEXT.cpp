/*
See LICENSE file in root folder
*/
#include "ShaderWriter/ModernGraphicsWriterEXT.hpp"

namespace sdw
{
	ModernGraphicsWriterEXT::ModernGraphicsWriterEXT( ShaderAllocator * allocator )
		: PipelineWriter{ ast::ShaderStage::eModernGraphics, allocator }
	{
	}
	/**
	*name
	*	Fragment Shader.
	*/
	/**@{*/
	void ModernGraphicsWriterEXT::implementEntryPoint( FragmentMainFuncT< VoidT, VoidT > const & function )
	{
		implementEntryPointT( function );
	}

	void ModernGraphicsWriterEXT::implementEntryPoint( ast::FragmentOrigin origin
		, ast::FragmentCenter center
		, FragmentMainFuncT< VoidT, VoidT > const & function )
	{
		implementEntryPointT( origin, center, function );
	}
	/**@}*/
}
