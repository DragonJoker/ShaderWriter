/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/PreprocIf.hpp"

#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Stmt/StmtVisitor.hpp"

#include <stdexcept>

namespace ast::stmt
{
	PreprocIf::PreprocIf( StmtCache & stmtCache
		, expr::ExprPtr ctrlExpr )
		: Container{ stmtCache, sizeof( PreprocIf ), Kind::ePreprocIf }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	PreprocElse * PreprocIf::createElse()
	{
		if ( m_else )
		{
			throw std::runtime_error{ "Else is already defined for this If." };
		}

		m_else = getStmtCache().makePreprocElse();
		return m_else.get();
	}

	PreprocElif * PreprocIf::createElif( expr::ExprPtr ctrlExpr )
	{
		m_elifs.emplace_back( getStmtCache().makePreprocElif( std::move( ctrlExpr ) ) );
		return static_cast< PreprocElif * >( m_elifs.back().get() );
	}

	void PreprocIf::accept( VisitorPtr vis )
	{
		vis->visitPreprocIf( this );
	}
}
