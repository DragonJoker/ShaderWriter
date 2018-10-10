/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAddAssign_H___
#define ___AST_ExprAddAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast
{
	class ExprAddAssign
		: public ExprAssign
	{
	public:
		ExprAddAssign( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprAddAssign > makeAddAssignExpr( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprAddAssign >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
