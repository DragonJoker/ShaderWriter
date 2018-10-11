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
		SwitchTest( ExprPtr value );

		void accept( VisitorPtr vis )override;

		inline Expr * getValue()const
		{
			return m_value.get();
		}

	private:
		ExprPtr m_value;
	};
	using SwitchTestPtr = std::unique_ptr< SwitchTest >;

	inline SwitchTestPtr makeSwitchTest( ExprPtr value )
	{
		return std::make_unique< SwitchTest >( std::move( value ) );
	}
}

#endif
