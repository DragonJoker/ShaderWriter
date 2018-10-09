/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprSwitchTest_H___
#define ___AST_ExprSwitchTest_H___
#pragma once

#include "Expr.hpp"

namespace ast
{
	class ExprSwitchTest
		: public Expr
	{
	public:
		ExprSwitchTest( ExprPtr value );

		void accept( ExprVisitorPtr vis )override;

	private:
		ExprPtr m_value;
	};
}

#endif
