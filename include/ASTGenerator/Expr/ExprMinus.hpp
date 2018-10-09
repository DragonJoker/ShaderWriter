/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMinus_H___
#define ___AST_ExprMinus_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprMinus
		: public ExprBinary
	{
	public:
		ExprMinus( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
