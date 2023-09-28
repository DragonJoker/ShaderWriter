/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StmtSpecialiser_H___
#define ___SDW_StmtSpecialiser_H___
#pragma once

#include "ShaderAST/Visitors/CloneStmt.hpp"

#include <map>

namespace ast
{
	class StmtSpecialiser
		: public StmtCloner
	{
	public:
		SDAST_API static stmt::ContainerPtr submit( stmt::StmtCache & stmtCache
			, expr::ExprCache & exprCache
			, type::TypesCache & typesCache
			, stmt::Container * container
			, SpecialisationInfo const & specialisation );

	private:
		SDAST_API StmtSpecialiser( stmt::StmtCache & stmtCache
			, expr::ExprCache & exprCache
			, type::TypesCache & typesCache
			, SpecialisationInfo const & specialisation
			, stmt::ContainerPtr & result );

		SDAST_API expr::ExprPtr doSubmit( expr::Expr * expr )override;

		SDAST_API void visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )override;

	private:
		type::TypesCache & m_typesCache;
		SpecialisationInfo const & m_specialisation;
		std::map< var::VariablePtr, expr::LiteralPtr > m_specialisations;
	};
}

#endif
