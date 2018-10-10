/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAdd_H___
#define ___AST_ExprAdd_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprAdd
		: public ExprBinary
	{
	public:
		ExprAdd( TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprAdd > makeAddExpr( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprAdd >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
