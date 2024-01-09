/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitAnd_H___
#define ___AST_ExprBitAnd_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class BitAnd
		: public Binary
	{
	public:
		SDAST_API BitAnd( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
