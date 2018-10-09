/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprGreater_H___
#define ___AST_ExprGreater_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprGreater
		: public ExprBinary
	{
	public:
		ExprGreater( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
