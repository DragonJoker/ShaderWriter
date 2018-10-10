/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprNotEqual_H___
#define ___AST_ExprNotEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprNotEqual
		: public ExprBinary
	{
	public:
		ExprNotEqual( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprNotEqual > makeNotEqualExpr( ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprNotEqual >( std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
