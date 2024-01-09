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
		friend class If;
		friend class StmtCache;

	private:
		SDAST_API explicit Else( StmtCache & stmtCache );

	public:
		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
