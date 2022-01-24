/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtPerPrimitiveDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PerPrimitiveDecl::PerPrimitiveDecl( type::TypePtr type )
		: Stmt{ Kind::ePerPrimitiveDecl }
		, m_type{ type }
	{
	}

	void PerPrimitiveDecl::accept( VisitorPtr vis )
	{
		vis->visitPerPrimitiveDeclStmt( this );
	}
}
