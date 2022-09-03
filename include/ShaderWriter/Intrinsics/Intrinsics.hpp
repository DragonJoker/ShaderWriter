/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Intrinsics_H___
#define ___SDW_Intrinsics_H___
#pragma once

#include "IntrinsicFunctions.hpp"
#include "ShaderWriter/BaseTypes/NonUniform.hpp"

namespace sdw
{
	template< typename ... ValuesT >
	inline Vec2 vec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline Vec3 vec3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline Vec4 vec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DVec2 dvec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DVec3 dvec3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DVec4 dvec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline HVec2 f16vec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline HVec4 f16vec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I8Vec2 i8vec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I8Vec3 i8vec3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I8Vec4 i8vec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I16Vec2 i16vec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I16Vec3 i16vec3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I16Vec4 i16vec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I32Vec2 ivec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I32Vec3 ivec3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I32Vec4 ivec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I64Vec2 i64vec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I64Vec3 i64vec3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline I64Vec4 i64vec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U8Vec2 u8vec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U8Vec3 u8vec3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U8Vec4 u8vec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U16Vec2 u16vec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U16Vec3 u16vec3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U16Vec4 u16vec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U32Vec2 uvec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U32Vec3 uvec3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U32Vec4 uvec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U64Vec2 u64vec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U64Vec3 u64vec3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline U64Vec4 u64vec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline BVec2 bvec2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline BVec3 bvec3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline BVec4 bvec4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline Mat2 mat2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline Mat2x3 mat2x3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline Mat2x4 mat2x4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline Mat3 mat3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline Mat3x2 mat3x2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline Mat3x4 mat3x4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline Mat4 mat4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline Mat4x2 mat4x2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline Mat4x3 mat4x3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DMat2 dmat2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DMat2x3 dmat2x3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DMat2x4 dmat2x4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DMat3 dmat3( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DMat3x2 dmat3x2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DMat3x4 dmat3x4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DMat4 dmat4( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DMat4x2 dmat4x2( Value const & value
		, ValuesT ... values );
	template< typename ... ValuesT >
	inline DMat4x3 dmat4x3( Value const & value
		, ValuesT ... values );
	template< typename ValueT >
	inline NonUniformT< ValueT > nonuniform( Value const & value );
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	inline CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > combine( SampledImageT< FormatT, DimT, ArrayedT, MsT > const & image
		, SamplerT< DepthT > const & sampler );
}

#include "Intrinsics.inl"

#endif
