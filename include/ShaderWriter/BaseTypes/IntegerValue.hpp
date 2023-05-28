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

		template< IntegerT RhsT >
		IntegerValue & operator=( RhsT const & rhs );
		expr::ExprPtr makeCondition()const;
		ReturnWrapperT< IntegerValue > operator++();
		ReturnWrapperT< IntegerValue > operator++( int );
		ReturnWrapperT< IntegerValue > operator--();
		ReturnWrapperT< IntegerValue > operator--( int );
		template< IntegerT RhsT >
		IntegerValue & operator+=( RhsT const & rhs );
		template< IntegerT RhsT >
		IntegerValue & operator-=( RhsT const & rhs );
		template< IntegerT RhsT >
		IntegerValue & operator*=( RhsT const & rhs );
		template< IntegerT RhsT >
		IntegerValue & operator/=( RhsT const & rhs );
		template< IntegerT RhsT >
		IntegerValue & operator%=( RhsT const & rhs );
		template< IntegerT RhsT >
		IntegerValue & operator<<=( RhsT const & rhs );
		template< IntegerT RhsT >
		IntegerValue & operator>>=( RhsT const & rhs );
		template< IntegerT RhsT >
		IntegerValue & operator&=( RhsT const & rhs );
		template< IntegerT RhsT >
		IntegerValue & operator|=( RhsT const & rhs );
		template< IntegerT RhsT >
		IntegerValue & operator^=( RhsT const & rhs );
		IntegerValue operator-()const;
		IntegerValue operator+()const;

		Vec2T< IntegerValue > xx()const;
		Vec3T< IntegerValue > xxx()const;
		Vec4T< IntegerValue > xxxx()const;

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	template< ast::type::Kind KindT >
	IntegerValue< KindT > operator~( IntegerValue< KindT > const & value );

	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator+( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator-( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator*( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator/( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator%( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator<<( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator>>( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator&( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator|( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	IntegerValue< typeEnumV< OperandTypeT< LhsT > > > operator^( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator==( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator!=( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator<( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator<=( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator>( LhsT const & lhs
		, RhsT const & rhs );
	template< IntegerT LhsT, IntegerT RhsT >
	Boolean operator>=( LhsT const & lhs
		, RhsT const & rhs );
}

#include "IntegerValue.inl"

#endif
