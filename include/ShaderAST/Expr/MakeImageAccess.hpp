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
	ImageAccessCallPtr makeImageSize1DFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayFR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIRg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayIR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURgba32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURgba16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURgba8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURg32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURg16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayURg8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayUR32( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayUR16( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayUR8( type::TypesCache & cache, ExprPtr image );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DFR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DFR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DFR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectFR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeFR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferFR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayFR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayFR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayFR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSFR16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayFR16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIRg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DIR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIRg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DIR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIRg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DIR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIRg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectIR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIRg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeIR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIRg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferIR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIRg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayIR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIRg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayIR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIRg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayIR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIRg8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIR16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSIR8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRg32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRg16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIRg8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIR16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayIR8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DURg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DUR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DUR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DURg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DUR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DUR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DURg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DUR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DUR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectURg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectUR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectUR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeURg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeUR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeUR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferURg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferUR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferUR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayURg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayUR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayUR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayURg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayUR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayUR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURg32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURg16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayURg8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayUR16( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayUR8( type::TypesCache & cache, ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURg32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURg16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSURg8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSUR16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSUR8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURgba32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURgba16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURgba8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURg32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURg16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayURg8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayUR16( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayUR8( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd3DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DRectUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddBufferUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	 vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd3DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DRectIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddBufferIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin1DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin3DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DRectUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinBufferUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin1DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin1DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin3DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DRectIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinBufferIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin1DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax1DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax3DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DRectUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxBufferUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax1DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax1DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax3DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DRectIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxBufferIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax1DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd3DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DRectUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndBufferUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd3DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DRectIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndBufferIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr1DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr3DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DRectUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrBufferUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr1DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr1DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr3DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DRectIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrBufferIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr1DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor1DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor3DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DRectUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorBufferUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor1DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor1DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor3DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DRectIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorBufferIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor1DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange3DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DRectUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeBufferUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange3DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DRectIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeBufferIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap3DUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapBufferUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayUR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap3DIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapBufferIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayIR32( type::TypesCache & cache, ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );}

#endif
