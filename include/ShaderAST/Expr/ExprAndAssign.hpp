/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAndAssign_H___
#define ___AST_ExprAndAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class AndAssign
		: public Assign
	{
	public:
		SDAST_API AndAssign( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using AndAssignPtr = std::unique_ptr< AndAssign >;

	inline AndAssignPtr makeAndAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< AndAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
