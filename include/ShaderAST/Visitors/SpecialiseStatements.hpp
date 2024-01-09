/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpecialiseStatements_H___
#define ___SDW_SpecialiseStatements_H___
#pragma once

#include "ShaderAST/Stmt/Stmt.hpp"

namespace ast
{
	SDAST_API stmt::ContainerPtr specialiseStatements( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container const & container
		, SpecialisationInfo const & specialisation );
}

#endif
