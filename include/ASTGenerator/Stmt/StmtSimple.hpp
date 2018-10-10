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

		inline Expr * getExpr()const
		{
			return m_expr.get();
		}

	private:
		ExprPtr m_expr;
	};

	inline std::unique_ptr< StmtSimple > makeSimpleStmt( ExprPtr expr )
	{
		return std::make_unique< StmtSimple >( std::move( expr ) );
	}
}

#endif
