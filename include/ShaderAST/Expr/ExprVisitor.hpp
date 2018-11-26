/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprVisitor_H___
#define ___AST_ExprVisitor_H___
#pragma once

#include "ExprAdd.hpp"
#include "ExprAddAssign.hpp"
#include "ExprAggrInit.hpp"
#include "ExprAndAssign.hpp"
#include "ExprArrayAccess.hpp"
#include "ExprAssign.hpp"
#include "ExprBitAnd.hpp"
#include "ExprBitNot.hpp"
#include "ExprBitOr.hpp"
#include "ExprBitXor.hpp"
#include "ExprCast.hpp"
#include "ExprComma.hpp"
#include "ExprCompositeConstruct.hpp"
#include "ExprDivide.hpp"
#include "ExprDivideAssign.hpp"
#include "ExprEqual.hpp"
#include "ExprFnCall.hpp"
#include "ExprGreater.hpp"
#include "ExprGreaterEqual.hpp"
#include "ExprIdentifier.hpp"
#include "ExprImageAccessCall.hpp"
#include "ExprInit.hpp"
#include "ExprIntrinsicCall.hpp"
#include "ExprLShift.hpp"
#include "ExprLShiftAssign.hpp"
#include "ExprLess.hpp"
#include "ExprLessEqual.hpp"
#include "ExprLiteral.hpp"
#include "ExprLogAnd.hpp"
#include "ExprLogNot.hpp"
#include "ExprLogOr.hpp"
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
#include "ExprSwizzle.hpp"
#include "ExprTextureAccessCall.hpp"
#include "ExprTimes.hpp"
#include "ExprTimesAssign.hpp"
#include "ExprUnaryMinus.hpp"
#include "ExprUnaryPlus.hpp"
#include "ExprXorAssign.hpp"

namespace ast::expr
{
	class Visitor
	{
	protected:
		Visitor()
		{
		};

	public:
		virtual ~Visitor()
		{
		};

		virtual void visitAddExpr( Add * ) = 0;
		virtual void visitAddAssignExpr( AddAssign * ) = 0;
		virtual void visitAggrInitExpr( AggrInit * ) = 0;
		virtual void visitAndAssignExpr( AndAssign * ) = 0;
		virtual void visitArrayAccessExpr( ArrayAccess * ) = 0;
		virtual void visitAssignExpr( Assign * ) = 0;
		virtual void visitBitAndExpr( BitAnd * ) = 0;
		virtual void visitBitNotExpr( BitNot * ) = 0;
		virtual void visitBitOrExpr( BitOr * ) = 0;
		virtual void visitBitXorExpr( BitXor * ) = 0;
		virtual void visitCastExpr( Cast * ) = 0;
		virtual void visitCommaExpr( Comma * ) = 0;
		virtual void visitCompositeConstructExpr( CompositeConstruct * ) = 0;
		virtual void visitDivideExpr( Divide * ) = 0;
		virtual void visitDivideAssignExpr( DivideAssign * ) = 0;
		virtual void visitEqualExpr( Equal * ) = 0;
		virtual void visitFnCallExpr( FnCall * ) = 0;
		virtual void visitGreaterExpr( Greater * ) = 0;
		virtual void visitGreaterEqualExpr( GreaterEqual * ) = 0;
		virtual void visitIdentifierExpr( Identifier * ) = 0;
		virtual void visitImageAccessCallExpr( ImageAccessCall * ) = 0;
		virtual void visitInitExpr( Init * ) = 0;
		virtual void visitIntrinsicCallExpr( IntrinsicCall * ) = 0;
		virtual void visitLessExpr( Less * ) = 0;
		virtual void visitLessEqualExpr( LessEqual * ) = 0;
		virtual void visitLiteralExpr( Literal * ) = 0;
		virtual void visitLogAndExpr( LogAnd * ) = 0;
		virtual void visitLogNotExpr( LogNot * ) = 0;
		virtual void visitLogOrExpr( LogOr * ) = 0;
		virtual void visitLShiftExpr( LShift * ) = 0;
		virtual void visitLShiftAssignExpr( LShiftAssign * ) = 0;
		virtual void visitMbrSelectExpr( MbrSelect * ) = 0;
		virtual void visitMinusExpr( Minus * ) = 0;
		virtual void visitMinusAssignExpr( MinusAssign * ) = 0;
		virtual void visitModuloExpr( Modulo * ) = 0;
		virtual void visitModuloAssignExpr( ModuloAssign * ) = 0;
		virtual void visitNotEqualExpr( NotEqual * ) = 0;
		virtual void visitOrAssignExpr( OrAssign * ) = 0;
		virtual void visitPostDecrementExpr( PostDecrement * ) = 0;
		virtual void visitPostIncrementExpr( PostIncrement * ) = 0;
		virtual void visitPreDecrementExpr( PreDecrement * ) = 0;
		virtual void visitPreIncrementExpr( PreIncrement * ) = 0;
		virtual void visitQuestionExpr( Question * ) = 0;
		virtual void visitRShiftExpr( RShift * ) = 0;
		virtual void visitRShiftAssignExpr( RShiftAssign * ) = 0;
		virtual void visitSwitchCaseExpr( SwitchCase * ) = 0;
		virtual void visitSwitchTestExpr( SwitchTest * ) = 0;
		virtual void visitSwizzleExpr( Swizzle * ) = 0;
		virtual void visitTextureAccessCallExpr( TextureAccessCall * ) = 0;
		virtual void visitTimesExpr( Times * ) = 0;
		virtual void visitTimesAssignExpr( TimesAssign * ) = 0;
		virtual void visitUnaryMinusExpr( UnaryMinus * ) = 0;
		virtual void visitUnaryPlusExpr( UnaryPlus * ) = 0;
		virtual void visitXorAssignExpr( XorAssign * ) = 0;
	};

	class SimpleVisitor
		: public Visitor
	{
	protected:
		SimpleVisitor()
		{
		}

	public:
		virtual ~SimpleVisitor()
		{
		}

		virtual void visitUnaryExpr( Unary * expr ) = 0;
		virtual void visitBinaryExpr( Binary * expr ) = 0;

		void visitAddExpr( Add * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitAddAssignExpr( AddAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitAndAssignExpr( AndAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitArrayAccessExpr( ArrayAccess * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitAssignExpr( Assign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitBitAndExpr( BitAnd * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitBitNotExpr( BitNot * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitBitOrExpr( BitOr * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitBitXorExpr( BitXor * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitCastExpr( Cast * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitCommaExpr( Comma * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitDivideExpr( Divide * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitDivideAssignExpr( DivideAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitEqualExpr( Equal * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitGreaterExpr( Greater * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitGreaterEqualExpr( GreaterEqual * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLessExpr( Less * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLessEqualExpr( LessEqual * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLogAndExpr( LogAnd * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLogNotExpr( LogNot * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitLogOrExpr( LogOr * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLShiftExpr( LShift * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLShiftAssignExpr( LShiftAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitMbrSelectExpr( MbrSelect * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitMinusExpr( Minus * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitMinusAssignExpr( MinusAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitModuloExpr( Modulo * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitModuloAssignExpr( ModuloAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitNotEqualExpr( NotEqual * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitOrAssignExpr( OrAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitPostDecrementExpr( PostDecrement * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitPostIncrementExpr( PostIncrement * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitPreDecrementExpr( PreDecrement * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitPreIncrementExpr( PreIncrement * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitRShiftExpr( RShift * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitRShiftAssignExpr( RShiftAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitTimesExpr( Times * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitTimesAssignExpr( TimesAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitUnaryMinusExpr( UnaryMinus * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitUnaryPlusExpr( UnaryPlus * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitXorAssignExpr( XorAssign * expr )override
		{
			visitBinaryExpr( expr );
		}
	};
};

#endif
