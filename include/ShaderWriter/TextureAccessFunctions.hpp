
/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GetTextureAccessFunctions_H___
#define ___SDW_GetTextureAccessFunctions_H___
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

#include <ASTGenerator/Expr/MakeTextureAccess.hpp>

namespace sdw
{
#pragma region textureSize
	/**
	*name
	*	textureSize
	*/
	/**@{*/
	inline Int textureSize( SampledImage1D const & image
		, Int const & lod )
	{
		return Int{ findShader( image, lod )
			, expr::makeTextureSize1DF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( SampledImage2D const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSize2DF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec3 textureSize( SampledImage3D const & image
		, Int const & lod )
	{
		return IVec3{ findShader( image, lod )
			, expr::makeTextureSize3DF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( SampledImageCube const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSizeCubeF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline Int textureSize( SampledImage1DShadow const & image
		, Int const & lod )
	{
		return Int{ findShader( image, lod )
			, expr::makeTextureSize1DShadowF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( SampledImage2DShadow const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSize2DShadowF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( SampledImageCubeShadow const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSizeCubeShadowF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec3 textureSize( SampledImageCubeArray const & image
		, Int const & lod )
	{
		return IVec3{ findShader( image, lod )
			, expr::makeTextureSizeCubeArrayF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec3 textureSize( SampledImageCubeArrayShadow const & image
		, Int const & lod )
	{
		return IVec3{ findShader( image, lod )
			, expr::makeTextureSizeCubeArrayShadowF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( SampledImage1DArray const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSize1DArrayF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec3 textureSize( SampledImage2DArray const & image
		, Int const & lod )
	{
		return IVec3{ findShader( image, lod )
			, expr::makeTextureSize2DArrayF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( SampledImage1DArrayShadow const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSize1DArrayShadowF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec3 textureSize( SampledImage2DArrayShadow const & image
		, Int const & lod )
	{
		return IVec3{ findShader( image, lod )
			, expr::makeTextureSize2DArrayShadowF( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline Int textureSize( ISampledImage1D const & image
		, Int const & lod )
	{
		return Int{ findShader( image, lod )
			, expr::makeTextureSize1DI( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( ISampledImage2D const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSize2DI( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec3 textureSize( ISampledImage3D const & image
		, Int const & lod )
	{
		return IVec3{ findShader( image, lod )
			, expr::makeTextureSize3DI( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( ISampledImageCube const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSizeCubeI( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec3 textureSize( ISampledImageCubeArray const & image
		, Int const & lod )
	{
		return IVec3{ findShader( image, lod )
			, expr::makeTextureSizeCubeArrayI( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( ISampledImage1DArray const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSize1DArrayI( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec3 textureSize( ISampledImage2DArray const & image
		, Int const & lod )
	{
		return IVec3{ findShader( image, lod )
			, expr::makeTextureSize2DArrayI( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline Int textureSize( USampledImage1D const & image
		, Int const & lod )
	{
		return Int{ findShader( image, lod )
			, expr::makeTextureSize1DU( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( USampledImage2D const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSize2DU( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec3 textureSize( USampledImage3D const & image
		, Int const & lod )
	{
		return IVec3{ findShader( image, lod )
			, expr::makeTextureSize3DU( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( USampledImageCube const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSizeCubeU( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec3 textureSize( USampledImageCubeArray const & image
		, Int const & lod )
	{
		return IVec3{ findShader( image, lod )
			, expr::makeTextureSizeCubeArrayU( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( USampledImage1DArray const & image
		, Int const & lod )
	{
		return IVec2{ findShader( image, lod )
			, expr::makeTextureSize1DArrayU( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec3 textureSize( USampledImage2DArray const & image
		, Int const & lod )
	{
		return IVec3{ findShader( image, lod )
			, expr::makeTextureSize2DArrayU( makeExpr( image )
				, makeExpr( lod ) ) };
	}
	inline IVec2 textureSize( SampledImage2DRect const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeTextureSize2DRectF( makeExpr( image ) ) };
	}
	inline IVec2 textureSize( SampledImage2DRectShadow const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeTextureSize2DRectShadowF( makeExpr( image ) ) };
	}
	inline Int textureSize( SampledImageBuffer const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureSizeBufferF( makeExpr( image ) ) };
	}
	inline IVec2 textureSize( ISampledImage2DRect const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeTextureSize2DRectI( makeExpr( image ) ) };
	}
	inline Int textureSize( ISampledImageBuffer const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureSizeBufferI( makeExpr( image ) ) };
	}
	inline IVec2 textureSize( USampledImage2DRect const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeTextureSize2DRectU( makeExpr( image ) ) };
	}
	inline Int textureSize( USampledImageBuffer const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureSizeBufferU( makeExpr( image ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureQueryLod
	/**
	*name
	*	textureQueryLod
	*/
	/**@{*/
	inline Vec2 textureQueryLod( SampledImage1D const & image
		, Float const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod1DF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImage2D const & image
		, Vec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod2DF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImage3D const & image
		, Vec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod3DF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImageCube const & image
		, Vec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLodCubeF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImage1DArray const & image
		, Float const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod1DArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImage2DArray const & image
		, Vec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod2DArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImageCubeArray const & image
		, Vec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLodCubeArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImage1DShadow const & image
		, Float const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod1DShadowF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImage2DShadow const & image
		, Vec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod2DShadowF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImageCubeShadow const & image
		, Vec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLodCubeShadowF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImage1DArrayShadow const & image
		, Float const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod1DArrayShadowF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImage2DArrayShadow const & image
		, Vec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod2DArrayShadowF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( SampledImageCubeArrayShadow const & image
		, Vec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLodCubeArrayShadowF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( ISampledImage1D const & image
		, Float const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod1DI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( ISampledImage2D const & image
		, Vec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod2DI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( ISampledImage3D const & image
		, Vec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod3DI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( ISampledImageCube const & image
		, Vec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLodCubeI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( ISampledImage1DArray const & image
		, Float const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod1DArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( ISampledImage2DArray const & image
		, Vec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod2DArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( ISampledImageCubeArray const & image
		, Vec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLodCubeArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( USampledImage1D const & image
		, Float const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod1DU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( USampledImage2D const & image
		, Vec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod2DU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( USampledImage3D const & image
		, Vec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod3DU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( USampledImageCube const & image
		, Vec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLodCubeU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( USampledImage1DArray const & image
		, Float const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod1DArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( USampledImage2DArray const & image
		, Vec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLod2DArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec2 textureQueryLod( USampledImageCubeArray const & image
		, Vec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeTextureQueryLodCubeArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureQueryLevels
	/**
	*name
	*	textureQueryLevels
	*/
	/**@{*/
	inline Int textureQueryLevels( SampledImage1D const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels1DF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImage2D const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels2DF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImage3D const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels3DF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImageCube const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevelsCubeF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImage1DArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels1DArrayF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImage2DArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels2DArrayF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImageCubeArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevelsCubeArrayF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImage1DShadow const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels1DShadowF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImage2DShadow const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels2DShadowF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImageCubeShadow const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevelsCubeShadowF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImage1DArrayShadow const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels1DArrayShadowF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImage2DArrayShadow const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels2DArrayShadowF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( SampledImageCubeArrayShadow const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevelsCubeArrayShadowF( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( ISampledImage1D const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels1DI( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( ISampledImage2D const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels2DI( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( ISampledImage3D const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels3DI( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( ISampledImageCube const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevelsCubeI( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( ISampledImage1DArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels1DArrayI( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( ISampledImage2DArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels2DArrayI( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( ISampledImageCubeArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevelsCubeArrayI( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( USampledImage1D const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels1DU( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( USampledImage2D const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels2DU( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( USampledImage3D const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels3DU( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( USampledImageCube const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevelsCubeU( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( USampledImage1DArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels1DArrayU( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( USampledImage2DArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevels2DArrayU( makeExpr( image ) ) };
	}
	inline Int textureQueryLevels( USampledImageCubeArray const & image )
	{
		return Int{ findShader( image )
			, expr::makeTextureQueryLevelsCubeArrayU( makeExpr( image ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region texture
	/**
	*name
	*	texture
	*/
	/**@{*/
	inline Vec4 texture( SampledImage1D const & image
		, Float const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexture1DF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texture( SampledImage2D const & image
		, Vec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexture2DF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texture( SampledImage3D const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexture3DF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texture( SampledImageCube const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureCubeF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texture( SampledImage1DArray const & image
		, Vec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexture1DArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texture( SampledImage2DArray const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexture2DArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texture( SampledImageCubeArray const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureCubeArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texture( SampledImage2DRect const & image
		, Vec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexture2DRectF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 texture( ISampledImage1D const & image
		, Float const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTexture1DI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 texture( ISampledImage2D const & image
		, Vec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTexture2DI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 texture( ISampledImage3D const & image
		, Vec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTexture3DI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 texture( ISampledImageCube const & image
		, Vec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTextureCubeI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 texture( ISampledImage1DArray const & image
		, Vec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTexture1DArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 texture( ISampledImage2DArray const & image
		, Vec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTexture2DArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 texture( ISampledImageCubeArray const & image
		, Vec4 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTextureCubeArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 texture( ISampledImage2DRect const & image
		, Vec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTexture2DRectI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 texture( USampledImage1D const & image
		, Float const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTexture1DU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 texture( USampledImage2D const & image
		, Vec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTexture2DU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 texture( USampledImage3D const & image
		, Vec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTexture3DU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 texture( USampledImageCube const & image
		, Vec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTextureCubeU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 texture( USampledImage1DArray const & image
		, Vec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTexture1DArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 texture( USampledImage2DArray const & image
		, Vec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTexture2DArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 texture( USampledImageCubeArray const & image
		, Vec4 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTextureCubeArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 texture( USampledImage2DRect const & image
		, Vec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTexture2DRectU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Float texture( SampledImage1DShadow const & image
		, Float const & P
		, Float const & refZ )
	{
		return Float{ findShader( image, P, refZ )
			, expr::makeTexture1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Float texture( SampledImage2DShadow const & image
		, Vec2 const & P
		, Float const & refZ )
	{
		return Float{ findShader( image, P, refZ )
			, expr::makeTexture2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Float texture( SampledImageCubeShadow const & image
		, Vec3 const & P
		, Float const & refZ )
	{
		return Float{ findShader( image, P, refZ )
			, expr::makeTextureCubeShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Float texture( SampledImage1DArrayShadow const & image
		, Vec2 const & P
		, Float const & refZ )
	{
		return Float{ findShader( image, P, refZ )
			, expr::makeTexture1DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Float texture( SampledImage2DArrayShadow const & image
		, Vec3 const & P
		, Float const & refZ )
	{
		return Float{ findShader( image, P, refZ )
			, expr::makeTexture2DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Float texture( SampledImage2DRectShadow const & image
		, Vec2 const & P
		, Float const & refZ )
	{
		return Float{ findShader( image, P, refZ )
			, expr::makeTexture2DRectShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Float texture( SampledImageCubeArrayShadow const & image
		, Vec4 const & P
		, Float const & refZ )
	{
		return Float{ findShader( image, P, refZ )
			, expr::makeTextureCubeArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureBias
	/**
	*name
	*	textureBias
	*/
	/**@{*/
	inline Vec4 texture( SampledImage1D const & image
		, Float const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTexture1DFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 texture( SampledImage2D const & image
		, Vec2 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTexture2DFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 texture( SampledImage3D const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTexture3DFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 texture( SampledImageCube const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureCubeFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 texture( SampledImage1DArray const & image
		, Vec2 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTexture1DArrayFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 texture( SampledImage2DArray const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTexture2DArrayFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 texture( SampledImageCubeArray const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureCubeArrayFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline IVec4 texture( ISampledImage1D const & image
		, Float const & P
		, Float const & bias )
	{
		return IVec4{ findShader( image, P, bias )
			, expr::makeTexture1DIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline IVec4 texture( ISampledImage2D const & image
		, Vec2 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( image, P, bias )
			, expr::makeTexture2DIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline IVec4 texture( ISampledImage3D const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( image, P, bias )
			, expr::makeTexture3DIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline IVec4 texture( ISampledImageCube const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( image, P, bias )
			, expr::makeTextureCubeIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline IVec4 texture( ISampledImage1DArray const & image
		, Vec2 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( image, P, bias )
			, expr::makeTexture1DArrayIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline IVec4 texture( ISampledImage2DArray const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( image, P, bias )
			, expr::makeTexture2DArrayIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline IVec4 texture( ISampledImageCubeArray const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( image, P, bias )
			, expr::makeTextureCubeArrayIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline UVec4 texture( USampledImage1D const & image
		, Float const & P
		, Float const & bias )
	{
		return UVec4{ findShader( image, P, bias )
			, expr::makeTexture1DUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline UVec4 texture( USampledImage2D const & image
		, Vec2 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( image, P, bias )
			, expr::makeTexture2DUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline UVec4 texture( USampledImage3D const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( image, P, bias )
			, expr::makeTexture3DUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline UVec4 texture( USampledImageCube const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( image, P, bias )
			, expr::makeTextureCubeUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline UVec4 texture( USampledImage1DArray const & image
		, Vec2 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( image, P, bias )
			, expr::makeTexture1DArrayUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline UVec4 texture( USampledImage2DArray const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( image, P, bias )
			, expr::makeTexture2DArrayUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline UVec4 texture( USampledImageCubeArray const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( image, P, bias )
			, expr::makeTextureCubeArrayUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Float texture( SampledImage1DShadow const & image
		, Float const & P
		, Float const & refZ
		, Float const & bias )
	{
		return Float{ findShader( image, P, refZ, bias )
			, expr::makeTexture1DShadowFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( bias ) ) };
	}
	inline Float texture( SampledImage2DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & bias )
	{
		return Float{ findShader( image, P, refZ, bias )
			, expr::makeTexture2DShadowFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( bias ) ) };
	}
	inline Float texture( SampledImageCubeShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Float const & bias )
	{
		return Float{ findShader( image, P, refZ, bias )
			, expr::makeTextureCubeShadowFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( bias ) ) };
	}
	inline Float texture( SampledImage1DArrayShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & bias )
	{
		return Float{ findShader( image, P, refZ, bias )
			, expr::makeTexture1DArrayShadowFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( bias ) ) };
	}
	inline Float texture( SampledImage2DArrayShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Float const & bias )
	{
		return Float{ findShader( image, P, refZ, bias )
			, expr::makeTexture2DArrayShadowFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( bias ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureProj
	/**
	*name
	*	textureProj
	*/
	/**@{*/
	inline Vec4 textureProj( SampledImage1D const & image
		, Vec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj1DF2( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( SampledImage1D const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj1DF4( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( SampledImage2D const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DF3( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( SampledImage2D const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DF4( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( SampledImage3D const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj3DF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( SampledImage2DRect const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DRectF3( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( SampledImage2DRect const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DRectF4( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( ISampledImage1D const & image
		, Vec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj1DI2( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( ISampledImage1D const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj1DI4( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( ISampledImage2D const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DI3( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( ISampledImage2D const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DI4( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( ISampledImage3D const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj3DI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( ISampledImage2DRect const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DRectI3( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( ISampledImage2DRect const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DRectI4( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( USampledImage1D const & image
		, Vec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj1DU2( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( USampledImage1D const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj1DU4( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( USampledImage2D const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DU3( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( USampledImage2D const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DU4( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( USampledImage3D const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj3DU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( USampledImage2DRect const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DRectU3( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( USampledImage2DRect const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureProj2DRectU4( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureProj( SampledImage1D const & image
		, Vec2 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj1DF2Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( SampledImage1D const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj1DF4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( SampledImage2D const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj2DF3Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( SampledImage2D const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj2DF4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( ISampledImage1D const & image
		, Vec2 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj1DI2Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( ISampledImage1D const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj1DI4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( ISampledImage2D const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj2DI3Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( ISampledImage2D const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj2DI4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( USampledImage1D const & image
		, Vec2 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj1DU2Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( USampledImage1D const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj1DU4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( USampledImage2D const & image
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj2DU3Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( USampledImage2D const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj2DU4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Float textureProj( SampledImage1DShadow const & image
		, Vec2 const & P
		, Float const & refZ )
	{
		return Float{ findShader( image, P, refZ )
			, expr::makeTextureProj1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Float textureProj( SampledImage2DShadow const & image
		, Vec3 const & P
		, Float const & refZ )
	{
		return Float{ findShader( image, P, refZ )
			, expr::makeTextureProj2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Float textureProj( SampledImage2DRectShadow const & image
		, Vec3 const & P
		, Float const & refZ )
	{
		return Float{ findShader( image, P, refZ )
			, expr::makeTextureProj2DRectShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureProjBias
	/**
	*name
	*	textureProjBias
	*/
	/**@{*/
	inline Vec4 textureProj( SampledImage3D const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj3DFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( ISampledImage3D const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj3DIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProj( USampledImage3D const & image
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, bias )
			, expr::makeTextureProj3DUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}
	inline Float textureProj( SampledImage1DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & bias )
	{
		return Float{ findShader( image, P, refZ, bias )
			, expr::makeTextureProj1DShadowFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( bias ) ) };
	}
	inline Float textureProj( SampledImage2DShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Float const & bias )
	{
		return Float{ findShader( image, P, refZ, bias )
			, expr::makeTextureProj2DShadowFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( bias ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureLod
	/**
	*name
	*	textureLod
	*/
	/**@{*/
	inline Vec4 textureLod( SampledImage1D const & image
		, Float const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod1DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( SampledImage2D const & image
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod2DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( SampledImage3D const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( SampledImageCube const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLodCubeF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( SampledImage1DArray const & image
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod1DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( SampledImage2DArray const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod2DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( SampledImageCubeArray const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLodCubeArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( ISampledImage1D const & image
		, Float const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( ISampledImage2D const & image
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( ISampledImage3D const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( ISampledImageCube const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLodCubeI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( ISampledImage1DArray const & image
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( ISampledImage2DArray const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( ISampledImageCubeArray const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLodCubeArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( USampledImage1D const & image
		, Float const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( USampledImage2D const & image
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( USampledImage3D const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( USampledImageCube const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLodCubeU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( USampledImage1DArray const & image
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( USampledImage2DArray const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLod2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureLod( USampledImageCubeArray const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureLodCubeArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Float textureLod( SampledImage1DShadow const & image
		, Float const & P
		, Float const & refZ
		, Float const & lod )
	{
		return Float{ findShader( image, P, refZ, lod )
			, expr::makeTextureLod1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( lod ) ) };
	}
	inline Float textureLod( SampledImage2DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & lod )
	{
		return Float{ findShader( image, P, refZ, lod )
			, expr::makeTextureLod2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( lod ) ) };
	}
	inline Float textureLod( SampledImage1DArrayShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & lod )
	{
		return Float{ findShader( image, P, refZ, lod )
			, expr::makeTextureLod1DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( lod ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureOffset
	/**
	*name
	*	textureOffset
	*/
	/**@{*/
	inline Vec4 textureOffset( SampledImage1D const & image
		, Float const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset1DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( SampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset2DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( SampledImage3D const & image
		, Vec3 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( SampledImage2DRect const & image
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset2DRectF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( SampledImage1DArray const & image
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset1DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( SampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset2DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( ISampledImage1D const & image
		, Float const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( ISampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( ISampledImage3D const & image
		, Vec3 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( ISampledImage2DRect const & image
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( ISampledImage1DArray const & image
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( ISampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( USampledImage1D const & image
		, Float const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( USampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( USampledImage3D const & image
		, Vec3 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( USampledImage2DRect const & image
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( USampledImage1DArray const & image
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureOffset( USampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureOffset2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Float textureOffset( SampledImage2DRectShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, IVec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, offset )
			, expr::makeTextureOffset2DRectShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}
	inline Float textureOffset( SampledImage1DShadow const & image
		, Float const & P
		, Float const & refZ
		, Int const & offset )
	{
		return Float{ findShader( image, P, refZ, offset )
			, expr::makeTextureOffset1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}
	inline Float textureOffset( SampledImage2DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, IVec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, offset )
			, expr::makeTextureOffset2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}
	inline Float textureOffset( SampledImage1DArrayShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Int const & offset )
	{
		return Float{ findShader( image, P, refZ, offset )
			, expr::makeTextureOffset1DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}
	inline Float textureOffset( SampledImage2DArrayShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Vec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, offset )
			, expr::makeTextureOffset2DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureOffsetBias
	/**
	*name
	*	textureOffsetBias
	*/
	/**@{*/
	inline Vec4 textureOffset( SampledImage1D const & image
		, Float const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset1DFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( SampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset2DFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( SampledImage3D const & image
		, Vec3 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset3DFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( SampledImage1DArray const & image
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset1DArrayFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( SampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset2DArrayFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( ISampledImage1D const & image
		, Float const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset1DIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( ISampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset2DIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( ISampledImage3D const & image
		, Vec3 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset3DIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( ISampledImage1DArray const & image
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset1DArrayIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( ISampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset2DArrayIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( USampledImage1D const & image
		, Float const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset1DUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( USampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset2DUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( USampledImage3D const & image
		, Vec3 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset3DUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( USampledImage1DArray const & image
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset1DArrayUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureOffset( USampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureOffset2DArrayUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Float textureOffset( SampledImage1DShadow const & image
		, Float const & P
		, Float const & refZ
		, Int const & offset
		, Float const & bias )
	{
		return Float{ findShader( image, P, refZ, offset, bias )
			, expr::makeTextureOffset1DShadowFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Float textureOffset( SampledImage2DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, IVec2 const & offset
		, Float const & bias )
	{
		return Float{ findShader( image, P, refZ, offset, bias )
			, expr::makeTextureOffset2DShadowFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region texelFetch
	/**
	*name
	*	texelFetch
	*/
	/**@{*/
	inline Vec4 texelFetch( SampledImage1D const & image
		, Int const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch1DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( SampledImage2D const & image
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch2DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( SampledImage3D const & image
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( SampledImage1DArray const & image
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch1DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( SampledImage2DArray const & image
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch2DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( ISampledImage1D const & image
		, Int const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( ISampledImage2D const & image
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( ISampledImage3D const & image
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( ISampledImage1DArray const & image
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( ISampledImage2DArray const & image
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( USampledImage1D const & image
		, Int const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( USampledImage2D const & image
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( USampledImage3D const & image
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( USampledImage1DArray const & image
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( USampledImage2DArray const & image
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTexelFetch2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 texelFetch( SampledImage2DRect const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexelFetch2DRectF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texelFetch( SampledImageBuffer const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexelFetchBufferF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texelFetch( ISampledImage2DRect const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexelFetch2DRectI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texelFetch( ISampledImageBuffer const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexelFetchBufferI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texelFetch( USampledImage2DRect const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexelFetch2DRectU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 texelFetch( USampledImageBuffer const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTexelFetchBufferU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region texelFetchOffset
	/**
	*name
	*	texelFetchOffset
	*/
	/**@{*/
	inline Vec4 texelFetchOffset( SampledImage1D const & image
		, Int const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset1DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( SampledImage2D const & image
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset2DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( SampledImage3D const & image
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( SampledImage1DArray const & image
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset1DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( SampledImage2DArray const & image
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset2DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( ISampledImage1D const & image
		, Int const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( ISampledImage2D const & image
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( ISampledImage3D const & image
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( ISampledImage1DArray const & image
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( ISampledImage2DArray const & image
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( USampledImage1D const & image
		, Int const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( USampledImage2D const & image
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( USampledImage3D const & image
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( USampledImage1DArray const & image
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( USampledImage2DArray const & image
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTexelFetchOffset2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( SampledImage2DRect const & image
		, IVec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTexelFetchOffset2DRectF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( ISampledImage2DRect const & image
		, IVec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTexelFetchOffset2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 texelFetchOffset( USampledImage2DRect const & image
		, IVec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTexelFetchOffset2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureProjOffset
	/**
	*name
	*	textureProjOffset
	*/
	/**@{*/
	inline Vec4 textureProjOffset( SampledImage1D const & image
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset1DF2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( SampledImage1D const & image
		, Vec4 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset1DF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( SampledImage2D const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DF3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( SampledImage2D const & image
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( SampledImage3D const & image
		, Vec4 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( SampledImage2DRect const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DRectF3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( SampledImage2DRect const & image
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DRectF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage1D const & image
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset1DI2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage1D const & image
		, Vec4 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset1DI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage2D const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DI3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage2D const & image
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage3D const & image
		, Vec4 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage2DRect const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DRectI3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage2DRect const & image
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DRectI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage1D const & image
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset1DU2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage1D const & image
		, Vec4 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset1DU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage2D const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DU3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage2D const & image
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage3D const & image
		, Vec4 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage2DRect const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DRectU3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage2DRect const & image
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureProjOffset2DRectU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjOffset( SampledImage1D const & image
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset1DF2Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( SampledImage1D const & image
		, Vec4 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset1DF4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( SampledImage2D const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset2DF3Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( SampledImage2D const & image
		, Vec4 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset2DF4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage1D const & image
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset1DI2Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage1D const & image
		, Vec4 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset1DI4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage2D const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset2DI3Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage2D const & image
		, Vec4 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset2DI4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage1D const & image
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset1DU2Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage1D const & image
		, Vec4 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset1DU4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage2D const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset2DU3Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage2D const & image
		, Vec4 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset2DU4Bias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Float textureProjOffset( SampledImage1DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Int const & offset )
	{
		return Float{ findShader( image, P, refZ, offset )
			, expr::makeTextureProjOffset1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}
	inline Float textureProjOffset( SampledImage2DShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, IVec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, offset )
			, expr::makeTextureProjOffset2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}
	inline Float textureProjOffset( SampledImage2DRectShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, IVec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, offset )
			, expr::makeTextureProjOffset2DRectShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureProjOffsetBias
	/**
	*name
	*	textureProjOffsetBias
	*/
	/**@{*/
	inline Vec4 textureProjOffset( SampledImage3D const & image
		, Vec4 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset3DFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( ISampledImage3D const & image
		, Vec4 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset3DIBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Vec4 textureProjOffset( USampledImage3D const & image
		, Vec4 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( image, P, offset, bias )
			, expr::makeTextureProjOffset3DUBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Float textureProjOffset( SampledImage1DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Int const & offset
		, Float const & bias )
	{
		return Float{ findShader( image, P, refZ, offset, bias )
			, expr::makeTextureProjOffset1DShadowFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	inline Float textureProjOffset( SampledImage2DShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, IVec2 const & offset
		, Float const & bias )
	{
		return Float{ findShader( image, P, refZ, offset, bias )
			, expr::makeTextureProjOffset2DShadowFBias( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureLodOffset
	/**
	*name
	*	textureLodOffset
	*/
	/**@{*/
	inline Vec4 textureLodOffset( SampledImage1D const & image
		, Float const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset1DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( SampledImage2D const & image
		, Vec2 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset2DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( SampledImage3D const & image
		, Vec3 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( SampledImage1DArray const & image
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset1DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( SampledImage2DArray const & image
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset2DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( ISampledImage1D const & image
		, Float const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( ISampledImage2D const & image
		, Vec2 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( ISampledImage3D const & image
		, Vec3 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( ISampledImage1DArray const & image
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( ISampledImage2DArray const & image
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( USampledImage1D const & image
		, Float const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( USampledImage2D const & image
		, Vec2 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( USampledImage3D const & image
		, Vec3 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( USampledImage1DArray const & image
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureLodOffset( USampledImage2DArray const & image
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureLodOffset2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Float textureLodOffset( SampledImage1DShadow const & image
		, Float const & P
		, Float const & refZ
		, Float const & lod
		, Int const & offset )
	{
		return Float{ findShader( image, P, refZ, lod, offset )
			, expr::makeTextureLodOffset1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Float textureLodOffset( SampledImage2DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & lod
		, IVec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, lod, offset )
			, expr::makeTextureLodOffset2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Float textureLodOffset( SampledImage1DArrayShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & lod
		, Int const & offset )
	{
		return Float{ findShader( image, P, refZ, lod, offset )
			, expr::makeTextureLodOffset1DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureProjLod
	/**
	*name
	*	textureProjLod
	*/
	/**@{*/
	inline Vec4 textureProjLod( SampledImage1D const & image
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod1DF2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( SampledImage1D const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod1DF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( SampledImage2D const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod2DF3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( SampledImage2D const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod2DF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( SampledImage3D const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( ISampledImage1D const & image
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod1DI2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( ISampledImage1D const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod1DI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( ISampledImage2D const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod2DI3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( ISampledImage2D const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod2DI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( ISampledImage3D const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( USampledImage1D const & image
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod1DU2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( USampledImage1D const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod1DU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( USampledImage2D const & image
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod2DU3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( USampledImage2D const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod2DU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Vec4 textureProjLod( USampledImage3D const & image
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( image, P, lod )
			, expr::makeTextureProjLod3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}
	inline Float textureProjLod( SampledImage1DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & lod )
	{
		return Float{ findShader( image, P, refZ, lod )
			, expr::makeTextureProjLod1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( lod ) ) };
	}
	inline Float textureProjLod( SampledImage2DShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Float const & lod )
	{
		return Float{ findShader( image, P, refZ, lod )
			, expr::makeTextureProjLod2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( lod ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureProjLodOffset
	/**
	*name
	*	textureProjLodOffset
	*/
	/**@{*/
	inline Vec4 textureProjLodOffset( SampledImage1D const & image
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset1DF2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( SampledImage1D const & image
		, Vec4 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset1DF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( SampledImage2D const & image
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset2DF3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( SampledImage2D const & image
		, Vec4 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset2DF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( SampledImage3D const & image
		, Vec4 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( ISampledImage1D const & image
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset1DI2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( ISampledImage1D const & image
		, Vec4 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset1DI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( ISampledImage2D const & image
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset2DI3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( ISampledImage2D const & image
		, Vec4 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset2DI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( ISampledImage3D const & image
		, Vec4 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( USampledImage1D const & image
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset1DU2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( USampledImage1D const & image
		, Vec4 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset1DU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( USampledImage2D const & image
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset2DU3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( USampledImage2D const & image
		, Vec4 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset2DU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjLodOffset( USampledImage3D const & image
		, Vec4 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, lod, offset )
			, expr::makeTextureProjLodOffset3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Float textureProjLodOffset( SampledImage1DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & lod
		, Int const & offset )
	{
		return Float{ findShader( image, P, refZ, lod, offset )
			, expr::makeTextureProjLodOffset1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	inline Float textureProjLodOffset( SampledImage2DShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Float const & lod
		, IVec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, lod, offset )
			, expr::makeTextureProjLodOffset2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureGrad
	/**
	*name
	*	textureGrad
	*/
	/**@{*/
	inline Vec4 textureGrad( SampledImage1D const & image
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad1DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( SampledImage2D const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad2DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( SampledImage3D const & image
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( SampledImageCube const & image
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGradCubeF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( SampledImage2DRect const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad2DRectF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( SampledImage1DArray const & image
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad1DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( SampledImage2DArray const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad2DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( SampledImageCubeArray const & image
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGradCubeArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( ISampledImage1D const & image
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( ISampledImage2D const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( ISampledImage3D const & image
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( ISampledImageCube const & image
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGradCubeI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( ISampledImage2DRect const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( ISampledImage1DArray const & image
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( ISampledImage2DArray const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( ISampledImageCubeArray const & image
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGradCubeArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( USampledImage1D const & image
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( USampledImage2D const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( USampledImage3D const & image
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( USampledImageCube const & image
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGradCubeU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( USampledImage2DRect const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( USampledImage1DArray const & image
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( USampledImage2DArray const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGrad2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Vec4 textureGrad( USampledImageCubeArray const & image
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy )
			, expr::makeTextureGradCubeArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Float textureGrad( SampledImage2DRectShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy )
			, expr::makeTextureGrad2DRectShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Float textureGrad( SampledImage1DShadow const & image
		, Float const & P
		, Float const & refZ
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy )
			, expr::makeTextureGrad1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Float textureGrad( SampledImage2DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy )
			, expr::makeTextureGrad2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	inline Float textureGrad( SampledImage1DArrayShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy )
			, expr::makeTextureGrad1DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureGradOffset
	/**
	*name
	*	textureGradOffset
	*/
	/**@{*/
	inline Vec4 textureGradOffset( SampledImage1D const & image
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( SampledImage2D const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( SampledImage3D const & image
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( SampledImage2DRect const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DRectF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( SampledImage1DArray const & image
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( SampledImage2DArray const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( ISampledImage1D const & image
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( ISampledImage2D const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( ISampledImage3D const & image
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( ISampledImage2DRect const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( ISampledImage1DArray const & image
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( ISampledImage2DArray const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( USampledImage1D const & image
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( USampledImage2D const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( USampledImage3D const & image
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( USampledImage2DRect const & image
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( USampledImage1DArray const & image
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGradOffset( USampledImage2DArray const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Float textureGradOffset( SampledImage2DRectShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DRectShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Float textureGradOffset( SampledImage1DShadow const & image
		, Float const & P
		, Float const & refZ
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Float textureGradOffset( SampledImage2DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Float textureGradOffset( SampledImage1DArrayShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Float textureGradOffset( SampledImage2DArrayShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureProjGrad
	/**
	*name
	*	textureProjGrad
	*/
	/**@{*/
	inline Vec4 textureProjGrad( SampledImage1D const & image
		, Vec2 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad1DF2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( SampledImage1D const & image
		, Vec4 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad1DF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( SampledImage2D const & image
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DF3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( SampledImage2D const & image
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( SampledImage3D const & image
		, Vec4 const & P
		, Vec3 const & pDx
		, Vec3 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( SampledImage2DRect const & image
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectF3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( SampledImage2DRect const & image
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( ISampledImage1D const & image
		, Vec2 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad1DI2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( ISampledImage1D const & image
		, Vec4 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad1DI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( ISampledImage2D const & image
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DI3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( ISampledImage2D const & image
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( ISampledImage3D const & image
		, Vec4 const & P
		, Vec3 const & pDx
		, Vec3 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( ISampledImage2DRect const & image
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectI3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( ISampledImage2DRect const & image
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( USampledImage1D const & image
		, Vec2 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad1DU2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( USampledImage1D const & image
		, Vec4 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad1DU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( USampledImage2D const & image
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DU3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( USampledImage2D const & image
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( USampledImage3D const & image
		, Vec4 const & P
		, Vec3 const & pDx
		, Vec3 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( USampledImage2DRect const & image
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectU3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Vec4 textureProjGrad( USampledImage2DRect const & image
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( image, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Float textureProjGrad( SampledImage1DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & pDx
		, Float const & pDy )
	{
		return Float{ findShader( image, P, refZ, pDx, pDy )
			, expr::makeTextureProjGrad1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Float textureProjGrad( SampledImage2DShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Float{ findShader( image, P, refZ, pDx, pDy )
			, expr::makeTextureProjGrad2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	inline Float textureProjGrad( SampledImage2DRectShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Float{ findShader( image, P, refZ, pDx, pDy )
			, expr::makeTextureProjGrad2DRectShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureProjGradOffset
	/**
	*name
	*	textureProjGradOffset
	*/
	/**@{*/
	inline Vec4 textureProjGradOffset( SampledImage1D const & image
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DF2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( SampledImage1D const & image
		, Vec4 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( SampledImage2D const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DF3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( SampledImage2D const & image
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( SampledImage3D const & image
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset3DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( SampledImage2DRect const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectF3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( SampledImage2DRect const & image
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectF4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( ISampledImage1D const & image
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DI2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( ISampledImage1D const & image
		, Vec4 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( ISampledImage2D const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DI3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( ISampledImage2D const & image
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( ISampledImage3D const & image
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset3DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( ISampledImage2DRect const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectI3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( ISampledImage2DRect const & image
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectI4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( USampledImage1D const & image
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DU2( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( USampledImage1D const & image
		, Vec4 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( USampledImage2D const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DU3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( USampledImage2D const & image
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( USampledImage3D const & image
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset3DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( USampledImage2DRect const & image
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectU3( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureProjGradOffset( USampledImage2DRect const & image
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectU4( makeExpr( image )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Float textureProjGradOffset( SampledImage1DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Float textureProjGradOffset( SampledImage2DShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	inline Float textureProjGradOffset( SampledImage2DRectShadow const & image
		, Vec4 const & P
		, Float const & refZ
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Float{ findShader( image, P, refZ, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureGather
	/**
	*name
	*	textureGather
	*/
	/**@{*/
	inline Vec4 textureGather( SampledImage2D const & image
		, Vec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureGather2DF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureGather( SampledImage2DArray const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureGather2DArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureGather( SampledImageCube const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureGatherCubeF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureGather( SampledImageCubeArray const & image
		, Vec4 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureGatherCubeArrayF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureGather( SampledImage2DRect const & image
		, Vec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeTextureGather2DRectF( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 textureGather( ISampledImage2D const & image
		, Vec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTextureGather2DI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 textureGather( ISampledImage2DArray const & image
		, Vec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTextureGather2DArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 textureGather( ISampledImageCube const & image
		, Vec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTextureGatherCubeI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 textureGather( ISampledImageCubeArray const & image
		, Vec4 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTextureGatherCubeArrayI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline IVec4 textureGather( ISampledImage2DRect const & image
		, Vec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeTextureGather2DRectI( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 textureGather( USampledImage2D const & image
		, Vec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTextureGather2DU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 textureGather( USampledImage2DArray const & image
		, Vec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTextureGather2DArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 textureGather( USampledImageCube const & image
		, Vec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTextureGatherCubeU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 textureGather( USampledImageCubeArray const & image
		, Vec4 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTextureGatherCubeArrayU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline UVec4 textureGather( USampledImage2DRect const & image
		, Vec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeTextureGather2DRectU( makeExpr( image )
				, makeExpr( P ) ) };
	}
	inline Vec4 textureGather( SampledImage2D const & image
		, Vec2 const & P
		, Int const & comp )
	{
		return Vec4{ findShader( image, P, comp )
			, expr::makeTextureGather2DFComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline Vec4 textureGather( SampledImage2DArray const & image
		, Vec3 const & P
		, Int const & comp )
	{
		return Vec4{ findShader( image, P, comp )
			, expr::makeTextureGather2DArrayFComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline Vec4 textureGather( SampledImageCube const & image
		, Vec3 const & P
		, Int const & comp )
	{
		return Vec4{ findShader( image, P, comp )
			, expr::makeTextureGatherCubeFComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline Vec4 textureGather( SampledImageCubeArray const & image
		, Vec4 const & P
		, Int const & comp )
	{
		return Vec4{ findShader( image, P, comp )
			, expr::makeTextureGatherCubeArrayFComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline Vec4 textureGather( SampledImage2DRect const & image
		, Vec3 const & P
		, Int const & comp )
	{
		return Vec4{ findShader( image, P, comp )
			, expr::makeTextureGather2DRectFComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline IVec4 textureGather( ISampledImage2D const & image
		, Vec2 const & P
		, Int const & comp )
	{
		return IVec4{ findShader( image, P, comp )
			, expr::makeTextureGather2DIComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline IVec4 textureGather( ISampledImage2DArray const & image
		, Vec3 const & P
		, Int const & comp )
	{
		return IVec4{ findShader( image, P, comp )
			, expr::makeTextureGather2DArrayIComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline IVec4 textureGather( ISampledImageCube const & image
		, Vec3 const & P
		, Int const & comp )
	{
		return IVec4{ findShader( image, P, comp )
			, expr::makeTextureGatherCubeIComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline IVec4 textureGather( ISampledImageCubeArray const & image
		, Vec4 const & P
		, Int const & comp )
	{
		return IVec4{ findShader( image, P, comp )
			, expr::makeTextureGatherCubeArrayIComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline IVec4 textureGather( ISampledImage2DRect const & image
		, Vec3 const & P
		, Int const & comp )
	{
		return IVec4{ findShader( image, P, comp )
			, expr::makeTextureGather2DRectIComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline UVec4 textureGather( USampledImage2D const & image
		, Vec2 const & P
		, Int const & comp )
	{
		return UVec4{ findShader( image, P, comp )
			, expr::makeTextureGather2DUComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline UVec4 textureGather( USampledImage2DArray const & image
		, Vec3 const & P
		, Int const & comp )
	{
		return UVec4{ findShader( image, P, comp )
			, expr::makeTextureGather2DArrayUComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline UVec4 textureGather( USampledImageCube const & image
		, Vec3 const & P
		, Int const & comp )
	{
		return UVec4{ findShader( image, P, comp )
			, expr::makeTextureGatherCubeUComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline UVec4 textureGather( USampledImageCubeArray const & image
		, Vec4 const & P
		, Int const & comp )
	{
		return UVec4{ findShader( image, P, comp )
			, expr::makeTextureGatherCubeArrayUComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline UVec4 textureGather( USampledImage2DRect const & image
		, Vec3 const & P
		, Int const & comp )
	{
		return UVec4{ findShader( image, P, comp )
			, expr::makeTextureGather2DRectUComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}
	inline Vec4 textureGather( SampledImage2DShadow const & image
		, Vec2 const & P
		, Float const & refZ )
	{
		return Vec4{ findShader( image, P, refZ )
			, expr::makeTextureGather2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Vec4 textureGather( SampledImage2DArrayShadow const & image
		, Vec3 const & P
		, Float const & refZ )
	{
		return Vec4{ findShader( image, P, refZ )
			, expr::makeTextureGather2DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Vec4 textureGather( SampledImageCubeShadow const & image
		, Vec3 const & P
		, Float const & refZ )
	{
		return Vec4{ findShader( image, P, refZ )
			, expr::makeTextureGatherCubeShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Vec4 textureGather( SampledImageCubeArrayShadow const & image
		, Vec4 const & P
		, Float const & refZ )
	{
		return Vec4{ findShader( image, P, refZ )
			, expr::makeTextureGatherCubeArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	inline Vec4 textureGather( SampledImage2DRectShadow const & image
		, Vec3 const & P
		, Float const & refZ )
	{
		return Vec4{ findShader( image, P, refZ )
			, expr::makeTextureGather2DRectShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureGatherOffset
	/**
	*name
	*	textureGatherOffset
	*/
	/**@{*/
	inline Vec4 textureGatherOffset( SampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureGatherOffset2DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGatherOffset( SampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureGatherOffset2DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGatherOffset( SampledImage2DRect const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, offset )
			, expr::makeTextureGatherOffset2DRectF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline IVec4 textureGatherOffset( ISampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return IVec4{ findShader( image, P, offset )
			, expr::makeTextureGatherOffset2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline IVec4 textureGatherOffset( ISampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return IVec4{ findShader( image, P, offset )
			, expr::makeTextureGatherOffset2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline IVec4 textureGatherOffset( ISampledImage2DRect const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return IVec4{ findShader( image, P, offset )
			, expr::makeTextureGatherOffset2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline UVec4 textureGatherOffset( USampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return UVec4{ findShader( image, P, offset )
			, expr::makeTextureGatherOffset2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline UVec4 textureGatherOffset( USampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return UVec4{ findShader( image, P, offset )
			, expr::makeTextureGatherOffset2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline UVec4 textureGatherOffset( USampledImage2DRect const & image
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return UVec4{ findShader( image, P, offset )
			, expr::makeTextureGatherOffset2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGatherOffset( SampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return Vec4{ findShader( image, P, offset, comp )
			, expr::makeTextureGatherOffset2DFComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}
	inline Vec4 textureGatherOffset( SampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return Vec4{ findShader( image, P, offset, comp )
			, expr::makeTextureGatherOffset2DArrayFComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}
	inline Vec4 textureGatherOffset( SampledImage2DRect const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return Vec4{ findShader( image, P, offset, comp )
			, expr::makeTextureGatherOffset2DRectFComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}
	inline IVec4 textureGatherOffset( ISampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return IVec4{ findShader( image, P, offset, comp )
			, expr::makeTextureGatherOffset2DIComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}
	inline IVec4 textureGatherOffset( ISampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return IVec4{ findShader( image, P, offset, comp )
			, expr::makeTextureGatherOffset2DArrayIComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}
	inline IVec4 textureGatherOffset( ISampledImage2DRect const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return IVec4{ findShader( image, P, offset, comp )
			, expr::makeTextureGatherOffset2DRectIComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}
	inline UVec4 textureGatherOffset( USampledImage2D const & image
		, Vec2 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return UVec4{ findShader( image, P, offset, comp )
			, expr::makeTextureGatherOffset2DUComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}
	inline UVec4 textureGatherOffset( USampledImage2DArray const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return UVec4{ findShader( image, P, offset, comp )
			, expr::makeTextureGatherOffset2DArrayUComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}
	inline UVec4 textureGatherOffset( USampledImage2DRect const & image
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return UVec4{ findShader( image, P, offset, comp )
			, expr::makeTextureGatherOffset2DRectUComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}
	inline Vec4 textureGatherOffset( SampledImage2DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, refZ, offset )
			, expr::makeTextureGatherOffset2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGatherOffset( SampledImage2DArrayShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, refZ, offset )
			, expr::makeTextureGatherOffset2DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}
	inline Vec4 textureGatherOffset( SampledImage2DRectShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, IVec2 const & offset )
	{
		return Vec4{ findShader( image, P, refZ, offset )
			, expr::makeTextureGatherOffset2DRectShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region textureGatherOffsets
	/**
	*name
	*	textureGatherOffsets
	*/
	/**@{*/
	inline Vec4 textureGatherOffsets( SampledImage2D const & image
		, Vec2 const & P
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( image, P, offsets )
			, expr::makeTextureGatherOffsets2DF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}
	inline Vec4 textureGatherOffsets( SampledImage2DArray const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( image, P, offsets )
			, expr::makeTextureGatherOffsets2DArrayF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}
	inline Vec4 textureGatherOffsets( SampledImage2DRect const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( image, P, offsets )
			, expr::makeTextureGatherOffsets2DRectF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}
	inline IVec4 textureGatherOffsets( ISampledImage2D const & image
		, Vec2 const & P
		, Array< IVec2 > const & offsets )
	{
		return IVec4{ findShader( image, P, offsets )
			, expr::makeTextureGatherOffsets2DI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}
	inline IVec4 textureGatherOffsets( ISampledImage2DArray const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return IVec4{ findShader( image, P, offsets )
			, expr::makeTextureGatherOffsets2DArrayI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}
	inline IVec4 textureGatherOffsets( ISampledImage2DRect const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return IVec4{ findShader( image, P, offsets )
			, expr::makeTextureGatherOffsets2DRectI( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}
	inline UVec4 textureGatherOffsets( USampledImage2D const & image
		, Vec2 const & P
		, Array< IVec2 > const & offsets )
	{
		return UVec4{ findShader( image, P, offsets )
			, expr::makeTextureGatherOffsets2DU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}
	inline UVec4 textureGatherOffsets( USampledImage2DArray const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return UVec4{ findShader( image, P, offsets )
			, expr::makeTextureGatherOffsets2DArrayU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}
	inline UVec4 textureGatherOffsets( USampledImage2DRect const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return UVec4{ findShader( image, P, offsets )
			, expr::makeTextureGatherOffsets2DRectU( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}
	inline Vec4 textureGatherOffsets( SampledImage2D const & image
		, Vec2 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return Vec4{ findShader( image, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DFComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}
	inline Vec4 textureGatherOffsets( SampledImage2DArray const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return Vec4{ findShader( image, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DArrayFComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}
	inline Vec4 textureGatherOffsets( SampledImage2DRect const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return Vec4{ findShader( image, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DRectFComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}
	inline IVec4 textureGatherOffsets( ISampledImage2D const & image
		, Vec2 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return IVec4{ findShader( image, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DIComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}
	inline IVec4 textureGatherOffsets( ISampledImage2DArray const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return IVec4{ findShader( image, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DArrayIComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}
	inline IVec4 textureGatherOffsets( ISampledImage2DRect const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return IVec4{ findShader( image, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DRectIComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}
	inline UVec4 textureGatherOffsets( USampledImage2D const & image
		, Vec2 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return UVec4{ findShader( image, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DUComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}
	inline UVec4 textureGatherOffsets( USampledImage2DArray const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return UVec4{ findShader( image, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DArrayUComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}
	inline UVec4 textureGatherOffsets( USampledImage2DRect const & image
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return UVec4{ findShader( image, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DRectUComp( makeExpr( image )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}
	inline Vec4 textureGatherOffsets( SampledImage2DShadow const & image
		, Vec2 const & P
		, Float const & refZ
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( image, P, refZ, offsets )
			, expr::makeTextureGatherOffsets2DShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offsets ) ) };
	}
	inline Vec4 textureGatherOffsets( SampledImage2DArrayShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( image, P, refZ, offsets )
			, expr::makeTextureGatherOffsets2DArrayShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offsets ) ) };
	}
	inline Vec4 textureGatherOffsets( SampledImage2DRectShadow const & image
		, Vec3 const & P
		, Float const & refZ
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( image, P, refZ, offsets )
			, expr::makeTextureGatherOffsets2DRectShadowF( makeExpr( image )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offsets ) ) };
	}
	/**@}*/
#pragma endregion
}

#endif
