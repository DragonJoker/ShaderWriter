/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprQuestion.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprQuestion::ExprQuestion( TypePtr type
		, ExprPtr ctrlExpr
		, ExprPtr trueExpr
		, ExprPtr falseExpr )
		: Expr{ type, Kind::eQuestion }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
		, m_trueExpr{ std::move( trueExpr ) }
		, m_falseExpr{ std::move( falseExpr ) }
	{
	}

	void ExprQuestion::accept( ExprVisitorPtr vis )
	{
		vis->visitQuestionExpr( this );
	}
}
