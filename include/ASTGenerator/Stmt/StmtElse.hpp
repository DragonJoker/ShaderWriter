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
	public:
		Else();

		void accept( VisitorPtr vis )override;
	};
	using ElsePtr = std::unique_ptr< Else >;

	inline std::unique_ptr< Else > makeElse()
	{
		return std::make_unique< Else >();
	}
}

#endif
