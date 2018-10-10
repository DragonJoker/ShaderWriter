/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocIfDef_H___
#define ___AST_PreprocIfDef_H___
#pragma once

#include "Stmt.hpp"

#include "ASTGenerator/Expr/ExprIdentifier.hpp"

namespace ast
{
	class PreprocIfDef
		: public Stmt
	{
	public:
		PreprocIfDef( ExprIdentifierPtr identExpr );

		void accept( StmtVisitorPtr vis )override;

		inline ExprIdentifier * getIdentExpr()const
		{
			return m_identExpr.get();
		}

	private:
		ExprIdentifierPtr m_identExpr;
	};

	inline std::unique_ptr< PreprocIfDef > makePreprocIfDef( ExprIdentifierPtr identExpr )
	{
		return std::make_unique< PreprocIfDef >( std::move( identExpr ) );
	}
}

#endif
