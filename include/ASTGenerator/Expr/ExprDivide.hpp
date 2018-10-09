/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprDivide_H___
#define ___AST_ExprDivide_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprDivide
		: public ExprBinary
	{
	public:
		ExprDivide( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
