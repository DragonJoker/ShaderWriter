/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprXorAssign_H___
#define ___AST_ExprXorAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast
{
	class ExprXorAssign
		: public ExprAssign
	{
	public:
		ExprXorAssign( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprXorAssign > makeXorAssignExpr( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprXorAssign >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
