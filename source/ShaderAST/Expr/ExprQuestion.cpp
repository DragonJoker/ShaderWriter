/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprQuestion.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Question::Question( type::TypePtr type
		, ExprPtr ctrlExpr
		, ExprPtr trueExpr
		, ExprPtr falseExpr )
		: Expr{ std::move( type ), Kind::eQuestion }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
		, m_trueExpr{ std::move( trueExpr ) }
		, m_falseExpr{ std::move( falseExpr ) }
	{
	}

	void Question::accept( VisitorPtr vis )
	{
		vis->visitQuestionExpr( this );
	}
}
