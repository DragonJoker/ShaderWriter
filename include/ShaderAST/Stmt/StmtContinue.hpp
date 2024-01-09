/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtContinue_H___
#define ___AST_StmtContinue_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class Continue
		: public Stmt
	{
	public:
		SDAST_API explicit Continue( StmtCache & stmtCache );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
