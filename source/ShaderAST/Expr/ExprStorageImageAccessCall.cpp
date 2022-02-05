/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprStorageImageAccessCall.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	ImageAccessCall::ImageAccessCall( type::TypePtr type
		, StorageImageAccess imageAccess
		, ExprList && argList )
		: Expr{ getExprTypesCache( argList ), std::move( type ), Kind::eImageAccessCall, Flag::eNone }
		, m_imageAccess{ imageAccess }
		, m_argList{ std::move( argList ) }
	{
	}

	void ImageAccessCall::accept( VisitorPtr vis )
	{
		vis->visitImageAccessCallExpr( this );
	}
}
