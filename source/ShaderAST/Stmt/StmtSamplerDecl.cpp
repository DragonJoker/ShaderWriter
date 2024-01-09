/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtSamplerDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	SamplerDecl::SamplerDecl( StmtCache & stmtCache
		, var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ stmtCache, sizeof( SamplerDecl ), Kind::eSamplerDecl }
		, m_variable{ std::move( variable ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
	}

	void SamplerDecl::accept( VisitorPtr vis )const
	{
		vis->visitSamplerDeclStmt( this );
	}
}
