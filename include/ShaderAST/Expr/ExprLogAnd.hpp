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
		LogAnd( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using LogAndPtr = std::unique_ptr< LogAnd >;

	inline LogAndPtr makeLogAnd( type::TypesCache & cache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< LogAnd >( cache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
