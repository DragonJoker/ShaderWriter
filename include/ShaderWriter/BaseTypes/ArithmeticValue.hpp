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
	struct ArithmeticValueTraits;

	template< ast::type::Kind KindT >
	using CppTypeT = typename ArithmeticValueTraits< KindT >::CppType;

	template< ast::type::Kind KindT >
	struct ArithmeticValue
		: public Value
	{
		ArithmeticValue( Shader * shader
			, expr::ExprPtr expr );
		ArithmeticValue( ArithmeticValue && rhs );
		ArithmeticValue( ArithmeticValue const & rhs );
		explicit ArithmeticValue( Value const & value );
		explicit ArithmeticValue( CppTypeT< KindT > rhs );
		ArithmeticValue & operator=( ArithmeticValue const & rhs );
		template< typename T >
		inline ArithmeticValue & operator=( T const & rhs );
		ArithmeticValue & operator=( CppTypeT< KindT > const & rhs );
		expr::ExprPtr makeCondition()const;
		ArithmeticValue & operator+=( ArithmeticValue const & rhs );
		ArithmeticValue & operator-=( ArithmeticValue const & rhs );
		ArithmeticValue & operator*=( ArithmeticValue const & rhs );
		ArithmeticValue & operator/=( ArithmeticValue const & rhs );
		ArithmeticValue & operator+=( CppTypeT< KindT > const & rhs );
		ArithmeticValue & operator-=( CppTypeT< KindT > const & rhs );
		ArithmeticValue & operator*=( CppTypeT< KindT > const & rhs );
		ArithmeticValue & operator/=( CppTypeT< KindT > const & rhs );
		ArithmeticValue & operator+=( Optional< ArithmeticValue > const & rhs );
		ArithmeticValue & operator-=( Optional< ArithmeticValue > const & rhs );
		ArithmeticValue & operator*=( Optional< ArithmeticValue > const & rhs );
		ArithmeticValue & operator/=( Optional< ArithmeticValue > const & rhs );
		ArithmeticValue & operator-();

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
	Bool operator==( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator!=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator<( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator<=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator>( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator>=( ArithmeticValue< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator+( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator-( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator*( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator/( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator==( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator!=( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator<( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator<=( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator>( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator>=( CppTypeT< KindT > const & lhs
		, ArithmeticValue< KindT > const & rhs );

	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator+( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator-( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator*( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	ArithmeticValue< KindT > operator/( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator==( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator!=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator<( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator<=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator>( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Bool operator>=( ArithmeticValue< KindT > const & lhs
		, CppTypeT< KindT > const & rhs );

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator==( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator!=( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator<( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator<=( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator>( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator>=( Optional< ArithmeticValue< KindT > > const & lhs
		, ArithmeticValue< KindT > const & rhs );

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator==( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator!=( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator<( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator<=( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator>( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator>=( ArithmeticValue< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator==( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator!=( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator<( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator<=( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator>( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator>=( Optional< ArithmeticValue< KindT > > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator==( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator!=( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator<( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator<=( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator>( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator>=( Optional< ArithmeticValue< KindT > > const & lhs
		, CppTypeT< KindT > const & rhs );

	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator+( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator-( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator*( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional< ArithmeticValue< KindT > > operator/( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator==( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator!=( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator<( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator<=( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator>( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
	template< ast::type::Kind KindT >
	Optional < Bool > operator>=( CppTypeT< KindT > const & lhs
		, Optional< ArithmeticValue< KindT > > const & rhs );
}

#include "ArithmeticValue.inl"

#endif
