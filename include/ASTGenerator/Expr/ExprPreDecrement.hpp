/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprPreDecrement_H___
#define ___AST_ExprPreDecrement_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast
{
	class ExprPreDecrement
		: public ExprUnary
	{
	public:
		ExprPreDecrement( ExprPtr operand );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprPreDecrement > makePreDecrementExpr( ExprPtr operand )
	{
		return std::make_unique< ExprPreDecrement >( std::move( operand ) );
	}
}

#endif
