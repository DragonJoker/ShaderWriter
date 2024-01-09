/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprEqual_H___
#define ___AST_ExprEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Equal
		: public Binary
	{
	public:
		SDAST_API Equal( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
