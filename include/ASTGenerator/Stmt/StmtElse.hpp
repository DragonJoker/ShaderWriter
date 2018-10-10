/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtElse_H___
#define ___AST_StmtElse_H___
#pragma once

#include "StmtCompound.hpp"

namespace ast
{
	class StmtIf;
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

	inline std::unique_ptr< StmtElse > makeElseStmt( StmtIf const & ifStmt )
	{
		return std::make_unique< StmtElse >( ifStmt );
	}
}

#endif
