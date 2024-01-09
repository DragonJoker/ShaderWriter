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

		bool hasIdentifier()const noexcept
		{
			return getLHS() != nullptr;
		}

		Identifier const & getIdentifier()const noexcept
		{
			assert( hasIdentifier() );
			return *static_cast< Identifier const * >( Binary::getLHS() );
		}

		Expr const * getAliasedExpr()const noexcept
		{
			return Binary::getRHS();
		}

		SDAST_API void accept( VisitorPtr vis )const override;

	private:
		using Binary::getLHS;
		using Binary::getRHS;
	};
}

#endif
