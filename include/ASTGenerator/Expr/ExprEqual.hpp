/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprEqual_H___
#define ___AST_ExprEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprEqual
		: public ExprBinary
	{
	public:
		ExprEqual( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprEqual > makeEqualExpr( ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprEqual >( std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
