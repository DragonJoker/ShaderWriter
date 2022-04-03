/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtElseIf_H___
#define ___AST_StmtElseIf_H___
#pragma once

#include "StmtCompound.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class If;
	class ElseIf
		: public Compound
	{
		friend class If;

	private:
		SDAST_API explicit ElseIf( expr::ExprPtr ctrlExpr );

	public:
		SDAST_API void accept( VisitorPtr vis )override;

		inline expr::Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		expr::ExprPtr m_ctrlExpr;
	};
	using ElseIfPtr = std::unique_ptr< ElseIf >;
	using ElseIfList = std::vector< ElseIfPtr >;
}

#endif
