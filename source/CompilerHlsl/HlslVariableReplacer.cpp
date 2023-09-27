/*
See LICENSE file in root folder
*/
#include "HlslVariableReplacer.hpp"

namespace hlsl
{
	ast::expr::ExprPtr VariableReplacer::submit( ast::expr::ExprCache & exprCache
		, ast::expr::Expr * expr
		, ast::var::VariablePtr origin
		, ast::var::VariablePtr replacement )
	{
		ast::expr::ExprPtr result{};
		VariableReplacer vis{ exprCache, result, origin, replacement };
		expr->accept( &vis );
		return result;
	}

	VariableReplacer::VariableReplacer( ast::expr::ExprCache & exprCache
		, ast::expr::ExprPtr & result
		, ast::var::VariablePtr origin
		, ast::var::VariablePtr replacement )
		: ExprCloner{ exprCache, result }
		, m_origin{ origin }
		, m_replacement{ replacement }
	{
	}

	ast::expr::ExprPtr VariableReplacer::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result{};
		VariableReplacer vis{ m_exprCache, result, m_origin, m_replacement };
		expr->accept( &vis );
		return result;
	}

	void VariableReplacer::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		if ( expr->getVariable() == m_origin )
		{
			m_result = m_exprCache.makeIdentifier( expr->getTypesCache(), m_replacement );
		}
		else
		{
			m_result = m_exprCache.makeIdentifier( expr->getTypesCache(), expr->getVariable() );
		}
	}
}
