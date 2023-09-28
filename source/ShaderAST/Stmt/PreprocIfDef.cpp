/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/PreprocIfDef.hpp"

#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Stmt/StmtVisitor.hpp"

#include <stdexcept>

namespace ast::stmt
{
	PreprocIfDef::PreprocIfDef( StmtCache & stmtCache
		, expr::IdentifierPtr identExpr )
		: Container{ stmtCache, sizeof( PreprocIfDef ), Kind::ePreprocIfDef }
		, m_identExpr{ std::move( identExpr ) }
	{
	}

	PreprocElse * PreprocIfDef::createElse()
	{
		if ( m_else )
		{
			throw std::runtime_error{ "Else is already defined for this IfDef." };
		}

		m_else = getStmtCache().makePreprocElse();
		return m_else.get();
	}

	PreprocElif * PreprocIfDef::createElif( expr::ExprPtr ctrlExpr )
	{
		m_elifs.emplace_back( getStmtCache().makePreprocElif( std::move( ctrlExpr ) ) );
		return static_cast< PreprocElif * >( m_elifs.back().get() );
	}

	void PreprocIfDef::accept( VisitorPtr vis )
	{
		vis->visitPreprocIfDef( this );
	}
}
