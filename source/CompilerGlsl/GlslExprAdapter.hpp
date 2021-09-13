/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslExprAdapter_H___
#define ___SDW_GlslExprAdapter_H___
#pragma once

#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslHelpers.hpp"

#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace glsl
{
	class ExprAdapter
		: public ast::ExprCloner
	{
	public:
		static ast::expr::ExprPtr submit( ast::type::TypesCache & cache
			, ast::expr::Expr * expr
			, GlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig );
		static ast::expr::ExprPtr submit( ast::type::TypesCache & cache
			, ast::expr::ExprPtr const & expr
			, GlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig );

	private:
		ExprAdapter( ast::type::TypesCache & cache
			, GlslConfig const & writerConfig
			, IntrinsicsConfig const & intrinsicsConfig
			, ast::expr::ExprPtr & result );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;

		void doProcessImageLoad( ast::expr::ImageAccessCall * expr );
		void doProcessImageStore( ast::expr::ImageAccessCall * expr );
		void doProcessImageAccessCall( ast::expr::ImageAccessCall * expr );
		void doProcessTextureShadow( ast::expr::TextureAccessCall * expr );
		void doProcessTextureSample( ast::expr::TextureAccessCall * expr );
		void doProcessTextureGather( ast::expr::TextureAccessCall * expr );

	private:
		ast::type::TypesCache & m_cache;
		GlslConfig const & m_writerConfig;
		IntrinsicsConfig const & m_intrinsicsConfig;
	};
}

#endif
