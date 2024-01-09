/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtHitAttributeVariableDecl_H___
#define ___AST_StmtHitAttributeVariableDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class HitAttributeVariableDecl
		: public Stmt
	{
	public:
		SDAST_API explicit HitAttributeVariableDecl( StmtCache & stmtCache
			, var::VariablePtr variable );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline var::VariablePtr getVariable()const
		{
			return m_variable;
		}

	private:
		var::VariablePtr m_variable;
	};
}

#endif
