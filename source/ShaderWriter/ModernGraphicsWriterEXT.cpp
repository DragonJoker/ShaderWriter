/*
See LICENSE file in root folder
*/
#include "ShaderWriter/ModernGraphicsWriterEXT.hpp"

namespace sdw
{
	ModernGraphicsWriterEXT::ModernGraphicsWriterEXT( ShaderAllocator * allocator )
		: GraphicsPipelineWriter{ ast::ShaderStage::eModernGraphicsEXT, allocator }
	{
	}

	ModernGraphicsWriterEXT::ModernGraphicsWriterEXT( ShaderBuilder & builder )
		: GraphicsPipelineWriter{ builder }
	{
		if ( builder.getType() != ast::ShaderStage::eModernGraphicsEXT )
		{
			throw ast::Exception{ "Can't create a ModernGraphicsWriterEXT from this kind of builder." };
		}
	}
}
