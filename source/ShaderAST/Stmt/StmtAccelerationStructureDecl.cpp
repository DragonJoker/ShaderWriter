/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtAccelerationStructureDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	AccelerationStructureDecl::AccelerationStructureDecl( StmtCache & stmtCache
		, var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ stmtCache, sizeof( AccelerationStructureDecl ), Kind::eAccelerationStructureDecl }
		, m_variable{ std::move( variable ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
	}

	void AccelerationStructureDecl::accept( VisitorPtr vis )const
	{
		vis->visitAccelerationStructureDeclStmt( this );
	}
}
