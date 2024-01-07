/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Boolean_H___
#define ___SDW_Boolean_H___
#pragma once

#include "Void.hpp"

namespace sdw
{
	struct Boolean
		: public Value
	{
		SDW_DeclValue( SDW_API, Boolean );

		SDW_API Boolean( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
		SDW_API explicit Boolean( bool value );
		SDW_API explicit Boolean( Value rhs );

		SDW_API Boolean & operator=( bool rhs );
		SDW_API Boolean operator!()const;
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

	template< typename RetT, typename LhsT, typename RhsT, typename CreatorT >
	inline RetT writeComparator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator );
}

#include "Boolean.inl"

inline sdw::Boolean operator "" _b( unsigned long long value )
{
	return sdw::Boolean{ value != 0u };
}

#endif
