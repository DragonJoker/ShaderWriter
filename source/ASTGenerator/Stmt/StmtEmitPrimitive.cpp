/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtEmitPrimitive.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	EmitPrimitive::EmitPrimitive()
		: Stmt{ Kind::eEmitPrimitive }
	{
	}

	void EmitPrimitive::accept( VisitorPtr vis )
	{
		vis->visitEmitPrimitiveStmt( this );
	}
}
