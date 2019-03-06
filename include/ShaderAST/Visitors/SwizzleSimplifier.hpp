/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SwizzleSimplifier_H___
#define ___SDW_SwizzleSimplifier_H___
#pragma once

#include "ShaderAST/Visitors/CloneStmt.hpp"

namespace ast
{
	class SwizzleSimplifier
		: public StmtCloner
	{
	public:
		static stmt::ContainerPtr submit( type::TypesCache & cache
			, stmt::Container * stmt );

	private:
		SwizzleSimplifier( type::TypesCache & cache
			, stmt::ContainerPtr & result );

		expr::ExprPtr doSubmit( expr::Expr * expr )override;

	private:
		type::TypesCache & m_cache;
	};
}

#endif
