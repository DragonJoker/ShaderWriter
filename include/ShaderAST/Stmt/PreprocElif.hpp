/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocElif_H___
#define ___AST_PreprocElif_H___
#pragma once

#include "StmtContainer.hpp"

namespace ast::stmt
{
	class PreprocIf;
	class PreprocIfDef;
	class PreprocElif
		: public Container
	{
		friend class PreprocIf;
		friend class PreprocIfDef;
		friend class StmtCache;

	private:
		SDAST_API explicit PreprocElif( StmtCache & stmtCache
			, expr::ExprPtr ctrlExpr );

	public:
		SDAST_API void accept( VisitorPtr vis )override;

		inline expr::Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		expr::ExprPtr m_ctrlExpr{};
	};
}

#endif
