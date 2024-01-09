/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInputGeometryLayout.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InputGeometryLayout::InputGeometryLayout( StmtCache & stmtCache
		, type::TypePtr type
		, type::InputLayout layout )
		: Stmt{ stmtCache, sizeof( InputGeometryLayout ), Kind::eInputGeometryLayout }
		, m_type{ std::move( type ) }
		, m_layout{ layout }
	{
	}

	void InputGeometryLayout::accept( VisitorPtr vis )const
	{
		vis->visitInputGeometryLayoutStmt( this );
	}
}
