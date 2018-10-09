/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitAnd_H___
#define ___AST_ExprBitAnd_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprBitAnd
		: public ExprBinary
	{
	public:
		ExprBitAnd( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
