/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtFragmentLayout.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	FragmentLayout::FragmentLayout( StmtCache & stmtCache
		, type::TypePtr type
		, FragmentOrigin origin
		, FragmentCenter center
		, InvocationOrdering ordering )
		: Stmt{ stmtCache, sizeof( FragmentLayout ), Kind::eFragmentLayout }
		, m_type{ type }
		, m_origin{ origin }
		, m_center{ center }
		, m_ordering{ ordering }
	{
	}

	void FragmentLayout::accept( VisitorPtr vis )const
	{
		vis->visitFragmentLayoutStmt( this );
	}
}
