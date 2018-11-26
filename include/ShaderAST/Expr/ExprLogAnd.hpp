/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogAnd_H___
#define ___AST_ExprLogAnd_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class LogAnd
		: public Binary
	{
	public:
		LogAnd( ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using LogAndPtr = std::unique_ptr< LogAnd >;

	inline LogAndPtr makeLogAnd( ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< LogAnd >( std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
