/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprGreaterEqual_H___
#define ___AST_ExprGreaterEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class GreaterEqual
		: public Binary
	{
	public:
		SDAST_API GreaterEqual( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
