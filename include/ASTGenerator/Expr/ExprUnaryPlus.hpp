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
		UnaryPlus( type::TypePtr type
			, ExprPtr operand );

		void accept( VisitorPtr vis )override;
	};
	using UnaryPlusPtr = std::unique_ptr< UnaryPlus >;

	inline UnaryPlusPtr makeUnaryPlus( ExprPtr operand )
	{
		auto type = operand->getType();
		return std::make_unique< UnaryPlus >( std::move( type )
			, std::move( operand ) );
	}
}

#endif
