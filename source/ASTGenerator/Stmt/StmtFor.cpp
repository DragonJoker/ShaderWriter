/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtFor.hpp"

namespace ast
{
	StmtFor::StmtFor( ExprPtr initExpr
		, ExprPtr ctrlExpr
		, ExprPtr incrExpr )
		: StmtCompound{ Kind::eFor }
		, m_initExpr{ std::move( initExpr ) }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
		, m_incrExpr{ std::move( incrExpr ) }
	{
	}
}
