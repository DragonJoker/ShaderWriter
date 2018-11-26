/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocIfDef_H___
#define ___AST_PreprocIfDef_H___
#pragma once

#include "PreprocElif.hpp"
#include "PreprocElse.hpp"

#include "ShaderAST/Expr/ExprIdentifier.hpp"

namespace ast::stmt
{
	class PreprocIfDef
		: public Container
	{
	public:
		PreprocIfDef( expr::IdentifierPtr identExpr );

		PreprocElse * createElse();
		PreprocElif * createElif( expr::ExprPtr ctrlExpr );

		void accept( VisitorPtr vis )override;

		inline expr::Identifier * getIdentExpr()const
		{
			return m_identExpr.get();
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
		expr::IdentifierPtr m_identExpr;
		PreprocElsePtr m_else;
		StmtList m_elifs;
	};
	using PreprocIfDefPtr = std::unique_ptr< PreprocIfDef >;

	inline PreprocIfDefPtr makePreprocIfDef( expr::IdentifierPtr identExpr )
	{
		return std::make_unique< PreprocIfDef >( std::move( identExpr ) );
	}
}

#endif
