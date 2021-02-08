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
		SDAST_API Question( type::TypePtr type
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
		ExprPtr m_ctrlExpr;
		ExprPtr m_trueExpr;
		ExprPtr m_falseExpr;
	};
	using QuestionPtr = std::unique_ptr< Question >;

	inline QuestionPtr makeQuestion( type::TypePtr type
		, ExprPtr ctrlExpr
		, ExprPtr trueExpr
		, ExprPtr falseExpr )
	{
		return std::make_unique< Question >( std::move( type )
			, std::move( ctrlExpr )
			, std::move( trueExpr )
			, std::move( falseExpr ) );
	}
}

#endif
