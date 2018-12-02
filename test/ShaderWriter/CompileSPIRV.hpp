#pragma once

#include <ShaderWriter/ShaderWriterPrerequisites.hpp>

namespace test
{
	bool compileSpirV( sdw::Shader const & shader
		, std::vector< uint32_t > const & spirv
		,std::string & errors );
}
