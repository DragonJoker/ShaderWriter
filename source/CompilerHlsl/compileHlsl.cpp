/*
See LICENSE file in root folder
*/
#include "CompilerHlsl/compileHlsl.hpp"

#include "HlslStmtAdapter.hpp"
#include "HlslStmtConfigFiller.hpp"
#include "HlslStmtVisitor.hpp"

#include <ShaderAST/Visitors/StmtSpecialiser.hpp>

namespace hlsl
{
	std::string compileHlsl( sdw::Shader const & shader
		, ast::SpecialisationInfo const & specialisation )
	{
		auto config = hlsl::StmtConfigFiller::submit( shader );
		auto dxStatements = hlsl::StmtAdapter::submit( shader, config );
		dxStatements = ast::StmtSpecialiser::submit( shader.getTypesCache(), dxStatements.get(), specialisation );
		return hlsl::StmtVisitor::submit( dxStatements.get(), shader.getType() );
	}
}
