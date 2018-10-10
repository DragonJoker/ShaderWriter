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
		ExprQuestion( TypePtr type
			, ExprPtr ctrlExpr
			, ExprPtr trueExpr
			, ExprPtr falseExpr );

		void accept( ExprVisitorPtr vis )override;

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
		ExprPtr m_ctrlExpr;
		ExprPtr m_trueExpr;
		ExprPtr m_falseExpr;
	};

	inline std::unique_ptr< ExprQuestion > makeQuestionExpr( TypePtr type
		, ExprPtr ctrlExpr
		, ExprPtr trueExpr
		, ExprPtr falseExpr )
	{
		return std::make_unique< ExprQuestion >( type
			, std::move( ctrlExpr )
			, std::move( trueExpr )
			, std::move( falseExpr ) );
	}
}

#endif
