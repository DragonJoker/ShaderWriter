/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprUnary_H___
#define ___AST_ExprUnary_H___
#pragma once

#include "Expr.hpp"

namespace ast
{
	class ExprUnary
		: public Expr
	{
	public:
		ExprUnary( Type type
			, ExprPtr operand
			, Expr::Kind kind );

		inline Expr * getOperand()const
		{
			return m_operand.get();
		}

	private:
		ExprPtr m_operand;
	};
}

#endif
