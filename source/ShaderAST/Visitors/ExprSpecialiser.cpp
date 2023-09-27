/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/ExprSpecialiser.hpp"

namespace ast
{
	expr::ExprPtr ExprSpecialiser::submit( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, expr::Expr * expr
		, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations )
	{
		expr::ExprPtr result{};
		ExprSpecialiser vis{ exprCache, typesCache, specialisations, result };
		expr->accept( &vis );
		return result;
	}

	expr::ExprPtr ExprSpecialiser::submit( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, expr::ExprPtr const & expr
		, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations )
	{
		return submit( exprCache
			, typesCache
			, expr.get()
			, specialisations );
	}

	ExprSpecialiser::ExprSpecialiser( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations
		, expr::ExprPtr & result )
		: ExprCloner{ exprCache, result }
		, m_typesCache{ typesCache }
		, m_specialisations{ specialisations }
	{
	}

	ast::expr::ExprPtr ExprSpecialiser::doSubmit( ast::expr::Expr * expr )
	{
		expr::ExprPtr result{};
		ExprSpecialiser vis{ m_exprCache, m_typesCache, m_specialisations, result };
		expr->accept( &vis );

		if ( expr->isNonUniform() )
		{
			result->updateFlag( ast::expr::Flag::eNonUniform );
		}

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
			m_result = m_exprCache.makeIdentifier( m_typesCache, expr->getVariable() );
		}
	}
}
