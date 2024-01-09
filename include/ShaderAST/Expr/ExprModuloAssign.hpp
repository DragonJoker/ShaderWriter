/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprModuloAssign_H___
#define ___AST_ExprModuloAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast::expr
{
	class ModuloAssign
		: public Assign
	{
	public:
		SDAST_API ModuloAssign( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr lhs
			, ExprPtr rhs );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
