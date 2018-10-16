/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtReturn_H___
#define ___AST_StmtReturn_H___
#pragma once

#include "Stmt.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast::stmt
{
	class Return
		: public Stmt
	{
	public:
		Return( expr::ExprPtr expr );

		void accept( VisitorPtr vis )override;

		inline expr::Expr * getExpr()const
		{
			return m_expr.get();
		}

	private:
		expr::ExprPtr m_expr;
	};
	using ReturnPtr = std::unique_ptr< Return >;

	inline ReturnPtr makeReturn()
	{
		return std::make_unique< Return >( nullptr );
	}

	inline ReturnPtr makeReturn( expr::ExprPtr expr )
	{
		return std::make_unique< Return >( std::move( expr ) );
	}
}

#endif
