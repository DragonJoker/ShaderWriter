/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprUnary.hpp"

#include "ShaderAST/Expr/ExprList.hpp"

namespace ast::expr
{
	Unary::Unary( type::TypePtr type
		, ExprPtr operand
		, Kind kind )
		: Expr{ getExprTypesCache( operand ), std::move( type ), kind, ( isExprConstant( operand ) ? Flag::eConstant : Flag::eNone ) }
		, m_operand{ std::move( operand ) }
	{
	}
}
