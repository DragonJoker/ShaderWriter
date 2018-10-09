/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprUnary.hpp"

namespace ast
{
	ExprUnary::ExprUnary( Type type
		, ExprPtr operand
		, Expr::Kind kind )
		: Expr{ type, kind }
		, m_operand{ std::move( operand ) }
	{
	}
}
