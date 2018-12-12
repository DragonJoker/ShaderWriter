/*
See LICENSE file in root folder
*/
#include "HlslVariableReplacer.hpp"

namespace hlsl
{
	ast::expr::ExprPtr VariableReplacer::submit( ast::expr::Expr * expr
		, ast::var::VariablePtr origin
		, ast::var::VariablePtr replacement )
	{
		ast::expr::ExprPtr result;
		VariableReplacer vis{ result, origin, replacement };
		expr->accept( &vis );
		return result;
	}
			
	ast::expr::ExprPtr VariableReplacer::submit( ast::expr::ExprPtr const & expr
		, ast::var::VariablePtr origin
		, ast::var::VariablePtr replacement )
	{
		return submit( expr.get(), origin, replacement );
	}

	VariableReplacer::VariableReplacer( ast::expr::ExprPtr & result
		, ast::var::VariablePtr origin
		, ast::var::VariablePtr replacement )
		: ExprCloner{ result }
		, m_origin{ origin }
		, m_replacement{ replacement }
	{
	}

	ast::expr::ExprPtr VariableReplacer::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result;
		VariableReplacer vis{ result, m_origin, m_replacement };
		expr->accept( &vis );
		return result;
	}

	void VariableReplacer::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		if ( expr->getVariable() == m_origin )
		{
			m_result = ast::expr::makeIdentifier( expr->getCache(), m_replacement );
		}
		else
		{
			m_result = ast::expr::makeIdentifier( expr->getCache(), expr->getVariable() );
		}
	}
}
