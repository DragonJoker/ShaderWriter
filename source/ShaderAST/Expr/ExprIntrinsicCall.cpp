/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprIntrinsicCall.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	IntrinsicCall::IntrinsicCall( type::TypePtr type
		, Intrinsic intrinsic
		, ExprList && argList )
		: Expr{ type->getCache(), type, Kind::eIntrinsicCall, Flag::eNone }
		, m_intrinsic{ intrinsic }
		, m_argList{ std::move( argList ) }
	{
	}

	void IntrinsicCall::accept( VisitorPtr vis )
	{
		vis->visitIntrinsicCallExpr( this );
	}
}
