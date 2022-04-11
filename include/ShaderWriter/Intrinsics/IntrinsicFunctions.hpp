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
#include "ShaderWriter/BaseTypes/TaskPayload.hpp"
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
	SDW_API ReturnWrapperT< Float > degrees( Float const & radians );
	SDW_API ReturnWrapperT< Vec2 > degrees( Vec2 const & radians );
	SDW_API ReturnWrapperT< Vec3 > degrees( Vec3 const & radians );
	SDW_API ReturnWrapperT< Vec4 > degrees( Vec4 const & radians );
	/**@}*/
#pragma endregion
#pragma region radians
	/**
	*name
	*	radians
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > radians( Float const & degrees );
	SDW_API ReturnWrapperT< Vec2 > radians( Vec2 const & degrees );
	SDW_API ReturnWrapperT< Vec3 > radians( Vec3 const & degrees );
	SDW_API ReturnWrapperT< Vec4 > radians( Vec4 const & degrees );
	/**@}*/
#pragma endregion
#pragma region cos
	/**
	*name
	*	cos
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > cos( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > cos( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > cos( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > cos( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region sin
	/**
	*name
	*	sin
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > sin( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > sin( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > sin( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > sin( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region tan
	/**
	*name
	*	tan
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > tan( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > tan( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > tan( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > tan( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region cosh
	/**
	*name
	*	cosh
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > cosh( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > cosh( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > cosh( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > cosh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region sinh
	/**
	*name
	*	sinh
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > sinh( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > sinh( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > sinh( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > sinh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region tanh
	/**
	*name
	*	tanh
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > tanh( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > tanh( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > tanh( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > tanh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region acos
	/**
	*name
	*	acos
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > acos( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > acos( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > acos( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > acos( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region asin
	/**
	*name
	*	asin
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > asin( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > asin( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > asin( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > asin( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region atan
	/**
	*name
	*	atan
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > atan( Float const & y_over_x );
	SDW_API ReturnWrapperT< Vec2 > atan( Vec2 const & y_over_x );
	SDW_API ReturnWrapperT< Vec3 > atan( Vec3 const & y_over_x );
	SDW_API ReturnWrapperT< Vec4 > atan( Vec4 const & y_over_x );
	/**@}*/
#pragma endregion
#pragma region atan2
	/**
	*name
	*	atan2
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > atan2( Float const & y, Float const & x );
	SDW_API ReturnWrapperT< Vec2 > atan2( Vec2 const & y, Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > atan2( Vec3 const & y, Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > atan2( Vec4 const & y, Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region acosh
	/**
	*name
	*	acosh
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > acosh( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > acosh( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > acosh( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > acosh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region asinh
	/**
	*name
	*	asinh
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > asinh( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > asinh( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > asinh( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > asinh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region atanh
	/**
	*name
	*	atanh
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > atanh( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > atanh( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > atanh( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > atanh( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region pow
	/**
	*name
	*	pow
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > pow( Float const & x, Float const & y );
	SDW_API ReturnWrapperT< Vec2 > pow( Vec2 const & x, Vec2 const & y );
	SDW_API ReturnWrapperT< Vec3 > pow( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< Vec4 > pow( Vec4 const & x, Vec4 const & y );
	/**@}*/
#pragma endregion
#pragma region exp
	/**
	*name
	*	exp
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > exp( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > exp( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > exp( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > exp( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region log
	/**
	*name
	*	log
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > log( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > log( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > log( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > log( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region exp2
	/**
	*name
	*	exp2
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > exp2( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > exp2( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > exp2( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > exp2( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region log2
	/**
	*name
	*	log2
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > log2( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > log2( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > log2( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > log2( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region sqrt
	/**
	*name
	*	sqrt
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > sqrt( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > sqrt( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > sqrt( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > sqrt( Vec4 const & x );
	SDW_API ReturnWrapperT< Double > sqrt( Double const & x );
	SDW_API ReturnWrapperT< DVec2 > sqrt( DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > sqrt( DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > sqrt( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region inverseSqrt
	/**
	*name
	*	inverseSqrt
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > inverseSqrt( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > inverseSqrt( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > inverseSqrt( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > inverseSqrt( Vec4 const & x );
	SDW_API ReturnWrapperT< Double > inverseSqrt( Double const & x );
	SDW_API ReturnWrapperT< DVec2 > inverseSqrt( DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > inverseSqrt( DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > inverseSqrt( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region abs
	/**
	*name
	*	abs
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > abs( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > abs( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > abs( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > abs( Vec4 const & x );
	SDW_API ReturnWrapperT< Int > abs( Int const & x );
	SDW_API ReturnWrapperT< IVec2 > abs( IVec2 const & x );
	SDW_API ReturnWrapperT< IVec3 > abs( IVec3 const & x );
	SDW_API ReturnWrapperT< IVec4 > abs( IVec4 const & x );
	SDW_API ReturnWrapperT< Double > abs( Double const & x );
	SDW_API ReturnWrapperT< DVec2 > abs( DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > abs( DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > abs( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region sign
	/**
	*name
	*	sign
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > sign( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > sign( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > sign( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > sign( Vec4 const & x );
	SDW_API ReturnWrapperT< Int > sign( Int const & x );
	SDW_API ReturnWrapperT< IVec2 > sign( IVec2 const & x );
	SDW_API ReturnWrapperT< IVec3 > sign( IVec3 const & x );
	SDW_API ReturnWrapperT< IVec4 > sign( IVec4 const & x );
	SDW_API ReturnWrapperT< Double > sign( Double const & x );
	SDW_API ReturnWrapperT< DVec2 > sign( DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > sign( DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > sign( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region floor
	/**
	*name
	*	floor
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > floor( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > floor( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > floor( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > floor( Vec4 const & x );
	SDW_API ReturnWrapperT< Double > floor( Double const & x );
	SDW_API ReturnWrapperT< DVec2 > floor( DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > floor( DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > floor( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region trunc
	/**
	*name
	*	trunc
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > trunc( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > trunc( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > trunc( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > trunc( Vec4 const & x );
	SDW_API ReturnWrapperT< Double > trunc( Double const & x );
	SDW_API ReturnWrapperT< DVec2 > trunc( DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > trunc( DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > trunc( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region round
	/**
	*name
	*	round
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > round( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > round( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > round( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > round( Vec4 const & x );
	SDW_API ReturnWrapperT< Double > round( Double const & x );
	SDW_API ReturnWrapperT< DVec2 > round( DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > round( DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > round( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region roundEven
	/**
	*name
	*	roundEven
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > roundEven( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > roundEven( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > roundEven( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > roundEven( Vec4 const & x );
	SDW_API ReturnWrapperT< Double > roundEven( Double const & x );
	SDW_API ReturnWrapperT< DVec2 > roundEven( DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > roundEven( DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > roundEven( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region ceil
	/**
	*name
	*	ceil
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > ceil( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > ceil( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > ceil( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > ceil( Vec4 const & x );
	SDW_API ReturnWrapperT< Double > ceil( Double const & x );
	SDW_API ReturnWrapperT< DVec2 > ceil( DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > ceil( DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > ceil( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region fract
	/**
	*name
	*	fract
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > fract( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > fract( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > fract( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > fract( Vec4 const & x );
	SDW_API ReturnWrapperT< Double > fract( Double const & x );
	SDW_API ReturnWrapperT< DVec2 > fract( DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > fract( DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > fract( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region mod
	/**
	*name
	*	mod
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > mod( Float const & x, Float const & y );
	SDW_API ReturnWrapperT< Vec2 > mod( Vec2 const & x, Vec2 const & y );
	SDW_API ReturnWrapperT< Vec3 > mod( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< Vec4 > mod( Vec4 const & x, Vec4 const & y );
	SDW_API ReturnWrapperT< Double > mod( Double const & x, Double const & y );
	SDW_API ReturnWrapperT< DVec2 > mod( DVec2 const & x, DVec2 const & y );
	SDW_API ReturnWrapperT< DVec3 > mod( DVec3 const & x, DVec3 const & y );
	SDW_API ReturnWrapperT< DVec4 > mod( DVec4 const & x, DVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region modf
	/**
	*name
	*	modf
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > modf( Float const & x, Float const & i );
	SDW_API ReturnWrapperT< Vec2 > modf( Vec2 const & x, Vec2 const & i );
	SDW_API ReturnWrapperT< Vec3 > modf( Vec3 const & x, Vec3 const & i );
	SDW_API ReturnWrapperT< Vec4 > modf( Vec4 const & x, Vec4 const & i );
	SDW_API ReturnWrapperT< Double > modf( Double const & x, Double const & i );
	SDW_API ReturnWrapperT< DVec2 > modf( DVec2 const & x, DVec2 const & i );
	SDW_API ReturnWrapperT< DVec3 > modf( DVec3 const & x, DVec3 const & i );
	SDW_API ReturnWrapperT< DVec4 > modf( DVec4 const & x, DVec4 const & i );
	/**@}*/
#pragma endregion
#pragma region min
	/**
	*name
	*	min
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > min( Float const & x, Float const & y );
	SDW_API ReturnWrapperT< Vec2 > min( Vec2 const & x, Vec2 const & y );
	SDW_API ReturnWrapperT< Vec3 > min( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< Vec4 > min( Vec4 const & x, Vec4 const & y );
	SDW_API ReturnWrapperT< Double > min( Double const & x, Double const & y );
	SDW_API ReturnWrapperT< DVec2 > min( DVec2 const & x, DVec2 const & y );
	SDW_API ReturnWrapperT< DVec3 > min( DVec3 const & x, DVec3 const & y );
	SDW_API ReturnWrapperT< DVec4 > min( DVec4 const & x, DVec4 const & y );
	SDW_API ReturnWrapperT< Int > min( Int const & x, Int const & y );
	SDW_API ReturnWrapperT< IVec2 > min( IVec2 const & x, IVec2 const & y );
	SDW_API ReturnWrapperT< IVec3 > min( IVec3 const & x, IVec3 const & y );
	SDW_API ReturnWrapperT< IVec4 > min( IVec4 const & x, IVec4 const & y );
	SDW_API ReturnWrapperT< UInt > min( UInt const & x, UInt const & y );
	SDW_API ReturnWrapperT< UVec2 > min( UVec2 const & x, UVec2 const & y );
	SDW_API ReturnWrapperT< UVec3 > min( UVec3 const & x, UVec3 const & y );
	SDW_API ReturnWrapperT< UVec4 > min( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region max
	/**
	*name
	*	max
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > max( Float const & x, Float const & y );
	SDW_API ReturnWrapperT< Vec2 > max( Vec2 const & x, Vec2 const & y );
	SDW_API ReturnWrapperT< Vec3 > max( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< Vec4 > max( Vec4 const & x, Vec4 const & y );
	SDW_API ReturnWrapperT< Double > max( Double const & x, Double const & y );
	SDW_API ReturnWrapperT< DVec2 > max( DVec2 const & x, DVec2 const & y );
	SDW_API ReturnWrapperT< DVec3 > max( DVec3 const & x, DVec3 const & y );
	SDW_API ReturnWrapperT< DVec4 > max( DVec4 const & x, DVec4 const & y );
	SDW_API ReturnWrapperT< Int > max( Int const & x, Int const & y );
	SDW_API ReturnWrapperT< IVec2 > max( IVec2 const & x, IVec2 const & y );
	SDW_API ReturnWrapperT< IVec3 > max( IVec3 const & x, IVec3 const & y );
	SDW_API ReturnWrapperT< IVec4 > max( IVec4 const & x, IVec4 const & y );
	SDW_API ReturnWrapperT< UInt > max( UInt const & x, UInt const & y );
	SDW_API ReturnWrapperT< UVec2 > max( UVec2 const & x, UVec2 const & y );
	SDW_API ReturnWrapperT< UVec3 > max( UVec3 const & x, UVec3 const & y );
	SDW_API ReturnWrapperT< UVec4 > max( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region clamp
	/**
	*name
	*	clamp
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > clamp( Float const & x, Float const & minVal, Float const & maxVal );
	SDW_API ReturnWrapperT< Vec2 > clamp( Vec2 const & x, Vec2 const & minVal, Vec2 const & maxVal );
	SDW_API ReturnWrapperT< Vec3 > clamp( Vec3 const & x, Vec3 const & minVal, Vec3 const & maxVal );
	SDW_API ReturnWrapperT< Vec4 > clamp( Vec4 const & x, Vec4 const & minVal, Vec4 const & maxVal );
	SDW_API ReturnWrapperT< Double > clamp( Double const & x, Double const & minVal, Double const & maxVal );
	SDW_API ReturnWrapperT< DVec2 > clamp( DVec2 const & x, DVec2 const & minVal, DVec2 const & maxVal );
	SDW_API ReturnWrapperT< DVec3 > clamp( DVec3 const & x, DVec3 const & minVal, DVec3 const & maxVal );
	SDW_API ReturnWrapperT< DVec4 > clamp( DVec4 const & x, DVec4 const & minVal, DVec4 const & maxVal );
	SDW_API ReturnWrapperT< Int > clamp( Int const & x, Int const & minVal, Int const & maxVal );
	SDW_API ReturnWrapperT< IVec2 > clamp( IVec2 const & x, IVec2 const & minVal, IVec2 const & maxVal );
	SDW_API ReturnWrapperT< IVec3 > clamp( IVec3 const & x, IVec3 const & minVal, IVec3 const & maxVal );
	SDW_API ReturnWrapperT< IVec4 > clamp( IVec4 const & x, IVec4 const & minVal, IVec4 const & maxVal );
	SDW_API ReturnWrapperT< UInt > clamp( UInt const & x, UInt const & minVal, UInt const & maxVal );
	SDW_API ReturnWrapperT< UVec2 > clamp( UVec2 const & x, UVec2 const & minVal, UVec2 const & maxVal );
	SDW_API ReturnWrapperT< UVec3 > clamp( UVec3 const & x, UVec3 const & minVal, UVec3 const & maxVal );
	SDW_API ReturnWrapperT< UVec4 > clamp( UVec4 const & x, UVec4 const & minVal, UVec4 const & maxVal );
	/**@}*/
#pragma endregion
#pragma region mix
	/**
	*name
	*	mix
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > mix( Float const & x, Float const & y, Float const & a );
	SDW_API ReturnWrapperT< Vec2 > mix( Vec2 const & x, Vec2 const & y, Vec2 const & a );
	SDW_API ReturnWrapperT< Vec3 > mix( Vec3 const & x, Vec3 const & y, Vec3 const & a );
	SDW_API ReturnWrapperT< Vec4 > mix( Vec4 const & x, Vec4 const & y, Vec4 const & a );
	SDW_API ReturnWrapperT< Double > mix( Double const & x, Double const & y, Double const & a );
	SDW_API ReturnWrapperT< DVec2 > mix( DVec2 const & x, DVec2 const & y, DVec2 const & a );
	SDW_API ReturnWrapperT< DVec3 > mix( DVec3 const & x, DVec3 const & y, DVec3 const & a );
	SDW_API ReturnWrapperT< DVec4 > mix( DVec4 const & x, DVec4 const & y, DVec4 const & a );
	/**@}*/
#pragma endregion
#pragma region step
	/**
	*name
	*	step
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > step( Float const & edge, Float const & x );
	SDW_API ReturnWrapperT< Vec2 > step( Vec2 const & edge, Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > step( Vec3 const & edge, Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > step( Vec4 const & edge, Vec4 const & x );
	SDW_API ReturnWrapperT< Double > step( Double const & edge, Double const & x );
	SDW_API ReturnWrapperT< DVec2 > step( DVec2 const & edge, DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > step( DVec3 const & edge, DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > step( DVec4 const & edge, DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region smoothStep
	/**
	*name
	*	smoothStep
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > smoothStep( Float const & edge0, Float const & edge1, Float const & x );
	SDW_API ReturnWrapperT< Vec2 > smoothStep( Vec2 const & edge0, Vec2 const & edge1, Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > smoothStep( Vec3 const & edge0, Vec3 const & edge1, Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > smoothStep( Vec4 const & edge0, Vec4 const & edge1, Vec4 const & x );
	SDW_API ReturnWrapperT< Double > smoothStep( Double const & edge0, Double const & edge1, Double const & x );
	SDW_API ReturnWrapperT< DVec2 > smoothStep( DVec2 const & edge0, DVec2 const & edge1, DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > smoothStep( DVec3 const & edge0, DVec3 const & edge1, DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > smoothStep( DVec4 const & edge0, DVec4 const & edge1, DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region isnan
	/**
	*name
	*	isnan
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Boolean > isnan( Float const & x );
	SDW_API ReturnWrapperT< BVec2 > isnan( Vec2 const & x );
	SDW_API ReturnWrapperT< BVec3 > isnan( Vec3 const & x );
	SDW_API ReturnWrapperT< BVec4 > isnan( Vec4 const & x );
	SDW_API ReturnWrapperT< Boolean > isnan( Double const & x );
	SDW_API ReturnWrapperT< BVec2 > isnan( DVec2 const & x );
	SDW_API ReturnWrapperT< BVec3 > isnan( DVec3 const & x );
	SDW_API ReturnWrapperT< BVec4 > isnan( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region isinf
	/**
	*name
	*	isinf
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Boolean > isinf( Float const & x );
	SDW_API ReturnWrapperT< BVec2 > isinf( Vec2 const & x );
	SDW_API ReturnWrapperT< BVec3 > isinf( Vec3 const & x );
	SDW_API ReturnWrapperT< BVec4 > isinf( Vec4 const & x );
	SDW_API ReturnWrapperT< Boolean > isinf( Double const & x );
	SDW_API ReturnWrapperT< BVec2 > isinf( DVec2 const & x );
	SDW_API ReturnWrapperT< BVec3 > isinf( DVec3 const & x );
	SDW_API ReturnWrapperT< BVec4 > isinf( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region floatBitsToInt
	/**
	*name
	*	floatBitsToInt
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > floatBitsToInt( Float const & value );
	SDW_API ReturnWrapperT< IVec2 > floatBitsToInt( Vec2 const & value );
	SDW_API ReturnWrapperT< IVec3 > floatBitsToInt( Vec3 const & value );
	SDW_API ReturnWrapperT< IVec4 > floatBitsToInt( Vec4 const & value );
	/**@}*/
#pragma endregion
#pragma region floatBitsToUInt
	/**
	*name
	*	floatBitsToUInt
	*/
	/**@{*/
	SDW_API ReturnWrapperT< UInt > floatBitsToUInt( Float const & value );
	SDW_API ReturnWrapperT< UVec2 > floatBitsToUInt( Vec2 const & value );
	SDW_API ReturnWrapperT< UVec3 > floatBitsToUInt( Vec3 const & value );
	SDW_API ReturnWrapperT< UVec4 > floatBitsToUInt( Vec4 const & value );
	/**@}*/
#pragma endregion
#pragma region intBitsToFloat
	/**
	*name
	*	intBitsToFloat
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > intBitsToFloat( Int const & x );
	SDW_API ReturnWrapperT< Vec2 > intBitsToFloat( IVec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > intBitsToFloat( IVec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > intBitsToFloat( IVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region uintBitsToFloat
	/**
	*name
	*	uintBitsToFloat
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > uintBitsToFloat( UInt const & x );
	SDW_API ReturnWrapperT< Vec2 > uintBitsToFloat( UVec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > uintBitsToFloat( UVec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > uintBitsToFloat( UVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region fma
	/**
	*name
	*	fma
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > fma( Float const & a, Float const & b, Float const & c );
	SDW_API ReturnWrapperT< Vec2 > fma( Vec2 const & a, Vec2 const & b, Vec2 const & c );
	SDW_API ReturnWrapperT< Vec3 > fma( Vec3 const & a, Vec3 const & b, Vec3 const & c );
	SDW_API ReturnWrapperT< Vec4 > fma( Vec4 const & a, Vec4 const & b, Vec4 const & c );
	SDW_API ReturnWrapperT< Double > fma( Double const & a, Double const & b, Double const & c );
	SDW_API ReturnWrapperT< DVec2 > fma( DVec2 const & a, DVec2 const & b, DVec2 const & c );
	SDW_API ReturnWrapperT< DVec3 > fma( DVec3 const & a, DVec3 const & b, DVec3 const & c );
	SDW_API ReturnWrapperT< DVec4 > fma( DVec4 const & a, DVec4 const & b, DVec4 const & c );
	/**@}*/
#pragma endregion
#pragma region frexp
	/**
	*name
	*	frexp
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > frexp( Float const & x, Int & exp );
	SDW_API ReturnWrapperT< Vec2 > frexp( Vec2 const & x, IVec2 & exp );
	SDW_API ReturnWrapperT< Vec3 > frexp( Vec3 const & x, IVec3 & exp );
	SDW_API ReturnWrapperT< Vec4 > frexp( Vec4 const & x, IVec4 & exp );
	SDW_API ReturnWrapperT< Double > frexp( Double const & x, Int & exp );
	SDW_API ReturnWrapperT< DVec2 > frexp( DVec2 const & x, IVec2 & exp );
	SDW_API ReturnWrapperT< DVec3 > frexp( DVec3 const & x, IVec3 & exp );
	SDW_API ReturnWrapperT< DVec4 > frexp( DVec4 const & x, IVec4 & exp );
	/**@}*/
#pragma endregion
#pragma region ldexp
	/**
	*name
	*	ldexp
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > ldexp( Float const & x, Int const & exp );
	SDW_API ReturnWrapperT< Vec2 > ldexp( Vec2 const & x, IVec2 const & exp );
	SDW_API ReturnWrapperT< Vec3 > ldexp( Vec3 const & x, IVec3 const & exp );
	SDW_API ReturnWrapperT< Vec4 > ldexp( Vec4 const & x, IVec4 const & exp );
	SDW_API ReturnWrapperT< Double > ldexp( Double const & x, Int const & exp );
	SDW_API ReturnWrapperT< DVec2 > ldexp( DVec2 const & x, IVec2 const & exp );
	SDW_API ReturnWrapperT< DVec3 > ldexp( DVec3 const & x, IVec3 const & exp );
	SDW_API ReturnWrapperT< DVec4 > ldexp( DVec4 const & x, IVec4 const & exp );
	/**@}*/
#pragma endregion
#pragma region packDouble2x32
	/**
	*name
	*	packDouble2x32
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Double > packDouble2x32( UVec2 const & v );
	/**@}*/
#pragma endregion
#pragma region packHalf2x16
	/**
	*name
	*	packHalf2x16
	*/
	/**@{*/
	SDW_API ReturnWrapperT< UInt > packHalf2x16( Vec2 const & v );
	/**@}*/
#pragma endregion
#pragma region packSnorm2x16
	/**
	*name
	*	packSnorm2x16
	*/
	/**@{*/
	SDW_API ReturnWrapperT< UInt > packSnorm2x16( Vec2 const & v );
	/**@}*/
#pragma endregion
#pragma region packSnorm4x8
	/**
	*name
	*	packSnorm4x8
	*/
	/**@{*/
	SDW_API ReturnWrapperT< UInt > packSnorm4x8( Vec4 const & v );
	/**@}*/
#pragma endregion
#pragma region packUnorm2x16
	/**
	*name
	*	packUnorm2x16
	*/
	/**@{*/
	SDW_API ReturnWrapperT< UInt > packUnorm2x16( Vec2 const & v );
	/**@}*/
#pragma endregion
#pragma region packUnorm4x8
	/**
	*name
	*	packUnorm4x8
	*/
	/**@{*/
	SDW_API ReturnWrapperT< UInt > packUnorm4x8( Vec4 const & v );
	/**@}*/
#pragma endregion
#pragma region unpackDouble2x32
	/**
	*name
	*	unpackDouble2x32
	*/
	/**@{*/
	SDW_API ReturnWrapperT< UVec2 > unpackDouble2x32( Double const & d );
	/**@}*/
#pragma endregion
#pragma region unpackHalf2x16
	/**
	*name
	*	unpackHalf2x16
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Vec2 > unpackHalf2x16( UInt const & v );
	/**@}*/
#pragma endregion
#pragma region unpackSnorm2x16
	/**
	*name
	*	unpackSnorm2x16
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Vec2 > unpackSnorm2x16( UInt const & p );
	/**@}*/
#pragma endregion
#pragma region unpackSnorm4x8
	/**
	*name
	*	unpackSnorm4x8
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Vec4 > unpackSnorm4x8( UInt const & p );
	/**@}*/
#pragma endregion
#pragma region unpackUnorm2x16
	/**
	*name
	*	unpackUnorm2x16
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Vec2 > unpackUnorm2x16( UInt const & p );
	/**@}*/
#pragma endregion
#pragma region unpackUnorm4x8
	/**
	*name
	*	unpackUnorm4x8
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Vec4 > unpackUnorm4x8( UInt const & p );
	/**@}*/
#pragma endregion
#pragma region length
	/**
	*name
	*	length
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > length( Float const & x );
	SDW_API ReturnWrapperT< Float > length( Vec2 const & x );
	SDW_API ReturnWrapperT< Float > length( Vec3 const & x );
	SDW_API ReturnWrapperT< Float > length( Vec4 const & x );
	SDW_API ReturnWrapperT< Double > length( Double const & x );
	SDW_API ReturnWrapperT< Double > length( DVec2 const & x );
	SDW_API ReturnWrapperT< Double > length( DVec3 const & x );
	SDW_API ReturnWrapperT< Double > length( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region distance
	/**
	*name
	*	distance
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > distance( Float const & p0, Float const & p1 );
	SDW_API ReturnWrapperT< Float > distance( Vec2 const & p0, Vec2 const & p1 );
	SDW_API ReturnWrapperT< Float > distance( Vec3 const & p0, Vec3 const & p1 );
	SDW_API ReturnWrapperT< Float > distance( Vec4 const & p0, Vec4 const & p1 );
	SDW_API ReturnWrapperT< Double > distance( Double const & p0, Double const & p1 );
	SDW_API ReturnWrapperT< Double > distance( DVec2 const & p0, DVec2 const & p1 );
	SDW_API ReturnWrapperT< Double > distance( DVec3 const & p0, DVec3 const & p1 );
	SDW_API ReturnWrapperT< Double > distance( DVec4 const & p0, DVec4 const & p1 );
	/**@}*/
#pragma endregion
#pragma region dot
	/**
	*name
	*	dot
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > dot( Float const & x, Float const & y );
	SDW_API ReturnWrapperT< Float > dot( Vec2 const & x, Vec2 const & y );
	SDW_API ReturnWrapperT< Float > dot( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< Float > dot( Vec4 const & x, Vec4 const & y );
	SDW_API ReturnWrapperT< Double > dot( Double const & x, Double const & y );
	SDW_API ReturnWrapperT< Double > dot( DVec2 const & x, DVec2 const & y );
	SDW_API ReturnWrapperT< Double > dot( DVec3 const & x, DVec3 const & y );
	SDW_API ReturnWrapperT< Double > dot( DVec4 const & x, DVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region cross
	/**
	*name
	*	cross
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Vec3 > cross( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< DVec3 > cross( DVec3 const & x, DVec3 const & y );
	/**@}*/
#pragma endregion
#pragma region normalize
	/**
	*name
	*	normalize
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > normalize( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > normalize( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > normalize( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > normalize( Vec4 const & x );
	SDW_API ReturnWrapperT< Double > normalize( Double const & x );
	SDW_API ReturnWrapperT< DVec2 > normalize( DVec2 const & x );
	SDW_API ReturnWrapperT< DVec3 > normalize( DVec3 const & x );
	SDW_API ReturnWrapperT< DVec4 > normalize( DVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region faceForward
	/**
	*name
	*	faceForward
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > faceForward( Float const & N, Float const & I, Float const & Nref );
	SDW_API ReturnWrapperT< Vec2 > faceForward( Vec2 const & N, Vec2 const & I, Vec2 const & Nref );
	SDW_API ReturnWrapperT< Vec3 > faceForward( Vec3 const & N, Vec3 const & I, Vec3 const & Nref );
	SDW_API ReturnWrapperT< Vec4 > faceForward( Vec4 const & N, Vec4 const & I, Vec4 const & Nref );
	SDW_API ReturnWrapperT< Double > faceForward( Double const & N, Double const & I, Double const & Nref );
	SDW_API ReturnWrapperT< DVec2 > faceForward( DVec2 const & N, DVec2 const & I, DVec2 const & Nref );
	SDW_API ReturnWrapperT< DVec3 > faceForward( DVec3 const & N, DVec3 const & I, DVec3 const & Nref );
	SDW_API ReturnWrapperT< DVec4 > faceForward( DVec4 const & N, DVec4 const & I, DVec4 const & Nref );
	/**@}*/
#pragma endregion
#pragma region reflect
	/**
	*name
	*	reflect
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > reflect( Float const & I, Float const & N );
	SDW_API ReturnWrapperT< Vec2 > reflect( Vec2 const & I, Vec2 const & N );
	SDW_API ReturnWrapperT< Vec3 > reflect( Vec3 const & I, Vec3 const & N );
	SDW_API ReturnWrapperT< Vec4 > reflect( Vec4 const & I, Vec4 const & N );
	SDW_API ReturnWrapperT< Double > reflect( Double const & I, Double const & N );
	SDW_API ReturnWrapperT< DVec2 > reflect( DVec2 const & I, DVec2 const & N );
	SDW_API ReturnWrapperT< DVec3 > reflect( DVec3 const & I, DVec3 const & N );
	SDW_API ReturnWrapperT< DVec4 > reflect( DVec4 const & I, DVec4 const & N );
	/**@}*/
#pragma endregion
#pragma region refract
	/**
	*name
	*	refract
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > refract( Float const & I, Float const & N, Float const & eta );
	SDW_API ReturnWrapperT< Vec2 > refract( Vec2 const & I, Vec2 const & N, Float const & eta );
	SDW_API ReturnWrapperT< Vec3 > refract( Vec3 const & I, Vec3 const & N, Float const & eta );
	SDW_API ReturnWrapperT< Vec4 > refract( Vec4 const & I, Vec4 const & N, Float const & eta );
	SDW_API ReturnWrapperT< Double > refract( Double const & I, Double const & N, Float const & eta );
	SDW_API ReturnWrapperT< DVec2 > refract( DVec2 const & I, DVec2 const & N, Float const & eta );
	SDW_API ReturnWrapperT< DVec3 > refract( DVec3 const & I, DVec3 const & N, Float const & eta );
	SDW_API ReturnWrapperT< DVec4 > refract( DVec4 const & I, DVec4 const & N, Float const & eta );
	/**@}*/
#pragma endregion
#pragma region matrixCompMult
	/**
	*name
	*	matrixCompMult
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Mat2 > matrixCompMult( Mat2 const & x, Mat2 const & y );
	SDW_API ReturnWrapperT< Mat2x3 > matrixCompMult( Mat2x3 const & x, Mat2x3 const & y );
	SDW_API ReturnWrapperT< Mat2x4 > matrixCompMult( Mat2x4 const & x, Mat2x4 const & y );
	SDW_API ReturnWrapperT< Mat3x2 > matrixCompMult( Mat3x2 const & x, Mat3x2 const & y );
	SDW_API ReturnWrapperT< Mat3 > matrixCompMult( Mat3 const & x, Mat3 const & y );
	SDW_API ReturnWrapperT< Mat3x4 > matrixCompMult( Mat3x4 const & x, Mat3x4 const & y );
	SDW_API ReturnWrapperT< Mat4x2 > matrixCompMult( Mat4x2 const & x, Mat4x2 const & y );
	SDW_API ReturnWrapperT< Mat4x3 > matrixCompMult( Mat4x3 const & x, Mat4x3 const & y );
	SDW_API ReturnWrapperT< Mat4 > matrixCompMult( Mat4 const & x, Mat4 const & y );
	SDW_API ReturnWrapperT< DMat2 > matrixCompMult( DMat2 const & x, DMat2 const & y );
	SDW_API ReturnWrapperT< DMat2x3 > matrixCompMult( DMat2x3 const & x, DMat2x3 const & y );
	SDW_API ReturnWrapperT< DMat2x4 > matrixCompMult( DMat2x4 const & x, DMat2x4 const & y );
	SDW_API ReturnWrapperT< DMat3x2 > matrixCompMult( DMat3x2 const & x, DMat3x2 const & y );
	SDW_API ReturnWrapperT< DMat3 > matrixCompMult( DMat3 const & x, DMat3 const & y );
	SDW_API ReturnWrapperT< DMat3x4 > matrixCompMult( DMat3x4 const & x, DMat3x4 const & y );
	SDW_API ReturnWrapperT< DMat4x2 > matrixCompMult( DMat4x2 const & x, DMat4x2 const & y );
	SDW_API ReturnWrapperT< DMat4x3 > matrixCompMult( DMat4x3 const & x, DMat4x3 const & y );
	SDW_API ReturnWrapperT< DMat4 > matrixCompMult( DMat4 const & x, DMat4 const & y );
	/**@}*/
#pragma endregion
#pragma region outerProduct
	/**
	*name
	*	outerProduct
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Mat2 > outerProduct( Vec2 const & c, Vec2 const & r );
	SDW_API ReturnWrapperT< Mat3 > outerProduct( Vec3 const & c, Vec3 const & r );
	SDW_API ReturnWrapperT< Mat4 > outerProduct( Vec4 const & c, Vec4 const & r );
	SDW_API ReturnWrapperT< Mat2x3 > outerProduct( Vec3 const & c, Vec2 const & r );
	SDW_API ReturnWrapperT< Mat3x2 > outerProduct( Vec2 const & c, Vec3 const & r );
	SDW_API ReturnWrapperT< Mat2x4 > outerProduct( Vec4 const & c, Vec2 const & r );
	SDW_API ReturnWrapperT< Mat4x2 > outerProduct( Vec2 const & c, Vec4 const & r );
	SDW_API ReturnWrapperT< Mat3x4 > outerProduct( Vec4 const & c, Vec3 const & r );
	SDW_API ReturnWrapperT< Mat4x3 > outerProduct( Vec3 const & c, Vec4 const & r );
	SDW_API ReturnWrapperT< DMat2 > outerProduct( DVec2 const & c, DVec2 const & r );
	SDW_API ReturnWrapperT< DMat3 > outerProduct( DVec3 const & c, DVec3 const & r );
	SDW_API ReturnWrapperT< DMat4 > outerProduct( DVec4 const & c, DVec4 const & r );
	SDW_API ReturnWrapperT< DMat2x3 > outerProduct( DVec3 const & c, DVec2 const & r );
	SDW_API ReturnWrapperT< DMat3x2 > outerProduct( DVec2 const & c, DVec3 const & r );
	SDW_API ReturnWrapperT< DMat2x4 > outerProduct( DVec4 const & c, DVec2 const & r );
	SDW_API ReturnWrapperT< DMat4x2 > outerProduct( DVec2 const & c, DVec4 const & r );
	SDW_API ReturnWrapperT< DMat3x4 > outerProduct( DVec4 const & c, DVec3 const & r );
	SDW_API ReturnWrapperT< DMat4x3 > outerProduct( DVec3 const & c, DVec4 const & r );
	/**@}*/
#pragma endregion
#pragma region transpose
	/**
	*name
	*	transpose
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Mat2 > transpose( Mat2 const & x );
	SDW_API ReturnWrapperT< Mat3x2 > transpose( Mat2x3 const & x );
	SDW_API ReturnWrapperT< Mat4x2 > transpose( Mat2x4 const & x );
	SDW_API ReturnWrapperT< Mat2x3 > transpose( Mat3x2 const & x );
	SDW_API ReturnWrapperT< Mat3 > transpose( Mat3 const & x );
	SDW_API ReturnWrapperT< Mat4x3 > transpose( Mat3x4 const & x );
	SDW_API ReturnWrapperT< Mat2x4 > transpose( Mat4x2 const & x );
	SDW_API ReturnWrapperT< Mat3x4 > transpose( Mat4x3 const & x );
	SDW_API ReturnWrapperT< Mat4 > transpose( Mat4 const & x );
	SDW_API ReturnWrapperT< DMat2 > transpose( DMat2 const & x );
	SDW_API ReturnWrapperT< DMat3x2 > transpose( DMat2x3 const & x );
	SDW_API ReturnWrapperT< DMat4x2 > transpose( DMat2x4 const & x );
	SDW_API ReturnWrapperT< DMat2x3 > transpose( DMat3x2 const & x );
	SDW_API ReturnWrapperT< DMat3 > transpose( DMat3 const & x );
	SDW_API ReturnWrapperT< DMat4x3 > transpose( DMat3x4 const & x );
	SDW_API ReturnWrapperT< DMat2x4 > transpose( DMat4x2 const & x );
	SDW_API ReturnWrapperT< DMat3x4 > transpose( DMat4x3 const & x );
	SDW_API ReturnWrapperT< DMat4 > transpose( DMat4 const & x );
	/**@}*/
#pragma endregion
#pragma region determinant
	/**
	*name
	*	determinant
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > determinant( Mat2 const & m );
	SDW_API ReturnWrapperT< Float > determinant( Mat3 const & m );
	SDW_API ReturnWrapperT< Float > determinant( Mat4 const & m );
	SDW_API ReturnWrapperT< Double > determinant( DMat2 const & m );
	SDW_API ReturnWrapperT< Double > determinant( DMat3 const & m );
	SDW_API ReturnWrapperT< Double > determinant( DMat4 const & m );
	/**@}*/
#pragma endregion
#pragma region inverse
	/**
	*name
	*	inverse
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Mat2 > inverse( Mat2 const & m );
	SDW_API ReturnWrapperT< Mat3 > inverse( Mat3 const & m );
	SDW_API ReturnWrapperT< Mat4 > inverse( Mat4 const & m );
	SDW_API ReturnWrapperT< DMat2 > inverse( DMat2 const & m );
	SDW_API ReturnWrapperT< DMat3 > inverse( DMat3 const & m );
	SDW_API ReturnWrapperT< DMat4 > inverse( DMat4 const & m );
	/**@}*/
#pragma endregion
#pragma region lessThan
	/**
	*name
	*	lessThan
	*/
	/**@{*/
	SDW_API ReturnWrapperT< BVec2 > lessThan( Vec2 const & x, Vec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > lessThan( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > lessThan( Vec4 const & x, Vec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > lessThan( DVec2 const & x, DVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > lessThan( DVec3 const & x, DVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > lessThan( DVec4 const & x, DVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > lessThan( IVec2 const & x, IVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > lessThan( IVec3 const & x, IVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > lessThan( IVec4 const & x, IVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > lessThan( UVec2 const & x, UVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > lessThan( UVec3 const & x, UVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > lessThan( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region lessThanEqual
	/**
	*name
	*	lessThanEqual
	*/
	/**@{*/
	SDW_API ReturnWrapperT< BVec2 > lessThanEqual( Vec2 const & x, Vec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > lessThanEqual( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > lessThanEqual( Vec4 const & x, Vec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > lessThanEqual( DVec2 const & x, DVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > lessThanEqual( DVec3 const & x, DVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > lessThanEqual( DVec4 const & x, DVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > lessThanEqual( IVec2 const & x, IVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > lessThanEqual( IVec3 const & x, IVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > lessThanEqual( IVec4 const & x, IVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > lessThanEqual( UVec2 const & x, UVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > lessThanEqual( UVec3 const & x, UVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > lessThanEqual( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region greaterThan
	/**
	*name
	*	greaterThan
	*/
	/**@{*/
	SDW_API ReturnWrapperT< BVec2 > greaterThan( Vec2 const & x, Vec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > greaterThan( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > greaterThan( Vec4 const & x, Vec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > greaterThan( DVec2 const & x, DVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > greaterThan( DVec3 const & x, DVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > greaterThan( DVec4 const & x, DVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > greaterThan( IVec2 const & x, IVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > greaterThan( IVec3 const & x, IVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > greaterThan( IVec4 const & x, IVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > greaterThan( UVec2 const & x, UVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > greaterThan( UVec3 const & x, UVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > greaterThan( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region greaterThanEqual
	/**
	*name
	*	greaterThanEqual
	*/
	/**@{*/
	SDW_API ReturnWrapperT< BVec2 > greaterThanEqual( Vec2 const & x, Vec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > greaterThanEqual( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > greaterThanEqual( Vec4 const & x, Vec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > greaterThanEqual( DVec2 const & x, DVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > greaterThanEqual( DVec3 const & x, DVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > greaterThanEqual( DVec4 const & x, DVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > greaterThanEqual( IVec2 const & x, IVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > greaterThanEqual( IVec3 const & x, IVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > greaterThanEqual( IVec4 const & x, IVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > greaterThanEqual( UVec2 const & x, UVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > greaterThanEqual( UVec3 const & x, UVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > greaterThanEqual( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region equal
	/**
	*name
	*	equal
	*/
	/**@{*/
	SDW_API ReturnWrapperT< BVec2 > equal( Vec2 const & x, Vec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > equal( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > equal( Vec4 const & x, Vec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > equal( DVec2 const & x, DVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > equal( DVec3 const & x, DVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > equal( DVec4 const & x, DVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > equal( IVec2 const & x, IVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > equal( IVec3 const & x, IVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > equal( IVec4 const & x, IVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > equal( UVec2 const & x, UVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > equal( UVec3 const & x, UVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > equal( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region notEqual
	/**
	*name
	*	notEqual
	*/
	/**@{*/
	SDW_API ReturnWrapperT< BVec2 > notEqual( Vec2 const & x, Vec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > notEqual( Vec3 const & x, Vec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > notEqual( Vec4 const & x, Vec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > notEqual( DVec2 const & x, DVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > notEqual( DVec3 const & x, DVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > notEqual( DVec4 const & x, DVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > notEqual( IVec2 const & x, IVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > notEqual( IVec3 const & x, IVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > notEqual( IVec4 const & x, IVec4 const & y );
	SDW_API ReturnWrapperT< BVec2 > notEqual( UVec2 const & x, UVec2 const & y );
	SDW_API ReturnWrapperT< BVec3 > notEqual( UVec3 const & x, UVec3 const & y );
	SDW_API ReturnWrapperT< BVec4 > notEqual( UVec4 const & x, UVec4 const & y );
	/**@}*/
#pragma endregion
#pragma region all
	/**
	*name
	*	all
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Boolean > all( BVec2 const & x );
	SDW_API ReturnWrapperT< Boolean > all( BVec3 const & x );
	SDW_API ReturnWrapperT< Boolean > all( BVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region any
	/**
	*name
	*	any
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Boolean > any( BVec2 const & x );
	SDW_API ReturnWrapperT< Boolean > any( BVec3 const & x );
	SDW_API ReturnWrapperT< Boolean > any( BVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region binNot
	/**
	*name
	*	binNot
	*/
	/**@{*/
	SDW_API ReturnWrapperT< BVec2 > binNot( BVec2 const & x );
	SDW_API ReturnWrapperT< BVec3 > binNot( BVec3 const & x );
	SDW_API ReturnWrapperT< BVec4 > binNot( BVec4 const & x );
	/**@}*/
#pragma endregion
#pragma region uaddCarry
	/**
	*name
	*	uaddCarry
	*/
	/**@{*/
	SDW_API ReturnWrapperT< UInt > uaddCarry( UInt const & x, UInt const & y, UInt const & carry );
	SDW_API ReturnWrapperT< UVec2 > uaddCarry( UVec2 const & x, UVec2 const & y, UVec2 const & carry );
	SDW_API ReturnWrapperT< UVec3 > uaddCarry( UVec3 const & x, UVec3 const & y, UVec3 const & carry );
	SDW_API ReturnWrapperT< UVec4 > uaddCarry( UVec4 const & x, UVec4 const & y, UVec4 const & carry );
	/**@}*/
#pragma endregion
#pragma region usubBorrow
	/**
	*name
	*	usubBorrow
	*/
	/**@{*/
	SDW_API ReturnWrapperT< UInt > usubBorrow( UInt const & x, UInt const & y, UInt const & borrow );
	SDW_API ReturnWrapperT< UVec2 > usubBorrow( UVec2 const & x, UVec2 const & y, UVec2 const & borrow );
	SDW_API ReturnWrapperT< UVec3 > usubBorrow( UVec3 const & x, UVec3 const & y, UVec3 const & borrow );
	SDW_API ReturnWrapperT< UVec4 > usubBorrow( UVec4 const & x, UVec4 const & y, UVec4 const & borrow );
	/**@}*/
#pragma endregion
#pragma region umulExtended
	/**
	*name
	*	umulExtended
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > umulExtended( UInt const & x, UInt const & y, UInt const & msb, UInt const & lsb );
	SDW_API ReturnWrapperT< Void > umulExtended( UVec2 const & x, UVec2 const & y, UVec2 const & msb, UVec2 const & lsb );
	SDW_API ReturnWrapperT< Void > umulExtended( UVec3 const & x, UVec3 const & y, UVec3 const & msb, UVec3 const & lsb );
	SDW_API ReturnWrapperT< Void > umulExtended( UVec4 const & x, UVec4 const & y, UVec4 const & msb, UVec4 const & lsb );
	/**@}*/
#pragma endregion
#pragma region imulExtended
	/**
	*name
	*	imulExtended
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > imulExtended( Int const & x, Int const & y, Int const & msb, Int const & lsb );
	SDW_API ReturnWrapperT< Void > imulExtended( IVec2 const & x, IVec2 const & y, IVec2 const & msb, IVec2 const & lsb );
	SDW_API ReturnWrapperT< Void > imulExtended( IVec3 const & x, IVec3 const & y, IVec3 const & msb, IVec3 const & lsb );
	SDW_API ReturnWrapperT< Void > imulExtended( IVec4 const & x, IVec4 const & y, IVec4 const & msb, IVec4 const & lsb );
	/**@}*/
#pragma endregion
#pragma region bitfieldExtract
	/**
	*name
	*	bitfieldExtract
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > bitfieldExtract( Int const & value, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< IVec2 > bitfieldExtract( IVec2 const & value, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< IVec3 > bitfieldExtract( IVec3 const & value, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< IVec4 > bitfieldExtract( IVec4 const & value, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< UInt > bitfieldExtract( UInt const & value, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< UVec2 > bitfieldExtract( UVec2 const & value, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< UVec3 > bitfieldExtract( UVec3 const & value, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< UVec4 > bitfieldExtract( UVec4 const & value, Int const & offset, Int const & bits );
	/**@}*/
#pragma endregion
#pragma region bitfieldInsert
	/**
	*name
	*	bitfieldInsert
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > bitfieldInsert( Int const & base, Int const & insert, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< IVec2 > bitfieldInsert( IVec2 const & base, IVec2 const & insert, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< IVec3 > bitfieldInsert( IVec3 const & base, IVec3 const & insert, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< IVec4 > bitfieldInsert( IVec4 const & base, IVec4 const & insert, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< UInt > bitfieldInsert( UInt const & base, UInt const & insert, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< UVec2 > bitfieldInsert( UVec2 const & base, UVec2 const & insert, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< UVec3 > bitfieldInsert( UVec3 const & base, UVec3 const & insert, Int const & offset, Int const & bits );
	SDW_API ReturnWrapperT< UVec4 > bitfieldInsert( UVec4 const & base, UVec4 const & insert, Int const & offset, Int const & bits );
	/**@}*/
#pragma endregion
#pragma region bitfieldReverse
	/**
	*name
	*	bitfieldReverse
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > bitfieldReverse( Int const & value );
	SDW_API ReturnWrapperT< IVec2 > bitfieldReverse( IVec2 const & value );
	SDW_API ReturnWrapperT< IVec3 > bitfieldReverse( IVec3 const & value );
	SDW_API ReturnWrapperT< IVec4 > bitfieldReverse( IVec4 const & value );
	SDW_API ReturnWrapperT< UInt > bitfieldReverse( UInt const & value );
	SDW_API ReturnWrapperT< UVec2 > bitfieldReverse( UVec2 const & value );
	SDW_API ReturnWrapperT< UVec3 > bitfieldReverse( UVec3 const & value );
	SDW_API ReturnWrapperT< UVec4 > bitfieldReverse( UVec4 const & value );
	/**@}*/
#pragma endregion
#pragma region bitCount
	/**
	*name
	*	bitCount
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > bitCount( Int const & value );
	SDW_API ReturnWrapperT< IVec2 > bitCount( IVec2 const & value );
	SDW_API ReturnWrapperT< IVec3 > bitCount( IVec3 const & value );
	SDW_API ReturnWrapperT< IVec4 > bitCount( IVec4 const & value );
	SDW_API ReturnWrapperT< UInt > bitCount( UInt const & value );
	SDW_API ReturnWrapperT< UVec2 > bitCount( UVec2 const & value );
	SDW_API ReturnWrapperT< UVec3 > bitCount( UVec3 const & value );
	SDW_API ReturnWrapperT< UVec4 > bitCount( UVec4 const & value );
	/**@}*/
#pragma endregion
#pragma region findLSB
	/**
	*name
	*	findLSB
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > findLSB( Int const & value );
	SDW_API ReturnWrapperT< IVec2 > findLSB( IVec2 const & value );
	SDW_API ReturnWrapperT< IVec3 > findLSB( IVec3 const & value );
	SDW_API ReturnWrapperT< IVec4 > findLSB( IVec4 const & value );
	SDW_API ReturnWrapperT< Int > findLSB( UInt const & value );
	SDW_API ReturnWrapperT< IVec2 > findLSB( UVec2 const & value );
	SDW_API ReturnWrapperT< IVec3 > findLSB( UVec3 const & value );
	SDW_API ReturnWrapperT< IVec4 > findLSB( UVec4 const & value );
	/**@}*/
#pragma endregion
#pragma region findMSB
	/**
	*name
	*	findMSB
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > findMSB( Int const & value );
	SDW_API ReturnWrapperT< IVec2 > findMSB( IVec2 const & value );
	SDW_API ReturnWrapperT< IVec3 > findMSB( IVec3 const & value );
	SDW_API ReturnWrapperT< IVec4 > findMSB( IVec4 const & value );
	SDW_API ReturnWrapperT< Int > findMSB( UInt const & value );
	SDW_API ReturnWrapperT< IVec2 > findMSB( UVec2 const & value );
	SDW_API ReturnWrapperT< IVec3 > findMSB( UVec3 const & value );
	SDW_API ReturnWrapperT< IVec4 > findMSB( UVec4 const & value );
	/**@}*/
#pragma endregion
#pragma region atomicAdd
	/**
	*name
	*	atomicAdd
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > atomicAdd( Int const & mem, Int const & data );
	SDW_API ReturnWrapperT< UInt > atomicAdd( UInt const & mem, UInt const & data );
	SDW_API ReturnWrapperT< Float > atomicAdd( Float const & mem, Float const & data );
	SDW_API ReturnWrapperT< HVec2 > atomicAdd( HVec2 const & mem, HVec2 const & data );
	SDW_API ReturnWrapperT< HVec4 > atomicAdd( HVec4 const & mem, HVec4 const & data );
	/**@}*/
#pragma endregion
#pragma region atomicMin
	/**
	*name
	*	atomicMin
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > atomicMin( Int const & mem, Int const & data );
	SDW_API ReturnWrapperT< UInt > atomicMin( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicMax
	/**
	*name
	*	atomicMax
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > atomicMax( Int const & mem, Int const & data );
	SDW_API ReturnWrapperT< UInt > atomicMax( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicAnd
	/**
	*name
	*	atomicAnd
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > atomicAnd( Int const & mem, Int const & data );
	SDW_API ReturnWrapperT< UInt > atomicAnd( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicOr
	/**
	*name
	*	atomicOr
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > atomicOr( Int const & mem, Int const & data );
	SDW_API ReturnWrapperT< UInt > atomicOr( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicXor
	/**
	*name
	*	atomicXor
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > atomicXor( Int const & mem, Int const & data );
	SDW_API ReturnWrapperT< UInt > atomicXor( UInt const & mem, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region atomicExchange
	/**
	*name
	*	atomicExchange
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > atomicExchange( Int const & mem, Int const & data );
	SDW_API ReturnWrapperT< UInt > atomicExchange( UInt const & mem, UInt const & data );
	SDW_API ReturnWrapperT< Float > atomicExchange( Float const & mem, Float const & data );
	SDW_API ReturnWrapperT< HVec2 > atomicExchange( HVec2 const & mem, HVec2 const & data );
	SDW_API ReturnWrapperT< HVec4 > atomicExchange( HVec4 const & mem, HVec4 const & data );
	/**@}*/
#pragma endregion
#pragma region atomicCompSwap
	/**
	*name
	*	atomicCompSwap
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Int > atomicCompSwap( Int const & mem, Int const & compare, Int const & data );
	SDW_API ReturnWrapperT< UInt > atomicCompSwap( UInt const & mem, UInt const & compare, UInt const & data );
	/**@}*/
#pragma endregion
#pragma region dFdx
	/**
	*name
	*	dFdx
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > dFdx( Float const & p );
	SDW_API ReturnWrapperT< Vec2 > dFdx( Vec2 const & p );
	SDW_API ReturnWrapperT< Vec3 > dFdx( Vec3 const & p );
	SDW_API ReturnWrapperT< Vec4 > dFdx( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region dFdxCoarse
	/**
	*name
	*	dFdxCoarse
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > dFdxCoarse( Float const & p );
	SDW_API ReturnWrapperT< Vec2 > dFdxCoarse( Vec2 const & p );
	SDW_API ReturnWrapperT< Vec3 > dFdxCoarse( Vec3 const & p );
	SDW_API ReturnWrapperT< Vec4 > dFdxCoarse( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region dFdxFine
	/**
	*name
	*	dFdxFine
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > dFdxFine( Float const & p );
	SDW_API ReturnWrapperT< Vec2 > dFdxFine( Vec2 const & p );
	SDW_API ReturnWrapperT< Vec3 > dFdxFine( Vec3 const & p );
	SDW_API ReturnWrapperT< Vec4 > dFdxFine( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region dFdy
	/**
	*name
	*	dFdy
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > dFdy( Float const & p );
	SDW_API ReturnWrapperT< Vec2 > dFdy( Vec2 const & p );
	SDW_API ReturnWrapperT< Vec3 > dFdy( Vec3 const & p );
	SDW_API ReturnWrapperT< Vec4 > dFdy( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region dFdyCoarse
	/**
	*name
	*	dFdyCoarse
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > dFdyCoarse( Float const & p );
	SDW_API ReturnWrapperT< Vec2 > dFdyCoarse( Vec2 const & p );
	SDW_API ReturnWrapperT< Vec3 > dFdyCoarse( Vec3 const & p );
	SDW_API ReturnWrapperT< Vec4 > dFdyCoarse( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region dFdyFine
	/**
	*name
	*	dFdyFine
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > dFdyFine( Float const & p );
	SDW_API ReturnWrapperT< Vec2 > dFdyFine( Vec2 const & p );
	SDW_API ReturnWrapperT< Vec3 > dFdyFine( Vec3 const & p );
	SDW_API ReturnWrapperT< Vec4 > dFdyFine( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region fwidth
	/**
	*name
	*	fwidth
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > fwidth( Float const & p );
	SDW_API ReturnWrapperT< Vec2 > fwidth( Vec2 const & p );
	SDW_API ReturnWrapperT< Vec3 > fwidth( Vec3 const & p );
	SDW_API ReturnWrapperT< Vec4 > fwidth( Vec4 const & p );
	/**@}*/
#pragma endregion
#pragma region interpolateAtCentroid
	/**
	*name
	*	interpolateAtCentroid
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > interpolateAtCentroid( Float const & x );
	SDW_API ReturnWrapperT< Vec2 > interpolateAtCentroid( Vec2 const & x );
	SDW_API ReturnWrapperT< Vec3 > interpolateAtCentroid( Vec3 const & x );
	SDW_API ReturnWrapperT< Vec4 > interpolateAtCentroid( Vec4 const & x );
	/**@}*/
#pragma endregion
#pragma region interpolateAtSample
	/**
	*name
	*	interpolateAtSample
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > interpolateAtSample( Float const & interpolant, Int const & sample );
	SDW_API ReturnWrapperT< Vec2 > interpolateAtSample( Vec2 const & interpolant, Int const & sample );
	SDW_API ReturnWrapperT< Vec3 > interpolateAtSample( Vec3 const & interpolant, Int const & sample );
	SDW_API ReturnWrapperT< Vec4 > interpolateAtSample( Vec4 const & interpolant, Int const & sample );
	/**@}*/
#pragma endregion
#pragma region interpolateAtOffset
	/**
	*name
	*	interpolateAtOffset
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Float > interpolateAtOffset( Float const & interpolant, Vec2 const & offset );
	SDW_API ReturnWrapperT< Vec2 > interpolateAtOffset( Vec2 const & interpolant, Vec2 const & offset );
	SDW_API ReturnWrapperT< Vec3 > interpolateAtOffset( Vec3 const & interpolant, Vec2 const & offset );
	SDW_API ReturnWrapperT< Vec4 > interpolateAtOffset( Vec4 const & interpolant, Vec2 const & offset );
	/**@}*/
#pragma endregion
#pragma region EmitStreamVertex
	/**
	*name
	*	EmitStreamVertex
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > EmitStreamVertex( Int const & stream );
	/**@}*/
#pragma endregion
#pragma region EndStreamPrimitive
	/**
	*name
	*	EndStreamPrimitive
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > EndStreamPrimitive( Int const & stream );
	/**@}*/
#pragma endregion
#pragma region EmitVertex
	/**
	*name
	*	EmitVertex
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > EmitVertex( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region EndPrimitive
	/**
	*name
	*	EndPrimitive
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > EndPrimitive( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region barrier
	/**
	*name
	*	barrier
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > barrier( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region helperInvocation
	/**
	*name
	*	helperInvocation
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Boolean > helperInvocation( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region memoryBarrier
	/**
	*name
	*	memoryBarrier
	*/
	/**@{*/
	SDW_API ReturnWrapperT< UInt > memoryBarrier( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region memoryBarrierBuffer
	/**
	*name
	*	memoryBarrierBuffer
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > memoryBarrierBuffer( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region memoryBarrierShared
	/**
	*name
	*	memoryBarrierShared
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > memoryBarrierShared( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region memoryBarrierImage
	/**
	*name
	*	memoryBarrierImage
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > memoryBarrierImage( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region groupMemoryBarrier
	/**
	*name
	*	groupMemoryBarrier
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > groupMemoryBarrier( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region traceRay
	/**
	*name
	*	traceRay
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > traceRay( AccelerationStructure const & topLevel, UInt const & rayFlags, UInt const & cullMask, UInt const & sbtRecordOffset, UInt const & sbtRecordStride, UInt const & missIndex, RayDesc const & rayDesc, RayPayload const & payload );
	/**@}*/
#pragma endregion
#pragma region reportIntersection
	/**
	*name
	*	reportIntersection
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Boolean > reportIntersection( Float const & hitT, UInt const & hitKind, HitAttribute const & attribs );
	/**@}*/
#pragma endregion
#pragma region executeCallable
	/**
	*name
	*	executeCallable
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > executeCallable( UInt const & sbtRecordIndex, CallableData const & callable );
	/**@}*/
#pragma endregion
#pragma region setMeshOutputCounts
	/**
	*name
	*	setMeshOutputCounts
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > setMeshOutputCounts( UInt const & numVertices, UInt const & numPrimitives );
	/**@}*/
#pragma endregion
#pragma region dispatchMesh
	/**
	*name
	*	dispatchMesh
	*/
	/**@{*/
	SDW_API ReturnWrapperT< Void > dispatchMesh( TaskPayload const & payload, UInt const & numTasks );
	/**@}*/
#pragma endregion
}

#endif
