/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBinary_H___
#define ___AST_ExprBinary_H___
#pragma once

#include "Expr.hpp"

namespace ast
{
	class ExprBinary
		: public Expr
	{
	public:
		ExprBinary( Type type
			, ExprPtr lhs
			, ExprPtr rhs
			, Expr::Kind kind );

		inline Expr const & getLHS()const
		{
			return *m_lhs;
		}

		inline Expr const & getRHS()const
		{
			return *m_rhs;
		}

	private:
		ExprPtr m_lhs;
		ExprPtr m_rhs;
	};
}

#endif
