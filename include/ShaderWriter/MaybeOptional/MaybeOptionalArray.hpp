/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalArray_H___
#define ___SDW_MaybeOptionalArray_H___
#pragma once

#include "MaybeOptional.hpp"
#include "ShaderWriter/BaseTypes/Array.hpp"

namespace sdw
{
	template< typename ValueT >
	struct MaybeOptional< Array< ValueT > >
		: public Array< ValueT >
	{
		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr );
		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline MaybeOptional( Array< ValueT > const & rhs );
		inline MaybeOptional( Optional< Array< ValueT > > const & rhs );
		inline MaybeOptional( MaybeOptional< Array< ValueT > > const & rhs );

		template< typename IndexT >
		inline MaybeOptional< ValueT > operator[]( IndexT const & offset )const;

		inline operator Array< ValueT >()const;
		inline operator Optional< Array< ValueT > >()const;

		inline bool isOptional()const;
		inline bool isEnabled()const;

	private:
		bool m_optional;
		bool m_enabled;
	};
}

#include "MaybeOptionalArray.inl"

#endif
