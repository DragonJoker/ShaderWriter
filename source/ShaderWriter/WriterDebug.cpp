/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterDebug.hpp"

#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>
#include <ShaderAST/Visitors/PreprocessShader.hpp>
#include <ShaderAST/Shader.hpp>

namespace sdw
{
	std::string writePreprocessedDebug( Shader const & shader
		, ast::PreprocessResult & preprocessResult )
	{
		return debug::displayStatements( *preprocessResult.statements );
	}
}
