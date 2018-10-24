/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GetImageAccessFunctions_H___
#define ___SDW_GetImageAccessFunctions_H___
#pragma once

#include "Function.hpp"
#include "FunctionParam.hpp"
#include "Bool.hpp"
#include "Image.hpp"
#include "OptionalMat2.hpp"
#include "OptionalMat2x3.hpp"
#include "OptionalMat2x4.hpp"
#include "OptionalMat3.hpp"
#include "OptionalMat3x2.hpp"
#include "OptionalMat3x4.hpp"
#include "OptionalMat4.hpp"
#include "OptionalMat4x2.hpp"
#include "OptionalMat4x3.hpp"
#include "Sampler.hpp"

#include <ASTGenerator/Expr/MakeImageAccess.hpp>

namespace sdw
{
	inline Int imageSize( Image1D const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DF( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( Image2D const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DF( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( Image3D const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DF( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( ImageCube const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeF( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( ImageCubeArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayF( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( Image2DRect const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectF( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( Image1DArray const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayF( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( Image2DArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayF( makeExpr( image ) ) };
	}

	inline Int imageSize( ImageBuffer const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferF( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( Image2DMS const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSF( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( Image2DMSArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayF( makeExpr( image ) ) };
	}

	inline Int imageSize( IImage1D const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DI( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( IImage2D const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DI( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( IImage3D const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DI( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( IImageCube const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeI( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( IImageCubeArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayI( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( IImage2DRect const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectI( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( IImage1DArray const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayI( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( IImage2DArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayI( makeExpr( image ) ) };
	}

	inline Int imageSize( IImageBuffer const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferI( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( IImage2DMS const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSI( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( IImage2DMSArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayI( makeExpr( image ) ) };
	}

	inline Int imageSize( UImage1D const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DU( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( UImage2D const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DU( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( UImage3D const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DU( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( UImageCube const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeU( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( UImageCubeArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayU( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( UImage2DRect const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectU( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( UImage1DArray const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayU( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( UImage2DArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayU( makeExpr( image ) ) };
	}

	inline Int imageSize( UImageBuffer const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferU( makeExpr( image ) ) };
	}

	inline IVec2 imageSize( UImage2DMS const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSU( makeExpr( image ) ) };
	}

	inline IVec3 imageSize( UImage2DMSArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayU( makeExpr( image ) ) };
	}

	inline Int imageSamples( Image2DMS const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSF( makeExpr( image ) ) };
	}

	inline Int imageSamples( Image2DMSArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayF( makeExpr( image ) ) };
	}

	inline Int imageSamples( IImage2DMS const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSI( makeExpr( image ) ) };
	}

	inline Int imageSamples( IImage2DMSArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayI( makeExpr( image ) ) };
	}

	inline Int imageSamples( UImage2DMS const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSU( makeExpr( image ) ) };
	}

	inline Int imageSamples( UImage2DMSArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayU( makeExpr( image ) ) };
	}

	inline Vec4 imageLoad( Image1D const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DF( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( Image2D const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DF( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( Image3D const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DF( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( Image2DRect const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DRectF( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( ImageCube const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeF( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( ImageBuffer const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferF( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( Image1DArray const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( Image2DArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( ImageCubeArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}

	inline Vec4 imageLoad( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}

	inline Vec4 imageLoad( IImage1D const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DI( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( IImage2D const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DI( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( IImage3D const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DI( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( IImage2DRect const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DRectI( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( IImageCube const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeI( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( IImageBuffer const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferI( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( IImage1DArray const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( IImage2DArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( IImageCubeArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}

	inline Vec4 imageLoad( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}

	inline Vec4 imageLoad( UImage1D const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DU( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( UImage2D const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DU( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( UImage3D const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DU( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( UImage2DRect const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DRectU( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( UImageCube const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeU( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( UImageBuffer const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferU( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( UImage1DArray const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( UImage2DArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( UImageCubeArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}

	inline Vec4 imageLoad( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}

	inline Vec4 imageLoad( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}

	inline UInt imageAtomicAdd( Image1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( Image2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( Image3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( Image2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( ImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( ImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( Image1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( Image2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( ImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( IImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( IImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( IImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( IImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( IImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( IImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( IImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( IImage2DArray const & image
		,  IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( IImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( UImage2DArray const & image
		,  IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAdd( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( Image1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( Image2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( Image3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( Image2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( ImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( ImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( Image1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( Image2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( ImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( UImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( UImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( UImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( UImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( UImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( UImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( UImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( UImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( UImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAdd( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( Image1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( Image2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( Image3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( Image2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( ImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( ImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( Image1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( Image2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( ImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( IImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( IImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( IImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( IImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( IImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( IImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( IImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( IImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( IImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMin( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( Image1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( Image2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( Image3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( Image2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( ImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( ImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( Image1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( Image2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( ImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( UImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( UImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( UImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( UImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( UImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( UImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( UImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( UImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( UImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMin( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( Image1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( Image2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( Image3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( Image2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( ImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( ImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( Image1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( Image2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( ImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( IImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( IImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( IImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( IImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( IImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( IImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( IImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( IImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( IImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicMax( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( Image1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( Image2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( Image3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( Image2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( ImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( ImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( Image1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( Image2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( ImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( UImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( UImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( UImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( UImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( UImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( UImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( UImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( UImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( UImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicMax( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( Image1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( Image2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( Image3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( Image2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( ImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( ImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( Image1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( Image2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( ImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( IImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( IImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( IImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( IImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( IImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( IImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( IImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( IImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( IImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicAnd( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( Image1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( Image2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( Image3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( Image2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( ImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( ImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( Image1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( Image2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( ImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( UImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( UImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( UImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( UImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( UImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( UImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( UImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( UImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( UImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicAnd( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( Image1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( Image2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( Image3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( Image2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( ImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( ImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( Image1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( Image2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( ImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( IImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( IImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( IImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( IImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( IImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( IImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( IImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( IImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( IImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicOr( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( Image1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( Image2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( Image3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( Image2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( ImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( ImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( Image1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( Image2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( ImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( UImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( UImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( UImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( UImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( UImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( UImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( UImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( UImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( UImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicOr( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( Image1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( Image2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( Image3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( Image2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( ImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( ImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( Image1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( Image2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( ImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( IImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( IImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( IImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( IImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( IImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( IImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( IImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( IImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( IImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicXor( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( Image1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( Image2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( Image3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( Image2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( ImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( ImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( Image1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( Image2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( ImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( UImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( UImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( UImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( UImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( UImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( UImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( UImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( UImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( UImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicXor( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( Image1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( Image2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( Image3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( Image2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( ImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( ImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( Image1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( Image2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( ImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( IImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( IImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( IImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( IImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( IImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( IImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( IImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( IImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( IImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicExchange( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( Image1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( Image2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( Image3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( Image2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( ImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( ImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( Image1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( Image2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( ImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( UImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( UImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( UImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( UImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( UImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( UImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( UImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( UImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( UImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicExchange( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( Image1D const & image
		, Int const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( Image2D const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( Image3D const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( Image2DRect const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( ImageCube const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( ImageBuffer const & image
		, Int const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( Image1DArray const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( Image2DArray const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( ImageCubeArray const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayFU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( IImage1D const & image
		, Int const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( IImage2D const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( IImage3D const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( IImage2DRect const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( IImageCube const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( IImageBuffer const & image
		, Int const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( IImage1DArray const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( IImage2DArray const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( IImageCubeArray const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayIU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( UImage1D const & image
		, Int const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( UImage2D const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( UImage3D const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( UImageCube const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( UImageBuffer const & image
		, Int const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline UInt imageAtomicCompSwap( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayUU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( Image1D const & image
		, Int const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( Image2D const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( Image3D const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( Image2DRect const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( ImageCube const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( ImageBuffer const & image
		, Int const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( Image1DArray const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( Image2DArray const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( ImageCubeArray const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayFI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( IImage1D const & image
		, Int const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( IImage2D const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( IImage3D const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( IImage2DRect const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( IImageCube const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( IImageBuffer const & image
		, Int const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( IImage1DArray const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( IImage2DArray const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayII( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( UImage1D const & image
		, Int const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( UImage2D const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( UImage3D const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( UImage2DRect const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( UImageCube const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( UImageBuffer const & image
		, Int const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( UImage1DArray const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( UImage2DArray const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( UImageCubeArray const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}

	inline Int imageAtomicCompSwap( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayUI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
}

#endif
