/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLess_H___
#define ___AST_ExprLess_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprLess
		: public ExprBinary
	{
	public:
		ExprLess( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprLess > makeLessExpr( ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprLess >( std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
