/*
See LICENSE file in root folder
*/
#ifndef ___Writer_GetExprName_H___
#define ___Writer_GetExprName_H___
#pragma once

#include <ASTGenerator/Expr/Expr.hpp>

namespace sdw
{
	std::string findName( ast::expr::Expr * expr );
	std::string findName( ast::expr::ExprPtr const & expr );
}

#endif
