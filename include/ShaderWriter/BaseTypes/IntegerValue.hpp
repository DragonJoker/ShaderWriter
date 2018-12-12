/*
See LICENSE file in root folder
*/
#ifndef ___SDW_IntegerValue_H___
#define ___SDW_IntegerValue_H___
#pragma once

#include "ArithmeticValue.hpp"

namespace sdw
{
	template< ast::type::Kind KindT >
	struct IntegerValue
		: public ArithmeticValue< KindT >
	{
		inline IntegerValue( Shader * shader
			, expr::ExprPtr expr );
		inline IntegerValue( IntegerValue && rhs );
		inline IntegerValue( IntegerValue const & rhs );
		inline explicit IntegerValue( Value const & value );
		inline explicit IntegerValue( CppTypeT< KindT > rhs );
		inline IntegerValue & operator=( IntegerValue const & rhs );
		template< typename T >
		inline IntegerValue & operator=( T const & rhs );
		inline IntegerValue & operator=( CppTypeT< KindT > const & rhs );
		inline IntegerValue & operator++();
		inline IntegerValue operator++( int );
		inline IntegerValue & operator--();
		inline IntegerValue operator--( int );
		inline IntegerValue & operator+=( IntegerValue const & rhs );
		inline IntegerValue & operator-=( IntegerValue const & rhs );
		inline IntegerValue & operator*=( IntegerValue const & rhs );
		inline IntegerValue & operator/=( IntegerValue const & rhs );
		inline IntegerValue & operator%=( IntegerValue const & rhs );
		inline IntegerValue & operator<<=( IntegerValue const & rhs );
		inline IntegerValue & operator>>=( IntegerValue const & rhs );
		inline IntegerValue & operator&=( IntegerValue const & rhs );
		inline IntegerValue & operator|=( IntegerValue const & rhs );
		inline IntegerValue & operator^=( IntegerValue const & rhs );
		inline IntegerValue & operator+=( Optional< IntegerValue > const & rhs );
		inline IntegerValue & operator-=( Optional< IntegerValue > const & rhs );
		inline IntegerValue & operator*=( Optional< IntegerValue > const & rhs );
		inline IntegerValue & operator/=( Optional< IntegerValue > const & rhs );
		inline IntegerValue & operator%=( Optional< IntegerValue > const & rhs );
		inline IntegerValue & operator<<=( Optional< IntegerValue > const & rhs );
		inline IntegerValue & operator>>=( Optional< IntegerValue > const & rhs );
		inline IntegerValue & operator&=( Optional< IntegerValue > const & rhs );
		inline IntegerValue & operator|=( Optional< IntegerValue > const & rhs );
		inline IntegerValue & operator^=( Optional< IntegerValue > const & rhs );
		inline IntegerValue & operator+=( CppTypeT< KindT > const & rhs );
		inline IntegerValue & operator-=( CppTypeT< KindT > const & rhs );
		inline IntegerValue & operator*=( CppTypeT< KindT > const & rhs );
		inline IntegerValue & operator/=( CppTypeT< KindT > const & rhs );
		inline IntegerValue & operator-();
		inline IntegerValue & operator%=( CppTypeT< KindT > const & rhs );
		inline IntegerValue & operator<<=( CppTypeT< KindT > const & rhs );
		inline IntegerValue & operator>>=( CppTypeT< KindT > const & rhs );
		inline IntegerValue & operator&=( CppTypeT< KindT > const & rhs );
		inline IntegerValue & operator|=( CppTypeT< KindT > const & rhs );
		inline IntegerValue & operator^=( CppTypeT< KindT > const & rhs );

		static inline ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator%( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator<<( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator>>( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator&( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator|( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator^( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator~( IntegerValue< KindT > const & value );

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator%( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator<<( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator>>( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator&( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator|( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator^( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator%( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator<<( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator>>( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator&( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator|( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator^( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator%( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator<<( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator>>( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator&( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator|( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator^( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator~( Optional< IntegerValue< KindT > > const & value );

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator%( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator<<( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator>>( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator&( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator|( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator^( CppTypeT< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator%( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator<<( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator>>( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator&( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator|( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > operator^( IntegerValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator%( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator<<( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator>>( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator&( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator|( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator^( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator%( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator<<( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator>>( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator&( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator|( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > operator^( CppTypeT< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
}

#include "IntegerValue.inl"

#endif
