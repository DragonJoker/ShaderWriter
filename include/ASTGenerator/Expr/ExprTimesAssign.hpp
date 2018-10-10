/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprTimesAssign_H___
#define ___AST_ExprTimesAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast
{
	class ExprTimesAssign
		: public ExprAssign
	{
	public:
		ExprTimesAssign( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprTimesAssign > makeTimesAssignExpr( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprTimesAssign >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
