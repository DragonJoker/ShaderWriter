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
	struct Boolean
		: public Value
	{
		SDW_API Boolean( Shader * shader
			, expr::ExprPtr expr );
		SDW_API Boolean( Boolean && rhs );
		SDW_API Boolean( Boolean const & rhs );
		SDW_API explicit Boolean( Value rhs );
		SDW_API Boolean & operator=( Boolean const & rhs );
		template< typename T >
		inline Boolean & operator=( T const & rhs );
		SDW_API Boolean & operator=( bool rhs );
		SDW_API operator bool();
		SDW_API expr::ExprPtr makeCondition()const;

		SDW_API static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	SDW_API Boolean operator==( Boolean const & lhs
		, Boolean const & rhs );
	SDW_API Boolean operator!=( Boolean const & lhs
		, Boolean const & rhs );
	SDW_API Boolean operator||( Boolean const & lhs
		, Boolean const & rhs );
	SDW_API Boolean operator&&( Boolean const & lhs
		, Boolean const & rhs );
	SDW_API Optional< Boolean > operator||( Optional< Boolean > const & lhs
		, Boolean const & rhs );
	SDW_API Optional< Boolean > operator&&( Optional< Boolean > const & lhs
		, Boolean const & rhs );
	SDW_API Optional< Boolean > operator||( Boolean const & lhs
		, Optional< Boolean > const & rhs );
	SDW_API Optional< Boolean > operator&&( Boolean const & lhs
		, Optional< Boolean > const & rhs );
	SDW_API Optional< Boolean > operator||( Optional< Boolean > const & lhs
		, Optional< Boolean > const & rhs );
	SDW_API Optional< Boolean > operator&&( Optional< Boolean > const & lhs
		, Optional< Boolean > const & rhs );

	template< typename LhsT, typename RhsT, typename CreatorT >
	inline Boolean writeComparator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	Optional< Boolean > writeComparator( Optional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	Optional< Boolean > writeComparator( LhsT const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	Optional< Boolean > writeComparator( Optional< LhsT > const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< Boolean > writeComparator( MaybeOptional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< Boolean > writeComparator( LhsT const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator );
	template< typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< Boolean > writeComparator( MaybeOptional< LhsT > const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator );
}

#include "Bool.inl"

#endif
