/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ResolveConstants_H___
#define ___SDW_ResolveConstants_H___
#pragma once

#include "ShaderAST/ShaderStlTypes.hpp"
#include "ShaderAST/Expr/ExprIntrinsicCall.hpp"
#include "ShaderAST/Expr/ExprList.hpp"

namespace ast
{
	SDAST_API stmt::ContainerPtr resolveConstants( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container const & stmt );
	SDAST_API expr::ExprPtr resolveConstants( expr::ExprCache & exprCache
		, expr::Expr const & expr );
}

#endif
