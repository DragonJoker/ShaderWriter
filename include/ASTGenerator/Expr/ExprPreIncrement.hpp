/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprPreIncrement_H___
#define ___AST_ExprPreIncrement_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast
{
	class ExprPreIncrement
		: public ExprUnary
	{
	public:
		ExprPreIncrement( ExprPtr operand );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
