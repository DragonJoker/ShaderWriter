/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprPreIncrement_H___
#define ___AST_ExprPreIncrement_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class PreIncrement
		: public Unary
	{
	public:
		SDAST_API PreIncrement( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr operand );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
