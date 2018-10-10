/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtVariableDecl_H___
#define ___AST_StmtVariableDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast
{
	class StmtVariableDecl
		: public Stmt
	{
	public:
		StmtVariableDecl( VariablePtr variable );

		void accept( StmtVisitorPtr vis )override;

		inline Variable const & getVariable()const
		{
			return *m_variable;
		}

	private:
		VariablePtr m_variable;
	};
	using StmtVariableDeclPtr = std::unique_ptr< StmtVariableDecl >;

	inline std::unique_ptr< StmtVariableDecl > makeVariableDeclStmt( VariablePtr variable )
	{
		return std::make_unique< StmtVariableDecl >( std::move( variable ) );
	}
}

#endif
