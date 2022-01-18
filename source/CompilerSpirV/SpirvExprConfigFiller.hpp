/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslExprConfigFiller_H___
#define ___SDW_HlslExprConfigFiller_H___
#pragma once

#include "SpirvHelpers.hpp"

#include <ShaderAST/Expr/ExprVisitor.hpp>

namespace spirv
{
	class ExprConfigFiller
		: public ast::expr::SimpleVisitor
	{
	public:
		static void submit( ast::expr::Expr * expr
			, ModuleConfig & config );
		static void submit( ast::expr::ExprPtr const & expr
			, ModuleConfig & config );

	private:
		ExprConfigFiller( ModuleConfig & config );

		void doSubmit( ast::expr::Expr * expr );

		void visitUnaryExpr( ast::expr::Unary * expr )override;
		void visitBinaryExpr( ast::expr::Binary * expr )override;

		void visitAggrInitExpr( ast::expr::AggrInit * expr )override;
		void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override;
		void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override;
		void visitFnCallExpr( ast::expr::FnCall * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;
		void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;
		void visitInitExpr( ast::expr::Init * expr )override;
		void visitLiteralExpr( ast::expr::Literal * expr )override;
		void visitQuestionExpr( ast::expr::Question * expr )override;
		void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override;
		void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override;
		void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override;
		void visitSwizzleExpr( ast::expr::Swizzle * expr )override;

	private:
		ModuleConfig & m_config;
	};
}

#endif
