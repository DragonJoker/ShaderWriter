/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslExprAdapter_H___
#define ___SDW_GlslExprAdapter_H___
#pragma once

#include "CompilerGlsl/GlslStmtAdapter.hpp"

#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace glsl
{
	class ExprAdapter
		: public ast::ExprCloner
	{
	public:
		static ast::expr::ExprPtr submit( ast::type::TypesCache & cache
			, ast::expr::Expr * expr
			, AdaptationData & adaptationData
			, ast::stmt::Container * container );
		static ast::expr::ExprPtr submit( ast::type::TypesCache & cache
			, ast::expr::ExprPtr const & expr
			, AdaptationData & adaptationData
			, ast::stmt::Container * container );

	private:
		ExprAdapter( ast::type::TypesCache & cache
			, AdaptationData & adaptationData
			, ast::stmt::Container * container
			, ast::expr::ExprPtr & result );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitAssignExpr( ast::expr::Assign * expr )override;
		void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override;
		void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
		void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override;
		void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override;
		void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )override;

		void doProcessImageStore( ast::expr::ImageAccessCall * expr );
		void doProcessTextureShadow( ast::expr::CombinedImageAccessCall * expr );
		void doProcessTextureSample( ast::expr::CombinedImageAccessCall * expr );
		void doProcessTextureGather( ast::expr::CombinedImageAccessCall * expr );

		ast::expr::ExprPtr doProcessIOMbr( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, uint64_t mbrFlags
			, bool isInput
			, IOVars & io );
		ast::expr::ExprPtr doProcessMbr( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, uint64_t mbrFlags );

	private:
		ast::type::TypesCache & m_cache;
		AdaptationData & m_adaptationData;
		ast::stmt::Container * m_container;
	};
}

#endif
