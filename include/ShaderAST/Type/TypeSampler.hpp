/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeSampler_H___
#define ___AST_TypeSampler_H___
#pragma once

#include "Type.hpp"

#include <vector>

namespace ast::type
{
	class Sampler
		: public Type
	{
	public:
		SDAST_API Sampler( TypesCache & typesCache
			, bool comparison );

		bool isComparison()const
		{
			return m_comparison;
		}

	private:
		bool m_comparison;
	};
	using SamplerPtr = std::shared_ptr< Sampler >;
}

#endif
