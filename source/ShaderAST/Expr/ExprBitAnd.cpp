/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprBitAnd.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	BitAnd::BitAnd( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eBitAnd }
	{
	}

	void BitAnd::accept( VisitorPtr vis )
	{
		vis->visitBitAndExpr( this );
	}
}
