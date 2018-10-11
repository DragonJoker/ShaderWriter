/*
See LICENSE file in root folder
*/
#ifndef ___AST_Prerequisites_H___
#define ___AST_Prerequisites_H___
#pragma once

#include <cassert>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace ast
{
	namespace expr
	{
		class Expr;
		class Visitor;
		using ExprPtr = std::unique_ptr< Expr >;
		using VisitorPtr = Visitor * ;
	}
	namespace stmt
	{
		class Stmt;
		class Visitor;
		using StmtPtr = std::unique_ptr< Stmt >;
		using VisitorPtr = Visitor * ;
	}
	namespace var
	{
		class Variable;
		using VariablePtr = std::shared_ptr< Variable >;
	}
	namespace type
	{
		class Type;
		using TypePtr = std::shared_ptr< Type >;
	}
}

#endif
