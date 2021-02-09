/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLessEqual_H___
#define ___AST_ExprLessEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class LessEqual
		: public Binary
	{
	public:
		SDAST_API LessEqual( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using LessEqualPtr = std::unique_ptr< LessEqual >;

	inline LessEqualPtr makeLessEqual( type::TypesCache & cache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< LessEqual >( cache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
