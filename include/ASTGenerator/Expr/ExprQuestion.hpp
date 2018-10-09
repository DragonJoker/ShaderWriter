/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprQuestion_H___
#define ___AST_ExprQuestion_H___
#pragma once

#include "Expr.hpp"

namespace ast
{
	class ExprQuestion
		: public Expr
	{
	public:
		ExprQuestion( Type type
			, ExprPtr ctrlExpr
			, ExprPtr trueExpr
			, ExprPtr falseExpr );

		void accept( ExprVisitorPtr vis )override;

	private:
		ExprPtr m_ctrlExpr;
		ExprPtr m_trueExpr;
		ExprPtr m_falseExpr;
	};
}

#endif
