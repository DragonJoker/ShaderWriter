/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtContainer_H___
#define ___AST_StmtContainer_H___
#pragma once

#include "Stmt.hpp"

namespace ast
{
	class StmtCloner;
}

namespace ast::stmt
{
	class Container
		: public Stmt
	{
	protected:
		SDAST_API Container( StmtCache & stmtCache
			, size_t size
			, Kind kind );

	public:
		SDAST_API explicit Container( StmtCache & stmtCache );

		SDAST_API void addStmt( StmtPtr stmt );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline StmtPtr const & back()const
		{
			return m_statements.back();
		}

		inline bool empty()const
		{
			return m_statements.empty();
		}

		inline size_t size()const
		{
			return m_statements.size();
		}

		inline StmtList::const_iterator begin()const
		{
			return m_statements.begin();
		}

		inline StmtList::const_iterator end()const
		{
			return m_statements.end();
		}

	private:
		StmtList m_statements;

		friend class ast::StmtCloner;
	};
}

#endif
