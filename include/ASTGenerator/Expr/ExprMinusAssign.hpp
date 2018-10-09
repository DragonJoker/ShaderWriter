/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMinusAssign_H___
#define ___AST_ExprMinusAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast
{
	class ExprMinusAssign
		: public ExprAssign
	{
	public:
		ExprMinusAssign( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
