/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitAnd_H___
#define ___AST_ExprBitAnd_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class BitAnd
		: public Binary
	{
	public:
		BitAnd( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using BitAndPtr = std::unique_ptr< BitAnd >;

	inline BitAndPtr makeBitAnd( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< BitAnd >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
