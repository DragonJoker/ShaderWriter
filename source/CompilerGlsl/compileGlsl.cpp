/*
See LICENSE file in root folder
*/
#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslStmtAdapter.hpp"
#include "GlslStmtConfigFiller.hpp"
#include "GlslStmtVisitor.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Visitors/StmtSpecialiser.hpp>
#include <ShaderAST/Visitors/StmtSimplifier.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

namespace glsl
{
	std::string compileGlsl( ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig const & writerConfig )
	{
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto ssaStatements = ast::transformSSA( shader.getTypesCache()
			, shader.getStatements()
			, ssaData );
		auto simplified = ast::StmtSimplifier::submit( shader.getTypesCache()
			, ssaStatements.get() );
		auto intrinsicsConfig = glsl::StmtConfigFiller::submit( simplified.get() );
		auto glStatements = glsl::StmtAdapter::submit( shader.getTypesCache()
			, simplified.get()
			, writerConfig
			, intrinsicsConfig );
		glStatements = ast::StmtSpecialiser::submit( shader.getTypesCache(), glStatements.get(), specialisation );
		std::map< ast::var::VariablePtr, ast::expr::Expr * > aliases;
		return glsl::StmtVisitor::submit( writerConfig, aliases, glStatements.get() );
	}
}
