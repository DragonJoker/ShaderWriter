/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAdd_H___
#define ___AST_ExprAdd_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Add
		: public Binary
	{
	public:
		SDAST_API Add( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
