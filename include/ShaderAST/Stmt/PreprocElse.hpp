/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocElse_H___
#define ___AST_PreprocElse_H___
#pragma once

#include "StmtContainer.hpp"

namespace ast::stmt
{
	class PreprocIf;
	class PreprocIfDef;
	class PreprocElse
		: public Container
	{
		friend class PreprocIf;
		friend class PreprocIfDef;
		friend class StmtCache;

	private:
		SDAST_API PreprocElse( StmtCache & stmtCache );

	public:
		SDAST_API void accept( VisitorPtr vis )override;
	};
}

#endif
