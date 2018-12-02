/*
See LICENSE file in root folder
*/
#ifndef ___AST_GlslTextureAccessConfig_H___
#define ___AST_GlslTextureAccessConfig_H___
#pragma once

#include "GlslHelpers.hpp"

#include <ShaderAST/Expr/EnumTextureAccess.hpp>

namespace glsl
{
	inline void getGlslConfig( ast::expr::TextureAccess value
		, IntrinsicsConfig & config )
	{
		switch ( value )
		{
		case ast::expr::TextureAccess::eTexture1DShadowF:
			config.requiresTexture1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTexture1DShadowFBias:
			config.requiresTexture1DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTexture2DShadowF:
			config.requiresTexture2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTexture2DShadowFBias:
			config.requiresTexture2DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureCubeShadowF:
			config.requiresTextureCubeShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureCubeShadowFBias:
			config.requiresTextureCubeShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTexture1DArrayShadowF:
			config.requiresTexture1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTexture1DArrayShadowFBias:
			config.requiresTexture1DArrayShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTexture2DArrayShadowF:
			config.requiresTexture2DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTexture2DArrayShadowFBias:
			config.requiresTexture2DArrayShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTexture2DRectShadowF:
			config.requiresTexture2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProj1DShadowF:
			config.requiresTextureProj1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
			config.requiresTextureProj1DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureProj2DShadowF:
			config.requiresTextureProj2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
			config.requiresTextureProj2DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureProj2DRectShadowF:
			config.requiresTextureProj2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLod1DShadowF:
			config.requiresTextureLod1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLod2DShadowF:
			config.requiresTextureLod2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLod1DArrayShadowF:
			config.requiresTextureLod1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset2DRectShadowF:
			config.requiresTextureOffset2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset1DShadowF:
			config.requiresTextureOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset1DShadowFBias:
			config.requiresTextureOffset1DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset2DShadowF:
			config.requiresTextureOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset2DShadowFBias:
			config.requiresTextureOffset2DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset1DArrayShadowF:
			config.requiresTextureOffset1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset2DArrayShadowF:
			config.requiresTextureOffset2DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DShadowF:
			config.requiresTextureProjOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
			config.requiresTextureProjOffset1DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DShadowF:
			config.requiresTextureProjOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
			config.requiresTextureProjOffset2DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF:
			config.requiresTextureProjOffset2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DShadowF:
			config.requiresTextureLodOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLodOffset2DShadowF:
			config.requiresTextureLodOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DArrayShadowF:
			config.requiresTextureLodOffset1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjLod1DShadowF:
			config.requiresTextureProjLod1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjLod2DShadowF:
			config.requiresTextureProjLod2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
			config.requiresTextureProjLodOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
			config.requiresTextureProjLodOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGrad2DRectShadowF:
			config.requiresTextureGrad2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGrad1DShadowF:
			config.requiresTextureGrad1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGrad2DShadowF:
			config.requiresTextureGrad2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGrad1DArrayShadowF:
			config.requiresTextureGrad1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DRectShadowF:
			config.requiresTextureGradOffset2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DShadowF:
			config.requiresTextureGradOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DShadowF:
			config.requiresTextureGradOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DArrayShadowF:
			config.requiresTextureGradOffset1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DArrayShadowF:
			config.requiresTextureGradOffset2DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
			config.requiresTextureProjGrad1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
			config.requiresTextureProjGrad2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
			config.requiresTextureProjGrad2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
			config.requiresTextureProjGradOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
			config.requiresTextureProjGradOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
			config.requiresTextureProjGradOffset2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGather2DF:
		case ast::expr::TextureAccess::eTextureGather2DFComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayF:
		case ast::expr::TextureAccess::eTextureGather2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherCubeF:
		case ast::expr::TextureAccess::eTextureGatherCubeFComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayF:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayFComp:
		case ast::expr::TextureAccess::eTextureGather2DRectF:
		case ast::expr::TextureAccess::eTextureGather2DRectFComp:
		case ast::expr::TextureAccess::eTextureGather2DI:
		case ast::expr::TextureAccess::eTextureGather2DIComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayI:
		case ast::expr::TextureAccess::eTextureGather2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherCubeI:
		case ast::expr::TextureAccess::eTextureGatherCubeIComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayI:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayIComp:
		case ast::expr::TextureAccess::eTextureGather2DRectI:
		case ast::expr::TextureAccess::eTextureGather2DRectIComp:
		case ast::expr::TextureAccess::eTextureGather2DU:
		case ast::expr::TextureAccess::eTextureGather2DUComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayU:
		case ast::expr::TextureAccess::eTextureGather2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherCubeU:
		case ast::expr::TextureAccess::eTextureGatherCubeUComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayU:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayUComp:
		case ast::expr::TextureAccess::eTextureGather2DRectU:
		case ast::expr::TextureAccess::eTextureGather2DRectUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectUComp:
		case ast::expr::TextureAccess::eTextureGather2DShadowF:
		case ast::expr::TextureAccess::eTextureGather2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGatherCubeShadowF:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayShadowF:
		case ast::expr::TextureAccess::eTextureGather2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectShadowF:
			config.requiresTextureGather = true;
			break;
		}
	}
}

#endif
