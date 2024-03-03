/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprUnary.hpp"

#include "ShaderAST/Expr/ExprCache.hpp"
#include "ShaderAST/Expr/ExprList.hpp"

namespace ast::expr
{
	Unary::Unary( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr operand
		, Kind kind )
		: Expr{ exprCache
			, sizeof( Unary )
			, getExprTypesCache( operand )
			, std::move( type )
			, kind
			, ( isExprConstant( operand ) ? Flag::eConstant : Flag::eNone ) }
		, m_operand{ std::move( operand ) }
	{
		if ( !m_operand )
		{
			AST_Exception( "Unary expression without operand" );
		}
	}

	Unary::Unary( ExprCache & exprCache
		, ExprPtr operand
		, Kind kind )
		: Expr{ exprCache
			, sizeof( Unary )
			, getExprTypesCache( operand )
			, operand->getType()
			, kind
			, ( isExprConstant( operand ) ? Flag::eConstant : Flag::eNone ) }
		, m_operand{ std::move( operand ) }
	{
	}
}
