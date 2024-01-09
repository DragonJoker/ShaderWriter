/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprUnary_H___
#define ___AST_ExprUnary_H___
#pragma once

#include "Expr.hpp"

namespace ast::expr
{
	class Unary
		: public Expr
	{
	public:
		SDAST_API Unary( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr operand
			, Kind kind );
		SDAST_API Unary( ExprCache & exprCache
			, ExprPtr operand
			, Kind kind );

		inline Expr const * getOperand()const
		{
			return m_operand.get();
		}

	private:
		ExprPtr m_operand{};
	};
}

#endif
