/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprStorageImageAccessCall.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	StorageImageAccessCall::StorageImageAccessCall( ExprCache & exprCache
		, type::TypePtr type
		, StorageImageAccess imageAccess
		, ExprList argList )
		: Expr{ exprCache
			, sizeof( StorageImageAccessCall )
			, getExprTypesCache( argList )
			, std::move( type )
			, Kind::eImageAccessCall
			, Flag::eNone }
		, m_imageAccess{ imageAccess }
		, m_argList{ std::move( argList ) }
	{
	}

	void StorageImageAccessCall::accept( VisitorPtr vis )const
	{
		vis->visitImageAccessCallExpr( this );
	}
}
