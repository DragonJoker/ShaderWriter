/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Boolean_H___
#define ___SDW_Boolean_H___
#pragma once

#include "Void.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptional.hpp"

namespace sdw
{
	struct Bool
		: public Value
	{
		SDW_API Bool( Shader * shader
			, expr::ExprPtr expr );
		SDW_API Bool( Bool && rhs );
		SDW_API Bool( Bool const & rhs );
		SDW_API explicit Bool( Value const & rhs );
		SDW_API Bool & operator=( Bool const & rhs );
		template< typename T >
		inline Bool & operator=( T const & rhs );
		SDW_API Bool & operator=( bool rhs );
		SDW_API operator bool();
		SDW_API expr::ExprPtr makeCondition()const;

		SDW_API static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	SDW_API Bool operator==( Bool const & lhs
		, Bool const & rhs );
	SDW_API Bool operator!=( Bool const & lhs
		, Bool const & rhs );
	SDW_API Bool operator||( Bool const & lhs
		, Bool const & rhs );
	SDW_API Bool operator&&( Bool const & lhs
		, Bool const & rhs );
	SDW_API Optional< Bool > operator||( Optional< Bool > const & lhs
		, Bool const & rhs );
	SDW_API Optional< Bool > operator&&( Optional< Bool > const & lhs
		, Bool const & rhs );
	SDW_API Optional< Bool > operator||( Bool const & lhs
		, Optional< Bool > const & rhs );
	SDW_API Optional< Bool > operator&&( Bool const & lhs
		, Optional< Bool > const & rhs );
	SDW_API Optional< Bool > operator||( Optional< Bool > const & lhs
		, Optional< Bool > const & rhs );
	SDW_API Optional< Bool > operator&&( Optional< Bool > const & lhs
		, Optional< Bool > const & rhs );

	template< typename LhsT, typename RhsT, typename CreatorT >
	inline Bool writeComparator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	Optional< Bool > writeComparator( Optional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	Optional< Bool > writeComparator( LhsT const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	Optional< Bool > writeComparator( Optional< LhsT > const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< Bool > writeComparator( MaybeOptional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< Bool > writeComparator( LhsT const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< Bool > writeComparator( MaybeOptional< LhsT > const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator );
}

#include "Bool.inl"

#endif
