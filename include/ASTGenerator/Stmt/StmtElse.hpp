/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtElse_H___
#define ___AST_StmtElse_H___
#pragma once

#include "StmtIf.hpp"

namespace ast
{
	class StmtElse
		: public StmtCompound
	{
	public:
		StmtElse( StmtIf const & ifStmt );

		void accept( StmtVisitorPtr vis )override;

		inline StmtIf const & getIfStmt()const
		{
			return m_ifStmt;
		}

	private:
		StmtIf const & m_ifStmt;
	};
}

#endif
