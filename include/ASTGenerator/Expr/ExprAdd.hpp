/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAdd_H___
#define ___AST_ExprAdd_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprAdd
		: public ExprBinary
	{
	public:
		ExprAdd( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
