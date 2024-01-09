/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtDispatchMesh.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	DispatchMesh::DispatchMesh( StmtCache & stmtCache
		, expr::ExprPtr numGroupsX
		, expr::ExprPtr numGroupsY
		, expr::ExprPtr numGroupsZ
		, expr::ExprPtr payload )
		: Stmt{ stmtCache, sizeof( DispatchMesh ), Kind::eDispatchMesh }
		, m_numGroupsX{ std::move( numGroupsX ) }
		, m_numGroupsY{ std::move( numGroupsY ) }
		, m_numGroupsZ{ std::move( numGroupsZ ) }
		, m_payload{ std::move( payload ) }
	{
	}

	void DispatchMesh::accept( VisitorPtr vis )const
	{
		vis->visitDispatchMeshStmt( this );
	}
}
