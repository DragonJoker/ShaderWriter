/*
See LICENSE file in root folder
*/
#ifndef ___AST_Expr_H___
#define ___AST_Expr_H___
#pragma once

#include "ASTGenerator/Type/Type.hpp"

namespace ast::expr
{
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
		eArrayAccess,
	};

	class Expr
	{
	public:
		Expr( type::TypePtr type, Kind kind );
		virtual ~Expr();

		virtual void accept( VisitorPtr ) = 0;

		inline Kind getKind()const
		{
			return m_kind;
		}

		inline type::TypePtr get()const
		{
			return m_type;
		}

	private:
		Kind m_kind;
		type::TypePtr m_type;
	};
}

#endif
