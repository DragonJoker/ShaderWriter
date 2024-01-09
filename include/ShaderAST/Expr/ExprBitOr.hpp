/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitOr_H___
#define ___AST_ExprBitOr_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class BitOr
		: public Binary
	{
	public:
		SDAST_API BitOr( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
