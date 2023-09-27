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

	private:
		SDAST_API explicit PreprocElif( expr::ExprPtr ctrlExpr );

	public:
		SDAST_API void accept( VisitorPtr vis )override;

		inline expr::Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		expr::ExprPtr m_ctrlExpr{};
	};
	using PreprocElifPtr = std::unique_ptr< PreprocElif >;
}

#endif
