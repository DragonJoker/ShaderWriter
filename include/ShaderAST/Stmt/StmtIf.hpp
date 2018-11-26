/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtIf_H___
#define ___AST_StmtIf_H___
#pragma once

#include "StmtElse.hpp"
#include "StmtElseIf.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class If
		: public Compound
	{
	public:
		If( expr::ExprPtr ctrlExpr );

		Else * createElse();
		ElseIf * createElseIf( expr::ExprPtr ctrlExpr );

		void accept( VisitorPtr vis )override;

		inline expr::Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

		inline Else * getElse()
		{
			return m_else.get();
		}

		inline ElseIfList const & getElseIfList()
		{
			return m_elseIfs;
		}

	private:
		expr::ExprPtr m_ctrlExpr;
		ElsePtr m_else;
		ElseIfList m_elseIfs;
	};
	using IfPtr = std::unique_ptr< If >;

	inline IfPtr makeIf( expr::ExprPtr ctrlExpr )
	{
		return std::make_unique< If >( std::move( ctrlExpr ) );
	}
}

#endif
