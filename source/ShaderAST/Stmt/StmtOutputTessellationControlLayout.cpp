/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtOutputTessellationControlLayout.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	OutputTessellationControlLayout::OutputTessellationControlLayout( type::TypePtr type
		, type::PatchDomain domain
		, type::Partitioning partitioning
		, type::OutputTopology topology
		, type::PrimitiveOrdering order
		, uint32_t outputVertices )
		: Stmt{ Kind::eOutputTessellationControlLayout }
		, m_type{ std::move( type ) }
		, m_domain{ domain }
		, m_partitioning{ partitioning }
		, m_topology{ topology }
		, m_order{ order }
		, m_outputVertices{ outputVertices }
	{
	}

	void OutputTessellationControlLayout::accept( VisitorPtr vis )
	{
		vis->visitOutputTessellationControlLayoutStmt( this );
	}
}
