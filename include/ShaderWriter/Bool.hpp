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
		Boolean( Value const & rhs );
		Boolean & operator=( Boolean const & rhs );
		template< typename T >
		inline Boolean & operator=( T const & rhs );
		Boolean & operator=( bool rhs );
		operator bool();
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

#define Writer_DeclareComparisonLHS( Operator, LhsTypeT, RhsTypeT )\
	Boolean operator Operator( LhsTypeT const & lhs, RhsTypeT const & rhs );\
	Optional< Boolean > operator Operator( Optional< LhsTypeT > const & lhs, RhsTypeT const & rhs )

#define Writer_DeclareComparisonRHS( Operator, LhsTypeT, RhsTypeT )\
	Boolean operator Operator( LhsTypeT const & lhs, RhsTypeT const & rhs );\
	Optional< Boolean > operator Operator( LhsTypeT const & lhs, Optional< RhsTypeT > const & rhs )

#define Writer_DeclareComparison( Operator, LhsTypeT, RhsTypeT )\
	Boolean operator Operator( LhsTypeT const & lhs, RhsTypeT const & rhs );\
	Optional< Boolean > operator Operator( Optional< LhsTypeT > const & lhs, RhsTypeT const & rhs );\
	Optional< Boolean > operator Operator( LhsTypeT const & lhs, Optional< RhsTypeT > const & rhs );\
	Optional< Boolean > operator Operator( Optional< LhsTypeT > const & lhs, Optional< RhsTypeT > const & rhs )

#define Writer_DeclareComparisonTypes( Operator, TypeT )\
	Writer_DeclareComparison( Operator, TypeT, Int );\
	Writer_DeclareComparison( Operator, TypeT, UInt );\
	Writer_DeclareComparison( Operator, TypeT, Float );\
	Writer_DeclareComparison( Operator, TypeT, Double );\
	Writer_DeclareComparisonLHS( Operator, TypeT, int32_t );\
	Writer_DeclareComparisonLHS( Operator, TypeT, uint32_t );\
	Writer_DeclareComparisonLHS( Operator, TypeT, float );\
	Writer_DeclareComparisonLHS( Operator, TypeT, double );\
	Writer_DeclareComparisonRHS( Operator, int32_t, TypeT );\
	Writer_DeclareComparisonRHS( Operator, uint32_t, TypeT );\
	Writer_DeclareComparisonRHS( Operator, float, TypeT );\
	Writer_DeclareComparisonRHS( Operator, double, TypeT )

#define Writer_DeclareComparisons( TypeT )\
	Writer_DeclareComparisonTypes( ==, TypeT );\
	Writer_DeclareComparisonTypes( !=, TypeT );\
	Writer_DeclareComparisonTypes( <, TypeT );\
	Writer_DeclareComparisonTypes( <=, TypeT );\
	Writer_DeclareComparisonTypes( >, TypeT );\
	Writer_DeclareComparisonTypes( >=, TypeT )

	Writer_DeclareComparisons( Int );
	Writer_DeclareComparisons( UInt );
	Writer_DeclareComparisons( Float );
	Writer_DeclareComparisons( Double );

#undef Writer_DeclareComparisons
#undef Writer_DeclareComparisonTypes
#undef Writer_DeclareComparison
#undef Writer_DeclareComparisonLHS
#undef Writer_DeclareComparisonRHS
}

#include "Bool.inl"

#endif
