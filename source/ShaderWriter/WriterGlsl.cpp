/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterGlsl.hpp"

#include "ShaderWriter/GLSL/GlslStmtVisitor.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	std::string writeGlsl( Shader & shader
		, ShaderType type )
	{
		return writeGlsl( shader.getStatements(), type );
	}

	std::string writeGlsl( stmt::Container * stmt, ShaderType type )
	{
		return glsl::StmtVisitor::submit( stmt );
	}
}
