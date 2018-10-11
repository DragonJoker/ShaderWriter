/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAssign_H___
#define ___AST_ExprAssign_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Assign
		: public Binary
	{
	public:
		Assign( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs
			, Kind kind = Kind::eAssign );

		void accept( VisitorPtr vis )override;
	};
	using AssignPtr = std::unique_ptr< Assign >;

	inline AssignPtr makeAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< Assign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
