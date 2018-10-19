/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprIntrinsicCall.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	IntrinsicCall::IntrinsicCall( type::TypePtr type
		, Intrinsic intrinsic
		, ExprList && argList )
		: Expr{ std::move( type ), Kind::eIntrinsicCall }
		, m_intrinsic{ intrinsic }
		, m_argList{ std::move( argList ) }
	{
	}

	void IntrinsicCall::accept( VisitorPtr vis )
	{
		vis->visitIntrinsicCallExpr( this );
	}
}
