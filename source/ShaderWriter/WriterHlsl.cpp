/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterHlsl.hpp"

#include "ShaderWriter/HLSL/HlslStmtAdapter.hpp"
#include "ShaderWriter/HLSL/HlslStmtConfigFiller.hpp"
#include "ShaderWriter/HLSL/HlslStmtVisitor.hpp"
#include "ShaderWriter/Visitors/StmtSpecialiser.hpp"

namespace sdw
{
	std::string compileHlsl( Shader const & shader
		, SpecialisationInfo const & specialisation )
	{
		auto config = hlsl::StmtConfigFiller::submit( shader );
		auto dxStatements = hlsl::StmtAdapter::submit( shader, config );
		dxStatements = StmtSpecialiser::submit( dxStatements.get(), specialisation );
		return hlsl::StmtVisitor::submit( dxStatements.get(), shader.getType() );
	}
}
