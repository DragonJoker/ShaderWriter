/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprPreIncrement_H___
#define ___AST_ExprPreIncrement_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class PreIncrement
		: public Unary
	{
	public:
		PreIncrement( type::TypePtr type
			, ExprPtr operand );

		void accept( VisitorPtr vis )override;
	};
	using PreIncrementPtr = std::unique_ptr< PreIncrement >;

	inline PreIncrementPtr makePreIncrement( ExprPtr operand )
	{
		auto type = operand->getType();
		return std::make_unique< PreIncrement >( std::move( type )
			, std::move( operand ) );
	}
}

#endif
