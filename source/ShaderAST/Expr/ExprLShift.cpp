/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLShift.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	LShift::LShift( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eLShift }
	{
	}

	void LShift::accept( VisitorPtr vis )const
	{
		vis->visitLShiftExpr( this );
	}
}
