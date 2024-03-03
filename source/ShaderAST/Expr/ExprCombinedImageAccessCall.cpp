/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprCombinedImageAccessCall.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	//*********************************************************************************************

	CombinedImageAccessCall::CombinedImageAccessCall( ExprCache & exprCache
		, type::TypePtr type
		, CombinedImageAccess textureAccess
		, ExprList argList )
		: Expr{ exprCache
			, sizeof( CombinedImageAccessCall )
			, getExprTypesCache( argList )
			, std::move( type )
			, Kind::eCombinedImageAccessCall
			, Flag::eNone }
		, m_textureAccess{ textureAccess }
		, m_argList{ std::move( argList ) }
	{
	}

	void CombinedImageAccessCall::accept( VisitorPtr vis )const
	{
		vis->visitCombinedImageAccessCallExpr( this );
	}

	//*********************************************************************************************

	bool isBiasAndOffset( CombinedImageAccess value )
	{
		switch ( value )
		{
		case CombinedImageAccess::eTextureOffset1DFBias:
		case CombinedImageAccess::eTextureOffset2DFBias:
		case CombinedImageAccess::eTextureOffset3DFBias:
		case CombinedImageAccess::eTextureOffset1DArrayFBias:
		case CombinedImageAccess::eTextureOffset2DArrayFBias:
		case CombinedImageAccess::eTextureOffset1DIBias:
		case CombinedImageAccess::eTextureOffset2DIBias:
		case CombinedImageAccess::eTextureOffset3DIBias:
		case CombinedImageAccess::eTextureOffset1DArrayIBias:
		case CombinedImageAccess::eTextureOffset2DArrayIBias:
		case CombinedImageAccess::eTextureOffset1DUBias:
		case CombinedImageAccess::eTextureOffset2DUBias:
		case CombinedImageAccess::eTextureOffset3DUBias:
		case CombinedImageAccess::eTextureOffset1DArrayUBias:
		case CombinedImageAccess::eTextureOffset2DArrayUBias:
		case CombinedImageAccess::eTextureProjOffset1DF2Bias:
		case CombinedImageAccess::eTextureProjOffset1DF4Bias:
		case CombinedImageAccess::eTextureProjOffset2DF3Bias:
		case CombinedImageAccess::eTextureProjOffset2DF4Bias:
		case CombinedImageAccess::eTextureProjOffset3DFBias:
		case CombinedImageAccess::eTextureProjOffset1DI2Bias:
		case CombinedImageAccess::eTextureProjOffset1DI4Bias:
		case CombinedImageAccess::eTextureProjOffset2DI3Bias:
		case CombinedImageAccess::eTextureProjOffset2DI4Bias:
		case CombinedImageAccess::eTextureProjOffset3DIBias:
		case CombinedImageAccess::eTextureProjOffset1DU2Bias:
		case CombinedImageAccess::eTextureProjOffset1DU4Bias:
		case CombinedImageAccess::eTextureProjOffset2DU3Bias:
		case CombinedImageAccess::eTextureProjOffset2DU4Bias:
		case CombinedImageAccess::eTextureProjOffset3DUBias:
			return true;
		default:
			return false;
		}
	}

	bool isProj( ast::expr::CombinedImageAccess value )
	{
		switch ( value )
		{
		case ast::expr::CombinedImageAccess::eTextureProj1DF2:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj1DI2:
		case ast::expr::CombinedImageAccess::eTextureProj1DU2:
		case ast::expr::CombinedImageAccess::eTextureProj1DF2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProj1DI2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DU2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProj1DF4:
		case ast::expr::CombinedImageAccess::eTextureProj1DI4:
		case ast::expr::CombinedImageAccess::eTextureProj1DU4:
		case ast::expr::CombinedImageAccess::eTextureProj1DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DF4:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DF4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DF4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU4:
		case ast::expr::CombinedImageAccess::eTextureProj2DF3:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj2DI3:
		case ast::expr::CombinedImageAccess::eTextureProj2DU3:
		case ast::expr::CombinedImageAccess::eTextureProj2DF3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProj2DI3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DU3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProj2DF4:
		case ast::expr::CombinedImageAccess::eTextureProj2DI4:
		case ast::expr::CombinedImageAccess::eTextureProj2DU4:
		case ast::expr::CombinedImageAccess::eTextureProj2DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DF4:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DF4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DF4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU4:
		case ast::expr::CombinedImageAccess::eTextureProj3DF:
		case ast::expr::CombinedImageAccess::eTextureProj3DI:
		case ast::expr::CombinedImageAccess::eTextureProj3DU:
		case ast::expr::CombinedImageAccess::eTextureProj3DFBias:
		case ast::expr::CombinedImageAccess::eTextureProj3DIBias:
		case ast::expr::CombinedImageAccess::eTextureProj3DUBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DIBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DUBias:
		case ast::expr::CombinedImageAccess::eTextureProjLod3DF:
		case ast::expr::CombinedImageAccess::eTextureProjLod3DI:
		case ast::expr::CombinedImageAccess::eTextureProjLod3DU:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureProjGrad3DF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad3DI:
		case ast::expr::CombinedImageAccess::eTextureProjGrad3DU:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DU:
			return true;
		default:
			return false;
		}
	}

	bool isShadow( CombinedImageAccess value )
	{
		switch ( value )
		{
		case CombinedImageAccess::eTexture1DShadowF:
		case CombinedImageAccess::eTexture1DShadowFBias:
		case CombinedImageAccess::eTexture2DShadowF:
		case CombinedImageAccess::eTexture2DShadowFBias:
		case CombinedImageAccess::eTextureCubeShadowF:
		case CombinedImageAccess::eTextureCubeShadowFBias:
		case CombinedImageAccess::eTexture1DArrayShadowF:
		case CombinedImageAccess::eTexture1DArrayShadowFBias:
		case CombinedImageAccess::eTexture2DArrayShadowF:
		case CombinedImageAccess::eTextureCubeArrayShadowF:
		case CombinedImageAccess::eTextureProj1DShadowF:
		case CombinedImageAccess::eTextureProj1DShadowFBias:
		case CombinedImageAccess::eTextureProj2DShadowF:
		case CombinedImageAccess::eTextureProj2DShadowFBias:
		case CombinedImageAccess::eTextureLod1DShadowF:
		case CombinedImageAccess::eTextureLod2DShadowF:
		case CombinedImageAccess::eTextureLodCubeShadowF:
		case CombinedImageAccess::eTextureLod1DArrayShadowF:
		case CombinedImageAccess::eTextureLod2DArrayShadowF:
		case CombinedImageAccess::eTextureLodCubeArrayShadowF:
		case CombinedImageAccess::eTextureOffset1DShadowF:
		case CombinedImageAccess::eTextureOffset1DShadowFBias:
		case CombinedImageAccess::eTextureOffset2DShadowF:
		case CombinedImageAccess::eTextureOffset2DShadowFBias:
		case CombinedImageAccess::eTextureOffset1DArrayShadowF:
		case CombinedImageAccess::eTextureOffset2DArrayShadowF:
		case CombinedImageAccess::eTextureProjOffset1DShadowF:
		case CombinedImageAccess::eTextureProjOffset1DShadowFBias:
		case CombinedImageAccess::eTextureProjOffset2DShadowF:
		case CombinedImageAccess::eTextureProjOffset2DShadowFBias:
		case CombinedImageAccess::eTextureLodOffset1DShadowF:
		case CombinedImageAccess::eTextureLodOffset2DShadowF:
		case CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
		case CombinedImageAccess::eTextureProjLod1DShadowF:
		case CombinedImageAccess::eTextureProjLod2DShadowF:
		case CombinedImageAccess::eTextureProjLodOffset1DShadowF:
		case CombinedImageAccess::eTextureProjLodOffset2DShadowF:
		case CombinedImageAccess::eTextureGrad1DShadowF:
		case CombinedImageAccess::eTextureGrad2DShadowF:
		case CombinedImageAccess::eTextureGrad1DArrayShadowF:
		case CombinedImageAccess::eTextureGradOffset1DShadowF:
		case CombinedImageAccess::eTextureGradOffset2DShadowF:
		case CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
		case CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
		case CombinedImageAccess::eTextureProjGrad1DShadowF:
		case CombinedImageAccess::eTextureProjGrad2DShadowF:
		case CombinedImageAccess::eTextureProjGradOffset1DShadowF:
		case CombinedImageAccess::eTextureProjGradOffset2DShadowF:
		case CombinedImageAccess::eTextureGather2DShadowF:
		case CombinedImageAccess::eTextureGather2DArrayShadowF:
		case CombinedImageAccess::eTextureGatherCubeShadowF:
		case CombinedImageAccess::eTextureGatherCubeArrayShadowF:
		case CombinedImageAccess::eTextureGatherOffset2DShadowF:
		case CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
		case CombinedImageAccess::eTextureGatherOffsets2DShadowF:
		case CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
			return true;
		default:
			return false;
		}
	}

	bool isShadowLodOffset( CombinedImageAccess value )
	{
		switch ( value )
		{
		case CombinedImageAccess::eTextureLodOffset1DShadowF:
		case CombinedImageAccess::eTextureLodOffset2DShadowF:
		case CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
		case CombinedImageAccess::eTextureProjLodOffset1DShadowF:
		case CombinedImageAccess::eTextureProjLodOffset2DShadowF:
			return true;
		default:
			return false;
		}
	}

	//*********************************************************************************************
}
