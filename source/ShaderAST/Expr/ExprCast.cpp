/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprCast.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Cast::Cast( type::TypePtr dstType
		, ExprPtr operand )
		: Unary{ std::move( dstType )
			, std::move( operand )
			, Kind::eCast }
	{
	}

	void Cast::accept( VisitorPtr vis )
	{
		vis->visitCastExpr( this );
	}

	Expr const * removeCasts( Expr const & expr )
	{
		auto result = &expr;

		while ( result->getKind() == Kind::eCast )
		{
			result = static_cast< Cast const & >( *result ).getOperand();
		}

		return result;
	}
}
