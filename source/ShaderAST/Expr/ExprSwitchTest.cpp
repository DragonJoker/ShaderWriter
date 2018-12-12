/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprSwitchTest.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	SwitchTest::SwitchTest( ExprPtr value )
		: Expr{ getExprTypesCache( value ), std::move( value->getType() ), Kind::eSwitchTest }
		, m_value{ std::move( value ) }
	{
	}

	void SwitchTest::accept( VisitorPtr vis )
	{
		vis->visitSwitchTestExpr( this );
	}
}
