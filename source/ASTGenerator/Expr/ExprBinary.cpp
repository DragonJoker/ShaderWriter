/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprBinary.hpp"

namespace ast::expr
{
	Binary::Binary( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs
		, Kind kind )
		: Expr{ std::move( type ), kind }
		, m_lhs{ std::move( lhs ) }
		, m_rhs{ std::move( rhs ) }
	{
	}
}
