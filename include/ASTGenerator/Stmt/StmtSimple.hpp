/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtSimple_H___
#define ___AST_StmtSimple_H___
#pragma once

#include "Stmt.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast
{
	class StmtSimple
		: public Stmt
	{
	public:
		StmtSimple( ExprPtr expr );

		void accept( StmtVisitorPtr vis )override;

		inline Expr const & getExpr()const
		{
			return *m_expr;
		}

	private:
		ExprPtr m_expr;
	};
}

#endif
