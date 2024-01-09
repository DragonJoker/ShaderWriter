/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtTerminateInvocation_H___
#define ___AST_StmtTerminateInvocation_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class TerminateInvocation
		: public Stmt
	{
	public:
		SDAST_API explicit TerminateInvocation( StmtCache & stmtCache );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
