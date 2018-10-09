/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprMbrSelect.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprMbrSelect::ExprMbrSelect( VariablePtr variable
		, ExprIdentifierPtr member )
		: ExprUnary{ member->getType(), std::move( member ), Kind::eMbrSelect }
		, m_variable{ std::move( variable ) }
	{
	}

	void ExprMbrSelect::accept( ExprVisitorPtr vis )
	{
		vis->visitMbrSelectExpr( this );
	}
}
