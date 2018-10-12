/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprComma_H___
#define ___AST_ExprComma_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Comma
		: public Binary
	{
	public:
		Comma(type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using CommaPtr = std::unique_ptr< Comma >;

	inline CommaPtr makeComma( ExprPtr lhs
		, ExprPtr rhs )
	{
		auto type = rhs->getType();
		return std::make_unique< Comma >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
