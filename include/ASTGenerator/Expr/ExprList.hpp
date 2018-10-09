/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprList_H___
#define ___AST_ExprList_H___
#pragma once

#include "Expr.hpp"

#include <vector>

namespace ast
{
	using ExprList = std::vector< ExprPtr >;
}

#endif
