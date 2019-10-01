/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprBinary.hpp"

#include "ShaderAST/Expr/ExprList.hpp"

namespace ast::expr
{
	Binary::Binary( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs
		, Kind kind )
		: Expr{ getExprTypesCache( lhs, rhs ), std::move( type ), kind, isExprConstant( lhs, rhs ) ? Flag::eConstant : Flag::eNone }
		, m_lhs{ std::move( lhs ) }
		, m_rhs{ std::move( rhs ) }
	{
	}
}
