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
		Simple( expr::ExprPtr expr );

		void accept( VisitorPtr vis )override;

		inline expr::Expr * getExpr()const
		{
			return m_expr.get();
		}

	private:
		expr::ExprPtr m_expr;
	};
	using SimplePtr = std::unique_ptr< Simple >;

	inline SimplePtr makeSimple( expr::ExprPtr expr )
	{
		return std::make_unique< Simple >( std::move( expr ) );
	}
}

#endif
