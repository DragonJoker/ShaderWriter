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

	inline bool isFloatFormat( ImageFormat format )
	{
		return format == ImageFormat::eUnknown
			|| format == ImageFormat::eRgba32f
			|| format == ImageFormat::eRgba16f
			|| format == ImageFormat::eRg32f
			|| format == ImageFormat::eRg16f
			|| format == ImageFormat::eR32f
			|| format == ImageFormat::eR16f;
	}

	inline bool isSIntFormat( ImageFormat format )
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

	inline bool isUIntFormat( ImageFormat format )
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
			, AccessKind accessKind = AccessKind::eRead )
			: sampledType{ sampledType }
			, dimension{ dimension }
			, format{ format }
			, isDepth{ isDepth }
			, isSampled{ isSampled }
			, isArrayed{ isArrayed }
			, isMS{ isMS }
			, accessKind{ accessKind }
		{
			assert( ( this->sampledType == type::Kind::eFloat && isFloatFormat( format ) )
				|| ( this->sampledType == type::Kind::eInt && isSIntFormat( format ) )
				|| ( this->sampledType == type::Kind::eUInt && isUIntFormat( format ) ) );
		}

		type::Kind sampledType;
		ImageDim dimension;
		ImageFormat format;
		Trinary isDepth;
		Trinary isSampled;
		bool isArrayed;
		bool isMS;
		AccessKind accessKind;
	};

	template< Kind SampledT
		, ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline ImageConfiguration makeConfig( ImageFormat format
		, bool sampled
		, bool readOnly )
	{
		return ImageConfiguration
		{
			SampledT,
			DimT,
			format,
			DepthT ? Trinary::eTrue : Trinary::eFalse,
			sampled ? Trinary::eTrue : Trinary::eFalse,
			ArrayedT,
			MsT,
			readOnly ? AccessKind::eRead : AccessKind::eReadWrite
		};
	}
}

#define FImg1D ast::type::Kind::eFloat, ast::type::ImageDim::e1D, false, false, false
#define FImg2D ast::type::Kind::eFloat, ast::type::ImageDim::e2D, false, false, false
#define FImg3D ast::type::Kind::eFloat, ast::type::ImageDim::e3D, false, false, false
#define FImgRect ast::type::Kind::eFloat, ast::type::ImageDim::eRect, false, false, false
#define FImgCube ast::type::Kind::eFloat, ast::type::ImageDim::eCube, false, false, false
#define FImgBuffer ast::type::Kind::eFloat, ast::type::ImageDim::eBuffer, false, false, false
#define FImg1DArray ast::type::Kind::eFloat, ast::type::ImageDim::e1D, true, false, false
#define FImg2DArray ast::type::Kind::eFloat, ast::type::ImageDim::e2D, true, false, false
#define FImgCubeArray ast::type::Kind::eFloat, ast::type::ImageDim::eCube, true, false, false
#define FImg1DShadow ast::type::Kind::eFloat, ast::type::ImageDim::e1D, false, true, false
#define FImg2DShadow ast::type::Kind::eFloat, ast::type::ImageDim::e2D, false, true, false
#define FImgRectShadow ast::type::Kind::eFloat, ast::type::ImageDim::eRect, false, true, false
#define FImgCubeShadow ast::type::Kind::eFloat, ast::type::ImageDim::eCube, false, true, false
#define FImg1DArrayShadow ast::type::Kind::eFloat, ast::type::ImageDim::e1D, true, true, false
#define FImg2DArrayShadow ast::type::Kind::eFloat, ast::type::ImageDim::e2D, true, true, false
#define FImgCubeArrayShadow ast::type::Kind::eFloat, ast::type::ImageDim::eCube, true, true, false
#define FImg2DMS ast::type::Kind::eFloat, ast::type::ImageDim::e2D, false, false, true
#define FImg2DMSArray ast::type::Kind::eFloat, ast::type::ImageDim::e2D, true, false, true

#define IImg1D ast::type::Kind::eInt, ast::type::ImageDim::e1D, false, false, false
#define IImg2D ast::type::Kind::eInt, ast::type::ImageDim::e2D, false, false, false
#define IImg3D ast::type::Kind::eInt, ast::type::ImageDim::e3D, false, false, false
#define IImgRect ast::type::Kind::eInt, ast::type::ImageDim::eRect, false, false, false
#define IImgCube ast::type::Kind::eInt, ast::type::ImageDim::eCube, false, false, false
#define IImgBuffer ast::type::Kind::eInt, ast::type::ImageDim::eBuffer, false, false, false
#define IImg1DArray ast::type::Kind::eInt, ast::type::ImageDim::e1D, true, false, false
#define IImg2DArray ast::type::Kind::eInt, ast::type::ImageDim::e2D, true, false, false
#define IImgCubeArray ast::type::Kind::eInt, ast::type::ImageDim::eCube, true, false, false
#define IImg2DMS ast::type::Kind::eInt, ast::type::ImageDim::e2D, false, false, true
#define IImg2DMSArray ast::type::Kind::eInt, ast::type::ImageDim::e2D, true, false, true

#define UImg1D ast::type::Kind::eUInt, ast::type::ImageDim::e1D, false, false, false
#define UImg2D ast::type::Kind::eUInt, ast::type::ImageDim::e2D, false, false, false
#define UImg3D ast::type::Kind::eUInt, ast::type::ImageDim::e3D, false, false, false
#define UImgRect ast::type::Kind::eUInt, ast::type::ImageDim::eRect, false, false, false
#define UImgCube ast::type::Kind::eUInt, ast::type::ImageDim::eCube, false, false, false
#define UImgBuffer ast::type::Kind::eUInt, ast::type::ImageDim::eBuffer, false, false, false
#define UImg1DArray ast::type::Kind::eUInt, ast::type::ImageDim::e1D, true, false, false
#define UImg2DArray ast::type::Kind::eUInt, ast::type::ImageDim::e2D, true, false, false
#define UImgCubeArray ast::type::Kind::eUInt, ast::type::ImageDim::eCube, true, false, false
#define UImg2DMS ast::type::Kind::eUInt, ast::type::ImageDim::e2D, false, false, true
#define UImg2DMSArray ast::type::Kind::eUInt, ast::type::ImageDim::e2D, true, false, true

#endif
