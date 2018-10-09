/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprGreaterEqual_H___
#define ___AST_ExprGreaterEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprGreaterEqual
		: public ExprBinary
	{
	public:
		ExprGreaterEqual( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
