/*
See LICENSE file in root folder
*/
#ifndef ___AST_ImageConfiguration_H___
#define ___AST_ImageConfiguration_H___
#pragma once

#include "Type.hpp"

namespace ast::type
{
	enum class Trinary
		: uint8_t
	{
		eFalse,
		eTrue,
		eDontCare,
	};

	enum class AccessKind
		: uint8_t
	{
		eRead,
		eWrite,
		eReadWrite,
	};

	enum class ImageDim
		: uint8_t
	{
		e1D,
		e2D,
		e3D,
		eCube,
		eRect,
		eBuffer,
	};

	enum class ImageFormat
		: uint8_t
	{
		eUnknown,
		eRgba32f,
		eRgba16f,
		eRg32f,
		eRg16f,
		eR32f,
		eR16f,
		eRgba32i,
		eRgba16i,
		eRgba8i,
		eRg32i,
		eRg16i,
		eRg8i,
		eR32i,
		eR16i,
		eR8i,
		eRgba32u,
		eRgba16u,
		eRgba8u,
		eRg32u,
		eRg16u,
		eRg8u,
		eR32u,
		eR16u,
		eR8u,
	};

	template< ImageFormat FormatT >
	struct ImageFormatTraits;

	template< ImageFormat FormatT >
	static Kind sampledBaseType = ImageFormatTraits< FormatT >::SampledBaseType;
	template< ImageFormat FormatT >
	static Kind sampledType = ImageFormatTraits< FormatT >::SampledType;

	TypePtr getType( ImageFormat format );
	bool isFloatFormat( ImageFormat format );
	bool isSIntFormat( ImageFormat format );
	bool isUIntFormat( ImageFormat format );

	struct ImageConfiguration
	{
		ImageConfiguration( type::Kind sampledType = type::Kind::eFloat
			, ImageDim dimension = ImageDim::e1D
			, ImageFormat format = ImageFormat::eUnknown
			, Trinary isDepth = Trinary::eFalse
			, Trinary isSampled = Trinary::eFalse
			, bool isArrayed = false
			, bool isMS = false
			, AccessKind accessKind = AccessKind::eRead );

		type::Kind sampledType;
		ImageDim dimension;
		ImageFormat format;
		Trinary isDepth;
		Trinary isSampled;
		bool isArrayed;
		bool isMS;
		AccessKind accessKind;
	};

	template< ImageFormat FormatT
		, ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline ImageConfiguration makeConfig( bool sampled
		, bool readOnly );
}

#define Img1D ast::type::ImageDim::e1D, false, false, false
#define Img2D ast::type::ImageDim::e2D, false, false, false
#define Img3D ast::type::ImageDim::e3D, false, false, false
#define ImgRect ast::type::ImageDim::eRect, false, false, false
#define ImgCube ast::type::ImageDim::eCube, false, false, false
#define ImgBuffer ast::type::ImageDim::eBuffer, false, false, false
#define Img1DArray ast::type::ImageDim::e1D, true, false, false
#define Img2DArray ast::type::ImageDim::e2D, true, false, false
#define ImgCubeArray ast::type::ImageDim::eCube, true, false, false
#define Img2DMS ast::type::ImageDim::e2D, false, false, true
#define Img2DMSArray ast::type::ImageDim::e2D, true, false, true

#define Img1DShadow ast::type::ImageDim::e1D, false, true, false
#define Img2DShadow ast::type::ImageDim::e2D, false, true, false
#define ImgRectShadow ast::type::ImageDim::eRect, false, true, false
#define ImgCubeShadow ast::type::ImageDim::eCube, false, true, false
#define Img1DArrayShadow ast::type::ImageDim::e1D, true, true, false
#define Img2DArrayShadow ast::type::ImageDim::e2D, true, true, false
#define ImgCubeArrayShadow ast::type::ImageDim::eCube, true, true, false

#define FImg1DRgba16 ast::type::ImageFormat::eRgba16f, Img1D
#define FImg2DRgba16 ast::type::ImageFormat::eRgba16f, Img2D
#define FImg3DRgba16 ast::type::ImageFormat::eRgba16f, Img3D
#define FImgRectRgba16 ast::type::ImageFormat::eRgba16f, ImgRect
#define FImgCubeRgba16 ast::type::ImageFormat::eRgba16f, ImgCube
#define FImgBufferRgba16 ast::type::ImageFormat::eRgba16f, ImgBuffer
#define FImg1DArrayRgba16 ast::type::ImageFormat::eRgba16f, Img1DArray
#define FImg2DArrayRgba16 ast::type::ImageFormat::eRgba16f, Img2DArray
#define FImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16f, ImgCubeArray
#define FImg2DMSRgba16 ast::type::ImageFormat::eRgba16f, Img2DMS
#define FImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16f, Img2DMSArray

#define FImg1DShadowR16 ast::type::ImageFormat::eR16f, Img1DShadow
#define FImg2DShadowR16 ast::type::ImageFormat::eR16f, Img2DShadow
#define FImgRectShadowR16 ast::type::ImageFormat::eR16f, ImgRectShadow
#define FImgCubeShadowR16 ast::type::ImageFormat::eR16f, ImgCubeShadow
#define FImg1DArrayShadowR16 ast::type::ImageFormat::eR16f, Img1DArrayShadow
#define FImg2DArrayShadowR16 ast::type::ImageFormat::eR16f, Img2DArrayShadow
#define FImgCubeArrayShadowR16 ast::type::ImageFormat::eR16f, ImgCubeArrayShadow

#define FImg1DRgba32 ast::type::ImageFormat::eRgba32f, Img1D
#define FImg2DRgba32 ast::type::ImageFormat::eRgba32f, Img2D
#define FImg3DRgba32 ast::type::ImageFormat::eRgba32f, Img3D
#define FImgRectRgba32 ast::type::ImageFormat::eRgba32f, ImgRect
#define FImgCubeRgba32 ast::type::ImageFormat::eRgba32f, ImgCube
#define FImgBufferRgba32 ast::type::ImageFormat::eRgba32f, ImgBuffer
#define FImg1DArrayRgba32 ast::type::ImageFormat::eRgba32f, Img1DArray
#define FImg2DArrayRgba32 ast::type::ImageFormat::eRgba32f, Img2DArray
#define FImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32f, ImgCubeArray
#define FImg2DMSRgba32 ast::type::ImageFormat::eRgba32f, Img2DMS
#define FImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32f, Img2DMSArray

#define FImg1DShadowR32 ast::type::ImageFormat::eR32f, Img1DShadow
#define FImg2DShadowR32 ast::type::ImageFormat::eR32f, Img2DShadow
#define FImgRectShadowR32 ast::type::ImageFormat::eR32f, ImgRectShadow
#define FImgCubeShadowR32 ast::type::ImageFormat::eR32f, ImgCubeShadow
#define FImg1DArrayShadowR32 ast::type::ImageFormat::eR32f, Img1DArrayShadow
#define FImg2DArrayShadowR32 ast::type::ImageFormat::eR32f, Img2DArrayShadow
#define FImgCubeArrayShadowR32 ast::type::ImageFormat::eR32f, ImgCubeArrayShadow

#define IImg1DRgba8 ast::type::ImageFormat::eRgba8i, Img1D
#define IImg2DRgba8 ast::type::ImageFormat::eRgba8i, Img2D
#define IImg3DRgba8 ast::type::ImageFormat::eRgba8i, Img3D
#define IImgRectRgba8 ast::type::ImageFormat::eRgba8i, ImgRect
#define IImgCubeRgba8 ast::type::ImageFormat::eRgba8i, ImgCube
#define IImgBufferRgba8 ast::type::ImageFormat::eRgba8i, ImgBuffer
#define IImg1DArrayRgba8 ast::type::ImageFormat::eRgba8i, Img1DArray
#define IImg2DArrayRgba8 ast::type::ImageFormat::eRgba8i, Img2DArray
#define IImgCubeArrayRgba8 ast::type::ImageFormat::eRgba8i, ImgCubeArray
#define IImg2DMSRgba8 ast::type::ImageFormat::eRgba8i, Img2DMS
#define IImg2DMSArrayRgba8 ast::type::ImageFormat::eRgba8i, Img2DMSArray

#define IImg1DRgba16 ast::type::ImageFormat::eRgba16i, Img1D
#define IImg2DRgba16 ast::type::ImageFormat::eRgba16i, Img2D
#define IImg3DRgba16 ast::type::ImageFormat::eRgba16i, Img3D
#define IImgRectRgba16 ast::type::ImageFormat::eRgba16i, ImgRect
#define IImgCubeRgba16 ast::type::ImageFormat::eRgba16i, ImgCube
#define IImgBufferRgba16 ast::type::ImageFormat::eRgba16i, ImgBuffer
#define IImg1DArrayRgba16 ast::type::ImageFormat::eRgba16i, Img1DArray
#define IImg2DArrayRgba16 ast::type::ImageFormat::eRgba16i, Img2DArray
#define IImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16i, ImgCubeArray
#define IImg2DMSRgba16 ast::type::ImageFormat::eRgba16i, Img2DMS
#define IImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16i, Img2DMSArray

#define IImg1DRgba32 ast::type::ImageFormat::eRgba32i, Img1D
#define IImg2DRgba32 ast::type::ImageFormat::eRgba32i, Img2D
#define IImg3DRgba32 ast::type::ImageFormat::eRgba32i, Img3D
#define IImgRectRgba32 ast::type::ImageFormat::eRgba32i, ImgRect
#define IImgCubeRgba32 ast::type::ImageFormat::eRgba32i, ImgCube
#define IImgBufferRgba32 ast::type::ImageFormat::eRgba32i, ImgBuffer
#define IImg1DArrayRgba32 ast::type::ImageFormat::eRgba32i, Img1DArray
#define IImg2DArrayRgba32 ast::type::ImageFormat::eRgba32i, Img2DArray
#define IImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32i, ImgCubeArray
#define IImg2DMSRgba32 ast::type::ImageFormat::eRgba32i, Img2DMS
#define IImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32i, Img2DMSArray

#define UImg1DRgba8 ast::type::ImageFormat::eRgba8u, Img1D
#define UImg2DRgba8 ast::type::ImageFormat::eRgba8u, Img2D
#define UImg3DRgba8 ast::type::ImageFormat::eRgba8u, Img3D
#define UImgRectRgba8 ast::type::ImageFormat::eRgba8u, ImgRect
#define UImgCubeRgba8 ast::type::ImageFormat::eRgba8u, ImgCube
#define UImgBufferRgba8 ast::type::ImageFormat::eRgba8u, ImgBuffer
#define UImg1DArrayRgba8 ast::type::ImageFormat::eRgba8u, Img1DArray
#define UImg2DArrayRgba8 ast::type::ImageFormat::eRgba8u, Img2DArray
#define UImgCubeArrayRgba8 ast::type::ImageFormat::eRgba8u, ImgCubeArray
#define UImg2DMSRgba8 ast::type::ImageFormat::eRgba8u, Img2DMS
#define UImg2DMSArrayRgba8 ast::type::ImageFormat::eRgba8u, Img2DMSArray

#define UImg1DRgba16 ast::type::ImageFormat::eRgba16u, Img1D
#define UImg2DRgba16 ast::type::ImageFormat::eRgba16u, Img2D
#define UImg3DRgba16 ast::type::ImageFormat::eRgba16u, Img3D
#define UImgRectRgba16 ast::type::ImageFormat::eRgba16u, ImgRect
#define UImgCubeRgba16 ast::type::ImageFormat::eRgba16u, ImgCube
#define UImgBufferRgba16 ast::type::ImageFormat::eRgba16u, ImgBuffer
#define UImg1DArrayRgba16 ast::type::ImageFormat::eRgba16u, Img1DArray
#define UImg2DArrayRgba16 ast::type::ImageFormat::eRgba16u, Img2DArray
#define UImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16u, ImgCubeArray
#define UImg2DMSRgba16 ast::type::ImageFormat::eRgba16u, Img2DMS
#define UImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16u, Img2DMSArray

#define UImg1DRgba32 ast::type::ImageFormat::eRgba32u, Img1D
#define UImg2DRgba32 ast::type::ImageFormat::eRgba32u, Img2D
#define UImg3DRgba32 ast::type::ImageFormat::eRgba32u, Img3D
#define UImgRectRgba32 ast::type::ImageFormat::eRgba32u, ImgRect
#define UImgCubeRgba32 ast::type::ImageFormat::eRgba32u, ImgCube
#define UImgBufferRgba32 ast::type::ImageFormat::eRgba32u, ImgBuffer
#define UImg1DArrayRgba32 ast::type::ImageFormat::eRgba32u, Img1DArray
#define UImg2DArrayRgba32 ast::type::ImageFormat::eRgba32u, Img2DArray
#define UImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32u, ImgCubeArray
#define UImg2DMSRgba32 ast::type::ImageFormat::eRgba32u, Img2DMS
#define UImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32u, Img2DMSArray

#define FImg1DRg16 ast::type::ImageFormat::eRg16f, Img1D
#define FImg2DRg16 ast::type::ImageFormat::eRg16f, Img2D
#define FImg3DRg16 ast::type::ImageFormat::eRg16f, Img3D
#define FImgRectRg16 ast::type::ImageFormat::eRg16f, ImgRect
#define FImgCubeRg16 ast::type::ImageFormat::eRg16f, ImgCube
#define FImgBufferRg16 ast::type::ImageFormat::eRg16f, ImgBuffer
#define FImg1DArrayRg16 ast::type::ImageFormat::eRg16f, Img1DArray
#define FImg2DArrayRg16 ast::type::ImageFormat::eRg16f, Img2DArray
#define FImgCubeArrayRg16 ast::type::ImageFormat::eRg16f, ImgCubeArray
#define FImg2DMSRg16 ast::type::ImageFormat::eRg16f, Img2DMS
#define FImg2DMSArrayRg16 ast::type::ImageFormat::eRg16f, Img2DMSArray

#define FImg1DRg32 ast::type::ImageFormat::eRg32f, Img1D
#define FImg2DRg32 ast::type::ImageFormat::eRg32f, Img2D
#define FImg3DRg32 ast::type::ImageFormat::eRg32f, Img3D
#define FImgRectRg32 ast::type::ImageFormat::eRg32f, ImgRect
#define FImgCubeRg32 ast::type::ImageFormat::eRg32f, ImgCube
#define FImgBufferRg32 ast::type::ImageFormat::eRg32f, ImgBuffer
#define FImg1DArrayRg32 ast::type::ImageFormat::eRg32f, Img1DArray
#define FImg2DArrayRg32 ast::type::ImageFormat::eRg32f, Img2DArray
#define FImgCubeArrayRg32 ast::type::ImageFormat::eRg32f, ImgCubeArray
#define FImg2DMSRg32 ast::type::ImageFormat::eRg32f, Img2DMS
#define FImg2DMSArrayRg32 ast::type::ImageFormat::eRg32f, Img2DMSArray

#define IImg1DRg8 ast::type::ImageFormat::eRg8i, Img1D
#define IImg2DRg8 ast::type::ImageFormat::eRg8i, Img2D
#define IImg3DRg8 ast::type::ImageFormat::eRg8i, Img3D
#define IImgRectRg8 ast::type::ImageFormat::eRg8i, ImgRect
#define IImgCubeRg8 ast::type::ImageFormat::eRg8i, ImgCube
#define IImgBufferRg8 ast::type::ImageFormat::eRg8i, ImgBuffer
#define IImg1DArrayRg8 ast::type::ImageFormat::eRg8i, Img1DArray
#define IImg2DArrayRg8 ast::type::ImageFormat::eRg8i, Img2DArray
#define IImgCubeArrayRg8 ast::type::ImageFormat::eRg8i, ImgCubeArray
#define IImg2DMSRg8 ast::type::ImageFormat::eRg8i, Img2DMS
#define IImg2DMSArrayRg8 ast::type::ImageFormat::eRg8i, Img2DMSArray

#define IImg1DRg16 ast::type::ImageFormat::eRg16i, Img1D
#define IImg2DRg16 ast::type::ImageFormat::eRg16i, Img2D
#define IImg3DRg16 ast::type::ImageFormat::eRg16i, Img3D
#define IImgRectRg16 ast::type::ImageFormat::eRg16i, ImgRect
#define IImgCubeRg16 ast::type::ImageFormat::eRg16i, ImgCube
#define IImgBufferRg16 ast::type::ImageFormat::eRg16i, ImgBuffer
#define IImg1DArrayRg16 ast::type::ImageFormat::eRg16i, Img1DArray
#define IImg2DArrayRg16 ast::type::ImageFormat::eRg16i, Img2DArray
#define IImgCubeArrayRg16 ast::type::ImageFormat::eRg16i, ImgCubeArray
#define IImg2DMSRg16 ast::type::ImageFormat::eRg16i, Img2DMS
#define IImg2DMSArrayRg16 ast::type::ImageFormat::eRg16i, Img2DMSArray

#define IImg1DRg32 ast::type::ImageFormat::eRg32i, Img1D
#define IImg2DRg32 ast::type::ImageFormat::eRg32i, Img2D
#define IImg3DRg32 ast::type::ImageFormat::eRg32i, Img3D
#define IImgRectRg32 ast::type::ImageFormat::eRg32i, ImgRect
#define IImgCubeRg32 ast::type::ImageFormat::eRg32i, ImgCube
#define IImgBufferRg32 ast::type::ImageFormat::eRg32i, ImgBuffer
#define IImg1DArrayRg32 ast::type::ImageFormat::eRg32i, Img1DArray
#define IImg2DArrayRg32 ast::type::ImageFormat::eRg32i, Img2DArray
#define IImgCubeArrayRg32 ast::type::ImageFormat::eRg32i, ImgCubeArray
#define IImg2DMSRg32 ast::type::ImageFormat::eRg32i, Img2DMS
#define IImg2DMSArrayRg32 ast::type::ImageFormat::eRg32i, Img2DMSArray

#define UImg1DRg8 ast::type::ImageFormat::eRg8u, Img1D
#define UImg2DRg8 ast::type::ImageFormat::eRg8u, Img2D
#define UImg3DRg8 ast::type::ImageFormat::eRg8u, Img3D
#define UImgRectRg8 ast::type::ImageFormat::eRg8u, ImgRect
#define UImgCubeRg8 ast::type::ImageFormat::eRg8u, ImgCube
#define UImgBufferRg8 ast::type::ImageFormat::eRg8u, ImgBuffer
#define UImg1DArrayRg8 ast::type::ImageFormat::eRg8u, Img1DArray
#define UImg2DArrayRg8 ast::type::ImageFormat::eRg8u, Img2DArray
#define UImgCubeArrayRg8 ast::type::ImageFormat::eRg8u, ImgCubeArray
#define UImg2DMSRg8 ast::type::ImageFormat::eRg8u, Img2DMS
#define UImg2DMSArrayRg8 ast::type::ImageFormat::eRg8u, Img2DMSArray

#define UImg1DRg16 ast::type::ImageFormat::eRg16u, Img1D
#define UImg2DRg16 ast::type::ImageFormat::eRg16u, Img2D
#define UImg3DRg16 ast::type::ImageFormat::eRg16u, Img3D
#define UImgRectRg16 ast::type::ImageFormat::eRg16u, ImgRect
#define UImgCubeRg16 ast::type::ImageFormat::eRg16u, ImgCube
#define UImgBufferRg16 ast::type::ImageFormat::eRg16u, ImgBuffer
#define UImg1DArrayRg16 ast::type::ImageFormat::eRg16u, Img1DArray
#define UImg2DArrayRg16 ast::type::ImageFormat::eRg16u, Img2DArray
#define UImgCubeArrayRg16 ast::type::ImageFormat::eRg16u, ImgCubeArray
#define UImg2DMSRg16 ast::type::ImageFormat::eRg16u, Img2DMS
#define UImg2DMSArrayRg16 ast::type::ImageFormat::eRg16u, Img2DMSArray

#define UImg1DRg32 ast::type::ImageFormat::eRg32u, Img1D
#define UImg2DRg32 ast::type::ImageFormat::eRg32u, Img2D
#define UImg3DRg32 ast::type::ImageFormat::eRg32u, Img3D
#define UImgRectRg32 ast::type::ImageFormat::eRg32u, ImgRect
#define UImgCubeRg32 ast::type::ImageFormat::eRg32u, ImgCube
#define UImgBufferRg32 ast::type::ImageFormat::eRg32u, ImgBuffer
#define UImg1DArrayRg32 ast::type::ImageFormat::eRg32u, Img1DArray
#define UImg2DArrayRg32 ast::type::ImageFormat::eRg32u, Img2DArray
#define UImgCubeArrayRg32 ast::type::ImageFormat::eRg32u, ImgCubeArray
#define UImg2DMSRg32 ast::type::ImageFormat::eRg32u, Img2DMS
#define UImg2DMSArrayRg32 ast::type::ImageFormat::eRg32u, Img2DMSArray

#define FImg1DR16 ast::type::ImageFormat::eR16f, Img1D
#define FImg2DR16 ast::type::ImageFormat::eR16f, Img2D
#define FImg3DR16 ast::type::ImageFormat::eR16f, Img3D
#define FImgRectR16 ast::type::ImageFormat::eR16f, ImgRect
#define FImgCubeR16 ast::type::ImageFormat::eR16f, ImgCube
#define FImgBufferR16 ast::type::ImageFormat::eR16f, ImgBuffer
#define FImg1DArrayR16 ast::type::ImageFormat::eR16f, Img1DArray
#define FImg2DArrayR16 ast::type::ImageFormat::eR16f, Img2DArray
#define FImgCubeArrayR16 ast::type::ImageFormat::eR16f, ImgCubeArray
#define FImg2DMSR16 ast::type::ImageFormat::eR16f, Img2DMS
#define FImg2DMSArrayR16 ast::type::ImageFormat::eR16f, Img2DMSArray

#define FImg1DR32 ast::type::ImageFormat::eR32f, Img1D
#define FImg2DR32 ast::type::ImageFormat::eR32f, Img2D
#define FImg3DR32 ast::type::ImageFormat::eR32f, Img3D
#define FImgRectR32 ast::type::ImageFormat::eR32f, ImgRect
#define FImgCubeR32 ast::type::ImageFormat::eR32f, ImgCube
#define FImgBufferR32 ast::type::ImageFormat::eR32f, ImgBuffer
#define FImg1DArrayR32 ast::type::ImageFormat::eR32f, Img1DArray
#define FImg2DArrayR32 ast::type::ImageFormat::eR32f, Img2DArray
#define FImgCubeArrayR32 ast::type::ImageFormat::eR32f, ImgCubeArray
#define FImg2DMSR32 ast::type::ImageFormat::eR32f, Img2DMS
#define FImg2DMSArrayR32 ast::type::ImageFormat::eR32f, Img2DMSArray

#define IImg1DR8 ast::type::ImageFormat::eR8i, Img1D
#define IImg2DR8 ast::type::ImageFormat::eR8i, Img2D
#define IImg3DR8 ast::type::ImageFormat::eR8i, Img3D
#define IImgRectR8 ast::type::ImageFormat::eR8i, ImgRect
#define IImgCubeR8 ast::type::ImageFormat::eR8i, ImgCube
#define IImgBufferR8 ast::type::ImageFormat::eR8i, ImgBuffer
#define IImg1DArrayR8 ast::type::ImageFormat::eR8i, Img1DArray
#define IImg2DArrayR8 ast::type::ImageFormat::eR8i, Img2DArray
#define IImgCubeArrayR8 ast::type::ImageFormat::eR8i, ImgCubeArray
#define IImg2DMSR8 ast::type::ImageFormat::eR8i, Img2DMS
#define IImg2DMSArrayR8 ast::type::ImageFormat::eR8i, Img2DMSArray

#define IImg1DR16 ast::type::ImageFormat::eR16i, Img1D
#define IImg2DR16 ast::type::ImageFormat::eR16i, Img2D
#define IImg3DR16 ast::type::ImageFormat::eR16i, Img3D
#define IImgRectR16 ast::type::ImageFormat::eR16i, ImgRect
#define IImgCubeR16 ast::type::ImageFormat::eR16i, ImgCube
#define IImgBufferR16 ast::type::ImageFormat::eR16i, ImgBuffer
#define IImg1DArrayR16 ast::type::ImageFormat::eR16i, Img1DArray
#define IImg2DArrayR16 ast::type::ImageFormat::eR16i, Img2DArray
#define IImgCubeArrayR16 ast::type::ImageFormat::eR16i, ImgCubeArray
#define IImg2DMSR16 ast::type::ImageFormat::eR16i, Img2DMS
#define IImg2DMSArrayR16 ast::type::ImageFormat::eR16i, Img2DMSArray

#define IImg1DR32 ast::type::ImageFormat::eR32i, Img1D
#define IImg2DR32 ast::type::ImageFormat::eR32i, Img2D
#define IImg3DR32 ast::type::ImageFormat::eR32i, Img3D
#define IImgRectR32 ast::type::ImageFormat::eR32i, ImgRect
#define IImgCubeR32 ast::type::ImageFormat::eR32i, ImgCube
#define IImgBufferR32 ast::type::ImageFormat::eR32i, ImgBuffer
#define IImg1DArrayR32 ast::type::ImageFormat::eR32i, Img1DArray
#define IImg2DArrayR32 ast::type::ImageFormat::eR32i, Img2DArray
#define IImgCubeArrayR32 ast::type::ImageFormat::eR32i, ImgCubeArray
#define IImg2DMSR32 ast::type::ImageFormat::eR32i, Img2DMS
#define IImg2DMSArrayR32 ast::type::ImageFormat::eR32i, Img2DMSArray

#define UImg1DR8 ast::type::ImageFormat::eR8u, Img1D
#define UImg2DR8 ast::type::ImageFormat::eR8u, Img2D
#define UImg3DR8 ast::type::ImageFormat::eR8u, Img3D
#define UImgRectR8 ast::type::ImageFormat::eR8u, ImgRect
#define UImgCubeR8 ast::type::ImageFormat::eR8u, ImgCube
#define UImgBufferR8 ast::type::ImageFormat::eR8u, ImgBuffer
#define UImg1DArrayR8 ast::type::ImageFormat::eR8u, Img1DArray
#define UImg2DArrayR8 ast::type::ImageFormat::eR8u, Img2DArray
#define UImgCubeArrayR8 ast::type::ImageFormat::eR8u, ImgCubeArray
#define UImg2DMSR8 ast::type::ImageFormat::eR8u, Img2DMS
#define UImg2DMSArrayR8 ast::type::ImageFormat::eR8u, Img2DMSArray

#define UImg1DR16 ast::type::ImageFormat::eR16u, Img1D
#define UImg2DR16 ast::type::ImageFormat::eR16u, Img2D
#define UImg3DR16 ast::type::ImageFormat::eR16u, Img3D
#define UImgRectR16 ast::type::ImageFormat::eR16u, ImgRect
#define UImgCubeR16 ast::type::ImageFormat::eR16u, ImgCube
#define UImgBufferR16 ast::type::ImageFormat::eR16u, ImgBuffer
#define UImg1DArrayR16 ast::type::ImageFormat::eR16u, Img1DArray
#define UImg2DArrayR16 ast::type::ImageFormat::eR16u, Img2DArray
#define UImgCubeArrayR16 ast::type::ImageFormat::eR16u, ImgCubeArray
#define UImg2DMSR16 ast::type::ImageFormat::eR16u, Img2DMS
#define UImg2DMSArrayR16 ast::type::ImageFormat::eR16u, Img2DMSArray

#define UImg1DR32 ast::type::ImageFormat::eR32u, Img1D
#define UImg2DR32 ast::type::ImageFormat::eR32u, Img2D
#define UImg3DR32 ast::type::ImageFormat::eR32u, Img3D
#define UImgRectR32 ast::type::ImageFormat::eR32u, ImgRect
#define UImgCubeR32 ast::type::ImageFormat::eR32u, ImgCube
#define UImgBufferR32 ast::type::ImageFormat::eR32u, ImgBuffer
#define UImg1DArrayR32 ast::type::ImageFormat::eR32u, Img1DArray
#define UImg2DArrayR32 ast::type::ImageFormat::eR32u, Img2DArray
#define UImgCubeArrayR32 ast::type::ImageFormat::eR32u, ImgCubeArray
#define UImg2DMSR32 ast::type::ImageFormat::eR32u, Img2DMS
#define UImg2DMSArrayR32 ast::type::ImageFormat::eR32u, Img2DMSArray

#include "ImageConfiguration.inl"

#endif
