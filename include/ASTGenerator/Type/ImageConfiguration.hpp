/*
See LICENSE file in root folder
*/
#ifndef ___AST_ImageConfiguration_H___
#define ___AST_ImageConfiguration_H___
#pragma once

#include "Type.hpp"

namespace ast::type
{
	enum class Ternary
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
	struct IsFloatFormatT
		: std::false_type
	{
	};

	template< ImageFormat FormatT >
	struct IsSIntFormatT
		: std::false_type
	{
	};

	template< ImageFormat FormatT >
	struct IsUIntFormatT
		: std::false_type
	{
	};

	template<>
	struct IsFloatFormatT< ImageFormat::eRgba32f >
		: std::true_type
	{
	};

	template<>
	struct IsFloatFormatT< ImageFormat::eRgba16f >
		: std::true_type
	{
	};

	template<>
	struct IsFloatFormatT< ImageFormat::eRg32f >
		: std::true_type
	{
	};

	template<>
	struct IsFloatFormatT< ImageFormat::eRg16f >
		: std::true_type
	{
	};

	template<>
	struct IsFloatFormatT< ImageFormat::eR32f >
		: std::true_type
	{
	};

	template<>
	struct IsFloatFormatT< ImageFormat::eR16f >
		: std::true_type
	{
	};

	template<>
	struct IsSIntFormatT< ImageFormat::eRgba32i >
		: std::true_type
	{
	};

	template<>
	struct IsSIntFormatT< ImageFormat::eRgba16i >
		: std::true_type
	{
	};

	template<>
	struct IsSIntFormatT< ImageFormat::eRgba8i >
		: std::true_type
	{
	};

	template<>
	struct IsSIntFormatT< ImageFormat::eRg32i >
		: std::true_type
	{
	};

	template<>
	struct IsSIntFormatT< ImageFormat::eRg16i >
		: std::true_type
	{
	};

	template<>
	struct IsSIntFormatT< ImageFormat::eRg8i >
		: std::true_type
	{
	};

	template<>
	struct IsSIntFormatT< ImageFormat::eR32i >
		: std::true_type
	{
	};

	template<>
	struct IsSIntFormatT< ImageFormat::eR16i >
		: std::true_type
	{
	};

	template<>
	struct IsSIntFormatT< ImageFormat::eR8i >
		: std::true_type
	{
	};

	template<>
	struct IsUIntFormatT< ImageFormat::eRgba32u >
		: std::true_type
	{
	};

	template<>
	struct IsUIntFormatT< ImageFormat::eRgba16u >
		: std::true_type
	{
	};

	template<>
	struct IsUIntFormatT< ImageFormat::eRgba8u >
		: std::true_type
	{
	};

	template<>
	struct IsUIntFormatT< ImageFormat::eRg32u >
		: std::true_type
	{
	};

	template<>
	struct IsUIntFormatT< ImageFormat::eRg16u >
		: std::true_type
	{
	};

	template<>
	struct IsUIntFormatT< ImageFormat::eRg8u >
		: std::true_type
	{
	};

	template<>
	struct IsUIntFormatT< ImageFormat::eR32u >
		: std::true_type
	{
	};

	template<>
	struct IsUIntFormatT< ImageFormat::eR16u >
		: std::true_type
	{
	};

	template<>
	struct IsUIntFormatT< ImageFormat::eR8u >
		: std::true_type
	{
	};

	template< ImageFormat FormatT >
	static bool constexpr IsFloatFormat = IsFloatFormatT< FormatT >::value;
	template< ImageFormat FormatT >
	static bool constexpr IsSIntFormat = IsSIntFormatT< FormatT >::value;
	template< ImageFormat FormatT >
	static bool constexpr IsUIntFormat = IsUIntFormatT< FormatT >::value;

	struct ImageConfiguration
	{
		ImageDim dimension;
		ImageFormat format;
		Ternary isDepth;
		Ternary isSampled;
		bool isArrayed;
		bool isMS;
		AccessKind accessKind;
		uint32_t componentCount;
		Kind componentType;
	};
}

#define Img1DRGBA32F ast::type::ImageDim::e1D, ast::type::ImageFormat::eRgba32f, false, false, false
#define Img1DRGBA8I ast::type::ImageDim::e1D, ast::type::ImageFormat::eRgba8i, false, false, false
#define Img1DRGBA8U ast::type::ImageDim::e1D, ast::type::ImageFormat::eRgba8u, false, false, false
#define Img2DRGBA32F ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, false, false, false
#define Img2DRGBA8I ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba8i, false, false, false
#define Img2DRGBA8U ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba8u, false, false, false
#define Img3DRGBA32F ast::type::ImageDim::e3D, ast::type::ImageFormat::eRgba32f, false, false, false
#define Img3DRGBA8I ast::type::ImageDim::e3D, ast::type::ImageFormat::eRgba8i, false, false, false
#define Img3DRGBA8U ast::type::ImageDim::e3D, ast::type::ImageFormat::eRgba8u, false, false, false
#define ImgRectRGBA32F ast::type::ImageDim::eRect, ast::type::ImageFormat::eRgba32f, false, false, false
#define ImgRectRGBA8I ast::type::ImageDim::eRect, ast::type::ImageFormat::eRgba8i, false, false, false
#define ImgRectRGBA8U ast::type::ImageDim::eRect, ast::type::ImageFormat::eRgba8u, false, false, false
#define ImgCubeRGBA32F ast::type::ImageDim::eCube, ast::type::ImageFormat::eRgba32f, false, false, false
#define ImgCubeRGBA8I ast::type::ImageDim::eCube, ast::type::ImageFormat::eRgba8i, false, false, false
#define ImgCubeRGBA8U ast::type::ImageDim::eCube, ast::type::ImageFormat::eRgba8u, false, false, false
#define ImgBufferRGBA32F ast::type::ImageDim::eBuffer, ast::type::ImageFormat::eRgba32f, false, false, false
#define ImgBufferRGBA8I ast::type::ImageDim::eBuffer, ast::type::ImageFormat::eRgba8i, false, false, false
#define ImgBufferRGBA8U ast::type::ImageDim::eBuffer, ast::type::ImageFormat::eRgba8u, false, false, false

#define Img1DArrayRGBA32F ast::type::ImageDim::e1D, ast::type::ImageFormat::eRgba32f, true, false, false
#define Img1DArrayRGBA8I ast::type::ImageDim::e1D, ast::type::ImageFormat::eRgba8i, true, false, false
#define Img1DArrayRGBA8U ast::type::ImageDim::e1D, ast::type::ImageFormat::eRgba8u, true, false, false
#define Img2DArrayRGBA32F ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, true, false, false
#define Img2DArrayRGBA8I ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba8i, true, false, false
#define Img2DArrayRGBA8U ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba8u, true, false, false
#define ImgRectArrayRGBA32F ast::type::ImageDim::eRect, ast::type::ImageFormat::eRgba32f, true, false, false
#define ImgRectArrayRGBA8I ast::type::ImageDim::eRect, ast::type::ImageFormat::eRgba8i, true, false, false
#define ImgRectArrayRGBA8U ast::type::ImageDim::eRect, ast::type::ImageFormat::eRgba8u, true, false, false
#define ImgCubeArrayRGBA32F ast::type::ImageDim::eCube, ast::type::ImageFormat::eRgba32f, true, false, false
#define ImgCubeArrayRGBA8I ast::type::ImageDim::eCube, ast::type::ImageFormat::eRgba8i, true, false, false
#define ImgCubeArrayRGBA8U ast::type::ImageDim::eCube, ast::type::ImageFormat::eRgba8u, true, false, false

#define Img1DShadowRGBA32F ast::type::ImageDim::e1D, ast::type::ImageFormat::eRgba32f, false, true, false
#define Img2DShadowRGBA32F ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, false, true, false
#define ImgRectShadowRGBA32F ast::type::ImageDim::eRect, ast::type::ImageFormat::eRgba32f, false, true, false
#define ImgCubeShadowRGBA32F ast::type::ImageDim::eCube, ast::type::ImageFormat::eRgba32f, false, true, false

#define Img1DArrayShadowRGBA32F ast::type::ImageDim::e1D, ast::type::ImageFormat::eRgba32f, true, true, false
#define Img2DArrayShadowRGBA32F ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, true, true, false
#define ImgRectArrayShadowF ast::type::ImageDim::eRect, ast::type::ImageFormat::eRgba32f, true, true, false
#define ImgCubeArrayShadowRGBA32F ast::type::ImageDim::eCube, ast::type::ImageFormat::eRgba32f, true, true, false

#define Img2DMSRGBA32F ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, false, false, true
#define Img2DMSRGBA8I ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba8i, false, false, true
#define Img2DMSRGBA8U ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba8u, false, false, true

#define Img2DMSArrayRGBA32F ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, true, false, true
#define Img2DMSArrayRGBA8I ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba8i, true, false, true
#define Img2DMSArrayRGBA8U ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba8u, true, false, true

#endif
