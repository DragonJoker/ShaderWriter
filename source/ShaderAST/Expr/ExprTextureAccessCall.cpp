/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprTextureAccessCall.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	//*********************************************************************************************

	TextureAccessCall::TextureAccessCall( type::TypePtr type
		, TextureAccess textureAccess
		, ExprList && argList )
		: Expr{ getExprTypesCache( argList ), std::move( type ), Kind::eTextureAccessCall, Flag::eNone }
		, m_textureAccess{ textureAccess }
		, m_argList{ std::move( argList ) }
	{
	}

	void TextureAccessCall::accept( VisitorPtr vis )
	{
		vis->visitTextureAccessCallExpr( this );
	}

	//*********************************************************************************************

	bool isBiasAndOffset( TextureAccess value )
	{
		switch ( value )
		{
		case TextureAccess::eTextureOffset1DFBias:
		case TextureAccess::eTextureOffset2DFBias:
		case TextureAccess::eTextureOffset3DFBias:
		case TextureAccess::eTextureOffset1DArrayFBias:
		case TextureAccess::eTextureOffset2DArrayFBias:
		case TextureAccess::eTextureOffset1DIBias:
		case TextureAccess::eTextureOffset2DIBias:
		case TextureAccess::eTextureOffset3DIBias:
		case TextureAccess::eTextureOffset1DArrayIBias:
		case TextureAccess::eTextureOffset2DArrayIBias:
		case TextureAccess::eTextureOffset1DUBias:
		case TextureAccess::eTextureOffset2DUBias:
		case TextureAccess::eTextureOffset3DUBias:
		case TextureAccess::eTextureOffset1DArrayUBias:
		case TextureAccess::eTextureOffset2DArrayUBias:
		case TextureAccess::eTextureProjOffset1DF2Bias:
		case TextureAccess::eTextureProjOffset1DF4Bias:
		case TextureAccess::eTextureProjOffset2DF3Bias:
		case TextureAccess::eTextureProjOffset2DF4Bias:
		case TextureAccess::eTextureProjOffset3DFBias:
		case TextureAccess::eTextureProjOffset1DI2Bias:
		case TextureAccess::eTextureProjOffset1DI4Bias:
		case TextureAccess::eTextureProjOffset2DI3Bias:
		case TextureAccess::eTextureProjOffset2DI4Bias:
		case TextureAccess::eTextureProjOffset3DIBias:
		case TextureAccess::eTextureProjOffset1DU2Bias:
		case TextureAccess::eTextureProjOffset1DU4Bias:
		case TextureAccess::eTextureProjOffset2DU3Bias:
		case TextureAccess::eTextureProjOffset2DU4Bias:
		case TextureAccess::eTextureProjOffset3DUBias:
			return true;
		default:
			return false;
		}
	}

	bool isProj( ast::expr::TextureAccess value )
	{
		switch ( value )
		{
		case ast::expr::TextureAccess::eTextureProj1DF2:
		case ast::expr::TextureAccess::eTextureProj1DShadowF:
		case ast::expr::TextureAccess::eTextureProj1DI2:
		case ast::expr::TextureAccess::eTextureProj1DU2:
		case ast::expr::TextureAccess::eTextureProj1DF2Bias:
		case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProj1DI2Bias:
		case ast::expr::TextureAccess::eTextureProj1DU2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjOffset1DF2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset1DI2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DU2Bias:
		case ast::expr::TextureAccess::eTextureProjLod1DF2:
		case ast::expr::TextureAccess::eTextureProjLod1DShadowF:
		case ast::expr::TextureAccess::eTextureProjLod1DI2:
		case ast::expr::TextureAccess::eTextureProjLod1DU2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjGrad1DF2:
		case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad1DI2:
		case ast::expr::TextureAccess::eTextureProjGrad1DU2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DU2:
		case ast::expr::TextureAccess::eTextureProj1DF4:
		case ast::expr::TextureAccess::eTextureProj1DI4:
		case ast::expr::TextureAccess::eTextureProj1DU4:
		case ast::expr::TextureAccess::eTextureProj1DF4Bias:
		case ast::expr::TextureAccess::eTextureProj1DI4Bias:
		case ast::expr::TextureAccess::eTextureProj1DU4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DF4:
		case ast::expr::TextureAccess::eTextureProjOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjOffset1DF4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DI4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DU4Bias:
		case ast::expr::TextureAccess::eTextureProjLod1DF4:
		case ast::expr::TextureAccess::eTextureProjLod1DI4:
		case ast::expr::TextureAccess::eTextureProjLod1DU4:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DF4:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjGrad1DF4:
		case ast::expr::TextureAccess::eTextureProjGrad1DI4:
		case ast::expr::TextureAccess::eTextureProjGrad1DU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DU4:
		case ast::expr::TextureAccess::eTextureProj2DF3:
		case ast::expr::TextureAccess::eTextureProj2DShadowF:
		case ast::expr::TextureAccess::eTextureProj2DRectF3:
		case ast::expr::TextureAccess::eTextureProj2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProj2DI3:
		case ast::expr::TextureAccess::eTextureProj2DRectI3:
		case ast::expr::TextureAccess::eTextureProj2DU3:
		case ast::expr::TextureAccess::eTextureProj2DRectU3:
		case ast::expr::TextureAccess::eTextureProj2DF3Bias:
		case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProj2DI3Bias:
		case ast::expr::TextureAccess::eTextureProj2DU3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectF3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectI3:
		case ast::expr::TextureAccess::eTextureProjOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectU3:
		case ast::expr::TextureAccess::eTextureProjOffset2DF3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DI3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DU3Bias:
		case ast::expr::TextureAccess::eTextureProjLod2DF3:
		case ast::expr::TextureAccess::eTextureProjLod2DShadowF:
		case ast::expr::TextureAccess::eTextureProjLod2DI3:
		case ast::expr::TextureAccess::eTextureProjLod2DU3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjGrad2DF3:
		case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectF3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad2DI3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectI3:
		case ast::expr::TextureAccess::eTextureProjGrad2DU3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU3:
		case ast::expr::TextureAccess::eTextureProj2DF4:
		case ast::expr::TextureAccess::eTextureProj2DRectF4:
		case ast::expr::TextureAccess::eTextureProj2DI4:
		case ast::expr::TextureAccess::eTextureProj2DRectI4:
		case ast::expr::TextureAccess::eTextureProj2DU4:
		case ast::expr::TextureAccess::eTextureProj2DRectU4:
		case ast::expr::TextureAccess::eTextureProj2DF4Bias:
		case ast::expr::TextureAccess::eTextureProj2DI4Bias:
		case ast::expr::TextureAccess::eTextureProj2DU4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DF4:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectF4:
		case ast::expr::TextureAccess::eTextureProjOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectI4:
		case ast::expr::TextureAccess::eTextureProjOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectU4:
		case ast::expr::TextureAccess::eTextureProjOffset2DF4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DI4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DU4Bias:
		case ast::expr::TextureAccess::eTextureProjLod2DF4:
		case ast::expr::TextureAccess::eTextureProjLod2DI4:
		case ast::expr::TextureAccess::eTextureProjLod2DU4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DF4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjGrad2DF4:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectF4:
		case ast::expr::TextureAccess::eTextureProjGrad2DI4:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectI4:
		case ast::expr::TextureAccess::eTextureProjGrad2DU4:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU4:
		case ast::expr::TextureAccess::eTextureProj3DF:
		case ast::expr::TextureAccess::eTextureProj3DI:
		case ast::expr::TextureAccess::eTextureProj3DU:
		case ast::expr::TextureAccess::eTextureProj3DFBias:
		case ast::expr::TextureAccess::eTextureProj3DIBias:
		case ast::expr::TextureAccess::eTextureProj3DUBias:
		case ast::expr::TextureAccess::eTextureProjOffset3DF:
		case ast::expr::TextureAccess::eTextureProjOffset3DI:
		case ast::expr::TextureAccess::eTextureProjOffset3DU:
		case ast::expr::TextureAccess::eTextureProjOffset3DFBias:
		case ast::expr::TextureAccess::eTextureProjOffset3DIBias:
		case ast::expr::TextureAccess::eTextureProjOffset3DUBias:
		case ast::expr::TextureAccess::eTextureProjLod3DF:
		case ast::expr::TextureAccess::eTextureProjLod3DI:
		case ast::expr::TextureAccess::eTextureProjLod3DU:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DF:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DI:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DU:
		case ast::expr::TextureAccess::eTextureProjGrad3DF:
		case ast::expr::TextureAccess::eTextureProjGrad3DI:
		case ast::expr::TextureAccess::eTextureProjGrad3DU:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DF:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DI:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DU:
			return true;
		default:
			return false;
		}
	}

	bool isShadow( TextureAccess value )
	{
		switch ( value )
		{
		case TextureAccess::eTexture1DShadowF:
		case TextureAccess::eTexture1DShadowFBias:
		case TextureAccess::eTexture2DShadowF:
		case TextureAccess::eTexture2DShadowFBias:
		case TextureAccess::eTextureCubeShadowF:
		case TextureAccess::eTextureCubeShadowFBias:
		case TextureAccess::eTexture1DArrayShadowF:
		case TextureAccess::eTexture1DArrayShadowFBias:
		case TextureAccess::eTexture2DArrayShadowF:
		case TextureAccess::eTexture2DRectShadowF:
		case TextureAccess::eTextureCubeArrayShadowF:
		case TextureAccess::eTextureProj1DShadowF:
		case TextureAccess::eTextureProj1DShadowFBias:
		case TextureAccess::eTextureProj2DShadowF:
		case TextureAccess::eTextureProj2DShadowFBias:
		case TextureAccess::eTextureProj2DRectShadowF:
		case TextureAccess::eTextureLod1DShadowF:
		case TextureAccess::eTextureLod2DShadowF:
		case TextureAccess::eTextureLod1DArrayShadowF:
		case TextureAccess::eTextureOffset2DRectShadowF:
		case TextureAccess::eTextureOffset1DShadowF:
		case TextureAccess::eTextureOffset1DShadowFBias:
		case TextureAccess::eTextureOffset2DShadowF:
		case TextureAccess::eTextureOffset2DShadowFBias:
		case TextureAccess::eTextureOffset1DArrayShadowF:
		case TextureAccess::eTextureOffset2DArrayShadowF:
		case TextureAccess::eTextureProjOffset1DShadowF:
		case TextureAccess::eTextureProjOffset1DShadowFBias:
		case TextureAccess::eTextureProjOffset2DShadowF:
		case TextureAccess::eTextureProjOffset2DShadowFBias:
		case TextureAccess::eTextureProjOffset2DRectShadowF:
		case TextureAccess::eTextureLodOffset1DShadowF:
		case TextureAccess::eTextureLodOffset2DShadowF:
		case TextureAccess::eTextureLodOffset1DArrayShadowF:
		case TextureAccess::eTextureProjLod1DShadowF:
		case TextureAccess::eTextureProjLod2DShadowF:
		case TextureAccess::eTextureProjLodOffset1DShadowF:
		case TextureAccess::eTextureProjLodOffset2DShadowF:
		case TextureAccess::eTextureGrad2DRectShadowF:
		case TextureAccess::eTextureGrad1DShadowF:
		case TextureAccess::eTextureGrad2DShadowF:
		case TextureAccess::eTextureGrad1DArrayShadowF:
		case TextureAccess::eTextureGradOffset2DRectShadowF:
		case TextureAccess::eTextureGradOffset1DShadowF:
		case TextureAccess::eTextureGradOffset2DShadowF:
		case TextureAccess::eTextureGradOffset1DArrayShadowF:
		case TextureAccess::eTextureGradOffset2DArrayShadowF:
		case TextureAccess::eTextureProjGrad1DShadowF:
		case TextureAccess::eTextureProjGrad2DShadowF:
		case TextureAccess::eTextureProjGrad2DRectShadowF:
		case TextureAccess::eTextureProjGradOffset1DShadowF:
		case TextureAccess::eTextureProjGradOffset2DShadowF:
		case TextureAccess::eTextureProjGradOffset2DRectShadowF:
		case TextureAccess::eTextureGather2DShadowF:
		case TextureAccess::eTextureGather2DArrayShadowF:
		case TextureAccess::eTextureGatherCubeShadowF:
		case TextureAccess::eTextureGatherCubeArrayShadowF:
		case TextureAccess::eTextureGather2DRectShadowF:
		case TextureAccess::eTextureGatherOffset2DShadowF:
		case TextureAccess::eTextureGatherOffset2DArrayShadowF:
		case TextureAccess::eTextureGatherOffset2DRectShadowF:
		case TextureAccess::eTextureGatherOffsets2DShadowF:
		case TextureAccess::eTextureGatherOffsets2DArrayShadowF:
		case TextureAccess::eTextureGatherOffsets2DRectShadowF:
			return true;
		default:
			return false;
		}
	}

	bool isShadowLodOffset( TextureAccess value )
	{
		switch ( value )
		{
		case TextureAccess::eTextureLodOffset1DShadowF:
		case TextureAccess::eTextureLodOffset2DShadowF:
		case TextureAccess::eTextureLodOffset1DArrayShadowF:
		case TextureAccess::eTextureProjLodOffset1DShadowF:
		case TextureAccess::eTextureProjLodOffset2DShadowF:
			return true;
		default:
			return false;
		}
	}

	//*********************************************************************************************
}
