/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMinusAssign_H___
#define ___AST_ExprMinusAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class MinusAssign
		: public Assign
	{
	public:
		MinusAssign( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using MinusAssignPtr = std::unique_ptr< MinusAssign >;

	inline MinusAssignPtr makeMinusAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< MinusAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
