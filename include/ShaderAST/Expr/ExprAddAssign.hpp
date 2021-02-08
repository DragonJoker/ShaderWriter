/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAddAssign_H___
#define ___AST_ExprAddAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class AddAssign
		: public Assign
	{
	public:
		SDAST_API AddAssign( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using AddAssignPtr = std::unique_ptr< AddAssign >;

	inline AddAssignPtr makeAddAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< AddAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
