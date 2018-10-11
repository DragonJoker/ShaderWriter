/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLessEqual_H___
#define ___AST_ExprLessEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class LessEqual
		: public Binary
	{
	public:
		LessEqual( ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using LessEqualPtr = std::unique_ptr< LessEqual >;

	inline LessEqualPtr makeLessEqual( ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< LessEqual >( std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
