/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ArithmeticValue_H___
#define ___SDW_ArithmeticValue_H___
#pragma once

#include "ShaderWriter/BaseTypes/Boolean.hpp"

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

		template< ArithmeticT RhsT >
		ArithmeticValue & operator=( RhsT const & rhs );
		expr::ExprPtr makeCondition()const;
		template< ArithmeticT RhsT >
		ArithmeticValue & operator+=( RhsT const & rhs );
		template< ArithmeticT RhsT >
		ArithmeticValue & operator-=( RhsT const & rhs );
		template< ArithmeticT RhsT >
		ArithmeticValue & operator*=( RhsT const & rhs );
		template< ArithmeticT RhsT >
		ArithmeticValue & operator/=( RhsT const & rhs );
		ArithmeticValue operator-()const;
		ArithmeticValue operator+()const;

		Vec2T< ArithmeticValue > xx()const;
		Vec3T< ArithmeticValue > xxx()const;
		Vec4T< ArithmeticValue > xxxx()const;

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	template< ArithmeticT LhsT, ArithmeticT RhsT >
	ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > operator+( LhsT const & lhs
		, RhsT const & rhs );
	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > operator-( LhsT const & lhs
		, RhsT const & rhs );
	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > operator*( LhsT const & lhs
		, RhsT const & rhs );
	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	ArithmeticValue< typeEnumV< OperandTypeT< LhsT > > > operator/( LhsT const & lhs
		, RhsT const & rhs );
	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator==( LhsT const & lhs
		, RhsT const & rhs );
	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator!=( LhsT const & lhs
		, RhsT const & rhs );
	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator<( LhsT const & lhs
		, RhsT const & rhs );
	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator<=( LhsT const & lhs
		, RhsT const & rhs );
	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator>( LhsT const & lhs
		, RhsT const & rhs );
	template< ArithmeticT LhsT, ArithmeticT RhsT  >
	Boolean operator>=( LhsT const & lhs
		, RhsT const & rhs );
}

#include "ArithmeticValue.inl"

#endif
