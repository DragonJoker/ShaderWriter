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
	class Expr;
	class Stmt;
	class Variable;
	class Type;
	class ExprVisitor;
	class StmtVisitor;
	class TypeVisitor;

	using ExprPtr = std::unique_ptr< Expr >;
	using StmtPtr = std::unique_ptr< Stmt >;
	using TypePtr = std::shared_ptr< Type >;
	using VariablePtr = std::shared_ptr< Variable >;
	using ExprVisitorPtr = ExprVisitor *;
	using StmtVisitorPtr = StmtVisitor *;
	using TypeVisitorPtr = TypeVisitor *;
}

#endif
