/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ArithmeticValue_H___
#define ___SDW_ArithmeticValue_H___
#pragma once

#include "ShaderWriter/BaseTypes/Bool.hpp"

namespace sdw
{
	template< ast::type::Kind KindT >
	struct ArithmeticValue
		: public Value
	{
		SDW_DeclValue( , ArithmeticValue );

		ArithmeticValue( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
		explicit ArithmeticValue( Value value );
		explicit ArithmeticValue( CppTypeT< ArithmeticValue > rhs );

		template< typename T >
		ArithmeticValue & operator=( T const & rhs );
		ArithmeticValue & operator=( CppTypeT< ArithmeticValue > const & rhs );
		expr::ExprPtr makeCondition()const;
		ArithmeticValue & operator+=( ArithmeticValue const & rhs );
		ArithmeticValue & operator-=( ArithmeticValue const & rhs );
		ArithmeticValue & operator*=( ArithmeticValue const & rhs );
		ArithmeticValue & operator/=( ArithmeticValue const & rhs );
		ArithmeticValue & operator+=( CppTypeT< ArithmeticValue > const & rhs );
		ArithmeticValue & operator-=( CppTypeT< ArithmeticValue > const & rhs );
		ArithmeticValue & operator*=( CppTypeT< ArithmeticValue > const & rhs );
		ArithmeticValue & operator/=( CppTypeT< ArithmeticValue > const & rhs );
		ArithmeticValue operator-()const;
		ArithmeticValue operator+()const;

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator+( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator-( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator*( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator/( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator==( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator!=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator+( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator-( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator*( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator/( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator==( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator!=( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<=( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>=( CppTypeT< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator+( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator-( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator*( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator/( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator==( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator!=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator<=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Boolean operator>=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< ArithmeticValue< KindT > > const & rhs );
}

#include "ArithmeticValue.inl"

#endif
