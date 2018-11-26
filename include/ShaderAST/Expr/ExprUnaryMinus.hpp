/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprUnaryMinus_H___
#define ___AST_ExprUnaryMinus_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class UnaryMinus
		: public Unary
	{
	public:
		UnaryMinus( type::TypePtr type
			, ExprPtr operand );

		void accept( VisitorPtr vis )override;
	};
	using UnaryMinusPtr = std::unique_ptr< UnaryMinus >;

	inline UnaryMinusPtr makeUnaryMinus( ExprPtr operand )
	{
		auto type = operand->getType();
		return std::make_unique< UnaryMinus >( std::move( type )
			, std::move( operand ) );
	}
}

#endif
