/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/StructuredUbo.hpp"

#include <ShaderAST/Shader.hpp>

namespace sdw
{
	void registerUbo( Shader & shader, std::string const & name, UboInfo const & info )
	{
		shader.registerUbo( name, info );
	}
}
