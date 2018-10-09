/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprSwitchCase.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprSwitchCase::ExprSwitchCase( ExprLiteralPtr label )
		: Expr{ label->getType(), Kind::eSwitchCase }
		, m_label{ std::move( label ) }
	{
	}

	void ExprSwitchCase::accept( ExprVisitorPtr vis )
	{
		vis->visitSwitchCaseExpr( this );
	}
}
