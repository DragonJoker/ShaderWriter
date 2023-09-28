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
		SDAST_API PreprocDefine( StmtCache & stmtCache
			, EntityName nameId
			, expr::ExprPtr expr );

		PreprocDefine( StmtCache & stmtCache
			, uint32_t id
			, std::string name
			, expr::ExprPtr expr )
			: PreprocDefine{ stmtCache, { id, std::move( name ) }, std::move( expr ) }
		{
		}

		SDAST_API void accept( VisitorPtr vis )override;

		inline uint32_t getId()const
		{
			return m_nameId.id;
		}

		inline std::string const & getName()const
		{
			return m_nameId.name;
		}

		inline expr::Expr * getExpr()const
		{
			return m_expr.get();
		}

	private:
		EntityName m_nameId;
		expr::ExprPtr m_expr{};
	};
}

#endif
