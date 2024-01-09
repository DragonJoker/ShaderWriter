/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLShiftAssign_H___
#define ___AST_ExprLShiftAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class LShiftAssign
		: public Assign
	{
	public:
		SDAST_API LShiftAssign( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
