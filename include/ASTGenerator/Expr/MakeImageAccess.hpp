/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMakeImageAccess_H___
#define ___AST_ExprMakeImageAccess_H___
#pragma once

#include "ExprImageAccessCall.hpp"

namespace ast::expr
{
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DFR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFRgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFRgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFRg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFRg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFRgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFRgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFRg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFRg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFRgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFRgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFRg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFRg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFRgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFRgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFRg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFRg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIR8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRgba8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRg8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIR8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRgba8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRg8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIR8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRgba8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRg8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIR8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRgba8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRg8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DUR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DUR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DUR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DUR8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURgba8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURg8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DUR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DUR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DUR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeUR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeUR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeUR8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURgba8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURg8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayUR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayUR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayUR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectUR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectUR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectUR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayUR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayUR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayUR8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURgba8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURg8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayUR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayUR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayUR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferUR8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURgba32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURgba16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURgba8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURg32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURg16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURg8( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSUR32( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSUR16( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSUR8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURgba32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURgba16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURgba8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURg32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURg16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURg8( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayUR32( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayUR16( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayUR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSUR8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURgba32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURgba16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURgba8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURg32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURg16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURg8( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayUR32( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayUR16( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayUR8( ExprPtr image );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFRgba32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFRgba16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFRg32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFRg16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFR32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFR16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFRgba32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFRgba16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFRg32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFRg16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFR32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFR16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRgba32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRgba16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRgba8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRg32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRg16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRg8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIR32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIR16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIR8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRgba32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRgba16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRgba8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRg32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRg16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRg8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIR32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIR16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIR8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURgba32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURgba16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURgba8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURg32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURg16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURg8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayUR32( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayUR16( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayUR8( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURgba32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURgba16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURgba8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURg32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURg16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURg8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSUR32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSUR16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSUR8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURgba32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURgba16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURgba8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURg32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURg16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURg8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayUR32( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayUR16( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayUR8( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd3DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddBufferUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	 vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd3DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddBufferIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin1DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin3DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinBufferUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin1DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin3DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinBufferIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax1DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax3DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxBufferUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax1DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax3DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxBufferIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd3DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndBufferUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd3DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndBufferIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr1DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr3DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrBufferUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr1DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr3DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrBufferIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor1DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor3DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorBufferUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor1DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor3DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorBufferIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange3DUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeBufferUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayUR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange3DIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeBufferIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayIR32( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DUR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DUR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap3DUR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectUR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeUR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapBufferUR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayUR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayUR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayUR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DIR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DIR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap3DIR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectIR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeIR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapBufferIR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayIR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayIR32( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayIR32( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );}

#endif
