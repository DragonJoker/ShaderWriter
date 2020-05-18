/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalVoid_H___
#define ___SDW_OptionalVoid_H___
#pragma once

#include "Optional.hpp"
#include "ShaderWriter/BaseTypes/Void.hpp"

namespace sdw
{
	template<>
	struct Optional< Void >
		: public Void
	{
		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled )
			: Void{ shader, std::move( expr ), enabled }
			, m_enabled{ enabled }
		{
		}

		inline Optional( Void const & other
			, bool enabled )
			: Void{ other }
			, m_enabled{ enabled }
		{
		}

		inline Optional( Optional const & rhs )
			: Void{ static_cast< Void const & >( rhs ) }
			, m_enabled{ rhs.m_enabled }
		{
		}

		inline Optional< Void > operator=( Optional< Void > const & rhs )
		{
			return *this;
		}

		inline bool isEnabled()const
		{
			return m_enabled;
		}

	private:
		bool m_enabled;
	};
}

#endif
