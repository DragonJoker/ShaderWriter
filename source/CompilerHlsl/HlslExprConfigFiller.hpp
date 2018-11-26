/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslExprConfigFiller_H___
#define ___SDW_HlslExprConfigFiller_H___
#pragma once

#include "HlslHelpers.hpp"
#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace hlsl
{
	class ExprConfigFiller
		: public ast::ExprCloner
	{
	public:
		static ast::expr::ExprPtr submit( ast::expr::Expr * expr
			, IntrinsicsConfig & config );
		static ast::expr::ExprPtr submit( ast::expr::ExprPtr const & expr
			, IntrinsicsConfig & config );

	private:
		ExprConfigFiller( ast::expr::ExprPtr & result
			, IntrinsicsConfig & config );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;

	private:
		IntrinsicsConfig & m_config;
	};
}

#endif
