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
		Container( Kind kind = Kind::eContainer );
		void addStmt( StmtPtr stmt );

		void accept( VisitorPtr vis )override;

		inline StmtList const & getStatements()const
		{
			return m_statements;
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
