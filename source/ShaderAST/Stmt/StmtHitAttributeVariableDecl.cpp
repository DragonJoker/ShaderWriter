/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtHitAttributeVariableDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	HitAttributeVariableDecl::HitAttributeVariableDecl( StmtCache & stmtCache
		, var::VariablePtr variable )
		: Stmt{ stmtCache, sizeof( HitAttributeVariableDecl ), Kind::eHitAttributeVariableDecl }
		, m_variable{ std::move( variable ) }
	{
	}

	void HitAttributeVariableDecl::accept( VisitorPtr vis )const
	{
		vis->visitHitAttributeVariableDeclStmt( this );
	}
}
