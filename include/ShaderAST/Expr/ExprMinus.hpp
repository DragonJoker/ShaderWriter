/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMinus_H___
#define ___AST_ExprMinus_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Minus
		: public Binary
	{
	public:
		SDAST_API Minus( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
