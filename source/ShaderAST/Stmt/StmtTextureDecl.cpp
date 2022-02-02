/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtTextureDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	TextureDecl::TextureDecl( var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ Kind::eTextureDecl }
		, m_variable{ std::move( variable ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
	}

	void TextureDecl::accept( VisitorPtr vis )
	{
		vis->visitTextureDeclStmt( this );
	}
}
