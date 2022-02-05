/*
See LICENSE file in root folder
*/
#ifndef ___AST_DebugExprVisitor_H___
#define ___AST_DebugExprVisitor_H___
#pragma once

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::debug
{
	class ExprVisitor
		: public expr::SimpleVisitor
	{
	protected:
		SDAST_API ExprVisitor( std::string & result );

	public:
		SDAST_API static std::string submit( expr::Expr * expr );

	private:
		SDAST_API void wrap( expr::Expr * expr );
		SDAST_API void visitUnaryExpr( expr::Unary * expr )override;
		SDAST_API void visitBinaryExpr( expr::Binary * expr )override;

		SDAST_API void visitAggrInitExpr( expr::AggrInit * expr )override;
		SDAST_API void visitCastExpr( expr::Cast * expr )override;
		SDAST_API void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override;
		SDAST_API void visitMbrSelectExpr( expr::MbrSelect * expr )override;
		SDAST_API void visitFnCallExpr( expr::FnCall * expr )override;
		SDAST_API void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override;
		SDAST_API void visitSampledImageAccessCallExpr( expr::SampledImageAccessCall * expr )override;
		SDAST_API void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall * expr )override;
		SDAST_API void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override;
		SDAST_API void visitIdentifierExpr( expr::Identifier * expr )override;
		SDAST_API void visitInitExpr( expr::Init * expr )override;
		SDAST_API void visitLiteralExpr( expr::Literal * expr )override;
		SDAST_API void visitQuestionExpr( expr::Question * expr )override;
		SDAST_API void visitStreamAppendExpr( expr::StreamAppend * expr )override;
		SDAST_API void visitSwitchCaseExpr( expr::SwitchCase * expr )override;
		SDAST_API void visitSwitchTestExpr( expr::SwitchTest * expr )override;
		SDAST_API void visitSwizzleExpr( expr::Swizzle * expr )override;

	private:
		std::string & m_result;
	};
}

#endif
