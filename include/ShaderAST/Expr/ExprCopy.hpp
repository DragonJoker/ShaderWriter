/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprCopy_H___
#define ___AST_ExprCopy_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class Copy
		: public Unary
	{
	public:
		SDAST_API Copy( ExprPtr op );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using CopyPtr = std::unique_ptr< Copy >;

	inline CopyPtr makeCopy( ExprPtr op )
	{
		return std::make_unique< Copy >( std::move( op ) );
	}
}

#endif
