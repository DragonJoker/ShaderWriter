/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprOrAssign_H___
#define ___AST_ExprOrAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast
{
	class ExprOrAssign
		: public ExprAssign
	{
	public:
		ExprOrAssign( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprOrAssign > makeOrAssignExpr( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprOrAssign >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
