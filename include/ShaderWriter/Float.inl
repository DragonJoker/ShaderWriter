/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Expr/ExprAssign.hpp>
#include <ASTGenerator/Stmt/StmtSimple.hpp>

namespace sdw
{
	template< typename T >
	Float & Float::operator=( T const & rhs )
	{
		updateContainer( rhs );
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getFloat()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
}
