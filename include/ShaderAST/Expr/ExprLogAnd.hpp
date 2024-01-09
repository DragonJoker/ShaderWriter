/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogAnd_H___
#define ___AST_ExprLogAnd_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class LogAnd
		: public Binary
	{
	public:
		SDAST_API LogAnd( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
