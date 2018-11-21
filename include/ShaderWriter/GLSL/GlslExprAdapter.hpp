/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslExprAdapter_H___
#define ___SDW_GlslExprAdapter_H___
#pragma once

#include "ShaderWriter/GLSL/GlslHelpers.hpp"
#include "ShaderWriter/Visitors/CloneExpr.hpp"

namespace sdw::glsl
{
	class ExprAdapter
		: public ExprCloner
	{
	public:
		static expr::ExprPtr submit( expr::Expr * expr
			, IntrinsicsConfig const & config );
		static expr::ExprPtr submit( expr::ExprPtr const & expr
			, IntrinsicsConfig const & config );

	private:
		ExprAdapter( expr::ExprPtr & result
			, IntrinsicsConfig const & config );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override;
		void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;

		void doProcessImageLoad( expr::ImageAccessCall * expr );
		void doProcessTextureShadow( expr::TextureAccessCall * expr );
		void doProcessTextureSample( expr::TextureAccessCall * expr );
		void doProcessTextureGather( expr::TextureAccessCall * expr );

	private:
		IntrinsicsConfig const & m_config;
	};
}

#endif
