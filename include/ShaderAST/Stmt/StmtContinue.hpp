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
		SDAST_API Continue();

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using ContinuePtr = std::unique_ptr< Continue >;

	inline ContinuePtr makeContinue()
	{
		return std::make_unique< Continue >();
	}
}

#endif
