/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLShift_H___
#define ___AST_ExprLShift_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprLShift
		: public ExprBinary
	{
	public:
		ExprLShift( TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprLShift > makeLShiftExpr( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprLShift >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
