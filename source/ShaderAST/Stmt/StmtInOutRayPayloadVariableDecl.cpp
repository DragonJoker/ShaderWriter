/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInOutRayPayloadVariableDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InOutRayPayloadVariableDecl::InOutRayPayloadVariableDecl( var::VariablePtr variable
		, uint32_t location )
		: Stmt{ Kind::eInOutRayPayloadVariableDecl }
		, m_variable{ std::move( variable ) }
		, m_location{ location }
	{
	}

	void InOutRayPayloadVariableDecl::accept( VisitorPtr vis )
	{
		vis->visitInOutRayPayloadVariableDeclStmt( this );
	}
}
