/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogNot_H___
#define ___AST_ExprLogNot_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast
{
	class ExprLogNot
		: public ExprUnary
	{
	public:
		ExprLogNot( ExprPtr operand );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprLogNot > makeLogNotExpr( ExprPtr operand )
	{
		return std::make_unique< ExprLogNot >( std::move( operand ) );
	}
}

#endif
