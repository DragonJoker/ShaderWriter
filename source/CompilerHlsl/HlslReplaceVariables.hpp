/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslReplaceVariables_H___
#define ___AST_HlslReplaceVariables_H___
#pragma once

#include "HlslHelpers.hpp"

namespace hlsl
{
	ast::expr::ExprPtr replaceVariables( ast::expr::ExprCache & exprCache
		, ast::expr::Expr const & expr
		, ast::var::VariablePtr origin
		, ast::var::VariablePtr replacement );
}

#endif
