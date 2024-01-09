/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLShift_H___
#define ___AST_ExprLShift_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class LShift
		: public Binary
	{
	public:
		SDAST_API LShift( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
