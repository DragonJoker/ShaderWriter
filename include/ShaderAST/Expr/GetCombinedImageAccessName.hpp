/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#ifndef ___AST_ExprGetCombinedImageAccessName_H___
#define ___AST_ExprGetCombinedImageAccessName_H___
#pragma once

#include "EnumCombinedImageAccess.hpp"
#include "ShaderAST/Shader.hpp"

#include <string>

namespace ast::expr
{
	inline std::string getName( CombinedImageAccess value )
	{
		std::string result;

		switch ( value )
		{
		case CombinedImageAccess::eUndefined:
			result = "Undefined";
			break;

		case CombinedImageAccess::eCount:
			result = "Count";
			break;

		case CombinedImageAccess::eInvalid:
			result = "Invalid";
			break;

	// Texture Query Functions
		case CombinedImageAccess::eTextureSize1DF:
			result = "TextureSize1DF";
			break;

		case CombinedImageAccess::eTextureSize2DF:
			result = "TextureSize2DF";
			break;

		case CombinedImageAccess::eTextureSize3DF:
			result = "TextureSize3DF";
			break;

		case CombinedImageAccess::eTextureSizeCubeF:
			result = "TextureSizeCubeF";
			break;

		case CombinedImageAccess::eTextureSize1DShadowF:
			result = "TextureSize1DShadowF";
			break;

		case CombinedImageAccess::eTextureSize2DShadowF:
			result = "TextureSize2DShadowF";
			break;

		case CombinedImageAccess::eTextureSizeCubeShadowF:
			result = "TextureSizeCubeShadowF";
			break;

		case CombinedImageAccess::eTextureSizeCubeArrayF:
			result = "TextureSizeCubeArrayF";
			break;

		case CombinedImageAccess::eTextureSizeCubeArrayShadowF:
			result = "TextureSizeCubeArrayShadowF";
			break;

		case CombinedImageAccess::eTextureSize1DArrayF:
			result = "TextureSize1DArrayF";
			break;

		case CombinedImageAccess::eTextureSize2DArrayF:
			result = "TextureSize2DArrayF";
			break;

		case CombinedImageAccess::eTextureSize1DArrayShadowF:
			result = "TextureSize1DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureSize2DArrayShadowF:
			result = "TextureSize2DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureSizeBufferF:
			result = "TextureSizeBufferF";
			break;

		case CombinedImageAccess::eTextureSize1DI:
			result = "TextureSize1DI";
			break;

		case CombinedImageAccess::eTextureSize2DI:
			result = "TextureSize2DI";
			break;

		case CombinedImageAccess::eTextureSize3DI:
			result = "TextureSize3DI";
			break;

		case CombinedImageAccess::eTextureSizeCubeI:
			result = "TextureSizeCubeI";
			break;

		case CombinedImageAccess::eTextureSizeCubeArrayI:
			result = "TextureSizeCubeArrayI";
			break;

		case CombinedImageAccess::eTextureSize1DArrayI:
			result = "TextureSize1DArrayI";
			break;

		case CombinedImageAccess::eTextureSize2DArrayI:
			result = "TextureSize2DArrayI";
			break;

		case CombinedImageAccess::eTextureSizeBufferI:
			result = "TextureSizeBufferI";
			break;

		case CombinedImageAccess::eTextureSize1DU:
			result = "TextureSize1DU";
			break;

		case CombinedImageAccess::eTextureSize2DU:
			result = "TextureSize2DU";
			break;

		case CombinedImageAccess::eTextureSize3DU:
			result = "TextureSize3DU";
			break;

		case CombinedImageAccess::eTextureSizeCubeU:
			result = "TextureSizeCubeU";
			break;

		case CombinedImageAccess::eTextureSizeCubeArrayU:
			result = "TextureSizeCubeArrayU";
			break;

		case CombinedImageAccess::eTextureSize1DArrayU:
			result = "TextureSize1DArrayU";
			break;

		case CombinedImageAccess::eTextureSize2DArrayU:
			result = "TextureSize2DArrayU";
			break;

		case CombinedImageAccess::eTextureSizeBufferU:
			result = "TextureSizeBufferU";
			break;

		case CombinedImageAccess::eTextureQueryLod1DF:
			result = "TextureQueryLod1DF";
			break;

		case CombinedImageAccess::eTextureQueryLod2DF:
			result = "TextureQueryLod2DF";
			break;

		case CombinedImageAccess::eTextureQueryLod3DF:
			result = "TextureQueryLod3DF";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeF:
			result = "TextureQueryLodCubeF";
			break;

		case CombinedImageAccess::eTextureQueryLod1DArrayF:
			result = "TextureQueryLod1DArrayF";
			break;

		case CombinedImageAccess::eTextureQueryLod2DArrayF:
			result = "TextureQueryLod2DArrayF";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeArrayF:
			result = "TextureQueryLodCubeArrayF";
			break;

		case CombinedImageAccess::eTextureQueryLod1DShadowF:
			result = "TextureQueryLod1DShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLod2DShadowF:
			result = "TextureQueryLod2DShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeShadowF:
			result = "TextureQueryLodCubeShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLod1DArrayShadowF:
			result = "TextureQueryLod1DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLod2DArrayShadowF:
			result = "TextureQueryLod2DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeArrayShadowF:
			result = "TextureQueryLodCubeArrayShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLod1DI:
			result = "TextureQueryLod1DI";
			break;

		case CombinedImageAccess::eTextureQueryLod2DI:
			result = "TextureQueryLod2DI";
			break;

		case CombinedImageAccess::eTextureQueryLod3DI:
			result = "TextureQueryLod3DI";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeI:
			result = "TextureQueryLodCubeI";
			break;

		case CombinedImageAccess::eTextureQueryLod1DArrayI:
			result = "TextureQueryLod1DArrayI";
			break;

		case CombinedImageAccess::eTextureQueryLod2DArrayI:
			result = "TextureQueryLod2DArrayI";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeArrayI:
			result = "TextureQueryLodCubeArrayI";
			break;

		case CombinedImageAccess::eTextureQueryLod1DU:
			result = "TextureQueryLod1DU";
			break;

		case CombinedImageAccess::eTextureQueryLod2DU:
			result = "TextureQueryLod2DU";
			break;

		case CombinedImageAccess::eTextureQueryLod3DU:
			result = "TextureQueryLod3DU";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeU:
			result = "TextureQueryLodCubeU";
			break;

		case CombinedImageAccess::eTextureQueryLod1DArrayU:
			result = "TextureQueryLod1DArrayU";
			break;

		case CombinedImageAccess::eTextureQueryLod2DArrayU:
			result = "TextureQueryLod2DArrayU";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeArrayU:
			result = "TextureQueryLodCubeArrayU";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DF:
			result = "TextureQueryLevels1DF";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DF:
			result = "TextureQueryLevels2DF";
			break;

		case CombinedImageAccess::eTextureQueryLevels3DF:
			result = "TextureQueryLevels3DF";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeF:
			result = "TextureQueryLevelsCubeF";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DArrayF:
			result = "TextureQueryLevels1DArrayF";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DArrayF:
			result = "TextureQueryLevels2DArrayF";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeArrayF:
			result = "TextureQueryLevelsCubeArrayF";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DShadowF:
			result = "TextureQueryLevels1DShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DShadowF:
			result = "TextureQueryLevels2DShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeShadowF:
			result = "TextureQueryLevelsCubeShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DArrayShadowF:
			result = "TextureQueryLevels1DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DArrayShadowF:
			result = "TextureQueryLevels2DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeArrayShadowF:
			result = "TextureQueryLevelsCubeArrayShadowF";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DI:
			result = "TextureQueryLevels1DI";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DI:
			result = "TextureQueryLevels2DI";
			break;

		case CombinedImageAccess::eTextureQueryLevels3DI:
			result = "TextureQueryLevels3DI";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeI:
			result = "TextureQueryLevelsCubeI";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DArrayI:
			result = "TextureQueryLevels1DArrayI";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DArrayI:
			result = "TextureQueryLevels2DArrayI";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeArrayI:
			result = "TextureQueryLevelsCubeArrayI";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DU:
			result = "TextureQueryLevels1DU";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DU:
			result = "TextureQueryLevels2DU";
			break;

		case CombinedImageAccess::eTextureQueryLevels3DU:
			result = "TextureQueryLevels3DU";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeU:
			result = "TextureQueryLevelsCubeU";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DArrayU:
			result = "TextureQueryLevels1DArrayU";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DArrayU:
			result = "TextureQueryLevels2DArrayU";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeArrayU:
			result = "TextureQueryLevelsCubeArrayU";
			break;


	// Texel Lookup Functions
		case CombinedImageAccess::eTexture1DF:
			result = "Texture1DF";
			break;

		case CombinedImageAccess::eTexture1DFBias:
			result = "Texture1DFBias";
			break;

		case CombinedImageAccess::eTexture2DF:
			result = "Texture2DF";
			break;

		case CombinedImageAccess::eTexture2DFBias:
			result = "Texture2DFBias";
			break;

		case CombinedImageAccess::eTexture3DF:
			result = "Texture3DF";
			break;

		case CombinedImageAccess::eTexture3DFBias:
			result = "Texture3DFBias";
			break;

		case CombinedImageAccess::eTextureCubeF:
			result = "TextureCubeF";
			break;

		case CombinedImageAccess::eTextureCubeFBias:
			result = "TextureCubeFBias";
			break;

		case CombinedImageAccess::eTexture1DArrayF:
			result = "Texture1DArrayF";
			break;

		case CombinedImageAccess::eTexture1DArrayFBias:
			result = "Texture1DArrayFBias";
			break;

		case CombinedImageAccess::eTexture2DArrayF:
			result = "Texture2DArrayF";
			break;

		case CombinedImageAccess::eTexture2DArrayFBias:
			result = "Texture2DArrayFBias";
			break;

		case CombinedImageAccess::eTextureCubeArrayF:
			result = "TextureCubeArrayF";
			break;

		case CombinedImageAccess::eTextureCubeArrayFBias:
			result = "TextureCubeArrayFBias";
			break;

		case CombinedImageAccess::eTexture1DI:
			result = "Texture1DI";
			break;

		case CombinedImageAccess::eTexture1DIBias:
			result = "Texture1DIBias";
			break;

		case CombinedImageAccess::eTexture2DI:
			result = "Texture2DI";
			break;

		case CombinedImageAccess::eTexture2DIBias:
			result = "Texture2DIBias";
			break;

		case CombinedImageAccess::eTexture3DI:
			result = "Texture3DI";
			break;

		case CombinedImageAccess::eTexture3DIBias:
			result = "Texture3DIBias";
			break;

		case CombinedImageAccess::eTextureCubeI:
			result = "TextureCubeI";
			break;

		case CombinedImageAccess::eTextureCubeIBias:
			result = "TextureCubeIBias";
			break;

		case CombinedImageAccess::eTexture1DArrayI:
			result = "Texture1DArrayI";
			break;

		case CombinedImageAccess::eTexture1DArrayIBias:
			result = "Texture1DArrayIBias";
			break;

		case CombinedImageAccess::eTexture2DArrayI:
			result = "Texture2DArrayI";
			break;

		case CombinedImageAccess::eTexture2DArrayIBias:
			result = "Texture2DArrayIBias";
			break;

		case CombinedImageAccess::eTextureCubeArrayI:
			result = "TextureCubeArrayI";
			break;

		case CombinedImageAccess::eTextureCubeArrayIBias:
			result = "TextureCubeArrayIBias";
			break;

		case CombinedImageAccess::eTexture1DU:
			result = "Texture1DU";
			break;

		case CombinedImageAccess::eTexture1DUBias:
			result = "Texture1DUBias";
			break;

		case CombinedImageAccess::eTexture2DU:
			result = "Texture2DU";
			break;

		case CombinedImageAccess::eTexture2DUBias:
			result = "Texture2DUBias";
			break;

		case CombinedImageAccess::eTexture3DU:
			result = "Texture3DU";
			break;

		case CombinedImageAccess::eTexture3DUBias:
			result = "Texture3DUBias";
			break;

		case CombinedImageAccess::eTextureCubeU:
			result = "TextureCubeU";
			break;

		case CombinedImageAccess::eTextureCubeUBias:
			result = "TextureCubeUBias";
			break;

		case CombinedImageAccess::eTexture1DArrayU:
			result = "Texture1DArrayU";
			break;

		case CombinedImageAccess::eTexture1DArrayUBias:
			result = "Texture1DArrayUBias";
			break;

		case CombinedImageAccess::eTexture2DArrayU:
			result = "Texture2DArrayU";
			break;

		case CombinedImageAccess::eTexture2DArrayUBias:
			result = "Texture2DArrayUBias";
			break;

		case CombinedImageAccess::eTextureCubeArrayU:
			result = "TextureCubeArrayU";
			break;

		case CombinedImageAccess::eTextureCubeArrayUBias:
			result = "TextureCubeArrayUBias";
			break;

		case CombinedImageAccess::eTextureProj1DF2:
			result = "TextureProj1DF2";
			break;

		case CombinedImageAccess::eTextureProj1DF2Bias:
			result = "TextureProj1DF2Bias";
			break;

		case CombinedImageAccess::eTextureProj1DF4:
			result = "TextureProj1DF4";
			break;

		case CombinedImageAccess::eTextureProj1DF4Bias:
			result = "TextureProj1DF4Bias";
			break;

		case CombinedImageAccess::eTextureProj2DF3:
			result = "TextureProj2DF3";
			break;

		case CombinedImageAccess::eTextureProj2DF3Bias:
			result = "TextureProj2DF3Bias";
			break;

		case CombinedImageAccess::eTextureProj2DF4:
			result = "TextureProj2DF4";
			break;

		case CombinedImageAccess::eTextureProj2DF4Bias:
			result = "TextureProj2DF4Bias";
			break;

		case CombinedImageAccess::eTextureProj3DF:
			result = "TextureProj3DF";
			break;

		case CombinedImageAccess::eTextureProj3DFBias:
			result = "TextureProj3DFBias";
			break;

		case CombinedImageAccess::eTextureProj1DI2:
			result = "TextureProj1DI2";
			break;

		case CombinedImageAccess::eTextureProj1DI2Bias:
			result = "TextureProj1DI2Bias";
			break;

		case CombinedImageAccess::eTextureProj1DI4:
			result = "TextureProj1DI4";
			break;

		case CombinedImageAccess::eTextureProj1DI4Bias:
			result = "TextureProj1DI4Bias";
			break;

		case CombinedImageAccess::eTextureProj2DI3:
			result = "TextureProj2DI3";
			break;

		case CombinedImageAccess::eTextureProj2DI3Bias:
			result = "TextureProj2DI3Bias";
			break;

		case CombinedImageAccess::eTextureProj2DI4:
			result = "TextureProj2DI4";
			break;

		case CombinedImageAccess::eTextureProj2DI4Bias:
			result = "TextureProj2DI4Bias";
			break;

		case CombinedImageAccess::eTextureProj3DI:
			result = "TextureProj3DI";
			break;

		case CombinedImageAccess::eTextureProj3DIBias:
			result = "TextureProj3DIBias";
			break;

		case CombinedImageAccess::eTextureProj1DU2:
			result = "TextureProj1DU2";
			break;

		case CombinedImageAccess::eTextureProj1DU2Bias:
			result = "TextureProj1DU2Bias";
			break;

		case CombinedImageAccess::eTextureProj1DU4:
			result = "TextureProj1DU4";
			break;

		case CombinedImageAccess::eTextureProj1DU4Bias:
			result = "TextureProj1DU4Bias";
			break;

		case CombinedImageAccess::eTextureProj2DU3:
			result = "TextureProj2DU3";
			break;

		case CombinedImageAccess::eTextureProj2DU3Bias:
			result = "TextureProj2DU3Bias";
			break;

		case CombinedImageAccess::eTextureProj2DU4:
			result = "TextureProj2DU4";
			break;

		case CombinedImageAccess::eTextureProj2DU4Bias:
			result = "TextureProj2DU4Bias";
			break;

		case CombinedImageAccess::eTextureProj3DU:
			result = "TextureProj3DU";
			break;

		case CombinedImageAccess::eTextureProj3DUBias:
			result = "TextureProj3DUBias";
			break;

		case CombinedImageAccess::eTextureLod1DF:
			result = "TextureLod1DF";
			break;

		case CombinedImageAccess::eTextureLod2DF:
			result = "TextureLod2DF";
			break;

		case CombinedImageAccess::eTextureLod3DF:
			result = "TextureLod3DF";
			break;

		case CombinedImageAccess::eTextureLodCubeF:
			result = "TextureLodCubeF";
			break;

		case CombinedImageAccess::eTextureLod1DArrayF:
			result = "TextureLod1DArrayF";
			break;

		case CombinedImageAccess::eTextureLod2DArrayF:
			result = "TextureLod2DArrayF";
			break;

		case CombinedImageAccess::eTextureLodCubeArrayF:
			result = "TextureLodCubeArrayF";
			break;

		case CombinedImageAccess::eTextureLod1DI:
			result = "TextureLod1DI";
			break;

		case CombinedImageAccess::eTextureLod2DI:
			result = "TextureLod2DI";
			break;

		case CombinedImageAccess::eTextureLod3DI:
			result = "TextureLod3DI";
			break;

		case CombinedImageAccess::eTextureLodCubeI:
			result = "TextureLodCubeI";
			break;

		case CombinedImageAccess::eTextureLod1DArrayI:
			result = "TextureLod1DArrayI";
			break;

		case CombinedImageAccess::eTextureLod2DArrayI:
			result = "TextureLod2DArrayI";
			break;

		case CombinedImageAccess::eTextureLodCubeArrayI:
			result = "TextureLodCubeArrayI";
			break;

		case CombinedImageAccess::eTextureLod1DU:
			result = "TextureLod1DU";
			break;

		case CombinedImageAccess::eTextureLod2DU:
			result = "TextureLod2DU";
			break;

		case CombinedImageAccess::eTextureLod3DU:
			result = "TextureLod3DU";
			break;

		case CombinedImageAccess::eTextureLodCubeU:
			result = "TextureLodCubeU";
			break;

		case CombinedImageAccess::eTextureLod1DArrayU:
			result = "TextureLod1DArrayU";
			break;

		case CombinedImageAccess::eTextureLod2DArrayU:
			result = "TextureLod2DArrayU";
			break;

		case CombinedImageAccess::eTextureLodCubeArrayU:
			result = "TextureLodCubeArrayU";
			break;

		case CombinedImageAccess::eTextureOffset1DF:
			result = "TextureOffset1DF";
			break;

		case CombinedImageAccess::eTextureOffset1DFBias:
			result = "TextureOffset1DFBias";
			break;

		case CombinedImageAccess::eTextureOffset2DF:
			result = "TextureOffset2DF";
			break;

		case CombinedImageAccess::eTextureOffset2DFBias:
			result = "TextureOffset2DFBias";
			break;

		case CombinedImageAccess::eTextureOffset3DF:
			result = "TextureOffset3DF";
			break;

		case CombinedImageAccess::eTextureOffset3DFBias:
			result = "TextureOffset3DFBias";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayF:
			result = "TextureOffset1DArrayF";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayFBias:
			result = "TextureOffset1DArrayFBias";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayF:
			result = "TextureOffset2DArrayF";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayFBias:
			result = "TextureOffset2DArrayFBias";
			break;

		case CombinedImageAccess::eTextureOffset1DI:
			result = "TextureOffset1DI";
			break;

		case CombinedImageAccess::eTextureOffset1DIBias:
			result = "TextureOffset1DIBias";
			break;

		case CombinedImageAccess::eTextureOffset2DI:
			result = "TextureOffset2DI";
			break;

		case CombinedImageAccess::eTextureOffset2DIBias:
			result = "TextureOffset2DIBias";
			break;

		case CombinedImageAccess::eTextureOffset3DI:
			result = "TextureOffset3DI";
			break;

		case CombinedImageAccess::eTextureOffset3DIBias:
			result = "TextureOffset3DIBias";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayI:
			result = "TextureOffset1DArrayI";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayIBias:
			result = "TextureOffset1DArrayIBias";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayI:
			result = "TextureOffset2DArrayI";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayIBias:
			result = "TextureOffset2DArrayIBias";
			break;

		case CombinedImageAccess::eTextureOffset1DU:
			result = "TextureOffset1DU";
			break;

		case CombinedImageAccess::eTextureOffset1DUBias:
			result = "TextureOffset1DUBias";
			break;

		case CombinedImageAccess::eTextureOffset2DU:
			result = "TextureOffset2DU";
			break;

		case CombinedImageAccess::eTextureOffset2DUBias:
			result = "TextureOffset2DUBias";
			break;

		case CombinedImageAccess::eTextureOffset3DU:
			result = "TextureOffset3DU";
			break;

		case CombinedImageAccess::eTextureOffset3DUBias:
			result = "TextureOffset3DUBias";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayU:
			result = "TextureOffset1DArrayU";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayUBias:
			result = "TextureOffset1DArrayUBias";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayU:
			result = "TextureOffset2DArrayU";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayUBias:
			result = "TextureOffset2DArrayUBias";
			break;

		case CombinedImageAccess::eTexelFetch1DF:
			result = "TexelFetch1DF";
			break;

		case CombinedImageAccess::eTexelFetch2DF:
			result = "TexelFetch2DF";
			break;

		case CombinedImageAccess::eTexelFetch3DF:
			result = "TexelFetch3DF";
			break;

		case CombinedImageAccess::eTexelFetch1DArrayF:
			result = "TexelFetch1DArrayF";
			break;

		case CombinedImageAccess::eTexelFetch2DArrayF:
			result = "TexelFetch2DArrayF";
			break;

		case CombinedImageAccess::eTexelFetchBufferF:
			result = "TexelFetchBufferF";
			break;

		case CombinedImageAccess::eTexelFetch1DI:
			result = "TexelFetch1DI";
			break;

		case CombinedImageAccess::eTexelFetch2DI:
			result = "TexelFetch2DI";
			break;

		case CombinedImageAccess::eTexelFetch3DI:
			result = "TexelFetch3DI";
			break;

		case CombinedImageAccess::eTexelFetch1DArrayI:
			result = "TexelFetch1DArrayI";
			break;

		case CombinedImageAccess::eTexelFetch2DArrayI:
			result = "TexelFetch2DArrayI";
			break;

		case CombinedImageAccess::eTexelFetchBufferI:
			result = "TexelFetchBufferI";
			break;

		case CombinedImageAccess::eTexelFetch1DU:
			result = "TexelFetch1DU";
			break;

		case CombinedImageAccess::eTexelFetch2DU:
			result = "TexelFetch2DU";
			break;

		case CombinedImageAccess::eTexelFetch3DU:
			result = "TexelFetch3DU";
			break;

		case CombinedImageAccess::eTexelFetch1DArrayU:
			result = "TexelFetch1DArrayU";
			break;

		case CombinedImageAccess::eTexelFetch2DArrayU:
			result = "TexelFetch2DArrayU";
			break;

		case CombinedImageAccess::eTexelFetchBufferU:
			result = "TexelFetchBufferU";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DF:
			result = "TexelFetchOffset1DF";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DF:
			result = "TexelFetchOffset2DF";
			break;

		case CombinedImageAccess::eTexelFetchOffset3DF:
			result = "TexelFetchOffset3DF";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DArrayF:
			result = "TexelFetchOffset1DArrayF";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DArrayF:
			result = "TexelFetchOffset2DArrayF";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DI:
			result = "TexelFetchOffset1DI";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DI:
			result = "TexelFetchOffset2DI";
			break;

		case CombinedImageAccess::eTexelFetchOffset3DI:
			result = "TexelFetchOffset3DI";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DArrayI:
			result = "TexelFetchOffset1DArrayI";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DArrayI:
			result = "TexelFetchOffset2DArrayI";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DU:
			result = "TexelFetchOffset1DU";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DU:
			result = "TexelFetchOffset2DU";
			break;

		case CombinedImageAccess::eTexelFetchOffset3DU:
			result = "TexelFetchOffset3DU";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DArrayU:
			result = "TexelFetchOffset1DArrayU";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DArrayU:
			result = "TexelFetchOffset2DArrayU";
			break;

		case CombinedImageAccess::eTextureProjOffset1DF2:
			result = "TextureProjOffset1DF2";
			break;

		case CombinedImageAccess::eTextureProjOffset1DF2Bias:
			result = "TextureProjOffset1DF2Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset1DF4:
			result = "TextureProjOffset1DF4";
			break;

		case CombinedImageAccess::eTextureProjOffset1DF4Bias:
			result = "TextureProjOffset1DF4Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset2DF3:
			result = "TextureProjOffset2DF3";
			break;

		case CombinedImageAccess::eTextureProjOffset2DF3Bias:
			result = "TextureProjOffset2DF3Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset2DF4:
			result = "TextureProjOffset2DF4";
			break;

		case CombinedImageAccess::eTextureProjOffset2DF4Bias:
			result = "TextureProjOffset2DF4Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset3DF:
			result = "TextureProjOffset3DF";
			break;

		case CombinedImageAccess::eTextureProjOffset3DFBias:
			result = "TextureProjOffset3DFBias";
			break;

		case CombinedImageAccess::eTextureProjOffset1DI2:
			result = "TextureProjOffset1DI2";
			break;

		case CombinedImageAccess::eTextureProjOffset1DI2Bias:
			result = "TextureProjOffset1DI2Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset1DI4:
			result = "TextureProjOffset1DI4";
			break;

		case CombinedImageAccess::eTextureProjOffset1DI4Bias:
			result = "TextureProjOffset1DI4Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset2DI3:
			result = "TextureProjOffset2DI3";
			break;

		case CombinedImageAccess::eTextureProjOffset2DI3Bias:
			result = "TextureProjOffset2DI3Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset2DI4:
			result = "TextureProjOffset2DI4";
			break;

		case CombinedImageAccess::eTextureProjOffset2DI4Bias:
			result = "TextureProjOffset2DI4Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset3DI:
			result = "TextureProjOffset3DI";
			break;

		case CombinedImageAccess::eTextureProjOffset3DIBias:
			result = "TextureProjOffset3DIBias";
			break;

		case CombinedImageAccess::eTextureProjOffset1DU2:
			result = "TextureProjOffset1DU2";
			break;

		case CombinedImageAccess::eTextureProjOffset1DU2Bias:
			result = "TextureProjOffset1DU2Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset1DU4:
			result = "TextureProjOffset1DU4";
			break;

		case CombinedImageAccess::eTextureProjOffset1DU4Bias:
			result = "TextureProjOffset1DU4Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset2DU3:
			result = "TextureProjOffset2DU3";
			break;

		case CombinedImageAccess::eTextureProjOffset2DU3Bias:
			result = "TextureProjOffset2DU3Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset2DU4:
			result = "TextureProjOffset2DU4";
			break;

		case CombinedImageAccess::eTextureProjOffset2DU4Bias:
			result = "TextureProjOffset2DU4Bias";
			break;

		case CombinedImageAccess::eTextureProjOffset3DU:
			result = "TextureProjOffset3DU";
			break;

		case CombinedImageAccess::eTextureProjOffset3DUBias:
			result = "TextureProjOffset3DUBias";
			break;

		case CombinedImageAccess::eTextureLodOffset1DF:
			result = "TextureLodOffset1DF";
			break;

		case CombinedImageAccess::eTextureLodOffset2DF:
			result = "TextureLodOffset2DF";
			break;

		case CombinedImageAccess::eTextureLodOffset3DF:
			result = "TextureLodOffset3DF";
			break;

		case CombinedImageAccess::eTextureLodOffset1DArrayF:
			result = "TextureLodOffset1DArrayF";
			break;

		case CombinedImageAccess::eTextureLodOffset2DArrayF:
			result = "TextureLodOffset2DArrayF";
			break;

		case CombinedImageAccess::eTextureLodOffset1DI:
			result = "TextureLodOffset1DI";
			break;

		case CombinedImageAccess::eTextureLodOffset2DI:
			result = "TextureLodOffset2DI";
			break;

		case CombinedImageAccess::eTextureLodOffset3DI:
			result = "TextureLodOffset3DI";
			break;

		case CombinedImageAccess::eTextureLodOffset1DArrayI:
			result = "TextureLodOffset1DArrayI";
			break;

		case CombinedImageAccess::eTextureLodOffset2DArrayI:
			result = "TextureLodOffset2DArrayI";
			break;

		case CombinedImageAccess::eTextureLodOffset1DU:
			result = "TextureLodOffset1DU";
			break;

		case CombinedImageAccess::eTextureLodOffset2DU:
			result = "TextureLodOffset2DU";
			break;

		case CombinedImageAccess::eTextureLodOffset3DU:
			result = "TextureLodOffset3DU";
			break;

		case CombinedImageAccess::eTextureLodOffset1DArrayU:
			result = "TextureLodOffset1DArrayU";
			break;

		case CombinedImageAccess::eTextureLodOffset2DArrayU:
			result = "TextureLodOffset2DArrayU";
			break;

		case CombinedImageAccess::eTextureProjLod1DF2:
			result = "TextureProjLod1DF2";
			break;

		case CombinedImageAccess::eTextureProjLod1DF4:
			result = "TextureProjLod1DF4";
			break;

		case CombinedImageAccess::eTextureProjLod2DF3:
			result = "TextureProjLod2DF3";
			break;

		case CombinedImageAccess::eTextureProjLod2DF4:
			result = "TextureProjLod2DF4";
			break;

		case CombinedImageAccess::eTextureProjLod3DF:
			result = "TextureProjLod3DF";
			break;

		case CombinedImageAccess::eTextureProjLod1DI2:
			result = "TextureProjLod1DI2";
			break;

		case CombinedImageAccess::eTextureProjLod1DI4:
			result = "TextureProjLod1DI4";
			break;

		case CombinedImageAccess::eTextureProjLod2DI3:
			result = "TextureProjLod2DI3";
			break;

		case CombinedImageAccess::eTextureProjLod2DI4:
			result = "TextureProjLod2DI4";
			break;

		case CombinedImageAccess::eTextureProjLod3DI:
			result = "TextureProjLod3DI";
			break;

		case CombinedImageAccess::eTextureProjLod1DU2:
			result = "TextureProjLod1DU2";
			break;

		case CombinedImageAccess::eTextureProjLod1DU4:
			result = "TextureProjLod1DU4";
			break;

		case CombinedImageAccess::eTextureProjLod2DU3:
			result = "TextureProjLod2DU3";
			break;

		case CombinedImageAccess::eTextureProjLod2DU4:
			result = "TextureProjLod2DU4";
			break;

		case CombinedImageAccess::eTextureProjLod3DU:
			result = "TextureProjLod3DU";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DF2:
			result = "TextureProjLodOffset1DF2";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DF4:
			result = "TextureProjLodOffset1DF4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DF3:
			result = "TextureProjLodOffset2DF3";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DF4:
			result = "TextureProjLodOffset2DF4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset3DF:
			result = "TextureProjLodOffset3DF";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DI2:
			result = "TextureProjLodOffset1DI2";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DI4:
			result = "TextureProjLodOffset1DI4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DI3:
			result = "TextureProjLodOffset2DI3";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DI4:
			result = "TextureProjLodOffset2DI4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset3DI:
			result = "TextureProjLodOffset3DI";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DU2:
			result = "TextureProjLodOffset1DU2";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DU4:
			result = "TextureProjLodOffset1DU4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DU3:
			result = "TextureProjLodOffset2DU3";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DU4:
			result = "TextureProjLodOffset2DU4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset3DU:
			result = "TextureProjLodOffset3DU";
			break;

		case CombinedImageAccess::eTextureGrad1DF:
			result = "TextureGrad1DF";
			break;

		case CombinedImageAccess::eTextureGrad2DF:
			result = "TextureGrad2DF";
			break;

		case CombinedImageAccess::eTextureGrad3DF:
			result = "TextureGrad3DF";
			break;

		case CombinedImageAccess::eTextureGradCubeF:
			result = "TextureGradCubeF";
			break;

		case CombinedImageAccess::eTextureGrad1DArrayF:
			result = "TextureGrad1DArrayF";
			break;

		case CombinedImageAccess::eTextureGrad2DArrayF:
			result = "TextureGrad2DArrayF";
			break;

		case CombinedImageAccess::eTextureGradCubeArrayF:
			result = "TextureGradCubeArrayF";
			break;

		case CombinedImageAccess::eTextureGrad1DI:
			result = "TextureGrad1DI";
			break;

		case CombinedImageAccess::eTextureGrad2DI:
			result = "TextureGrad2DI";
			break;

		case CombinedImageAccess::eTextureGrad3DI:
			result = "TextureGrad3DI";
			break;

		case CombinedImageAccess::eTextureGradCubeI:
			result = "TextureGradCubeI";
			break;

		case CombinedImageAccess::eTextureGrad1DArrayI:
			result = "TextureGrad1DArrayI";
			break;

		case CombinedImageAccess::eTextureGrad2DArrayI:
			result = "TextureGrad2DArrayI";
			break;

		case CombinedImageAccess::eTextureGradCubeArrayI:
			result = "TextureGradCubeArrayI";
			break;

		case CombinedImageAccess::eTextureGrad1DU:
			result = "TextureGrad1DU";
			break;

		case CombinedImageAccess::eTextureGrad2DU:
			result = "TextureGrad2DU";
			break;

		case CombinedImageAccess::eTextureGrad3DU:
			result = "TextureGrad3DU";
			break;

		case CombinedImageAccess::eTextureGradCubeU:
			result = "TextureGradCubeU";
			break;

		case CombinedImageAccess::eTextureGrad1DArrayU:
			result = "TextureGrad1DArrayU";
			break;

		case CombinedImageAccess::eTextureGrad2DArrayU:
			result = "TextureGrad2DArrayU";
			break;

		case CombinedImageAccess::eTextureGradCubeArrayU:
			result = "TextureGradCubeArrayU";
			break;

		case CombinedImageAccess::eTextureGradOffset1DF:
			result = "TextureGradOffset1DF";
			break;

		case CombinedImageAccess::eTextureGradOffset2DF:
			result = "TextureGradOffset2DF";
			break;

		case CombinedImageAccess::eTextureGradOffset3DF:
			result = "TextureGradOffset3DF";
			break;

		case CombinedImageAccess::eTextureGradOffset1DArrayF:
			result = "TextureGradOffset1DArrayF";
			break;

		case CombinedImageAccess::eTextureGradOffset2DArrayF:
			result = "TextureGradOffset2DArrayF";
			break;

		case CombinedImageAccess::eTextureGradOffset1DI:
			result = "TextureGradOffset1DI";
			break;

		case CombinedImageAccess::eTextureGradOffset2DI:
			result = "TextureGradOffset2DI";
			break;

		case CombinedImageAccess::eTextureGradOffset3DI:
			result = "TextureGradOffset3DI";
			break;

		case CombinedImageAccess::eTextureGradOffset1DArrayI:
			result = "TextureGradOffset1DArrayI";
			break;

		case CombinedImageAccess::eTextureGradOffset2DArrayI:
			result = "TextureGradOffset2DArrayI";
			break;

		case CombinedImageAccess::eTextureGradOffset1DU:
			result = "TextureGradOffset1DU";
			break;

		case CombinedImageAccess::eTextureGradOffset2DU:
			result = "TextureGradOffset2DU";
			break;

		case CombinedImageAccess::eTextureGradOffset3DU:
			result = "TextureGradOffset3DU";
			break;

		case CombinedImageAccess::eTextureGradOffset1DArrayU:
			result = "TextureGradOffset1DArrayU";
			break;

		case CombinedImageAccess::eTextureGradOffset2DArrayU:
			result = "TextureGradOffset2DArrayU";
			break;

		case CombinedImageAccess::eTextureProjGrad1DF2:
			result = "TextureProjGrad1DF2";
			break;

		case CombinedImageAccess::eTextureProjGrad1DF4:
			result = "TextureProjGrad1DF4";
			break;

		case CombinedImageAccess::eTextureProjGrad2DF3:
			result = "TextureProjGrad2DF3";
			break;

		case CombinedImageAccess::eTextureProjGrad2DF4:
			result = "TextureProjGrad2DF4";
			break;

		case CombinedImageAccess::eTextureProjGrad3DF:
			result = "TextureProjGrad3DF";
			break;

		case CombinedImageAccess::eTextureProjGrad1DI2:
			result = "TextureProjGrad1DI2";
			break;

		case CombinedImageAccess::eTextureProjGrad1DI4:
			result = "TextureProjGrad1DI4";
			break;

		case CombinedImageAccess::eTextureProjGrad2DI3:
			result = "TextureProjGrad2DI3";
			break;

		case CombinedImageAccess::eTextureProjGrad2DI4:
			result = "TextureProjGrad2DI4";
			break;

		case CombinedImageAccess::eTextureProjGrad3DI:
			result = "TextureProjGrad3DI";
			break;

		case CombinedImageAccess::eTextureProjGrad1DU2:
			result = "TextureProjGrad1DU2";
			break;

		case CombinedImageAccess::eTextureProjGrad1DU4:
			result = "TextureProjGrad1DU4";
			break;

		case CombinedImageAccess::eTextureProjGrad2DU3:
			result = "TextureProjGrad2DU3";
			break;

		case CombinedImageAccess::eTextureProjGrad2DU4:
			result = "TextureProjGrad2DU4";
			break;

		case CombinedImageAccess::eTextureProjGrad3DU:
			result = "TextureProjGrad3DU";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DF2:
			result = "TextureProjGradOffset1DF2";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DF4:
			result = "TextureProjGradOffset1DF4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DF3:
			result = "TextureProjGradOffset2DF3";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DF4:
			result = "TextureProjGradOffset2DF4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset3DF:
			result = "TextureProjGradOffset3DF";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DI2:
			result = "TextureProjGradOffset1DI2";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DI4:
			result = "TextureProjGradOffset1DI4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DI3:
			result = "TextureProjGradOffset2DI3";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DI4:
			result = "TextureProjGradOffset2DI4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset3DI:
			result = "TextureProjGradOffset3DI";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DU2:
			result = "TextureProjGradOffset1DU2";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DU4:
			result = "TextureProjGradOffset1DU4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DU3:
			result = "TextureProjGradOffset2DU3";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DU4:
			result = "TextureProjGradOffset2DU4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset3DU:
			result = "TextureProjGradOffset3DU";
			break;

	
	// Texel Compare Functions
		case CombinedImageAccess::eTexture1DShadowF:
			result = "Texture1DShadowF";
			break;

		case CombinedImageAccess::eTexture1DShadowFBias:
			result = "Texture1DShadowFBias";
			break;

		case CombinedImageAccess::eTexture2DShadowF:
			result = "Texture2DShadowF";
			break;

		case CombinedImageAccess::eTexture2DShadowFBias:
			result = "Texture2DShadowFBias";
			break;

		case CombinedImageAccess::eTextureCubeShadowF:
			result = "TextureCubeShadowF";
			break;

		case CombinedImageAccess::eTextureCubeShadowFBias:
			result = "TextureCubeShadowFBias";
			break;

		case CombinedImageAccess::eTexture1DArrayShadowF:
			result = "Texture1DArrayShadowF";
			break;

		case CombinedImageAccess::eTexture1DArrayShadowFBias:
			result = "Texture1DArrayShadowFBias";
			break;

		case CombinedImageAccess::eTexture2DArrayShadowF:
			result = "Texture2DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureCubeArrayShadowF:
			result = "TextureCubeArrayShadowF";
			break;

		case CombinedImageAccess::eTextureProj1DShadowF:
			result = "TextureProj1DShadowF";
			break;

		case CombinedImageAccess::eTextureProj1DShadowFBias:
			result = "TextureProj1DShadowFBias";
			break;

		case CombinedImageAccess::eTextureProj2DShadowF:
			result = "TextureProj2DShadowF";
			break;

		case CombinedImageAccess::eTextureProj2DShadowFBias:
			result = "TextureProj2DShadowFBias";
			break;

		case CombinedImageAccess::eTextureLod1DShadowF:
			result = "TextureLod1DShadowF";
			break;

		case CombinedImageAccess::eTextureLod2DShadowF:
			result = "TextureLod2DShadowF";
			break;

		case CombinedImageAccess::eTextureLodCubeShadowF:
			result = "TextureLodCubeShadowF";
			break;

		case CombinedImageAccess::eTextureLod1DArrayShadowF:
			result = "TextureLod1DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureLod2DArrayShadowF:
			result = "TextureLod2DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureLodCubeArrayShadowF:
			result = "TextureLodCubeArrayShadowF";
			break;

		case CombinedImageAccess::eTextureOffset1DShadowF:
			result = "TextureOffset1DShadowF";
			break;

		case CombinedImageAccess::eTextureOffset1DShadowFBias:
			result = "TextureOffset1DShadowFBias";
			break;

		case CombinedImageAccess::eTextureOffset2DShadowF:
			result = "TextureOffset2DShadowF";
			break;

		case CombinedImageAccess::eTextureOffset2DShadowFBias:
			result = "TextureOffset2DShadowFBias";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayShadowF:
			result = "TextureOffset1DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayShadowF:
			result = "TextureOffset2DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureProjOffset1DShadowF:
			result = "TextureProjOffset1DShadowF";
			break;

		case CombinedImageAccess::eTextureProjOffset1DShadowFBias:
			result = "TextureProjOffset1DShadowFBias";
			break;

		case CombinedImageAccess::eTextureProjOffset2DShadowF:
			result = "TextureProjOffset2DShadowF";
			break;

		case CombinedImageAccess::eTextureProjOffset2DShadowFBias:
			result = "TextureProjOffset2DShadowFBias";
			break;

		case CombinedImageAccess::eTextureLodOffset1DShadowF:
			result = "TextureLodOffset1DShadowF";
			break;

		case CombinedImageAccess::eTextureLodOffset2DShadowF:
			result = "TextureLodOffset2DShadowF";
			break;

		case CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
			result = "TextureLodOffset1DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureProjLod1DShadowF:
			result = "TextureProjLod1DShadowF";
			break;

		case CombinedImageAccess::eTextureProjLod2DShadowF:
			result = "TextureProjLod2DShadowF";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DShadowF:
			result = "TextureProjLodOffset1DShadowF";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DShadowF:
			result = "TextureProjLodOffset2DShadowF";
			break;

		case CombinedImageAccess::eTextureGrad1DShadowF:
			result = "TextureGrad1DShadowF";
			break;

		case CombinedImageAccess::eTextureGrad2DShadowF:
			result = "TextureGrad2DShadowF";
			break;

		case CombinedImageAccess::eTextureGrad1DArrayShadowF:
			result = "TextureGrad1DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureGradOffset1DShadowF:
			result = "TextureGradOffset1DShadowF";
			break;

		case CombinedImageAccess::eTextureGradOffset2DShadowF:
			result = "TextureGradOffset2DShadowF";
			break;

		case CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
			result = "TextureGradOffset1DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
			result = "TextureGradOffset2DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureProjGrad1DShadowF:
			result = "TextureProjGrad1DShadowF";
			break;

		case CombinedImageAccess::eTextureProjGrad2DShadowF:
			result = "TextureProjGrad2DShadowF";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DShadowF:
			result = "TextureProjGradOffset1DShadowF";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DShadowF:
			result = "TextureProjGradOffset2DShadowF";
			break;


	// Texture Gather Functions
		case CombinedImageAccess::eTextureGather2DF:
			result = "TextureGather2DF";
			break;

		case CombinedImageAccess::eTextureGather2DArrayF:
			result = "TextureGather2DArrayF";
			break;

		case CombinedImageAccess::eTextureGatherCubeF:
			result = "TextureGatherCubeF";
			break;

		case CombinedImageAccess::eTextureGatherCubeArrayF:
			result = "TextureGatherCubeArrayF";
			break;

		case CombinedImageAccess::eTextureGather2DI:
			result = "TextureGather2DI";
			break;

		case CombinedImageAccess::eTextureGather2DArrayI:
			result = "TextureGather2DArrayI";
			break;

		case CombinedImageAccess::eTextureGatherCubeI:
			result = "TextureGatherCubeI";
			break;

		case CombinedImageAccess::eTextureGatherCubeArrayI:
			result = "TextureGatherCubeArrayI";
			break;

		case CombinedImageAccess::eTextureGather2DU:
			result = "TextureGather2DU";
			break;

		case CombinedImageAccess::eTextureGather2DArrayU:
			result = "TextureGather2DArrayU";
			break;

		case CombinedImageAccess::eTextureGatherCubeU:
			result = "TextureGatherCubeU";
			break;

		case CombinedImageAccess::eTextureGatherCubeArrayU:
			result = "TextureGatherCubeArrayU";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DF:
			result = "TextureGatherOffset2DF";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DArrayF:
			result = "TextureGatherOffset2DArrayF";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DI:
			result = "TextureGatherOffset2DI";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DArrayI:
			result = "TextureGatherOffset2DArrayI";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DU:
			result = "TextureGatherOffset2DU";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DArrayU:
			result = "TextureGatherOffset2DArrayU";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DF:
			result = "TextureGatherOffsets2DF";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DArrayF:
			result = "TextureGatherOffsets2DArrayF";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DI:
			result = "TextureGatherOffsets2DI";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DArrayI:
			result = "TextureGatherOffsets2DArrayI";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DU:
			result = "TextureGatherOffsets2DU";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DArrayU:
			result = "TextureGatherOffsets2DArrayU";
			break;


	// Texture Gather Compare Functions
		case CombinedImageAccess::eTextureGather2DShadowF:
			result = "TextureGather2DShadowF";
			break;

		case CombinedImageAccess::eTextureGather2DArrayShadowF:
			result = "TextureGather2DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureGatherCubeShadowF:
			result = "TextureGatherCubeShadowF";
			break;

		case CombinedImageAccess::eTextureGatherCubeArrayShadowF:
			result = "TextureGatherCubeArrayShadowF";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DShadowF:
			result = "TextureGatherOffset2DShadowF";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
			result = "TextureGatherOffset2DArrayShadowF";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DShadowF:
			result = "TextureGatherOffsets2DShadowF";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
			result = "TextureGatherOffsets2DArrayShadowF";
			break;

		default:
			throw Exception{ "Unsupported CombinedImageAccess type." };
		}

		return result;
	}
}

#endif
