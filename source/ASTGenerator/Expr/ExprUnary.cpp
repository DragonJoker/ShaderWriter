/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprUnary.hpp"

namespace ast::expr
{
	Unary::Unary( type::TypePtr type
		, ExprPtr operand
		, Kind kind )
		: Expr{ std::move( type ), kind }
		, m_operand{ std::move( operand ) }
	{
	}
}
