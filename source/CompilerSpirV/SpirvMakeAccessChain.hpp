/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvMakeAccessChain_H___
#define ___SDW_SpirvMakeAccessChain_H___
#pragma once

#include "CompilerSpirV/SpirvModule.hpp"

#include <ShaderAST/Expr/SwizzleKind.hpp>

namespace spirv
{
	struct PreprocContext;

	ValueId writeShuffle( Module & module
		, Block & currentBlock
		, ValueId typeId
		, ast::type::TypePtr outerType
		, ValueId outerId
		, ast::expr::SwizzleKind swizzle );
	bool isAccessChain( ast::expr::Expr * expr );
	bool isPtrAccessChain( ast::expr::Expr * expr );
	ValueId makeAccessChain( ast::expr::Expr * expr
		, PreprocContext const & context
		, Module & module
		, Block & currentBlock
		, LoadedVariableArray & loadedVariables );
}

#endif
