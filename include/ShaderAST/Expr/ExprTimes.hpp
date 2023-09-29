/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprTimes_H___
#define ___AST_ExprTimes_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Times
		: public Binary
	{
	public:
		SDAST_API Times( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
}

#endif
