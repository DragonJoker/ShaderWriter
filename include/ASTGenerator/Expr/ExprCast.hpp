/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprCast_H___
#define ___AST_ExprCast_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class Cast
		: public Unary
	{
	public:
		Cast( type::TypePtr dstType
			, ExprPtr operand );

		void accept( VisitorPtr vis )override;
	};
	using CastPtr = std::unique_ptr< Cast >;

	inline CastPtr makeCast( type::TypePtr dstType
		, ExprPtr operand )
	{
		return std::make_unique< Cast >( std::move( dstType )
			, std::move( operand ) );
	}
}

#endif
