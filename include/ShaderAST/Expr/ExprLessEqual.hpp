/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLessEqual_H___
#define ___AST_ExprLessEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class LessEqual
		: public Binary
	{
	public:
		SDAST_API LessEqual( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
