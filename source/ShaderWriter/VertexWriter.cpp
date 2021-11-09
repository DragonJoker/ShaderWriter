/*
See LICENSE file in root folder
*/
#include "ShaderWriter/VertexWriter.hpp"

namespace sdw
{
	VertexWriter::VertexWriter()
		: ShaderWriter{ ast::ShaderStage::eVertex }
	{
	}

	void VertexWriter::implementMain( VertexMainFuncT< VoidT, VoidT > const & function )
	{
		implementMainT( function );
	}
}
