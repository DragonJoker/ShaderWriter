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
		SDW_DeclValue( , IntegerValue );

		IntegerValue( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
		explicit IntegerValue( Value value );
		explicit IntegerValue( CppTypeT< IntegerValue > rhs );

		template< typename T >
		IntegerValue & operator=( T const & rhs );
		IntegerValue & operator=( CppTypeT< IntegerValue > const & rhs );
		expr::ExprPtr makeCondition()const;
		ReturnWrapperT< IntegerValue > operator++();
		ReturnWrapperT< IntegerValue > operator++( int );
		ReturnWrapperT< IntegerValue > operator--();
		ReturnWrapperT< IntegerValue > operator--( int );
		IntegerValue & operator+=( IntegerValue const & rhs );
		IntegerValue & operator-=( IntegerValue const & rhs );
		IntegerValue & operator*=( IntegerValue const & rhs );
		IntegerValue & operator/=( IntegerValue const & rhs );
		IntegerValue & operator%=( IntegerValue const & rhs );
		IntegerValue & operator<<=( IntegerValue const & rhs );
		IntegerValue & operator>>=( IntegerValue const & rhs );
		IntegerValue & operator&=( IntegerValue const & rhs );
		IntegerValue & operator|=( IntegerValue const & rhs );
		IntegerValue & operator^=( IntegerValue const & rhs );
		IntegerValue & operator+=( CppTypeT< IntegerValue > const & rhs );
		IntegerValue & operator-=( CppTypeT< IntegerValue > const & rhs );
		IntegerValue & operator*=( CppTypeT< IntegerValue > const & rhs );
		IntegerValue & operator/=( CppTypeT< IntegerValue > const & rhs );
		IntegerValue & operator%=( CppTypeT< IntegerValue > const & rhs );
		IntegerValue & operator<<=( CppTypeT< IntegerValue > const & rhs );
		IntegerValue & operator>>=( CppTypeT< IntegerValue > const & rhs );
		IntegerValue & operator&=( CppTypeT< IntegerValue > const & rhs );
		IntegerValue & operator|=( CppTypeT< IntegerValue > const & rhs );
		IntegerValue & operator^=( CppTypeT< IntegerValue > const & rhs );
		IntegerValue operator-()const;
		IntegerValue operator+()const;

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
