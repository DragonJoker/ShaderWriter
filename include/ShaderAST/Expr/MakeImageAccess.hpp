/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#ifndef ___AST_ExprMakeImageAccess_H___
#define ___AST_ExprMakeImageAccess_H___
#pragma once

#include "ExprImageAccessCall.hpp"

#include <cassert>

namespace ast::expr
{	// Image Query Functions

	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 1D>
	*/
	inline ImageAccessCallPtr makeImageSize1DUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D>
	*/
	inline ImageAccessCallPtr makeImageSize2DUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 3D>
	*/
	inline ImageAccessCallPtr makeImageSize3DUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Cube>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, Cube, Array>
	*/
	inline ImageAccessCallPtr makeImageSizeCubeArrayUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, Rect>
	*/
	inline ImageAccessCallPtr makeImageSize2DRectUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 1D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize1DArrayUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DArrayUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, Buffer>
	*/
	inline ImageAccessCallPtr makeImageSizeBufferUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSize2DMSArrayUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayFRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayFRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayFRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayFRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayFR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Float, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayFR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayIRgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayIRgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayIRgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayIRg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayIRg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayIRg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayIR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayIR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayURgba32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayURgba16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayURgba8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayURg32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayURg16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayURg8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayUR16( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*/
	inline ImageAccessCallPtr makeImageSamples2DMSArrayUR8( type::TypesCache & cache
		, ExprPtr image )
	{
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	// Image texel load

	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2F )
			, ImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eHalf )
			, ImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2F )
			, ImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eHalf )
			, ImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2F )
			, ImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eHalf )
			, ImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DRectF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageLoad2DRectF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2F )
			, ImageAccess::eImageLoad2DRectF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageLoad2DRectF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageLoad2DRectF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eHalf )
			, ImageAccess::eImageLoad2DRectF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2F )
			, ImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eHalf )
			, ImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2F )
			, ImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eHalf )
			, ImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2F )
			, ImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eHalf )
			, ImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2F )
			, ImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eHalf )
			, ImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2F )
			, ImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eHalf )
			, ImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad2DMSFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2F )
			, ImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad2DMSFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad2DMSFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eHalf )
			, ImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad2DMSArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2F )
			, ImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad2DMSArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad2DMSArrayFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eHalf )
			, ImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DRectI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DRectI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DRectI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DRectI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DRectI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DRectI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DRectI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DRectI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DRectI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4I )
			, ImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2I )
			, ImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoad1DUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad3DUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DRectU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DRectU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DRectU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DRectU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DRectU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DRectU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DRectU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DRectU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad2DRectUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DRectU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline ImageAccessCallPtr makeImageLoadBufferUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageLoad1DArrayUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoad2DArrayUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline ImageAccessCallPtr makeImageLoadCubeArrayUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4U )
			, ImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2U )
			, ImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
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
	inline ImageAccessCallPtr makeImageLoad2DMSArrayUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	// Image texel store

	/**
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4f
	*/
	inline ImageAccessCallPtr makeImageStore1DFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageStore1DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2f
	*/
	inline ImageAccessCallPtr makeImageStore1DFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageStore1DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageStore1DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	half
	*/
	inline ImageAccessCallPtr makeImageStore1DFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eHalf );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4f
	*/
	inline ImageAccessCallPtr makeImageStore2DFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageStore2DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2f
	*/
	inline ImageAccessCallPtr makeImageStore2DFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageStore2DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageStore2DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	half
	*/
	inline ImageAccessCallPtr makeImageStore2DFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eHalf );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4f
	*/
	inline ImageAccessCallPtr makeImageStore3DFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageStore3DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2f
	*/
	inline ImageAccessCallPtr makeImageStore3DFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageStore3DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageStore3DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	half
	*/
	inline ImageAccessCallPtr makeImageStore3DFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eHalf );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4f
	*/
	inline ImageAccessCallPtr makeImageStore2DRectFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageStore2DRectFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2f
	*/
	inline ImageAccessCallPtr makeImageStore2DRectFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageStore2DRectFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageStore2DRectFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	half
	*/
	inline ImageAccessCallPtr makeImageStore2DRectFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eHalf );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4f
	*/
	inline ImageAccessCallPtr makeImageStoreCubeFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageStoreCubeFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2f
	*/
	inline ImageAccessCallPtr makeImageStoreCubeFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageStoreCubeFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageStoreCubeFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	half
	*/
	inline ImageAccessCallPtr makeImageStoreCubeFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eHalf );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4f
	*/
	inline ImageAccessCallPtr makeImageStoreBufferFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageStoreBufferFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2f
	*/
	inline ImageAccessCallPtr makeImageStoreBufferFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageStoreBufferFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageStoreBufferFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	half
	*/
	inline ImageAccessCallPtr makeImageStoreBufferFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eHalf );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4f
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2f
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	half
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eHalf );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4f
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2f
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	half
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eHalf );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4f
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2f
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	half
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eHalf );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4f
	*/
	inline ImageAccessCallPtr makeImageStore2DMSFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageStore2DMSFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2f
	*/
	inline ImageAccessCallPtr makeImageStore2DMSFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageStore2DMSFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageStore2DMSFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	half
	*/
	inline ImageAccessCallPtr makeImageStore2DMSFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eHalf );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4f
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayFRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2f
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayFRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2F );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	half
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayFR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eHalf );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore1DIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore1DIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore1DIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore1DIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore1DIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore1DIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore1DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore1DIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore1DIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore3DIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore3DIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore3DIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore3DIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore3DIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore3DIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore3DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore3DIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore3DIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DRectIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DRectIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DRectIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DRectIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DRectIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DRectIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DRectIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DRectIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DRectIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStoreCubeIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStoreCubeIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStoreCubeIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStoreBufferIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStoreBufferIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStoreBufferIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStoreBufferIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStoreBufferIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStoreBufferIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStoreBufferIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStoreBufferIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStoreBufferIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DMSIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DMSIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DMSIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayIRgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayIRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayIRgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayIRg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayIRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayIRg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2I );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayIR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayIR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore1DURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore1DURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore1DURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore1DURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore1DURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore1DURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore1DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore1DUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore1DUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore3DURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore3DURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore3DURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore3DURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore3DURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore3DURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore3DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore3DUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore3DUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DRectURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DRectURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DRectURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DRectURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DRectURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DRectURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DRectUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DRectUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DRectUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStoreCubeUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStoreCubeUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStoreCubeUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStoreBufferURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStoreBufferURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStoreBufferURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStoreBufferURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStoreBufferURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStoreBufferURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStoreBufferUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStoreBufferUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStoreBufferUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore1DArrayUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DArrayUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStoreCubeArrayUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DMSUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DMSUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DMSUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayURgba32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayURgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayURgba8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayURg32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayURg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayURg8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2U );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayUR16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	Image<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline ImageAccessCallPtr makeImageStore2DMSArrayUR8( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVoid )
			, ImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	// Image atomics

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
	inline ImageAccessCallPtr makeImageAtomicAdd1DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd2DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd3DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd2DRectUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAddCubeUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAddBufferUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd1DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd2DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() ==  type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAddCubeArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd2DMSUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd1DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd2DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd3DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd2DRectIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAddCubeIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAddBufferIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd1DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd2DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAddCubeArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd2DMSIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAdd2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd1DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicAdd1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd1DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicAdd1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd1DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicAdd1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicAdd2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicAdd2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicAdd2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd3DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicAdd3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd3DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicAdd3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd3DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicAdd3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DRectFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicAdd2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DRectFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicAdd2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DRectFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicAdd2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicAddCubeFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicAddCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicAddCubeFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicAddCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicAddCubeFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicAddCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicAddBufferFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicAddBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicAddBufferFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicAddBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicAddBufferFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicAddBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd1DArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicAdd1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd1DArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicAdd1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd1DArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicAdd1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	 vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() ==  type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicAdd2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	 vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() ==  type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicAdd2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	 vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() ==  type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicAdd2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicAddCubeArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicAddCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicAddCubeArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicAddCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicAddCubeArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicAddCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DMSFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicAdd2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DMSFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicAdd2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DMSFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicAdd2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DMSArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicAdd2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DMSArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicAdd2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicAdd2DMSArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicAdd2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin1DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin2DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin3DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin2DRectUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMinCubeUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMinBufferUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin1DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin2DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMinCubeArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin2DMSUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin1DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin2DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin3DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin2DRectIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMinCubeIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMinBufferIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin1DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin2DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMinCubeArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin2DMSIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMin2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax1DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax2DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax3DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax2DRectUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMaxCubeUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMaxBufferUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax1DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax2DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMaxCubeArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax2DMSUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax1DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax2DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax3DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax2DRectIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMaxCubeIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMaxBufferIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax1DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax2DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMaxCubeArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax2DMSIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicMax2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd1DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd2DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd3DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd2DRectUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAndCubeUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAndBufferUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd1DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd2DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAndCubeArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd2DMSUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd1DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd2DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd3DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd2DRectIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAndCubeIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAndBufferIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd1DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd2DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAndCubeArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd2DMSIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicAnd2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr1DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr2DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr3DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr2DRectUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOrCubeUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOrBufferUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr1DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr2DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOrCubeArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr2DMSUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr1DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr2DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr3DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr2DRectIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOrCubeIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOrBufferIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr1DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr2DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOrCubeArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr2DMSIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicOr2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor1DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor2DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor3DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor2DRectUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXorCubeUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXorBufferUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor1DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor2DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXorCubeArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor2DMSUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor1DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor2DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor3DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor2DRectIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXorCubeIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXorBufferIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor1DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor2DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXorCubeArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor2DMSIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicXor2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange1DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange2DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange3DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange2DRectUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchangeCubeUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchangeBufferUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange1DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange2DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchangeCubeArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange2DMSUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange1DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange2DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange3DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange2DRectIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchangeCubeIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchangeBufferIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange1DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange2DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchangeCubeArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange2DMSIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicExchange2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange1DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicExchange1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange1DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicExchange1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange1DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicExchange1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicExchange2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicExchange2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicExchange2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange3DFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicExchange3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange3DFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicExchange3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange3DFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicExchange3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DRectFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicExchange2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DRectFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicExchange2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Rect>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DRectFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicExchange2DRectF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchangeCubeFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicExchangeCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchangeCubeFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicExchangeCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicExchangeCubeFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicExchangeCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchangeBufferFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicExchangeBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchangeBufferFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicExchangeBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicExchangeBufferFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicExchangeBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange1DArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicExchange1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange1DArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicExchange1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange1DArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicExchange1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicExchange2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicExchange2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicExchange2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchangeCubeArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicExchangeCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchangeCubeArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicExchangeCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicExchangeCubeArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicExchangeCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DMSFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicExchange2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DMSFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicExchange2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DMSFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicExchange2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DMSArrayFRgba16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec4H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec4H )
			, ImageAccess::eImageAtomicExchange2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DMSArrayFRg16( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eVec2H );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eVec2H )
			, ImageAccess::eImageAtomicExchange2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	Image<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	float
	*/
	inline ImageAccessCallPtr makeImageAtomicExchange2DMSArrayFR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eFloat );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eFloat )
			, ImageAccess::eImageAtomicExchange2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap1DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( compare->getType()->getKind() == type::Kind::eUInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap2DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( compare->getType()->getKind() == type::Kind::eUInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap3DUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( compare->getType()->getKind() == type::Kind::eUInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap3DU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap2DRectUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( compare->getType()->getKind() == type::Kind::eUInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwapCubeUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( compare->getType()->getKind() == type::Kind::eUInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwapBufferUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( compare->getType()->getKind() == type::Kind::eUInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapBufferU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap1DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( compare->getType()->getKind() == type::Kind::eUInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap2DArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( compare->getType()->getKind() == type::Kind::eUInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( compare->getType()->getKind() == type::Kind::eUInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap2DMSUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( compare->getType()->getKind() == type::Kind::eUInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayUR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( compare->getType()->getKind() == type::Kind::eUInt );
		assert( data->getType()->getKind() == type::Kind::eUInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap1DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( compare->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap2DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( compare->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap3DIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( compare->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap3DI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap2DRectIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( compare->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwapCubeIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( compare->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwapBufferIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eInt );
		assert( compare->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapBufferI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap1DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( compare->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap2DArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( compare->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( compare->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap2DMSIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec2I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( compare->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}
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
	inline ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayIR32( type::TypesCache & cache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getKind() == type::Kind::eVec3I );
		assert( sample->getType()->getKind() == type::Kind::eInt );
		assert( compare->getType()->getKind() == type::Kind::eInt );
		assert( data->getType()->getKind() == type::Kind::eInt );
		return makeImageAccessCall( cache.getBasicType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}
}

#endif
