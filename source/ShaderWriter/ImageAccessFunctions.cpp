
/*
See LICENSE file in root folder
*/

#include "ShaderWriter/ImageAccessFunctions.hpp"

#include <ASTGenerator/Expr/MakeImageAccess.hpp>

namespace sdw
{
#pragma region imageSize
	/**
	*name
	*	imageSize
	*/
	/**@{*/
	Int imageSize( Image1D const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DF( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2D const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DF( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image3D const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DF( makeExpr( image ) ) };
	}
	IVec2 imageSize( ImageCube const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeF( makeExpr( image ) ) };
	}
	IVec3 imageSize( ImageCubeArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayF( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DRect const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectF( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image1DArray const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayF( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayF( makeExpr( image ) ) };
	}
	Int imageSize( ImageBuffer const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferF( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DMS const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSF( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DMSArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayF( makeExpr( image ) ) };
	}
	Int imageSize( IImage1D const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DI( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2D const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DI( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage3D const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DI( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImageCube const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeI( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImageCubeArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayI( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRect const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectI( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage1DArray const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayI( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayI( makeExpr( image ) ) };
	}
	Int imageSize( IImageBuffer const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferI( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DMS const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSI( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DMSArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayI( makeExpr( image ) ) };
	}
	Int imageSize( UImage1D const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DU( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2D const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DU( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage3D const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DU( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImageCube const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeU( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImageCubeArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayU( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRect const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectU( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage1DArray const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayU( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayU( makeExpr( image ) ) };
	}
	Int imageSize( UImageBuffer const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferU( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DMS const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSU( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DMSArray const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayU( makeExpr( image ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageSamples
	/**
	*name
	*	imageSamples
	*/
	/**@{*/
	Int imageSamples( Image2DMS const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSF( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayF( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMS const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSI( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayI( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMS const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSU( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayU( makeExpr( image ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageLoad
	/**
	*name
	*	imageLoad
	*/
	/**@{*/
	Vec4 imageLoad( Image1D const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image2D const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image3D const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image2DRect const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DRectF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( ImageCube const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( ImageBuffer const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image1DArray const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image2DArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( ImageCubeArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( IImage1D const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( IImage2D const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( IImage3D const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( IImage2DRect const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DRectI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( IImageCube const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( IImageBuffer const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( IImage1DArray const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( IImage2DArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( IImageCubeArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( UImage1D const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( UImage2D const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( UImage3D const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( UImage2DRect const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DRectU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( UImageCube const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( UImageBuffer const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( UImage1DArray const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( UImage2DArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( UImageCubeArray const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image2DMS const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec4 imageLoad( Image2DMSArray const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec4 imageLoad( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec4 imageLoad( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec4 imageLoad( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec4 imageLoad( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicAdd
	/**
	*name
	*	imageAtomicAdd
	*/
	/**@{*/
	UInt imageAtomicAdd( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage2DArray const & image
		,  IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicMin
	/**
	*name
	*	imageAtomicMin
	*/
	/**@{*/
	UInt imageAtomicMin( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicMax
	/**
	*name
	*	imageAtomicMax
	*/
	/**@{*/
	UInt imageAtomicMax( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicAnd
	/**
	*name
	*	imageAtomicAnd
	*/
	/**@{*/
	UInt imageAtomicAnd( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicOr
	/**
	*name
	*	imageAtomicOr
	*/
	/**@{*/
	UInt imageAtomicOr( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicXor
	/**
	*name
	*	imageAtomicXor
	*/
	/**@{*/
	UInt imageAtomicXor( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicExchange
	/**
	*name
	*	imageAtomicExchange
	*/
	/**@{*/
	UInt imageAtomicExchange( UImage1D const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage2D const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage3D const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImageCube const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImageBuffer const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage1D const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage2D const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage3D const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage2DRect const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImageCube const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImageBuffer const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage1DArray const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage2DArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicCompSwap
	/**
	*name
	*	imageAtomicCompSwap
	*/
	/**@{*/
	UInt imageAtomicCompSwap( UImage1D const & image
		, Int const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage2D const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage3D const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage2DRect const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImageCube const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImageBuffer const & image
		, Int const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage1DArray const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage2DArray const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImageCubeArray const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage1D const & image
		, Int const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage2D const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage3D const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage2DRect const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImageCube const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImageBuffer const & image
		, Int const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage1DArray const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage2DArray const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImageCubeArray const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage2DMS const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage2DMSArray const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
}
