/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprNotEqual_H___
#define ___AST_ExprNotEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class NotEqual
		: public Binary
	{
	public:
		SDAST_API NotEqual( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using NotEqualPtr = std::unique_ptr< NotEqual >;

	inline NotEqualPtr makeNotEqual( type::TypesCache & cache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< NotEqual >( cache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
