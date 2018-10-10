/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAssign_H___
#define ___AST_ExprAssign_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprAssign
		: public ExprBinary
	{
	public:
		ExprAssign( Type type
			, ExprPtr lhs
			, ExprPtr rhs
			, Expr::Kind kind = Expr::Kind::eAssign );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprAssign > makeAssignExpr( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprAssign >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
