/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtSampledImageDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	SampledImageDecl::SampledImageDecl( var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ Kind::eSampledImageDecl }
		, m_variable{ std::move( variable ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
	}

	void SampledImageDecl::accept( VisitorPtr vis )
	{
		vis->visitSampledImageDeclStmt( this );
	}
}
