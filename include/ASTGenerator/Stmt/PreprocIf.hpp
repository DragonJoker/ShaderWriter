/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocIf_H___
#define ___AST_PreprocIf_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class PreprocIf
		: public Stmt
	{
	public:
		PreprocIf( expr::ExprPtr ctrlExpr );

		void accept( VisitorPtr vis )override;

		inline expr::Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		expr::ExprPtr m_ctrlExpr;
	};
	using PreprocIfPtr = std::unique_ptr< PreprocIf >;

	inline PreprocIfPtr makePreprocIf( expr::ExprPtr ctrlExpr )
	{
		return std::make_unique< PreprocIf >( std::move( ctrlExpr ) );
	}
}

#endif
