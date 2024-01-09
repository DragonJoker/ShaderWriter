/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GetExprName_H___
#define ___SDW_GetExprName_H___
#pragma once

#include "ShaderAST/Expr/ExprIdentifier.hpp"

namespace ast
{
	SDAST_API std::vector< expr::Identifier const * > listCommaIdentifiers( expr::Expr const & expr );
	SDAST_API std::vector< expr::Identifier const * > listIdentifiers( expr::Expr const & expr
		, type::Kind kind = type::Kind::eUndefined
		, var::Flag flag = var::Flag::eNone );
	SDAST_API expr::Identifier const * findIdentifier( expr::Expr const & expr
		, type::Kind kind = type::Kind::eUndefined
		, var::Flag flag = var::Flag::eNone );
	SDAST_API std::string findName( expr::Expr const & expr
		, type::Kind kind = type::Kind::eUndefined
		, var::Flag flag = var::Flag::eNone );
}

#endif
