/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtStructureDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtStructureDecl::StmtStructureDecl( std::string name )
		: StmtCompound{ Kind::eStructureDecl }
		, m_name{ std::move( name ) }
	{
	}

	void StmtStructureDecl::add( StmtVariableDeclPtr decl )
	{
		addStmt( std::move( decl ) );
	}

	void StmtStructureDecl::accept( StmtVisitorPtr vis )
	{
		vis->visitStructureDeclStmt( this );
	}
}
