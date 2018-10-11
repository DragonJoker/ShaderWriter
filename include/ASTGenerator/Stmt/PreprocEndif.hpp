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
		PreprocEndif();

		void accept( VisitorPtr vis )override;
	};
	using PreprocEndifPtr = std::unique_ptr< PreprocEndif >;

	inline PreprocEndifPtr makePreprocEndif()
	{
		return std::make_unique< PreprocEndif >();
	}
}

#endif
