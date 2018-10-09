/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAndAssign_H___
#define ___AST_ExprAndAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast
{
	class ExprAndAssign
		: public ExprAssign
	{
	public:
		ExprAndAssign( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
