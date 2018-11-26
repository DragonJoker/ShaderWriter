/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslExprConfigFiller_H___
#define ___SDW_HlslExprConfigFiller_H___
#pragma once

#include "ShaderWriter/HLSL/HlslHelpers.hpp"
#include <ASTGenerator/Visitors/CloneExpr.hpp>

namespace sdw::hlsl
{
	class ExprConfigFiller
		: public ExprCloner
	{
	public:
		static expr::ExprPtr submit( expr::Expr * expr
			, IntrinsicsConfig & config );
		static expr::ExprPtr submit( expr::ExprPtr const & expr
			, IntrinsicsConfig & config );

	private:
		ExprConfigFiller( expr::ExprPtr & result
			, IntrinsicsConfig & config );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override;
		void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override;
		void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;

	private:
		IntrinsicsConfig & m_config;
	};
}

#endif
