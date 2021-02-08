/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprModulo_H___
#define ___AST_ExprModulo_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Modulo
		: public Binary
	{
	public:
		SDAST_API Modulo( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using ModuloPtr = std::unique_ptr< Modulo >;

	inline ModuloPtr makeModulo( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< Modulo >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
