/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtPerPrimitiveDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PerPrimitiveDecl::PerPrimitiveDecl( StmtCache & stmtCache
		, type::TypePtr type )
		: Stmt{ stmtCache, sizeof( PerPrimitiveDecl ), Kind::ePerPrimitiveDecl }
		, m_type{ type }
	{
	}

	void PerPrimitiveDecl::accept( VisitorPtr vis )const
	{
		vis->visitPerPrimitiveDeclStmt( this );
	}
}
