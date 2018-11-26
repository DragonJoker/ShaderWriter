/*
See LICENSE file in root folder
*/
#include "HlslExprConfigFiller.hpp"

#include "HlslHelpers.hpp"
#include "HlslVariableReplacer.hpp"
#include "HlslImageAccessConfig.hpp"
#include "HlslIntrinsicConfig.hpp"
#include "HlslTextureAccessConfig.hpp"

#include <ShaderWriter/Intrinsics/Intrinsics.hpp>

namespace hlsl
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

	void ExprConfigFiller::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		getHlslConfig( expr->getImageAccess(), m_config );
		m_result = ExprCloner::submit( expr );
	}

	void ExprConfigFiller::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		getHlslConfig( expr->getIntrinsic(), m_config );
		m_result = ExprCloner::submit( expr );
	}

	void ExprConfigFiller::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		getHlslConfig( expr->getTextureAccess(), m_config );
		m_result = ExprCloner::submit( expr );
	}
}
