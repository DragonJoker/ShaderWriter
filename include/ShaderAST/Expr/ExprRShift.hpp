/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprRShift_H___
#define ___AST_ExprRShift_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class RShift
		: public Binary
	{
	public:
		SDAST_API RShift( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using RShiftPtr = std::unique_ptr< RShift >;

	inline RShiftPtr makeRShift( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< RShift >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
