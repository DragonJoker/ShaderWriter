/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprSwitchTest.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	SwitchTest::SwitchTest( ExprPtr value )
		: Expr{ std::move( type::getUndefined() ), Kind::eSwitchTest }
		, m_value{ std::move( value ) }
	{
	}

	void SwitchTest::accept( VisitorPtr vis )
	{
		vis->visitSwitchTestExpr( this );
	}
}
