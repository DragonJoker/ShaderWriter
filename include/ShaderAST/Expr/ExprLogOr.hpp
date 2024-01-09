/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogOr_H___
#define ___AST_ExprLogOr_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class LogOr
		: public Binary
	{
	public:
		SDAST_API LogOr( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
