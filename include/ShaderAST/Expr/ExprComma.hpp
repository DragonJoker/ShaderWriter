/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprComma_H___
#define ___AST_ExprComma_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Comma
		: public Binary
	{
	public:
		SDAST_API Comma( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
