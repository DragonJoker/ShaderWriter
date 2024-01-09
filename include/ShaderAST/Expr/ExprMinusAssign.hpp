/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMinusAssign_H___
#define ___AST_ExprMinusAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class MinusAssign
		: public Assign
	{
	public:
		SDAST_API MinusAssign( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
