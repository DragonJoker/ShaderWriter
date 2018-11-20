#pragma once

#include <ShaderWriter/ShaderWriterPrerequisites.hpp>

namespace test
{
	bool compileHlsl( std::string const & shader
		, sdw::ShaderType type
		, std::string & errors );
}
