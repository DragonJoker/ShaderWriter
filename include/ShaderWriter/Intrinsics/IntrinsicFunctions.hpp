/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#ifndef ___SDW_IntrinsicFunctions_H___
#define ___SDW_IntrinsicFunctions_H___
#pragma once

#include "ShaderWriter/BaseTypes/Boolean.hpp"
#include "ShaderWriter/BaseTypes/CallableData.hpp"
#include "ShaderWriter/BaseTypes/CombinedImage.hpp"
#include "ShaderWriter/BaseTypes/HitAttribute.hpp"
#include "ShaderWriter/BaseTypes/RayPayload.hpp"
#include "ShaderWriter/BaseTypes/SampledImage.hpp"
#include "ShaderWriter/BaseTypes/Sampler.hpp"
#include "ShaderWriter/BaseTypes/StorageImage.hpp"
#include "ShaderWriter/BaseTypes/TaskPayloadNV.hpp"
#include "ShaderWriter/CompositeTypes/Function.hpp"
#include "ShaderWriter/CompositeTypes/FunctionParam.hpp"
#include "ShaderWriter/CompositeTypes/RayDesc.hpp"
#include "ShaderWriter/MatTypes/Mat2.hpp"
#include "ShaderWriter/MatTypes/Mat2x3.hpp"
#include "ShaderWriter/MatTypes/Mat2x4.hpp"
#include "ShaderWriter/MatTypes/Mat3.hpp"
#include "ShaderWriter/MatTypes/Mat3x2.hpp"
#include "ShaderWriter/MatTypes/Mat3x4.hpp"
#include "ShaderWriter/MatTypes/Mat4.hpp"
#include "ShaderWriter/MatTypes/Mat4x2.hpp"
#include "ShaderWriter/MatTypes/Mat4x3.hpp"

#include <ShaderAST/Expr/MakeIntrinsic.hpp>

namespace sdw
{
#pragma region degrees
	/**
	*name
	*	degrees
	*/
	/**@{*/
	SDW_API RetFloat degrees( Float const radians );
	SDW_API RetVec2 degrees( Vec2 const radians );
	SDW_API RetVec3 degrees( Vec3 const radians );
	SDW_API RetVec4 degrees( Vec4 const radians );
	/**@}*/
#pragma endregion
#pragma region radians
	/**
	*name
	*	radians
	*/
	/**@{*/
	SDW_API RetFloat radians( Float const degrees );
	SDW_API RetVec2 radians( Vec2 const degrees );
	SDW_API RetVec3 radians( Vec3 const degrees );
	SDW_API RetVec4 radians( Vec4 const degrees );
	/**@}*/
#pragma endregion
#pragma region cos
	/**
	*name
	*	cos
	*/
	/**@{*/
	SDW_API RetFloat cos( Float const x );
	SDW_API RetVec2 cos( Vec2 const x );
	SDW_API RetVec3 cos( Vec3 const x );
	SDW_API RetVec4 cos( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region sin
	/**
	*name
	*	sin
	*/
	/**@{*/
	SDW_API RetFloat sin( Float const x );
	SDW_API RetVec2 sin( Vec2 const x );
	SDW_API RetVec3 sin( Vec3 const x );
	SDW_API RetVec4 sin( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region tan
	/**
	*name
	*	tan
	*/
	/**@{*/
	SDW_API RetFloat tan( Float const x );
	SDW_API RetVec2 tan( Vec2 const x );
	SDW_API RetVec3 tan( Vec3 const x );
	SDW_API RetVec4 tan( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region cosh
	/**
	*name
	*	cosh
	*/
	/**@{*/
	SDW_API RetFloat cosh( Float const x );
	SDW_API RetVec2 cosh( Vec2 const x );
	SDW_API RetVec3 cosh( Vec3 const x );
	SDW_API RetVec4 cosh( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region sinh
	/**
	*name
	*	sinh
	*/
	/**@{*/
	SDW_API RetFloat sinh( Float const x );
	SDW_API RetVec2 sinh( Vec2 const x );
	SDW_API RetVec3 sinh( Vec3 const x );
	SDW_API RetVec4 sinh( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region tanh
	/**
	*name
	*	tanh
	*/
	/**@{*/
	SDW_API RetFloat tanh( Float const x );
	SDW_API RetVec2 tanh( Vec2 const x );
	SDW_API RetVec3 tanh( Vec3 const x );
	SDW_API RetVec4 tanh( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region acos
	/**
	*name
	*	acos
	*/
	/**@{*/
	SDW_API RetFloat acos( Float const x );
	SDW_API RetVec2 acos( Vec2 const x );
	SDW_API RetVec3 acos( Vec3 const x );
	SDW_API RetVec4 acos( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region asin
	/**
	*name
	*	asin
	*/
	/**@{*/
	SDW_API RetFloat asin( Float const x );
	SDW_API RetVec2 asin( Vec2 const x );
	SDW_API RetVec3 asin( Vec3 const x );
	SDW_API RetVec4 asin( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region atan
	/**
	*name
	*	atan
	*/
	/**@{*/
	SDW_API RetFloat atan( Float const y_over_x );
	SDW_API RetVec2 atan( Vec2 const y_over_x );
	SDW_API RetVec3 atan( Vec3 const y_over_x );
	SDW_API RetVec4 atan( Vec4 const y_over_x );
	/**@}*/
#pragma endregion
#pragma region atan2
	/**
	*name
	*	atan2
	*/
	/**@{*/
	SDW_API RetFloat atan2( Float const y, Float const x );
	SDW_API RetVec2 atan2( Vec2 const y, Vec2 const x );
	SDW_API RetVec3 atan2( Vec3 const y, Vec3 const x );
	SDW_API RetVec4 atan2( Vec4 const y, Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region acosh
	/**
	*name
	*	acosh
	*/
	/**@{*/
	SDW_API RetFloat acosh( Float const x );
	SDW_API RetVec2 acosh( Vec2 const x );
	SDW_API RetVec3 acosh( Vec3 const x );
	SDW_API RetVec4 acosh( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region asinh
	/**
	*name
	*	asinh
	*/
	/**@{*/
	SDW_API RetFloat asinh( Float const x );
	SDW_API RetVec2 asinh( Vec2 const x );
	SDW_API RetVec3 asinh( Vec3 const x );
	SDW_API RetVec4 asinh( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region atanh
	/**
	*name
	*	atanh
	*/
	/**@{*/
	SDW_API RetFloat atanh( Float const x );
	SDW_API RetVec2 atanh( Vec2 const x );
	SDW_API RetVec3 atanh( Vec3 const x );
	SDW_API RetVec4 atanh( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region pow
	/**
	*name
	*	pow
	*/
	/**@{*/
	SDW_API RetFloat pow( Float const x, Float const y );
	SDW_API RetVec2 pow( Vec2 const x, Vec2 const y );
	SDW_API RetVec3 pow( Vec3 const x, Vec3 const y );
	SDW_API RetVec4 pow( Vec4 const x, Vec4 const y );
	/**@}*/
#pragma endregion
#pragma region exp
	/**
	*name
	*	exp
	*/
	/**@{*/
	SDW_API RetFloat exp( Float const x );
	SDW_API RetVec2 exp( Vec2 const x );
	SDW_API RetVec3 exp( Vec3 const x );
	SDW_API RetVec4 exp( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region log
	/**
	*name
	*	log
	*/
	/**@{*/
	SDW_API RetFloat log( Float const x );
	SDW_API RetVec2 log( Vec2 const x );
	SDW_API RetVec3 log( Vec3 const x );
	SDW_API RetVec4 log( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region exp2
	/**
	*name
	*	exp2
	*/
	/**@{*/
	SDW_API RetFloat exp2( Float const x );
	SDW_API RetVec2 exp2( Vec2 const x );
	SDW_API RetVec3 exp2( Vec3 const x );
	SDW_API RetVec4 exp2( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region log2
	/**
	*name
	*	log2
	*/
	/**@{*/
	SDW_API RetFloat log2( Float const x );
	SDW_API RetVec2 log2( Vec2 const x );
	SDW_API RetVec3 log2( Vec3 const x );
	SDW_API RetVec4 log2( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region sqrt
	/**
	*name
	*	sqrt
	*/
	/**@{*/
	SDW_API RetFloat sqrt( Float const x );
	SDW_API RetVec2 sqrt( Vec2 const x );
	SDW_API RetVec3 sqrt( Vec3 const x );
	SDW_API RetVec4 sqrt( Vec4 const x );
	SDW_API RetDouble sqrt( Double const x );
	SDW_API RetDVec2 sqrt( DVec2 const x );
	SDW_API RetDVec3 sqrt( DVec3 const x );
	SDW_API RetDVec4 sqrt( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region inverseSqrt
	/**
	*name
	*	inverseSqrt
	*/
	/**@{*/
	SDW_API RetFloat inverseSqrt( Float const x );
	SDW_API RetVec2 inverseSqrt( Vec2 const x );
	SDW_API RetVec3 inverseSqrt( Vec3 const x );
	SDW_API RetVec4 inverseSqrt( Vec4 const x );
	SDW_API RetDouble inverseSqrt( Double const x );
	SDW_API RetDVec2 inverseSqrt( DVec2 const x );
	SDW_API RetDVec3 inverseSqrt( DVec3 const x );
	SDW_API RetDVec4 inverseSqrt( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region abs
	/**
	*name
	*	abs
	*/
	/**@{*/
	SDW_API RetFloat abs( Float const x );
	SDW_API RetVec2 abs( Vec2 const x );
	SDW_API RetVec3 abs( Vec3 const x );
	SDW_API RetVec4 abs( Vec4 const x );
	SDW_API RetInt32 abs( Int32 const x );
	SDW_API RetI32Vec2 abs( I32Vec2 const x );
	SDW_API RetI32Vec3 abs( I32Vec3 const x );
	SDW_API RetI32Vec4 abs( I32Vec4 const x );
	SDW_API RetDouble abs( Double const x );
	SDW_API RetDVec2 abs( DVec2 const x );
	SDW_API RetDVec3 abs( DVec3 const x );
	SDW_API RetDVec4 abs( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region sign
	/**
	*name
	*	sign
	*/
	/**@{*/
	SDW_API RetFloat sign( Float const x );
	SDW_API RetVec2 sign( Vec2 const x );
	SDW_API RetVec3 sign( Vec3 const x );
	SDW_API RetVec4 sign( Vec4 const x );
	SDW_API RetInt32 sign( Int32 const x );
	SDW_API RetI32Vec2 sign( I32Vec2 const x );
	SDW_API RetI32Vec3 sign( I32Vec3 const x );
	SDW_API RetI32Vec4 sign( I32Vec4 const x );
	SDW_API RetDouble sign( Double const x );
	SDW_API RetDVec2 sign( DVec2 const x );
	SDW_API RetDVec3 sign( DVec3 const x );
	SDW_API RetDVec4 sign( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region floor
	/**
	*name
	*	floor
	*/
	/**@{*/
	SDW_API RetFloat floor( Float const x );
	SDW_API RetVec2 floor( Vec2 const x );
	SDW_API RetVec3 floor( Vec3 const x );
	SDW_API RetVec4 floor( Vec4 const x );
	SDW_API RetDouble floor( Double const x );
	SDW_API RetDVec2 floor( DVec2 const x );
	SDW_API RetDVec3 floor( DVec3 const x );
	SDW_API RetDVec4 floor( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region trunc
	/**
	*name
	*	trunc
	*/
	/**@{*/
	SDW_API RetFloat trunc( Float const x );
	SDW_API RetVec2 trunc( Vec2 const x );
	SDW_API RetVec3 trunc( Vec3 const x );
	SDW_API RetVec4 trunc( Vec4 const x );
	SDW_API RetDouble trunc( Double const x );
	SDW_API RetDVec2 trunc( DVec2 const x );
	SDW_API RetDVec3 trunc( DVec3 const x );
	SDW_API RetDVec4 trunc( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region round
	/**
	*name
	*	round
	*/
	/**@{*/
	SDW_API RetFloat round( Float const x );
	SDW_API RetVec2 round( Vec2 const x );
	SDW_API RetVec3 round( Vec3 const x );
	SDW_API RetVec4 round( Vec4 const x );
	SDW_API RetDouble round( Double const x );
	SDW_API RetDVec2 round( DVec2 const x );
	SDW_API RetDVec3 round( DVec3 const x );
	SDW_API RetDVec4 round( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region roundEven
	/**
	*name
	*	roundEven
	*/
	/**@{*/
	SDW_API RetFloat roundEven( Float const x );
	SDW_API RetVec2 roundEven( Vec2 const x );
	SDW_API RetVec3 roundEven( Vec3 const x );
	SDW_API RetVec4 roundEven( Vec4 const x );
	SDW_API RetDouble roundEven( Double const x );
	SDW_API RetDVec2 roundEven( DVec2 const x );
	SDW_API RetDVec3 roundEven( DVec3 const x );
	SDW_API RetDVec4 roundEven( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region ceil
	/**
	*name
	*	ceil
	*/
	/**@{*/
	SDW_API RetFloat ceil( Float const x );
	SDW_API RetVec2 ceil( Vec2 const x );
	SDW_API RetVec3 ceil( Vec3 const x );
	SDW_API RetVec4 ceil( Vec4 const x );
	SDW_API RetDouble ceil( Double const x );
	SDW_API RetDVec2 ceil( DVec2 const x );
	SDW_API RetDVec3 ceil( DVec3 const x );
	SDW_API RetDVec4 ceil( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region fract
	/**
	*name
	*	fract
	*/
	/**@{*/
	SDW_API RetFloat fract( Float const x );
	SDW_API RetVec2 fract( Vec2 const x );
	SDW_API RetVec3 fract( Vec3 const x );
	SDW_API RetVec4 fract( Vec4 const x );
	SDW_API RetDouble fract( Double const x );
	SDW_API RetDVec2 fract( DVec2 const x );
	SDW_API RetDVec3 fract( DVec3 const x );
	SDW_API RetDVec4 fract( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region mod
	/**
	*name
	*	mod
	*/
	/**@{*/
	SDW_API RetFloat mod( Float const x, Float const y );
	SDW_API RetVec2 mod( Vec2 const x, Vec2 const y );
	SDW_API RetVec3 mod( Vec3 const x, Vec3 const y );
	SDW_API RetVec4 mod( Vec4 const x, Vec4 const y );
	SDW_API RetDouble mod( Double const x, Double const y );
	SDW_API RetDVec2 mod( DVec2 const x, DVec2 const y );
	SDW_API RetDVec3 mod( DVec3 const x, DVec3 const y );
	SDW_API RetDVec4 mod( DVec4 const x, DVec4 const y );
	/**@}*/
#pragma endregion
#pragma region modf
	/**
	*name
	*	modf
	*/
	/**@{*/
	SDW_API RetFloat modf( Float const x, Float const i );
	SDW_API RetVec2 modf( Vec2 const x, Vec2 const i );
	SDW_API RetVec3 modf( Vec3 const x, Vec3 const i );
	SDW_API RetVec4 modf( Vec4 const x, Vec4 const i );
	SDW_API RetDouble modf( Double const x, Double const i );
	SDW_API RetDVec2 modf( DVec2 const x, DVec2 const i );
	SDW_API RetDVec3 modf( DVec3 const x, DVec3 const i );
	SDW_API RetDVec4 modf( DVec4 const x, DVec4 const i );
	/**@}*/
#pragma endregion
#pragma region min
	/**
	*name
	*	min
	*/
	/**@{*/
	SDW_API RetFloat min( Float const x, Float const y );
	SDW_API RetVec2 min( Vec2 const x, Vec2 const y );
	SDW_API RetVec3 min( Vec3 const x, Vec3 const y );
	SDW_API RetVec4 min( Vec4 const x, Vec4 const y );
	SDW_API RetDouble min( Double const x, Double const y );
	SDW_API RetDVec2 min( DVec2 const x, DVec2 const y );
	SDW_API RetDVec3 min( DVec3 const x, DVec3 const y );
	SDW_API RetDVec4 min( DVec4 const x, DVec4 const y );
	SDW_API RetInt32 min( Int32 const x, Int32 const y );
	SDW_API RetI32Vec2 min( I32Vec2 const x, I32Vec2 const y );
	SDW_API RetI32Vec3 min( I32Vec3 const x, I32Vec3 const y );
	SDW_API RetI32Vec4 min( I32Vec4 const x, I32Vec4 const y );
	SDW_API RetUInt32 min( UInt32 const x, UInt32 const y );
	SDW_API RetU32Vec2 min( U32Vec2 const x, U32Vec2 const y );
	SDW_API RetU32Vec3 min( U32Vec3 const x, U32Vec3 const y );
	SDW_API RetU32Vec4 min( U32Vec4 const x, U32Vec4 const y );
	/**@}*/
#pragma endregion
#pragma region max
	/**
	*name
	*	max
	*/
	/**@{*/
	SDW_API RetFloat max( Float const x, Float const y );
	SDW_API RetVec2 max( Vec2 const x, Vec2 const y );
	SDW_API RetVec3 max( Vec3 const x, Vec3 const y );
	SDW_API RetVec4 max( Vec4 const x, Vec4 const y );
	SDW_API RetDouble max( Double const x, Double const y );
	SDW_API RetDVec2 max( DVec2 const x, DVec2 const y );
	SDW_API RetDVec3 max( DVec3 const x, DVec3 const y );
	SDW_API RetDVec4 max( DVec4 const x, DVec4 const y );
	SDW_API RetInt32 max( Int32 const x, Int32 const y );
	SDW_API RetI32Vec2 max( I32Vec2 const x, I32Vec2 const y );
	SDW_API RetI32Vec3 max( I32Vec3 const x, I32Vec3 const y );
	SDW_API RetI32Vec4 max( I32Vec4 const x, I32Vec4 const y );
	SDW_API RetUInt32 max( UInt32 const x, UInt32 const y );
	SDW_API RetU32Vec2 max( U32Vec2 const x, U32Vec2 const y );
	SDW_API RetU32Vec3 max( U32Vec3 const x, U32Vec3 const y );
	SDW_API RetU32Vec4 max( U32Vec4 const x, U32Vec4 const y );
	/**@}*/
#pragma endregion
#pragma region clamp
	/**
	*name
	*	clamp
	*/
	/**@{*/
	SDW_API RetFloat clamp( Float const x, Float const minVal, Float const maxVal );
	SDW_API RetVec2 clamp( Vec2 const x, Vec2 const minVal, Vec2 const maxVal );
	SDW_API RetVec3 clamp( Vec3 const x, Vec3 const minVal, Vec3 const maxVal );
	SDW_API RetVec4 clamp( Vec4 const x, Vec4 const minVal, Vec4 const maxVal );
	SDW_API RetDouble clamp( Double const x, Double const minVal, Double const maxVal );
	SDW_API RetDVec2 clamp( DVec2 const x, DVec2 const minVal, DVec2 const maxVal );
	SDW_API RetDVec3 clamp( DVec3 const x, DVec3 const minVal, DVec3 const maxVal );
	SDW_API RetDVec4 clamp( DVec4 const x, DVec4 const minVal, DVec4 const maxVal );
	SDW_API RetInt32 clamp( Int32 const x, Int32 const minVal, Int32 const maxVal );
	SDW_API RetI32Vec2 clamp( I32Vec2 const x, I32Vec2 const minVal, I32Vec2 const maxVal );
	SDW_API RetI32Vec3 clamp( I32Vec3 const x, I32Vec3 const minVal, I32Vec3 const maxVal );
	SDW_API RetI32Vec4 clamp( I32Vec4 const x, I32Vec4 const minVal, I32Vec4 const maxVal );
	SDW_API RetUInt32 clamp( UInt32 const x, UInt32 const minVal, UInt32 const maxVal );
	SDW_API RetU32Vec2 clamp( U32Vec2 const x, U32Vec2 const minVal, U32Vec2 const maxVal );
	SDW_API RetU32Vec3 clamp( U32Vec3 const x, U32Vec3 const minVal, U32Vec3 const maxVal );
	SDW_API RetU32Vec4 clamp( U32Vec4 const x, U32Vec4 const minVal, U32Vec4 const maxVal );
	/**@}*/
#pragma endregion
#pragma region mix
	/**
	*name
	*	mix
	*/
	/**@{*/
	SDW_API RetFloat mix( Float const x, Float const y, Float const a );
	SDW_API RetVec2 mix( Vec2 const x, Vec2 const y, Vec2 const a );
	SDW_API RetVec3 mix( Vec3 const x, Vec3 const y, Vec3 const a );
	SDW_API RetVec4 mix( Vec4 const x, Vec4 const y, Vec4 const a );
	SDW_API RetDouble mix( Double const x, Double const y, Double const a );
	SDW_API RetDVec2 mix( DVec2 const x, DVec2 const y, DVec2 const a );
	SDW_API RetDVec3 mix( DVec3 const x, DVec3 const y, DVec3 const a );
	SDW_API RetDVec4 mix( DVec4 const x, DVec4 const y, DVec4 const a );
	/**@}*/
#pragma endregion
#pragma region step
	/**
	*name
	*	step
	*/
	/**@{*/
	SDW_API RetFloat step( Float const edge, Float const x );
	SDW_API RetVec2 step( Vec2 const edge, Vec2 const x );
	SDW_API RetVec3 step( Vec3 const edge, Vec3 const x );
	SDW_API RetVec4 step( Vec4 const edge, Vec4 const x );
	SDW_API RetDouble step( Double const edge, Double const x );
	SDW_API RetDVec2 step( DVec2 const edge, DVec2 const x );
	SDW_API RetDVec3 step( DVec3 const edge, DVec3 const x );
	SDW_API RetDVec4 step( DVec4 const edge, DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region smoothStep
	/**
	*name
	*	smoothStep
	*/
	/**@{*/
	SDW_API RetFloat smoothStep( Float const edge0, Float const edge1, Float const x );
	SDW_API RetVec2 smoothStep( Vec2 const edge0, Vec2 const edge1, Vec2 const x );
	SDW_API RetVec3 smoothStep( Vec3 const edge0, Vec3 const edge1, Vec3 const x );
	SDW_API RetVec4 smoothStep( Vec4 const edge0, Vec4 const edge1, Vec4 const x );
	SDW_API RetDouble smoothStep( Double const edge0, Double const edge1, Double const x );
	SDW_API RetDVec2 smoothStep( DVec2 const edge0, DVec2 const edge1, DVec2 const x );
	SDW_API RetDVec3 smoothStep( DVec3 const edge0, DVec3 const edge1, DVec3 const x );
	SDW_API RetDVec4 smoothStep( DVec4 const edge0, DVec4 const edge1, DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region isnan
	/**
	*name
	*	isnan
	*/
	/**@{*/
	SDW_API RetBoolean isnan( Float const x );
	SDW_API RetBVec2 isnan( Vec2 const x );
	SDW_API RetBVec3 isnan( Vec3 const x );
	SDW_API RetBVec4 isnan( Vec4 const x );
	SDW_API RetBoolean isnan( Double const x );
	SDW_API RetBVec2 isnan( DVec2 const x );
	SDW_API RetBVec3 isnan( DVec3 const x );
	SDW_API RetBVec4 isnan( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region isinf
	/**
	*name
	*	isinf
	*/
	/**@{*/
	SDW_API RetBoolean isinf( Float const x );
	SDW_API RetBVec2 isinf( Vec2 const x );
	SDW_API RetBVec3 isinf( Vec3 const x );
	SDW_API RetBVec4 isinf( Vec4 const x );
	SDW_API RetBoolean isinf( Double const x );
	SDW_API RetBVec2 isinf( DVec2 const x );
	SDW_API RetBVec3 isinf( DVec3 const x );
	SDW_API RetBVec4 isinf( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region floatBitsToInt
	/**
	*name
	*	floatBitsToInt
	*/
	/**@{*/
	SDW_API RetInt32 floatBitsToInt( Float const value );
	SDW_API RetI32Vec2 floatBitsToInt( Vec2 const value );
	SDW_API RetI32Vec3 floatBitsToInt( Vec3 const value );
	SDW_API RetI32Vec4 floatBitsToInt( Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region floatBitsToUInt
	/**
	*name
	*	floatBitsToUInt
	*/
	/**@{*/
	SDW_API RetUInt32 floatBitsToUInt( Float const value );
	SDW_API RetU32Vec2 floatBitsToUInt( Vec2 const value );
	SDW_API RetU32Vec3 floatBitsToUInt( Vec3 const value );
	SDW_API RetU32Vec4 floatBitsToUInt( Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region intBitsToFloat
	/**
	*name
	*	intBitsToFloat
	*/
	/**@{*/
	SDW_API RetFloat intBitsToFloat( Int32 const x );
	SDW_API RetVec2 intBitsToFloat( I32Vec2 const x );
	SDW_API RetVec3 intBitsToFloat( I32Vec3 const x );
	SDW_API RetVec4 intBitsToFloat( I32Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region uintBitsToFloat
	/**
	*name
	*	uintBitsToFloat
	*/
	/**@{*/
	SDW_API RetFloat uintBitsToFloat( UInt32 const x );
	SDW_API RetVec2 uintBitsToFloat( U32Vec2 const x );
	SDW_API RetVec3 uintBitsToFloat( U32Vec3 const x );
	SDW_API RetVec4 uintBitsToFloat( U32Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region fma
	/**
	*name
	*	fma
	*/
	/**@{*/
	SDW_API RetFloat fma( Float const a, Float const b, Float const c );
	SDW_API RetVec2 fma( Vec2 const a, Vec2 const b, Vec2 const c );
	SDW_API RetVec3 fma( Vec3 const a, Vec3 const b, Vec3 const c );
	SDW_API RetVec4 fma( Vec4 const a, Vec4 const b, Vec4 const c );
	SDW_API RetDouble fma( Double const a, Double const b, Double const c );
	SDW_API RetDVec2 fma( DVec2 const a, DVec2 const b, DVec2 const c );
	SDW_API RetDVec3 fma( DVec3 const a, DVec3 const b, DVec3 const c );
	SDW_API RetDVec4 fma( DVec4 const a, DVec4 const b, DVec4 const c );
	/**@}*/
#pragma endregion
#pragma region frexp
	/**
	*name
	*	frexp
	*/
	/**@{*/
	SDW_API RetFloat frexp( Float const x, Int32 exp );
	SDW_API RetVec2 frexp( Vec2 const x, I32Vec2 exp );
	SDW_API RetVec3 frexp( Vec3 const x, I32Vec3 exp );
	SDW_API RetVec4 frexp( Vec4 const x, I32Vec4 exp );
	SDW_API RetDouble frexp( Double const x, Int32 exp );
	SDW_API RetDVec2 frexp( DVec2 const x, I32Vec2 exp );
	SDW_API RetDVec3 frexp( DVec3 const x, I32Vec3 exp );
	SDW_API RetDVec4 frexp( DVec4 const x, I32Vec4 exp );
	/**@}*/
#pragma endregion
#pragma region ldexp
	/**
	*name
	*	ldexp
	*/
	/**@{*/
	SDW_API RetFloat ldexp( Float const x, Int32 const exp );
	SDW_API RetVec2 ldexp( Vec2 const x, I32Vec2 const exp );
	SDW_API RetVec3 ldexp( Vec3 const x, I32Vec3 const exp );
	SDW_API RetVec4 ldexp( Vec4 const x, I32Vec4 const exp );
	SDW_API RetDouble ldexp( Double const x, Int32 const exp );
	SDW_API RetDVec2 ldexp( DVec2 const x, I32Vec2 const exp );
	SDW_API RetDVec3 ldexp( DVec3 const x, I32Vec3 const exp );
	SDW_API RetDVec4 ldexp( DVec4 const x, I32Vec4 const exp );
	/**@}*/
#pragma endregion
#pragma region packDouble2x32
	/**
	*name
	*	packDouble2x32
	*/
	/**@{*/
	SDW_API RetDouble packDouble2x32( U32Vec2 const v );
	/**@}*/
#pragma endregion
#pragma region packHalf2x16
	/**
	*name
	*	packHalf2x16
	*/
	/**@{*/
	SDW_API RetUInt32 packHalf2x16( Vec2 const v );
	/**@}*/
#pragma endregion
#pragma region packSnorm2x16
	/**
	*name
	*	packSnorm2x16
	*/
	/**@{*/
	SDW_API RetUInt32 packSnorm2x16( Vec2 const v );
	/**@}*/
#pragma endregion
#pragma region packSnorm4x8
	/**
	*name
	*	packSnorm4x8
	*/
	/**@{*/
	SDW_API RetUInt32 packSnorm4x8( Vec4 const v );
	/**@}*/
#pragma endregion
#pragma region packUnorm2x16
	/**
	*name
	*	packUnorm2x16
	*/
	/**@{*/
	SDW_API RetUInt32 packUnorm2x16( Vec2 const v );
	/**@}*/
#pragma endregion
#pragma region packUnorm4x8
	/**
	*name
	*	packUnorm4x8
	*/
	/**@{*/
	SDW_API RetUInt32 packUnorm4x8( Vec4 const v );
	/**@}*/
#pragma endregion
#pragma region unpackDouble2x32
	/**
	*name
	*	unpackDouble2x32
	*/
	/**@{*/
	SDW_API RetU32Vec2 unpackDouble2x32( Double const d );
	/**@}*/
#pragma endregion
#pragma region unpackHalf2x16
	/**
	*name
	*	unpackHalf2x16
	*/
	/**@{*/
	SDW_API RetVec2 unpackHalf2x16( UInt32 const v );
	/**@}*/
#pragma endregion
#pragma region unpackSnorm2x16
	/**
	*name
	*	unpackSnorm2x16
	*/
	/**@{*/
	SDW_API RetVec2 unpackSnorm2x16( UInt32 const p );
	/**@}*/
#pragma endregion
#pragma region unpackSnorm4x8
	/**
	*name
	*	unpackSnorm4x8
	*/
	/**@{*/
	SDW_API RetVec4 unpackSnorm4x8( UInt32 const p );
	/**@}*/
#pragma endregion
#pragma region unpackUnorm2x16
	/**
	*name
	*	unpackUnorm2x16
	*/
	/**@{*/
	SDW_API RetVec2 unpackUnorm2x16( UInt32 const p );
	/**@}*/
#pragma endregion
#pragma region unpackUnorm4x8
	/**
	*name
	*	unpackUnorm4x8
	*/
	/**@{*/
	SDW_API RetVec4 unpackUnorm4x8( UInt32 const p );
	/**@}*/
#pragma endregion
#pragma region length
	/**
	*name
	*	length
	*/
	/**@{*/
	SDW_API RetFloat length( Float const x );
	SDW_API RetFloat length( Vec2 const x );
	SDW_API RetFloat length( Vec3 const x );
	SDW_API RetFloat length( Vec4 const x );
	SDW_API RetDouble length( Double const x );
	SDW_API RetDouble length( DVec2 const x );
	SDW_API RetDouble length( DVec3 const x );
	SDW_API RetDouble length( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region distance
	/**
	*name
	*	distance
	*/
	/**@{*/
	SDW_API RetFloat distance( Float const p0, Float const p1 );
	SDW_API RetFloat distance( Vec2 const p0, Vec2 const p1 );
	SDW_API RetFloat distance( Vec3 const p0, Vec3 const p1 );
	SDW_API RetFloat distance( Vec4 const p0, Vec4 const p1 );
	SDW_API RetDouble distance( Double const p0, Double const p1 );
	SDW_API RetDouble distance( DVec2 const p0, DVec2 const p1 );
	SDW_API RetDouble distance( DVec3 const p0, DVec3 const p1 );
	SDW_API RetDouble distance( DVec4 const p0, DVec4 const p1 );
	/**@}*/
#pragma endregion
#pragma region dot
	/**
	*name
	*	dot
	*/
	/**@{*/
	SDW_API RetFloat dot( Float const x, Float const y );
	SDW_API RetFloat dot( Vec2 const x, Vec2 const y );
	SDW_API RetFloat dot( Vec3 const x, Vec3 const y );
	SDW_API RetFloat dot( Vec4 const x, Vec4 const y );
	SDW_API RetDouble dot( Double const x, Double const y );
	SDW_API RetDouble dot( DVec2 const x, DVec2 const y );
	SDW_API RetDouble dot( DVec3 const x, DVec3 const y );
	SDW_API RetDouble dot( DVec4 const x, DVec4 const y );
	/**@}*/
#pragma endregion
#pragma region cross
	/**
	*name
	*	cross
	*/
	/**@{*/
	SDW_API RetVec3 cross( Vec3 const x, Vec3 const y );
	SDW_API RetDVec3 cross( DVec3 const x, DVec3 const y );
	/**@}*/
#pragma endregion
#pragma region normalize
	/**
	*name
	*	normalize
	*/
	/**@{*/
	SDW_API RetFloat normalize( Float const x );
	SDW_API RetVec2 normalize( Vec2 const x );
	SDW_API RetVec3 normalize( Vec3 const x );
	SDW_API RetVec4 normalize( Vec4 const x );
	SDW_API RetDouble normalize( Double const x );
	SDW_API RetDVec2 normalize( DVec2 const x );
	SDW_API RetDVec3 normalize( DVec3 const x );
	SDW_API RetDVec4 normalize( DVec4 const x );
	/**@}*/
#pragma endregion
#pragma region faceForward
	/**
	*name
	*	faceForward
	*/
	/**@{*/
	SDW_API RetFloat faceForward( Float const N, Float const I, Float const Nref );
	SDW_API RetVec2 faceForward( Vec2 const N, Vec2 const I, Vec2 const Nref );
	SDW_API RetVec3 faceForward( Vec3 const N, Vec3 const I, Vec3 const Nref );
	SDW_API RetVec4 faceForward( Vec4 const N, Vec4 const I, Vec4 const Nref );
	SDW_API RetDouble faceForward( Double const N, Double const I, Double const Nref );
	SDW_API RetDVec2 faceForward( DVec2 const N, DVec2 const I, DVec2 const Nref );
	SDW_API RetDVec3 faceForward( DVec3 const N, DVec3 const I, DVec3 const Nref );
	SDW_API RetDVec4 faceForward( DVec4 const N, DVec4 const I, DVec4 const Nref );
	/**@}*/
#pragma endregion
#pragma region reflect
	/**
	*name
	*	reflect
	*/
	/**@{*/
	SDW_API RetFloat reflect( Float const I, Float const N );
	SDW_API RetVec2 reflect( Vec2 const I, Vec2 const N );
	SDW_API RetVec3 reflect( Vec3 const I, Vec3 const N );
	SDW_API RetVec4 reflect( Vec4 const I, Vec4 const N );
	SDW_API RetDouble reflect( Double const I, Double const N );
	SDW_API RetDVec2 reflect( DVec2 const I, DVec2 const N );
	SDW_API RetDVec3 reflect( DVec3 const I, DVec3 const N );
	SDW_API RetDVec4 reflect( DVec4 const I, DVec4 const N );
	/**@}*/
#pragma endregion
#pragma region refract
	/**
	*name
	*	refract
	*/
	/**@{*/
	SDW_API RetFloat refract( Float const I, Float const N, Float const eta );
	SDW_API RetVec2 refract( Vec2 const I, Vec2 const N, Float const eta );
	SDW_API RetVec3 refract( Vec3 const I, Vec3 const N, Float const eta );
	SDW_API RetVec4 refract( Vec4 const I, Vec4 const N, Float const eta );
	SDW_API RetDouble refract( Double const I, Double const N, Float const eta );
	SDW_API RetDVec2 refract( DVec2 const I, DVec2 const N, Float const eta );
	SDW_API RetDVec3 refract( DVec3 const I, DVec3 const N, Float const eta );
	SDW_API RetDVec4 refract( DVec4 const I, DVec4 const N, Float const eta );
	/**@}*/
#pragma endregion
#pragma region matrixCompMult
	/**
	*name
	*	matrixCompMult
	*/
	/**@{*/
	SDW_API RetMat2 matrixCompMult( Mat2 const x, Mat2 const y );
	SDW_API RetMat2x3 matrixCompMult( Mat2x3 const x, Mat2x3 const y );
	SDW_API RetMat2x4 matrixCompMult( Mat2x4 const x, Mat2x4 const y );
	SDW_API RetMat3x2 matrixCompMult( Mat3x2 const x, Mat3x2 const y );
	SDW_API RetMat3 matrixCompMult( Mat3 const x, Mat3 const y );
	SDW_API RetMat3x4 matrixCompMult( Mat3x4 const x, Mat3x4 const y );
	SDW_API RetMat4x2 matrixCompMult( Mat4x2 const x, Mat4x2 const y );
	SDW_API RetMat4x3 matrixCompMult( Mat4x3 const x, Mat4x3 const y );
	SDW_API RetMat4 matrixCompMult( Mat4 const x, Mat4 const y );
	SDW_API RetDMat2 matrixCompMult( DMat2 const x, DMat2 const y );
	SDW_API RetDMat2x3 matrixCompMult( DMat2x3 const x, DMat2x3 const y );
	SDW_API RetDMat2x4 matrixCompMult( DMat2x4 const x, DMat2x4 const y );
	SDW_API RetDMat3x2 matrixCompMult( DMat3x2 const x, DMat3x2 const y );
	SDW_API RetDMat3 matrixCompMult( DMat3 const x, DMat3 const y );
	SDW_API RetDMat3x4 matrixCompMult( DMat3x4 const x, DMat3x4 const y );
	SDW_API RetDMat4x2 matrixCompMult( DMat4x2 const x, DMat4x2 const y );
	SDW_API RetDMat4x3 matrixCompMult( DMat4x3 const x, DMat4x3 const y );
	SDW_API RetDMat4 matrixCompMult( DMat4 const x, DMat4 const y );
	/**@}*/
#pragma endregion
#pragma region outerProduct
	/**
	*name
	*	outerProduct
	*/
	/**@{*/
	SDW_API RetMat2 outerProduct( Vec2 const c, Vec2 const r );
	SDW_API RetMat3 outerProduct( Vec3 const c, Vec3 const r );
	SDW_API RetMat4 outerProduct( Vec4 const c, Vec4 const r );
	SDW_API RetMat2x3 outerProduct( Vec3 const c, Vec2 const r );
	SDW_API RetMat3x2 outerProduct( Vec2 const c, Vec3 const r );
	SDW_API RetMat2x4 outerProduct( Vec4 const c, Vec2 const r );
	SDW_API RetMat4x2 outerProduct( Vec2 const c, Vec4 const r );
	SDW_API RetMat3x4 outerProduct( Vec4 const c, Vec3 const r );
	SDW_API RetMat4x3 outerProduct( Vec3 const c, Vec4 const r );
	SDW_API RetDMat2 outerProduct( DVec2 const c, DVec2 const r );
	SDW_API RetDMat3 outerProduct( DVec3 const c, DVec3 const r );
	SDW_API RetDMat4 outerProduct( DVec4 const c, DVec4 const r );
	SDW_API RetDMat2x3 outerProduct( DVec3 const c, DVec2 const r );
	SDW_API RetDMat3x2 outerProduct( DVec2 const c, DVec3 const r );
	SDW_API RetDMat2x4 outerProduct( DVec4 const c, DVec2 const r );
	SDW_API RetDMat4x2 outerProduct( DVec2 const c, DVec4 const r );
	SDW_API RetDMat3x4 outerProduct( DVec4 const c, DVec3 const r );
	SDW_API RetDMat4x3 outerProduct( DVec3 const c, DVec4 const r );
	/**@}*/
#pragma endregion
#pragma region transpose
	/**
	*name
	*	transpose
	*/
	/**@{*/
	SDW_API RetMat2 transpose( Mat2 const x );
	SDW_API RetMat3x2 transpose( Mat2x3 const x );
	SDW_API RetMat4x2 transpose( Mat2x4 const x );
	SDW_API RetMat2x3 transpose( Mat3x2 const x );
	SDW_API RetMat3 transpose( Mat3 const x );
	SDW_API RetMat4x3 transpose( Mat3x4 const x );
	SDW_API RetMat2x4 transpose( Mat4x2 const x );
	SDW_API RetMat3x4 transpose( Mat4x3 const x );
	SDW_API RetMat4 transpose( Mat4 const x );
	SDW_API RetDMat2 transpose( DMat2 const x );
	SDW_API RetDMat3x2 transpose( DMat2x3 const x );
	SDW_API RetDMat4x2 transpose( DMat2x4 const x );
	SDW_API RetDMat2x3 transpose( DMat3x2 const x );
	SDW_API RetDMat3 transpose( DMat3 const x );
	SDW_API RetDMat4x3 transpose( DMat3x4 const x );
	SDW_API RetDMat2x4 transpose( DMat4x2 const x );
	SDW_API RetDMat3x4 transpose( DMat4x3 const x );
	SDW_API RetDMat4 transpose( DMat4 const x );
	/**@}*/
#pragma endregion
#pragma region determinant
	/**
	*name
	*	determinant
	*/
	/**@{*/
	SDW_API RetFloat determinant( Mat2 const m );
	SDW_API RetFloat determinant( Mat3 const m );
	SDW_API RetFloat determinant( Mat4 const m );
	SDW_API RetDouble determinant( DMat2 const m );
	SDW_API RetDouble determinant( DMat3 const m );
	SDW_API RetDouble determinant( DMat4 const m );
	/**@}*/
#pragma endregion
#pragma region inverse
	/**
	*name
	*	inverse
	*/
	/**@{*/
	SDW_API RetMat2 inverse( Mat2 const m );
	SDW_API RetMat3 inverse( Mat3 const m );
	SDW_API RetMat4 inverse( Mat4 const m );
	SDW_API RetDMat2 inverse( DMat2 const m );
	SDW_API RetDMat3 inverse( DMat3 const m );
	SDW_API RetDMat4 inverse( DMat4 const m );
	/**@}*/
#pragma endregion
#pragma region lessThan
	/**
	*name
	*	lessThan
	*/
	/**@{*/
	SDW_API RetBVec2 lessThan( Vec2 const x, Vec2 const y );
	SDW_API RetBVec3 lessThan( Vec3 const x, Vec3 const y );
	SDW_API RetBVec4 lessThan( Vec4 const x, Vec4 const y );
	SDW_API RetBVec2 lessThan( DVec2 const x, DVec2 const y );
	SDW_API RetBVec3 lessThan( DVec3 const x, DVec3 const y );
	SDW_API RetBVec4 lessThan( DVec4 const x, DVec4 const y );
	SDW_API RetBVec2 lessThan( I32Vec2 const x, I32Vec2 const y );
	SDW_API RetBVec3 lessThan( I32Vec3 const x, I32Vec3 const y );
	SDW_API RetBVec4 lessThan( I32Vec4 const x, I32Vec4 const y );
	SDW_API RetBVec2 lessThan( U32Vec2 const x, U32Vec2 const y );
	SDW_API RetBVec3 lessThan( U32Vec3 const x, U32Vec3 const y );
	SDW_API RetBVec4 lessThan( U32Vec4 const x, U32Vec4 const y );
	/**@}*/
#pragma endregion
#pragma region lessThanEqual
	/**
	*name
	*	lessThanEqual
	*/
	/**@{*/
	SDW_API RetBVec2 lessThanEqual( Vec2 const x, Vec2 const y );
	SDW_API RetBVec3 lessThanEqual( Vec3 const x, Vec3 const y );
	SDW_API RetBVec4 lessThanEqual( Vec4 const x, Vec4 const y );
	SDW_API RetBVec2 lessThanEqual( DVec2 const x, DVec2 const y );
	SDW_API RetBVec3 lessThanEqual( DVec3 const x, DVec3 const y );
	SDW_API RetBVec4 lessThanEqual( DVec4 const x, DVec4 const y );
	SDW_API RetBVec2 lessThanEqual( I32Vec2 const x, I32Vec2 const y );
	SDW_API RetBVec3 lessThanEqual( I32Vec3 const x, I32Vec3 const y );
	SDW_API RetBVec4 lessThanEqual( I32Vec4 const x, I32Vec4 const y );
	SDW_API RetBVec2 lessThanEqual( U32Vec2 const x, U32Vec2 const y );
	SDW_API RetBVec3 lessThanEqual( U32Vec3 const x, U32Vec3 const y );
	SDW_API RetBVec4 lessThanEqual( U32Vec4 const x, U32Vec4 const y );
	/**@}*/
#pragma endregion
#pragma region greaterThan
	/**
	*name
	*	greaterThan
	*/
	/**@{*/
	SDW_API RetBVec2 greaterThan( Vec2 const x, Vec2 const y );
	SDW_API RetBVec3 greaterThan( Vec3 const x, Vec3 const y );
	SDW_API RetBVec4 greaterThan( Vec4 const x, Vec4 const y );
	SDW_API RetBVec2 greaterThan( DVec2 const x, DVec2 const y );
	SDW_API RetBVec3 greaterThan( DVec3 const x, DVec3 const y );
	SDW_API RetBVec4 greaterThan( DVec4 const x, DVec4 const y );
	SDW_API RetBVec2 greaterThan( I32Vec2 const x, I32Vec2 const y );
	SDW_API RetBVec3 greaterThan( I32Vec3 const x, I32Vec3 const y );
	SDW_API RetBVec4 greaterThan( I32Vec4 const x, I32Vec4 const y );
	SDW_API RetBVec2 greaterThan( U32Vec2 const x, U32Vec2 const y );
	SDW_API RetBVec3 greaterThan( U32Vec3 const x, U32Vec3 const y );
	SDW_API RetBVec4 greaterThan( U32Vec4 const x, U32Vec4 const y );
	/**@}*/
#pragma endregion
#pragma region greaterThanEqual
	/**
	*name
	*	greaterThanEqual
	*/
	/**@{*/
	SDW_API RetBVec2 greaterThanEqual( Vec2 const x, Vec2 const y );
	SDW_API RetBVec3 greaterThanEqual( Vec3 const x, Vec3 const y );
	SDW_API RetBVec4 greaterThanEqual( Vec4 const x, Vec4 const y );
	SDW_API RetBVec2 greaterThanEqual( DVec2 const x, DVec2 const y );
	SDW_API RetBVec3 greaterThanEqual( DVec3 const x, DVec3 const y );
	SDW_API RetBVec4 greaterThanEqual( DVec4 const x, DVec4 const y );
	SDW_API RetBVec2 greaterThanEqual( I32Vec2 const x, I32Vec2 const y );
	SDW_API RetBVec3 greaterThanEqual( I32Vec3 const x, I32Vec3 const y );
	SDW_API RetBVec4 greaterThanEqual( I32Vec4 const x, I32Vec4 const y );
	SDW_API RetBVec2 greaterThanEqual( U32Vec2 const x, U32Vec2 const y );
	SDW_API RetBVec3 greaterThanEqual( U32Vec3 const x, U32Vec3 const y );
	SDW_API RetBVec4 greaterThanEqual( U32Vec4 const x, U32Vec4 const y );
	/**@}*/
#pragma endregion
#pragma region equal
	/**
	*name
	*	equal
	*/
	/**@{*/
	SDW_API RetBVec2 equal( Vec2 const x, Vec2 const y );
	SDW_API RetBVec3 equal( Vec3 const x, Vec3 const y );
	SDW_API RetBVec4 equal( Vec4 const x, Vec4 const y );
	SDW_API RetBVec2 equal( DVec2 const x, DVec2 const y );
	SDW_API RetBVec3 equal( DVec3 const x, DVec3 const y );
	SDW_API RetBVec4 equal( DVec4 const x, DVec4 const y );
	SDW_API RetBVec2 equal( I32Vec2 const x, I32Vec2 const y );
	SDW_API RetBVec3 equal( I32Vec3 const x, I32Vec3 const y );
	SDW_API RetBVec4 equal( I32Vec4 const x, I32Vec4 const y );
	SDW_API RetBVec2 equal( U32Vec2 const x, U32Vec2 const y );
	SDW_API RetBVec3 equal( U32Vec3 const x, U32Vec3 const y );
	SDW_API RetBVec4 equal( U32Vec4 const x, U32Vec4 const y );
	/**@}*/
#pragma endregion
#pragma region notEqual
	/**
	*name
	*	notEqual
	*/
	/**@{*/
	SDW_API RetBVec2 notEqual( Vec2 const x, Vec2 const y );
	SDW_API RetBVec3 notEqual( Vec3 const x, Vec3 const y );
	SDW_API RetBVec4 notEqual( Vec4 const x, Vec4 const y );
	SDW_API RetBVec2 notEqual( DVec2 const x, DVec2 const y );
	SDW_API RetBVec3 notEqual( DVec3 const x, DVec3 const y );
	SDW_API RetBVec4 notEqual( DVec4 const x, DVec4 const y );
	SDW_API RetBVec2 notEqual( I32Vec2 const x, I32Vec2 const y );
	SDW_API RetBVec3 notEqual( I32Vec3 const x, I32Vec3 const y );
	SDW_API RetBVec4 notEqual( I32Vec4 const x, I32Vec4 const y );
	SDW_API RetBVec2 notEqual( U32Vec2 const x, U32Vec2 const y );
	SDW_API RetBVec3 notEqual( U32Vec3 const x, U32Vec3 const y );
	SDW_API RetBVec4 notEqual( U32Vec4 const x, U32Vec4 const y );
	/**@}*/
#pragma endregion
#pragma region all
	/**
	*name
	*	all
	*/
	/**@{*/
	SDW_API RetBoolean all( BVec2 const x );
	SDW_API RetBoolean all( BVec3 const x );
	SDW_API RetBoolean all( BVec4 const x );
	/**@}*/
#pragma endregion
#pragma region any
	/**
	*name
	*	any
	*/
	/**@{*/
	SDW_API RetBoolean any( BVec2 const x );
	SDW_API RetBoolean any( BVec3 const x );
	SDW_API RetBoolean any( BVec4 const x );
	/**@}*/
#pragma endregion
#pragma region binNot
	/**
	*name
	*	binNot
	*/
	/**@{*/
	SDW_API RetBVec2 binNot( BVec2 const x );
	SDW_API RetBVec3 binNot( BVec3 const x );
	SDW_API RetBVec4 binNot( BVec4 const x );
	/**@}*/
#pragma endregion
#pragma region uaddCarry
	/**
	*name
	*	uaddCarry
	*/
	/**@{*/
	SDW_API RetUInt32 uaddCarry( UInt32 const x, UInt32 const y, UInt32 const carry );
	SDW_API RetU32Vec2 uaddCarry( U32Vec2 const x, U32Vec2 const y, U32Vec2 const carry );
	SDW_API RetU32Vec3 uaddCarry( U32Vec3 const x, U32Vec3 const y, U32Vec3 const carry );
	SDW_API RetU32Vec4 uaddCarry( U32Vec4 const x, U32Vec4 const y, U32Vec4 const carry );
	/**@}*/
#pragma endregion
#pragma region usubBorrow
	/**
	*name
	*	usubBorrow
	*/
	/**@{*/
	SDW_API RetUInt32 usubBorrow( UInt32 const x, UInt32 const y, UInt32 const borrow );
	SDW_API RetU32Vec2 usubBorrow( U32Vec2 const x, U32Vec2 const y, U32Vec2 const borrow );
	SDW_API RetU32Vec3 usubBorrow( U32Vec3 const x, U32Vec3 const y, U32Vec3 const borrow );
	SDW_API RetU32Vec4 usubBorrow( U32Vec4 const x, U32Vec4 const y, U32Vec4 const borrow );
	/**@}*/
#pragma endregion
#pragma region umulExtended
	/**
	*name
	*	umulExtended
	*/
	/**@{*/
	SDW_API RetVoid umulExtended( UInt32 const x, UInt32 const y, UInt32 const msb, UInt32 const lsb );
	SDW_API RetVoid umulExtended( U32Vec2 const x, U32Vec2 const y, U32Vec2 const msb, U32Vec2 const lsb );
	SDW_API RetVoid umulExtended( U32Vec3 const x, U32Vec3 const y, U32Vec3 const msb, U32Vec3 const lsb );
	SDW_API RetVoid umulExtended( U32Vec4 const x, U32Vec4 const y, U32Vec4 const msb, U32Vec4 const lsb );
	/**@}*/
#pragma endregion
#pragma region imulExtended
	/**
	*name
	*	imulExtended
	*/
	/**@{*/
	SDW_API RetVoid imulExtended( Int32 const x, Int32 const y, Int32 const msb, Int32 const lsb );
	SDW_API RetVoid imulExtended( I32Vec2 const x, I32Vec2 const y, I32Vec2 const msb, I32Vec2 const lsb );
	SDW_API RetVoid imulExtended( I32Vec3 const x, I32Vec3 const y, I32Vec3 const msb, I32Vec3 const lsb );
	SDW_API RetVoid imulExtended( I32Vec4 const x, I32Vec4 const y, I32Vec4 const msb, I32Vec4 const lsb );
	/**@}*/
#pragma endregion
#pragma region bitfieldExtract
	/**
	*name
	*	bitfieldExtract
	*/
	/**@{*/
	SDW_API RetInt32 bitfieldExtract( Int32 const value, Int32 const offset, Int32 const bits );
	SDW_API RetI32Vec2 bitfieldExtract( I32Vec2 const value, Int32 const offset, Int32 const bits );
	SDW_API RetI32Vec3 bitfieldExtract( I32Vec3 const value, Int32 const offset, Int32 const bits );
	SDW_API RetI32Vec4 bitfieldExtract( I32Vec4 const value, Int32 const offset, Int32 const bits );
	SDW_API RetUInt32 bitfieldExtract( UInt32 const value, Int32 const offset, Int32 const bits );
	SDW_API RetU32Vec2 bitfieldExtract( U32Vec2 const value, Int32 const offset, Int32 const bits );
	SDW_API RetU32Vec3 bitfieldExtract( U32Vec3 const value, Int32 const offset, Int32 const bits );
	SDW_API RetU32Vec4 bitfieldExtract( U32Vec4 const value, Int32 const offset, Int32 const bits );
	/**@}*/
#pragma endregion
#pragma region bitfieldInsert
	/**
	*name
	*	bitfieldInsert
	*/
	/**@{*/
	SDW_API RetInt32 bitfieldInsert( Int32 const base, Int32 const insert, Int32 const offset, Int32 const bits );
	SDW_API RetI32Vec2 bitfieldInsert( I32Vec2 const base, I32Vec2 const insert, Int32 const offset, Int32 const bits );
	SDW_API RetI32Vec3 bitfieldInsert( I32Vec3 const base, I32Vec3 const insert, Int32 const offset, Int32 const bits );
	SDW_API RetI32Vec4 bitfieldInsert( I32Vec4 const base, I32Vec4 const insert, Int32 const offset, Int32 const bits );
	SDW_API RetUInt32 bitfieldInsert( UInt32 const base, UInt32 const insert, Int32 const offset, Int32 const bits );
	SDW_API RetU32Vec2 bitfieldInsert( U32Vec2 const base, U32Vec2 const insert, Int32 const offset, Int32 const bits );
	SDW_API RetU32Vec3 bitfieldInsert( U32Vec3 const base, U32Vec3 const insert, Int32 const offset, Int32 const bits );
	SDW_API RetU32Vec4 bitfieldInsert( U32Vec4 const base, U32Vec4 const insert, Int32 const offset, Int32 const bits );
	/**@}*/
#pragma endregion
#pragma region bitfieldReverse
	/**
	*name
	*	bitfieldReverse
	*/
	/**@{*/
	SDW_API RetInt32 bitfieldReverse( Int32 const value );
	SDW_API RetI32Vec2 bitfieldReverse( I32Vec2 const value );
	SDW_API RetI32Vec3 bitfieldReverse( I32Vec3 const value );
	SDW_API RetI32Vec4 bitfieldReverse( I32Vec4 const value );
	SDW_API RetUInt32 bitfieldReverse( UInt32 const value );
	SDW_API RetU32Vec2 bitfieldReverse( U32Vec2 const value );
	SDW_API RetU32Vec3 bitfieldReverse( U32Vec3 const value );
	SDW_API RetU32Vec4 bitfieldReverse( U32Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region bitCount
	/**
	*name
	*	bitCount
	*/
	/**@{*/
	SDW_API RetInt32 bitCount( Int32 const value );
	SDW_API RetI32Vec2 bitCount( I32Vec2 const value );
	SDW_API RetI32Vec3 bitCount( I32Vec3 const value );
	SDW_API RetI32Vec4 bitCount( I32Vec4 const value );
	SDW_API RetUInt32 bitCount( UInt32 const value );
	SDW_API RetU32Vec2 bitCount( U32Vec2 const value );
	SDW_API RetU32Vec3 bitCount( U32Vec3 const value );
	SDW_API RetU32Vec4 bitCount( U32Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region findLSB
	/**
	*name
	*	findLSB
	*/
	/**@{*/
	SDW_API RetInt32 findLSB( Int32 const value );
	SDW_API RetI32Vec2 findLSB( I32Vec2 const value );
	SDW_API RetI32Vec3 findLSB( I32Vec3 const value );
	SDW_API RetI32Vec4 findLSB( I32Vec4 const value );
	SDW_API RetInt32 findLSB( UInt32 const value );
	SDW_API RetI32Vec2 findLSB( U32Vec2 const value );
	SDW_API RetI32Vec3 findLSB( U32Vec3 const value );
	SDW_API RetI32Vec4 findLSB( U32Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region findMSB
	/**
	*name
	*	findMSB
	*/
	/**@{*/
	SDW_API RetInt32 findMSB( Int32 const value );
	SDW_API RetI32Vec2 findMSB( I32Vec2 const value );
	SDW_API RetI32Vec3 findMSB( I32Vec3 const value );
	SDW_API RetI32Vec4 findMSB( I32Vec4 const value );
	SDW_API RetInt32 findMSB( UInt32 const value );
	SDW_API RetI32Vec2 findMSB( U32Vec2 const value );
	SDW_API RetI32Vec3 findMSB( U32Vec3 const value );
	SDW_API RetI32Vec4 findMSB( U32Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region atomicAdd
	/**
	*name
	*	atomicAdd
	*/
	/**@{*/
	SDW_API RetInt32 atomicAdd( Int32 const mem, Int32 const data );
	SDW_API RetUInt32 atomicAdd( UInt32 const mem, UInt32 const data );
	SDW_API RetFloat atomicAdd( Float const mem, Float const data );
	SDW_API RetHVec2 atomicAdd( HVec2 const mem, HVec2 const data );
	SDW_API RetHVec4 atomicAdd( HVec4 const mem, HVec4 const data );
	/**@}*/
#pragma endregion
#pragma region atomicMin
	/**
	*name
	*	atomicMin
	*/
	/**@{*/
	SDW_API RetInt32 atomicMin( Int32 const mem, Int32 const data );
	SDW_API RetUInt32 atomicMin( UInt32 const mem, UInt32 const data );
	/**@}*/
#pragma endregion
#pragma region atomicMax
	/**
	*name
	*	atomicMax
	*/
	/**@{*/
	SDW_API RetInt32 atomicMax( Int32 const mem, Int32 const data );
	SDW_API RetUInt32 atomicMax( UInt32 const mem, UInt32 const data );
	/**@}*/
#pragma endregion
#pragma region atomicAnd
	/**
	*name
	*	atomicAnd
	*/
	/**@{*/
	SDW_API RetInt32 atomicAnd( Int32 const mem, Int32 const data );
	SDW_API RetUInt32 atomicAnd( UInt32 const mem, UInt32 const data );
	/**@}*/
#pragma endregion
#pragma region atomicOr
	/**
	*name
	*	atomicOr
	*/
	/**@{*/
	SDW_API RetInt32 atomicOr( Int32 const mem, Int32 const data );
	SDW_API RetUInt32 atomicOr( UInt32 const mem, UInt32 const data );
	/**@}*/
#pragma endregion
#pragma region atomicXor
	/**
	*name
	*	atomicXor
	*/
	/**@{*/
	SDW_API RetInt32 atomicXor( Int32 const mem, Int32 const data );
	SDW_API RetUInt32 atomicXor( UInt32 const mem, UInt32 const data );
	/**@}*/
#pragma endregion
#pragma region atomicExchange
	/**
	*name
	*	atomicExchange
	*/
	/**@{*/
	SDW_API RetInt32 atomicExchange( Int32 const mem, Int32 const data );
	SDW_API RetUInt32 atomicExchange( UInt32 const mem, UInt32 const data );
	SDW_API RetFloat atomicExchange( Float const mem, Float const data );
	SDW_API RetHVec2 atomicExchange( HVec2 const mem, HVec2 const data );
	SDW_API RetHVec4 atomicExchange( HVec4 const mem, HVec4 const data );
	/**@}*/
#pragma endregion
#pragma region atomicCompSwap
	/**
	*name
	*	atomicCompSwap
	*/
	/**@{*/
	SDW_API RetInt32 atomicCompSwap( Int32 const mem, Int32 const compare, Int32 const data );
	SDW_API RetUInt32 atomicCompSwap( UInt32 const mem, UInt32 const compare, UInt32 const data );
	/**@}*/
#pragma endregion
#pragma region dFdx
	/**
	*name
	*	dFdx
	*/
	/**@{*/
	SDW_API RetFloat dFdx( Float const p );
	SDW_API RetVec2 dFdx( Vec2 const p );
	SDW_API RetVec3 dFdx( Vec3 const p );
	SDW_API RetVec4 dFdx( Vec4 const p );
	/**@}*/
#pragma endregion
#pragma region dFdxCoarse
	/**
	*name
	*	dFdxCoarse
	*/
	/**@{*/
	SDW_API RetFloat dFdxCoarse( Float const p );
	SDW_API RetVec2 dFdxCoarse( Vec2 const p );
	SDW_API RetVec3 dFdxCoarse( Vec3 const p );
	SDW_API RetVec4 dFdxCoarse( Vec4 const p );
	/**@}*/
#pragma endregion
#pragma region dFdxFine
	/**
	*name
	*	dFdxFine
	*/
	/**@{*/
	SDW_API RetFloat dFdxFine( Float const p );
	SDW_API RetVec2 dFdxFine( Vec2 const p );
	SDW_API RetVec3 dFdxFine( Vec3 const p );
	SDW_API RetVec4 dFdxFine( Vec4 const p );
	/**@}*/
#pragma endregion
#pragma region dFdy
	/**
	*name
	*	dFdy
	*/
	/**@{*/
	SDW_API RetFloat dFdy( Float const p );
	SDW_API RetVec2 dFdy( Vec2 const p );
	SDW_API RetVec3 dFdy( Vec3 const p );
	SDW_API RetVec4 dFdy( Vec4 const p );
	/**@}*/
#pragma endregion
#pragma region dFdyCoarse
	/**
	*name
	*	dFdyCoarse
	*/
	/**@{*/
	SDW_API RetFloat dFdyCoarse( Float const p );
	SDW_API RetVec2 dFdyCoarse( Vec2 const p );
	SDW_API RetVec3 dFdyCoarse( Vec3 const p );
	SDW_API RetVec4 dFdyCoarse( Vec4 const p );
	/**@}*/
#pragma endregion
#pragma region dFdyFine
	/**
	*name
	*	dFdyFine
	*/
	/**@{*/
	SDW_API RetFloat dFdyFine( Float const p );
	SDW_API RetVec2 dFdyFine( Vec2 const p );
	SDW_API RetVec3 dFdyFine( Vec3 const p );
	SDW_API RetVec4 dFdyFine( Vec4 const p );
	/**@}*/
#pragma endregion
#pragma region fwidth
	/**
	*name
	*	fwidth
	*/
	/**@{*/
	SDW_API RetFloat fwidth( Float const p );
	SDW_API RetVec2 fwidth( Vec2 const p );
	SDW_API RetVec3 fwidth( Vec3 const p );
	SDW_API RetVec4 fwidth( Vec4 const p );
	/**@}*/
#pragma endregion
#pragma region interpolateAtCentroid
	/**
	*name
	*	interpolateAtCentroid
	*/
	/**@{*/
	SDW_API RetFloat interpolateAtCentroid( Float const x );
	SDW_API RetVec2 interpolateAtCentroid( Vec2 const x );
	SDW_API RetVec3 interpolateAtCentroid( Vec3 const x );
	SDW_API RetVec4 interpolateAtCentroid( Vec4 const x );
	/**@}*/
#pragma endregion
#pragma region interpolateAtSample
	/**
	*name
	*	interpolateAtSample
	*/
	/**@{*/
	SDW_API RetFloat interpolateAtSample( Float const interpolant, Int32 const sample );
	SDW_API RetVec2 interpolateAtSample( Vec2 const interpolant, Int32 const sample );
	SDW_API RetVec3 interpolateAtSample( Vec3 const interpolant, Int32 const sample );
	SDW_API RetVec4 interpolateAtSample( Vec4 const interpolant, Int32 const sample );
	/**@}*/
#pragma endregion
#pragma region interpolateAtOffset
	/**
	*name
	*	interpolateAtOffset
	*/
	/**@{*/
	SDW_API RetFloat interpolateAtOffset( Float const interpolant, Vec2 const offset );
	SDW_API RetVec2 interpolateAtOffset( Vec2 const interpolant, Vec2 const offset );
	SDW_API RetVec3 interpolateAtOffset( Vec3 const interpolant, Vec2 const offset );
	SDW_API RetVec4 interpolateAtOffset( Vec4 const interpolant, Vec2 const offset );
	/**@}*/
#pragma endregion
#pragma region EmitStreamVertex
	/**
	*name
	*	EmitStreamVertex
	*/
	/**@{*/
	SDW_API RetVoid EmitStreamVertex( Int32 const stream );
	/**@}*/
#pragma endregion
#pragma region EndStreamPrimitive
	/**
	*name
	*	EndStreamPrimitive
	*/
	/**@{*/
	SDW_API RetVoid EndStreamPrimitive( Int32 const stream );
	/**@}*/
#pragma endregion
#pragma region EmitVertex
	/**
	*name
	*	EmitVertex
	*/
	/**@{*/
	SDW_API RetVoid EmitVertex( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region EndPrimitive
	/**
	*name
	*	EndPrimitive
	*/
	/**@{*/
	SDW_API RetVoid EndPrimitive( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region helperInvocation
	/**
	*name
	*	helperInvocation
	*/
	/**@{*/
	SDW_API RetBoolean helperInvocation( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region controlBarrier
	/**
	*name
	*	controlBarrier
	*/
	/**@{*/
	SDW_API RetVoid controlBarrier( type::Scope executionScope, type::Scope memoryScope, type::MemorySemantics semantics );
	/**@}*/
#pragma endregion
#pragma region memoryBarrier
	/**
	*name
	*	memoryBarrier
	*/
	/**@{*/
	SDW_API RetVoid memoryBarrier( type::Scope memoryScope, type::MemorySemantics semantics );
	/**@}*/
#pragma endregion
#pragma region traceRay
	/**
	*name
	*	traceRay
	*/
	/**@{*/
	SDW_API RetVoid traceRay( AccelerationStructure const topLevel, UInt32 const rayFlags, UInt32 const cullMask, UInt32 const sbtRecordOffset, UInt32 const sbtRecordStride, UInt32 const missIndex, RayDesc const rayDesc, RayPayload const payload );
	/**@}*/
#pragma endregion
#pragma region reportIntersection
	/**
	*name
	*	reportIntersection
	*/
	/**@{*/
	SDW_API RetBoolean reportIntersection( Float const hitT, UInt32 const hitKind, HitAttribute const attribs );
	/**@}*/
#pragma endregion
#pragma region executeCallable
	/**
	*name
	*	executeCallable
	*/
	/**@{*/
	SDW_API RetVoid executeCallable( UInt32 const sbtRecordIndex, CallableData const callable );
	/**@}*/
#pragma endregion
#pragma region setMeshOutputCountsNV
	/**
	*name
	*	setMeshOutputCountsNV
	*/
	/**@{*/
	SDW_API RetVoid setMeshOutputCountsNV( UInt32 const numVertices, UInt32 const numPrimitives );
	/**@}*/
#pragma endregion
#pragma region dispatchMeshNV
	/**
	*name
	*	dispatchMeshNV
	*/
	/**@{*/
	SDW_API RetVoid dispatchMeshNV( TaskPayloadNV const payload, UInt32 const numTasks );
	/**@}*/
#pragma endregion
#pragma region writePackedPrimitiveIndices4x8NV
	/**
	*name
	*	writePackedPrimitiveIndices4x8NV
	*/
	/**@{*/
	SDW_API RetVoid writePackedPrimitiveIndices4x8NV( UInt32 const indexOffset, UInt32 const packedIndices );
	/**@}*/
#pragma endregion
#pragma region setMeshOutputCounts
	/**
	*name
	*	setMeshOutputCounts
	*/
	/**@{*/
	SDW_API RetVoid setMeshOutputCounts( UInt32 const numVertices, UInt32 const numPrimitives );
	/**@}*/
#pragma endregion
#pragma region subgroupElect
	/**
	*name
	*	subgroupElect
	*/
	/**@{*/
	SDW_API RetBoolean subgroupElect( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region subgroupAll
	/**
	*name
	*	subgroupAll
	*/
	/**@{*/
	SDW_API RetBoolean subgroupAll( Boolean const value );
	/**@}*/
#pragma endregion
#pragma region subgroupAny
	/**
	*name
	*	subgroupAny
	*/
	/**@{*/
	SDW_API RetBoolean subgroupAny( Boolean const value );
	/**@}*/
#pragma endregion
#pragma region subgroupAllEqual
	/**
	*name
	*	subgroupAllEqual
	*/
	/**@{*/
	SDW_API RetBoolean subgroupAllEqual( Float const value );
	SDW_API RetBoolean subgroupAllEqual( Vec2 const value );
	SDW_API RetBoolean subgroupAllEqual( Vec3 const value );
	SDW_API RetBoolean subgroupAllEqual( Vec4 const value );
	SDW_API RetBoolean subgroupAllEqual( Int32 const value );
	SDW_API RetBoolean subgroupAllEqual( I32Vec2 const value );
	SDW_API RetBoolean subgroupAllEqual( I32Vec3 const value );
	SDW_API RetBoolean subgroupAllEqual( I32Vec4 const value );
	SDW_API RetBoolean subgroupAllEqual( UInt32 const value );
	SDW_API RetBoolean subgroupAllEqual( U32Vec2 const value );
	SDW_API RetBoolean subgroupAllEqual( U32Vec3 const value );
	SDW_API RetBoolean subgroupAllEqual( U32Vec4 const value );
	SDW_API RetBoolean subgroupAllEqual( Boolean const value );
	SDW_API RetBoolean subgroupAllEqual( BVec2 const value );
	SDW_API RetBoolean subgroupAllEqual( BVec3 const value );
	SDW_API RetBoolean subgroupAllEqual( BVec4 const value );
	SDW_API RetBoolean subgroupAllEqual( Double const value );
	SDW_API RetBoolean subgroupAllEqual( DVec2 const value );
	SDW_API RetBoolean subgroupAllEqual( DVec3 const value );
	SDW_API RetBoolean subgroupAllEqual( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupBroadcast
	/**
	*name
	*	subgroupBroadcast
	*/
	/**@{*/
	SDW_API RetFloat subgroupBroadcast( Float const value, UInt32 const id );
	SDW_API RetVec2 subgroupBroadcast( Vec2 const value, UInt32 const id );
	SDW_API RetVec3 subgroupBroadcast( Vec3 const value, UInt32 const id );
	SDW_API RetVec4 subgroupBroadcast( Vec4 const value, UInt32 const id );
	SDW_API RetInt32 subgroupBroadcast( Int32 const value, UInt32 const id );
	SDW_API RetI32Vec2 subgroupBroadcast( I32Vec2 const value, UInt32 const id );
	SDW_API RetI32Vec3 subgroupBroadcast( I32Vec3 const value, UInt32 const id );
	SDW_API RetI32Vec4 subgroupBroadcast( I32Vec4 const value, UInt32 const id );
	SDW_API RetUInt32 subgroupBroadcast( UInt32 const value, UInt32 const id );
	SDW_API RetU32Vec2 subgroupBroadcast( U32Vec2 const value, UInt32 const id );
	SDW_API RetU32Vec3 subgroupBroadcast( U32Vec3 const value, UInt32 const id );
	SDW_API RetU32Vec4 subgroupBroadcast( U32Vec4 const value, UInt32 const id );
	SDW_API RetBoolean subgroupBroadcast( Boolean const value, UInt32 const id );
	SDW_API RetBVec2 subgroupBroadcast( BVec2 const value, UInt32 const id );
	SDW_API RetBVec3 subgroupBroadcast( BVec3 const value, UInt32 const id );
	SDW_API RetBVec4 subgroupBroadcast( BVec4 const value, UInt32 const id );
	SDW_API RetDouble subgroupBroadcast( Double const value, UInt32 const id );
	SDW_API RetDVec2 subgroupBroadcast( DVec2 const value, UInt32 const id );
	SDW_API RetDVec3 subgroupBroadcast( DVec3 const value, UInt32 const id );
	SDW_API RetDVec4 subgroupBroadcast( DVec4 const value, UInt32 const id );
	/**@}*/
#pragma endregion
#pragma region subgroupBroadcastFirst
	/**
	*name
	*	subgroupBroadcastFirst
	*/
	/**@{*/
	SDW_API RetFloat subgroupBroadcastFirst( Float const value );
	SDW_API RetVec2 subgroupBroadcastFirst( Vec2 const value );
	SDW_API RetVec3 subgroupBroadcastFirst( Vec3 const value );
	SDW_API RetVec4 subgroupBroadcastFirst( Vec4 const value );
	SDW_API RetInt32 subgroupBroadcastFirst( Int32 const value );
	SDW_API RetI32Vec2 subgroupBroadcastFirst( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupBroadcastFirst( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupBroadcastFirst( I32Vec4 const value );
	SDW_API RetUInt32 subgroupBroadcastFirst( UInt32 const value );
	SDW_API RetU32Vec2 subgroupBroadcastFirst( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupBroadcastFirst( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupBroadcastFirst( U32Vec4 const value );
	SDW_API RetBoolean subgroupBroadcastFirst( Boolean const value );
	SDW_API RetBVec2 subgroupBroadcastFirst( BVec2 const value );
	SDW_API RetBVec3 subgroupBroadcastFirst( BVec3 const value );
	SDW_API RetBVec4 subgroupBroadcastFirst( BVec4 const value );
	SDW_API RetDouble subgroupBroadcastFirst( Double const value );
	SDW_API RetDVec2 subgroupBroadcastFirst( DVec2 const value );
	SDW_API RetDVec3 subgroupBroadcastFirst( DVec3 const value );
	SDW_API RetDVec4 subgroupBroadcastFirst( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupBallot
	/**
	*name
	*	subgroupBallot
	*/
	/**@{*/
	SDW_API RetU32Vec4 subgroupBallot( Boolean const value );
	/**@}*/
#pragma endregion
#pragma region subgroupInverseBallot
	/**
	*name
	*	subgroupInverseBallot
	*/
	/**@{*/
	SDW_API RetBoolean subgroupInverseBallot( U32Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupBallotBitExtract
	/**
	*name
	*	subgroupBallotBitExtract
	*/
	/**@{*/
	SDW_API RetBoolean subgroupBallotBitExtract( U32Vec4 const value, UInt32 const index );
	/**@}*/
#pragma endregion
#pragma region subgroupBallotBitCount
	/**
	*name
	*	subgroupBallotBitCount
	*/
	/**@{*/
	SDW_API RetUInt32 subgroupBallotBitCount( U32Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupBallotInclusiveBitCount
	/**
	*name
	*	subgroupBallotInclusiveBitCount
	*/
	/**@{*/
	SDW_API RetUInt32 subgroupBallotInclusiveBitCount( U32Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupBallotExclusiveBitCount
	/**
	*name
	*	subgroupBallotExclusiveBitCount
	*/
	/**@{*/
	SDW_API RetUInt32 subgroupBallotExclusiveBitCount( U32Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupBallotFindLSB
	/**
	*name
	*	subgroupBallotFindLSB
	*/
	/**@{*/
	SDW_API RetUInt32 subgroupBallotFindLSB( U32Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupBallotFindMSB
	/**
	*name
	*	subgroupBallotFindMSB
	*/
	/**@{*/
	SDW_API RetUInt32 subgroupBallotFindMSB( U32Vec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupShuffle
	/**
	*name
	*	subgroupShuffle
	*/
	/**@{*/
	SDW_API RetFloat subgroupShuffle( Float const value, UInt32 const id );
	SDW_API RetVec2 subgroupShuffle( Vec2 const value, UInt32 const id );
	SDW_API RetVec3 subgroupShuffle( Vec3 const value, UInt32 const id );
	SDW_API RetVec4 subgroupShuffle( Vec4 const value, UInt32 const id );
	SDW_API RetInt32 subgroupShuffle( Int32 const value, UInt32 const id );
	SDW_API RetI32Vec2 subgroupShuffle( I32Vec2 const value, UInt32 const id );
	SDW_API RetI32Vec3 subgroupShuffle( I32Vec3 const value, UInt32 const id );
	SDW_API RetI32Vec4 subgroupShuffle( I32Vec4 const value, UInt32 const id );
	SDW_API RetUInt32 subgroupShuffle( UInt32 const value, UInt32 const id );
	SDW_API RetU32Vec2 subgroupShuffle( U32Vec2 const value, UInt32 const id );
	SDW_API RetU32Vec3 subgroupShuffle( U32Vec3 const value, UInt32 const id );
	SDW_API RetU32Vec4 subgroupShuffle( U32Vec4 const value, UInt32 const id );
	SDW_API RetBoolean subgroupShuffle( Boolean const value, UInt32 const id );
	SDW_API RetBVec2 subgroupShuffle( BVec2 const value, UInt32 const id );
	SDW_API RetBVec3 subgroupShuffle( BVec3 const value, UInt32 const id );
	SDW_API RetBVec4 subgroupShuffle( BVec4 const value, UInt32 const id );
	SDW_API RetDouble subgroupShuffle( Double const value, UInt32 const id );
	SDW_API RetDVec2 subgroupShuffle( DVec2 const value, UInt32 const id );
	SDW_API RetDVec3 subgroupShuffle( DVec3 const value, UInt32 const id );
	SDW_API RetDVec4 subgroupShuffle( DVec4 const value, UInt32 const id );
	/**@}*/
#pragma endregion
#pragma region subgroupShuffleXor
	/**
	*name
	*	subgroupShuffleXor
	*/
	/**@{*/
	SDW_API RetFloat subgroupShuffleXor( Float const value, UInt32 const mask );
	SDW_API RetVec2 subgroupShuffleXor( Vec2 const value, UInt32 const mask );
	SDW_API RetVec3 subgroupShuffleXor( Vec3 const value, UInt32 const mask );
	SDW_API RetVec4 subgroupShuffleXor( Vec4 const value, UInt32 const mask );
	SDW_API RetInt32 subgroupShuffleXor( Int32 const value, UInt32 const mask );
	SDW_API RetI32Vec2 subgroupShuffleXor( I32Vec2 const value, UInt32 const mask );
	SDW_API RetI32Vec3 subgroupShuffleXor( I32Vec3 const value, UInt32 const mask );
	SDW_API RetI32Vec4 subgroupShuffleXor( I32Vec4 const value, UInt32 const mask );
	SDW_API RetUInt32 subgroupShuffleXor( UInt32 const value, UInt32 const mask );
	SDW_API RetU32Vec2 subgroupShuffleXor( U32Vec2 const value, UInt32 const mask );
	SDW_API RetU32Vec3 subgroupShuffleXor( U32Vec3 const value, UInt32 const mask );
	SDW_API RetU32Vec4 subgroupShuffleXor( U32Vec4 const value, UInt32 const mask );
	SDW_API RetBoolean subgroupShuffleXor( Boolean const value, UInt32 const mask );
	SDW_API RetBVec2 subgroupShuffleXor( BVec2 const value, UInt32 const mask );
	SDW_API RetBVec3 subgroupShuffleXor( BVec3 const value, UInt32 const mask );
	SDW_API RetBVec4 subgroupShuffleXor( BVec4 const value, UInt32 const mask );
	SDW_API RetDouble subgroupShuffleXor( Double const value, UInt32 const mask );
	SDW_API RetDVec2 subgroupShuffleXor( DVec2 const value, UInt32 const mask );
	SDW_API RetDVec3 subgroupShuffleXor( DVec3 const value, UInt32 const mask );
	SDW_API RetDVec4 subgroupShuffleXor( DVec4 const value, UInt32 const mask );
	/**@}*/
#pragma endregion
#pragma region subgroupShuffleUp
	/**
	*name
	*	subgroupShuffleUp
	*/
	/**@{*/
	SDW_API RetFloat subgroupShuffleUp( Float const value, UInt32 const delta );
	SDW_API RetVec2 subgroupShuffleUp( Vec2 const value, UInt32 const delta );
	SDW_API RetVec3 subgroupShuffleUp( Vec3 const value, UInt32 const delta );
	SDW_API RetVec4 subgroupShuffleUp( Vec4 const value, UInt32 const delta );
	SDW_API RetInt32 subgroupShuffleUp( Int32 const value, UInt32 const delta );
	SDW_API RetI32Vec2 subgroupShuffleUp( I32Vec2 const value, UInt32 const delta );
	SDW_API RetI32Vec3 subgroupShuffleUp( I32Vec3 const value, UInt32 const delta );
	SDW_API RetI32Vec4 subgroupShuffleUp( I32Vec4 const value, UInt32 const delta );
	SDW_API RetUInt32 subgroupShuffleUp( UInt32 const value, UInt32 const delta );
	SDW_API RetU32Vec2 subgroupShuffleUp( U32Vec2 const value, UInt32 const delta );
	SDW_API RetU32Vec3 subgroupShuffleUp( U32Vec3 const value, UInt32 const delta );
	SDW_API RetU32Vec4 subgroupShuffleUp( U32Vec4 const value, UInt32 const delta );
	SDW_API RetBoolean subgroupShuffleUp( Boolean const value, UInt32 const delta );
	SDW_API RetBVec2 subgroupShuffleUp( BVec2 const value, UInt32 const delta );
	SDW_API RetBVec3 subgroupShuffleUp( BVec3 const value, UInt32 const delta );
	SDW_API RetBVec4 subgroupShuffleUp( BVec4 const value, UInt32 const delta );
	SDW_API RetDouble subgroupShuffleUp( Double const value, UInt32 const delta );
	SDW_API RetDVec2 subgroupShuffleUp( DVec2 const value, UInt32 const delta );
	SDW_API RetDVec3 subgroupShuffleUp( DVec3 const value, UInt32 const delta );
	SDW_API RetDVec4 subgroupShuffleUp( DVec4 const value, UInt32 const delta );
	/**@}*/
#pragma endregion
#pragma region subgroupShuffleDown
	/**
	*name
	*	subgroupShuffleDown
	*/
	/**@{*/
	SDW_API RetFloat subgroupShuffleDown( Float const value, UInt32 const delta );
	SDW_API RetVec2 subgroupShuffleDown( Vec2 const value, UInt32 const delta );
	SDW_API RetVec3 subgroupShuffleDown( Vec3 const value, UInt32 const delta );
	SDW_API RetVec4 subgroupShuffleDown( Vec4 const value, UInt32 const delta );
	SDW_API RetInt32 subgroupShuffleDown( Int32 const value, UInt32 const delta );
	SDW_API RetI32Vec2 subgroupShuffleDown( I32Vec2 const value, UInt32 const delta );
	SDW_API RetI32Vec3 subgroupShuffleDown( I32Vec3 const value, UInt32 const delta );
	SDW_API RetI32Vec4 subgroupShuffleDown( I32Vec4 const value, UInt32 const delta );
	SDW_API RetUInt32 subgroupShuffleDown( UInt32 const value, UInt32 const delta );
	SDW_API RetU32Vec2 subgroupShuffleDown( U32Vec2 const value, UInt32 const delta );
	SDW_API RetU32Vec3 subgroupShuffleDown( U32Vec3 const value, UInt32 const delta );
	SDW_API RetU32Vec4 subgroupShuffleDown( U32Vec4 const value, UInt32 const delta );
	SDW_API RetBoolean subgroupShuffleDown( Boolean const value, UInt32 const delta );
	SDW_API RetBVec2 subgroupShuffleDown( BVec2 const value, UInt32 const delta );
	SDW_API RetBVec3 subgroupShuffleDown( BVec3 const value, UInt32 const delta );
	SDW_API RetBVec4 subgroupShuffleDown( BVec4 const value, UInt32 const delta );
	SDW_API RetDouble subgroupShuffleDown( Double const value, UInt32 const delta );
	SDW_API RetDVec2 subgroupShuffleDown( DVec2 const value, UInt32 const delta );
	SDW_API RetDVec3 subgroupShuffleDown( DVec3 const value, UInt32 const delta );
	SDW_API RetDVec4 subgroupShuffleDown( DVec4 const value, UInt32 const delta );
	/**@}*/
#pragma endregion
#pragma region subgroupAdd
	/**
	*name
	*	subgroupAdd
	*/
	/**@{*/
	SDW_API RetFloat subgroupAdd( Float const value );
	SDW_API RetVec2 subgroupAdd( Vec2 const value );
	SDW_API RetVec3 subgroupAdd( Vec3 const value );
	SDW_API RetVec4 subgroupAdd( Vec4 const value );
	SDW_API RetInt32 subgroupAdd( Int32 const value );
	SDW_API RetI32Vec2 subgroupAdd( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupAdd( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupAdd( I32Vec4 const value );
	SDW_API RetUInt32 subgroupAdd( UInt32 const value );
	SDW_API RetU32Vec2 subgroupAdd( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupAdd( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupAdd( U32Vec4 const value );
	SDW_API RetDouble subgroupAdd( Double const value );
	SDW_API RetDVec2 subgroupAdd( DVec2 const value );
	SDW_API RetDVec3 subgroupAdd( DVec3 const value );
	SDW_API RetDVec4 subgroupAdd( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupMul
	/**
	*name
	*	subgroupMul
	*/
	/**@{*/
	SDW_API RetFloat subgroupMul( Float const value );
	SDW_API RetVec2 subgroupMul( Vec2 const value );
	SDW_API RetVec3 subgroupMul( Vec3 const value );
	SDW_API RetVec4 subgroupMul( Vec4 const value );
	SDW_API RetInt32 subgroupMul( Int32 const value );
	SDW_API RetI32Vec2 subgroupMul( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupMul( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupMul( I32Vec4 const value );
	SDW_API RetUInt32 subgroupMul( UInt32 const value );
	SDW_API RetU32Vec2 subgroupMul( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupMul( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupMul( U32Vec4 const value );
	SDW_API RetDouble subgroupMul( Double const value );
	SDW_API RetDVec2 subgroupMul( DVec2 const value );
	SDW_API RetDVec3 subgroupMul( DVec3 const value );
	SDW_API RetDVec4 subgroupMul( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupMin
	/**
	*name
	*	subgroupMin
	*/
	/**@{*/
	SDW_API RetFloat subgroupMin( Float const value );
	SDW_API RetVec2 subgroupMin( Vec2 const value );
	SDW_API RetVec3 subgroupMin( Vec3 const value );
	SDW_API RetVec4 subgroupMin( Vec4 const value );
	SDW_API RetInt32 subgroupMin( Int32 const value );
	SDW_API RetI32Vec2 subgroupMin( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupMin( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupMin( I32Vec4 const value );
	SDW_API RetUInt32 subgroupMin( UInt32 const value );
	SDW_API RetU32Vec2 subgroupMin( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupMin( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupMin( U32Vec4 const value );
	SDW_API RetDouble subgroupMin( Double const value );
	SDW_API RetDVec2 subgroupMin( DVec2 const value );
	SDW_API RetDVec3 subgroupMin( DVec3 const value );
	SDW_API RetDVec4 subgroupMin( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupMax
	/**
	*name
	*	subgroupMax
	*/
	/**@{*/
	SDW_API RetFloat subgroupMax( Float const value );
	SDW_API RetVec2 subgroupMax( Vec2 const value );
	SDW_API RetVec3 subgroupMax( Vec3 const value );
	SDW_API RetVec4 subgroupMax( Vec4 const value );
	SDW_API RetInt32 subgroupMax( Int32 const value );
	SDW_API RetI32Vec2 subgroupMax( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupMax( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupMax( I32Vec4 const value );
	SDW_API RetUInt32 subgroupMax( UInt32 const value );
	SDW_API RetU32Vec2 subgroupMax( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupMax( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupMax( U32Vec4 const value );
	SDW_API RetDouble subgroupMax( Double const value );
	SDW_API RetDVec2 subgroupMax( DVec2 const value );
	SDW_API RetDVec3 subgroupMax( DVec3 const value );
	SDW_API RetDVec4 subgroupMax( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupAnd
	/**
	*name
	*	subgroupAnd
	*/
	/**@{*/
	SDW_API RetInt32 subgroupAnd( Int32 const value );
	SDW_API RetI32Vec2 subgroupAnd( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupAnd( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupAnd( I32Vec4 const value );
	SDW_API RetUInt32 subgroupAnd( UInt32 const value );
	SDW_API RetU32Vec2 subgroupAnd( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupAnd( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupAnd( U32Vec4 const value );
	SDW_API RetBoolean subgroupAnd( Boolean const value );
	SDW_API RetBVec2 subgroupAnd( BVec2 const value );
	SDW_API RetBVec3 subgroupAnd( BVec3 const value );
	SDW_API RetBVec4 subgroupAnd( BVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupOr
	/**
	*name
	*	subgroupOr
	*/
	/**@{*/
	SDW_API RetInt32 subgroupOr( Int32 const value );
	SDW_API RetI32Vec2 subgroupOr( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupOr( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupOr( I32Vec4 const value );
	SDW_API RetUInt32 subgroupOr( UInt32 const value );
	SDW_API RetU32Vec2 subgroupOr( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupOr( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupOr( U32Vec4 const value );
	SDW_API RetBoolean subgroupOr( Boolean const value );
	SDW_API RetBVec2 subgroupOr( BVec2 const value );
	SDW_API RetBVec3 subgroupOr( BVec3 const value );
	SDW_API RetBVec4 subgroupOr( BVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupXor
	/**
	*name
	*	subgroupXor
	*/
	/**@{*/
	SDW_API RetInt32 subgroupXor( Int32 const value );
	SDW_API RetI32Vec2 subgroupXor( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupXor( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupXor( I32Vec4 const value );
	SDW_API RetUInt32 subgroupXor( UInt32 const value );
	SDW_API RetU32Vec2 subgroupXor( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupXor( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupXor( U32Vec4 const value );
	SDW_API RetBoolean subgroupXor( Boolean const value );
	SDW_API RetBVec2 subgroupXor( BVec2 const value );
	SDW_API RetBVec3 subgroupXor( BVec3 const value );
	SDW_API RetBVec4 subgroupXor( BVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveAdd
	/**
	*name
	*	subgroupInclusiveAdd
	*/
	/**@{*/
	SDW_API RetFloat subgroupInclusiveAdd( Float const value );
	SDW_API RetVec2 subgroupInclusiveAdd( Vec2 const value );
	SDW_API RetVec3 subgroupInclusiveAdd( Vec3 const value );
	SDW_API RetVec4 subgroupInclusiveAdd( Vec4 const value );
	SDW_API RetInt32 subgroupInclusiveAdd( Int32 const value );
	SDW_API RetI32Vec2 subgroupInclusiveAdd( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupInclusiveAdd( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupInclusiveAdd( I32Vec4 const value );
	SDW_API RetUInt32 subgroupInclusiveAdd( UInt32 const value );
	SDW_API RetU32Vec2 subgroupInclusiveAdd( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupInclusiveAdd( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupInclusiveAdd( U32Vec4 const value );
	SDW_API RetDouble subgroupInclusiveAdd( Double const value );
	SDW_API RetDVec2 subgroupInclusiveAdd( DVec2 const value );
	SDW_API RetDVec3 subgroupInclusiveAdd( DVec3 const value );
	SDW_API RetDVec4 subgroupInclusiveAdd( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveMul
	/**
	*name
	*	subgroupInclusiveMul
	*/
	/**@{*/
	SDW_API RetFloat subgroupInclusiveMul( Float const value );
	SDW_API RetVec2 subgroupInclusiveMul( Vec2 const value );
	SDW_API RetVec3 subgroupInclusiveMul( Vec3 const value );
	SDW_API RetVec4 subgroupInclusiveMul( Vec4 const value );
	SDW_API RetInt32 subgroupInclusiveMul( Int32 const value );
	SDW_API RetI32Vec2 subgroupInclusiveMul( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupInclusiveMul( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupInclusiveMul( I32Vec4 const value );
	SDW_API RetUInt32 subgroupInclusiveMul( UInt32 const value );
	SDW_API RetU32Vec2 subgroupInclusiveMul( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupInclusiveMul( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupInclusiveMul( U32Vec4 const value );
	SDW_API RetDouble subgroupInclusiveMul( Double const value );
	SDW_API RetDVec2 subgroupInclusiveMul( DVec2 const value );
	SDW_API RetDVec3 subgroupInclusiveMul( DVec3 const value );
	SDW_API RetDVec4 subgroupInclusiveMul( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveMin
	/**
	*name
	*	subgroupInclusiveMin
	*/
	/**@{*/
	SDW_API RetFloat subgroupInclusiveMin( Float const value );
	SDW_API RetVec2 subgroupInclusiveMin( Vec2 const value );
	SDW_API RetVec3 subgroupInclusiveMin( Vec3 const value );
	SDW_API RetVec4 subgroupInclusiveMin( Vec4 const value );
	SDW_API RetInt32 subgroupInclusiveMin( Int32 const value );
	SDW_API RetI32Vec2 subgroupInclusiveMin( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupInclusiveMin( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupInclusiveMin( I32Vec4 const value );
	SDW_API RetUInt32 subgroupInclusiveMin( UInt32 const value );
	SDW_API RetU32Vec2 subgroupInclusiveMin( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupInclusiveMin( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupInclusiveMin( U32Vec4 const value );
	SDW_API RetDouble subgroupInclusiveMin( Double const value );
	SDW_API RetDVec2 subgroupInclusiveMin( DVec2 const value );
	SDW_API RetDVec3 subgroupInclusiveMin( DVec3 const value );
	SDW_API RetDVec4 subgroupInclusiveMin( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveMax
	/**
	*name
	*	subgroupInclusiveMax
	*/
	/**@{*/
	SDW_API RetFloat subgroupInclusiveMax( Float const value );
	SDW_API RetVec2 subgroupInclusiveMax( Vec2 const value );
	SDW_API RetVec3 subgroupInclusiveMax( Vec3 const value );
	SDW_API RetVec4 subgroupInclusiveMax( Vec4 const value );
	SDW_API RetInt32 subgroupInclusiveMax( Int32 const value );
	SDW_API RetI32Vec2 subgroupInclusiveMax( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupInclusiveMax( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupInclusiveMax( I32Vec4 const value );
	SDW_API RetUInt32 subgroupInclusiveMax( UInt32 const value );
	SDW_API RetU32Vec2 subgroupInclusiveMax( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupInclusiveMax( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupInclusiveMax( U32Vec4 const value );
	SDW_API RetDouble subgroupInclusiveMax( Double const value );
	SDW_API RetDVec2 subgroupInclusiveMax( DVec2 const value );
	SDW_API RetDVec3 subgroupInclusiveMax( DVec3 const value );
	SDW_API RetDVec4 subgroupInclusiveMax( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveAnd
	/**
	*name
	*	subgroupInclusiveAnd
	*/
	/**@{*/
	SDW_API RetInt32 subgroupInclusiveAnd( Int32 const value );
	SDW_API RetI32Vec2 subgroupInclusiveAnd( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupInclusiveAnd( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupInclusiveAnd( I32Vec4 const value );
	SDW_API RetUInt32 subgroupInclusiveAnd( UInt32 const value );
	SDW_API RetU32Vec2 subgroupInclusiveAnd( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupInclusiveAnd( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupInclusiveAnd( U32Vec4 const value );
	SDW_API RetBoolean subgroupInclusiveAnd( Boolean const value );
	SDW_API RetBVec2 subgroupInclusiveAnd( BVec2 const value );
	SDW_API RetBVec3 subgroupInclusiveAnd( BVec3 const value );
	SDW_API RetBVec4 subgroupInclusiveAnd( BVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveOr
	/**
	*name
	*	subgroupInclusiveOr
	*/
	/**@{*/
	SDW_API RetInt32 subgroupInclusiveOr( Int32 const value );
	SDW_API RetI32Vec2 subgroupInclusiveOr( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupInclusiveOr( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupInclusiveOr( I32Vec4 const value );
	SDW_API RetUInt32 subgroupInclusiveOr( UInt32 const value );
	SDW_API RetU32Vec2 subgroupInclusiveOr( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupInclusiveOr( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupInclusiveOr( U32Vec4 const value );
	SDW_API RetBoolean subgroupInclusiveOr( Boolean const value );
	SDW_API RetBVec2 subgroupInclusiveOr( BVec2 const value );
	SDW_API RetBVec3 subgroupInclusiveOr( BVec3 const value );
	SDW_API RetBVec4 subgroupInclusiveOr( BVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveXor
	/**
	*name
	*	subgroupInclusiveXor
	*/
	/**@{*/
	SDW_API RetInt32 subgroupInclusiveXor( Int32 const value );
	SDW_API RetI32Vec2 subgroupInclusiveXor( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupInclusiveXor( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupInclusiveXor( I32Vec4 const value );
	SDW_API RetUInt32 subgroupInclusiveXor( UInt32 const value );
	SDW_API RetU32Vec2 subgroupInclusiveXor( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupInclusiveXor( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupInclusiveXor( U32Vec4 const value );
	SDW_API RetBoolean subgroupInclusiveXor( Boolean const value );
	SDW_API RetBVec2 subgroupInclusiveXor( BVec2 const value );
	SDW_API RetBVec3 subgroupInclusiveXor( BVec3 const value );
	SDW_API RetBVec4 subgroupInclusiveXor( BVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveAdd
	/**
	*name
	*	subgroupExclusiveAdd
	*/
	/**@{*/
	SDW_API RetFloat subgroupExclusiveAdd( Float const value );
	SDW_API RetVec2 subgroupExclusiveAdd( Vec2 const value );
	SDW_API RetVec3 subgroupExclusiveAdd( Vec3 const value );
	SDW_API RetVec4 subgroupExclusiveAdd( Vec4 const value );
	SDW_API RetInt32 subgroupExclusiveAdd( Int32 const value );
	SDW_API RetI32Vec2 subgroupExclusiveAdd( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupExclusiveAdd( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupExclusiveAdd( I32Vec4 const value );
	SDW_API RetUInt32 subgroupExclusiveAdd( UInt32 const value );
	SDW_API RetU32Vec2 subgroupExclusiveAdd( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupExclusiveAdd( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupExclusiveAdd( U32Vec4 const value );
	SDW_API RetDouble subgroupExclusiveAdd( Double const value );
	SDW_API RetDVec2 subgroupExclusiveAdd( DVec2 const value );
	SDW_API RetDVec3 subgroupExclusiveAdd( DVec3 const value );
	SDW_API RetDVec4 subgroupExclusiveAdd( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveMul
	/**
	*name
	*	subgroupExclusiveMul
	*/
	/**@{*/
	SDW_API RetFloat subgroupExclusiveMul( Float const value );
	SDW_API RetVec2 subgroupExclusiveMul( Vec2 const value );
	SDW_API RetVec3 subgroupExclusiveMul( Vec3 const value );
	SDW_API RetVec4 subgroupExclusiveMul( Vec4 const value );
	SDW_API RetInt32 subgroupExclusiveMul( Int32 const value );
	SDW_API RetI32Vec2 subgroupExclusiveMul( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupExclusiveMul( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupExclusiveMul( I32Vec4 const value );
	SDW_API RetUInt32 subgroupExclusiveMul( UInt32 const value );
	SDW_API RetU32Vec2 subgroupExclusiveMul( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupExclusiveMul( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupExclusiveMul( U32Vec4 const value );
	SDW_API RetDouble subgroupExclusiveMul( Double const value );
	SDW_API RetDVec2 subgroupExclusiveMul( DVec2 const value );
	SDW_API RetDVec3 subgroupExclusiveMul( DVec3 const value );
	SDW_API RetDVec4 subgroupExclusiveMul( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveMin
	/**
	*name
	*	subgroupExclusiveMin
	*/
	/**@{*/
	SDW_API RetFloat subgroupExclusiveMin( Float const value );
	SDW_API RetVec2 subgroupExclusiveMin( Vec2 const value );
	SDW_API RetVec3 subgroupExclusiveMin( Vec3 const value );
	SDW_API RetVec4 subgroupExclusiveMin( Vec4 const value );
	SDW_API RetInt32 subgroupExclusiveMin( Int32 const value );
	SDW_API RetI32Vec2 subgroupExclusiveMin( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupExclusiveMin( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupExclusiveMin( I32Vec4 const value );
	SDW_API RetUInt32 subgroupExclusiveMin( UInt32 const value );
	SDW_API RetU32Vec2 subgroupExclusiveMin( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupExclusiveMin( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupExclusiveMin( U32Vec4 const value );
	SDW_API RetDouble subgroupExclusiveMin( Double const value );
	SDW_API RetDVec2 subgroupExclusiveMin( DVec2 const value );
	SDW_API RetDVec3 subgroupExclusiveMin( DVec3 const value );
	SDW_API RetDVec4 subgroupExclusiveMin( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveMax
	/**
	*name
	*	subgroupExclusiveMax
	*/
	/**@{*/
	SDW_API RetFloat subgroupExclusiveMax( Float const value );
	SDW_API RetVec2 subgroupExclusiveMax( Vec2 const value );
	SDW_API RetVec3 subgroupExclusiveMax( Vec3 const value );
	SDW_API RetVec4 subgroupExclusiveMax( Vec4 const value );
	SDW_API RetInt32 subgroupExclusiveMax( Int32 const value );
	SDW_API RetI32Vec2 subgroupExclusiveMax( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupExclusiveMax( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupExclusiveMax( I32Vec4 const value );
	SDW_API RetUInt32 subgroupExclusiveMax( UInt32 const value );
	SDW_API RetU32Vec2 subgroupExclusiveMax( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupExclusiveMax( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupExclusiveMax( U32Vec4 const value );
	SDW_API RetDouble subgroupExclusiveMax( Double const value );
	SDW_API RetDVec2 subgroupExclusiveMax( DVec2 const value );
	SDW_API RetDVec3 subgroupExclusiveMax( DVec3 const value );
	SDW_API RetDVec4 subgroupExclusiveMax( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveAnd
	/**
	*name
	*	subgroupExclusiveAnd
	*/
	/**@{*/
	SDW_API RetInt32 subgroupExclusiveAnd( Int32 const value );
	SDW_API RetI32Vec2 subgroupExclusiveAnd( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupExclusiveAnd( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupExclusiveAnd( I32Vec4 const value );
	SDW_API RetUInt32 subgroupExclusiveAnd( UInt32 const value );
	SDW_API RetU32Vec2 subgroupExclusiveAnd( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupExclusiveAnd( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupExclusiveAnd( U32Vec4 const value );
	SDW_API RetBoolean subgroupExclusiveAnd( Boolean const value );
	SDW_API RetBVec2 subgroupExclusiveAnd( BVec2 const value );
	SDW_API RetBVec3 subgroupExclusiveAnd( BVec3 const value );
	SDW_API RetBVec4 subgroupExclusiveAnd( BVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveOr
	/**
	*name
	*	subgroupExclusiveOr
	*/
	/**@{*/
	SDW_API RetInt32 subgroupExclusiveOr( Int32 const value );
	SDW_API RetI32Vec2 subgroupExclusiveOr( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupExclusiveOr( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupExclusiveOr( I32Vec4 const value );
	SDW_API RetUInt32 subgroupExclusiveOr( UInt32 const value );
	SDW_API RetU32Vec2 subgroupExclusiveOr( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupExclusiveOr( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupExclusiveOr( U32Vec4 const value );
	SDW_API RetBoolean subgroupExclusiveOr( Boolean const value );
	SDW_API RetBVec2 subgroupExclusiveOr( BVec2 const value );
	SDW_API RetBVec3 subgroupExclusiveOr( BVec3 const value );
	SDW_API RetBVec4 subgroupExclusiveOr( BVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveXor
	/**
	*name
	*	subgroupExclusiveXor
	*/
	/**@{*/
	SDW_API RetInt32 subgroupExclusiveXor( Int32 const value );
	SDW_API RetI32Vec2 subgroupExclusiveXor( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupExclusiveXor( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupExclusiveXor( I32Vec4 const value );
	SDW_API RetUInt32 subgroupExclusiveXor( UInt32 const value );
	SDW_API RetU32Vec2 subgroupExclusiveXor( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupExclusiveXor( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupExclusiveXor( U32Vec4 const value );
	SDW_API RetBoolean subgroupExclusiveXor( Boolean const value );
	SDW_API RetBVec2 subgroupExclusiveXor( BVec2 const value );
	SDW_API RetBVec3 subgroupExclusiveXor( BVec3 const value );
	SDW_API RetBVec4 subgroupExclusiveXor( BVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupClusterAdd
	/**
	*name
	*	subgroupClusterAdd
	*/
	/**@{*/
	SDW_API RetFloat subgroupClusterAdd( Float const value, UInt32 const clusterSize );
	SDW_API RetVec2 subgroupClusterAdd( Vec2 const value, UInt32 const clusterSize );
	SDW_API RetVec3 subgroupClusterAdd( Vec3 const value, UInt32 const clusterSize );
	SDW_API RetVec4 subgroupClusterAdd( Vec4 const value, UInt32 const clusterSize );
	SDW_API RetInt32 subgroupClusterAdd( Int32 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec2 subgroupClusterAdd( I32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec3 subgroupClusterAdd( I32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec4 subgroupClusterAdd( I32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetUInt32 subgroupClusterAdd( UInt32 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec2 subgroupClusterAdd( U32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec3 subgroupClusterAdd( U32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec4 subgroupClusterAdd( U32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetDouble subgroupClusterAdd( Double const value, UInt32 const clusterSize );
	SDW_API RetDVec2 subgroupClusterAdd( DVec2 const value, UInt32 const clusterSize );
	SDW_API RetDVec3 subgroupClusterAdd( DVec3 const value, UInt32 const clusterSize );
	SDW_API RetDVec4 subgroupClusterAdd( DVec4 const value, UInt32 const clusterSize );
	/**@}*/
#pragma endregion
#pragma region subgroupClusterMul
	/**
	*name
	*	subgroupClusterMul
	*/
	/**@{*/
	SDW_API RetFloat subgroupClusterMul( Float const value, UInt32 const clusterSize );
	SDW_API RetVec2 subgroupClusterMul( Vec2 const value, UInt32 const clusterSize );
	SDW_API RetVec3 subgroupClusterMul( Vec3 const value, UInt32 const clusterSize );
	SDW_API RetVec4 subgroupClusterMul( Vec4 const value, UInt32 const clusterSize );
	SDW_API RetInt32 subgroupClusterMul( Int32 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec2 subgroupClusterMul( I32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec3 subgroupClusterMul( I32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec4 subgroupClusterMul( I32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetUInt32 subgroupClusterMul( UInt32 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec2 subgroupClusterMul( U32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec3 subgroupClusterMul( U32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec4 subgroupClusterMul( U32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetDouble subgroupClusterMul( Double const value, UInt32 const clusterSize );
	SDW_API RetDVec2 subgroupClusterMul( DVec2 const value, UInt32 const clusterSize );
	SDW_API RetDVec3 subgroupClusterMul( DVec3 const value, UInt32 const clusterSize );
	SDW_API RetDVec4 subgroupClusterMul( DVec4 const value, UInt32 const clusterSize );
	/**@}*/
#pragma endregion
#pragma region subgroupClusterMin
	/**
	*name
	*	subgroupClusterMin
	*/
	/**@{*/
	SDW_API RetFloat subgroupClusterMin( Float const value, UInt32 const clusterSize );
	SDW_API RetVec2 subgroupClusterMin( Vec2 const value, UInt32 const clusterSize );
	SDW_API RetVec3 subgroupClusterMin( Vec3 const value, UInt32 const clusterSize );
	SDW_API RetVec4 subgroupClusterMin( Vec4 const value, UInt32 const clusterSize );
	SDW_API RetInt32 subgroupClusterMin( Int32 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec2 subgroupClusterMin( I32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec3 subgroupClusterMin( I32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec4 subgroupClusterMin( I32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetUInt32 subgroupClusterMin( UInt32 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec2 subgroupClusterMin( U32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec3 subgroupClusterMin( U32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec4 subgroupClusterMin( U32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetDouble subgroupClusterMin( Double const value, UInt32 const clusterSize );
	SDW_API RetDVec2 subgroupClusterMin( DVec2 const value, UInt32 const clusterSize );
	SDW_API RetDVec3 subgroupClusterMin( DVec3 const value, UInt32 const clusterSize );
	SDW_API RetDVec4 subgroupClusterMin( DVec4 const value, UInt32 const clusterSize );
	/**@}*/
#pragma endregion
#pragma region subgroupClusterMax
	/**
	*name
	*	subgroupClusterMax
	*/
	/**@{*/
	SDW_API RetFloat subgroupClusterMax( Float const value, UInt32 const clusterSize );
	SDW_API RetVec2 subgroupClusterMax( Vec2 const value, UInt32 const clusterSize );
	SDW_API RetVec3 subgroupClusterMax( Vec3 const value, UInt32 const clusterSize );
	SDW_API RetVec4 subgroupClusterMax( Vec4 const value, UInt32 const clusterSize );
	SDW_API RetInt32 subgroupClusterMax( Int32 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec2 subgroupClusterMax( I32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec3 subgroupClusterMax( I32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec4 subgroupClusterMax( I32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetUInt32 subgroupClusterMax( UInt32 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec2 subgroupClusterMax( U32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec3 subgroupClusterMax( U32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec4 subgroupClusterMax( U32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetDouble subgroupClusterMax( Double const value, UInt32 const clusterSize );
	SDW_API RetDVec2 subgroupClusterMax( DVec2 const value, UInt32 const clusterSize );
	SDW_API RetDVec3 subgroupClusterMax( DVec3 const value, UInt32 const clusterSize );
	SDW_API RetDVec4 subgroupClusterMax( DVec4 const value, UInt32 const clusterSize );
	/**@}*/
#pragma endregion
#pragma region subgroupClusterAnd
	/**
	*name
	*	subgroupClusterAnd
	*/
	/**@{*/
	SDW_API RetInt32 subgroupClusterAnd( Int32 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec2 subgroupClusterAnd( I32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec3 subgroupClusterAnd( I32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec4 subgroupClusterAnd( I32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetUInt32 subgroupClusterAnd( UInt32 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec2 subgroupClusterAnd( U32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec3 subgroupClusterAnd( U32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec4 subgroupClusterAnd( U32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetBoolean subgroupClusterAnd( Boolean const value, UInt32 const clusterSize );
	SDW_API RetBVec2 subgroupClusterAnd( BVec2 const value, UInt32 const clusterSize );
	SDW_API RetBVec3 subgroupClusterAnd( BVec3 const value, UInt32 const clusterSize );
	SDW_API RetBVec4 subgroupClusterAnd( BVec4 const value, UInt32 const clusterSize );
	/**@}*/
#pragma endregion
#pragma region subgroupClusterOr
	/**
	*name
	*	subgroupClusterOr
	*/
	/**@{*/
	SDW_API RetInt32 subgroupClusterOr( Int32 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec2 subgroupClusterOr( I32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec3 subgroupClusterOr( I32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec4 subgroupClusterOr( I32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetUInt32 subgroupClusterOr( UInt32 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec2 subgroupClusterOr( U32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec3 subgroupClusterOr( U32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec4 subgroupClusterOr( U32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetBoolean subgroupClusterOr( Boolean const value, UInt32 const clusterSize );
	SDW_API RetBVec2 subgroupClusterOr( BVec2 const value, UInt32 const clusterSize );
	SDW_API RetBVec3 subgroupClusterOr( BVec3 const value, UInt32 const clusterSize );
	SDW_API RetBVec4 subgroupClusterOr( BVec4 const value, UInt32 const clusterSize );
	/**@}*/
#pragma endregion
#pragma region subgroupClusterXor
	/**
	*name
	*	subgroupClusterXor
	*/
	/**@{*/
	SDW_API RetInt32 subgroupClusterXor( Int32 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec2 subgroupClusterXor( I32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec3 subgroupClusterXor( I32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetI32Vec4 subgroupClusterXor( I32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetUInt32 subgroupClusterXor( UInt32 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec2 subgroupClusterXor( U32Vec2 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec3 subgroupClusterXor( U32Vec3 const value, UInt32 const clusterSize );
	SDW_API RetU32Vec4 subgroupClusterXor( U32Vec4 const value, UInt32 const clusterSize );
	SDW_API RetBoolean subgroupClusterXor( Boolean const value, UInt32 const clusterSize );
	SDW_API RetBVec2 subgroupClusterXor( BVec2 const value, UInt32 const clusterSize );
	SDW_API RetBVec3 subgroupClusterXor( BVec3 const value, UInt32 const clusterSize );
	SDW_API RetBVec4 subgroupClusterXor( BVec4 const value, UInt32 const clusterSize );
	/**@}*/
#pragma endregion
#pragma region subgroupQuadBroadcast
	/**
	*name
	*	subgroupQuadBroadcast
	*/
	/**@{*/
	SDW_API RetFloat subgroupQuadBroadcast( Float const value, UInt32 const id );
	SDW_API RetVec2 subgroupQuadBroadcast( Vec2 const value, UInt32 const id );
	SDW_API RetVec3 subgroupQuadBroadcast( Vec3 const value, UInt32 const id );
	SDW_API RetVec4 subgroupQuadBroadcast( Vec4 const value, UInt32 const id );
	SDW_API RetInt32 subgroupQuadBroadcast( Int32 const value, UInt32 const id );
	SDW_API RetI32Vec2 subgroupQuadBroadcast( I32Vec2 const value, UInt32 const id );
	SDW_API RetI32Vec3 subgroupQuadBroadcast( I32Vec3 const value, UInt32 const id );
	SDW_API RetI32Vec4 subgroupQuadBroadcast( I32Vec4 const value, UInt32 const id );
	SDW_API RetUInt32 subgroupQuadBroadcast( UInt32 const value, UInt32 const id );
	SDW_API RetU32Vec2 subgroupQuadBroadcast( U32Vec2 const value, UInt32 const id );
	SDW_API RetU32Vec3 subgroupQuadBroadcast( U32Vec3 const value, UInt32 const id );
	SDW_API RetU32Vec4 subgroupQuadBroadcast( U32Vec4 const value, UInt32 const id );
	SDW_API RetBoolean subgroupQuadBroadcast( Boolean const value, UInt32 const id );
	SDW_API RetBVec2 subgroupQuadBroadcast( BVec2 const value, UInt32 const id );
	SDW_API RetBVec3 subgroupQuadBroadcast( BVec3 const value, UInt32 const id );
	SDW_API RetBVec4 subgroupQuadBroadcast( BVec4 const value, UInt32 const id );
	SDW_API RetDouble subgroupQuadBroadcast( Double const value, UInt32 const id );
	SDW_API RetDVec2 subgroupQuadBroadcast( DVec2 const value, UInt32 const id );
	SDW_API RetDVec3 subgroupQuadBroadcast( DVec3 const value, UInt32 const id );
	SDW_API RetDVec4 subgroupQuadBroadcast( DVec4 const value, UInt32 const id );
	/**@}*/
#pragma endregion
#pragma region subgroupQuadSwapHorizontal
	/**
	*name
	*	subgroupQuadSwapHorizontal
	*/
	/**@{*/
	SDW_API RetFloat subgroupQuadSwapHorizontal( Float const value );
	SDW_API RetVec2 subgroupQuadSwapHorizontal( Vec2 const value );
	SDW_API RetVec3 subgroupQuadSwapHorizontal( Vec3 const value );
	SDW_API RetVec4 subgroupQuadSwapHorizontal( Vec4 const value );
	SDW_API RetInt32 subgroupQuadSwapHorizontal( Int32 const value );
	SDW_API RetI32Vec2 subgroupQuadSwapHorizontal( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupQuadSwapHorizontal( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupQuadSwapHorizontal( I32Vec4 const value );
	SDW_API RetUInt32 subgroupQuadSwapHorizontal( UInt32 const value );
	SDW_API RetU32Vec2 subgroupQuadSwapHorizontal( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupQuadSwapHorizontal( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupQuadSwapHorizontal( U32Vec4 const value );
	SDW_API RetBoolean subgroupQuadSwapHorizontal( Boolean const value );
	SDW_API RetBVec2 subgroupQuadSwapHorizontal( BVec2 const value );
	SDW_API RetBVec3 subgroupQuadSwapHorizontal( BVec3 const value );
	SDW_API RetBVec4 subgroupQuadSwapHorizontal( BVec4 const value );
	SDW_API RetDouble subgroupQuadSwapHorizontal( Double const value );
	SDW_API RetDVec2 subgroupQuadSwapHorizontal( DVec2 const value );
	SDW_API RetDVec3 subgroupQuadSwapHorizontal( DVec3 const value );
	SDW_API RetDVec4 subgroupQuadSwapHorizontal( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupQuadSwapVertical
	/**
	*name
	*	subgroupQuadSwapVertical
	*/
	/**@{*/
	SDW_API RetFloat subgroupQuadSwapVertical( Float const value );
	SDW_API RetVec2 subgroupQuadSwapVertical( Vec2 const value );
	SDW_API RetVec3 subgroupQuadSwapVertical( Vec3 const value );
	SDW_API RetVec4 subgroupQuadSwapVertical( Vec4 const value );
	SDW_API RetInt32 subgroupQuadSwapVertical( Int32 const value );
	SDW_API RetI32Vec2 subgroupQuadSwapVertical( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupQuadSwapVertical( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupQuadSwapVertical( I32Vec4 const value );
	SDW_API RetUInt32 subgroupQuadSwapVertical( UInt32 const value );
	SDW_API RetU32Vec2 subgroupQuadSwapVertical( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupQuadSwapVertical( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupQuadSwapVertical( U32Vec4 const value );
	SDW_API RetBoolean subgroupQuadSwapVertical( Boolean const value );
	SDW_API RetBVec2 subgroupQuadSwapVertical( BVec2 const value );
	SDW_API RetBVec3 subgroupQuadSwapVertical( BVec3 const value );
	SDW_API RetBVec4 subgroupQuadSwapVertical( BVec4 const value );
	SDW_API RetDouble subgroupQuadSwapVertical( Double const value );
	SDW_API RetDVec2 subgroupQuadSwapVertical( DVec2 const value );
	SDW_API RetDVec3 subgroupQuadSwapVertical( DVec3 const value );
	SDW_API RetDVec4 subgroupQuadSwapVertical( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region subgroupQuadSwapDiagonal
	/**
	*name
	*	subgroupQuadSwapDiagonal
	*/
	/**@{*/
	SDW_API RetFloat subgroupQuadSwapDiagonal( Float const value );
	SDW_API RetVec2 subgroupQuadSwapDiagonal( Vec2 const value );
	SDW_API RetVec3 subgroupQuadSwapDiagonal( Vec3 const value );
	SDW_API RetVec4 subgroupQuadSwapDiagonal( Vec4 const value );
	SDW_API RetInt32 subgroupQuadSwapDiagonal( Int32 const value );
	SDW_API RetI32Vec2 subgroupQuadSwapDiagonal( I32Vec2 const value );
	SDW_API RetI32Vec3 subgroupQuadSwapDiagonal( I32Vec3 const value );
	SDW_API RetI32Vec4 subgroupQuadSwapDiagonal( I32Vec4 const value );
	SDW_API RetUInt32 subgroupQuadSwapDiagonal( UInt32 const value );
	SDW_API RetU32Vec2 subgroupQuadSwapDiagonal( U32Vec2 const value );
	SDW_API RetU32Vec3 subgroupQuadSwapDiagonal( U32Vec3 const value );
	SDW_API RetU32Vec4 subgroupQuadSwapDiagonal( U32Vec4 const value );
	SDW_API RetBoolean subgroupQuadSwapDiagonal( Boolean const value );
	SDW_API RetBVec2 subgroupQuadSwapDiagonal( BVec2 const value );
	SDW_API RetBVec3 subgroupQuadSwapDiagonal( BVec3 const value );
	SDW_API RetBVec4 subgroupQuadSwapDiagonal( BVec4 const value );
	SDW_API RetDouble subgroupQuadSwapDiagonal( Double const value );
	SDW_API RetDVec2 subgroupQuadSwapDiagonal( DVec2 const value );
	SDW_API RetDVec3 subgroupQuadSwapDiagonal( DVec3 const value );
	SDW_API RetDVec4 subgroupQuadSwapDiagonal( DVec4 const value );
	/**@}*/
#pragma endregion
#pragma region readInvocation
	/**
	*name
	*	readInvocation
	*/
	/**@{*/
	SDW_API RetFloat readInvocation( Float const value, UInt const invocationIndex );
	SDW_API RetVec2 readInvocation( Vec2 const value, UInt const invocationIndex );
	SDW_API RetVec3 readInvocation( Vec3 const value, UInt const invocationIndex );
	SDW_API RetVec4 readInvocation( Vec4 const value, UInt const invocationIndex );
	SDW_API RetInt32 readInvocation( Int32 const value, UInt const invocationIndex );
	SDW_API RetI32Vec2 readInvocation( I32Vec2 const value, UInt const invocationIndex );
	SDW_API RetI32Vec3 readInvocation( I32Vec3 const value, UInt const invocationIndex );
	SDW_API RetI32Vec4 readInvocation( I32Vec4 const value, UInt const invocationIndex );
	SDW_API RetUInt32 readInvocation( UInt32 const value, UInt const invocationIndex );
	SDW_API RetU32Vec2 readInvocation( U32Vec2 const value, UInt const invocationIndex );
	SDW_API RetU32Vec3 readInvocation( U32Vec3 const value, UInt const invocationIndex );
	SDW_API RetU32Vec4 readInvocation( U32Vec4 const value, UInt const invocationIndex );
	SDW_API RetDouble readInvocation( Double const value, UInt const invocationIndex );
	SDW_API RetDVec2 readInvocation( DVec2 const value, UInt const invocationIndex );
	SDW_API RetDVec3 readInvocation( DVec3 const value, UInt const invocationIndex );
	SDW_API RetDVec4 readInvocation( DVec4 const value, UInt const invocationIndex );
	/**@}*/
#pragma endregion
#pragma region readFirstInvocation
	/**
	*name
	*	readFirstInvocation
	*/
	/**@{*/
	SDW_API RetFloat readFirstInvocation( Float const value );
	SDW_API RetVec2 readFirstInvocation( Vec2 const value );
	SDW_API RetVec3 readFirstInvocation( Vec3 const value );
	SDW_API RetVec4 readFirstInvocation( Vec4 const value );
	SDW_API RetInt32 readFirstInvocation( Int32 const value );
	SDW_API RetI32Vec2 readFirstInvocation( I32Vec2 const value );
	SDW_API RetI32Vec3 readFirstInvocation( I32Vec3 const value );
	SDW_API RetI32Vec4 readFirstInvocation( I32Vec4 const value );
	SDW_API RetUInt32 readFirstInvocation( UInt32 const value );
	SDW_API RetU32Vec2 readFirstInvocation( U32Vec2 const value );
	SDW_API RetU32Vec3 readFirstInvocation( U32Vec3 const value );
	SDW_API RetU32Vec4 readFirstInvocation( U32Vec4 const value );
	SDW_API RetDouble readFirstInvocation( Double const value );
	SDW_API RetDVec2 readFirstInvocation( DVec2 const value );
	SDW_API RetDVec3 readFirstInvocation( DVec3 const value );
	SDW_API RetDVec4 readFirstInvocation( DVec4 const value );
	/**@}*/
#pragma endregion
}

#endif
