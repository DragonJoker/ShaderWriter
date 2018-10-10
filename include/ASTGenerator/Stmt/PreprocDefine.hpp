/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocDefine_H___
#define ___AST_PreprocDefine_H___
#pragma once

#include "Stmt.hpp"

namespace ast
{
	class PreprocDefine
		: public Stmt
	{
	public:
		PreprocDefine( std::string name
			, ExprPtr expr );

		void accept( StmtVisitorPtr vis )override;

		inline std::string const & getName()const
		{
			return m_name;
		}

		inline Expr * getExpr()const
		{
			return m_expr.get();
		}

	private:
		std::string m_name;
		ExprPtr m_expr;
	};

	inline std::unique_ptr< PreprocDefine > makePreprocDefine( std::string name
		, ExprPtr expr )
	{
		return std::make_unique< PreprocDefine >( std::move( name )
			, std::move( expr ) );
	}
}

#endif
