/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocElse_H___
#define ___AST_PreprocElse_H___
#pragma once

#include "Stmt.hpp"

namespace ast
{
	class PreprocElse
		: public Stmt
	{
	public:
		PreprocElse();

		void accept( StmtVisitorPtr vis )override;
	};

	inline std::unique_ptr< PreprocElse > makePreprocElse()
	{
		return std::make_unique< PreprocElse >();
	}
}

#endif
