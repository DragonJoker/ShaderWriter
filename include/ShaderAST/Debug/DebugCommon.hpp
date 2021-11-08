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
	SDAST_API std::string getName( type::Type const & type );
	SDAST_API std::string getName( type::TypePtr type );
	SDAST_API std::string getName( type::Kind type );
	SDAST_API std::string getName( type::Kind type
		, uint32_t arraySize );
	SDAST_API std::string getName( type::ImageFormat value );
	SDAST_API std::string getName( type::ImageFormat format
		, type::ImageDim dim
		, bool arrayed
		, bool depth
		, bool ms );
	SDAST_API std::string getName( type::ImageFormat format
		, type::AccessKind access
		, type::ImageDim dim
		, bool arrayed
		, bool depth
		, bool ms );
	SDAST_API std::string getName( type::InputLayout value );
	SDAST_API std::string getName( type::OutputLayout value );
	SDAST_API std::string getName( type::PatchDomain value );
	SDAST_API std::string getName( type::OutputPartitioning value );
	SDAST_API std::string getName( type::OutputTopology value );
	SDAST_API std::string getName( type::OutputVertexOrder value );
	SDAST_API std::string getName( FragmentOrigin value );
	SDAST_API std::string getName( FragmentCenter value );
	SDAST_API std::string displayVar( var::Variable const & var );
	SDAST_API std::string displayVar( var::VariablePtr var );
}

#endif
