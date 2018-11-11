/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslExprConfigFiller.hpp"

#include "ShaderWriter/HLSL/HlslHelpers.hpp"
#include "ShaderWriter/HLSL/HlslVariableReplacer.hpp"
#include "ShaderWriter/HLSL/HlslImageAccessConfig.hpp"
#include "ShaderWriter/HLSL/HlslIntrinsicConfig.hpp"
#include "ShaderWriter/HLSL/HlslTextureAccessConfig.hpp"

#include "ShaderWriter/Intrinsics.hpp"

namespace sdw::hlsl
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

	void ExprConfigFiller::visitImageAccessCallExpr( expr::ImageAccessCall * expr )
	{
		getHlslConfig( expr->getImageAccess(), m_config );
		m_result = ExprCloner::submit( expr );
	}

	void ExprConfigFiller::visitIntrinsicCallExpr( expr::IntrinsicCall * expr )
	{
		getHlslConfig( expr->getIntrinsic(), m_config );
		m_result = ExprCloner::submit( expr );
	}

	void ExprConfigFiller::visitTextureAccessCallExpr( expr::TextureAccessCall * expr )
	{
		getHlslConfig( expr->getTextureAccess(), m_config );
		m_result = ExprCloner::submit( expr );
	}
}
