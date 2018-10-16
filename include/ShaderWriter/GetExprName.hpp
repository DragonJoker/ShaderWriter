/*
See LICENSE file in root folder
*/
#ifndef ___Writer_GetExprName_H___
#define ___Writer_GetExprName_H___
#pragma once

#include <ASTGenerator/Expr/ExprIdentifier.hpp>

namespace sdw
{
	ast::expr::Identifier * findIdentifier( ast::expr::Expr * expr );
	ast::expr::Identifier * findIdentifier( ast::expr::ExprPtr const & expr );
	std::string findName( ast::expr::Expr * expr );
	std::string findName( ast::expr::ExprPtr const & expr );
}

#endif
