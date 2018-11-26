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
	*@param image
	*	SampledImage<Float, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DFRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DFRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DFRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DFRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DFRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DFRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DFRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DFRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DFRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DFRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DFRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DFRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeFRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeFRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeFRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeFRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DShadowFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DShadowFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DShadowFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DShadowFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeShadowFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeShadowFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayFRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayFRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayFRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayFRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayShadowFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayShadowFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectFRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectFRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectFRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectFRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectFR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectFR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*/
	TextureAccessCallPtr makeTextureSize2DRectShadowFR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*/
	TextureAccessCallPtr makeTextureSize2DRectShadowFR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayFRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayFRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayFRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayFRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayFRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayFRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayFRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayFRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayShadowFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayShadowFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayShadowFR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayShadowFR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DIRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DIRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DIRgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DIRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DIRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DIRg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DIR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DIR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DIR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DIRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DIRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DIRgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DIRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DIRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DIRg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DIR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DIR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DIR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DIRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DIRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DIRgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DIRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DIRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DIRg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DIR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DIR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DIR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeIRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeIRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeIRgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeIRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeIRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeIRg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeIR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeIR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeIR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayIRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayIRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayIRgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayIRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayIRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayIRg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayIR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayIR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayIR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectIRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectIRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectIRgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectIRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectIRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectIRg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectIR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectIR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectIR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayIRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayIRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayIRgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayIRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayIRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayIRg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayIR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayIR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayIR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayIRgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayIRgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayIRgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayIRg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayIRg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayIRg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayIR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayIR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayIR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DURgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DURgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DURgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DURg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DURg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DURg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DUR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DUR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DUR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DURgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DURgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DURgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DURg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DURg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DURg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DUR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DUR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 2D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DUR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DURgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DURgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DURgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DURg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DURg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DURg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DUR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DUR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 3D>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize3DUR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeURgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeURgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeURgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeURg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeURg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeURg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeUR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeUR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Cube>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeUR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayURgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayURgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayURgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayURg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayURg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayURg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayUR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayUR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSizeCubeArrayUR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectURgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectURgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectURgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectURg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectURg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectURg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectUR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectUR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, Rect>
	*/
	TextureAccessCallPtr makeTextureSize2DRectUR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayURgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayURgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayURgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayURg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayURg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayURg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayUR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayUR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize1DArrayUR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayURgba32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayURgba16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayURgba8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayURg32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayURg16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayURg8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayUR32( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayUR16( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	vec3i
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTextureSize2DArrayUR8( ExprPtr image, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Buffer>
	*/
	TextureAccessCallPtr makeTextureSizeBufferUR8( ExprPtr image );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DShadowFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DShadowFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DShadowFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DShadowFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeShadowFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeShadowFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayShadowFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayShadowFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayShadowFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayShadowFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayShadowFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayShadowFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLod3DUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTextureQueryLod1DArrayUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureQueryLod2DArrayUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureQueryLodCubeArrayUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DShadowFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DShadowFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DShadowFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DShadowFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeShadowFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeShadowFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayShadowFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayShadowFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayShadowFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayShadowFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube, Array, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayShadowFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Float, Cube, Array, Shadow>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayShadowFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DUR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DUR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 3D>
	*/
	TextureAccessCallPtr makeTextureQueryLevels3DUR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeUR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels1DArrayUR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevels2DArrayUR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*/
	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayUR8( ExprPtr image );
	// Texel Lookup Functions

	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DFBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DFBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DFBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DFBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DFBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeFBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeFBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayFBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayFBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayFBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayFBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayFBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayFBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DIBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DIBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DIBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DIBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DIBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DIBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DIBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeIBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeIBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeIBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayIBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayIBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayIBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayIBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayIBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayIBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayIBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayIBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayIBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DUBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DUBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DUBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DUBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture3DUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DUBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DUBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture3DUBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureCubeUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeUBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeUBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeUBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture1DArrayUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayUBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayUBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayUBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTexture2DArrayUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayUBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayUBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayUBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureCubeArrayUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayUBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayUBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayUBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTexture2DRectUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DF2Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DF2Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DF2Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DF2Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DF2R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DF2R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF2BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF2BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF2BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF2BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF2BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF2BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DF4Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DF4Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DF4Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DF4Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DF4R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DF4R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF4BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DF4BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DF3Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DF3Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DF3Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DF3Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DF3R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DF3R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF3BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF3BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF3BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF3BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF3BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF3BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DF4Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DF4Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DF4Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DF4Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DF4R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DF4R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF4BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DF4BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DFBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DFBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF3Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF3Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF3Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF3Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF3R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF3R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF4Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF4Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF4Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF4Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF4R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectF4R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DI2Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DI2Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DI2Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DI2Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DI2Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DI2Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DI2R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DI2R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DI2R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI2BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI2BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI2BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI2BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI2BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI2BiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI2BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI2BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI2BiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DI4Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DI4Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DI4Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DI4Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DI4Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DI4Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DI4R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DI4R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DI4R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI4BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI4BiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI4BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI4BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DI4BiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DI3Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DI3Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DI3Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DI3Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DI3Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DI3Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DI3R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DI3R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DI3R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI3BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI3BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI3BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI3BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI3BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI3BiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI3BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI3BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI3BiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DI4Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DI4Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DI4Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DI4Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DI4Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DI4Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DI4R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DI4R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DI4R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI4BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI4BiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI4BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI4BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DI4BiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DIBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DIBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DIBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI3Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI3Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI3Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI3Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI3Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI3Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI3R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI3R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI3R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI4Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI4Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI4Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI4Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI4Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI4Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI4R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI4R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectI4R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DU2Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DU2Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DU2Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DU2Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DU2Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DU2Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DU2R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DU2R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProj1DU2R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU2BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU2BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU2BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU2BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU2BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU2BiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU2BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU2BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU2BiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DU4Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DU4Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DU4Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DU4Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DU4Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DU4Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DU4R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DU4R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj1DU4R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU4BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU4BiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU4BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU4BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DU4BiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DU3Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DU3Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DU3Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DU3Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DU3Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DU3Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DU3R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DU3R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DU3R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU3BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU3BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU3BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU3BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU3BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU3BiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU3BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU3BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU3BiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DU4Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DU4Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DU4Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DU4Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DU4Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DU4Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DU4R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DU4R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DU4R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU4BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU4BiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU4BiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU4BiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DU4BiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj3DUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DUBiasR32( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DUBiasR16( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj3DUBiasR8( ExprPtr image, ExprPtr P, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU3Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU3Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU3Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU3Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU3Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU3Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU3R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU3R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU3R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU4Rgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU4Rgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU4Rgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU4Rg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU4Rg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU4Rg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU4R32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU4R16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureProj2DRectU4R8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod3DUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLodCubeArrayUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DFRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DFRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DFRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DFRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DFR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DFR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DFBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DFBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DFRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DFRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DFRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DFRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DFR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DFR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DFBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DFBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DFRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DFRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DFR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DFR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DFBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DFBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectFRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectFRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectFRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectFRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectFR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectFR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayFBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayFBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DIRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DIRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DIRgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DIRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DIRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DIRg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DIR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DIR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DIR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DIBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DIBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DIBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DIRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DIRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DIRgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DIRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DIRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DIRg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DIR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DIR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DIR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DIBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DIBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DIBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DIRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DIRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DIRg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DIR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DIR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DIR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DIBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DIBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DIBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectIRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectIRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectIRgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectIRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectIRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectIRg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectIR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectIR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayIBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayIBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DURgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DURgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DURgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DURg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DURg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DURg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DUR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DUR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DUR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DUBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DUBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DUBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DURgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DURgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DURgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DURg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DURg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DURg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DUR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DUR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DUR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DUBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DUBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DUBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DURgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DURgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DURgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DURg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DURg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DURg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DUR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DUR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureOffset3DUR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DUBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DUBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset3DUBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectURgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectURgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectURgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectURg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectURg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectURg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectUR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectUR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayUBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayUBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch3DUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetch2DRectUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch1DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*/
	TextureAccessCallPtr makeTexelFetch2DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Buffer>
	*@param P
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchBufferUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DFR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DFR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DFR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DFR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DFR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DFR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectFRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectFRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectFRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectFRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectFR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectFR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DIR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DIR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DIR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DIR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DIR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DIR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DIR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DIR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DIR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectIRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectIRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectIRgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectIRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectIRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectIRg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectIR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectIR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DURg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DURg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DURg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DUR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DUR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	int
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DUR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DURg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DURg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DURg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DUR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DUR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DUR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DURg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DURg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DURg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DUR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DUR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTexelFetchOffset3DUR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectURgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectURgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectURgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectURg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectURg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectURg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectUR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2i
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DRectUR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param lod
	*	int
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTexelFetchOffset1DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param lod
	*	int
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTexelFetchOffset2DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF2BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DF4BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF3BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DF4BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DFBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF3Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF3Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF3Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF3Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF3R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF3R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF4Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF4Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF4R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectF4R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2BiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI2BiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4BiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DI4BiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3BiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI3BiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4BiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DI4BiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIRg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DIBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI3Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI3Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI3Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI3Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI3Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI3Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI3R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI3R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI3R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI4Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI4Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI4Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI4R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI4R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectI4R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2BiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU2BiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4BiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param offset
	*	int
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset1DU4BiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3BiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU3BiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4BiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4BiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4BiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4BiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4BiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4BiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4BiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4BiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset2DU4BiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DURgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DURgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DURgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DURg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DURg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DURg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUBiasRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUBiasRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUBiasRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUBiasRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUBiasRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUBiasRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUBiasR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUBiasR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param offset
	*	vec3i
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProjOffset3DUBiasR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU3Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU3Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU3Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU3Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU3Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU3Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU3R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU3R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU3R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU4Rg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU4Rg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU4Rg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU4R32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU4R16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectU4R8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DFR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DFR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DFR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DFR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DFR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DFR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DIR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DIR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DIR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DIR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DIR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DIR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DIR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DIR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DIR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DURg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DURg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DURg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DUR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DUR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DUR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DURg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DURg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DURg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DUR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DUR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DUR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DURg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DURg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DURg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DUR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DUR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureLodOffset3DUR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureLodOffset1DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureLodOffset2DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF2Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF2Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF2Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF2Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF2R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF2R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF4R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DF4R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF3Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF3Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF3Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF3Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF3R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF3R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF4R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DF4R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DFR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DFR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI2Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI2Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI2Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI2Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI2Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI2Rg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI2R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI2R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI2R8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI4Rg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI4R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI4R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DI4R8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI3Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI3Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI3Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI3Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI3Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI3Rg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI3R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI3R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI3R8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI4Rg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI4R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI4R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DI4R8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DIR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DIR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DIR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU2Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU2Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU2Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU2Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU2Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU2Rg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU2R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU2R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU2R8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU4Rg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU4R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU4R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DU4R8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU3Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU3Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU3Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU3Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU3Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU3Rg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU3R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU3R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU3R8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU4Rg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU4R32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU4R16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DU4R8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DURg32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DURg16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DURg8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DUR32( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DUR16( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod3DUR8( ExprPtr image, ExprPtr P, ExprPtr lod );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF2Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF2Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF2Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF2Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF2R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF2R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF4R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DF4R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF3Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF3Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF3Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF3Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF3R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF3R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF4R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DF4R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DFRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DFRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DFR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DFR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI2Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI2Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI2Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI2Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI2Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI2Rg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI2R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI2R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI2R8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI4Rg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI4R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI4R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DI4R8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI3Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI3Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI3Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI3Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI3Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI3Rg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI3R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI3R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI3R8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI4Rg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI4R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI4R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DI4R8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DIRg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DIRg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DIRg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DIR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DIR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DIR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU2Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU2Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU2Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU2Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU2Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU2Rg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU2R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU2R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU2R8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU4Rg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU4R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU4R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjLodOffset1DU4R8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU3Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU3Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU3Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU3Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU3Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU3Rg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU3R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU3R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU3R8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU4Rg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU4Rg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU4Rg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU4R32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU4R16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset2DU4R8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DURgba32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DURgba16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DURgba8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DURg32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DURg16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DURg8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DUR32( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DUR16( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param lod
	*	float
	*@param offset
	*	vec3i
	*/
	TextureAccessCallPtr makeTextureProjLodOffset3DUR8( ExprPtr image, ExprPtr P, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	float
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGrad3DUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DRectUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D, Array>
	*@param P
	*	vec2f
	*@param dPdx
	*	float
	*@param dPdy
	*	float
	*/
	TextureAccessCallPtr makeTextureGrad1DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param dPdx
	*	vec2f
	*@param dPdy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGrad2DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param dPdx
	*	vec3f
	*@param dPdy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGradCubeArrayUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset3DUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF2Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF2Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF2Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF2Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF2R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF2R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF4Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF4Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF4R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DF4R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF3Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF3Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF3Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF3Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF3R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF3R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF4Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF4Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF4R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DF4R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DFRg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DFRg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DFR32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DFR16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF3Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF3Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF3Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF3Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF3R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF3R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF4Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF4Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF4R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectF4R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI2Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI2Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI2Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI2Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI2Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI2Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI2R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI2R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI2R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI4Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI4Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI4Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI4R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI4R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DI4R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI3Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI3Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI3Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI3Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI3Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI3Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI3R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI3R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI3R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI4Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI4Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI4Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI4R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI4R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DI4R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DIRg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DIRg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DIRg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DIR32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DIR16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DIR8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI3Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI3Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI3Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI3Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI3Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI3Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI3R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI3R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI3R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI4Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI4Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI4Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI4R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI4R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	int
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectI4R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU2Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU2Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU2Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU2Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU2Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU2Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU2R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU2R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec2f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU2R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU4Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU4Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU4Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU4R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU4R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 1D>
	*@param P
	*	vec4f
	*@param pDx
	*	float
	*@param pDy
	*	float
	*/
	TextureAccessCallPtr makeTextureProjGrad1DU4R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU3Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU3Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU3Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU3Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU3Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU3Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU3R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU3R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU3R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU4Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU4Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU4Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU4R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU4R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DU4R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DURgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DURgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DURgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DURg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DURg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DURg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DUR32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DUR16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, 3D>
	*@param P
	*	vec4f
	*@param pDx
	*	vec3f
	*@param pDy
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureProjGrad3DUR8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU3Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU3Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU3Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU3Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU3Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU3Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU3R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU3R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec3f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU3R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU4Rg32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU4Rg16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec2u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU4Rg8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU4R32( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU4R16( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	uint
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec4f
	*@param pDx
	*	vec2f
	*@param pDy
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureProjGrad2DRectU4R8( ExprPtr image, ExprPtr P, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF2Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF2Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF2Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF2Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF2R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF2R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF4Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF4Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF4R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DF4R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF3Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF3Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF3Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF3Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF3R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF3R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF4Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF4Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF4R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DF4R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DFRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DFRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DFRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DFRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DFR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DFR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF3Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF3Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF3Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF3Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF3R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF3R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF4Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF4Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF4Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF4Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF4R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectF4R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI2Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI2Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI2Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI2Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI2Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI2Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI2R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI2R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI2R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI4Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI4Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI4Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI4R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI4R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DI4R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI3Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI3Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI3Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI3Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI3Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI3Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI3R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI3R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI3R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI4Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI4Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI4Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI4R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI4R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DI4R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DIRgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DIRgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DIRgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DIRg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DIRg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DIRg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DIR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DIR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DIR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI3Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI3Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI3Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI3Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI3Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI3Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI3R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI3R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI3R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI4Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI4Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI4Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI4Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI4Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2i
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI4Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI4R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI4R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	int
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectI4R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU2Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU2Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU2Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU2Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU2Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU2Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU2R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU2R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU2R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU4Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU4Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU4Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU4R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU4R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DU4R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU3Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU3Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU3Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU3Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU3Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU3Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU3R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU3R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU3R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU4Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU4Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU4Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU4R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU4R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DU4R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DURgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DURgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DURgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DURg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DURg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DURg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DUR32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DUR16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset3DUR8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU3Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU3Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU3Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU3Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU3Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU3Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU3R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU3R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU3R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU4Rgba32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU4Rgba16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU4Rgba8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU4Rg32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU4Rg16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	vec2u
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU4Rg8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU4R32( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU4R16( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	uint
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectU4R8( ExprPtr image, ExprPtr P, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );	
	// Texel Compare Functions

	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DShadowFBiasR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DShadowFBiasR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DShadowFBiasR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DShadowFBiasR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeShadowFBiasR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeShadowFBiasR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayShadowFBiasR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture1DArrayShadowFBiasR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayShadowFBiasR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTexture2DArrayShadowFBiasR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture2DRectShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTexture2DRectShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param P
	*	vec4f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param P
	*	vec4f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureCubeArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DShadowFBiasR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj1DShadowFBiasR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DShadowFBiasR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param bias
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DShadowFBiasR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DRectShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureProj2DRectShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureLod1DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DRectShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	float
	*@param refZ
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureOffset1DShadowFBiasR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureOffset1DShadowFBiasR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureOffset2DShadowFBiasR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureOffset2DShadowFBiasR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Array, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureOffset1DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureOffset2DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	int
	*/
	TextureAccessCallPtr makeTextureProjOffset1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjOffset1DShadowFBiasR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjOffset1DShadowFBiasR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjOffset2DShadowFBiasR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjOffset2DShadowFBiasR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset, ExprPtr bias );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureProjOffset2DRectShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureLodOffset1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureLodOffset1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureLodOffset2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureLodOffset2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureLodOffset1DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureLodOffset1DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 1D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param lod
	*	float
	*/
	TextureAccessCallPtr makeTextureProjLod2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjLodOffset1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjLodOffset1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjLodOffset2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjLodOffset2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr lod, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGrad2DRectShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGrad2DRectShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGrad1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGrad1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGrad2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGrad2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGrad1DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGrad1DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DRectShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset1DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureGradOffset2DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGrad1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGrad1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGrad2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGrad2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGrad2DRectShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGrad2DRectShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr pDx, ExprPtr pDy );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset1DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	/**
	*@return
	*	float
	*@param image
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
	TextureAccessCallPtr makeTextureProjGradOffset2DRectShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr dPdx, ExprPtr dPdy, ExprPtr offset );
	// Texture Gather Functions

	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DFCompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DFCompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DFCompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DFCompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DFCompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DFCompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFCompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFCompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFCompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFCompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFCompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayFCompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeFCompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeFCompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeFCompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeFCompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeFCompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeFCompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFCompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFCompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFCompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFCompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFCompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayFCompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectFCompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectFCompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectFCompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectFCompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectFCompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectFCompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DICompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DICompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DICompRgba8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DICompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DICompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DICompRg8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DICompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DICompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DICompR8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayICompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayICompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayICompRgba8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayICompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayICompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayICompRg8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayICompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayICompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayICompR8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeICompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeICompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeICompRgba8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeICompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeICompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeICompRg8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeICompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeICompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeICompR8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayICompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayICompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayICompRgba8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayICompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayICompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayICompRg8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayICompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayICompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayICompR8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectICompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectICompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectICompRgba8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectICompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectICompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectICompRg8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectICompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectICompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectICompR8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DUCompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DUCompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DUCompRgba8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DUCompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DUCompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DUCompRg8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DUCompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DUCompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DUCompR8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUCompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUCompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUCompRgba8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUCompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUCompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUCompRg8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUCompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUCompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DArrayUCompR8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*/
	TextureAccessCallPtr makeTextureGatherCubeUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeUCompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeUCompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeUCompRgba8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeUCompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeUCompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeUCompRg8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeUCompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeUCompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube>
	*@param P
	*	vec3f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeUCompR8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUCompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUCompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUCompRgba8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUCompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUCompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUCompRg8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUCompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUCompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Cube, Array>
	*@param P
	*	vec4f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayUCompR8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*/
	TextureAccessCallPtr makeTextureGather2DRectUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectUCompRgba32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectUCompRgba16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectUCompRgba8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectUCompRg32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectUCompRg16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectUCompRg8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectUCompR32( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectUCompR16( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGather2DRectUCompR8( ExprPtr image, ExprPtr P, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFCompRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFCompRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFCompR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DFCompR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFCompRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFCompRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFCompR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayFCompR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFCompRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFCompRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFCompR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectFCompR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DIRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DIRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DIRgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DIRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DIRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DIRg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DIR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DIR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DIR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DICompRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DICompRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DICompRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DICompRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DICompRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DICompRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DICompR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DICompR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DICompR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayICompRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayICompRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayICompRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayICompRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayICompRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayICompRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayICompR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayICompR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayICompR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectIRgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectIRgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectIRgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectIRg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectIRg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectIRg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectIR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectIR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectICompRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectICompRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectICompRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectICompRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectICompRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectICompRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectICompR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectICompR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectICompR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DURgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DURgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DURgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DURg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DURg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DURg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUCompRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUCompRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUCompRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUCompRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUCompR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUCompR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DUCompR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUCompRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUCompRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUCompRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUCompRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUCompR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUCompR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayUCompR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectURgba32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectURgba16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectURgba8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectURg32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectURg16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectURg8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUR16( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUR8( ExprPtr image, ExprPtr P, ExprPtr offset );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUCompRgba8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUCompRg32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUCompRg16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUCompRg8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUCompR32( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUCompR16( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offset
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectUCompR8( ExprPtr image, ExprPtr P, ExprPtr offset, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFRg32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFRg16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFR32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFR16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFCompRg32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFCompRg16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFCompR32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DFCompR16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFR32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFR16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFCompRg32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFCompRg16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFCompR32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFCompR16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFRg32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFRg16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFR32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFR16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFCompRg32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFCompRg16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFCompR32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectFCompR16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DIRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DIRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DIRgba8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DIRg32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DIRg16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DIRg8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DIR32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DIR16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DIR8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DICompRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DICompRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DICompRgba8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DICompRg32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DICompRg16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DICompRg8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DICompR32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DICompR16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DICompR8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayIR16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayIR8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayICompRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayICompRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayICompRgba8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayICompRg32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayICompRg16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayICompRg8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayICompR32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayICompR16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayICompR8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectIRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectIRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectIRgba8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectIRg32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectIRg16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectIRg8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectIR16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectIR8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectICompRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectICompRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectICompRgba8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectICompRg32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectICompRg16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectICompRg8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectICompR32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectICompR16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4i
	*@param image
	*	SampledImage<Int, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectICompR8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DURgba32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DURgba16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DURgba8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DURg32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DURg16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DURg8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUR32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUR16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUR8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUCompRgba8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUCompRg32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUCompRg16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUCompRg8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUCompR32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUCompR16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DUCompR8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayURg32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayURg16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayURg8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUR16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUR8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUCompRgba8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUCompRg32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUCompRg16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUCompRg8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUCompR32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUCompR16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, 2D, Array>
	*@param P
	*	vec3f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUCompR8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectURgba32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectURgba16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectURgba8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectURg32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectURg16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectURg8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUR16( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUR8( ExprPtr image, ExprPtr P, ExprPtr offsets );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUCompRgba32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUCompRgba16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUCompRgba8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUCompRg32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUCompRg16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUCompRg8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUCompR32( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUCompR16( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	/**
	*@return
	*	vec4u
	*@param image
	*	SampledImage<UInt, Rect>
	*@param P
	*	vec2f
	*@param offsets
	*	vec2i
	*@param comp
	*	int
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectUCompR8( ExprPtr image, ExprPtr P, ExprPtr offsets, ExprPtr comp );
	// Texture Gather Compare Functions

	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGather2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGather2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGather2DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGather2DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGatherCubeShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGatherCubeShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param P
	*	vec4f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Cube, Array, Shadow>
	*@param P
	*	vec4f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGatherCubeArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGather2DRectShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*/
	TextureAccessCallPtr makeTextureGather2DRectShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offset
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffset2DRectShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, 2D, Array, Shadow>
	*@param P
	*	vec3f
	*@param refZ
	*	float
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DArrayShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectShadowFR32( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offsets );
	/**
	*@return
	*	vec4f
	*@param image
	*	SampledImage<Float, Rect, Shadow>
	*@param P
	*	vec2f
	*@param refZ
	*	float
	*@param offsets
	*	vec2i
	*/
	TextureAccessCallPtr makeTextureGatherOffsets2DRectShadowFR16( ExprPtr image, ExprPtr P, ExprPtr refZ, ExprPtr offsets );}

#endif
