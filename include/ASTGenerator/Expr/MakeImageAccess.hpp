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
	ImageAccessCallPtr makeImageSize1DF( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DF( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DF( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeF( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayF( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectF( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayF( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayF( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferF( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSF( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayF( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DI( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DI( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DI( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeI( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayI( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectI( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayI( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayI( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferI( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSI( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayI( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	ImageAccessCallPtr makeImageSize1DU( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	ImageAccessCallPtr makeImageSize2DU( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	ImageAccessCallPtr makeImageSize3DU( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	ImageAccessCallPtr makeImageSizeCubeU( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	ImageAccessCallPtr makeImageSizeCubeArrayU( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	ImageAccessCallPtr makeImageSize2DRectU( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	ImageAccessCallPtr makeImageSize1DArrayU( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	ImageAccessCallPtr makeImageSize2DArrayU( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	ImageAccessCallPtr makeImageSizeBufferU( ExprPtr image );
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSize2DMSU( ExprPtr image );
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSize2DMSArrayU( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSF( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayF( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSI( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayI( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	ImageAccessCallPtr makeImageSamples2DMSU( ExprPtr image );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	ImageAccessCallPtr makeImageSamples2DMSArrayU( ExprPtr image );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DF( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DF( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DF( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectF( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeF( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferF( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayF( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayF( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayF( ExprPtr image, ExprPtr P );
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
	ImageAccessCallPtr makeImageLoad2DMSF( ExprPtr image, ExprPtr P, ExprPtr sample );
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
	ImageAccessCallPtr makeImageLoad2DMSArrayF( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DI( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DI( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DI( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectI( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeI( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferI( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayI( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayI( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayI( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSI( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayI( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoad1DU( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DU( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad3DU( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad2DRectU( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeU( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*/
	ImageAccessCallPtr makeImageLoadBufferU( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*/
	ImageAccessCallPtr makeImageLoad1DArrayU( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoad2DArrayU( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*/
	ImageAccessCallPtr makeImageLoadCubeArrayU( ExprPtr image, ExprPtr P );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSU( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*/
	ImageAccessCallPtr makeImageLoad2DMSArrayU( ExprPtr image, ExprPtr P, ExprPtr sample );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd3DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DRectFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddBufferFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd3DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DRectIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddBufferIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	 vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd1DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd3DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DRectUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddCubeUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddBufferUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd1DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddCubeArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DMSUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd3DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DRectFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddBufferFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd1DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd3DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DRectII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddCubeII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddBufferII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd1DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddCubeArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DMSII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd3DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DRectUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddBufferUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAddCubeArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin1DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin3DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DRectFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinBufferFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin1DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin1DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin3DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DRectIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinBufferIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin1DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin1DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin3DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DRectUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinCubeUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinBufferUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin1DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinCubeArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DMSUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin1DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin3DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DRectFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinBufferFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin1DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin1DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin3DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DRectII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinCubeII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinBufferII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin1DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinCubeArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DMSII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin1DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin3DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DRectUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinBufferUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin1DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMinCubeArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax1DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax3DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DRectFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxBufferFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax1DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax1DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax3DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DRectIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxBufferIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax1DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax1DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax3DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DRectUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxCubeUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxBufferUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax1DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DMSUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax1DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax3DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DRectFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxBufferFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax1DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax1DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax3DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DRectII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxCubeII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxBufferII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax1DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DMSII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax1DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax3DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DRectUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxBufferUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax1DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd3DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DRectFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndBufferFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd3DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DRectIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndBufferIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd1DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd3DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DRectUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndCubeUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndBufferUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd1DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndCubeArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DMSUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd3DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DRectFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndBufferFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd1DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd3DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DRectII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndCubeII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndBufferII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd1DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndCubeArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DMSII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd3DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DRectUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndBufferUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd1DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAndCubeArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr1DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr3DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DRectFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrBufferFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr1DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr1DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr3DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DRectIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrBufferIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr1DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr1DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr3DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DRectUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrCubeUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrBufferUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr1DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrCubeArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DMSUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr1DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr3DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DRectFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrBufferFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr1DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr1DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr3DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DRectII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrCubeII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrBufferII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr1DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrCubeArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DMSII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr1DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr3DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DRectUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrBufferUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr1DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOrCubeArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor1DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor3DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DRectFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorBufferFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor1DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor1DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor3DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DRectIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorBufferIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor1DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor1DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor3DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DRectUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorCubeUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorBufferUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor1DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorCubeArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DMSUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor1DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor3DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DRectFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorBufferFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor1DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor1DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor3DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DRectII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorCubeII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorBufferII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor1DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorCubeArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DMSII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor1DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor3DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DRectUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorBufferUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor1DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXorCubeArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange3DFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DRectFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeBufferFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayFU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange3DIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DRectIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeBufferIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayIU( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange1DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange3DUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DRectUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeCubeUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeBufferUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange1DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayUU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DMSUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange3DFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DRectFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeBufferFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayFI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange1DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange3DII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DRectII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeCubeII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeBufferII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange1DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayII( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DMSII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange3DUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DRectUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeBufferUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange1DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayUI( ExprPtr image, ExprPtr P, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DFU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DFU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap3DFU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectFU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeFU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapBufferFU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayFU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayFU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayFU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayFU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D>
	*@param P
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DIU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D>
	*@param P
	*	vec2i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DIU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 3D>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap3DIU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Rect>
	*@param P
	*	vec2i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectIU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeIU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Buffer>
	*@param P
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapBufferIU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 1D, Array>
	*@param P
	*	vec2i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayIU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, Array>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayIU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, Cube, Array>
	*@param P
	*	vec3i
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayIU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	uint
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param compare
	*	uint
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayIU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap1DUU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DUU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap3DUU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectUU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapCubeUU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapBufferUU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayUU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayUU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayUU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayUU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*@param P
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DFI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D>
	*@param P
	*	vec2i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DFI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 3D>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap3DFI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Rect>
	*@param P
	*	vec2i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectFI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeFI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*@param P
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapBufferFI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D, Array>
	*@param P
	*	vec2i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayFI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, Array>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayFI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Cube, Array>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayFI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayFI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap1DII( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DII( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap3DII( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectII( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapCubeII( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapBufferII( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayII( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayII( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayII( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayII( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DUI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D>
	*@param P
	*	vec2i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DUI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 3D>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap3DUI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Rect>
	*@param P
	*	vec2i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectUI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeUI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*@param P
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapBufferUI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D, Array>
	*@param P
	*	vec2i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayUI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, Array>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayUI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Cube, Array>
	*@param P
	*	vec3i
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayUI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*@param P
	*	vec2i
	*@param sample
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param P
	*	vec3i
	*@param sample
	*	int
	*@param compare
	*	int
	*@param data
	*	int
	*/
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayUI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );}

#endif
