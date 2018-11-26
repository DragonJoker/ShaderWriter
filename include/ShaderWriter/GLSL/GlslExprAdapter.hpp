/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslExprAdapter_H___
#define ___SDW_GlslExprAdapter_H___
#pragma once

#include "ShaderWriter/WriterGlsl.hpp"
#include "ShaderWriter/GLSL/GlslHelpers.hpp"

#include <ASTGenerator/Visitors/CloneExpr.hpp>

namespace sdw::glsl
{
	class ExprAdapter
		: public ast::ExprCloner
	{
	public:
		static expr::ExprPtr submit( expr::Expr * expr
			, GlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig );
		static expr::ExprPtr submit( expr::ExprPtr const & expr
			, GlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig );

	private:
		ExprAdapter( GlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig
			, expr::ExprPtr & result );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override;
		void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;

		void doProcessImageLoad( expr::ImageAccessCall * expr );
		void doProcessTextureShadow( expr::TextureAccessCall * expr );
		void doProcessTextureSample( expr::TextureAccessCall * expr );
		void doProcessTextureGather( expr::TextureAccessCall * expr );

	private:
		GlslConfig const & m_writerConfig;
		IntrinsicsConfig const & m_intrinsicsConfig;
	};
}

#endif
