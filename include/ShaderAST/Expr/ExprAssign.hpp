/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAssign_H___
#define ___AST_ExprAssign_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast::expr
{
	class Assign
		: public Binary
	{
	public:
		SDAST_API Assign( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs
			, Kind kind = Kind::eAssign );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
