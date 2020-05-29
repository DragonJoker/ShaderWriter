/*
See LICENSE file in root folder
*/
#ifndef ___AST_DebugCommon_H___
#define ___AST_DebugCommon_H___
#pragma once

#include "ShaderAST/Expr/Expr.hpp"
#include "ShaderAST/Stmt/PreprocExtension.hpp"
#include "ShaderAST/Stmt/StmtInOutVariableDecl.hpp"
#include "ShaderAST/Stmt/StmtInputGeometryLayout.hpp"
#include "ShaderAST/Stmt/StmtOutputGeometryLayout.hpp"
#include "ShaderAST/Type/Type.hpp"
#include "ShaderAST/Type/ImageConfiguration.hpp"

#include <stdexcept>

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
	std::string getName( type::ImageFormat format
		, type::AccessKind access
		, type::ImageDim dim
		, bool arrayed
		, bool depth
		, bool ms );
	std::string getName( FragmentOrigin value );
	std::string getName( FragmentCenter value );
	std::string displayVar( var::VariablePtr var );
}

#endif
