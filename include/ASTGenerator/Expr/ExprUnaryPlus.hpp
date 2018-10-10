/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprUnaryPlus_H___
#define ___AST_ExprUnaryPlus_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast
{
	class ExprUnaryPlus
		: public ExprUnary
	{
	public:
		ExprUnaryPlus( ExprPtr operand );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprUnaryPlus > makeUnaryPlusExpr( ExprPtr operand )
	{
		return std::make_unique< ExprUnaryPlus >( std::move( operand ) );
	}
}

#endif
