/*
See LICENSE file in root folder
*/
#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslStmtAdapter.hpp"
#include "GlslStmtConfigFiller.hpp"
#include "GlslStmtVisitor.hpp"

#include <ShaderWriter/Shader.hpp>

#include <ShaderAST/Visitors/StmtSpecialiser.hpp>

namespace glsl
{
	std::string compileGlsl( sdw::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
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
