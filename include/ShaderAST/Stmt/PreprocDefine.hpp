/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocDefine_H___
#define ___AST_PreprocDefine_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class PreprocDefine
		: public Stmt
	{
	public:
		SDAST_API PreprocDefine( std::string name
			, expr::ExprPtr expr );

		SDAST_API void accept( VisitorPtr vis )override;

		inline std::string const & getName()const
		{
			return m_name;
		}

		inline expr::Expr * getExpr()const
		{
			return m_expr.get();
		}

	private:
		std::string m_name;
		expr::ExprPtr m_expr;
	};
	using PreprocDefinePtr = std::unique_ptr< PreprocDefine >;

	inline PreprocDefinePtr makePreprocDefine( std::string name
		, expr::ExprPtr expr )
	{
		return std::make_unique< PreprocDefine >( std::move( name )
			, std::move( expr ) );
	}
}

#endif
