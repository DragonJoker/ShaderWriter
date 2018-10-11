/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLShift.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	LShift::LShift( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eLShift }
	{
	}

	void LShift::accept( VisitorPtr vis )
	{
		vis->visitLShiftExpr( this );
	}
}
