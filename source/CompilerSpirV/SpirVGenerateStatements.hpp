/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvStmtVisitor_H___
#define ___SDW_SpirvStmtVisitor_H___
#pragma once

#include "CompilerSpirV/compileSpirV.hpp"
#include "CompilerSpirV/SpirVBlock.hpp"
#include "CompilerSpirV/SpirVCountActions.hpp"
#include "CompilerSpirV/SpirVHelpers.hpp"

#include <GlslCommon/GlslStatementsHelpers.hpp>

namespace spirv
{
	ModulePtr generateModule( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::stmt::Stmt const & stmt
		, ast::ShaderStage type
		, ModuleConfig const & moduleConfig
		, spirv::PreprocContext context
		, SpirVConfig const & spirvConfig
		, glsl::StmtConfig const & stmtConfig
		, ShaderActions actions
		, glsl::Statements debugStatements );
	DebugId generateModuleExpr( ast::expr::ExprCache & exprCache
		, ast::expr::Expr const & expr
		, PreprocContext const & context
		, Block & currentBlock
		, Module & shaderModule );
}

#endif
