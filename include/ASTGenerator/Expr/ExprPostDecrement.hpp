/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprPostDecrement_H___
#define ___AST_ExprPostDecrement_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class PostDecrement
		: public Unary
	{
	public:
		PostDecrement( ExprPtr operand );

		void accept( VisitorPtr vis )override;
	};
	using PostDecrementPtr = std::unique_ptr< PostDecrement >;

	inline PostDecrementPtr makePostDecrement( ExprPtr operand )
	{
		return std::make_unique< PostDecrement >( std::move( operand ) );
	}
}

#endif
