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
		auto config = writerConfig;
		config.shaderStage = shader.getType();
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto statements = ast::transformSSA( shader.getTypesCache()
			, shader.getStatements()
			, ssaData );
		statements = ast::StmtSimplifier::submit( shader.getTypesCache()
			, statements.get() );
		glsl::AdaptationData adaptationData{ shader.getType()
			, config
			, glsl::StmtConfigFiller::submit( statements.get() )
			, ssaData.nextVarId };
		statements = glsl::StmtAdapter::submit( shader.getTypesCache()
			, statements.get()
			, adaptationData );
		// Simplify again, since adaptation can introduce complexity
		statements = ast::StmtSimplifier::submit( shader.getTypesCache()
			, statements.get() );
		statements = ast::StmtSpecialiser::submit( shader.getTypesCache(), statements.get(), specialisation );
		std::map< ast::var::VariablePtr, ast::expr::Expr * > aliases;
		return glsl::StmtVisitor::submit( config, aliases, statements.get() );
	}
}
