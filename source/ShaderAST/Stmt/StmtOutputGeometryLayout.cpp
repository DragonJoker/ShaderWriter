/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtOutputGeometryLayout.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	OutputGeometryLayout::OutputGeometryLayout( type::TypePtr type
		, type::OutputLayout layout
		, uint32_t primCount )
		: Stmt{ Kind::eOutputGeometryLayout }
		, m_type{ std::move( type ) }
		, m_layout{ layout }
		, m_primCount{ primCount }
	{
	}

	void OutputGeometryLayout::accept( VisitorPtr vis )
	{
		vis->visitOutputGeometryLayoutStmt( this );
	}
}
