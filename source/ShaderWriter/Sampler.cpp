/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Sampler.hpp"

namespace sdw
{
	Sampler::Sampler( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	Sampler::operator uint32_t()
	{
		return 0u;
	}
}
