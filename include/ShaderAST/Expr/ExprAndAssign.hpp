/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAndAssign_H___
#define ___AST_ExprAndAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class AndAssign
		: public Assign
	{
	public:
		SDAST_API AndAssign( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
