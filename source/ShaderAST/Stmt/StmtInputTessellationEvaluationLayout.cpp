/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInputTessellationEvaluationLayout.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InputTessellationEvaluationLayout::InputTessellationEvaluationLayout( type::TypePtr type
		, type::PatchDomain domain
		, type::Partitioning partitioning
		, type::PrimitiveOrdering order )
		: Stmt{ Kind::eInputTessellationEvaluationLayout }
		, m_type{ std::move( type ) }
		, m_domain{ domain }
		, m_partitioning{ partitioning }
		, m_order{ order }
	{
	}

	void InputTessellationEvaluationLayout::accept( VisitorPtr vis )
	{
		vis->visitInputTessellationEvaluationLayoutStmt( this );
	}
}
