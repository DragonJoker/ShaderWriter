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

		inline Expr const & getCtrlExpr()const
		{
			return *m_ctrlExpr;
		}

		inline Expr const & getTrueExpr()const
		{
			return *m_trueExpr;
		}

		inline Expr const & getFalseExpr()const
		{
			return *m_falseExpr;
		}

	private:
		ExprPtr m_ctrlExpr;
		ExprPtr m_trueExpr;
		ExprPtr m_falseExpr;
	};
}

#endif
