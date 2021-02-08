/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprRShiftAssign_H___
#define ___AST_ExprRShiftAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class RShiftAssign
		: public Assign
	{
	public:
		SDAST_API RShiftAssign( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using RShiftAssignPtr = std::unique_ptr< RShiftAssign >;

	inline RShiftAssignPtr makeRShiftAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< RShiftAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
