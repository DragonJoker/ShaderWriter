/*
See LICENSE file in root folder
*/
#include "CompilerHlsl/compileHlsl.hpp"

#include "HlslStmtAdapter.hpp"
#include "HlslStmtConfigFiller.hpp"
#include "HlslStmtVisitor.hpp"

#include <ShaderAST/Visitors/StmtSpecialiser.hpp>
#include <ShaderAST/Visitors/StmtSimplifier.hpp>

namespace hlsl
{
	std::string compileHlsl( ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, HlslConfig const & writerConfig )
	{
		auto intrinsicsConfig = hlsl::StmtConfigFiller::submit( shader );
		auto dxStatements = hlsl::StmtAdapter::submit( shader
			, intrinsicsConfig
			, writerConfig );
		auto simplified = ast::StmtSimplifier::submit( shader.getTypesCache()
			, shader.getStatements() );
		dxStatements = ast::StmtSpecialiser::submit( shader.getTypesCache(), dxStatements.get(), specialisation );
		return hlsl::StmtVisitor::submit( writerConfig, dxStatements.get() );
	}
}
