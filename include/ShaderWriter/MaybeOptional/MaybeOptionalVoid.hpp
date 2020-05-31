/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalVoid_H___
#define ___SDW_MaybeOptionalVoid_H___
#pragma once

#include "MaybeOptional.hpp"
#include "ShaderWriter/Optional/OptionalVoid.hpp"

namespace sdw
{
	template<>
	struct MaybeOptional< Void >
		: public Void
	{
		using MyValue = Void;

	public:
		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr )
			: Void{ shader, std::move( expr ) }
			, m_optional{ false }
			, m_enabled{ true }
		{
		}

		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled )
			: Void{ shader, std::move( expr ) }
			, m_optional{ true }
			, m_enabled{ enabled }
		{
		}

		inline MaybeOptional( Void const & rhs )
			: Void{ rhs }
			, m_optional{ false }
			, m_enabled{ true }
		{
		}

		inline MaybeOptional( Optional< Void > const & rhs )
			: Void{ static_cast< Void const & >( rhs ) }
			, m_optional{ true }
			, m_enabled{ rhs.isEnabled() }
		{
		}

		inline MaybeOptional( MaybeOptional< Void > const & rhs )
			: Void{ static_cast< Void const & >( rhs ) }
			, m_optional{ rhs.isOptional() }
			, m_enabled{ rhs.isEnabled() }
		{
		}

		inline operator Void const & ()const
		{
			return *this;
		}

		inline operator Void & ()
		{
			return *this;
		}

		inline operator Optional< Void >()const
		{
			return Optional< Void >{ *this
				, m_enabled };
		}

		inline bool isOptional()const
		{
			return m_optional;
		}

		inline bool isEnabled()const
		{
			return m_enabled;
		}

	private:
		bool m_optional;
		bool m_enabled;
	};
}

#endif
