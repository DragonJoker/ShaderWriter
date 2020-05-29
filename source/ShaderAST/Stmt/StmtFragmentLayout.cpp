/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtFragmentLayout.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	FragmentLayout::FragmentLayout( FragmentOrigin origin
		, FragmentCenter center )
		: Stmt{ Kind::eFragmentLayout }
		, m_origin{ origin }
		, m_center{ center }
	{
	}

	void FragmentLayout::accept( VisitorPtr vis )
	{
		vis->visitFragmentLayout( this );
	}
}
