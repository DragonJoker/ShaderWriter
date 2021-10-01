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
		auto intrinsicsConfig = hlsl::StmtConfigFiller::submit( shader );
		ast::SSAData ssaData;
		ssaData.nextVarId = shader.getData().nextVarId;
		auto ssaStatements = ast::transformSSA( shader.getTypesCache()
			, shader.getStatements()
			, ssaData );
		AdaptationData adaptationData{};
		adaptationData.aliasId = ssaData.aliasId;
		adaptationData.nextVarId = ssaData.nextVarId;
		auto dxStatements = hlsl::StmtAdapter::submit( shader
			, ssaStatements.get()
			, intrinsicsConfig
			, writerConfig
			, adaptationData );
		auto simplified = ast::StmtSimplifier::submit( shader.getTypesCache()
			, shader.getStatements() );
		dxStatements = ast::StmtSpecialiser::submit( shader.getTypesCache(), dxStatements.get(), specialisation );
		std::map< ast::var::VariablePtr, ast::expr::Expr * > aliases;
		return hlsl::StmtVisitor::submit( writerConfig, aliases, dxStatements.get() );
	}
}
