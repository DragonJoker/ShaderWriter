/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprTimesAssign_H___
#define ___AST_ExprTimesAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class TimesAssign
		: public Assign
	{
	public:
		SDAST_API TimesAssign( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
