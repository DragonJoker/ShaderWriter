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
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( type::getUInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
}
