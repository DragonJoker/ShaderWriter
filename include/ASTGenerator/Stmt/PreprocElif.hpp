/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocElif_H___
#define ___AST_PreprocElif_H___
#pragma once

#include "Stmt.hpp"

namespace ast
{
	class PreprocElif
		: public Stmt
	{
	public:
		PreprocElif( ExprPtr ctrlExpr );

		void accept( StmtVisitorPtr vis )override;

		inline Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		ExprPtr m_ctrlExpr;
	};

	inline std::unique_ptr< PreprocElif > makePreprocElif( ExprPtr ctrlExpr )
	{
		return std::make_unique< PreprocElif >( std::move( ctrlExpr ) );
	}
}

#endif
