/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLess_H___
#define ___AST_ExprLess_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Less
		: public Binary
	{
	public:
		Less( ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using LessPtr = std::unique_ptr< Less >;

	inline LessPtr makeLess( ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< Less >( std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
