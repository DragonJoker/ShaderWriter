/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprTimes_H___
#define ___AST_ExprTimes_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprTimes
		: public ExprBinary
	{
	public:
		ExprTimes( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
