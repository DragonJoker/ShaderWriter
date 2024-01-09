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
		SDAST_API Visitor()noexcept = default;

	public:
		SDAST_API virtual ~Visitor()noexcept = default;

		SDAST_API virtual void visitAddExpr( Add const * ) = 0;
		SDAST_API virtual void visitAddAssignExpr( AddAssign const * ) = 0;
		SDAST_API virtual void visitAggrInitExpr( AggrInit const * ) = 0;
		SDAST_API virtual void visitAliasExpr( Alias const * ) = 0;
		SDAST_API virtual void visitAndAssignExpr( AndAssign const * ) = 0;
		SDAST_API virtual void visitArrayAccessExpr( ArrayAccess const * ) = 0;
		SDAST_API virtual void visitAssignExpr( Assign const * ) = 0;
		SDAST_API virtual void visitBitAndExpr( BitAnd const * ) = 0;
		SDAST_API virtual void visitBitNotExpr( BitNot const * ) = 0;
		SDAST_API virtual void visitBitOrExpr( BitOr const * ) = 0;
		SDAST_API virtual void visitBitXorExpr( BitXor const * ) = 0;
		SDAST_API virtual void visitCastExpr( Cast const * ) = 0;
		SDAST_API virtual void visitCommaExpr( Comma const * ) = 0;
		SDAST_API virtual void visitCompositeConstructExpr( CompositeConstruct const * ) = 0;
		SDAST_API virtual void visitCopyExpr( Copy const * ) = 0;
		SDAST_API virtual void visitDivideExpr( Divide const * ) = 0;
		SDAST_API virtual void visitDivideAssignExpr( DivideAssign const * ) = 0;
		SDAST_API virtual void visitEqualExpr( Equal const * ) = 0;
		SDAST_API virtual void visitFnCallExpr( FnCall const * ) = 0;
		SDAST_API virtual void visitGreaterExpr( Greater const * ) = 0;
		SDAST_API virtual void visitGreaterEqualExpr( GreaterEqual const * ) = 0;
		SDAST_API virtual void visitIdentifierExpr( Identifier const * ) = 0;
		SDAST_API virtual void visitImageAccessCallExpr( StorageImageAccessCall const * ) = 0;
		SDAST_API virtual void visitInitExpr( Init const * ) = 0;
		SDAST_API virtual void visitIntrinsicCallExpr( IntrinsicCall const * ) = 0;
		SDAST_API virtual void visitLessExpr( Less const * ) = 0;
		SDAST_API virtual void visitLessEqualExpr( LessEqual const * ) = 0;
		SDAST_API virtual void visitLiteralExpr( Literal const * ) = 0;
		SDAST_API virtual void visitLogAndExpr( LogAnd const * ) = 0;
		SDAST_API virtual void visitLogNotExpr( LogNot const * ) = 0;
		SDAST_API virtual void visitLogOrExpr( LogOr const * ) = 0;
		SDAST_API virtual void visitLShiftExpr( LShift const * ) = 0;
		SDAST_API virtual void visitLShiftAssignExpr( LShiftAssign const * ) = 0;
		SDAST_API virtual void visitMbrSelectExpr( MbrSelect const * ) = 0;
		SDAST_API virtual void visitMinusExpr( Minus const * ) = 0;
		SDAST_API virtual void visitMinusAssignExpr( MinusAssign const * ) = 0;
		SDAST_API virtual void visitModuloExpr( Modulo const * ) = 0;
		SDAST_API virtual void visitModuloAssignExpr( ModuloAssign const * ) = 0;
		SDAST_API virtual void visitNotEqualExpr( NotEqual const * ) = 0;
		SDAST_API virtual void visitOrAssignExpr( OrAssign const * ) = 0;
		SDAST_API virtual void visitPostDecrementExpr( PostDecrement const * ) = 0;
		SDAST_API virtual void visitPostIncrementExpr( PostIncrement const * ) = 0;
		SDAST_API virtual void visitPreDecrementExpr( PreDecrement const * ) = 0;
		SDAST_API virtual void visitPreIncrementExpr( PreIncrement const * ) = 0;
		SDAST_API virtual void visitQuestionExpr( Question const * ) = 0;
		SDAST_API virtual void visitRShiftExpr( RShift const * ) = 0;
		SDAST_API virtual void visitRShiftAssignExpr( RShiftAssign const * ) = 0;
		SDAST_API virtual void visitStreamAppendExpr( StreamAppend const * ) = 0;
		SDAST_API virtual void visitSwitchCaseExpr( SwitchCase const * ) = 0;
		SDAST_API virtual void visitSwitchTestExpr( SwitchTest const * ) = 0;
		SDAST_API virtual void visitSwizzleExpr( Swizzle const * ) = 0;
		SDAST_API virtual void visitCombinedImageAccessCallExpr( CombinedImageAccessCall const * ) = 0;
		SDAST_API virtual void visitTimesExpr( Times const * ) = 0;
		SDAST_API virtual void visitTimesAssignExpr( TimesAssign const * ) = 0;
		SDAST_API virtual void visitUnaryMinusExpr( UnaryMinus const * ) = 0;
		SDAST_API virtual void visitUnaryPlusExpr( UnaryPlus const * ) = 0;
		SDAST_API virtual void visitXorAssignExpr( XorAssign const * ) = 0;
	};
	/**
	*	Provides a base implementation of an expression visitor.
	*	Implements all visits except the following:
	*	- void visitUnaryExpr( ast::expr::Unary const * expr )override;
	*	- void visitBinaryExpr( ast::expr::Binary const * expr )override;
	*	- void visitAggrInitExpr( ast::expr::AggrInit const * expr )override;
	*	- void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override;
	*	- void visitFnCallExpr( ast::expr::FnCall const * expr )override;
	*	- void visitIdentifierExpr( ast::expr::Identifier const * expr )override;
	*	- void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override;
	*	- void visitInitExpr( ast::expr::Init const * expr )override;
	*	- void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override;
	*	- void visitLiteralExpr( ast::expr::Literal const * expr )override;
	*	- void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override;
	*	- void visitQuestionExpr( ast::expr::Question const * expr )override;
	*	- void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override;
	*	- void visitSwitchCaseExpr( ast::expr::SwitchCase const * expr )override;
	*	- void visitSwitchTestExpr( ast::expr::SwitchTest const * expr )override;
	*	- void visitSwizzleExpr( ast::expr::Swizzle const * expr )override;
	*	- void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override;
	*/
	class SimpleVisitor
		: public Visitor
	{
	protected:
		SDAST_API SimpleVisitor()noexcept = default;

	public:
		SDAST_API ~SimpleVisitor()noexcept override = default;

		virtual void visitUnaryExpr( Unary const * expr ) = 0;
		virtual void visitBinaryExpr( Binary const * expr ) = 0;

		void visitAddExpr( Add const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitAddAssignExpr( AddAssign const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitAliasExpr( Alias const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitAndAssignExpr( AndAssign const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitArrayAccessExpr( ArrayAccess const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitAssignExpr( Assign const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitBitAndExpr( BitAnd const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitBitNotExpr( BitNot const * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitBitOrExpr( BitOr const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitBitXorExpr( BitXor const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitCastExpr( Cast const * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitCommaExpr( Comma const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitCopyExpr( expr::Copy const * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitDivideExpr( Divide const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitDivideAssignExpr( DivideAssign const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitEqualExpr( Equal const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitGreaterExpr( Greater const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitGreaterEqualExpr( GreaterEqual const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLessExpr( Less const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLessEqualExpr( LessEqual const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLogAndExpr( LogAnd const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLogNotExpr( LogNot const * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitLogOrExpr( LogOr const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLShiftExpr( LShift const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitLShiftAssignExpr( LShiftAssign const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitMinusExpr( Minus const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitMinusAssignExpr( MinusAssign const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitModuloExpr( Modulo const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitModuloAssignExpr( ModuloAssign const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitNotEqualExpr( NotEqual const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitOrAssignExpr( OrAssign const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitPostDecrementExpr( PostDecrement const * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitPostIncrementExpr( PostIncrement const * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitPreDecrementExpr( PreDecrement const * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitPreIncrementExpr( PreIncrement const * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitRShiftExpr( RShift const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitRShiftAssignExpr( RShiftAssign const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitTimesExpr( Times const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitTimesAssignExpr( TimesAssign const * expr )override
		{
			visitBinaryExpr( expr );
		}
		void visitUnaryMinusExpr( UnaryMinus const * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitUnaryPlusExpr( UnaryPlus const * expr )override
		{
			visitUnaryExpr( expr );
		}
		void visitXorAssignExpr( XorAssign const * expr )override
		{
			visitBinaryExpr( expr );
		}
	};
}

#endif
