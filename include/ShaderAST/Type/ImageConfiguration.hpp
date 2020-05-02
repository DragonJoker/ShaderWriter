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

	inline constexpr bool isFloatFormat( ImageFormat format )
	{
		return format == ImageFormat::eUnknown
			|| format == ImageFormat::eRgba32f
			|| format == ImageFormat::eRgba16f
			|| format == ImageFormat::eRg32f
			|| format == ImageFormat::eRg16f
			|| format == ImageFormat::eR32f
			|| format == ImageFormat::eR16f;
	}

	inline constexpr bool isSIntFormat( ImageFormat format )
	{
		return format == ImageFormat::eUnknown
			|| format == ImageFormat::eRgba32i
			|| format == ImageFormat::eRgba16i
			|| format == ImageFormat::eRgba8i
			|| format == ImageFormat::eRg32i
			|| format == ImageFormat::eRg16i
			|| format == ImageFormat::eRg8i
			|| format == ImageFormat::eR32i
			|| format == ImageFormat::eR16i
			|| format == ImageFormat::eR8i;
	}

	inline constexpr bool isUIntFormat( ImageFormat format )
	{
		return format == ImageFormat::eUnknown
			|| format == ImageFormat::eRgba32u
			|| format == ImageFormat::eRgba16u
			|| format == ImageFormat::eRgba8u
			|| format == ImageFormat::eRg32u
			|| format == ImageFormat::eRg16u
			|| format == ImageFormat::eRg8u
			|| format == ImageFormat::eR32u
			|| format == ImageFormat::eR16u
			|| format == ImageFormat::eR8u;
	}

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

	size_t getHash( type::ImageConfiguration const & config );

	template< ImageFormat FormatT
		, AccessKind AccessT
		, ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline ImageConfiguration makeConfig( bool sampled
		, bool readOnly );

	template< typename T >
	inline size_t hashCombine( size_t & hash
		, T const & rhs );
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

#define RImg1D ast::type::AccessKind::eRead, ast::type::ImageDim::e1D, false, false, false
#define RImg2D ast::type::AccessKind::eRead, ast::type::ImageDim::e2D, false, false, false
#define RImg3D ast::type::AccessKind::eRead, ast::type::ImageDim::e3D, false, false, false
#define RImgRect ast::type::AccessKind::eRead, ast::type::ImageDim::eRect, false, false, false
#define RImgCube ast::type::AccessKind::eRead, ast::type::ImageDim::eCube, false, false, false
#define RImgBuffer ast::type::AccessKind::eRead, ast::type::ImageDim::eBuffer, false, false, false
#define RImg1DArray ast::type::AccessKind::eRead, ast::type::ImageDim::e1D, true, false, false
#define RImg2DArray ast::type::AccessKind::eRead, ast::type::ImageDim::e2D, true, false, false
#define RImgCubeArray ast::type::AccessKind::eRead, ast::type::ImageDim::eCube, true, false, false
#define RImg2DMS ast::type::AccessKind::eRead, ast::type::ImageDim::e2D, false, false, true
#define RImg2DMSArray ast::type::AccessKind::eRead, ast::type::ImageDim::e2D, true, false, true
#define RImg1DShadow ast::type::AccessKind::eRead, ast::type::ImageDim::e1D, false, true, false
#define RImg2DShadow ast::type::AccessKind::eRead, ast::type::ImageDim::e2D, false, true, false
#define RImgRectShadow ast::type::AccessKind::eRead, ast::type::ImageDim::eRect, false, true, false
#define RImgCubeShadow ast::type::AccessKind::eRead, ast::type::ImageDim::eCube, false, true, false
#define RImg1DArrayShadow ast::type::AccessKind::eRead, ast::type::ImageDim::e1D, true, true, false
#define RImg2DArrayShadow ast::type::AccessKind::eRead, ast::type::ImageDim::e2D, true, true, false
#define RImgCubeArrayShadow ast::type::AccessKind::eRead, ast::type::ImageDim::eCube, true, true, false

#define RFImg1DRgba16 ast::type::ImageFormat::eRgba16f, RImg1D
#define RFImg2DRgba16 ast::type::ImageFormat::eRgba16f, RImg2D
#define RFImg3DRgba16 ast::type::ImageFormat::eRgba16f, RImg3D
#define RFImgRectRgba16 ast::type::ImageFormat::eRgba16f, RImgRect
#define RFImgCubeRgba16 ast::type::ImageFormat::eRgba16f, RImgCube
#define RFImgBufferRgba16 ast::type::ImageFormat::eRgba16f, RImgBuffer
#define RFImg1DArrayRgba16 ast::type::ImageFormat::eRgba16f, RImg1DArray
#define RFImg2DArrayRgba16 ast::type::ImageFormat::eRgba16f, RImg2DArray
#define RFImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16f, RImgCubeArray
#define RFImg2DMSRgba16 ast::type::ImageFormat::eRgba16f, RImg2DMS
#define RFImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16f, RImg2DMSArray
#define RFImg1DShadowR16 ast::type::ImageFormat::eR16f, RImg1DShadow
#define RFImg2DShadowR16 ast::type::ImageFormat::eR16f, RImg2DShadow
#define RFImgRectShadowR16 ast::type::ImageFormat::eR16f, RImgRectShadow
#define RFImgCubeShadowR16 ast::type::ImageFormat::eR16f, RImgCubeShadow
#define RFImg1DArrayShadowR16 ast::type::ImageFormat::eR16f, RImg1DArrayShadow
#define RFImg2DArrayShadowR16 ast::type::ImageFormat::eR16f, RImg2DArrayShadow
#define RFImgCubeArrayShadowR16 ast::type::ImageFormat::eR16f, RImgCubeArrayShadow
#define RFImg1DRgba32 ast::type::ImageFormat::eRgba32f, RImg1D
#define RFImg2DRgba32 ast::type::ImageFormat::eRgba32f, RImg2D
#define RFImg3DRgba32 ast::type::ImageFormat::eRgba32f, RImg3D
#define RFImgRectRgba32 ast::type::ImageFormat::eRgba32f, RImgRect
#define RFImgCubeRgba32 ast::type::ImageFormat::eRgba32f, RImgCube
#define RFImgBufferRgba32 ast::type::ImageFormat::eRgba32f, RImgBuffer
#define RFImg1DArrayRgba32 ast::type::ImageFormat::eRgba32f, RImg1DArray
#define RFImg2DArrayRgba32 ast::type::ImageFormat::eRgba32f, RImg2DArray
#define RFImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32f, RImgCubeArray
#define RFImg2DMSRgba32 ast::type::ImageFormat::eRgba32f, RImg2DMS
#define RFImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32f, RImg2DMSArray
#define RFImg1DShadowR32 ast::type::ImageFormat::eR32f, RImg1DShadow
#define RFImg2DShadowR32 ast::type::ImageFormat::eR32f, RImg2DShadow
#define RFImgRectShadowR32 ast::type::ImageFormat::eR32f, RImgRectShadow
#define RFImgCubeShadowR32 ast::type::ImageFormat::eR32f, RImgCubeShadow
#define RFImg1DArrayShadowR32 ast::type::ImageFormat::eR32f, RImg1DArrayShadow
#define RFImg2DArrayShadowR32 ast::type::ImageFormat::eR32f, RImg2DArrayShadow
#define RFImgCubeArrayShadowR32 ast::type::ImageFormat::eR32f, RImgCubeArrayShadow

#define RIImg1DRgba8 ast::type::ImageFormat::eRgba8i, RImg1D
#define RIImg2DRgba8 ast::type::ImageFormat::eRgba8i, RImg2D
#define RIImg3DRgba8 ast::type::ImageFormat::eRgba8i, RImg3D
#define RIImgRectRgba8 ast::type::ImageFormat::eRgba8i, RImgRect
#define RIImgCubeRgba8 ast::type::ImageFormat::eRgba8i, RImgCube
#define RIImgBufferRgba8 ast::type::ImageFormat::eRgba8i, RImgBuffer
#define RIImg1DArrayRgba8 ast::type::ImageFormat::eRgba8i, RImg1DArray
#define RIImg2DArrayRgba8 ast::type::ImageFormat::eRgba8i, RImg2DArray
#define RIImgCubeArrayRgba8 ast::type::ImageFormat::eRgba8i, RImgCubeArray
#define RIImg2DMSRgba8 ast::type::ImageFormat::eRgba8i, RImg2DMS
#define RIImg2DMSArrayRgba8 ast::type::ImageFormat::eRgba8i, RImg2DMSArray
#define RIImg1DRgba16 ast::type::ImageFormat::eRgba16i, RImg1D
#define RIImg2DRgba16 ast::type::ImageFormat::eRgba16i, RImg2D
#define RIImg3DRgba16 ast::type::ImageFormat::eRgba16i, RImg3D
#define RIImgRectRgba16 ast::type::ImageFormat::eRgba16i, RImgRect
#define RIImgCubeRgba16 ast::type::ImageFormat::eRgba16i, RImgCube
#define RIImgBufferRgba16 ast::type::ImageFormat::eRgba16i, RImgBuffer
#define RIImg1DArrayRgba16 ast::type::ImageFormat::eRgba16i, RImg1DArray
#define RIImg2DArrayRgba16 ast::type::ImageFormat::eRgba16i, RImg2DArray
#define RIImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16i, RImgCubeArray
#define RIImg2DMSRgba16 ast::type::ImageFormat::eRgba16i, RImg2DMS
#define RIImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16i, RImg2DMSArray
#define RIImg1DRgba32 ast::type::ImageFormat::eRgba32i, RImg1D
#define RIImg2DRgba32 ast::type::ImageFormat::eRgba32i, RImg2D
#define RIImg3DRgba32 ast::type::ImageFormat::eRgba32i, RImg3D
#define RIImgRectRgba32 ast::type::ImageFormat::eRgba32i, RImgRect
#define RIImgCubeRgba32 ast::type::ImageFormat::eRgba32i, RImgCube
#define RIImgBufferRgba32 ast::type::ImageFormat::eRgba32i, RImgBuffer
#define RIImg1DArrayRgba32 ast::type::ImageFormat::eRgba32i, RImg1DArray
#define RIImg2DArrayRgba32 ast::type::ImageFormat::eRgba32i, RImg2DArray
#define RIImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32i, RImgCubeArray
#define RIImg2DMSRgba32 ast::type::ImageFormat::eRgba32i, RImg2DMS
#define RIImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32i, RImg2DMSArray

#define RUImg1DRgba8 ast::type::ImageFormat::eRgba8u, RImg1D
#define RUImg2DRgba8 ast::type::ImageFormat::eRgba8u, RImg2D
#define RUImg3DRgba8 ast::type::ImageFormat::eRgba8u, RImg3D
#define RUImgRectRgba8 ast::type::ImageFormat::eRgba8u, RImgRect
#define RUImgCubeRgba8 ast::type::ImageFormat::eRgba8u, RImgCube
#define RUImgBufferRgba8 ast::type::ImageFormat::eRgba8u, RImgBuffer
#define RUImg1DArrayRgba8 ast::type::ImageFormat::eRgba8u, RImg1DArray
#define RUImg2DArrayRgba8 ast::type::ImageFormat::eRgba8u, RImg2DArray
#define RUImgCubeArrayRgba8 ast::type::ImageFormat::eRgba8u, RImgCubeArray
#define RUImg2DMSRgba8 ast::type::ImageFormat::eRgba8u, RImg2DMS
#define RUImg2DMSArrayRgba8 ast::type::ImageFormat::eRgba8u, RImg2DMSArray
#define RUImg1DRgba16 ast::type::ImageFormat::eRgba16u, RImg1D
#define RUImg2DRgba16 ast::type::ImageFormat::eRgba16u, RImg2D
#define RUImg3DRgba16 ast::type::ImageFormat::eRgba16u, RImg3D
#define RUImgRectRgba16 ast::type::ImageFormat::eRgba16u, RImgRect
#define RUImgCubeRgba16 ast::type::ImageFormat::eRgba16u, RImgCube
#define RUImgBufferRgba16 ast::type::ImageFormat::eRgba16u, RImgBuffer
#define RUImg1DArrayRgba16 ast::type::ImageFormat::eRgba16u, RImg1DArray
#define RUImg2DArrayRgba16 ast::type::ImageFormat::eRgba16u, RImg2DArray
#define RUImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16u, RImgCubeArray
#define RUImg2DMSRgba16 ast::type::ImageFormat::eRgba16u, RImg2DMS
#define RUImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16u, RImg2DMSArray
#define RUImg1DRgba32 ast::type::ImageFormat::eRgba32u, RImg1D
#define RUImg2DRgba32 ast::type::ImageFormat::eRgba32u, RImg2D
#define RUImg3DRgba32 ast::type::ImageFormat::eRgba32u, RImg3D
#define RUImgRectRgba32 ast::type::ImageFormat::eRgba32u, RImgRect
#define RUImgCubeRgba32 ast::type::ImageFormat::eRgba32u, RImgCube
#define RUImgBufferRgba32 ast::type::ImageFormat::eRgba32u, RImgBuffer
#define RUImg1DArrayRgba32 ast::type::ImageFormat::eRgba32u, RImg1DArray
#define RUImg2DArrayRgba32 ast::type::ImageFormat::eRgba32u, RImg2DArray
#define RUImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32u, RImgCubeArray
#define RUImg2DMSRgba32 ast::type::ImageFormat::eRgba32u, RImg2DMS
#define RUImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32u, RImg2DMSArray

#define RFImg1DRg16 ast::type::ImageFormat::eRg16f, RImg1D
#define RFImg2DRg16 ast::type::ImageFormat::eRg16f, RImg2D
#define RFImg3DRg16 ast::type::ImageFormat::eRg16f, RImg3D
#define RFImgRectRg16 ast::type::ImageFormat::eRg16f, RImgRect
#define RFImgCubeRg16 ast::type::ImageFormat::eRg16f, RImgCube
#define RFImgBufferRg16 ast::type::ImageFormat::eRg16f, RImgBuffer
#define RFImg1DArrayRg16 ast::type::ImageFormat::eRg16f, RImg1DArray
#define RFImg2DArrayRg16 ast::type::ImageFormat::eRg16f, RImg2DArray
#define RFImgCubeArrayRg16 ast::type::ImageFormat::eRg16f, RImgCubeArray
#define RFImg2DMSRg16 ast::type::ImageFormat::eRg16f, RImg2DMS
#define RFImg2DMSArrayRg16 ast::type::ImageFormat::eRg16f, RImg2DMSArray
#define RFImg1DRg32 ast::type::ImageFormat::eRg32f, RImg1D
#define RFImg2DRg32 ast::type::ImageFormat::eRg32f, RImg2D
#define RFImg3DRg32 ast::type::ImageFormat::eRg32f, RImg3D
#define RFImgRectRg32 ast::type::ImageFormat::eRg32f, RImgRect
#define RFImgCubeRg32 ast::type::ImageFormat::eRg32f, RImgCube
#define RFImgBufferRg32 ast::type::ImageFormat::eRg32f, RImgBuffer
#define RFImg1DArrayRg32 ast::type::ImageFormat::eRg32f, RImg1DArray
#define RFImg2DArrayRg32 ast::type::ImageFormat::eRg32f, RImg2DArray
#define RFImgCubeArrayRg32 ast::type::ImageFormat::eRg32f, RImgCubeArray
#define RFImg2DMSRg32 ast::type::ImageFormat::eRg32f, RImg2DMS
#define RFImg2DMSArrayRg32 ast::type::ImageFormat::eRg32f, RImg2DMSArray

#define RIImg1DRg8 ast::type::ImageFormat::eRg8i, RImg1D
#define RIImg2DRg8 ast::type::ImageFormat::eRg8i, RImg2D
#define RIImg3DRg8 ast::type::ImageFormat::eRg8i, RImg3D
#define RIImgRectRg8 ast::type::ImageFormat::eRg8i, RImgRect
#define RIImgCubeRg8 ast::type::ImageFormat::eRg8i, RImgCube
#define RIImgBufferRg8 ast::type::ImageFormat::eRg8i, RImgBuffer
#define RIImg1DArrayRg8 ast::type::ImageFormat::eRg8i, RImg1DArray
#define RIImg2DArrayRg8 ast::type::ImageFormat::eRg8i, RImg2DArray
#define RIImgCubeArrayRg8 ast::type::ImageFormat::eRg8i, RImgCubeArray
#define RIImg2DMSRg8 ast::type::ImageFormat::eRg8i, RImg2DMS
#define RIImg2DMSArrayRg8 ast::type::ImageFormat::eRg8i, RImg2DMSArray
#define RIImg1DRg16 ast::type::ImageFormat::eRg16i, RImg1D
#define RIImg2DRg16 ast::type::ImageFormat::eRg16i, RImg2D
#define RIImg3DRg16 ast::type::ImageFormat::eRg16i, RImg3D
#define RIImgRectRg16 ast::type::ImageFormat::eRg16i, RImgRect
#define RIImgCubeRg16 ast::type::ImageFormat::eRg16i, RImgCube
#define RIImgBufferRg16 ast::type::ImageFormat::eRg16i, RImgBuffer
#define RIImg1DArrayRg16 ast::type::ImageFormat::eRg16i, RImg1DArray
#define RIImg2DArrayRg16 ast::type::ImageFormat::eRg16i, RImg2DArray
#define RIImgCubeArrayRg16 ast::type::ImageFormat::eRg16i, RImgCubeArray
#define RIImg2DMSRg16 ast::type::ImageFormat::eRg16i, RImg2DMS
#define RIImg2DMSArrayRg16 ast::type::ImageFormat::eRg16i, RImg2DMSArray
#define RIImg1DRg32 ast::type::ImageFormat::eRg32i, RImg1D
#define RIImg2DRg32 ast::type::ImageFormat::eRg32i, RImg2D
#define RIImg3DRg32 ast::type::ImageFormat::eRg32i, RImg3D
#define RIImgRectRg32 ast::type::ImageFormat::eRg32i, RImgRect
#define RIImgCubeRg32 ast::type::ImageFormat::eRg32i, RImgCube
#define RIImgBufferRg32 ast::type::ImageFormat::eRg32i, RImgBuffer
#define RIImg1DArrayRg32 ast::type::ImageFormat::eRg32i, RImg1DArray
#define RIImg2DArrayRg32 ast::type::ImageFormat::eRg32i, RImg2DArray
#define RIImgCubeArrayRg32 ast::type::ImageFormat::eRg32i, RImgCubeArray
#define RIImg2DMSRg32 ast::type::ImageFormat::eRg32i, RImg2DMS
#define RIImg2DMSArrayRg32 ast::type::ImageFormat::eRg32i, RImg2DMSArray

#define RUImg1DRg8 ast::type::ImageFormat::eRg8u, RImg1D
#define RUImg2DRg8 ast::type::ImageFormat::eRg8u, RImg2D
#define RUImg3DRg8 ast::type::ImageFormat::eRg8u, RImg3D
#define RUImgRectRg8 ast::type::ImageFormat::eRg8u, RImgRect
#define RUImgCubeRg8 ast::type::ImageFormat::eRg8u, RImgCube
#define RUImgBufferRg8 ast::type::ImageFormat::eRg8u, RImgBuffer
#define RUImg1DArrayRg8 ast::type::ImageFormat::eRg8u, RImg1DArray
#define RUImg2DArrayRg8 ast::type::ImageFormat::eRg8u, RImg2DArray
#define RUImgCubeArrayRg8 ast::type::ImageFormat::eRg8u, RImgCubeArray
#define RUImg2DMSRg8 ast::type::ImageFormat::eRg8u, RImg2DMS
#define RUImg2DMSArrayRg8 ast::type::ImageFormat::eRg8u, RImg2DMSArray
#define RUImg1DRg16 ast::type::ImageFormat::eRg16u, RImg1D
#define RUImg2DRg16 ast::type::ImageFormat::eRg16u, RImg2D
#define RUImg3DRg16 ast::type::ImageFormat::eRg16u, RImg3D
#define RUImgRectRg16 ast::type::ImageFormat::eRg16u, RImgRect
#define RUImgCubeRg16 ast::type::ImageFormat::eRg16u, RImgCube
#define RUImgBufferRg16 ast::type::ImageFormat::eRg16u, RImgBuffer
#define RUImg1DArrayRg16 ast::type::ImageFormat::eRg16u, RImg1DArray
#define RUImg2DArrayRg16 ast::type::ImageFormat::eRg16u, RImg2DArray
#define RUImgCubeArrayRg16 ast::type::ImageFormat::eRg16u, RImgCubeArray
#define RUImg2DMSRg16 ast::type::ImageFormat::eRg16u, RImg2DMS
#define RUImg2DMSArrayRg16 ast::type::ImageFormat::eRg16u, RImg2DMSArray
#define RUImg1DRg32 ast::type::ImageFormat::eRg32u, RImg1D
#define RUImg2DRg32 ast::type::ImageFormat::eRg32u, RImg2D
#define RUImg3DRg32 ast::type::ImageFormat::eRg32u, RImg3D
#define RUImgRectRg32 ast::type::ImageFormat::eRg32u, RImgRect
#define RUImgCubeRg32 ast::type::ImageFormat::eRg32u, RImgCube
#define RUImgBufferRg32 ast::type::ImageFormat::eRg32u, RImgBuffer
#define RUImg1DArrayRg32 ast::type::ImageFormat::eRg32u, RImg1DArray
#define RUImg2DArrayRg32 ast::type::ImageFormat::eRg32u, RImg2DArray
#define RUImgCubeArrayRg32 ast::type::ImageFormat::eRg32u, RImgCubeArray
#define RUImg2DMSRg32 ast::type::ImageFormat::eRg32u, RImg2DMS
#define RUImg2DMSArrayRg32 ast::type::ImageFormat::eRg32u, RImg2DMSArray

#define RFImg1DR16 ast::type::ImageFormat::eR16f, RImg1D
#define RFImg2DR16 ast::type::ImageFormat::eR16f, RImg2D
#define RFImg3DR16 ast::type::ImageFormat::eR16f, RImg3D
#define RFImgRectR16 ast::type::ImageFormat::eR16f, RImgRect
#define RFImgCubeR16 ast::type::ImageFormat::eR16f, RImgCube
#define RFImgBufferR16 ast::type::ImageFormat::eR16f, RImgBuffer
#define RFImg1DArrayR16 ast::type::ImageFormat::eR16f, RImg1DArray
#define RFImg2DArrayR16 ast::type::ImageFormat::eR16f, RImg2DArray
#define RFImgCubeArrayR16 ast::type::ImageFormat::eR16f, RImgCubeArray
#define RFImg2DMSR16 ast::type::ImageFormat::eR16f, RImg2DMS
#define RFImg2DMSArrayR16 ast::type::ImageFormat::eR16f, RImg2DMSArray
#define RFImg1DR32 ast::type::ImageFormat::eR32f, RImg1D
#define RFImg2DR32 ast::type::ImageFormat::eR32f, RImg2D
#define RFImg3DR32 ast::type::ImageFormat::eR32f, RImg3D
#define RFImgRectR32 ast::type::ImageFormat::eR32f, RImgRect
#define RFImgCubeR32 ast::type::ImageFormat::eR32f, RImgCube
#define RFImgBufferR32 ast::type::ImageFormat::eR32f, RImgBuffer
#define RFImg1DArrayR32 ast::type::ImageFormat::eR32f, RImg1DArray
#define RFImg2DArrayR32 ast::type::ImageFormat::eR32f, RImg2DArray
#define RFImgCubeArrayR32 ast::type::ImageFormat::eR32f, RImgCubeArray
#define RFImg2DMSR32 ast::type::ImageFormat::eR32f, RImg2DMS
#define RFImg2DMSArrayR32 ast::type::ImageFormat::eR32f, RImg2DMSArray

#define RIImg1DR8 ast::type::ImageFormat::eR8i, RImg1D
#define RIImg2DR8 ast::type::ImageFormat::eR8i, RImg2D
#define RIImg3DR8 ast::type::ImageFormat::eR8i, RImg3D
#define RIImgRectR8 ast::type::ImageFormat::eR8i, RImgRect
#define RIImgCubeR8 ast::type::ImageFormat::eR8i, RImgCube
#define RIImgBufferR8 ast::type::ImageFormat::eR8i, RImgBuffer
#define RIImg1DArrayR8 ast::type::ImageFormat::eR8i, RImg1DArray
#define RIImg2DArrayR8 ast::type::ImageFormat::eR8i, RImg2DArray
#define RIImgCubeArrayR8 ast::type::ImageFormat::eR8i, RImgCubeArray
#define RIImg2DMSR8 ast::type::ImageFormat::eR8i, RImg2DMS
#define RIImg2DMSArrayR8 ast::type::ImageFormat::eR8i, RImg2DMSArray
#define RIImg1DR16 ast::type::ImageFormat::eR16i, RImg1D
#define RIImg2DR16 ast::type::ImageFormat::eR16i, RImg2D
#define RIImg3DR16 ast::type::ImageFormat::eR16i, RImg3D
#define RIImgRectR16 ast::type::ImageFormat::eR16i, RImgRect
#define RIImgCubeR16 ast::type::ImageFormat::eR16i, RImgCube
#define RIImgBufferR16 ast::type::ImageFormat::eR16i, RImgBuffer
#define RIImg1DArrayR16 ast::type::ImageFormat::eR16i, RImg1DArray
#define RIImg2DArrayR16 ast::type::ImageFormat::eR16i, RImg2DArray
#define RIImgCubeArrayR16 ast::type::ImageFormat::eR16i, RImgCubeArray
#define RIImg2DMSR16 ast::type::ImageFormat::eR16i, RImg2DMS
#define RIImg2DMSArrayR16 ast::type::ImageFormat::eR16i, RImg2DMSArray
#define RIImg1DR32 ast::type::ImageFormat::eR32i, RImg1D
#define RIImg2DR32 ast::type::ImageFormat::eR32i, RImg2D
#define RIImg3DR32 ast::type::ImageFormat::eR32i, RImg3D
#define RIImgRectR32 ast::type::ImageFormat::eR32i, RImgRect
#define RIImgCubeR32 ast::type::ImageFormat::eR32i, RImgCube
#define RIImgBufferR32 ast::type::ImageFormat::eR32i, RImgBuffer
#define RIImg1DArrayR32 ast::type::ImageFormat::eR32i, RImg1DArray
#define RIImg2DArrayR32 ast::type::ImageFormat::eR32i, RImg2DArray
#define RIImgCubeArrayR32 ast::type::ImageFormat::eR32i, RImgCubeArray
#define RIImg2DMSR32 ast::type::ImageFormat::eR32i, RImg2DMS
#define RIImg2DMSArrayR32 ast::type::ImageFormat::eR32i, RImg2DMSArray

#define RUImg1DR8 ast::type::ImageFormat::eR8u, RImg1D
#define RUImg2DR8 ast::type::ImageFormat::eR8u, RImg2D
#define RUImg3DR8 ast::type::ImageFormat::eR8u, RImg3D
#define RUImgRectR8 ast::type::ImageFormat::eR8u, RImgRect
#define RUImgCubeR8 ast::type::ImageFormat::eR8u, RImgCube
#define RUImgBufferR8 ast::type::ImageFormat::eR8u, RImgBuffer
#define RUImg1DArrayR8 ast::type::ImageFormat::eR8u, RImg1DArray
#define RUImg2DArrayR8 ast::type::ImageFormat::eR8u, RImg2DArray
#define RUImgCubeArrayR8 ast::type::ImageFormat::eR8u, RImgCubeArray
#define RUImg2DMSR8 ast::type::ImageFormat::eR8u, RImg2DMS
#define RUImg2DMSArrayR8 ast::type::ImageFormat::eR8u, RImg2DMSArray
#define RUImg1DR16 ast::type::ImageFormat::eR16u, RImg1D
#define RUImg2DR16 ast::type::ImageFormat::eR16u, RImg2D
#define RUImg3DR16 ast::type::ImageFormat::eR16u, RImg3D
#define RUImgRectR16 ast::type::ImageFormat::eR16u, RImgRect
#define RUImgCubeR16 ast::type::ImageFormat::eR16u, RImgCube
#define RUImgBufferR16 ast::type::ImageFormat::eR16u, RImgBuffer
#define RUImg1DArrayR16 ast::type::ImageFormat::eR16u, RImg1DArray
#define RUImg2DArrayR16 ast::type::ImageFormat::eR16u, RImg2DArray
#define RUImgCubeArrayR16 ast::type::ImageFormat::eR16u, RImgCubeArray
#define RUImg2DMSR16 ast::type::ImageFormat::eR16u, RImg2DMS
#define RUImg2DMSArrayR16 ast::type::ImageFormat::eR16u, RImg2DMSArray
#define RUImg1DR32 ast::type::ImageFormat::eR32u, RImg1D
#define RUImg2DR32 ast::type::ImageFormat::eR32u, RImg2D
#define RUImg3DR32 ast::type::ImageFormat::eR32u, RImg3D
#define RUImgRectR32 ast::type::ImageFormat::eR32u, RImgRect
#define RUImgCubeR32 ast::type::ImageFormat::eR32u, RImgCube
#define RUImgBufferR32 ast::type::ImageFormat::eR32u, RImgBuffer
#define RUImg1DArrayR32 ast::type::ImageFormat::eR32u, RImg1DArray
#define RUImg2DArrayR32 ast::type::ImageFormat::eR32u, RImg2DArray
#define RUImgCubeArrayR32 ast::type::ImageFormat::eR32u, RImgCubeArray
#define RUImg2DMSR32 ast::type::ImageFormat::eR32u, RImg2DMS
#define RUImg2DMSArrayR32 ast::type::ImageFormat::eR32u, RImg2DMSArray

#define WImg1D ast::type::AccessKind::eWrite, ast::type::ImageDim::e1D, false, false, false
#define WImg2D ast::type::AccessKind::eWrite, ast::type::ImageDim::e2D, false, false, false
#define WImg3D ast::type::AccessKind::eWrite, ast::type::ImageDim::e3D, false, false, false
#define WImgRect ast::type::AccessKind::eWrite, ast::type::ImageDim::eRect, false, false, false
#define WImgCube ast::type::AccessKind::eWrite, ast::type::ImageDim::eCube, false, false, false
#define WImgBuffer ast::type::AccessKind::eWrite, ast::type::ImageDim::eBuffer, false, false, false
#define WImg1DArray ast::type::AccessKind::eWrite, ast::type::ImageDim::e1D, true, false, false
#define WImg2DArray ast::type::AccessKind::eWrite, ast::type::ImageDim::e2D, true, false, false
#define WImgCubeArray ast::type::AccessKind::eWrite, ast::type::ImageDim::eCube, true, false, false
#define WImg2DMS ast::type::AccessKind::eWrite, ast::type::ImageDim::e2D, false, false, true
#define WImg2DMSArray ast::type::AccessKind::eWrite, ast::type::ImageDim::e2D, true, false, true
#define WImg1DShadow ast::type::AccessKind::eWrite, ast::type::ImageDim::e1D, false, true, false
#define WImg2DShadow ast::type::AccessKind::eWrite, ast::type::ImageDim::e2D, false, true, false
#define WImgRectShadow ast::type::AccessKind::eWrite, ast::type::ImageDim::eRect, false, true, false
#define WImgCubeShadow ast::type::AccessKind::eWrite, ast::type::ImageDim::eCube, false, true, false
#define WImg1DArrayShadow ast::type::AccessKind::eWrite, ast::type::ImageDim::e1D, true, true, false
#define WImg2DArrayShadow ast::type::AccessKind::eWrite, ast::type::ImageDim::e2D, true, true, false
#define WImgCubeArrayShadow ast::type::AccessKind::eWrite, ast::type::ImageDim::eCube, true, true, false

#define WFImg1DRgba16 ast::type::ImageFormat::eRgba16f, WImg1D
#define WFImg2DRgba16 ast::type::ImageFormat::eRgba16f, WImg2D
#define WFImg3DRgba16 ast::type::ImageFormat::eRgba16f, WImg3D
#define WFImgRectRgba16 ast::type::ImageFormat::eRgba16f, WImgRect
#define WFImgCubeRgba16 ast::type::ImageFormat::eRgba16f, WImgCube
#define WFImgBufferRgba16 ast::type::ImageFormat::eRgba16f, WImgBuffer
#define WFImg1DArrayRgba16 ast::type::ImageFormat::eRgba16f, WImg1DArray
#define WFImg2DArrayRgba16 ast::type::ImageFormat::eRgba16f, WImg2DArray
#define WFImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16f, WImgCubeArray
#define WFImg2DMSRgba16 ast::type::ImageFormat::eRgba16f, WImg2DMS
#define WFImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16f, WImg2DMSArray
#define WFImg1DShadowR16 ast::type::ImageFormat::eR16f, WImg1DShadow
#define WFImg2DShadowR16 ast::type::ImageFormat::eR16f, WImg2DShadow
#define WFImgRectShadowR16 ast::type::ImageFormat::eR16f, WImgRectShadow
#define WFImgCubeShadowR16 ast::type::ImageFormat::eR16f, WImgCubeShadow
#define WFImg1DArrayShadowR16 ast::type::ImageFormat::eR16f, WImg1DArrayShadow
#define WFImg2DArrayShadowR16 ast::type::ImageFormat::eR16f, WImg2DArrayShadow
#define WFImgCubeArrayShadowR16 ast::type::ImageFormat::eR16f, WImgCubeArrayShadow
#define WFImg1DRgba32 ast::type::ImageFormat::eRgba32f, WImg1D
#define WFImg2DRgba32 ast::type::ImageFormat::eRgba32f, WImg2D
#define WFImg3DRgba32 ast::type::ImageFormat::eRgba32f, WImg3D
#define WFImgRectRgba32 ast::type::ImageFormat::eRgba32f, WImgRect
#define WFImgCubeRgba32 ast::type::ImageFormat::eRgba32f, WImgCube
#define WFImgBufferRgba32 ast::type::ImageFormat::eRgba32f, WImgBuffer
#define WFImg1DArrayRgba32 ast::type::ImageFormat::eRgba32f, WImg1DArray
#define WFImg2DArrayRgba32 ast::type::ImageFormat::eRgba32f, WImg2DArray
#define WFImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32f, WImgCubeArray
#define WFImg2DMSRgba32 ast::type::ImageFormat::eRgba32f, WImg2DMS
#define WFImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32f, WImg2DMSArray
#define WFImg1DShadowR32 ast::type::ImageFormat::eR32f, WImg1DShadow
#define WFImg2DShadowR32 ast::type::ImageFormat::eR32f, WImg2DShadow
#define WFImgRectShadowR32 ast::type::ImageFormat::eR32f, WImgRectShadow
#define WFImgCubeShadowR32 ast::type::ImageFormat::eR32f, WImgCubeShadow
#define WFImg1DArrayShadowR32 ast::type::ImageFormat::eR32f, WImg1DArrayShadow
#define WFImg2DArrayShadowR32 ast::type::ImageFormat::eR32f, WImg2DArrayShadow
#define WFImgCubeArrayShadowR32 ast::type::ImageFormat::eR32f, WImgCubeArrayShadow

#define WIImg1DRgba8 ast::type::ImageFormat::eRgba8i, WImg1D
#define WIImg2DRgba8 ast::type::ImageFormat::eRgba8i, WImg2D
#define WIImg3DRgba8 ast::type::ImageFormat::eRgba8i, WImg3D
#define WIImgRectRgba8 ast::type::ImageFormat::eRgba8i, WImgRect
#define WIImgCubeRgba8 ast::type::ImageFormat::eRgba8i, WImgCube
#define WIImgBufferRgba8 ast::type::ImageFormat::eRgba8i, WImgBuffer
#define WIImg1DArrayRgba8 ast::type::ImageFormat::eRgba8i, WImg1DArray
#define WIImg2DArrayRgba8 ast::type::ImageFormat::eRgba8i, WImg2DArray
#define WIImgCubeArrayRgba8 ast::type::ImageFormat::eRgba8i, WImgCubeArray
#define WIImg2DMSRgba8 ast::type::ImageFormat::eRgba8i, WImg2DMS
#define WIImg2DMSArrayRgba8 ast::type::ImageFormat::eRgba8i, WImg2DMSArray
#define WIImg1DRgba16 ast::type::ImageFormat::eRgba16i, WImg1D
#define WIImg2DRgba16 ast::type::ImageFormat::eRgba16i, WImg2D
#define WIImg3DRgba16 ast::type::ImageFormat::eRgba16i, WImg3D
#define WIImgRectRgba16 ast::type::ImageFormat::eRgba16i, WImgRect
#define WIImgCubeRgba16 ast::type::ImageFormat::eRgba16i, WImgCube
#define WIImgBufferRgba16 ast::type::ImageFormat::eRgba16i, WImgBuffer
#define WIImg1DArrayRgba16 ast::type::ImageFormat::eRgba16i, WImg1DArray
#define WIImg2DArrayRgba16 ast::type::ImageFormat::eRgba16i, WImg2DArray
#define WIImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16i, WImgCubeArray
#define WIImg2DMSRgba16 ast::type::ImageFormat::eRgba16i, WImg2DMS
#define WIImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16i, WImg2DMSArray
#define WIImg1DRgba32 ast::type::ImageFormat::eRgba32i, WImg1D
#define WIImg2DRgba32 ast::type::ImageFormat::eRgba32i, WImg2D
#define WIImg3DRgba32 ast::type::ImageFormat::eRgba32i, WImg3D
#define WIImgRectRgba32 ast::type::ImageFormat::eRgba32i, WImgRect
#define WIImgCubeRgba32 ast::type::ImageFormat::eRgba32i, WImgCube
#define WIImgBufferRgba32 ast::type::ImageFormat::eRgba32i, WImgBuffer
#define WIImg1DArrayRgba32 ast::type::ImageFormat::eRgba32i, WImg1DArray
#define WIImg2DArrayRgba32 ast::type::ImageFormat::eRgba32i, WImg2DArray
#define WIImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32i, WImgCubeArray
#define WIImg2DMSRgba32 ast::type::ImageFormat::eRgba32i, WImg2DMS
#define WIImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32i, WImg2DMSArray

#define WUImg1DRgba8 ast::type::ImageFormat::eRgba8u, WImg1D
#define WUImg2DRgba8 ast::type::ImageFormat::eRgba8u, WImg2D
#define WUImg3DRgba8 ast::type::ImageFormat::eRgba8u, WImg3D
#define WUImgRectRgba8 ast::type::ImageFormat::eRgba8u, WImgRect
#define WUImgCubeRgba8 ast::type::ImageFormat::eRgba8u, WImgCube
#define WUImgBufferRgba8 ast::type::ImageFormat::eRgba8u, WImgBuffer
#define WUImg1DArrayRgba8 ast::type::ImageFormat::eRgba8u, WImg1DArray
#define WUImg2DArrayRgba8 ast::type::ImageFormat::eRgba8u, WImg2DArray
#define WUImgCubeArrayRgba8 ast::type::ImageFormat::eRgba8u, WImgCubeArray
#define WUImg2DMSRgba8 ast::type::ImageFormat::eRgba8u, WImg2DMS
#define WUImg2DMSArrayRgba8 ast::type::ImageFormat::eRgba8u, WImg2DMSArray
#define WUImg1DRgba16 ast::type::ImageFormat::eRgba16u, WImg1D
#define WUImg2DRgba16 ast::type::ImageFormat::eRgba16u, WImg2D
#define WUImg3DRgba16 ast::type::ImageFormat::eRgba16u, WImg3D
#define WUImgRectRgba16 ast::type::ImageFormat::eRgba16u, WImgRect
#define WUImgCubeRgba16 ast::type::ImageFormat::eRgba16u, WImgCube
#define WUImgBufferRgba16 ast::type::ImageFormat::eRgba16u, WImgBuffer
#define WUImg1DArrayRgba16 ast::type::ImageFormat::eRgba16u, WImg1DArray
#define WUImg2DArrayRgba16 ast::type::ImageFormat::eRgba16u, WImg2DArray
#define WUImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16u, WImgCubeArray
#define WUImg2DMSRgba16 ast::type::ImageFormat::eRgba16u, WImg2DMS
#define WUImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16u, WImg2DMSArray
#define WUImg1DRgba32 ast::type::ImageFormat::eRgba32u, WImg1D
#define WUImg2DRgba32 ast::type::ImageFormat::eRgba32u, WImg2D
#define WUImg3DRgba32 ast::type::ImageFormat::eRgba32u, WImg3D
#define WUImgRectRgba32 ast::type::ImageFormat::eRgba32u, WImgRect
#define WUImgCubeRgba32 ast::type::ImageFormat::eRgba32u, WImgCube
#define WUImgBufferRgba32 ast::type::ImageFormat::eRgba32u, WImgBuffer
#define WUImg1DArrayRgba32 ast::type::ImageFormat::eRgba32u, WImg1DArray
#define WUImg2DArrayRgba32 ast::type::ImageFormat::eRgba32u, WImg2DArray
#define WUImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32u, WImgCubeArray
#define WUImg2DMSRgba32 ast::type::ImageFormat::eRgba32u, WImg2DMS
#define WUImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32u, WImg2DMSArray

#define WFImg1DRg16 ast::type::ImageFormat::eRg16f, WImg1D
#define WFImg2DRg16 ast::type::ImageFormat::eRg16f, WImg2D
#define WFImg3DRg16 ast::type::ImageFormat::eRg16f, WImg3D
#define WFImgRectRg16 ast::type::ImageFormat::eRg16f, WImgRect
#define WFImgCubeRg16 ast::type::ImageFormat::eRg16f, WImgCube
#define WFImgBufferRg16 ast::type::ImageFormat::eRg16f, WImgBuffer
#define WFImg1DArrayRg16 ast::type::ImageFormat::eRg16f, WImg1DArray
#define WFImg2DArrayRg16 ast::type::ImageFormat::eRg16f, WImg2DArray
#define WFImgCubeArrayRg16 ast::type::ImageFormat::eRg16f, WImgCubeArray
#define WFImg2DMSRg16 ast::type::ImageFormat::eRg16f, WImg2DMS
#define WFImg2DMSArrayRg16 ast::type::ImageFormat::eRg16f, WImg2DMSArray
#define WFImg1DRg32 ast::type::ImageFormat::eRg32f, WImg1D
#define WFImg2DRg32 ast::type::ImageFormat::eRg32f, WImg2D
#define WFImg3DRg32 ast::type::ImageFormat::eRg32f, WImg3D
#define WFImgRectRg32 ast::type::ImageFormat::eRg32f, WImgRect
#define WFImgCubeRg32 ast::type::ImageFormat::eRg32f, WImgCube
#define WFImgBufferRg32 ast::type::ImageFormat::eRg32f, WImgBuffer
#define WFImg1DArrayRg32 ast::type::ImageFormat::eRg32f, WImg1DArray
#define WFImg2DArrayRg32 ast::type::ImageFormat::eRg32f, WImg2DArray
#define WFImgCubeArrayRg32 ast::type::ImageFormat::eRg32f, WImgCubeArray
#define WFImg2DMSRg32 ast::type::ImageFormat::eRg32f, WImg2DMS
#define WFImg2DMSArrayRg32 ast::type::ImageFormat::eRg32f, WImg2DMSArray

#define WIImg1DRg8 ast::type::ImageFormat::eRg8i, WImg1D
#define WIImg2DRg8 ast::type::ImageFormat::eRg8i, WImg2D
#define WIImg3DRg8 ast::type::ImageFormat::eRg8i, WImg3D
#define WIImgRectRg8 ast::type::ImageFormat::eRg8i, WImgRect
#define WIImgCubeRg8 ast::type::ImageFormat::eRg8i, WImgCube
#define WIImgBufferRg8 ast::type::ImageFormat::eRg8i, WImgBuffer
#define WIImg1DArrayRg8 ast::type::ImageFormat::eRg8i, WImg1DArray
#define WIImg2DArrayRg8 ast::type::ImageFormat::eRg8i, WImg2DArray
#define WIImgCubeArrayRg8 ast::type::ImageFormat::eRg8i, WImgCubeArray
#define WIImg2DMSRg8 ast::type::ImageFormat::eRg8i, WImg2DMS
#define WIImg2DMSArrayRg8 ast::type::ImageFormat::eRg8i, WImg2DMSArray
#define WIImg1DRg16 ast::type::ImageFormat::eRg16i, WImg1D
#define WIImg2DRg16 ast::type::ImageFormat::eRg16i, WImg2D
#define WIImg3DRg16 ast::type::ImageFormat::eRg16i, WImg3D
#define WIImgRectRg16 ast::type::ImageFormat::eRg16i, WImgRect
#define WIImgCubeRg16 ast::type::ImageFormat::eRg16i, WImgCube
#define WIImgBufferRg16 ast::type::ImageFormat::eRg16i, WImgBuffer
#define WIImg1DArrayRg16 ast::type::ImageFormat::eRg16i, WImg1DArray
#define WIImg2DArrayRg16 ast::type::ImageFormat::eRg16i, WImg2DArray
#define WIImgCubeArrayRg16 ast::type::ImageFormat::eRg16i, WImgCubeArray
#define WIImg2DMSRg16 ast::type::ImageFormat::eRg16i, WImg2DMS
#define WIImg2DMSArrayRg16 ast::type::ImageFormat::eRg16i, WImg2DMSArray
#define WIImg1DRg32 ast::type::ImageFormat::eRg32i, WImg1D
#define WIImg2DRg32 ast::type::ImageFormat::eRg32i, WImg2D
#define WIImg3DRg32 ast::type::ImageFormat::eRg32i, WImg3D
#define WIImgRectRg32 ast::type::ImageFormat::eRg32i, WImgRect
#define WIImgCubeRg32 ast::type::ImageFormat::eRg32i, WImgCube
#define WIImgBufferRg32 ast::type::ImageFormat::eRg32i, WImgBuffer
#define WIImg1DArrayRg32 ast::type::ImageFormat::eRg32i, WImg1DArray
#define WIImg2DArrayRg32 ast::type::ImageFormat::eRg32i, WImg2DArray
#define WIImgCubeArrayRg32 ast::type::ImageFormat::eRg32i, WImgCubeArray
#define WIImg2DMSRg32 ast::type::ImageFormat::eRg32i, WImg2DMS
#define WIImg2DMSArrayRg32 ast::type::ImageFormat::eRg32i, WImg2DMSArray

#define WUImg1DRg8 ast::type::ImageFormat::eRg8u, WImg1D
#define WUImg2DRg8 ast::type::ImageFormat::eRg8u, WImg2D
#define WUImg3DRg8 ast::type::ImageFormat::eRg8u, WImg3D
#define WUImgRectRg8 ast::type::ImageFormat::eRg8u, WImgRect
#define WUImgCubeRg8 ast::type::ImageFormat::eRg8u, WImgCube
#define WUImgBufferRg8 ast::type::ImageFormat::eRg8u, WImgBuffer
#define WUImg1DArrayRg8 ast::type::ImageFormat::eRg8u, WImg1DArray
#define WUImg2DArrayRg8 ast::type::ImageFormat::eRg8u, WImg2DArray
#define WUImgCubeArrayRg8 ast::type::ImageFormat::eRg8u, WImgCubeArray
#define WUImg2DMSRg8 ast::type::ImageFormat::eRg8u, WImg2DMS
#define WUImg2DMSArrayRg8 ast::type::ImageFormat::eRg8u, WImg2DMSArray
#define WUImg1DRg16 ast::type::ImageFormat::eRg16u, WImg1D
#define WUImg2DRg16 ast::type::ImageFormat::eRg16u, WImg2D
#define WUImg3DRg16 ast::type::ImageFormat::eRg16u, WImg3D
#define WUImgRectRg16 ast::type::ImageFormat::eRg16u, WImgRect
#define WUImgCubeRg16 ast::type::ImageFormat::eRg16u, WImgCube
#define WUImgBufferRg16 ast::type::ImageFormat::eRg16u, WImgBuffer
#define WUImg1DArrayRg16 ast::type::ImageFormat::eRg16u, WImg1DArray
#define WUImg2DArrayRg16 ast::type::ImageFormat::eRg16u, WImg2DArray
#define WUImgCubeArrayRg16 ast::type::ImageFormat::eRg16u, WImgCubeArray
#define WUImg2DMSRg16 ast::type::ImageFormat::eRg16u, WImg2DMS
#define WUImg2DMSArrayRg16 ast::type::ImageFormat::eRg16u, WImg2DMSArray
#define WUImg1DRg32 ast::type::ImageFormat::eRg32u, WImg1D
#define WUImg2DRg32 ast::type::ImageFormat::eRg32u, WImg2D
#define WUImg3DRg32 ast::type::ImageFormat::eRg32u, WImg3D
#define WUImgRectRg32 ast::type::ImageFormat::eRg32u, WImgRect
#define WUImgCubeRg32 ast::type::ImageFormat::eRg32u, WImgCube
#define WUImgBufferRg32 ast::type::ImageFormat::eRg32u, WImgBuffer
#define WUImg1DArrayRg32 ast::type::ImageFormat::eRg32u, WImg1DArray
#define WUImg2DArrayRg32 ast::type::ImageFormat::eRg32u, WImg2DArray
#define WUImgCubeArrayRg32 ast::type::ImageFormat::eRg32u, WImgCubeArray
#define WUImg2DMSRg32 ast::type::ImageFormat::eRg32u, WImg2DMS
#define WUImg2DMSArrayRg32 ast::type::ImageFormat::eRg32u, WImg2DMSArray

#define WFImg1DR16 ast::type::ImageFormat::eR16f, WImg1D
#define WFImg2DR16 ast::type::ImageFormat::eR16f, WImg2D
#define WFImg3DR16 ast::type::ImageFormat::eR16f, WImg3D
#define WFImgRectR16 ast::type::ImageFormat::eR16f, WImgRect
#define WFImgCubeR16 ast::type::ImageFormat::eR16f, WImgCube
#define WFImgBufferR16 ast::type::ImageFormat::eR16f, WImgBuffer
#define WFImg1DArrayR16 ast::type::ImageFormat::eR16f, WImg1DArray
#define WFImg2DArrayR16 ast::type::ImageFormat::eR16f, WImg2DArray
#define WFImgCubeArrayR16 ast::type::ImageFormat::eR16f, WImgCubeArray
#define WFImg2DMSR16 ast::type::ImageFormat::eR16f, WImg2DMS
#define WFImg2DMSArrayR16 ast::type::ImageFormat::eR16f, WImg2DMSArray
#define WFImg1DR32 ast::type::ImageFormat::eR32f, WImg1D
#define WFImg2DR32 ast::type::ImageFormat::eR32f, WImg2D
#define WFImg3DR32 ast::type::ImageFormat::eR32f, WImg3D
#define WFImgRectR32 ast::type::ImageFormat::eR32f, WImgRect
#define WFImgCubeR32 ast::type::ImageFormat::eR32f, WImgCube
#define WFImgBufferR32 ast::type::ImageFormat::eR32f, WImgBuffer
#define WFImg1DArrayR32 ast::type::ImageFormat::eR32f, WImg1DArray
#define WFImg2DArrayR32 ast::type::ImageFormat::eR32f, WImg2DArray
#define WFImgCubeArrayR32 ast::type::ImageFormat::eR32f, WImgCubeArray
#define WFImg2DMSR32 ast::type::ImageFormat::eR32f, WImg2DMS
#define WFImg2DMSArrayR32 ast::type::ImageFormat::eR32f, WImg2DMSArray

#define WIImg1DR8 ast::type::ImageFormat::eR8i, WImg1D
#define WIImg2DR8 ast::type::ImageFormat::eR8i, WImg2D
#define WIImg3DR8 ast::type::ImageFormat::eR8i, WImg3D
#define WIImgRectR8 ast::type::ImageFormat::eR8i, WImgRect
#define WIImgCubeR8 ast::type::ImageFormat::eR8i, WImgCube
#define WIImgBufferR8 ast::type::ImageFormat::eR8i, WImgBuffer
#define WIImg1DArrayR8 ast::type::ImageFormat::eR8i, WImg1DArray
#define WIImg2DArrayR8 ast::type::ImageFormat::eR8i, WImg2DArray
#define WIImgCubeArrayR8 ast::type::ImageFormat::eR8i, WImgCubeArray
#define WIImg2DMSR8 ast::type::ImageFormat::eR8i, WImg2DMS
#define WIImg2DMSArrayR8 ast::type::ImageFormat::eR8i, WImg2DMSArray
#define WIImg1DR16 ast::type::ImageFormat::eR16i, WImg1D
#define WIImg2DR16 ast::type::ImageFormat::eR16i, WImg2D
#define WIImg3DR16 ast::type::ImageFormat::eR16i, WImg3D
#define WIImgRectR16 ast::type::ImageFormat::eR16i, WImgRect
#define WIImgCubeR16 ast::type::ImageFormat::eR16i, WImgCube
#define WIImgBufferR16 ast::type::ImageFormat::eR16i, WImgBuffer
#define WIImg1DArrayR16 ast::type::ImageFormat::eR16i, WImg1DArray
#define WIImg2DArrayR16 ast::type::ImageFormat::eR16i, WImg2DArray
#define WIImgCubeArrayR16 ast::type::ImageFormat::eR16i, WImgCubeArray
#define WIImg2DMSR16 ast::type::ImageFormat::eR16i, WImg2DMS
#define WIImg2DMSArrayR16 ast::type::ImageFormat::eR16i, WImg2DMSArray
#define WIImg1DR32 ast::type::ImageFormat::eR32i, WImg1D
#define WIImg2DR32 ast::type::ImageFormat::eR32i, WImg2D
#define WIImg3DR32 ast::type::ImageFormat::eR32i, WImg3D
#define WIImgRectR32 ast::type::ImageFormat::eR32i, WImgRect
#define WIImgCubeR32 ast::type::ImageFormat::eR32i, WImgCube
#define WIImgBufferR32 ast::type::ImageFormat::eR32i, WImgBuffer
#define WIImg1DArrayR32 ast::type::ImageFormat::eR32i, WImg1DArray
#define WIImg2DArrayR32 ast::type::ImageFormat::eR32i, WImg2DArray
#define WIImgCubeArrayR32 ast::type::ImageFormat::eR32i, WImgCubeArray
#define WIImg2DMSR32 ast::type::ImageFormat::eR32i, WImg2DMS
#define WIImg2DMSArrayR32 ast::type::ImageFormat::eR32i, WImg2DMSArray

#define WUImg1DR8 ast::type::ImageFormat::eR8u, WImg1D
#define WUImg2DR8 ast::type::ImageFormat::eR8u, WImg2D
#define WUImg3DR8 ast::type::ImageFormat::eR8u, WImg3D
#define WUImgRectR8 ast::type::ImageFormat::eR8u, WImgRect
#define WUImgCubeR8 ast::type::ImageFormat::eR8u, WImgCube
#define WUImgBufferR8 ast::type::ImageFormat::eR8u, WImgBuffer
#define WUImg1DArrayR8 ast::type::ImageFormat::eR8u, WImg1DArray
#define WUImg2DArrayR8 ast::type::ImageFormat::eR8u, WImg2DArray
#define WUImgCubeArrayR8 ast::type::ImageFormat::eR8u, WImgCubeArray
#define WUImg2DMSR8 ast::type::ImageFormat::eR8u, WImg2DMS
#define WUImg2DMSArrayR8 ast::type::ImageFormat::eR8u, WImg2DMSArray
#define WUImg1DR16 ast::type::ImageFormat::eR16u, WImg1D
#define WUImg2DR16 ast::type::ImageFormat::eR16u, WImg2D
#define WUImg3DR16 ast::type::ImageFormat::eR16u, WImg3D
#define WUImgRectR16 ast::type::ImageFormat::eR16u, WImgRect
#define WUImgCubeR16 ast::type::ImageFormat::eR16u, WImgCube
#define WUImgBufferR16 ast::type::ImageFormat::eR16u, WImgBuffer
#define WUImg1DArrayR16 ast::type::ImageFormat::eR16u, WImg1DArray
#define WUImg2DArrayR16 ast::type::ImageFormat::eR16u, WImg2DArray
#define WUImgCubeArrayR16 ast::type::ImageFormat::eR16u, WImgCubeArray
#define WUImg2DMSR16 ast::type::ImageFormat::eR16u, WImg2DMS
#define WUImg2DMSArrayR16 ast::type::ImageFormat::eR16u, WImg2DMSArray
#define WUImg1DR32 ast::type::ImageFormat::eR32u, WImg1D
#define WUImg2DR32 ast::type::ImageFormat::eR32u, WImg2D
#define WUImg3DR32 ast::type::ImageFormat::eR32u, WImg3D
#define WUImgRectR32 ast::type::ImageFormat::eR32u, WImgRect
#define WUImgCubeR32 ast::type::ImageFormat::eR32u, WImgCube
#define WUImgBufferR32 ast::type::ImageFormat::eR32u, WImgBuffer
#define WUImg1DArrayR32 ast::type::ImageFormat::eR32u, WImg1DArray
#define WUImg2DArrayR32 ast::type::ImageFormat::eR32u, WImg2DArray
#define WUImgCubeArrayR32 ast::type::ImageFormat::eR32u, WImgCubeArray
#define WUImg2DMSR32 ast::type::ImageFormat::eR32u, WImg2DMS
#define WUImg2DMSArrayR32 ast::type::ImageFormat::eR32u, WImg2DMSArray

#define RWimg1D ast::type::AccessKind::eReadWrite, ast::type::ImageDim::e1D, false, false, false
#define RWimg2D ast::type::AccessKind::eReadWrite, ast::type::ImageDim::e2D, false, false, false
#define RWimg3D ast::type::AccessKind::eReadWrite, ast::type::ImageDim::e3D, false, false, false
#define RWimgRect ast::type::AccessKind::eReadWrite, ast::type::ImageDim::eRect, false, false, false
#define RWimgCube ast::type::AccessKind::eReadWrite, ast::type::ImageDim::eCube, false, false, false
#define RWimgBuffer ast::type::AccessKind::eReadWrite, ast::type::ImageDim::eBuffer, false, false, false
#define RWimg1DArray ast::type::AccessKind::eReadWrite, ast::type::ImageDim::e1D, true, false, false
#define RWimg2DArray ast::type::AccessKind::eReadWrite, ast::type::ImageDim::e2D, true, false, false
#define RWimgCubeArray ast::type::AccessKind::eReadWrite, ast::type::ImageDim::eCube, true, false, false
#define RWimg2DMS ast::type::AccessKind::eReadWrite, ast::type::ImageDim::e2D, false, false, true
#define RWimg2DMSArray ast::type::AccessKind::eReadWrite, ast::type::ImageDim::e2D, true, false, true
#define RWimg1DShadow ast::type::AccessKind::eReadWrite, ast::type::ImageDim::e1D, false, true, false
#define RWimg2DShadow ast::type::AccessKind::eReadWrite, ast::type::ImageDim::e2D, false, true, false
#define RWimgRectShadow ast::type::AccessKind::eReadWrite, ast::type::ImageDim::eRect, false, true, false
#define RWimgCubeShadow ast::type::AccessKind::eReadWrite, ast::type::ImageDim::eCube, false, true, false
#define RWimg1DArrayShadow ast::type::AccessKind::eReadWrite, ast::type::ImageDim::e1D, true, true, false
#define RWimg2DArrayShadow ast::type::AccessKind::eReadWrite, ast::type::ImageDim::e2D, true, true, false
#define RWimgCubeArrayShadow ast::type::AccessKind::eReadWrite, ast::type::ImageDim::eCube, true, true, false

#define RWFImg1DRgba16 ast::type::ImageFormat::eRgba16f, RWimg1D
#define RWFImg2DRgba16 ast::type::ImageFormat::eRgba16f, RWimg2D
#define RWFImg3DRgba16 ast::type::ImageFormat::eRgba16f, RWimg3D
#define RWFImgRectRgba16 ast::type::ImageFormat::eRgba16f, RWimgRect
#define RWFImgCubeRgba16 ast::type::ImageFormat::eRgba16f, RWimgCube
#define RWFImgBufferRgba16 ast::type::ImageFormat::eRgba16f, RWimgBuffer
#define RWFImg1DArrayRgba16 ast::type::ImageFormat::eRgba16f, RWimg1DArray
#define RWFImg2DArrayRgba16 ast::type::ImageFormat::eRgba16f, RWimg2DArray
#define RWFImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16f, RWimgCubeArray
#define RWFImg2DMSRgba16 ast::type::ImageFormat::eRgba16f, RWimg2DMS
#define RWFImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16f, RWimg2DMSArray
#define RWFImg1DShadowR16 ast::type::ImageFormat::eR16f, RWimg1DShadow
#define RWFImg2DShadowR16 ast::type::ImageFormat::eR16f, RWimg2DShadow
#define RWFImgRectShadowR16 ast::type::ImageFormat::eR16f, RWimgRectShadow
#define RWFImgCubeShadowR16 ast::type::ImageFormat::eR16f, RWimgCubeShadow
#define RWFImg1DArrayShadowR16 ast::type::ImageFormat::eR16f, RWimg1DArrayShadow
#define RWFImg2DArrayShadowR16 ast::type::ImageFormat::eR16f, RWimg2DArrayShadow
#define RWFImgCubeArrayShadowR16 ast::type::ImageFormat::eR16f, RWimgCubeArrayShadow
#define RWFImg1DRgba32 ast::type::ImageFormat::eRgba32f, RWimg1D
#define RWFImg2DRgba32 ast::type::ImageFormat::eRgba32f, RWimg2D
#define RWFImg3DRgba32 ast::type::ImageFormat::eRgba32f, RWimg3D
#define RWFImgRectRgba32 ast::type::ImageFormat::eRgba32f, RWimgRect
#define RWFImgCubeRgba32 ast::type::ImageFormat::eRgba32f, RWimgCube
#define RWFImgBufferRgba32 ast::type::ImageFormat::eRgba32f, RWimgBuffer
#define RWFImg1DArrayRgba32 ast::type::ImageFormat::eRgba32f, RWimg1DArray
#define RWFImg2DArrayRgba32 ast::type::ImageFormat::eRgba32f, RWimg2DArray
#define RWFImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32f, RWimgCubeArray
#define RWFImg2DMSRgba32 ast::type::ImageFormat::eRgba32f, RWimg2DMS
#define RWFImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32f, RWimg2DMSArray
#define RWFImg1DShadowR32 ast::type::ImageFormat::eR32f, RWimg1DShadow
#define RWFImg2DShadowR32 ast::type::ImageFormat::eR32f, RWimg2DShadow
#define RWFImgRectShadowR32 ast::type::ImageFormat::eR32f, RWimgRectShadow
#define RWFImgCubeShadowR32 ast::type::ImageFormat::eR32f, RWimgCubeShadow
#define RWFImg1DArrayShadowR32 ast::type::ImageFormat::eR32f, RWimg1DArrayShadow
#define RWFImg2DArrayShadowR32 ast::type::ImageFormat::eR32f, RWimg2DArrayShadow
#define RWFImgCubeArrayShadowR32 ast::type::ImageFormat::eR32f, RWimgCubeArrayShadow

#define RWIImg1DRgba8 ast::type::ImageFormat::eRgba8i, RWimg1D
#define RWIImg2DRgba8 ast::type::ImageFormat::eRgba8i, RWimg2D
#define RWIImg3DRgba8 ast::type::ImageFormat::eRgba8i, RWimg3D
#define RWIImgRectRgba8 ast::type::ImageFormat::eRgba8i, RWimgRect
#define RWIImgCubeRgba8 ast::type::ImageFormat::eRgba8i, RWimgCube
#define RWIImgBufferRgba8 ast::type::ImageFormat::eRgba8i, RWimgBuffer
#define RWIImg1DArrayRgba8 ast::type::ImageFormat::eRgba8i, RWimg1DArray
#define RWIImg2DArrayRgba8 ast::type::ImageFormat::eRgba8i, RWimg2DArray
#define RWIImgCubeArrayRgba8 ast::type::ImageFormat::eRgba8i, RWimgCubeArray
#define RWIImg2DMSRgba8 ast::type::ImageFormat::eRgba8i, RWimg2DMS
#define RWIImg2DMSArrayRgba8 ast::type::ImageFormat::eRgba8i, RWimg2DMSArray
#define RWIImg1DRgba16 ast::type::ImageFormat::eRgba16i, RWimg1D
#define RWIImg2DRgba16 ast::type::ImageFormat::eRgba16i, RWimg2D
#define RWIImg3DRgba16 ast::type::ImageFormat::eRgba16i, RWimg3D
#define RWIImgRectRgba16 ast::type::ImageFormat::eRgba16i, RWimgRect
#define RWIImgCubeRgba16 ast::type::ImageFormat::eRgba16i, RWimgCube
#define RWIImgBufferRgba16 ast::type::ImageFormat::eRgba16i, RWimgBuffer
#define RWIImg1DArrayRgba16 ast::type::ImageFormat::eRgba16i, RWimg1DArray
#define RWIImg2DArrayRgba16 ast::type::ImageFormat::eRgba16i, RWimg2DArray
#define RWIImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16i, RWimgCubeArray
#define RWIImg2DMSRgba16 ast::type::ImageFormat::eRgba16i, RWimg2DMS
#define RWIImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16i, RWimg2DMSArray
#define RWIImg1DRgba32 ast::type::ImageFormat::eRgba32i, RWimg1D
#define RWIImg2DRgba32 ast::type::ImageFormat::eRgba32i, RWimg2D
#define RWIImg3DRgba32 ast::type::ImageFormat::eRgba32i, RWimg3D
#define RWIImgRectRgba32 ast::type::ImageFormat::eRgba32i, RWimgRect
#define RWIImgCubeRgba32 ast::type::ImageFormat::eRgba32i, RWimgCube
#define RWIImgBufferRgba32 ast::type::ImageFormat::eRgba32i, RWimgBuffer
#define RWIImg1DArrayRgba32 ast::type::ImageFormat::eRgba32i, RWimg1DArray
#define RWIImg2DArrayRgba32 ast::type::ImageFormat::eRgba32i, RWimg2DArray
#define RWIImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32i, RWimgCubeArray
#define RWIImg2DMSRgba32 ast::type::ImageFormat::eRgba32i, RWimg2DMS
#define RWIImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32i, RWimg2DMSArray

#define RWUImg1DRgba8 ast::type::ImageFormat::eRgba8u, RWimg1D
#define RWUImg2DRgba8 ast::type::ImageFormat::eRgba8u, RWimg2D
#define RWUImg3DRgba8 ast::type::ImageFormat::eRgba8u, RWimg3D
#define RWUImgRectRgba8 ast::type::ImageFormat::eRgba8u, RWimgRect
#define RWUImgCubeRgba8 ast::type::ImageFormat::eRgba8u, RWimgCube
#define RWUImgBufferRgba8 ast::type::ImageFormat::eRgba8u, RWimgBuffer
#define RWUImg1DArrayRgba8 ast::type::ImageFormat::eRgba8u, RWimg1DArray
#define RWUImg2DArrayRgba8 ast::type::ImageFormat::eRgba8u, RWimg2DArray
#define RWUImgCubeArrayRgba8 ast::type::ImageFormat::eRgba8u, RWimgCubeArray
#define RWUImg2DMSRgba8 ast::type::ImageFormat::eRgba8u, RWimg2DMS
#define RWUImg2DMSArrayRgba8 ast::type::ImageFormat::eRgba8u, RWimg2DMSArray
#define RWUImg1DRgba16 ast::type::ImageFormat::eRgba16u, RWimg1D
#define RWUImg2DRgba16 ast::type::ImageFormat::eRgba16u, RWimg2D
#define RWUImg3DRgba16 ast::type::ImageFormat::eRgba16u, RWimg3D
#define RWUImgRectRgba16 ast::type::ImageFormat::eRgba16u, RWimgRect
#define RWUImgCubeRgba16 ast::type::ImageFormat::eRgba16u, RWimgCube
#define RWUImgBufferRgba16 ast::type::ImageFormat::eRgba16u, RWimgBuffer
#define RWUImg1DArrayRgba16 ast::type::ImageFormat::eRgba16u, RWimg1DArray
#define RWUImg2DArrayRgba16 ast::type::ImageFormat::eRgba16u, RWimg2DArray
#define RWUImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16u, RWimgCubeArray
#define RWUImg2DMSRgba16 ast::type::ImageFormat::eRgba16u, RWimg2DMS
#define RWUImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16u, RWimg2DMSArray
#define RWUImg1DRgba32 ast::type::ImageFormat::eRgba32u, RWimg1D
#define RWUImg2DRgba32 ast::type::ImageFormat::eRgba32u, RWimg2D
#define RWUImg3DRgba32 ast::type::ImageFormat::eRgba32u, RWimg3D
#define RWUImgRectRgba32 ast::type::ImageFormat::eRgba32u, RWimgRect
#define RWUImgCubeRgba32 ast::type::ImageFormat::eRgba32u, RWimgCube
#define RWUImgBufferRgba32 ast::type::ImageFormat::eRgba32u, RWimgBuffer
#define RWUImg1DArrayRgba32 ast::type::ImageFormat::eRgba32u, RWimg1DArray
#define RWUImg2DArrayRgba32 ast::type::ImageFormat::eRgba32u, RWimg2DArray
#define RWUImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32u, RWimgCubeArray
#define RWUImg2DMSRgba32 ast::type::ImageFormat::eRgba32u, RWimg2DMS
#define RWUImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32u, RWimg2DMSArray

#define RWFImg1DRg16 ast::type::ImageFormat::eRg16f, RWimg1D
#define RWFImg2DRg16 ast::type::ImageFormat::eRg16f, RWimg2D
#define RWFImg3DRg16 ast::type::ImageFormat::eRg16f, RWimg3D
#define RWFImgRectRg16 ast::type::ImageFormat::eRg16f, RWimgRect
#define RWFImgCubeRg16 ast::type::ImageFormat::eRg16f, RWimgCube
#define RWFImgBufferRg16 ast::type::ImageFormat::eRg16f, RWimgBuffer
#define RWFImg1DArrayRg16 ast::type::ImageFormat::eRg16f, RWimg1DArray
#define RWFImg2DArrayRg16 ast::type::ImageFormat::eRg16f, RWimg2DArray
#define RWFImgCubeArrayRg16 ast::type::ImageFormat::eRg16f, RWimgCubeArray
#define RWFImg2DMSRg16 ast::type::ImageFormat::eRg16f, RWimg2DMS
#define RWFImg2DMSArrayRg16 ast::type::ImageFormat::eRg16f, RWimg2DMSArray
#define RWFImg1DRg32 ast::type::ImageFormat::eRg32f, RWimg1D
#define RWFImg2DRg32 ast::type::ImageFormat::eRg32f, RWimg2D
#define RWFImg3DRg32 ast::type::ImageFormat::eRg32f, RWimg3D
#define RWFImgRectRg32 ast::type::ImageFormat::eRg32f, RWimgRect
#define RWFImgCubeRg32 ast::type::ImageFormat::eRg32f, RWimgCube
#define RWFImgBufferRg32 ast::type::ImageFormat::eRg32f, RWimgBuffer
#define RWFImg1DArrayRg32 ast::type::ImageFormat::eRg32f, RWimg1DArray
#define RWFImg2DArrayRg32 ast::type::ImageFormat::eRg32f, RWimg2DArray
#define RWFImgCubeArrayRg32 ast::type::ImageFormat::eRg32f, RWimgCubeArray
#define RWFImg2DMSRg32 ast::type::ImageFormat::eRg32f, RWimg2DMS
#define RWFImg2DMSArrayRg32 ast::type::ImageFormat::eRg32f, RWimg2DMSArray

#define RWIImg1DRg8 ast::type::ImageFormat::eRg8i, RWimg1D
#define RWIImg2DRg8 ast::type::ImageFormat::eRg8i, RWimg2D
#define RWIImg3DRg8 ast::type::ImageFormat::eRg8i, RWimg3D
#define RWIImgRectRg8 ast::type::ImageFormat::eRg8i, RWimgRect
#define RWIImgCubeRg8 ast::type::ImageFormat::eRg8i, RWimgCube
#define RWIImgBufferRg8 ast::type::ImageFormat::eRg8i, RWimgBuffer
#define RWIImg1DArrayRg8 ast::type::ImageFormat::eRg8i, RWimg1DArray
#define RWIImg2DArrayRg8 ast::type::ImageFormat::eRg8i, RWimg2DArray
#define RWIImgCubeArrayRg8 ast::type::ImageFormat::eRg8i, RWimgCubeArray
#define RWIImg2DMSRg8 ast::type::ImageFormat::eRg8i, RWimg2DMS
#define RWIImg2DMSArrayRg8 ast::type::ImageFormat::eRg8i, RWimg2DMSArray
#define RWIImg1DRg16 ast::type::ImageFormat::eRg16i, RWimg1D
#define RWIImg2DRg16 ast::type::ImageFormat::eRg16i, RWimg2D
#define RWIImg3DRg16 ast::type::ImageFormat::eRg16i, RWimg3D
#define RWIImgRectRg16 ast::type::ImageFormat::eRg16i, RWimgRect
#define RWIImgCubeRg16 ast::type::ImageFormat::eRg16i, RWimgCube
#define RWIImgBufferRg16 ast::type::ImageFormat::eRg16i, RWimgBuffer
#define RWIImg1DArrayRg16 ast::type::ImageFormat::eRg16i, RWimg1DArray
#define RWIImg2DArrayRg16 ast::type::ImageFormat::eRg16i, RWimg2DArray
#define RWIImgCubeArrayRg16 ast::type::ImageFormat::eRg16i, RWimgCubeArray
#define RWIImg2DMSRg16 ast::type::ImageFormat::eRg16i, RWimg2DMS
#define RWIImg2DMSArrayRg16 ast::type::ImageFormat::eRg16i, RWimg2DMSArray
#define RWIImg1DRg32 ast::type::ImageFormat::eRg32i, RWimg1D
#define RWIImg2DRg32 ast::type::ImageFormat::eRg32i, RWimg2D
#define RWIImg3DRg32 ast::type::ImageFormat::eRg32i, RWimg3D
#define RWIImgRectRg32 ast::type::ImageFormat::eRg32i, RWimgRect
#define RWIImgCubeRg32 ast::type::ImageFormat::eRg32i, RWimgCube
#define RWIImgBufferRg32 ast::type::ImageFormat::eRg32i, RWimgBuffer
#define RWIImg1DArrayRg32 ast::type::ImageFormat::eRg32i, RWimg1DArray
#define RWIImg2DArrayRg32 ast::type::ImageFormat::eRg32i, RWimg2DArray
#define RWIImgCubeArrayRg32 ast::type::ImageFormat::eRg32i, RWimgCubeArray
#define RWIImg2DMSRg32 ast::type::ImageFormat::eRg32i, RWimg2DMS
#define RWIImg2DMSArrayRg32 ast::type::ImageFormat::eRg32i, RWimg2DMSArray

#define RWUImg1DRg8 ast::type::ImageFormat::eRg8u, RWimg1D
#define RWUImg2DRg8 ast::type::ImageFormat::eRg8u, RWimg2D
#define RWUImg3DRg8 ast::type::ImageFormat::eRg8u, RWimg3D
#define RWUImgRectRg8 ast::type::ImageFormat::eRg8u, RWimgRect
#define RWUImgCubeRg8 ast::type::ImageFormat::eRg8u, RWimgCube
#define RWUImgBufferRg8 ast::type::ImageFormat::eRg8u, RWimgBuffer
#define RWUImg1DArrayRg8 ast::type::ImageFormat::eRg8u, RWimg1DArray
#define RWUImg2DArrayRg8 ast::type::ImageFormat::eRg8u, RWimg2DArray
#define RWUImgCubeArrayRg8 ast::type::ImageFormat::eRg8u, RWimgCubeArray
#define RWUImg2DMSRg8 ast::type::ImageFormat::eRg8u, RWimg2DMS
#define RWUImg2DMSArrayRg8 ast::type::ImageFormat::eRg8u, RWimg2DMSArray
#define RWUImg1DRg16 ast::type::ImageFormat::eRg16u, RWimg1D
#define RWUImg2DRg16 ast::type::ImageFormat::eRg16u, RWimg2D
#define RWUImg3DRg16 ast::type::ImageFormat::eRg16u, RWimg3D
#define RWUImgRectRg16 ast::type::ImageFormat::eRg16u, RWimgRect
#define RWUImgCubeRg16 ast::type::ImageFormat::eRg16u, RWimgCube
#define RWUImgBufferRg16 ast::type::ImageFormat::eRg16u, RWimgBuffer
#define RWUImg1DArrayRg16 ast::type::ImageFormat::eRg16u, RWimg1DArray
#define RWUImg2DArrayRg16 ast::type::ImageFormat::eRg16u, RWimg2DArray
#define RWUImgCubeArrayRg16 ast::type::ImageFormat::eRg16u, RWimgCubeArray
#define RWUImg2DMSRg16 ast::type::ImageFormat::eRg16u, RWimg2DMS
#define RWUImg2DMSArrayRg16 ast::type::ImageFormat::eRg16u, RWimg2DMSArray
#define RWUImg1DRg32 ast::type::ImageFormat::eRg32u, RWimg1D
#define RWUImg2DRg32 ast::type::ImageFormat::eRg32u, RWimg2D
#define RWUImg3DRg32 ast::type::ImageFormat::eRg32u, RWimg3D
#define RWUImgRectRg32 ast::type::ImageFormat::eRg32u, RWimgRect
#define RWUImgCubeRg32 ast::type::ImageFormat::eRg32u, RWimgCube
#define RWUImgBufferRg32 ast::type::ImageFormat::eRg32u, RWimgBuffer
#define RWUImg1DArrayRg32 ast::type::ImageFormat::eRg32u, RWimg1DArray
#define RWUImg2DArrayRg32 ast::type::ImageFormat::eRg32u, RWimg2DArray
#define RWUImgCubeArrayRg32 ast::type::ImageFormat::eRg32u, RWimgCubeArray
#define RWUImg2DMSRg32 ast::type::ImageFormat::eRg32u, RWimg2DMS
#define RWUImg2DMSArrayRg32 ast::type::ImageFormat::eRg32u, RWimg2DMSArray

#define RWFImg1DR16 ast::type::ImageFormat::eR16f, RWimg1D
#define RWFImg2DR16 ast::type::ImageFormat::eR16f, RWimg2D
#define RWFImg3DR16 ast::type::ImageFormat::eR16f, RWimg3D
#define RWFImgRectR16 ast::type::ImageFormat::eR16f, RWimgRect
#define RWFImgCubeR16 ast::type::ImageFormat::eR16f, RWimgCube
#define RWFImgBufferR16 ast::type::ImageFormat::eR16f, RWimgBuffer
#define RWFImg1DArrayR16 ast::type::ImageFormat::eR16f, RWimg1DArray
#define RWFImg2DArrayR16 ast::type::ImageFormat::eR16f, RWimg2DArray
#define RWFImgCubeArrayR16 ast::type::ImageFormat::eR16f, RWimgCubeArray
#define RWFImg2DMSR16 ast::type::ImageFormat::eR16f, RWimg2DMS
#define RWFImg2DMSArrayR16 ast::type::ImageFormat::eR16f, RWimg2DMSArray
#define RWFImg1DR32 ast::type::ImageFormat::eR32f, RWimg1D
#define RWFImg2DR32 ast::type::ImageFormat::eR32f, RWimg2D
#define RWFImg3DR32 ast::type::ImageFormat::eR32f, RWimg3D
#define RWFImgRectR32 ast::type::ImageFormat::eR32f, RWimgRect
#define RWFImgCubeR32 ast::type::ImageFormat::eR32f, RWimgCube
#define RWFImgBufferR32 ast::type::ImageFormat::eR32f, RWimgBuffer
#define RWFImg1DArrayR32 ast::type::ImageFormat::eR32f, RWimg1DArray
#define RWFImg2DArrayR32 ast::type::ImageFormat::eR32f, RWimg2DArray
#define RWFImgCubeArrayR32 ast::type::ImageFormat::eR32f, RWimgCubeArray
#define RWFImg2DMSR32 ast::type::ImageFormat::eR32f, RWimg2DMS
#define RWFImg2DMSArrayR32 ast::type::ImageFormat::eR32f, RWimg2DMSArray

#define RWIImg1DR8 ast::type::ImageFormat::eR8i, RWimg1D
#define RWIImg2DR8 ast::type::ImageFormat::eR8i, RWimg2D
#define RWIImg3DR8 ast::type::ImageFormat::eR8i, RWimg3D
#define RWIImgRectR8 ast::type::ImageFormat::eR8i, RWimgRect
#define RWIImgCubeR8 ast::type::ImageFormat::eR8i, RWimgCube
#define RWIImgBufferR8 ast::type::ImageFormat::eR8i, RWimgBuffer
#define RWIImg1DArrayR8 ast::type::ImageFormat::eR8i, RWimg1DArray
#define RWIImg2DArrayR8 ast::type::ImageFormat::eR8i, RWimg2DArray
#define RWIImgCubeArrayR8 ast::type::ImageFormat::eR8i, RWimgCubeArray
#define RWIImg2DMSR8 ast::type::ImageFormat::eR8i, RWimg2DMS
#define RWIImg2DMSArrayR8 ast::type::ImageFormat::eR8i, RWimg2DMSArray
#define RWIImg1DR16 ast::type::ImageFormat::eR16i, RWimg1D
#define RWIImg2DR16 ast::type::ImageFormat::eR16i, RWimg2D
#define RWIImg3DR16 ast::type::ImageFormat::eR16i, RWimg3D
#define RWIImgRectR16 ast::type::ImageFormat::eR16i, RWimgRect
#define RWIImgCubeR16 ast::type::ImageFormat::eR16i, RWimgCube
#define RWIImgBufferR16 ast::type::ImageFormat::eR16i, RWimgBuffer
#define RWIImg1DArrayR16 ast::type::ImageFormat::eR16i, RWimg1DArray
#define RWIImg2DArrayR16 ast::type::ImageFormat::eR16i, RWimg2DArray
#define RWIImgCubeArrayR16 ast::type::ImageFormat::eR16i, RWimgCubeArray
#define RWIImg2DMSR16 ast::type::ImageFormat::eR16i, RWimg2DMS
#define RWIImg2DMSArrayR16 ast::type::ImageFormat::eR16i, RWimg2DMSArray
#define RWIImg1DR32 ast::type::ImageFormat::eR32i, RWimg1D
#define RWIImg2DR32 ast::type::ImageFormat::eR32i, RWimg2D
#define RWIImg3DR32 ast::type::ImageFormat::eR32i, RWimg3D
#define RWIImgRectR32 ast::type::ImageFormat::eR32i, RWimgRect
#define RWIImgCubeR32 ast::type::ImageFormat::eR32i, RWimgCube
#define RWIImgBufferR32 ast::type::ImageFormat::eR32i, RWimgBuffer
#define RWIImg1DArrayR32 ast::type::ImageFormat::eR32i, RWimg1DArray
#define RWIImg2DArrayR32 ast::type::ImageFormat::eR32i, RWimg2DArray
#define RWIImgCubeArrayR32 ast::type::ImageFormat::eR32i, RWimgCubeArray
#define RWIImg2DMSR32 ast::type::ImageFormat::eR32i, RWimg2DMS
#define RWIImg2DMSArrayR32 ast::type::ImageFormat::eR32i, RWimg2DMSArray

#define RWUImg1DR8 ast::type::ImageFormat::eR8u, RWimg1D
#define RWUImg2DR8 ast::type::ImageFormat::eR8u, RWimg2D
#define RWUImg3DR8 ast::type::ImageFormat::eR8u, RWimg3D
#define RWUImgRectR8 ast::type::ImageFormat::eR8u, RWimgRect
#define RWUImgCubeR8 ast::type::ImageFormat::eR8u, RWimgCube
#define RWUImgBufferR8 ast::type::ImageFormat::eR8u, RWimgBuffer
#define RWUImg1DArrayR8 ast::type::ImageFormat::eR8u, RWimg1DArray
#define RWUImg2DArrayR8 ast::type::ImageFormat::eR8u, RWimg2DArray
#define RWUImgCubeArrayR8 ast::type::ImageFormat::eR8u, RWimgCubeArray
#define RWUImg2DMSR8 ast::type::ImageFormat::eR8u, RWimg2DMS
#define RWUImg2DMSArrayR8 ast::type::ImageFormat::eR8u, RWimg2DMSArray
#define RWUImg1DR16 ast::type::ImageFormat::eR16u, RWimg1D
#define RWUImg2DR16 ast::type::ImageFormat::eR16u, RWimg2D
#define RWUImg3DR16 ast::type::ImageFormat::eR16u, RWimg3D
#define RWUImgRectR16 ast::type::ImageFormat::eR16u, RWimgRect
#define RWUImgCubeR16 ast::type::ImageFormat::eR16u, RWimgCube
#define RWUImgBufferR16 ast::type::ImageFormat::eR16u, RWimgBuffer
#define RWUImg1DArrayR16 ast::type::ImageFormat::eR16u, RWimg1DArray
#define RWUImg2DArrayR16 ast::type::ImageFormat::eR16u, RWimg2DArray
#define RWUImgCubeArrayR16 ast::type::ImageFormat::eR16u, RWimgCubeArray
#define RWUImg2DMSR16 ast::type::ImageFormat::eR16u, RWimg2DMS
#define RWUImg2DMSArrayR16 ast::type::ImageFormat::eR16u, RWimg2DMSArray
#define RWUImg1DR32 ast::type::ImageFormat::eR32u, RWimg1D
#define RWUImg2DR32 ast::type::ImageFormat::eR32u, RWimg2D
#define RWUImg3DR32 ast::type::ImageFormat::eR32u, RWimg3D
#define RWUImgRectR32 ast::type::ImageFormat::eR32u, RWimgRect
#define RWUImgCubeR32 ast::type::ImageFormat::eR32u, RWimgCube
#define RWUImgBufferR32 ast::type::ImageFormat::eR32u, RWimgBuffer
#define RWUImg1DArrayR32 ast::type::ImageFormat::eR32u, RWimg1DArray
#define RWUImg2DArrayR32 ast::type::ImageFormat::eR32u, RWimg2DArray
#define RWUImgCubeArrayR32 ast::type::ImageFormat::eR32u, RWimgCubeArray
#define RWUImg2DMSR32 ast::type::ImageFormat::eR32u, RWimg2DMS
#define RWUImg2DMSArrayR32 ast::type::ImageFormat::eR32u, RWimg2DMSArray

#include "ImageConfiguration.inl"

#endif
