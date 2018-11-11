
/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ImageAccessFunctions_H___
#define ___SDW_ImageAccessFunctions_H___
#pragma once

#include "Function.hpp"
#include "FunctionParam.hpp"
#include "Bool.hpp"
#include "Image.hpp"
#include "SampledImage.hpp"
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
#pragma region imageSize
	/**
	*name
	*	imageSize
	*/
	/**@{*/
	Int imageSize( Image1D const & image );
	IVec2 imageSize( Image2D const & image );
	IVec3 imageSize( Image3D const & image );
	IVec2 imageSize( ImageCube const & image );
	IVec3 imageSize( ImageCubeArray const & image );
	IVec2 imageSize( Image2DRect const & image );
	IVec2 imageSize( Image1DArray const & image );
	IVec3 imageSize( Image2DArray const & image );
	Int imageSize( ImageBuffer const & image );
	IVec2 imageSize( Image2DMS const & image );
	IVec3 imageSize( Image2DMSArray const & image );
	Int imageSize( IImage1D const & image );
	IVec2 imageSize( IImage2D const & image );
	IVec3 imageSize( IImage3D const & image );
	IVec2 imageSize( IImageCube const & image );
	IVec3 imageSize( IImageCubeArray const & image );
	IVec2 imageSize( IImage2DRect const & image );
	IVec2 imageSize( IImage1DArray const & image );
	IVec3 imageSize( IImage2DArray const & image );
	Int imageSize( IImageBuffer const & image );
	IVec2 imageSize( IImage2DMS const & image );
	IVec3 imageSize( IImage2DMSArray const & image );
	Int imageSize( UImage1D const & image );
	IVec2 imageSize( UImage2D const & image );
	IVec3 imageSize( UImage3D const & image );
	IVec2 imageSize( UImageCube const & image );
	IVec3 imageSize( UImageCubeArray const & image );
	IVec2 imageSize( UImage2DRect const & image );
	IVec2 imageSize( UImage1DArray const & image );
	IVec3 imageSize( UImage2DArray const & image );
	Int imageSize( UImageBuffer const & image );
	IVec2 imageSize( UImage2DMS const & image );
	IVec3 imageSize( UImage2DMSArray const & image );
	/**@}*/
#pragma endregion
#pragma region imageSamples
	/**
	*name
	*	imageSamples
	*/
	/**@{*/
	Int imageSamples( Image2DMS const & image );
	Int imageSamples( Image2DMSArray const & image );
	Int imageSamples( IImage2DMS const & image );
	Int imageSamples( IImage2DMSArray const & image );
	Int imageSamples( UImage2DMS const & image );
	Int imageSamples( UImage2DMSArray const & image );
	/**@}*/
#pragma endregion
#pragma region imageLoad
	/**
	*name
	*	imageLoad
	*/
	/**@{*/
	Vec4 imageLoad( Image1D const & image, Int const & P );
	Vec4 imageLoad( Image2D const & image, IVec2 const & P );
	Vec4 imageLoad( Image3D const & image, IVec3 const & P );
	Vec4 imageLoad( Image2DRect const & image, IVec2 const & P );
	Vec4 imageLoad( ImageCube const & image, IVec3 const & P );
	Vec4 imageLoad( ImageBuffer const & image, Int const & P );
	Vec4 imageLoad( Image1DArray const & image, IVec2 const & P );
	Vec4 imageLoad( Image2DArray const & image, IVec3 const & P );
	Vec4 imageLoad( ImageCubeArray const & image, IVec3 const & P );
	Vec4 imageLoad( IImage1D const & image, Int const & P );
	Vec4 imageLoad( IImage2D const & image, IVec2 const & P );
	Vec4 imageLoad( IImage3D const & image, IVec3 const & P );
	Vec4 imageLoad( IImage2DRect const & image, IVec2 const & P );
	Vec4 imageLoad( IImageCube const & image, IVec3 const & P );
	Vec4 imageLoad( IImageBuffer const & image, Int const & P );
	Vec4 imageLoad( IImage1DArray const & image, IVec2 const & P );
	Vec4 imageLoad( IImage2DArray const & image, IVec3 const & P );
	Vec4 imageLoad( IImageCubeArray const & image, IVec3 const & P );
	Vec4 imageLoad( UImage1D const & image, Int const & P );
	Vec4 imageLoad( UImage2D const & image, IVec2 const & P );
	Vec4 imageLoad( UImage3D const & image, IVec3 const & P );
	Vec4 imageLoad( UImage2DRect const & image, IVec2 const & P );
	Vec4 imageLoad( UImageCube const & image, IVec3 const & P );
	Vec4 imageLoad( UImageBuffer const & image, Int const & P );
	Vec4 imageLoad( UImage1DArray const & image, IVec2 const & P );
	Vec4 imageLoad( UImage2DArray const & image, IVec3 const & P );
	Vec4 imageLoad( UImageCubeArray const & image, IVec3 const & P );
	Vec4 imageLoad( Image2DMS const & image, IVec2 const & P, Int const & sample );
	Vec4 imageLoad( Image2DMSArray const & image, IVec3 const & P, Int const & sample );
	Vec4 imageLoad( IImage2DMS const & image, IVec2 const & P, Int const & sample );
	Vec4 imageLoad( IImage2DMSArray const & image, IVec3 const & P, Int const & sample );
	Vec4 imageLoad( UImage2DMS const & image, IVec2 const & P, Int const & sample );
	Vec4 imageLoad( UImage2DMSArray const & image, IVec3 const & P, Int const & sample );
	/**@}*/
#pragma endregion
#pragma region imageAtomicAddU
	/**
	*name
	*	imageAtomicAddU
	*/
	/**@{*/
	UInt imageAtomicAdd( Image1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicAdd( Image2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( Image3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( Image2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( ImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( ImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicAdd( Image1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( Image2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( ImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( IImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicAdd( IImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( IImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( IImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( IImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( IImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicAdd( IImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( IImage2DArray const & image,  IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( IImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicAdd( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicAdd( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( UImage2DArray const & image,  IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( Image2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAdd( Image2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAdd( IImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAdd( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAdd( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAdd( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicAddI
	/**
	*name
	*	imageAtomicAddI
	*/
	/**@{*/
	Int imageAtomicAdd( Image1D const & image, Int const & P, Int const & data );
	Int imageAtomicAdd( Image2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( Image3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( Image2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( ImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( ImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicAdd( Image1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( Image2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( ImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicAdd( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicAdd( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( UImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicAdd( UImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( UImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( UImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( UImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( UImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicAdd( UImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( UImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( UImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( Image2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicAdd( Image2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicAdd( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicAdd( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicAdd( UImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicAdd( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicMinU
	/**
	*name
	*	imageAtomicMinU
	*/
	/**@{*/
	UInt imageAtomicMin( Image1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicMin( Image2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( Image3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( Image2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( ImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( ImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicMin( Image1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( Image2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( ImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( IImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicMin( IImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( IImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( IImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( IImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( IImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicMin( IImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( IImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( IImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicMin( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicMin( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( Image2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMin( Image2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMin( IImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMin( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMin( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMin( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicMinI
	/**
	*name
	*	imageAtomicMinI
	*/
	/**@{*/
	Int imageAtomicMin( Image1D const & image, Int const & P, Int const & data );
	Int imageAtomicMin( Image2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( Image3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( Image2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( ImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( ImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicMin( Image1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( Image2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( ImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicMin( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicMin( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( UImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicMin( UImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( UImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( UImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( UImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( UImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicMin( UImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( UImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( UImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( Image2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicMin( Image2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicMin( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicMin( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicMin( UImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicMin( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicMaxU
	/**
	*name
	*	imageAtomicMaxU
	*/
	/**@{*/
	UInt imageAtomicMax( Image1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicMax( Image2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( Image3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( Image2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( ImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( ImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicMax( Image1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( Image2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( ImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( IImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicMax( IImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( IImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( IImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( IImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( IImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicMax( IImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( IImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( IImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicMax( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicMax( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( Image2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMax( Image2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMax( IImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMax( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMax( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMax( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicMaxI
	/**
	*name
	*	imageAtomicMaxI
	*/
	/**@{*/
	Int imageAtomicMax( Image1D const & image, Int const & P, Int const & data );
	Int imageAtomicMax( Image2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( Image3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( Image2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( ImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( ImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicMax( Image1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( Image2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( ImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicMax( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicMax( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( UImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicMax( UImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( UImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( UImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( UImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( UImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicMax( UImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( UImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( UImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( Image2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicMax( Image2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicMax( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicMax( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicMax( UImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicMax( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicAndU
	/**
	*name
	*	imageAtomicAndU
	*/
	/**@{*/
	UInt imageAtomicAnd( Image1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicAnd( Image2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( Image3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( Image2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( ImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( ImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicAnd( Image1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( Image2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( ImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( IImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicAnd( IImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( IImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( IImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( IImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( IImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicAnd( IImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( IImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( IImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicAnd( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicAnd( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( Image2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAnd( Image2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAnd( IImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAnd( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAnd( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAnd( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicAndI
	/**
	*name
	*	imageAtomicAndI
	*/
	/**@{*/
	Int imageAtomicAnd( Image1D const & image, Int const & P, Int const & data );
	Int imageAtomicAnd( Image2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( Image3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( Image2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( ImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( ImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicAnd( Image1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( Image2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( ImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicAnd( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicAnd( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( UImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicAnd( UImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( UImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( UImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( UImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( UImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicAnd( UImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( UImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( UImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( Image2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicAnd( Image2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicAnd( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicAnd( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicAnd( UImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicAnd( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicOrU
	/**
	*name
	*	imageAtomicOrU
	*/
	/**@{*/
	UInt imageAtomicOr( Image1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicOr( Image2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( Image3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( Image2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( ImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( ImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicOr( Image1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( Image2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( ImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( IImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicOr( IImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( IImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( IImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( IImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( IImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicOr( IImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( IImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( IImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicOr( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicOr( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( Image2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicOr( Image2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicOr( IImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicOr( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicOr( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicOr( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicOrI
	/**
	*name
	*	imageAtomicOrI
	*/
	/**@{*/
	Int imageAtomicOr( Image1D const & image, Int const & P, Int const & data );
	Int imageAtomicOr( Image2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( Image3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( Image2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( ImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( ImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicOr( Image1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( Image2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( ImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicOr( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicOr( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( UImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicOr( UImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( UImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( UImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( UImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( UImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicOr( UImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( UImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( UImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( Image2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicOr( Image2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicOr( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicOr( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicOr( UImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicOr( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicXorU
	/**
	*name
	*	imageAtomicXorU
	*/
	/**@{*/
	UInt imageAtomicXor( Image1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicXor( Image2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( Image3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( Image2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( ImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( ImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicXor( Image1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( Image2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( ImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( IImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicXor( IImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( IImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( IImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( IImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( IImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicXor( IImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( IImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( IImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicXor( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicXor( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( Image2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicXor( Image2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicXor( IImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicXor( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicXor( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicXor( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicXorI
	/**
	*name
	*	imageAtomicXorI
	*/
	/**@{*/
	Int imageAtomicXor( Image1D const & image, Int const & P, Int const & data );
	Int imageAtomicXor( Image2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( Image3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( Image2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( ImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( ImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicXor( Image1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( Image2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( ImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicXor( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicXor( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( UImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicXor( UImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( UImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( UImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( UImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( UImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicXor( UImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( UImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( UImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( Image2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicXor( Image2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicXor( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicXor( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicXor( UImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicXor( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicExchangeU
	/**
	*name
	*	imageAtomicExchangeU
	*/
	/**@{*/
	UInt imageAtomicExchange( Image1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicExchange( Image2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( Image3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( Image2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( ImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( ImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicExchange( Image1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( Image2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( ImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( IImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicExchange( IImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( IImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( IImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( IImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( IImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicExchange( IImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( IImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( IImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicExchange( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicExchange( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( Image2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicExchange( Image2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicExchange( IImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicExchange( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicExchange( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicExchange( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicExchangeI
	/**
	*name
	*	imageAtomicExchangeI
	*/
	/**@{*/
	Int imageAtomicExchange( Image1D const & image, Int const & P, Int const & data );
	Int imageAtomicExchange( Image2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( Image3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( Image2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( ImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( ImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicExchange( Image1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( Image2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( ImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicExchange( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicExchange( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( UImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicExchange( UImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( UImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( UImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( UImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( UImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicExchange( UImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( UImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( UImageCubeArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( Image2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicExchange( Image2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicExchange( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicExchange( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	Int imageAtomicExchange( UImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicExchange( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicCompSwapU
	/**
	*name
	*	imageAtomicCompSwapU
	*/
	/**@{*/
	UInt imageAtomicCompSwap( Image1D const & image, Int const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( Image2D const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( Image3D const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( Image2DRect const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( ImageCube const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( ImageBuffer const & image, Int const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( Image1DArray const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( Image2DArray const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( ImageCubeArray const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( IImage1D const & image, Int const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( IImage2D const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( IImage3D const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( IImage2DRect const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( IImageCube const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( IImageBuffer const & image, Int const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( IImage1DArray const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( IImage2DArray const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( IImageCubeArray const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage1D const & image, Int const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2D const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage3D const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2DRect const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImageCube const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImageBuffer const & image, Int const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage1DArray const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2DArray const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImageCubeArray const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( Image2DMS const & image, IVec2 const & P, Int const & sample, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( Image2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( IImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & compare, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicCompSwapI
	/**
	*name
	*	imageAtomicCompSwapI
	*/
	/**@{*/
	Int imageAtomicCompSwap( Image1D const & image, Int const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( Image2D const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( Image3D const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( Image2DRect const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( ImageCube const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( ImageBuffer const & image, Int const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( Image1DArray const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( Image2DArray const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( ImageCubeArray const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage1D const & image, Int const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2D const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage3D const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2DRect const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImageCube const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImageBuffer const & image, Int const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage1DArray const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2DArray const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImageCubeArray const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( UImage1D const & image, Int const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( UImage2D const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( UImage3D const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( UImage2DRect const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( UImageCube const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( UImageBuffer const & image, Int const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( UImage1DArray const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( UImage2DArray const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( UImageCubeArray const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( Image2DMS const & image, IVec2 const & P, Int const & sample, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( Image2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( UImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & compare, Int const & data );
	/**@}*/
#pragma endregion
}

#endif
