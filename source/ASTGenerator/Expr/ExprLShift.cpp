/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLShift.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprLShift::ExprLShift( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eLShift }
	{
	}

	void ExprLShift::accept( ExprVisitorPtr vis )
	{
		vis->visitLShiftExpr( this );
	}
}
