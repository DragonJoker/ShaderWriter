/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprSwitchCase_H___
#define ___AST_ExprSwitchCase_H___
#pragma once

#include "ExprLiteral.hpp"

namespace ast
{
	class ExprSwitchCase
		: public Expr
	{
	public:
		ExprSwitchCase( ExprLiteralPtr label );

		void accept( ExprVisitorPtr vis )override;

		inline ExprLiteral * getLabel()const
		{
			return m_label.get();
		}

	private:
		ExprLiteralPtr m_label;
	};
	using ExprSwitchCasePtr = std::unique_ptr< ExprSwitchCase >;
	using ExprSwitchCaseList = std::vector< ExprSwitchCasePtr >;

	inline std::unique_ptr< ExprSwitchCase > makeSwitchCaseExpr( ExprLiteralPtr label )
	{
		return std::make_unique< ExprSwitchCase >( std::move( label ) );
	}
}

#endif
