/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprRShift_H___
#define ___AST_ExprRShift_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class RShift
		: public Binary
	{
	public:
		SDAST_API RShift( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
