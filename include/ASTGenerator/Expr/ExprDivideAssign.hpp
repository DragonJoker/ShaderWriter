/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprDivideAssign_H___
#define ___AST_ExprDivideAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast
{
	class ExprDivideAssign
		: public ExprAssign
	{
	public:
		ExprDivideAssign( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprDivideAssign > makeDivideAssignExpr( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprDivideAssign >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
