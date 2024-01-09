/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprXorAssign_H___
#define ___AST_ExprXorAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class XorAssign
		: public Assign
	{
	public:
		SDAST_API XorAssign( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
