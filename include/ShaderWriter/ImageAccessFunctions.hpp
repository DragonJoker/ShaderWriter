
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
	Int imageSize( Image1DRgba32 const & image );
	Int imageSize( Image1DRgba16 const & image );
	Int imageSize( Image1DRg32 const & image );
	Int imageSize( Image1DRg16 const & image );
	Int imageSize( Image1DR32 const & image );
	Int imageSize( Image1DR16 const & image );
	IVec2 imageSize( Image2DRgba32 const & image );
	IVec2 imageSize( Image2DRgba16 const & image );
	IVec2 imageSize( Image2DRg32 const & image );
	IVec2 imageSize( Image2DRg16 const & image );
	IVec2 imageSize( Image2DR32 const & image );
	IVec2 imageSize( Image2DR16 const & image );
	IVec3 imageSize( Image3DRgba32 const & image );
	IVec3 imageSize( Image3DRgba16 const & image );
	IVec3 imageSize( Image3DRg32 const & image );
	IVec3 imageSize( Image3DRg16 const & image );
	IVec3 imageSize( Image3DR32 const & image );
	IVec3 imageSize( Image3DR16 const & image );
	IVec2 imageSize( ImageCubeRgba32 const & image );
	IVec2 imageSize( ImageCubeRgba16 const & image );
	IVec2 imageSize( ImageCubeRg32 const & image );
	IVec2 imageSize( ImageCubeRg16 const & image );
	IVec2 imageSize( ImageCubeR32 const & image );
	IVec2 imageSize( ImageCubeR16 const & image );
	IVec3 imageSize( ImageCubeArrayRgba32 const & image );
	IVec3 imageSize( ImageCubeArrayRgba16 const & image );
	IVec3 imageSize( ImageCubeArrayRg32 const & image );
	IVec3 imageSize( ImageCubeArrayRg16 const & image );
	IVec3 imageSize( ImageCubeArrayR32 const & image );
	IVec3 imageSize( ImageCubeArrayR16 const & image );
	IVec2 imageSize( Image2DRectRgba32 const & image );
	IVec2 imageSize( Image2DRectRgba16 const & image );
	IVec2 imageSize( Image2DRectRg32 const & image );
	IVec2 imageSize( Image2DRectRg16 const & image );
	IVec2 imageSize( Image2DRectR32 const & image );
	IVec2 imageSize( Image2DRectR16 const & image );
	IVec2 imageSize( Image1DArrayRgba32 const & image );
	IVec2 imageSize( Image1DArrayRgba16 const & image );
	IVec2 imageSize( Image1DArrayRg32 const & image );
	IVec2 imageSize( Image1DArrayRg16 const & image );
	IVec2 imageSize( Image1DArrayR32 const & image );
	IVec2 imageSize( Image1DArrayR16 const & image );
	IVec3 imageSize( Image2DArrayRgba32 const & image );
	IVec3 imageSize( Image2DArrayRgba16 const & image );
	IVec3 imageSize( Image2DArrayRg32 const & image );
	IVec3 imageSize( Image2DArrayRg16 const & image );
	IVec3 imageSize( Image2DArrayR32 const & image );
	IVec3 imageSize( Image2DArrayR16 const & image );
	Int imageSize( ImageBufferRgba32 const & image );
	Int imageSize( ImageBufferRgba16 const & image );
	Int imageSize( ImageBufferRg32 const & image );
	Int imageSize( ImageBufferRg16 const & image );
	Int imageSize( ImageBufferR32 const & image );
	Int imageSize( ImageBufferR16 const & image );
	IVec2 imageSize( Image2DMSRgba32 const & image );
	IVec2 imageSize( Image2DMSRgba16 const & image );
	IVec2 imageSize( Image2DMSRg32 const & image );
	IVec2 imageSize( Image2DMSRg16 const & image );
	IVec2 imageSize( Image2DMSR32 const & image );
	IVec2 imageSize( Image2DMSR16 const & image );
	IVec3 imageSize( Image2DMSArrayRgba32 const & image );
	IVec3 imageSize( Image2DMSArrayRgba16 const & image );
	IVec3 imageSize( Image2DMSArrayRg32 const & image );
	IVec3 imageSize( Image2DMSArrayRg16 const & image );
	IVec3 imageSize( Image2DMSArrayR32 const & image );
	IVec3 imageSize( Image2DMSArrayR16 const & image );
	Int imageSize( IImage1DRgba32 const & image );
	Int imageSize( IImage1DRgba16 const & image );
	Int imageSize( IImage1DRgba8 const & image );
	Int imageSize( IImage1DRg32 const & image );
	Int imageSize( IImage1DRg16 const & image );
	Int imageSize( IImage1DRg8 const & image );
	Int imageSize( IImage1DR32 const & image );
	Int imageSize( IImage1DR16 const & image );
	Int imageSize( IImage1DR8 const & image );
	IVec2 imageSize( IImage2DRgba32 const & image );
	IVec2 imageSize( IImage2DRgba16 const & image );
	IVec2 imageSize( IImage2DRgba8 const & image );
	IVec2 imageSize( IImage2DRg32 const & image );
	IVec2 imageSize( IImage2DRg16 const & image );
	IVec2 imageSize( IImage2DRg8 const & image );
	IVec2 imageSize( IImage2DR32 const & image );
	IVec2 imageSize( IImage2DR16 const & image );
	IVec2 imageSize( IImage2DR8 const & image );
	IVec3 imageSize( IImage3DRgba32 const & image );
	IVec3 imageSize( IImage3DRgba16 const & image );
	IVec3 imageSize( IImage3DRgba8 const & image );
	IVec3 imageSize( IImage3DRg32 const & image );
	IVec3 imageSize( IImage3DRg16 const & image );
	IVec3 imageSize( IImage3DRg8 const & image );
	IVec3 imageSize( IImage3DR32 const & image );
	IVec3 imageSize( IImage3DR16 const & image );
	IVec3 imageSize( IImage3DR8 const & image );
	IVec2 imageSize( IImageCubeRgba32 const & image );
	IVec2 imageSize( IImageCubeRgba16 const & image );
	IVec2 imageSize( IImageCubeRgba8 const & image );
	IVec2 imageSize( IImageCubeRg32 const & image );
	IVec2 imageSize( IImageCubeRg16 const & image );
	IVec2 imageSize( IImageCubeRg8 const & image );
	IVec2 imageSize( IImageCubeR32 const & image );
	IVec2 imageSize( IImageCubeR16 const & image );
	IVec2 imageSize( IImageCubeR8 const & image );
	IVec3 imageSize( IImageCubeArrayRgba32 const & image );
	IVec3 imageSize( IImageCubeArrayRgba16 const & image );
	IVec3 imageSize( IImageCubeArrayRgba8 const & image );
	IVec3 imageSize( IImageCubeArrayRg32 const & image );
	IVec3 imageSize( IImageCubeArrayRg16 const & image );
	IVec3 imageSize( IImageCubeArrayRg8 const & image );
	IVec3 imageSize( IImageCubeArrayR32 const & image );
	IVec3 imageSize( IImageCubeArrayR16 const & image );
	IVec3 imageSize( IImageCubeArrayR8 const & image );
	IVec2 imageSize( IImage2DRectRgba32 const & image );
	IVec2 imageSize( IImage2DRectRgba16 const & image );
	IVec2 imageSize( IImage2DRectRgba8 const & image );
	IVec2 imageSize( IImage2DRectRg32 const & image );
	IVec2 imageSize( IImage2DRectRg16 const & image );
	IVec2 imageSize( IImage2DRectRg8 const & image );
	IVec2 imageSize( IImage2DRectR32 const & image );
	IVec2 imageSize( IImage2DRectR16 const & image );
	IVec2 imageSize( IImage2DRectR8 const & image );
	IVec2 imageSize( IImage1DArrayRgba32 const & image );
	IVec2 imageSize( IImage1DArrayRgba16 const & image );
	IVec2 imageSize( IImage1DArrayRgba8 const & image );
	IVec2 imageSize( IImage1DArrayRg32 const & image );
	IVec2 imageSize( IImage1DArrayRg16 const & image );
	IVec2 imageSize( IImage1DArrayRg8 const & image );
	IVec2 imageSize( IImage1DArrayR32 const & image );
	IVec2 imageSize( IImage1DArrayR16 const & image );
	IVec2 imageSize( IImage1DArrayR8 const & image );
	IVec3 imageSize( IImage2DArrayRgba32 const & image );
	IVec3 imageSize( IImage2DArrayRgba16 const & image );
	IVec3 imageSize( IImage2DArrayRgba8 const & image );
	IVec3 imageSize( IImage2DArrayRg32 const & image );
	IVec3 imageSize( IImage2DArrayRg16 const & image );
	IVec3 imageSize( IImage2DArrayRg8 const & image );
	IVec3 imageSize( IImage2DArrayR32 const & image );
	IVec3 imageSize( IImage2DArrayR16 const & image );
	IVec3 imageSize( IImage2DArrayR8 const & image );
	Int imageSize( IImageBufferRgba32 const & image );
	Int imageSize( IImageBufferRgba16 const & image );
	Int imageSize( IImageBufferRgba8 const & image );
	Int imageSize( IImageBufferRg32 const & image );
	Int imageSize( IImageBufferRg16 const & image );
	Int imageSize( IImageBufferRg8 const & image );
	Int imageSize( IImageBufferR32 const & image );
	Int imageSize( IImageBufferR16 const & image );
	Int imageSize( IImageBufferR8 const & image );
	IVec2 imageSize( IImage2DMSRgba32 const & image );
	IVec2 imageSize( IImage2DMSRgba16 const & image );
	IVec2 imageSize( IImage2DMSRgba8 const & image );
	IVec2 imageSize( IImage2DMSRg32 const & image );
	IVec2 imageSize( IImage2DMSRg16 const & image );
	IVec2 imageSize( IImage2DMSRg8 const & image );
	IVec2 imageSize( IImage2DMSR32 const & image );
	IVec2 imageSize( IImage2DMSR16 const & image );
	IVec2 imageSize( IImage2DMSR8 const & image );
	IVec3 imageSize( IImage2DMSArrayRgba32 const & image );
	IVec3 imageSize( IImage2DMSArrayRgba16 const & image );
	IVec3 imageSize( IImage2DMSArrayRgba8 const & image );
	IVec3 imageSize( IImage2DMSArrayRg32 const & image );
	IVec3 imageSize( IImage2DMSArrayRg16 const & image );
	IVec3 imageSize( IImage2DMSArrayRg8 const & image );
	IVec3 imageSize( IImage2DMSArrayR32 const & image );
	IVec3 imageSize( IImage2DMSArrayR16 const & image );
	IVec3 imageSize( IImage2DMSArrayR8 const & image );
	Int imageSize( UImage1DRgba32 const & image );
	Int imageSize( UImage1DRgba16 const & image );
	Int imageSize( UImage1DRgba8 const & image );
	Int imageSize( UImage1DRg32 const & image );
	Int imageSize( UImage1DRg16 const & image );
	Int imageSize( UImage1DRg8 const & image );
	Int imageSize( UImage1DR32 const & image );
	Int imageSize( UImage1DR16 const & image );
	Int imageSize( UImage1DR8 const & image );
	IVec2 imageSize( UImage2DRgba32 const & image );
	IVec2 imageSize( UImage2DRgba16 const & image );
	IVec2 imageSize( UImage2DRgba8 const & image );
	IVec2 imageSize( UImage2DRg32 const & image );
	IVec2 imageSize( UImage2DRg16 const & image );
	IVec2 imageSize( UImage2DRg8 const & image );
	IVec2 imageSize( UImage2DR32 const & image );
	IVec2 imageSize( UImage2DR16 const & image );
	IVec2 imageSize( UImage2DR8 const & image );
	IVec3 imageSize( UImage3DRgba32 const & image );
	IVec3 imageSize( UImage3DRgba16 const & image );
	IVec3 imageSize( UImage3DRgba8 const & image );
	IVec3 imageSize( UImage3DRg32 const & image );
	IVec3 imageSize( UImage3DRg16 const & image );
	IVec3 imageSize( UImage3DRg8 const & image );
	IVec3 imageSize( UImage3DR32 const & image );
	IVec3 imageSize( UImage3DR16 const & image );
	IVec3 imageSize( UImage3DR8 const & image );
	IVec2 imageSize( UImageCubeRgba32 const & image );
	IVec2 imageSize( UImageCubeRgba16 const & image );
	IVec2 imageSize( UImageCubeRgba8 const & image );
	IVec2 imageSize( UImageCubeRg32 const & image );
	IVec2 imageSize( UImageCubeRg16 const & image );
	IVec2 imageSize( UImageCubeRg8 const & image );
	IVec2 imageSize( UImageCubeR32 const & image );
	IVec2 imageSize( UImageCubeR16 const & image );
	IVec2 imageSize( UImageCubeR8 const & image );
	IVec3 imageSize( UImageCubeArrayRgba32 const & image );
	IVec3 imageSize( UImageCubeArrayRgba16 const & image );
	IVec3 imageSize( UImageCubeArrayRgba8 const & image );
	IVec3 imageSize( UImageCubeArrayRg32 const & image );
	IVec3 imageSize( UImageCubeArrayRg16 const & image );
	IVec3 imageSize( UImageCubeArrayRg8 const & image );
	IVec3 imageSize( UImageCubeArrayR32 const & image );
	IVec3 imageSize( UImageCubeArrayR16 const & image );
	IVec3 imageSize( UImageCubeArrayR8 const & image );
	IVec2 imageSize( UImage2DRectRgba32 const & image );
	IVec2 imageSize( UImage2DRectRgba16 const & image );
	IVec2 imageSize( UImage2DRectRgba8 const & image );
	IVec2 imageSize( UImage2DRectRg32 const & image );
	IVec2 imageSize( UImage2DRectRg16 const & image );
	IVec2 imageSize( UImage2DRectRg8 const & image );
	IVec2 imageSize( UImage2DRectR32 const & image );
	IVec2 imageSize( UImage2DRectR16 const & image );
	IVec2 imageSize( UImage2DRectR8 const & image );
	IVec2 imageSize( UImage1DArrayRgba32 const & image );
	IVec2 imageSize( UImage1DArrayRgba16 const & image );
	IVec2 imageSize( UImage1DArrayRgba8 const & image );
	IVec2 imageSize( UImage1DArrayRg32 const & image );
	IVec2 imageSize( UImage1DArrayRg16 const & image );
	IVec2 imageSize( UImage1DArrayRg8 const & image );
	IVec2 imageSize( UImage1DArrayR32 const & image );
	IVec2 imageSize( UImage1DArrayR16 const & image );
	IVec2 imageSize( UImage1DArrayR8 const & image );
	IVec3 imageSize( UImage2DArrayRgba32 const & image );
	IVec3 imageSize( UImage2DArrayRgba16 const & image );
	IVec3 imageSize( UImage2DArrayRgba8 const & image );
	IVec3 imageSize( UImage2DArrayRg32 const & image );
	IVec3 imageSize( UImage2DArrayRg16 const & image );
	IVec3 imageSize( UImage2DArrayRg8 const & image );
	IVec3 imageSize( UImage2DArrayR32 const & image );
	IVec3 imageSize( UImage2DArrayR16 const & image );
	IVec3 imageSize( UImage2DArrayR8 const & image );
	Int imageSize( UImageBufferRgba32 const & image );
	Int imageSize( UImageBufferRgba16 const & image );
	Int imageSize( UImageBufferRgba8 const & image );
	Int imageSize( UImageBufferRg32 const & image );
	Int imageSize( UImageBufferRg16 const & image );
	Int imageSize( UImageBufferRg8 const & image );
	Int imageSize( UImageBufferR32 const & image );
	Int imageSize( UImageBufferR16 const & image );
	Int imageSize( UImageBufferR8 const & image );
	IVec2 imageSize( UImage2DMSRgba32 const & image );
	IVec2 imageSize( UImage2DMSRgba16 const & image );
	IVec2 imageSize( UImage2DMSRgba8 const & image );
	IVec2 imageSize( UImage2DMSRg32 const & image );
	IVec2 imageSize( UImage2DMSRg16 const & image );
	IVec2 imageSize( UImage2DMSRg8 const & image );
	IVec2 imageSize( UImage2DMSR32 const & image );
	IVec2 imageSize( UImage2DMSR16 const & image );
	IVec2 imageSize( UImage2DMSR8 const & image );
	IVec3 imageSize( UImage2DMSArrayRgba32 const & image );
	IVec3 imageSize( UImage2DMSArrayRgba16 const & image );
	IVec3 imageSize( UImage2DMSArrayRgba8 const & image );
	IVec3 imageSize( UImage2DMSArrayRg32 const & image );
	IVec3 imageSize( UImage2DMSArrayRg16 const & image );
	IVec3 imageSize( UImage2DMSArrayRg8 const & image );
	IVec3 imageSize( UImage2DMSArrayR32 const & image );
	IVec3 imageSize( UImage2DMSArrayR16 const & image );
	IVec3 imageSize( UImage2DMSArrayR8 const & image );
	/**@}*/
#pragma endregion
#pragma region imageSamples
	/**
	*name
	*	imageSamples
	*/
	/**@{*/
	Int imageSamples( Image2DMSRgba32 const & image );
	Int imageSamples( Image2DMSRgba16 const & image );
	Int imageSamples( Image2DMSRg32 const & image );
	Int imageSamples( Image2DMSRg16 const & image );
	Int imageSamples( Image2DMSR32 const & image );
	Int imageSamples( Image2DMSR16 const & image );
	Int imageSamples( Image2DMSArrayRgba32 const & image );
	Int imageSamples( Image2DMSArrayRgba16 const & image );
	Int imageSamples( Image2DMSArrayRg32 const & image );
	Int imageSamples( Image2DMSArrayRg16 const & image );
	Int imageSamples( Image2DMSArrayR32 const & image );
	Int imageSamples( Image2DMSArrayR16 const & image );
	Int imageSamples( IImage2DMSRgba32 const & image );
	Int imageSamples( IImage2DMSRgba16 const & image );
	Int imageSamples( IImage2DMSRgba8 const & image );
	Int imageSamples( IImage2DMSRg32 const & image );
	Int imageSamples( IImage2DMSRg16 const & image );
	Int imageSamples( IImage2DMSRg8 const & image );
	Int imageSamples( IImage2DMSR32 const & image );
	Int imageSamples( IImage2DMSR16 const & image );
	Int imageSamples( IImage2DMSR8 const & image );
	Int imageSamples( IImage2DMSArrayRgba32 const & image );
	Int imageSamples( IImage2DMSArrayRgba16 const & image );
	Int imageSamples( IImage2DMSArrayRgba8 const & image );
	Int imageSamples( IImage2DMSArrayRg32 const & image );
	Int imageSamples( IImage2DMSArrayRg16 const & image );
	Int imageSamples( IImage2DMSArrayRg8 const & image );
	Int imageSamples( IImage2DMSArrayR32 const & image );
	Int imageSamples( IImage2DMSArrayR16 const & image );
	Int imageSamples( IImage2DMSArrayR8 const & image );
	Int imageSamples( UImage2DMSRgba32 const & image );
	Int imageSamples( UImage2DMSRgba16 const & image );
	Int imageSamples( UImage2DMSRgba8 const & image );
	Int imageSamples( UImage2DMSRg32 const & image );
	Int imageSamples( UImage2DMSRg16 const & image );
	Int imageSamples( UImage2DMSRg8 const & image );
	Int imageSamples( UImage2DMSR32 const & image );
	Int imageSamples( UImage2DMSR16 const & image );
	Int imageSamples( UImage2DMSR8 const & image );
	Int imageSamples( UImage2DMSArrayRgba32 const & image );
	Int imageSamples( UImage2DMSArrayRgba16 const & image );
	Int imageSamples( UImage2DMSArrayRgba8 const & image );
	Int imageSamples( UImage2DMSArrayRg32 const & image );
	Int imageSamples( UImage2DMSArrayRg16 const & image );
	Int imageSamples( UImage2DMSArrayRg8 const & image );
	Int imageSamples( UImage2DMSArrayR32 const & image );
	Int imageSamples( UImage2DMSArrayR16 const & image );
	Int imageSamples( UImage2DMSArrayR8 const & image );
	/**@}*/
#pragma endregion
#pragma region imageLoad
	/**
	*name
	*	imageLoad
	*/
	/**@{*/
	Vec4 imageLoad( Image1DRgba32 const & image, Int const & P );
	Vec4 imageLoad( Image1DRgba16 const & image, Int const & P );
	Vec2 imageLoad( Image1DRg32 const & image, Int const & P );
	Vec2 imageLoad( Image1DRg16 const & image, Int const & P );
	Float imageLoad( Image1DR32 const & image, Int const & P );
	Float imageLoad( Image1DR16 const & image, Int const & P );
	Vec4 imageLoad( Image2DRgba32 const & image, IVec2 const & P );
	Vec4 imageLoad( Image2DRgba16 const & image, IVec2 const & P );
	Vec2 imageLoad( Image2DRg32 const & image, IVec2 const & P );
	Vec2 imageLoad( Image2DRg16 const & image, IVec2 const & P );
	Float imageLoad( Image2DR32 const & image, IVec2 const & P );
	Float imageLoad( Image2DR16 const & image, IVec2 const & P );
	Vec4 imageLoad( Image3DRgba32 const & image, IVec3 const & P );
	Vec4 imageLoad( Image3DRgba16 const & image, IVec3 const & P );
	Vec2 imageLoad( Image3DRg32 const & image, IVec3 const & P );
	Vec2 imageLoad( Image3DRg16 const & image, IVec3 const & P );
	Float imageLoad( Image3DR32 const & image, IVec3 const & P );
	Float imageLoad( Image3DR16 const & image, IVec3 const & P );
	Vec4 imageLoad( Image2DRectRgba32 const & image, IVec2 const & P );
	Vec4 imageLoad( Image2DRectRgba16 const & image, IVec2 const & P );
	Vec2 imageLoad( Image2DRectRg32 const & image, IVec2 const & P );
	Vec2 imageLoad( Image2DRectRg16 const & image, IVec2 const & P );
	Float imageLoad( Image2DRectR32 const & image, IVec2 const & P );
	Float imageLoad( Image2DRectR16 const & image, IVec2 const & P );
	Vec4 imageLoad( ImageCubeRgba32 const & image, IVec3 const & P );
	Vec4 imageLoad( ImageCubeRgba16 const & image, IVec3 const & P );
	Vec2 imageLoad( ImageCubeRg32 const & image, IVec3 const & P );
	Vec2 imageLoad( ImageCubeRg16 const & image, IVec3 const & P );
	Float imageLoad( ImageCubeR32 const & image, IVec3 const & P );
	Float imageLoad( ImageCubeR16 const & image, IVec3 const & P );
	Vec4 imageLoad( ImageBufferRgba32 const & image, Int const & P );
	Vec4 imageLoad( ImageBufferRgba16 const & image, Int const & P );
	Vec2 imageLoad( ImageBufferRg32 const & image, Int const & P );
	Vec2 imageLoad( ImageBufferRg16 const & image, Int const & P );
	Float imageLoad( ImageBufferR32 const & image, Int const & P );
	Float imageLoad( ImageBufferR16 const & image, Int const & P );
	Vec4 imageLoad( Image1DArrayRgba32 const & image, IVec2 const & P );
	Vec4 imageLoad( Image1DArrayRgba16 const & image, IVec2 const & P );
	Vec2 imageLoad( Image1DArrayRg32 const & image, IVec2 const & P );
	Vec2 imageLoad( Image1DArrayRg16 const & image, IVec2 const & P );
	Float imageLoad( Image1DArrayR32 const & image, IVec2 const & P );
	Float imageLoad( Image1DArrayR16 const & image, IVec2 const & P );
	Vec4 imageLoad( Image2DArrayRgba32 const & image, IVec3 const & P );
	Vec4 imageLoad( Image2DArrayRgba16 const & image, IVec3 const & P );
	Vec2 imageLoad( Image2DArrayRg32 const & image, IVec3 const & P );
	Vec2 imageLoad( Image2DArrayRg16 const & image, IVec3 const & P );
	Float imageLoad( Image2DArrayR32 const & image, IVec3 const & P );
	Float imageLoad( Image2DArrayR16 const & image, IVec3 const & P );
	Vec4 imageLoad( ImageCubeArrayRgba32 const & image, IVec3 const & P );
	Vec4 imageLoad( ImageCubeArrayRgba16 const & image, IVec3 const & P );
	Vec2 imageLoad( ImageCubeArrayRg32 const & image, IVec3 const & P );
	Vec2 imageLoad( ImageCubeArrayRg16 const & image, IVec3 const & P );
	Float imageLoad( ImageCubeArrayR32 const & image, IVec3 const & P );
	Float imageLoad( ImageCubeArrayR16 const & image, IVec3 const & P );
	IVec4 imageLoad( IImage1DRgba32 const & image, Int const & P );
	IVec4 imageLoad( IImage1DRgba16 const & image, Int const & P );
	IVec4 imageLoad( IImage1DRgba8 const & image, Int const & P );
	IVec2 imageLoad( IImage1DRg32 const & image, Int const & P );
	IVec2 imageLoad( IImage1DRg16 const & image, Int const & P );
	IVec2 imageLoad( IImage1DRg8 const & image, Int const & P );
	Int imageLoad( IImage1DR32 const & image, Int const & P );
	Int imageLoad( IImage1DR16 const & image, Int const & P );
	Int imageLoad( IImage1DR8 const & image, Int const & P );
	IVec4 imageLoad( IImage2DRgba32 const & image, IVec2 const & P );
	IVec4 imageLoad( IImage2DRgba16 const & image, IVec2 const & P );
	IVec4 imageLoad( IImage2DRgba8 const & image, IVec2 const & P );
	IVec2 imageLoad( IImage2DRg32 const & image, IVec2 const & P );
	IVec2 imageLoad( IImage2DRg16 const & image, IVec2 const & P );
	IVec2 imageLoad( IImage2DRg8 const & image, IVec2 const & P );
	Int imageLoad( IImage2DR32 const & image, IVec2 const & P );
	Int imageLoad( IImage2DR16 const & image, IVec2 const & P );
	Int imageLoad( IImage2DR8 const & image, IVec2 const & P );
	IVec4 imageLoad( IImage3DRgba32 const & image, IVec3 const & P );
	IVec4 imageLoad( IImage3DRgba16 const & image, IVec3 const & P );
	IVec4 imageLoad( IImage3DRgba8 const & image, IVec3 const & P );
	IVec2 imageLoad( IImage3DRg32 const & image, IVec3 const & P );
	IVec2 imageLoad( IImage3DRg16 const & image, IVec3 const & P );
	IVec2 imageLoad( IImage3DRg8 const & image, IVec3 const & P );
	Int imageLoad( IImage3DR32 const & image, IVec3 const & P );
	Int imageLoad( IImage3DR16 const & image, IVec3 const & P );
	Int imageLoad( IImage3DR8 const & image, IVec3 const & P );
	IVec4 imageLoad( IImage2DRectRgba32 const & image, IVec2 const & P );
	IVec4 imageLoad( IImage2DRectRgba16 const & image, IVec2 const & P );
	IVec4 imageLoad( IImage2DRectRgba8 const & image, IVec2 const & P );
	IVec2 imageLoad( IImage2DRectRg32 const & image, IVec2 const & P );
	IVec2 imageLoad( IImage2DRectRg16 const & image, IVec2 const & P );
	IVec2 imageLoad( IImage2DRectRg8 const & image, IVec2 const & P );
	Int imageLoad( IImage2DRectR32 const & image, IVec2 const & P );
	Int imageLoad( IImage2DRectR16 const & image, IVec2 const & P );
	Int imageLoad( IImage2DRectR8 const & image, IVec2 const & P );
	IVec4 imageLoad( IImageCubeRgba32 const & image, IVec3 const & P );
	IVec4 imageLoad( IImageCubeRgba16 const & image, IVec3 const & P );
	IVec4 imageLoad( IImageCubeRgba8 const & image, IVec3 const & P );
	IVec2 imageLoad( IImageCubeRg32 const & image, IVec3 const & P );
	IVec2 imageLoad( IImageCubeRg16 const & image, IVec3 const & P );
	IVec2 imageLoad( IImageCubeRg8 const & image, IVec3 const & P );
	Int imageLoad( IImageCubeR32 const & image, IVec3 const & P );
	Int imageLoad( IImageCubeR16 const & image, IVec3 const & P );
	Int imageLoad( IImageCubeR8 const & image, IVec3 const & P );
	IVec4 imageLoad( IImageBufferRgba32 const & image, Int const & P );
	IVec4 imageLoad( IImageBufferRgba16 const & image, Int const & P );
	IVec4 imageLoad( IImageBufferRgba8 const & image, Int const & P );
	IVec2 imageLoad( IImageBufferRg32 const & image, Int const & P );
	IVec2 imageLoad( IImageBufferRg16 const & image, Int const & P );
	IVec2 imageLoad( IImageBufferRg8 const & image, Int const & P );
	Int imageLoad( IImageBufferR32 const & image, Int const & P );
	Int imageLoad( IImageBufferR16 const & image, Int const & P );
	Int imageLoad( IImageBufferR8 const & image, Int const & P );
	IVec4 imageLoad( IImage1DArrayRgba32 const & image, IVec2 const & P );
	IVec4 imageLoad( IImage1DArrayRgba16 const & image, IVec2 const & P );
	IVec4 imageLoad( IImage1DArrayRgba8 const & image, IVec2 const & P );
	IVec2 imageLoad( IImage1DArrayRg32 const & image, IVec2 const & P );
	IVec2 imageLoad( IImage1DArrayRg16 const & image, IVec2 const & P );
	IVec2 imageLoad( IImage1DArrayRg8 const & image, IVec2 const & P );
	Int imageLoad( IImage1DArrayR32 const & image, IVec2 const & P );
	Int imageLoad( IImage1DArrayR16 const & image, IVec2 const & P );
	Int imageLoad( IImage1DArrayR8 const & image, IVec2 const & P );
	IVec4 imageLoad( IImage2DArrayRgba32 const & image, IVec3 const & P );
	IVec4 imageLoad( IImage2DArrayRgba16 const & image, IVec3 const & P );
	IVec4 imageLoad( IImage2DArrayRgba8 const & image, IVec3 const & P );
	IVec2 imageLoad( IImage2DArrayRg32 const & image, IVec3 const & P );
	IVec2 imageLoad( IImage2DArrayRg16 const & image, IVec3 const & P );
	IVec2 imageLoad( IImage2DArrayRg8 const & image, IVec3 const & P );
	Int imageLoad( IImage2DArrayR32 const & image, IVec3 const & P );
	Int imageLoad( IImage2DArrayR16 const & image, IVec3 const & P );
	Int imageLoad( IImage2DArrayR8 const & image, IVec3 const & P );
	IVec4 imageLoad( IImageCubeArrayRgba32 const & image, IVec3 const & P );
	IVec4 imageLoad( IImageCubeArrayRgba16 const & image, IVec3 const & P );
	IVec4 imageLoad( IImageCubeArrayRgba8 const & image, IVec3 const & P );
	IVec2 imageLoad( IImageCubeArrayRg32 const & image, IVec3 const & P );
	IVec2 imageLoad( IImageCubeArrayRg16 const & image, IVec3 const & P );
	IVec2 imageLoad( IImageCubeArrayRg8 const & image, IVec3 const & P );
	Int imageLoad( IImageCubeArrayR32 const & image, IVec3 const & P );
	Int imageLoad( IImageCubeArrayR16 const & image, IVec3 const & P );
	Int imageLoad( IImageCubeArrayR8 const & image, IVec3 const & P );
	UVec4 imageLoad( UImage1DRgba32 const & image, Int const & P );
	UVec4 imageLoad( UImage1DRgba16 const & image, Int const & P );
	UVec4 imageLoad( UImage1DRgba8 const & image, Int const & P );
	UVec2 imageLoad( UImage1DRg32 const & image, Int const & P );
	UVec2 imageLoad( UImage1DRg16 const & image, Int const & P );
	UVec2 imageLoad( UImage1DRg8 const & image, Int const & P );
	UInt imageLoad( UImage1DR32 const & image, Int const & P );
	UInt imageLoad( UImage1DR16 const & image, Int const & P );
	UInt imageLoad( UImage1DR8 const & image, Int const & P );
	UVec4 imageLoad( UImage2DRgba32 const & image, IVec2 const & P );
	UVec4 imageLoad( UImage2DRgba16 const & image, IVec2 const & P );
	UVec4 imageLoad( UImage2DRgba8 const & image, IVec2 const & P );
	UVec2 imageLoad( UImage2DRg32 const & image, IVec2 const & P );
	UVec2 imageLoad( UImage2DRg16 const & image, IVec2 const & P );
	UVec2 imageLoad( UImage2DRg8 const & image, IVec2 const & P );
	UInt imageLoad( UImage2DR32 const & image, IVec2 const & P );
	UInt imageLoad( UImage2DR16 const & image, IVec2 const & P );
	UInt imageLoad( UImage2DR8 const & image, IVec2 const & P );
	UVec4 imageLoad( UImage3DRgba32 const & image, IVec3 const & P );
	UVec4 imageLoad( UImage3DRgba16 const & image, IVec3 const & P );
	UVec4 imageLoad( UImage3DRgba8 const & image, IVec3 const & P );
	UVec2 imageLoad( UImage3DRg32 const & image, IVec3 const & P );
	UVec2 imageLoad( UImage3DRg16 const & image, IVec3 const & P );
	UVec2 imageLoad( UImage3DRg8 const & image, IVec3 const & P );
	UInt imageLoad( UImage3DR32 const & image, IVec3 const & P );
	UInt imageLoad( UImage3DR16 const & image, IVec3 const & P );
	UInt imageLoad( UImage3DR8 const & image, IVec3 const & P );
	UVec4 imageLoad( UImage2DRectRgba32 const & image, IVec2 const & P );
	UVec4 imageLoad( UImage2DRectRgba16 const & image, IVec2 const & P );
	UVec4 imageLoad( UImage2DRectRgba8 const & image, IVec2 const & P );
	UVec2 imageLoad( UImage2DRectRg32 const & image, IVec2 const & P );
	UVec2 imageLoad( UImage2DRectRg16 const & image, IVec2 const & P );
	UVec2 imageLoad( UImage2DRectRg8 const & image, IVec2 const & P );
	UInt imageLoad( UImage2DRectR32 const & image, IVec2 const & P );
	UInt imageLoad( UImage2DRectR16 const & image, IVec2 const & P );
	UInt imageLoad( UImage2DRectR8 const & image, IVec2 const & P );
	UVec4 imageLoad( UImageCubeRgba32 const & image, IVec3 const & P );
	UVec4 imageLoad( UImageCubeRgba16 const & image, IVec3 const & P );
	UVec4 imageLoad( UImageCubeRgba8 const & image, IVec3 const & P );
	UVec2 imageLoad( UImageCubeRg32 const & image, IVec3 const & P );
	UVec2 imageLoad( UImageCubeRg16 const & image, IVec3 const & P );
	UVec2 imageLoad( UImageCubeRg8 const & image, IVec3 const & P );
	UInt imageLoad( UImageCubeR32 const & image, IVec3 const & P );
	UInt imageLoad( UImageCubeR16 const & image, IVec3 const & P );
	UInt imageLoad( UImageCubeR8 const & image, IVec3 const & P );
	UVec4 imageLoad( UImageBufferRgba32 const & image, Int const & P );
	UVec4 imageLoad( UImageBufferRgba16 const & image, Int const & P );
	UVec4 imageLoad( UImageBufferRgba8 const & image, Int const & P );
	UVec2 imageLoad( UImageBufferRg32 const & image, Int const & P );
	UVec2 imageLoad( UImageBufferRg16 const & image, Int const & P );
	UVec2 imageLoad( UImageBufferRg8 const & image, Int const & P );
	UInt imageLoad( UImageBufferR32 const & image, Int const & P );
	UInt imageLoad( UImageBufferR16 const & image, Int const & P );
	UInt imageLoad( UImageBufferR8 const & image, Int const & P );
	UVec4 imageLoad( UImage1DArrayRgba32 const & image, IVec2 const & P );
	UVec4 imageLoad( UImage1DArrayRgba16 const & image, IVec2 const & P );
	UVec4 imageLoad( UImage1DArrayRgba8 const & image, IVec2 const & P );
	UVec2 imageLoad( UImage1DArrayRg32 const & image, IVec2 const & P );
	UVec2 imageLoad( UImage1DArrayRg16 const & image, IVec2 const & P );
	UVec2 imageLoad( UImage1DArrayRg8 const & image, IVec2 const & P );
	UInt imageLoad( UImage1DArrayR32 const & image, IVec2 const & P );
	UInt imageLoad( UImage1DArrayR16 const & image, IVec2 const & P );
	UInt imageLoad( UImage1DArrayR8 const & image, IVec2 const & P );
	UVec4 imageLoad( UImage2DArrayRgba32 const & image, IVec3 const & P );
	UVec4 imageLoad( UImage2DArrayRgba16 const & image, IVec3 const & P );
	UVec4 imageLoad( UImage2DArrayRgba8 const & image, IVec3 const & P );
	UVec2 imageLoad( UImage2DArrayRg32 const & image, IVec3 const & P );
	UVec2 imageLoad( UImage2DArrayRg16 const & image, IVec3 const & P );
	UVec2 imageLoad( UImage2DArrayRg8 const & image, IVec3 const & P );
	UInt imageLoad( UImage2DArrayR32 const & image, IVec3 const & P );
	UInt imageLoad( UImage2DArrayR16 const & image, IVec3 const & P );
	UInt imageLoad( UImage2DArrayR8 const & image, IVec3 const & P );
	UVec4 imageLoad( UImageCubeArrayRgba32 const & image, IVec3 const & P );
	UVec4 imageLoad( UImageCubeArrayRgba16 const & image, IVec3 const & P );
	UVec4 imageLoad( UImageCubeArrayRgba8 const & image, IVec3 const & P );
	UVec2 imageLoad( UImageCubeArrayRg32 const & image, IVec3 const & P );
	UVec2 imageLoad( UImageCubeArrayRg16 const & image, IVec3 const & P );
	UVec2 imageLoad( UImageCubeArrayRg8 const & image, IVec3 const & P );
	UInt imageLoad( UImageCubeArrayR32 const & image, IVec3 const & P );
	UInt imageLoad( UImageCubeArrayR16 const & image, IVec3 const & P );
	UInt imageLoad( UImageCubeArrayR8 const & image, IVec3 const & P );
	Vec4 imageLoad( Image2DMSRgba32 const & image, IVec2 const & P, Int const & sample );
	Vec4 imageLoad( Image2DMSRgba16 const & image, IVec2 const & P, Int const & sample );
	Vec2 imageLoad( Image2DMSRg32 const & image, IVec2 const & P, Int const & sample );
	Vec2 imageLoad( Image2DMSRg16 const & image, IVec2 const & P, Int const & sample );
	Float imageLoad( Image2DMSR32 const & image, IVec2 const & P, Int const & sample );
	Float imageLoad( Image2DMSR16 const & image, IVec2 const & P, Int const & sample );
	Vec4 imageLoad( Image2DMSArrayRgba32 const & image, IVec3 const & P, Int const & sample );
	Vec4 imageLoad( Image2DMSArrayRgba16 const & image, IVec3 const & P, Int const & sample );
	Vec2 imageLoad( Image2DMSArrayRg32 const & image, IVec3 const & P, Int const & sample );
	Vec2 imageLoad( Image2DMSArrayRg16 const & image, IVec3 const & P, Int const & sample );
	Float imageLoad( Image2DMSArrayR32 const & image, IVec3 const & P, Int const & sample );
	Float imageLoad( Image2DMSArrayR16 const & image, IVec3 const & P, Int const & sample );
	IVec4 imageLoad( IImage2DMSRgba32 const & image, IVec2 const & P, Int const & sample );
	IVec4 imageLoad( IImage2DMSRgba16 const & image, IVec2 const & P, Int const & sample );
	IVec4 imageLoad( IImage2DMSRgba8 const & image, IVec2 const & P, Int const & sample );
	IVec2 imageLoad( IImage2DMSRg32 const & image, IVec2 const & P, Int const & sample );
	IVec2 imageLoad( IImage2DMSRg16 const & image, IVec2 const & P, Int const & sample );
	IVec2 imageLoad( IImage2DMSRg8 const & image, IVec2 const & P, Int const & sample );
	Int imageLoad( IImage2DMSR32 const & image, IVec2 const & P, Int const & sample );
	Int imageLoad( IImage2DMSR16 const & image, IVec2 const & P, Int const & sample );
	Int imageLoad( IImage2DMSR8 const & image, IVec2 const & P, Int const & sample );
	IVec4 imageLoad( IImage2DMSArrayRgba32 const & image, IVec3 const & P, Int const & sample );
	IVec4 imageLoad( IImage2DMSArrayRgba16 const & image, IVec3 const & P, Int const & sample );
	IVec4 imageLoad( IImage2DMSArrayRgba8 const & image, IVec3 const & P, Int const & sample );
	IVec2 imageLoad( IImage2DMSArrayRg32 const & image, IVec3 const & P, Int const & sample );
	IVec2 imageLoad( IImage2DMSArrayRg16 const & image, IVec3 const & P, Int const & sample );
	IVec2 imageLoad( IImage2DMSArrayRg8 const & image, IVec3 const & P, Int const & sample );
	Int imageLoad( IImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample );
	Int imageLoad( IImage2DMSArrayR16 const & image, IVec3 const & P, Int const & sample );
	Int imageLoad( IImage2DMSArrayR8 const & image, IVec3 const & P, Int const & sample );
	UVec4 imageLoad( UImage2DMSRgba32 const & image, IVec2 const & P, Int const & sample );
	UVec4 imageLoad( UImage2DMSRgba16 const & image, IVec2 const & P, Int const & sample );
	UVec4 imageLoad( UImage2DMSRgba8 const & image, IVec2 const & P, Int const & sample );
	UVec2 imageLoad( UImage2DMSRg32 const & image, IVec2 const & P, Int const & sample );
	UVec2 imageLoad( UImage2DMSRg16 const & image, IVec2 const & P, Int const & sample );
	UVec2 imageLoad( UImage2DMSRg8 const & image, IVec2 const & P, Int const & sample );
	UInt imageLoad( UImage2DMSR32 const & image, IVec2 const & P, Int const & sample );
	UInt imageLoad( UImage2DMSR16 const & image, IVec2 const & P, Int const & sample );
	UInt imageLoad( UImage2DMSR8 const & image, IVec2 const & P, Int const & sample );
	UVec4 imageLoad( UImage2DMSArrayRgba32 const & image, IVec3 const & P, Int const & sample );
	UVec4 imageLoad( UImage2DMSArrayRgba16 const & image, IVec3 const & P, Int const & sample );
	UVec4 imageLoad( UImage2DMSArrayRgba8 const & image, IVec3 const & P, Int const & sample );
	UVec2 imageLoad( UImage2DMSArrayRg32 const & image, IVec3 const & P, Int const & sample );
	UVec2 imageLoad( UImage2DMSArrayRg16 const & image, IVec3 const & P, Int const & sample );
	UVec2 imageLoad( UImage2DMSArrayRg8 const & image, IVec3 const & P, Int const & sample );
	UInt imageLoad( UImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample );
	UInt imageLoad( UImage2DMSArrayR16 const & image, IVec3 const & P, Int const & sample );
	UInt imageLoad( UImage2DMSArrayR8 const & image, IVec3 const & P, Int const & sample );
	/**@}*/
#pragma endregion
#pragma region imageAtomicAdd
	/**
	*name
	*	imageAtomicAdd
	*/
	/**@{*/
	UInt imageAtomicAdd( UImage1DR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicAdd( UImage2DR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( UImage3DR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( UImage2DRectR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( UImageCubeR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( UImageBufferR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicAdd( UImage1DArrayR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAdd( UImage2DArrayR32 const & image,  IVec3 const & P, UInt const & data );
	UInt imageAtomicAdd( UImageCubeArrayR32 const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicAdd( IImage1DR32 const & image, Int const & P, Int const & data );
	Int imageAtomicAdd( IImage2DR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( IImage3DR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( IImage2DRectR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( IImageCubeR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( IImageBufferR32 const & image, Int const & P, Int const & data );
	Int imageAtomicAdd( IImage1DArrayR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAdd( IImage2DArrayR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAdd( IImageCubeArrayR32 const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicAdd( UImage2DMSR32 const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAdd( UImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicAdd( IImage2DMSR32 const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicAdd( IImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicMin
	/**
	*name
	*	imageAtomicMin
	*/
	/**@{*/
	UInt imageAtomicMin( UImage1DR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicMin( UImage2DR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( UImage3DR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( UImage2DRectR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( UImageCubeR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( UImageBufferR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicMin( UImage1DArrayR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMin( UImage2DArrayR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMin( UImageCubeArrayR32 const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicMin( IImage1DR32 const & image, Int const & P, Int const & data );
	Int imageAtomicMin( IImage2DR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( IImage3DR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( IImage2DRectR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( IImageCubeR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( IImageBufferR32 const & image, Int const & P, Int const & data );
	Int imageAtomicMin( IImage1DArrayR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMin( IImage2DArrayR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMin( IImageCubeArrayR32 const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicMin( UImage2DMSR32 const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMin( UImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicMin( IImage2DMSR32 const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicMin( IImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicMax
	/**
	*name
	*	imageAtomicMax
	*/
	/**@{*/
	UInt imageAtomicMax( UImage1DR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicMax( UImage2DR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( UImage3DR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( UImage2DRectR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( UImageCubeR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( UImageBufferR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicMax( UImage1DArrayR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicMax( UImage2DArrayR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicMax( UImageCubeArrayR32 const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicMax( IImage1DR32 const & image, Int const & P, Int const & data );
	Int imageAtomicMax( IImage2DR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( IImage3DR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( IImage2DRectR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( IImageCubeR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( IImageBufferR32 const & image, Int const & P, Int const & data );
	Int imageAtomicMax( IImage1DArrayR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicMax( IImage2DArrayR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicMax( IImageCubeArrayR32 const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicMax( UImage2DMSR32 const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicMax( UImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicMax( IImage2DMSR32 const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicMax( IImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicAnd
	/**
	*name
	*	imageAtomicAnd
	*/
	/**@{*/
	UInt imageAtomicAnd( UImage1DR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicAnd( UImage2DR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( UImage3DR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( UImage2DRectR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( UImageCubeR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( UImageBufferR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicAnd( UImage1DArrayR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicAnd( UImage2DArrayR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicAnd( UImageCubeArrayR32 const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicAnd( IImage1DR32 const & image, Int const & P, Int const & data );
	Int imageAtomicAnd( IImage2DR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( IImage3DR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( IImage2DRectR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( IImageCubeR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( IImageBufferR32 const & image, Int const & P, Int const & data );
	Int imageAtomicAnd( IImage1DArrayR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicAnd( IImage2DArrayR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicAnd( IImageCubeArrayR32 const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicAnd( UImage2DMSR32 const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicAnd( UImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicAnd( IImage2DMSR32 const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicAnd( IImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicOr
	/**
	*name
	*	imageAtomicOr
	*/
	/**@{*/
	UInt imageAtomicOr( UImage1DR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicOr( UImage2DR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( UImage3DR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( UImage2DRectR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( UImageCubeR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( UImageBufferR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicOr( UImage1DArrayR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicOr( UImage2DArrayR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicOr( UImageCubeArrayR32 const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicOr( IImage1DR32 const & image, Int const & P, Int const & data );
	Int imageAtomicOr( IImage2DR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( IImage3DR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( IImage2DRectR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( IImageCubeR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( IImageBufferR32 const & image, Int const & P, Int const & data );
	Int imageAtomicOr( IImage1DArrayR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicOr( IImage2DArrayR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicOr( IImageCubeArrayR32 const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicOr( UImage2DMSR32 const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicOr( UImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicOr( IImage2DMSR32 const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicOr( IImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicXor
	/**
	*name
	*	imageAtomicXor
	*/
	/**@{*/
	UInt imageAtomicXor( UImage1DR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicXor( UImage2DR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( UImage3DR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( UImage2DRectR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( UImageCubeR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( UImageBufferR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicXor( UImage1DArrayR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicXor( UImage2DArrayR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicXor( UImageCubeArrayR32 const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicXor( IImage1DR32 const & image, Int const & P, Int const & data );
	Int imageAtomicXor( IImage2DR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( IImage3DR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( IImage2DRectR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( IImageCubeR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( IImageBufferR32 const & image, Int const & P, Int const & data );
	Int imageAtomicXor( IImage1DArrayR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicXor( IImage2DArrayR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicXor( IImageCubeArrayR32 const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicXor( UImage2DMSR32 const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicXor( UImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicXor( IImage2DMSR32 const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicXor( IImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicExchange
	/**
	*name
	*	imageAtomicExchange
	*/
	/**@{*/
	UInt imageAtomicExchange( UImage1DR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicExchange( UImage2DR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( UImage3DR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( UImage2DRectR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( UImageCubeR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( UImageBufferR32 const & image, Int const & P, UInt const & data );
	UInt imageAtomicExchange( UImage1DArrayR32 const & image, IVec2 const & P, UInt const & data );
	UInt imageAtomicExchange( UImage2DArrayR32 const & image, IVec3 const & P, UInt const & data );
	UInt imageAtomicExchange( UImageCubeArrayR32 const & image, IVec3 const & P, UInt const & data );
	Int imageAtomicExchange( IImage1DR32 const & image, Int const & P, Int const & data );
	Int imageAtomicExchange( IImage2DR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( IImage3DR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( IImage2DRectR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( IImageCubeR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( IImageBufferR32 const & image, Int const & P, Int const & data );
	Int imageAtomicExchange( IImage1DArrayR32 const & image, IVec2 const & P, Int const & data );
	Int imageAtomicExchange( IImage2DArrayR32 const & image, IVec3 const & P, Int const & data );
	Int imageAtomicExchange( IImageCubeArrayR32 const & image, IVec3 const & P, Int const & data );
	UInt imageAtomicExchange( UImage2DMSR32 const & image, IVec2 const & P, Int const & sample, UInt const & data );
	UInt imageAtomicExchange( UImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, UInt const & data );
	Int imageAtomicExchange( IImage2DMSR32 const & image, IVec2 const & P, Int const & sample, Int const & data );
	Int imageAtomicExchange( IImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, Int const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicCompSwap
	/**
	*name
	*	imageAtomicCompSwap
	*/
	/**@{*/
	UInt imageAtomicCompSwap( UImage1DR32 const & image, Int const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2DR32 const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage3DR32 const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2DRectR32 const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImageCubeR32 const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImageBufferR32 const & image, Int const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage1DArrayR32 const & image, IVec2 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2DArrayR32 const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImageCubeArrayR32 const & image, IVec3 const & P, UInt const & compare, UInt const & data );
	Int imageAtomicCompSwap( IImage1DR32 const & image, Int const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2DR32 const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage3DR32 const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2DRectR32 const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImageCubeR32 const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImageBufferR32 const & image, Int const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage1DArrayR32 const & image, IVec2 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2DArrayR32 const & image, IVec3 const & P, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImageCubeArrayR32 const & image, IVec3 const & P, Int const & compare, Int const & data );
	UInt imageAtomicCompSwap( UImage2DMSR32 const & image, IVec2 const & P, Int const & sample, UInt const & compare, UInt const & data );
	UInt imageAtomicCompSwap( UImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, UInt const & compare, UInt const & data );
	Int imageAtomicCompSwap( IImage2DMSR32 const & image, IVec2 const & P, Int const & sample, Int const & compare, Int const & data );
	Int imageAtomicCompSwap( IImage2DMSArrayR32 const & image, IVec3 const & P, Int const & sample, Int const & compare, Int const & data );
	/**@}*/
#pragma endregion
}

#endif
