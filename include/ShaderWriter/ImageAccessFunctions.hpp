
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
#pragma region imageAtomicAdd
	/**
	*name
	*	imageAtomicAdd
	*/
	/**@{*/
	UInt imageAtomicAdd( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicAdd( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicAdd( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( UImage2DArray const & image,  IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicAdd( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicAdd( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicAdd( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicAdd( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAdd( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicAdd( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicAdd( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicMin
	/**
	*name
	*	imageAtomicMin
	*/
	/**@{*/
	UInt imageAtomicMin( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicMin( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicMin( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicMin( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicMin( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicMin( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicMin( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMin( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicMin( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicMin( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicMax
	/**
	*name
	*	imageAtomicMax
	*/
	/**@{*/
	UInt imageAtomicMax( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicMax( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicMax( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicMax( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicMax( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicMax( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicMax( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMax( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicMax( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicMax( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicAnd
	/**
	*name
	*	imageAtomicAnd
	*/
	/**@{*/
	UInt imageAtomicAnd( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicAnd( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicAnd( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicAnd( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicAnd( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicAnd( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicAnd( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAnd( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicAnd( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicAnd( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicOr
	/**
	*name
	*	imageAtomicOr
	*/
	/**@{*/
	UInt imageAtomicOr( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicOr( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicOr( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicOr( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicOr( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicOr( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicOr( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicOr( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicOr( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicOr( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicXor
	/**
	*name
	*	imageAtomicXor
	*/
	/**@{*/
	UInt imageAtomicXor( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicXor( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicXor( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicXor( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicXor( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicXor( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicXor( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicXor( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicXor( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicXor( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicExchange
	/**
	*name
	*	imageAtomicExchange
	*/
	/**@{*/
	UInt imageAtomicExchange( UImage1D const & image, Int const & P, UInt const & data );
	UInt imageAtomicExchange( UImage2D const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( UImage3D const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( UImage2DRect const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( UImageCube const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( UImageBuffer const & image, Int const & P, UInt const & data );
	UInt imageAtomicExchange( UImage1DArray const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( UImage2DArray const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( UImageCubeArray const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicExchange( IImage1D const & image, Int const & P, Int const & data );
	Int imageAtomicExchange( IImage2D const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( IImage3D const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( IImage2DRect const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( IImageCube const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( IImageBuffer const & image, Int const & P, Int const & data );
	Int imageAtomicExchange( IImage1DArray const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( IImage2DArray const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( IImageCubeArray const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicExchange( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicExchange( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicExchange( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicExchange( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicCompSwap
	/**
	*name
	*	imageAtomicCompSwap
	*/
	/**@{*/
	UInt imageAtomicCompSwap( UImage1D const & image, Int const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2D const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage3D const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2DRect const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImageCube const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImageBuffer const & image, Int const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage1DArray const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2DArray const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImageCubeArray const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	Int imageAtomicCompSwap( IImage1D const & image, Int const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2D const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage3D const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2DRect const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImageCube const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImageBuffer const & image, Int const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage1DArray const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2DArray const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImageCubeArray const & image, IVec3 const & P, Int const & compare, Int const & data );
	UInt imageAtomicCompSwap( UImage2DMS const & image, IVec2 const & P, Int const & sample, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2DMSArray const & image, IVec3 const & P, Int const & sample, UInt const & compare, UInt const & data );
	Int imageAtomicCompSwap( IImage2DMS const & image, IVec2 const & P, Int const & sample, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2DMSArray const & image, IVec3 const & P, Int const & sample, Int const & compare, Int const & data );
	/**@}*/
#pragma endregion
}

#endif
