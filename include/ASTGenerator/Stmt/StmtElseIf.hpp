/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtElseIf_H___
#define ___AST_StmtElseIf_H___
#pragma once

#include "StmtCompound.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast::stmt
{
	class If;
	class ElseIf
		: public Compound
	{
	public:
		ElseIf( If const & ifStmt
			, expr::ExprPtr ctrlExpr );

		void accept( VisitorPtr vis )override;

		inline expr::Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		If const & m_ifStmt;
		expr::ExprPtr m_ctrlExpr;
	};
	using ElseIfPtr = std::unique_ptr< ElseIf >;

	inline ElseIfPtr makeElseIf( If const & ifStmt
		, expr::ExprPtr ctrlExpr )
	{
		return std::make_unique< ElseIf >( ifStmt
			, std::move( ctrlExpr ) );
	}
}

#endif
