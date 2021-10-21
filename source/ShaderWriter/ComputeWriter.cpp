/*
See LICENSE file in root folder
*/
#include "ShaderWriter/ComputeWriter.hpp"

namespace sdw
{
	ComputeWriter::ComputeWriter()
		: ShaderWriter{ ast::ShaderStage::eCompute }
	{
	}
}
