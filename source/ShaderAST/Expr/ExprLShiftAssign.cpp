/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLShiftAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	LShiftAssign::LShiftAssign( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eLShiftAssign }
	{
	}

	void LShiftAssign::accept( VisitorPtr vis )const
	{
		vis->visitLShiftAssignExpr( this );
	}
}
