/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprBinary.hpp"

#include "ShaderAST/Expr/ExprCache.hpp"

namespace ast::expr
{
	Binary::Binary( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs
		, Kind kind )
		: Expr{ exprCache
			, sizeof( Binary )
			, getExprTypesCache( lhs, rhs )
			, std::move( type )
			, kind
			, isExprConstant( lhs, rhs ) ? Flag::eConstant : Flag::eNone }
		, m_lhs{ std::move( lhs ) }
		, m_rhs{ std::move( rhs ) }
	{
		if ( !m_lhs && !m_rhs )
		{
			AST_Exception( "Binary expression without operands" );
		}
	}
}
