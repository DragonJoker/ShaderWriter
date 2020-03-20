/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterDebug.hpp"

#include <ShaderAST/Debug/DebugStmtVisitor.hpp>
#include <ShaderAST/Shader.hpp>

namespace sdw
{
	std::string writeDebug( Shader const & shader )
	{
		return debug::StmtVisitor::submit( shader.getStatements() );
	}

	std::string writeDebug( stmt::Container * stmt )
	{
		return debug::StmtVisitor::submit( stmt );
	}
}
