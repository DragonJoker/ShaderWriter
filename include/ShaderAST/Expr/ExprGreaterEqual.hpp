/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprGreaterEqual_H___
#define ___AST_ExprGreaterEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class GreaterEqual
		: public Binary
	{
	public:
		GreaterEqual( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using GreaterEqualPtr = std::unique_ptr< GreaterEqual >;

	inline GreaterEqualPtr makeGreaterEqual( type::TypesCache & cache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< GreaterEqual >( cache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
