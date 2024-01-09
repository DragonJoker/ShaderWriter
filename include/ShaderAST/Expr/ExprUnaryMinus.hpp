/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprUnaryMinus_H___
#define ___AST_ExprUnaryMinus_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class UnaryMinus
		: public Unary
	{
	public:
		SDAST_API UnaryMinus( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr operand );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
