/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprCast_H___
#define ___AST_ExprCast_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class Cast
		: public Unary
	{
	public:
		SDAST_API Cast( ExprCache & exprCache
			, type::TypePtr dstType
			, ExprPtr operand );

		SDAST_API void accept( VisitorPtr vis )const override;
	};

	Expr const * removeCasts( Expr const & expr );
}

#endif
