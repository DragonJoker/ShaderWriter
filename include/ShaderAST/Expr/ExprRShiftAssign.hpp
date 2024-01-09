/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprRShiftAssign_H___
#define ___AST_ExprRShiftAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class RShiftAssign
		: public Assign
	{
	public:
		SDAST_API RShiftAssign( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
