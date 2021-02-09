/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtDiscard_H___
#define ___AST_StmtDiscard_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class Discard
		: public Stmt
	{
	public:
		SDAST_API Discard();

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using DiscardPtr = std::unique_ptr< Discard >;

	inline DiscardPtr makeDiscard()
	{
		return std::make_unique< Discard >();
	}
}

#endif
