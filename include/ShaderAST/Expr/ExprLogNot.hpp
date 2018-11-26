/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogNot_H___
#define ___AST_ExprLogNot_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class LogNot
		: public Unary
	{
	public:
		LogNot( ExprPtr operand );

		void accept( VisitorPtr vis )override;
	};
	using LogNotPtr = std::unique_ptr< LogNot >;

	inline LogNotPtr makeLogNot( ExprPtr operand )
	{
		return std::make_unique< LogNot >( std::move( operand ) );
	}
}

#endif
