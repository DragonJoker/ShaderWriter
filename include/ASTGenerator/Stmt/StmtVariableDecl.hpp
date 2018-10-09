/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtVariableDecl_H___
#define ___AST_StmtVariableDecl_H___
#pragma once

#include "StmtIf.hpp"

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
}

#endif
