/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocIfDef_H___
#define ___AST_PreprocIfDef_H___
#pragma once

#include "Stmt.hpp"

#include "ASTGenerator/Expr/ExprIdentifier.hpp"

namespace ast::stmt
{
	class PreprocIfDef
		: public Stmt
	{
	public:
		PreprocIfDef( expr::IdentifierPtr identExpr );

		void accept( VisitorPtr vis )override;

		inline expr::Identifier * getIdentExpr()const
		{
			return m_identExpr.get();
		}

	private:
		expr::IdentifierPtr m_identExpr;
	};
	using PreprocIfDefPtr = std::unique_ptr< PreprocIfDef >;

	inline PreprocIfDefPtr makePreprocIfDef( expr::IdentifierPtr identExpr )
	{
		return std::make_unique< PreprocIfDef >( std::move( identExpr ) );
	}
}

#endif
