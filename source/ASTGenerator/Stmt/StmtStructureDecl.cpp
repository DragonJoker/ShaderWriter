/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtStructureDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	StructureDecl::StructureDecl( type::StructPtr type )
		: Stmt{ Kind::eStructureDecl }
		, m_type{ std::move( type ) }
	{
	}

	void StructureDecl::accept( VisitorPtr vis )
	{
		vis->visitStructureDeclStmt( this );
	}
}
