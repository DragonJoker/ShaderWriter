/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprDivide_H___
#define ___AST_ExprDivide_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Divide
		: public Binary
	{
	public:
		Divide( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using DividePtr = std::unique_ptr< Divide >;

	inline DividePtr makeDivide( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< Divide >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
