/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtIf.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	If::If( expr::ExprPtr ctrlExpr )
		: Compound{ Kind::eIf }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	Else * If::createElse()
	{
		if ( m_else )
		{
			throw std::runtime_error{ "Else is already defined for this If." };
		}

		m_else.reset( new Else );
		return m_else.get();
	}

	ElseIf * If::createElseIf( expr::ExprPtr ctrlExpr )
	{
		m_elseIfs.emplace_back( std::unique_ptr< ElseIf >( new ElseIf{ std::move( ctrlExpr ) } ) );
		return static_cast< ElseIf * >( m_elseIfs.back().get() );
	}

	void If::accept( VisitorPtr vis )
	{
		vis->visitIfStmt( this );
	}
}
