/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StmtSpecialiser_H___
#define ___SDW_StmtSpecialiser_H___
#pragma once

#include "ASTGenerator/Visitors/CloneStmt.hpp"

#include <map>

namespace ast
{
	class StmtSpecialiser
		: public StmtCloner
	{
	public:
		static stmt::ContainerPtr submit( stmt::Container * container
			, SpecialisationInfo const & specialisation );

	private:
		StmtSpecialiser( stmt::ContainerPtr & result
			, SpecialisationInfo const & specialisation );

		expr::ExprPtr doSubmit( expr::Expr * expr )override;

		void visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )override;

	private:
		SpecialisationInfo const & m_specialisation;
		std::map< var::VariablePtr, expr::LiteralPtr > m_specialisations;
	};
}

#endif
