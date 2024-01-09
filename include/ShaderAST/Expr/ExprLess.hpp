/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLess_H___
#define ___AST_ExprLess_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Less
		: public Binary
	{
	public:
		SDAST_API Less( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
