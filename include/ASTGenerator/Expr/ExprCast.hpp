/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprCast_H___
#define ___AST_ExprCast_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast
{
	class ExprCast
		: public ExprUnary
	{
	public:
		ExprCast( TypePtr dstType
			, ExprPtr operand );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprCast > makeCastExpr( TypePtr dstType
		, ExprPtr operand )
	{
		return std::make_unique< ExprCast >( std::move( dstType )
			, std::move( operand ) );
	}
}

#endif
