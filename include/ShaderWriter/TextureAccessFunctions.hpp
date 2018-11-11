
/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TextureAccessFunctions_H___
#define ___SDW_TextureAccessFunctions_H___
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
	Int textureSize( SampledImage1D const & image, Int const & lod );
	IVec2 textureSize( SampledImage2D const & image, Int const & lod );
	IVec3 textureSize( SampledImage3D const & image, Int const & lod );
	IVec2 textureSize( SampledImageCube const & image, Int const & lod );
	Int textureSize( SampledImage1DShadow const & image, Int const & lod );
	IVec2 textureSize( SampledImage2DShadow const & image, Int const & lod );
	IVec2 textureSize( SampledImageCubeShadow const & image, Int const & lod );
	IVec3 textureSize( SampledImageCubeArray const & image, Int const & lod );
	IVec3 textureSize( SampledImageCubeArrayShadow const & image, Int const & lod );
	IVec2 textureSize( SampledImage1DArray const & image, Int const & lod );
	IVec3 textureSize( SampledImage2DArray const & image, Int const & lod );
	IVec2 textureSize( SampledImage1DArrayShadow const & image, Int const & lod );
	IVec3 textureSize( SampledImage2DArrayShadow const & image, Int const & lod );
	Int textureSize( ISampledImage1D const & image, Int const & lod );
	IVec2 textureSize( ISampledImage2D const & image, Int const & lod );
	IVec3 textureSize( ISampledImage3D const & image, Int const & lod );
	IVec2 textureSize( ISampledImageCube const & image, Int const & lod );
	IVec3 textureSize( ISampledImageCubeArray const & image, Int const & lod );
	IVec2 textureSize( ISampledImage1DArray const & image, Int const & lod );
	IVec3 textureSize( ISampledImage2DArray const & image, Int const & lod );
	Int textureSize( USampledImage1D const & image, Int const & lod );
	IVec2 textureSize( USampledImage2D const & image, Int const & lod );
	IVec3 textureSize( USampledImage3D const & image, Int const & lod );
	IVec2 textureSize( USampledImageCube const & image, Int const & lod );
	IVec3 textureSize( USampledImageCubeArray const & image, Int const & lod );
	IVec2 textureSize( USampledImage1DArray const & image, Int const & lod );
	IVec3 textureSize( USampledImage2DArray const & image, Int const & lod );
	IVec2 textureSize( SampledImage2DRect const & image );
	IVec2 textureSize( SampledImage2DRectShadow const & image );
	Int textureSize( SampledImageBuffer const & image );
	IVec2 textureSize( ISampledImage2DRect const & image );
	Int textureSize( ISampledImageBuffer const & image );
	IVec2 textureSize( USampledImage2DRect const & image );
	Int textureSize( USampledImageBuffer const & image );
	/**@}*/
#pragma endregion
#pragma region textureQueryLod
	/**
	*name
	*	textureQueryLod
	*/
	/**@{*/
	Vec2 textureQueryLod( SampledImage1D const & image, Float const & P );
	Vec2 textureQueryLod( SampledImage2D const & image, Vec2 const & P );
	Vec2 textureQueryLod( SampledImage3D const & image, Vec3 const & P );
	Vec2 textureQueryLod( SampledImageCube const & image, Vec3 const & P );
	Vec2 textureQueryLod( SampledImage1DArray const & image, Float const & P );
	Vec2 textureQueryLod( SampledImage2DArray const & image, Vec2 const & P );
	Vec2 textureQueryLod( SampledImageCubeArray const & image, Vec3 const & P );
	Vec2 textureQueryLod( SampledImage1DShadow const & image, Float const & P );
	Vec2 textureQueryLod( SampledImage2DShadow const & image, Vec2 const & P );
	Vec2 textureQueryLod( SampledImageCubeShadow const & image, Vec3 const & P );
	Vec2 textureQueryLod( SampledImage1DArrayShadow const & image, Float const & P );
	Vec2 textureQueryLod( SampledImage2DArrayShadow const & image, Vec2 const & P );
	Vec2 textureQueryLod( SampledImageCubeArrayShadow const & image, Vec3 const & P );
	Vec2 textureQueryLod( ISampledImage1D const & image, Float const & P );
	Vec2 textureQueryLod( ISampledImage2D const & image, Vec2 const & P );
	Vec2 textureQueryLod( ISampledImage3D const & image, Vec3 const & P );
	Vec2 textureQueryLod( ISampledImageCube const & image, Vec3 const & P );
	Vec2 textureQueryLod( ISampledImage1DArray const & image, Float const & P );
	Vec2 textureQueryLod( ISampledImage2DArray const & image, Vec2 const & P );
	Vec2 textureQueryLod( ISampledImageCubeArray const & image, Vec3 const & P );
	Vec2 textureQueryLod( USampledImage1D const & image, Float const & P );
	Vec2 textureQueryLod( USampledImage2D const & image, Vec2 const & P );
	Vec2 textureQueryLod( USampledImage3D const & image, Vec3 const & P );
	Vec2 textureQueryLod( USampledImageCube const & image, Vec3 const & P );
	Vec2 textureQueryLod( USampledImage1DArray const & image, Float const & P );
	Vec2 textureQueryLod( USampledImage2DArray const & image, Vec2 const & P );
	Vec2 textureQueryLod( USampledImageCubeArray const & image, Vec3 const & P );
	/**@}*/
#pragma endregion
#pragma region textureQueryLevels
	/**
	*name
	*	textureQueryLevels
	*/
	/**@{*/
	Int textureQueryLevels( SampledImage1D const & image );
	Int textureQueryLevels( SampledImage2D const & image );
	Int textureQueryLevels( SampledImage3D const & image );
	Int textureQueryLevels( SampledImageCube const & image );
	Int textureQueryLevels( SampledImage1DArray const & image );
	Int textureQueryLevels( SampledImage2DArray const & image );
	Int textureQueryLevels( SampledImageCubeArray const & image );
	Int textureQueryLevels( SampledImage1DShadow const & image );
	Int textureQueryLevels( SampledImage2DShadow const & image );
	Int textureQueryLevels( SampledImageCubeShadow const & image );
	Int textureQueryLevels( SampledImage1DArrayShadow const & image );
	Int textureQueryLevels( SampledImage2DArrayShadow const & image );
	Int textureQueryLevels( SampledImageCubeArrayShadow const & image );
	Int textureQueryLevels( ISampledImage1D const & image );
	Int textureQueryLevels( ISampledImage2D const & image );
	Int textureQueryLevels( ISampledImage3D const & image );
	Int textureQueryLevels( ISampledImageCube const & image );
	Int textureQueryLevels( ISampledImage1DArray const & image );
	Int textureQueryLevels( ISampledImage2DArray const & image );
	Int textureQueryLevels( ISampledImageCubeArray const & image );
	Int textureQueryLevels( USampledImage1D const & image );
	Int textureQueryLevels( USampledImage2D const & image );
	Int textureQueryLevels( USampledImage3D const & image );
	Int textureQueryLevels( USampledImageCube const & image );
	Int textureQueryLevels( USampledImage1DArray const & image );
	Int textureQueryLevels( USampledImage2DArray const & image );
	Int textureQueryLevels( USampledImageCubeArray const & image );
	/**@}*/
#pragma endregion
#pragma region texture
	/**
	*name
	*	texture
	*/
	/**@{*/
	Vec4 texture( SampledImage1D const & image, Float const & P );
	Vec4 texture( SampledImage2D const & image, Vec2 const & P );
	Vec4 texture( SampledImage3D const & image, Vec3 const & P );
	Vec4 texture( SampledImageCube const & image, Vec3 const & P );
	Vec4 texture( SampledImage1DArray const & image, Vec2 const & P );
	Vec4 texture( SampledImage2DArray const & image, Vec3 const & P );
	Vec4 texture( SampledImageCubeArray const & image, Vec4 const & P );
	Vec4 texture( SampledImage2DRect const & image, Vec2 const & P );
	IVec4 texture( ISampledImage1D const & image, Float const & P );
	IVec4 texture( ISampledImage2D const & image, Vec2 const & P );
	IVec4 texture( ISampledImage3D const & image, Vec3 const & P );
	IVec4 texture( ISampledImageCube const & image, Vec3 const & P );
	IVec4 texture( ISampledImage1DArray const & image, Vec2 const & P );
	IVec4 texture( ISampledImage2DArray const & image, Vec3 const & P );
	IVec4 texture( ISampledImageCubeArray const & image, Vec4 const & P );
	IVec4 texture( ISampledImage2DRect const & image, Vec2 const & P );
	UVec4 texture( USampledImage1D const & image, Float const & P );
	UVec4 texture( USampledImage2D const & image, Vec2 const & P );
	UVec4 texture( USampledImage3D const & image, Vec3 const & P );
	UVec4 texture( USampledImageCube const & image, Vec3 const & P );
	UVec4 texture( USampledImage1DArray const & image, Vec2 const & P );
	UVec4 texture( USampledImage2DArray const & image, Vec3 const & P );
	UVec4 texture( USampledImageCubeArray const & image, Vec4 const & P );
	UVec4 texture( USampledImage2DRect const & image, Vec2 const & P );
	Float texture( SampledImage1DShadow const & image, Float const & P, Float const & refZ );
	Float texture( SampledImage2DShadow const & image, Vec2 const & P, Float const & refZ );
	Float texture( SampledImageCubeShadow const & image, Vec3 const & P, Float const & refZ );
	Float texture( SampledImage1DArrayShadow const & image, Vec2 const & P, Float const & refZ );
	Float texture( SampledImage2DArrayShadow const & image, Vec3 const & P, Float const & refZ );
	Float texture( SampledImage2DRectShadow const & image, Vec2 const & P, Float const & refZ );
	Float texture( SampledImageCubeArrayShadow const & image, Vec4 const & P, Float const & refZ );
	/**@}*/
#pragma endregion
#pragma region textureBias
	/**
	*name
	*	textureBias
	*/
	/**@{*/
	Vec4 texture( SampledImage1D const & image, Float const & P, Float const & bias );
	Vec4 texture( SampledImage2D const & image, Vec2 const & P, Float const & bias );
	Vec4 texture( SampledImage3D const & image, Vec3 const & P, Float const & bias );
	Vec4 texture( SampledImageCube const & image, Vec3 const & P, Float const & bias );
	Vec4 texture( SampledImage1DArray const & image, Vec2 const & P, Float const & bias );
	Vec4 texture( SampledImage2DArray const & image, Vec3 const & P, Float const & bias );
	Vec4 texture( SampledImageCubeArray const & image, Vec4 const & P, Float const & bias );
	IVec4 texture( ISampledImage1D const & image, Float const & P, Float const & bias );
	IVec4 texture( ISampledImage2D const & image, Vec2 const & P, Float const & bias );
	IVec4 texture( ISampledImage3D const & image, Vec3 const & P, Float const & bias );
	IVec4 texture( ISampledImageCube const & image, Vec3 const & P, Float const & bias );
	IVec4 texture( ISampledImage1DArray const & image, Vec2 const & P, Float const & bias );
	IVec4 texture( ISampledImage2DArray const & image, Vec3 const & P, Float const & bias );
	IVec4 texture( ISampledImageCubeArray const & image, Vec4 const & P, Float const & bias );
	UVec4 texture( USampledImage1D const & image, Float const & P, Float const & bias );
	UVec4 texture( USampledImage2D const & image, Vec2 const & P, Float const & bias );
	UVec4 texture( USampledImage3D const & image, Vec3 const & P, Float const & bias );
	UVec4 texture( USampledImageCube const & image, Vec3 const & P, Float const & bias );
	UVec4 texture( USampledImage1DArray const & image, Vec2 const & P, Float const & bias );
	UVec4 texture( USampledImage2DArray const & image, Vec3 const & P, Float const & bias );
	UVec4 texture( USampledImageCubeArray const & image, Vec4 const & P, Float const & bias );
	Float texture( SampledImage1DShadow const & image, Float const & P, Float const & refZ, Float const & bias );
	Float texture( SampledImage2DShadow const & image, Vec2 const & P, Float const & refZ, Float const & bias );
	Float texture( SampledImageCubeShadow const & image, Vec3 const & P, Float const & refZ, Float const & bias );
	Float texture( SampledImage1DArrayShadow const & image, Vec2 const & P, Float const & refZ, Float const & bias );
	Float texture( SampledImage2DArrayShadow const & image, Vec3 const & P, Float const & refZ, Float const & bias );
	/**@}*/
#pragma endregion
#pragma region textureProj
	/**
	*name
	*	textureProj
	*/
	/**@{*/
	Vec4 textureProj( SampledImage1D const & image, Vec2 const & P );
	Vec4 textureProj( SampledImage1D const & image, Vec4 const & P );
	Vec4 textureProj( SampledImage2D const & image, Vec3 const & P );
	Vec4 textureProj( SampledImage2D const & image, Vec4 const & P );
	Vec4 textureProj( SampledImage3D const & image, Vec4 const & P );
	Vec4 textureProj( SampledImage2DRect const & image, Vec3 const & P );
	Vec4 textureProj( SampledImage2DRect const & image, Vec4 const & P );
	Vec4 textureProj( ISampledImage1D const & image, Vec2 const & P );
	Vec4 textureProj( ISampledImage1D const & image, Vec4 const & P );
	Vec4 textureProj( ISampledImage2D const & image, Vec3 const & P );
	Vec4 textureProj( ISampledImage2D const & image, Vec4 const & P );
	Vec4 textureProj( ISampledImage3D const & image, Vec4 const & P );
	Vec4 textureProj( ISampledImage2DRect const & image, Vec3 const & P );
	Vec4 textureProj( ISampledImage2DRect const & image, Vec4 const & P );
	Vec4 textureProj( USampledImage1D const & image, Vec2 const & P );
	Vec4 textureProj( USampledImage1D const & image, Vec4 const & P );
	Vec4 textureProj( USampledImage2D const & image, Vec3 const & P );
	Vec4 textureProj( USampledImage2D const & image, Vec4 const & P );
	Vec4 textureProj( USampledImage3D const & image, Vec4 const & P );
	Vec4 textureProj( USampledImage2DRect const & image, Vec3 const & P );
	Vec4 textureProj( USampledImage2DRect const & image, Vec4 const & P );
	Float textureProj( SampledImage1DShadow const & image, Vec2 const & P, Float const & refZ );
	Float textureProj( SampledImage2DShadow const & image, Vec3 const & P, Float const & refZ );
	Float textureProj( SampledImage2DRectShadow const & image, Vec3 const & P, Float const & refZ );
	/**@}*/
#pragma endregion
#pragma region textureProjBias
	/**
	*name
	*	textureProjBias
	*/
	/**@{*/
	Vec4 textureProj( SampledImage1D const & image, Vec2 const & P, Float const & bias );
	Vec4 textureProj( SampledImage1D const & image, Vec4 const & P, Float const & bias );
	Vec4 textureProj( SampledImage2D const & image, Vec3 const & P, Float const & bias );
	Vec4 textureProj( SampledImage2D const & image, Vec4 const & P, Float const & bias );
	Vec4 textureProj( SampledImage3D const & image, Vec4 const & P, Float const & bias );
	Vec4 textureProj( ISampledImage1D const & image, Vec2 const & P, Float const & bias );
	Vec4 textureProj( ISampledImage1D const & image, Vec4 const & P, Float const & bias );
	Vec4 textureProj( ISampledImage2D const & image, Vec3 const & P, Float const & bias );
	Vec4 textureProj( ISampledImage2D const & image, Vec4 const & P, Float const & bias );
	Vec4 textureProj( ISampledImage3D const & image, Vec4 const & P, Float const & bias );
	Vec4 textureProj( USampledImage1D const & image, Vec2 const & P, Float const & bias );
	Vec4 textureProj( USampledImage1D const & image, Vec4 const & P, Float const & bias );
	Vec4 textureProj( USampledImage2D const & image, Vec3 const & P, Float const & bias );
	Vec4 textureProj( USampledImage2D const & image, Vec4 const & P, Float const & bias );
	Vec4 textureProj( USampledImage3D const & image, Vec4 const & P, Float const & bias );
	Float textureProj( SampledImage1DShadow const & image, Vec2 const & P, Float const & refZ, Float const & bias );
	Float textureProj( SampledImage2DShadow const & image, Vec3 const & P, Float const & refZ, Float const & bias );
	/**@}*/
#pragma endregion
#pragma region textureLod
	/**
	*name
	*	textureLod
	*/
	/**@{*/
	Vec4 textureLod( SampledImage1D const & image, Float const & P, Float const & lod );
	Vec4 textureLod( SampledImage2D const & image, Vec2 const & P, Float const & lod );
	Vec4 textureLod( SampledImage3D const & image, Vec3 const & P, Float const & lod );
	Vec4 textureLod( SampledImageCube const & image, Vec3 const & P, Float const & lod );
	Vec4 textureLod( SampledImage1DArray const & image, Vec2 const & P, Float const & lod );
	Vec4 textureLod( SampledImage2DArray const & image, Vec3 const & P, Float const & lod );
	Vec4 textureLod( SampledImageCubeArray const & image, Vec4 const & P, Float const & lod );
	Vec4 textureLod( ISampledImage1D const & image, Float const & P, Float const & lod );
	Vec4 textureLod( ISampledImage2D const & image, Vec2 const & P, Float const & lod );
	Vec4 textureLod( ISampledImage3D const & image, Vec3 const & P, Float const & lod );
	Vec4 textureLod( ISampledImageCube const & image, Vec3 const & P, Float const & lod );
	Vec4 textureLod( ISampledImage1DArray const & image, Vec2 const & P, Float const & lod );
	Vec4 textureLod( ISampledImage2DArray const & image, Vec3 const & P, Float const & lod );
	Vec4 textureLod( ISampledImageCubeArray const & image, Vec4 const & P, Float const & lod );
	Vec4 textureLod( USampledImage1D const & image, Float const & P, Float const & lod );
	Vec4 textureLod( USampledImage2D const & image, Vec2 const & P, Float const & lod );
	Vec4 textureLod( USampledImage3D const & image, Vec3 const & P, Float const & lod );
	Vec4 textureLod( USampledImageCube const & image, Vec3 const & P, Float const & lod );
	Vec4 textureLod( USampledImage1DArray const & image, Vec2 const & P, Float const & lod );
	Vec4 textureLod( USampledImage2DArray const & image, Vec3 const & P, Float const & lod );
	Vec4 textureLod( USampledImageCubeArray const & image, Vec4 const & P, Float const & lod );
	Float textureLod( SampledImage1DShadow const & image, Float const & P, Float const & refZ, Float const & lod );
	Float textureLod( SampledImage2DShadow const & image, Vec2 const & P, Float const & refZ, Float const & lod );
	Float textureLod( SampledImage1DArrayShadow const & image, Vec2 const & P, Float const & refZ, Float const & lod );
	/**@}*/
#pragma endregion
#pragma region textureOffset
	/**
	*name
	*	textureOffset
	*/
	/**@{*/
	Vec4 textureOffset( SampledImage1D const & image, Float const & P, Int const & offset );
	Vec4 textureOffset( SampledImage2D const & image, Vec2 const & P, IVec2 const & offset );
	Vec4 textureOffset( SampledImage3D const & image, Vec3 const & P, IVec3 const & offset );
	Vec4 textureOffset( SampledImage2DRect const & image, Vec2 const & P, IVec2 const & offset );
	Vec4 textureOffset( SampledImage1DArray const & image, Vec2 const & P, Int const & offset );
	Vec4 textureOffset( SampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset );
	Vec4 textureOffset( ISampledImage1D const & image, Float const & P, Int const & offset );
	Vec4 textureOffset( ISampledImage2D const & image, Vec2 const & P, IVec2 const & offset );
	Vec4 textureOffset( ISampledImage3D const & image, Vec3 const & P, IVec3 const & offset );
	Vec4 textureOffset( ISampledImage2DRect const & image, Vec2 const & P, IVec2 const & offset );
	Vec4 textureOffset( ISampledImage1DArray const & image, Vec2 const & P, Int const & offset );
	Vec4 textureOffset( ISampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset );
	Vec4 textureOffset( USampledImage1D const & image, Float const & P, Int const & offset );
	Vec4 textureOffset( USampledImage2D const & image, Vec2 const & P, IVec2 const & offset );
	Vec4 textureOffset( USampledImage3D const & image, Vec3 const & P, IVec3 const & offset );
	Vec4 textureOffset( USampledImage2DRect const & image, Vec2 const & P, IVec2 const & offset );
	Vec4 textureOffset( USampledImage1DArray const & image, Vec2 const & P, Int const & offset );
	Vec4 textureOffset( USampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset );
	Float textureOffset( SampledImage2DRectShadow const & image, Vec2 const & P, Float const & refZ, IVec2 const & offset );
	Float textureOffset( SampledImage1DShadow const & image, Float const & P, Float const & refZ, Int const & offset );
	Float textureOffset( SampledImage2DShadow const & image, Vec2 const & P, Float const & refZ, IVec2 const & offset );
	Float textureOffset( SampledImage1DArrayShadow const & image, Vec2 const & P, Float const & refZ, Int const & offset );
	Float textureOffset( SampledImage2DArrayShadow const & image, Vec3 const & P, Float const & refZ, IVec2 const & offset );
	/**@}*/
#pragma endregion
#pragma region textureOffsetBias
	/**
	*name
	*	textureOffsetBias
	*/
	/**@{*/
	Vec4 textureOffset( SampledImage1D const & image, Float const & P, Int const & offset, Float const & bias );
	Vec4 textureOffset( SampledImage2D const & image, Vec2 const & P, IVec2 const & offset, Float const & bias );
	Vec4 textureOffset( SampledImage3D const & image, Vec3 const & P, IVec3 const & offset, Float const & bias );
	Vec4 textureOffset( SampledImage1DArray const & image, Vec2 const & P, Int const & offset, Float const & bias );
	Vec4 textureOffset( SampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset, Float const & bias );
	Vec4 textureOffset( ISampledImage1D const & image, Float const & P, Int const & offset, Float const & bias );
	Vec4 textureOffset( ISampledImage2D const & image, Vec2 const & P, IVec2 const & offset, Float const & bias );
	Vec4 textureOffset( ISampledImage3D const & image, Vec3 const & P, IVec3 const & offset, Float const & bias );
	Vec4 textureOffset( ISampledImage1DArray const & image, Vec2 const & P, Int const & offset, Float const & bias );
	Vec4 textureOffset( ISampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset, Float const & bias );
	Vec4 textureOffset( USampledImage1D const & image, Float const & P, Int const & offset, Float const & bias );
	Vec4 textureOffset( USampledImage2D const & image, Vec2 const & P, IVec2 const & offset, Float const & bias );
	Vec4 textureOffset( USampledImage3D const & image, Vec3 const & P, IVec3 const & offset, Float const & bias );
	Vec4 textureOffset( USampledImage1DArray const & image, Vec2 const & P, Int const & offset, Float const & bias );
	Vec4 textureOffset( USampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset, Float const & bias );
	Float textureOffset( SampledImage1DShadow const & image, Float const & P, Float const & refZ, Int const & offset, Float const & bias );
	Float textureOffset( SampledImage2DShadow const & image, Vec2 const & P, Float const & refZ, IVec2 const & offset, Float const & bias );
	/**@}*/
#pragma endregion
#pragma region texelFetch
	/**
	*name
	*	texelFetch
	*/
	/**@{*/
	Vec4 texelFetch( SampledImage1D const & image, Int const & P, Int const & lod );
	Vec4 texelFetch( SampledImage2D const & image, IVec2 const & P, Int const & lod );
	Vec4 texelFetch( SampledImage3D const & image, IVec3 const & P, Int const & lod );
	Vec4 texelFetch( SampledImage1DArray const & image, IVec2 const & P, Int const & lod );
	Vec4 texelFetch( SampledImage2DArray const & image, IVec3 const & P, Int const & lod );
	Vec4 texelFetch( ISampledImage1D const & image, Int const & P, Int const & lod );
	Vec4 texelFetch( ISampledImage2D const & image, IVec2 const & P, Int const & lod );
	Vec4 texelFetch( ISampledImage3D const & image, IVec3 const & P, Int const & lod );
	Vec4 texelFetch( ISampledImage1DArray const & image, IVec2 const & P, Int const & lod );
	Vec4 texelFetch( ISampledImage2DArray const & image, IVec3 const & P, Int const & lod );
	Vec4 texelFetch( USampledImage1D const & image, Int const & P, Int const & lod );
	Vec4 texelFetch( USampledImage2D const & image, IVec2 const & P, Int const & lod );
	Vec4 texelFetch( USampledImage3D const & image, IVec3 const & P, Int const & lod );
	Vec4 texelFetch( USampledImage1DArray const & image, IVec2 const & P, Int const & lod );
	Vec4 texelFetch( USampledImage2DArray const & image, IVec3 const & P, Int const & lod );
	Vec4 texelFetch( SampledImage2DRect const & image, IVec2 const & P );
	Vec4 texelFetch( SampledImageBuffer const & image, Int const & P );
	Vec4 texelFetch( ISampledImage2DRect const & image, IVec2 const & P );
	Vec4 texelFetch( ISampledImageBuffer const & image, Int const & P );
	Vec4 texelFetch( USampledImage2DRect const & image, IVec2 const & P );
	Vec4 texelFetch( USampledImageBuffer const & image, Int const & P );
	/**@}*/
#pragma endregion
#pragma region texelFetchOffset
	/**
	*name
	*	texelFetchOffset
	*/
	/**@{*/
	Vec4 texelFetchOffset( SampledImage1D const & image, Int const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( SampledImage2D const & image, IVec2 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( SampledImage3D const & image, IVec3 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( SampledImage1DArray const & image, IVec2 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( SampledImage2DArray const & image, IVec3 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( ISampledImage1D const & image, Int const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( ISampledImage2D const & image, IVec2 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( ISampledImage3D const & image, IVec3 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( ISampledImage1DArray const & image, IVec2 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( ISampledImage2DArray const & image, IVec3 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( USampledImage1D const & image, Int const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( USampledImage2D const & image, IVec2 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( USampledImage3D const & image, IVec3 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( USampledImage1DArray const & image, IVec2 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( USampledImage2DArray const & image, IVec3 const & P, Int const & lod, Int const & offset );
	Vec4 texelFetchOffset( SampledImage2DRect const & image, IVec2 const & P, Int const & offset );
	Vec4 texelFetchOffset( ISampledImage2DRect const & image, IVec2 const & P, Int const & offset );
	Vec4 texelFetchOffset( USampledImage2DRect const & image, IVec2 const & P, Int const & offset );
	/**@}*/
#pragma endregion
#pragma region textureProjOffset
	/**
	*name
	*	textureProjOffset
	*/
	/**@{*/
	Vec4 textureProjOffset( SampledImage1D const & image, Vec2 const & P, Int const & offset );
	Vec4 textureProjOffset( SampledImage1D const & image, Vec4 const & P, Int const & offset );
	Vec4 textureProjOffset( SampledImage2D const & image, Vec3 const & P, IVec2 const & offset );
	Vec4 textureProjOffset( SampledImage2D const & image, Vec4 const & P, IVec2 const & offset );
	Vec4 textureProjOffset( SampledImage3D const & image, Vec4 const & P, IVec3 const & offset );
	Vec4 textureProjOffset( SampledImage2DRect const & image, Vec3 const & P, IVec2 const & offset );
	Vec4 textureProjOffset( SampledImage2DRect const & image, Vec4 const & P, IVec2 const & offset );
	Vec4 textureProjOffset( ISampledImage1D const & image, Vec2 const & P, Int const & offset );
	Vec4 textureProjOffset( ISampledImage1D const & image, Vec4 const & P, Int const & offset );
	Vec4 textureProjOffset( ISampledImage2D const & image, Vec3 const & P, IVec2 const & offset );
	Vec4 textureProjOffset( ISampledImage2D const & image, Vec4 const & P, IVec2 const & offset );
	Vec4 textureProjOffset( ISampledImage3D const & image, Vec4 const & P, IVec3 const & offset );
	Vec4 textureProjOffset( ISampledImage2DRect const & image, Vec3 const & P, IVec2 const & offset );
	Vec4 textureProjOffset( ISampledImage2DRect const & image, Vec4 const & P, IVec2 const & offset );
	Vec4 textureProjOffset( USampledImage1D const & image, Vec2 const & P, Int const & offset );
	Vec4 textureProjOffset( USampledImage1D const & image, Vec4 const & P, Int const & offset );
	Vec4 textureProjOffset( USampledImage2D const & image, Vec3 const & P, IVec2 const & offset );
	Vec4 textureProjOffset( USampledImage2D const & image, Vec4 const & P, IVec2 const & offset );
	Vec4 textureProjOffset( USampledImage3D const & image, Vec4 const & P, IVec3 const & offset );
	Vec4 textureProjOffset( USampledImage2DRect const & image, Vec3 const & P, IVec2 const & offset );
	Vec4 textureProjOffset( USampledImage2DRect const & image, Vec4 const & P, IVec2 const & offset );
	Float textureProjOffset( SampledImage1DShadow const & image, Vec2 const & P, Float const & refZ, Int const & offset );
	Float textureProjOffset( SampledImage2DShadow const & image, Vec3 const & P, Float const & refZ, IVec2 const & offset );
	Float textureProjOffset( SampledImage2DRectShadow const & image, Vec3 const & P, Float const & refZ, IVec2 const & offset );
	/**@}*/
#pragma endregion
#pragma region textureProjOffsetBias
	/**
	*name
	*	textureProjOffsetBias
	*/
	/**@{*/
	Vec4 textureProjOffset( SampledImage1D const & image, Vec2 const & P, Int const & offset, Float const & bias );
	Vec4 textureProjOffset( SampledImage1D const & image, Vec4 const & P, Int const & offset, Float const & bias );
	Vec4 textureProjOffset( SampledImage2D const & image, Vec3 const & P, IVec2 const & offset, Float const & bias );
	Vec4 textureProjOffset( SampledImage2D const & image, Vec4 const & P, IVec2 const & offset, Float const & bias );
	Vec4 textureProjOffset( SampledImage3D const & image, Vec4 const & P, IVec3 const & offset, Float const & bias );
	Vec4 textureProjOffset( ISampledImage1D const & image, Vec2 const & P, Int const & offset, Float const & bias );
	Vec4 textureProjOffset( ISampledImage1D const & image, Vec4 const & P, Int const & offset, Float const & bias );
	Vec4 textureProjOffset( ISampledImage2D const & image, Vec3 const & P, IVec2 const & offset, Float const & bias );
	Vec4 textureProjOffset( ISampledImage2D const & image, Vec4 const & P, IVec2 const & offset, Float const & bias );
	Vec4 textureProjOffset( ISampledImage3D const & image, Vec4 const & P, IVec3 const & offset, Float const & bias );
	Vec4 textureProjOffset( USampledImage1D const & image, Vec2 const & P, Int const & offset, Float const & bias );
	Vec4 textureProjOffset( USampledImage1D const & image, Vec4 const & P, Int const & offset, Float const & bias );
	Vec4 textureProjOffset( USampledImage2D const & image, Vec3 const & P, IVec2 const & offset, Float const & bias );
	Vec4 textureProjOffset( USampledImage2D const & image, Vec4 const & P, IVec2 const & offset, Float const & bias );
	Vec4 textureProjOffset( USampledImage3D const & image, Vec4 const & P, IVec3 const & offset, Float const & bias );
	Float textureProjOffset( SampledImage1DShadow const & image, Vec2 const & P, Float const & refZ, Int const & offset, Float const & bias );
	Float textureProjOffset( SampledImage2DShadow const & image, Vec3 const & P, Float const & refZ, IVec2 const & offset, Float const & bias );
	/**@}*/
#pragma endregion
#pragma region textureLodOffset
	/**
	*name
	*	textureLodOffset
	*/
	/**@{*/
	Vec4 textureLodOffset( SampledImage1D const & image, Float const & P, Float const & lod, Int const & offset );
	Vec4 textureLodOffset( SampledImage2D const & image, Vec2 const & P, Float const & lod, IVec2 const & offset );
	Vec4 textureLodOffset( SampledImage3D const & image, Vec3 const & P, Float const & lod, IVec3 const & offset );
	Vec4 textureLodOffset( SampledImage1DArray const & image, Vec2 const & P, Float const & lod, Int const & offset );
	Vec4 textureLodOffset( SampledImage2DArray const & image, Vec3 const & P, Float const & lod, IVec2 const & offset );
	Vec4 textureLodOffset( ISampledImage1D const & image, Float const & P, Float const & lod, Int const & offset );
	Vec4 textureLodOffset( ISampledImage2D const & image, Vec2 const & P, Float const & lod, IVec2 const & offset );
	Vec4 textureLodOffset( ISampledImage3D const & image, Vec3 const & P, Float const & lod, IVec3 const & offset );
	Vec4 textureLodOffset( ISampledImage1DArray const & image, Vec2 const & P, Float const & lod, Int const & offset );
	Vec4 textureLodOffset( ISampledImage2DArray const & image, Vec3 const & P, Float const & lod, IVec2 const & offset );
	Vec4 textureLodOffset( USampledImage1D const & image, Float const & P, Float const & lod, Int const & offset );
	Vec4 textureLodOffset( USampledImage2D const & image, Vec2 const & P, Float const & lod, IVec2 const & offset );
	Vec4 textureLodOffset( USampledImage3D const & image, Vec3 const & P, Float const & lod, IVec3 const & offset );
	Vec4 textureLodOffset( USampledImage1DArray const & image, Vec2 const & P, Float const & lod, Int const & offset );
	Vec4 textureLodOffset( USampledImage2DArray const & image, Vec3 const & P, Float const & lod, IVec2 const & offset );
	Float textureLodOffset( SampledImage1DShadow const & image, Float const & P, Float const & refZ, Float const & lod, Int const & offset );
	Float textureLodOffset( SampledImage2DShadow const & image, Vec2 const & P, Float const & refZ, Float const & lod, IVec2 const & offset );
	Float textureLodOffset( SampledImage1DArrayShadow const & image, Vec2 const & P, Float const & refZ, Float const & lod, Int const & offset );
	/**@}*/
#pragma endregion
#pragma region textureProjLod
	/**
	*name
	*	textureProjLod
	*/
	/**@{*/
	Vec4 textureProjLod( SampledImage1D const & image, Vec2 const & P, Float const & lod );
	Vec4 textureProjLod( SampledImage1D const & image, Vec4 const & P, Float const & lod );
	Vec4 textureProjLod( SampledImage2D const & image, Vec3 const & P, Float const & lod );
	Vec4 textureProjLod( SampledImage2D const & image, Vec4 const & P, Float const & lod );
	Vec4 textureProjLod( SampledImage3D const & image, Vec4 const & P, Float const & lod );
	Vec4 textureProjLod( ISampledImage1D const & image, Vec2 const & P, Float const & lod );
	Vec4 textureProjLod( ISampledImage1D const & image, Vec4 const & P, Float const & lod );
	Vec4 textureProjLod( ISampledImage2D const & image, Vec3 const & P, Float const & lod );
	Vec4 textureProjLod( ISampledImage2D const & image, Vec4 const & P, Float const & lod );
	Vec4 textureProjLod( ISampledImage3D const & image, Vec4 const & P, Float const & lod );
	Vec4 textureProjLod( USampledImage1D const & image, Vec2 const & P, Float const & lod );
	Vec4 textureProjLod( USampledImage1D const & image, Vec4 const & P, Float const & lod );
	Vec4 textureProjLod( USampledImage2D const & image, Vec3 const & P, Float const & lod );
	Vec4 textureProjLod( USampledImage2D const & image, Vec4 const & P, Float const & lod );
	Vec4 textureProjLod( USampledImage3D const & image, Vec4 const & P, Float const & lod );
	Float textureProjLod( SampledImage1DShadow const & image, Vec2 const & P, Float const & refZ, Float const & lod );
	Float textureProjLod( SampledImage2DShadow const & image, Vec3 const & P, Float const & refZ, Float const & lod );
	/**@}*/
#pragma endregion
#pragma region textureProjLodOffset
	/**
	*name
	*	textureProjLodOffset
	*/
	/**@{*/
	Vec4 textureProjLodOffset( SampledImage1D const & image, Vec2 const & P, Float const & lod, Int const & offset );
	Vec4 textureProjLodOffset( SampledImage1D const & image, Vec4 const & P, Float const & lod, Int const & offset );
	Vec4 textureProjLodOffset( SampledImage2D const & image, Vec3 const & P, Float const & lod, IVec2 const & offset );
	Vec4 textureProjLodOffset( SampledImage2D const & image, Vec4 const & P, Float const & lod, IVec2 const & offset );
	Vec4 textureProjLodOffset( SampledImage3D const & image, Vec4 const & P, Float const & lod, IVec3 const & offset );
	Vec4 textureProjLodOffset( ISampledImage1D const & image, Vec2 const & P, Float const & lod, Int const & offset );
	Vec4 textureProjLodOffset( ISampledImage1D const & image, Vec4 const & P, Float const & lod, Int const & offset );
	Vec4 textureProjLodOffset( ISampledImage2D const & image, Vec3 const & P, Float const & lod, IVec2 const & offset );
	Vec4 textureProjLodOffset( ISampledImage2D const & image, Vec4 const & P, Float const & lod, IVec2 const & offset );
	Vec4 textureProjLodOffset( ISampledImage3D const & image, Vec4 const & P, Float const & lod, IVec3 const & offset );
	Vec4 textureProjLodOffset( USampledImage1D const & image, Vec2 const & P, Float const & lod, Int const & offset );
	Vec4 textureProjLodOffset( USampledImage1D const & image, Vec4 const & P, Float const & lod, Int const & offset );
	Vec4 textureProjLodOffset( USampledImage2D const & image, Vec3 const & P, Float const & lod, IVec2 const & offset );
	Vec4 textureProjLodOffset( USampledImage2D const & image, Vec4 const & P, Float const & lod, IVec2 const & offset );
	Vec4 textureProjLodOffset( USampledImage3D const & image, Vec4 const & P, Float const & lod, IVec3 const & offset );
	Float textureProjLodOffset( SampledImage1DShadow const & image, Vec2 const & P, Float const & refZ, Float const & lod, Int const & offset );
	Float textureProjLodOffset( SampledImage2DShadow const & image, Vec3 const & P, Float const & refZ, Float const & lod, IVec2 const & offset );
	/**@}*/
#pragma endregion
#pragma region textureGrad
	/**
	*name
	*	textureGrad
	*/
	/**@{*/
	Vec4 textureGrad( SampledImage1D const & image, Float const & P, Float const & dPdx, Float const & dPdy );
	Vec4 textureGrad( SampledImage2D const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy );
	Vec4 textureGrad( SampledImage3D const & image, Vec3 const & P, Vec3 const & dPdx, Vec3 const & dPdy );
	Vec4 textureGrad( SampledImageCube const & image, Vec3 const & P, Vec3 const & dPdx, Vec3 const & dPdy );
	Vec4 textureGrad( SampledImage2DRect const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy );
	Vec4 textureGrad( SampledImage1DArray const & image, Vec2 const & P, Float const & dPdx, Float const & dPdy );
	Vec4 textureGrad( SampledImage2DArray const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy );
	Vec4 textureGrad( SampledImageCubeArray const & image, Vec4 const & P, Vec3 const & dPdx, Vec3 const & dPdy );
	Vec4 textureGrad( ISampledImage1D const & image, Float const & P, Float const & dPdx, Float const & dPdy );
	Vec4 textureGrad( ISampledImage2D const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy );
	Vec4 textureGrad( ISampledImage3D const & image, Vec3 const & P, Vec3 const & dPdx, Vec3 const & dPdy );
	Vec4 textureGrad( ISampledImageCube const & image, Vec3 const & P, Vec3 const & dPdx, Vec3 const & dPdy );
	Vec4 textureGrad( ISampledImage2DRect const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy );
	Vec4 textureGrad( ISampledImage1DArray const & image, Vec2 const & P, Float const & dPdx, Float const & dPdy );
	Vec4 textureGrad( ISampledImage2DArray const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy );
	Vec4 textureGrad( ISampledImageCubeArray const & image, Vec4 const & P, Vec3 const & dPdx, Vec3 const & dPdy );
	Vec4 textureGrad( USampledImage1D const & image, Float const & P, Float const & dPdx, Float const & dPdy );
	Vec4 textureGrad( USampledImage2D const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy );
	Vec4 textureGrad( USampledImage3D const & image, Vec3 const & P, Vec3 const & dPdx, Vec3 const & dPdy );
	Vec4 textureGrad( USampledImageCube const & image, Vec3 const & P, Vec3 const & dPdx, Vec3 const & dPdy );
	Vec4 textureGrad( USampledImage2DRect const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy );
	Vec4 textureGrad( USampledImage1DArray const & image, Vec2 const & P, Float const & dPdx, Float const & dPdy );
	Vec4 textureGrad( USampledImage2DArray const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy );
	Vec4 textureGrad( USampledImageCubeArray const & image, Vec4 const & P, Vec3 const & dPdx, Vec3 const & dPdy );
	Float textureGrad( SampledImage2DRectShadow const & image, Vec2 const & P, Float const & refZ, Vec2 const & dPdx, Vec2 const & dPdy );
	Float textureGrad( SampledImage1DShadow const & image, Float const & P, Float const & refZ, Float const & dPdx, Float const & dPdy );
	Float textureGrad( SampledImage2DShadow const & image, Vec2 const & P, Float const & refZ, Vec2 const & dPdx, Vec2 const & dPdy );
	Float textureGrad( SampledImage1DArrayShadow const & image, Vec2 const & P, Float const & refZ, Float const & dPdx, Float const & dPdy );
	/**@}*/
#pragma endregion
#pragma region textureGradOffset
	/**
	*name
	*	textureGradOffset
	*/
	/**@{*/
	Vec4 textureGradOffset( SampledImage1D const & image, Float const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureGradOffset( SampledImage2D const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureGradOffset( SampledImage3D const & image, Vec3 const & P, Vec3 const & dPdx, Vec3 const & dPdy, IVec3 const & offset );
	Vec4 textureGradOffset( SampledImage2DRect const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureGradOffset( SampledImage1DArray const & image, Vec2 const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureGradOffset( SampledImage2DArray const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureGradOffset( ISampledImage1D const & image, Float const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureGradOffset( ISampledImage2D const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureGradOffset( ISampledImage3D const & image, Vec3 const & P, Vec3 const & dPdx, Vec3 const & dPdy, IVec3 const & offset );
	Vec4 textureGradOffset( ISampledImage2DRect const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureGradOffset( ISampledImage1DArray const & image, Vec2 const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureGradOffset( ISampledImage2DArray const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureGradOffset( USampledImage1D const & image, Float const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureGradOffset( USampledImage2D const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureGradOffset( USampledImage3D const & image, Vec3 const & P, Vec3 const & dPdx, Vec3 const & dPdy, IVec3 const & offset );
	Vec4 textureGradOffset( USampledImage2DRect const & image, Vec2 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureGradOffset( USampledImage1DArray const & image, Vec2 const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureGradOffset( USampledImage2DArray const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Float textureGradOffset( SampledImage2DRectShadow const & image, Vec2 const & P, Float const & refZ, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Float textureGradOffset( SampledImage1DShadow const & image, Float const & P, Float const & refZ, Float const & dPdx, Float const & dPdy, Int const & offset );
	Float textureGradOffset( SampledImage2DShadow const & image, Vec2 const & P, Float const & refZ, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Float textureGradOffset( SampledImage1DArrayShadow const & image, Vec2 const & P, Float const & refZ, Float const & dPdx, Float const & dPdy, Int const & offset );
	Float textureGradOffset( SampledImage2DArrayShadow const & image, Vec3 const & P, Float const & refZ, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	/**@}*/
#pragma endregion
#pragma region textureProjGrad
	/**
	*name
	*	textureProjGrad
	*/
	/**@{*/
	Vec4 textureProjGrad( SampledImage1D const & image, Vec2 const & P, Float const & pDx, Float const & pDy );
	Vec4 textureProjGrad( SampledImage1D const & image, Vec4 const & P, Float const & pDx, Float const & pDy );
	Vec4 textureProjGrad( SampledImage2D const & image, Vec3 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Vec4 textureProjGrad( SampledImage2D const & image, Vec4 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Vec4 textureProjGrad( SampledImage3D const & image, Vec4 const & P, Vec3 const & pDx, Vec3 const & pDy );
	Vec4 textureProjGrad( SampledImage2DRect const & image, Vec3 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Vec4 textureProjGrad( SampledImage2DRect const & image, Vec4 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Vec4 textureProjGrad( ISampledImage1D const & image, Vec2 const & P, Float const & pDx, Float const & pDy );
	Vec4 textureProjGrad( ISampledImage1D const & image, Vec4 const & P, Float const & pDx, Float const & pDy );
	Vec4 textureProjGrad( ISampledImage2D const & image, Vec3 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Vec4 textureProjGrad( ISampledImage2D const & image, Vec4 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Vec4 textureProjGrad( ISampledImage3D const & image, Vec4 const & P, Vec3 const & pDx, Vec3 const & pDy );
	Vec4 textureProjGrad( ISampledImage2DRect const & image, Vec3 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Vec4 textureProjGrad( ISampledImage2DRect const & image, Vec4 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Vec4 textureProjGrad( USampledImage1D const & image, Vec2 const & P, Float const & pDx, Float const & pDy );
	Vec4 textureProjGrad( USampledImage1D const & image, Vec4 const & P, Float const & pDx, Float const & pDy );
	Vec4 textureProjGrad( USampledImage2D const & image, Vec3 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Vec4 textureProjGrad( USampledImage2D const & image, Vec4 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Vec4 textureProjGrad( USampledImage3D const & image, Vec4 const & P, Vec3 const & pDx, Vec3 const & pDy );
	Vec4 textureProjGrad( USampledImage2DRect const & image, Vec3 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Vec4 textureProjGrad( USampledImage2DRect const & image, Vec4 const & P, Vec2 const & pDx, Vec2 const & pDy );
	Float textureProjGrad( SampledImage1DShadow const & image, Vec2 const & P, Float const & refZ, Float const & pDx, Float const & pDy );
	Float textureProjGrad( SampledImage2DShadow const & image, Vec3 const & P, Float const & refZ, Vec2 const & pDx, Vec2 const & pDy );
	Float textureProjGrad( SampledImage2DRectShadow const & image, Vec3 const & P, Float const & refZ, Vec2 const & pDx, Vec2 const & pDy );
	/**@}*/
#pragma endregion
#pragma region textureProjGradOffset
	/**
	*name
	*	textureProjGradOffset
	*/
	/**@{*/
	Vec4 textureProjGradOffset( SampledImage1D const & image, Vec2 const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureProjGradOffset( SampledImage1D const & image, Vec4 const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureProjGradOffset( SampledImage2D const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureProjGradOffset( SampledImage2D const & image, Vec4 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureProjGradOffset( SampledImage3D const & image, Vec4 const & P, Vec3 const & dPdx, Vec3 const & dPdy, IVec3 const & offset );
	Vec4 textureProjGradOffset( SampledImage2DRect const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureProjGradOffset( SampledImage2DRect const & image, Vec4 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureProjGradOffset( ISampledImage1D const & image, Vec2 const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureProjGradOffset( ISampledImage1D const & image, Vec4 const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureProjGradOffset( ISampledImage2D const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureProjGradOffset( ISampledImage2D const & image, Vec4 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureProjGradOffset( ISampledImage3D const & image, Vec4 const & P, Vec3 const & dPdx, Vec3 const & dPdy, IVec3 const & offset );
	Vec4 textureProjGradOffset( ISampledImage2DRect const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureProjGradOffset( ISampledImage2DRect const & image, Vec4 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureProjGradOffset( USampledImage1D const & image, Vec2 const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureProjGradOffset( USampledImage1D const & image, Vec4 const & P, Float const & dPdx, Float const & dPdy, Int const & offset );
	Vec4 textureProjGradOffset( USampledImage2D const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureProjGradOffset( USampledImage2D const & image, Vec4 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureProjGradOffset( USampledImage3D const & image, Vec4 const & P, Vec3 const & dPdx, Vec3 const & dPdy, IVec3 const & offset );
	Vec4 textureProjGradOffset( USampledImage2DRect const & image, Vec3 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Vec4 textureProjGradOffset( USampledImage2DRect const & image, Vec4 const & P, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Float textureProjGradOffset( SampledImage1DShadow const & image, Vec2 const & P, Float const & refZ, Float const & dPdx, Float const & dPdy, Int const & offset );
	Float textureProjGradOffset( SampledImage2DShadow const & image, Vec3 const & P, Float const & refZ, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	Float textureProjGradOffset( SampledImage2DRectShadow const & image, Vec3 const & P, Float const & refZ, Vec2 const & dPdx, Vec2 const & dPdy, IVec2 const & offset );
	/**@}*/
#pragma endregion
#pragma region textureGather
	/**
	*name
	*	textureGather
	*/
	/**@{*/
	Vec4 textureGather( SampledImage2D const & image, Vec2 const & P );
	Vec4 textureGather( SampledImage2DArray const & image, Vec3 const & P );
	Vec4 textureGather( SampledImageCube const & image, Vec3 const & P );
	Vec4 textureGather( SampledImageCubeArray const & image, Vec4 const & P );
	Vec4 textureGather( SampledImage2DRect const & image, Vec3 const & P );
	IVec4 textureGather( ISampledImage2D const & image, Vec2 const & P );
	IVec4 textureGather( ISampledImage2DArray const & image, Vec3 const & P );
	IVec4 textureGather( ISampledImageCube const & image, Vec3 const & P );
	IVec4 textureGather( ISampledImageCubeArray const & image, Vec4 const & P );
	IVec4 textureGather( ISampledImage2DRect const & image, Vec3 const & P );
	UVec4 textureGather( USampledImage2D const & image, Vec2 const & P );
	UVec4 textureGather( USampledImage2DArray const & image, Vec3 const & P );
	UVec4 textureGather( USampledImageCube const & image, Vec3 const & P );
	UVec4 textureGather( USampledImageCubeArray const & image, Vec4 const & P );
	UVec4 textureGather( USampledImage2DRect const & image, Vec3 const & P );
	Vec4 textureGather( SampledImage2DShadow const & image, Vec2 const & P, Float const & refZ );
	Vec4 textureGather( SampledImage2DArrayShadow const & image, Vec3 const & P, Float const & refZ );
	Vec4 textureGather( SampledImageCubeShadow const & image, Vec3 const & P, Float const & refZ );
	Vec4 textureGather( SampledImageCubeArrayShadow const & image, Vec4 const & P, Float const & refZ );
	Vec4 textureGather( SampledImage2DRectShadow const & image, Vec3 const & P, Float const & refZ );
	/**@}*/
#pragma endregion
#pragma region textureGatherComp
	/**
	*name
	*	textureGatherComp
	*/
	/**@{*/
	Vec4 textureGather( SampledImage2D const & image, Vec2 const & P, Int const & comp );
	Vec4 textureGather( SampledImage2DArray const & image, Vec3 const & P, Int const & comp );
	Vec4 textureGather( SampledImageCube const & image, Vec3 const & P, Int const & comp );
	Vec4 textureGather( SampledImageCubeArray const & image, Vec4 const & P, Int const & comp );
	Vec4 textureGather( SampledImage2DRect const & image, Vec3 const & P, Int const & comp );
	IVec4 textureGather( ISampledImage2D const & image, Vec2 const & P, Int const & comp );
	IVec4 textureGather( ISampledImage2DArray const & image, Vec3 const & P, Int const & comp );
	IVec4 textureGather( ISampledImageCube const & image, Vec3 const & P, Int const & comp );
	IVec4 textureGather( ISampledImageCubeArray const & image, Vec4 const & P, Int const & comp );
	IVec4 textureGather( ISampledImage2DRect const & image, Vec3 const & P, Int const & comp );
	UVec4 textureGather( USampledImage2D const & image, Vec2 const & P, Int const & comp );
	UVec4 textureGather( USampledImage2DArray const & image, Vec3 const & P, Int const & comp );
	UVec4 textureGather( USampledImageCube const & image, Vec3 const & P, Int const & comp );
	UVec4 textureGather( USampledImageCubeArray const & image, Vec4 const & P, Int const & comp );
	UVec4 textureGather( USampledImage2DRect const & image, Vec3 const & P, Int const & comp );
	/**@}*/
#pragma endregion
#pragma region textureGatherOffset
	/**
	*name
	*	textureGatherOffset
	*/
	/**@{*/
	Vec4 textureGatherOffset( SampledImage2D const & image, Vec2 const & P, IVec2 const & offset );
	Vec4 textureGatherOffset( SampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset );
	Vec4 textureGatherOffset( SampledImage2DRect const & image, Vec3 const & P, IVec2 const & offset );
	IVec4 textureGatherOffset( ISampledImage2D const & image, Vec2 const & P, IVec2 const & offset );
	IVec4 textureGatherOffset( ISampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset );
	IVec4 textureGatherOffset( ISampledImage2DRect const & image, Vec3 const & P, IVec2 const & offset );
	UVec4 textureGatherOffset( USampledImage2D const & image, Vec2 const & P, IVec2 const & offset );
	UVec4 textureGatherOffset( USampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset );
	UVec4 textureGatherOffset( USampledImage2DRect const & image, Vec3 const & P, IVec2 const & offset );
	Vec4 textureGatherOffset( SampledImage2DShadow const & image, Vec2 const & P, Float const & refZ, IVec2 const & offset );
	Vec4 textureGatherOffset( SampledImage2DArrayShadow const & image, Vec3 const & P, Float const & refZ, IVec2 const & offset );
	Vec4 textureGatherOffset( SampledImage2DRectShadow const & image, Vec3 const & P, Float const & refZ, IVec2 const & offset );
	/**@}*/
#pragma endregion
#pragma region textureGatherOffsetComp
	/**
	*name
	*	textureGatherOffsetComp
	*/
	/**@{*/
	Vec4 textureGatherOffset( SampledImage2D const & image, Vec2 const & P, IVec2 const & offset, Int const & comp );
	Vec4 textureGatherOffset( SampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset, Int const & comp );
	Vec4 textureGatherOffset( SampledImage2DRect const & image, Vec3 const & P, IVec2 const & offset, Int const & comp );
	IVec4 textureGatherOffset( ISampledImage2D const & image, Vec2 const & P, IVec2 const & offset, Int const & comp );
	IVec4 textureGatherOffset( ISampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset, Int const & comp );
	IVec4 textureGatherOffset( ISampledImage2DRect const & image, Vec3 const & P, IVec2 const & offset, Int const & comp );
	UVec4 textureGatherOffset( USampledImage2D const & image, Vec2 const & P, IVec2 const & offset, Int const & comp );
	UVec4 textureGatherOffset( USampledImage2DArray const & image, Vec3 const & P, IVec2 const & offset, Int const & comp );
	UVec4 textureGatherOffset( USampledImage2DRect const & image, Vec3 const & P, IVec2 const & offset, Int const & comp );
	/**@}*/
#pragma endregion
#pragma region textureGatherOffsets
	/**
	*name
	*	textureGatherOffsets
	*/
	/**@{*/
	Vec4 textureGatherOffsets( SampledImage2D const & image, Vec2 const & P, Array< IVec2 > const & offsets );
	Vec4 textureGatherOffsets( SampledImage2DArray const & image, Vec3 const & P, Array< IVec2 > const & offsets );
	Vec4 textureGatherOffsets( SampledImage2DRect const & image, Vec3 const & P, Array< IVec2 > const & offsets );
	IVec4 textureGatherOffsets( ISampledImage2D const & image, Vec2 const & P, Array< IVec2 > const & offsets );
	IVec4 textureGatherOffsets( ISampledImage2DArray const & image, Vec3 const & P, Array< IVec2 > const & offsets );
	IVec4 textureGatherOffsets( ISampledImage2DRect const & image, Vec3 const & P, Array< IVec2 > const & offsets );
	UVec4 textureGatherOffsets( USampledImage2D const & image, Vec2 const & P, Array< IVec2 > const & offsets );
	UVec4 textureGatherOffsets( USampledImage2DArray const & image, Vec3 const & P, Array< IVec2 > const & offsets );
	UVec4 textureGatherOffsets( USampledImage2DRect const & image, Vec3 const & P, Array< IVec2 > const & offsets );
	Vec4 textureGatherOffsets( SampledImage2DShadow const & image, Vec2 const & P, Float const & refZ, Array< IVec2 > const & offsets );
	Vec4 textureGatherOffsets( SampledImage2DArrayShadow const & image, Vec3 const & P, Float const & refZ, Array< IVec2 > const & offsets );
	Vec4 textureGatherOffsets( SampledImage2DRectShadow const & image, Vec3 const & P, Float const & refZ, Array< IVec2 > const & offsets );
	/**@}*/
#pragma endregion
#pragma region textureGatherOffsetsComp
	/**
	*name
	*	textureGatherOffsetsComp
	*/
	/**@{*/
	Vec4 textureGatherOffsets( SampledImage2D const & image, Vec2 const & P, Array< IVec2 > const & offsets, Int const & comp );
	Vec4 textureGatherOffsets( SampledImage2DArray const & image, Vec3 const & P, Array< IVec2 > const & offsets, Int const & comp );
	Vec4 textureGatherOffsets( SampledImage2DRect const & image, Vec3 const & P, Array< IVec2 > const & offsets, Int const & comp );
	IVec4 textureGatherOffsets( ISampledImage2D const & image, Vec2 const & P, Array< IVec2 > const & offsets, Int const & comp );
	IVec4 textureGatherOffsets( ISampledImage2DArray const & image, Vec3 const & P, Array< IVec2 > const & offsets, Int const & comp );
	IVec4 textureGatherOffsets( ISampledImage2DRect const & image, Vec3 const & P, Array< IVec2 > const & offsets, Int const & comp );
	UVec4 textureGatherOffsets( USampledImage2D const & image, Vec2 const & P, Array< IVec2 > const & offsets, Int const & comp );
	UVec4 textureGatherOffsets( USampledImage2DArray const & image, Vec3 const & P, Array< IVec2 > const & offsets, Int const & comp );
	UVec4 textureGatherOffsets( USampledImage2DRect const & image, Vec3 const & P, Array< IVec2 > const & offsets, Int const & comp );
	/**@}*/
#pragma endregion
}

#endif
