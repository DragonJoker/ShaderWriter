/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprComma_H___
#define ___AST_ExprComma_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprComma
		: public ExprBinary
	{
	public:
		ExprComma( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
