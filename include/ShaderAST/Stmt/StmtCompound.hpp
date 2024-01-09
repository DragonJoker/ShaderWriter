/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtCompound_H___
#define ___AST_StmtCompound_H___
#pragma once

#include "StmtContainer.hpp"

namespace ast::stmt
{
	class Compound
		: public Container
	{
	protected:
		SDAST_API Compound( StmtCache & stmtCache
			, size_t size
			, Kind kind );

	public:
		SDAST_API explicit Compound( StmtCache & stmtCache );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
