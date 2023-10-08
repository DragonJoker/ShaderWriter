/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslGenerateStatements_H___
#define ___SDW_HlslGenerateStatements_H___
#pragma once

#include "HlslHelpers.hpp"

namespace hlsl
{
	std::string generateStatements( HlslConfig const & writerConfig
		, RoutineMap const & routines
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
		, ast::stmt::Stmt * stmt
		, std::string indent = std::string{} );
}

#endif
