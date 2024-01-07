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
	inline Vec2 vec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline Vec3 vec3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline Vec4 vec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DVec2 dvec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DVec3 dvec3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DVec4 dvec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline HVec2 f16vec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline HVec4 f16vec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I8Vec2 i8vec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I8Vec3 i8vec3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I8Vec4 i8vec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I16Vec2 i16vec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I16Vec3 i16vec3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I16Vec4 i16vec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I32Vec2 i32vec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I32Vec3 i32vec3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I32Vec4 i32vec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I64Vec2 i64vec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I64Vec3 i64vec3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline I64Vec4 i64vec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U8Vec2 u8vec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U8Vec3 u8vec3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U8Vec4 u8vec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U16Vec2 u16vec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U16Vec3 u16vec3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U16Vec4 u16vec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U32Vec2 u32vec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U32Vec3 u32vec3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U32Vec4 u32vec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U64Vec2 u64vec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U64Vec3 u64vec3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline U64Vec4 u64vec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline BVec2 bvec2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline BVec3 bvec3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline BVec4 bvec4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline Mat2x2 mat2x2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline Mat2x3 mat2x3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline Mat2x4 mat2x4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline Mat3x2 mat3x2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline Mat3x3 mat3x3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline Mat3x4 mat3x4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline Mat4x2 mat4x2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline Mat4x3 mat4x3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline Mat4x4 mat4x4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DMat2x2 dmat2x2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DMat2x3 dmat2x3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DMat2x4 dmat2x4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DMat3x2 dmat3x2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DMat3x3 dmat3x3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DMat3x4 dmat3x4( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DMat4x2 dmat4x2( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DMat4x3 dmat4x3( ValuesT && ... values );
	template< typename ... ValuesT >
	inline DMat4x4 dmat4x4( ValuesT && ... values );
	template< ValueT ValT >
	inline NonUniformT< ValT > nonuniform( ValT const & value );
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	inline CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > combine( SampledImageT< FormatT, DimT, ArrayedT, MsT > const & image
		, SamplerT< DepthT > const & sampler );

	template< typename ... ValuesT >
	inline I32Vec2 ivec2( ValuesT && ... values )
	{
		return i32vec2( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I32Vec3 ivec3( ValuesT && ... values )
	{
		return i32vec3( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline I32Vec4 ivec4( ValuesT && ... values )
	{
		return i32vec4( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U32Vec2 uvec2( ValuesT && ... values )
	{
		return u32vec2( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U32Vec3 uvec3( ValuesT && ... values )
	{
		return u32vec3( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline U32Vec4 uvec4( ValuesT && ... values )
	{
		return u32vec4( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat2 mat2( ValuesT && ... values )
	{
		return mat2x2( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat3 mat3( ValuesT && ... values )
	{
		return mat3x3( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline Mat4 mat4( ValuesT && ... values )
	{
		return mat4x4( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat2 dmat2( ValuesT && ... values )
	{
		return dmat2x2( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat3 dmat3( ValuesT && ... values )
	{
		return dmat3x3( std::forward< ValuesT >( values )... );
	}

	template< typename ... ValuesT >
	inline DMat4 dmat4( ValuesT && ... values )
	{
		return dmat4x4( std::forward< ValuesT >( values )... );
	}

	// Idiomatic SPIR-V style.
	SDW_API RetVoid controlBarrier( ShaderWriter & writer
		, type::Scope executionScope
		, type::Scope memoryScope
		, type::MemorySemantics semantics );
	SDW_API RetVoid memoryBarrier( ShaderWriter & writer
		, type::Scope memoryScope
		, type::MemorySemantics semantics );

	// Old school GLSL style.
	inline RetVoid barrier( ShaderWriter & writer )
	{
		if ( getBuilder( writer ).getType() == ast::ShaderStage::eCompute )
		{
			return controlBarrier( writer
				, type::Scope::eWorkgroup
				, type::Scope::eWorkgroup
				, ( type::MemorySemanticsMask::eAcquireRelease
					| type::MemorySemanticsMask::eWorkgroupMemory ) );
		}

		return controlBarrier( writer
			, type::Scope::eWorkgroup
			, type::Scope::eInvocation
			, type::MemorySemantics{ type::MemorySemanticsMask::eNone } );
	}

	inline RetVoid memoryBarrier( ShaderWriter & writer )
	{
		return memoryBarrier( writer
			, type::Scope::eDevice
			, ( type::MemorySemanticsMask::eAcquireRelease
				| type::MemorySemanticsMask::eUniformMemory
				| type::MemorySemanticsMask::eWorkgroupMemory
				| type::MemorySemanticsMask::eImageMemory ) );
	}

	inline RetVoid memoryBarrierBuffer( ShaderWriter & writer )
	{
		return memoryBarrier( writer
			, type::Scope::eDevice
			, ( type::MemorySemanticsMask::eAcquireRelease
				| type::MemorySemanticsMask::eUniformMemory ) );
	}

	inline RetVoid memoryBarrierShared( ShaderWriter & writer )
	{
		return memoryBarrier( writer
			, type::Scope::eDevice
			, ( type::MemorySemanticsMask::eAcquireRelease
				| type::MemorySemanticsMask::eWorkgroupMemory ) );
	}

	inline RetVoid memoryBarrierImage( ShaderWriter & writer )
	{
		return memoryBarrier( writer
			, type::Scope::eDevice
			, ( type::MemorySemanticsMask::eAcquireRelease
				| type::MemorySemanticsMask::eImageMemory ) );
	}

	inline RetVoid groupMemoryBarrier( ShaderWriter & writer )
	{
		return memoryBarrier( writer
			, type::Scope::eWorkgroup
			, ( type::MemorySemanticsMask::eAcquireRelease
				| type::MemorySemanticsMask::eUniformMemory
				| type::MemorySemanticsMask::eWorkgroupMemory
				| type::MemorySemanticsMask::eImageMemory ) );
	}

	inline RetVoid subgroupBarrier( ShaderWriter & writer )
	{
		return controlBarrier( writer
			, type::Scope::eSubgroup
			, type::Scope::eSubgroup
			, ( type::MemorySemanticsMask::eAcquireRelease
				| type::MemorySemanticsMask::eUniformMemory
				| type::MemorySemanticsMask::eWorkgroupMemory
				| type::MemorySemanticsMask::eImageMemory ) );
	}

	inline RetVoid subgroupMemoryBarrier( ShaderWriter & writer )
	{
		return memoryBarrier( writer
			, type::Scope::eSubgroup
			, ( type::MemorySemanticsMask::eAcquireRelease
				| type::MemorySemanticsMask::eUniformMemory
				| type::MemorySemanticsMask::eWorkgroupMemory
				| type::MemorySemanticsMask::eImageMemory ) );
	}

	inline RetVoid subgroupMemoryBarrierBuffer( ShaderWriter & writer )
	{
		return memoryBarrier( writer
			, type::Scope::eSubgroup
			, ( type::MemorySemanticsMask::eAcquireRelease
				| type::MemorySemanticsMask::eUniformMemory ) );
	}

	inline RetVoid subgroupMemoryBarrierShared( ShaderWriter & writer )
	{
		return memoryBarrier( writer
			, type::Scope::eSubgroup
			, ( type::MemorySemanticsMask::eAcquireRelease
				| type::MemorySemanticsMask::eWorkgroupMemory ) );
	}

	inline RetVoid subgroupMemoryBarrierImage( ShaderWriter & writer )
	{
		return memoryBarrier( writer
			, type::Scope::eSubgroup
			, ( type::MemorySemanticsMask::eAcquireRelease
				| type::MemorySemanticsMask::eImageMemory ) );
	}
}

#include "Intrinsics.inl"

#endif
