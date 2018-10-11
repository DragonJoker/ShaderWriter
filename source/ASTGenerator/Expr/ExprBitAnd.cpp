/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprBitAnd.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

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
