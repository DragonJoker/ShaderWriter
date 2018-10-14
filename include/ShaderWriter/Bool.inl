/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Expr/ExprAssign.hpp>
#include <ASTGenerator/Stmt/StmtSimple.hpp>

namespace sdw
{
	template< typename T >
	inline Boolean & Boolean::operator=( T const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( type::getBool()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
}
