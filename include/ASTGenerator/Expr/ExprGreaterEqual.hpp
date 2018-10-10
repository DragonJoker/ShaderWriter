/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprGreaterEqual_H___
#define ___AST_ExprGreaterEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprGreaterEqual
		: public ExprBinary
	{
	public:
		ExprGreaterEqual( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprGreaterEqual > makeGreaterEqualExpr( ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprGreaterEqual >( std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
