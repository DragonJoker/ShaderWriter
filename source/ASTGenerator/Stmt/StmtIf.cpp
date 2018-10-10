/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtIf.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtIf::StmtIf( ExprPtr ctrlExpr )
		: StmtCompound{ Kind::eIf }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	StmtElse * StmtIf::createElse()
	{
		if ( m_else )
		{
			throw std::runtime_error{ "StmtElse is already defined for this StmtIf." };
		}

		m_else = makeElseStmt( *this );
		return m_else.get();
	}

	StmtElseIf * StmtIf::createElseIf( ExprPtr ctrlExpr )
	{
		m_elseIfs.emplace_back( makeElseIfStmt( *this, std::move( ctrlExpr ) ) );
		return static_cast< StmtElseIf * >( m_elseIfs.back().get() );
	}

	void StmtIf::accept( StmtVisitorPtr vis )
	{
		vis->visitIfStmt( this );
	}
}
