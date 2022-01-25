/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/ArraySsbo.hpp"
#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Shader.hpp>

namespace sdw
{
	void registerSsbo( ShaderWriter & writer
		, std::string name
		, SsboInfo const & info )
	{
		writer.getShader().registerSsbo( std::move( name ), info );
	}
}
