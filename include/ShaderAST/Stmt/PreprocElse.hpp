/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocElse_H___
#define ___AST_PreprocElse_H___
#pragma once

#include "StmtContainer.hpp"

namespace ast::stmt
{
	class PreprocIf;
	class PreprocIfDef;
	class PreprocElse
		: public Container
	{
		friend class PreprocIf;
		friend class PreprocIfDef;

	private:
		PreprocElse();

	public:
		void accept( VisitorPtr vis )override;
	};
	using PreprocElsePtr = std::unique_ptr< PreprocElse >;
}

#endif
