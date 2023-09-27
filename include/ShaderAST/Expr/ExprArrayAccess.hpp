/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprArrayAccess_H___
#define ___AST_ExprArrayAccess_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class ArrayAccess
		: public Binary
	{
	public:
		SDAST_API ArrayAccess( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
}

#endif
