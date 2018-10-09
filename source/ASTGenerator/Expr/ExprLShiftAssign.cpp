/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLShiftAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprLShiftAssign::ExprLShiftAssign( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprAssign{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eLShiftAssign }
	{
	}

	void ExprLShiftAssign::accept( ExprVisitorPtr vis )
	{
		vis->visitLShiftAssignExpr( this );
	}
}
