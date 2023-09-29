/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocEndif_H___
#define ___AST_PreprocEndif_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class PreprocEndif
		: public Stmt
	{
	public:
		SDAST_API explicit PreprocEndif( StmtCache & stmtCache );

		SDAST_API void accept( VisitorPtr vis )override;
	};
}

#endif
