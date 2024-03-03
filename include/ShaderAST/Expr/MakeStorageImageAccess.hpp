/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#ifndef ___AST_ExprMakeStorageImageAccess_H___
#define ___AST_ExprMakeStorageImageAccess_H___
#pragma once

#include "ExprCache.hpp"
#include "ExprStorageImageAccessCall.hpp"

#include <cassert>

namespace ast::expr
{	// Image Query Functions

	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 1D>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSize1DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 3D>
	*/
	inline StorageImageAccessCallPtr makeImageSize3DUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize3DU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, Cube>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSizeCubeArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize1DArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, Buffer>
	*/
	inline StorageImageAccessCallPtr makeImageSizeBufferUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	vec3i
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSize2DMSArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec3I )
			, StorageImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*/
	inline StorageImageAccessCallPtr makeImageSamples2DMSArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image )
	{
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}
	// Image texel load

	/**
	*@return
	*	vec4f
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4F )
			, StorageImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2F )
			, StorageImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eHalf )
			, StorageImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4F )
			, StorageImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2F )
			, StorageImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eHalf )
			, StorageImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4F )
			, StorageImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2F )
			, StorageImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eHalf )
			, StorageImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4F )
			, StorageImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2F )
			, StorageImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eHalf )
			, StorageImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4F )
			, StorageImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2F )
			, StorageImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eHalf )
			, StorageImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4F )
			, StorageImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2F )
			, StorageImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eHalf )
			, StorageImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4F )
			, StorageImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2F )
			, StorageImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eHalf )
			, StorageImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4F )
			, StorageImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2F )
			, StorageImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eHalf )
			, StorageImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4F )
			, StorageImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2F )
			, StorageImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eHalf )
			, StorageImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4f
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4F )
			, StorageImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4h
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2f
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2F )
			, StorageImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2h
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	float
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	half
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eHalf )
			, StorageImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4I )
			, StorageImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2i
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2I )
			, StorageImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	int
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad3DUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoadBufferUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageLoad1DArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*/
	inline StorageImageAccessCallPtr makeImageLoadCubeArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4u
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4U )
			, StorageImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2u
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2U )
			, StorageImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	/**
	*@return
	*	uint
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageLoad2DMSArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}
	// Image texel store

	/**
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4f
	*/
	inline StorageImageAccessCallPtr makeImageStore1DFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline StorageImageAccessCallPtr makeImageStore1DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2f
	*/
	inline StorageImageAccessCallPtr makeImageStore1DFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline StorageImageAccessCallPtr makeImageStore1DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	float
	*/
	inline StorageImageAccessCallPtr makeImageStore1DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	half
	*/
	inline StorageImageAccessCallPtr makeImageStore1DFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eHalf );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4f
	*/
	inline StorageImageAccessCallPtr makeImageStore2DFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4h
	*/
	inline StorageImageAccessCallPtr makeImageStore2DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2f
	*/
	inline StorageImageAccessCallPtr makeImageStore2DFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2h
	*/
	inline StorageImageAccessCallPtr makeImageStore2DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	float
	*/
	inline StorageImageAccessCallPtr makeImageStore2DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	half
	*/
	inline StorageImageAccessCallPtr makeImageStore2DFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eHalf );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4f
	*/
	inline StorageImageAccessCallPtr makeImageStore3DFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline StorageImageAccessCallPtr makeImageStore3DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2f
	*/
	inline StorageImageAccessCallPtr makeImageStore3DFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline StorageImageAccessCallPtr makeImageStore3DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline StorageImageAccessCallPtr makeImageStore3DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	half
	*/
	inline StorageImageAccessCallPtr makeImageStore3DFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eHalf );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4f
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2f
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	half
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eHalf );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4f
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2f
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	float
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	half
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eHalf );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4f
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4h
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2f
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2h
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	float
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	half
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eHalf );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4f
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2f
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	half
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eHalf );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4f
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4h
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2f
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2h
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	float
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	half
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eHalf );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayF
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4f
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2f
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	float
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	half
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eHalf );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4f
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayFRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4h
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2f
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayFRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2h
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	float
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Float, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	half
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayFR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eHalf );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore1DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore1DIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore1DIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore3DIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore3DIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore3DIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore3DIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore3DIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore3DIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore3DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore3DIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore3DIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayIRgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayIRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayIRgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayIRg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayIRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2i
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayIRg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2I );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayIR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<Int, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	int
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayIR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore1DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore1DUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore1DUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore3DURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore3DURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore3DURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore3DURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore3DURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore3DURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore3DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore3DUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 3D>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore3DUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Buffer>
	*@param[in] P
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStoreBufferUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 1D, Array>
	*@param[in] P
	*	vec2i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore1DArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, Cube, Array>
	*@param[in] P
	*	vec3i
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStoreCubeArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStoreCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS>
	*@param[in] P
	*	vec2i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayURgba32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayURgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec4u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayURgba8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayURg32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayURg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	vec2u
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayURg8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2U );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayUR16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}
	/**
	*@param image
	*	StorageImage<UInt, 2D, MS, Array>
	*@param[in] P
	*	vec3i
	*@param[in] sample
	*	int
	*@param[in] data
	*	uint
	*/
	inline StorageImageAccessCallPtr makeImageStore2DMSArrayUR8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVoid )
			, StorageImageAccess::eImageStore2DMSArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd1DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAdd1DU
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAdd2DU
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd3DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAdd3DU
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
	inline StorageImageAccessCallPtr makeImageAtomicAddCubeUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAddCubeU
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
	inline StorageImageAccessCallPtr makeImageAtomicAddBufferUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAddBufferU
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd1DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAdd1DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() ==  type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAdd2DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicAddCubeArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAddCubeArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAdd2DMSU
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAdd2DMSArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd1DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAdd1DI
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAdd2DI
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd3DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAdd3DI
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
	inline StorageImageAccessCallPtr makeImageAtomicAddCubeIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAddCubeI
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
	inline StorageImageAccessCallPtr makeImageAtomicAddBufferIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAddBufferI
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd1DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAdd1DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAdd2DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicAddCubeArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAddCubeArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAdd2DMSI
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAdd2DMSArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd1DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicAdd1DF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd1DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicAdd1DF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd1DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicAdd1DF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicAdd2DF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicAdd2DF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicAdd2DF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd3DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicAdd3DF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd3DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicAdd3DF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd3DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicAdd3DF
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
	inline StorageImageAccessCallPtr makeImageAtomicAddCubeFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicAddCubeF
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
	inline StorageImageAccessCallPtr makeImageAtomicAddCubeFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicAddCubeF
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
	inline StorageImageAccessCallPtr makeImageAtomicAddCubeFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicAddCubeF
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
	inline StorageImageAccessCallPtr makeImageAtomicAddBufferFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicAddBufferF
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
	inline StorageImageAccessCallPtr makeImageAtomicAddBufferFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicAddBufferF
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
	inline StorageImageAccessCallPtr makeImageAtomicAddBufferFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicAddBufferF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd1DArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicAdd1DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd1DArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicAdd1DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd1DArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicAdd1DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() ==  type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicAdd2DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() ==  type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicAdd2DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() ==  type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicAdd2DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicAddCubeArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicAddCubeArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicAddCubeArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicAddCubeArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicAddCubeArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicAddCubeArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DMSFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicAdd2DMSF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DMSFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicAdd2DMSF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DMSFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicAdd2DMSF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DMSArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicAdd2DMSArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DMSArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicAdd2DMSArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicAdd2DMSArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicAdd2DMSArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicMin1DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMin1DU
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
	inline StorageImageAccessCallPtr makeImageAtomicMin2DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMin2DU
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
	inline StorageImageAccessCallPtr makeImageAtomicMin3DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMin3DU
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
	inline StorageImageAccessCallPtr makeImageAtomicMinCubeUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMinCubeU
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
	inline StorageImageAccessCallPtr makeImageAtomicMinBufferUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMinBufferU
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
	inline StorageImageAccessCallPtr makeImageAtomicMin1DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMin1DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicMin2DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMin2DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicMinCubeArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMinCubeArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicMin2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMin2DMSU
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
	inline StorageImageAccessCallPtr makeImageAtomicMin2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMin2DMSArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicMin1DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMin1DI
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
	inline StorageImageAccessCallPtr makeImageAtomicMin2DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMin2DI
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
	inline StorageImageAccessCallPtr makeImageAtomicMin3DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMin3DI
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
	inline StorageImageAccessCallPtr makeImageAtomicMinCubeIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMinCubeI
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
	inline StorageImageAccessCallPtr makeImageAtomicMinBufferIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMinBufferI
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
	inline StorageImageAccessCallPtr makeImageAtomicMin1DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMin1DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicMin2DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMin2DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicMinCubeArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMinCubeArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicMin2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMin2DMSI
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
	inline StorageImageAccessCallPtr makeImageAtomicMin2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMin2DMSArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicMax1DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMax1DU
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
	inline StorageImageAccessCallPtr makeImageAtomicMax2DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMax2DU
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
	inline StorageImageAccessCallPtr makeImageAtomicMax3DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMax3DU
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
	inline StorageImageAccessCallPtr makeImageAtomicMaxCubeUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMaxCubeU
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
	inline StorageImageAccessCallPtr makeImageAtomicMaxBufferUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMaxBufferU
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
	inline StorageImageAccessCallPtr makeImageAtomicMax1DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMax1DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicMax2DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMax2DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicMaxCubeArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMaxCubeArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicMax2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMax2DMSU
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
	inline StorageImageAccessCallPtr makeImageAtomicMax2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicMax2DMSArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicMax1DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMax1DI
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
	inline StorageImageAccessCallPtr makeImageAtomicMax2DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMax2DI
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
	inline StorageImageAccessCallPtr makeImageAtomicMax3DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMax3DI
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
	inline StorageImageAccessCallPtr makeImageAtomicMaxCubeIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMaxCubeI
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
	inline StorageImageAccessCallPtr makeImageAtomicMaxBufferIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMaxBufferI
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
	inline StorageImageAccessCallPtr makeImageAtomicMax1DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMax1DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicMax2DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMax2DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicMaxCubeArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMaxCubeArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicMax2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMax2DMSI
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
	inline StorageImageAccessCallPtr makeImageAtomicMax2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicMax2DMSArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd1DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAnd1DU
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd2DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAnd2DU
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd3DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAnd3DU
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
	inline StorageImageAccessCallPtr makeImageAtomicAndCubeUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAndCubeU
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
	inline StorageImageAccessCallPtr makeImageAtomicAndBufferUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAndBufferU
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd1DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAnd1DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd2DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAnd2DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicAndCubeArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAndCubeArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAnd2DMSU
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicAnd2DMSArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd1DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAnd1DI
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd2DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAnd2DI
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd3DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAnd3DI
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
	inline StorageImageAccessCallPtr makeImageAtomicAndCubeIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAndCubeI
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
	inline StorageImageAccessCallPtr makeImageAtomicAndBufferIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAndBufferI
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd1DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAnd1DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd2DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAnd2DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicAndCubeArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAndCubeArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAnd2DMSI
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
	inline StorageImageAccessCallPtr makeImageAtomicAnd2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicAnd2DMSArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicOr1DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicOr1DU
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
	inline StorageImageAccessCallPtr makeImageAtomicOr2DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicOr2DU
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
	inline StorageImageAccessCallPtr makeImageAtomicOr3DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicOr3DU
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
	inline StorageImageAccessCallPtr makeImageAtomicOrCubeUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicOrCubeU
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
	inline StorageImageAccessCallPtr makeImageAtomicOrBufferUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicOrBufferU
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
	inline StorageImageAccessCallPtr makeImageAtomicOr1DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicOr1DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicOr2DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicOr2DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicOrCubeArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicOrCubeArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicOr2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicOr2DMSU
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
	inline StorageImageAccessCallPtr makeImageAtomicOr2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicOr2DMSArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicOr1DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicOr1DI
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
	inline StorageImageAccessCallPtr makeImageAtomicOr2DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicOr2DI
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
	inline StorageImageAccessCallPtr makeImageAtomicOr3DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicOr3DI
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
	inline StorageImageAccessCallPtr makeImageAtomicOrCubeIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicOrCubeI
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
	inline StorageImageAccessCallPtr makeImageAtomicOrBufferIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicOrBufferI
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
	inline StorageImageAccessCallPtr makeImageAtomicOr1DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicOr1DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicOr2DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicOr2DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicOrCubeArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicOrCubeArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicOr2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicOr2DMSI
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
	inline StorageImageAccessCallPtr makeImageAtomicOr2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicOr2DMSArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicXor1DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicXor1DU
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
	inline StorageImageAccessCallPtr makeImageAtomicXor2DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicXor2DU
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
	inline StorageImageAccessCallPtr makeImageAtomicXor3DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicXor3DU
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
	inline StorageImageAccessCallPtr makeImageAtomicXorCubeUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicXorCubeU
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
	inline StorageImageAccessCallPtr makeImageAtomicXorBufferUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicXorBufferU
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
	inline StorageImageAccessCallPtr makeImageAtomicXor1DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicXor1DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicXor2DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicXor2DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicXorCubeArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicXorCubeArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicXor2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicXor2DMSU
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
	inline StorageImageAccessCallPtr makeImageAtomicXor2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicXor2DMSArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicXor1DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicXor1DI
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
	inline StorageImageAccessCallPtr makeImageAtomicXor2DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicXor2DI
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
	inline StorageImageAccessCallPtr makeImageAtomicXor3DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicXor3DI
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
	inline StorageImageAccessCallPtr makeImageAtomicXorCubeIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicXorCubeI
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
	inline StorageImageAccessCallPtr makeImageAtomicXorBufferIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicXorBufferI
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
	inline StorageImageAccessCallPtr makeImageAtomicXor1DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicXor1DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicXor2DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicXor2DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicXorCubeArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicXorCubeArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicXor2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicXor2DMSI
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
	inline StorageImageAccessCallPtr makeImageAtomicXor2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicXor2DMSArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange1DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicExchange1DU
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicExchange2DU
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange3DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicExchange3DU
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeCubeUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicExchangeCubeU
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeBufferUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicExchangeBufferU
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange1DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicExchange1DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicExchange2DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeCubeArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicExchangeCubeArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicExchange2DMSU
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicExchange2DMSArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange1DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicExchange1DI
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicExchange2DI
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange3DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicExchange3DI
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeCubeIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicExchangeCubeI
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeBufferIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicExchangeBufferI
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange1DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicExchange1DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicExchange2DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeCubeArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicExchangeCubeArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicExchange2DMSI
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicExchange2DMSArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange1DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicExchange1DF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange1DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicExchange1DF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange1DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicExchange1DF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicExchange2DF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicExchange2DF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicExchange2DF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange3DFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicExchange3DF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange3DFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicExchange3DF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange3DFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicExchange3DF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeCubeFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicExchangeCubeF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeCubeFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicExchangeCubeF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeCubeFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicExchangeCubeF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeBufferFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicExchangeBufferF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeBufferFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicExchangeBufferF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeBufferFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicExchangeBufferF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange1DArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicExchange1DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange1DArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicExchange1DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange1DArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicExchange1DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicExchange2DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicExchange2DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicExchange2DArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeCubeArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicExchangeCubeArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeCubeArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicExchangeCubeArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchangeCubeArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicExchangeCubeArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DMSFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicExchange2DMSF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DMSFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicExchange2DMSF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DMSFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicExchange2DMSF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DMSArrayFRgba16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec4H )
			, StorageImageAccess::eImageAtomicExchange2DMSArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DMSArrayFRg16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eVec2H )
			, StorageImageAccess::eImageAtomicExchange2DMSArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicExchange2DMSArrayFR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eFloat )
			, StorageImageAccess::eImageAtomicExchange2DMSArrayF
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap1DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicCompSwap1DU
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap2DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicCompSwap2DU
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap3DUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicCompSwap3DU
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwapCubeUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicCompSwapCubeU
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwapBufferUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicCompSwapBufferU
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap1DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicCompSwap1DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap2DArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicCompSwap2DArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwapCubeArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicCompSwapCubeArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap2DMSUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicCompSwap2DMSU
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayUR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eUInt )
			, StorageImageAccess::eImageAtomicCompSwap2DMSArrayU
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap1DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( compare->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicCompSwap1DI
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap2DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( compare->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicCompSwap2DI
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap3DIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( compare->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicCompSwap3DI
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwapCubeIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( compare->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicCompSwapCubeI
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwapBufferIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eInt );
		assert( compare->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicCompSwapBufferI
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap1DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( compare->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicCompSwap1DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap2DArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( compare->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicCompSwap2DArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwapCubeArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( compare->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicCompSwapCubeArrayI
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap2DMSIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec2I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( compare->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicCompSwap2DMSI
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
	inline StorageImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayIR32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( P->getType()->getRawKind() == type::Kind::eVec3I );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		assert( compare->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return exprCache.makeStorageImageAccessCall( typesCache.getBasicType( type::Kind::eInt )
			, StorageImageAccess::eImageAtomicCompSwap2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}
}

#endif
