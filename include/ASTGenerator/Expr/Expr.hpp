/*
See LICENSE file in root folder
*/
#ifndef ___AST_Expr_H___
#define ___AST_Expr_H___
#pragma once

#include "ASTGenerator/ASTGeneratorPrerequisites.hpp"

namespace ast
{
	class Expr
	{
	public:
		enum class Kind
			: uint8_t
		{
			eAdd,
			eMinus,
			eTimes,
			eDivide,
			eModulo,
			eLShift,
			eRShift,
			eBitAnd,
			eBitNot,
			eBitOr,
			eBitXor,
			eLogAnd,
			eLogNot,
			eLogOr,
			eLogXor,
			eCast,
			eInit,
			eFnCall,
			eEqual,
			eGreater,
			eGreaterEqual,
			eLess,
			eLessEqual,
			eNotEqual,
			eComma,
			eIdentifier,
			eLiteral,
			eMbrSelect,
			eSwitchTest,
			eSwitchCase,
			eQuestion,
			ePreIncrement,
			ePreDecrement,
			ePostIncrement,
			ePostDecrement,
			eUnaryMinus,
			eUnaryPlus,
			eAssign,
			eAddAssign,
			eMinusAssign,
			eTimesAssign,
			eDivideAssign,
			eModuloAssign,
			eLShiftAssign,
			eRShiftAssign,
			eAndAssign,
			eNotAssign,
			eOrAssign,
			eXorAssign,
		};

	public:
		Expr( Type type, Kind kind );
		virtual ~Expr();

		virtual void accept( ExprVisitorPtr ) = 0;

		inline Kind getKind()const
		{
			return m_kind;
		}

		inline Type getType()const
		{
			return m_type;
		}

	private:
		Kind m_kind;
		Type m_type;
	};
}

#endif
