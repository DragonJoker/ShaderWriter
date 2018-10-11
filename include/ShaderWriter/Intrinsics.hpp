/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Intrinsics_H___
#define ___Writer_Intrinsics_H___
#pragma once

#include "FunctionParam.hpp"

namespace sdw
{
	template< typename T > struct IsArithmeticType : public std::false_type {};
	template<> struct IsArithmeticType< Int > : public std::true_type {};
	template<> struct IsArithmeticType< UInt > : public std::true_type {};
	template<> struct IsArithmeticType< Float > : public std::true_type {};
	template<> struct IsArithmeticType< Vec2 > : public std::true_type {};
	template<> struct IsArithmeticType< Vec3 > : public std::true_type {};
	template<> struct IsArithmeticType< Vec4 > : public std::true_type {};
	template<> struct IsArithmeticType< IVec2 > : public std::true_type {};
	template<> struct IsArithmeticType< IVec3 > : public std::true_type {};
	template<> struct IsArithmeticType< IVec4 > : public std::true_type {};
	template<> struct IsArithmeticType< Mat2 > : public std::true_type {};
	template<> struct IsArithmeticType< Mat3 > : public std::true_type {};
	template<> struct IsArithmeticType< Mat4 > : public std::true_type{};

#	define GLSL_DECLARE_OPERATOR( RetType, LhsType, RhsType, Operator )\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( LhsType const & p_lhs, RhsType const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( LhsType const & p_lhs, InParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( LhsType const & p_lhs, InOutParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( LhsType const & p_lhs, OutParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( LhsType const & p_lhs, Optional< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( InParam< LhsType > const & p_lhs, RhsType const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( InParam< LhsType > const & p_lhs, InParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( InParam< LhsType > const & p_lhs, InOutParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( InParam< LhsType > const & p_lhs, OutParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( InParam< LhsType > const & p_lhs, Optional< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( InOutParam< LhsType > const & p_lhs, RhsType const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( InOutParam< LhsType > const & p_lhs, InParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( InOutParam< LhsType > const & p_lhs, InOutParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( InOutParam< LhsType > const & p_lhs, OutParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( InOutParam< LhsType > const & p_lhs, Optional< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( OutParam< LhsType > const & p_lhs, RhsType const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( OutParam< LhsType > const & p_lhs, InParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( OutParam< LhsType > const & p_lhs, InOutParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( OutParam< LhsType > const & p_lhs, OutParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( OutParam< LhsType > const & p_lhs, Optional< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( Optional< LhsType > const & p_lhs, RhsType const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( Optional< LhsType > const & p_lhs, InParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( Optional< LhsType > const & p_lhs, InOutParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( Optional< LhsType > const & p_lhs, OutParam< RhsType > const & rhs );\
	template< typename LhsType, typename RhsType, typename Enable = typename std::enable_if< IsArithmeticType< LhsType >::value >::type >\
	RetType operator Operator( Optional< LhsType > const & p_lhs, Optional< RhsType > const & rhs )

#	define GLSL_DECLARE_ARITHMETIC_OPERATOR( LhsType, RhsType, Operator )\
	GLSL_DECLARE_OPERATOR( LhsType, LhsType, RhsType, Operator )

#	define GLSL_DECLARE_BOOLEAN_OPERATOR( LhsType, RhsType, Operator )\
	GLSL_DECLARE_OPERATOR( Boolean, LhsType, RhsType, Operator )

	GLSL_DECLARE_ARITHMETIC_OPERATOR( TypeA, TypeB, + );
	GLSL_DECLARE_ARITHMETIC_OPERATOR( TypeA, TypeB, - );
	GLSL_DECLARE_ARITHMETIC_OPERATOR( TypeA, TypeB, * );
	GLSL_DECLARE_ARITHMETIC_OPERATOR( TypeA, TypeB, / );
	GLSL_DECLARE_ARITHMETIC_OPERATOR( TypeA, TypeB, ^ );
	GLSL_DECLARE_BOOLEAN_OPERATOR( TypeA, TypeB, == );
	GLSL_DECLARE_BOOLEAN_OPERATOR( TypeA, TypeB, != );
	GLSL_DECLARE_BOOLEAN_OPERATOR( TypeA, TypeB, < );
	GLSL_DECLARE_BOOLEAN_OPERATOR( TypeA, TypeB, <= );
	GLSL_DECLARE_BOOLEAN_OPERATOR( TypeA, TypeB, > );
	GLSL_DECLARE_BOOLEAN_OPERATOR( TypeA, TypeB, >= );

	Vec4 operator*( Mat4 const & p_a, Vec4 const & p_b );
	Vec3 operator*( Mat3 const & p_a, Vec3 const & p_b );
	Float operator+( float p_a, Float const & p_b );
	Float operator-( float p_a, Float const & p_b );
	Float operator*( float p_a, Float const & p_b );
	Float operator/( float p_a, Float const & p_b );
	Int operator+( int p_a, Int const & p_b );
	Int operator-( int p_a, Int const & p_b );
	Int operator*( int p_a, Int const & p_b );
	Int operator/( int p_a, Int const & p_b );
	Int operator%( int p_a, Int const & p_b );
	Int operator%( Int const & p_a, int p_b );
	Int operator%( Int const & p_a, Int const & p_b );

	template< typename ... Values > inline Vec2 vec2( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline Vec3 vec3( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline Vec4 vec4( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline IVec2 ivec2( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline IVec3 ivec3( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline IVec4 ivec4( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline UVec2 uvec2( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline UVec3 uvec3( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline UVec4 uvec4( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline BVec2 bvec2( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline BVec3 bvec3( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline BVec4 bvec4( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline Mat2 mat2( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline Mat3 mat3( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline Mat4 mat4( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline Float dot( Type const & p_value, Values const & ... p_values );
	template< typename ... Values > inline Float inversesqrt( Expr const & p_value, Values const & ... p_values );
	template< typename Value, typename ... Values > inline Value cross( Value const & p_value, Values const & ... p_values );
	template< typename Value, typename ... Values > inline Value clamp( Value const & p_value, Values const & ... p_values );
	template< typename Value, typename ... Values > inline Value min( Value const & p_value, Values const & ... p_values );
	template< typename Value, typename ... Values > inline Value max( Value const & p_value, Values const & ... p_values );
	template< typename Value, typename ... Values > inline Value mix( Value const & p_value, Values const & ... p_values );
	template< typename Value, typename ... Values > inline Value reflect( Type const & p_value, Values const & ... p_values );
	template< typename Value > inline Value sqrt( Value const & value );
	template< typename Value > inline Value pow( Value const & x, Value const & y );
	template< typename Value > inline Value pow( Value const & x, Optional< Value > const & y );
	template< typename Value > inline Value pow2( Value const & p );
	template< typename Value > inline Value neg( Value const & p_value );
	template< typename Value > inline Value log( Value const & p_value );
	template< typename Value > inline Value exp( Value const & p_value );
	template< typename Value > inline Value log2( Value const & p_value );
	template< typename Value > inline Value exp2( Value const & p_value );
	template< typename Value > inline Value tan( Value const & p_value );
	template< typename Value > inline Value sin( Value const & p_value );
	template< typename Value > inline Value cos( Value const & p_value );
	template< typename Value > inline Value atan( Value const & p_y, Value const & p_x );
	template< typename Value > inline Value atan( Value const & p_value );
	template< typename Value > inline Value asin( Value const & p_value );
	template< typename Value > inline Value acos( Value const & p_value );
	template< typename Value > inline Value fma( Value const & a, Value const & b, Value const & c );
	template< typename Input, typename Output > inline Output neg( Swizzle< Input, Output > const & p_value );
	template< typename Value > inline Value normalize( Value const & p_value );
	template< typename Input, typename Output > inline Output normalize( Swizzle< Input, Output > const & p_value );
	template< typename Value > inline Value transpose( Value const & p_value );
	template< typename Value > inline Value inverse( Value const & p_value );
	template< typename Value > inline Value abs( Value const & p_value );
	template< typename Value > inline Value isinf( Value const & p_value );
	template< typename ValueA, typename ValueB > ValueB smoothstep( ValueA const & p_edge0, ValueA const & p_edge1, ValueB const & x );
	template< typename Value > inline Value dFdx( Value const & p_value );
	template< typename Value > inline Value dFdy( Value const & p_value );
	template< typename Value > inline Value dFdxCoarse( Value const & p_value );
	template< typename Value > inline Value dFdyCoarse( Value const & p_value );
	template< typename Value > inline Value dFdxFine( Value const & p_value );
	template< typename Value > inline Value dFdyFine( Value const & p_value );
	template< typename Value > inline Value sign( Value const & p_value );
	template< typename Value > inline Value mod( Value const & x, Value const & y );
	template< typename Value > inline Value mod( Value const & x, Float const & y );
	template< typename Value > inline Value fract( Value const & p_value );
	template< typename Value > inline Value floor( Value const & value );
	template< typename Value > inline Value trunc( Value const & value );
	template< typename Value > inline Value round( Value const & value );
	template< typename ValueE, typename ValueX > inline ValueE step( ValueE const & edge, ValueX const & x );
	Int bitfieldReverse( Int const & value );
	UInt bitfieldReverse( UInt const & value );
	Int findMSB( Int value );
	Int findMSB( UInt value );
	Int textureSize( Sampler1D const & p_sampler, Int const p_lod );
	IVec2 textureSize( Sampler2D const & p_sampler, Int const & p_lod );
	IVec3 textureSize( Sampler3D const & p_sampler, Int const & p_lod );
	IVec2 textureSize( SamplerCube const & p_sampler, Int const & p_lod );
	IVec2 textureSize( Sampler1DArray const & p_sampler, Int const p_lod );
	IVec3 textureSize( Sampler2DArray const & p_sampler, Int const & p_lod );
	IVec3 textureSize( SamplerCubeArray const & p_sampler, Int const & p_lod );
	Int textureSize( Sampler1DShadow const & p_sampler, Int const p_lod );
	IVec2 textureSize( Sampler2DShadow const & p_sampler, Int const & p_lod );
	IVec2 textureSize( SamplerCubeShadow const & p_sampler, Int const & p_lod );
	IVec2 textureSize( Sampler1DArrayShadow const & p_sampler, Int const p_lod );
	IVec3 textureSize( Sampler2DArrayShadow const & p_sampler, Int const & p_lod );
	IVec3 textureSize( SamplerCubeArrayShadow const & p_sampler, Int const & p_lod );
	Vec4 textureGather( Sampler2D const & sampler, Vec2 const & value );
	Vec4 textureGather( Sampler2DArray const & sampler, Vec3 const & value );
	Vec4 textureGather( SamplerCube const & sampler, Vec3 const & value );
	Vec4 textureGather( SamplerCubeArray const & sampler, Vec4 const & value );
	Vec4 textureGather( Sampler2D const & sampler, Vec2 const & value, Int const & comp );
	Vec4 textureGather( Sampler2DArray const & sampler, Vec3 const & value, Int const & comp );
	Vec4 textureGather( SamplerCube const & sampler, Vec3 const & value, Int const & comp );
	Vec4 textureGather( SamplerCubeArray const & sampler, Vec4 const & value, Int const & comp );
	Vec4 textureGather( Sampler2DShadow const & sampler, Vec3 const & value, Float const & refZ );
	Vec4 textureGather( Sampler2DArrayShadow const & sampler, Vec3 const & value, Float const & refZ );
	Vec4 textureGather( SamplerCubeShadow const & sampler, Vec3 const & value, Float const & refZ );
	Vec4 textureGather( SamplerCubeArrayShadow const & sampler, Vec4 const & value, Float const & refZ );
	Vec4 texture( Sampler1D const & p_sampler, Float const & p_value );
	Vec4 texture( Sampler1D const & p_sampler, Float const & p_value, Float const & p_lod );
	Vec4 texture( Sampler2D const & p_sampler, Vec2 const & p_value );
	Vec4 texture( Sampler2D const & p_sampler, Vec2 const & p_value, Float const & p_lod );
	Vec4 texture( Sampler3D const & p_sampler, Vec3 const & p_value );
	Vec4 texture( Sampler3D const & p_sampler, Vec3 const & p_value, Float const & p_lod );
	Vec4 texture( SamplerCube const & p_sampler, Vec3 const & p_value );
	Vec4 texture( SamplerCube const & p_sampler, Vec3 const & p_value, Float const & p_lod );
	Vec4 textureOffset( Sampler1D const & p_sampler, Vec2 const & p_value, Int const p_offset );
	Vec4 textureOffset( Sampler1D const & p_sampler, Vec2 const & p_value, Int const p_offset, Float const & p_lod );
	Vec4 textureOffset( Sampler2D const & p_sampler, Vec2 const & p_value, IVec2 const p_offset );
	Vec4 textureOffset( Sampler2D const & p_sampler, Vec2 const & p_value, IVec2 const p_offset, Float const & p_lod );
	Vec4 textureOffset( Sampler3D const & p_sampler, Vec3 const & p_value, IVec3 const p_offset );
	Vec4 textureOffset( Sampler3D const & p_sampler, Vec3 const & p_value, IVec3 const p_offset, Float const & p_lod );
	Vec4 textureLodOffset( Sampler1D const & p_sampler, Vec2 const & p_value, Float const & p_lod, Int const p_offset );
	Vec4 textureLodOffset( Sampler2D const & p_sampler, Vec2 const & p_value, Float const & p_lod, IVec2 const p_offset );
	Vec4 textureLodOffset( Sampler3D const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec3 const p_offset );
	Vec4 texelFetch( SamplerBuffer const & p_sampler, Type const & p_value );
	Vec4 texelFetch( Sampler1D const & p_sampler, Type const & p_value, Int const & p_modif );
	Vec4 texelFetch( Sampler2D const & p_sampler, Type const & p_value, Int const & p_modif );
	Vec4 texelFetch( Sampler3D const & p_sampler, Type const & p_value, Int const & p_modif );
	Vec4 texture( Sampler1DArray const & p_sampler, Vec2 const & p_value );
	Vec4 texture( Sampler1DArray const & p_sampler, Vec2 const & p_value, Float const & p_lod );
	Vec4 texture( Sampler2DArray const & p_sampler, Vec3 const & p_value );
	Vec4 texture( Sampler2DArray const & p_sampler, Vec3 const & p_value, Float const & p_lod );
	Vec4 texture( SamplerCubeArray const & p_sampler, Vec4 const & p_value );
	Vec4 texture( SamplerCubeArray const & p_sampler, Vec4 const & p_value, Float const & p_lod );
	Vec4 textureOffset( Sampler1DArray const & p_sampler, Vec2 const & p_value, Int const p_offset );
	Vec4 textureOffset( Sampler1DArray const & p_sampler, Vec2 const & p_value, Int const p_offset, Float const & p_lod );
	Vec4 textureOffset( Sampler2DArray const & p_sampler, Vec3 const & p_value, IVec2 const p_offset );
	Vec4 textureOffset( Sampler2DArray const & p_sampler, Vec3 const & p_value, IVec2 const p_offset, Float const & p_lod );
	Vec4 textureLodOffset( Sampler1DArray const & p_sampler, Vec2 const & p_value, Float const & p_lod, Int const p_offset );
	Vec4 textureLodOffset( Sampler2DArray const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec2 const p_offset );
	Float texture( Sampler1DShadow const & p_sampler, Vec2 const & p_value );
	Float texture( Sampler1DShadow const & p_sampler, Vec2 const & p_value, Float const & p_lod );
	Float texture( Sampler2DShadow const & p_sampler, Vec3 const & p_value );
	Float texture( Sampler2DShadow const & p_sampler, Vec3 const & p_value, Float const & p_lod );
	Float texture( SamplerCubeShadow const & p_sampler, Vec4 const & p_value );
	Float texture( SamplerCubeShadow const & p_sampler, Vec4 const & p_value, Float const & p_lod );
	Float textureOffset( Sampler1DShadow const & p_sampler, Vec2 const & p_value, Int const p_offset );
	Float textureOffset( Sampler1DShadow const & p_sampler, Vec2 const & p_value, Int const p_offset, Float const & p_lod );
	Float textureOffset( Sampler2DShadow const & p_sampler, Vec3 const & p_value, IVec2 const p_offset );
	Float textureOffset( Sampler2DShadow const & p_sampler, Vec3 const & p_value, IVec2 const p_offset, Float const & p_lod );
	Float textureLodOffset( Sampler1DShadow const & p_sampler, Vec2 const & p_value, Float const & p_lod, Int const p_offset );
	Float textureLodOffset( Sampler2DShadow const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec2 const p_offset );
	Float texture( Sampler1DArrayShadow const & p_sampler, Vec3 const & p_value );
	Float texture( Sampler1DArrayShadow const & p_sampler, Vec3 const & p_value, Float const & p_lod );
	Float texture( Sampler2DArrayShadow const & p_sampler, Vec4 const & p_value );
	Float texture( Sampler2DArrayShadow const & p_sampler, Vec4 const & p_value, Float const & p_lod );
	Float texture( SamplerCubeArrayShadow const & p_sampler, Vec4 const & p_value, Float const & p_layer );
	Float texture( SamplerCubeArrayShadow const & p_sampler, Vec4 const & p_value, Float const & p_layer, Float const & p_lod );
	Float textureOffset( Sampler1DArrayShadow const & p_sampler, Vec3 const & p_value, Int const p_offset );
	Float textureOffset( Sampler1DArrayShadow const & p_sampler, Vec3 const & p_value, Int const p_offset, Float const & p_lod );
	Float textureOffset( Sampler2DArrayShadow const & p_sampler, Vec4 const & p_value, IVec2 const p_offset );
	Float textureOffset( Sampler2DArrayShadow const & p_sampler, Vec4 const & p_value, IVec2 const p_offset, Float const & p_lod );
	Float textureLodOffset( Sampler1DArrayShadow const & p_sampler, Vec3 const & p_value, Float const & p_lod, Int const p_offset );
	Float textureLodOffset( Sampler2DArrayShadow const & p_sampler, Vec4 const & p_value, Float const & p_lod, IVec2 const p_offset );
	Vec2 reflect( Vec2 const & p_a, Vec2 const & p_b );
	Vec3 reflect( Vec3 const & p_a, Vec3 const & p_b );
	Vec4 reflect( Vec4 const & p_a, Vec4 const & p_b );
	Vec2 refract( Vec2 const & p_a, Vec2 const & p_b, Float const & p_r );
	Vec3 refract( Vec3 const & p_a, Vec3 const & p_b, Float const & p_r );
	Vec4 refract( Vec4 const & p_a, Vec4 const & p_b, Float const & p_r );
	Float length( Type const & p_value );
	Float distance( Type const & p_a, Type const & p_b );
	Float radians( Type const & p_value );
	Float cos( Type const & p_value );
	Float sin( Type const & p_value );
	Float tan( Type const & p_value );
	Optional< Int > textureSize( Optional< Sampler1D > const & p_sampler, Int const p_lod );
	Optional< IVec2 > textureSize( Optional< Sampler2D > const & p_sampler, Int const & p_lod );
	Optional< IVec3 > textureSize( Optional< Sampler3D > const & p_sampler, Int const & p_lod );
	Optional< IVec2 > textureSize( Optional< SamplerCube > const & p_sampler, Int const & p_lod );
	Optional< IVec2 > textureSize( Optional< Sampler1DArray > const & p_sampler, Int const p_lod );
	Optional< IVec3 > textureSize( Optional< Sampler2DArray > const & p_sampler, Int const & p_lod );
	Optional< IVec3 > textureSize( Optional< SamplerCubeArray > const & p_sampler, Int const & p_lod );
	Optional< Int > textureSize( Optional< Sampler1DShadow > const & p_sampler, Int const p_lod );
	Optional< IVec2 > textureSize( Optional< Sampler2DShadow > const & p_sampler, Int const & p_lod );
	Optional< IVec2 > textureSize( Optional< SamplerCubeShadow > const & p_sampler, Int const & p_lod );
	Optional< IVec2 > textureSize( Optional< Sampler1DArrayShadow > const & p_sampler, Int const p_lod );
	Optional< IVec3 > textureSize( Optional< Sampler2DArrayShadow > const & p_sampler, Int const & p_lod );
	Optional< IVec3 > textureSize( Optional< SamplerCubeArrayShadow > const & p_sampler, Int const & p_lod );
	Optional< Vec4 > texture( Optional< Sampler1D > const & p_sampler, Float const & p_value );
	Optional< Vec4 > texture( Optional< Sampler1D > const & p_sampler, Float const & p_value, Float const & p_lod );
	Optional< Vec4 > texture( Optional< Sampler2D > const & p_sampler, Vec2 const & p_value );
	Optional< Vec4 > texture( Optional< Sampler2D > const & p_sampler, Vec2 const & p_value, Float const & p_lod );
	Optional< Vec4 > texture( Optional< Sampler3D > const & p_sampler, Vec3 const & p_value );
	Optional< Vec4 > texture( Optional< Sampler3D > const & p_sampler, Vec3 const & p_value, Float const & p_lod );
	Optional< Vec4 > texture( Optional< SamplerCube > const & p_sampler, Vec3 const & p_value );
	Optional< Vec4 > texture( Optional< SamplerCube > const & p_sampler, Vec3 const & p_value, Float const & p_lod );
	Optional< Vec4 > textureOffset( Optional< Sampler1D > const & p_sampler, Float const & p_value, Int const p_offset );
	Optional< Vec4 > textureOffset( Optional< Sampler1D > const & p_sampler, Float const & p_value, Int const p_offset, Float const & p_lod );
	Optional< Vec4 > textureOffset( Optional< Sampler2D > const & p_sampler, Vec2 const & p_value, IVec2 const p_offset );
	Optional< Vec4 > textureOffset( Optional< Sampler2D > const & p_sampler, Vec2 const & p_value, IVec2 const p_offset, Float const & p_lod );
	Optional< Vec4 > textureOffset( Optional< Sampler3D > const & p_sampler, Vec3 const & p_value, IVec3 const p_offset );
	Optional< Vec4 > textureOffset( Optional< Sampler3D > const & p_sampler, Vec3 const & p_value, IVec3 const p_offset, Float const & p_lod );
	Optional< Vec4 > textureLodOffset( Optional< Sampler1D > const & p_sampler, Vec2 const & p_value, Float const & p_lod, Int const p_offset );
	Optional< Vec4 > textureLodOffset( Optional< Sampler2D > const & p_sampler, Vec2 const & p_value, Float const & p_lod, IVec2 const p_offset );
	Optional< Vec4 > textureLodOffset( Optional< Sampler3D > const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec3 const p_offset );
	Optional< Vec4 > texelFetch( Optional< SamplerBuffer > const & p_sampler, Type const & p_value );
	Optional< Vec4 > texelFetch( Optional< Sampler1D > const & p_sampler, Type const & p_value, Int const & p_modif );
	Optional< Vec4 > texelFetch( Optional< Sampler2D > const & p_sampler, Type const & p_value, Int const & p_modif );
	Optional< Vec4 > texelFetch( Optional< Sampler3D > const & p_sampler, Type const & p_value, Int const & p_modif );
	Optional< Vec4 > texture( Optional< Sampler1DArray > const & p_sampler, Vec2 const & p_value );
	Optional< Vec4 > texture( Optional< Sampler1DArray > const & p_sampler, Vec2 const & p_value, Float const & p_lod );
	Optional< Vec4 > texture( Optional< Sampler2DArray > const & p_sampler, Vec3 const & p_value );
	Optional< Vec4 > texture( Optional< Sampler2DArray > const & p_sampler, Vec3 const & p_value, Float const & p_lod );
	Optional< Vec4 > texture( Optional< SamplerCubeArray > const & p_sampler, Vec4 const & p_value );
	Optional< Vec4 > texture( Optional< SamplerCubeArray > const & p_sampler, Vec4 const & p_value, Float const & p_lod );
	Optional< Vec4 > textureOffset( Optional< Sampler1DArray > const & p_sampler, Vec2 const & p_value, Int const p_offset );
	Optional< Vec4 > textureOffset( Optional< Sampler1DArray > const & p_sampler, Vec2 const & p_value, Int const p_offset, Float const & p_lod );
	Optional< Vec4 > textureOffset( Optional< Sampler2DArray > const & p_sampler, Vec3 const & p_value, IVec2 const p_offset );
	Optional< Vec4 > textureOffset( Optional< Sampler2DArray > const & p_sampler, Vec3 const & p_value, IVec2 const p_offset, Float const & p_lod );
	Optional< Vec4 > textureLodOffset( Optional< Sampler1DArray > const & p_sampler, Vec2 const & p_value, Float const & p_lod, Int const p_offset );
	Optional< Vec4 > textureLodOffset( Optional< Sampler2DArray > const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec2 const p_offset );
	Optional< Float > texture( Optional< Sampler1DShadow > const & p_sampler, Vec2 const & p_value );
	Optional< Float > texture( Optional< Sampler1DShadow > const & p_sampler, Vec2 const & p_value, Float const & p_lod );
	Optional< Float > texture( Optional< Sampler2DShadow > const & p_sampler, Vec3 const & p_value );
	Optional< Float > texture( Optional< Sampler2DShadow > const & p_sampler, Vec3 const & p_value, Float const & p_lod );
	Optional< Float > texture( Optional< SamplerCubeShadow > const & p_sampler, Vec4 const & p_value );
	Optional< Float > texture( Optional< SamplerCubeShadow > const & p_sampler, Vec4 const & p_value, Float const & p_lod );
	Optional< Float > textureOffset( Optional< Sampler1DShadow > const & p_sampler, Vec2 const & p_value, Int const p_offset );
	Optional< Float > textureOffset( Optional< Sampler1DShadow > const & p_sampler, Vec2 const & p_value, Int const p_offset, Float const & p_lod );
	Optional< Float > textureOffset( Optional< Sampler2DShadow > const & p_sampler, Vec3 const & p_value, IVec2 const p_offset );
	Optional< Float > textureOffset( Optional< Sampler2DShadow > const & p_sampler, Vec3 const & p_value, IVec2 const p_offset, Float const & p_lod );
	Optional< Float > textureLodOffset( Optional< Sampler1DShadow > const & p_sampler, Vec2 const & p_value, Float const & p_lod, Int const p_offset );
	Optional< Float > textureLodOffset( Optional< Sampler2DShadow > const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec2 const p_offset );
	Optional< Float > texture( Optional< Sampler1DArrayShadow > const & p_sampler, Vec3 const & p_value );
	Optional< Float > texture( Optional< Sampler1DArrayShadow > const & p_sampler, Vec3 const & p_value, Float const & p_lod );
	Optional< Float > texture( Optional< Sampler2DArrayShadow > const & p_sampler, Vec4 const & p_value );
	Optional< Float > texture( Optional< Sampler2DArrayShadow > const & p_sampler, Vec4 const & p_value, Float const & p_lod );
	Optional< Float > texture( Optional< SamplerCubeArrayShadow > const & p_sampler, Vec4 const & p_value, Float const & p_layer );
	Optional< Float > texture( Optional< SamplerCubeArrayShadow > const & p_sampler, Vec4 const & p_value, Float const & p_layer, Float const & p_lod );
	Optional< Float > textureOffset( Optional< Sampler1DArrayShadow > const & p_sampler, Vec3 const & p_value, Int const p_offset );
	Optional< Float > textureOffset( Optional< Sampler1DArrayShadow > const & p_sampler, Vec3 const & p_value, Int const p_offset, Float const & p_lod );
	Optional< Float > textureOffset( Optional< Sampler2DArrayShadow > const & p_sampler, Vec4 const & p_value, IVec2 const p_offset );
	Optional< Float > textureOffset( Optional< Sampler2DArrayShadow > const & p_sampler, Vec4 const & p_value, IVec2 const p_offset, Float const & p_lod );
	Optional< Float > textureLodOffset( Optional< Sampler1DArrayShadow > const & p_sampler, Vec3 const & p_value, Float const & p_lod, Int const p_offset );
	Optional< Float > textureLodOffset( Optional< Sampler2DArrayShadow > const & p_sampler, Vec4 const & p_value, Float const & p_lod, IVec2 const p_offset );
	Optional< Vec2 > reflect( Optional< Vec2 > const & p_a, Type const & p_b );
	Optional< Vec3 > reflect( Optional< Vec3 > const & p_a, Type const & p_b );
	Optional< Vec4 > reflect( Optional< Vec4 > const & p_a, Type const & p_b );
	Optional< Float > length( Optional< Type > const & p_value );
	Optional< Float > radians( Optional< Type > const & p_value );
	Optional< Float > cos( Optional< Type > const & p_value );
	Optional< Float > sin( Optional< Type > const & p_value );
	Optional< Float > tan( Optional< Type > const & p_value );
}

#include "Intrinsics.inl"

#endif
