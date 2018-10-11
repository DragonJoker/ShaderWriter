/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprEqual_H___
#define ___AST_ExprEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Equal
		: public Binary
	{
	public:
		Equal( ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using EqualPtr = std::unique_ptr< Equal >;

	inline EqualPtr makeEqual( ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< Equal >( std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
