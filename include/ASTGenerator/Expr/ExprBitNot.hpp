/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitNot_H___
#define ___AST_ExprBitNot_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast
{
	class ExprBitNot
		: public ExprUnary
	{
	public:
		ExprBitNot( Type type
			, ExprPtr operand );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprBitNot > makeBitNotExpr( Type type
		, ExprPtr operand )
	{
		return std::make_unique< ExprBitNot >( type
			, std::move( operand ) );
	}
}

#endif
