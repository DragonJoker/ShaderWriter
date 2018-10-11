/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocElse_H___
#define ___AST_PreprocElse_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class PreprocElse
		: public Stmt
	{
	public:
		PreprocElse();

		void accept( VisitorPtr vis )override;
	};
	using PreprocElsePtr = std::unique_ptr< PreprocElse >;

	inline PreprocElsePtr makePreprocElse()
	{
		return std::make_unique< PreprocElse >();
	}
}

#endif
