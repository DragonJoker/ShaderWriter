/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprUnaryPlus_H___
#define ___AST_ExprUnaryPlus_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class UnaryPlus
		: public Unary
	{
	public:
		UnaryPlus( ExprPtr operand );

		void accept( VisitorPtr vis )override;
	};
	using UnaryPlusPtr = std::unique_ptr< UnaryPlus >;

	inline UnaryPlusPtr makeUnaryPlus( ExprPtr operand )
	{
		return std::make_unique< UnaryPlus >( std::move( operand ) );
	}
}

#endif
