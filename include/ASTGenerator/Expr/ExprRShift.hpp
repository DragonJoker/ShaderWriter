/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprRShift_H___
#define ___AST_ExprRShift_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprRShift
		: public ExprBinary
	{
	public:
		ExprRShift( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
