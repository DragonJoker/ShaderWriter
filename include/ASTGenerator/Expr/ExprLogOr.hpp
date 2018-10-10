/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogOr_H___
#define ___AST_ExprLogOr_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprLogOr
		: public ExprBinary
	{
	public:
		ExprLogOr( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprLogOr > makeLogOrExpr( ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprLogOr >( std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
