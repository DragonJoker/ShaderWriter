/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprTextureAccessCall.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	TextureAccessCall::TextureAccessCall( type::TypePtr type
		, TextureAccess textureAccess
		, ExprList && argList )
		: Expr{ getExprTypesCache( argList ), std::move( type ), Kind::eTextureAccessCall }
		, m_textureAccess{ textureAccess }
		, m_argList{ std::move( argList ) }
	{
	}

	void TextureAccessCall::accept( VisitorPtr vis )
	{
		vis->visitTextureAccessCallExpr( this );
	}
}
