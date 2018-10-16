/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtInputGeometryLayout.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InputGeometryLayout::InputGeometryLayout( InputLayout layout )
		: Stmt{ Kind::eInputGeometryLayout }
		, m_layout{ layout }
	{
	}

	void InputGeometryLayout::accept( VisitorPtr vis )
	{
		vis->visitInputGeometryLayoutStmt( this );
	}
}
