/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtStructureDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	StructureDecl::StructureDecl( StmtCache & stmtCache
		, type::StructPtr type )
		: Stmt{ stmtCache, sizeof( StructureDecl ), Kind::eStructureDecl }
		, m_type{ std::move( type ) }
	{
	}

	void StructureDecl::accept( VisitorPtr vis )const
	{
		vis->visitStructureDeclStmt( this );
	}
}
