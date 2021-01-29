/*
See LICENSE file in root folder
*/
#ifndef ___SDW_IntegerValue_H___
#define ___SDW_IntegerValue_H___
#pragma once

#include "ArithmeticValue.hpp"
#include "ReturnWrapper.hpp"

namespace sdw
{
	template< ast::type::Kind KindT >
	struct IntegerValue
		: public Value
	{
		IntegerValue( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
		IntegerValue( IntegerValue< KindT > && rhs );
		IntegerValue( IntegerValue< KindT > const & rhs );
		explicit IntegerValue( Value value );
		explicit IntegerValue( CppTypeT< IntegerValue< KindT > > rhs );
		explicit IntegerValue( ReturnWrapperT< IntegerValue< KindT > > rhs );

		inline IntegerValue< KindT > & operator=( IntegerValue< KindT > const & rhs );
		inline IntegerValue< KindT > & operator=( ReturnWrapperT< IntegerValue< KindT > > rhs );

		template< typename T >
		IntegerValue< KindT > & operator=( T const & rhs );
		IntegerValue< KindT > & operator=( CppTypeT< IntegerValue< KindT > > const & rhs );
		expr::ExprPtr makeCondition()const;
		ReturnWrapperT< IntegerValue< KindT > > operator++();
		ReturnWrapperT< IntegerValue< KindT > > operator++( int );
		ReturnWrapperT< IntegerValue< KindT > > operator--();
		ReturnWrapperT< IntegerValue< KindT > > operator--( int );
		IntegerValue< KindT > & operator+=( IntegerValue< KindT > const & rhs );
		IntegerValue< KindT > & operator-=( IntegerValue< KindT > const & rhs );
		IntegerValue< KindT > & operator*=( IntegerValue< KindT > const & rhs );
		IntegerValue< KindT > & operator/=( IntegerValue< KindT > const & rhs );
		IntegerValue< KindT > & operator%=( IntegerValue< KindT > const & rhs );
		IntegerValue< KindT > & operator<<=( IntegerValue< KindT > const & rhs );
		IntegerValue< KindT > & operator>>=( IntegerValue< KindT > const & rhs );
		IntegerValue< KindT > & operator&=( IntegerValue< KindT > const & rhs );
		IntegerValue< KindT > & operator|=( IntegerValue< KindT > const & rhs );
		IntegerValue< KindT > & operator^=( IntegerValue< KindT > const & rhs );
		IntegerValue< KindT > & operator+=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue< KindT > & operator-=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue< KindT > & operator*=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue< KindT > & operator/=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue< KindT > & operator%=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue< KindT > & operator<<=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue< KindT > & operator>>=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue< KindT > & operator&=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue< KindT > & operator|=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue< KindT > & operator^=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue< KindT > operator-()const;
		IntegerValue< KindT > operator+()const;

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator+( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator-( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator*( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator/( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator%( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator<<( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator>>( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator&( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator|( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator^( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator~( IntegerValue< KindT > const & value );
	template< ast::type::Kind KindT >
	Boolean operator==( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator!=( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<=( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>=( IntegerValue< KindT > const & lhs
		, IntegerValue< KindT > const & rhs );

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator+( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator-( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator*( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator/( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator%( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator<<( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator>>( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator&( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator|( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator^( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator==( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator!=( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<=( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>=( CppTypeT< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator+( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator-( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator*( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator/( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator%( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator<<( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator>>( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator&( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator|( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator^( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator==( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator!=( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<=( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>=( IntegerValue< KindT > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
}

#include "IntegerValue.inl"

#endif
