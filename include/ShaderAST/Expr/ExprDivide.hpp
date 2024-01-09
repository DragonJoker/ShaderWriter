/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprDivide_H___
#define ___AST_ExprDivide_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Divide
		: public Binary
	{
	public:
		SDAST_API Divide( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
