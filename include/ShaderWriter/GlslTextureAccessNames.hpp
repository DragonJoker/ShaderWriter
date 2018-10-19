/*
See LICENSE file in root folder
*/
#ifndef ___AST_GlslTextureAccessNames_H___
#define ___AST_GlslTextureAccessNames_H___
#pragma once

#include <ASTGenerator/Expr/EnumTextureAccess.hpp>

#include <string>

namespace sdw
{
	inline std::string getGlslName( ast::expr::TextureAccess value )
	{
		std::string result;

		switch ( value )
		{
	// Texture Query Functions
		case ast::expr::TextureAccess::eTextureSize1DF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize3DF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize1DShadowF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DShadowF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeShadowF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeArrayF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeArrayShadowF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DRectF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DRectShadowF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize1DArrayF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DArrayF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize1DArrayShadowF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DArrayShadowF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSizeBufferF:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize1DI:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DI:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize3DI:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeI:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeArrayI:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DRectI:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize1DArrayI:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DArrayI:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSizeBufferI:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize1DU:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DU:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize3DU:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeU:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSizeCubeArrayU:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DRectU:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize1DArrayU:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSize2DArrayU:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureSizeBufferU:
			result = "textureSize";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod3DF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DArrayF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DArrayF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DShadowF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DShadowF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeShadowF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DArrayShadowF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DArrayShadowF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayShadowF:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DI:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DI:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod3DI:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeI:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DArrayI:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DArrayI:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayI:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DU:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DU:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod3DU:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeU:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DArrayU:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLod2DArrayU:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayU:
			result = "textureQueryLod";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels3DF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DShadowF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DShadowF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeShadowF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayShadowF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayShadowF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayShadowF:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DI:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DI:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels3DI:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeI:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayI:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayI:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayI:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DU:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DU:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels3DU:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeU:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayU:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayU:
			result = "textureQueryLevels";
			break;

		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayU:
			result = "textureQueryLevels";
			break;


	// Texel Lookup Functions
		case ast::expr::TextureAccess::eTexture1DF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture3DF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture3DFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DShadowF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DShadowFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DShadowF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DShadowFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeShadowF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeShadowFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DArrayF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DArrayFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DArrayF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DArrayFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeArrayF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeArrayFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DArrayShadowF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DArrayShadowFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DArrayShadowF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DArrayShadowFBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DRectF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DRectShadowF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeArrayShadowF:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DI:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DIBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DI:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DIBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture3DI:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture3DIBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeI:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeIBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DArrayI:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DArrayIBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DArrayI:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DArrayIBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeArrayI:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeArrayIBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DRectI:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DU:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DUBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DU:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DUBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture3DU:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture3DUBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeU:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeUBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DArrayU:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture1DArrayUBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DArrayU:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DArrayUBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeArrayU:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureCubeArrayUBias:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTexture2DRectU:
			result = "texture";
			break;

		case ast::expr::TextureAccess::eTextureProj1DF2:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DF2Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DF4:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DF4Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DF3:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DF3Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DF4:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DF4Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj3DF:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj3DFBias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DShadowF:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DShadowF:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DRectF3:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DRectF4:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DRectShadowF:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DI2:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DI2Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DI4:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DI4Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DI3:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DI3Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DI4:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DI4Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj3DI:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj3DIBias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DRectI3:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DRectI4:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DU2:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DU2Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DU4:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj1DU4Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DU3:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DU3Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DU4:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DU4Bias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj3DU:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj3DUBias:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DRectU3:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureProj2DRectU4:
			result = "textureProj";
			break;

		case ast::expr::TextureAccess::eTextureLod1DF:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod2DF:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod3DF:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLodCubeF:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod1DShadowF:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod2DShadowF:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod1DArrayF:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod2DArrayF:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod1DArrayShadowF:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLodCubeArrayF:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod1DI:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod2DI:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod3DI:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLodCubeI:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod1DArrayI:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod2DArrayI:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLodCubeArrayI:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod1DU:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod2DU:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod3DU:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLodCubeU:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod1DArrayU:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLod2DArrayU:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureLodCubeArrayU:
			result = "textureLod";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DF:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DFBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DF:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DFBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset3DF:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset3DFBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DRectF:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DRectShadowF:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DShadowF:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DShadowFBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DShadowF:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DShadowFBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DArrayF:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DArrayFBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DArrayF:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DArrayFBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DArrayShadowF:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DArrayShadowF:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DI:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DIBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DI:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DIBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset3DI:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset3DIBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DRectI:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DArrayI:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DArrayIBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DArrayI:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DArrayIBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DU:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DUBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DU:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DUBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset3DU:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset3DUBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DRectU:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DArrayU:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset1DArrayUBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DArrayU:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTextureOffset2DArrayUBias:
			result = "textureOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetch1DF:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch2DF:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch3DF:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch2DRectF:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch1DArrayF:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch2DArrayF:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetchBufferF:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch1DI:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch2DI:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch3DI:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch2DRectI:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch1DArrayI:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch2DArrayI:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetchBufferI:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch1DU:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch2DU:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch3DU:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch2DRectU:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch1DArrayU:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetch2DArrayU:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetchBufferU:
			result = "texelFetch";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset1DF:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset2DF:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset3DF:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset2DRectF:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayF:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayF:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset1DI:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset2DI:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset3DI:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset2DRectI:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayI:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayI:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset1DU:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset2DU:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset3DU:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset2DRectU:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayU:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayU:
			result = "texelFetchOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DF2:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DF2Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DF4:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DF4Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DF3:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DF3Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DF4:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DF4Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset3DF:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset3DFBias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DShadowF:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DShadowF:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DRectF3:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DRectF4:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DI2:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DI2Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DI4:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DI4Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DI3:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DI3Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DI4:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DI4Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset3DI:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset3DIBias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DRectI3:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DRectI4:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DU2:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DU2Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DU4:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DU4Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DU3:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DU3Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DU4:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DU4Bias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset3DU:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset3DUBias:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DRectU3:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DRectU4:
			result = "textureProjOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DF:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset2DF:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset3DF:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DShadowF:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset2DShadowF:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DArrayF:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset2DArrayF:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DArrayShadowF:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DI:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset2DI:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset3DI:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DArrayI:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset2DArrayI:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DU:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset2DU:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset3DU:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DArrayU:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureLodOffset2DArrayU:
			result = "textureLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLod1DF2:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod1DF4:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod2DF3:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod2DF4:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod3DF:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod1DShadowF:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod2DShadowF:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod1DI2:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod1DI4:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod2DI3:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod2DI4:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod3DI:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod1DU2:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod1DU4:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod2DU3:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod2DU4:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLod3DU:
			result = "textureProjLod";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset1DF2:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset1DF4:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset2DF3:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset2DF4:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset3DF:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset1DI2:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset1DI4:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset2DI3:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset2DI4:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset3DI:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset1DU2:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset1DU4:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset2DU3:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset2DU4:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset3DU:
			result = "textureProjLodOffset";
			break;

		case ast::expr::TextureAccess::eTextureGrad1DF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad2DF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad3DF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGradCubeF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad2DRectF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad2DRectShadowF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad1DShadowF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad2DShadowF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad1DArrayF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad2DArrayF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad1DArrayShadowF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGradCubeArrayF:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad1DI:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad2DI:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad3DI:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGradCubeI:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad2DRectI:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad1DArrayI:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad2DArrayI:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGradCubeArrayI:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad1DU:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad2DU:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad3DU:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGradCubeU:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad2DRectU:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad1DArrayU:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGrad2DArrayU:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGradCubeArrayU:
			result = "textureGrad";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DF:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DF:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset3DF:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DRectF:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DRectShadowF:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DShadowF:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DShadowF:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DArrayF:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DArrayF:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DArrayShadowF:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DArrayShadowF:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DI:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DI:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset3DI:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DRectI:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DArrayI:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DArrayI:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DU:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DU:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset3DU:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DRectU:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DArrayU:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DArrayU:
			result = "textureGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad1DF2:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad1DF4:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DF3:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DF4:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad3DF:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DRectF3:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DRectF4:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad1DI2:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad1DI4:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DI3:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DI4:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad3DI:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DRectI3:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DRectI4:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad1DU2:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad1DU4:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DU3:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DU4:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad3DU:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DRectU3:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DRectU4:
			result = "textureProjGrad";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset1DF2:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset1DF4:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DF3:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DF4:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset3DF:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF3:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF4:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset1DI2:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset1DI4:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DI3:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DI4:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset3DI:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI3:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI4:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset1DU2:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset1DU4:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DU3:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DU4:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset3DU:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU3:
			result = "textureProjGradOffset";
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU4:
			result = "textureProjGradOffset";
			break;


	// Texture Gather Functions
		case ast::expr::TextureAccess::eTextureGather2DF:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DFComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DArrayF:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DArrayFComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeF:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeFComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeArrayF:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeArrayFComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DRectF:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DRectFComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DShadowF:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DArrayShadowF:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeShadowF:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeArrayShadowF:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DRectShadowF:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DI:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DIComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DArrayI:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DArrayIComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeI:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeIComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeArrayI:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeArrayIComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DRectI:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DRectIComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DU:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DUComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DArrayU:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DArrayUComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeU:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeUComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeArrayU:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherCubeArrayUComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DRectU:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGather2DRectUComp:
			result = "textureGather";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DF:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DFComp:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayF:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayFComp:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DRectF:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DRectFComp:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DShadowF:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayShadowF:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DRectShadowF:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DI:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DIComp:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayI:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayIComp:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DRectI:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DRectIComp:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DU:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DUComp:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayU:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayUComp:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DRectU:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffset2DRectUComp:
			result = "textureGatherOffset";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DF:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DFComp:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayF:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayFComp:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectF:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectFComp:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DShadowF:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayShadowF:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectShadowF:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DI:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DIComp:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayI:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayIComp:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectI:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectIComp:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DU:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DUComp:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayU:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayUComp:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectU:
			result = "textureGatherOffsets";
			break;

		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectUComp:
			result = "textureGatherOffsets";
			break;

		default:
			throw std::runtime_error{ "Unsupported TextureAccess type." };
		}

		return result;
	}
}

#endif
