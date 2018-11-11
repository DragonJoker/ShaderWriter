
/*
See LICENSE file in root folder
*/
#ifndef ___SDW_IntrinsicFunctions_H___
#define ___SDW_IntrinsicFunctions_H___
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

#include <ASTGenerator/Expr/MakeIntrinsic.hpp>

namespace sdw
{
#pragma region degrees
	/**
	*name
	*	degrees
	*/
	/**@{*/
	Float degrees( Float const & radians );
	Vec2 degrees( Vec2 const & radians );
	Vec3 degrees( Vec3 const & radians );
	Vec4 degrees( Vec4 const & radians );
	/**@}*/
#pragma endregion
#pragma region radians
	/**
	*name
	*	radians
	*/
	/**@{*/
	Float radians( Float const & degrees );
	Vec2 radians( Vec2 const & degrees );
	Vec3 radians( Vec3 const & degrees );
	Vec4 radians( Vec4 const & degrees );
	/**@}*/
#pragma endregion
#pragma region cos
	/**
	*name
	*	cos
	*/
	/**@{*/
	Float cos( Float const & x );
	Vec2 cos( Vec2 const & x );
	Vec3 cos( Vec3 const & x );
	Vec4 cos( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region sin
	/**
	*name
	*	sin
	*/
	/**@{*/
	Float sin( Float const & x );
	Vec2 sin( Vec2 const & x );
	Vec3 sin( Vec3 const & x );
	Vec4 sin( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region tan
	/**
	*name
	*	tan
	*/
	/**@{*/
	Float tan( Float const & x );
	Vec2 tan( Vec2 const & x );
	Vec3 tan( Vec3 const & x );
	Vec4 tan( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region cosh
	/**
	*name
	*	cosh
	*/
	/**@{*/
	Float cosh( Float const & x );
	Vec2 cosh( Vec2 const & x );
	Vec3 cosh( Vec3 const & x );
	Vec4 cosh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region sinh
	/**
	*name
	*	sinh
	*/
	/**@{*/
	Float sinh( Float const & x );
	Vec2 sinh( Vec2 const & x );
	Vec3 sinh( Vec3 const & x );
	Vec4 sinh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region tanh
	/**
	*name
	*	tanh
	*/
	/**@{*/
	Float tanh( Float const & x );
	Vec2 tanh( Vec2 const & x );
	Vec3 tanh( Vec3 const & x );
	Vec4 tanh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region acos
	/**
	*name
	*	acos
	*/
	/**@{*/
	Float acos( Float const & x );
	Vec2 acos( Vec2 const & x );
	Vec3 acos( Vec3 const & x );
	Vec4 acos( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region asin
	/**
	*name
	*	asin
	*/
	/**@{*/
	Float asin( Float const & x );
	Vec2 asin( Vec2 const & x );
	Vec3 asin( Vec3 const & x );
	Vec4 asin( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region atan
	/**
	*name
	*	atan
	*/
	/**@{*/
	Float atan( Float const & x );
	Vec2 atan( Vec2 const & x );
	Vec3 atan( Vec3 const & x );
	Vec4 atan( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region acosh
	/**
	*name
	*	acosh
	*/
	/**@{*/
	Float acosh( Float const & x );
	Vec2 acosh( Vec2 const & x );
	Vec3 acosh( Vec3 const & x );
	Vec4 acosh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region asinh
	/**
	*name
	*	asinh
	*/
	/**@{*/
	Float asinh( Float const & x );
	Vec2 asinh( Vec2 const & x );
	Vec3 asinh( Vec3 const & x );
	Vec4 asinh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region atanh
	/**
	*name
	*	atanh
	*/
	/**@{*/
	Float atanh( Float const & x );
	Vec2 atanh( Vec2 const & x );
	Vec3 atanh( Vec3 const & x );
	Vec4 atanh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region pow
	/**
	*name
	*	pow
	*/
	/**@{*/
	Float pow( Float const & x, Float const & y );
	Vec2 pow( Vec2 const & x, Vec2 const & y );
	Vec3 pow( Vec3 const & x, Vec3 const & y );
	Vec4 pow( Vec4 const & x, Vec4 const & y );
	/**@}*/
#pragma endregion
#pragma region exp
	/**
	*name
	*	exp
	*/
	/**@{*/
	Float exp( Float const & x );
	Vec2 exp( Vec2 const & x );
	Vec3 exp( Vec3 const & x );
	Vec4 exp( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region log
	/**
	*name
	*	log
	*/
	/**@{*/
	Float log( Float const & x );
	Vec2 log( Vec2 const & x );
	Vec3 log( Vec3 const & x );
	Vec4 log( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region exp2
	/**
	*name
	*	exp2
	*/
	/**@{*/
	Float exp2( Float const & x );
	Vec2 exp2( Vec2 const & x );
	Vec3 exp2( Vec3 const & x );
	Vec4 exp2( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region log2
	/**
	*name
	*	log2
	*/
	/**@{*/
	Float log2( Float const & x );
	Vec2 log2( Vec2 const & x );
	Vec3 log2( Vec3 const & x );
	Vec4 log2( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region sqrt
	/**
	*name
	*	sqrt
	*/
	/**@{*/
	Float sqrt( Float const & x );
	Vec2 sqrt( Vec2 const & x );
	Vec3 sqrt( Vec3 const & x );
	Vec4 sqrt( Vec4 const & x );
	Double sqrt( Double const & x );
	DVec2 sqrt( DVec2 const & x );
	DVec3 sqrt( DVec3 const & x );
	DVec4 sqrt( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region inverseSqrt
	/**
	*name
	*	inverseSqrt
	*/
	/**@{*/
	Float inverseSqrt( Float const & x );
	Vec2 inverseSqrt( Vec2 const & x );
	Vec3 inverseSqrt( Vec3 const & x );
	Vec4 inverseSqrt( Vec4 const & x );
	Double inverseSqrt( Double const & x );
	DVec2 inverseSqrt( DVec2 const & x );
	DVec3 inverseSqrt( DVec3 const & x );
	DVec4 inverseSqrt( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region abs
	/**
	*name
	*	abs
	*/
	/**@{*/
	Float abs( Float const & x );
	Vec2 abs( Vec2 const & x );
	Vec3 abs( Vec3 const & x );
	Vec4 abs( Vec4 const & x );
	Int abs( Int const & x );
	IVec2 abs( IVec2 const & x );
	IVec3 abs( IVec3 const & x );
	IVec4 abs( IVec4 const & x );
	Double abs( Double const & x );
	DVec2 abs( DVec2 const & x );
	DVec3 abs( DVec3 const & x );
	DVec4 abs( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region sign
	/**
	*name
	*	sign
	*/
	/**@{*/
	Float sign( Float const & x );
	Vec2 sign( Vec2 const & x );
	Vec3 sign( Vec3 const & x );
	Vec4 sign( Vec4 const & x );
	Int sign( Int const & x );
	IVec2 sign( IVec2 const & x );
	IVec3 sign( IVec3 const & x );
	IVec4 sign( IVec4 const & x );
	Double sign( Double const & x );
	DVec2 sign( DVec2 const & x );
	DVec3 sign( DVec3 const & x );
	DVec4 sign( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region floor
	/**
	*name
	*	floor
	*/
	/**@{*/
	Float floor( Float const & x );
	Vec2 floor( Vec2 const & x );
	Vec3 floor( Vec3 const & x );
	Vec4 floor( Vec4 const & x );
	Double floor( Double const & x );
	DVec2 floor( DVec2 const & x );
	DVec3 floor( DVec3 const & x );
	DVec4 floor( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region trunc
	/**
	*name
	*	trunc
	*/
	/**@{*/
	Float trunc( Float const & x );
	Vec2 trunc( Vec2 const & x );
	Vec3 trunc( Vec3 const & x );
	Vec4 trunc( Vec4 const & x );
	Double trunc( Double const & x );
	DVec2 trunc( DVec2 const & x );
	DVec3 trunc( DVec3 const & x );
	DVec4 trunc( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region round
	/**
	*name
	*	round
	*/
	/**@{*/
	Float round( Float const & x );
	Vec2 round( Vec2 const & x );
	Vec3 round( Vec3 const & x );
	Vec4 round( Vec4 const & x );
	Double round( Double const & x );
	DVec2 round( DVec2 const & x );
	DVec3 round( DVec3 const & x );
	DVec4 round( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region roundEven
	/**
	*name
	*	roundEven
	*/
	/**@{*/
	Float roundEven( Float const & x );
	Vec2 roundEven( Vec2 const & x );
	Vec3 roundEven( Vec3 const & x );
	Vec4 roundEven( Vec4 const & x );
	Double roundEven( Double const & x );
	DVec2 roundEven( DVec2 const & x );
	DVec3 roundEven( DVec3 const & x );
	DVec4 roundEven( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region ceil
	/**
	*name
	*	ceil
	*/
	/**@{*/
	Float ceil( Float const & x );
	Vec2 ceil( Vec2 const & x );
	Vec3 ceil( Vec3 const & x );
	Vec4 ceil( Vec4 const & x );
	Double ceil( Double const & x );
	DVec2 ceil( DVec2 const & x );
	DVec3 ceil( DVec3 const & x );
	DVec4 ceil( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region fract
	/**
	*name
	*	fract
	*/
	/**@{*/
	Float fract( Float const & x );
	Vec2 fract( Vec2 const & x );
	Vec3 fract( Vec3 const & x );
	Vec4 fract( Vec4 const & x );
	Double fract( Double const & x );
	DVec2 fract( DVec2 const & x );
	DVec3 fract( DVec3 const & x );
	DVec4 fract( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region mod
	/**
	*name
	*	mod
	*/
	/**@{*/
	Float mod( Float const & x, Float const & y );
	Vec2 mod( Vec2 const & x, Vec2 const & y );
	Vec3 mod( Vec3 const & x, Vec3 const & y );
	Vec4 mod( Vec4 const & x, Vec4 const & y );
	Vec2 mod( Vec2 const & x, Float const & y );
	Vec3 mod( Vec3 const & x, Float const & y );
	Vec4 mod( Vec4 const & x, Float const & y );
	Double mod( Double const & x, Double const & y );
	DVec2 mod( DVec2 const & x, DVec2 const & y );
	DVec3 mod( DVec3 const & x, DVec3 const & y );
	DVec4 mod( DVec4 const & x, DVec4 const & y );
	DVec2 mod( DVec2 const & x, Double const & y );
	DVec3 mod( DVec3 const & x, Double const & y );
	DVec4 mod( DVec4 const & x, Double const & y );
	/**@}*/
#pragma endregion
#pragma region modf
	/**
	*name
	*	modf
	*/
	/**@{*/
	Float modf( Float const & x, Float const & i );
	Vec2 modf( Vec2 const & x, Vec2 const & i );
	Vec3 modf( Vec3 const & x, Vec3 const & i );
	Vec4 modf( Vec4 const & x, Vec4 const & i );
	Double modf( Double const & x, Double const & i );
	DVec2 modf( DVec2 const & x, DVec2 const & i );
	DVec3 modf( DVec3 const & x, DVec3 const & i );
	DVec4 modf( DVec4 const & x, DVec4 const & i );
	/**@}*/
#pragma endregion
#pragma region min
	/**
	*name
	*	min
	*/
	/**@{*/
	Float min( Float const & x, Float const & y );
	Vec2 min( Vec2 const & x, Vec2 const & y );
	Vec3 min( Vec3 const & x, Vec3 const & y );
	Vec4 min( Vec4 const & x, Vec4 const & y );
	Vec2 min( Vec2 const & x, Float const & y );
	Vec3 min( Vec3 const & x, Float const & y );
	Vec4 min( Vec4 const & x, Float const & y );
	Double min( Double const & x, Double const & y );
	DVec2 min( DVec2 const & x, DVec2 const & y );
	DVec3 min( DVec3 const & x, DVec3 const & y );
	DVec4 min( DVec4 const & x, DVec4 const & y );
	DVec2 min( DVec2 const & x, Double const & y );
	DVec3 min( DVec3 const & x, Double const & y );
	DVec4 min( DVec4 const & x, Double const & y );
	Int min( Int const & x, Int const & y );
	IVec2 min( IVec2 const & x, IVec2 const & y );
	IVec3 min( IVec3 const & x, IVec3 const & y );
	IVec4 min( IVec4 const & x, IVec4 const & y );
	IVec2 min( IVec2 const & x, Int const & y );
	IVec3 min( IVec3 const & x, Int const & y );
	IVec4 min( IVec4 const & x, Int const & y );
	UInt min( UInt const & x, UInt const & y );
	UVec2 min( UVec2 const & x, UVec2 const & y );
	UVec3 min( UVec3 const & x, UVec3 const & y );
	UVec4 min( UVec4 const & x, UVec4 const & y );
	UVec2 min( UVec2 const & x, UInt const & y );
	UVec3 min( UVec3 const & x, UInt const & y );
	UVec4 min( UVec4 const & x, UInt const & y );
	/**@}*/
#pragma endregion
#pragma region max
	/**
	*name
	*	max
	*/
	/**@{*/
	Float max( Float const & x, Float const & y );
	Vec2 max( Vec2 const & x, Vec2 const & y );
	Vec3 max( Vec3 const & x, Vec3 const & y );
	Vec4 max( Vec4 const & x, Vec4 const & y );
	Vec2 max( Vec2 const & x, Float const & y );
	Vec3 max( Vec3 const & x, Float const & y );
	Vec4 max( Vec4 const & x, Float const & y );
	Double max( Double const & x, Double const & y );
	DVec2 max( DVec2 const & x, DVec2 const & y );
	DVec3 max( DVec3 const & x, DVec3 const & y );
	DVec4 max( DVec4 const & x, DVec4 const & y );
	DVec2 max( DVec2 const & x, Double const & y );
	DVec3 max( DVec3 const & x, Double const & y );
	DVec4 max( DVec4 const & x, Double const & y );
	Int max( Int const & x, Int const & y );
	IVec2 max( IVec2 const & x, IVec2 const & y );
	IVec3 max( IVec3 const & x, IVec3 const & y );
	IVec4 max( IVec4 const & x, IVec4 const & y );
	IVec2 max( IVec2 const & x, Int const & y );
	IVec3 max( IVec3 const & x, Int const & y );
	IVec4 max( IVec4 const & x, Int const & y );
	UInt max( UInt const & x, UInt const & y );
	UVec2 max( UVec2 const & x, UVec2 const & y );
	UVec3 max( UVec3 const & x, UVec3 const & y );
	UVec4 max( UVec4 const & x, UVec4 const & y );
	UVec2 max( UVec2 const & x, UInt const & y );
	UVec3 max( UVec3 const & x, UInt const & y );
	UVec4 max( UVec4 const & x, UInt const & y );
	/**@}*/
#pragma endregion
#pragma region clamp
	/**
	*name
	*	clamp
	*/
	/**@{*/
	Float clamp( Float const & x, Float const & minVal, Float const & maxVal );
	Vec2 clamp( Vec2 const & x, Vec2 const & minVal, Vec2 const & maxVal );
	Vec3 clamp( Vec3 const & x, Vec3 const & minVal, Vec3 const & maxVal );
	Vec4 clamp( Vec4 const & x, Vec4 const & minVal, Vec4 const & maxVal );
	Vec2 clamp( Vec2 const & x, Float const & minVal, Float const & maxVal );
	Vec3 clamp( Vec3 const & x, Float const & minVal, Float const & maxVal );
	Vec4 clamp( Vec4 const & x, Float const & minVal, Float const & maxVal );
	Double clamp( Double const & x, Double const & minVal, Double const & maxVal );
	DVec2 clamp( DVec2 const & x, DVec2 const & minVal, DVec2 const & maxVal );
	DVec3 clamp( DVec3 const & x, DVec3 const & minVal, DVec3 const & maxVal );
	DVec4 clamp( DVec4 const & x, DVec4 const & minVal, DVec4 const & maxVal );
	DVec2 clamp( DVec2 const & x, Double const & minVal, Double const & maxVal );
	DVec3 clamp( DVec3 const & x, Double const & minVal, Double const & maxVal );
	DVec4 clamp( DVec4 const & x, Double const & minVal, Double const & maxVal );
	Int clamp( Int const & x, Int const & minVal, Int const & maxVal );
	IVec2 clamp( IVec2 const & x, IVec2 const & minVal, IVec2 const & maxVal );
	IVec3 clamp( IVec3 const & x, IVec3 const & minVal, IVec3 const & maxVal );
	IVec4 clamp( IVec4 const & x, IVec4 const & minVal, IVec4 const & maxVal );
	IVec2 clamp( IVec2 const & x, Int const & minVal, Int const & maxVal );
	IVec3 clamp( IVec3 const & x, Int const & minVal, Int const & maxVal );
	IVec4 clamp( IVec4 const & x, Int const & minVal, Int const & maxVal );
	UInt clamp( UInt const & x, UInt const & minVal, UInt const & maxVal );
	UVec2 clamp( UVec2 const & x, UVec2 const & minVal, UVec2 const & maxVal );
	UVec3 clamp( UVec3 const & x, UVec3 const & minVal, UVec3 const & maxVal );
	UVec4 clamp( UVec4 const & x, UVec4 const & minVal, UVec4 const & maxVal );
	UVec2 clamp( UVec2 const & x, UInt const & minVal, UInt const & maxVal );
	UVec3 clamp( UVec3 const & x, UInt const & minVal, UInt const & maxVal );
	UVec4 clamp( UVec4 const & x, UInt const & minVal, UInt const & maxVal );
	/**@}*/
#pragma endregion
#pragma region mix
	/**
	*name
	*	mix
	*/
	/**@{*/
	Float mix( Float const & x, Float const & y, Float const & a );
	Vec2 mix( Vec2 const & x, Vec2 const & y, Vec2 const & a );
	Vec3 mix( Vec3 const & x, Vec3 const & y, Vec3 const & a );
	Vec4 mix( Vec4 const & x, Vec4 const & y, Vec4 const & a );
	Vec2 mix( Vec2 const & x, Vec2 const & y, Float const & a );
	Vec3 mix( Vec3 const & x, Vec3 const & y, Float const & a );
	Vec4 mix( Vec4 const & x, Vec4 const & y, Float const & a );
	Float mix( Float const & x, Float const & y, Boolean const & a );
	Vec2 mix( Vec2 const & x, Vec2 const & y, BVec2 const & a );
	Vec3 mix( Vec3 const & x, Vec3 const & y, BVec3 const & a );
	Vec4 mix( Vec4 const & x, Vec4 const & y, BVec4 const & a );
	Double mix( Double const & x, Double const & y, Double const & a );
	DVec2 mix( DVec2 const & x, DVec2 const & y, DVec2 const & a );
	DVec3 mix( DVec3 const & x, DVec3 const & y, DVec3 const & a );
	DVec4 mix( DVec4 const & x, DVec4 const & y, DVec4 const & a );
	DVec2 mix( DVec2 const & x, DVec2 const & y, Double const & a );
	DVec3 mix( DVec3 const & x, DVec3 const & y, Double const & a );
	DVec4 mix( DVec4 const & x, DVec4 const & y, Double const & a );
	Double mix( Double const & x, Double const & y, Boolean const & a );
	DVec2 mix( DVec2 const & x, DVec2 const & y, BVec2 const & a );
	DVec3 mix( DVec3 const & x, DVec3 const & y, BVec3 const & a );
	DVec4 mix( DVec4 const & x, DVec4 const & y, BVec4 const & a );
	/**@}*/
#pragma endregion
#pragma region step
	/**
	*name
	*	step
	*/
	/**@{*/
	Float step( Float const & edge, Float const & x );
	Vec2 step( Vec2 const & edge, Vec2 const & x );
	Vec3 step( Vec3 const & edge, Vec3 const & x );
	Vec4 step( Vec4 const & edge, Vec4 const & x );
	Vec2 step( Float const & edge, Vec2 const & x );
	Vec3 step( Float const & edge, Vec3 const & x );
	Vec4 step( Float const & edge, Vec4 const & x );
	Double step( Double const & edge, Double const & x );
	DVec2 step( DVec2 const & edge, DVec2 const & x );
	DVec3 step( DVec3 const & edge, DVec3 const & x );
	DVec4 step( DVec4 const & edge, DVec4 const & x );
	DVec2 step( Double const & edge, DVec2 const & x );
	DVec3 step( Double const & edge, DVec3 const & x );
	DVec4 step( Double const & edge, DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region smoothStep
	/**
	*name
	*	smoothStep
	*/
	/**@{*/
	Float smoothStep( Float const & edge0, Float const & edge1, Float const & x );
	Vec2 smoothStep( Vec2 const & edge0, Vec2 const & edge1, Vec2 const & x );
	Vec3 smoothStep( Vec3 const & edge0, Vec3 const & edge1, Vec3 const & x );
	Vec4 smoothStep( Vec4 const & edge0, Vec4 const & edge1, Vec4 const & x );
	Vec2 smoothStep( Float const & edge0, Float const & edge1, Vec2 const & x );
	Vec3 smoothStep( Float const & edge0, Float const & edge1, Vec3 const & x );
	Vec4 smoothStep( Float const & edge0, Float const & edge1, Vec4 const & x );
	Double smoothStep( Double const & edge0, Double const & edge1, Double const & x );
	DVec2 smoothStep( DVec2 const & edge0, DVec2 const & edge1, DVec2 const & x );
	DVec3 smoothStep( DVec3 const & edge0, DVec3 const & edge1, DVec3 const & x );
	DVec4 smoothStep( DVec4 const & edge0, DVec4 const & edge1, DVec4 const & x );
	DVec2 smoothStep( Double const & edge0, Double const & edge1, DVec2 const & x );
	DVec3 smoothStep( Double const & edge0, Double const & edge1, DVec3 const & x );
	DVec4 smoothStep( Double const & edge0, Double const & edge1, DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region isnan
	/**
	*name
	*	isnan
	*/
	/**@{*/
	Boolean isnan( Float const & x );
	BVec2 isnan( Vec2 const & x );
	BVec3 isnan( Vec3 const & x );
	BVec4 isnan( Vec4 const & x );
	Boolean isnan( Double const & x );
	BVec2 isnan( DVec2 const & x );
	BVec3 isnan( DVec3 const & x );
	BVec4 isnan( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region isinf
	/**
	*name
	*	isinf
	*/
	/**@{*/
	Boolean isinf( Float const & x );
	BVec2 isinf( Vec2 const & x );
	BVec3 isinf( Vec3 const & x );
	BVec4 isinf( Vec4 const & x );
	Boolean isinf( Double const & x );
	BVec2 isinf( DVec2 const & x );
	BVec3 isinf( DVec3 const & x );
	BVec4 isinf( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region floatBitsToInt
	/**
	*name
	*	floatBitsToInt
	*/
	/**@{*/
	Int floatBitsToInt( Float const & value );
	IVec2 floatBitsToInt( Vec2 const & value );
	IVec3 floatBitsToInt( Vec3 const & value );
	IVec4 floatBitsToInt( Vec4 const & value );
	/**@}*/
#pragma endregion
#pragma region floatBitsToUInt
	/**
	*name
	*	floatBitsToUInt
	*/
	/**@{*/
	UInt floatBitsToUInt( Float const & value );
	UVec2 floatBitsToUInt( Vec2 const & value );
	UVec3 floatBitsToUInt( Vec3 const & value );
	UVec4 floatBitsToUInt( Vec4 const & value );
	/**@}*/
#pragma endregion
#pragma region intBitsToFloat
	/**
	*name
	*	intBitsToFloat
	*/
	/**@{*/
	Float intBitsToFloat( Int const & x );
	Vec2 intBitsToFloat( IVec2 const & x );
	Vec3 intBitsToFloat( IVec3 const & x );
	Vec4 intBitsToFloat( IVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region uintBitsToFloat
	/**
	*name
	*	uintBitsToFloat
	*/
	/**@{*/
	Float uintBitsToFloat( UInt const & x );
	Vec2 uintBitsToFloat( UVec2 const & x );
	Vec3 uintBitsToFloat( UVec3 const & x );
	Vec4 uintBitsToFloat( UVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region fma
	/**
	*name
	*	fma
	*/
	/**@{*/
	Float fma( Float const & a, Float const & b, Float const & c );
	Vec2 fma( Vec2 const & a, Vec2 const & b, Vec2 const & c );
	Vec3 fma( Vec3 const & a, Vec3 const & b, Vec3 const & c );
	Vec4 fma( Vec4 const & a, Vec4 const & b, Vec4 const & c );
	Double fma( Double const & a, Double const & b, Double const & c );
	DVec2 fma( DVec2 const & a, DVec2 const & b, DVec2 const & c );
	DVec3 fma( DVec3 const & a, DVec3 const & b, DVec3 const & c );
	DVec4 fma( DVec4 const & a, DVec4 const & b, DVec4 const & c );
	/**@}*/
#pragma endregion
#pragma region frexp
	/**
	*name
	*	frexp
	*/
	/**@{*/
	Float frexp( Float const & x, Int const & exp );
	Vec2 frexp( Vec2 const & x, IVec2 const & exp );
	Vec3 frexp( Vec3 const & x, IVec3 const & exp );
	Vec4 frexp( Vec4 const & x, IVec4 const & exp );
	Double frexp( Double const & x, Int const & exp );
	DVec2 frexp( DVec2 const & x, IVec2 const & exp );
	DVec3 frexp( DVec3 const & x, IVec3 const & exp );
	DVec4 frexp( DVec4 const & x, IVec4 const & exp );
	/**@}*/
#pragma endregion
#pragma region ldexp
	/**
	*name
	*	ldexp
	*/
	/**@{*/
	Float ldexp( Float const & x, Int const & exp );
	Vec2 ldexp( Vec2 const & x, IVec2 const & exp );
	Vec3 ldexp( Vec3 const & x, IVec3 const & exp );
	Vec4 ldexp( Vec4 const & x, IVec4 const & exp );
	Double ldexp( Double const & x, Int const & exp );
	DVec2 ldexp( DVec2 const & x, IVec2 const & exp );
	DVec3 ldexp( DVec3 const & x, IVec3 const & exp );
	DVec4 ldexp( DVec4 const & x, IVec4 const & exp );
	/**@}*/
#pragma endregion
#pragma region packDouble2x32
	/**
	*name
	*	packDouble2x32
	*/
	/**@{*/
	Double packDouble2x32( UVec2 const & v );
	/**@}*/
#pragma endregion
#pragma region packHalf2x16
	/**
	*name
	*	packHalf2x16
	*/
	/**@{*/
	UInt packHalf2x16( Vec2 const & v );
	/**@}*/
#pragma endregion
#pragma region packSnorm2x16
	/**
	*name
	*	packSnorm2x16
	*/
	/**@{*/
	UInt packSnorm2x16( Vec2 const & v );
	/**@}*/
#pragma endregion
#pragma region packSnorm4x8
	/**
	*name
	*	packSnorm4x8
	*/
	/**@{*/
	UInt packSnorm4x8( Vec4 const & v );
	/**@}*/
#pragma endregion
#pragma region packUnorm2x16
	/**
	*name
	*	packUnorm2x16
	*/
	/**@{*/
	UInt packUnorm2x16( Vec2 const & v );
	/**@}*/
#pragma endregion
#pragma region packUnorm4x8
	/**
	*name
	*	packUnorm4x8
	*/
	/**@{*/
	UInt packUnorm4x8( Vec4 const & v );
	/**@}*/
#pragma endregion
#pragma region unpackDouble2x32
	/**
	*name
	*	unpackDouble2x32
	*/
	/**@{*/
	UVec2 unpackDouble2x32( Double const & d );
	/**@}*/
#pragma endregion
#pragma region unpackHalf2x16
	/**
	*name
	*	unpackHalf2x16
	*/
	/**@{*/
	Vec2 unpackHalf2x16( UInt const & v );
	/**@}*/
#pragma endregion
#pragma region unpackSnorm2x16
	/**
	*name
	*	unpackSnorm2x16
	*/
	/**@{*/
	Vec2 unpackSnorm2x16( UInt const & p );
	/**@}*/
#pragma endregion
#pragma region unpackSnorm4x8
	/**
	*name
	*	unpackSnorm4x8
	*/
	/**@{*/
	Vec4 unpackSnorm4x8( UInt const & p );
	/**@}*/
#pragma endregion
#pragma region unpackUnorm2x16
	/**
	*name
	*	unpackUnorm2x16
	*/
	/**@{*/
	Vec2 unpackUnorm2x16( UInt const & p );
	/**@}*/
#pragma endregion
#pragma region unpackUnorm4x8
	/**
	*name
	*	unpackUnorm4x8
	*/
	/**@{*/
	Vec4 unpackUnorm4x8( UInt const & p );
	/**@}*/
#pragma endregion
#pragma region length
	/**
	*name
	*	length
	*/
	/**@{*/
	Float length( Float const & x );
	Float length( Vec2 const & x );
	Float length( Vec3 const & x );
	Float length( Vec4 const & x );
	Double length( Double const & x );
	Double length( DVec2 const & x );
	Double length( DVec3 const & x );
	Double length( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region distance
	/**
	*name
	*	distance
	*/
	/**@{*/
	Float distance( Float const & p0, Float const & p1 );
	Vec2 distance( Vec2 const & p0, Vec2 const & p1 );
	Vec3 distance( Vec3 const & p0, Vec3 const & p1 );
	Vec4 distance( Vec4 const & p0, Vec4 const & p1 );
	Double distance( Double const & p0, Double const & p1 );
	Double distance( DVec2 const & p0, DVec2 const & p1 );
	Double distance( DVec3 const & p0, DVec3 const & p1 );
	Double distance( DVec4 const & p0, DVec4 const & p1 );
	/**@}*/
#pragma endregion
#pragma region dot
	/**
	*name
	*	dot
	*/
	/**@{*/
	Float dot( Float const & x, Float const & y );
	Float dot( Vec2 const & x, Vec2 const & y );
	Float dot( Vec3 const & x, Vec3 const & y );
	Float dot( Vec4 const & x, Vec4 const & y );
	Double dot( Double const & x, Double const & y );
	Double dot( DVec2 const & x, DVec2 const & y );
	Double dot( DVec3 const & x, DVec3 const & y );
	Double dot( DVec4 const & x, DVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region cross
	/**
	*name
	*	cross
	*/
	/**@{*/
	Vec3 cross( Vec3 const & x, Vec3 const & y );
	DVec3 cross( DVec3 const & x, DVec3 const & y );
	/**@}*/
#pragma endregion
#pragma region normalize
	/**
	*name
	*	normalize
	*/
	/**@{*/
	Float normalize( Float const & x );
	Vec2 normalize( Vec2 const & x );
	Vec3 normalize( Vec3 const & x );
	Vec4 normalize( Vec4 const & x );
	Double normalize( Double const & x );
	DVec2 normalize( DVec2 const & x );
	DVec3 normalize( DVec3 const & x );
	DVec4 normalize( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region faceForward
	/**
	*name
	*	faceForward
	*/
	/**@{*/
	Float faceForward( Float const & N, Float const & I, Float const & Nref );
	Vec2 faceForward( Vec2 const & N, Vec2 const & I, Vec2 const & Nref );
	Vec3 faceForward( Vec3 const & N, Vec3 const & I, Vec3 const & Nref );
	Vec4 faceForward( Vec4 const & N, Vec4 const & I, Vec4 const & Nref );
	Double faceForward( Double const & N, Double const & I, Double const & Nref );
	DVec2 faceForward( DVec2 const & N, DVec2 const & I, DVec2 const & Nref );
	DVec3 faceForward( DVec3 const & N, DVec3 const & I, DVec3 const & Nref );
	DVec4 faceForward( DVec4 const & N, DVec4 const & I, DVec4 const & Nref );
	/**@}*/
#pragma endregion
#pragma region reflect
	/**
	*name
	*	reflect
	*/
	/**@{*/
	Float reflect( Float const & I, Float const & N );
	Vec2 reflect( Vec2 const & I, Vec2 const & N );
	Vec3 reflect( Vec3 const & I, Vec3 const & N );
	Vec4 reflect( Vec4 const & I, Vec4 const & N );
	Double reflect( Float const & I, Double const & N );
	DVec2 reflect( DVec2 const & I, DVec2 const & N );
	DVec3 reflect( DVec3 const & I, DVec3 const & N );
	DVec4 reflect( DVec4 const & I, DVec4 const & N );
	/**@}*/
#pragma endregion
#pragma region refract
	/**
	*name
	*	refract
	*/
	/**@{*/
	Float refract( Float const & I, Float const & N );
	Vec2 refract( Vec2 const & I, Vec2 const & N );
	Vec3 refract( Vec3 const & I, Vec3 const & N );
	Vec4 refract( Vec4 const & I, Vec4 const & N );
	Double refract( Double const & I, Double const & N );
	DVec2 refract( DVec2 const & I, DVec2 const & N );
	DVec3 refract( DVec3 const & I, DVec3 const & N );
	DVec4 refract( DVec4 const & I, DVec4 const & N );
	/**@}*/
#pragma endregion
#pragma region matrixCompMult
	/**
	*name
	*	matrixCompMult
	*/
	/**@{*/
	Mat2 matrixCompMult( Mat2 const & x, Mat2 const & y );
	Mat2x3 matrixCompMult( Mat2x3 const & x, Mat2x3 const & y );
	Mat2x4 matrixCompMult( Mat2x4 const & x, Mat2x4 const & y );
	Mat3x2 matrixCompMult( Mat3x2 const & x, Mat3x2 const & y );
	Mat3 matrixCompMult( Mat3 const & x, Mat3 const & y );
	Mat3x4 matrixCompMult( Mat3x4 const & x, Mat3x4 const & y );
	Mat4x2 matrixCompMult( Mat4x2 const & x, Mat4x2 const & y );
	Mat4x3 matrixCompMult( Mat4x3 const & x, Mat4x3 const & y );
	Mat4 matrixCompMult( Mat4 const & x, Mat4 const & y );
	DMat2 matrixCompMult( DMat2 const & x, DMat2 const & y );
	DMat2x3 matrixCompMult( DMat2x3 const & x, DMat2x3 const & y );
	DMat2x4 matrixCompMult( DMat2x4 const & x, DMat2x4 const & y );
	DMat3x2 matrixCompMult( DMat3x2 const & x, DMat3x2 const & y );
	DMat3 matrixCompMult( DMat3 const & x, DMat3 const & y );
	DMat3x4 matrixCompMult( DMat3x4 const & x, DMat3x4 const & y );
	DMat4x2 matrixCompMult( DMat4x2 const & x, DMat4x2 const & y );
	DMat4x3 matrixCompMult( DMat4x3 const & x, DMat4x3 const & y );
	DMat4 matrixCompMult( DMat4 const & x, DMat4 const & y );
	/**@}*/
#pragma endregion
#pragma region outerProduct
	/**
	*name
	*	outerProduct
	*/
	/**@{*/
	Mat2 outerProduct( Vec2 const & c, Vec2 const & r );
	Mat3 outerProduct( Vec3 const & c, Vec3 const & r );
	Mat4 outerProduct( Vec4 const & c, Vec4 const & r );
	Mat2x3 outerProduct( Vec3 const & c, Vec2 const & r );
	Mat3x2 outerProduct( Vec2 const & c, Vec3 const & r );
	Mat2x4 outerProduct( Vec4 const & c, Vec2 const & r );
	Mat4x2 outerProduct( Vec2 const & c, Vec4 const & r );
	Mat3x4 outerProduct( Vec4 const & c, Vec3 const & r );
	Mat4x3 outerProduct( Vec3 const & c, Vec4 const & r );
	DMat2 outerProduct( DVec2 const & c, DVec2 const & r );
	DMat3 outerProduct( DVec3 const & c, DVec3 const & r );
	DMat4 outerProduct( DVec4 const & c, DVec4 const & r );
	DMat2x3 outerProduct( DVec3 const & c, DVec2 const & r );
	DMat3x2 outerProduct( DVec2 const & c, DVec3 const & r );
	DMat2x4 outerProduct( DVec4 const & c, DVec2 const & r );
	DMat4x2 outerProduct( DVec2 const & c, DVec4 const & r );
	DMat3x4 outerProduct( DVec4 const & c, DVec3 const & r );
	DMat4x3 outerProduct( DVec3 const & c, DVec4 const & r );
	/**@}*/
#pragma endregion
#pragma region transpose
	/**
	*name
	*	transpose
	*/
	/**@{*/
	Mat2 transpose( Mat2 const & x );
	Mat3x2 transpose( Mat2x3 const & x );
	Mat4x2 transpose( Mat2x4 const & x );
	Mat2x3 transpose( Mat3x2 const & x );
	Mat3 transpose( Mat3 const & x );
	Mat4x3 transpose( Mat3x4 const & x );
	Mat2x4 transpose( Mat4x2 const & x );
	Mat3x4 transpose( Mat4x3 const & x );
	Mat4 transpose( Mat4 const & x );
	DMat2 transpose( DMat2 const & x );
	DMat3x2 transpose( DMat2x3 const & x );
	DMat4x2 transpose( DMat2x4 const & x );
	DMat2x3 transpose( DMat3x2 const & x );
	DMat3 transpose( DMat3 const & x );
	DMat4x3 transpose( DMat3x4 const & x );
	DMat2x4 transpose( DMat4x2 const & x );
	DMat3x4 transpose( DMat4x3 const & x );
	DMat4 transpose( DMat4 const & x );
	/**@}*/
#pragma endregion
#pragma region determinant
	/**
	*name
	*	determinant
	*/
	/**@{*/
	Float determinant( Mat2 const & m );
	Float determinant( Mat3 const & m );
	Float determinant( Mat4 const & m );
	Double determinant( DMat2 const & m );
	Double determinant( DMat3 const & m );
	Double determinant( DMat4 const & m );
	/**@}*/
#pragma endregion
#pragma region inverse
	/**
	*name
	*	inverse
	*/
	/**@{*/
	Mat2 inverse( Mat2 const & m );
	Mat3 inverse( Mat3 const & m );
	Mat4 inverse( Mat4 const & m );
	DMat2 inverse( DMat2 const & m );
	DMat3 inverse( DMat3 const & m );
	DMat4 inverse( DMat4 const & m );
	/**@}*/
#pragma endregion
#pragma region lessThan
	/**
	*name
	*	lessThan
	*/
	/**@{*/
	BVec2 lessThan( Vec2 const & x, Vec2 const & y );
	BVec3 lessThan( Vec3 const & x, Vec3 const & y );
	BVec4 lessThan( Vec4 const & x, Vec4 const & y );
	BVec2 lessThan( DVec2 const & x, DVec2 const & y );
	BVec3 lessThan( DVec3 const & x, DVec3 const & y );
	BVec4 lessThan( DVec4 const & x, DVec4 const & y );
	BVec2 lessThan( IVec2 const & x, IVec2 const & y );
	BVec3 lessThan( IVec3 const & x, IVec3 const & y );
	BVec4 lessThan( IVec4 const & x, IVec4 const & y );
	BVec2 lessThan( UVec2 const & x, UVec2 const & y );
	BVec3 lessThan( UVec3 const & x, UVec3 const & y );
	BVec4 lessThan( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region lessThanEqual
	/**
	*name
	*	lessThanEqual
	*/
	/**@{*/
	BVec2 lessThanEqual( Vec2 const & x, Vec2 const & y );
	BVec3 lessThanEqual( Vec3 const & x, Vec3 const & y );
	BVec4 lessThanEqual( Vec4 const & x, Vec4 const & y );
	BVec2 lessThanEqual( DVec2 const & x, DVec2 const & y );
	BVec3 lessThanEqual( DVec3 const & x, DVec3 const & y );
	BVec4 lessThanEqual( DVec4 const & x, DVec4 const & y );
	BVec2 lessThanEqual( IVec2 const & x, IVec2 const & y );
	BVec3 lessThanEqual( IVec3 const & x, IVec3 const & y );
	BVec4 lessThanEqual( IVec4 const & x, IVec4 const & y );
	BVec2 lessThanEqual( UVec2 const & x, UVec2 const & y );
	BVec3 lessThanEqual( UVec3 const & x, UVec3 const & y );
	BVec4 lessThanEqual( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region greaterThan
	/**
	*name
	*	greaterThan
	*/
	/**@{*/
	BVec2 greaterThan( Vec2 const & x, Vec2 const & y );
	BVec3 greaterThan( Vec3 const & x, Vec3 const & y );
	BVec4 greaterThan( Vec4 const & x, Vec4 const & y );
	BVec2 greaterThan( DVec2 const & x, DVec2 const & y );
	BVec3 greaterThan( DVec3 const & x, DVec3 const & y );
	BVec4 greaterThan( DVec4 const & x, DVec4 const & y );
	BVec2 greaterThan( IVec2 const & x, IVec2 const & y );
	BVec3 greaterThan( IVec3 const & x, IVec3 const & y );
	BVec4 greaterThan( IVec4 const & x, IVec4 const & y );
	BVec2 greaterThan( UVec2 const & x, UVec2 const & y );
	BVec3 greaterThan( UVec3 const & x, UVec3 const & y );
	BVec4 greaterThan( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region greaterThanEqual
	/**
	*name
	*	greaterThanEqual
	*/
	/**@{*/
	BVec2 greaterThanEqual( Vec2 const & x, Vec2 const & y );
	BVec3 greaterThanEqual( Vec3 const & x, Vec3 const & y );
	BVec4 greaterThanEqual( Vec4 const & x, Vec4 const & y );
	BVec2 greaterThanEqual( DVec2 const & x, DVec2 const & y );
	BVec3 greaterThanEqual( DVec3 const & x, DVec3 const & y );
	BVec4 greaterThanEqual( DVec4 const & x, DVec4 const & y );
	BVec2 greaterThanEqual( IVec2 const & x, IVec2 const & y );
	BVec3 greaterThanEqual( IVec3 const & x, IVec3 const & y );
	BVec4 greaterThanEqual( IVec4 const & x, IVec4 const & y );
	BVec2 greaterThanEqual( UVec2 const & x, UVec2 const & y );
	BVec3 greaterThanEqual( UVec3 const & x, UVec3 const & y );
	BVec4 greaterThanEqual( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region equal
	/**
	*name
	*	equal
	*/
	/**@{*/
	BVec2 equal( Vec2 const & x, Vec2 const & y );
	BVec3 equal( Vec3 const & x, Vec3 const & y );
	BVec4 equal( Vec4 const & x, Vec4 const & y );
	BVec2 equal( DVec2 const & x, DVec2 const & y );
	BVec3 equal( DVec3 const & x, DVec3 const & y );
	BVec4 equal( DVec4 const & x, DVec4 const & y );
	BVec2 equal( IVec2 const & x, IVec2 const & y );
	BVec3 equal( IVec3 const & x, IVec3 const & y );
	BVec4 equal( IVec4 const & x, IVec4 const & y );
	BVec2 equal( UVec2 const & x, UVec2 const & y );
	BVec3 equal( UVec3 const & x, UVec3 const & y );
	BVec4 equal( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region notEqual
	/**
	*name
	*	notEqual
	*/
	/**@{*/
	BVec2 notEqual( Vec2 const & x, Vec2 const & y );
	BVec3 notEqual( Vec3 const & x, Vec3 const & y );
	BVec4 notEqual( Vec4 const & x, Vec4 const & y );
	BVec2 notEqual( DVec2 const & x, DVec2 const & y );
	BVec3 notEqual( DVec3 const & x, DVec3 const & y );
	BVec4 notEqual( DVec4 const & x, DVec4 const & y );
	BVec2 notEqual( IVec2 const & x, IVec2 const & y );
	BVec3 notEqual( IVec3 const & x, IVec3 const & y );
	BVec4 notEqual( IVec4 const & x, IVec4 const & y );
	BVec2 notEqual( UVec2 const & x, UVec2 const & y );
	BVec3 notEqual( UVec3 const & x, UVec3 const & y );
	BVec4 notEqual( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region all
	/**
	*name
	*	all
	*/
	/**@{*/
	Boolean all( BVec2 const & x );
	Boolean all( BVec3 const & x );
	Boolean all( BVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region any
	/**
	*name
	*	any
	*/
	/**@{*/
	Boolean any( BVec2 const & x );
	Boolean any( BVec3 const & x );
	Boolean any( BVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region not
	/**
	*name
	*	not
	*/
	/**@{*/
	BVec2 not( BVec2 const & x );
	BVec3 not( BVec3 const & x );
	BVec4 not( BVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region uaddCarry
	/**
	*name
	*	uaddCarry
	*/
	/**@{*/
	UInt uaddCarry( UInt const & x, UInt const & y, UInt const & carry );
	UVec2 uaddCarry( UVec2 const & x, UVec2 const & y, UVec2 const & carry );
	UVec3 uaddCarry( UVec3 const & x, UVec3 const & y, UVec3 const & carry );
	UVec4 uaddCarry( UVec4 const & x, UVec4 const & y, UVec4 const & carry );
	/**@}*/
#pragma endregion
#pragma region usubBorrow
	/**
	*name
	*	usubBorrow
	*/
	/**@{*/
	UInt usubBorrow( UInt const & x, UInt const & y, UInt const & borrow );
	UVec2 usubBorrow( UVec2 const & x, UVec2 const & y, UVec2 const & borrow );
	UVec3 usubBorrow( UVec3 const & x, UVec3 const & y, UVec3 const & borrow );
	UVec4 usubBorrow( UVec4 const & x, UVec4 const & y, UVec4 const & borrow );
	/**@}*/
#pragma endregion
#pragma region umulExtended
	/**
	*name
	*	umulExtended
	*/
	/**@{*/
	Void umulExtended( UInt const & x, UInt const & y, UInt const & msb, UInt const & lsb );
	Void umulExtended( UVec2 const & x, UVec2 const & y, UVec2 const & msb, UVec2 const & lsb );
	Void umulExtended( UVec3 const & x, UVec3 const & y, UVec3 const & msb, UVec3 const & lsb );
	Void umulExtended( UVec4 const & x, UVec4 const & y, UVec4 const & msb, UVec4 const & lsb );
	/**@}*/
#pragma endregion
#pragma region imulExtended
	/**
	*name
	*	imulExtended
	*/
	/**@{*/
	Void imulExtended( Int const & x, Int const & y, Int const & msb, Int const & lsb );
	Void imulExtended( IVec2 const & x, IVec2 const & y, IVec2 const & msb, IVec2 const & lsb );
	Void imulExtended( IVec3 const & x, IVec3 const & y, IVec3 const & msb, IVec3 const & lsb );
	Void imulExtended( IVec4 const & x, IVec4 const & y, IVec4 const & msb, IVec4 const & lsb );
	/**@}*/
#pragma endregion
#pragma region bitfieldExtract
	/**
	*name
	*	bitfieldExtract
	*/
	/**@{*/
	Int bitfieldExtract( Int const & value, Int const & offset, Int const & bits );
	IVec2 bitfieldExtract( IVec2 const & value, Int const & offset, Int const & bits );
	IVec3 bitfieldExtract( IVec3 const & value, Int const & offset, Int const & bits );
	IVec4 bitfieldExtract( IVec4 const & value, Int const & offset, Int const & bits );
	UInt bitfieldExtract( UInt const & value, Int const & offset, Int const & bits );
	UVec2 bitfieldExtract( UVec2 const & value, Int const & offset, Int const & bits );
	UVec3 bitfieldExtract( UVec3 const & value, Int const & offset, Int const & bits );
	UVec4 bitfieldExtract( UVec4 const & value, Int const & offset, Int const & bits );
	/**@}*/
#pragma endregion
#pragma region bitfieldInsert
	/**
	*name
	*	bitfieldInsert
	*/
	/**@{*/
	Int bitfieldInsert( Int const & base, Int const & insert, Int const & offset, Int const & bits );
	IVec2 bitfieldInsert( IVec2 const & base, IVec2 const & insert, Int const & offset, Int const & bits );
	IVec3 bitfieldInsert( IVec3 const & base, IVec3 const & insert, Int const & offset, Int const & bits );
	IVec4 bitfieldInsert( IVec4 const & base, IVec4 const & insert, Int const & offset, Int const & bits );
	UInt bitfieldInsert( UInt const & base, UInt const & insert, Int const & offset, Int const & bits );
	UVec2 bitfieldInsert( UVec2 const & base, UVec2 const & insert, Int const & offset, Int const & bits );
	UVec3 bitfieldInsert( UVec3 const & base, UVec3 const & insert, Int const & offset, Int const & bits );
	UVec4 bitfieldInsert( UVec4 const & base, UVec4 const & insert, Int const & offset, Int const & bits );
	/**@}*/
#pragma endregion
#pragma region bitfieldReverse
	/**
	*name
	*	bitfieldReverse
	*/
	/**@{*/
	Int bitfieldReverse( Int const & value );
	IVec2 bitfieldReverse( IVec2 const & value );
	IVec3 bitfieldReverse( IVec3 const & value );
	IVec4 bitfieldReverse( IVec4 const & value );
	UInt bitfieldReverse( UInt const & value );
	UVec2 bitfieldReverse( UVec2 const & value );
	UVec3 bitfieldReverse( UVec3 const & value );
	UVec4 bitfieldReverse( UVec4 const & value );
	/**@}*/
#pragma endregion
#pragma region bitCount
	/**
	*name
	*	bitCount
	*/
	/**@{*/
	Int bitCount( Int const & value );
	IVec2 bitCount( IVec2 const & value );
	IVec3 bitCount( IVec3 const & value );
	IVec4 bitCount( IVec4 const & value );
	UInt bitCount( UInt const & value );
	UVec2 bitCount( UVec2 const & value );
	UVec3 bitCount( UVec3 const & value );
	UVec4 bitCount( UVec4 const & value );
	/**@}*/
#pragma endregion
#pragma region findLSB
	/**
	*name
	*	findLSB
	*/
	/**@{*/
	Int findLSB( Int const & value );
	IVec2 findLSB( IVec2 const & value );
	IVec3 findLSB( IVec3 const & value );
	IVec4 findLSB( IVec4 const & value );
	Int findLSB( UInt const & value );
	IVec2 findLSB( UVec2 const & value );
	IVec3 findLSB( UVec3 const & value );
	IVec4 findLSB( UVec4 const & value );
	/**@}*/
#pragma endregion
#pragma region findMSB
	/**
	*name
	*	findMSB
	*/
	/**@{*/
	Int findMSB( Int const & value );
	IVec2 findMSB( IVec2 const & value );
	IVec3 findMSB( IVec3 const & value );
	IVec4 findMSB( IVec4 const & value );
	Int findMSB( UInt const & value );
	IVec2 findMSB( UVec2 const & value );
	IVec3 findMSB( UVec3 const & value );
	IVec4 findMSB( UVec4 const & value );
	/**@}*/
#pragma endregion
#pragma region atomicAdd
	/**
	*name
	*	atomicAdd
	*/
	/**@{*/
	Int atomicAdd( Int const & mem, Int const & data );
	UInt atomicAdd( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicMin
	/**
	*name
	*	atomicMin
	*/
	/**@{*/
	Int atomicMin( Int const & mem, Int const & data );
	UInt atomicMin( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicMax
	/**
	*name
	*	atomicMax
	*/
	/**@{*/
	Int atomicMax( Int const & mem, Int const & data );
	UInt atomicMax( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicAnd
	/**
	*name
	*	atomicAnd
	*/
	/**@{*/
	Int atomicAnd( Int const & mem, Int const & data );
	UInt atomicAnd( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicOr
	/**
	*name
	*	atomicOr
	*/
	/**@{*/
	Int atomicOr( Int const & mem, Int const & data );
	UInt atomicOr( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicXor
	/**
	*name
	*	atomicXor
	*/
	/**@{*/
	Int atomicXor( Int const & mem, Int const & data );
	UInt atomicXor( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicExchange
	/**
	*name
	*	atomicExchange
	*/
	/**@{*/
	Int atomicExchange( Int const & mem, Int const & data );
	UInt atomicExchange( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicCompSwap
	/**
	*name
	*	atomicCompSwap
	*/
	/**@{*/
	Int atomicCompSwap( Int const & mem, UInt const & compare );
	UInt atomicCompSwap( UInt const & mem, UInt const & compare );
	/**@}*/
#pragma endregion
#pragma region dFdx
	/**
	*name
	*	dFdx
	*/
	/**@{*/
	Float dFdx( Float const & p );
	Vec2 dFdx( Vec2 const & p );
	Vec3 dFdx( Vec3 const & p );
	Vec4 dFdx( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region dFdxCoarse
	/**
	*name
	*	dFdxCoarse
	*/
	/**@{*/
	Float dFdxCoarse( Float const & p );
	Vec2 dFdxCoarse( Vec2 const & p );
	Vec3 dFdxCoarse( Vec3 const & p );
	Vec4 dFdxCoarse( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region dFdxFine
	/**
	*name
	*	dFdxFine
	*/
	/**@{*/
	Float dFdxFine( Float const & p );
	Vec2 dFdxFine( Vec2 const & p );
	Vec3 dFdxFine( Vec3 const & p );
	Vec4 dFdxFine( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region dFdy
	/**
	*name
	*	dFdy
	*/
	/**@{*/
	Float dFdy( Float const & p );
	Vec2 dFdy( Vec2 const & p );
	Vec3 dFdy( Vec3 const & p );
	Vec4 dFdy( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region dFdyCoarse
	/**
	*name
	*	dFdyCoarse
	*/
	/**@{*/
	Float dFdyCoarse( Float const & p );
	Vec2 dFdyCoarse( Vec2 const & p );
	Vec3 dFdyCoarse( Vec3 const & p );
	Vec4 dFdyCoarse( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region dFdyFine
	/**
	*name
	*	dFdyFine
	*/
	/**@{*/
	Float dFdyFine( Float const & p );
	Vec2 dFdyFine( Vec2 const & p );
	Vec3 dFdyFine( Vec3 const & p );
	Vec4 dFdyFine( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region fwidth
	/**
	*name
	*	fwidth
	*/
	/**@{*/
	Float fwidth( Float const & p );
	Vec2 fwidth( Vec2 const & p );
	Vec3 fwidth( Vec3 const & p );
	Vec4 fwidth( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region interpolateAtCentroid
	/**
	*name
	*	interpolateAtCentroid
	*/
	/**@{*/
	Float interpolateAtCentroid( Float const & x );
	Vec2 interpolateAtCentroid( Vec2 const & x );
	Vec3 interpolateAtCentroid( Vec3 const & x );
	Vec4 interpolateAtCentroid( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region interpolateAtSample
	/**
	*name
	*	interpolateAtSample
	*/
	/**@{*/
	Float interpolateAtSample( Float const & interpolant, Int const & sample );
	Vec2 interpolateAtSample( Vec2 const & interpolant, Int const & sample );
	Vec3 interpolateAtSample( Vec3 const & interpolant, Int const & sample );
	Vec4 interpolateAtSample( Vec4 const & interpolant, Int const & sample );
	/**@}*/
#pragma endregion
#pragma region interpolateAtOffset
	/**
	*name
	*	interpolateAtOffset
	*/
	/**@{*/
	Float interpolateAtOffset( Float const & interpolant, Vec2 const & offset );
	Vec2 interpolateAtOffset( Vec2 const & interpolant, Vec2 const & offset );
	Vec3 interpolateAtOffset( Vec3 const & interpolant, Vec2 const & offset );
	Vec4 interpolateAtOffset( Vec4 const & interpolant, Vec2 const & offset );
	/**@}*/
#pragma endregion
#pragma region EmitStreamVertex
	/**
	*name
	*	EmitStreamVertex
	*/
	/**@{*/
	Void EmitStreamVertex( Int const & stream );
	/**@}*/
#pragma endregion
#pragma region EndStreamPrimitive
	/**
	*name
	*	EndStreamPrimitive
	*/
	/**@{*/
	Void EndStreamPrimitive( Int const & stream );
	/**@}*/
#pragma endregion
#pragma region EmitVertex
	/**
	*name
	*	EmitVertex
	*/
	/**@{*/
	Void EmitVertex( );
	/**@}*/
#pragma endregion
#pragma region EndPrimitive
	/**
	*name
	*	EndPrimitive
	*/
	/**@{*/
	Void EndPrimitive( );
	/**@}*/
#pragma endregion
#pragma region barrier
	/**
	*name
	*	barrier
	*/
	/**@{*/
	Void barrier( );
	/**@}*/
#pragma endregion
#pragma region memoryBarrier
	/**
	*name
	*	memoryBarrier
	*/
	/**@{*/
	UInt memoryBarrier( );
	/**@}*/
#pragma endregion
#pragma region memoryBarrierBuffer
	/**
	*name
	*	memoryBarrierBuffer
	*/
	/**@{*/
	Void memoryBarrierBuffer( );
	/**@}*/
#pragma endregion
#pragma region memoryBarrierShared
	/**
	*name
	*	memoryBarrierShared
	*/
	/**@{*/
	Void memoryBarrierShared( );
	/**@}*/
#pragma endregion
#pragma region memoryBarrierImage
	/**
	*name
	*	memoryBarrierImage
	*/
	/**@{*/
	Void memoryBarrierImage( );
	/**@}*/
#pragma endregion
#pragma region groupMemoryBarrier
	/**
	*name
	*	groupMemoryBarrier
	*/
	/**@{*/
	Void groupMemoryBarrier( );
	/**@}*/
#pragma endregion
}

#endif
