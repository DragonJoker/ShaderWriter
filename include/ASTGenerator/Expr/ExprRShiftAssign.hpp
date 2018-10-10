/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprRShiftAssign_H___
#define ___AST_ExprRShiftAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast
{
	class ExprRShiftAssign
		: public ExprAssign
	{
	public:
		ExprRShiftAssign( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprRShiftAssign > makeRShiftAssignExpr( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprRShiftAssign >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
