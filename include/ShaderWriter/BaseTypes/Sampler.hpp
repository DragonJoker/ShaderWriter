/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Sampler_H___
#define ___SDW_Sampler_H___

#include "ShaderWriter/Value.hpp"

namespace sdw
{
	struct Sampler
		: public Value
	{
		Sampler( Shader * shader
			, expr::ExprPtr expr );
		template< typename T >
		inline Sampler & operator=( T const & rhs );
		operator uint32_t();

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "Sampler.inl"

#endif
