/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalArray_H___
#define ___SDW_OptionalArray_H___
#pragma once

#include "Optional.hpp"
#include "ShaderWriter/BaseTypes/Array.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Array< ValueT > >
		: public Array< ValueT >
	{
		using MyValue = Array< ValueT >;

		Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Optional< Array< ValueT > > const & rhs );

		inline Optional< MyValue > & operator=( MyValue const & rhs );
		inline Optional< MyValue > & operator=( Optional< MyValue > const & rhs );
		inline Optional< MyValue > & operator=( MaybeOptional< MyValue > const & rhs );

		template< typename IndexT >
		Optional< ValueT > operator[]( IndexT const & offset )const;
		inline bool isEnabled()const;

	private:
		bool m_enabled;
	};
}

#include "OptionalArray.inl"

#endif
