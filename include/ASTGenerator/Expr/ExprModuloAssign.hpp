/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprModuloAssign_H___
#define ___AST_ExprModuloAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast
{
	class ExprModuloAssign
		: public ExprAssign
	{
	public:
		ExprModuloAssign( TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprModuloAssign > makeModuloAssignExpr( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprModuloAssign >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
