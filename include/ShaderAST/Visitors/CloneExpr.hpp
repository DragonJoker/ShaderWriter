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
		SDAST_API static expr::ExprPtr submit( expr::ExprCache & exprCache
			, expr::Expr const & expr );
		SDAST_API static expr::ExprPtr submit( expr::ExprCache & exprCache
			, expr::Expr const * expr );

	protected:
		SDAST_API explicit ExprCloner( expr::ExprCache & exprCache
			, expr::ExprPtr & result );

	protected:
		SDAST_API virtual expr::ExprPtr doSubmit( expr::Expr const & expr );
		SDAST_API expr::ExprPtr doSubmit( expr::Expr const * expr );

		SDAST_API void visitAddExpr( expr::Add const * expr )override;
		SDAST_API void visitAddAssignExpr( expr::AddAssign const * expr )override;
		SDAST_API void visitAggrInitExpr( expr::AggrInit const * expr )override;
		SDAST_API void visitAliasExpr( expr::Alias const * expr )override;
		SDAST_API void visitAndAssignExpr( expr::AndAssign const * expr )override;
		SDAST_API void visitArrayAccessExpr( expr::ArrayAccess const * expr )override;
		SDAST_API void visitAssignExpr( expr::Assign const * expr )override;
		SDAST_API void visitBitAndExpr( expr::BitAnd const * expr )override;
		SDAST_API void visitBitNotExpr( expr::BitNot const * expr )override;
		SDAST_API void visitBitOrExpr( expr::BitOr const * expr )override;
		SDAST_API void visitBitXorExpr( expr::BitXor const * expr )override;
		SDAST_API void visitCastExpr( expr::Cast const * expr )override;
		SDAST_API void visitCommaExpr( expr::Comma const * expr )override;
		SDAST_API void visitCompositeConstructExpr( expr::CompositeConstruct const * expr )override;
		SDAST_API void visitCopyExpr( expr::Copy const * expr )override;
		SDAST_API void visitDivideExpr( expr::Divide const * expr )override;
		SDAST_API void visitDivideAssignExpr( expr::DivideAssign const * expr )override;
		SDAST_API void visitEqualExpr( expr::Equal const * expr )override;
		SDAST_API void visitFnCallExpr( expr::FnCall const * expr )override;
		SDAST_API void visitGreaterExpr( expr::Greater const * expr )override;
		SDAST_API void visitGreaterEqualExpr( expr::GreaterEqual const * expr )override;
		SDAST_API void visitIdentifierExpr( expr::Identifier const * expr )override;
		SDAST_API void visitImageAccessCallExpr( expr::StorageImageAccessCall const * expr )override;
		SDAST_API void visitInitExpr( expr::Init const * expr )override;
		SDAST_API void visitIntrinsicCallExpr( expr::IntrinsicCall const * expr )override;
		SDAST_API void visitLessExpr( expr::Less const * expr )override;
		SDAST_API void visitLessEqualExpr( expr::LessEqual const * expr )override;
		SDAST_API void visitLiteralExpr( expr::Literal const * expr )override;
		SDAST_API void visitLogAndExpr( expr::LogAnd const * expr )override;
		SDAST_API void visitLogNotExpr( expr::LogNot const * expr )override;
		SDAST_API void visitLogOrExpr( expr::LogOr const * expr )override;
		SDAST_API void visitLShiftExpr( expr::LShift const * expr )override;
		SDAST_API void visitLShiftAssignExpr( expr::LShiftAssign const * expr )override;
		SDAST_API void visitMbrSelectExpr( expr::MbrSelect const * expr )override;
		SDAST_API void visitMinusExpr( expr::Minus const * expr )override;
		SDAST_API void visitMinusAssignExpr( expr::MinusAssign const * expr )override;
		SDAST_API void visitModuloExpr( expr::Modulo const * expr )override;
		SDAST_API void visitModuloAssignExpr( expr::ModuloAssign const * expr )override;
		SDAST_API void visitNotEqualExpr( expr::NotEqual const * expr )override;
		SDAST_API void visitOrAssignExpr( expr::OrAssign const * expr )override;
		SDAST_API void visitPostDecrementExpr( expr::PostDecrement const * expr )override;
		SDAST_API void visitPostIncrementExpr( expr::PostIncrement const * expr )override;
		SDAST_API void visitPreDecrementExpr( expr::PreDecrement const * expr )override;
		SDAST_API void visitPreIncrementExpr( expr::PreIncrement const * expr )override;
		SDAST_API void visitQuestionExpr( expr::Question const * expr )override;
		SDAST_API void visitRShiftExpr( expr::RShift const * expr )override;
		SDAST_API void visitRShiftAssignExpr( expr::RShiftAssign const * expr )override;
		SDAST_API void visitStreamAppendExpr( expr::StreamAppend const * expr )override;
		SDAST_API void visitSwitchCaseExpr( expr::SwitchCase const * expr )override;
		SDAST_API void visitSwitchTestExpr( expr::SwitchTest const * expr )override;
		SDAST_API void visitSwizzleExpr( expr::Swizzle const * expr )override;
		SDAST_API void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall const * expr )override;
		SDAST_API void visitTimesExpr( expr::Times const * expr )override;
		SDAST_API void visitTimesAssignExpr( expr::TimesAssign const * expr )override;
		SDAST_API void visitUnaryMinusExpr( expr::UnaryMinus const * expr )override;
		SDAST_API void visitUnaryPlusExpr( expr::UnaryPlus const * expr )override;
		SDAST_API void visitXorAssignExpr( expr::XorAssign const * expr )override;

	protected:
		expr::ExprCache & m_exprCache;
		expr::ExprPtr & m_result;
	};
}

#endif
