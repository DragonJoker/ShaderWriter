/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprSwitchCase.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	SwitchCase::SwitchCase( LiteralPtr label )
		: Expr{ std::move( label->getType() ), Kind::eSwitchCase }
		, m_label{ std::move( label ) }
	{
	}

	void SwitchCase::accept( VisitorPtr vis )
	{
		vis->visitSwitchCaseExpr( this );
	}
}
