/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocIf_H___
#define ___AST_PreprocIf_H___
#pragma once

#include "Stmt.hpp"

namespace ast
{
	class PreprocIf
		: public Stmt
	{
	public:
		PreprocIf( ExprPtr ctrlExpr );

		void accept( StmtVisitorPtr vis )override;

		inline Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		ExprPtr m_ctrlExpr;
	};

	inline std::unique_ptr< PreprocIf > makePreprocIf( ExprPtr ctrlExpr )
	{
		return std::make_unique< PreprocIf >( std::move( ctrlExpr ) );
	}
}

#endif
