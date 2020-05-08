/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StmtSimplifier_H___
#define ___SDW_StmtSimplifier_H___
#pragma once

#include "ShaderAST/Visitors/CloneStmt.hpp"

namespace ast
{
	class StmtSimplifier
		: public StmtCloner
	{
	public:
		static stmt::ContainerPtr submit( type::TypesCache & cache
			, stmt::Container * stmt );

	private:
		static stmt::ContainerPtr submit( type::TypesCache & cache
			, stmt::Container * stmt
			, std::map< var::VariablePtr, expr::Literal * > & literalVars );
		
	private:
		StmtSimplifier( type::TypesCache & cache
			, std::map< var::VariablePtr, expr::Literal * > & literalVars
			, stmt::ContainerPtr & result );

		expr::ExprPtr doSubmit( expr::Expr * expr )override;

	private:
		type::TypesCache & m_cache;
		std::map< var::VariablePtr, expr::Literal * > & m_literalVars;
	};
}

#endif
