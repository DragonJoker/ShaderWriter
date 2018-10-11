/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprDivideAssign_H___
#define ___AST_ExprDivideAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class DivideAssign
		: public Assign
	{
	public:
		DivideAssign( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using DivideAssignPtr = std::unique_ptr< DivideAssign >;

	inline DivideAssignPtr makeDivideAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< DivideAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
