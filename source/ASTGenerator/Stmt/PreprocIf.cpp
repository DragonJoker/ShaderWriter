/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocIf.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocIf::PreprocIf( expr::ExprPtr ctrlExpr )
		: Container{ Kind::ePreprocIf }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	PreprocElse * PreprocIf::createElse()
	{
		if ( m_else )
		{
			throw std::runtime_error{ "Else is already defined for this If." };
		}

		m_else.reset( new PreprocElse );
		return m_else.get();
	}

	PreprocElif * PreprocIf::createElif( expr::ExprPtr ctrlExpr )
	{
		m_elifs.emplace_back( std::unique_ptr< PreprocElif >( new PreprocElif{ std::move( ctrlExpr ) } ) );
		return static_cast< PreprocElif * >( m_elifs.back().get() );
	}

	void PreprocIf::accept( VisitorPtr vis )
	{
		vis->visitPreprocIf( this );
	}
}
