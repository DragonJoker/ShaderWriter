/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitAnd_H___
#define ___AST_ExprBitAnd_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprBitAnd
		: public ExprBinary
	{
	public:
		ExprBitAnd( TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprBitAnd > makeBitAndExpr( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprBitAnd >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
