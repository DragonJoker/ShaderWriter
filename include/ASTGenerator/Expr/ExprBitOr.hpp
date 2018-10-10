/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitOr_H___
#define ___AST_ExprBitOr_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprBitOr
		: public ExprBinary
	{
	public:
		ExprBitOr( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprBitOr > makeBitOrExpr( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprBitOr >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
