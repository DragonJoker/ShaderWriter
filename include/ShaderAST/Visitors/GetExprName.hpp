/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GetExprName_H___
#define ___SDW_GetExprName_H___
#pragma once

#include "ShaderAST/Expr/ExprIdentifier.hpp"

namespace ast
{
	expr::Identifier * findIdentifier( expr::Expr * expr );
	expr::Identifier * findIdentifier( expr::ExprPtr const & expr );
	std::string findName( expr::Expr * expr );
	std::string findName( expr::ExprPtr const & expr );
}

#endif
