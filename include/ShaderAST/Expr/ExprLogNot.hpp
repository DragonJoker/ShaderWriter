/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogNot_H___
#define ___AST_ExprLogNot_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class LogNot
		: public Unary
	{
	public:
		SDAST_API LogNot( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr operand );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
