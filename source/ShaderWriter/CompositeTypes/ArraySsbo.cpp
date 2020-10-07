/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/ArraySsbo.hpp"

#include <ShaderAST/Shader.hpp>

namespace sdw
{
	void registerSsbo( Shader & shader, std::string const & name, SsboInfo const & info )
	{
		shader.registerSsbo( name, info );
	}
}
