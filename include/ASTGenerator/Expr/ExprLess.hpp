/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLess_H___
#define ___AST_ExprLess_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprLess
		: public ExprBinary
	{
	public:
		ExprLess( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
