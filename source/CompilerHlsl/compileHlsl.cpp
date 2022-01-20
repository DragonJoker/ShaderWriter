/*
See LICENSE file in root folder
*/
#include "CompilerHlsl/compileHlsl.hpp"

#include "HlslStmtAdapter.hpp"
#include "HlslStmtConfigFiller.hpp"
#include "HlslStmtVisitor.hpp"

#include <ShaderAST/Visitors/StmtSpecialiser.hpp>
#include <ShaderAST/Visitors/StmtSimplifier.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

namespace hlsl
{
	std::string compileHlsl( ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, HlslConfig const & writerConfig )
	{
		auto config = writerConfig;
		config.shaderStage = shader.getType();
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto ssaStatements = ast::transformSSA( shader.getTypesCache()
			, shader.getStatements()
			, ssaData );
		HlslShader hlslShader{ shader };
		AdaptationData adaptationData{ hlslShader };
		adaptationData.aliasId = ssaData.aliasId;
		adaptationData.nextVarId = ssaData.nextVarId;

		auto intrinsicsConfig = hlsl::StmtConfigFiller::submit( hlslShader
			, adaptationData
			, ssaStatements.get() );

		auto dxStatements = hlsl::StmtAdapter::submit( hlslShader
			, ssaStatements.get()
			, intrinsicsConfig
			, config
			, adaptationData );
		dxStatements = ast::StmtSimplifier::submit( shader.getTypesCache()
			, dxStatements.get() );
		dxStatements = ast::StmtSpecialiser::submit( shader.getTypesCache(), dxStatements.get(), specialisation );
		std::map< ast::var::VariablePtr, ast::expr::Expr * > aliases;
		return hlsl::StmtVisitor::submit( config, adaptationData.getRoutines(), aliases, dxStatements.get() );
	}
}
