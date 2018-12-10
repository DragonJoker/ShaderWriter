
/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ImageAccessFunctions_H___
#define ___SDW_ImageAccessFunctions_H___
#pragma once

#include "ShaderWriter/BaseTypes/Bool.hpp"
#include "ShaderWriter/BaseTypes/Image.hpp"
#include "ShaderWriter/BaseTypes/SampledImage.hpp"
#include "ShaderWriter/BaseTypes/Sampler.hpp"
#include "ShaderWriter/CompositeTypes/Function.hpp"
#include "ShaderWriter/CompositeTypes/FunctionParam.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptional.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat2.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat2x3.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat2x4.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat3.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat3x2.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat3x4.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat4.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat4x2.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat4x3.hpp"

#include <ShaderAST/Expr/MakeImageAccess.hpp>

namespace sdw
{
#pragma region imageSize
	/**
	*name
	*	imageSize
	*/
	/**@{*/
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DRgba32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DRgba16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DRg32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DRg16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DR32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayR16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferRgba32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferRgba16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferRg32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferRg16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferR32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayR16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRgba32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRgba16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRgba8 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRg32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRg16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRg8 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DR32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DR16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DR8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRgba8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRg8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DR8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRgba8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRg8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DR8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRgba8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRg8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeR8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRgba8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRg8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayR8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRgba8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRg8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayR8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRgba8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRg8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayR8 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRgba32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRgba16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRgba8 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRg32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRg16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRg8 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferR32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferR16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferR8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRgba8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRg8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSR8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRgba8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRg8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayR8 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRgba32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRgba16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRgba8 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRg32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRg16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRg8 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DR32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DR16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DR8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRgba8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRg8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DR8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRgba8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRg8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DR8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRgba8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRg8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeR8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRgba8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRg8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayR8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRgba8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRg8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayR8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRgba8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRg8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayR8 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRgba32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRgba16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRgba8 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRg32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRg16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRg8 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferR32 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferR16 > const & image );
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferR8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRgba32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRgba16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRgba8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRg32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRg16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRg8 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSR32 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSR16 > const & image );
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSR8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRgba32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRgba16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRgba8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRg32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRg16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRg8 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayR32 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayR16 > const & image );
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayR8 > const & image );
	/**@}*/
#pragma endregion
#pragma region imageSamples
	/**
	*name
	*	imageSamples
	*/
	/**@{*/
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSRgba32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSRgba16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSRg32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSRg16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSR32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSR16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayRgba32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayRgba16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayRg32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayRg16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayR32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayR16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRgba32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRgba16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRgba8 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRg32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRg16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRg8 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSR32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSR16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSR8 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRgba32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRgba16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRgba8 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRg32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRg16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRg8 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayR32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayR16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayR8 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRgba32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRgba16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRgba8 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRg32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRg16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRg8 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSR32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSR16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSR8 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRgba32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRgba16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRgba8 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRg32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRg16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRg8 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayR32 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayR16 > const & image );
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayR8 > const & image );
	/**@}*/
#pragma endregion
#pragma region imageLoad
	/**
	*name
	*	imageLoad
	*/
	/**@{*/
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image1DRgba32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image1DRgba16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image1DRg32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image1DRg16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image1DR32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image1DR16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DRgba32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DRgba16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DRg32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DRg16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DR32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DR16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image3DRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image3DRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image3DRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image3DRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image3DR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image3DR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageCubeRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageCubeRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageCubeRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageCubeRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageCubeR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageBufferRgba32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageBufferRgba16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageBufferRg32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageBufferRg16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageBufferR32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageBufferR16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image1DArrayRgba32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image1DArrayRgba16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image1DArrayRg32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image1DArrayRg16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image1DArrayR16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DArrayRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DArrayRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DArrayRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DArrayRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DArrayR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageCubeArrayRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageCubeArrayRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageCubeArrayRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageCubeArrayRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageCubeArrayR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DRgba32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DRgba16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DRgba8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DRg32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DRg16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DRg8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DR32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DR16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DR8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DRgba32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DRgba16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DRgba8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DRg32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DRg16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DRg8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DR32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DR16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DR8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage3DRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage3DRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage3DRgba8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage3DRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage3DRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage3DRg8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage3DR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage3DR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage3DR8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeRgba8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeRg8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeR8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageBufferRgba32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageBufferRgba16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageBufferRgba8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageBufferRg32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageBufferRg16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageBufferRg8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageBufferR32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageBufferR16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageBufferR8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DArrayRgba32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DArrayRgba16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DArrayRgba8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DArrayRg32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DArrayRg16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DArrayRg8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DArrayR16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DArrayR8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DArrayRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DArrayRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DArrayRgba8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DArrayRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DArrayRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DArrayRg8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DArrayR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DArrayR8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeArrayRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeArrayRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeArrayRgba8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeArrayRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeArrayRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeArrayRg8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeArrayR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeArrayR8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DRgba32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DRgba16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DRgba8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DRg32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DRg16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DRg8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DR32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DR16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DR8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DRgba32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DRgba16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DRgba8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DRg32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DRg16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DRg8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DR32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DR16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DR8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage3DRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage3DRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage3DRgba8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage3DRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage3DRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage3DRg8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage3DR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage3DR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage3DR8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeRgba8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeRg8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeR8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageBufferRgba32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageBufferRgba16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageBufferRgba8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageBufferRg32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageBufferRg16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageBufferRg8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageBufferR32 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageBufferR16 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageBufferR8 > const & image, MaybeOptional< Int > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DArrayRgba32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DArrayRgba16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DArrayRgba8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DArrayRg32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DArrayRg16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DArrayRg8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DArrayR16 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DArrayR8 > const & image, MaybeOptional< IVec2 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DArrayRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DArrayRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DArrayRgba8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DArrayRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DArrayRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DArrayRg8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DArrayR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DArrayR8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeArrayRgba32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeArrayRgba16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeArrayRgba8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeArrayRg32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeArrayRg16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeArrayRg8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeArrayR16 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeArrayR8 > const & image, MaybeOptional< IVec3 > const & P );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DMSRgba32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DMSRgba16 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DMSRg32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DMSRg16 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DMSR16 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DMSArrayRgba32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DMSArrayRgba16 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DMSArrayRg32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DMSArrayRg16 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DMSArrayR16 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSRgba32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSRgba16 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSRgba8 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSRg32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSRg16 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSRg8 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSR16 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSR8 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSArrayRgba32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSArrayRgba16 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSArrayRgba8 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSArrayRg32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSArrayRg16 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSArrayRg8 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSArrayR16 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSArrayR8 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSRgba32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSRgba16 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSRgba8 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSRg32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSRg16 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSRg8 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSR16 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSR8 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSArrayRgba32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSArrayRgba16 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSArrayRgba8 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSArrayRg32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSArrayRg16 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSArrayRg8 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSArrayR16 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSArrayR8 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample );
	/**@}*/
#pragma endregion
#pragma region imageAtomicAdd
	/**
	*name
	*	imageAtomicAdd
	*/
	/**@{*/
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage2DArrayR32 > const & image, MaybeOptional<  IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicMin
	/**
	*name
	*	imageAtomicMin
	*/
	/**@{*/
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicMax
	/**
	*name
	*	imageAtomicMax
	*/
	/**@{*/
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicAnd
	/**
	*name
	*	imageAtomicAnd
	*/
	/**@{*/
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicOr
	/**
	*name
	*	imageAtomicOr
	*/
	/**@{*/
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicXor
	/**
	*name
	*	imageAtomicXor
	*/
	/**@{*/
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicExchange
	/**
	*name
	*	imageAtomicExchange
	*/
	/**@{*/
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & data );
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & data );
	/**@}*/
#pragma endregion
#pragma region imageAtomicCompSwap
	/**
	*name
	*	imageAtomicCompSwap
	*/
	/**@{*/
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage1DR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & compare, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage2DR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & compare, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage3DR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & compare, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImageCubeR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & compare, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImageBufferR32 > const & image, MaybeOptional< Int > const & P, MaybeOptional< Int > const & compare, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage1DArrayR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & compare, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage2DArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & compare, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImageCubeArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & compare, MaybeOptional< Int > const & data );
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage2DMSR32 > const & image, MaybeOptional< IVec2 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & compare, MaybeOptional< Int > const & data );
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage2DMSArrayR32 > const & image, MaybeOptional< IVec3 > const & P, MaybeOptional< Int > const & sample, MaybeOptional< Int > const & compare, MaybeOptional< Int > const & data );
	/**@}*/
#pragma endregion
}

#endif
