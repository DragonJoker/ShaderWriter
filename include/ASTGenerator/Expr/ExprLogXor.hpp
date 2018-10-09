/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogXor_H___
#define ___AST_ExprLogXor_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprLogXor
		: public ExprBinary
	{
	public:
		ExprLogXor( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
