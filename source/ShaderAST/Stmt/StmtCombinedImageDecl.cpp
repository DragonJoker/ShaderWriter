/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtCombinedImageDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	CombinedImageDecl::CombinedImageDecl( StmtCache & stmtCache
		, var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ stmtCache, sizeof( CombinedImageDecl ), Kind::eCombinedImageDecl }
		, m_variable{ std::move( variable ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
	}

	void CombinedImageDecl::accept( VisitorPtr vis )const
	{
		vis->visitCombinedImageDeclStmt( this );
	}
}
