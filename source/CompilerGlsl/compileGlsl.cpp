/*
See LICENSE file in root folder
*/
#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslStmtAdapter.hpp"
#include "GlslStmtConfigFiller.hpp"
#include "GlslStmtVisitor.hpp"

#include <ShaderWriter/Shader.hpp>

#include <ShaderAST/Visitors/StmtSpecialiser.hpp>
#include <ShaderAST/Visitors/StmtSimplifier.hpp>

namespace glsl
{
	std::string compileGlsl( sdw::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig const & writerConfig )
	{
		auto simplified = ast::StmtSimplifier::submit( shader.getTypesCache()
			, shader.getStatements() );
		auto intrinsicsConfig = glsl::StmtConfigFiller::submit( simplified.get() );
		auto glStatements = glsl::StmtAdapter::submit( shader.getTypesCache()
			, simplified.get()
			, writerConfig
			, intrinsicsConfig );
		glStatements = ast::StmtSpecialiser::submit( shader.getTypesCache(), glStatements.get(), specialisation );
		return glsl::StmtVisitor::submit( writerConfig, glStatements.get() );
	}
}
