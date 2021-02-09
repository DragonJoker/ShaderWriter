/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLogNot_H___
#define ___AST_ExprLogNot_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class LogNot
		: public Unary
	{
	public:
		SDAST_API LogNot( type::TypePtr type
			, ExprPtr operand );

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using LogNotPtr = std::unique_ptr< LogNot >;

	inline LogNotPtr makeLogNot( type::TypesCache & cache
		, ExprPtr operand )
	{
		return std::make_unique< LogNot >( cache.getBool()
			, std::move( operand ) );
	}
}

#endif
