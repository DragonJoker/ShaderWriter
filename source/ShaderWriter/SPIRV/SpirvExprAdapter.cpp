/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SPIRV/SpirvExprAdapter.hpp"
#include "ShaderWriter/SPIRV/SpirvExprEvaluator.hpp"

namespace sdw::spirv
{
	expr::ExprPtr ExprAdapter::submit( expr::Expr * expr
		, PreprocContext const & context )
	{
		expr::ExprPtr result;
		ExprAdapter vis{ result, context };
		expr->accept( &vis );
		return result;
	}

	ExprAdapter::ExprAdapter( expr::ExprPtr & result
		, PreprocContext const & context )
		: ExprCloner{ result }
		, m_context{ context }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		expr::ExprPtr result;
		ExprAdapter vis{ result, m_context };
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitIdentifierExpr( expr::Identifier * expr )
	{
		auto it = m_context.defines.find( expr->getVariable()->getName() );

		if ( it != m_context.defines.end() )
		{
			m_result = getLiteral( expr, m_context );
		}
		else
		{
			m_result = ExprCloner::submit( expr );
		}
	}
}
