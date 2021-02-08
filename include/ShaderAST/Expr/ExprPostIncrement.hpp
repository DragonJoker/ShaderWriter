/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprPostIncrement_H___
#define ___AST_ExprPostIncrement_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class PostIncrement
		: public Unary
	{
	public:
		SDAST_API PostIncrement( type::TypePtr type
			, ExprPtr operand );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using PostIncrementPtr = std::unique_ptr< PostIncrement >;

	inline PostIncrementPtr makePostIncrement( ExprPtr operand )
	{
		auto type = operand->getType();
		return std::make_unique< PostIncrement >( std::move( type )
			, std::move( operand ) );
	}
}

#endif
