/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtSimple_H___
#define ___AST_StmtSimple_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class Simple
		: public Stmt
	{
	public:
		SDAST_API explicit Simple( StmtCache & stmtCache
			, expr::ExprPtr expr );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline expr::Expr const * getExpr()const
		{
			return m_expr.get();
		}

	private:
		expr::ExprPtr m_expr{};
	};
}

#endif
