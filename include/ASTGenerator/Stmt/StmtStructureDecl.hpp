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
		StmtStructureDecl( std::string name );
		void add( StmtVariableDeclPtr decl );

		void accept( StmtVisitorPtr vis )override;

		inline std::string const & getName()const
		{
			return m_name;
		}

	private:
		using StmtCompound::addStmt;

	private:
		std::string m_name;
	};

	inline std::unique_ptr< StmtStructureDecl > makeStructureDeclStmt( std::string name )
	{
		return std::make_unique< StmtStructureDecl >( std::move( name ) );
	}
}

#endif
