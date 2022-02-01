/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslTextureAccessConfig_H___
#define ___AST_HlslTextureAccessConfig_H___
#pragma once

#include "HlslHelpers.hpp"

#include <ShaderAST/Expr/EnumTextureAccess.hpp>

#include <stdexcept>

namespace hlsl
{
	inline void getHlslConfig( ast::expr::TextureAccess value
		, IntrinsicsConfig & config )
	{
		switch ( value )
		{
		case ast::expr::TextureAccess::eTexture1DShadowF:
		case ast::expr::TextureAccess::eTexture1DShadowFBias:
		case ast::expr::TextureAccess::eTexture2DShadowF:
		case ast::expr::TextureAccess::eTexture2DShadowFBias:
		case ast::expr::TextureAccess::eTextureCubeShadowF:
		case ast::expr::TextureAccess::eTextureCubeShadowFBias:
		case ast::expr::TextureAccess::eTexture1DArrayShadowF:
		case ast::expr::TextureAccess::eTexture1DArrayShadowFBias:
		case ast::expr::TextureAccess::eTexture2DArrayShadowF:
		case ast::expr::TextureAccess::eTexture2DRectShadowF:
		case ast::expr::TextureAccess::eTextureCubeArrayShadowF:
		case ast::expr::TextureAccess::eTextureProj1DShadowF:
		case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProj2DShadowF:
		case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProj2DRectShadowF:
		case ast::expr::TextureAccess::eTextureLod1DShadowF:
		case ast::expr::TextureAccess::eTextureLod2DShadowF:
		case ast::expr::TextureAccess::eTextureLod1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureOffset2DShadowFBias:
		case ast::expr::TextureAccess::eTextureOffset1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureOffset2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureProjLod1DShadowF:
		case ast::expr::TextureAccess::eTextureProjLod2DShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
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
			config.requiresShadowSampler = true;
			config.requiresShadowOnTiled = ( value == ast::expr::TextureAccess::eTextureCubeShadowF
				|| value == ast::expr::TextureAccess::eTextureCubeShadowFBias
				|| value == ast::expr::TextureAccess::eTextureCubeArrayShadowF
				|| value == ast::expr::TextureAccess::eTextureGatherCubeShadowF
				|| value == ast::expr::TextureAccess::eTextureGatherCubeArrayShadowF
				|| value == ast::expr::TextureAccess::eTextureLod1DShadowF
				|| value == ast::expr::TextureAccess::eTextureLod2DShadowF
				|| value == ast::expr::TextureAccess::eTextureLod1DArrayShadowF
				|| value == ast::expr::TextureAccess::eTextureLodOffset1DShadowF
				|| value == ast::expr::TextureAccess::eTextureLodOffset2DShadowF
				|| value == ast::expr::TextureAccess::eTextureLodOffset1DArrayShadowF
				|| value == ast::expr::TextureAccess::eTextureProjLod1DShadowF
				|| value == ast::expr::TextureAccess::eTextureProjLod2DShadowF
				|| value == ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF
				|| value == ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF );
			break;

		case ast::expr::TextureAccess::eTextureGrad1DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
		case ast::expr::TextureAccess::eTextureGrad1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureGrad2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGrad2DShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayShadowF:
			throw std::runtime_error{ "Unsupported grad shadow" };

		case ast::expr::TextureAccess::eTexture1DI:
		case ast::expr::TextureAccess::eTexture1DIBias:
		case ast::expr::TextureAccess::eTexture2DI:
		case ast::expr::TextureAccess::eTexture2DIBias:
		case ast::expr::TextureAccess::eTexture3DI:
		case ast::expr::TextureAccess::eTexture3DIBias:
		case ast::expr::TextureAccess::eTextureCubeI:
		case ast::expr::TextureAccess::eTextureCubeIBias:
		case ast::expr::TextureAccess::eTexture1DArrayI:
		case ast::expr::TextureAccess::eTexture1DArrayIBias:
		case ast::expr::TextureAccess::eTexture2DArrayI:
		case ast::expr::TextureAccess::eTexture2DArrayIBias:
		case ast::expr::TextureAccess::eTextureCubeArrayI:
		case ast::expr::TextureAccess::eTextureCubeArrayIBias:
		case ast::expr::TextureAccess::eTexture2DRectI:
		case ast::expr::TextureAccess::eTexture1DU:
		case ast::expr::TextureAccess::eTexture1DUBias:
		case ast::expr::TextureAccess::eTexture2DU:
		case ast::expr::TextureAccess::eTexture2DUBias:
		case ast::expr::TextureAccess::eTexture3DU:
		case ast::expr::TextureAccess::eTexture3DUBias:
		case ast::expr::TextureAccess::eTextureCubeU:
		case ast::expr::TextureAccess::eTextureCubeUBias:
		case ast::expr::TextureAccess::eTexture1DArrayU:
		case ast::expr::TextureAccess::eTexture1DArrayUBias:
		case ast::expr::TextureAccess::eTexture2DArrayU:
		case ast::expr::TextureAccess::eTexture2DArrayUBias:
		case ast::expr::TextureAccess::eTextureCubeArrayU:
		case ast::expr::TextureAccess::eTextureCubeArrayUBias:
		case ast::expr::TextureAccess::eTexture2DRectU:
		case ast::expr::TextureAccess::eTextureProj1DI2:
		case ast::expr::TextureAccess::eTextureProj1DI2Bias:
		case ast::expr::TextureAccess::eTextureProj1DI4:
		case ast::expr::TextureAccess::eTextureProj1DI4Bias:
		case ast::expr::TextureAccess::eTextureProj2DI3:
		case ast::expr::TextureAccess::eTextureProj2DI3Bias:
		case ast::expr::TextureAccess::eTextureProj2DI4:
		case ast::expr::TextureAccess::eTextureProj2DI4Bias:
		case ast::expr::TextureAccess::eTextureProj3DI:
		case ast::expr::TextureAccess::eTextureProj3DIBias:
		case ast::expr::TextureAccess::eTextureProj2DRectI3:
		case ast::expr::TextureAccess::eTextureProj2DRectI4:
		case ast::expr::TextureAccess::eTextureProj1DU2:
		case ast::expr::TextureAccess::eTextureProj1DU2Bias:
		case ast::expr::TextureAccess::eTextureProj1DU4:
		case ast::expr::TextureAccess::eTextureProj1DU4Bias:
		case ast::expr::TextureAccess::eTextureProj2DU3:
		case ast::expr::TextureAccess::eTextureProj2DU3Bias:
		case ast::expr::TextureAccess::eTextureProj2DU4:
		case ast::expr::TextureAccess::eTextureProj2DU4Bias:
		case ast::expr::TextureAccess::eTextureProj3DU:
		case ast::expr::TextureAccess::eTextureProj3DUBias:
		case ast::expr::TextureAccess::eTextureProj2DRectU3:
		case ast::expr::TextureAccess::eTextureProj2DRectU4:
		case ast::expr::TextureAccess::eTextureLod1DI:
		case ast::expr::TextureAccess::eTextureLod2DI:
		case ast::expr::TextureAccess::eTextureLod3DI:
		case ast::expr::TextureAccess::eTextureLodCubeI:
		case ast::expr::TextureAccess::eTextureLod1DArrayI:
		case ast::expr::TextureAccess::eTextureLod2DArrayI:
		case ast::expr::TextureAccess::eTextureLodCubeArrayI:
		case ast::expr::TextureAccess::eTextureLod1DU:
		case ast::expr::TextureAccess::eTextureLod2DU:
		case ast::expr::TextureAccess::eTextureLod3DU:
		case ast::expr::TextureAccess::eTextureLodCubeU:
		case ast::expr::TextureAccess::eTextureLod1DArrayU:
		case ast::expr::TextureAccess::eTextureLod2DArrayU:
		case ast::expr::TextureAccess::eTextureLodCubeArrayU:
		case ast::expr::TextureAccess::eTextureOffset1DI:
		case ast::expr::TextureAccess::eTextureOffset1DIBias:
		case ast::expr::TextureAccess::eTextureOffset2DI:
		case ast::expr::TextureAccess::eTextureOffset2DIBias:
		case ast::expr::TextureAccess::eTextureOffset3DI:
		case ast::expr::TextureAccess::eTextureOffset3DIBias:
		case ast::expr::TextureAccess::eTextureOffset2DRectI:
		case ast::expr::TextureAccess::eTextureOffset1DArrayI:
		case ast::expr::TextureAccess::eTextureOffset1DArrayIBias:
		case ast::expr::TextureAccess::eTextureOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureOffset2DArrayIBias:
		case ast::expr::TextureAccess::eTextureOffset1DU:
		case ast::expr::TextureAccess::eTextureOffset1DUBias:
		case ast::expr::TextureAccess::eTextureOffset2DU:
		case ast::expr::TextureAccess::eTextureOffset2DUBias:
		case ast::expr::TextureAccess::eTextureOffset3DU:
		case ast::expr::TextureAccess::eTextureOffset3DUBias:
		case ast::expr::TextureAccess::eTextureOffset2DRectU:
		case ast::expr::TextureAccess::eTextureOffset1DArrayU:
		case ast::expr::TextureAccess::eTextureOffset1DArrayUBias:
		case ast::expr::TextureAccess::eTextureOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureOffset2DArrayUBias:
		case ast::expr::TextureAccess::eTextureProjOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjOffset1DI2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjOffset1DI4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjOffset2DI3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjOffset2DI4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset3DI:
		case ast::expr::TextureAccess::eTextureProjOffset3DIBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectI3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectI4:
		case ast::expr::TextureAccess::eTextureProjOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjOffset1DU2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjOffset1DU4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjOffset2DU3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjOffset2DU4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset3DU:
		case ast::expr::TextureAccess::eTextureProjOffset3DUBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectU3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectU4:
		case ast::expr::TextureAccess::eTextureLodOffset1DI:
		case ast::expr::TextureAccess::eTextureLodOffset2DI:
		case ast::expr::TextureAccess::eTextureLodOffset3DI:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayI:
		case ast::expr::TextureAccess::eTextureLodOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureLodOffset1DU:
		case ast::expr::TextureAccess::eTextureLodOffset2DU:
		case ast::expr::TextureAccess::eTextureLodOffset3DU:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayU:
		case ast::expr::TextureAccess::eTextureLodOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureProjLod1DI2:
		case ast::expr::TextureAccess::eTextureProjLod1DI4:
		case ast::expr::TextureAccess::eTextureProjLod2DI3:
		case ast::expr::TextureAccess::eTextureProjLod2DI4:
		case ast::expr::TextureAccess::eTextureProjLod3DI:
		case ast::expr::TextureAccess::eTextureProjLod1DU2:
		case ast::expr::TextureAccess::eTextureProjLod1DU4:
		case ast::expr::TextureAccess::eTextureProjLod2DU3:
		case ast::expr::TextureAccess::eTextureProjLod2DU4:
		case ast::expr::TextureAccess::eTextureProjLod3DU:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DI:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DU:
		case ast::expr::TextureAccess::eTextureGrad1DI:
		case ast::expr::TextureAccess::eTextureGrad2DI:
		case ast::expr::TextureAccess::eTextureGrad3DI:
		case ast::expr::TextureAccess::eTextureGradCubeI:
		case ast::expr::TextureAccess::eTextureGrad2DRectI:
		case ast::expr::TextureAccess::eTextureGrad1DArrayI:
		case ast::expr::TextureAccess::eTextureGrad2DArrayI:
		case ast::expr::TextureAccess::eTextureGradCubeArrayI:
		case ast::expr::TextureAccess::eTextureGrad1DU:
		case ast::expr::TextureAccess::eTextureGrad2DU:
		case ast::expr::TextureAccess::eTextureGrad3DU:
		case ast::expr::TextureAccess::eTextureGradCubeU:
		case ast::expr::TextureAccess::eTextureGrad2DRectU:
		case ast::expr::TextureAccess::eTextureGrad1DArrayU:
		case ast::expr::TextureAccess::eTextureGrad2DArrayU:
		case ast::expr::TextureAccess::eTextureGradCubeArrayU:
		case ast::expr::TextureAccess::eTextureProjGrad1DI2:
		case ast::expr::TextureAccess::eTextureProjGrad1DI4:
		case ast::expr::TextureAccess::eTextureProjGrad2DI3:
		case ast::expr::TextureAccess::eTextureProjGrad2DI4:
		case ast::expr::TextureAccess::eTextureProjGrad3DI:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectI3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectI4:
		case ast::expr::TextureAccess::eTextureProjGrad1DU2:
		case ast::expr::TextureAccess::eTextureProjGrad1DU4:
		case ast::expr::TextureAccess::eTextureProjGrad2DU3:
		case ast::expr::TextureAccess::eTextureProjGrad2DU4:
		case ast::expr::TextureAccess::eTextureProjGrad3DU:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectU3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectU4:
		case ast::expr::TextureAccess::eTextureGradOffset1DI:
		case ast::expr::TextureAccess::eTextureGradOffset2DI:
		case ast::expr::TextureAccess::eTextureGradOffset3DI:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectI:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayI:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureGradOffset1DU:
		case ast::expr::TextureAccess::eTextureGradOffset2DU:
		case ast::expr::TextureAccess::eTextureGradOffset3DU:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectU:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayU:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DI:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DU:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU4:
			throw std::runtime_error{ "Unsupported non-float texture sampling" };
		default:
			break;
		}

		switch ( value )
		{
		case ast::expr::TextureAccess::eTexture1DShadowFBias:
		case ast::expr::TextureAccess::eTexture2DShadowFBias:
		case ast::expr::TextureAccess::eTextureCubeShadowFBias:
		case ast::expr::TextureAccess::eTexture1DArrayShadowFBias:
		case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
		case ast::expr::TextureAccess::eTextureOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureOffset2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
			config.requiresShadowOnTiled = true;
			break;
		default:
			break;
		}

		switch ( value )
		{
		case ast::expr::TextureAccess::eTextureGather2DF:
		case ast::expr::TextureAccess::eTextureGather2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherCubeF:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayF:
		case ast::expr::TextureAccess::eTextureGather2DRectF:
		case ast::expr::TextureAccess::eTextureGather2DI:
		case ast::expr::TextureAccess::eTextureGather2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherCubeI:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayI:
		case ast::expr::TextureAccess::eTextureGather2DRectI:
		case ast::expr::TextureAccess::eTextureGather2DU:
		case ast::expr::TextureAccess::eTextureGather2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherCubeU:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayU:
		case ast::expr::TextureAccess::eTextureGather2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectU:
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
			config.requiresGather = true;
			break;
		default:
			break;
		}

		switch ( value )
		{
		case ast::expr::TextureAccess::eTextureSizeBufferF:
			config.requiresTextureSizeBufferF = true;
			break;

		case ast::expr::TextureAccess::eTextureSizeBufferI:
			config.requiresTextureSizeBufferI = true;
			break;

		case ast::expr::TextureAccess::eTextureSizeBufferU:
			config.requiresTextureSizeBufferU = true;
			break;

		case ast::expr::TextureAccess::eTextureSize1DF:
			config.requiresTextureSize1DF = true;
			break;

		case ast::expr::TextureAccess::eTextureSize1DShadowF:
			config.requiresTextureSize1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureSize1DI:
			config.requiresTextureSize1DI = true;
			break;

		case ast::expr::TextureAccess::eTextureSize1DU:
			config.requiresTextureSize1DU = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DF:
			config.requiresTextureSize2DF = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DShadowF:
			config.requiresTextureSize2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DRectF:
			config.requiresTextureSize2DRectF = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DRectShadowF:
			config.requiresTextureSize2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DI:
			config.requiresTextureSize2DI = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DRectI:
			config.requiresTextureSize2DRectI = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DU:
			config.requiresTextureSize2DU = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DRectU:
			config.requiresTextureSize2DRectU = true;
			break;

		case ast::expr::TextureAccess::eTextureSize3DF:
			config.requiresTextureSize3DF = true;
			break;

		case ast::expr::TextureAccess::eTextureSize3DI:
			config.requiresTextureSize3DI = true;
			break;

		case ast::expr::TextureAccess::eTextureSize3DU:
			config.requiresTextureSize3DU = true;
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeF:
			config.requiresTextureSizeCubeF = true;
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeShadowF:
			config.requiresTextureSizeCubeShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeI:
			config.requiresTextureSizeCubeI = true;
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeU:
			config.requiresTextureSizeCubeU = true;
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeArrayF:
			config.requiresTextureSizeCubeArrayF = true;
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeArrayShadowF:
			config.requiresTextureSizeCubeArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeArrayI:
			config.requiresTextureSizeCubeArrayI = true;
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeArrayU:
			config.requiresTextureSizeCubeArrayU = true;
			break;

		case ast::expr::TextureAccess::eTextureSize1DArrayF:
			config.requiresTextureSize1DArrayF = true;
			break;

		case ast::expr::TextureAccess::eTextureSize1DArrayShadowF:
			config.requiresTextureSize1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureSize1DArrayI:
			config.requiresTextureSize1DArrayI = true;
			break;

		case ast::expr::TextureAccess::eTextureSize1DArrayU:
			config.requiresTextureSize1DArrayU = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DArrayF:
			config.requiresTextureSize2DArrayF = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DArrayShadowF:
			config.requiresTextureSize2DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DArrayI:
			config.requiresTextureSize2DArrayI = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DArrayU:
			config.requiresTextureSize2DArrayU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DF:
			config.requiresTextureQueryLod1DF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DShadowF:
			config.requiresTextureQueryLod1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DI:
			config.requiresTextureQueryLod1DI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DU:
			config.requiresTextureQueryLod1DU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DF:
			config.requiresTextureQueryLod2DF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DShadowF:
			config.requiresTextureQueryLod2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DI:
			config.requiresTextureQueryLod2DI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DU:
			config.requiresTextureQueryLod2DU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod3DF:
			config.requiresTextureQueryLod3DF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod3DI:
			config.requiresTextureQueryLod3DI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod3DU:
			config.requiresTextureQueryLod3DU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeF:
			config.requiresTextureQueryLodCubeF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeShadowF:
			config.requiresTextureQueryLodCubeShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeI:
			config.requiresTextureQueryLodCubeI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeU:
			config.requiresTextureQueryLodCubeU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayF:
			config.requiresTextureQueryLodCubeArrayF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayShadowF:
			config.requiresTextureQueryLodCubeArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayI:
			config.requiresTextureQueryLodCubeArrayI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayU:
			config.requiresTextureQueryLodCubeArrayU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DArrayF:
			config.requiresTextureQueryLod1DArrayF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DArrayShadowF:
			config.requiresTextureQueryLod1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DArrayI:
			config.requiresTextureQueryLod1DArrayI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DArrayU:
			config.requiresTextureQueryLod1DArrayU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DArrayF:
			config.requiresTextureQueryLod2DArrayF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DArrayShadowF:
			config.requiresTextureQueryLod2DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DArrayI:
			config.requiresTextureQueryLod2DArrayI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DArrayU:
			config.requiresTextureQueryLod2DArrayU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DF:
			config.requiresTextureQueryLevels1DF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DShadowF:
			config.requiresTextureQueryLevels1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DI:
			config.requiresTextureQueryLevels1DI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DU:
			config.requiresTextureQueryLevels1DU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DF:
			config.requiresTextureQueryLevels2DF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DShadowF:
			config.requiresTextureQueryLevels2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DI:
			config.requiresTextureQueryLevels2DI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DU:
			config.requiresTextureQueryLevels2DU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels3DF:
			config.requiresTextureQueryLevels3DF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels3DI:
			config.requiresTextureQueryLevels3DI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels3DU:
			config.requiresTextureQueryLevels3DU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeF:
			config.requiresTextureQueryLevelsCubeF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeShadowF:
			config.requiresTextureQueryLevelsCubeShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeI:
			config.requiresTextureQueryLevelsCubeI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeU:
			config.requiresTextureQueryLevelsCubeU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayF:
			config.requiresTextureQueryLevelsCubeArrayF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayShadowF:
			config.requiresTextureQueryLevelsCubeArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayI:
			config.requiresTextureQueryLevelsCubeArrayI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayU:
			config.requiresTextureQueryLevelsCubeArrayU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayF:
			config.requiresTextureQueryLevels1DArrayF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayShadowF:
			config.requiresTextureQueryLevels1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayI:
			config.requiresTextureQueryLevels1DArrayI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayU:
			config.requiresTextureQueryLevels1DArrayU = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayF:
			config.requiresTextureQueryLevels2DArrayF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayShadowF:
			config.requiresTextureQueryLevels2DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayI:
			config.requiresTextureQueryLevels2DArrayI = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayU:
			config.requiresTextureQueryLevels2DArrayU = true;
			break;

		case ast::expr::TextureAccess::eTextureProj1DF2:
		case ast::expr::TextureAccess::eTextureProj1DI2:
		case ast::expr::TextureAccess::eTextureProj1DU2:
		case ast::expr::TextureAccess::eTextureProj1DF2Bias:
		case ast::expr::TextureAccess::eTextureProj1DI2Bias:
		case ast::expr::TextureAccess::eTextureProj1DU2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjOffset1DF2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DI2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DU2Bias:
		case ast::expr::TextureAccess::eTextureProjLod1DF2:
		case ast::expr::TextureAccess::eTextureProjLod1DI2:
		case ast::expr::TextureAccess::eTextureProjLod1DU2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjGrad1DF2:
		case ast::expr::TextureAccess::eTextureProjGrad1DI2:
		case ast::expr::TextureAccess::eTextureProjGrad1DU2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DU2:
		case ast::expr::TextureAccess::eTextureProj1DShadowF:
		case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjLod1DShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
			config.requiresProjectTexCoords2 = true;
			break;

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
			config.requiresProjectTexCoords4To1 = true;
			break;

		case ast::expr::TextureAccess::eTextureProj2DF3:
		case ast::expr::TextureAccess::eTextureProj2DRectF3:
		case ast::expr::TextureAccess::eTextureProj2DI3:
		case ast::expr::TextureAccess::eTextureProj2DRectI3:
		case ast::expr::TextureAccess::eTextureProj2DU3:
		case ast::expr::TextureAccess::eTextureProj2DRectU3:
		case ast::expr::TextureAccess::eTextureProj2DF3Bias:
		case ast::expr::TextureAccess::eTextureProj2DI3Bias:
		case ast::expr::TextureAccess::eTextureProj2DU3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectF3:
		case ast::expr::TextureAccess::eTextureProjOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectI3:
		case ast::expr::TextureAccess::eTextureProjOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectU3:
		case ast::expr::TextureAccess::eTextureProjOffset2DF3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DI3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DU3Bias:
		case ast::expr::TextureAccess::eTextureProjLod2DF3:
		case ast::expr::TextureAccess::eTextureProjLod2DI3:
		case ast::expr::TextureAccess::eTextureProjLod2DU3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjGrad2DF3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectF3:
		case ast::expr::TextureAccess::eTextureProjGrad2DI3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectI3:
		case ast::expr::TextureAccess::eTextureProjGrad2DU3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU3:
		case ast::expr::TextureAccess::eTextureProj2DShadowF:
		case ast::expr::TextureAccess::eTextureProj2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjLod2DShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
			config.requiresProjectTexCoords3 = true;
			break;

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
			config.requiresProjectTexCoords4To2 = true;
			break;

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
			config.requiresProjectTexCoords4 = true;
			break;

		default:
			break;
		}
	}
}

#endif
