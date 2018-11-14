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
	*	Image<UInt, 1D>
	*@param P
	*	int
	*@param data
	*	uint
	*/
	ImageAccessCallPtr makeImageAtomicAdd1DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd3DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DRectU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddCubeU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddBufferU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd1DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddCubeArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DMSU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd1DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd3DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DRectI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddCubeI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddBufferI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd1DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAddCubeArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DMSI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin1DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin3DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DRectU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinCubeU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinBufferU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin1DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinCubeArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DMSU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin1DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin3DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DRectI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinCubeI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinBufferI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin1DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMinCubeArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DMSI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMin2DMSArrayI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax1DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax3DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DRectU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxCubeU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxBufferU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax1DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DMSU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax1DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax3DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DRectI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxCubeI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxBufferI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax1DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMaxCubeArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DMSI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicMax2DMSArrayI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd1DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd3DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DRectU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndCubeU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndBufferU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd1DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndCubeArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DMSU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd1DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd3DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DRectI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndCubeI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndBufferI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd1DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAndCubeArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DMSI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr1DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr3DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DRectU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrCubeU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrBufferU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr1DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrCubeArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DMSU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr1DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr3DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DRectI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrCubeI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrBufferI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr1DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOrCubeArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DMSI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicOr2DMSArrayI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor1DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor3DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DRectU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorCubeU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorBufferU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor1DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorCubeArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DMSU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor1DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor3DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DRectI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorCubeI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorBufferI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor1DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXorCubeArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DMSI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicXor2DMSArrayI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange1DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange3DU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DRectU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeCubeU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeBufferU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange1DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayU( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DMSU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange1DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange3DI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DRectI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeCubeI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeBufferI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange1DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayI( ExprPtr image, ExprPtr P, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DMSI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap1DU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap3DU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapCubeU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapBufferU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayU( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayU( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap1DI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap3DI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DRectI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapCubeI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapBufferI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayI( ExprPtr image, ExprPtr P, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );
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
	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayI( ExprPtr image, ExprPtr P, ExprPtr sample, ExprPtr compare, ExprPtr data );}

#endif
