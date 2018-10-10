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

		void accept( StmtVisitorPtr vis )override;

		inline StmtList const & getStatements()const
		{
			return m_statements;
		}

	private:
		StmtList m_statements;
	};
	using StmtCompoundPtr = std::unique_ptr< StmtCompound >;

	inline std::unique_ptr< StmtCompound > makeCompoundStmt( Stmt::Kind kind = Stmt::Kind::eCompound )
	{
		return std::make_unique< StmtCompound >( kind );
	}
}

#endif
