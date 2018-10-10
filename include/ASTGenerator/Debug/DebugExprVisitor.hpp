/*
See LICENSE file in root folder
*/
#ifndef ___AST_DebugExprVisitor_H___
#define ___AST_DebugExprVisitor_H___
#pragma once

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	class DebugExprVisitor
		: public ExprSimpleVisitor
	{
	protected:
		DebugExprVisitor( std::string & result );

	public:
		static std::string submit( Expr * expr );

	private:
		void visitUnaryExpr( ExprUnary * expr );
		void visitBinaryExpr( ExprBinary * expr );

		void visitCastExpr( ExprCast * expr )override;
		void visitMbrSelectExpr( ExprMbrSelect * expr )override;
		void visitFnCallExpr( ExprFnCall * expr )override;
		void visitIdentifierExpr( ExprIdentifier * expr )override;
		void visitInitExpr( ExprInit * expr )override;
		void visitLiteralExpr( ExprLiteral * expr )override;
		void visitQuestionExpr( ExprQuestion * expr )override;
		void visitSwitchCaseExpr( ExprSwitchCase * expr )override;
		void visitSwitchTestExpr( ExprSwitchTest * expr )override;

	private:
		std::string & m_result;
	};
};

#endif
