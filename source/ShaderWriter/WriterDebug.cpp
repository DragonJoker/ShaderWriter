/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterDebug.hpp"

#include "ShaderWriter/Shader.hpp"

#include <ASTGenerator/Debug/DebugStmtVisitor.hpp>

namespace sdw
{
	std::string writeDebug( Shader & shader )
	{
		return debug::StmtVisitor::submit( shader.getStatements() );
	}
}
