/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprBinary.hpp"

namespace ast
{
	ExprBinary::ExprBinary( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs
		, Expr::Kind kind )
		: Expr{ type, kind }
		, m_lhs{ std::move( lhs ) }
		, m_rhs{ std::move( rhs ) }
	{
	}
}
