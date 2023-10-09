/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvStmtVisitor_H___
#define ___SDW_SpirvStmtVisitor_H___
#pragma once

#include "CompilerSpirV/compileSpirV.hpp"
#include "CompilerSpirV/SpirvBlock.hpp"
#include "CompilerSpirV/SpirvCountActions.hpp"
#include "CompilerSpirV/SpirvHelpers.hpp"

#include <GlslCommon/GlslStatementsHelpers.hpp>

namespace spirv
{
	ModulePtr generateModule( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::stmt::Stmt * stmt
		, ast::ShaderStage type
		, ModuleConfig const & moduleConfig
		, spirv::PreprocContext context
		, SpirVConfig & spirvConfig
		, ShaderActions actions
		, glsl::Statements debugStatements );
	ValueId generateModuleExpr( ast::expr::ExprCache & exprCache
		, ast::expr::Expr * expr
		, PreprocContext const & context
		, Block & currentBlock
		, Module & module );
}

#endif
