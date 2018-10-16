/*
See LICENSE file in root folder
*/
#ifndef ___Writer_CloneExpr_H___
#define ___Writer_CloneExpr_H___
#pragma once

#include <ASTGenerator/Expr/Expr.hpp>

namespace sdw
{
	ast::expr::ExprPtr makeExpr( ast::expr::Expr * expr );
	ast::expr::ExprPtr makeExpr( ast::expr::ExprPtr const & expr );
}

#endif
