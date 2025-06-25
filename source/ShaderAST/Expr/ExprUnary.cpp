/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprUnary.hpp"

#include "ShaderAST/Expr/ExprCache.hpp"
#include "ShaderAST/Expr/ExprList.hpp"

namespace ast::expr
{
	namespace helper
	{
		static type::TypesCache & getOperandTypesCache( type::TypePtr type
			, Expr * operand )
		{
			if ( !operand )
				AST_Exception( "Unary expression without operand" );
			return getExprTypesCache( *operand );
		}
	}

	Unary::Unary( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr operand
		, Kind kind )
		: Expr{ exprCache
			, sizeof( Unary )
			, helper::getOperandTypesCache( type, operand.get() )
			, type
			, kind
			, ( isExprConstant( operand ) ? Flag::eConstant : Flag::eNone ) }
		, m_operand{ std::move( operand ) }
	{
	}

	Unary::Unary( ExprCache & exprCache
		, ExprPtr operand
		, Kind kind )
		: Expr{ exprCache
			, sizeof( Unary )
			, helper::getOperandTypesCache( nullptr, operand.get() )
			, operand->getType()
			, kind
			, ( isExprConstant( operand ) ? Flag::eConstant : Flag::eNone ) }
		, m_operand{ std::move( operand ) }
	{
	}
}
