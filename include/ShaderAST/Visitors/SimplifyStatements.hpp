/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SimplifyStatements_H___
#define ___SDW_SimplifyStatements_H___
#pragma once

#include "ShaderAST/Visitors/CloneStmt.hpp"

namespace ast
{
	SDAST_API bool isMatrixTimesVector( expr::Kind exprKind
		, type::Kind lhsTypeKind
		, type::Kind rhsTypeKind
		, bool & switchParams
		, bool & needMatchingVectors );
	SDAST_API std::vector< uint32_t > getSwizzleIndices( expr::SwizzleKind swizzle );
	SDAST_API expr::ExprPtr makeOne( expr::ExprCache & exprCache
		, type::TypePtr type );
	SDAST_API stmt::ContainerPtr simplify( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container const & stmt );
	SDAST_API expr::ExprPtr simplify( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, expr::Expr const & expr );
}

#endif
