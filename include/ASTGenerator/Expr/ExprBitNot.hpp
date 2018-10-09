/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitNot_H___
#define ___AST_ExprBitNot_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprBitNot
		: public ExprBinary
	{
	public:
		ExprBitNot( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
