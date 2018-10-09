/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprEqual_H___
#define ___AST_ExprEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprEqual
		: public ExprBinary
	{
	public:
		ExprEqual( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
