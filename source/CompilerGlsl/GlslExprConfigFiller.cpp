/*
See LICENSE file in root folder
*/
#include "GlslExprConfigFiller.hpp"

#include "GlslHelpers.hpp"
#include "GlslTextureAccessConfig.hpp"

namespace glsl
{
	ast::expr::ExprPtr ExprConfigFiller::submit( ast::expr::Expr * expr
		, IntrinsicsConfig & config )
	{
		ast::expr::ExprPtr result;
		ExprConfigFiller vis{ result, config };
		expr->accept( &vis );
		return result;
	}
			
	ast::expr::ExprPtr ExprConfigFiller::submit( ast::expr::ExprPtr const & expr
		, IntrinsicsConfig & config )
	{
		return submit( expr.get()
			, config );
	}

	ExprConfigFiller::ExprConfigFiller( ast::expr::ExprPtr & result
		, IntrinsicsConfig & config )
		: ExprCloner{ result }
		, m_config{ config }
	{
	}

	ast::expr::ExprPtr ExprConfigFiller::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result;
		ExprConfigFiller vis{ result, m_config };
		expr->accept( &vis );
		return result;
	}

	void ExprConfigFiller::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		getGlslConfig( expr->getTextureAccess(), m_config );
		m_result = ExprCloner::submit( expr );
	}
}
