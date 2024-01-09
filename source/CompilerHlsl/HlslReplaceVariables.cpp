/*
See LICENSE file in root folder
*/
#include "HlslReplaceVariables.hpp"

#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace hlsl
{
	namespace replace
	{
		class VariableReplacer
			: public ast::ExprCloner
		{
		public:
			static ast::expr::ExprPtr submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr const & expr
				, ast::var::VariablePtr origin
				, ast::var::VariablePtr replacement )
			{
				ast::expr::ExprPtr result{};
				VariableReplacer vis{ exprCache, result, origin, replacement };
				expr.accept( &vis );
				return result;
			}

		private:
			VariableReplacer( ast::expr::ExprCache & exprCache
				, ast::expr::ExprPtr & result
				, ast::var::VariablePtr origin
				, ast::var::VariablePtr replacement )
				: ExprCloner{ exprCache, result }
				, m_origin{ origin }
				, m_replacement{ replacement }
			{
			}

			using ast::ExprCloner::doSubmit;

			ast::expr::ExprPtr doSubmit( ast::expr::Expr const & expr )override
			{
				ast::expr::ExprPtr result{};
				VariableReplacer vis{ m_exprCache, result, m_origin, m_replacement };
				expr.accept( &vis );
				return result;
			}

			void visitIdentifierExpr( ast::expr::Identifier const * expr )override
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

		private:
			ast::var::VariablePtr m_origin;
			ast::var::VariablePtr m_replacement;
		};
	}

	ast::expr::ExprPtr replaceVariables( ast::expr::ExprCache & exprCache
		, ast::expr::Expr const & expr
		, ast::var::VariablePtr origin
		, ast::var::VariablePtr replacement )
	{
		return replace::VariableReplacer::submit( exprCache, expr, origin, replacement );
	}
}
