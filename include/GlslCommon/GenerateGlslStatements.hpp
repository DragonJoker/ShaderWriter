/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GenerateGlslStatements_H___
#define ___SDW_GenerateGlslStatements_H___
#pragma once

#include "GlslStatementsHelpers.hpp"

#include <map>
#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <sstream>
#pragma warning( pop )

namespace glsl
{
	SDWGLC_API Statements generateGlslStatements( StmtConfig const & config
		, IntrinsicsConfig const & intrinsics
		, ast::stmt::Container const & stmt
		, bool withExprColumns = false );
	SDWGLC_API std::string getExprName( StmtConfig const & config
		, ast::expr::Expr const & expr );
}

#endif
