/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprGreater.hpp"
#include "ASTGenerator/Type/Type.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Greater::Greater( ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type::getBool() )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eGreater }
	{
	}

	void Greater::accept( VisitorPtr vis )
	{
		vis->visitGreaterExpr( this );
	}
}
