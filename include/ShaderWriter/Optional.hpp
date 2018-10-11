/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Optional_H___
#define ___Writer_Optional_H___
#pragma once

#include "Value.hpp"

namespace sdw
{
	template< typename TypeT >
	struct Optional
		: public TypeT
	{
		Optional( stmt::Container * container
			, expr::ExprPtr expr
			, bool enabled );
		Optional( TypeT const & other
			, bool enabled );

		inline Optional< TypeT > operator=( Optional< TypeT > const & rhs );
		template< typename T >
		inline Optional< TypeT > operator=( T const & rhs );
		inline bool isEnabled()const;

		inline operator Optional< Value >()const;

	private:
		bool m_enabled;
	};

	template< typename T >
	struct is_optional
		: public std::false_type
	{
	};

	template< typename T >
	struct is_optional< Optional< T > >
		: public std::true_type
	{
	};

	template< typename T >
	expr::ExprPtr make( Optional< T > const & value );
}

#include "Optional.inl"

#endif
