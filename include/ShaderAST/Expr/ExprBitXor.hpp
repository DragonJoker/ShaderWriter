/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprBitXor_H___
#define ___AST_ExprBitXor_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class BitXor
		: public Binary
	{
	public:
		BitXor( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using BitXorPtr = std::unique_ptr< BitXor >;

	inline BitXorPtr makeBitXor( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< BitXor >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
