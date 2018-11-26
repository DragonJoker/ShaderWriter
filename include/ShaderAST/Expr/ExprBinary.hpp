/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBinary_H___
#define ___AST_ExprBinary_H___
#pragma once

#include "Expr.hpp"

namespace ast::expr
{
	class Binary
		: public Expr
	{
	public:
		Binary( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs
			, Kind kind );

		inline Expr * getLHS()const
		{
			return m_lhs.get();
		}

		inline Expr * getRHS()const
		{
			return m_rhs.get();
		}

	private:
		ExprPtr m_lhs;
		ExprPtr m_rhs;
	};
}

#endif
