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

#include <string>

namespace ast::expr
{
	inline std::string getName( CombinedImageAccess value )
	{
		std::string result;

		switch ( value )
		{
		case CombinedImageAccess::eUndefined:
			result = "UNDEFINED";
			break;

		case CombinedImageAccess::eCount:
			result = "COUNT";
			break;

		case CombinedImageAccess::eInvalid:
			result = "INVALID";
			break;

	// Texture Query Functions
		case CombinedImageAccess::eTextureSize1DF:
			result = "TEXTURESIZE1DF";
			break;

		case CombinedImageAccess::eTextureSize2DF:
			result = "TEXTURESIZE2DF";
			break;

		case CombinedImageAccess::eTextureSize3DF:
			result = "TEXTURESIZE3DF";
			break;

		case CombinedImageAccess::eTextureSizeCubeF:
			result = "TEXTURESIZECUBEF";
			break;

		case CombinedImageAccess::eTextureSize1DShadowF:
			result = "TEXTURESIZE1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureSize2DShadowF:
			result = "TEXTURESIZE2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureSizeCubeShadowF:
			result = "TEXTURESIZECUBESHADOWF";
			break;

		case CombinedImageAccess::eTextureSizeCubeArrayF:
			result = "TEXTURESIZECUBEARRAYF";
			break;

		case CombinedImageAccess::eTextureSizeCubeArrayShadowF:
			result = "TEXTURESIZECUBEARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureSize2DRectF:
			result = "TEXTURESIZE2DRECTF";
			break;

		case CombinedImageAccess::eTextureSize2DRectShadowF:
			result = "TEXTURESIZE2DRECTSHADOWF";
			break;

		case CombinedImageAccess::eTextureSize1DArrayF:
			result = "TEXTURESIZE1DARRAYF";
			break;

		case CombinedImageAccess::eTextureSize2DArrayF:
			result = "TEXTURESIZE2DARRAYF";
			break;

		case CombinedImageAccess::eTextureSize1DArrayShadowF:
			result = "TEXTURESIZE1DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureSize2DArrayShadowF:
			result = "TEXTURESIZE2DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureSizeBufferF:
			result = "TEXTURESIZEBUFFERF";
			break;

		case CombinedImageAccess::eTextureSize1DI:
			result = "TEXTURESIZE1DI";
			break;

		case CombinedImageAccess::eTextureSize2DI:
			result = "TEXTURESIZE2DI";
			break;

		case CombinedImageAccess::eTextureSize3DI:
			result = "TEXTURESIZE3DI";
			break;

		case CombinedImageAccess::eTextureSizeCubeI:
			result = "TEXTURESIZECUBEI";
			break;

		case CombinedImageAccess::eTextureSizeCubeArrayI:
			result = "TEXTURESIZECUBEARRAYI";
			break;

		case CombinedImageAccess::eTextureSize2DRectI:
			result = "TEXTURESIZE2DRECTI";
			break;

		case CombinedImageAccess::eTextureSize1DArrayI:
			result = "TEXTURESIZE1DARRAYI";
			break;

		case CombinedImageAccess::eTextureSize2DArrayI:
			result = "TEXTURESIZE2DARRAYI";
			break;

		case CombinedImageAccess::eTextureSizeBufferI:
			result = "TEXTURESIZEBUFFERI";
			break;

		case CombinedImageAccess::eTextureSize1DU:
			result = "TEXTURESIZE1DU";
			break;

		case CombinedImageAccess::eTextureSize2DU:
			result = "TEXTURESIZE2DU";
			break;

		case CombinedImageAccess::eTextureSize3DU:
			result = "TEXTURESIZE3DU";
			break;

		case CombinedImageAccess::eTextureSizeCubeU:
			result = "TEXTURESIZECUBEU";
			break;

		case CombinedImageAccess::eTextureSizeCubeArrayU:
			result = "TEXTURESIZECUBEARRAYU";
			break;

		case CombinedImageAccess::eTextureSize2DRectU:
			result = "TEXTURESIZE2DRECTU";
			break;

		case CombinedImageAccess::eTextureSize1DArrayU:
			result = "TEXTURESIZE1DARRAYU";
			break;

		case CombinedImageAccess::eTextureSize2DArrayU:
			result = "TEXTURESIZE2DARRAYU";
			break;

		case CombinedImageAccess::eTextureSizeBufferU:
			result = "TEXTURESIZEBUFFERU";
			break;

		case CombinedImageAccess::eTextureQueryLod1DF:
			result = "TEXTUREQUERYLOD1DF";
			break;

		case CombinedImageAccess::eTextureQueryLod2DF:
			result = "TEXTUREQUERYLOD2DF";
			break;

		case CombinedImageAccess::eTextureQueryLod3DF:
			result = "TEXTUREQUERYLOD3DF";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeF:
			result = "TEXTUREQUERYLODCUBEF";
			break;

		case CombinedImageAccess::eTextureQueryLod1DArrayF:
			result = "TEXTUREQUERYLOD1DARRAYF";
			break;

		case CombinedImageAccess::eTextureQueryLod2DArrayF:
			result = "TEXTUREQUERYLOD2DARRAYF";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeArrayF:
			result = "TEXTUREQUERYLODCUBEARRAYF";
			break;

		case CombinedImageAccess::eTextureQueryLod1DShadowF:
			result = "TEXTUREQUERYLOD1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLod2DShadowF:
			result = "TEXTUREQUERYLOD2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeShadowF:
			result = "TEXTUREQUERYLODCUBESHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLod1DArrayShadowF:
			result = "TEXTUREQUERYLOD1DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLod2DArrayShadowF:
			result = "TEXTUREQUERYLOD2DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeArrayShadowF:
			result = "TEXTUREQUERYLODCUBEARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLod1DI:
			result = "TEXTUREQUERYLOD1DI";
			break;

		case CombinedImageAccess::eTextureQueryLod2DI:
			result = "TEXTUREQUERYLOD2DI";
			break;

		case CombinedImageAccess::eTextureQueryLod3DI:
			result = "TEXTUREQUERYLOD3DI";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeI:
			result = "TEXTUREQUERYLODCUBEI";
			break;

		case CombinedImageAccess::eTextureQueryLod1DArrayI:
			result = "TEXTUREQUERYLOD1DARRAYI";
			break;

		case CombinedImageAccess::eTextureQueryLod2DArrayI:
			result = "TEXTUREQUERYLOD2DARRAYI";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeArrayI:
			result = "TEXTUREQUERYLODCUBEARRAYI";
			break;

		case CombinedImageAccess::eTextureQueryLod1DU:
			result = "TEXTUREQUERYLOD1DU";
			break;

		case CombinedImageAccess::eTextureQueryLod2DU:
			result = "TEXTUREQUERYLOD2DU";
			break;

		case CombinedImageAccess::eTextureQueryLod3DU:
			result = "TEXTUREQUERYLOD3DU";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeU:
			result = "TEXTUREQUERYLODCUBEU";
			break;

		case CombinedImageAccess::eTextureQueryLod1DArrayU:
			result = "TEXTUREQUERYLOD1DARRAYU";
			break;

		case CombinedImageAccess::eTextureQueryLod2DArrayU:
			result = "TEXTUREQUERYLOD2DARRAYU";
			break;

		case CombinedImageAccess::eTextureQueryLodCubeArrayU:
			result = "TEXTUREQUERYLODCUBEARRAYU";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DF:
			result = "TEXTUREQUERYLEVELS1DF";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DF:
			result = "TEXTUREQUERYLEVELS2DF";
			break;

		case CombinedImageAccess::eTextureQueryLevels3DF:
			result = "TEXTUREQUERYLEVELS3DF";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeF:
			result = "TEXTUREQUERYLEVELSCUBEF";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DArrayF:
			result = "TEXTUREQUERYLEVELS1DARRAYF";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DArrayF:
			result = "TEXTUREQUERYLEVELS2DARRAYF";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeArrayF:
			result = "TEXTUREQUERYLEVELSCUBEARRAYF";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DShadowF:
			result = "TEXTUREQUERYLEVELS1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DShadowF:
			result = "TEXTUREQUERYLEVELS2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeShadowF:
			result = "TEXTUREQUERYLEVELSCUBESHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DArrayShadowF:
			result = "TEXTUREQUERYLEVELS1DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DArrayShadowF:
			result = "TEXTUREQUERYLEVELS2DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeArrayShadowF:
			result = "TEXTUREQUERYLEVELSCUBEARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DI:
			result = "TEXTUREQUERYLEVELS1DI";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DI:
			result = "TEXTUREQUERYLEVELS2DI";
			break;

		case CombinedImageAccess::eTextureQueryLevels3DI:
			result = "TEXTUREQUERYLEVELS3DI";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeI:
			result = "TEXTUREQUERYLEVELSCUBEI";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DArrayI:
			result = "TEXTUREQUERYLEVELS1DARRAYI";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DArrayI:
			result = "TEXTUREQUERYLEVELS2DARRAYI";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeArrayI:
			result = "TEXTUREQUERYLEVELSCUBEARRAYI";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DU:
			result = "TEXTUREQUERYLEVELS1DU";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DU:
			result = "TEXTUREQUERYLEVELS2DU";
			break;

		case CombinedImageAccess::eTextureQueryLevels3DU:
			result = "TEXTUREQUERYLEVELS3DU";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeU:
			result = "TEXTUREQUERYLEVELSCUBEU";
			break;

		case CombinedImageAccess::eTextureQueryLevels1DArrayU:
			result = "TEXTUREQUERYLEVELS1DARRAYU";
			break;

		case CombinedImageAccess::eTextureQueryLevels2DArrayU:
			result = "TEXTUREQUERYLEVELS2DARRAYU";
			break;

		case CombinedImageAccess::eTextureQueryLevelsCubeArrayU:
			result = "TEXTUREQUERYLEVELSCUBEARRAYU";
			break;


	// Texel Lookup Functions
		case CombinedImageAccess::eTexture1DF:
			result = "TEXTURE1DF";
			break;

		case CombinedImageAccess::eTexture1DFBias:
			result = "TEXTURE1DFBIAS";
			break;

		case CombinedImageAccess::eTexture2DF:
			result = "TEXTURE2DF";
			break;

		case CombinedImageAccess::eTexture2DFBias:
			result = "TEXTURE2DFBIAS";
			break;

		case CombinedImageAccess::eTexture3DF:
			result = "TEXTURE3DF";
			break;

		case CombinedImageAccess::eTexture3DFBias:
			result = "TEXTURE3DFBIAS";
			break;

		case CombinedImageAccess::eTextureCubeF:
			result = "TEXTURECUBEF";
			break;

		case CombinedImageAccess::eTextureCubeFBias:
			result = "TEXTURECUBEFBIAS";
			break;

		case CombinedImageAccess::eTexture1DArrayF:
			result = "TEXTURE1DARRAYF";
			break;

		case CombinedImageAccess::eTexture1DArrayFBias:
			result = "TEXTURE1DARRAYFBIAS";
			break;

		case CombinedImageAccess::eTexture2DArrayF:
			result = "TEXTURE2DARRAYF";
			break;

		case CombinedImageAccess::eTexture2DArrayFBias:
			result = "TEXTURE2DARRAYFBIAS";
			break;

		case CombinedImageAccess::eTextureCubeArrayF:
			result = "TEXTURECUBEARRAYF";
			break;

		case CombinedImageAccess::eTextureCubeArrayFBias:
			result = "TEXTURECUBEARRAYFBIAS";
			break;

		case CombinedImageAccess::eTexture2DRectF:
			result = "TEXTURE2DRECTF";
			break;

		case CombinedImageAccess::eTexture1DI:
			result = "TEXTURE1DI";
			break;

		case CombinedImageAccess::eTexture1DIBias:
			result = "TEXTURE1DIBIAS";
			break;

		case CombinedImageAccess::eTexture2DI:
			result = "TEXTURE2DI";
			break;

		case CombinedImageAccess::eTexture2DIBias:
			result = "TEXTURE2DIBIAS";
			break;

		case CombinedImageAccess::eTexture3DI:
			result = "TEXTURE3DI";
			break;

		case CombinedImageAccess::eTexture3DIBias:
			result = "TEXTURE3DIBIAS";
			break;

		case CombinedImageAccess::eTextureCubeI:
			result = "TEXTURECUBEI";
			break;

		case CombinedImageAccess::eTextureCubeIBias:
			result = "TEXTURECUBEIBIAS";
			break;

		case CombinedImageAccess::eTexture1DArrayI:
			result = "TEXTURE1DARRAYI";
			break;

		case CombinedImageAccess::eTexture1DArrayIBias:
			result = "TEXTURE1DARRAYIBIAS";
			break;

		case CombinedImageAccess::eTexture2DArrayI:
			result = "TEXTURE2DARRAYI";
			break;

		case CombinedImageAccess::eTexture2DArrayIBias:
			result = "TEXTURE2DARRAYIBIAS";
			break;

		case CombinedImageAccess::eTextureCubeArrayI:
			result = "TEXTURECUBEARRAYI";
			break;

		case CombinedImageAccess::eTextureCubeArrayIBias:
			result = "TEXTURECUBEARRAYIBIAS";
			break;

		case CombinedImageAccess::eTexture2DRectI:
			result = "TEXTURE2DRECTI";
			break;

		case CombinedImageAccess::eTexture1DU:
			result = "TEXTURE1DU";
			break;

		case CombinedImageAccess::eTexture1DUBias:
			result = "TEXTURE1DUBIAS";
			break;

		case CombinedImageAccess::eTexture2DU:
			result = "TEXTURE2DU";
			break;

		case CombinedImageAccess::eTexture2DUBias:
			result = "TEXTURE2DUBIAS";
			break;

		case CombinedImageAccess::eTexture3DU:
			result = "TEXTURE3DU";
			break;

		case CombinedImageAccess::eTexture3DUBias:
			result = "TEXTURE3DUBIAS";
			break;

		case CombinedImageAccess::eTextureCubeU:
			result = "TEXTURECUBEU";
			break;

		case CombinedImageAccess::eTextureCubeUBias:
			result = "TEXTURECUBEUBIAS";
			break;

		case CombinedImageAccess::eTexture1DArrayU:
			result = "TEXTURE1DARRAYU";
			break;

		case CombinedImageAccess::eTexture1DArrayUBias:
			result = "TEXTURE1DARRAYUBIAS";
			break;

		case CombinedImageAccess::eTexture2DArrayU:
			result = "TEXTURE2DARRAYU";
			break;

		case CombinedImageAccess::eTexture2DArrayUBias:
			result = "TEXTURE2DARRAYUBIAS";
			break;

		case CombinedImageAccess::eTextureCubeArrayU:
			result = "TEXTURECUBEARRAYU";
			break;

		case CombinedImageAccess::eTextureCubeArrayUBias:
			result = "TEXTURECUBEARRAYUBIAS";
			break;

		case CombinedImageAccess::eTexture2DRectU:
			result = "TEXTURE2DRECTU";
			break;

		case CombinedImageAccess::eTextureProj1DF2:
			result = "TEXTUREPROJ1DF2";
			break;

		case CombinedImageAccess::eTextureProj1DF2Bias:
			result = "TEXTUREPROJ1DF2BIAS";
			break;

		case CombinedImageAccess::eTextureProj1DF4:
			result = "TEXTUREPROJ1DF4";
			break;

		case CombinedImageAccess::eTextureProj1DF4Bias:
			result = "TEXTUREPROJ1DF4BIAS";
			break;

		case CombinedImageAccess::eTextureProj2DF3:
			result = "TEXTUREPROJ2DF3";
			break;

		case CombinedImageAccess::eTextureProj2DF3Bias:
			result = "TEXTUREPROJ2DF3BIAS";
			break;

		case CombinedImageAccess::eTextureProj2DF4:
			result = "TEXTUREPROJ2DF4";
			break;

		case CombinedImageAccess::eTextureProj2DF4Bias:
			result = "TEXTUREPROJ2DF4BIAS";
			break;

		case CombinedImageAccess::eTextureProj3DF:
			result = "TEXTUREPROJ3DF";
			break;

		case CombinedImageAccess::eTextureProj3DFBias:
			result = "TEXTUREPROJ3DFBIAS";
			break;

		case CombinedImageAccess::eTextureProj2DRectF3:
			result = "TEXTUREPROJ2DRECTF3";
			break;

		case CombinedImageAccess::eTextureProj2DRectF4:
			result = "TEXTUREPROJ2DRECTF4";
			break;

		case CombinedImageAccess::eTextureProj1DI2:
			result = "TEXTUREPROJ1DI2";
			break;

		case CombinedImageAccess::eTextureProj1DI2Bias:
			result = "TEXTUREPROJ1DI2BIAS";
			break;

		case CombinedImageAccess::eTextureProj1DI4:
			result = "TEXTUREPROJ1DI4";
			break;

		case CombinedImageAccess::eTextureProj1DI4Bias:
			result = "TEXTUREPROJ1DI4BIAS";
			break;

		case CombinedImageAccess::eTextureProj2DI3:
			result = "TEXTUREPROJ2DI3";
			break;

		case CombinedImageAccess::eTextureProj2DI3Bias:
			result = "TEXTUREPROJ2DI3BIAS";
			break;

		case CombinedImageAccess::eTextureProj2DI4:
			result = "TEXTUREPROJ2DI4";
			break;

		case CombinedImageAccess::eTextureProj2DI4Bias:
			result = "TEXTUREPROJ2DI4BIAS";
			break;

		case CombinedImageAccess::eTextureProj3DI:
			result = "TEXTUREPROJ3DI";
			break;

		case CombinedImageAccess::eTextureProj3DIBias:
			result = "TEXTUREPROJ3DIBIAS";
			break;

		case CombinedImageAccess::eTextureProj2DRectI3:
			result = "TEXTUREPROJ2DRECTI3";
			break;

		case CombinedImageAccess::eTextureProj2DRectI4:
			result = "TEXTUREPROJ2DRECTI4";
			break;

		case CombinedImageAccess::eTextureProj1DU2:
			result = "TEXTUREPROJ1DU2";
			break;

		case CombinedImageAccess::eTextureProj1DU2Bias:
			result = "TEXTUREPROJ1DU2BIAS";
			break;

		case CombinedImageAccess::eTextureProj1DU4:
			result = "TEXTUREPROJ1DU4";
			break;

		case CombinedImageAccess::eTextureProj1DU4Bias:
			result = "TEXTUREPROJ1DU4BIAS";
			break;

		case CombinedImageAccess::eTextureProj2DU3:
			result = "TEXTUREPROJ2DU3";
			break;

		case CombinedImageAccess::eTextureProj2DU3Bias:
			result = "TEXTUREPROJ2DU3BIAS";
			break;

		case CombinedImageAccess::eTextureProj2DU4:
			result = "TEXTUREPROJ2DU4";
			break;

		case CombinedImageAccess::eTextureProj2DU4Bias:
			result = "TEXTUREPROJ2DU4BIAS";
			break;

		case CombinedImageAccess::eTextureProj3DU:
			result = "TEXTUREPROJ3DU";
			break;

		case CombinedImageAccess::eTextureProj3DUBias:
			result = "TEXTUREPROJ3DUBIAS";
			break;

		case CombinedImageAccess::eTextureProj2DRectU3:
			result = "TEXTUREPROJ2DRECTU3";
			break;

		case CombinedImageAccess::eTextureProj2DRectU4:
			result = "TEXTUREPROJ2DRECTU4";
			break;

		case CombinedImageAccess::eTextureLod1DF:
			result = "TEXTURELOD1DF";
			break;

		case CombinedImageAccess::eTextureLod2DF:
			result = "TEXTURELOD2DF";
			break;

		case CombinedImageAccess::eTextureLod3DF:
			result = "TEXTURELOD3DF";
			break;

		case CombinedImageAccess::eTextureLodCubeF:
			result = "TEXTURELODCUBEF";
			break;

		case CombinedImageAccess::eTextureLod1DArrayF:
			result = "TEXTURELOD1DARRAYF";
			break;

		case CombinedImageAccess::eTextureLod2DArrayF:
			result = "TEXTURELOD2DARRAYF";
			break;

		case CombinedImageAccess::eTextureLodCubeArrayF:
			result = "TEXTURELODCUBEARRAYF";
			break;

		case CombinedImageAccess::eTextureLod1DI:
			result = "TEXTURELOD1DI";
			break;

		case CombinedImageAccess::eTextureLod2DI:
			result = "TEXTURELOD2DI";
			break;

		case CombinedImageAccess::eTextureLod3DI:
			result = "TEXTURELOD3DI";
			break;

		case CombinedImageAccess::eTextureLodCubeI:
			result = "TEXTURELODCUBEI";
			break;

		case CombinedImageAccess::eTextureLod1DArrayI:
			result = "TEXTURELOD1DARRAYI";
			break;

		case CombinedImageAccess::eTextureLod2DArrayI:
			result = "TEXTURELOD2DARRAYI";
			break;

		case CombinedImageAccess::eTextureLodCubeArrayI:
			result = "TEXTURELODCUBEARRAYI";
			break;

		case CombinedImageAccess::eTextureLod1DU:
			result = "TEXTURELOD1DU";
			break;

		case CombinedImageAccess::eTextureLod2DU:
			result = "TEXTURELOD2DU";
			break;

		case CombinedImageAccess::eTextureLod3DU:
			result = "TEXTURELOD3DU";
			break;

		case CombinedImageAccess::eTextureLodCubeU:
			result = "TEXTURELODCUBEU";
			break;

		case CombinedImageAccess::eTextureLod1DArrayU:
			result = "TEXTURELOD1DARRAYU";
			break;

		case CombinedImageAccess::eTextureLod2DArrayU:
			result = "TEXTURELOD2DARRAYU";
			break;

		case CombinedImageAccess::eTextureLodCubeArrayU:
			result = "TEXTURELODCUBEARRAYU";
			break;

		case CombinedImageAccess::eTextureOffset1DF:
			result = "TEXTUREOFFSET1DF";
			break;

		case CombinedImageAccess::eTextureOffset1DFBias:
			result = "TEXTUREOFFSET1DFBIAS";
			break;

		case CombinedImageAccess::eTextureOffset2DF:
			result = "TEXTUREOFFSET2DF";
			break;

		case CombinedImageAccess::eTextureOffset2DFBias:
			result = "TEXTUREOFFSET2DFBIAS";
			break;

		case CombinedImageAccess::eTextureOffset3DF:
			result = "TEXTUREOFFSET3DF";
			break;

		case CombinedImageAccess::eTextureOffset3DFBias:
			result = "TEXTUREOFFSET3DFBIAS";
			break;

		case CombinedImageAccess::eTextureOffset2DRectF:
			result = "TEXTUREOFFSET2DRECTF";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayF:
			result = "TEXTUREOFFSET1DARRAYF";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayFBias:
			result = "TEXTUREOFFSET1DARRAYFBIAS";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayF:
			result = "TEXTUREOFFSET2DARRAYF";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayFBias:
			result = "TEXTUREOFFSET2DARRAYFBIAS";
			break;

		case CombinedImageAccess::eTextureOffset1DI:
			result = "TEXTUREOFFSET1DI";
			break;

		case CombinedImageAccess::eTextureOffset1DIBias:
			result = "TEXTUREOFFSET1DIBIAS";
			break;

		case CombinedImageAccess::eTextureOffset2DI:
			result = "TEXTUREOFFSET2DI";
			break;

		case CombinedImageAccess::eTextureOffset2DIBias:
			result = "TEXTUREOFFSET2DIBIAS";
			break;

		case CombinedImageAccess::eTextureOffset3DI:
			result = "TEXTUREOFFSET3DI";
			break;

		case CombinedImageAccess::eTextureOffset3DIBias:
			result = "TEXTUREOFFSET3DIBIAS";
			break;

		case CombinedImageAccess::eTextureOffset2DRectI:
			result = "TEXTUREOFFSET2DRECTI";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayI:
			result = "TEXTUREOFFSET1DARRAYI";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayIBias:
			result = "TEXTUREOFFSET1DARRAYIBIAS";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayI:
			result = "TEXTUREOFFSET2DARRAYI";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayIBias:
			result = "TEXTUREOFFSET2DARRAYIBIAS";
			break;

		case CombinedImageAccess::eTextureOffset1DU:
			result = "TEXTUREOFFSET1DU";
			break;

		case CombinedImageAccess::eTextureOffset1DUBias:
			result = "TEXTUREOFFSET1DUBIAS";
			break;

		case CombinedImageAccess::eTextureOffset2DU:
			result = "TEXTUREOFFSET2DU";
			break;

		case CombinedImageAccess::eTextureOffset2DUBias:
			result = "TEXTUREOFFSET2DUBIAS";
			break;

		case CombinedImageAccess::eTextureOffset3DU:
			result = "TEXTUREOFFSET3DU";
			break;

		case CombinedImageAccess::eTextureOffset3DUBias:
			result = "TEXTUREOFFSET3DUBIAS";
			break;

		case CombinedImageAccess::eTextureOffset2DRectU:
			result = "TEXTUREOFFSET2DRECTU";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayU:
			result = "TEXTUREOFFSET1DARRAYU";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayUBias:
			result = "TEXTUREOFFSET1DARRAYUBIAS";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayU:
			result = "TEXTUREOFFSET2DARRAYU";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayUBias:
			result = "TEXTUREOFFSET2DARRAYUBIAS";
			break;

		case CombinedImageAccess::eTexelFetch1DF:
			result = "TEXELFETCH1DF";
			break;

		case CombinedImageAccess::eTexelFetch2DF:
			result = "TEXELFETCH2DF";
			break;

		case CombinedImageAccess::eTexelFetch3DF:
			result = "TEXELFETCH3DF";
			break;

		case CombinedImageAccess::eTexelFetch2DRectF:
			result = "TEXELFETCH2DRECTF";
			break;

		case CombinedImageAccess::eTexelFetch1DArrayF:
			result = "TEXELFETCH1DARRAYF";
			break;

		case CombinedImageAccess::eTexelFetch2DArrayF:
			result = "TEXELFETCH2DARRAYF";
			break;

		case CombinedImageAccess::eTexelFetchBufferF:
			result = "TEXELFETCHBUFFERF";
			break;

		case CombinedImageAccess::eTexelFetch1DI:
			result = "TEXELFETCH1DI";
			break;

		case CombinedImageAccess::eTexelFetch2DI:
			result = "TEXELFETCH2DI";
			break;

		case CombinedImageAccess::eTexelFetch3DI:
			result = "TEXELFETCH3DI";
			break;

		case CombinedImageAccess::eTexelFetch2DRectI:
			result = "TEXELFETCH2DRECTI";
			break;

		case CombinedImageAccess::eTexelFetch1DArrayI:
			result = "TEXELFETCH1DARRAYI";
			break;

		case CombinedImageAccess::eTexelFetch2DArrayI:
			result = "TEXELFETCH2DARRAYI";
			break;

		case CombinedImageAccess::eTexelFetchBufferI:
			result = "TEXELFETCHBUFFERI";
			break;

		case CombinedImageAccess::eTexelFetch1DU:
			result = "TEXELFETCH1DU";
			break;

		case CombinedImageAccess::eTexelFetch2DU:
			result = "TEXELFETCH2DU";
			break;

		case CombinedImageAccess::eTexelFetch3DU:
			result = "TEXELFETCH3DU";
			break;

		case CombinedImageAccess::eTexelFetch2DRectU:
			result = "TEXELFETCH2DRECTU";
			break;

		case CombinedImageAccess::eTexelFetch1DArrayU:
			result = "TEXELFETCH1DARRAYU";
			break;

		case CombinedImageAccess::eTexelFetch2DArrayU:
			result = "TEXELFETCH2DARRAYU";
			break;

		case CombinedImageAccess::eTexelFetchBufferU:
			result = "TEXELFETCHBUFFERU";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DF:
			result = "TEXELFETCHOFFSET1DF";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DF:
			result = "TEXELFETCHOFFSET2DF";
			break;

		case CombinedImageAccess::eTexelFetchOffset3DF:
			result = "TEXELFETCHOFFSET3DF";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DRectF:
			result = "TEXELFETCHOFFSET2DRECTF";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DArrayF:
			result = "TEXELFETCHOFFSET1DARRAYF";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DArrayF:
			result = "TEXELFETCHOFFSET2DARRAYF";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DI:
			result = "TEXELFETCHOFFSET1DI";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DI:
			result = "TEXELFETCHOFFSET2DI";
			break;

		case CombinedImageAccess::eTexelFetchOffset3DI:
			result = "TEXELFETCHOFFSET3DI";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DRectI:
			result = "TEXELFETCHOFFSET2DRECTI";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DArrayI:
			result = "TEXELFETCHOFFSET1DARRAYI";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DArrayI:
			result = "TEXELFETCHOFFSET2DARRAYI";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DU:
			result = "TEXELFETCHOFFSET1DU";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DU:
			result = "TEXELFETCHOFFSET2DU";
			break;

		case CombinedImageAccess::eTexelFetchOffset3DU:
			result = "TEXELFETCHOFFSET3DU";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DRectU:
			result = "TEXELFETCHOFFSET2DRECTU";
			break;

		case CombinedImageAccess::eTexelFetchOffset1DArrayU:
			result = "TEXELFETCHOFFSET1DARRAYU";
			break;

		case CombinedImageAccess::eTexelFetchOffset2DArrayU:
			result = "TEXELFETCHOFFSET2DARRAYU";
			break;

		case CombinedImageAccess::eTextureProjOffset1DF2:
			result = "TEXTUREPROJOFFSET1DF2";
			break;

		case CombinedImageAccess::eTextureProjOffset1DF2Bias:
			result = "TEXTUREPROJOFFSET1DF2BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset1DF4:
			result = "TEXTUREPROJOFFSET1DF4";
			break;

		case CombinedImageAccess::eTextureProjOffset1DF4Bias:
			result = "TEXTUREPROJOFFSET1DF4BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset2DF3:
			result = "TEXTUREPROJOFFSET2DF3";
			break;

		case CombinedImageAccess::eTextureProjOffset2DF3Bias:
			result = "TEXTUREPROJOFFSET2DF3BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset2DF4:
			result = "TEXTUREPROJOFFSET2DF4";
			break;

		case CombinedImageAccess::eTextureProjOffset2DF4Bias:
			result = "TEXTUREPROJOFFSET2DF4BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset3DF:
			result = "TEXTUREPROJOFFSET3DF";
			break;

		case CombinedImageAccess::eTextureProjOffset3DFBias:
			result = "TEXTUREPROJOFFSET3DFBIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset2DRectF3:
			result = "TEXTUREPROJOFFSET2DRECTF3";
			break;

		case CombinedImageAccess::eTextureProjOffset2DRectF4:
			result = "TEXTUREPROJOFFSET2DRECTF4";
			break;

		case CombinedImageAccess::eTextureProjOffset1DI2:
			result = "TEXTUREPROJOFFSET1DI2";
			break;

		case CombinedImageAccess::eTextureProjOffset1DI2Bias:
			result = "TEXTUREPROJOFFSET1DI2BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset1DI4:
			result = "TEXTUREPROJOFFSET1DI4";
			break;

		case CombinedImageAccess::eTextureProjOffset1DI4Bias:
			result = "TEXTUREPROJOFFSET1DI4BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset2DI3:
			result = "TEXTUREPROJOFFSET2DI3";
			break;

		case CombinedImageAccess::eTextureProjOffset2DI3Bias:
			result = "TEXTUREPROJOFFSET2DI3BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset2DI4:
			result = "TEXTUREPROJOFFSET2DI4";
			break;

		case CombinedImageAccess::eTextureProjOffset2DI4Bias:
			result = "TEXTUREPROJOFFSET2DI4BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset3DI:
			result = "TEXTUREPROJOFFSET3DI";
			break;

		case CombinedImageAccess::eTextureProjOffset3DIBias:
			result = "TEXTUREPROJOFFSET3DIBIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset2DRectI3:
			result = "TEXTUREPROJOFFSET2DRECTI3";
			break;

		case CombinedImageAccess::eTextureProjOffset2DRectI4:
			result = "TEXTUREPROJOFFSET2DRECTI4";
			break;

		case CombinedImageAccess::eTextureProjOffset1DU2:
			result = "TEXTUREPROJOFFSET1DU2";
			break;

		case CombinedImageAccess::eTextureProjOffset1DU2Bias:
			result = "TEXTUREPROJOFFSET1DU2BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset1DU4:
			result = "TEXTUREPROJOFFSET1DU4";
			break;

		case CombinedImageAccess::eTextureProjOffset1DU4Bias:
			result = "TEXTUREPROJOFFSET1DU4BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset2DU3:
			result = "TEXTUREPROJOFFSET2DU3";
			break;

		case CombinedImageAccess::eTextureProjOffset2DU3Bias:
			result = "TEXTUREPROJOFFSET2DU3BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset2DU4:
			result = "TEXTUREPROJOFFSET2DU4";
			break;

		case CombinedImageAccess::eTextureProjOffset2DU4Bias:
			result = "TEXTUREPROJOFFSET2DU4BIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset3DU:
			result = "TEXTUREPROJOFFSET3DU";
			break;

		case CombinedImageAccess::eTextureProjOffset3DUBias:
			result = "TEXTUREPROJOFFSET3DUBIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset2DRectU3:
			result = "TEXTUREPROJOFFSET2DRECTU3";
			break;

		case CombinedImageAccess::eTextureProjOffset2DRectU4:
			result = "TEXTUREPROJOFFSET2DRECTU4";
			break;

		case CombinedImageAccess::eTextureLodOffset1DF:
			result = "TEXTURELODOFFSET1DF";
			break;

		case CombinedImageAccess::eTextureLodOffset2DF:
			result = "TEXTURELODOFFSET2DF";
			break;

		case CombinedImageAccess::eTextureLodOffset3DF:
			result = "TEXTURELODOFFSET3DF";
			break;

		case CombinedImageAccess::eTextureLodOffset1DArrayF:
			result = "TEXTURELODOFFSET1DARRAYF";
			break;

		case CombinedImageAccess::eTextureLodOffset2DArrayF:
			result = "TEXTURELODOFFSET2DARRAYF";
			break;

		case CombinedImageAccess::eTextureLodOffset1DI:
			result = "TEXTURELODOFFSET1DI";
			break;

		case CombinedImageAccess::eTextureLodOffset2DI:
			result = "TEXTURELODOFFSET2DI";
			break;

		case CombinedImageAccess::eTextureLodOffset3DI:
			result = "TEXTURELODOFFSET3DI";
			break;

		case CombinedImageAccess::eTextureLodOffset1DArrayI:
			result = "TEXTURELODOFFSET1DARRAYI";
			break;

		case CombinedImageAccess::eTextureLodOffset2DArrayI:
			result = "TEXTURELODOFFSET2DARRAYI";
			break;

		case CombinedImageAccess::eTextureLodOffset1DU:
			result = "TEXTURELODOFFSET1DU";
			break;

		case CombinedImageAccess::eTextureLodOffset2DU:
			result = "TEXTURELODOFFSET2DU";
			break;

		case CombinedImageAccess::eTextureLodOffset3DU:
			result = "TEXTURELODOFFSET3DU";
			break;

		case CombinedImageAccess::eTextureLodOffset1DArrayU:
			result = "TEXTURELODOFFSET1DARRAYU";
			break;

		case CombinedImageAccess::eTextureLodOffset2DArrayU:
			result = "TEXTURELODOFFSET2DARRAYU";
			break;

		case CombinedImageAccess::eTextureProjLod1DF2:
			result = "TEXTUREPROJLOD1DF2";
			break;

		case CombinedImageAccess::eTextureProjLod1DF4:
			result = "TEXTUREPROJLOD1DF4";
			break;

		case CombinedImageAccess::eTextureProjLod2DF3:
			result = "TEXTUREPROJLOD2DF3";
			break;

		case CombinedImageAccess::eTextureProjLod2DF4:
			result = "TEXTUREPROJLOD2DF4";
			break;

		case CombinedImageAccess::eTextureProjLod3DF:
			result = "TEXTUREPROJLOD3DF";
			break;

		case CombinedImageAccess::eTextureProjLod1DI2:
			result = "TEXTUREPROJLOD1DI2";
			break;

		case CombinedImageAccess::eTextureProjLod1DI4:
			result = "TEXTUREPROJLOD1DI4";
			break;

		case CombinedImageAccess::eTextureProjLod2DI3:
			result = "TEXTUREPROJLOD2DI3";
			break;

		case CombinedImageAccess::eTextureProjLod2DI4:
			result = "TEXTUREPROJLOD2DI4";
			break;

		case CombinedImageAccess::eTextureProjLod3DI:
			result = "TEXTUREPROJLOD3DI";
			break;

		case CombinedImageAccess::eTextureProjLod1DU2:
			result = "TEXTUREPROJLOD1DU2";
			break;

		case CombinedImageAccess::eTextureProjLod1DU4:
			result = "TEXTUREPROJLOD1DU4";
			break;

		case CombinedImageAccess::eTextureProjLod2DU3:
			result = "TEXTUREPROJLOD2DU3";
			break;

		case CombinedImageAccess::eTextureProjLod2DU4:
			result = "TEXTUREPROJLOD2DU4";
			break;

		case CombinedImageAccess::eTextureProjLod3DU:
			result = "TEXTUREPROJLOD3DU";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DF2:
			result = "TEXTUREPROJLODOFFSET1DF2";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DF4:
			result = "TEXTUREPROJLODOFFSET1DF4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DF3:
			result = "TEXTUREPROJLODOFFSET2DF3";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DF4:
			result = "TEXTUREPROJLODOFFSET2DF4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset3DF:
			result = "TEXTUREPROJLODOFFSET3DF";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DI2:
			result = "TEXTUREPROJLODOFFSET1DI2";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DI4:
			result = "TEXTUREPROJLODOFFSET1DI4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DI3:
			result = "TEXTUREPROJLODOFFSET2DI3";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DI4:
			result = "TEXTUREPROJLODOFFSET2DI4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset3DI:
			result = "TEXTUREPROJLODOFFSET3DI";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DU2:
			result = "TEXTUREPROJLODOFFSET1DU2";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DU4:
			result = "TEXTUREPROJLODOFFSET1DU4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DU3:
			result = "TEXTUREPROJLODOFFSET2DU3";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DU4:
			result = "TEXTUREPROJLODOFFSET2DU4";
			break;

		case CombinedImageAccess::eTextureProjLodOffset3DU:
			result = "TEXTUREPROJLODOFFSET3DU";
			break;

		case CombinedImageAccess::eTextureGrad1DF:
			result = "TEXTUREGRAD1DF";
			break;

		case CombinedImageAccess::eTextureGrad2DF:
			result = "TEXTUREGRAD2DF";
			break;

		case CombinedImageAccess::eTextureGrad3DF:
			result = "TEXTUREGRAD3DF";
			break;

		case CombinedImageAccess::eTextureGradCubeF:
			result = "TEXTUREGRADCUBEF";
			break;

		case CombinedImageAccess::eTextureGrad2DRectF:
			result = "TEXTUREGRAD2DRECTF";
			break;

		case CombinedImageAccess::eTextureGrad1DArrayF:
			result = "TEXTUREGRAD1DARRAYF";
			break;

		case CombinedImageAccess::eTextureGrad2DArrayF:
			result = "TEXTUREGRAD2DARRAYF";
			break;

		case CombinedImageAccess::eTextureGradCubeArrayF:
			result = "TEXTUREGRADCUBEARRAYF";
			break;

		case CombinedImageAccess::eTextureGrad1DI:
			result = "TEXTUREGRAD1DI";
			break;

		case CombinedImageAccess::eTextureGrad2DI:
			result = "TEXTUREGRAD2DI";
			break;

		case CombinedImageAccess::eTextureGrad3DI:
			result = "TEXTUREGRAD3DI";
			break;

		case CombinedImageAccess::eTextureGradCubeI:
			result = "TEXTUREGRADCUBEI";
			break;

		case CombinedImageAccess::eTextureGrad2DRectI:
			result = "TEXTUREGRAD2DRECTI";
			break;

		case CombinedImageAccess::eTextureGrad1DArrayI:
			result = "TEXTUREGRAD1DARRAYI";
			break;

		case CombinedImageAccess::eTextureGrad2DArrayI:
			result = "TEXTUREGRAD2DARRAYI";
			break;

		case CombinedImageAccess::eTextureGradCubeArrayI:
			result = "TEXTUREGRADCUBEARRAYI";
			break;

		case CombinedImageAccess::eTextureGrad1DU:
			result = "TEXTUREGRAD1DU";
			break;

		case CombinedImageAccess::eTextureGrad2DU:
			result = "TEXTUREGRAD2DU";
			break;

		case CombinedImageAccess::eTextureGrad3DU:
			result = "TEXTUREGRAD3DU";
			break;

		case CombinedImageAccess::eTextureGradCubeU:
			result = "TEXTUREGRADCUBEU";
			break;

		case CombinedImageAccess::eTextureGrad2DRectU:
			result = "TEXTUREGRAD2DRECTU";
			break;

		case CombinedImageAccess::eTextureGrad1DArrayU:
			result = "TEXTUREGRAD1DARRAYU";
			break;

		case CombinedImageAccess::eTextureGrad2DArrayU:
			result = "TEXTUREGRAD2DARRAYU";
			break;

		case CombinedImageAccess::eTextureGradCubeArrayU:
			result = "TEXTUREGRADCUBEARRAYU";
			break;

		case CombinedImageAccess::eTextureGradOffset1DF:
			result = "TEXTUREGRADOFFSET1DF";
			break;

		case CombinedImageAccess::eTextureGradOffset2DF:
			result = "TEXTUREGRADOFFSET2DF";
			break;

		case CombinedImageAccess::eTextureGradOffset3DF:
			result = "TEXTUREGRADOFFSET3DF";
			break;

		case CombinedImageAccess::eTextureGradOffset2DRectF:
			result = "TEXTUREGRADOFFSET2DRECTF";
			break;

		case CombinedImageAccess::eTextureGradOffset1DArrayF:
			result = "TEXTUREGRADOFFSET1DARRAYF";
			break;

		case CombinedImageAccess::eTextureGradOffset2DArrayF:
			result = "TEXTUREGRADOFFSET2DARRAYF";
			break;

		case CombinedImageAccess::eTextureGradOffset1DI:
			result = "TEXTUREGRADOFFSET1DI";
			break;

		case CombinedImageAccess::eTextureGradOffset2DI:
			result = "TEXTUREGRADOFFSET2DI";
			break;

		case CombinedImageAccess::eTextureGradOffset3DI:
			result = "TEXTUREGRADOFFSET3DI";
			break;

		case CombinedImageAccess::eTextureGradOffset2DRectI:
			result = "TEXTUREGRADOFFSET2DRECTI";
			break;

		case CombinedImageAccess::eTextureGradOffset1DArrayI:
			result = "TEXTUREGRADOFFSET1DARRAYI";
			break;

		case CombinedImageAccess::eTextureGradOffset2DArrayI:
			result = "TEXTUREGRADOFFSET2DARRAYI";
			break;

		case CombinedImageAccess::eTextureGradOffset1DU:
			result = "TEXTUREGRADOFFSET1DU";
			break;

		case CombinedImageAccess::eTextureGradOffset2DU:
			result = "TEXTUREGRADOFFSET2DU";
			break;

		case CombinedImageAccess::eTextureGradOffset3DU:
			result = "TEXTUREGRADOFFSET3DU";
			break;

		case CombinedImageAccess::eTextureGradOffset2DRectU:
			result = "TEXTUREGRADOFFSET2DRECTU";
			break;

		case CombinedImageAccess::eTextureGradOffset1DArrayU:
			result = "TEXTUREGRADOFFSET1DARRAYU";
			break;

		case CombinedImageAccess::eTextureGradOffset2DArrayU:
			result = "TEXTUREGRADOFFSET2DARRAYU";
			break;

		case CombinedImageAccess::eTextureProjGrad1DF2:
			result = "TEXTUREPROJGRAD1DF2";
			break;

		case CombinedImageAccess::eTextureProjGrad1DF4:
			result = "TEXTUREPROJGRAD1DF4";
			break;

		case CombinedImageAccess::eTextureProjGrad2DF3:
			result = "TEXTUREPROJGRAD2DF3";
			break;

		case CombinedImageAccess::eTextureProjGrad2DF4:
			result = "TEXTUREPROJGRAD2DF4";
			break;

		case CombinedImageAccess::eTextureProjGrad3DF:
			result = "TEXTUREPROJGRAD3DF";
			break;

		case CombinedImageAccess::eTextureProjGrad2DRectF3:
			result = "TEXTUREPROJGRAD2DRECTF3";
			break;

		case CombinedImageAccess::eTextureProjGrad2DRectF4:
			result = "TEXTUREPROJGRAD2DRECTF4";
			break;

		case CombinedImageAccess::eTextureProjGrad1DI2:
			result = "TEXTUREPROJGRAD1DI2";
			break;

		case CombinedImageAccess::eTextureProjGrad1DI4:
			result = "TEXTUREPROJGRAD1DI4";
			break;

		case CombinedImageAccess::eTextureProjGrad2DI3:
			result = "TEXTUREPROJGRAD2DI3";
			break;

		case CombinedImageAccess::eTextureProjGrad2DI4:
			result = "TEXTUREPROJGRAD2DI4";
			break;

		case CombinedImageAccess::eTextureProjGrad3DI:
			result = "TEXTUREPROJGRAD3DI";
			break;

		case CombinedImageAccess::eTextureProjGrad2DRectI3:
			result = "TEXTUREPROJGRAD2DRECTI3";
			break;

		case CombinedImageAccess::eTextureProjGrad2DRectI4:
			result = "TEXTUREPROJGRAD2DRECTI4";
			break;

		case CombinedImageAccess::eTextureProjGrad1DU2:
			result = "TEXTUREPROJGRAD1DU2";
			break;

		case CombinedImageAccess::eTextureProjGrad1DU4:
			result = "TEXTUREPROJGRAD1DU4";
			break;

		case CombinedImageAccess::eTextureProjGrad2DU3:
			result = "TEXTUREPROJGRAD2DU3";
			break;

		case CombinedImageAccess::eTextureProjGrad2DU4:
			result = "TEXTUREPROJGRAD2DU4";
			break;

		case CombinedImageAccess::eTextureProjGrad3DU:
			result = "TEXTUREPROJGRAD3DU";
			break;

		case CombinedImageAccess::eTextureProjGrad2DRectU3:
			result = "TEXTUREPROJGRAD2DRECTU3";
			break;

		case CombinedImageAccess::eTextureProjGrad2DRectU4:
			result = "TEXTUREPROJGRAD2DRECTU4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DF2:
			result = "TEXTUREPROJGRADOFFSET1DF2";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DF4:
			result = "TEXTUREPROJGRADOFFSET1DF4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DF3:
			result = "TEXTUREPROJGRADOFFSET2DF3";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DF4:
			result = "TEXTUREPROJGRADOFFSET2DF4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset3DF:
			result = "TEXTUREPROJGRADOFFSET3DF";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DRectF3:
			result = "TEXTUREPROJGRADOFFSET2DRECTF3";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DRectF4:
			result = "TEXTUREPROJGRADOFFSET2DRECTF4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DI2:
			result = "TEXTUREPROJGRADOFFSET1DI2";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DI4:
			result = "TEXTUREPROJGRADOFFSET1DI4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DI3:
			result = "TEXTUREPROJGRADOFFSET2DI3";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DI4:
			result = "TEXTUREPROJGRADOFFSET2DI4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset3DI:
			result = "TEXTUREPROJGRADOFFSET3DI";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DRectI3:
			result = "TEXTUREPROJGRADOFFSET2DRECTI3";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DRectI4:
			result = "TEXTUREPROJGRADOFFSET2DRECTI4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DU2:
			result = "TEXTUREPROJGRADOFFSET1DU2";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DU4:
			result = "TEXTUREPROJGRADOFFSET1DU4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DU3:
			result = "TEXTUREPROJGRADOFFSET2DU3";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DU4:
			result = "TEXTUREPROJGRADOFFSET2DU4";
			break;

		case CombinedImageAccess::eTextureProjGradOffset3DU:
			result = "TEXTUREPROJGRADOFFSET3DU";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DRectU3:
			result = "TEXTUREPROJGRADOFFSET2DRECTU3";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DRectU4:
			result = "TEXTUREPROJGRADOFFSET2DRECTU4";
			break;

	
	// Texel Compare Functions
		case CombinedImageAccess::eTexture1DShadowF:
			result = "TEXTURE1DSHADOWF";
			break;

		case CombinedImageAccess::eTexture1DShadowFBias:
			result = "TEXTURE1DSHADOWFBIAS";
			break;

		case CombinedImageAccess::eTexture2DShadowF:
			result = "TEXTURE2DSHADOWF";
			break;

		case CombinedImageAccess::eTexture2DShadowFBias:
			result = "TEXTURE2DSHADOWFBIAS";
			break;

		case CombinedImageAccess::eTextureCubeShadowF:
			result = "TEXTURECUBESHADOWF";
			break;

		case CombinedImageAccess::eTextureCubeShadowFBias:
			result = "TEXTURECUBESHADOWFBIAS";
			break;

		case CombinedImageAccess::eTexture1DArrayShadowF:
			result = "TEXTURE1DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTexture1DArrayShadowFBias:
			result = "TEXTURE1DARRAYSHADOWFBIAS";
			break;

		case CombinedImageAccess::eTexture2DArrayShadowF:
			result = "TEXTURE2DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTexture2DRectShadowF:
			result = "TEXTURE2DRECTSHADOWF";
			break;

		case CombinedImageAccess::eTextureCubeArrayShadowF:
			result = "TEXTURECUBEARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureProj1DShadowF:
			result = "TEXTUREPROJ1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureProj1DShadowFBias:
			result = "TEXTUREPROJ1DSHADOWFBIAS";
			break;

		case CombinedImageAccess::eTextureProj2DShadowF:
			result = "TEXTUREPROJ2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureProj2DShadowFBias:
			result = "TEXTUREPROJ2DSHADOWFBIAS";
			break;

		case CombinedImageAccess::eTextureProj2DRectShadowF:
			result = "TEXTUREPROJ2DRECTSHADOWF";
			break;

		case CombinedImageAccess::eTextureLod1DShadowF:
			result = "TEXTURELOD1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureLod2DShadowF:
			result = "TEXTURELOD2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureLod1DArrayShadowF:
			result = "TEXTURELOD1DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureOffset2DRectShadowF:
			result = "TEXTUREOFFSET2DRECTSHADOWF";
			break;

		case CombinedImageAccess::eTextureOffset1DShadowF:
			result = "TEXTUREOFFSET1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureOffset1DShadowFBias:
			result = "TEXTUREOFFSET1DSHADOWFBIAS";
			break;

		case CombinedImageAccess::eTextureOffset2DShadowF:
			result = "TEXTUREOFFSET2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureOffset2DShadowFBias:
			result = "TEXTUREOFFSET2DSHADOWFBIAS";
			break;

		case CombinedImageAccess::eTextureOffset1DArrayShadowF:
			result = "TEXTUREOFFSET1DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureOffset2DArrayShadowF:
			result = "TEXTUREOFFSET2DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjOffset1DShadowF:
			result = "TEXTUREPROJOFFSET1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjOffset1DShadowFBias:
			result = "TEXTUREPROJOFFSET1DSHADOWFBIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset2DShadowF:
			result = "TEXTUREPROJOFFSET2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjOffset2DShadowFBias:
			result = "TEXTUREPROJOFFSET2DSHADOWFBIAS";
			break;

		case CombinedImageAccess::eTextureProjOffset2DRectShadowF:
			result = "TEXTUREPROJOFFSET2DRECTSHADOWF";
			break;

		case CombinedImageAccess::eTextureLodOffset1DShadowF:
			result = "TEXTURELODOFFSET1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureLodOffset2DShadowF:
			result = "TEXTURELODOFFSET2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
			result = "TEXTURELODOFFSET1DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjLod1DShadowF:
			result = "TEXTUREPROJLOD1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjLod2DShadowF:
			result = "TEXTUREPROJLOD2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjLodOffset1DShadowF:
			result = "TEXTUREPROJLODOFFSET1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjLodOffset2DShadowF:
			result = "TEXTUREPROJLODOFFSET2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureGrad2DRectShadowF:
			result = "TEXTUREGRAD2DRECTSHADOWF";
			break;

		case CombinedImageAccess::eTextureGrad1DShadowF:
			result = "TEXTUREGRAD1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureGrad2DShadowF:
			result = "TEXTUREGRAD2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureGrad1DArrayShadowF:
			result = "TEXTUREGRAD1DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureGradOffset2DRectShadowF:
			result = "TEXTUREGRADOFFSET2DRECTSHADOWF";
			break;

		case CombinedImageAccess::eTextureGradOffset1DShadowF:
			result = "TEXTUREGRADOFFSET1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureGradOffset2DShadowF:
			result = "TEXTUREGRADOFFSET2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
			result = "TEXTUREGRADOFFSET1DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
			result = "TEXTUREGRADOFFSET2DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjGrad1DShadowF:
			result = "TEXTUREPROJGRAD1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjGrad2DShadowF:
			result = "TEXTUREPROJGRAD2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjGrad2DRectShadowF:
			result = "TEXTUREPROJGRAD2DRECTSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjGradOffset1DShadowF:
			result = "TEXTUREPROJGRADOFFSET1DSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DShadowF:
			result = "TEXTUREPROJGRADOFFSET2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureProjGradOffset2DRectShadowF:
			result = "TEXTUREPROJGRADOFFSET2DRECTSHADOWF";
			break;


	// Texture Gather Functions
		case CombinedImageAccess::eTextureGather2DF:
			result = "TEXTUREGATHER2DF";
			break;

		case CombinedImageAccess::eTextureGather2DArrayF:
			result = "TEXTUREGATHER2DARRAYF";
			break;

		case CombinedImageAccess::eTextureGatherCubeF:
			result = "TEXTUREGATHERCUBEF";
			break;

		case CombinedImageAccess::eTextureGatherCubeArrayF:
			result = "TEXTUREGATHERCUBEARRAYF";
			break;

		case CombinedImageAccess::eTextureGather2DRectF:
			result = "TEXTUREGATHER2DRECTF";
			break;

		case CombinedImageAccess::eTextureGather2DI:
			result = "TEXTUREGATHER2DI";
			break;

		case CombinedImageAccess::eTextureGather2DArrayI:
			result = "TEXTUREGATHER2DARRAYI";
			break;

		case CombinedImageAccess::eTextureGatherCubeI:
			result = "TEXTUREGATHERCUBEI";
			break;

		case CombinedImageAccess::eTextureGatherCubeArrayI:
			result = "TEXTUREGATHERCUBEARRAYI";
			break;

		case CombinedImageAccess::eTextureGather2DRectI:
			result = "TEXTUREGATHER2DRECTI";
			break;

		case CombinedImageAccess::eTextureGather2DU:
			result = "TEXTUREGATHER2DU";
			break;

		case CombinedImageAccess::eTextureGather2DArrayU:
			result = "TEXTUREGATHER2DARRAYU";
			break;

		case CombinedImageAccess::eTextureGatherCubeU:
			result = "TEXTUREGATHERCUBEU";
			break;

		case CombinedImageAccess::eTextureGatherCubeArrayU:
			result = "TEXTUREGATHERCUBEARRAYU";
			break;

		case CombinedImageAccess::eTextureGather2DRectU:
			result = "TEXTUREGATHER2DRECTU";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DF:
			result = "TEXTUREGATHEROFFSET2DF";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DArrayF:
			result = "TEXTUREGATHEROFFSET2DARRAYF";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DRectF:
			result = "TEXTUREGATHEROFFSET2DRECTF";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DI:
			result = "TEXTUREGATHEROFFSET2DI";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DArrayI:
			result = "TEXTUREGATHEROFFSET2DARRAYI";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DRectI:
			result = "TEXTUREGATHEROFFSET2DRECTI";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DU:
			result = "TEXTUREGATHEROFFSET2DU";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DArrayU:
			result = "TEXTUREGATHEROFFSET2DARRAYU";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DRectU:
			result = "TEXTUREGATHEROFFSET2DRECTU";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DF:
			result = "TEXTUREGATHEROFFSETS2DF";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DArrayF:
			result = "TEXTUREGATHEROFFSETS2DARRAYF";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DRectF:
			result = "TEXTUREGATHEROFFSETS2DRECTF";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DI:
			result = "TEXTUREGATHEROFFSETS2DI";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DArrayI:
			result = "TEXTUREGATHEROFFSETS2DARRAYI";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DRectI:
			result = "TEXTUREGATHEROFFSETS2DRECTI";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DU:
			result = "TEXTUREGATHEROFFSETS2DU";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DArrayU:
			result = "TEXTUREGATHEROFFSETS2DARRAYU";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DRectU:
			result = "TEXTUREGATHEROFFSETS2DRECTU";
			break;


	// Texture Gather Compare Functions
		case CombinedImageAccess::eTextureGather2DShadowF:
			result = "TEXTUREGATHER2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureGather2DArrayShadowF:
			result = "TEXTUREGATHER2DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureGatherCubeShadowF:
			result = "TEXTUREGATHERCUBESHADOWF";
			break;

		case CombinedImageAccess::eTextureGatherCubeArrayShadowF:
			result = "TEXTUREGATHERCUBEARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureGather2DRectShadowF:
			result = "TEXTUREGATHER2DRECTSHADOWF";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DShadowF:
			result = "TEXTUREGATHEROFFSET2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
			result = "TEXTUREGATHEROFFSET2DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureGatherOffset2DRectShadowF:
			result = "TEXTUREGATHEROFFSET2DRECTSHADOWF";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DShadowF:
			result = "TEXTUREGATHEROFFSETS2DSHADOWF";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
			result = "TEXTUREGATHEROFFSETS2DARRAYSHADOWF";
			break;

		case CombinedImageAccess::eTextureGatherOffsets2DRectShadowF:
			result = "TEXTUREGATHEROFFSETS2DRECTSHADOWF";
			break;

		default:
			throw std::runtime_error{ "Unsupported CombinedImageAccess type." };
		}

		return result;
	}
}

#endif
