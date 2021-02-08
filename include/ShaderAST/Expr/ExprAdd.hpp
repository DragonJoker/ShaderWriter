/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAdd_H___
#define ___AST_ExprAdd_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Add
		: public Binary
	{
	public:
		SDAST_API Add( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using AddPtr = std::unique_ptr< Add >;

	inline AddPtr makeAdd( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< Add >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
