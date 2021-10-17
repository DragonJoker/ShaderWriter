/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslExprVisitor_H___
#define ___SDW_HlslExprVisitor_H___
#pragma once

#include "HlslHelpers.hpp"

#include <ShaderAST/Expr/ExprVisitor.hpp>

namespace hlsl
{
	class ExprVisitor
		: public ast::expr::SimpleVisitor
	{
	public:
		static std::string submit( ast::expr::Expr * expr
			, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases );

	private:
		ExprVisitor( std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
			, std::string & result );
		std::string doSubmit( ast::expr::Expr * expr );
		void wrap( ast::expr::Expr * expr );
		void visitAssignmentExpr( ast::expr::Binary * expr );

		void visitUnaryExpr( ast::expr::Unary * expr )override;
		void visitBinaryExpr( ast::expr::Binary * expr )override;
		void visitAddAssignExpr( ast::expr::AddAssign * expr )override;
		void visitAndAssignExpr( ast::expr::AndAssign * expr )override;
		void visitAssignExpr( ast::expr::Assign * expr )override;
		void visitDivideAssignExpr( ast::expr::DivideAssign * expr )override;
		void visitLShiftAssignExpr( ast::expr::LShiftAssign * expr )override;
		void visitMinusAssignExpr( ast::expr::MinusAssign * expr )override;
		void visitModuloAssignExpr( ast::expr::ModuloAssign * expr )override;
		void visitOrAssignExpr( ast::expr::OrAssign * expr )override;
		void visitRShiftAssignExpr( ast::expr::RShiftAssign * expr )override;
		void visitTimesAssignExpr( ast::expr::TimesAssign * expr )override;
		void visitXorAssignExpr( ast::expr::XorAssign * expr )override;
		void visitAggrInitExpr( ast::expr::AggrInit * expr )override;
		void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override;
		void visitCastExpr( ast::expr::Cast * expr )override;
		void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override;
		void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override;
		void visitFnCallExpr( ast::expr::FnCall * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;
		void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override;
		void visitInitExpr( ast::expr::Init * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
		void visitLiteralExpr( ast::expr::Literal * expr )override;
		void visitQuestionExpr( ast::expr::Question *expr )override;
		void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override;
		void visitSwitchCaseExpr( ast::expr::SwitchCase *expr )override;
		void visitSwitchTestExpr( ast::expr::SwitchTest *expr )override;
		void visitSwizzleExpr( ast::expr::Swizzle * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;
		void visitAliasExpr( ast::expr::Alias * expr )override;

		void doProcessMemberTexture( ast::expr::TextureAccessCall * expr );
		void doProcessNonMemberTexture( ast::expr::TextureAccessCall * expr );
		void doProcessTextureGather( ast::expr::TextureAccessCall * expr );

	private:
		std::string & m_result;
		std::map< ast::var::VariablePtr, ast::expr::Expr * > & m_aliases;
	};
}

#endif
