/*
See LICENSE file in root folder
*/
#ifndef ___ShaderWriter_GetTextureAccessFunctions_H___
#define ___ShaderWriter_GetTextureAccessFunctions_H___
#pragma once

#include "Function.hpp"
#include "FunctionParam.hpp"
#include "Bool.hpp"
#include "Image.hpp"
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
{	// Texture Query Functions

	inline Int textureSize( Sampler1D const & texture
		, Int const & lod )
	{
		return Int{ findShader( texture, lod )
			, expr::makeTextureSize1DF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( Sampler2D const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSize2DF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec3 textureSize( Sampler3D const & texture
		, Int const & lod )
	{
		return IVec3{ findShader( texture, lod )
			, expr::makeTextureSize3DF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( SamplerCube const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSizeCubeF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline Int textureSize( Sampler1DShadow const & texture
		, Int const & lod )
	{
		return Int{ findShader( texture, lod )
			, expr::makeTextureSize1DShadowF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( Sampler2DShadow const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSize2DShadowF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( SamplerCubeShadow const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSizeCubeShadowF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec3 textureSize( SamplerCubeArray const & texture
		, Int const & lod )
	{
		return IVec3{ findShader( texture, lod )
			, expr::makeTextureSizeCubeArrayF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec3 textureSize( SamplerCubeArrayShadow const & texture
		, Int const & lod )
	{
		return IVec3{ findShader( texture, lod )
			, expr::makeTextureSizeCubeArrayShadowF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( Sampler2DRect const & texture )
	{
		return IVec2{ findShader( texture )
			, expr::makeTextureSize2DRectF( makeExpr( texture ) ) };
	}

	inline IVec2 textureSize( Sampler2DRectShadow const & texture )
	{
		return IVec2{ findShader( texture )
			, expr::makeTextureSize2DRectShadowF( makeExpr( texture ) ) };
	}

	inline IVec2 textureSize( Sampler1DArray const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSize1DArrayF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec3 textureSize( Sampler2DArray const & texture
		, Int const & lod )
	{
		return IVec3{ findShader( texture, lod )
			, expr::makeTextureSize2DArrayF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( Sampler1DArrayShadow const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSize1DArrayShadowF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec3 textureSize( Sampler2DArrayShadow const & texture
		, Int const & lod )
	{
		return IVec3{ findShader( texture, lod )
			, expr::makeTextureSize2DArrayShadowF( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline Int textureSize( SamplerBuffer const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureSizeBufferF( makeExpr( texture ) ) };
	}

	inline Int textureSize( ISampler1D const & texture
		, Int const & lod )
	{
		return Int{ findShader( texture, lod )
			, expr::makeTextureSize1DI( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( ISampler2D const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSize2DI( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec3 textureSize( ISampler3D const & texture
		, Int const & lod )
	{
		return IVec3{ findShader( texture, lod )
			, expr::makeTextureSize3DI( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( ISamplerCube const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSizeCubeI( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec3 textureSize( ISamplerCubeArray const & texture
		, Int const & lod )
	{
		return IVec3{ findShader( texture, lod )
			, expr::makeTextureSizeCubeArrayI( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( ISampler2DRect const & texture )
	{
		return IVec2{ findShader( texture )
			, expr::makeTextureSize2DRectI( makeExpr( texture ) ) };
	}

	inline IVec2 textureSize( ISampler1DArray const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSize1DArrayI( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec3 textureSize( ISampler2DArray const & texture
		, Int const & lod )
	{
		return IVec3{ findShader( texture, lod )
			, expr::makeTextureSize2DArrayI( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline Int textureSize( ISamplerBuffer const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureSizeBufferI( makeExpr( texture ) ) };
	}

	inline Int textureSize( USampler1D const & texture
		, Int const & lod )
	{
		return Int{ findShader( texture, lod )
			, expr::makeTextureSize1DU( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( USampler2D const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSize2DU( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec3 textureSize( USampler3D const & texture
		, Int const & lod )
	{
		return IVec3{ findShader( texture, lod )
			, expr::makeTextureSize3DU( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( USamplerCube const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSizeCubeU( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec3 textureSize( USamplerCubeArray const & texture
		, Int const & lod )
	{
		return IVec3{ findShader( texture, lod )
			, expr::makeTextureSizeCubeArrayU( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec2 textureSize( USampler2DRect const & texture )
	{
		return IVec2{ findShader( texture )
			, expr::makeTextureSize2DRectU( makeExpr( texture ) ) };
	}

	inline IVec2 textureSize( USampler1DArray const & texture
		, Int const & lod )
	{
		return IVec2{ findShader( texture, lod )
			, expr::makeTextureSize1DArrayU( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline IVec3 textureSize( USampler2DArray const & texture
		, Int const & lod )
	{
		return IVec3{ findShader( texture, lod )
			, expr::makeTextureSize2DArrayU( makeExpr( texture )
				, makeExpr( lod ) ) };
	}

	inline Int textureSize( USamplerBuffer const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureSizeBufferU( makeExpr( texture ) ) };
	}

	inline Vec2 textureQueryLod( Sampler1D const & texture
		, Float const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod1DF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( Sampler2D const & texture
		, Vec2 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod2DF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( Sampler3D const & texture
		, Vec3 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod3DF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( SamplerCube const & texture
		, Vec3 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLodCubeF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( Sampler1DArray const & texture
		, Float const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod1DArrayF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( Sampler2DArray const & texture
		, Vec2 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod2DArrayF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( SamplerCubeArray const & texture
		, Vec3 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLodCubeArrayF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( Sampler1DShadow const & texture
		, Float const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod1DShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( Sampler2DShadow const & texture
		, Vec2 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod2DShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( SamplerCubeShadow const & texture
		, Vec3 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLodCubeShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( Sampler1DArrayShadow const & texture
		, Float const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod1DArrayShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( Sampler2DArrayShadow const & texture
		, Vec2 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod2DArrayShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( SamplerCubeArrayShadow const & texture
		, Vec3 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLodCubeArrayShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( ISampler1D const & texture
		, Float const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod1DI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( ISampler2D const & texture
		, Vec2 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod2DI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( ISampler3D const & texture
		, Vec3 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod3DI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( ISamplerCube const & texture
		, Vec3 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLodCubeI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( ISampler1DArray const & texture
		, Float const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod1DArrayI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( ISampler2DArray const & texture
		, Vec2 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod2DArrayI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( ISamplerCubeArray const & texture
		, Vec3 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLodCubeArrayI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( USampler1D const & texture
		, Float const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod1DU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( USampler2D const & texture
		, Vec2 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod2DU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( USampler3D const & texture
		, Vec3 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod3DU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( USamplerCube const & texture
		, Vec3 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLodCubeU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( USampler1DArray const & texture
		, Float const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod1DArrayU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( USampler2DArray const & texture
		, Vec2 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLod2DArrayU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec2 textureQueryLod( USamplerCubeArray const & texture
		, Vec3 const & P )
	{
		return Vec2{ findShader( texture, P )
			, expr::makeTextureQueryLodCubeArrayU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Int textureQueryLevels( Sampler1D const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels1DF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( Sampler2D const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels2DF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( Sampler3D const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels3DF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( SamplerCube const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevelsCubeF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( Sampler1DArray const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels1DArrayF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( Sampler2DArray const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels2DArrayF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( SamplerCubeArray const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevelsCubeArrayF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( Sampler1DShadow const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels1DShadowF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( Sampler2DShadow const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels2DShadowF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( SamplerCubeShadow const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevelsCubeShadowF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( Sampler1DArrayShadow const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels1DArrayShadowF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( Sampler2DArrayShadow const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels2DArrayShadowF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( SamplerCubeArrayShadow const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevelsCubeArrayShadowF( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( ISampler1D const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels1DI( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( ISampler2D const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels2DI( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( ISampler3D const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels3DI( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( ISamplerCube const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevelsCubeI( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( ISampler1DArray const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels1DArrayI( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( ISampler2DArray const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels2DArrayI( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( ISamplerCubeArray const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevelsCubeArrayI( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( USampler1D const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels1DU( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( USampler2D const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels2DU( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( USampler3D const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels3DU( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( USamplerCube const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevelsCubeU( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( USampler1DArray const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels1DArrayU( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( USampler2DArray const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevels2DArrayU( makeExpr( texture ) ) };
	}

	inline Int textureQueryLevels( USamplerCubeArray const & texture )
	{
		return Int{ findShader( texture )
			, expr::makeTextureQueryLevelsCubeArrayU( makeExpr( texture ) ) };
	}

	// Texel Lookup Functions

	inline Vec4 texture( Sampler1D const & texture
		, Float const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexture1DF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texture( Sampler1D const & texture
		, Float const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTexture1DFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 texture( Sampler2D const & texture
		, Vec2 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexture2DF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texture( Sampler2D const & texture
		, Vec2 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTexture2DFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 texture( Sampler3D const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexture3DF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texture( Sampler3D const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTexture3DFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 texture( SamplerCube const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureCubeF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texture( SamplerCube const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureCubeFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Float texture( Sampler1DShadow const & texture
		, Vec3 const & P )
	{
		return Float{ findShader( texture, P )
			, expr::makeTexture1DShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Float texture( Sampler1DShadow const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return Float{ findShader( texture, P, bias )
			, expr::makeTexture1DShadowFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Float texture( Sampler2DShadow const & texture
		, Vec3 const & P )
	{
		return Float{ findShader( texture, P )
			, expr::makeTexture2DShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Float texture( Sampler2DShadow const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return Float{ findShader( texture, P, bias )
			, expr::makeTexture2DShadowFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Float texture( SamplerCubeShadow const & texture
		, Vec4 const & P )
	{
		return Float{ findShader( texture, P )
			, expr::makeTextureCubeShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Float texture( SamplerCubeShadow const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Float{ findShader( texture, P, bias )
			, expr::makeTextureCubeShadowFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 texture( Sampler1DArray const & texture
		, Vec2 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexture1DArrayF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texture( Sampler1DArray const & texture
		, Vec2 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTexture1DArrayFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 texture( Sampler2DArray const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexture2DArrayF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texture( Sampler2DArray const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTexture2DArrayFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 texture( SamplerCubeArray const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureCubeArrayF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texture( SamplerCubeArray const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureCubeArrayFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Float texture( Sampler1DArrayShadow const & texture
		, Vec3 const & P )
	{
		return Float{ findShader( texture, P )
			, expr::makeTexture1DArrayShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Float texture( Sampler1DArrayShadow const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return Float{ findShader( texture, P, bias )
			, expr::makeTexture1DArrayShadowFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Float texture( Sampler2DArrayShadow const & texture
		, Vec4 const & P )
	{
		return Float{ findShader( texture, P )
			, expr::makeTexture2DArrayShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Float texture( Sampler2DArrayShadow const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Float{ findShader( texture, P, bias )
			, expr::makeTexture2DArrayShadowFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 texture( Sampler2DRect const & texture
		, Vec2 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexture2DRectF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Float texture( Sampler2DRectShadow const & texture
		, Vec3 const & P )
	{
		return Float{ findShader( texture, P )
			, expr::makeTexture2DRectShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Float texture( SamplerCubeArrayShadow const & texture
		, Vec4 const & P
		, Float const & compare )
	{
		return Float{ findShader( texture, P, compare )
			, expr::makeTextureCubeArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( compare ) ) };
	}

	inline IVec4 texture( ISampler1D const & texture
		, Float const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTexture1DI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 texture( ISampler1D const & texture
		, Float const & P
		, Float const & bias )
	{
		return IVec4{ findShader( texture, P, bias )
			, expr::makeTexture1DIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline IVec4 texture( ISampler2D const & texture
		, Vec2 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTexture2DI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 texture( ISampler2D const & texture
		, Vec2 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( texture, P, bias )
			, expr::makeTexture2DIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline IVec4 texture( ISampler3D const & texture
		, Vec3 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTexture3DI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 texture( ISampler3D const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( texture, P, bias )
			, expr::makeTexture3DIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline IVec4 texture( ISamplerCube const & texture
		, Vec3 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTextureCubeI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 texture( ISamplerCube const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( texture, P, bias )
			, expr::makeTextureCubeIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline IVec4 texture( ISampler1DArray const & texture
		, Vec2 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTexture1DArrayI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 texture( ISampler1DArray const & texture
		, Vec2 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( texture, P, bias )
			, expr::makeTexture1DArrayIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline IVec4 texture( ISampler2DArray const & texture
		, Vec3 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTexture2DArrayI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 texture( ISampler2DArray const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( texture, P, bias )
			, expr::makeTexture2DArrayIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline IVec4 texture( ISamplerCubeArray const & texture
		, Vec4 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTextureCubeArrayI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 texture( ISamplerCubeArray const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return IVec4{ findShader( texture, P, bias )
			, expr::makeTextureCubeArrayIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline IVec4 texture( ISampler2DRect const & texture
		, Vec2 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTexture2DRectI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 texture( USampler1D const & texture
		, Float const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTexture1DU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 texture( USampler1D const & texture
		, Float const & P
		, Float const & bias )
	{
		return UVec4{ findShader( texture, P, bias )
			, expr::makeTexture1DUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline UVec4 texture( USampler2D const & texture
		, Vec2 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTexture2DU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 texture( USampler2D const & texture
		, Vec2 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( texture, P, bias )
			, expr::makeTexture2DUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline UVec4 texture( USampler3D const & texture
		, Vec3 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTexture3DU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 texture( USampler3D const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( texture, P, bias )
			, expr::makeTexture3DUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline UVec4 texture( USamplerCube const & texture
		, Vec3 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTextureCubeU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 texture( USamplerCube const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( texture, P, bias )
			, expr::makeTextureCubeUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline UVec4 texture( USampler1DArray const & texture
		, Vec2 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTexture1DArrayU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 texture( USampler1DArray const & texture
		, Vec2 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( texture, P, bias )
			, expr::makeTexture1DArrayUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline UVec4 texture( USampler2DArray const & texture
		, Vec3 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTexture2DArrayU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 texture( USampler2DArray const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( texture, P, bias )
			, expr::makeTexture2DArrayUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline UVec4 texture( USamplerCubeArray const & texture
		, Vec4 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTextureCubeArrayU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 texture( USamplerCubeArray const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return UVec4{ findShader( texture, P, bias )
			, expr::makeTextureCubeArrayUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline UVec4 texture( USampler2DRect const & texture
		, Vec2 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTexture2DRectU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( Sampler1D const & texture
		, Vec2 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj1DF2( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( Sampler1D const & texture
		, Vec2 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj1DF2Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( Sampler1D const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj1DF4( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( Sampler1D const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj1DF4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( Sampler2D const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DF3( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( Sampler2D const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj2DF3Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( Sampler2D const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DF4( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( Sampler2D const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj2DF4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( Sampler3D const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj3DF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( Sampler3D const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj3DFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Float textureProj( Sampler1DShadow const & texture
		, Vec4 const & P )
	{
		return Float{ findShader( texture, P )
			, expr::makeTextureProj1DShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Float textureProj( Sampler1DShadow const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Float{ findShader( texture, P, bias )
			, expr::makeTextureProj1DShadowFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Float textureProj( Sampler2DShadow const & texture
		, Vec4 const & P )
	{
		return Float{ findShader( texture, P )
			, expr::makeTextureProj2DShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Float textureProj( Sampler2DShadow const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Float{ findShader( texture, P, bias )
			, expr::makeTextureProj2DShadowFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( Sampler2DRect const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DRectF3( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( Sampler2DRect const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DRectF4( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Float textureProj( Sampler2DRectShadow const & texture
		, Vec4 const & P )
	{
		return Float{ findShader( texture, P )
			, expr::makeTextureProj2DRectShadowF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( ISampler1D const & texture
		, Vec2 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj1DI2( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( ISampler1D const & texture
		, Vec2 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj1DI2Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( ISampler1D const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj1DI4( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( ISampler1D const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj1DI4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( ISampler2D const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DI3( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( ISampler2D const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj2DI3Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( ISampler2D const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DI4( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( ISampler2D const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj2DI4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( ISampler3D const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj3DI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( ISampler3D const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj3DIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( ISampler2DRect const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DRectI3( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( ISampler2DRect const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DRectI4( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( USampler1D const & texture
		, Vec2 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj1DU2( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( USampler1D const & texture
		, Vec2 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj1DU2Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( USampler1D const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj1DU4( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( USampler1D const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj1DU4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( USampler2D const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DU3( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( USampler2D const & texture
		, Vec3 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj2DU3Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( USampler2D const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DU4( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( USampler2D const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj2DU4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( USampler3D const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj3DU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( USampler3D const & texture
		, Vec4 const & P
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, bias )
			, expr::makeTextureProj3DUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProj( USampler2DRect const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DRectU3( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureProj( USampler2DRect const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureProj2DRectU4( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureLod( Sampler1D const & texture
		, Float const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod1DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( Sampler2D const & texture
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod2DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( Sampler3D const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( SamplerCube const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLodCubeF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Float textureLod( Sampler1DShadow const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Float{ findShader( texture, P, lod )
			, expr::makeTextureLod1DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Float textureLod( Sampler2DShadow const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Float{ findShader( texture, P, lod )
			, expr::makeTextureLod2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( Sampler1DArray const & texture
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod1DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( Sampler2DArray const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod2DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Float textureLod( Sampler1DArrayShadow const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Float{ findShader( texture, P, lod )
			, expr::makeTextureLod1DArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( SamplerCubeArray const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLodCubeArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( ISampler1D const & texture
		, Float const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod1DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( ISampler2D const & texture
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod2DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( ISampler3D const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( ISamplerCube const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLodCubeI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( ISampler1DArray const & texture
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod1DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( ISampler2DArray const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod2DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( ISamplerCubeArray const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLodCubeArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( USampler1D const & texture
		, Float const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod1DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( USampler2D const & texture
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod2DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( USampler3D const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( USamplerCube const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLodCubeU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( USampler1DArray const & texture
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod1DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( USampler2DArray const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLod2DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureLod( USamplerCubeArray const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureLodCubeArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureOffset( Sampler1D const & texture
		, Float const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset1DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( Sampler1D const & texture
		, Float const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset1DFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( Sampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( Sampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset2DFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( Sampler3D const & texture
		, Vec3 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( Sampler3D const & texture
		, Vec3 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset3DFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( Sampler2DRect const & texture
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DRectF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Float textureOffset( Sampler2DRectShadow const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Float{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DRectShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Float textureOffset( Sampler1DShadow const & texture
		, Vec3 const & P
		, Int const & offset )
	{
		return Float{ findShader( texture, P, offset )
			, expr::makeTextureOffset1DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Float textureOffset( Sampler1DShadow const & texture
		, Vec3 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Float{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset1DShadowFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Float textureOffset( Sampler2DShadow const & texture
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Float{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Float textureOffset( Sampler2DShadow const & texture
		, Vec4 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Float{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset2DShadowFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( Sampler1DArray const & texture
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset1DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( Sampler1DArray const & texture
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset1DArrayFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( Sampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( Sampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset2DArrayFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Float textureOffset( Sampler1DArrayShadow const & texture
		, Vec3 const & P
		, Int const & offset )
	{
		return Float{ findShader( texture, P, offset )
			, expr::makeTextureOffset1DArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Float textureOffset( Sampler2DArrayShadow const & texture
		, Vec4 const & P
		, Vec2 const & offset )
	{
		return Float{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( ISampler1D const & texture
		, Float const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset1DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( ISampler1D const & texture
		, Float const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset1DIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( ISampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( ISampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset2DIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( ISampler3D const & texture
		, Vec3 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( ISampler3D const & texture
		, Vec3 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset3DIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( ISampler2DRect const & texture
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DRectI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( ISampler1DArray const & texture
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset1DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( ISampler1DArray const & texture
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset1DArrayIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( ISampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( ISampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset2DArrayIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( USampler1D const & texture
		, Float const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset1DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( USampler1D const & texture
		, Float const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset1DUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( USampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( USampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset2DUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( USampler3D const & texture
		, Vec3 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( USampler3D const & texture
		, Vec3 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset3DUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( USampler2DRect const & texture
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DRectU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( USampler1DArray const & texture
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset1DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( USampler1DArray const & texture
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset1DArrayUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureOffset( USampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureOffset2DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureOffset( USampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureOffset2DArrayUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 texelFetch( Sampler1D const & texture
		, Int const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch1DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( Sampler2D const & texture
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch2DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( Sampler3D const & texture
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( Sampler2DRect const & texture
		, IVec2 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexelFetch2DRectF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texelFetch( Sampler1DArray const & texture
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch1DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( Sampler2DArray const & texture
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch2DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( SamplerBuffer const & texture
		, Int const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexelFetchBufferF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texelFetch( ISampler1D const & texture
		, Int const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch1DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( ISampler2D const & texture
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch2DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( ISampler3D const & texture
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( ISampler2DRect const & texture
		, IVec2 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexelFetch2DRectI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texelFetch( ISampler1DArray const & texture
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch1DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( ISampler2DArray const & texture
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch2DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( ISamplerBuffer const & texture
		, Int const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexelFetchBufferI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texelFetch( USampler1D const & texture
		, Int const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch1DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( USampler2D const & texture
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch2DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( USampler3D const & texture
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( USampler2DRect const & texture
		, IVec2 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexelFetch2DRectU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texelFetch( USampler1DArray const & texture
		, IVec2 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch1DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( USampler2DArray const & texture
		, IVec3 const & P
		, Int const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTexelFetch2DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 texelFetch( USamplerBuffer const & texture
		, Int const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTexelFetchBufferU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 texelFetchOffset( Sampler1D const & texture
		, Int const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset1DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( Sampler2D const & texture
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset2DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( Sampler3D const & texture
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( Sampler2DRect const & texture
		, IVec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTexelFetchOffset2DRectF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( Sampler1DArray const & texture
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset1DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( Sampler2DArray const & texture
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset2DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( ISampler1D const & texture
		, Int const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset1DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( ISampler2D const & texture
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset2DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( ISampler3D const & texture
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( ISampler2DRect const & texture
		, IVec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTexelFetchOffset2DRectI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( ISampler1DArray const & texture
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset1DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( ISampler2DArray const & texture
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset2DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( USampler1D const & texture
		, Int const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset1DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( USampler2D const & texture
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset2DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( USampler3D const & texture
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( USampler2DRect const & texture
		, IVec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTexelFetchOffset2DRectU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( USampler1DArray const & texture
		, IVec2 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset1DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 texelFetchOffset( USampler2DArray const & texture
		, IVec3 const & P
		, Int const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTexelFetchOffset2DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( Sampler1D const & texture
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset1DF2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( Sampler1D const & texture
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset1DF2Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( Sampler1D const & texture
		, Vec4 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset1DF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( Sampler1D const & texture
		, Vec4 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset1DF4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( Sampler2D const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DF3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( Sampler2D const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset2DF3Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( Sampler2D const & texture
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( Sampler2D const & texture
		, Vec4 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset2DF4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( Sampler3D const & texture
		, Vec4 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( Sampler3D const & texture
		, Vec4 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset3DFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Float textureProjOffset( Sampler1DShadow const & texture
		, Vec4 const & P
		, Int const & offset )
	{
		return Float{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset1DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Float textureProjOffset( Sampler1DShadow const & texture
		, Vec4 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Float{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset1DShadowFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Float textureProjOffset( Sampler2DShadow const & texture
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Float{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Float textureProjOffset( Sampler2DShadow const & texture
		, Vec4 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Float{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset2DShadowFBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( Sampler2DRect const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DRectF3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( Sampler2DRect const & texture
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DRectF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Float textureProjOffset( Sampler2DRectShadow const & texture
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Float{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DRectShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( ISampler1D const & texture
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset1DI2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( ISampler1D const & texture
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset1DI2Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( ISampler1D const & texture
		, Vec4 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset1DI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( ISampler1D const & texture
		, Vec4 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset1DI4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( ISampler2D const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DI3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( ISampler2D const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset2DI3Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( ISampler2D const & texture
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( ISampler2D const & texture
		, Vec4 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset2DI4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( ISampler3D const & texture
		, Vec4 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( ISampler3D const & texture
		, Vec4 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset3DIBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( ISampler2DRect const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DRectI3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( ISampler2DRect const & texture
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DRectI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( USampler1D const & texture
		, Vec2 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset1DU2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( USampler1D const & texture
		, Vec2 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset1DU2Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( USampler1D const & texture
		, Vec4 const & P
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset1DU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( USampler1D const & texture
		, Vec4 const & P
		, Int const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset1DU4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( USampler2D const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DU3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( USampler2D const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset2DU3Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( USampler2D const & texture
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( USampler2D const & texture
		, Vec4 const & P
		, IVec2 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset2DU4Bias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( USampler3D const & texture
		, Vec4 const & P
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( USampler3D const & texture
		, Vec4 const & P
		, IVec3 const & offset
		, Float const & bias )
	{
		return Vec4{ findShader( texture, P, offset, bias )
			, expr::makeTextureProjOffset3DUBias( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( bias ) ) };
	}

	inline Vec4 textureProjOffset( USampler2DRect const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DRectU3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjOffset( USampler2DRect const & texture
		, Vec4 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureProjOffset2DRectU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( Sampler1D const & texture
		, Float const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset1DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( Sampler2D const & texture
		, Vec2 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset2DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( Sampler3D const & texture
		, Vec3 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Float textureLodOffset( Sampler1DShadow const & texture
		, Vec3 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Float{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset1DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Float textureLodOffset( Sampler2DShadow const & texture
		, Vec4 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Float{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( Sampler1DArray const & texture
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset1DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( Sampler2DArray const & texture
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset2DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Float textureLodOffset( Sampler1DArrayShadow const & texture
		, Vec3 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Float{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset1DArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( ISampler1D const & texture
		, Float const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset1DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( ISampler2D const & texture
		, Vec2 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset2DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( ISampler3D const & texture
		, Vec3 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( ISampler1DArray const & texture
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset1DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( ISampler2DArray const & texture
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset2DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( USampler1D const & texture
		, Float const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset1DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( USampler2D const & texture
		, Vec2 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset2DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( USampler3D const & texture
		, Vec3 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( USampler1DArray const & texture
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset1DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureLodOffset( USampler2DArray const & texture
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureLodOffset2DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLod( Sampler1D const & texture
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod1DF2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( Sampler1D const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod1DF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( Sampler2D const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod2DF3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( Sampler2D const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod2DF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( Sampler3D const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Float textureProjLod( Sampler1DShadow const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Float{ findShader( texture, P, lod )
			, expr::makeTextureProjLod1DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Float textureProjLod( Sampler2DShadow const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Float{ findShader( texture, P, lod )
			, expr::makeTextureProjLod2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( ISampler1D const & texture
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod1DI2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( ISampler1D const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod1DI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( ISampler2D const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod2DI3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( ISampler2D const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod2DI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( ISampler3D const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( USampler1D const & texture
		, Vec2 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod1DU2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( USampler1D const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod1DU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( USampler2D const & texture
		, Vec3 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod2DU3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( USampler2D const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod2DU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLod( USampler3D const & texture
		, Vec4 const & P
		, Float const & lod )
	{
		return Vec4{ findShader( texture, P, lod )
			, expr::makeTextureProjLod3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod ) ) };
	}

	inline Vec4 textureProjLodOffset( Sampler1D const & texture
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset1DF2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( Sampler1D const & texture
		, Vec4 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset1DF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( Sampler2D const & texture
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset2DF3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( Sampler2D const & texture
		, Vec4 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset2DF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( Sampler3D const & texture
		, Vec4 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Float textureProjLodOffset( Sampler1DShadow const & texture
		, Vec4 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Float{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset1DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Float textureProjLodOffset( Sampler2DShadow const & texture
		, Vec4 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Float{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( ISampler1D const & texture
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset1DI2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( ISampler1D const & texture
		, Vec4 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset1DI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( ISampler2D const & texture
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset2DI3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( ISampler2D const & texture
		, Vec4 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset2DI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( ISampler3D const & texture
		, Vec4 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( USampler1D const & texture
		, Vec2 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset1DU2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( USampler1D const & texture
		, Vec4 const & P
		, Float const & lod
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset1DU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( USampler2D const & texture
		, Vec3 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset2DU3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( USampler2D const & texture
		, Vec4 const & P
		, Float const & lod
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset2DU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjLodOffset( USampler3D const & texture
		, Vec4 const & P
		, Float const & lod
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, lod, offset )
			, expr::makeTextureProjLodOffset3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( lod )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGrad( Sampler1D const & texture
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad1DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( Sampler2D const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad2DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( Sampler3D const & texture
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( SamplerCube const & texture
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGradCubeF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( Sampler2DRect const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad2DRectF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Float textureGrad( Sampler2DRectShadow const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Float{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad2DRectShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Float textureGrad( Sampler1DShadow const & texture
		, Vec3 const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Float{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad1DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Float textureGrad( Sampler2DShadow const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Float{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( Sampler1DArray const & texture
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad1DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( Sampler2DArray const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad2DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Float textureGrad( Sampler1DArrayShadow const & texture
		, Vec3 const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Float{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad1DArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( SamplerCubeArray const & texture
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGradCubeArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( ISampler1D const & texture
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad1DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( ISampler2D const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad2DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( ISampler3D const & texture
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( ISamplerCube const & texture
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGradCubeI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( ISampler2DRect const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad2DRectI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( ISampler1DArray const & texture
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad1DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( ISampler2DArray const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad2DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( ISamplerCubeArray const & texture
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGradCubeArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( USampler1D const & texture
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad1DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( USampler2D const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad2DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( USampler3D const & texture
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( USamplerCube const & texture
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGradCubeU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( USampler2DRect const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad2DRectU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( USampler1DArray const & texture
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad1DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( USampler2DArray const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGrad2DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGrad( USamplerCubeArray const & texture
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy )
			, expr::makeTextureGradCubeArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy ) ) };
	}

	inline Vec4 textureGradOffset( Sampler1D const & texture
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( Sampler2D const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( Sampler3D const & texture
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( Sampler2DRect const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DRectF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Float textureGradOffset( Sampler2DRectShadow const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Float{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DRectShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Float textureGradOffset( Sampler1DShadow const & texture
		, Vec3 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Float{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Float textureGradOffset( Sampler2DShadow const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Float{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( Sampler1DArray const & texture
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( Sampler2DArray const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Float textureGradOffset( Sampler1DArrayShadow const & texture
		, Vec3 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Float{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Float textureGradOffset( Sampler2DArrayShadow const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Float{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( ISampler1D const & texture
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( ISampler2D const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( ISampler3D const & texture
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( ISampler2DRect const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DRectI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( ISampler1DArray const & texture
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( ISampler2DArray const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( USampler1D const & texture
		, Float const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( USampler2D const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( USampler3D const & texture
		, Vec3 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( USampler2DRect const & texture
		, Vec2 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DRectU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( USampler1DArray const & texture
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset1DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGradOffset( USampler2DArray const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureGradOffset2DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGrad( Sampler1D const & texture
		, Vec2 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad1DF2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( Sampler1D const & texture
		, Vec4 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad1DF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( Sampler2D const & texture
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DF3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( Sampler2D const & texture
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( Sampler3D const & texture
		, Vec4 const & P
		, Vec3 const & pDx
		, Vec3 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Float textureProjGrad( Sampler1DShadow const & texture
		, Vec4 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Float{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad1DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Float textureProjGrad( Sampler2DShadow const & texture
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Float{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( Sampler2DRect const & texture
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectF3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( Sampler2DRect const & texture
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Float textureProjGrad( Sampler2DRectShadow const & texture
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Float{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( ISampler1D const & texture
		, Vec2 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad1DI2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( ISampler1D const & texture
		, Vec4 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad1DI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( ISampler2D const & texture
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DI3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( ISampler2D const & texture
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( ISampler3D const & texture
		, Vec4 const & P
		, Vec3 const & pDx
		, Vec3 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( ISampler2DRect const & texture
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectI3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( ISampler2DRect const & texture
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( USampler1D const & texture
		, Vec2 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad1DU2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( USampler1D const & texture
		, Vec4 const & P
		, Float const & pDx
		, Float const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad1DU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( USampler2D const & texture
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DU3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( USampler2D const & texture
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( USampler3D const & texture
		, Vec4 const & P
		, Vec3 const & pDx
		, Vec3 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( USampler2DRect const & texture
		, Vec3 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectU3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGrad( USampler2DRect const & texture
		, Vec4 const & P
		, Vec2 const & pDx
		, Vec2 const & pDy )
	{
		return Vec4{ findShader( texture, P, pDx, pDy )
			, expr::makeTextureProjGrad2DRectU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( pDx )
				, makeExpr( pDy ) ) };
	}

	inline Vec4 textureProjGradOffset( Sampler1D const & texture
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DF2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( Sampler1D const & texture
		, Vec4 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( Sampler2D const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DF3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( Sampler2D const & texture
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( Sampler3D const & texture
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset3DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Float textureProjGradOffset( Sampler1DShadow const & texture
		, Vec4 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Float{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Float textureProjGradOffset( Sampler2DShadow const & texture
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Float{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( Sampler2DRect const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectF3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( Sampler2DRect const & texture
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectF4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Float textureProjGradOffset( Sampler2DRectShadow const & texture
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Float{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( ISampler1D const & texture
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DI2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( ISampler1D const & texture
		, Vec4 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( ISampler2D const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DI3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( ISampler2D const & texture
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( ISampler3D const & texture
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset3DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( ISampler2DRect const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectI3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( ISampler2DRect const & texture
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectI4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( USampler1D const & texture
		, Vec2 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DU2( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( USampler1D const & texture
		, Vec4 const & P
		, Float const & dPdx
		, Float const & dPdy
		, Int const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset1DU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( USampler2D const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DU3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( USampler2D const & texture
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( USampler3D const & texture
		, Vec4 const & P
		, Vec3 const & dPdx
		, Vec3 const & dPdy
		, IVec3 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset3DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( USampler2DRect const & texture
		, Vec3 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectU3( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureProjGradOffset( USampler2DRect const & texture
		, Vec4 const & P
		, Vec2 const & dPdx
		, Vec2 const & dPdy
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, dPdx, dPdy, offset )
			, expr::makeTextureProjGradOffset2DRectU4( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( dPdx )
				, makeExpr( dPdy )
				, makeExpr( offset ) ) };
	}

	// Texture Gather Functions

	inline Vec4 textureGather( Sampler2D const & texture
		, Vec2 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureGather2DF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureGather( Sampler2D const & texture
		, Vec2 const & P
		, Int const & comp )
	{
		return Vec4{ findShader( texture, P, comp )
			, expr::makeTextureGather2DFComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGather( Sampler2DArray const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureGather2DArrayF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureGather( Sampler2DArray const & texture
		, Vec3 const & P
		, Int const & comp )
	{
		return Vec4{ findShader( texture, P, comp )
			, expr::makeTextureGather2DArrayFComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGather( SamplerCube const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureGatherCubeF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureGather( SamplerCube const & texture
		, Vec3 const & P
		, Int const & comp )
	{
		return Vec4{ findShader( texture, P, comp )
			, expr::makeTextureGatherCubeFComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGather( SamplerCubeArray const & texture
		, Vec4 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureGatherCubeArrayF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureGather( SamplerCubeArray const & texture
		, Vec4 const & P
		, Int const & comp )
	{
		return Vec4{ findShader( texture, P, comp )
			, expr::makeTextureGatherCubeArrayFComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGather( Sampler2DRect const & texture
		, Vec3 const & P )
	{
		return Vec4{ findShader( texture, P )
			, expr::makeTextureGather2DRectF( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline Vec4 textureGather( Sampler2DRect const & texture
		, Vec3 const & P
		, Int const & comp )
	{
		return Vec4{ findShader( texture, P, comp )
			, expr::makeTextureGather2DRectFComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGather( Sampler2DShadow const & texture
		, Vec2 const & P
		, Float const & refZ )
	{
		return Vec4{ findShader( texture, P, refZ )
			, expr::makeTextureGather2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}

	inline Vec4 textureGather( Sampler2DArrayShadow const & texture
		, Vec3 const & P
		, Float const & refZ )
	{
		return Vec4{ findShader( texture, P, refZ )
			, expr::makeTextureGather2DArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}

	inline Vec4 textureGather( SamplerCubeShadow const & texture
		, Vec3 const & P
		, Float const & refZ )
	{
		return Vec4{ findShader( texture, P, refZ )
			, expr::makeTextureGatherCubeShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}

	inline Vec4 textureGather( SamplerCubeArrayShadow const & texture
		, Vec4 const & P
		, Float const & refZ )
	{
		return Vec4{ findShader( texture, P, refZ )
			, expr::makeTextureGatherCubeArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}

	inline Vec4 textureGather( Sampler2DRectShadow const & texture
		, Vec3 const & P
		, Float const & refZ )
	{
		return Vec4{ findShader( texture, P, refZ )
			, expr::makeTextureGather2DRectShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( refZ ) ) };
	}

	inline IVec4 textureGather( ISampler2D const & texture
		, Vec2 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTextureGather2DI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 textureGather( ISampler2D const & texture
		, Vec2 const & P
		, Int const & comp )
	{
		return IVec4{ findShader( texture, P, comp )
			, expr::makeTextureGather2DIComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline IVec4 textureGather( ISampler2DArray const & texture
		, Vec3 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTextureGather2DArrayI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 textureGather( ISampler2DArray const & texture
		, Vec3 const & P
		, Int const & comp )
	{
		return IVec4{ findShader( texture, P, comp )
			, expr::makeTextureGather2DArrayIComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline IVec4 textureGather( ISamplerCube const & texture
		, Vec3 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTextureGatherCubeI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 textureGather( ISamplerCube const & texture
		, Vec3 const & P
		, Int const & comp )
	{
		return IVec4{ findShader( texture, P, comp )
			, expr::makeTextureGatherCubeIComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline IVec4 textureGather( ISamplerCubeArray const & texture
		, Vec4 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTextureGatherCubeArrayI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 textureGather( ISamplerCubeArray const & texture
		, Vec4 const & P
		, Int const & comp )
	{
		return IVec4{ findShader( texture, P, comp )
			, expr::makeTextureGatherCubeArrayIComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline IVec4 textureGather( ISampler2DRect const & texture
		, Vec3 const & P )
	{
		return IVec4{ findShader( texture, P )
			, expr::makeTextureGather2DRectI( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline IVec4 textureGather( ISampler2DRect const & texture
		, Vec3 const & P
		, Int const & comp )
	{
		return IVec4{ findShader( texture, P, comp )
			, expr::makeTextureGather2DRectIComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline UVec4 textureGather( USampler2D const & texture
		, Vec2 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTextureGather2DU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 textureGather( USampler2D const & texture
		, Vec2 const & P
		, Int const & comp )
	{
		return UVec4{ findShader( texture, P, comp )
			, expr::makeTextureGather2DUComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline UVec4 textureGather( USampler2DArray const & texture
		, Vec3 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTextureGather2DArrayU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 textureGather( USampler2DArray const & texture
		, Vec3 const & P
		, Int const & comp )
	{
		return UVec4{ findShader( texture, P, comp )
			, expr::makeTextureGather2DArrayUComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline UVec4 textureGather( USamplerCube const & texture
		, Vec3 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTextureGatherCubeU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 textureGather( USamplerCube const & texture
		, Vec3 const & P
		, Int const & comp )
	{
		return UVec4{ findShader( texture, P, comp )
			, expr::makeTextureGatherCubeUComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline UVec4 textureGather( USamplerCubeArray const & texture
		, Vec4 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTextureGatherCubeArrayU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 textureGather( USamplerCubeArray const & texture
		, Vec4 const & P
		, Int const & comp )
	{
		return UVec4{ findShader( texture, P, comp )
			, expr::makeTextureGatherCubeArrayUComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline UVec4 textureGather( USampler2DRect const & texture
		, Vec3 const & P )
	{
		return UVec4{ findShader( texture, P )
			, expr::makeTextureGather2DRectU( makeExpr( texture )
				, makeExpr( P ) ) };
	}

	inline UVec4 textureGather( USampler2DRect const & texture
		, Vec3 const & P
		, Int const & comp )
	{
		return UVec4{ findShader( texture, P, comp )
			, expr::makeTextureGather2DRectUComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGatherOffset( Sampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureGatherOffset2DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGatherOffset( Sampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return Vec4{ findShader( texture, P, offset, comp )
			, expr::makeTextureGatherOffset2DFComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGatherOffset( Sampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureGatherOffset2DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGatherOffset( Sampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return Vec4{ findShader( texture, P, offset, comp )
			, expr::makeTextureGatherOffset2DArrayFComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGatherOffset( Sampler2DRect const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, offset )
			, expr::makeTextureGatherOffset2DRectF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGatherOffset( Sampler2DRect const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return Vec4{ findShader( texture, P, offset, comp )
			, expr::makeTextureGatherOffset2DRectFComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGatherOffset( Sampler2DShadow const & texture
		, Vec2 const & P
		, Float const & refZ
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, refZ, offset )
			, expr::makeTextureGatherOffset2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGatherOffset( Sampler2DArrayShadow const & texture
		, Vec3 const & P
		, Float const & refZ
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, refZ, offset )
			, expr::makeTextureGatherOffset2DArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}

	inline Vec4 textureGatherOffset( Sampler2DRectShadow const & texture
		, Vec3 const & P
		, Float const & refZ
		, IVec2 const & offset )
	{
		return Vec4{ findShader( texture, P, refZ, offset )
			, expr::makeTextureGatherOffset2DRectShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offset ) ) };
	}

	inline IVec4 textureGatherOffset( ISampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return IVec4{ findShader( texture, P, offset )
			, expr::makeTextureGatherOffset2DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline IVec4 textureGatherOffset( ISampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return IVec4{ findShader( texture, P, offset, comp )
			, expr::makeTextureGatherOffset2DIComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}

	inline IVec4 textureGatherOffset( ISampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return IVec4{ findShader( texture, P, offset )
			, expr::makeTextureGatherOffset2DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline IVec4 textureGatherOffset( ISampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return IVec4{ findShader( texture, P, offset, comp )
			, expr::makeTextureGatherOffset2DArrayIComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}

	inline IVec4 textureGatherOffset( ISampler2DRect const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return IVec4{ findShader( texture, P, offset )
			, expr::makeTextureGatherOffset2DRectI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline IVec4 textureGatherOffset( ISampler2DRect const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return IVec4{ findShader( texture, P, offset, comp )
			, expr::makeTextureGatherOffset2DRectIComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}

	inline UVec4 textureGatherOffset( USampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset )
	{
		return UVec4{ findShader( texture, P, offset )
			, expr::makeTextureGatherOffset2DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline UVec4 textureGatherOffset( USampler2D const & texture
		, Vec2 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return UVec4{ findShader( texture, P, offset, comp )
			, expr::makeTextureGatherOffset2DUComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}

	inline UVec4 textureGatherOffset( USampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return UVec4{ findShader( texture, P, offset )
			, expr::makeTextureGatherOffset2DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline UVec4 textureGatherOffset( USampler2DArray const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return UVec4{ findShader( texture, P, offset, comp )
			, expr::makeTextureGatherOffset2DArrayUComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}

	inline UVec4 textureGatherOffset( USampler2DRect const & texture
		, Vec3 const & P
		, IVec2 const & offset )
	{
		return UVec4{ findShader( texture, P, offset )
			, expr::makeTextureGatherOffset2DRectU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset ) ) };
	}

	inline UVec4 textureGatherOffset( USampler2DRect const & texture
		, Vec3 const & P
		, IVec2 const & offset
		, Int const & comp )
	{
		return UVec4{ findShader( texture, P, offset, comp )
			, expr::makeTextureGatherOffset2DRectUComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offset )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGatherOffsets( Sampler2D const & texture
		, Vec2 const & P
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( texture, P, offsets )
			, expr::makeTextureGatherOffsets2DF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}

	inline Vec4 textureGatherOffsets( Sampler2D const & texture
		, Vec2 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return Vec4{ findShader( texture, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DFComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGatherOffsets( Sampler2DArray const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( texture, P, offsets )
			, expr::makeTextureGatherOffsets2DArrayF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}

	inline Vec4 textureGatherOffsets( Sampler2DArray const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return Vec4{ findShader( texture, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DArrayFComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGatherOffsets( Sampler2DRect const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( texture, P, offsets )
			, expr::makeTextureGatherOffsets2DRectF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}

	inline Vec4 textureGatherOffsets( Sampler2DRect const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return Vec4{ findShader( texture, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DRectFComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}

	inline Vec4 textureGatherOffsets( Sampler2DShadow const & texture
		, Vec2 const & P
		, Float const & refZ
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( texture, P, refZ, offsets )
			, expr::makeTextureGatherOffsets2DShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offsets ) ) };
	}

	inline Vec4 textureGatherOffsets( Sampler2DArrayShadow const & texture
		, Vec3 const & P
		, Float const & refZ
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( texture, P, refZ, offsets )
			, expr::makeTextureGatherOffsets2DArrayShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offsets ) ) };
	}

	inline Vec4 textureGatherOffsets( Sampler2DRectShadow const & texture
		, Vec3 const & P
		, Float const & refZ
		, Array< IVec2 > const & offsets )
	{
		return Vec4{ findShader( texture, P, refZ, offsets )
			, expr::makeTextureGatherOffsets2DRectShadowF( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( refZ )
				, makeExpr( offsets ) ) };
	}

	inline IVec4 textureGatherOffsets( ISampler2D const & texture
		, Vec2 const & P
		, Array< IVec2 > const & offsets )
	{
		return IVec4{ findShader( texture, P, offsets )
			, expr::makeTextureGatherOffsets2DI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}

	inline IVec4 textureGatherOffsets( ISampler2D const & texture
		, Vec2 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return IVec4{ findShader( texture, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DIComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}

	inline IVec4 textureGatherOffsets( ISampler2DArray const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return IVec4{ findShader( texture, P, offsets )
			, expr::makeTextureGatherOffsets2DArrayI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}

	inline IVec4 textureGatherOffsets( ISampler2DArray const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return IVec4{ findShader( texture, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DArrayIComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}

	inline IVec4 textureGatherOffsets( ISampler2DRect const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return IVec4{ findShader( texture, P, offsets )
			, expr::makeTextureGatherOffsets2DRectI( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}

	inline IVec4 textureGatherOffsets( ISampler2DRect const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return IVec4{ findShader( texture, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DRectIComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}

	inline UVec4 textureGatherOffsets( USampler2D const & texture
		, Vec2 const & P
		, Array< IVec2 > const & offsets )
	{
		return UVec4{ findShader( texture, P, offsets )
			, expr::makeTextureGatherOffsets2DU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}

	inline UVec4 textureGatherOffsets( USampler2D const & texture
		, Vec2 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return UVec4{ findShader( texture, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DUComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}

	inline UVec4 textureGatherOffsets( USampler2DArray const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return UVec4{ findShader( texture, P, offsets )
			, expr::makeTextureGatherOffsets2DArrayU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}

	inline UVec4 textureGatherOffsets( USampler2DArray const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return UVec4{ findShader( texture, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DArrayUComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}

	inline UVec4 textureGatherOffsets( USampler2DRect const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets )
	{
		return UVec4{ findShader( texture, P, offsets )
			, expr::makeTextureGatherOffsets2DRectU( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets ) ) };
	}

	inline UVec4 textureGatherOffsets( USampler2DRect const & texture
		, Vec3 const & P
		, Array< IVec2 > const & offsets
		, Int const & comp )
	{
		return UVec4{ findShader( texture, P, offsets, comp )
			, expr::makeTextureGatherOffsets2DRectUComp( makeExpr( texture )
				, makeExpr( P )
				, makeExpr( offsets )
				, makeExpr( comp ) ) };
	}
}

#endif
