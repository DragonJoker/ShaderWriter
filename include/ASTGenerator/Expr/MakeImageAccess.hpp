/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMakeImageAccess_H___
#define ___AST_ExprMakeImageAccess_H___
#pragma once

#include "ExprImageAccessCall.hpp"

namespace ast::expr
{
	inline ImageAccessCallPtr/*int*/ makeImageSize1DF( ExprPtr/*image1D*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSize1DF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize2DF( ExprPtr/*image2D*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSize3DF( ExprPtr/*image3D*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSizeCubeF( ExprPtr/*imageCube*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSizeCubeArrayF( ExprPtr/*imageCubeArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize2DRectF( ExprPtr/*image2DRect*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize1DArrayF( ExprPtr/*image1DArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSize2DArrayF( ExprPtr/*image2DArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageSizeBufferF( ExprPtr/*imageBuffer*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize2DMSF( ExprPtr/*image2DMS*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSize2DMSArrayF( ExprPtr/*image2DMSArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageSize1DI( ExprPtr/*iimage1D*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSize1DI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize2DI( ExprPtr/*iimage2D*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSize3DI( ExprPtr/*iimage3D*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSizeCubeI( ExprPtr/*iimageCube*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSizeCubeArrayI( ExprPtr/*iimageCubeArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize2DRectI( ExprPtr/*iimage2DRect*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize1DArrayI( ExprPtr/*iimage1DArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSize2DArrayI( ExprPtr/*iimage2DArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageSizeBufferI( ExprPtr/*iimageBuffer*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize2DMSI( ExprPtr/*iimage2DMS*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSize2DMSArrayI( ExprPtr/*iimage2DMSArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageSize1DU( ExprPtr/*uimage1D*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSize1DU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize2DU( ExprPtr/*uimage2D*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSize3DU( ExprPtr/*uimage3D*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSizeCubeU( ExprPtr/*uimageCube*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSizeCubeArrayU( ExprPtr/*uimageCubeArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize2DRectU( ExprPtr/*uimage2DRect*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize1DArrayU( ExprPtr/*uimage1DArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSize2DArrayU( ExprPtr/*uimage2DArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageSizeBufferU( ExprPtr/*uimageBuffer*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec2i*/ makeImageSize2DMSU( ExprPtr/*uimage2DMS*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec3i*/ makeImageSize2DMSArrayU( ExprPtr/*uimage2DMSArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageSamples2DMSF( ExprPtr/*image2DMS*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageSamples2DMSArrayF( ExprPtr/*image2DMSArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageSamples2DMSI( ExprPtr/*iimage2DMS*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageSamples2DMSArrayI( ExprPtr/*iimage2DMSArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageSamples2DMSU( ExprPtr/*uimage2DMS*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageSamples2DMSArrayU( ExprPtr/*uimage2DMSArray*/ image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad1DF( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DF( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad3DF( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DRectF( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DRectF
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoadCubeF( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoadBufferF( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad1DArrayF( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DArrayF( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoadCubeArrayF( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DMSF( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DMSArrayF( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad1DI( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DI( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad3DI( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DRectI( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DRectI
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoadCubeI( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoadBufferI( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad1DArrayI( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DArrayI( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoadCubeArrayI( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DMSI( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DMSArrayI( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad1DU( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DU( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad3DU( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DRectU( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DRectU
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoadCubeU( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoadBufferU( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad1DArrayU( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DArrayU( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoadCubeArrayU( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DMSU( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	inline ImageAccessCallPtr/*vec4f*/ makeImageLoad2DMSArrayU( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd1DFU( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DFU( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd3DFU( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DRectFU( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAddCubeFU( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAddBufferFU( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd1DArrayFU( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DArrayFU( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAddCubeArrayFU( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DMSFU( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DMSArrayFU( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd1DIU( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DIU( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd3DIU( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DRectIU( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAddCubeIU( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAddBufferIU( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd1DArrayIU( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DArrayIU( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/* vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAddCubeArrayIU( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DMSIU( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DMSArrayIU( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd1DUU( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DUU( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd3DUU( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DRectUU( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAddCubeUU( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAddBufferUU( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd1DArrayUU( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DArrayUU( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/* vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAddCubeArrayUU( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DMSUU( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAdd2DMSArrayUU( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd1DFI( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DFI( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd3DFI( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DRectFI( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAddCubeFI( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAddBufferFI( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd1DArrayFI( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DArrayFI( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAddCubeArrayFI( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DMSFI( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DMSArrayFI( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd1DII( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DII( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd3DII( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DRectII( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAddCubeII( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAddBufferII( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd1DArrayII( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DArrayII( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAddCubeArrayII( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DMSII( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DMSArrayII( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd1DUI( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DUI( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd3DUI( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DRectUI( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAddCubeUI( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAddBufferUI( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd1DArrayUI( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DArrayUI( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAddCubeArrayUI( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DMSUI( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAdd2DMSArrayUI( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin1DFU( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DFU( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin3DFU( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DRectFU( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMinCubeFU( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMinBufferFU( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin1DArrayFU( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DArrayFU( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMinCubeArrayFU( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DMSFU( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DMSArrayFU( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin1DIU( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DIU( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin3DIU( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DRectIU( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMinCubeIU( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMinBufferIU( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin1DArrayIU( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DArrayIU( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMinCubeArrayIU( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DMSIU( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DMSArrayIU( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin1DUU( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DUU( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin3DUU( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DRectUU( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMinCubeUU( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMinBufferUU( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin1DArrayUU( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DArrayUU( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMinCubeArrayUU( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DMSUU( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMin2DMSArrayUU( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin1DFI( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DFI( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin3DFI( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DRectFI( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMinCubeFI( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMinBufferFI( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin1DArrayFI( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DArrayFI( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMinCubeArrayFI( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DMSFI( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DMSArrayFI( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin1DII( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DII( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin3DII( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DRectII( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMinCubeII( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMinBufferII( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin1DArrayII( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DArrayII( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMinCubeArrayII( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DMSII( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DMSArrayII( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin1DUI( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DUI( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin3DUI( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DRectUI( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMinCubeUI( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMinBufferUI( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin1DArrayUI( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DArrayUI( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMinCubeArrayUI( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DMSUI( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMin2DMSArrayUI( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax1DFU( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DFU( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax3DFU( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DRectFU( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMaxCubeFU( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMaxBufferFU( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax1DArrayFU( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DArrayFU( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMaxCubeArrayFU( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DMSFU( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DMSArrayFU( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax1DIU( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DIU( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax3DIU( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DRectIU( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMaxCubeIU( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMaxBufferIU( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax1DArrayIU( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DArrayIU( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMaxCubeArrayIU( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DMSIU( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DMSArrayIU( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax1DUU( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DUU( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax3DUU( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DRectUU( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMaxCubeUU( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMaxBufferUU( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax1DArrayUU( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DArrayUU( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMaxCubeArrayUU( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DMSUU( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicMax2DMSArrayUU( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax1DFI( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DFI( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax3DFI( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DRectFI( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMaxCubeFI( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMaxBufferFI( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax1DArrayFI( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DArrayFI( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMaxCubeArrayFI( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DMSFI( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DMSArrayFI( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax1DII( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DII( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax3DII( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DRectII( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMaxCubeII( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMaxBufferII( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax1DArrayII( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DArrayII( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMaxCubeArrayII( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DMSII( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DMSArrayII( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax1DUI( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DUI( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax3DUI( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DRectUI( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMaxCubeUI( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMaxBufferUI( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax1DArrayUI( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DArrayUI( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMaxCubeArrayUI( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DMSUI( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicMax2DMSArrayUI( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd1DFU( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DFU( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd3DFU( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DRectFU( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAndCubeFU( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAndBufferFU( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd1DArrayFU( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DArrayFU( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAndCubeArrayFU( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DMSFU( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DMSArrayFU( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd1DIU( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DIU( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd3DIU( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DRectIU( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAndCubeIU( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAndBufferIU( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd1DArrayIU( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DArrayIU( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAndCubeArrayIU( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DMSIU( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DMSArrayIU( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd1DUU( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DUU( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd3DUU( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DRectUU( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAndCubeUU( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAndBufferUU( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd1DArrayUU( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DArrayUU( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAndCubeArrayUU( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DMSUU( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicAnd2DMSArrayUU( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd1DFI( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DFI( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd3DFI( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DRectFI( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAndCubeFI( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAndBufferFI( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd1DArrayFI( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DArrayFI( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAndCubeArrayFI( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DMSFI( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DMSArrayFI( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd1DII( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DII( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd3DII( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DRectII( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAndCubeII( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAndBufferII( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd1DArrayII( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DArrayII( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAndCubeArrayII( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DMSII( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DMSArrayII( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd1DUI( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DUI( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd3DUI( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DRectUI( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAndCubeUI( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAndBufferUI( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd1DArrayUI( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DArrayUI( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAndCubeArrayUI( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DMSUI( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicAnd2DMSArrayUI( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr1DFU( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DFU( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr3DFU( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DRectFU( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOrCubeFU( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOrBufferFU( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr1DArrayFU( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DArrayFU( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOrCubeArrayFU( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DMSFU( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DMSArrayFU( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr1DIU( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DIU( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr3DIU( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DRectIU( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOrCubeIU( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOrBufferIU( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr1DArrayIU( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DArrayIU( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOrCubeArrayIU( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DMSIU( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DMSArrayIU( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr1DUU( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DUU( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr3DUU( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DRectUU( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOrCubeUU( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOrBufferUU( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr1DArrayUU( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DArrayUU( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOrCubeArrayUU( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DMSUU( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicOr2DMSArrayUU( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr1DFI( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DFI( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr3DFI( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DRectFI( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOrCubeFI( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOrBufferFI( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr1DArrayFI( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DArrayFI( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOrCubeArrayFI( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DMSFI( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DMSArrayFI( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr1DII( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DII( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr3DII( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DRectII( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOrCubeII( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOrBufferII( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr1DArrayII( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DArrayII( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOrCubeArrayII( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DMSII( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DMSArrayII( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr1DUI( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DUI( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr3DUI( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DRectUI( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOrCubeUI( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOrBufferUI( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr1DArrayUI( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DArrayUI( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOrCubeArrayUI( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DMSUI( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicOr2DMSArrayUI( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor1DFU( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DFU( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor3DFU( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DRectFU( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXorCubeFU( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXorBufferFU( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor1DArrayFU( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DArrayFU( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXorCubeArrayFU( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DMSFU( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DMSArrayFU( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor1DIU( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DIU( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor3DIU( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DRectIU( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXorCubeIU( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXorBufferIU( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor1DArrayIU( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DArrayIU( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXorCubeArrayIU( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DMSIU( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DMSArrayIU( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor1DUU( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DUU( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor3DUU( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DRectUU( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXorCubeUU( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXorBufferUU( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor1DArrayUU( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DArrayUU( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXorCubeArrayUU( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DMSUU( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicXor2DMSArrayUU( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor1DFI( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DFI( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor3DFI( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DRectFI( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXorCubeFI( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXorBufferFI( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor1DArrayFI( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DArrayFI( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXorCubeArrayFI( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DMSFI( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DMSArrayFI( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor1DII( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DII( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor3DII( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DRectII( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXorCubeII( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXorBufferII( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor1DArrayII( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DArrayII( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXorCubeArrayII( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DMSII( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DMSArrayII( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor1DUI( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DUI( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor3DUI( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DRectUI( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXorCubeUI( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXorBufferUI( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor1DArrayUI( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DArrayUI( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXorCubeArrayUI( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DMSUI( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicXor2DMSArrayUI( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange1DFU( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DFU( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange3DFU( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DRectFU( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchangeCubeFU( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchangeBufferFU( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange1DArrayFU( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DArrayFU( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchangeCubeArrayFU( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DMSFU( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DMSArrayFU( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange1DIU( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DIU( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange3DIU( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DRectIU( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchangeCubeIU( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchangeBufferIU( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange1DArrayIU( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DArrayIU( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchangeCubeArrayIU( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DMSIU( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DMSArrayIU( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange1DUU( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DUU( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange3DUU( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DRectUU( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchangeCubeUU( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchangeBufferUU( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange1DArrayUU( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DArrayUU( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchangeCubeArrayUU( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DMSUU( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicExchange2DMSArrayUU( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange1DFI( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DFI( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange3DFI( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DRectFI( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchangeCubeFI( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchangeBufferFI( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange1DArrayFI( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DArrayFI( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchangeCubeArrayFI( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DMSFI( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DMSArrayFI( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange1DII( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DII( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange3DII( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DRectII( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchangeCubeII( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchangeBufferII( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange1DArrayII( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DArrayII( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchangeCubeArrayII( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DMSII( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DMSArrayII( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange1DUI( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DUI( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange3DUI( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DRectUI( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchangeCubeUI( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchangeBufferUI( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange1DArrayUI( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DArrayUI( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchangeCubeArrayUI( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DMSUI( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicExchange2DMSArrayUI( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap1DFU( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DFU( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap3DFU( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap3DFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DRectFU( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwapCubeFU( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwapBufferFU( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap1DArrayFU( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DArrayFU( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwapCubeArrayFU( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DMSFU( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DMSArrayFU( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap1DIU( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DIU( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap3DIU( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap3DIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DRectIU( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwapCubeIU( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwapBufferIU( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap1DArrayIU( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DArrayIU( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwapCubeArrayIU( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DMSIU( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DMSArrayIU( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap1DUU( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DUU( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap3DUU( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap3DUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DRectUU( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwapCubeUU( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwapBufferUU( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap1DArrayUU( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DArrayUU( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwapCubeArrayUU( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DMSUU( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*uint*/ makeImageAtomicCompSwap2DMSArrayUU( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*uint*/ compare
		, ExprPtr/*uint*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap1DFI( ExprPtr/*image1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DFI( ExprPtr/*image2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap3DFI( ExprPtr/*image3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap3DFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DRectFI( ExprPtr/*image2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwapCubeFI( ExprPtr/*imageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwapBufferFI( ExprPtr/*imageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap1DArrayFI( ExprPtr/*image1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DArrayFI( ExprPtr/*image2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwapCubeArrayFI( ExprPtr/*imageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DMSFI( ExprPtr/*image2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DMSArrayFI( ExprPtr/*image2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap1DII( ExprPtr/*iimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DII( ExprPtr/*iimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap3DII( ExprPtr/*iimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap3DII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DRectII( ExprPtr/*iimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwapCubeII( ExprPtr/*iimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwapBufferII( ExprPtr/*iimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapBufferII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap1DArrayII( ExprPtr/*iimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DArrayII( ExprPtr/*iimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwapCubeArrayII( ExprPtr/*iimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DMSII( ExprPtr/*iimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DMSArrayII( ExprPtr/*iimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap1DUI( ExprPtr/*uimage1D*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DUI( ExprPtr/*uimage2D*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap3DUI( ExprPtr/*uimage3D*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap3DUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DRectUI( ExprPtr/*uimage2DRect*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwapCubeUI( ExprPtr/*uimageCube*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwapBufferUI( ExprPtr/*uimageBuffer*/ image
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap1DArrayUI( ExprPtr/*uimage1DArray*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DArrayUI( ExprPtr/*uimage2DArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwapCubeArrayUI( ExprPtr/*uimageCubeArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DMSUI( ExprPtr/*uimage2DMS*/ image
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	inline ImageAccessCallPtr/*int*/ makeImageAtomicCompSwap2DMSArrayUI( ExprPtr/*uimage2DMSArray*/ image
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ sample
		, ExprPtr/*int*/ compare
		, ExprPtr/*int*/ data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}
}

#endif
