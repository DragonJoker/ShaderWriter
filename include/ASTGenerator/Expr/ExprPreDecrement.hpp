/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprPreDecrement_H___
#define ___AST_ExprPreDecrement_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class PreDecrement
		: public Unary
	{
	public:
		PreDecrement( ExprPtr operand );

		void accept( VisitorPtr vis )override;
	};
	using PreDecrementPtr = std::unique_ptr< PreDecrement >;

	inline PreDecrementPtr makePreDecrement( ExprPtr operand )
	{
		return std::make_unique< PreDecrement >( std::move( operand ) );
	}
}

#endif
