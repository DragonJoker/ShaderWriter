/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtDoWhile.hpp"

namespace ast
{
	StmtDoWhile::StmtDoWhile( ExprPtr ctrlExpr )
		: StmtCompound{ Kind::eDoWhile }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}
}
