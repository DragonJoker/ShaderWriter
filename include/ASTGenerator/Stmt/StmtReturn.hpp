/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtReturn_H___
#define ___AST_StmtReturn_H___
#pragma once

#include "Stmt.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast
{
	class StmtReturn
		: public Stmt
	{
	public:
		StmtReturn( ExprPtr expr );

		void accept( StmtVisitorPtr vis )override;

		inline Expr * getExpr()const
		{
			return m_expr.get();
		}

	private:
		ExprPtr m_expr;
	};

	inline std::unique_ptr< StmtReturn > makeReturnStmt( ExprPtr expr )
	{
		return std::make_unique< StmtReturn >( std::move( expr ) );
	}
}

#endif
