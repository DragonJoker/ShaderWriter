/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitNot_H___
#define ___AST_ExprBitNot_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class BitNot
		: public Unary
	{
	public:
		BitNot( type::TypePtr type
			, ExprPtr operand );

		void accept( VisitorPtr vis )override;
	};
	using BitNotPtr = std::unique_ptr< BitNot >;

	inline BitNotPtr makeBitNot( ExprPtr operand )
	{
		auto type = operand->getType();
		return std::make_unique< BitNot >( std::move( type )
			, std::move( operand ) );
	}
}

#endif
