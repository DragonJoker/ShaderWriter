/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprGreater_H___
#define ___AST_ExprGreater_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Greater
		: public Binary
	{
	public:
		Greater( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( VisitorPtr vis )override;
	};
	using GreaterPtr = std::unique_ptr< Greater >;

	inline GreaterPtr makeGreater( type::TypesCache & cache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< Greater >( cache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
