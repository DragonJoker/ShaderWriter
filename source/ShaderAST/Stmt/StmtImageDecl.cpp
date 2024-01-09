/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtImageDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ImageDecl::ImageDecl( StmtCache & stmtCache
		, var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ stmtCache, sizeof( ImageDecl ), Kind::eImageDecl }
		, m_variable{ std::move( variable ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
	}

	void ImageDecl::accept( VisitorPtr vis )const
	{
		vis->visitImageDeclStmt( this );
	}
}
