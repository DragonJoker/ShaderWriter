/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Type/TypeSampler.hpp"

namespace ast::type
{
	Sampler::Sampler( bool comparison
		, uint32_t arraySize )
		: Type{ Kind::eSampler, arraySize }
		, m_comparison{ comparison }
	{
	}
}
