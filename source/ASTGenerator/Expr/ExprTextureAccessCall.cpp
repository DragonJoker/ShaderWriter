/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprTextureAccessCall.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	TextureAccessCall::TextureAccessCall( type::TypePtr type
		, TextureAccess textureAccess
		, ExprList && argList )
		: Expr{ std::move( type ), Kind::eTextureAccessCall }
		, m_textureAccess{ textureAccess }
		, m_argList{ std::move( argList ) }
	{
	}

	void TextureAccessCall::accept( VisitorPtr vis )
	{
		vis->visitTextureAccessCallExpr( this );
	}
}
