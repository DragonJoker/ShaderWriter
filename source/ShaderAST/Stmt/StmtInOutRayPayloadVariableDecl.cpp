/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInOutRayPayloadVariableDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InOutRayPayloadVariableDecl::InOutRayPayloadVariableDecl( StmtCache & stmtCache
		, var::VariablePtr variable
		, uint32_t location )
		: Stmt{ stmtCache, sizeof( InOutRayPayloadVariableDecl ), Kind::eInOutRayPayloadVariableDecl }
		, m_variable{ std::move( variable ) }
		, m_location{ location }
	{
	}

	void InOutRayPayloadVariableDecl::accept( VisitorPtr vis )const
	{
		vis->visitInOutRayPayloadVariableDeclStmt( this );
	}
}
