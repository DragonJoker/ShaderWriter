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
		eCount,
		eMin = eFalse,
		eMax = eDontCare,
	};

	enum class AccessKind
		: uint8_t
	{
		eRead,
		eWrite,
		eReadWrite,
		eCount,
		eMin = eRead,
		eMax = eReadWrite,
	};

	enum class ImageDim
		: uint8_t
	{
		e1D,
		e2D,
		e3D,
		eCube,
		eBuffer,
		eCount,
		eMin = e1D,
		eMax = eBuffer,
	};

	enum class ImageFormat
		: uint8_t
	{
		eRgbaTypeless,
		eRgTypeless,
		eRTypeless,
		eRgba32f,
		eRgba16f,
		eRg32f,
		eRg16f,
		eR32f,
		eR16f,
		eR11fG11fB10f,
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
		eRgb10A2u,
		eRgba16Snorm,
		eRgba8Snorm,
		eRg16Snorm,
		eRg8Snorm,
		eR16Snorm,
		eR8Snorm,
		eRgba16Unorm,
		eRgba8Unorm,
		eRg16Unorm,
		eRg8Unorm,
		eR16Unorm,
		eR8Unorm,
		eRgb10A2Unorm,
		eCount,
		eMin = eRgbaTypeless,
		eMax = eR8u,
	};

	template< ImageFormat FormatT >
	struct ImageFormatTraits;

	template< ImageFormat FormatT >
	static Kind constexpr sampledBaseTypeT = ImageFormatTraits< FormatT >::SampledBaseType;
	template< ImageFormat FormatT >
	static Kind constexpr sampledTypeT = ImageFormatTraits< FormatT >::SampledType;
	template< ImageFormat FormatT >
	static Kind constexpr texelTypeT = ImageFormatTraits< FormatT >::TexelType;

	constexpr bool isFloatFormat( ImageFormat format )noexcept
	{
		return format == ImageFormat::eRgbaTypeless
			|| format == ImageFormat::eRgTypeless
			|| format == ImageFormat::eRTypeless
			|| format == ImageFormat::eRgba32f
			|| format == ImageFormat::eRgba16f
			|| format == ImageFormat::eRg32f
			|| format == ImageFormat::eRg16f
			|| format == ImageFormat::eR32f
			|| format == ImageFormat::eR16f
			|| format == ImageFormat::eR11fG11fB10f
			|| format == ImageFormat::eRgba16Snorm
			|| format == ImageFormat::eRgba8Snorm
			|| format == ImageFormat::eRg16Snorm
			|| format == ImageFormat::eRg8Snorm
			|| format == ImageFormat::eR16Snorm
			|| format == ImageFormat::eR8Snorm
			|| format == ImageFormat::eRgba16Unorm
			|| format == ImageFormat::eRgba8Unorm
			|| format == ImageFormat::eRg16Unorm
			|| format == ImageFormat::eRg8Unorm
			|| format == ImageFormat::eR16Unorm
			|| format == ImageFormat::eR8Unorm
			|| format == ImageFormat::eRgb10A2Unorm;
	}

	constexpr bool isSIntFormat( ImageFormat format )noexcept
	{
		return format == ImageFormat::eRgba32i
			|| format == ImageFormat::eRgba16i
			|| format == ImageFormat::eRgba8i
			|| format == ImageFormat::eRg32i
			|| format == ImageFormat::eRg16i
			|| format == ImageFormat::eRg8i
			|| format == ImageFormat::eR32i
			|| format == ImageFormat::eR16i
			|| format == ImageFormat::eR8i;
	}

	constexpr bool isUIntFormat( ImageFormat format )noexcept
	{
		return format == ImageFormat::eRgba32u
			|| format == ImageFormat::eRgba16u
			|| format == ImageFormat::eRgba8u
			|| format == ImageFormat::eRg32u
			|| format == ImageFormat::eRg16u
			|| format == ImageFormat::eRg8u
			|| format == ImageFormat::eR32u
			|| format == ImageFormat::eR16u
			|| format == ImageFormat::eR8u
			|| format == ImageFormat::eRgb10A2u;
	}

	constexpr bool isAtomicFloatFormat( ImageFormat format )noexcept
	{
		return format == ImageFormat::eR32f;
	}

	constexpr bool isSingleInt32Format( ImageFormat format )noexcept
	{
		return format == ImageFormat::eR32i
			|| format == ImageFormat::eR32u;
	}

	struct ImageConfiguration
	{
		SDAST_API explicit ImageConfiguration( type::Kind sampledType = type::Kind::eFloat
			, ImageDim dimension = ImageDim::e1D
			, ImageFormat format = ImageFormat::eRgbaTypeless
			, Trinary isSampled = Trinary::eFalse
			, bool isArrayed = false
			, bool isMS = false
			, AccessKind accessKind = AccessKind::eRead )noexcept;

		type::Kind sampledType;
		ImageDim dimension;
		ImageFormat format;
		Trinary isSampled;
		bool isArrayed;
		bool isMS;
		AccessKind accessKind;
	};

	SDAST_API size_t getHash( type::ImageConfiguration const & config )noexcept;
	SDAST_API size_t getHash( type::ImageConfiguration const & config
		, bool isComparison )noexcept;

	template< ImageFormat FormatT
		, AccessKind AccessT
		, ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline ImageConfiguration makeConfig( bool sampled )noexcept;
}

#define Img1DBase ast::type::ImageDim::e1D, false, false
#define Img2DBase ast::type::ImageDim::e2D, false, false
#define Img3DBase ast::type::ImageDim::e3D, false, false
#define ImgCubeBase ast::type::ImageDim::eCube, false, false
#define ImgBufferBase ast::type::ImageDim::eBuffer, false, false
#define Img1DArrayBase ast::type::ImageDim::e1D, true, false
#define Img2DArrayBase ast::type::ImageDim::e2D, true, false
#define ImgCubeArrayBase ast::type::ImageDim::eCube, true, false
#define Img2DMSBase ast::type::ImageDim::e2D, false, true
#define Img2DMSArrayBase ast::type::ImageDim::e2D, true, true

#define Img1D Img1DBase
#define Img2D Img2DBase
#define Img3D Img3DBase
#define ImgCube ImgCubeBase
#define ImgBuffer ImgBufferBase
#define Img1DArray Img1DArrayBase
#define Img2DArray Img2DArrayBase
#define ImgCubeArray ImgCubeArrayBase
#define Img2DMS Img2DMSBase
#define Img2DMSArray Img2DMSArrayBase

#define Img1DRgba ast::type::ImageFormat::eRgbaTypeless, Img1D
#define Img2DRgba ast::type::ImageFormat::eRgbaTypeless, Img2D
#define Img3DRgba ast::type::ImageFormat::eRgbaTypeless, Img3D
#define ImgCubeRgba ast::type::ImageFormat::eRgbaTypeless, ImgCube
#define ImgBufferRgba ast::type::ImageFormat::eRgbaTypeless, ImgBuffer
#define Img1DArrayRgba ast::type::ImageFormat::eRgbaTypeless, Img1DArray
#define Img2DArrayRgba ast::type::ImageFormat::eRgbaTypeless, Img2DArray
#define ImgCubeArrayRgba ast::type::ImageFormat::eRgbaTypeless, ImgCubeArray
#define Img2DMSRgba ast::type::ImageFormat::eRgbaTypeless, Img2DMS
#define Img2DMSArrayRgba ast::type::ImageFormat::eRgbaTypeless, Img2DMSArray

#define FImg1DRgba16 ast::type::ImageFormat::eRgba16f, Img1D
#define FImg2DRgba16 ast::type::ImageFormat::eRgba16f, Img2D
#define FImg3DRgba16 ast::type::ImageFormat::eRgba16f, Img3D
#define FImgCubeRgba16 ast::type::ImageFormat::eRgba16f, ImgCube
#define FImgBufferRgba16 ast::type::ImageFormat::eRgba16f, ImgBuffer
#define FImg1DArrayRgba16 ast::type::ImageFormat::eRgba16f, Img1DArray
#define FImg2DArrayRgba16 ast::type::ImageFormat::eRgba16f, Img2DArray
#define FImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16f, ImgCubeArray
#define FImg2DMSRgba16 ast::type::ImageFormat::eRgba16f, Img2DMS
#define FImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16f, Img2DMSArray
#define FImg1DRgba32 ast::type::ImageFormat::eRgba32f, Img1D
#define FImg2DRgba32 ast::type::ImageFormat::eRgba32f, Img2D
#define FImg3DRgba32 ast::type::ImageFormat::eRgba32f, Img3D
#define FImgCubeRgba32 ast::type::ImageFormat::eRgba32f, ImgCube
#define FImgBufferRgba32 ast::type::ImageFormat::eRgba32f, ImgBuffer
#define FImg1DArrayRgba32 ast::type::ImageFormat::eRgba32f, Img1DArray
#define FImg2DArrayRgba32 ast::type::ImageFormat::eRgba32f, Img2DArray
#define FImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32f, ImgCubeArray
#define FImg2DMSRgba32 ast::type::ImageFormat::eRgba32f, Img2DMS
#define FImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32f, Img2DMSArray
#define FImg1DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, Img1D
#define FImg2DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, Img2D
#define FImg3DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, Img3D
#define FImgCubeRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, ImgCube
#define FImgBufferRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, ImgBuffer
#define FImg1DArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, Img1DArray
#define FImg2DArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, Img2DArray
#define FImgCubeArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, ImgCubeArray
#define FImg2DMSRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, Img2DMS
#define FImg2DMSArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, Img2DMSArray
#define FImg1DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, Img1D
#define FImg2DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, Img2D
#define FImg3DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, Img3D
#define FImgCubeRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, ImgCube
#define FImgBufferRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, ImgBuffer
#define FImg1DArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, Img1DArray
#define FImg2DArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, Img2DArray
#define FImgCubeArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, ImgCubeArray
#define FImg2DMSRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, Img2DMS
#define FImg2DMSArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, Img2DMSArray
#define FImg1DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, Img1D
#define FImg2DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, Img2D
#define FImg3DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, Img3D
#define FImgCubeRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, ImgCube
#define FImgBufferRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, ImgBuffer
#define FImg1DArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, Img1DArray
#define FImg2DArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, Img2DArray
#define FImgCubeArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, ImgCubeArray
#define FImg2DMSRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, Img2DMS
#define FImg2DMSArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, Img2DMSArray
#define FImg1DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, Img1D
#define FImg2DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, Img2D
#define FImg3DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, Img3D
#define FImgCubeRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, ImgCube
#define FImgBufferRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, ImgBuffer
#define FImg1DArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, Img1DArray
#define FImg2DArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, Img2DArray
#define FImgCubeArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, ImgCubeArray
#define FImg2DMSRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, Img2DMS
#define FImg2DMSArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, Img2DMSArray
#define FImg1DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, Img1D
#define FImg2DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, Img2D
#define FImg3DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, Img3D
#define FImgCubeRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, ImgCube
#define FImgBufferRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, ImgBuffer
#define FImg1DArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, Img1DArray
#define FImg2DArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, Img2DArray
#define FImgCubeArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, ImgCubeArray
#define FImg2DMSRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, Img2DMS
#define FImg2DMSArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, Img2DMSArray
#define FImg1DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, Img1D
#define FImg2DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, Img2D
#define FImg3DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, Img3D
#define FImgCubeR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, ImgCube
#define FImgBufferR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, ImgBuffer
#define FImg1DArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, Img1DArray
#define FImg2DArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, Img2DArray
#define FImgCubeArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, ImgCubeArray
#define FImg2DMSR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, Img2DMS
#define FImg2DMSArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, Img2DMSArray

#define IImg1DRgba8 ast::type::ImageFormat::eRgba8i, Img1D
#define IImg2DRgba8 ast::type::ImageFormat::eRgba8i, Img2D
#define IImg3DRgba8 ast::type::ImageFormat::eRgba8i, Img3D
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
#define UImgCubeRgba32 ast::type::ImageFormat::eRgba32u, ImgCube
#define UImgBufferRgba32 ast::type::ImageFormat::eRgba32u, ImgBuffer
#define UImg1DArrayRgba32 ast::type::ImageFormat::eRgba32u, Img1DArray
#define UImg2DArrayRgba32 ast::type::ImageFormat::eRgba32u, Img2DArray
#define UImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32u, ImgCubeArray
#define UImg2DMSRgba32 ast::type::ImageFormat::eRgba32u, Img2DMS
#define UImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32u, Img2DMSArray
#define UImg1DRgb10A2 ast::type::ImageFormat::eRgb10A2u, Img1D
#define UImg2DRgb10A2 ast::type::ImageFormat::eRgb10A2u, Img2D
#define UImg3DRgb10A2 ast::type::ImageFormat::eRgb10A2u, Img3D
#define UImgCubeRgb10A2 ast::type::ImageFormat::eRgb10A2u, ImgCube
#define UImgBufferRgb10A2 ast::type::ImageFormat::eRgb10A2u, ImgBuffer
#define UImg1DArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, Img1DArray
#define UImg2DArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, Img2DArray
#define UImgCubeArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, ImgCubeArray
#define UImg2DMSRgb10A2 ast::type::ImageFormat::eRgb10A2u, Img2DMS
#define UImg2DMSArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, Img2DMSArray

#define Img1DRg ast::type::ImageFormat::eRgTypeless, Img1D
#define Img2DRg ast::type::ImageFormat::eRgTypeless, Img2D
#define Img3DRg ast::type::ImageFormat::eRgTypeless, Img3D
#define ImgCubeRg ast::type::ImageFormat::eRgTypeless, ImgCube
#define ImgBufferRg ast::type::ImageFormat::eRgTypeless, ImgBuffer
#define Img1DArrayRg ast::type::ImageFormat::eRgTypeless, Img1DArray
#define Img2DArrayRg ast::type::ImageFormat::eRgTypeless, Img2DArray
#define ImgCubeArrayRg ast::type::ImageFormat::eRgTypeless, ImgCubeArray
#define Img2DMSRg ast::type::ImageFormat::eRgTypeless, Img2DMS
#define Img2DMSArrayRg ast::type::ImageFormat::eRgTypeless, Img2DMSArray

#define FImg1DRg16 ast::type::ImageFormat::eRg16f, Img1D
#define FImg2DRg16 ast::type::ImageFormat::eRg16f, Img2D
#define FImg3DRg16 ast::type::ImageFormat::eRg16f, Img3D
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
#define FImgCubeRg32 ast::type::ImageFormat::eRg32f, ImgCube
#define FImgBufferRg32 ast::type::ImageFormat::eRg32f, ImgBuffer
#define FImg1DArrayRg32 ast::type::ImageFormat::eRg32f, Img1DArray
#define FImg2DArrayRg32 ast::type::ImageFormat::eRg32f, Img2DArray
#define FImgCubeArrayRg32 ast::type::ImageFormat::eRg32f, ImgCubeArray
#define FImg2DMSRg32 ast::type::ImageFormat::eRg32f, Img2DMS
#define FImg2DMSArrayRg32 ast::type::ImageFormat::eRg32f, Img2DMSArray
#define FImg1DRg16Snorm ast::type::ImageFormat::eRg16Snorm, Img1D
#define FImg2DRg16Snorm ast::type::ImageFormat::eRg16Snorm, Img2D
#define FImg3DRg16Snorm ast::type::ImageFormat::eRg16Snorm, Img3D
#define FImgCubeRg16Snorm ast::type::ImageFormat::eRg16Snorm, ImgCube
#define FImgBufferRg16Snorm ast::type::ImageFormat::eRg16Snorm, ImgBuffer
#define FImg1DArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, Img1DArray
#define FImg2DArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, Img2DArray
#define FImgCubeArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, ImgCubeArray
#define FImg2DMSRg16Snorm ast::type::ImageFormat::eRg16Snorm, Img2DMS
#define FImg2DMSArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, Img2DMSArray
#define FImg1DRg8Snorm ast::type::ImageFormat::eRg8Snorm, Img1D
#define FImg2DRg8Snorm ast::type::ImageFormat::eRg8Snorm, Img2D
#define FImg3DRg8Snorm ast::type::ImageFormat::eRg8Snorm, Img3D
#define FImgCubeRg8Snorm ast::type::ImageFormat::eRg8Snorm, ImgCube
#define FImgBufferRg8Snorm ast::type::ImageFormat::eRg8Snorm, ImgBuffer
#define FImg1DArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, Img1DArray
#define FImg2DArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, Img2DArray
#define FImgCubeArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, ImgCubeArray
#define FImg2DMSRg8Snorm ast::type::ImageFormat::eRg8Snorm, Img2DMS
#define FImg2DMSArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, Img2DMSArray
#define FImg1DRg16Unorm ast::type::ImageFormat::eRg16Unorm, Img1D
#define FImg2DRg16Unorm ast::type::ImageFormat::eRg16Unorm, Img2D
#define FImg3DRg16Unorm ast::type::ImageFormat::eRg16Unorm, Img3D
#define FImgCubeRg16Unorm ast::type::ImageFormat::eRg16Unorm, ImgCube
#define FImgBufferRg16Unorm ast::type::ImageFormat::eRg16Unorm, ImgBuffer
#define FImg1DArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, Img1DArray
#define FImg2DArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, Img2DArray
#define FImgCubeArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, ImgCubeArray
#define FImg2DMSRg16Unorm ast::type::ImageFormat::eRg16Unorm, Img2DMS
#define FImg2DMSArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, Img2DMSArray
#define FImg1DRg8Unorm ast::type::ImageFormat::eRg8Unorm, Img1D
#define FImg2DRg8Unorm ast::type::ImageFormat::eRg8Unorm, Img2D
#define FImg3DRg8Unorm ast::type::ImageFormat::eRg8Unorm, Img3D
#define FImgCubeRg8Unorm ast::type::ImageFormat::eRg8Unorm, ImgCube
#define FImgBufferRg8Unorm ast::type::ImageFormat::eRg8Unorm, ImgBuffer
#define FImg1DArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, Img1DArray
#define FImg2DArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, Img2DArray
#define FImgCubeArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, ImgCubeArray
#define FImg2DMSRg8Unorm ast::type::ImageFormat::eRg8Unorm, Img2DMS
#define FImg2DMSArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, Img2DMSArray

#define IImg1DRg8 ast::type::ImageFormat::eRg8i, Img1D
#define IImg2DRg8 ast::type::ImageFormat::eRg8i, Img2D
#define IImg3DRg8 ast::type::ImageFormat::eRg8i, Img3D
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
#define UImgCubeRg32 ast::type::ImageFormat::eRg32u, ImgCube
#define UImgBufferRg32 ast::type::ImageFormat::eRg32u, ImgBuffer
#define UImg1DArrayRg32 ast::type::ImageFormat::eRg32u, Img1DArray
#define UImg2DArrayRg32 ast::type::ImageFormat::eRg32u, Img2DArray
#define UImgCubeArrayRg32 ast::type::ImageFormat::eRg32u, ImgCubeArray
#define UImg2DMSRg32 ast::type::ImageFormat::eRg32u, Img2DMS
#define UImg2DMSArrayRg32 ast::type::ImageFormat::eRg32u, Img2DMSArray

#define Img1DR ast::type::ImageFormat::eRTypeless, Img1D
#define Img2DR ast::type::ImageFormat::eRTypeless, Img2D
#define Img3DR ast::type::ImageFormat::eRTypeless, Img3D
#define ImgCubeR ast::type::ImageFormat::eRTypeless, ImgCube
#define ImgBufferR ast::type::ImageFormat::eRTypeless, ImgBuffer
#define Img1DArrayR ast::type::ImageFormat::eRTypeless, Img1DArray
#define Img2DArrayR ast::type::ImageFormat::eRTypeless, Img2DArray
#define ImgCubeArrayR ast::type::ImageFormat::eRTypeless, ImgCubeArray
#define Img2DMSR ast::type::ImageFormat::eRTypeless, Img2DMS
#define Img2DMSArrayR ast::type::ImageFormat::eRTypeless, Img2DMSArray

#define FImg1DR16 ast::type::ImageFormat::eR16f, Img1D
#define FImg2DR16 ast::type::ImageFormat::eR16f, Img2D
#define FImg3DR16 ast::type::ImageFormat::eR16f, Img3D
#define FImgCubeR16 ast::type::ImageFormat::eR16f, ImgCube
#define FImgBufferR16 ast::type::ImageFormat::eR16f, ImgBuffer
#define FImg1DArrayR16 ast::type::ImageFormat::eR16f, Img1DArray
#define FImg2DArrayR16 ast::type::ImageFormat::eR16f, Img2DArray
#define FImgCubeArrayR16 ast::type::ImageFormat::eR16f, ImgCubeArray
#define FImg2DMSR16 ast::type::ImageFormat::eR16f, Img2DMS
#define FImg2DMSArrayR16 ast::type::ImageFormat::eR16f, Img2DMSArray
#define FImg1DShadowR16 ast::type::ImageFormat::eR16f, Img1DBase, true
#define FImg2DShadowR16 ast::type::ImageFormat::eR16f, Img2DBase, true
#define FImgCubeShadowR16 ast::type::ImageFormat::eR16f, ImgCubeBase, true
#define FImg1DArrayShadowR16 ast::type::ImageFormat::eR16f, Img1DArrayBase, true
#define FImg2DArrayShadowR16 ast::type::ImageFormat::eR16f, Img2DArrayBase, true
#define FImgCubeArrayShadowR16 ast::type::ImageFormat::eR16f, ImgCubeArrayBase, true
#define FImg1DR32 ast::type::ImageFormat::eR32f, Img1D
#define FImg2DR32 ast::type::ImageFormat::eR32f, Img2D
#define FImg3DR32 ast::type::ImageFormat::eR32f, Img3D
#define FImgCubeR32 ast::type::ImageFormat::eR32f, ImgCube
#define FImgBufferR32 ast::type::ImageFormat::eR32f, ImgBuffer
#define FImg1DArrayR32 ast::type::ImageFormat::eR32f, Img1DArray
#define FImg2DArrayR32 ast::type::ImageFormat::eR32f, Img2DArray
#define FImgCubeArrayR32 ast::type::ImageFormat::eR32f, ImgCubeArray
#define FImg2DMSR32 ast::type::ImageFormat::eR32f, Img2DMS
#define FImg2DMSArrayR32 ast::type::ImageFormat::eR32f, Img2DMSArray
#define FImg1DShadowR32 ast::type::ImageFormat::eR32f, Img1DBase, true
#define FImg2DShadowR32 ast::type::ImageFormat::eR32f, Img2DBase, true
#define FImgCubeShadowR32 ast::type::ImageFormat::eR32f, ImgCubeBase, true
#define FImg1DArrayShadowR32 ast::type::ImageFormat::eR32f, Img1DArrayBase, true
#define FImg2DArrayShadowR32 ast::type::ImageFormat::eR32f, Img2DArrayBase, true
#define FImgCubeArrayShadowR32 ast::type::ImageFormat::eR32f, ImgCubeArrayBase, true
#define FImg1DR16Snorm ast::type::ImageFormat::eR16Snorm, Img1D
#define FImg2DR16Snorm ast::type::ImageFormat::eR16Snorm, Img2D
#define FImg3DR16Snorm ast::type::ImageFormat::eR16Snorm, Img3D
#define FImgCubeR16Snorm ast::type::ImageFormat::eR16Snorm, ImgCube
#define FImgBufferR16Snorm ast::type::ImageFormat::eR16Snorm, ImgBuffer
#define FImg1DArrayR16Snorm ast::type::ImageFormat::eR16Snorm, Img1DArray
#define FImg2DArrayR16Snorm ast::type::ImageFormat::eR16Snorm, Img2DArray
#define FImgCubeArrayR16Snorm ast::type::ImageFormat::eR16Snorm, ImgCubeArray
#define FImg2DMSR16Snorm ast::type::ImageFormat::eR16Snorm, Img2DMS
#define FImg2DMSArrayR16Snorm ast::type::ImageFormat::eR16Snorm, Img2DMSArray
#define FImg1DShadowR16Snorm ast::type::ImageFormat::eR16Snorm, Img1DBase, true
#define FImg2DShadowR16Snorm ast::type::ImageFormat::eR16Snorm, Img2DBase, true
#define FImgCubeShadowR16Snorm ast::type::ImageFormat::eR16Snorm, ImgCubeBase, true
#define FImg1DArrayShadowR16Snorm ast::type::ImageFormat::eR16Snorm, Img1DArrayBase, true
#define FImg2DArrayShadowR16Snorm ast::type::ImageFormat::eR16Snorm, Img2DArrayBase, true
#define FImgCubeArrayShadowR16Snorm ast::type::ImageFormat::eR16Snorm, ImgCubeArrayBase, true
#define FImg1DR8Snorm ast::type::ImageFormat::eR8Snorm, Img1D
#define FImg2DR8Snorm ast::type::ImageFormat::eR8Snorm, Img2D
#define FImg3DR8Snorm ast::type::ImageFormat::eR8Snorm, Img3D
#define FImgCubeR8Snorm ast::type::ImageFormat::eR8Snorm, ImgCube
#define FImgBufferR8Snorm ast::type::ImageFormat::eR8Snorm, ImgBuffer
#define FImg1DArrayR8Snorm ast::type::ImageFormat::eR8Snorm, Img1DArray
#define FImg2DArrayR8Snorm ast::type::ImageFormat::eR8Snorm, Img2DArray
#define FImgCubeArrayR8Snorm ast::type::ImageFormat::eR8Snorm, ImgCubeArray
#define FImg2DMSR8Snorm ast::type::ImageFormat::eR8Snorm, Img2DMS
#define FImg2DMSArrayR8Snorm ast::type::ImageFormat::eR8Snorm, Img2DMSArray
#define FImg1DShadowR8Snorm ast::type::ImageFormat::eR8Snorm, Img1DBase, true
#define FImg2DShadowR8Snorm ast::type::ImageFormat::eR8Snorm, Img2DBase, true
#define FImgCubeShadowR8Snorm ast::type::ImageFormat::eR8Snorm, ImgCubeBase, true
#define FImg1DArrayShadowR8Snorm ast::type::ImageFormat::eR8Snorm, Img1DArrayBase, true
#define FImg2DArrayShadowR8Snorm ast::type::ImageFormat::eR8Snorm, Img2DArrayBase, true
#define FImgCubeArrayShadowR8Snorm ast::type::ImageFormat::eR8Snorm, ImgCubeArrayBase, true
#define FImg1DR16Unorm ast::type::ImageFormat::eR16Unorm, Img1D
#define FImg2DR16Unorm ast::type::ImageFormat::eR16Unorm, Img2D
#define FImg3DR16Unorm ast::type::ImageFormat::eR16Unorm, Img3D
#define FImgCubeR16Unorm ast::type::ImageFormat::eR16Unorm, ImgCube
#define FImgBufferR16Unorm ast::type::ImageFormat::eR16Unorm, ImgBuffer
#define FImg1DArrayR16Unorm ast::type::ImageFormat::eR16Unorm, Img1DArray
#define FImg2DArrayR16Unorm ast::type::ImageFormat::eR16Unorm, Img2DArray
#define FImgCubeArrayR16Unorm ast::type::ImageFormat::eR16Unorm, ImgCubeArray
#define FImg2DMSR16Unorm ast::type::ImageFormat::eR16Unorm, Img2DMS
#define FImg2DMSArrayR16Unorm ast::type::ImageFormat::eR16Unorm, Img2DMSArray
#define FImg1DShadowR16Unorm ast::type::ImageFormat::eR16Unorm, Img1DBase, true
#define FImg2DShadowR16Unorm ast::type::ImageFormat::eR16Unorm, Img2DBase, true
#define FImgCubeShadowR16Unorm ast::type::ImageFormat::eR16Unorm, ImgCubeBase, true
#define FImg1DArrayShadowR16Unorm ast::type::ImageFormat::eR16Unorm, Img1DArrayBase, true
#define FImg2DArrayShadowR16Unorm ast::type::ImageFormat::eR16Unorm, Img2DArrayBase, true
#define FImgCubeArrayShadowR16Unorm ast::type::ImageFormat::eR16Unorm, ImgCubeArrayBase, true
#define FImg1DR8Unorm ast::type::ImageFormat::eR8Unorm, Img1D
#define FImg2DR8Unorm ast::type::ImageFormat::eR8Unorm, Img2D
#define FImg3DR8Unorm ast::type::ImageFormat::eR8Unorm, Img3D
#define FImgCubeR8Unorm ast::type::ImageFormat::eR8Unorm, ImgCube
#define FImgBufferR8Unorm ast::type::ImageFormat::eR8Unorm, ImgBuffer
#define FImg1DArrayR8Unorm ast::type::ImageFormat::eR8Unorm, Img1DArray
#define FImg2DArrayR8Unorm ast::type::ImageFormat::eR8Unorm, Img2DArray
#define FImgCubeArrayR8Unorm ast::type::ImageFormat::eR8Unorm, ImgCubeArray
#define FImg2DMSR8Unorm ast::type::ImageFormat::eR8Unorm, Img2DMS
#define FImg2DMSArrayR8Unorm ast::type::ImageFormat::eR8Unorm, Img2DMSArray
#define FImg1DShadowR8Unorm ast::type::ImageFormat::eR8Unorm, Img1DBase, true
#define FImg2DShadowR8Unorm ast::type::ImageFormat::eR8Unorm, Img2DBase, true
#define FImgCubeShadowR8Unorm ast::type::ImageFormat::eR8Unorm, ImgCubeBase, true
#define FImg1DArrayShadowR8Unorm ast::type::ImageFormat::eR8Unorm, Img1DArrayBase, true
#define FImg2DArrayShadowR8Unorm ast::type::ImageFormat::eR8Unorm, Img2DArrayBase, true
#define FImgCubeArrayShadowR8Unorm ast::type::ImageFormat::eR8Unorm, ImgCubeArrayBase, true

#define IImg1DR8 ast::type::ImageFormat::eR8i, Img1D
#define IImg2DR8 ast::type::ImageFormat::eR8i, Img2D
#define IImg3DR8 ast::type::ImageFormat::eR8i, Img3D
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
#define UImgCubeR32 ast::type::ImageFormat::eR32u, ImgCube
#define UImgBufferR32 ast::type::ImageFormat::eR32u, ImgBuffer
#define UImg1DArrayR32 ast::type::ImageFormat::eR32u, Img1DArray
#define UImg2DArrayR32 ast::type::ImageFormat::eR32u, Img2DArray
#define UImgCubeArrayR32 ast::type::ImageFormat::eR32u, ImgCubeArray
#define UImg2DMSR32 ast::type::ImageFormat::eR32u, Img2DMS
#define UImg2DMSArrayR32 ast::type::ImageFormat::eR32u, Img2DMSArray

#define RImg1D ast::type::AccessKind::eRead, Img1DBase
#define RImg2D ast::type::AccessKind::eRead, Img2DBase
#define RImg3D ast::type::AccessKind::eRead, Img3DBase
#define RImgCube ast::type::AccessKind::eRead, ImgCubeBase
#define RImgBuffer ast::type::AccessKind::eRead, ImgBufferBase
#define RImg1DArray ast::type::AccessKind::eRead, Img1DArrayBase
#define RImg2DArray ast::type::AccessKind::eRead, Img2DArrayBase
#define RImgCubeArray ast::type::AccessKind::eRead, ImgCubeArrayBase
#define RImg2DMS ast::type::AccessKind::eRead, Img2DMSBase
#define RImg2DMSArray ast::type::AccessKind::eRead, Img2DMSArrayBase

#define RFImg1DRgba16 ast::type::ImageFormat::eRgba16f, RImg1D
#define RFImg2DRgba16 ast::type::ImageFormat::eRgba16f, RImg2D
#define RFImg3DRgba16 ast::type::ImageFormat::eRgba16f, RImg3D
#define RFImgCubeRgba16 ast::type::ImageFormat::eRgba16f, RImgCube
#define RFImgBufferRgba16 ast::type::ImageFormat::eRgba16f, RImgBuffer
#define RFImg1DArrayRgba16 ast::type::ImageFormat::eRgba16f, RImg1DArray
#define RFImg2DArrayRgba16 ast::type::ImageFormat::eRgba16f, RImg2DArray
#define RFImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16f, RImgCubeArray
#define RFImg2DMSRgba16 ast::type::ImageFormat::eRgba16f, RImg2DMS
#define RFImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16f, RImg2DMSArray
#define RFImg1DRgba32 ast::type::ImageFormat::eRgba32f, RImg1D
#define RFImg2DRgba32 ast::type::ImageFormat::eRgba32f, RImg2D
#define RFImg3DRgba32 ast::type::ImageFormat::eRgba32f, RImg3D
#define RFImgCubeRgba32 ast::type::ImageFormat::eRgba32f, RImgCube
#define RFImgBufferRgba32 ast::type::ImageFormat::eRgba32f, RImgBuffer
#define RFImg1DArrayRgba32 ast::type::ImageFormat::eRgba32f, RImg1DArray
#define RFImg2DArrayRgba32 ast::type::ImageFormat::eRgba32f, RImg2DArray
#define RFImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32f, RImgCubeArray
#define RFImg2DMSRgba32 ast::type::ImageFormat::eRgba32f, RImg2DMS
#define RFImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32f, RImg2DMSArray
#define RFImg1DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RImg1D
#define RFImg2DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RImg2D
#define RFImg3DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RImg3D
#define RFImgCubeRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RImgCube
#define RFImgBufferRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RImgBuffer
#define RFImg1DArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RImg1DArray
#define RFImg2DArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RImg2DArray
#define RFImgCubeArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RImgCubeArray
#define RFImg2DMSRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RImg2DMS
#define RFImg2DMSArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RImg2DMSArray
#define RFImg1DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RImg1D
#define RFImg2DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RImg2D
#define RFImg3DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RImg3D
#define RFImgCubeRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RImgCube
#define RFImgBufferRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RImgBuffer
#define RFImg1DArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RImg1DArray
#define RFImg2DArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RImg2DArray
#define RFImgCubeArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RImgCubeArray
#define RFImg2DMSRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RImg2DMS
#define RFImg2DMSArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RImg2DMSArray
#define RFImg1DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RImg1D
#define RFImg2DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RImg2D
#define RFImg3DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RImg3D
#define RFImgCubeRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RImgCube
#define RFImgBufferRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RImgBuffer
#define RFImg1DArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RImg1DArray
#define RFImg2DArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RImg2DArray
#define RFImgCubeArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RImgCubeArray
#define RFImg2DMSRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RImg2DMS
#define RFImg2DMSArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RImg2DMSArray
#define RFImg1DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RImg1D
#define RFImg2DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RImg2D
#define RFImg3DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RImg3D
#define RFImgCubeRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RImgCube
#define RFImgBufferRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RImgBuffer
#define RFImg1DArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RImg1DArray
#define RFImg2DArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RImg2DArray
#define RFImgCubeArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RImgCubeArray
#define RFImg2DMSRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RImg2DMS
#define RFImg2DMSArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RImg2DMSArray
#define RFImg1DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RImg1D
#define RFImg2DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RImg2D
#define RFImg3DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RImg3D
#define RFImgCubeR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RImgCube
#define RFImgBufferR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RImgBuffer
#define RFImg1DArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RImg1DArray
#define RFImg2DArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RImg2DArray
#define RFImgCubeArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RImgCubeArray
#define RFImg2DMSR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RImg2DMS
#define RFImg2DMSArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RImg2DMSArray
#define RFImg1DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RImg1D
#define RFImg2DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RImg2D
#define RFImg3DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RImg3D
#define RFImgCubeRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RImgCube
#define RFImgBufferRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RImgBuffer
#define RFImg1DArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RImg1DArray
#define RFImg2DArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RImg2DArray
#define RFImgCubeArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RImgCubeArray
#define RFImg2DMSRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RImg2DMS
#define RFImg2DMSArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RImg2DMSArray

#define RIImg1DRgba8 ast::type::ImageFormat::eRgba8i, RImg1D
#define RIImg2DRgba8 ast::type::ImageFormat::eRgba8i, RImg2D
#define RIImg3DRgba8 ast::type::ImageFormat::eRgba8i, RImg3D
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
#define RUImgCubeRgba32 ast::type::ImageFormat::eRgba32u, RImgCube
#define RUImgBufferRgba32 ast::type::ImageFormat::eRgba32u, RImgBuffer
#define RUImg1DArrayRgba32 ast::type::ImageFormat::eRgba32u, RImg1DArray
#define RUImg2DArrayRgba32 ast::type::ImageFormat::eRgba32u, RImg2DArray
#define RUImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32u, RImgCubeArray
#define RUImg2DMSRgba32 ast::type::ImageFormat::eRgba32u, RImg2DMS
#define RUImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32u, RImg2DMSArray
#define RUImg1DRgb10A2 ast::type::ImageFormat::eRgb10A2u, RImg1D
#define RUImg2DRgb10A2 ast::type::ImageFormat::eRgb10A2u, RImg2D
#define RUImg3DRgb10A2 ast::type::ImageFormat::eRgb10A2u, RImg3D
#define RUImgCubeRgb10A2 ast::type::ImageFormat::eRgb10A2u, RImgCube
#define RUImgBufferRgb10A2 ast::type::ImageFormat::eRgb10A2u, RImgBuffer
#define RUImg1DArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, RImg1DArray
#define RUImg2DArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, RImg2DArray
#define RUImgCubeArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, RImgCubeArray
#define RUImg2DMSRgb10A2 ast::type::ImageFormat::eRgb10A2u, RImg2DMS
#define RUImg2DMSArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, RImg2DMSArray

#define RFImg1DRg16 ast::type::ImageFormat::eRg16f, RImg1D
#define RFImg2DRg16 ast::type::ImageFormat::eRg16f, RImg2D
#define RFImg3DRg16 ast::type::ImageFormat::eRg16f, RImg3D
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
#define RFImgCubeRg32 ast::type::ImageFormat::eRg32f, RImgCube
#define RFImgBufferRg32 ast::type::ImageFormat::eRg32f, RImgBuffer
#define RFImg1DArrayRg32 ast::type::ImageFormat::eRg32f, RImg1DArray
#define RFImg2DArrayRg32 ast::type::ImageFormat::eRg32f, RImg2DArray
#define RFImgCubeArrayRg32 ast::type::ImageFormat::eRg32f, RImgCubeArray
#define RFImg2DMSRg32 ast::type::ImageFormat::eRg32f, RImg2DMS
#define RFImg2DMSArrayRg32 ast::type::ImageFormat::eRg32f, RImg2DMSArray
#define RFImg1DRg16Snorm ast::type::ImageFormat::eRg16Snorm, RImg1D
#define RFImg2DRg16Snorm ast::type::ImageFormat::eRg16Snorm, RImg2D
#define RFImg3DRg16Snorm ast::type::ImageFormat::eRg16Snorm, RImg3D
#define RFImgCubeRg16Snorm ast::type::ImageFormat::eRg16Snorm, RImgCube
#define RFImgBufferRg16Snorm ast::type::ImageFormat::eRg16Snorm, RImgBuffer
#define RFImg1DArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, RImg1DArray
#define RFImg2DArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, RImg2DArray
#define RFImgCubeArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, RImgCubeArray
#define RFImg2DMSRg16Snorm ast::type::ImageFormat::eRg16Snorm, RImg2DMS
#define RFImg2DMSArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, RImg2DMSArray
#define RFImg1DRg8Snorm ast::type::ImageFormat::eRg8Snorm, RImg1D
#define RFImg2DRg8Snorm ast::type::ImageFormat::eRg8Snorm, RImg2D
#define RFImg3DRg8Snorm ast::type::ImageFormat::eRg8Snorm, RImg3D
#define RFImgCubeRg8Snorm ast::type::ImageFormat::eRg8Snorm, RImgCube
#define RFImgBufferRg8Snorm ast::type::ImageFormat::eRg8Snorm, RImgBuffer
#define RFImg1DArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, RImg1DArray
#define RFImg2DArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, RImg2DArray
#define RFImgCubeArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, RImgCubeArray
#define RFImg2DMSRg8Snorm ast::type::ImageFormat::eRg8Snorm, RImg2DMS
#define RFImg2DMSArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, RImg2DMSArray
#define RFImg1DRg16Unorm ast::type::ImageFormat::eRg16Unorm, RImg1D
#define RFImg2DRg16Unorm ast::type::ImageFormat::eRg16Unorm, RImg2D
#define RFImg3DRg16Unorm ast::type::ImageFormat::eRg16Unorm, RImg3D
#define RFImgCubeRg16Unorm ast::type::ImageFormat::eRg16Unorm, RImgCube
#define RFImgBufferRg16Unorm ast::type::ImageFormat::eRg16Unorm, RImgBuffer
#define RFImg1DArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, RImg1DArray
#define RFImg2DArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, RImg2DArray
#define RFImgCubeArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, RImgCubeArray
#define RFImg2DMSRg16Unorm ast::type::ImageFormat::eRg16Unorm, RImg2DMS
#define RFImg2DMSArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, RImg2DMSArray
#define RFImg1DRg8Unorm ast::type::ImageFormat::eRg8Unorm, RImg1D
#define RFImg2DRg8Unorm ast::type::ImageFormat::eRg8Unorm, RImg2D
#define RFImg3DRg8Unorm ast::type::ImageFormat::eRg8Unorm, RImg3D
#define RFImgCubeRg8Unorm ast::type::ImageFormat::eRg8Unorm, RImgCube
#define RFImgBufferRg8Unorm ast::type::ImageFormat::eRg8Unorm, RImgBuffer
#define RFImg1DArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, RImg1DArray
#define RFImg2DArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, RImg2DArray
#define RFImgCubeArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, RImgCubeArray
#define RFImg2DMSRg8Unorm ast::type::ImageFormat::eRg8Unorm, RImg2DMS
#define RFImg2DMSArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, RImg2DMSArray

#define RIImg1DRg8 ast::type::ImageFormat::eRg8i, RImg1D
#define RIImg2DRg8 ast::type::ImageFormat::eRg8i, RImg2D
#define RIImg3DRg8 ast::type::ImageFormat::eRg8i, RImg3D
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
#define RFImgCubeR32 ast::type::ImageFormat::eR32f, RImgCube
#define RFImgBufferR32 ast::type::ImageFormat::eR32f, RImgBuffer
#define RFImg1DArrayR32 ast::type::ImageFormat::eR32f, RImg1DArray
#define RFImg2DArrayR32 ast::type::ImageFormat::eR32f, RImg2DArray
#define RFImgCubeArrayR32 ast::type::ImageFormat::eR32f, RImgCubeArray
#define RFImg2DMSR32 ast::type::ImageFormat::eR32f, RImg2DMS
#define RFImg2DMSArrayR32 ast::type::ImageFormat::eR32f, RImg2DMSArray
#define RFImg1DR16Snorm ast::type::ImageFormat::eR16Snorm, RImg1D
#define RFImg2DR16Snorm ast::type::ImageFormat::eR16Snorm, RImg2D
#define RFImg3DR16Snorm ast::type::ImageFormat::eR16Snorm, RImg3D
#define RFImgCubeR16Snorm ast::type::ImageFormat::eR16Snorm, RImgCube
#define RFImgBufferR16Snorm ast::type::ImageFormat::eR16Snorm, RImgBuffer
#define RFImg1DArrayR16Snorm ast::type::ImageFormat::eR16Snorm, RImg1DArray
#define RFImg2DArrayR16Snorm ast::type::ImageFormat::eR16Snorm, RImg2DArray
#define RFImgCubeArrayR16Snorm ast::type::ImageFormat::eR16Snorm, RImgCubeArray
#define RFImg2DMSR16Snorm ast::type::ImageFormat::eR16Snorm, RImg2DMS
#define RFImg2DMSArrayR16Snorm ast::type::ImageFormat::eR16Snorm, RImg2DMSArray
#define RFImg1DR8Snorm ast::type::ImageFormat::eR8Snorm, RImg1D
#define RFImg2DR8Snorm ast::type::ImageFormat::eR8Snorm, RImg2D
#define RFImg3DR8Snorm ast::type::ImageFormat::eR8Snorm, RImg3D
#define RFImgCubeR8Snorm ast::type::ImageFormat::eR8Snorm, RImgCube
#define RFImgBufferR8Snorm ast::type::ImageFormat::eR8Snorm, RImgBuffer
#define RFImg1DArrayR8Snorm ast::type::ImageFormat::eR8Snorm, RImg1DArray
#define RFImg2DArrayR8Snorm ast::type::ImageFormat::eR8Snorm, RImg2DArray
#define RFImgCubeArrayR8Snorm ast::type::ImageFormat::eR8Snorm, RImgCubeArray
#define RFImg2DMSR8Snorm ast::type::ImageFormat::eR8Snorm, RImg2DMS
#define RFImg2DMSArrayR8Snorm ast::type::ImageFormat::eR8Snorm, RImg2DMSArray
#define RFImg1DR16Unorm ast::type::ImageFormat::eR16Unorm, RImg1D
#define RFImg2DR16Unorm ast::type::ImageFormat::eR16Unorm, RImg2D
#define RFImg3DR16Unorm ast::type::ImageFormat::eR16Unorm, RImg3D
#define RFImgCubeR16Unorm ast::type::ImageFormat::eR16Unorm, RImgCube
#define RFImgBufferR16Unorm ast::type::ImageFormat::eR16Unorm, RImgBuffer
#define RFImg1DArrayR16Unorm ast::type::ImageFormat::eR16Unorm, RImg1DArray
#define RFImg2DArrayR16Unorm ast::type::ImageFormat::eR16Unorm, RImg2DArray
#define RFImgCubeArrayR16Unorm ast::type::ImageFormat::eR16Unorm, RImgCubeArray
#define RFImg2DMSR16Unorm ast::type::ImageFormat::eR16Unorm, RImg2DMS
#define RFImg2DMSArrayR16Unorm ast::type::ImageFormat::eR16Unorm, RImg2DMSArray
#define RFImg1DR8Unorm ast::type::ImageFormat::eR8Unorm, RImg1D
#define RFImg2DR8Unorm ast::type::ImageFormat::eR8Unorm, RImg2D
#define RFImg3DR8Unorm ast::type::ImageFormat::eR8Unorm, RImg3D
#define RFImgCubeR8Unorm ast::type::ImageFormat::eR8Unorm, RImgCube
#define RFImgBufferR8Unorm ast::type::ImageFormat::eR8Unorm, RImgBuffer
#define RFImg1DArrayR8Unorm ast::type::ImageFormat::eR8Unorm, RImg1DArray
#define RFImg2DArrayR8Unorm ast::type::ImageFormat::eR8Unorm, RImg2DArray
#define RFImgCubeArrayR8Unorm ast::type::ImageFormat::eR8Unorm, RImgCubeArray
#define RFImg2DMSR8Unorm ast::type::ImageFormat::eR8Unorm, RImg2DMS
#define RFImg2DMSArrayR8Unorm ast::type::ImageFormat::eR8Unorm, RImg2DMSArray

#define RIImg1DR8 ast::type::ImageFormat::eR8i, RImg1D
#define RIImg2DR8 ast::type::ImageFormat::eR8i, RImg2D
#define RIImg3DR8 ast::type::ImageFormat::eR8i, RImg3D
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
#define RUImgCubeR32 ast::type::ImageFormat::eR32u, RImgCube
#define RUImgBufferR32 ast::type::ImageFormat::eR32u, RImgBuffer
#define RUImg1DArrayR32 ast::type::ImageFormat::eR32u, RImg1DArray
#define RUImg2DArrayR32 ast::type::ImageFormat::eR32u, RImg2DArray
#define RUImgCubeArrayR32 ast::type::ImageFormat::eR32u, RImgCubeArray
#define RUImg2DMSR32 ast::type::ImageFormat::eR32u, RImg2DMS
#define RUImg2DMSArrayR32 ast::type::ImageFormat::eR32u, RImg2DMSArray

#define WImg1D ast::type::AccessKind::eWrite, Img1DBase
#define WImg2D ast::type::AccessKind::eWrite, Img2DBase
#define WImg3D ast::type::AccessKind::eWrite, Img3DBase
#define WImgCube ast::type::AccessKind::eWrite, ImgCubeBase
#define WImgBuffer ast::type::AccessKind::eWrite, ImgBufferBase
#define WImg1DArray ast::type::AccessKind::eWrite, Img1DArrayBase
#define WImg2DArray ast::type::AccessKind::eWrite, Img2DArrayBase
#define WImgCubeArray ast::type::AccessKind::eWrite, ImgCubeArrayBase
#define WImg2DMS ast::type::AccessKind::eWrite, Img2DMSBase
#define WImg2DMSArray ast::type::AccessKind::eWrite, Img2DMSArrayBase

#define WImg1DRgba ast::type::ImageFormat::eRgbaTypeless, WImg1D
#define WImg2DRgba ast::type::ImageFormat::eRgbaTypeless, WImg2D
#define WImg3DRgba ast::type::ImageFormat::eRgbaTypeless, WImg3D
#define WImgCubeRgba ast::type::ImageFormat::eRgbaTypeless, WImgCube
#define WImgBufferRgba ast::type::ImageFormat::eRgbaTypeless, WImgBuffer
#define WImg1DArrayRgba ast::type::ImageFormat::eRgbaTypeless, WImg1DArray
#define WImg2DArrayRgba ast::type::ImageFormat::eRgbaTypeless, WImg2DArray
#define WImgCubeArrayRgba ast::type::ImageFormat::eRgbaTypeless, WImgCubeArray
#define WImg2DMSRgba ast::type::ImageFormat::eRgbaTypeless, WImg2DMS
#define WImg2DMSArrayRgba ast::type::ImageFormat::eRgbaTypeless, WImg2DMSArray

#define WFImg1DRgba16 ast::type::ImageFormat::eRgba16f, WImg1D
#define WFImg2DRgba16 ast::type::ImageFormat::eRgba16f, WImg2D
#define WFImg3DRgba16 ast::type::ImageFormat::eRgba16f, WImg3D
#define WFImgCubeRgba16 ast::type::ImageFormat::eRgba16f, WImgCube
#define WFImgBufferRgba16 ast::type::ImageFormat::eRgba16f, WImgBuffer
#define WFImg1DArrayRgba16 ast::type::ImageFormat::eRgba16f, WImg1DArray
#define WFImg2DArrayRgba16 ast::type::ImageFormat::eRgba16f, WImg2DArray
#define WFImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16f, WImgCubeArray
#define WFImg2DMSRgba16 ast::type::ImageFormat::eRgba16f, WImg2DMS
#define WFImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16f, WImg2DMSArray
#define WFImg1DRgba32 ast::type::ImageFormat::eRgba32f, WImg1D
#define WFImg2DRgba32 ast::type::ImageFormat::eRgba32f, WImg2D
#define WFImg3DRgba32 ast::type::ImageFormat::eRgba32f, WImg3D
#define WFImgCubeRgba32 ast::type::ImageFormat::eRgba32f, WImgCube
#define WFImgBufferRgba32 ast::type::ImageFormat::eRgba32f, WImgBuffer
#define WFImg1DArrayRgba32 ast::type::ImageFormat::eRgba32f, WImg1DArray
#define WFImg2DArrayRgba32 ast::type::ImageFormat::eRgba32f, WImg2DArray
#define WFImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32f, WImgCubeArray
#define WFImg2DMSRgba32 ast::type::ImageFormat::eRgba32f, WImg2DMS
#define WFImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32f, WImg2DMSArray
#define WFImg1DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, WImg1D
#define WFImg2DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, WImg2D
#define WFImg3DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, WImg3D
#define WFImgCubeRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, WImgCube
#define WFImgBufferRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, WImgBuffer
#define WFImg1DArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, WImg1DArray
#define WFImg2DArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, WImg2DArray
#define WFImgCubeArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, WImgCubeArray
#define WFImg2DMSRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, WImg2DMS
#define WFImg2DMSArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, WImg2DMSArray
#define WFImg1DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, WImg1D
#define WFImg2DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, WImg2D
#define WFImg3DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, WImg3D
#define WFImgCubeRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, WImgCube
#define WFImgBufferRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, WImgBuffer
#define WFImg1DArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, WImg1DArray
#define WFImg2DArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, WImg2DArray
#define WFImgCubeArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, WImgCubeArray
#define WFImg2DMSRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, WImg2DMS
#define WFImg2DMSArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, WImg2DMSArray
#define WFImg1DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, WImg1D
#define WFImg2DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, WImg2D
#define WFImg3DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, WImg3D
#define WFImgCubeRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, WImgCube
#define WFImgBufferRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, WImgBuffer
#define WFImg1DArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, WImg1DArray
#define WFImg2DArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, WImg2DArray
#define WFImgCubeArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, WImgCubeArray
#define WFImg2DMSRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, WImg2DMS
#define WFImg2DMSArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, WImg2DMSArray
#define WFImg1DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, WImg1D
#define WFImg2DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, WImg2D
#define WFImg3DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, WImg3D
#define WFImgCubeRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, WImgCube
#define WFImgBufferRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, WImgBuffer
#define WFImg1DArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, WImg1DArray
#define WFImg2DArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, WImg2DArray
#define WFImgCubeArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, WImgCubeArray
#define WFImg2DMSRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, WImg2DMS
#define WFImg2DMSArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, WImg2DMSArray
#define WFImg1DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, WImg1D
#define WFImg2DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, WImg2D
#define WFImg3DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, WImg3D
#define WFImgCubeR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, WImgCube
#define WFImgBufferR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, WImgBuffer
#define WFImg1DArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, WImg1DArray
#define WFImg2DArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, WImg2DArray
#define WFImgCubeArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, WImgCubeArray
#define WFImg2DMSR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, WImg2DMS
#define WFImg2DMSArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, WImg2DMSArray
#define WFImg1DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, WImg1D
#define WFImg2DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, WImg2D
#define WFImg3DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, WImg3D
#define WFImgCubeRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, WImgCube
#define WFImgBufferRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, WImgBuffer
#define WFImg1DArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, WImg1DArray
#define WFImg2DArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, WImg2DArray
#define WFImgCubeArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, WImgCubeArray
#define WFImg2DMSRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, WImg2DMS
#define WFImg2DMSArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, WImg2DMSArray

#define WIImg1DRgba8 ast::type::ImageFormat::eRgba8i, WImg1D
#define WIImg2DRgba8 ast::type::ImageFormat::eRgba8i, WImg2D
#define WIImg3DRgba8 ast::type::ImageFormat::eRgba8i, WImg3D
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
#define WUImgCubeRgba32 ast::type::ImageFormat::eRgba32u, WImgCube
#define WUImgBufferRgba32 ast::type::ImageFormat::eRgba32u, WImgBuffer
#define WUImg1DArrayRgba32 ast::type::ImageFormat::eRgba32u, WImg1DArray
#define WUImg2DArrayRgba32 ast::type::ImageFormat::eRgba32u, WImg2DArray
#define WUImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32u, WImgCubeArray
#define WUImg2DMSRgba32 ast::type::ImageFormat::eRgba32u, WImg2DMS
#define WUImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32u, WImg2DMSArray
#define WUImg1DRgb10A2 ast::type::ImageFormat::eRgb10A2u, WImg1D
#define WUImg2DRgb10A2 ast::type::ImageFormat::eRgb10A2u, WImg2D
#define WUImg3DRgb10A2 ast::type::ImageFormat::eRgb10A2u, WImg3D
#define WUImgCubeRgb10A2 ast::type::ImageFormat::eRgb10A2u, WImgCube
#define WUImgBufferRgb10A2 ast::type::ImageFormat::eRgb10A2u, WImgBuffer
#define WUImg1DArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, WImg1DArray
#define WUImg2DArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, WImg2DArray
#define WUImgCubeArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, WImgCubeArray
#define WUImg2DMSRgb10A2 ast::type::ImageFormat::eRgb10A2u, WImg2DMS
#define WUImg2DMSArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, WImg2DMSArray

#define WImg1DRg ast::type::ImageFormat::eRgTypeless, WImg1D
#define WImg2DRg ast::type::ImageFormat::eRgTypeless, WImg2D
#define WImg3DRg ast::type::ImageFormat::eRgTypeless, WImg3D
#define WImgCubeRg ast::type::ImageFormat::eRgTypeless, WImgCube
#define WImgBufferRg ast::type::ImageFormat::eRgTypeless, WImgBuffer
#define WImg1DArrayRg ast::type::ImageFormat::eRgTypeless, WImg1DArray
#define WImg2DArrayRg ast::type::ImageFormat::eRgTypeless, WImg2DArray
#define WImgCubeArrayRg ast::type::ImageFormat::eRgTypeless, WImgCubeArray
#define WImg2DMSRg ast::type::ImageFormat::eRgTypeless, WImg2DMS
#define WImg2DMSArrayRg ast::type::ImageFormat::eRgTypeless, WImg2DMSArray

#define WFImg1DRg16 ast::type::ImageFormat::eRg16f, WImg1D
#define WFImg2DRg16 ast::type::ImageFormat::eRg16f, WImg2D
#define WFImg3DRg16 ast::type::ImageFormat::eRg16f, WImg3D
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
#define WFImgCubeRg32 ast::type::ImageFormat::eRg32f, WImgCube
#define WFImgBufferRg32 ast::type::ImageFormat::eRg32f, WImgBuffer
#define WFImg1DArrayRg32 ast::type::ImageFormat::eRg32f, WImg1DArray
#define WFImg2DArrayRg32 ast::type::ImageFormat::eRg32f, WImg2DArray
#define WFImgCubeArrayRg32 ast::type::ImageFormat::eRg32f, WImgCubeArray
#define WFImg2DMSRg32 ast::type::ImageFormat::eRg32f, WImg2DMS
#define WFImg2DMSArrayRg32 ast::type::ImageFormat::eRg32f, WImg2DMSArray
#define WFImg1DRg16Snorm ast::type::ImageFormat::eRg16Snorm, WImg1D
#define WFImg2DRg16Snorm ast::type::ImageFormat::eRg16Snorm, WImg2D
#define WFImg3DRg16Snorm ast::type::ImageFormat::eRg16Snorm, WImg3D
#define WFImgCubeRg16Snorm ast::type::ImageFormat::eRg16Snorm, WImgCube
#define WFImgBufferRg16Snorm ast::type::ImageFormat::eRg16Snorm, WImgBuffer
#define WFImg1DArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, WImg1DArray
#define WFImg2DArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, WImg2DArray
#define WFImgCubeArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, WImgCubeArray
#define WFImg2DMSRg16Snorm ast::type::ImageFormat::eRg16Snorm, WImg2DMS
#define WFImg2DMSArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, WImg2DMSArray
#define WFImg1DRg8Snorm ast::type::ImageFormat::eRg8Snorm, WImg1D
#define WFImg2DRg8Snorm ast::type::ImageFormat::eRg8Snorm, WImg2D
#define WFImg3DRg8Snorm ast::type::ImageFormat::eRg8Snorm, WImg3D
#define WFImgCubeRg8Snorm ast::type::ImageFormat::eRg8Snorm, WImgCube
#define WFImgBufferRg8Snorm ast::type::ImageFormat::eRg8Snorm, WImgBuffer
#define WFImg1DArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, WImg1DArray
#define WFImg2DArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, WImg2DArray
#define WFImgCubeArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, WImgCubeArray
#define WFImg2DMSRg8Snorm ast::type::ImageFormat::eRg8Snorm, WImg2DMS
#define WFImg2DMSArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, WImg2DMSArray
#define WFImg1DRg16Unorm ast::type::ImageFormat::eRg16Unorm, WImg1D
#define WFImg2DRg16Unorm ast::type::ImageFormat::eRg16Unorm, WImg2D
#define WFImg3DRg16Unorm ast::type::ImageFormat::eRg16Unorm, WImg3D
#define WFImgCubeRg16Unorm ast::type::ImageFormat::eRg16Unorm, WImgCube
#define WFImgBufferRg16Unorm ast::type::ImageFormat::eRg16Unorm, WImgBuffer
#define WFImg1DArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, WImg1DArray
#define WFImg2DArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, WImg2DArray
#define WFImgCubeArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, WImgCubeArray
#define WFImg2DMSRg16Unorm ast::type::ImageFormat::eRg16Unorm, WImg2DMS
#define WFImg2DMSArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, WImg2DMSArray
#define WFImg1DRg8Unorm ast::type::ImageFormat::eRg8Unorm, WImg1D
#define WFImg2DRg8Unorm ast::type::ImageFormat::eRg8Unorm, WImg2D
#define WFImg3DRg8Unorm ast::type::ImageFormat::eRg8Unorm, WImg3D
#define WFImgCubeRg8Unorm ast::type::ImageFormat::eRg8Unorm, WImgCube
#define WFImgBufferRg8Unorm ast::type::ImageFormat::eRg8Unorm, WImgBuffer
#define WFImg1DArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, WImg1DArray
#define WFImg2DArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, WImg2DArray
#define WFImgCubeArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, WImgCubeArray
#define WFImg2DMSRg8Unorm ast::type::ImageFormat::eRg8Unorm, WImg2DMS
#define WFImg2DMSArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, WImg2DMSArray

#define WIImg1DRg8 ast::type::ImageFormat::eRg8i, WImg1D
#define WIImg2DRg8 ast::type::ImageFormat::eRg8i, WImg2D
#define WIImg3DRg8 ast::type::ImageFormat::eRg8i, WImg3D
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
#define WUImgCubeRg32 ast::type::ImageFormat::eRg32u, WImgCube
#define WUImgBufferRg32 ast::type::ImageFormat::eRg32u, WImgBuffer
#define WUImg1DArrayRg32 ast::type::ImageFormat::eRg32u, WImg1DArray
#define WUImg2DArrayRg32 ast::type::ImageFormat::eRg32u, WImg2DArray
#define WUImgCubeArrayRg32 ast::type::ImageFormat::eRg32u, WImgCubeArray
#define WUImg2DMSRg32 ast::type::ImageFormat::eRg32u, WImg2DMS
#define WUImg2DMSArrayRg32 ast::type::ImageFormat::eRg32u, WImg2DMSArray

#define WImg1DR ast::type::ImageFormat::eRTypeless, WImg1D
#define WImg2DR ast::type::ImageFormat::eRTypeless, WImg2D
#define WImg3DR ast::type::ImageFormat::eRTypeless, WImg3D
#define WImgCubeR ast::type::ImageFormat::eRTypeless, WImgCube
#define WImgBufferR ast::type::ImageFormat::eRTypeless, WImgBuffer
#define WImg1DArrayR ast::type::ImageFormat::eRTypeless, WImg1DArray
#define WImg2DArrayR ast::type::ImageFormat::eRTypeless, WImg2DArray
#define WImgCubeArrayR ast::type::ImageFormat::eRTypeless, WImgCubeArray
#define WImg2DMSR ast::type::ImageFormat::eRTypeless, WImg2DMS
#define WImg2DMSArrayR ast::type::ImageFormat::eRTypeless, WImg2DMSArray

#define WFImg1DR16 ast::type::ImageFormat::eR16f, WImg1D
#define WFImg2DR16 ast::type::ImageFormat::eR16f, WImg2D
#define WFImg3DR16 ast::type::ImageFormat::eR16f, WImg3D
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
#define WFImgCubeR32 ast::type::ImageFormat::eR32f, WImgCube
#define WFImgBufferR32 ast::type::ImageFormat::eR32f, WImgBuffer
#define WFImg1DArrayR32 ast::type::ImageFormat::eR32f, WImg1DArray
#define WFImg2DArrayR32 ast::type::ImageFormat::eR32f, WImg2DArray
#define WFImgCubeArrayR32 ast::type::ImageFormat::eR32f, WImgCubeArray
#define WFImg2DMSR32 ast::type::ImageFormat::eR32f, WImg2DMS
#define WFImg2DMSArrayR32 ast::type::ImageFormat::eR32f, WImg2DMSArray
#define WFImg1DR16Snorm ast::type::ImageFormat::eR16Snorm, WImg1D
#define WFImg2DR16Snorm ast::type::ImageFormat::eR16Snorm, WImg2D
#define WFImg3DR16Snorm ast::type::ImageFormat::eR16Snorm, WImg3D
#define WFImgCubeR16Snorm ast::type::ImageFormat::eR16Snorm, WImgCube
#define WFImgBufferR16Snorm ast::type::ImageFormat::eR16Snorm, WImgBuffer
#define WFImg1DArrayR16Snorm ast::type::ImageFormat::eR16Snorm, WImg1DArray
#define WFImg2DArrayR16Snorm ast::type::ImageFormat::eR16Snorm, WImg2DArray
#define WFImgCubeArrayR16Snorm ast::type::ImageFormat::eR16Snorm, WImgCubeArray
#define WFImg2DMSR16Snorm ast::type::ImageFormat::eR16Snorm, WImg2DMS
#define WFImg2DMSArrayR16Snorm ast::type::ImageFormat::eR16Snorm, WImg2DMSArray
#define WFImg1DR8Snorm ast::type::ImageFormat::eR8Snorm, WImg1D
#define WFImg2DR8Snorm ast::type::ImageFormat::eR8Snorm, WImg2D
#define WFImg3DR8Snorm ast::type::ImageFormat::eR8Snorm, WImg3D
#define WFImgCubeR8Snorm ast::type::ImageFormat::eR8Snorm, WImgCube
#define WFImgBufferR8Snorm ast::type::ImageFormat::eR8Snorm, WImgBuffer
#define WFImg1DArrayR8Snorm ast::type::ImageFormat::eR8Snorm, WImg1DArray
#define WFImg2DArrayR8Snorm ast::type::ImageFormat::eR8Snorm, WImg2DArray
#define WFImgCubeArrayR8Snorm ast::type::ImageFormat::eR8Snorm, WImgCubeArray
#define WFImg2DMSR8Snorm ast::type::ImageFormat::eR8Snorm, WImg2DMS
#define WFImg2DMSArrayR8Snorm ast::type::ImageFormat::eR8Snorm, WImg2DMSArray
#define WFImg1DR16Unorm ast::type::ImageFormat::eR16Unorm, WImg1D
#define WFImg2DR16Unorm ast::type::ImageFormat::eR16Unorm, WImg2D
#define WFImg3DR16Unorm ast::type::ImageFormat::eR16Unorm, WImg3D
#define WFImgCubeR16Unorm ast::type::ImageFormat::eR16Unorm, WImgCube
#define WFImgBufferR16Unorm ast::type::ImageFormat::eR16Unorm, WImgBuffer
#define WFImg1DArrayR16Unorm ast::type::ImageFormat::eR16Unorm, WImg1DArray
#define WFImg2DArrayR16Unorm ast::type::ImageFormat::eR16Unorm, WImg2DArray
#define WFImgCubeArrayR16Unorm ast::type::ImageFormat::eR16Unorm, WImgCubeArray
#define WFImg2DMSR16Unorm ast::type::ImageFormat::eR16Unorm, WImg2DMS
#define WFImg2DMSArrayR16Unorm ast::type::ImageFormat::eR16Unorm, WImg2DMSArray
#define WFImg1DR8Unorm ast::type::ImageFormat::eR8Unorm, WImg1D
#define WFImg2DR8Unorm ast::type::ImageFormat::eR8Unorm, WImg2D
#define WFImg3DR8Unorm ast::type::ImageFormat::eR8Unorm, WImg3D
#define WFImgCubeR8Unorm ast::type::ImageFormat::eR8Unorm, WImgCube
#define WFImgBufferR8Unorm ast::type::ImageFormat::eR8Unorm, WImgBuffer
#define WFImg1DArrayR8Unorm ast::type::ImageFormat::eR8Unorm, WImg1DArray
#define WFImg2DArrayR8Unorm ast::type::ImageFormat::eR8Unorm, WImg2DArray
#define WFImgCubeArrayR8Unorm ast::type::ImageFormat::eR8Unorm, WImgCubeArray
#define WFImg2DMSR8Unorm ast::type::ImageFormat::eR8Unorm, WImg2DMS
#define WFImg2DMSArrayR8Unorm ast::type::ImageFormat::eR8Unorm, WImg2DMSArray

#define WIImg1DR8 ast::type::ImageFormat::eR8i, WImg1D
#define WIImg2DR8 ast::type::ImageFormat::eR8i, WImg2D
#define WIImg3DR8 ast::type::ImageFormat::eR8i, WImg3D
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
#define WUImgCubeR32 ast::type::ImageFormat::eR32u, WImgCube
#define WUImgBufferR32 ast::type::ImageFormat::eR32u, WImgBuffer
#define WUImg1DArrayR32 ast::type::ImageFormat::eR32u, WImg1DArray
#define WUImg2DArrayR32 ast::type::ImageFormat::eR32u, WImg2DArray
#define WUImgCubeArrayR32 ast::type::ImageFormat::eR32u, WImgCubeArray
#define WUImg2DMSR32 ast::type::ImageFormat::eR32u, WImg2DMS
#define WUImg2DMSArrayR32 ast::type::ImageFormat::eR32u, WImg2DMSArray

#define RWImg1D ast::type::AccessKind::eReadWrite, Img1DBase
#define RWImg2D ast::type::AccessKind::eReadWrite, Img2DBase
#define RWImg3D ast::type::AccessKind::eReadWrite, Img3DBase
#define RWImgCube ast::type::AccessKind::eReadWrite, ImgCubeBase
#define RWImgBuffer ast::type::AccessKind::eReadWrite, ImgBufferBase
#define RWImg1DArray ast::type::AccessKind::eReadWrite, Img1DArrayBase
#define RWImg2DArray ast::type::AccessKind::eReadWrite, Img2DArrayBase
#define RWImgCubeArray ast::type::AccessKind::eReadWrite, ImgCubeArrayBase
#define RWImg2DMS ast::type::AccessKind::eReadWrite, Img2DMSBase
#define RWImg2DMSArray ast::type::AccessKind::eReadWrite, Img2DMSArrayBase

#define RWFImg1DRgba16 ast::type::ImageFormat::eRgba16f, RWImg1D
#define RWFImg2DRgba16 ast::type::ImageFormat::eRgba16f, RWImg2D
#define RWFImg3DRgba16 ast::type::ImageFormat::eRgba16f, RWImg3D
#define RWFImgCubeRgba16 ast::type::ImageFormat::eRgba16f, RWImgCube
#define RWFImgBufferRgba16 ast::type::ImageFormat::eRgba16f, RWImgBuffer
#define RWFImg1DArrayRgba16 ast::type::ImageFormat::eRgba16f, RWImg1DArray
#define RWFImg2DArrayRgba16 ast::type::ImageFormat::eRgba16f, RWImg2DArray
#define RWFImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16f, RWImgCubeArray
#define RWFImg2DMSRgba16 ast::type::ImageFormat::eRgba16f, RWImg2DMS
#define RWFImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16f, RWImg2DMSArray
#define RWFImg1DRgba32 ast::type::ImageFormat::eRgba32f, RWImg1D
#define RWFImg2DRgba32 ast::type::ImageFormat::eRgba32f, RWImg2D
#define RWFImg3DRgba32 ast::type::ImageFormat::eRgba32f, RWImg3D
#define RWFImgCubeRgba32 ast::type::ImageFormat::eRgba32f, RWImgCube
#define RWFImgBufferRgba32 ast::type::ImageFormat::eRgba32f, RWImgBuffer
#define RWFImg1DArrayRgba32 ast::type::ImageFormat::eRgba32f, RWImg1DArray
#define RWFImg2DArrayRgba32 ast::type::ImageFormat::eRgba32f, RWImg2DArray
#define RWFImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32f, RWImgCubeArray
#define RWFImg2DMSRgba32 ast::type::ImageFormat::eRgba32f, RWImg2DMS
#define RWFImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32f, RWImg2DMSArray
#define RWFImg1DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RWImg1D
#define RWFImg2DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RWImg2D
#define RWFImg3DRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RWImg3D
#define RWFImgCubeRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RWImgCube
#define RWFImgBufferRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RWImgBuffer
#define RWFImg1DArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RWImg1DArray
#define RWFImg2DArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RWImg2DArray
#define RWFImgCubeArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RWImgCubeArray
#define RWFImg2DMSRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RWImg2DMS
#define RWFImg2DMSArrayRgba16Snorm ast::type::ImageFormat::eRgba16Snorm, RWImg2DMSArray
#define RWFImg1DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RWImg1D
#define RWFImg2DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RWImg2D
#define RWFImg3DRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RWImg3D
#define RWFImgCubeRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RWImgCube
#define RWFImgBufferRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RWImgBuffer
#define RWFImg1DArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RWImg1DArray
#define RWFImg2DArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RWImg2DArray
#define RWFImgCubeArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RWImgCubeArray
#define RWFImg2DMSRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RWImg2DMS
#define RWFImg2DMSArrayRgba8Snorm ast::type::ImageFormat::eRgba8Snorm, RWImg2DMSArray
#define RWFImg1DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RWImg1D
#define RWFImg2DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RWImg2D
#define RWFImg3DRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RWImg3D
#define RWFImgCubeRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RWImgCube
#define RWFImgBufferRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RWImgBuffer
#define RWFImg1DArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RWImg1DArray
#define RWFImg2DArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RWImg2DArray
#define RWFImgCubeArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RWImgCubeArray
#define RWFImg2DMSRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RWImg2DMS
#define RWFImg2DMSArrayRgba16Unorm ast::type::ImageFormat::eRgba16Unorm, RWImg2DMSArray
#define RWFImg1DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RWImg1D
#define RWFImg2DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RWImg2D
#define RWFImg3DRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RWImg3D
#define RWFImgCubeRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RWImgCube
#define RWFImgBufferRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RWImgBuffer
#define RWFImg1DArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RWImg1DArray
#define RWFImg2DArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RWImg2DArray
#define RWFImgCubeArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RWImgCubeArray
#define RWFImg2DMSRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RWImg2DMS
#define RWFImg2DMSArrayRgba8Unorm ast::type::ImageFormat::eRgba8Unorm, RWImg2DMSArray
#define RWFImg1DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RWImg1D
#define RWFImg2DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RWImg2D
#define RWFImg3DR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RWImg3D
#define RWFImgCubeR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RWImgCube
#define RWFImgBufferR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RWImgBuffer
#define RWFImg1DArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RWImg1DArray
#define RWFImg2DArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RWImg2DArray
#define RWFImgCubeArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RWImgCubeArray
#define RWFImg2DMSR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RWImg2DMS
#define RWFImg2DMSArrayR11fG11fB10f ast::type::ImageFormat::eR11fG11fB10f, RWImg2DMSArray
#define RWFImg1DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RWImg1D
#define RWFImg2DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RWImg2D
#define RWFImg3DRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RWImg3D
#define RWFImgCubeRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RWImgCube
#define RWFImgBufferRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RWImgBuffer
#define RWFImg1DArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RWImg1DArray
#define RWFImg2DArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RWImg2DArray
#define RWFImgCubeArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RWImgCubeArray
#define RWFImg2DMSRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RWImg2DMS
#define RWFImg2DMSArrayRgb10A2Unorm ast::type::ImageFormat::eRgb10A2Unorm, RWImg2DMSArray

#define RWIImg1DRgba8 ast::type::ImageFormat::eRgba8i, RWImg1D
#define RWIImg2DRgba8 ast::type::ImageFormat::eRgba8i, RWImg2D
#define RWIImg3DRgba8 ast::type::ImageFormat::eRgba8i, RWImg3D
#define RWIImgCubeRgba8 ast::type::ImageFormat::eRgba8i, RWImgCube
#define RWIImgBufferRgba8 ast::type::ImageFormat::eRgba8i, RWImgBuffer
#define RWIImg1DArrayRgba8 ast::type::ImageFormat::eRgba8i, RWImg1DArray
#define RWIImg2DArrayRgba8 ast::type::ImageFormat::eRgba8i, RWImg2DArray
#define RWIImgCubeArrayRgba8 ast::type::ImageFormat::eRgba8i, RWImgCubeArray
#define RWIImg2DMSRgba8 ast::type::ImageFormat::eRgba8i, RWImg2DMS
#define RWIImg2DMSArrayRgba8 ast::type::ImageFormat::eRgba8i, RWImg2DMSArray
#define RWIImg1DRgba16 ast::type::ImageFormat::eRgba16i, RWImg1D
#define RWIImg2DRgba16 ast::type::ImageFormat::eRgba16i, RWImg2D
#define RWIImg3DRgba16 ast::type::ImageFormat::eRgba16i, RWImg3D
#define RWIImgCubeRgba16 ast::type::ImageFormat::eRgba16i, RWImgCube
#define RWIImgBufferRgba16 ast::type::ImageFormat::eRgba16i, RWImgBuffer
#define RWIImg1DArrayRgba16 ast::type::ImageFormat::eRgba16i, RWImg1DArray
#define RWIImg2DArrayRgba16 ast::type::ImageFormat::eRgba16i, RWImg2DArray
#define RWIImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16i, RWImgCubeArray
#define RWIImg2DMSRgba16 ast::type::ImageFormat::eRgba16i, RWImg2DMS
#define RWIImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16i, RWImg2DMSArray
#define RWIImg1DRgba32 ast::type::ImageFormat::eRgba32i, RWImg1D
#define RWIImg2DRgba32 ast::type::ImageFormat::eRgba32i, RWImg2D
#define RWIImg3DRgba32 ast::type::ImageFormat::eRgba32i, RWImg3D
#define RWIImgCubeRgba32 ast::type::ImageFormat::eRgba32i, RWImgCube
#define RWIImgBufferRgba32 ast::type::ImageFormat::eRgba32i, RWImgBuffer
#define RWIImg1DArrayRgba32 ast::type::ImageFormat::eRgba32i, RWImg1DArray
#define RWIImg2DArrayRgba32 ast::type::ImageFormat::eRgba32i, RWImg2DArray
#define RWIImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32i, RWImgCubeArray
#define RWIImg2DMSRgba32 ast::type::ImageFormat::eRgba32i, RWImg2DMS
#define RWIImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32i, RWImg2DMSArray

#define RWUImg1DRgba8 ast::type::ImageFormat::eRgba8u, RWImg1D
#define RWUImg2DRgba8 ast::type::ImageFormat::eRgba8u, RWImg2D
#define RWUImg3DRgba8 ast::type::ImageFormat::eRgba8u, RWImg3D
#define RWUImgCubeRgba8 ast::type::ImageFormat::eRgba8u, RWImgCube
#define RWUImgBufferRgba8 ast::type::ImageFormat::eRgba8u, RWImgBuffer
#define RWUImg1DArrayRgba8 ast::type::ImageFormat::eRgba8u, RWImg1DArray
#define RWUImg2DArrayRgba8 ast::type::ImageFormat::eRgba8u, RWImg2DArray
#define RWUImgCubeArrayRgba8 ast::type::ImageFormat::eRgba8u, RWImgCubeArray
#define RWUImg2DMSRgba8 ast::type::ImageFormat::eRgba8u, RWImg2DMS
#define RWUImg2DMSArrayRgba8 ast::type::ImageFormat::eRgba8u, RWImg2DMSArray
#define RWUImg1DRgba16 ast::type::ImageFormat::eRgba16u, RWImg1D
#define RWUImg2DRgba16 ast::type::ImageFormat::eRgba16u, RWImg2D
#define RWUImg3DRgba16 ast::type::ImageFormat::eRgba16u, RWImg3D
#define RWUImgCubeRgba16 ast::type::ImageFormat::eRgba16u, RWImgCube
#define RWUImgBufferRgba16 ast::type::ImageFormat::eRgba16u, RWImgBuffer
#define RWUImg1DArrayRgba16 ast::type::ImageFormat::eRgba16u, RWImg1DArray
#define RWUImg2DArrayRgba16 ast::type::ImageFormat::eRgba16u, RWImg2DArray
#define RWUImgCubeArrayRgba16 ast::type::ImageFormat::eRgba16u, RWImgCubeArray
#define RWUImg2DMSRgba16 ast::type::ImageFormat::eRgba16u, RWImg2DMS
#define RWUImg2DMSArrayRgba16 ast::type::ImageFormat::eRgba16u, RWImg2DMSArray
#define RWUImg1DRgba32 ast::type::ImageFormat::eRgba32u, RWImg1D
#define RWUImg2DRgba32 ast::type::ImageFormat::eRgba32u, RWImg2D
#define RWUImg3DRgba32 ast::type::ImageFormat::eRgba32u, RWImg3D
#define RWUImgCubeRgba32 ast::type::ImageFormat::eRgba32u, RWImgCube
#define RWUImgBufferRgba32 ast::type::ImageFormat::eRgba32u, RWImgBuffer
#define RWUImg1DArrayRgba32 ast::type::ImageFormat::eRgba32u, RWImg1DArray
#define RWUImg2DArrayRgba32 ast::type::ImageFormat::eRgba32u, RWImg2DArray
#define RWUImgCubeArrayRgba32 ast::type::ImageFormat::eRgba32u, RWImgCubeArray
#define RWUImg2DMSRgba32 ast::type::ImageFormat::eRgba32u, RWImg2DMS
#define RWUImg2DMSArrayRgba32 ast::type::ImageFormat::eRgba32u, RWImg2DMSArray
#define RWUImg1DRgb10A2 ast::type::ImageFormat::eRgb10A2u, RWImg1D
#define RWUImg2DRgb10A2 ast::type::ImageFormat::eRgb10A2u, RWImg2D
#define RWUImg3DRgb10A2 ast::type::ImageFormat::eRgb10A2u, RWImg3D
#define RWUImgCubeRgb10A2 ast::type::ImageFormat::eRgb10A2u, RWImgCube
#define RWUImgBufferRgb10A2 ast::type::ImageFormat::eRgb10A2u, RWImgBuffer
#define RWUImg1DArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, RWImg1DArray
#define RWUImg2DArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, RWImg2DArray
#define RWUImgCubeArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, RWImgCubeArray
#define RWUImg2DMSRgb10A2 ast::type::ImageFormat::eRgb10A2u, RWImg2DMS
#define RWUImg2DMSArrayRgb10A2 ast::type::ImageFormat::eRgb10A2u, RWImg2DMSArray

#define RWFImg1DRg16 ast::type::ImageFormat::eRg16f, RWImg1D
#define RWFImg2DRg16 ast::type::ImageFormat::eRg16f, RWImg2D
#define RWFImg3DRg16 ast::type::ImageFormat::eRg16f, RWImg3D
#define RWFImgCubeRg16 ast::type::ImageFormat::eRg16f, RWImgCube
#define RWFImgBufferRg16 ast::type::ImageFormat::eRg16f, RWImgBuffer
#define RWFImg1DArrayRg16 ast::type::ImageFormat::eRg16f, RWImg1DArray
#define RWFImg2DArrayRg16 ast::type::ImageFormat::eRg16f, RWImg2DArray
#define RWFImgCubeArrayRg16 ast::type::ImageFormat::eRg16f, RWImgCubeArray
#define RWFImg2DMSRg16 ast::type::ImageFormat::eRg16f, RWImg2DMS
#define RWFImg2DMSArrayRg16 ast::type::ImageFormat::eRg16f, RWImg2DMSArray
#define RWFImg1DRg32 ast::type::ImageFormat::eRg32f, RWImg1D
#define RWFImg2DRg32 ast::type::ImageFormat::eRg32f, RWImg2D
#define RWFImg3DRg32 ast::type::ImageFormat::eRg32f, RWImg3D
#define RWFImgCubeRg32 ast::type::ImageFormat::eRg32f, RWImgCube
#define RWFImgBufferRg32 ast::type::ImageFormat::eRg32f, RWImgBuffer
#define RWFImg1DArrayRg32 ast::type::ImageFormat::eRg32f, RWImg1DArray
#define RWFImg2DArrayRg32 ast::type::ImageFormat::eRg32f, RWImg2DArray
#define RWFImgCubeArrayRg32 ast::type::ImageFormat::eRg32f, RWImgCubeArray
#define RWFImg2DMSRg32 ast::type::ImageFormat::eRg32f, RWImg2DMS
#define RWFImg2DMSArrayRg32 ast::type::ImageFormat::eRg32f, RWImg2DMSArray
#define RWFImg1DRg16Snorm ast::type::ImageFormat::eRg16Snorm, RWImg1D
#define RWFImg2DRg16Snorm ast::type::ImageFormat::eRg16Snorm, RWImg2D
#define RWFImg3DRg16Snorm ast::type::ImageFormat::eRg16Snorm, RWImg3D
#define RWFImgCubeRg16Snorm ast::type::ImageFormat::eRg16Snorm, RWImgCube
#define RWFImgBufferRg16Snorm ast::type::ImageFormat::eRg16Snorm, RWImgBuffer
#define RWFImg1DArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, RWImg1DArray
#define RWFImg2DArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, RWImg2DArray
#define RWFImgCubeArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, RWImgCubeArray
#define RWFImg2DMSRg16Snorm ast::type::ImageFormat::eRg16Snorm, RWImg2DMS
#define RWFImg2DMSArrayRg16Snorm ast::type::ImageFormat::eRg16Snorm, RWImg2DMSArray
#define RWFImg1DRg8Snorm ast::type::ImageFormat::eRg8Snorm, RWImg1D
#define RWFImg2DRg8Snorm ast::type::ImageFormat::eRg8Snorm, RWImg2D
#define RWFImg3DRg8Snorm ast::type::ImageFormat::eRg8Snorm, RWImg3D
#define RWFImgCubeRg8Snorm ast::type::ImageFormat::eRg8Snorm, RWImgCube
#define RWFImgBufferRg8Snorm ast::type::ImageFormat::eRg8Snorm, RWImgBuffer
#define RWFImg1DArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, RWImg1DArray
#define RWFImg2DArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, RWImg2DArray
#define RWFImgCubeArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, RWImgCubeArray
#define RWFImg2DMSRg8Snorm ast::type::ImageFormat::eRg8Snorm, RWImg2DMS
#define RWFImg2DMSArrayRg8Snorm ast::type::ImageFormat::eRg8Snorm, RWImg2DMSArray
#define RWFImg1DRg16Unorm ast::type::ImageFormat::eRg16Unorm, RWImg1D
#define RWFImg2DRg16Unorm ast::type::ImageFormat::eRg16Unorm, RWImg2D
#define RWFImg3DRg16Unorm ast::type::ImageFormat::eRg16Unorm, RWImg3D
#define RWFImgCubeRg16Unorm ast::type::ImageFormat::eRg16Unorm, RWImgCube
#define RWFImgBufferRg16Unorm ast::type::ImageFormat::eRg16Unorm, RWImgBuffer
#define RWFImg1DArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, RWImg1DArray
#define RWFImg2DArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, RWImg2DArray
#define RWFImgCubeArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, RWImgCubeArray
#define RWFImg2DMSRg16Unorm ast::type::ImageFormat::eRg16Unorm, RWImg2DMS
#define RWFImg2DMSArrayRg16Unorm ast::type::ImageFormat::eRg16Unorm, RWImg2DMSArray
#define RWFImg1DRg8Unorm ast::type::ImageFormat::eRg8Unorm, RWImg1D
#define RWFImg2DRg8Unorm ast::type::ImageFormat::eRg8Unorm, RWImg2D
#define RWFImg3DRg8Unorm ast::type::ImageFormat::eRg8Unorm, RWImg3D
#define RWFImgCubeRg8Unorm ast::type::ImageFormat::eRg8Unorm, RWImgCube
#define RWFImgBufferRg8Unorm ast::type::ImageFormat::eRg8Unorm, RWImgBuffer
#define RWFImg1DArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, RWImg1DArray
#define RWFImg2DArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, RWImg2DArray
#define RWFImgCubeArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, RWImgCubeArray
#define RWFImg2DMSRg8Unorm ast::type::ImageFormat::eRg8Unorm, RWImg2DMS
#define RWFImg2DMSArrayRg8Unorm ast::type::ImageFormat::eRg8Unorm, RWImg2DMSArray

#define RWIImg1DRg8 ast::type::ImageFormat::eRg8i, RWImg1D
#define RWIImg2DRg8 ast::type::ImageFormat::eRg8i, RWImg2D
#define RWIImg3DRg8 ast::type::ImageFormat::eRg8i, RWImg3D
#define RWIImgCubeRg8 ast::type::ImageFormat::eRg8i, RWImgCube
#define RWIImgBufferRg8 ast::type::ImageFormat::eRg8i, RWImgBuffer
#define RWIImg1DArrayRg8 ast::type::ImageFormat::eRg8i, RWImg1DArray
#define RWIImg2DArrayRg8 ast::type::ImageFormat::eRg8i, RWImg2DArray
#define RWIImgCubeArrayRg8 ast::type::ImageFormat::eRg8i, RWImgCubeArray
#define RWIImg2DMSRg8 ast::type::ImageFormat::eRg8i, RWImg2DMS
#define RWIImg2DMSArrayRg8 ast::type::ImageFormat::eRg8i, RWImg2DMSArray
#define RWIImg1DRg16 ast::type::ImageFormat::eRg16i, RWImg1D
#define RWIImg2DRg16 ast::type::ImageFormat::eRg16i, RWImg2D
#define RWIImg3DRg16 ast::type::ImageFormat::eRg16i, RWImg3D
#define RWIImgCubeRg16 ast::type::ImageFormat::eRg16i, RWImgCube
#define RWIImgBufferRg16 ast::type::ImageFormat::eRg16i, RWImgBuffer
#define RWIImg1DArrayRg16 ast::type::ImageFormat::eRg16i, RWImg1DArray
#define RWIImg2DArrayRg16 ast::type::ImageFormat::eRg16i, RWImg2DArray
#define RWIImgCubeArrayRg16 ast::type::ImageFormat::eRg16i, RWImgCubeArray
#define RWIImg2DMSRg16 ast::type::ImageFormat::eRg16i, RWImg2DMS
#define RWIImg2DMSArrayRg16 ast::type::ImageFormat::eRg16i, RWImg2DMSArray
#define RWIImg1DRg32 ast::type::ImageFormat::eRg32i, RWImg1D
#define RWIImg2DRg32 ast::type::ImageFormat::eRg32i, RWImg2D
#define RWIImg3DRg32 ast::type::ImageFormat::eRg32i, RWImg3D
#define RWIImgCubeRg32 ast::type::ImageFormat::eRg32i, RWImgCube
#define RWIImgBufferRg32 ast::type::ImageFormat::eRg32i, RWImgBuffer
#define RWIImg1DArrayRg32 ast::type::ImageFormat::eRg32i, RWImg1DArray
#define RWIImg2DArrayRg32 ast::type::ImageFormat::eRg32i, RWImg2DArray
#define RWIImgCubeArrayRg32 ast::type::ImageFormat::eRg32i, RWImgCubeArray
#define RWIImg2DMSRg32 ast::type::ImageFormat::eRg32i, RWImg2DMS
#define RWIImg2DMSArrayRg32 ast::type::ImageFormat::eRg32i, RWImg2DMSArray

#define RWUImg1DRg8 ast::type::ImageFormat::eRg8u, RWImg1D
#define RWUImg2DRg8 ast::type::ImageFormat::eRg8u, RWImg2D
#define RWUImg3DRg8 ast::type::ImageFormat::eRg8u, RWImg3D
#define RWUImgCubeRg8 ast::type::ImageFormat::eRg8u, RWImgCube
#define RWUImgBufferRg8 ast::type::ImageFormat::eRg8u, RWImgBuffer
#define RWUImg1DArrayRg8 ast::type::ImageFormat::eRg8u, RWImg1DArray
#define RWUImg2DArrayRg8 ast::type::ImageFormat::eRg8u, RWImg2DArray
#define RWUImgCubeArrayRg8 ast::type::ImageFormat::eRg8u, RWImgCubeArray
#define RWUImg2DMSRg8 ast::type::ImageFormat::eRg8u, RWImg2DMS
#define RWUImg2DMSArrayRg8 ast::type::ImageFormat::eRg8u, RWImg2DMSArray
#define RWUImg1DRg16 ast::type::ImageFormat::eRg16u, RWImg1D
#define RWUImg2DRg16 ast::type::ImageFormat::eRg16u, RWImg2D
#define RWUImg3DRg16 ast::type::ImageFormat::eRg16u, RWImg3D
#define RWUImgCubeRg16 ast::type::ImageFormat::eRg16u, RWImgCube
#define RWUImgBufferRg16 ast::type::ImageFormat::eRg16u, RWImgBuffer
#define RWUImg1DArrayRg16 ast::type::ImageFormat::eRg16u, RWImg1DArray
#define RWUImg2DArrayRg16 ast::type::ImageFormat::eRg16u, RWImg2DArray
#define RWUImgCubeArrayRg16 ast::type::ImageFormat::eRg16u, RWImgCubeArray
#define RWUImg2DMSRg16 ast::type::ImageFormat::eRg16u, RWImg2DMS
#define RWUImg2DMSArrayRg16 ast::type::ImageFormat::eRg16u, RWImg2DMSArray
#define RWUImg1DRg32 ast::type::ImageFormat::eRg32u, RWImg1D
#define RWUImg2DRg32 ast::type::ImageFormat::eRg32u, RWImg2D
#define RWUImg3DRg32 ast::type::ImageFormat::eRg32u, RWImg3D
#define RWUImgCubeRg32 ast::type::ImageFormat::eRg32u, RWImgCube
#define RWUImgBufferRg32 ast::type::ImageFormat::eRg32u, RWImgBuffer
#define RWUImg1DArrayRg32 ast::type::ImageFormat::eRg32u, RWImg1DArray
#define RWUImg2DArrayRg32 ast::type::ImageFormat::eRg32u, RWImg2DArray
#define RWUImgCubeArrayRg32 ast::type::ImageFormat::eRg32u, RWImgCubeArray
#define RWUImg2DMSRg32 ast::type::ImageFormat::eRg32u, RWImg2DMS
#define RWUImg2DMSArrayRg32 ast::type::ImageFormat::eRg32u, RWImg2DMSArray

#define RWFImg1DR16 ast::type::ImageFormat::eR16f, RWImg1D
#define RWFImg2DR16 ast::type::ImageFormat::eR16f, RWImg2D
#define RWFImg3DR16 ast::type::ImageFormat::eR16f, RWImg3D
#define RWFImgCubeR16 ast::type::ImageFormat::eR16f, RWImgCube
#define RWFImgBufferR16 ast::type::ImageFormat::eR16f, RWImgBuffer
#define RWFImg1DArrayR16 ast::type::ImageFormat::eR16f, RWImg1DArray
#define RWFImg2DArrayR16 ast::type::ImageFormat::eR16f, RWImg2DArray
#define RWFImgCubeArrayR16 ast::type::ImageFormat::eR16f, RWImgCubeArray
#define RWFImg2DMSR16 ast::type::ImageFormat::eR16f, RWImg2DMS
#define RWFImg2DMSArrayR16 ast::type::ImageFormat::eR16f, RWImg2DMSArray
#define RWFImg1DR32 ast::type::ImageFormat::eR32f, RWImg1D
#define RWFImg2DR32 ast::type::ImageFormat::eR32f, RWImg2D
#define RWFImg3DR32 ast::type::ImageFormat::eR32f, RWImg3D
#define RWFImgCubeR32 ast::type::ImageFormat::eR32f, RWImgCube
#define RWFImgBufferR32 ast::type::ImageFormat::eR32f, RWImgBuffer
#define RWFImg1DArrayR32 ast::type::ImageFormat::eR32f, RWImg1DArray
#define RWFImg2DArrayR32 ast::type::ImageFormat::eR32f, RWImg2DArray
#define RWFImgCubeArrayR32 ast::type::ImageFormat::eR32f, RWImgCubeArray
#define RWFImg2DMSR32 ast::type::ImageFormat::eR32f, RWImg2DMS
#define RWFImg2DMSArrayR32 ast::type::ImageFormat::eR32f, RWImg2DMSArray
#define RWFImg1DR16Snorm ast::type::ImageFormat::eR16Snorm, RWImg1D
#define RWFImg2DR16Snorm ast::type::ImageFormat::eR16Snorm, RWImg2D
#define RWFImg3DR16Snorm ast::type::ImageFormat::eR16Snorm, RWImg3D
#define RWFImgCubeR16Snorm ast::type::ImageFormat::eR16Snorm, RWImgCube
#define RWFImgBufferR16Snorm ast::type::ImageFormat::eR16Snorm, RWImgBuffer
#define RWFImg1DArrayR16Snorm ast::type::ImageFormat::eR16Snorm, RWImg1DArray
#define RWFImg2DArrayR16Snorm ast::type::ImageFormat::eR16Snorm, RWImg2DArray
#define RWFImgCubeArrayR16Snorm ast::type::ImageFormat::eR16Snorm, RWImgCubeArray
#define RWFImg2DMSR16Snorm ast::type::ImageFormat::eR16Snorm, RWImg2DMS
#define RWFImg2DMSArrayR16Snorm ast::type::ImageFormat::eR16Snorm, RWImg2DMSArray
#define RWFImg1DR8Snorm ast::type::ImageFormat::eR8Snorm, RWImg1D
#define RWFImg2DR8Snorm ast::type::ImageFormat::eR8Snorm, RWImg2D
#define RWFImg3DR8Snorm ast::type::ImageFormat::eR8Snorm, RWImg3D
#define RWFImgCubeR8Snorm ast::type::ImageFormat::eR8Snorm, RWImgCube
#define RWFImgBufferR8Snorm ast::type::ImageFormat::eR8Snorm, RWImgBuffer
#define RWFImg1DArrayR8Snorm ast::type::ImageFormat::eR8Snorm, RWImg1DArray
#define RWFImg2DArrayR8Snorm ast::type::ImageFormat::eR8Snorm, RWImg2DArray
#define RWFImgCubeArrayR8Snorm ast::type::ImageFormat::eR8Snorm, RWImgCubeArray
#define RWFImg2DMSR8Snorm ast::type::ImageFormat::eR8Snorm, RWImg2DMS
#define RWFImg2DMSArrayR8Snorm ast::type::ImageFormat::eR8Snorm, RWImg2DMSArray
#define RWFImg1DR16Unorm ast::type::ImageFormat::eR16Unorm, RWImg1D
#define RWFImg2DR16Unorm ast::type::ImageFormat::eR16Unorm, RWImg2D
#define RWFImg3DR16Unorm ast::type::ImageFormat::eR16Unorm, RWImg3D
#define RWFImgCubeR16Unorm ast::type::ImageFormat::eR16Unorm, RWImgCube
#define RWFImgBufferR16Unorm ast::type::ImageFormat::eR16Unorm, RWImgBuffer
#define RWFImg1DArrayR16Unorm ast::type::ImageFormat::eR16Unorm, RWImg1DArray
#define RWFImg2DArrayR16Unorm ast::type::ImageFormat::eR16Unorm, RWImg2DArray
#define RWFImgCubeArrayR16Unorm ast::type::ImageFormat::eR16Unorm, RWImgCubeArray
#define RWFImg2DMSR16Unorm ast::type::ImageFormat::eR16Unorm, RWImg2DMS
#define RWFImg2DMSArrayR16Unorm ast::type::ImageFormat::eR16Unorm, RWImg2DMSArray
#define RWFImg1DR8Unorm ast::type::ImageFormat::eR8Unorm, RWImg1D
#define RWFImg2DR8Unorm ast::type::ImageFormat::eR8Unorm, RWImg2D
#define RWFImg3DR8Unorm ast::type::ImageFormat::eR8Unorm, RWImg3D
#define RWFImgCubeR8Unorm ast::type::ImageFormat::eR8Unorm, RWImgCube
#define RWFImgBufferR8Unorm ast::type::ImageFormat::eR8Unorm, RWImgBuffer
#define RWFImg1DArrayR8Unorm ast::type::ImageFormat::eR8Unorm, RWImg1DArray
#define RWFImg2DArrayR8Unorm ast::type::ImageFormat::eR8Unorm, RWImg2DArray
#define RWFImgCubeArrayR8Unorm ast::type::ImageFormat::eR8Unorm, RWImgCubeArray
#define RWFImg2DMSR8Unorm ast::type::ImageFormat::eR8Unorm, RWImg2DMS
#define RWFImg2DMSArrayR8Unorm ast::type::ImageFormat::eR8Unorm, RWImg2DMSArray

#define RWIImg1DR8 ast::type::ImageFormat::eR8i, RWImg1D
#define RWIImg2DR8 ast::type::ImageFormat::eR8i, RWImg2D
#define RWIImg3DR8 ast::type::ImageFormat::eR8i, RWImg3D
#define RWIImgCubeR8 ast::type::ImageFormat::eR8i, RWImgCube
#define RWIImgBufferR8 ast::type::ImageFormat::eR8i, RWImgBuffer
#define RWIImg1DArrayR8 ast::type::ImageFormat::eR8i, RWImg1DArray
#define RWIImg2DArrayR8 ast::type::ImageFormat::eR8i, RWImg2DArray
#define RWIImgCubeArrayR8 ast::type::ImageFormat::eR8i, RWImgCubeArray
#define RWIImg2DMSR8 ast::type::ImageFormat::eR8i, RWImg2DMS
#define RWIImg2DMSArrayR8 ast::type::ImageFormat::eR8i, RWImg2DMSArray
#define RWIImg1DR16 ast::type::ImageFormat::eR16i, RWImg1D
#define RWIImg2DR16 ast::type::ImageFormat::eR16i, RWImg2D
#define RWIImg3DR16 ast::type::ImageFormat::eR16i, RWImg3D
#define RWIImgCubeR16 ast::type::ImageFormat::eR16i, RWImgCube
#define RWIImgBufferR16 ast::type::ImageFormat::eR16i, RWImgBuffer
#define RWIImg1DArrayR16 ast::type::ImageFormat::eR16i, RWImg1DArray
#define RWIImg2DArrayR16 ast::type::ImageFormat::eR16i, RWImg2DArray
#define RWIImgCubeArrayR16 ast::type::ImageFormat::eR16i, RWImgCubeArray
#define RWIImg2DMSR16 ast::type::ImageFormat::eR16i, RWImg2DMS
#define RWIImg2DMSArrayR16 ast::type::ImageFormat::eR16i, RWImg2DMSArray
#define RWIImg1DR32 ast::type::ImageFormat::eR32i, RWImg1D
#define RWIImg2DR32 ast::type::ImageFormat::eR32i, RWImg2D
#define RWIImg3DR32 ast::type::ImageFormat::eR32i, RWImg3D
#define RWIImgCubeR32 ast::type::ImageFormat::eR32i, RWImgCube
#define RWIImgBufferR32 ast::type::ImageFormat::eR32i, RWImgBuffer
#define RWIImg1DArrayR32 ast::type::ImageFormat::eR32i, RWImg1DArray
#define RWIImg2DArrayR32 ast::type::ImageFormat::eR32i, RWImg2DArray
#define RWIImgCubeArrayR32 ast::type::ImageFormat::eR32i, RWImgCubeArray
#define RWIImg2DMSR32 ast::type::ImageFormat::eR32i, RWImg2DMS
#define RWIImg2DMSArrayR32 ast::type::ImageFormat::eR32i, RWImg2DMSArray

#define RWUImg1DR8 ast::type::ImageFormat::eR8u, RWImg1D
#define RWUImg2DR8 ast::type::ImageFormat::eR8u, RWImg2D
#define RWUImg3DR8 ast::type::ImageFormat::eR8u, RWImg3D
#define RWUImgCubeR8 ast::type::ImageFormat::eR8u, RWImgCube
#define RWUImgBufferR8 ast::type::ImageFormat::eR8u, RWImgBuffer
#define RWUImg1DArrayR8 ast::type::ImageFormat::eR8u, RWImg1DArray
#define RWUImg2DArrayR8 ast::type::ImageFormat::eR8u, RWImg2DArray
#define RWUImgCubeArrayR8 ast::type::ImageFormat::eR8u, RWImgCubeArray
#define RWUImg2DMSR8 ast::type::ImageFormat::eR8u, RWImg2DMS
#define RWUImg2DMSArrayR8 ast::type::ImageFormat::eR8u, RWImg2DMSArray
#define RWUImg1DR16 ast::type::ImageFormat::eR16u, RWImg1D
#define RWUImg2DR16 ast::type::ImageFormat::eR16u, RWImg2D
#define RWUImg3DR16 ast::type::ImageFormat::eR16u, RWImg3D
#define RWUImgCubeR16 ast::type::ImageFormat::eR16u, RWImgCube
#define RWUImgBufferR16 ast::type::ImageFormat::eR16u, RWImgBuffer
#define RWUImg1DArrayR16 ast::type::ImageFormat::eR16u, RWImg1DArray
#define RWUImg2DArrayR16 ast::type::ImageFormat::eR16u, RWImg2DArray
#define RWUImgCubeArrayR16 ast::type::ImageFormat::eR16u, RWImgCubeArray
#define RWUImg2DMSR16 ast::type::ImageFormat::eR16u, RWImg2DMS
#define RWUImg2DMSArrayR16 ast::type::ImageFormat::eR16u, RWImg2DMSArray
#define RWUImg1DR32 ast::type::ImageFormat::eR32u, RWImg1D
#define RWUImg2DR32 ast::type::ImageFormat::eR32u, RWImg2D
#define RWUImg3DR32 ast::type::ImageFormat::eR32u, RWImg3D
#define RWUImgCubeR32 ast::type::ImageFormat::eR32u, RWImgCube
#define RWUImgBufferR32 ast::type::ImageFormat::eR32u, RWImgBuffer
#define RWUImg1DArrayR32 ast::type::ImageFormat::eR32u, RWImg1DArray
#define RWUImg2DArrayR32 ast::type::ImageFormat::eR32u, RWImg2DArray
#define RWUImgCubeArrayR32 ast::type::ImageFormat::eR32u, RWImgCubeArray
#define RWUImg2DMSR32 ast::type::ImageFormat::eR32u, RWImg2DMS
#define RWUImg2DMSArrayR32 ast::type::ImageFormat::eR32u, RWImg2DMSArray

#include "ImageConfiguration.inl"

#endif
