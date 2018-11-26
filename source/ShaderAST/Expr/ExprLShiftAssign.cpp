/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLShiftAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	LShiftAssign::LShiftAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eLShiftAssign }
	{
	}

	void LShiftAssign::accept( VisitorPtr vis )
	{
		vis->visitLShiftAssignExpr( this );
	}
}
