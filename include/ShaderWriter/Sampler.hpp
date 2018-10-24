/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SAMPLER_H___
#define ___SDW_SAMPLER_H___

#include "Value.hpp"

namespace sdw
{
	template< SamplerType ST >
	struct SamplerT
		: public Value
	{
		inline SamplerT( Shader * shader
			, expr::ExprPtr expr );
		template< typename T > inline SamplerT & operator=( T const & rhs );
		inline operator uint32_t();
	};
}

#include "Sampler.inl"

#endif
