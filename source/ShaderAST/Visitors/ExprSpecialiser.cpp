/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/ExprSpecialiser.hpp"

namespace ast
{
	expr::ExprPtr ExprSpecialiser::submit( expr::Expr * expr
		, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations )
	{
		expr::ExprPtr result;
		ExprSpecialiser vis{ result, specialisations };
		expr->accept( &vis );
		return result;
	}
			
	expr::ExprPtr ExprSpecialiser::submit( expr::ExprPtr const & expr
		, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations )
	{
		return submit( expr.get()
			, specialisations );
	}

	ExprSpecialiser::ExprSpecialiser( expr::ExprPtr & result
		, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations )
		: ExprCloner{ result }
		, m_specialisations{ specialisations }
	{
	}

	ast::expr::ExprPtr ExprSpecialiser::doSubmit( ast::expr::Expr * expr )
	{
		expr::ExprPtr result;
		ExprSpecialiser vis{ result, m_specialisations };
		expr->accept( &vis );
		return result;
	}

	void ExprSpecialiser::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		auto it = m_specialisations.find( expr->getVariable() );

		if ( it != m_specialisations.end() )
		{
			m_result = doSubmit( it->second.get() );
		}
		else
		{
			m_result = expr::makeIdentifier( expr->getVariable() );
		}
	}
}
