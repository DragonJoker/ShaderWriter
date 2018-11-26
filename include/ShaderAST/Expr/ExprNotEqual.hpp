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
		NotEqual( ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using NotEqualPtr = std::unique_ptr< NotEqual >;

	inline NotEqualPtr makeNotEqual( ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< NotEqual >( std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
