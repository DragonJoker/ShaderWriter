/*
See LICENSE file in root folder
*/
#ifndef ___AST_DebugCommon_H___
#define ___AST_DebugCommon_H___
#pragma once

#include "ASTGenerator/Expr/Expr.hpp"
#include "ASTGenerator/Stmt/PreprocExtension.hpp"
#include "ASTGenerator/Stmt/StmtInOutVariableDecl.hpp"
#include "ASTGenerator/Type/Type.hpp"

namespace ast::debug
{
	std::string getName( type::TypePtr type );
	std::string getName( type::Kind type );
	std::string getDirectionName( var::Variable const & var );
	std::string getStatusName( stmt::PreprocExtension::Status status );
	std::string getOperatorName( expr::Kind kind );
	bool isUnaryPre( expr::Kind kind );
}

#endif
