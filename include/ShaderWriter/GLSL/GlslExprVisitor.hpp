/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GLSLExprVisitor_H___
#define ___SDW_GLSLExprVisitor_H___
#pragma once

#include "ShaderWriter/ShaderWriterPrerequisites.hpp"

#include <ASTGenerator/Expr/ExprVisitor.hpp>

namespace sdw::glsl
{
	class ExprVisitor
		: public expr::SimpleVisitor
	{
	public:
		static std::string submit( expr::Expr * expr );

	private:
		ExprVisitor( std::string & result );
		void wrap( expr::Expr * expr );
		void visitAssignmentExpr( expr::Binary * expr );

		void visitUnaryExpr( expr::Unary * expr )override;
		void visitBinaryExpr( expr::Binary * expr )override;

		void visitAddAssignExpr( expr::AddAssign * expr )override;
		void visitAndAssignExpr( expr::AndAssign * expr )override;
		void visitAssignExpr( expr::Assign * expr )override;
		void visitDivideAssignExpr( expr::DivideAssign * expr )override;
		void visitLShiftAssignExpr( expr::LShiftAssign * expr )override;
		void visitMinusAssignExpr( expr::MinusAssign * expr )override;
		void visitModuloAssignExpr( expr::ModuloAssign * expr )override;
		void visitOrAssignExpr( expr::OrAssign * expr )override;
		void visitRShiftAssignExpr( expr::RShiftAssign * expr )override;
		void visitTimesAssignExpr( expr::TimesAssign * expr )override;
		void visitXorAssignExpr( expr::XorAssign * expr )override;
		void visitAggrInitExpr( expr::AggrInit * expr )override;
		void visitArrayAccessExpr( expr::ArrayAccess * expr )override;
		void visitCastExpr( expr::Cast * expr )override;
		void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override;
		void visitMbrSelectExpr( expr::MbrSelect * expr )override;
		void visitFnCallExpr( expr::FnCall * expr )override;
		void visitIdentifierExpr( expr::Identifier * expr )override;
		void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override;
		void visitInitExpr( expr::Init * expr )override;
		void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override;
		void visitLiteralExpr( expr::Literal * expr )override;
		void visitQuestionExpr( expr::Question *expr )override;
		void visitSwitchCaseExpr( expr::SwitchCase *expr )override;
		void visitSwitchTestExpr( expr::SwitchTest *expr )override;
		void visitSwizzleExpr( expr::Swizzle * expr )override;
		void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;

	private:
		std::string & m_result;
	};
}

#endif
