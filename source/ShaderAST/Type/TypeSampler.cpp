/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeSampler.hpp"

namespace ast::type
{
	Sampler::Sampler( TypesCache & typesCache
		, bool comparison )
		: Type{ typesCache, Kind::eSampler }
		, m_comparison{ comparison }
	{
	}
}
