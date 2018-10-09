/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogNot_H___
#define ___AST_ExprLogNot_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprLogNot
		: public ExprBinary
	{
	public:
		ExprLogNot( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
