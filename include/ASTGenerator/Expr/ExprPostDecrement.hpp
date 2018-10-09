/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprPostDecrement_H___
#define ___AST_ExprPostDecrement_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast
{
	class ExprPostDecrement
		: public ExprUnary
	{
	public:
		ExprPostDecrement( ExprPtr operand );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
