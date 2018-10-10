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

		inline Expr * getValue()const
		{
			return m_value.get();
		}

	private:
		ExprPtr m_value;
	};
	using ExprSwitchTestPtr = std::unique_ptr< ExprSwitchTest >;

	inline std::unique_ptr< ExprSwitchTest > makeSwitchTestExpr( ExprPtr value )
	{
		return std::make_unique< ExprSwitchTest >( std::move( value ) );
	}
}

#endif
