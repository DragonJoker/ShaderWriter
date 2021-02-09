/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GetExprName_H___
#define ___SDW_GetExprName_H___
#pragma once

#include "ShaderAST/Expr/ExprIdentifier.hpp"

namespace ast
{
	SDAST_API std::vector< expr::Identifier * > listCommaIdentifiers( expr::Expr * expr );
	SDAST_API std::vector< expr::Identifier * > listIdentifiers( expr::Expr * expr
		, type::Kind kind = type::Kind::eUndefined
		, var::Flag flag = var::Flag::eNone );
	SDAST_API std::vector< expr::Identifier * > listIdentifiers( expr::ExprPtr const & expr
		, type::Kind kind = type::Kind::eUndefined
		, var::Flag flag = var::Flag::eNone );
	SDAST_API expr::Identifier * findIdentifier( expr::Expr * expr
		, type::Kind kind = type::Kind::eUndefined
		, var::Flag flag = var::Flag::eNone );
	SDAST_API expr::Identifier * findIdentifier( expr::ExprPtr const & expr
		, type::Kind kind = type::Kind::eUndefined
		, var::Flag flag = var::Flag::eNone );
	SDAST_API std::string findName( expr::Expr * expr
		, type::Kind kind = type::Kind::eUndefined
		, var::Flag flag = var::Flag::eNone );
	SDAST_API std::string findName( expr::ExprPtr const & expr
		, type::Kind kind = type::Kind::eUndefined
		, var::Flag flag = var::Flag::eNone );
}

#endif
