/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtIf.hpp"

#include "ShaderAST/Shader.hpp"
#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	If::If( StmtCache & stmtCache
		, expr::ExprPtr ctrlExpr )
		: Compound{ stmtCache, sizeof( If ), Kind::eIf }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	Else * If::createElse()
	{
		if ( m_else )
		{
			throw Exception{ "Else is already defined for this If." };
		}

		m_else = getStmtCache().makeElse();
		return m_else.get();
	}

	ElseIf * If::createElseIf( expr::ExprPtr ctrlExpr )
	{
		m_elseIfs.emplace_back( getStmtCache().makeElseIf( std::move( ctrlExpr ) ) );
		return m_elseIfs.back().get();
	}

	void If::accept( VisitorPtr vis )const
	{
		vis->visitIfStmt( this );
	}
}
