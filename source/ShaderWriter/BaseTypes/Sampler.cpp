/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Sampler.hpp"

namespace sdw
{
	Sampler::Sampler( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	Sampler::operator uint32_t()
	{
		return 0u;
	}

	ast::type::TypePtr Sampler::makeType( ast::type::TypesCache & cache
		, bool isComparison )
	{
		return cache.getSampler( isComparison );
	}
}
