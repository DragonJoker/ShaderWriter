/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocElif_H___
#define ___AST_PreprocElif_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class PreprocElif
		: public Stmt
	{
	public:
		PreprocElif( expr::ExprPtr ctrlExpr );

		void accept( VisitorPtr vis )override;

		inline expr::Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		expr::ExprPtr m_ctrlExpr;
	};
	using PreprocElifPtr = std::unique_ptr< PreprocElif >;

	inline PreprocElifPtr makePreprocElif( expr::ExprPtr ctrlExpr )
	{
		return std::make_unique< PreprocElif >( std::move( ctrlExpr ) );
	}
}

#endif
