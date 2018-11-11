/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMakeTextureAccess_H___
#define ___AST_ExprMakeTextureAccess_H___
#pragma once

#include "ExprTextureAccessCall.hpp"

namespace ast::expr
{	// Texture Query Functions

	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Float, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param texture
	*	SampledImage<Float, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Float, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DShadowF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DShadowF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Float, Cube, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeShadowF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param texture
	*	SampledImage<Float, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param texture
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayShadowF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Float, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectF( ExprPtr texture );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*/
	TextureAccessCallPtr makeTextureSize2DRectShadowF( ExprPtr texture );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayShadowF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param texture
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayShadowF( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Int, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DI( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Int, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DI( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param texture
	*	SampledImage<Int, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DI( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Int, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeI( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param texture
	*	SampledImage<Int, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayI( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Int, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectI( ExprPtr texture );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayI( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayI( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Int, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferI( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DU( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DU( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DU( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<UInt, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeU( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param texture
	*	SampledImage<UInt, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayU( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<UInt, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectU( ExprPtr texture );
	/**
	*@return
	*	vec2i
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayU( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayU( ExprPtr texture, ExprPtr lod );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<UInt, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferU( ExprPtr texture );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DShadowF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DShadowF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeShadowF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayShadowF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayShadowF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayShadowF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param texture
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DShadowF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DShadowF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, Cube, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeShadowF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, 1D, Array, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayShadowF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, 2D, Array, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayShadowF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Float, Cube, Array, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayShadowF( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Int, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DI( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Int, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DI( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Int, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DI( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Int, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeI( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayI( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayI( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<Int, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayI( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<UInt, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DU( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<UInt, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DU( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<UInt, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DU( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<UInt, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeU( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayU( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayU( ExprPtr texture );
	/**
	*@return
	*	int
	*@param texture
	*	SampledImage<UInt, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayU( ExprPtr texture );
	// Texel Lookup Functions

	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DFBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DFBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeFBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayFBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayFBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayFBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DIBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DIBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeIBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayIBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayIBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayIBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DUBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DUBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeUBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayUBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayUBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayUBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DF2( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF2Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DF4( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF4Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DF3( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF3Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DF4( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF4Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DFBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF3( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF4( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DI2( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI2Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DI4( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI4Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DI3( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI3Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DI4( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI4Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DIBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI3( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI4( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DU2( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU2Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DU4( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU4Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DU3( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU3Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DU4( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU4Bias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DUBias( ExprPtr texture, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU3( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU4( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DF( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DFBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DF( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DFBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DF( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DFBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectF( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayF( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayF( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DI( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DIBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DI( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DIBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DI( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DIBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectI( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayI( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayI( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DU( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DUBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DU( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DUBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DU( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DUBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectU( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayU( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayU( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DF( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DF( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DF( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectF( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayF( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayF( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DI( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DI( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DI( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectI( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayI( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayI( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DU( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DU( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DU( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectU( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayU( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayU( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DF( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF3( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF4( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DI( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI3( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI4( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4Bias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DU( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUBias( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU3( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU4( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DF( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DF( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DF( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayF( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayF( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DI( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DI( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DI( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayI( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayI( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DU( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DU( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DU( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayU( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayU( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF2( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF4( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF3( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF4( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DF( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI2( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI4( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI3( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI4( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DI( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU2( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU4( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU3( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU4( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DU( ExprPtr texture, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF2( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF4( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF3( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF4( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DF( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI2( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI4( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI3( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI4( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DI( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU2( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU4( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU3( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU4( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DU( ExprPtr texture, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureGradOffset1DF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureGradOffset3DF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DRectF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureGradOffset1DArrayF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DArrayF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureGradOffset1DI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureGradOffset3DI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DRectI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureGradOffset1DArrayI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DArrayI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureGradOffset1DU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureGradOffset3DU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DRectU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureGradOffset1DArrayU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DArrayU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF2( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF4( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF3( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF4( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DF( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF3( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF4( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI2( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI4( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI3( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI4( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DI( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI3( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI4( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU2( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU4( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU3( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU4( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DU( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU3( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU4( ExprPtr texture, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjGradOffset1DF2( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjGradOffset1DF4( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DF3( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DF4( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset3DF( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF3( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF4( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjGradOffset1DI2( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjGradOffset1DI4( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DI3( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DI4( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset3DI( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI3( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI4( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjGradOffset1DU2( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjGradOffset1DU4( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DU3( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DU4( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset3DU( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU3( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU4( ExprPtr texture, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );	
	// Texel Compare Functions

	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DShadowFBias( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DShadowFBias( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeShadowFBias( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayShadowFBias( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayShadowFBias( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture2DRectShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param P
	*	vec4f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DShadowFBias( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DShadowFBias( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DRectShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DShadowFBias( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DShadowFBias( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DShadowFBias( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DShadowFBias( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DRectShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureGradOffset1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureGradOffset1DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGradOffset2DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjGradOffset1DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjGradOffset2DRectShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	// Texture Gather Functions

	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DFComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeFComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DRectF( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectFComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DIComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayIComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeIComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayIComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DRectI( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectIComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DUComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeUComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DRectU( ExprPtr texture, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectUComp( ExprPtr texture, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DF( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFComp( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayF( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFComp( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectF( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFComp( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DI( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DIComp( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayI( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayIComp( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectI( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectIComp( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DU( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUComp( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayU( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUComp( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectU( ExprPtr texture, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUComp( ExprPtr texture, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DF( ExprPtr texture, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFComp( ExprPtr texture, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayF( ExprPtr texture, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFComp( ExprPtr texture, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectF( ExprPtr texture, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFComp( ExprPtr texture, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DI( ExprPtr texture, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DIComp( ExprPtr texture, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayI( ExprPtr texture, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayIComp( ExprPtr texture, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectI( ExprPtr texture, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param texture
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectIComp( ExprPtr texture, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DU( ExprPtr texture, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUComp( ExprPtr texture, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayU( ExprPtr texture, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUComp( ExprPtr texture, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectU( ExprPtr texture, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param texture
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUComp( ExprPtr texture, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	// Texture Gather Compare Functions

	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGather2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGather2DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGatherCubeShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param P
	*	vec4f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGather2DRectShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param texture
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectShadowF( ExprPtr texture, ExprPtr P, ExprPtr refZ, ExprPtr offsets );}

#endif
