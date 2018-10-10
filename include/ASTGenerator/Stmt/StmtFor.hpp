/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtFor_H___
#define ___AST_StmtFor_H___
#pragma once

#include "StmtCompound.hpp"

#include "ASTGenerator/Expr/ExprInit.hpp"

namespace ast
{
	class StmtFor
		: public StmtCompound
	{
	public:
		StmtFor( ExprPtr initExpr
			, ExprPtr ctrlExpr
			, ExprPtr incrExpr );

		void accept( StmtVisitorPtr vis )override;

		inline Expr * getInitExpr()const
		{
			return m_initExpr.get();
		}

		inline Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

		inline Expr * getIncrExpr()const
		{
			return m_incrExpr.get();
		}

	private:
		ExprPtr m_initExpr;
		ExprPtr m_ctrlExpr;
		ExprPtr m_incrExpr;
	};

	inline std::unique_ptr< StmtFor > makeForStmt( ExprPtr initExpr
		, ExprPtr ctrlExpr
		, ExprPtr incrExpr )
	{
		return std::make_unique< StmtFor >( std::move( initExpr )
			, std::move( ctrlExpr ) 
			, std::move( incrExpr ) );
	}
}

#endif
