/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslExprConfigFiller_H___
#define ___SDW_GlslExprConfigFiller_H___
#pragma once

#include "ShaderWriter/GLSL/GlslHelpers.hpp"
#include "ShaderWriter/Visitors/CloneExpr.hpp"

namespace sdw::glsl
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
		void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;

	private:
		IntrinsicsConfig & m_config;
	};
}

#endif
