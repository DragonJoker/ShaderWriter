/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtElse_H___
#define ___AST_StmtElse_H___
#pragma once

#include "StmtCompound.hpp"

namespace ast::stmt
{
	class If;
	class Else
		: public Compound
	{
	public:
		Else( If const & ifStmt );

		void accept( VisitorPtr vis )override;

		inline If const & getIfStmt()const
		{
			return m_ifStmt;
		}

	private:
		If const & m_ifStmt;
	};
	using ElsePtr = std::unique_ptr< Else >;

	inline std::unique_ptr< Else > makeElse( If const & ifStmt )
	{
		return std::make_unique< Else >( ifStmt );
	}
}

#endif
