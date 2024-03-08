/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SimplifyStatements_H___
#define ___SDW_SimplifyStatements_H___
#pragma once

#include "ShaderAST/Visitors/CloneStmt.hpp"

namespace ast
{
	SDAST_API expr::ExprList makeList( expr::ExprPtr arg0 );
	SDAST_API expr::ExprList makeList( expr::ExprPtr arg0
		, expr::ExprPtr arg1 );
	SDAST_API expr::ExprList makeList( expr::ExprPtr arg0
		, expr::ExprPtr arg1
		, expr::ExprPtr arg2 );
	SDAST_API expr::ExprList makeList( expr::ExprPtr arg0
		, expr::ExprPtr arg1
		, expr::ExprPtr arg2
		, expr::ExprPtr arg3 );
	SDAST_API bool isMatrixTimesVector( expr::Kind exprKind
		, type::Kind lhsTypeKind
		, type::Kind rhsTypeKind
		, bool & switchParams
		, bool & needMatchingVectors );
	SDAST_API std::vector< expr::SwizzleKind > getSwizzleValues( expr::SwizzleKind swizzle );
	SDAST_API std::vector< uint32_t > getSwizzleIndices( expr::SwizzleKind swizzle );
	SDAST_API expr::SwizzleKind getSwizzleComponents( uint32_t count );
	SDAST_API uint32_t getComponentsCount( expr::CompositeType type );
	SDAST_API expr::CompositeType getCompositeType( uint32_t count );
	SDAST_API expr::ExprPtr makeOne( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::Kind typeKind );
	SDAST_API expr::ExprPtr makeOne( expr::ExprCache & exprCache
		, type::TypePtr type );
	SDAST_API expr::ExprPtr makeZero( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::Kind typeKind );
	SDAST_API expr::ExprPtr makeZero( expr::ExprCache & exprCache
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
