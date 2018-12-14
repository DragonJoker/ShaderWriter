/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprGetTextureAccessName_H___
#define ___AST_ExprGetTextureAccessName_H___
#pragma once

#include "EnumTextureAccess.hpp"

#include <string>

namespace ast::expr
{
	inline std::string getName( TextureAccess value )
	{
		std::string result;

		switch ( value )
		{
	// Texture Query Functions
		case TextureAccess::eTextureSize1DF:
			result = "TEXTURESIZE1DF";
			break;

		case TextureAccess::eTextureSize2DF:
			result = "TEXTURESIZE2DF";
			break;

		case TextureAccess::eTextureSize3DF:
			result = "TEXTURESIZE3DF";
			break;

		case TextureAccess::eTextureSizeCubeF:
			result = "TEXTURESIZECUBEF";
			break;

		case TextureAccess::eTextureSize1DShadowF:
			result = "TEXTURESIZE1DSHADOWF";
			break;

		case TextureAccess::eTextureSize2DShadowF:
			result = "TEXTURESIZE2DSHADOWF";
			break;

		case TextureAccess::eTextureSizeCubeShadowF:
			result = "TEXTURESIZECUBESHADOWF";
			break;

		case TextureAccess::eTextureSizeCubeArrayF:
			result = "TEXTURESIZECUBEARRAYF";
			break;

		case TextureAccess::eTextureSizeCubeArrayShadowF:
			result = "TEXTURESIZECUBEARRAYSHADOWF";
			break;

		case TextureAccess::eTextureSize2DRectF:
			result = "TEXTURESIZE2DRECTF";
			break;

		case TextureAccess::eTextureSize2DRectShadowF:
			result = "TEXTURESIZE2DRECTSHADOWF";
			break;

		case TextureAccess::eTextureSize1DArrayF:
			result = "TEXTURESIZE1DARRAYF";
			break;

		case TextureAccess::eTextureSize2DArrayF:
			result = "TEXTURESIZE2DARRAYF";
			break;

		case TextureAccess::eTextureSize1DArrayShadowF:
			result = "TEXTURESIZE1DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureSize2DArrayShadowF:
			result = "TEXTURESIZE2DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureSizeBufferF:
			result = "TEXTURESIZEBUFFERF";
			break;

		case TextureAccess::eTextureSize1DI:
			result = "TEXTURESIZE1DI";
			break;

		case TextureAccess::eTextureSize2DI:
			result = "TEXTURESIZE2DI";
			break;

		case TextureAccess::eTextureSize3DI:
			result = "TEXTURESIZE3DI";
			break;

		case TextureAccess::eTextureSizeCubeI:
			result = "TEXTURESIZECUBEI";
			break;

		case TextureAccess::eTextureSizeCubeArrayI:
			result = "TEXTURESIZECUBEARRAYI";
			break;

		case TextureAccess::eTextureSize2DRectI:
			result = "TEXTURESIZE2DRECTI";
			break;

		case TextureAccess::eTextureSize1DArrayI:
			result = "TEXTURESIZE1DARRAYI";
			break;

		case TextureAccess::eTextureSize2DArrayI:
			result = "TEXTURESIZE2DARRAYI";
			break;

		case TextureAccess::eTextureSizeBufferI:
			result = "TEXTURESIZEBUFFERI";
			break;

		case TextureAccess::eTextureSize1DU:
			result = "TEXTURESIZE1DU";
			break;

		case TextureAccess::eTextureSize2DU:
			result = "TEXTURESIZE2DU";
			break;

		case TextureAccess::eTextureSize3DU:
			result = "TEXTURESIZE3DU";
			break;

		case TextureAccess::eTextureSizeCubeU:
			result = "TEXTURESIZECUBEU";
			break;

		case TextureAccess::eTextureSizeCubeArrayU:
			result = "TEXTURESIZECUBEARRAYU";
			break;

		case TextureAccess::eTextureSize2DRectU:
			result = "TEXTURESIZE2DRECTU";
			break;

		case TextureAccess::eTextureSize1DArrayU:
			result = "TEXTURESIZE1DARRAYU";
			break;

		case TextureAccess::eTextureSize2DArrayU:
			result = "TEXTURESIZE2DARRAYU";
			break;

		case TextureAccess::eTextureSizeBufferU:
			result = "TEXTURESIZEBUFFERU";
			break;

		case TextureAccess::eTextureQueryLod1DF:
			result = "TEXTUREQUERYLOD1DF";
			break;

		case TextureAccess::eTextureQueryLod2DF:
			result = "TEXTUREQUERYLOD2DF";
			break;

		case TextureAccess::eTextureQueryLod3DF:
			result = "TEXTUREQUERYLOD3DF";
			break;

		case TextureAccess::eTextureQueryLodCubeF:
			result = "TEXTUREQUERYLODCUBEF";
			break;

		case TextureAccess::eTextureQueryLod1DArrayF:
			result = "TEXTUREQUERYLOD1DARRAYF";
			break;

		case TextureAccess::eTextureQueryLod2DArrayF:
			result = "TEXTUREQUERYLOD2DARRAYF";
			break;

		case TextureAccess::eTextureQueryLodCubeArrayF:
			result = "TEXTUREQUERYLODCUBEARRAYF";
			break;

		case TextureAccess::eTextureQueryLod1DShadowF:
			result = "TEXTUREQUERYLOD1DSHADOWF";
			break;

		case TextureAccess::eTextureQueryLod2DShadowF:
			result = "TEXTUREQUERYLOD2DSHADOWF";
			break;

		case TextureAccess::eTextureQueryLodCubeShadowF:
			result = "TEXTUREQUERYLODCUBESHADOWF";
			break;

		case TextureAccess::eTextureQueryLod1DArrayShadowF:
			result = "TEXTUREQUERYLOD1DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureQueryLod2DArrayShadowF:
			result = "TEXTUREQUERYLOD2DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureQueryLodCubeArrayShadowF:
			result = "TEXTUREQUERYLODCUBEARRAYSHADOWF";
			break;

		case TextureAccess::eTextureQueryLod1DI:
			result = "TEXTUREQUERYLOD1DI";
			break;

		case TextureAccess::eTextureQueryLod2DI:
			result = "TEXTUREQUERYLOD2DI";
			break;

		case TextureAccess::eTextureQueryLod3DI:
			result = "TEXTUREQUERYLOD3DI";
			break;

		case TextureAccess::eTextureQueryLodCubeI:
			result = "TEXTUREQUERYLODCUBEI";
			break;

		case TextureAccess::eTextureQueryLod1DArrayI:
			result = "TEXTUREQUERYLOD1DARRAYI";
			break;

		case TextureAccess::eTextureQueryLod2DArrayI:
			result = "TEXTUREQUERYLOD2DARRAYI";
			break;

		case TextureAccess::eTextureQueryLodCubeArrayI:
			result = "TEXTUREQUERYLODCUBEARRAYI";
			break;

		case TextureAccess::eTextureQueryLod1DU:
			result = "TEXTUREQUERYLOD1DU";
			break;

		case TextureAccess::eTextureQueryLod2DU:
			result = "TEXTUREQUERYLOD2DU";
			break;

		case TextureAccess::eTextureQueryLod3DU:
			result = "TEXTUREQUERYLOD3DU";
			break;

		case TextureAccess::eTextureQueryLodCubeU:
			result = "TEXTUREQUERYLODCUBEU";
			break;

		case TextureAccess::eTextureQueryLod1DArrayU:
			result = "TEXTUREQUERYLOD1DARRAYU";
			break;

		case TextureAccess::eTextureQueryLod2DArrayU:
			result = "TEXTUREQUERYLOD2DARRAYU";
			break;

		case TextureAccess::eTextureQueryLodCubeArrayU:
			result = "TEXTUREQUERYLODCUBEARRAYU";
			break;

		case TextureAccess::eTextureQueryLevels1DF:
			result = "TEXTUREQUERYLEVELS1DF";
			break;

		case TextureAccess::eTextureQueryLevels2DF:
			result = "TEXTUREQUERYLEVELS2DF";
			break;

		case TextureAccess::eTextureQueryLevels3DF:
			result = "TEXTUREQUERYLEVELS3DF";
			break;

		case TextureAccess::eTextureQueryLevelsCubeF:
			result = "TEXTUREQUERYLEVELSCUBEF";
			break;

		case TextureAccess::eTextureQueryLevels1DArrayF:
			result = "TEXTUREQUERYLEVELS1DARRAYF";
			break;

		case TextureAccess::eTextureQueryLevels2DArrayF:
			result = "TEXTUREQUERYLEVELS2DARRAYF";
			break;

		case TextureAccess::eTextureQueryLevelsCubeArrayF:
			result = "TEXTUREQUERYLEVELSCUBEARRAYF";
			break;

		case TextureAccess::eTextureQueryLevels1DShadowF:
			result = "TEXTUREQUERYLEVELS1DSHADOWF";
			break;

		case TextureAccess::eTextureQueryLevels2DShadowF:
			result = "TEXTUREQUERYLEVELS2DSHADOWF";
			break;

		case TextureAccess::eTextureQueryLevelsCubeShadowF:
			result = "TEXTUREQUERYLEVELSCUBESHADOWF";
			break;

		case TextureAccess::eTextureQueryLevels1DArrayShadowF:
			result = "TEXTUREQUERYLEVELS1DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureQueryLevels2DArrayShadowF:
			result = "TEXTUREQUERYLEVELS2DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureQueryLevelsCubeArrayShadowF:
			result = "TEXTUREQUERYLEVELSCUBEARRAYSHADOWF";
			break;

		case TextureAccess::eTextureQueryLevels1DI:
			result = "TEXTUREQUERYLEVELS1DI";
			break;

		case TextureAccess::eTextureQueryLevels2DI:
			result = "TEXTUREQUERYLEVELS2DI";
			break;

		case TextureAccess::eTextureQueryLevels3DI:
			result = "TEXTUREQUERYLEVELS3DI";
			break;

		case TextureAccess::eTextureQueryLevelsCubeI:
			result = "TEXTUREQUERYLEVELSCUBEI";
			break;

		case TextureAccess::eTextureQueryLevels1DArrayI:
			result = "TEXTUREQUERYLEVELS1DARRAYI";
			break;

		case TextureAccess::eTextureQueryLevels2DArrayI:
			result = "TEXTUREQUERYLEVELS2DARRAYI";
			break;

		case TextureAccess::eTextureQueryLevelsCubeArrayI:
			result = "TEXTUREQUERYLEVELSCUBEARRAYI";
			break;

		case TextureAccess::eTextureQueryLevels1DU:
			result = "TEXTUREQUERYLEVELS1DU";
			break;

		case TextureAccess::eTextureQueryLevels2DU:
			result = "TEXTUREQUERYLEVELS2DU";
			break;

		case TextureAccess::eTextureQueryLevels3DU:
			result = "TEXTUREQUERYLEVELS3DU";
			break;

		case TextureAccess::eTextureQueryLevelsCubeU:
			result = "TEXTUREQUERYLEVELSCUBEU";
			break;

		case TextureAccess::eTextureQueryLevels1DArrayU:
			result = "TEXTUREQUERYLEVELS1DARRAYU";
			break;

		case TextureAccess::eTextureQueryLevels2DArrayU:
			result = "TEXTUREQUERYLEVELS2DARRAYU";
			break;

		case TextureAccess::eTextureQueryLevelsCubeArrayU:
			result = "TEXTUREQUERYLEVELSCUBEARRAYU";
			break;


	// Texel Lookup Functions
		case TextureAccess::eTexture1DF:
			result = "TEXTURE1DF";
			break;

		case TextureAccess::eTexture1DFBias:
			result = "TEXTURE1DFBIAS";
			break;

		case TextureAccess::eTexture2DF:
			result = "TEXTURE2DF";
			break;

		case TextureAccess::eTexture2DFBias:
			result = "TEXTURE2DFBIAS";
			break;

		case TextureAccess::eTexture3DF:
			result = "TEXTURE3DF";
			break;

		case TextureAccess::eTexture3DFBias:
			result = "TEXTURE3DFBIAS";
			break;

		case TextureAccess::eTextureCubeF:
			result = "TEXTURECUBEF";
			break;

		case TextureAccess::eTextureCubeFBias:
			result = "TEXTURECUBEFBIAS";
			break;

		case TextureAccess::eTexture1DArrayF:
			result = "TEXTURE1DARRAYF";
			break;

		case TextureAccess::eTexture1DArrayFBias:
			result = "TEXTURE1DARRAYFBIAS";
			break;

		case TextureAccess::eTexture2DArrayF:
			result = "TEXTURE2DARRAYF";
			break;

		case TextureAccess::eTexture2DArrayFBias:
			result = "TEXTURE2DARRAYFBIAS";
			break;

		case TextureAccess::eTextureCubeArrayF:
			result = "TEXTURECUBEARRAYF";
			break;

		case TextureAccess::eTextureCubeArrayFBias:
			result = "TEXTURECUBEARRAYFBIAS";
			break;

		case TextureAccess::eTexture2DRectF:
			result = "TEXTURE2DRECTF";
			break;

		case TextureAccess::eTexture1DI:
			result = "TEXTURE1DI";
			break;

		case TextureAccess::eTexture1DIBias:
			result = "TEXTURE1DIBIAS";
			break;

		case TextureAccess::eTexture2DI:
			result = "TEXTURE2DI";
			break;

		case TextureAccess::eTexture2DIBias:
			result = "TEXTURE2DIBIAS";
			break;

		case TextureAccess::eTexture3DI:
			result = "TEXTURE3DI";
			break;

		case TextureAccess::eTexture3DIBias:
			result = "TEXTURE3DIBIAS";
			break;

		case TextureAccess::eTextureCubeI:
			result = "TEXTURECUBEI";
			break;

		case TextureAccess::eTextureCubeIBias:
			result = "TEXTURECUBEIBIAS";
			break;

		case TextureAccess::eTexture1DArrayI:
			result = "TEXTURE1DARRAYI";
			break;

		case TextureAccess::eTexture1DArrayIBias:
			result = "TEXTURE1DARRAYIBIAS";
			break;

		case TextureAccess::eTexture2DArrayI:
			result = "TEXTURE2DARRAYI";
			break;

		case TextureAccess::eTexture2DArrayIBias:
			result = "TEXTURE2DARRAYIBIAS";
			break;

		case TextureAccess::eTextureCubeArrayI:
			result = "TEXTURECUBEARRAYI";
			break;

		case TextureAccess::eTextureCubeArrayIBias:
			result = "TEXTURECUBEARRAYIBIAS";
			break;

		case TextureAccess::eTexture2DRectI:
			result = "TEXTURE2DRECTI";
			break;

		case TextureAccess::eTexture1DU:
			result = "TEXTURE1DU";
			break;

		case TextureAccess::eTexture1DUBias:
			result = "TEXTURE1DUBIAS";
			break;

		case TextureAccess::eTexture2DU:
			result = "TEXTURE2DU";
			break;

		case TextureAccess::eTexture2DUBias:
			result = "TEXTURE2DUBIAS";
			break;

		case TextureAccess::eTexture3DU:
			result = "TEXTURE3DU";
			break;

		case TextureAccess::eTexture3DUBias:
			result = "TEXTURE3DUBIAS";
			break;

		case TextureAccess::eTextureCubeU:
			result = "TEXTURECUBEU";
			break;

		case TextureAccess::eTextureCubeUBias:
			result = "TEXTURECUBEUBIAS";
			break;

		case TextureAccess::eTexture1DArrayU:
			result = "TEXTURE1DARRAYU";
			break;

		case TextureAccess::eTexture1DArrayUBias:
			result = "TEXTURE1DARRAYUBIAS";
			break;

		case TextureAccess::eTexture2DArrayU:
			result = "TEXTURE2DARRAYU";
			break;

		case TextureAccess::eTexture2DArrayUBias:
			result = "TEXTURE2DARRAYUBIAS";
			break;

		case TextureAccess::eTextureCubeArrayU:
			result = "TEXTURECUBEARRAYU";
			break;

		case TextureAccess::eTextureCubeArrayUBias:
			result = "TEXTURECUBEARRAYUBIAS";
			break;

		case TextureAccess::eTexture2DRectU:
			result = "TEXTURE2DRECTU";
			break;

		case TextureAccess::eTextureProj1DF2:
			result = "TEXTUREPROJ1DF2";
			break;

		case TextureAccess::eTextureProj1DF2Bias:
			result = "TEXTUREPROJ1DF2BIAS";
			break;

		case TextureAccess::eTextureProj1DF4:
			result = "TEXTUREPROJ1DF4";
			break;

		case TextureAccess::eTextureProj1DF4Bias:
			result = "TEXTUREPROJ1DF4BIAS";
			break;

		case TextureAccess::eTextureProj2DF3:
			result = "TEXTUREPROJ2DF3";
			break;

		case TextureAccess::eTextureProj2DF3Bias:
			result = "TEXTUREPROJ2DF3BIAS";
			break;

		case TextureAccess::eTextureProj2DF4:
			result = "TEXTUREPROJ2DF4";
			break;

		case TextureAccess::eTextureProj2DF4Bias:
			result = "TEXTUREPROJ2DF4BIAS";
			break;

		case TextureAccess::eTextureProj3DF:
			result = "TEXTUREPROJ3DF";
			break;

		case TextureAccess::eTextureProj3DFBias:
			result = "TEXTUREPROJ3DFBIAS";
			break;

		case TextureAccess::eTextureProj2DRectF3:
			result = "TEXTUREPROJ2DRECTF3";
			break;

		case TextureAccess::eTextureProj2DRectF4:
			result = "TEXTUREPROJ2DRECTF4";
			break;

		case TextureAccess::eTextureProj1DI2:
			result = "TEXTUREPROJ1DI2";
			break;

		case TextureAccess::eTextureProj1DI2Bias:
			result = "TEXTUREPROJ1DI2BIAS";
			break;

		case TextureAccess::eTextureProj1DI4:
			result = "TEXTUREPROJ1DI4";
			break;

		case TextureAccess::eTextureProj1DI4Bias:
			result = "TEXTUREPROJ1DI4BIAS";
			break;

		case TextureAccess::eTextureProj2DI3:
			result = "TEXTUREPROJ2DI3";
			break;

		case TextureAccess::eTextureProj2DI3Bias:
			result = "TEXTUREPROJ2DI3BIAS";
			break;

		case TextureAccess::eTextureProj2DI4:
			result = "TEXTUREPROJ2DI4";
			break;

		case TextureAccess::eTextureProj2DI4Bias:
			result = "TEXTUREPROJ2DI4BIAS";
			break;

		case TextureAccess::eTextureProj3DI:
			result = "TEXTUREPROJ3DI";
			break;

		case TextureAccess::eTextureProj3DIBias:
			result = "TEXTUREPROJ3DIBIAS";
			break;

		case TextureAccess::eTextureProj2DRectI3:
			result = "TEXTUREPROJ2DRECTI3";
			break;

		case TextureAccess::eTextureProj2DRectI4:
			result = "TEXTUREPROJ2DRECTI4";
			break;

		case TextureAccess::eTextureProj1DU2:
			result = "TEXTUREPROJ1DU2";
			break;

		case TextureAccess::eTextureProj1DU2Bias:
			result = "TEXTUREPROJ1DU2BIAS";
			break;

		case TextureAccess::eTextureProj1DU4:
			result = "TEXTUREPROJ1DU4";
			break;

		case TextureAccess::eTextureProj1DU4Bias:
			result = "TEXTUREPROJ1DU4BIAS";
			break;

		case TextureAccess::eTextureProj2DU3:
			result = "TEXTUREPROJ2DU3";
			break;

		case TextureAccess::eTextureProj2DU3Bias:
			result = "TEXTUREPROJ2DU3BIAS";
			break;

		case TextureAccess::eTextureProj2DU4:
			result = "TEXTUREPROJ2DU4";
			break;

		case TextureAccess::eTextureProj2DU4Bias:
			result = "TEXTUREPROJ2DU4BIAS";
			break;

		case TextureAccess::eTextureProj3DU:
			result = "TEXTUREPROJ3DU";
			break;

		case TextureAccess::eTextureProj3DUBias:
			result = "TEXTUREPROJ3DUBIAS";
			break;

		case TextureAccess::eTextureProj2DRectU3:
			result = "TEXTUREPROJ2DRECTU3";
			break;

		case TextureAccess::eTextureProj2DRectU4:
			result = "TEXTUREPROJ2DRECTU4";
			break;

		case TextureAccess::eTextureLod1DF:
			result = "TEXTURELOD1DF";
			break;

		case TextureAccess::eTextureLod2DF:
			result = "TEXTURELOD2DF";
			break;

		case TextureAccess::eTextureLod3DF:
			result = "TEXTURELOD3DF";
			break;

		case TextureAccess::eTextureLodCubeF:
			result = "TEXTURELODCUBEF";
			break;

		case TextureAccess::eTextureLod1DArrayF:
			result = "TEXTURELOD1DARRAYF";
			break;

		case TextureAccess::eTextureLod2DArrayF:
			result = "TEXTURELOD2DARRAYF";
			break;

		case TextureAccess::eTextureLodCubeArrayF:
			result = "TEXTURELODCUBEARRAYF";
			break;

		case TextureAccess::eTextureLod1DI:
			result = "TEXTURELOD1DI";
			break;

		case TextureAccess::eTextureLod2DI:
			result = "TEXTURELOD2DI";
			break;

		case TextureAccess::eTextureLod3DI:
			result = "TEXTURELOD3DI";
			break;

		case TextureAccess::eTextureLodCubeI:
			result = "TEXTURELODCUBEI";
			break;

		case TextureAccess::eTextureLod1DArrayI:
			result = "TEXTURELOD1DARRAYI";
			break;

		case TextureAccess::eTextureLod2DArrayI:
			result = "TEXTURELOD2DARRAYI";
			break;

		case TextureAccess::eTextureLodCubeArrayI:
			result = "TEXTURELODCUBEARRAYI";
			break;

		case TextureAccess::eTextureLod1DU:
			result = "TEXTURELOD1DU";
			break;

		case TextureAccess::eTextureLod2DU:
			result = "TEXTURELOD2DU";
			break;

		case TextureAccess::eTextureLod3DU:
			result = "TEXTURELOD3DU";
			break;

		case TextureAccess::eTextureLodCubeU:
			result = "TEXTURELODCUBEU";
			break;

		case TextureAccess::eTextureLod1DArrayU:
			result = "TEXTURELOD1DARRAYU";
			break;

		case TextureAccess::eTextureLod2DArrayU:
			result = "TEXTURELOD2DARRAYU";
			break;

		case TextureAccess::eTextureLodCubeArrayU:
			result = "TEXTURELODCUBEARRAYU";
			break;

		case TextureAccess::eTextureOffset1DF:
			result = "TEXTUREOFFSET1DF";
			break;

		case TextureAccess::eTextureOffset1DFBias:
			result = "TEXTUREOFFSET1DFBIAS";
			break;

		case TextureAccess::eTextureOffset2DF:
			result = "TEXTUREOFFSET2DF";
			break;

		case TextureAccess::eTextureOffset2DFBias:
			result = "TEXTUREOFFSET2DFBIAS";
			break;

		case TextureAccess::eTextureOffset3DF:
			result = "TEXTUREOFFSET3DF";
			break;

		case TextureAccess::eTextureOffset3DFBias:
			result = "TEXTUREOFFSET3DFBIAS";
			break;

		case TextureAccess::eTextureOffset2DRectF:
			result = "TEXTUREOFFSET2DRECTF";
			break;

		case TextureAccess::eTextureOffset1DArrayF:
			result = "TEXTUREOFFSET1DARRAYF";
			break;

		case TextureAccess::eTextureOffset1DArrayFBias:
			result = "TEXTUREOFFSET1DARRAYFBIAS";
			break;

		case TextureAccess::eTextureOffset2DArrayF:
			result = "TEXTUREOFFSET2DARRAYF";
			break;

		case TextureAccess::eTextureOffset2DArrayFBias:
			result = "TEXTUREOFFSET2DARRAYFBIAS";
			break;

		case TextureAccess::eTextureOffset1DI:
			result = "TEXTUREOFFSET1DI";
			break;

		case TextureAccess::eTextureOffset1DIBias:
			result = "TEXTUREOFFSET1DIBIAS";
			break;

		case TextureAccess::eTextureOffset2DI:
			result = "TEXTUREOFFSET2DI";
			break;

		case TextureAccess::eTextureOffset2DIBias:
			result = "TEXTUREOFFSET2DIBIAS";
			break;

		case TextureAccess::eTextureOffset3DI:
			result = "TEXTUREOFFSET3DI";
			break;

		case TextureAccess::eTextureOffset3DIBias:
			result = "TEXTUREOFFSET3DIBIAS";
			break;

		case TextureAccess::eTextureOffset2DRectI:
			result = "TEXTUREOFFSET2DRECTI";
			break;

		case TextureAccess::eTextureOffset1DArrayI:
			result = "TEXTUREOFFSET1DARRAYI";
			break;

		case TextureAccess::eTextureOffset1DArrayIBias:
			result = "TEXTUREOFFSET1DARRAYIBIAS";
			break;

		case TextureAccess::eTextureOffset2DArrayI:
			result = "TEXTUREOFFSET2DARRAYI";
			break;

		case TextureAccess::eTextureOffset2DArrayIBias:
			result = "TEXTUREOFFSET2DARRAYIBIAS";
			break;

		case TextureAccess::eTextureOffset1DU:
			result = "TEXTUREOFFSET1DU";
			break;

		case TextureAccess::eTextureOffset1DUBias:
			result = "TEXTUREOFFSET1DUBIAS";
			break;

		case TextureAccess::eTextureOffset2DU:
			result = "TEXTUREOFFSET2DU";
			break;

		case TextureAccess::eTextureOffset2DUBias:
			result = "TEXTUREOFFSET2DUBIAS";
			break;

		case TextureAccess::eTextureOffset3DU:
			result = "TEXTUREOFFSET3DU";
			break;

		case TextureAccess::eTextureOffset3DUBias:
			result = "TEXTUREOFFSET3DUBIAS";
			break;

		case TextureAccess::eTextureOffset2DRectU:
			result = "TEXTUREOFFSET2DRECTU";
			break;

		case TextureAccess::eTextureOffset1DArrayU:
			result = "TEXTUREOFFSET1DARRAYU";
			break;

		case TextureAccess::eTextureOffset1DArrayUBias:
			result = "TEXTUREOFFSET1DARRAYUBIAS";
			break;

		case TextureAccess::eTextureOffset2DArrayU:
			result = "TEXTUREOFFSET2DARRAYU";
			break;

		case TextureAccess::eTextureOffset2DArrayUBias:
			result = "TEXTUREOFFSET2DARRAYUBIAS";
			break;

		case TextureAccess::eTexelFetch1DF:
			result = "TEXELFETCH1DF";
			break;

		case TextureAccess::eTexelFetch2DF:
			result = "TEXELFETCH2DF";
			break;

		case TextureAccess::eTexelFetch3DF:
			result = "TEXELFETCH3DF";
			break;

		case TextureAccess::eTexelFetch2DRectF:
			result = "TEXELFETCH2DRECTF";
			break;

		case TextureAccess::eTexelFetch1DArrayF:
			result = "TEXELFETCH1DARRAYF";
			break;

		case TextureAccess::eTexelFetch2DArrayF:
			result = "TEXELFETCH2DARRAYF";
			break;

		case TextureAccess::eTexelFetchBufferF:
			result = "TEXELFETCHBUFFERF";
			break;

		case TextureAccess::eTexelFetch1DI:
			result = "TEXELFETCH1DI";
			break;

		case TextureAccess::eTexelFetch2DI:
			result = "TEXELFETCH2DI";
			break;

		case TextureAccess::eTexelFetch3DI:
			result = "TEXELFETCH3DI";
			break;

		case TextureAccess::eTexelFetch2DRectI:
			result = "TEXELFETCH2DRECTI";
			break;

		case TextureAccess::eTexelFetch1DArrayI:
			result = "TEXELFETCH1DARRAYI";
			break;

		case TextureAccess::eTexelFetch2DArrayI:
			result = "TEXELFETCH2DARRAYI";
			break;

		case TextureAccess::eTexelFetchBufferI:
			result = "TEXELFETCHBUFFERI";
			break;

		case TextureAccess::eTexelFetch1DU:
			result = "TEXELFETCH1DU";
			break;

		case TextureAccess::eTexelFetch2DU:
			result = "TEXELFETCH2DU";
			break;

		case TextureAccess::eTexelFetch3DU:
			result = "TEXELFETCH3DU";
			break;

		case TextureAccess::eTexelFetch2DRectU:
			result = "TEXELFETCH2DRECTU";
			break;

		case TextureAccess::eTexelFetch1DArrayU:
			result = "TEXELFETCH1DARRAYU";
			break;

		case TextureAccess::eTexelFetch2DArrayU:
			result = "TEXELFETCH2DARRAYU";
			break;

		case TextureAccess::eTexelFetchBufferU:
			result = "TEXELFETCHBUFFERU";
			break;

		case TextureAccess::eTexelFetchOffset1DF:
			result = "TEXELFETCHOFFSET1DF";
			break;

		case TextureAccess::eTexelFetchOffset2DF:
			result = "TEXELFETCHOFFSET2DF";
			break;

		case TextureAccess::eTexelFetchOffset3DF:
			result = "TEXELFETCHOFFSET3DF";
			break;

		case TextureAccess::eTexelFetchOffset2DRectF:
			result = "TEXELFETCHOFFSET2DRECTF";
			break;

		case TextureAccess::eTexelFetchOffset1DArrayF:
			result = "TEXELFETCHOFFSET1DARRAYF";
			break;

		case TextureAccess::eTexelFetchOffset2DArrayF:
			result = "TEXELFETCHOFFSET2DARRAYF";
			break;

		case TextureAccess::eTexelFetchOffset1DI:
			result = "TEXELFETCHOFFSET1DI";
			break;

		case TextureAccess::eTexelFetchOffset2DI:
			result = "TEXELFETCHOFFSET2DI";
			break;

		case TextureAccess::eTexelFetchOffset3DI:
			result = "TEXELFETCHOFFSET3DI";
			break;

		case TextureAccess::eTexelFetchOffset2DRectI:
			result = "TEXELFETCHOFFSET2DRECTI";
			break;

		case TextureAccess::eTexelFetchOffset1DArrayI:
			result = "TEXELFETCHOFFSET1DARRAYI";
			break;

		case TextureAccess::eTexelFetchOffset2DArrayI:
			result = "TEXELFETCHOFFSET2DARRAYI";
			break;

		case TextureAccess::eTexelFetchOffset1DU:
			result = "TEXELFETCHOFFSET1DU";
			break;

		case TextureAccess::eTexelFetchOffset2DU:
			result = "TEXELFETCHOFFSET2DU";
			break;

		case TextureAccess::eTexelFetchOffset3DU:
			result = "TEXELFETCHOFFSET3DU";
			break;

		case TextureAccess::eTexelFetchOffset2DRectU:
			result = "TEXELFETCHOFFSET2DRECTU";
			break;

		case TextureAccess::eTexelFetchOffset1DArrayU:
			result = "TEXELFETCHOFFSET1DARRAYU";
			break;

		case TextureAccess::eTexelFetchOffset2DArrayU:
			result = "TEXELFETCHOFFSET2DARRAYU";
			break;

		case TextureAccess::eTextureProjOffset1DF2:
			result = "TEXTUREPROJOFFSET1DF2";
			break;

		case TextureAccess::eTextureProjOffset1DF2Bias:
			result = "TEXTUREPROJOFFSET1DF2BIAS";
			break;

		case TextureAccess::eTextureProjOffset1DF4:
			result = "TEXTUREPROJOFFSET1DF4";
			break;

		case TextureAccess::eTextureProjOffset1DF4Bias:
			result = "TEXTUREPROJOFFSET1DF4BIAS";
			break;

		case TextureAccess::eTextureProjOffset2DF3:
			result = "TEXTUREPROJOFFSET2DF3";
			break;

		case TextureAccess::eTextureProjOffset2DF3Bias:
			result = "TEXTUREPROJOFFSET2DF3BIAS";
			break;

		case TextureAccess::eTextureProjOffset2DF4:
			result = "TEXTUREPROJOFFSET2DF4";
			break;

		case TextureAccess::eTextureProjOffset2DF4Bias:
			result = "TEXTUREPROJOFFSET2DF4BIAS";
			break;

		case TextureAccess::eTextureProjOffset3DF:
			result = "TEXTUREPROJOFFSET3DF";
			break;

		case TextureAccess::eTextureProjOffset3DFBias:
			result = "TEXTUREPROJOFFSET3DFBIAS";
			break;

		case TextureAccess::eTextureProjOffset2DRectF3:
			result = "TEXTUREPROJOFFSET2DRECTF3";
			break;

		case TextureAccess::eTextureProjOffset2DRectF4:
			result = "TEXTUREPROJOFFSET2DRECTF4";
			break;

		case TextureAccess::eTextureProjOffset1DI2:
			result = "TEXTUREPROJOFFSET1DI2";
			break;

		case TextureAccess::eTextureProjOffset1DI2Bias:
			result = "TEXTUREPROJOFFSET1DI2BIAS";
			break;

		case TextureAccess::eTextureProjOffset1DI4:
			result = "TEXTUREPROJOFFSET1DI4";
			break;

		case TextureAccess::eTextureProjOffset1DI4Bias:
			result = "TEXTUREPROJOFFSET1DI4BIAS";
			break;

		case TextureAccess::eTextureProjOffset2DI3:
			result = "TEXTUREPROJOFFSET2DI3";
			break;

		case TextureAccess::eTextureProjOffset2DI3Bias:
			result = "TEXTUREPROJOFFSET2DI3BIAS";
			break;

		case TextureAccess::eTextureProjOffset2DI4:
			result = "TEXTUREPROJOFFSET2DI4";
			break;

		case TextureAccess::eTextureProjOffset2DI4Bias:
			result = "TEXTUREPROJOFFSET2DI4BIAS";
			break;

		case TextureAccess::eTextureProjOffset3DI:
			result = "TEXTUREPROJOFFSET3DI";
			break;

		case TextureAccess::eTextureProjOffset3DIBias:
			result = "TEXTUREPROJOFFSET3DIBIAS";
			break;

		case TextureAccess::eTextureProjOffset2DRectI3:
			result = "TEXTUREPROJOFFSET2DRECTI3";
			break;

		case TextureAccess::eTextureProjOffset2DRectI4:
			result = "TEXTUREPROJOFFSET2DRECTI4";
			break;

		case TextureAccess::eTextureProjOffset1DU2:
			result = "TEXTUREPROJOFFSET1DU2";
			break;

		case TextureAccess::eTextureProjOffset1DU2Bias:
			result = "TEXTUREPROJOFFSET1DU2BIAS";
			break;

		case TextureAccess::eTextureProjOffset1DU4:
			result = "TEXTUREPROJOFFSET1DU4";
			break;

		case TextureAccess::eTextureProjOffset1DU4Bias:
			result = "TEXTUREPROJOFFSET1DU4BIAS";
			break;

		case TextureAccess::eTextureProjOffset2DU3:
			result = "TEXTUREPROJOFFSET2DU3";
			break;

		case TextureAccess::eTextureProjOffset2DU3Bias:
			result = "TEXTUREPROJOFFSET2DU3BIAS";
			break;

		case TextureAccess::eTextureProjOffset2DU4:
			result = "TEXTUREPROJOFFSET2DU4";
			break;

		case TextureAccess::eTextureProjOffset2DU4Bias:
			result = "TEXTUREPROJOFFSET2DU4BIAS";
			break;

		case TextureAccess::eTextureProjOffset3DU:
			result = "TEXTUREPROJOFFSET3DU";
			break;

		case TextureAccess::eTextureProjOffset3DUBias:
			result = "TEXTUREPROJOFFSET3DUBIAS";
			break;

		case TextureAccess::eTextureProjOffset2DRectU3:
			result = "TEXTUREPROJOFFSET2DRECTU3";
			break;

		case TextureAccess::eTextureProjOffset2DRectU4:
			result = "TEXTUREPROJOFFSET2DRECTU4";
			break;

		case TextureAccess::eTextureLodOffset1DF:
			result = "TEXTURELODOFFSET1DF";
			break;

		case TextureAccess::eTextureLodOffset2DF:
			result = "TEXTURELODOFFSET2DF";
			break;

		case TextureAccess::eTextureLodOffset3DF:
			result = "TEXTURELODOFFSET3DF";
			break;

		case TextureAccess::eTextureLodOffset1DArrayF:
			result = "TEXTURELODOFFSET1DARRAYF";
			break;

		case TextureAccess::eTextureLodOffset2DArrayF:
			result = "TEXTURELODOFFSET2DARRAYF";
			break;

		case TextureAccess::eTextureLodOffset1DI:
			result = "TEXTURELODOFFSET1DI";
			break;

		case TextureAccess::eTextureLodOffset2DI:
			result = "TEXTURELODOFFSET2DI";
			break;

		case TextureAccess::eTextureLodOffset3DI:
			result = "TEXTURELODOFFSET3DI";
			break;

		case TextureAccess::eTextureLodOffset1DArrayI:
			result = "TEXTURELODOFFSET1DARRAYI";
			break;

		case TextureAccess::eTextureLodOffset2DArrayI:
			result = "TEXTURELODOFFSET2DARRAYI";
			break;

		case TextureAccess::eTextureLodOffset1DU:
			result = "TEXTURELODOFFSET1DU";
			break;

		case TextureAccess::eTextureLodOffset2DU:
			result = "TEXTURELODOFFSET2DU";
			break;

		case TextureAccess::eTextureLodOffset3DU:
			result = "TEXTURELODOFFSET3DU";
			break;

		case TextureAccess::eTextureLodOffset1DArrayU:
			result = "TEXTURELODOFFSET1DARRAYU";
			break;

		case TextureAccess::eTextureLodOffset2DArrayU:
			result = "TEXTURELODOFFSET2DARRAYU";
			break;

		case TextureAccess::eTextureProjLod1DF2:
			result = "TEXTUREPROJLOD1DF2";
			break;

		case TextureAccess::eTextureProjLod1DF4:
			result = "TEXTUREPROJLOD1DF4";
			break;

		case TextureAccess::eTextureProjLod2DF3:
			result = "TEXTUREPROJLOD2DF3";
			break;

		case TextureAccess::eTextureProjLod2DF4:
			result = "TEXTUREPROJLOD2DF4";
			break;

		case TextureAccess::eTextureProjLod3DF:
			result = "TEXTUREPROJLOD3DF";
			break;

		case TextureAccess::eTextureProjLod1DI2:
			result = "TEXTUREPROJLOD1DI2";
			break;

		case TextureAccess::eTextureProjLod1DI4:
			result = "TEXTUREPROJLOD1DI4";
			break;

		case TextureAccess::eTextureProjLod2DI3:
			result = "TEXTUREPROJLOD2DI3";
			break;

		case TextureAccess::eTextureProjLod2DI4:
			result = "TEXTUREPROJLOD2DI4";
			break;

		case TextureAccess::eTextureProjLod3DI:
			result = "TEXTUREPROJLOD3DI";
			break;

		case TextureAccess::eTextureProjLod1DU2:
			result = "TEXTUREPROJLOD1DU2";
			break;

		case TextureAccess::eTextureProjLod1DU4:
			result = "TEXTUREPROJLOD1DU4";
			break;

		case TextureAccess::eTextureProjLod2DU3:
			result = "TEXTUREPROJLOD2DU3";
			break;

		case TextureAccess::eTextureProjLod2DU4:
			result = "TEXTUREPROJLOD2DU4";
			break;

		case TextureAccess::eTextureProjLod3DU:
			result = "TEXTUREPROJLOD3DU";
			break;

		case TextureAccess::eTextureProjLodOffset1DF2:
			result = "TEXTUREPROJLODOFFSET1DF2";
			break;

		case TextureAccess::eTextureProjLodOffset1DF4:
			result = "TEXTUREPROJLODOFFSET1DF4";
			break;

		case TextureAccess::eTextureProjLodOffset2DF3:
			result = "TEXTUREPROJLODOFFSET2DF3";
			break;

		case TextureAccess::eTextureProjLodOffset2DF4:
			result = "TEXTUREPROJLODOFFSET2DF4";
			break;

		case TextureAccess::eTextureProjLodOffset3DF:
			result = "TEXTUREPROJLODOFFSET3DF";
			break;

		case TextureAccess::eTextureProjLodOffset1DI2:
			result = "TEXTUREPROJLODOFFSET1DI2";
			break;

		case TextureAccess::eTextureProjLodOffset1DI4:
			result = "TEXTUREPROJLODOFFSET1DI4";
			break;

		case TextureAccess::eTextureProjLodOffset2DI3:
			result = "TEXTUREPROJLODOFFSET2DI3";
			break;

		case TextureAccess::eTextureProjLodOffset2DI4:
			result = "TEXTUREPROJLODOFFSET2DI4";
			break;

		case TextureAccess::eTextureProjLodOffset3DI:
			result = "TEXTUREPROJLODOFFSET3DI";
			break;

		case TextureAccess::eTextureProjLodOffset1DU2:
			result = "TEXTUREPROJLODOFFSET1DU2";
			break;

		case TextureAccess::eTextureProjLodOffset1DU4:
			result = "TEXTUREPROJLODOFFSET1DU4";
			break;

		case TextureAccess::eTextureProjLodOffset2DU3:
			result = "TEXTUREPROJLODOFFSET2DU3";
			break;

		case TextureAccess::eTextureProjLodOffset2DU4:
			result = "TEXTUREPROJLODOFFSET2DU4";
			break;

		case TextureAccess::eTextureProjLodOffset3DU:
			result = "TEXTUREPROJLODOFFSET3DU";
			break;

		case TextureAccess::eTextureGrad1DF:
			result = "TEXTUREGRAD1DF";
			break;

		case TextureAccess::eTextureGrad2DF:
			result = "TEXTUREGRAD2DF";
			break;

		case TextureAccess::eTextureGrad3DF:
			result = "TEXTUREGRAD3DF";
			break;

		case TextureAccess::eTextureGradCubeF:
			result = "TEXTUREGRADCUBEF";
			break;

		case TextureAccess::eTextureGrad2DRectF:
			result = "TEXTUREGRAD2DRECTF";
			break;

		case TextureAccess::eTextureGrad1DArrayF:
			result = "TEXTUREGRAD1DARRAYF";
			break;

		case TextureAccess::eTextureGrad2DArrayF:
			result = "TEXTUREGRAD2DARRAYF";
			break;

		case TextureAccess::eTextureGradCubeArrayF:
			result = "TEXTUREGRADCUBEARRAYF";
			break;

		case TextureAccess::eTextureGrad1DI:
			result = "TEXTUREGRAD1DI";
			break;

		case TextureAccess::eTextureGrad2DI:
			result = "TEXTUREGRAD2DI";
			break;

		case TextureAccess::eTextureGrad3DI:
			result = "TEXTUREGRAD3DI";
			break;

		case TextureAccess::eTextureGradCubeI:
			result = "TEXTUREGRADCUBEI";
			break;

		case TextureAccess::eTextureGrad2DRectI:
			result = "TEXTUREGRAD2DRECTI";
			break;

		case TextureAccess::eTextureGrad1DArrayI:
			result = "TEXTUREGRAD1DARRAYI";
			break;

		case TextureAccess::eTextureGrad2DArrayI:
			result = "TEXTUREGRAD2DARRAYI";
			break;

		case TextureAccess::eTextureGradCubeArrayI:
			result = "TEXTUREGRADCUBEARRAYI";
			break;

		case TextureAccess::eTextureGrad1DU:
			result = "TEXTUREGRAD1DU";
			break;

		case TextureAccess::eTextureGrad2DU:
			result = "TEXTUREGRAD2DU";
			break;

		case TextureAccess::eTextureGrad3DU:
			result = "TEXTUREGRAD3DU";
			break;

		case TextureAccess::eTextureGradCubeU:
			result = "TEXTUREGRADCUBEU";
			break;

		case TextureAccess::eTextureGrad2DRectU:
			result = "TEXTUREGRAD2DRECTU";
			break;

		case TextureAccess::eTextureGrad1DArrayU:
			result = "TEXTUREGRAD1DARRAYU";
			break;

		case TextureAccess::eTextureGrad2DArrayU:
			result = "TEXTUREGRAD2DARRAYU";
			break;

		case TextureAccess::eTextureGradCubeArrayU:
			result = "TEXTUREGRADCUBEARRAYU";
			break;

		case TextureAccess::eTextureGradOffset1DF:
			result = "TEXTUREGRADOFFSET1DF";
			break;

		case TextureAccess::eTextureGradOffset2DF:
			result = "TEXTUREGRADOFFSET2DF";
			break;

		case TextureAccess::eTextureGradOffset3DF:
			result = "TEXTUREGRADOFFSET3DF";
			break;

		case TextureAccess::eTextureGradOffset2DRectF:
			result = "TEXTUREGRADOFFSET2DRECTF";
			break;

		case TextureAccess::eTextureGradOffset1DArrayF:
			result = "TEXTUREGRADOFFSET1DARRAYF";
			break;

		case TextureAccess::eTextureGradOffset2DArrayF:
			result = "TEXTUREGRADOFFSET2DARRAYF";
			break;

		case TextureAccess::eTextureGradOffset1DI:
			result = "TEXTUREGRADOFFSET1DI";
			break;

		case TextureAccess::eTextureGradOffset2DI:
			result = "TEXTUREGRADOFFSET2DI";
			break;

		case TextureAccess::eTextureGradOffset3DI:
			result = "TEXTUREGRADOFFSET3DI";
			break;

		case TextureAccess::eTextureGradOffset2DRectI:
			result = "TEXTUREGRADOFFSET2DRECTI";
			break;

		case TextureAccess::eTextureGradOffset1DArrayI:
			result = "TEXTUREGRADOFFSET1DARRAYI";
			break;

		case TextureAccess::eTextureGradOffset2DArrayI:
			result = "TEXTUREGRADOFFSET2DARRAYI";
			break;

		case TextureAccess::eTextureGradOffset1DU:
			result = "TEXTUREGRADOFFSET1DU";
			break;

		case TextureAccess::eTextureGradOffset2DU:
			result = "TEXTUREGRADOFFSET2DU";
			break;

		case TextureAccess::eTextureGradOffset3DU:
			result = "TEXTUREGRADOFFSET3DU";
			break;

		case TextureAccess::eTextureGradOffset2DRectU:
			result = "TEXTUREGRADOFFSET2DRECTU";
			break;

		case TextureAccess::eTextureGradOffset1DArrayU:
			result = "TEXTUREGRADOFFSET1DARRAYU";
			break;

		case TextureAccess::eTextureGradOffset2DArrayU:
			result = "TEXTUREGRADOFFSET2DARRAYU";
			break;

		case TextureAccess::eTextureProjGrad1DF2:
			result = "TEXTUREPROJGRAD1DF2";
			break;

		case TextureAccess::eTextureProjGrad1DF4:
			result = "TEXTUREPROJGRAD1DF4";
			break;

		case TextureAccess::eTextureProjGrad2DF3:
			result = "TEXTUREPROJGRAD2DF3";
			break;

		case TextureAccess::eTextureProjGrad2DF4:
			result = "TEXTUREPROJGRAD2DF4";
			break;

		case TextureAccess::eTextureProjGrad3DF:
			result = "TEXTUREPROJGRAD3DF";
			break;

		case TextureAccess::eTextureProjGrad2DRectF3:
			result = "TEXTUREPROJGRAD2DRECTF3";
			break;

		case TextureAccess::eTextureProjGrad2DRectF4:
			result = "TEXTUREPROJGRAD2DRECTF4";
			break;

		case TextureAccess::eTextureProjGrad1DI2:
			result = "TEXTUREPROJGRAD1DI2";
			break;

		case TextureAccess::eTextureProjGrad1DI4:
			result = "TEXTUREPROJGRAD1DI4";
			break;

		case TextureAccess::eTextureProjGrad2DI3:
			result = "TEXTUREPROJGRAD2DI3";
			break;

		case TextureAccess::eTextureProjGrad2DI4:
			result = "TEXTUREPROJGRAD2DI4";
			break;

		case TextureAccess::eTextureProjGrad3DI:
			result = "TEXTUREPROJGRAD3DI";
			break;

		case TextureAccess::eTextureProjGrad2DRectI3:
			result = "TEXTUREPROJGRAD2DRECTI3";
			break;

		case TextureAccess::eTextureProjGrad2DRectI4:
			result = "TEXTUREPROJGRAD2DRECTI4";
			break;

		case TextureAccess::eTextureProjGrad1DU2:
			result = "TEXTUREPROJGRAD1DU2";
			break;

		case TextureAccess::eTextureProjGrad1DU4:
			result = "TEXTUREPROJGRAD1DU4";
			break;

		case TextureAccess::eTextureProjGrad2DU3:
			result = "TEXTUREPROJGRAD2DU3";
			break;

		case TextureAccess::eTextureProjGrad2DU4:
			result = "TEXTUREPROJGRAD2DU4";
			break;

		case TextureAccess::eTextureProjGrad3DU:
			result = "TEXTUREPROJGRAD3DU";
			break;

		case TextureAccess::eTextureProjGrad2DRectU3:
			result = "TEXTUREPROJGRAD2DRECTU3";
			break;

		case TextureAccess::eTextureProjGrad2DRectU4:
			result = "TEXTUREPROJGRAD2DRECTU4";
			break;

		case TextureAccess::eTextureProjGradOffset1DF2:
			result = "TEXTUREPROJGRADOFFSET1DF2";
			break;

		case TextureAccess::eTextureProjGradOffset1DF4:
			result = "TEXTUREPROJGRADOFFSET1DF4";
			break;

		case TextureAccess::eTextureProjGradOffset2DF3:
			result = "TEXTUREPROJGRADOFFSET2DF3";
			break;

		case TextureAccess::eTextureProjGradOffset2DF4:
			result = "TEXTUREPROJGRADOFFSET2DF4";
			break;

		case TextureAccess::eTextureProjGradOffset3DF:
			result = "TEXTUREPROJGRADOFFSET3DF";
			break;

		case TextureAccess::eTextureProjGradOffset2DRectF3:
			result = "TEXTUREPROJGRADOFFSET2DRECTF3";
			break;

		case TextureAccess::eTextureProjGradOffset2DRectF4:
			result = "TEXTUREPROJGRADOFFSET2DRECTF4";
			break;

		case TextureAccess::eTextureProjGradOffset1DI2:
			result = "TEXTUREPROJGRADOFFSET1DI2";
			break;

		case TextureAccess::eTextureProjGradOffset1DI4:
			result = "TEXTUREPROJGRADOFFSET1DI4";
			break;

		case TextureAccess::eTextureProjGradOffset2DI3:
			result = "TEXTUREPROJGRADOFFSET2DI3";
			break;

		case TextureAccess::eTextureProjGradOffset2DI4:
			result = "TEXTUREPROJGRADOFFSET2DI4";
			break;

		case TextureAccess::eTextureProjGradOffset3DI:
			result = "TEXTUREPROJGRADOFFSET3DI";
			break;

		case TextureAccess::eTextureProjGradOffset2DRectI3:
			result = "TEXTUREPROJGRADOFFSET2DRECTI3";
			break;

		case TextureAccess::eTextureProjGradOffset2DRectI4:
			result = "TEXTUREPROJGRADOFFSET2DRECTI4";
			break;

		case TextureAccess::eTextureProjGradOffset1DU2:
			result = "TEXTUREPROJGRADOFFSET1DU2";
			break;

		case TextureAccess::eTextureProjGradOffset1DU4:
			result = "TEXTUREPROJGRADOFFSET1DU4";
			break;

		case TextureAccess::eTextureProjGradOffset2DU3:
			result = "TEXTUREPROJGRADOFFSET2DU3";
			break;

		case TextureAccess::eTextureProjGradOffset2DU4:
			result = "TEXTUREPROJGRADOFFSET2DU4";
			break;

		case TextureAccess::eTextureProjGradOffset3DU:
			result = "TEXTUREPROJGRADOFFSET3DU";
			break;

		case TextureAccess::eTextureProjGradOffset2DRectU3:
			result = "TEXTUREPROJGRADOFFSET2DRECTU3";
			break;

		case TextureAccess::eTextureProjGradOffset2DRectU4:
			result = "TEXTUREPROJGRADOFFSET2DRECTU4";
			break;

	
	// Texel Compare Functions
		case TextureAccess::eTexture1DShadowF:
			result = "TEXTURE1DSHADOWF";
			break;

		case TextureAccess::eTexture1DShadowFBias:
			result = "TEXTURE1DSHADOWFBIAS";
			break;

		case TextureAccess::eTexture2DShadowF:
			result = "TEXTURE2DSHADOWF";
			break;

		case TextureAccess::eTexture2DShadowFBias:
			result = "TEXTURE2DSHADOWFBIAS";
			break;

		case TextureAccess::eTextureCubeShadowF:
			result = "TEXTURECUBESHADOWF";
			break;

		case TextureAccess::eTextureCubeShadowFBias:
			result = "TEXTURECUBESHADOWFBIAS";
			break;

		case TextureAccess::eTexture1DArrayShadowF:
			result = "TEXTURE1DARRAYSHADOWF";
			break;

		case TextureAccess::eTexture1DArrayShadowFBias:
			result = "TEXTURE1DARRAYSHADOWFBIAS";
			break;

		case TextureAccess::eTexture2DArrayShadowF:
			result = "TEXTURE2DARRAYSHADOWF";
			break;

		case TextureAccess::eTexture2DRectShadowF:
			result = "TEXTURE2DRECTSHADOWF";
			break;

		case TextureAccess::eTextureCubeArrayShadowF:
			result = "TEXTURECUBEARRAYSHADOWF";
			break;

		case TextureAccess::eTextureProj1DShadowF:
			result = "TEXTUREPROJ1DSHADOWF";
			break;

		case TextureAccess::eTextureProj1DShadowFBias:
			result = "TEXTUREPROJ1DSHADOWFBIAS";
			break;

		case TextureAccess::eTextureProj2DShadowF:
			result = "TEXTUREPROJ2DSHADOWF";
			break;

		case TextureAccess::eTextureProj2DShadowFBias:
			result = "TEXTUREPROJ2DSHADOWFBIAS";
			break;

		case TextureAccess::eTextureProj2DRectShadowF:
			result = "TEXTUREPROJ2DRECTSHADOWF";
			break;

		case TextureAccess::eTextureLod1DShadowF:
			result = "TEXTURELOD1DSHADOWF";
			break;

		case TextureAccess::eTextureLod2DShadowF:
			result = "TEXTURELOD2DSHADOWF";
			break;

		case TextureAccess::eTextureLod1DArrayShadowF:
			result = "TEXTURELOD1DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureOffset2DRectShadowF:
			result = "TEXTUREOFFSET2DRECTSHADOWF";
			break;

		case TextureAccess::eTextureOffset1DShadowF:
			result = "TEXTUREOFFSET1DSHADOWF";
			break;

		case TextureAccess::eTextureOffset1DShadowFBias:
			result = "TEXTUREOFFSET1DSHADOWFBIAS";
			break;

		case TextureAccess::eTextureOffset2DShadowF:
			result = "TEXTUREOFFSET2DSHADOWF";
			break;

		case TextureAccess::eTextureOffset2DShadowFBias:
			result = "TEXTUREOFFSET2DSHADOWFBIAS";
			break;

		case TextureAccess::eTextureOffset1DArrayShadowF:
			result = "TEXTUREOFFSET1DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureOffset2DArrayShadowF:
			result = "TEXTUREOFFSET2DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureProjOffset1DShadowF:
			result = "TEXTUREPROJOFFSET1DSHADOWF";
			break;

		case TextureAccess::eTextureProjOffset1DShadowFBias:
			result = "TEXTUREPROJOFFSET1DSHADOWFBIAS";
			break;

		case TextureAccess::eTextureProjOffset2DShadowF:
			result = "TEXTUREPROJOFFSET2DSHADOWF";
			break;

		case TextureAccess::eTextureProjOffset2DShadowFBias:
			result = "TEXTUREPROJOFFSET2DSHADOWFBIAS";
			break;

		case TextureAccess::eTextureProjOffset2DRectShadowF:
			result = "TEXTUREPROJOFFSET2DRECTSHADOWF";
			break;

		case TextureAccess::eTextureLodOffset1DShadowF:
			result = "TEXTURELODOFFSET1DSHADOWF";
			break;

		case TextureAccess::eTextureLodOffset2DShadowF:
			result = "TEXTURELODOFFSET2DSHADOWF";
			break;

		case TextureAccess::eTextureLodOffset1DArrayShadowF:
			result = "TEXTURELODOFFSET1DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureProjLod1DShadowF:
			result = "TEXTUREPROJLOD1DSHADOWF";
			break;

		case TextureAccess::eTextureProjLod2DShadowF:
			result = "TEXTUREPROJLOD2DSHADOWF";
			break;

		case TextureAccess::eTextureProjLodOffset1DShadowF:
			result = "TEXTUREPROJLODOFFSET1DSHADOWF";
			break;

		case TextureAccess::eTextureProjLodOffset2DShadowF:
			result = "TEXTUREPROJLODOFFSET2DSHADOWF";
			break;

		case TextureAccess::eTextureGrad2DRectShadowF:
			result = "TEXTUREGRAD2DRECTSHADOWF";
			break;

		case TextureAccess::eTextureGrad1DShadowF:
			result = "TEXTUREGRAD1DSHADOWF";
			break;

		case TextureAccess::eTextureGrad2DShadowF:
			result = "TEXTUREGRAD2DSHADOWF";
			break;

		case TextureAccess::eTextureGrad1DArrayShadowF:
			result = "TEXTUREGRAD1DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureGradOffset2DRectShadowF:
			result = "TEXTUREGRADOFFSET2DRECTSHADOWF";
			break;

		case TextureAccess::eTextureGradOffset1DShadowF:
			result = "TEXTUREGRADOFFSET1DSHADOWF";
			break;

		case TextureAccess::eTextureGradOffset2DShadowF:
			result = "TEXTUREGRADOFFSET2DSHADOWF";
			break;

		case TextureAccess::eTextureGradOffset1DArrayShadowF:
			result = "TEXTUREGRADOFFSET1DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureGradOffset2DArrayShadowF:
			result = "TEXTUREGRADOFFSET2DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureProjGrad1DShadowF:
			result = "TEXTUREPROJGRAD1DSHADOWF";
			break;

		case TextureAccess::eTextureProjGrad2DShadowF:
			result = "TEXTUREPROJGRAD2DSHADOWF";
			break;

		case TextureAccess::eTextureProjGrad2DRectShadowF:
			result = "TEXTUREPROJGRAD2DRECTSHADOWF";
			break;

		case TextureAccess::eTextureProjGradOffset1DShadowF:
			result = "TEXTUREPROJGRADOFFSET1DSHADOWF";
			break;

		case TextureAccess::eTextureProjGradOffset2DShadowF:
			result = "TEXTUREPROJGRADOFFSET2DSHADOWF";
			break;

		case TextureAccess::eTextureProjGradOffset2DRectShadowF:
			result = "TEXTUREPROJGRADOFFSET2DRECTSHADOWF";
			break;


	// Texture Gather Functions
		case TextureAccess::eTextureGather2DF:
			result = "TEXTUREGATHER2DF";
			break;

		case TextureAccess::eTextureGather2DFComp:
			result = "TEXTUREGATHER2DFCOMP";
			break;

		case TextureAccess::eTextureGather2DArrayF:
			result = "TEXTUREGATHER2DARRAYF";
			break;

		case TextureAccess::eTextureGather2DArrayFComp:
			result = "TEXTUREGATHER2DARRAYFCOMP";
			break;

		case TextureAccess::eTextureGatherCubeF:
			result = "TEXTUREGATHERCUBEF";
			break;

		case TextureAccess::eTextureGatherCubeFComp:
			result = "TEXTUREGATHERCUBEFCOMP";
			break;

		case TextureAccess::eTextureGatherCubeArrayF:
			result = "TEXTUREGATHERCUBEARRAYF";
			break;

		case TextureAccess::eTextureGatherCubeArrayFComp:
			result = "TEXTUREGATHERCUBEARRAYFCOMP";
			break;

		case TextureAccess::eTextureGather2DRectF:
			result = "TEXTUREGATHER2DRECTF";
			break;

		case TextureAccess::eTextureGather2DRectFComp:
			result = "TEXTUREGATHER2DRECTFCOMP";
			break;

		case TextureAccess::eTextureGather2DI:
			result = "TEXTUREGATHER2DI";
			break;

		case TextureAccess::eTextureGather2DIComp:
			result = "TEXTUREGATHER2DICOMP";
			break;

		case TextureAccess::eTextureGather2DArrayI:
			result = "TEXTUREGATHER2DARRAYI";
			break;

		case TextureAccess::eTextureGather2DArrayIComp:
			result = "TEXTUREGATHER2DARRAYICOMP";
			break;

		case TextureAccess::eTextureGatherCubeI:
			result = "TEXTUREGATHERCUBEI";
			break;

		case TextureAccess::eTextureGatherCubeIComp:
			result = "TEXTUREGATHERCUBEICOMP";
			break;

		case TextureAccess::eTextureGatherCubeArrayI:
			result = "TEXTUREGATHERCUBEARRAYI";
			break;

		case TextureAccess::eTextureGatherCubeArrayIComp:
			result = "TEXTUREGATHERCUBEARRAYICOMP";
			break;

		case TextureAccess::eTextureGather2DRectI:
			result = "TEXTUREGATHER2DRECTI";
			break;

		case TextureAccess::eTextureGather2DRectIComp:
			result = "TEXTUREGATHER2DRECTICOMP";
			break;

		case TextureAccess::eTextureGather2DU:
			result = "TEXTUREGATHER2DU";
			break;

		case TextureAccess::eTextureGather2DUComp:
			result = "TEXTUREGATHER2DUCOMP";
			break;

		case TextureAccess::eTextureGather2DArrayU:
			result = "TEXTUREGATHER2DARRAYU";
			break;

		case TextureAccess::eTextureGather2DArrayUComp:
			result = "TEXTUREGATHER2DARRAYUCOMP";
			break;

		case TextureAccess::eTextureGatherCubeU:
			result = "TEXTUREGATHERCUBEU";
			break;

		case TextureAccess::eTextureGatherCubeUComp:
			result = "TEXTUREGATHERCUBEUCOMP";
			break;

		case TextureAccess::eTextureGatherCubeArrayU:
			result = "TEXTUREGATHERCUBEARRAYU";
			break;

		case TextureAccess::eTextureGatherCubeArrayUComp:
			result = "TEXTUREGATHERCUBEARRAYUCOMP";
			break;

		case TextureAccess::eTextureGather2DRectU:
			result = "TEXTUREGATHER2DRECTU";
			break;

		case TextureAccess::eTextureGather2DRectUComp:
			result = "TEXTUREGATHER2DRECTUCOMP";
			break;

		case TextureAccess::eTextureGatherOffset2DF:
			result = "TEXTUREGATHEROFFSET2DF";
			break;

		case TextureAccess::eTextureGatherOffset2DFComp:
			result = "TEXTUREGATHEROFFSET2DFCOMP";
			break;

		case TextureAccess::eTextureGatherOffset2DArrayF:
			result = "TEXTUREGATHEROFFSET2DARRAYF";
			break;

		case TextureAccess::eTextureGatherOffset2DArrayFComp:
			result = "TEXTUREGATHEROFFSET2DARRAYFCOMP";
			break;

		case TextureAccess::eTextureGatherOffset2DRectF:
			result = "TEXTUREGATHEROFFSET2DRECTF";
			break;

		case TextureAccess::eTextureGatherOffset2DRectFComp:
			result = "TEXTUREGATHEROFFSET2DRECTFCOMP";
			break;

		case TextureAccess::eTextureGatherOffset2DI:
			result = "TEXTUREGATHEROFFSET2DI";
			break;

		case TextureAccess::eTextureGatherOffset2DIComp:
			result = "TEXTUREGATHEROFFSET2DICOMP";
			break;

		case TextureAccess::eTextureGatherOffset2DArrayI:
			result = "TEXTUREGATHEROFFSET2DARRAYI";
			break;

		case TextureAccess::eTextureGatherOffset2DArrayIComp:
			result = "TEXTUREGATHEROFFSET2DARRAYICOMP";
			break;

		case TextureAccess::eTextureGatherOffset2DRectI:
			result = "TEXTUREGATHEROFFSET2DRECTI";
			break;

		case TextureAccess::eTextureGatherOffset2DRectIComp:
			result = "TEXTUREGATHEROFFSET2DRECTICOMP";
			break;

		case TextureAccess::eTextureGatherOffset2DU:
			result = "TEXTUREGATHEROFFSET2DU";
			break;

		case TextureAccess::eTextureGatherOffset2DUComp:
			result = "TEXTUREGATHEROFFSET2DUCOMP";
			break;

		case TextureAccess::eTextureGatherOffset2DArrayU:
			result = "TEXTUREGATHEROFFSET2DARRAYU";
			break;

		case TextureAccess::eTextureGatherOffset2DArrayUComp:
			result = "TEXTUREGATHEROFFSET2DARRAYUCOMP";
			break;

		case TextureAccess::eTextureGatherOffset2DRectU:
			result = "TEXTUREGATHEROFFSET2DRECTU";
			break;

		case TextureAccess::eTextureGatherOffset2DRectUComp:
			result = "TEXTUREGATHEROFFSET2DRECTUCOMP";
			break;

		case TextureAccess::eTextureGatherOffsets2DF:
			result = "TEXTUREGATHEROFFSETS2DF";
			break;

		case TextureAccess::eTextureGatherOffsets2DFComp:
			result = "TEXTUREGATHEROFFSETS2DFCOMP";
			break;

		case TextureAccess::eTextureGatherOffsets2DArrayF:
			result = "TEXTUREGATHEROFFSETS2DARRAYF";
			break;

		case TextureAccess::eTextureGatherOffsets2DArrayFComp:
			result = "TEXTUREGATHEROFFSETS2DARRAYFCOMP";
			break;

		case TextureAccess::eTextureGatherOffsets2DRectF:
			result = "TEXTUREGATHEROFFSETS2DRECTF";
			break;

		case TextureAccess::eTextureGatherOffsets2DRectFComp:
			result = "TEXTUREGATHEROFFSETS2DRECTFCOMP";
			break;

		case TextureAccess::eTextureGatherOffsets2DI:
			result = "TEXTUREGATHEROFFSETS2DI";
			break;

		case TextureAccess::eTextureGatherOffsets2DIComp:
			result = "TEXTUREGATHEROFFSETS2DICOMP";
			break;

		case TextureAccess::eTextureGatherOffsets2DArrayI:
			result = "TEXTUREGATHEROFFSETS2DARRAYI";
			break;

		case TextureAccess::eTextureGatherOffsets2DArrayIComp:
			result = "TEXTUREGATHEROFFSETS2DARRAYICOMP";
			break;

		case TextureAccess::eTextureGatherOffsets2DRectI:
			result = "TEXTUREGATHEROFFSETS2DRECTI";
			break;

		case TextureAccess::eTextureGatherOffsets2DRectIComp:
			result = "TEXTUREGATHEROFFSETS2DRECTICOMP";
			break;

		case TextureAccess::eTextureGatherOffsets2DU:
			result = "TEXTUREGATHEROFFSETS2DU";
			break;

		case TextureAccess::eTextureGatherOffsets2DUComp:
			result = "TEXTUREGATHEROFFSETS2DUCOMP";
			break;

		case TextureAccess::eTextureGatherOffsets2DArrayU:
			result = "TEXTUREGATHEROFFSETS2DARRAYU";
			break;

		case TextureAccess::eTextureGatherOffsets2DArrayUComp:
			result = "TEXTUREGATHEROFFSETS2DARRAYUCOMP";
			break;

		case TextureAccess::eTextureGatherOffsets2DRectU:
			result = "TEXTUREGATHEROFFSETS2DRECTU";
			break;

		case TextureAccess::eTextureGatherOffsets2DRectUComp:
			result = "TEXTUREGATHEROFFSETS2DRECTUCOMP";
			break;


	// Texture Gather Compare Functions
		case TextureAccess::eTextureGather2DShadowF:
			result = "TEXTUREGATHER2DSHADOWF";
			break;

		case TextureAccess::eTextureGather2DArrayShadowF:
			result = "TEXTUREGATHER2DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureGatherCubeShadowF:
			result = "TEXTUREGATHERCUBESHADOWF";
			break;

		case TextureAccess::eTextureGatherCubeArrayShadowF:
			result = "TEXTUREGATHERCUBEARRAYSHADOWF";
			break;

		case TextureAccess::eTextureGather2DRectShadowF:
			result = "TEXTUREGATHER2DRECTSHADOWF";
			break;

		case TextureAccess::eTextureGatherOffset2DShadowF:
			result = "TEXTUREGATHEROFFSET2DSHADOWF";
			break;

		case TextureAccess::eTextureGatherOffset2DArrayShadowF:
			result = "TEXTUREGATHEROFFSET2DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureGatherOffset2DRectShadowF:
			result = "TEXTUREGATHEROFFSET2DRECTSHADOWF";
			break;

		case TextureAccess::eTextureGatherOffsets2DShadowF:
			result = "TEXTUREGATHEROFFSETS2DSHADOWF";
			break;

		case TextureAccess::eTextureGatherOffsets2DArrayShadowF:
			result = "TEXTUREGATHEROFFSETS2DARRAYSHADOWF";
			break;

		case TextureAccess::eTextureGatherOffsets2DRectShadowF:
			result = "TEXTUREGATHEROFFSETS2DRECTSHADOWF";
			break;

		default:
			throw std::runtime_error{ "Unsupported TextureAccess type." };
		}

		return result;
	}
}

#endif
