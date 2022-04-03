/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocIf_H___
#define ___AST_PreprocIf_H___
#pragma once

#include "PreprocElif.hpp"
#include "PreprocElse.hpp"

namespace ast::stmt
{
	class PreprocIf
		: public Container
	{
	public:
		SDAST_API explicit PreprocIf( expr::ExprPtr ctrlExpr );

		SDAST_API PreprocElse * createElse();
		SDAST_API PreprocElif * createElif( expr::ExprPtr ctrlExpr );

		SDAST_API void accept( VisitorPtr vis )override;

		inline expr::Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

		inline PreprocElse * getElse()
		{
			return m_else.get();
		}

		inline StmtList const & getElifList()
		{
			return m_elifs;
		}

	private:
		expr::ExprPtr m_ctrlExpr;
		PreprocElsePtr m_else;
		StmtList m_elifs;
	};
	using PreprocIfPtr = std::unique_ptr< PreprocIf >;

	inline PreprocIfPtr makePreprocIf( expr::ExprPtr ctrlExpr )
	{
		return std::make_unique< PreprocIf >( std::move( ctrlExpr ) );
	}
}

#endif
