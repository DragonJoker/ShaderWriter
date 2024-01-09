/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitXor_H___
#define ___AST_ExprBitXor_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class BitXor
		: public Binary
	{
	public:
		SDAST_API BitXor( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
