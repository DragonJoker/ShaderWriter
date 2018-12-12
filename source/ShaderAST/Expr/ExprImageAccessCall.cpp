/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprImageAccessCall.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	ImageAccessCall::ImageAccessCall( type::TypePtr type
		, ImageAccess imageAccess
		, ExprList && argList )
		: Expr{ getExprTypesCache( argList ), std::move( type ), Kind::eImageAccessCall }
		, m_imageAccess{ imageAccess }
		, m_argList{ std::move( argList ) }
	{
	}

	void ImageAccessCall::accept( VisitorPtr vis )
	{
		vis->visitImageAccessCallExpr( this );
	}
}
