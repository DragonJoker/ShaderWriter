/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterGlsl.hpp"

#include "ShaderWriter/Shader.hpp"
#include "ShaderWriter/GLSL/GlslStmtAdapter.hpp"
#include "ShaderWriter/GLSL/GlslStmtConfigFiller.hpp"
#include "ShaderWriter/GLSL/GlslStmtVisitor.hpp"

#include <ShaderAST/Visitors/StmtSpecialiser.hpp>

namespace sdw
{
	std::string compileGlsl( Shader const & shader
		, SpecialisationInfo const & specialisation
		, GlslConfig const & writerConfig )
	{
		auto intrinsicsConfig = glsl::StmtConfigFiller::submit( shader );
		auto glStatements = glsl::StmtAdapter::submit( shader
			, writerConfig
			, intrinsicsConfig );
		glStatements = ast::StmtSpecialiser::submit( glStatements.get(), specialisation );
		return glsl::StmtVisitor::submit( glStatements.get() );
	}
}
