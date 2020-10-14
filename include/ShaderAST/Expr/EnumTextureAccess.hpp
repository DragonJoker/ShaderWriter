/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprEnumTextureAccess_H___
#define ___AST_ExprEnumTextureAccess_H___
#pragma once

namespace ast::expr
{
	enum class TextureAccess: uint32_t
	{
		eUndefined,
	// Texture Query Functions
		eTextureSize1DF,
		eTextureSize2DF,
		eTextureSize3DF,
		eTextureSizeCubeF,
		eTextureSize1DShadowF,
		eTextureSize2DShadowF,
		eTextureSizeCubeShadowF,
		eTextureSizeCubeArrayF,
		eTextureSizeCubeArrayShadowF,
		eTextureSize2DRectF,
		eTextureSize2DRectShadowF,
		eTextureSize1DArrayF,
		eTextureSize2DArrayF,
		eTextureSize1DArrayShadowF,
		eTextureSize2DArrayShadowF,
		eTextureSizeBufferF,
		eTextureSize1DI,
		eTextureSize2DI,
		eTextureSize3DI,
		eTextureSizeCubeI,
		eTextureSizeCubeArrayI,
		eTextureSize2DRectI,
		eTextureSize1DArrayI,
		eTextureSize2DArrayI,
		eTextureSizeBufferI,
		eTextureSize1DU,
		eTextureSize2DU,
		eTextureSize3DU,
		eTextureSizeCubeU,
		eTextureSizeCubeArrayU,
		eTextureSize2DRectU,
		eTextureSize1DArrayU,
		eTextureSize2DArrayU,
		eTextureSizeBufferU,
		eTextureQueryLod1DF,
		eTextureQueryLod2DF,
		eTextureQueryLod3DF,
		eTextureQueryLodCubeF,
		eTextureQueryLod1DArrayF,
		eTextureQueryLod2DArrayF,
		eTextureQueryLodCubeArrayF,
		eTextureQueryLod1DShadowF,
		eTextureQueryLod2DShadowF,
		eTextureQueryLodCubeShadowF,
		eTextureQueryLod1DArrayShadowF,
		eTextureQueryLod2DArrayShadowF,
		eTextureQueryLodCubeArrayShadowF,
		eTextureQueryLod1DI,
		eTextureQueryLod2DI,
		eTextureQueryLod3DI,
		eTextureQueryLodCubeI,
		eTextureQueryLod1DArrayI,
		eTextureQueryLod2DArrayI,
		eTextureQueryLodCubeArrayI,
		eTextureQueryLod1DU,
		eTextureQueryLod2DU,
		eTextureQueryLod3DU,
		eTextureQueryLodCubeU,
		eTextureQueryLod1DArrayU,
		eTextureQueryLod2DArrayU,
		eTextureQueryLodCubeArrayU,
		eTextureQueryLevels1DF,
		eTextureQueryLevels2DF,
		eTextureQueryLevels3DF,
		eTextureQueryLevelsCubeF,
		eTextureQueryLevels1DArrayF,
		eTextureQueryLevels2DArrayF,
		eTextureQueryLevelsCubeArrayF,
		eTextureQueryLevels1DShadowF,
		eTextureQueryLevels2DShadowF,
		eTextureQueryLevelsCubeShadowF,
		eTextureQueryLevels1DArrayShadowF,
		eTextureQueryLevels2DArrayShadowF,
		eTextureQueryLevelsCubeArrayShadowF,
		eTextureQueryLevels1DI,
		eTextureQueryLevels2DI,
		eTextureQueryLevels3DI,
		eTextureQueryLevelsCubeI,
		eTextureQueryLevels1DArrayI,
		eTextureQueryLevels2DArrayI,
		eTextureQueryLevelsCubeArrayI,
		eTextureQueryLevels1DU,
		eTextureQueryLevels2DU,
		eTextureQueryLevels3DU,
		eTextureQueryLevelsCubeU,
		eTextureQueryLevels1DArrayU,
		eTextureQueryLevels2DArrayU,
		eTextureQueryLevelsCubeArrayU,

	// Texel Lookup Functions
		eTexture1DF,
		eTexture1DFBias,
		eTexture2DF,
		eTexture2DFBias,
		eTexture3DF,
		eTexture3DFBias,
		eTextureCubeF,
		eTextureCubeFBias,
		eTexture1DArrayF,
		eTexture1DArrayFBias,
		eTexture2DArrayF,
		eTexture2DArrayFBias,
		eTextureCubeArrayF,
		eTextureCubeArrayFBias,
		eTexture2DRectF,
		eTexture1DI,
		eTexture1DIBias,
		eTexture2DI,
		eTexture2DIBias,
		eTexture3DI,
		eTexture3DIBias,
		eTextureCubeI,
		eTextureCubeIBias,
		eTexture1DArrayI,
		eTexture1DArrayIBias,
		eTexture2DArrayI,
		eTexture2DArrayIBias,
		eTextureCubeArrayI,
		eTextureCubeArrayIBias,
		eTexture2DRectI,
		eTexture1DU,
		eTexture1DUBias,
		eTexture2DU,
		eTexture2DUBias,
		eTexture3DU,
		eTexture3DUBias,
		eTextureCubeU,
		eTextureCubeUBias,
		eTexture1DArrayU,
		eTexture1DArrayUBias,
		eTexture2DArrayU,
		eTexture2DArrayUBias,
		eTextureCubeArrayU,
		eTextureCubeArrayUBias,
		eTexture2DRectU,
		eTextureProj1DF2,
		eTextureProj1DF2Bias,
		eTextureProj1DF4,
		eTextureProj1DF4Bias,
		eTextureProj2DF3,
		eTextureProj2DF3Bias,
		eTextureProj2DF4,
		eTextureProj2DF4Bias,
		eTextureProj3DF,
		eTextureProj3DFBias,
		eTextureProj2DRectF3,
		eTextureProj2DRectF4,
		eTextureProj1DI2,
		eTextureProj1DI2Bias,
		eTextureProj1DI4,
		eTextureProj1DI4Bias,
		eTextureProj2DI3,
		eTextureProj2DI3Bias,
		eTextureProj2DI4,
		eTextureProj2DI4Bias,
		eTextureProj3DI,
		eTextureProj3DIBias,
		eTextureProj2DRectI3,
		eTextureProj2DRectI4,
		eTextureProj1DU2,
		eTextureProj1DU2Bias,
		eTextureProj1DU4,
		eTextureProj1DU4Bias,
		eTextureProj2DU3,
		eTextureProj2DU3Bias,
		eTextureProj2DU4,
		eTextureProj2DU4Bias,
		eTextureProj3DU,
		eTextureProj3DUBias,
		eTextureProj2DRectU3,
		eTextureProj2DRectU4,
		eTextureLod1DF,
		eTextureLod2DF,
		eTextureLod3DF,
		eTextureLodCubeF,
		eTextureLod1DArrayF,
		eTextureLod2DArrayF,
		eTextureLodCubeArrayF,
		eTextureLod1DI,
		eTextureLod2DI,
		eTextureLod3DI,
		eTextureLodCubeI,
		eTextureLod1DArrayI,
		eTextureLod2DArrayI,
		eTextureLodCubeArrayI,
		eTextureLod1DU,
		eTextureLod2DU,
		eTextureLod3DU,
		eTextureLodCubeU,
		eTextureLod1DArrayU,
		eTextureLod2DArrayU,
		eTextureLodCubeArrayU,
		eTextureOffset1DF,
		eTextureOffset1DFBias,
		eTextureOffset2DF,
		eTextureOffset2DFBias,
		eTextureOffset3DF,
		eTextureOffset3DFBias,
		eTextureOffset2DRectF,
		eTextureOffset1DArrayF,
		eTextureOffset1DArrayFBias,
		eTextureOffset2DArrayF,
		eTextureOffset2DArrayFBias,
		eTextureOffset1DI,
		eTextureOffset1DIBias,
		eTextureOffset2DI,
		eTextureOffset2DIBias,
		eTextureOffset3DI,
		eTextureOffset3DIBias,
		eTextureOffset2DRectI,
		eTextureOffset1DArrayI,
		eTextureOffset1DArrayIBias,
		eTextureOffset2DArrayI,
		eTextureOffset2DArrayIBias,
		eTextureOffset1DU,
		eTextureOffset1DUBias,
		eTextureOffset2DU,
		eTextureOffset2DUBias,
		eTextureOffset3DU,
		eTextureOffset3DUBias,
		eTextureOffset2DRectU,
		eTextureOffset1DArrayU,
		eTextureOffset1DArrayUBias,
		eTextureOffset2DArrayU,
		eTextureOffset2DArrayUBias,
		eTexelFetch1DF,
		eTexelFetch2DF,
		eTexelFetch3DF,
		eTexelFetch2DRectF,
		eTexelFetch1DArrayF,
		eTexelFetch2DArrayF,
		eTexelFetchBufferF,
		eTexelFetch1DI,
		eTexelFetch2DI,
		eTexelFetch3DI,
		eTexelFetch2DRectI,
		eTexelFetch1DArrayI,
		eTexelFetch2DArrayI,
		eTexelFetchBufferI,
		eTexelFetch1DU,
		eTexelFetch2DU,
		eTexelFetch3DU,
		eTexelFetch2DRectU,
		eTexelFetch1DArrayU,
		eTexelFetch2DArrayU,
		eTexelFetchBufferU,
		eTexelFetchOffset1DF,
		eTexelFetchOffset2DF,
		eTexelFetchOffset3DF,
		eTexelFetchOffset2DRectF,
		eTexelFetchOffset1DArrayF,
		eTexelFetchOffset2DArrayF,
		eTexelFetchOffset1DI,
		eTexelFetchOffset2DI,
		eTexelFetchOffset3DI,
		eTexelFetchOffset2DRectI,
		eTexelFetchOffset1DArrayI,
		eTexelFetchOffset2DArrayI,
		eTexelFetchOffset1DU,
		eTexelFetchOffset2DU,
		eTexelFetchOffset3DU,
		eTexelFetchOffset2DRectU,
		eTexelFetchOffset1DArrayU,
		eTexelFetchOffset2DArrayU,
		eTextureProjOffset1DF2,
		eTextureProjOffset1DF2Bias,
		eTextureProjOffset1DF4,
		eTextureProjOffset1DF4Bias,
		eTextureProjOffset2DF3,
		eTextureProjOffset2DF3Bias,
		eTextureProjOffset2DF4,
		eTextureProjOffset2DF4Bias,
		eTextureProjOffset3DF,
		eTextureProjOffset3DFBias,
		eTextureProjOffset2DRectF3,
		eTextureProjOffset2DRectF4,
		eTextureProjOffset1DI2,
		eTextureProjOffset1DI2Bias,
		eTextureProjOffset1DI4,
		eTextureProjOffset1DI4Bias,
		eTextureProjOffset2DI3,
		eTextureProjOffset2DI3Bias,
		eTextureProjOffset2DI4,
		eTextureProjOffset2DI4Bias,
		eTextureProjOffset3DI,
		eTextureProjOffset3DIBias,
		eTextureProjOffset2DRectI3,
		eTextureProjOffset2DRectI4,
		eTextureProjOffset1DU2,
		eTextureProjOffset1DU2Bias,
		eTextureProjOffset1DU4,
		eTextureProjOffset1DU4Bias,
		eTextureProjOffset2DU3,
		eTextureProjOffset2DU3Bias,
		eTextureProjOffset2DU4,
		eTextureProjOffset2DU4Bias,
		eTextureProjOffset3DU,
		eTextureProjOffset3DUBias,
		eTextureProjOffset2DRectU3,
		eTextureProjOffset2DRectU4,
		eTextureLodOffset1DF,
		eTextureLodOffset2DF,
		eTextureLodOffset3DF,
		eTextureLodOffset1DArrayF,
		eTextureLodOffset2DArrayF,
		eTextureLodOffset1DI,
		eTextureLodOffset2DI,
		eTextureLodOffset3DI,
		eTextureLodOffset1DArrayI,
		eTextureLodOffset2DArrayI,
		eTextureLodOffset1DU,
		eTextureLodOffset2DU,
		eTextureLodOffset3DU,
		eTextureLodOffset1DArrayU,
		eTextureLodOffset2DArrayU,
		eTextureProjLod1DF2,
		eTextureProjLod1DF4,
		eTextureProjLod2DF3,
		eTextureProjLod2DF4,
		eTextureProjLod3DF,
		eTextureProjLod1DI2,
		eTextureProjLod1DI4,
		eTextureProjLod2DI3,
		eTextureProjLod2DI4,
		eTextureProjLod3DI,
		eTextureProjLod1DU2,
		eTextureProjLod1DU4,
		eTextureProjLod2DU3,
		eTextureProjLod2DU4,
		eTextureProjLod3DU,
		eTextureProjLodOffset1DF2,
		eTextureProjLodOffset1DF4,
		eTextureProjLodOffset2DF3,
		eTextureProjLodOffset2DF4,
		eTextureProjLodOffset3DF,
		eTextureProjLodOffset1DI2,
		eTextureProjLodOffset1DI4,
		eTextureProjLodOffset2DI3,
		eTextureProjLodOffset2DI4,
		eTextureProjLodOffset3DI,
		eTextureProjLodOffset1DU2,
		eTextureProjLodOffset1DU4,
		eTextureProjLodOffset2DU3,
		eTextureProjLodOffset2DU4,
		eTextureProjLodOffset3DU,
		eTextureGrad1DF,
		eTextureGrad2DF,
		eTextureGrad3DF,
		eTextureGradCubeF,
		eTextureGrad2DRectF,
		eTextureGrad1DArrayF,
		eTextureGrad2DArrayF,
		eTextureGradCubeArrayF,
		eTextureGrad1DI,
		eTextureGrad2DI,
		eTextureGrad3DI,
		eTextureGradCubeI,
		eTextureGrad2DRectI,
		eTextureGrad1DArrayI,
		eTextureGrad2DArrayI,
		eTextureGradCubeArrayI,
		eTextureGrad1DU,
		eTextureGrad2DU,
		eTextureGrad3DU,
		eTextureGradCubeU,
		eTextureGrad2DRectU,
		eTextureGrad1DArrayU,
		eTextureGrad2DArrayU,
		eTextureGradCubeArrayU,
		eTextureGradOffset1DF,
		eTextureGradOffset2DF,
		eTextureGradOffset3DF,
		eTextureGradOffset2DRectF,
		eTextureGradOffset1DArrayF,
		eTextureGradOffset2DArrayF,
		eTextureGradOffset1DI,
		eTextureGradOffset2DI,
		eTextureGradOffset3DI,
		eTextureGradOffset2DRectI,
		eTextureGradOffset1DArrayI,
		eTextureGradOffset2DArrayI,
		eTextureGradOffset1DU,
		eTextureGradOffset2DU,
		eTextureGradOffset3DU,
		eTextureGradOffset2DRectU,
		eTextureGradOffset1DArrayU,
		eTextureGradOffset2DArrayU,
		eTextureProjGrad1DF2,
		eTextureProjGrad1DF4,
		eTextureProjGrad2DF3,
		eTextureProjGrad2DF4,
		eTextureProjGrad3DF,
		eTextureProjGrad2DRectF3,
		eTextureProjGrad2DRectF4,
		eTextureProjGrad1DI2,
		eTextureProjGrad1DI4,
		eTextureProjGrad2DI3,
		eTextureProjGrad2DI4,
		eTextureProjGrad3DI,
		eTextureProjGrad2DRectI3,
		eTextureProjGrad2DRectI4,
		eTextureProjGrad1DU2,
		eTextureProjGrad1DU4,
		eTextureProjGrad2DU3,
		eTextureProjGrad2DU4,
		eTextureProjGrad3DU,
		eTextureProjGrad2DRectU3,
		eTextureProjGrad2DRectU4,
		eTextureProjGradOffset1DF2,
		eTextureProjGradOffset1DF4,
		eTextureProjGradOffset2DF3,
		eTextureProjGradOffset2DF4,
		eTextureProjGradOffset3DF,
		eTextureProjGradOffset2DRectF3,
		eTextureProjGradOffset2DRectF4,
		eTextureProjGradOffset1DI2,
		eTextureProjGradOffset1DI4,
		eTextureProjGradOffset2DI3,
		eTextureProjGradOffset2DI4,
		eTextureProjGradOffset3DI,
		eTextureProjGradOffset2DRectI3,
		eTextureProjGradOffset2DRectI4,
		eTextureProjGradOffset1DU2,
		eTextureProjGradOffset1DU4,
		eTextureProjGradOffset2DU3,
		eTextureProjGradOffset2DU4,
		eTextureProjGradOffset3DU,
		eTextureProjGradOffset2DRectU3,
		eTextureProjGradOffset2DRectU4,
	
	// Texel Compare Functions
		eTexture1DShadowF,
		eTexture1DShadowFBias,
		eTexture2DShadowF,
		eTexture2DShadowFBias,
		eTextureCubeShadowF,
		eTextureCubeShadowFBias,
		eTexture1DArrayShadowF,
		eTexture1DArrayShadowFBias,
		eTexture2DArrayShadowF,
		eTexture2DRectShadowF,
		eTextureCubeArrayShadowF,
		eTextureProj1DShadowF,
		eTextureProj1DShadowFBias,
		eTextureProj2DShadowF,
		eTextureProj2DShadowFBias,
		eTextureProj2DRectShadowF,
		eTextureLod1DShadowF,
		eTextureLod2DShadowF,
		eTextureLod1DArrayShadowF,
		eTextureOffset2DRectShadowF,
		eTextureOffset1DShadowF,
		eTextureOffset1DShadowFBias,
		eTextureOffset2DShadowF,
		eTextureOffset2DShadowFBias,
		eTextureOffset1DArrayShadowF,
		eTextureOffset2DArrayShadowF,
		eTextureProjOffset1DShadowF,
		eTextureProjOffset1DShadowFBias,
		eTextureProjOffset2DShadowF,
		eTextureProjOffset2DShadowFBias,
		eTextureProjOffset2DRectShadowF,
		eTextureLodOffset1DShadowF,
		eTextureLodOffset2DShadowF,
		eTextureLodOffset1DArrayShadowF,
		eTextureProjLod1DShadowF,
		eTextureProjLod2DShadowF,
		eTextureProjLodOffset1DShadowF,
		eTextureProjLodOffset2DShadowF,
		eTextureGrad2DRectShadowF,
		eTextureGrad1DShadowF,
		eTextureGrad2DShadowF,
		eTextureGrad1DArrayShadowF,
		eTextureGradOffset2DRectShadowF,
		eTextureGradOffset1DShadowF,
		eTextureGradOffset2DShadowF,
		eTextureGradOffset1DArrayShadowF,
		eTextureGradOffset2DArrayShadowF,
		eTextureProjGrad1DShadowF,
		eTextureProjGrad2DShadowF,
		eTextureProjGrad2DRectShadowF,
		eTextureProjGradOffset1DShadowF,
		eTextureProjGradOffset2DShadowF,
		eTextureProjGradOffset2DRectShadowF,

	// Texture Gather Functions
		eTextureGather2DF,
		eTextureGather2DFComp,
		eTextureGather2DArrayF,
		eTextureGather2DArrayFComp,
		eTextureGatherCubeF,
		eTextureGatherCubeFComp,
		eTextureGatherCubeArrayF,
		eTextureGatherCubeArrayFComp,
		eTextureGather2DRectF,
		eTextureGather2DRectFComp,
		eTextureGather2DI,
		eTextureGather2DIComp,
		eTextureGather2DArrayI,
		eTextureGather2DArrayIComp,
		eTextureGatherCubeI,
		eTextureGatherCubeIComp,
		eTextureGatherCubeArrayI,
		eTextureGatherCubeArrayIComp,
		eTextureGather2DRectI,
		eTextureGather2DRectIComp,
		eTextureGather2DU,
		eTextureGather2DUComp,
		eTextureGather2DArrayU,
		eTextureGather2DArrayUComp,
		eTextureGatherCubeU,
		eTextureGatherCubeUComp,
		eTextureGatherCubeArrayU,
		eTextureGatherCubeArrayUComp,
		eTextureGather2DRectU,
		eTextureGather2DRectUComp,
		eTextureGatherOffset2DF,
		eTextureGatherOffset2DFComp,
		eTextureGatherOffset2DArrayF,
		eTextureGatherOffset2DArrayFComp,
		eTextureGatherOffset2DRectF,
		eTextureGatherOffset2DRectFComp,
		eTextureGatherOffset2DI,
		eTextureGatherOffset2DIComp,
		eTextureGatherOffset2DArrayI,
		eTextureGatherOffset2DArrayIComp,
		eTextureGatherOffset2DRectI,
		eTextureGatherOffset2DRectIComp,
		eTextureGatherOffset2DU,
		eTextureGatherOffset2DUComp,
		eTextureGatherOffset2DArrayU,
		eTextureGatherOffset2DArrayUComp,
		eTextureGatherOffset2DRectU,
		eTextureGatherOffset2DRectUComp,
		eTextureGatherOffsets2DF,
		eTextureGatherOffsets2DFComp,
		eTextureGatherOffsets2DArrayF,
		eTextureGatherOffsets2DArrayFComp,
		eTextureGatherOffsets2DRectF,
		eTextureGatherOffsets2DRectFComp,
		eTextureGatherOffsets2DI,
		eTextureGatherOffsets2DIComp,
		eTextureGatherOffsets2DArrayI,
		eTextureGatherOffsets2DArrayIComp,
		eTextureGatherOffsets2DRectI,
		eTextureGatherOffsets2DRectIComp,
		eTextureGatherOffsets2DU,
		eTextureGatherOffsets2DUComp,
		eTextureGatherOffsets2DArrayU,
		eTextureGatherOffsets2DArrayUComp,
		eTextureGatherOffsets2DRectU,
		eTextureGatherOffsets2DRectUComp,

	// Texture Gather Compare Functions
		eTextureGather2DShadowF,
		eTextureGather2DArrayShadowF,
		eTextureGatherCubeShadowF,
		eTextureGatherCubeArrayShadowF,
		eTextureGather2DRectShadowF,
		eTextureGatherOffset2DShadowF,
		eTextureGatherOffset2DArrayShadowF,
		eTextureGatherOffset2DRectShadowF,
		eTextureGatherOffsets2DShadowF,
		eTextureGatherOffsets2DArrayShadowF,
		eTextureGatherOffsets2DRectShadowF,

	// Boundaries,
		eCount,
		eInvalid = ~( 0u ),
	};
}

#endif
