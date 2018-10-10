/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprModulo_H___
#define ___AST_ExprModulo_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprModulo
		: public ExprBinary
	{
	public:
		ExprModulo( TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};

	inline std::unique_ptr< ExprModulo > makeModuloExpr( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ExprModulo >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
