/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprModulo_H___
#define ___AST_ExprModulo_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Modulo
		: public Binary
	{
	public:
		SDAST_API Modulo( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
