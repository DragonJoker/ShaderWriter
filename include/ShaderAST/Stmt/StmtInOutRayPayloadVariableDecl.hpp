/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtInOutRayPayloadVariableDecl_H___
#define ___AST_StmtInOutRayPayloadVariableDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class InOutRayPayloadVariableDecl
		: public Stmt
	{
	public:
		SDAST_API InOutRayPayloadVariableDecl( StmtCache & stmtCache
			, var::VariablePtr variable
			, uint32_t location );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline var::VariablePtr getVariable()const
		{
			return m_variable;
		}

		inline uint32_t getLocation()const
		{
			return m_location;
		}

	private:
		var::VariablePtr m_variable;
		uint32_t m_location;
	};
}

#endif
