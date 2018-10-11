/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitOr_H___
#define ___AST_ExprBitOr_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class BitOr
		: public Binary
	{
	public:
		BitOr( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using BitOrPtr = std::unique_ptr< BitOr >;

	inline BitOrPtr makeBitOr( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< BitOr >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
