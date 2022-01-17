/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtHitAttributeVariableDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	HitAttributeVariableDecl::HitAttributeVariableDecl( var::VariablePtr variable )
		: Stmt{ Kind::eHitAttributeVariableDecl }
		, m_variable{ std::move( variable ) }
	{
	}

	void HitAttributeVariableDecl::accept( VisitorPtr vis )
	{
		vis->visitHitAttributeVariableDeclStmt( this );
	}
}
