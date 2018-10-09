/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtStructureDecl_H___
#define ___AST_StmtStructureDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "StmtVariableDecl.hpp"

namespace ast
{
	class StmtStructureDecl
		: public StmtCompound
	{
	public:
		StmtStructureDecl( std::string const & name );
		void add( StmtVariableDeclPtr decl );

		inline std::string const & getName()const
		{
			return m_name;
		}

	private:
		using StmtCompound::addStmt;

	private:
		std::string m_name;
	};
}

#endif
