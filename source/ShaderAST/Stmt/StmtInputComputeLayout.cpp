/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInputComputeLayout.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InputComputeLayout::InputComputeLayout( StmtCache & stmtCache
		, type::TypePtr type
		, uint32_t workGroupsX
		, uint32_t workGroupsY
		, uint32_t workGroupsZ )
		: Stmt{ stmtCache, sizeof( InputComputeLayout ), Kind::eInputComputeLayout }
		, m_type{ type }
		, m_workGroupsX{ workGroupsX }
		, m_workGroupsY{ workGroupsY }
		, m_workGroupsZ{ workGroupsZ }
	{
	}

	void InputComputeLayout::accept( VisitorPtr vis )const
	{
		vis->visitInputComputeLayoutStmt( this );
	}
}
