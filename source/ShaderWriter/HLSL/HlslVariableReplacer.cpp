/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslVariableReplacer.hpp"

namespace sdw::hlsl
{
	expr::ExprPtr VariableReplacer::submit( expr::Expr * expr
		, var::VariablePtr origin
		, var::VariablePtr replacement )
	{
		expr::ExprPtr result;
		VariableReplacer vis{ result, origin, replacement };
		expr->accept( &vis );
		return result;
	}
			
	expr::ExprPtr VariableReplacer::submit( expr::ExprPtr const & expr
		, var::VariablePtr origin
		, var::VariablePtr replacement )
	{
		return submit( expr.get(), origin, replacement );
	}

	VariableReplacer::VariableReplacer( expr::ExprPtr & result
		, var::VariablePtr origin
		, var::VariablePtr replacement )
		: ExprCloner{ result }
		, m_origin{ origin }
		, m_replacement{ replacement }
	{
	}

	ast::expr::ExprPtr VariableReplacer::doSubmit( ast::expr::Expr * expr )
	{
		expr::ExprPtr result;
		VariableReplacer vis{ result, m_origin, m_replacement };
		expr->accept( &vis );
		return result;
	}

	void VariableReplacer::visitIdentifierExpr( expr::Identifier * expr )
	{
		if ( expr->getVariable() == m_origin )
		{
			m_result = expr::makeIdentifier( m_replacement );
		}
		else
		{
			m_result = expr::makeIdentifier( expr->getVariable() );
		}
	}
}
