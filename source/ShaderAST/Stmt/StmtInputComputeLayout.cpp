/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInputComputeLayout.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InputComputeLayout::InputComputeLayout( uint32_t workGroupsX
		, uint32_t workGroupsY
		, uint32_t workGroupsZ )
		: Stmt{ Kind::eInputComputeLayout }
		, m_workGroupsX{ workGroupsX }
		, m_workGroupsY{ workGroupsY }
		, m_workGroupsZ{ workGroupsZ }
	{
	}

	void InputComputeLayout::accept( VisitorPtr vis )
	{
		vis->visitInputComputeLayoutStmt( this );
	}
}
