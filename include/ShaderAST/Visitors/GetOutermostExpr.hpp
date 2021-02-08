/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GetOutermostExpr_H___
#define ___SDW_GetOutermostExpr_H___
#pragma once

#include "ShaderAST/Expr/Expr.hpp"

namespace ast
{
	SDAST_API expr::Expr * getOutermostExpr( expr::Expr * expr );
	SDAST_API expr::Expr * getOutermostExpr( expr::ExprPtr const & expr );
}

#endif
