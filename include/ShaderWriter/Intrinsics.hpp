/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Intrinsics_H___
#define ___Writer_Intrinsics_H___
#pragma once

#include "Function.hpp"
#include "FunctionParam.hpp"
#include "Bool.hpp"
#include "OptionalMat2.hpp"
#include "OptionalMat3.hpp"
#include "OptionalMat4.hpp"
#include "Sampler.hpp"

namespace sdw
{
	template< typename ... ValuesT >
	inline Vec2 vec2( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline Vec3 vec3( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline Vec4 vec4( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline IVec2 ivec2( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline IVec3 ivec3( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline IVec4 ivec4( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline UVec2 uvec2( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline UVec3 uvec3( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline UVec4 uvec4( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline BVec2 bvec2( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline BVec3 bvec3( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline BVec4 bvec4( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline Mat2 mat2( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline Mat3 mat3( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline Mat4 mat4( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline IMat2 imat2( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline IMat3 imat3( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline IMat4 imat4( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline UMat2 umat2( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline UMat3 umat3( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline UMat4 umat4( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline BMat2 bmat2( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline BMat3 bmat3( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline BMat4 bmat4( Value const & value
		, ValuesT const & ... values );

	template< typename ... ValuesT >
	inline Float dot( Value const & value
		, ValuesT const & ... values );
	template< typename ... ValuesT >
	inline Float inversesqrt( Value const & value
		, ValuesT const & ... values );
	template< typename ValueT
		, typename ... ValuesT >
	inline ValueT cross( ValueT const & value
		, ValuesT const & ... values );
	template< typename ValueT
		, typename ... ValuesT >
	inline ValueT clamp( ValueT const & value
		, ValuesT const & ... values );
	template< typename ValueT
		, typename ... ValuesT >
	inline ValueT min( ValueT const & value
		, ValuesT const & ... values );
	template< typename ValueT
		, typename ... ValuesT >
	inline ValueT max( ValueT const & value
		, ValuesT const & ... values );
	template< typename ValueT
		, typename ... ValuesT >
	inline ValueT mix( ValueT const & value
		, ValuesT const & ... values );
	template< typename ValueT
		, typename ... ValuesT >
	inline ValueT reflect( Value const & value
		, ValuesT const & ... values );
	template< typename ValueT >
	inline ValueT sqrt( ValueT const & value );
	template< typename ValueT >
	inline ValueT pow( ValueT const & x
		, ValueT const & y );
	template< typename ValueT >
	inline ValueT pow( ValueT const & x
		, Optional< ValueT >
	const & y );
	template< typename ValueT >
	inline ValueT pow2( ValueT const & p );
	template< typename ValueT >
	inline ValueT neg( ValueT const & value );
	template< typename ValueT >
	inline ValueT log( ValueT const & value );
	template< typename ValueT >
	inline ValueT exp( ValueT const & value );
	template< typename ValueT >
	inline ValueT log2( ValueT const & value );
	template< typename ValueT >
	inline ValueT exp2( ValueT const & value );
	template< typename ValueT >
	inline ValueT tan( ValueT const & value );
	template< typename ValueT >
	inline ValueT sin( ValueT const & value );
	template< typename ValueT >
	inline ValueT cos( ValueT const & value );
	template< typename ValueT >
	inline ValueT atan( ValueT const & y
		, ValueT const & x );
	template< typename ValueT >
	inline ValueT atan( ValueT const & value );
	template< typename ValueT >
	inline ValueT asin( ValueT const & value );
	template< typename ValueT >
	inline ValueT acos( ValueT const & value );
	template< typename ValueT >
	inline ValueT fma( ValueT const & a
		, ValueT const & b
		, ValueT const & c );
	template< typename ValueT >
	inline ValueT normalize( ValueT const & value );
#if Writer_UseSwizzle
	template< typename Input, typename Output >
	inline Output neg( Swizzle< Input, Output > const & value );
	template< typename Input, typename Output >
	inline Output normalize( Swizzle< Input, Output > const & value );
#endif
	template< typename ValueT >
	inline ValueT transpose( ValueT const & value );
	template< typename ValueT >
	inline ValueT inverse( ValueT const & value );
	template< typename ValueT >
	inline ValueT abs( ValueT const & value );
	template< typename ValueT >
	inline ValueT isinf( ValueT const & value );
	template< typename ValueA
		, typename ValueB >
	ValueB smoothstep( ValueA const & edge0
		, ValueA const & edge1
		, ValueB const & x );
	template< typename ValueT >
	inline ValueT dFdx( ValueT const & value );
	template< typename ValueT >
	inline ValueT dFdy( ValueT const & value );
	template< typename ValueT >
	inline ValueT dFdxCoarse( ValueT const & value );
	template< typename ValueT >
	inline ValueT dFdyCoarse( ValueT const & value );
	template< typename ValueT >
	inline ValueT dFdxFine( ValueT const & value );
	template< typename ValueT >
	inline ValueT dFdyFine( ValueT const & value );
	template< typename ValueT >
	inline ValueT sign( ValueT const & value );
	template< typename ValueT >
	inline ValueT mod( ValueT const & x
		, ValueT const & y );
	template< typename ValueT >
	inline ValueT mod( ValueT const & x
		, Float const & y );
	template< typename ValueT >
	inline ValueT fract( ValueT const & value );
	template< typename ValueT >
	inline ValueT floor( ValueT const & value );
	template< typename ValueT >
	inline ValueT trunc( ValueT const & value );
	template< typename ValueT >
	inline ValueT round( ValueT const & value );
	template< typename ValueE
		, typename ValueX >
	inline ValueE step( ValueE const & edge
		, ValueX const & x );

	Int bitfieldReverse( Int const & value );
	UInt bitfieldReverse( UInt const & value );
	Int findMSB( Int value );
	Int findMSB( UInt value );
	Int textureSize( Sampler1D const & sampler
		, Int const lod );
	IVec2 textureSize( Sampler2D const & sampler
		, Int const & lod );
	IVec3 textureSize( Sampler3D const & sampler
		, Int const & lod );
	IVec2 textureSize( SamplerCube const & sampler
		, Int const & lod );
	IVec2 textureSize( Sampler1DArray const & sampler
		, Int const lod );
	IVec3 textureSize( Sampler2DArray const & sampler
		, Int const & lod );
	IVec3 textureSize( SamplerCubeArray const & sampler
		, Int const & lod );
	Int textureSize( Sampler1DShadow const & sampler
		, Int const lod );
	IVec2 textureSize( Sampler2DShadow const & sampler
		, Int const & lod );
	IVec2 textureSize( SamplerCubeShadow const & sampler
		, Int const & lod );
	IVec2 textureSize( Sampler1DArrayShadow const & sampler
		, Int const lod );
	IVec3 textureSize( Sampler2DArrayShadow const & sampler
		, Int const & lod );
	IVec3 textureSize( SamplerCubeArrayShadow const & sampler
		, Int const & lod );
	Vec4 textureGather( Sampler2D const & sampler
		, Vec2 const & value );
	Vec4 textureGather( Sampler2DArray const & sampler
		, Vec3 const & value );
	Vec4 textureGather( SamplerCube const & sampler
		, Vec3 const & value );
	Vec4 textureGather( SamplerCubeArray const & sampler
		, Vec4 const & value );
	Vec4 textureGather( Sampler2D const & sampler
		, Vec2 const & value
		, Int const & comp );
	Vec4 textureGather( Sampler2DArray const & sampler
		, Vec3 const & value
		, Int const & comp );
	Vec4 textureGather( SamplerCube const & sampler
		, Vec3 const & value
		, Int const & comp );
	Vec4 textureGather( SamplerCubeArray const & sampler
		, Vec4 const & value
		, Int const & comp );
	Vec4 textureGather( Sampler2DShadow const & sampler
		, Vec3 const & value
		, Float const & refZ );
	Vec4 textureGather( Sampler2DArrayShadow const & sampler
		, Vec3 const & value
		, Float const & refZ );
	Vec4 textureGather( SamplerCubeShadow const & sampler
		, Vec3 const & value
		, Float const & refZ );
	Vec4 textureGather( SamplerCubeArrayShadow const & sampler
		, Vec4 const & value
		, Float const & refZ );
	Vec4 texture( Sampler1D const & sampler
		, Float const & value );
	Vec4 texture( Sampler1D const & sampler
		, Float const & value
		, Float const & lod );
	Vec4 texture( Sampler2D const & sampler
		, Vec2 const & value );
	Vec4 texture( Sampler2D const & sampler
		, Vec2 const & value
		, Float const & lod );
	Vec4 texture( Sampler3D const & sampler
		, Vec3 const & value );
	Vec4 texture( Sampler3D const & sampler
		, Vec3 const & value
		, Float const & lod );
	Vec4 texture( SamplerCube const & sampler
		, Vec3 const & value );
	Vec4 texture( SamplerCube const & sampler
		, Vec3 const & value
		, Float const & lod );
	Vec4 textureOffset( Sampler1D const & sampler
		, Float const & value
		, Int const offset );
	Vec4 textureOffset( Sampler1D const & sampler
		, Float const & value
		, Int const offset
		, Float const & lod );
	Vec4 textureOffset( Sampler2D const & sampler
		, Vec2 const & value
		, IVec2 const offset );
	Vec4 textureOffset( Sampler2D const & sampler
		, Vec2 const & value
		, IVec2 const offset
		, Float const & lod );
	Vec4 textureOffset( Sampler3D const & sampler
		, Vec3 const & value
		, IVec3 const offset );
	Vec4 textureOffset( Sampler3D const & sampler
		, Vec3 const & value
		, IVec3 const offset
		, Float const & lod );
	Vec4 textureLodOffset( Sampler1D const & sampler
		, Float const & value
		, Float const & lod
		, Int const offset );
	Vec4 textureLodOffset( Sampler2D const & sampler
		, Vec2 const & value
		, Float const & lod
		, IVec2 const offset );
	Vec4 textureLodOffset( Sampler3D const & sampler
		, Vec3 const & value
		, Float const & lod
		, IVec3 const offset );
	Vec4 texelFetch( SamplerBuffer const & sampler
		, Value const & value );
	Vec4 texelFetch( Sampler1D const & sampler
		, Value const & value
		, Int const & modif );
	Vec4 texelFetch( Sampler2D const & sampler
		, Value const & value
		, Int const & modif );
	Vec4 texelFetch( Sampler3D const & sampler
		, Value const & value
		, Int const & modif );
	Vec4 texture( Sampler1DArray const & sampler
		, Vec2 const & value );
	Vec4 texture( Sampler1DArray const & sampler
		, Vec2 const & value
		, Float const & lod );
	Vec4 texture( Sampler2DArray const & sampler
		, Vec3 const & value );
	Vec4 texture( Sampler2DArray const & sampler
		, Vec3 const & value
		, Float const & lod );
	Vec4 texture( SamplerCubeArray const & sampler
		, Vec4 const & value );
	Vec4 texture( SamplerCubeArray const & sampler
		, Vec4 const & value
		, Float const & lod );
	Vec4 textureOffset( Sampler1DArray const & sampler
		, Vec2 const & value
		, Int const offset );
	Vec4 textureOffset( Sampler1DArray const & sampler
		, Vec2 const & value
		, Int const offset
		, Float const & lod );
	Vec4 textureOffset( Sampler2DArray const & sampler
		, Vec3 const & value
		, IVec2 const offset );
	Vec4 textureOffset( Sampler2DArray const & sampler
		, Vec3 const & value
		, IVec2 const offset
		, Float const & lod );
	Vec4 textureLodOffset( Sampler1DArray const & sampler
		, Vec2 const & value
		, Float const & lod
		, Int const offset );
	Vec4 textureLodOffset( Sampler2DArray const & sampler
		, Vec3 const & value
		, Float const & lod
		, IVec2 const offset );
	Float texture( Sampler1DShadow const & sampler
		, Vec2 const & value );
	Float texture( Sampler1DShadow const & sampler
		, Vec2 const & value
		, Float const & lod );
	Float texture( Sampler2DShadow const & sampler
		, Vec3 const & value );
	Float texture( Sampler2DShadow const & sampler
		, Vec3 const & value
		, Float const & lod );
	Float texture( SamplerCubeShadow const & sampler
		, Vec4 const & value );
	Float texture( SamplerCubeShadow const & sampler
		, Vec4 const & value
		, Float const & lod );
	Float textureOffset( Sampler1DShadow const & sampler
		, Vec2 const & value
		, Int const offset );
	Float textureOffset( Sampler1DShadow const & sampler
		, Vec2 const & value
		, Int const offset
		, Float const & lod );
	Float textureOffset( Sampler2DShadow const & sampler
		, Vec3 const & value
		, IVec2 const offset );
	Float textureOffset( Sampler2DShadow const & sampler
		, Vec3 const & value
		, IVec2 const offset
		, Float const & lod );
	Float textureLodOffset( Sampler1DShadow const & sampler
		, Vec2 const & value
		, Float const & lod
		, Int const offset );
	Float textureLodOffset( Sampler2DShadow const & sampler
		, Vec3 const & value
		, Float const & lod
		, IVec2 const offset );
	Float texture( Sampler1DArrayShadow const & sampler
		, Vec3 const & value );
	Float texture( Sampler1DArrayShadow const & sampler
		, Vec3 const & value
		, Float const & lod );
	Float texture( Sampler2DArrayShadow const & sampler
		, Vec4 const & value );
	Float texture( Sampler2DArrayShadow const & sampler
		, Vec4 const & value
		, Float const & lod );
	Float texture( SamplerCubeArrayShadow const & sampler
		, Vec4 const & value
		, Float const & layer );
	Float texture( SamplerCubeArrayShadow const & sampler
		, Vec4 const & value
		, Float const & layer
		, Float const & lod );
	Float textureOffset( Sampler1DArrayShadow const & sampler
		, Vec3 const & value
		, Int const offset );
	Float textureOffset( Sampler1DArrayShadow const & sampler
		, Vec3 const & value
		, Int const offset
		, Float const & lod );
	Float textureOffset( Sampler2DArrayShadow const & sampler
		, Vec4 const & value
		, IVec2 const offset );
	Float textureOffset( Sampler2DArrayShadow const & sampler
		, Vec4 const & value
		, IVec2 const offset
		, Float const & lod );
	Float textureLodOffset( Sampler1DArrayShadow const & sampler
		, Vec3 const & value
		, Float const & lod
		, Int const offset );
	Float textureLodOffset( Sampler2DArrayShadow const & sampler
		, Vec4 const & value
		, Float const & lod
		, IVec2 const offset );
	Vec2 reflect( Vec2 const & a
		, Vec2 const & b );
	Vec3 reflect( Vec3 const & a
		, Vec3 const & b );
	Vec4 reflect( Vec4 const & a
		, Vec4 const & b );
	Vec2 refract( Vec2 const & a
		, Vec2 const & b
		, Float const & r );
	Vec3 refract( Vec3 const & a
		, Vec3 const & b
		, Float const & r );
	Vec4 refract( Vec4 const & a
		, Vec4 const & b
		, Float const & r );
	Float length( Value const & value );
	Float distance( Value const & a
		, Value const & b );
	Float radians( Value const & value );
	Float cos( Value const & value );
	Float sin( Value const & value );
	Float tan( Value const & value );
	Optional< Int > textureSize( Optional< Sampler1D > const & sampler
		, Int const lod );
	Optional< IVec2 > textureSize( Optional< Sampler2D > const & sampler
		, Int const & lod );
	Optional< IVec3 > textureSize( Optional< Sampler3D > const & sampler
		, Int const & lod );
	Optional< IVec2 > textureSize( Optional< SamplerCube > const & sampler
		, Int const & lod );
	Optional< IVec2 > textureSize( Optional< Sampler1DArray > const & sampler
		, Int const lod );
	Optional< IVec3 > textureSize( Optional< Sampler2DArray > const & sampler
		, Int const & lod );
	Optional< IVec3 > textureSize( Optional< SamplerCubeArray > const & sampler
		, Int const & lod );
	Optional< Int > textureSize( Optional< Sampler1DShadow > const & sampler
		, Int const lod );
	Optional< IVec2 > textureSize( Optional< Sampler2DShadow > const & sampler
		, Int const & lod );
	Optional< IVec2 > textureSize( Optional< SamplerCubeShadow > const & sampler
		, Int const & lod );
	Optional< IVec2 > textureSize( Optional< Sampler1DArrayShadow > const & sampler
		, Int const lod );
	Optional< IVec3 > textureSize( Optional< Sampler2DArrayShadow > const & sampler
		, Int const & lod );
	Optional< IVec3 > textureSize( Optional< SamplerCubeArrayShadow > const & sampler
		, Int const & lod );
	Optional< Vec4 > texture( Optional< Sampler1D > const & sampler
		, Float const & value );
	Optional< Vec4 > texture( Optional< Sampler1D > const & sampler
		, Float const & value
		, Float const & lod );
	Optional< Vec4 > texture( Optional< Sampler2D > const & sampler
		, Vec2 const & value );
	Optional< Vec4 > texture( Optional< Sampler2D > const & sampler
		, Vec2 const & value
		, Float const & lod );
	Optional< Vec4 > texture( Optional< Sampler3D > const & sampler
		, Vec3 const & value );
	Optional< Vec4 > texture( Optional< Sampler3D > const & sampler
		, Vec3 const & value
		, Float const & lod );
	Optional< Vec4 > texture( Optional< SamplerCube > const & sampler
		, Vec3 const & value );
	Optional< Vec4 > texture( Optional< SamplerCube > const & sampler
		, Vec3 const & value
		, Float const & lod );
	Optional< Vec4 > textureOffset( Optional< Sampler1D > const & sampler
		, Float const & value
		, Int const offset );
	Optional< Vec4 > textureOffset( Optional< Sampler1D > const & sampler
		, Float const & value
		, Int const offset
		, Float const & lod );
	Optional< Vec4 > textureOffset( Optional< Sampler2D > const & sampler
		, Vec2 const & value
		, IVec2 const offset );
	Optional< Vec4 > textureOffset( Optional< Sampler2D > const & sampler
		, Vec2 const & value
		, IVec2 const offset
		, Float const & lod );
	Optional< Vec4 > textureOffset( Optional< Sampler3D > const & sampler
		, Vec3 const & value
		, IVec3 const offset );
	Optional< Vec4 > textureOffset( Optional< Sampler3D > const & sampler
		, Vec3 const & value
		, IVec3 const offset
		, Float const & lod );
	Optional< Vec4 > textureLodOffset( Optional< Sampler1D > const & sampler
		, Vec2 const & value
		, Float const & lod
		, Int const offset );
	Optional< Vec4 > textureLodOffset( Optional< Sampler2D > const & sampler
		, Vec2 const & value
		, Float const & lod
		, IVec2 const offset );
	Optional< Vec4 > textureLodOffset( Optional< Sampler3D > const & sampler
		, Vec3 const & value
		, Float const & lod
		, IVec3 const offset );
	Optional< Vec4 > texelFetch( Optional< SamplerBuffer > const & sampler
		, Value const & value );
	Optional< Vec4 > texelFetch( Optional< Sampler1D > const & sampler
		, Value const & value
		, Int const & modif );
	Optional< Vec4 > texelFetch( Optional< Sampler2D > const & sampler
		, Value const & value
		, Int const & modif );
	Optional< Vec4 > texelFetch( Optional< Sampler3D > const & sampler
		, Value const & value
		, Int const & modif );
	Optional< Vec4 > texture( Optional< Sampler1DArray > const & sampler
		, Vec2 const & value );
	Optional< Vec4 > texture( Optional< Sampler1DArray > const & sampler
		, Vec2 const & value
		, Float const & lod );
	Optional< Vec4 > texture( Optional< Sampler2DArray > const & sampler
		, Vec3 const & value );
	Optional< Vec4 > texture( Optional< Sampler2DArray > const & sampler
		, Vec3 const & value
		, Float const & lod );
	Optional< Vec4 > texture( Optional< SamplerCubeArray > const & sampler
		, Vec4 const & value );
	Optional< Vec4 >texture( Optional< SamplerCubeArray > const & sampler
		, Vec4 const & value
		, Float const & lod );
	Optional< Vec4 > textureOffset( Optional< Sampler1DArray > const & sampler
		, Vec2 const & value
		, Int const offset );
	Optional< Vec4 > textureOffset( Optional< Sampler1DArray > const & sampler
		, Vec2 const & value
		, Int const offset
		, Float const & lod );
	Optional< Vec4 > textureOffset( Optional< Sampler2DArray > const & sampler
		, Vec3 const & value
		, IVec2 const offset );
	Optional< Vec4 > textureOffset( Optional< Sampler2DArray > const & sampler
		, Vec3 const & value
		, IVec2 const offset
		, Float const & lod );
	Optional< Vec4 > textureLodOffset( Optional< Sampler1DArray > const & sampler
		, Vec2 const & value
		, Float const & lod
		, Int const offset );
	Optional< Vec4 > textureLodOffset( Optional< Sampler2DArray > const & sampler
		, Vec3 const & value
		, Float const & lod
		, IVec2 const offset );
	Optional< Float > texture( Optional< Sampler1DShadow > const & sampler
		, Vec2 const & value );
	Optional< Float > texture( Optional< Sampler1DShadow > const & sampler
		, Vec2 const & value
		, Float const & lod );
	Optional< Float > texture( Optional< Sampler2DShadow > const & sampler
		, Vec3 const & value );
	Optional< Float > texture( Optional< Sampler2DShadow > const & sampler
		, Vec3 const & value
		, Float const & lod );
	Optional< Float > texture( Optional< SamplerCubeShadow > const & sampler
		, Vec4 const & value );
	Optional< Float > texture( Optional< SamplerCubeShadow > const & sampler
		, Vec4 const & value
		, Float const & lod );
	Optional< Float > textureOffset( Optional< Sampler1DShadow > const & sampler
		, Vec2 const & value
		, Int const offset );
	Optional< Float > textureOffset( Optional< Sampler1DShadow > const & sampler
		, Vec2 const & value
		, Int const offset
		, Float const & lod );
	Optional< Float > textureOffset( Optional< Sampler2DShadow > const & sampler
		, Vec3 const & value
		, IVec2 const offset );
	Optional< Float > textureOffset( Optional< Sampler2DShadow > const & sampler
		, Vec3 const & value
		, IVec2 const offset
		, Float const & lod );
	Optional< Float > textureLodOffset( Optional< Sampler1DShadow > const & sampler
		, Vec2 const & value
		, Float const & lod
		, Int const offset );
	Optional< Float > textureLodOffset( Optional< Sampler2DShadow > const & sampler
		, Vec3 const & value
		, Float const & lod
		, IVec2 const offset );
	Optional< Float > texture( Optional< Sampler1DArrayShadow > const & sampler
		, Vec3 const & value );
	Optional< Float > texture( Optional< Sampler1DArrayShadow > const & sampler
		, Vec3 const & value
		, Float const & lod );
	Optional< Float > texture( Optional< Sampler2DArrayShadow > const & sampler
		, Vec4 const & value );
	Optional< Float > texture( Optional< Sampler2DArrayShadow > const & sampler
		, Vec4 const & value
		, Float const & lod );
	Optional< Float > texture( Optional< SamplerCubeArrayShadow > const & sampler
		, Vec4 const & value
		, Float const & layer );
	Optional< Float > texture( Optional< SamplerCubeArrayShadow > const & sampler
		, Vec4 const & value
		, Float const & layer
		, Float const & lod );
	Optional< Float > textureOffset( Optional< Sampler1DArrayShadow > const & sampler
		, Vec3 const & value
		, Int const offset );
	Optional< Float > textureOffset( Optional< Sampler1DArrayShadow > const & sampler
		, Vec3 const & value
		, Int const offset
		, Float const & lod );
	Optional< Float > textureOffset( Optional< Sampler2DArrayShadow > const & sampler
		, Vec4 const & value
		, IVec2 const offset );
	Optional< Float > textureOffset( Optional< Sampler2DArrayShadow > const & sampler
		, Vec4 const & value
		, IVec2 const offset
		, Float const & lod );
	Optional< Float > textureLodOffset( Optional< Sampler1DArrayShadow > const & sampler
		, Vec3 const & value
		, Float const & lod
		, Int const offset );
	Optional< Float > textureLodOffset( Optional< Sampler2DArrayShadow > const & sampler
		, Vec4 const & value
		, Float const & lod
		, IVec2 const offset );
	Optional< Vec2 > reflect( Optional< Vec2 > const & a, Value const & b );
	Optional< Vec3 > reflect( Optional< Vec3 > const & a
		, Value const & b );
	Optional< Vec4 > reflect( Optional< Vec4 > const & a
		, Value const & b );
	Optional< Float > length( Optional< Value >
	const & value );
	Optional< Float > radians( Optional< Value >
	const & value );
	Optional< Float > cos( Optional< Value >
	const & value );
	Optional< Float > sin( Optional< Value >
	const & value );
	Optional< Float > tan( Optional< Value >
	const & value );
}

#include "Intrinsics.inl"

#endif
