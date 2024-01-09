/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprPreDecrement_H___
#define ___AST_ExprPreDecrement_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class PreDecrement
		: public Unary
	{
	public:
		SDAST_API PreDecrement( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr operand );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
