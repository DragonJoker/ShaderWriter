/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprUnaryPlus_H___
#define ___AST_ExprUnaryPlus_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class UnaryPlus
		: public Unary
	{
	public:
		SDAST_API UnaryPlus( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr operand );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
