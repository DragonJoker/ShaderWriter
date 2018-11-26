/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeSampler.hpp"

namespace ast::type
{
	Sampler::Sampler( bool comparison )
		: Type{ Kind::eSampler }
		, m_comparison{ comparison }
	{
	}
}
