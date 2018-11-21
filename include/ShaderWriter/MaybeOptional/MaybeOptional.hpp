/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptional_H___
#define ___SDW_MaybeOptional_H___
#pragma once

#include "ShaderWriter/Optional/Optional.hpp"

namespace sdw
{
	template< typename ValueT >
	struct MaybeOptional
		: public ValueT
	{
		using MyValue = ValueT;

	public:
		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr );
		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline MaybeOptional( MyValue const & rhs );
		inline MaybeOptional( Optional< MyValue > const & rhs );
		inline MaybeOptional( MaybeOptional< MyValue > const & rhs );

		inline operator MyValue()const;
		inline operator Optional< MyValue >()const;

		inline bool isOptional()const;
		inline bool isEnabled()const;

	private:
		bool m_optional;
		bool m_enabled;
	};

	template< typename ... ParamsT >
	inline bool isAnyOptional( ParamsT const & ... params );

	template< typename T >
	inline bool isOptionalEnabled( MaybeOptional< T > const & value );

	template< typename T >
	inline expr::ExprPtr makeExpr( MaybeOptional< T > const & value
		, bool force = false );
}

#include "MaybeOptional.inl"

#endif
