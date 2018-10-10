/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocEndif_H___
#define ___AST_PreprocEndif_H___
#pragma once

#include "Stmt.hpp"

namespace ast
{
	class PreprocEndif
		: public Stmt
	{
	public:
		PreprocEndif();

		void accept( StmtVisitorPtr vis )override;
	};

	inline std::unique_ptr< PreprocEndif > makePreprocEndif()
	{
		return std::make_unique< PreprocEndif >();
	}
}

#endif
