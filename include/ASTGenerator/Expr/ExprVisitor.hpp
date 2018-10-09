/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprVisitor_H___
#define ___AST_ExprVisitor_H___
#pragma once

#include "ExprAdd.hpp"
#include "ExprAddAssign.hpp"
#include "ExprAndAssign.hpp"
#include "ExprAssign.hpp"
#include "ExprBitAnd.hpp"
#include "ExprBitNot.hpp"
#include "ExprBitOr.hpp"
#include "ExprBitXor.hpp"
#include "ExprCast.hpp"
#include "ExprComma.hpp"
#include "ExprDivide.hpp"
#include "ExprDivideAssign.hpp"
#include "ExprEqual.hpp"
#include "ExprFnCall.hpp"
#include "ExprGreater.hpp"
#include "ExprGreaterEqual.hpp"
#include "ExprIdentifier.hpp"
#include "ExprInit.hpp"
#include "ExprLShift.hpp"
#include "ExprLShiftAssign.hpp"
#include "ExprLess.hpp"
#include "ExprLessEqual.hpp"
#include "ExprLiteral.hpp"
#include "ExprLogAnd.hpp"
#include "ExprLogNot.hpp"
#include "ExprLogOr.hpp"
#include "ExprLogXor.hpp"
#include "ExprMbrSelect.hpp"
#include "ExprMinus.hpp"
#include "ExprMinusAssign.hpp"
#include "ExprModulo.hpp"
#include "ExprModuloAssign.hpp"
#include "ExprNotEqual.hpp"
#include "ExprOrAssign.hpp"
#include "ExprPostDecrement.hpp"
#include "ExprPostIncrement.hpp"
#include "ExprPreDecrement.hpp"
#include "ExprPreIncrement.hpp"
#include "ExprQuestion.hpp"
#include "ExprRShift.hpp"
#include "ExprRShiftAssign.hpp"
#include "ExprSwitchCase.hpp"
#include "ExprSwitchTest.hpp"
#include "ExprTimes.hpp"
#include "ExprTimesAssign.hpp"
#include "ExprUnaryMinus.hpp"
#include "ExprUnaryPlus.hpp"
#include "ExprXorAssign.hpp"

namespace ast
{
	class ExprVisitor
	{
	protected:
		ExprVisitor()
		{
		};

	public:
		virtual ~ExprVisitor()
		{
		};

		virtual void visitAddExpr( ExprAdd * ) = 0;
		virtual void visitAddAssignExpr( ExprAddAssign * ) = 0;
		virtual void visitAndAssignExpr( ExprAndAssign * ) = 0;
		virtual void visitAssignExpr( ExprAssign * ) = 0;
		virtual void visitBitAndExpr( ExprBitAnd * ) = 0;
		virtual void visitBitNotExpr( ExprBitNot * ) = 0;
		virtual void visitBitOrExpr( ExprBitOr * ) = 0;
		virtual void visitBitXorExpr( ExprBitXor * ) = 0;
		virtual void visitCastExpr( ExprCast * ) = 0;
		virtual void visitCommaExpr( ExprComma * ) = 0;
		virtual void visitDivideExpr( ExprDivide * ) = 0;
		virtual void visitDivideAssignExpr( ExprDivideAssign * ) = 0;
		virtual void visitEqualExpr( ExprEqual * ) = 0;
		virtual void visitFnCallExpr( ExprFnCall * ) = 0;
		virtual void visitGreaterExpr( ExprGreater * ) = 0;
		virtual void visitGreaterEqualExpr( ExprGreaterEqual * ) = 0;
		virtual void visitIdentifierExpr( ExprIdentifier * ) = 0;
		virtual void visitInitExpr( ExprInit * ) = 0;
		virtual void visitLessExpr( ExprLess * ) = 0;
		virtual void visitLessEqualExpr( ExprLessEqual * ) = 0;
		virtual void visitLiteralExpr( ExprLiteral * ) = 0;
		virtual void visitLogAndExpr( ExprLogAnd * ) = 0;
		virtual void visitLogNotExpr( ExprLogNot * ) = 0;
		virtual void visitLogOrExpr( ExprLogOr * ) = 0;
		virtual void visitLogXorExpr( ExprLogXor * ) = 0;
		virtual void visitLShiftExpr( ExprLShift * ) = 0;
		virtual void visitLShiftAssignExpr( ExprLShiftAssign * ) = 0;
		virtual void visitMbrSelectExpr( ExprMbrSelect * ) = 0;
		virtual void visitMinusExpr( ExprMinus * ) = 0;
		virtual void visitMinusAssignExpr( ExprMinusAssign * ) = 0;
		virtual void visitModuloExpr( ExprModulo * ) = 0;
		virtual void visitModuloAssignExpr( ExprModuloAssign * ) = 0;
		virtual void visitNotEqualExpr( ExprNotEqual * ) = 0;
		virtual void visitOrAssignExpr( ExprOrAssign * ) = 0;
		virtual void visitPostDecrementExpr( ExprPostDecrement * ) = 0;
		virtual void visitPostIncrementExpr( ExprPostIncrement * ) = 0;
		virtual void visitPreDecrementExpr( ExprPreDecrement * ) = 0;
		virtual void visitPreIncrementExpr( ExprPreIncrement * ) = 0;
		virtual void visitQuestionExpr( ExprQuestion * ) = 0;
		virtual void visitRShiftExpr( ExprRShift * ) = 0;
		virtual void visitRShiftAssignExpr( ExprRShiftAssign * ) = 0;
		virtual void visitSwitchCaseExpr( ExprSwitchCase * ) = 0;
		virtual void visitSwitchTestExpr( ExprSwitchTest * ) = 0;
		virtual void visitTimesExpr( ExprTimes * ) = 0;
		virtual void visitTimesAssignExpr( ExprTimesAssign * ) = 0;
		virtual void visitUnaryMinusExpr( ExprUnaryMinus * ) = 0;
		virtual void visitUnaryPlusExpr( ExprUnaryPlus * ) = 0;
		virtual void visitXorAssignExpr( ExprXorAssign * ) = 0;
	};

	class ExprSimpleVisitor
		: public ExprVisitor
	{
	protected:
		ExprSimpleVisitor()
		{
		}

	public:
		virtual ~ExprSimpleVisitor()
		{
		}

		virtual void visitUnaryExpr( ExprUnary * expr ) = 0;
		virtual void visitBinaryExpr( ExprBinary * expr ) = 0;

		void visitAddExpr( ExprAdd * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitAddAssignExpr( ExprAddAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitAndAssignExpr( ExprAndAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitAssignExpr( ExprAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitBitAndExpr( ExprBitAnd * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitBitNotExpr( ExprBitNot * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitBitOrExpr( ExprBitOr * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitBitXorExpr( ExprBitXor * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitCastExpr( ExprCast * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitCommaExpr( ExprComma * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitDivideExpr( ExprDivide * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitDivideAssignExpr( ExprDivideAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitEqualExpr( ExprEqual * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitGreaterExpr( ExprGreater * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitGreaterEqualExpr( ExprGreaterEqual * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLessExpr( ExprLess * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLessEqualExpr( ExprLessEqual * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLogAndExpr( ExprLogAnd * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLogNotExpr( ExprLogNot * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLogOrExpr( ExprLogOr * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLogXorExpr( ExprLogXor * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLShiftExpr( ExprLShift * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLShiftAssignExpr( ExprLShiftAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitMbrSelectExpr( ExprMbrSelect * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitMinusExpr( ExprMinus * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitMinusAssignExpr( ExprMinusAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitModuloExpr( ExprModulo * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitModuloAssignExpr( ExprModuloAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitNotEqualExpr( ExprNotEqual * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitOrAssignExpr( ExprOrAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitPostDecrementExpr( ExprPostDecrement * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitPostIncrementExpr( ExprPostIncrement * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitPreDecrementExpr( ExprPreDecrement * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitPreIncrementExpr( ExprPreIncrement * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitRShiftExpr( ExprRShift * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitRShiftAssignExpr( ExprRShiftAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitTimesExpr( ExprTimes * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitTimesAssignExpr( ExprTimesAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitUnaryMinusExpr( ExprUnaryMinus * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitUnaryPlusExpr( ExprUnaryPlus * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitXorAssignExpr( ExprXorAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
	};
};

#endif
