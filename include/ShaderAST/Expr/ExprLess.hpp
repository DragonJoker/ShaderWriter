/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLess_H___
#define ___AST_ExprLess_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Less
		: public Binary
	{
	public:
		SDAST_API Less( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using LessPtr = std::unique_ptr< Less >;

	inline LessPtr makeLess( type::TypesCache & cache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< Less >( cache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
