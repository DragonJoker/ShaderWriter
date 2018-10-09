/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtIf.hpp"

namespace ast
{
	StmtIf::StmtIf( ExprPtr ctrlExpr )
		: StmtCompound{ Kind::eIf }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}
}
