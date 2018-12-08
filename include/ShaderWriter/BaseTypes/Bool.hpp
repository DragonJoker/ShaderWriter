/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Boolean_H___
#define ___SDW_Boolean_H___
#pragma once

#include "Void.hpp"
#include "Int.hpp"
#include "UInt.hpp"
#include "Float.hpp"
#include "Double.hpp"

namespace sdw
{
	struct Boolean
		: public Value
	{
		Boolean( Shader * shader
			, expr::ExprPtr expr );
		Boolean( Boolean && rhs );
		Boolean( Boolean const & rhs );
		explicit Boolean( Value const & rhs );
		Boolean & operator=( Boolean const & rhs );
		template< typename T >
		inline Boolean & operator=( T const & rhs );
		Boolean & operator=( bool rhs );
		operator bool();
		expr::ExprPtr makeCondition()const;

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	Boolean operator==( Boolean const & lhs
		, Boolean const & rhs );
	Boolean operator!=( Boolean const & lhs
		, Boolean const & rhs );
	Boolean operator||( Boolean const & lhs
		, Boolean const & rhs );
	Boolean operator&&( Boolean const & lhs
		, Boolean const & rhs );
	Optional< Boolean > operator||( Optional< Boolean > const & lhs
		, Boolean const & rhs );
	Optional< Boolean > operator&&( Optional< Boolean > const & lhs
		, Boolean const & rhs );
	Optional< Boolean > operator||( Boolean const & lhs
		, Optional< Boolean > const & rhs );
	Optional< Boolean > operator&&( Boolean const & lhs
		, Optional< Boolean > const & rhs );
	Optional< Boolean > operator||( Optional< Boolean > const & lhs
		, Optional< Boolean > const & rhs );
	Optional< Boolean > operator&&( Optional< Boolean > const & lhs
		, Optional< Boolean > const & rhs );

	template< typename ValueT >
	Optional< Boolean > operator==( Optional< ValueT >  const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator!=( Optional< ValueT >  const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator<( Optional< ValueT >  const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator<=( Optional< ValueT >  const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator>( Optional< ValueT >  const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator>=( Optional< ValueT > const & lhs
		, ValueT const & rhs );

	template< typename ValueT >
	Optional< Boolean > operator==( ValueT const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator!=( ValueT const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator<( ValueT const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator<=( ValueT const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator>( ValueT const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator>=( ValueT const & lhs
		, Optional< ValueT > const & rhs );

	template< typename ValueT >
	Optional< Boolean > operator==( Optional< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator!=( Optional< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator<( Optional< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator<=( Optional< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator>( Optional< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Boolean > operator>=( Optional< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
}

#include "Bool.inl"

#endif
