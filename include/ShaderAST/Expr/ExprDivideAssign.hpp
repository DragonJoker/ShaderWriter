/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprDivideAssign_H___
#define ___AST_ExprDivideAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class DivideAssign
		: public Assign
	{
	public:
		SDAST_API DivideAssign( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
