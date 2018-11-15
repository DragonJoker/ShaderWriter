/*
See LICENSE file in root folder
*/
#ifndef ___AST_DebugCommon_H___
#define ___AST_DebugCommon_H___
#pragma once

#include "ASTGenerator/Expr/Expr.hpp"
#include "ASTGenerator/Stmt/PreprocExtension.hpp"
#include "ASTGenerator/Stmt/StmtInOutVariableDecl.hpp"
#include "ASTGenerator/Stmt/StmtInputGeometryLayout.hpp"
#include "ASTGenerator/Stmt/StmtOutputGeometryLayout.hpp"
#include "ASTGenerator/Type/Type.hpp"
#include "ASTGenerator/Type/ImageConfiguration.hpp"

namespace ast::debug
{
	std::string getName( type::Type const & type );
	std::string getName( type::TypePtr type );
	std::string getName( type::Kind type );
	std::string getName( type::Kind type
		, uint32_t arraySize );
	std::string getName( type::ImageFormat value );
	std::string getName( type::ImageFormat format
		, type::ImageDim dim
		, bool arrayed
		, bool depth
		, bool ms );
	std::string displayVar( var::VariablePtr var );
}

#endif
