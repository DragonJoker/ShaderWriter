/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprArrayAccess.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	ArrayAccess::ArrayAccess( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eArrayAccess }
	{
		assert( getLHS()->getType()->getKind() == type::Kind::eArray
			|| isVectorType( getLHS()->getType()->getKind() )
			|| isMatrixType( getLHS()->getType()->getKind() ) );
	}

	void ArrayAccess::accept( VisitorPtr vis )
	{
		vis->visitArrayAccessExpr( this );
	}
}
