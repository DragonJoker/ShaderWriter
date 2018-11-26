/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprOrAssign_H___
#define ___AST_ExprOrAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class OrAssign
		: public Assign
	{
	public:
		OrAssign( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using OrAssignPtr = std::unique_ptr< OrAssign >;

	inline OrAssignPtr makeOrAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< OrAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
