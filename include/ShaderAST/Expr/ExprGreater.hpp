/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprGreater_H___
#define ___AST_ExprGreater_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Greater
		: public Binary
	{
	public:
		SDAST_API Greater( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
