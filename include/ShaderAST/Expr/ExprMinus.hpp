/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMinus_H___
#define ___AST_ExprMinus_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Minus
		: public Binary
	{
	public:
		SDAST_API Minus( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using MinusPtr = std::unique_ptr< Minus >;

	inline MinusPtr makeMinus( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< Minus >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
