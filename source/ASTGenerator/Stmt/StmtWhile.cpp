/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtWhile.hpp"

namespace ast
{
	StmtWhile::StmtWhile( ExprPtr ctrlExpr )
		: StmtCompound{ Kind::eWhile }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}
}
