/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprEqual_H___
#define ___AST_ExprEqual_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Equal
		: public Binary
	{
	public:
		SDAST_API Equal( type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using EqualPtr = std::unique_ptr< Equal >;

	inline EqualPtr makeEqual( type::TypesCache & cache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return std::make_unique< Equal >( cache.getVector( type::Kind::eBoolean, type::getComponentCount( lhs->getType() ) )
			, std::move( lhs )
			, std::move( rhs ) );
	}
}

#endif
