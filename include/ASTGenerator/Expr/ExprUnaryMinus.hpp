/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprUnaryMinus_H___
#define ___AST_ExprUnaryMinus_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast
{
	class ExprUnaryMinus
		: public ExprUnary
	{
	public:
		ExprUnaryMinus( Type type
			, ExprPtr operand );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
