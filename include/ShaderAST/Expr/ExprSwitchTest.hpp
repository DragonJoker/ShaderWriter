/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprSwitchTest_H___
#define ___AST_ExprSwitchTest_H___
#pragma once

#include "Expr.hpp"

namespace ast::expr
{
	class SwitchTest
		: public Expr
	{
	public:
		SDAST_API explicit SwitchTest( ExprCache & exprCache
			, ExprPtr value );

		SDAST_API void accept( VisitorPtr vis )override;

		inline Expr * getValue()const
		{
			return m_value.get();
		}

	private:
		ExprPtr m_value{};
	};
}

#endif
