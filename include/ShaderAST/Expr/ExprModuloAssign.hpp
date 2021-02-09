/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprModuloAssign_H___
#define ___AST_ExprModuloAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class ModuloAssign
		: public Assign
	{
	public:
		SDAST_API ModuloAssign( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using ModuloAssignPtr = std::unique_ptr< ModuloAssign >;

	inline ModuloAssignPtr makeModuloAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< ModuloAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
