/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterDebug.hpp"

#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>
#include <ShaderAST/Shader.hpp>

namespace sdw
{
	std::string writeDebug( Shader const & shader )
	{
		return debug::displayStatements( shader.getStatements() );
	}

	std::string writeDebug( stmt::Container * stmt )
	{
		return debug::displayStatements( stmt );
	}
}
