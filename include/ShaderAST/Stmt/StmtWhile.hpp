/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtWhile_H___
#define ___AST_StmtWhile_H___
#pragma once

#include "StmtLoop.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class While
		: public Loop
	{
	public:
		SDAST_API While( expr::ExprPtr ctrlExpr );

		SDAST_API void accept( VisitorPtr vis )override;

		inline expr::Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		expr::ExprPtr m_ctrlExpr;
	};
	using WhilePtr = std::unique_ptr< While >;

	inline WhilePtr makeWhile( expr::ExprPtr ctrlExpr )
	{
		return std::make_unique< While >( std::move( ctrlExpr ) );
	}
}

#endif
