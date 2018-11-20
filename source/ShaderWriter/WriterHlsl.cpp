/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterHlsl.hpp"

#include "ShaderWriter/StmtSpecialiser.hpp"
#include "ShaderWriter/HLSL/HlslStmtAdapter.hpp"
#include "ShaderWriter/HLSL/HlslStmtConfigFiller.hpp"
#include "ShaderWriter/HLSL/HlslStmtVisitor.hpp"

namespace sdw
{
	std::string compileHlsl( Shader const & shader
		, ShaderType type
		, SpecialisationInfo const & specialisation )
	{
		auto config = hlsl::StmtConfigFiller::submit( shader );
		auto dxStatements = hlsl::StmtAdapter::submit( shader, type, config );
		dxStatements = StmtSpecialiser::submit( dxStatements.get(), specialisation );
		return hlsl::StmtVisitor::submit( dxStatements.get(), type );
	}
}
