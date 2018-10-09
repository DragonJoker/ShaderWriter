/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtCompound_H___
#define ___AST_StmtCompound_H___
#pragma once

#include "StmtList.hpp"

namespace ast
{
	class StmtCompound
		: public Stmt
	{
	public:
		StmtCompound( Stmt::Kind kind = Stmt::Kind::eCompound );
		void addStmt( StmtPtr stmt );

		inline StmtList const & getStatements()const
		{
			return m_statements;
		}

	private:
		StmtList m_statements;
	};
}

#endif
