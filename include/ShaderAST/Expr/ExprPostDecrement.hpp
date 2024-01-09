/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprPostDecrement_H___
#define ___AST_ExprPostDecrement_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class PostDecrement
		: public Unary
	{
	public:
		SDAST_API PostDecrement( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr operand );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
