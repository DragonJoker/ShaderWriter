/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAlias_H___
#define ___AST_ExprAlias_H___
#pragma once

#include "ExprBinary.hpp"
#include "ExprIdentifier.hpp"

namespace ast::expr
{
	class Alias
		: public Binary
	{
	public:
		SDAST_API Alias( ExprCache & exprCache
			, type::TypePtr type
			, IdentifierPtr lhs
			, ExprPtr rhs );

		Identifier * getLHS()const
		{
			return static_cast< Identifier * >( Binary::getLHS() );
		}

		SDAST_API void accept( VisitorPtr vis )override;
	};
}

#endif
