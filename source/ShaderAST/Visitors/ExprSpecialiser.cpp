/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/ExprSpecialiser.hpp"

namespace ast
{
	expr::ExprPtr ExprSpecialiser::submit( type::TypesCache & cache
		, expr::Expr * expr
		, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations )
	{
		expr::ExprPtr result;
		ExprSpecialiser vis{ cache, specialisations, result };
		expr->accept( &vis );
		return result;
	}
			
	expr::ExprPtr ExprSpecialiser::submit( type::TypesCache & cache
		, expr::ExprPtr const & expr
		, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations )
	{
		return submit( cache
			, expr.get()
			, specialisations );
	}

	ExprSpecialiser::ExprSpecialiser( type::TypesCache & cache
		, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations
		, expr::ExprPtr & result )
		: ExprCloner{ result }
		, m_cache{ cache }
		, m_specialisations{ specialisations }
	{
	}

	ast::expr::ExprPtr ExprSpecialiser::doSubmit( ast::expr::Expr * expr )
	{
		expr::ExprPtr result;
		ExprSpecialiser vis{ m_cache, m_specialisations, result };
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
			m_result = expr::makeIdentifier( m_cache, expr->getVariable() );
		}
	}
}
