/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprNotEqual_H___
#define ___AST_ExprNotEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class NotEqual
		: public Binary
	{
	public:
		SDAST_API NotEqual( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
