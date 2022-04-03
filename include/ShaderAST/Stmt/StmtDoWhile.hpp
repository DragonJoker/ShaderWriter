/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtDoWhile_H___
#define ___AST_StmtDoWhile_H___
#pragma once

#include "StmtLoop.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class DoWhile
		: public Loop
	{
	public:
		SDAST_API explicit DoWhile( expr::ExprPtr ctrlExpr );

		SDAST_API void accept( VisitorPtr vis )override;

		inline expr::Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		expr::ExprPtr m_ctrlExpr;
	};
	using DoWhilePtr = std::unique_ptr< DoWhile >;

	inline DoWhilePtr makeDoWhile( expr::ExprPtr ctrlExpr )
	{
		return std::make_unique< DoWhile >( std::move( ctrlExpr ) );
	}
}

#endif
