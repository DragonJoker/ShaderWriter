/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Expr/ExprAssign.hpp>
#include <ASTGenerator/Stmt/StmtSimple.hpp>

namespace sdw
{
	template< typename T >
	UInt & UInt::operator=( T const & rhs )
	{
		updateContainer( rhs );
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}
}
