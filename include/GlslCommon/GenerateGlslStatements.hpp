/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GenerateGlslStatements_H___
#define ___SDW_GenerateGlslStatements_H___
#pragma once

#include "GlslStatementsHelpers.hpp"

#include <map>

namespace glsl
{
	SDWGLC_API Statements generateGlslStatements( StmtConfig const & config
		, ast::stmt::Container * stmt );
	SDWGLC_API Statements generateGlslStatements( StmtConfig const & config
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
		, ast::stmt::Container * stmt );
}

#endif
