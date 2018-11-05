/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocIfDef.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocIfDef::PreprocIfDef( expr::IdentifierPtr identExpr )
		: Container{ Kind::ePreprocIfDef }
		, m_identExpr{ std::move( identExpr ) }
	{
	}

	PreprocElse * PreprocIfDef::createElse()
	{
		if ( m_else )
		{
			throw std::runtime_error{ "Else is already defined for this IfDef." };
		}

		m_else.reset( new PreprocElse );
		return m_else.get();
	}

	PreprocElif * PreprocIfDef::createElif( expr::ExprPtr ctrlExpr )
	{
		m_elifs.emplace_back( std::unique_ptr< PreprocElif >( new PreprocElif{ std::move( ctrlExpr ) } ) );
		return static_cast< PreprocElif * >( m_elifs.back().get() );
	}

	void PreprocIfDef::accept( VisitorPtr vis )
	{
		vis->visitPreprocIfDef( this );
	}
}
