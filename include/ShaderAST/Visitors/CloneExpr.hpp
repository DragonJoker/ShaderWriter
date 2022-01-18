/*
See LICENSE file in root folder
*/
#ifndef ___SDW_CloneExpr_H___
#define ___SDW_CloneExpr_H___
#pragma once

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast
{
	class ExprCloner
		: public expr::Visitor
	{
	public:
		SDAST_API static expr::ExprPtr submit( expr::Expr * expr );
		SDAST_API static expr::ExprPtr submit( expr::ExprPtr const & expr );

	protected:
		SDAST_API ExprCloner( expr::ExprPtr & result );

	private:
		SDAST_API virtual expr::ExprPtr doSubmit( expr::Expr * expr );
		SDAST_API expr::ExprPtr doSubmit( expr::ExprPtr const & expr );

	protected:
		SDAST_API void visitAddExpr( expr::Add * expr )override;
		SDAST_API void visitAddAssignExpr( expr::AddAssign * expr )override;
		SDAST_API void visitAggrInitExpr( expr::AggrInit * expr )override;
		SDAST_API void visitAliasExpr( expr::Alias * expr )override;
		SDAST_API void visitAndAssignExpr( expr::AndAssign * expr )override;
		SDAST_API void visitArrayAccessExpr( expr::ArrayAccess * expr )override;
		SDAST_API void visitAssignExpr( expr::Assign * expr )override;
		SDAST_API void visitBitAndExpr( expr::BitAnd * expr )override;
		SDAST_API void visitBitNotExpr( expr::BitNot * expr )override;
		SDAST_API void visitBitOrExpr( expr::BitOr * expr )override;
		SDAST_API void visitBitXorExpr( expr::BitXor * expr )override;
		SDAST_API void visitCastExpr( expr::Cast * expr )override;
		SDAST_API void visitCommaExpr( expr::Comma * expr )override;
		SDAST_API void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override;
		SDAST_API void visitCopyExpr( expr::Copy * )override;
		SDAST_API void visitDivideExpr( expr::Divide * expr )override;
		SDAST_API void visitDivideAssignExpr( expr::DivideAssign * expr )override;
		SDAST_API void visitEqualExpr( expr::Equal * expr )override;
		SDAST_API void visitFnCallExpr( expr::FnCall * expr )override;
		SDAST_API void visitGreaterExpr( expr::Greater * expr )override;
		SDAST_API void visitGreaterEqualExpr( expr::GreaterEqual * expr )override;
		SDAST_API void visitIdentifierExpr( expr::Identifier * expr )override;
		SDAST_API void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override;
		SDAST_API void visitInitExpr( expr::Init * expr )override;
		SDAST_API void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override;
		SDAST_API void visitLessExpr( expr::Less * expr )override;
		SDAST_API void visitLessEqualExpr( expr::LessEqual * expr )override;
		SDAST_API void visitLiteralExpr( expr::Literal * expr )override;
		SDAST_API void visitLogAndExpr( expr::LogAnd * expr )override;
		SDAST_API void visitLogNotExpr( expr::LogNot * expr )override;
		SDAST_API void visitLogOrExpr( expr::LogOr * expr )override;
		SDAST_API void visitLShiftExpr( expr::LShift * expr )override;
		SDAST_API void visitLShiftAssignExpr( expr::LShiftAssign * expr )override;
		SDAST_API void visitMbrSelectExpr( expr::MbrSelect * expr )override;
		SDAST_API void visitMinusExpr( expr::Minus * expr )override;
		SDAST_API void visitMinusAssignExpr( expr::MinusAssign * expr )override;
		SDAST_API void visitModuloExpr( expr::Modulo * expr )override;
		SDAST_API void visitModuloAssignExpr( expr::ModuloAssign * expr )override;
		SDAST_API void visitNotEqualExpr( expr::NotEqual * expr )override;
		SDAST_API void visitOrAssignExpr( expr::OrAssign * expr )override;
		SDAST_API void visitPostDecrementExpr( expr::PostDecrement * expr )override;
		SDAST_API void visitPostIncrementExpr( expr::PostIncrement * expr )override;
		SDAST_API void visitPreDecrementExpr( expr::PreDecrement * expr )override;
		SDAST_API void visitPreIncrementExpr( expr::PreIncrement * expr )override;
		SDAST_API void visitQuestionExpr( expr::Question * expr )override;
		SDAST_API void visitRShiftExpr( expr::RShift * expr )override;
		SDAST_API void visitRShiftAssignExpr( expr::RShiftAssign * expr )override;
		SDAST_API void visitStreamAppendExpr( expr::StreamAppend * expr )override;
		SDAST_API void visitSwitchCaseExpr( expr::SwitchCase * expr )override;
		SDAST_API void visitSwitchTestExpr( expr::SwitchTest * expr )override;
		SDAST_API void visitSwizzleExpr( expr::Swizzle * expr )override;
		SDAST_API void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override;
		SDAST_API void visitTimesExpr( expr::Times * expr )override;
		SDAST_API void visitTimesAssignExpr( expr::TimesAssign * expr )override;
		SDAST_API void visitUnaryMinusExpr( expr::UnaryMinus * expr )override;
		SDAST_API void visitUnaryPlusExpr( expr::UnaryPlus * expr )override;
		SDAST_API void visitXorAssignExpr( expr::XorAssign * expr )override;

	protected:
		expr::ExprPtr & m_result;
	};
}

#endif
