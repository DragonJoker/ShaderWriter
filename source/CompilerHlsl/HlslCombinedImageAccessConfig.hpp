/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslTextureAccessConfig_H___
#define ___AST_HlslTextureAccessConfig_H___
#pragma once

#include "HlslHelpers.hpp"

#include <ShaderAST/Expr/EnumCombinedImageAccess.hpp>

#include <stdexcept>

namespace hlsl
{
	inline void getHlslConfig( ast::expr::CombinedImageAccess value
		, IntrinsicsConfig & config )
	{
		switch ( value )
		{
		case ast::expr::CombinedImageAccess::eTexture1DShadowF:
		case ast::expr::CombinedImageAccess::eTexture1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTexture2DShadowF:
		case ast::expr::CombinedImageAccess::eTexture2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureCubeShadowFBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTexture1DArrayShadowFBias:
		case ast::expr::CombinedImageAccess::eTexture2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGather2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
			config.requiresShadowSampler = true;
			config.requiresShadowOnTiled = ( value == ast::expr::CombinedImageAccess::eTextureCubeShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureCubeShadowFBias
				|| value == ast::expr::CombinedImageAccess::eTextureCubeArrayShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureGatherCubeShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureGatherCubeArrayShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureLod1DShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureLod2DShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureLodCubeShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureLod1DArrayShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureLod2DArrayShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureLodCubeArrayShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureLodOffset1DShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureLodOffset2DShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureProjLod1DShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureProjLod2DShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF
				|| value == ast::expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF );
			break;

		case ast::expr::CombinedImageAccess::eTextureGrad1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGrad1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGrad2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
			throw ast::Exception{ "Unsupported grad shadow" };

		case ast::expr::CombinedImageAccess::eTexture1DI:
		case ast::expr::CombinedImageAccess::eTexture1DIBias:
		case ast::expr::CombinedImageAccess::eTexture2DI:
		case ast::expr::CombinedImageAccess::eTexture2DIBias:
		case ast::expr::CombinedImageAccess::eTexture3DI:
		case ast::expr::CombinedImageAccess::eTexture3DIBias:
		case ast::expr::CombinedImageAccess::eTextureCubeI:
		case ast::expr::CombinedImageAccess::eTextureCubeIBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayI:
		case ast::expr::CombinedImageAccess::eTexture1DArrayIBias:
		case ast::expr::CombinedImageAccess::eTexture2DArrayI:
		case ast::expr::CombinedImageAccess::eTexture2DArrayIBias:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayIBias:
		case ast::expr::CombinedImageAccess::eTexture1DU:
		case ast::expr::CombinedImageAccess::eTexture1DUBias:
		case ast::expr::CombinedImageAccess::eTexture2DU:
		case ast::expr::CombinedImageAccess::eTexture2DUBias:
		case ast::expr::CombinedImageAccess::eTexture3DU:
		case ast::expr::CombinedImageAccess::eTexture3DUBias:
		case ast::expr::CombinedImageAccess::eTextureCubeU:
		case ast::expr::CombinedImageAccess::eTextureCubeUBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayU:
		case ast::expr::CombinedImageAccess::eTexture1DArrayUBias:
		case ast::expr::CombinedImageAccess::eTexture2DArrayU:
		case ast::expr::CombinedImageAccess::eTexture2DArrayUBias:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayU:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayUBias:
		case ast::expr::CombinedImageAccess::eTextureProj1DI2:
		case ast::expr::CombinedImageAccess::eTextureProj1DI2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DI4:
		case ast::expr::CombinedImageAccess::eTextureProj1DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DI3:
		case ast::expr::CombinedImageAccess::eTextureProj2DI3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DI4:
		case ast::expr::CombinedImageAccess::eTextureProj2DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj3DI:
		case ast::expr::CombinedImageAccess::eTextureProj3DIBias:
		case ast::expr::CombinedImageAccess::eTextureProj1DU2:
		case ast::expr::CombinedImageAccess::eTextureProj1DU2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DU4:
		case ast::expr::CombinedImageAccess::eTextureProj1DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DU3:
		case ast::expr::CombinedImageAccess::eTextureProj2DU3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DU4:
		case ast::expr::CombinedImageAccess::eTextureProj2DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj3DU:
		case ast::expr::CombinedImageAccess::eTextureProj3DUBias:
		case ast::expr::CombinedImageAccess::eTextureLod1DI:
		case ast::expr::CombinedImageAccess::eTextureLod2DI:
		case ast::expr::CombinedImageAccess::eTextureLod3DI:
		case ast::expr::CombinedImageAccess::eTextureLodCubeI:
		case ast::expr::CombinedImageAccess::eTextureLod1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureLod2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureLodCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureLod1DU:
		case ast::expr::CombinedImageAccess::eTextureLod2DU:
		case ast::expr::CombinedImageAccess::eTextureLod3DU:
		case ast::expr::CombinedImageAccess::eTextureLodCubeU:
		case ast::expr::CombinedImageAccess::eTextureLod1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureLod2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureLodCubeArrayU:
		case ast::expr::CombinedImageAccess::eTextureOffset1DI:
		case ast::expr::CombinedImageAccess::eTextureOffset1DIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DI:
		case ast::expr::CombinedImageAccess::eTextureOffset2DIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureOffset3DIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DU:
		case ast::expr::CombinedImageAccess::eTextureOffset1DUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DU:
		case ast::expr::CombinedImageAccess::eTextureOffset2DUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureOffset3DUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayUBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DIBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DUBias:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DI:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DI:
		case ast::expr::CombinedImageAccess::eTextureLodOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DU:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DU:
		case ast::expr::CombinedImageAccess::eTextureLodOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLod3DI:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjLod3DU:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureGrad1DI:
		case ast::expr::CombinedImageAccess::eTextureGrad2DI:
		case ast::expr::CombinedImageAccess::eTextureGrad3DI:
		case ast::expr::CombinedImageAccess::eTextureGradCubeI:
		case ast::expr::CombinedImageAccess::eTextureGrad1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGrad2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGradCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureGrad1DU:
		case ast::expr::CombinedImageAccess::eTextureGrad2DU:
		case ast::expr::CombinedImageAccess::eTextureGrad3DU:
		case ast::expr::CombinedImageAccess::eTextureGradCubeU:
		case ast::expr::CombinedImageAccess::eTextureGrad1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGrad2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGradCubeArrayU:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad3DI:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad3DU:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DI:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DI:
		case ast::expr::CombinedImageAccess::eTextureGradOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DU:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DU:
		case ast::expr::CombinedImageAccess::eTextureGradOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DU:
			throw ast::Exception{ "Unsupported non-float texture sampling" };
		default:
			break;
		}

		switch ( value )
		{
		case ast::expr::CombinedImageAccess::eTexture1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTexture2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureCubeShadowFBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
			config.requiresShadowOnTiled = true;
			break;
		default:
			break;
		}

		switch ( value )
		{
		case ast::expr::CombinedImageAccess::eTextureGather2DF:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureGather2DI:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeI:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureGather2DU:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeU:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGather2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
			config.requiresGather = true;
			break;
		default:
			break;
		}

		switch ( value )
		{
		case ast::expr::CombinedImageAccess::eTextureSizeBufferF:
			config.requiresTextureSizeBufferF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSizeBufferI:
			config.requiresTextureSizeBufferI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSizeBufferU:
			config.requiresTextureSizeBufferU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize1DF:
			config.requiresTextureSize1DF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize1DShadowF:
			config.requiresTextureSize1DShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize1DI:
			config.requiresTextureSize1DI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize1DU:
			config.requiresTextureSize1DU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize2DF:
			config.requiresTextureSize2DF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize2DShadowF:
			config.requiresTextureSize2DShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize2DI:
			config.requiresTextureSize2DI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize2DU:
			config.requiresTextureSize2DU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize3DF:
			config.requiresTextureSize3DF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize3DI:
			config.requiresTextureSize3DI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize3DU:
			config.requiresTextureSize3DU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSizeCubeF:
			config.requiresTextureSizeCubeF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSizeCubeShadowF:
			config.requiresTextureSizeCubeShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSizeCubeI:
			config.requiresTextureSizeCubeI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSizeCubeU:
			config.requiresTextureSizeCubeU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayF:
			config.requiresTextureSizeCubeArrayF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayShadowF:
			config.requiresTextureSizeCubeArrayShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayI:
			config.requiresTextureSizeCubeArrayI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayU:
			config.requiresTextureSizeCubeArrayU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize1DArrayF:
			config.requiresTextureSize1DArrayF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize1DArrayShadowF:
			config.requiresTextureSize1DArrayShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize1DArrayI:
			config.requiresTextureSize1DArrayI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize1DArrayU:
			config.requiresTextureSize1DArrayU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize2DArrayF:
			config.requiresTextureSize2DArrayF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize2DArrayShadowF:
			config.requiresTextureSize2DArrayShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize2DArrayI:
			config.requiresTextureSize2DArrayI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSize2DArrayU:
			config.requiresTextureSize2DArrayU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod1DF:
			config.requiresTextureQueryLod1DF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod1DShadowF:
			config.requiresTextureQueryLod1DShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod1DI:
			config.requiresTextureQueryLod1DI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod1DU:
			config.requiresTextureQueryLod1DU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod2DF:
			config.requiresTextureQueryLod2DF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod2DShadowF:
			config.requiresTextureQueryLod2DShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod2DI:
			config.requiresTextureQueryLod2DI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod2DU:
			config.requiresTextureQueryLod2DU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod3DF:
			config.requiresTextureQueryLod3DF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod3DI:
			config.requiresTextureQueryLod3DI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod3DU:
			config.requiresTextureQueryLod3DU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeF:
			config.requiresTextureQueryLodCubeF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeShadowF:
			config.requiresTextureQueryLodCubeShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeI:
			config.requiresTextureQueryLodCubeI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeU:
			config.requiresTextureQueryLodCubeU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayF:
			config.requiresTextureQueryLodCubeArrayF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayShadowF:
			config.requiresTextureQueryLodCubeArrayShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayI:
			config.requiresTextureQueryLodCubeArrayI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayU:
			config.requiresTextureQueryLodCubeArrayU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayF:
			config.requiresTextureQueryLod1DArrayF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayShadowF:
			config.requiresTextureQueryLod1DArrayShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayI:
			config.requiresTextureQueryLod1DArrayI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayU:
			config.requiresTextureQueryLod1DArrayU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayF:
			config.requiresTextureQueryLod2DArrayF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayShadowF:
			config.requiresTextureQueryLod2DArrayShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayI:
			config.requiresTextureQueryLod2DArrayI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayU:
			config.requiresTextureQueryLod2DArrayU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DF:
			config.requiresTextureQueryLevels1DF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DShadowF:
			config.requiresTextureQueryLevels1DShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DI:
			config.requiresTextureQueryLevels1DI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DU:
			config.requiresTextureQueryLevels1DU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DF:
			config.requiresTextureQueryLevels2DF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DShadowF:
			config.requiresTextureQueryLevels2DShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DI:
			config.requiresTextureQueryLevels2DI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DU:
			config.requiresTextureQueryLevels2DU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DF:
			config.requiresTextureQueryLevels3DF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DI:
			config.requiresTextureQueryLevels3DI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DU:
			config.requiresTextureQueryLevels3DU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeF:
			config.requiresTextureQueryLevelsCubeF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeShadowF:
			config.requiresTextureQueryLevelsCubeShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeI:
			config.requiresTextureQueryLevelsCubeI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeU:
			config.requiresTextureQueryLevelsCubeU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayF:
			config.requiresTextureQueryLevelsCubeArrayF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayShadowF:
			config.requiresTextureQueryLevelsCubeArrayShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayI:
			config.requiresTextureQueryLevelsCubeArrayI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU:
			config.requiresTextureQueryLevelsCubeArrayU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayF:
			config.requiresTextureQueryLevels1DArrayF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayShadowF:
			config.requiresTextureQueryLevels1DArrayShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayI:
			config.requiresTextureQueryLevels1DArrayI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayU:
			config.requiresTextureQueryLevels1DArrayU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayF:
			config.requiresTextureQueryLevels2DArrayF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayShadowF:
			config.requiresTextureQueryLevels2DArrayShadowF = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayI:
			config.requiresTextureQueryLevels2DArrayI = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayU:
			config.requiresTextureQueryLevels2DArrayU = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureProj1DF2:
		case ast::expr::CombinedImageAccess::eTextureProj1DI2:
		case ast::expr::CombinedImageAccess::eTextureProj1DU2:
		case ast::expr::CombinedImageAccess::eTextureProj1DF2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DI2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DU2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
			config.requiresProjectTexCoords2 = true;
			break;

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
			config.requiresProjectTexCoords4To1 = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureProj2DF3:
		case ast::expr::CombinedImageAccess::eTextureProj2DI3:
		case ast::expr::CombinedImageAccess::eTextureProj2DU3:
		case ast::expr::CombinedImageAccess::eTextureProj2DF3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DI3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DU3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
			config.requiresProjectTexCoords3 = true;
			break;

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
			config.requiresProjectTexCoords4To2 = true;
			break;

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
			config.requiresProjectTexCoords4 = true;
			break;

		default:
			break;
		}
	}
}

#endif
