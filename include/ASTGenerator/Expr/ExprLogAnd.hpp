/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogAnd_H___
#define ___AST_ExprLogAnd_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprLogAnd
		: public ExprBinary
	{
	public:
		ExprLogAnd( ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprLogAnd > makeLogAndExpr( ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprLogAnd >( std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
