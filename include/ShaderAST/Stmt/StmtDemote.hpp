/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtDemote_H___
#define ___AST_StmtDemote_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class Demote
		: public Stmt
	{
	public:
		SDAST_API Demote();

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using DemotePtr = std::unique_ptr< Demote >;

	inline DemotePtr makeDemote()
	{
		return std::make_unique< Demote >();
	}
}

#endif
