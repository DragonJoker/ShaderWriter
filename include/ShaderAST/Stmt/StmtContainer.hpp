/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtContainer_H___
#define ___AST_StmtContainer_H___
#pragma once

#include "StmtList.hpp"

namespace ast::stmt
{
	class Container
		: public Stmt
	{
	public:
		SDAST_API Container( Kind kind = Kind::eContainer );
		SDAST_API void addStmt( StmtPtr stmt );

		SDAST_API void accept( VisitorPtr vis )override;

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
	};
	using ContainerPtr = std::unique_ptr< Container >;

	inline std::unique_ptr< Container > makeContainer()
	{
		return std::make_unique< Container >();
	}
}

#endif
