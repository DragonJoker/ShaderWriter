/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtSimple.hpp"

namespace ast
{
	StmtSimple::StmtSimple( ExprPtr expr )
		: Stmt{ Kind::eSimple }
		, m_expr{ std::move( expr ) }
	{
	}
}
