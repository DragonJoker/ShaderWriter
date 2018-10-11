/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtSamplerDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	SamplerDecl::SamplerDecl( var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ Kind::eSamplerDecl }
		, m_variable{ std::move( variable ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
	}

	void SamplerDecl::accept( VisitorPtr vis )
	{
		vis->visitSamplerDeclStmt( this );
	}
}
