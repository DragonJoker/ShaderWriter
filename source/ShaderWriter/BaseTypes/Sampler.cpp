/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Sampler.hpp"

namespace sdw
{
	Sampler::Sampler( ShaderWriter & writer
		, expr::ExprPtr expr )
		: Value{ writer, std::move( expr ) }
	{
	}

	Sampler::operator uint32_t()
	{
		return 0u;
	}

	ast::type::TypePtr Sampler::makeType( ast::type::TypesCache & cache )
	{
		return cache.getSampler();
	}
}
