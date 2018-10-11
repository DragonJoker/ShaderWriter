/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/Expr.hpp"

namespace ast::expr
{
	Expr::Expr( type::TypePtr type, Kind kind )
		: m_kind{ kind }
		, m_type{ std::move( type ) }
	{
	}

	Expr::~Expr()
	{
	}
}
