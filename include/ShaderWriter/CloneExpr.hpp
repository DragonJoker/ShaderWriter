/*
See LICENSE file in root folder
*/
#ifndef ___SDW_CloneExpr_H___
#define ___SDW_CloneExpr_H___
#pragma once

#include <ASTGenerator/Expr/Expr.hpp>

#include <ASTGenerator/Expr/ExprVisitor.hpp>

namespace sdw
{
	class ExprCloner
		: public ast::expr::Visitor
	{
	public:
		static ast::expr::ExprPtr submit( ast::expr::Expr * expr );
		static ast::expr::ExprPtr submit( ast::expr::ExprPtr const & expr );

	protected:
		ExprCloner( ast::expr::ExprPtr & result );

	private:
		virtual ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr );
		ast::expr::ExprPtr doSubmit( ast::expr::ExprPtr const & expr );

		void visitAddExpr( ast::expr::Add * expr )override;
		void visitAddAssignExpr( ast::expr::AddAssign * expr )override;
		void visitAggrInitExpr( ast::expr::AggrInit * expr )override;
		void visitAndAssignExpr( ast::expr::AndAssign * expr )override;
		void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override;
		void visitAssignExpr( ast::expr::Assign * expr )override;
		void visitBitAndExpr( ast::expr::BitAnd * expr )override;
		void visitBitNotExpr( ast::expr::BitNot * expr )override;
		void visitBitOrExpr( ast::expr::BitOr * expr )override;
		void visitBitXorExpr( ast::expr::BitXor * expr )override;
		void visitCastExpr( ast::expr::Cast * expr )override;
		void visitCommaExpr( ast::expr::Comma * expr )override;
		void visitDivideExpr( ast::expr::Divide * expr )override;
		void visitDivideAssignExpr( ast::expr::DivideAssign * expr )override;
		void visitEqualExpr( ast::expr::Equal * expr )override;
		void visitFnCallExpr( ast::expr::FnCall * expr )override;
		void visitGreaterExpr( ast::expr::Greater * expr )override;
		void visitGreaterEqualExpr( ast::expr::GreaterEqual * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;
		void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override;
		void visitInitExpr( ast::expr::Init * expr )override;
		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
		void visitLessExpr( ast::expr::Less * expr )override;
		void visitLessEqualExpr( ast::expr::LessEqual * expr )override;
		void visitLiteralExpr( ast::expr::Literal * expr )override;
		void visitLogAndExpr( ast::expr::LogAnd * expr )override;
		void visitLogNotExpr( ast::expr::LogNot * expr )override;
		void visitLogOrExpr( ast::expr::LogOr * expr )override;
		void visitLShiftExpr( ast::expr::LShift * expr )override;
		void visitLShiftAssignExpr( ast::expr::LShiftAssign * expr )override;
		void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override;
		void visitMinusExpr( ast::expr::Minus * expr )override;
		void visitMinusAssignExpr( ast::expr::MinusAssign * expr )override;
		void visitModuloExpr( ast::expr::Modulo * expr )override;
		void visitModuloAssignExpr( ast::expr::ModuloAssign * expr )override;
		void visitNotEqualExpr( ast::expr::NotEqual * expr )override;
		void visitOrAssignExpr( ast::expr::OrAssign * expr )override;
		void visitPostDecrementExpr( ast::expr::PostDecrement * expr )override;
		void visitPostIncrementExpr( ast::expr::PostIncrement * expr )override;
		void visitPreDecrementExpr( ast::expr::PreDecrement * expr )override;
		void visitPreIncrementExpr( ast::expr::PreIncrement * expr )override;
		void visitQuestionExpr( ast::expr::Question * expr )override;
		void visitRShiftExpr( ast::expr::RShift * expr )override;
		void visitRShiftAssignExpr( ast::expr::RShiftAssign * expr )override;
		void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override;
		void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override;
		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override;
		void visitTimesExpr( ast::expr::Times * expr )override;
		void visitTimesAssignExpr( ast::expr::TimesAssign * expr )override;
		void visitUnaryMinusExpr( ast::expr::UnaryMinus * expr )override;
		void visitUnaryPlusExpr( ast::expr::UnaryPlus * expr )override;
		void visitXorAssignExpr( ast::expr::XorAssign * expr )override;

	protected:
		ast::expr::ExprPtr & m_result;
	};
}

#endif
