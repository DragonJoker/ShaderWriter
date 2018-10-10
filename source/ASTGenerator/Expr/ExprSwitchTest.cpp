/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprSwitchTest.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprSwitchTest::ExprSwitchTest( ExprPtr value )
		: Expr{ getUndefinedType(), Kind::eSwitchTest }
		, m_value{ std::move( value ) }
	{
	}

	void ExprSwitchTest::accept( ExprVisitorPtr vis )
	{
		vis->visitSwitchTestExpr( this );
	}
}
