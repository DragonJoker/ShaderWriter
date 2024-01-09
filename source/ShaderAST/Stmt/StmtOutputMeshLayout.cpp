/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtOutputMeshLayout.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	OutputMeshLayout::OutputMeshLayout( StmtCache & stmtCache
		, type::TypePtr type
		, type::OutputTopology topology
		, uint32_t maxVertices
		, uint32_t maxPrimitives )
		: Stmt{ stmtCache, sizeof( OutputMeshLayout ), Kind::eOutputMeshLayout }
		, m_type{ std::move( type ) }
		, m_topology{ topology }
		, m_maxVertices{ maxVertices }
		, m_maxPrimitives{ maxPrimitives }
	{
	}

	void OutputMeshLayout::accept( VisitorPtr vis )const
	{
		vis->visitOutputMeshLayoutStmt( this );
	}
}
