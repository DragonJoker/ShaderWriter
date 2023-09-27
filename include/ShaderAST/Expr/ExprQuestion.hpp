/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprQuestion_H___
#define ___AST_ExprQuestion_H___
#pragma once

#include "Expr.hpp"

namespace ast::expr
{
	class Question
		: public Expr
	{
	public:
		SDAST_API Question( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr ctrlExpr
			, ExprPtr trueExpr
			, ExprPtr falseExpr );

		SDAST_API void accept( VisitorPtr vis )override;

		inline Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

		inline Expr * getTrueExpr()const
		{
			return m_trueExpr.get();
		}

		inline Expr * getFalseExpr()const
		{
			return m_falseExpr.get();
		}

	private:
		ExprPtr m_ctrlExpr{};
		ExprPtr m_trueExpr{};
		ExprPtr m_falseExpr{};
	};
}

#endif
