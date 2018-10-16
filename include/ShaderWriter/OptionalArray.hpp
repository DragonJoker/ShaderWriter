/*
See LICENSE file in root folder
*/
#ifndef ___Writer_OptionalArray_H___
#define ___Writer_OptionalArray_H___
#pragma once

#include "Array.hpp"
#include "Optional.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Array< ValueT > >
		: public Array< ValueT >
	{
		Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		template< typename IndexT >
		Optional< ValueT > operator[]( IndexT const & offset )const;
		inline bool isEnabled()const;

	private:
		bool m_enabled;
	};
}

#include "OptionalArray.inl"

#endif
