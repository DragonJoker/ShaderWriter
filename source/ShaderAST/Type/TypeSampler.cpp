/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeSampler.hpp"

namespace ast::type
{
	Sampler::Sampler( TypesCache * cache
		, bool comparison )
		: Type{ cache, Kind::eSampler }
		, m_comparison{ comparison }
	{
	}
}
