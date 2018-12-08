/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogOr_H___
#define ___AST_ExprLogOr_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class LogOr
		: public Binary
	{
	public:
		LogOr( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using LogOrPtr = std::unique_ptr< LogOr >;

	inline LogOrPtr makeLogOr( type::TypesCache & cache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< LogOr >( cache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
