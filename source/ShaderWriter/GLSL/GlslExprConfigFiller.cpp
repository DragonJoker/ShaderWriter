/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GLSL/GlslExprConfigFiller.hpp"

#include "ShaderWriter/GLSL/GlslHelpers.hpp"
#include "ShaderWriter/GLSL/GlslTextureAccessConfig.hpp"

namespace sdw::glsl
{
	expr::ExprPtr ExprConfigFiller::submit( expr::Expr * expr
		, IntrinsicsConfig & config )
	{
		expr::ExprPtr result;
		ExprConfigFiller vis{ result, config };
		expr->accept( &vis );
		return result;
	}
			
	expr::ExprPtr ExprConfigFiller::submit( expr::ExprPtr const & expr
		, IntrinsicsConfig & config )
	{
		return submit( expr.get()
			, config );
	}

	ExprConfigFiller::ExprConfigFiller( expr::ExprPtr & result
		, IntrinsicsConfig & config )
		: ExprCloner{ result }
		, m_config{ config }
	{
	}

	ast::expr::ExprPtr ExprConfigFiller::doSubmit( ast::expr::Expr * expr )
	{
		expr::ExprPtr result;
		ExprConfigFiller vis{ result, m_config };
		expr->accept( &vis );
		return result;
	}

	void ExprConfigFiller::visitTextureAccessCallExpr( expr::TextureAccessCall * expr )
	{
		getGlslConfig( expr->getTextureAccess(), m_config );
		m_result = ExprCloner::submit( expr );
	}
}
