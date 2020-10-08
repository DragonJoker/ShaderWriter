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
		: public Value
	{
		IntegerValue( Shader * shader
			, expr::ExprPtr expr );
		IntegerValue( IntegerValue && rhs );
		IntegerValue( IntegerValue const & rhs );
		explicit IntegerValue( Value value );
		explicit IntegerValue( CppTypeT< IntegerValue< KindT > > rhs );
		explicit IntegerValue( IncDecWrapperT< KindT > rhs );

		inline IntegerValue & operator=( IntegerValue const & rhs );
		inline IntegerValue & operator=( Optional< IntegerValue > const & rhs );
		inline IntegerValue & operator=( MaybeOptional< IntegerValue > const & rhs );
		inline IntegerValue & operator=( IncDecWrapperT< KindT > rhs );

		template< typename T >
		IntegerValue & operator=( T const & rhs );
		IntegerValue & operator=( CppTypeT< IntegerValue< KindT > > const & rhs );
		expr::ExprPtr makeCondition()const;
		IncDecWrapperT< KindT > operator++();
		IncDecWrapperT< KindT > operator++( int );
		IncDecWrapperT< KindT > operator--();
		IncDecWrapperT< KindT > operator--( int );
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
		IntegerValue & operator+=( Optional< IntegerValue > const & rhs );
		IntegerValue & operator-=( Optional< IntegerValue > const & rhs );
		IntegerValue & operator*=( Optional< IntegerValue > const & rhs );
		IntegerValue & operator/=( Optional< IntegerValue > const & rhs );
		IntegerValue & operator%=( Optional< IntegerValue > const & rhs );
		IntegerValue & operator<<=( Optional< IntegerValue > const & rhs );
		IntegerValue & operator>>=( Optional< IntegerValue > const & rhs );
		IntegerValue & operator&=( Optional< IntegerValue > const & rhs );
		IntegerValue & operator|=( Optional< IntegerValue > const & rhs );
		IntegerValue & operator^=( Optional< IntegerValue > const & rhs );
		IntegerValue & operator+=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue & operator-=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue & operator*=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue & operator/=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue & operator%=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue & operator<<=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue & operator>>=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue & operator&=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue & operator|=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue & operator^=( CppTypeT< IntegerValue< KindT > > const & rhs );
		IntegerValue operator-()const;
		IntegerValue operator+()const;

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	template< ast::type::Kind KindT >
	struct IncDecWrapperT
	{
		using ValueT = IntegerValue< KindT >;

		IncDecWrapperT( IncDecWrapperT const & rhs ) = delete;
		IncDecWrapperT & operator=( IncDecWrapperT const & rhs ) = delete;
		IncDecWrapperT & operator=( IncDecWrapperT && rhs ) = delete;

		IncDecWrapperT( Shader * shader
			, expr::ExprPtr expr );
		explicit IncDecWrapperT( IntegerValue< KindT > const & rhs );
		IncDecWrapperT( IncDecWrapperT && rhs );
		~IncDecWrapperT();

		sdw::expr::ExprPtr release()const;
		expr::ExprPtr makeCondition()const;
		Shader * getShader()const;

		explicit operator IntegerValue< KindT >();

	private:
		mutable IntegerValue< KindT > m_value;
	};

	template< ast::type::Kind KindT >
	expr::ExprPtr makeExpr( Shader const & shader
		, IncDecWrapperT< KindT > variable
		, bool force = true );

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
	Optional< IntegerValue< KindT > > operator+( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator-( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator*( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator/( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator%( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator<<( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator>>( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator&( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator|( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator^( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator==( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator!=( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator<( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator<=( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator>( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator>=( Optional< IntegerValue< KindT > > const & lhs
		, IntegerValue< KindT > const & rhs );

	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator+( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator-( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator*( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator/( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator%( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator<<( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator>>( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator&( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator|( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator^( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator==( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator!=( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator<( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator<=( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator>( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator>=( IntegerValue< KindT > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );

	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator+( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator-( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator*( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator/( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator%( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator<<( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator>>( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator&( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator|( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator^( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator~( Optional< IntegerValue< KindT > > const & value );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator==( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator!=( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator<( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator<=( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator>( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator>=( Optional< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );

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

	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator+( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator-( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator*( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator/( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator%( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator<<( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator>>( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator&( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator|( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator^( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator==( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator!=( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator<( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator<=( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator>( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator>=( Optional< IntegerValue< KindT > > const & lhs
		, CppTypeT< IntegerValue< KindT > > const & rhs );

	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator+( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator-( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator*( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator/( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator%( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator<<( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator>>( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator&( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator|( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< IntegerValue< KindT > > operator^( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator==( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator!=( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator<( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator<=( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator>( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< Boolean > operator>=( CppTypeT< IntegerValue< KindT > > const & lhs
		, Optional< IntegerValue< KindT > > const & rhs );
}

#include "IntegerValue.inl"

#endif
