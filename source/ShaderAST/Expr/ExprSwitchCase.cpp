/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprSwitchCase.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	SwitchCase::SwitchCase( LiteralPtr label )
		: Expr{ getExprTypesCache( *label ), label->getType(), Kind::eSwitchCase, Flag::eConstant }
		, m_label{ std::move( label ) }
	{
	}

	void SwitchCase::accept( VisitorPtr vis )
	{
		vis->visitSwitchCaseExpr( this );
	}
}
