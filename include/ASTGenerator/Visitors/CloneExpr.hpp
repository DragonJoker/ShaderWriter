/*
See LICENSE file in root folder
*/
#ifndef ___SDW_CloneExpr_H___
#define ___SDW_CloneExpr_H___
#pragma once

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	class ExprCloner
		: public expr::Visitor
	{
	public:
		static expr::ExprPtr submit( expr::Expr * expr );
		static expr::ExprPtr submit( expr::ExprPtr const & expr );

	protected:
		ExprCloner( expr::ExprPtr & result );

	private:
		virtual expr::ExprPtr doSubmit( expr::Expr * expr );
		expr::ExprPtr doSubmit( expr::ExprPtr const & expr );

		void visitAddExpr( expr::Add * expr )override;
		void visitAddAssignExpr( expr::AddAssign * expr )override;
		void visitAggrInitExpr( expr::AggrInit * expr )override;
		void visitAndAssignExpr( expr::AndAssign * expr )override;
		void visitArrayAccessExpr( expr::ArrayAccess * expr )override;
		void visitAssignExpr( expr::Assign * expr )override;
		void visitBitAndExpr( expr::BitAnd * expr )override;
		void visitBitNotExpr( expr::BitNot * expr )override;
		void visitBitOrExpr( expr::BitOr * expr )override;
		void visitBitXorExpr( expr::BitXor * expr )override;
		void visitCastExpr( expr::Cast * expr )override;
		void visitCommaExpr( expr::Comma * expr )override;
		void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override;
		void visitDivideExpr( expr::Divide * expr )override;
		void visitDivideAssignExpr( expr::DivideAssign * expr )override;
		void visitEqualExpr( expr::Equal * expr )override;
		void visitFnCallExpr( expr::FnCall * expr )override;
		void visitGreaterExpr( expr::Greater * expr )override;
		void visitGreaterEqualExpr( expr::GreaterEqual * expr )override;
		void visitIdentifierExpr( expr::Identifier * expr )override;
		void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override;
		void visitInitExpr( expr::Init * expr )override;
		void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override;
		void visitLessExpr( expr::Less * expr )override;
		void visitLessEqualExpr( expr::LessEqual * expr )override;
		void visitLiteralExpr( expr::Literal * expr )override;
		void visitLogAndExpr( expr::LogAnd * expr )override;
		void visitLogNotExpr( expr::LogNot * expr )override;
		void visitLogOrExpr( expr::LogOr * expr )override;
		void visitLShiftExpr( expr::LShift * expr )override;
		void visitLShiftAssignExpr( expr::LShiftAssign * expr )override;
		void visitMbrSelectExpr( expr::MbrSelect * expr )override;
		void visitMinusExpr( expr::Minus * expr )override;
		void visitMinusAssignExpr( expr::MinusAssign * expr )override;
		void visitModuloExpr( expr::Modulo * expr )override;
		void visitModuloAssignExpr( expr::ModuloAssign * expr )override;
		void visitNotEqualExpr( expr::NotEqual * expr )override;
		void visitOrAssignExpr( expr::OrAssign * expr )override;
		void visitPostDecrementExpr( expr::PostDecrement * expr )override;
		void visitPostIncrementExpr( expr::PostIncrement * expr )override;
		void visitPreDecrementExpr( expr::PreDecrement * expr )override;
		void visitPreIncrementExpr( expr::PreIncrement * expr )override;
		void visitQuestionExpr( expr::Question * expr )override;
		void visitRShiftExpr( expr::RShift * expr )override;
		void visitRShiftAssignExpr( expr::RShiftAssign * expr )override;
		void visitSwitchCaseExpr( expr::SwitchCase * expr )override;
		void visitSwitchTestExpr( expr::SwitchTest * expr )override;
		void visitSwizzleExpr( expr::Swizzle * expr )override;
		void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;
		void visitTimesExpr( expr::Times * expr )override;
		void visitTimesAssignExpr( expr::TimesAssign * expr )override;
		void visitUnaryMinusExpr( expr::UnaryMinus * expr )override;
		void visitUnaryPlusExpr( expr::UnaryPlus * expr )override;
		void visitXorAssignExpr( expr::XorAssign * expr )override;

	protected:
		expr::ExprPtr & m_result;
	};
}

#endif
