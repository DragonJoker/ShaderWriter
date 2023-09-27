/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprVisitor_H___
#define ___AST_ExprVisitor_H___
#pragma once

#include "ExprAdd.hpp"
#include "ExprAddAssign.hpp"
#include "ExprAggrInit.hpp"
#include "ExprAlias.hpp"
#include "ExprAndAssign.hpp"
#include "ExprArrayAccess.hpp"
#include "ExprAssign.hpp"
#include "ExprBitAnd.hpp"
#include "ExprBitNot.hpp"
#include "ExprBitOr.hpp"
#include "ExprBitXor.hpp"
#include "ExprCast.hpp"
#include "ExprCombinedImageAccessCall.hpp"
#include "ExprComma.hpp"
#include "ExprCompositeConstruct.hpp"
#include "ExprCopy.hpp"
#include "ExprDivide.hpp"
#include "ExprDivideAssign.hpp"
#include "ExprEqual.hpp"
#include "ExprFnCall.hpp"
#include "ExprGreater.hpp"
#include "ExprGreaterEqual.hpp"
#include "ExprIdentifier.hpp"
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
#include "ExprStorageImageAccessCall.hpp"
#include "ExprStreamAppend.hpp"
#include "ExprSwitchCase.hpp"
#include "ExprSwitchTest.hpp"
#include "ExprSwizzle.hpp"
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
		SDAST_API Visitor()
		{
		}

	public:
		SDAST_API virtual ~Visitor() = default;

		SDAST_API virtual void visitAddExpr( Add * ) = 0;
		SDAST_API virtual void visitAddAssignExpr( AddAssign * ) = 0;
		SDAST_API virtual void visitAggrInitExpr( AggrInit * ) = 0;
		SDAST_API virtual void visitAliasExpr( Alias * ) = 0;
		SDAST_API virtual void visitAndAssignExpr( AndAssign * ) = 0;
		SDAST_API virtual void visitArrayAccessExpr( ArrayAccess * ) = 0;
		SDAST_API virtual void visitAssignExpr( Assign * ) = 0;
		SDAST_API virtual void visitBitAndExpr( BitAnd * ) = 0;
		SDAST_API virtual void visitBitNotExpr( BitNot * ) = 0;
		SDAST_API virtual void visitBitOrExpr( BitOr * ) = 0;
		SDAST_API virtual void visitBitXorExpr( BitXor * ) = 0;
		SDAST_API virtual void visitCastExpr( Cast * ) = 0;
		SDAST_API virtual void visitCommaExpr( Comma * ) = 0;
		SDAST_API virtual void visitCompositeConstructExpr( CompositeConstruct * ) = 0;
		SDAST_API virtual void visitCopyExpr( Copy * ) = 0;
		SDAST_API virtual void visitDivideExpr( Divide * ) = 0;
		SDAST_API virtual void visitDivideAssignExpr( DivideAssign * ) = 0;
		SDAST_API virtual void visitEqualExpr( Equal * ) = 0;
		SDAST_API virtual void visitFnCallExpr( FnCall * ) = 0;
		SDAST_API virtual void visitGreaterExpr( Greater * ) = 0;
		SDAST_API virtual void visitGreaterEqualExpr( GreaterEqual * ) = 0;
		SDAST_API virtual void visitIdentifierExpr( Identifier * ) = 0;
		SDAST_API virtual void visitImageAccessCallExpr( StorageImageAccessCall * ) = 0;
		SDAST_API virtual void visitInitExpr( Init * ) = 0;
		SDAST_API virtual void visitIntrinsicCallExpr( IntrinsicCall * ) = 0;
		SDAST_API virtual void visitLessExpr( Less * ) = 0;
		SDAST_API virtual void visitLessEqualExpr( LessEqual * ) = 0;
		SDAST_API virtual void visitLiteralExpr( Literal * ) = 0;
		SDAST_API virtual void visitLogAndExpr( LogAnd * ) = 0;
		SDAST_API virtual void visitLogNotExpr( LogNot * ) = 0;
		SDAST_API virtual void visitLogOrExpr( LogOr * ) = 0;
		SDAST_API virtual void visitLShiftExpr( LShift * ) = 0;
		SDAST_API virtual void visitLShiftAssignExpr( LShiftAssign * ) = 0;
		SDAST_API virtual void visitMbrSelectExpr( MbrSelect * ) = 0;
		SDAST_API virtual void visitMinusExpr( Minus * ) = 0;
		SDAST_API virtual void visitMinusAssignExpr( MinusAssign * ) = 0;
		SDAST_API virtual void visitModuloExpr( Modulo * ) = 0;
		SDAST_API virtual void visitModuloAssignExpr( ModuloAssign * ) = 0;
		SDAST_API virtual void visitNotEqualExpr( NotEqual * ) = 0;
		SDAST_API virtual void visitOrAssignExpr( OrAssign * ) = 0;
		SDAST_API virtual void visitPostDecrementExpr( PostDecrement * ) = 0;
		SDAST_API virtual void visitPostIncrementExpr( PostIncrement * ) = 0;
		SDAST_API virtual void visitPreDecrementExpr( PreDecrement * ) = 0;
		SDAST_API virtual void visitPreIncrementExpr( PreIncrement * ) = 0;
		SDAST_API virtual void visitQuestionExpr( Question * ) = 0;
		SDAST_API virtual void visitRShiftExpr( RShift * ) = 0;
		SDAST_API virtual void visitRShiftAssignExpr( RShiftAssign * ) = 0;
		SDAST_API virtual void visitStreamAppendExpr( StreamAppend * ) = 0;
		SDAST_API virtual void visitSwitchCaseExpr( SwitchCase * ) = 0;
		SDAST_API virtual void visitSwitchTestExpr( SwitchTest * ) = 0;
		SDAST_API virtual void visitSwizzleExpr( Swizzle * ) = 0;
		SDAST_API virtual void visitCombinedImageAccessCallExpr( CombinedImageAccessCall * ) = 0;
		SDAST_API virtual void visitTimesExpr( Times * ) = 0;
		SDAST_API virtual void visitTimesAssignExpr( TimesAssign * ) = 0;
		SDAST_API virtual void visitUnaryMinusExpr( UnaryMinus * ) = 0;
		SDAST_API virtual void visitUnaryPlusExpr( UnaryPlus * ) = 0;
		SDAST_API virtual void visitXorAssignExpr( XorAssign * ) = 0;
	};
	/*
	*	Provides a base implementation of an expression visitor.
	*	Implements all visits except the following:
	*	- void visitAggrInitExpr( ast::expr::AggrInit * expr )override;
	*	- void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override;
	*	- void visitFnCallExpr( ast::expr::FnCall * expr )override;
	*	- void visitIdentifierExpr( ast::expr::Identifier * expr )override;
	*	- void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall * expr )override;
	*	- void visitInitExpr( ast::expr::Init * expr )override;
	*	- void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override;
	*	- void visitLiteralExpr( ast::expr::Literal * expr )override;
	*	- void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override;
	*	- void visitQuestionExpr( ast::expr::Question * expr )override;
	*	- void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override;
	*	- void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override;
	*	- void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override;
	*	- void visitSwizzleExpr( ast::expr::Swizzle * expr )override;
	*	- void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )override;
	*/
	class SimpleVisitor
		: public Visitor
	{
	protected:
		SimpleVisitor()
		{
		}

	public:
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
		void visitAliasExpr( Alias * expr )override
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
		void visitCopyExpr( expr::Copy * expr )override
		{
			visitUnaryExpr( expr );
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
}

#endif
