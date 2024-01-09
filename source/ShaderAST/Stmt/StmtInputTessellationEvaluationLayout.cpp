/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInputTessellationEvaluationLayout.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InputTessellationEvaluationLayout::InputTessellationEvaluationLayout( StmtCache & stmtCache
		, type::TypePtr type
		, type::PatchDomain domain
		, type::Partitioning partitioning
		, type::PrimitiveOrdering order )
		: Stmt{ stmtCache, sizeof( InputTessellationEvaluationLayout ), Kind::eInputTessellationEvaluationLayout }
		, m_type{ std::move( type ) }
		, m_domain{ domain }
		, m_partitioning{ partitioning }
		, m_order{ order }
	{
	}

	void InputTessellationEvaluationLayout::accept( VisitorPtr vis )const
	{
		vis->visitInputTessellationEvaluationLayoutStmt( this );
	}
}
