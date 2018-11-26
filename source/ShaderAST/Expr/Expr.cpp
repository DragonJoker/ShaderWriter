/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/Expr.hpp"

namespace ast::expr
{
	Expr::Expr( type::TypePtr type, Kind kind )
		: m_kind{ kind }
		, m_type{ std::move( type ) }
		, m_flags{ 0u }
	{
	}

	Expr::~Expr()
	{
	}
}
