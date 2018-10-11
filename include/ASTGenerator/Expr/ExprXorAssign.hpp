/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprXorAssign_H___
#define ___AST_ExprXorAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class XorAssign
		: public Assign
	{
	public:
		XorAssign( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using XorAssignPtr = std::unique_ptr< XorAssign >;

	inline XorAssignPtr makeXorAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< XorAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
