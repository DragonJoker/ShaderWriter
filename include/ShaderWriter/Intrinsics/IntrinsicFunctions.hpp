
/*
See LICENSE file in root folder
*/
#ifndef ___SDW_IntrinsicFunctions_H___
#define ___SDW_IntrinsicFunctions_H___
#pragma once

#include "ShaderWriter/BaseTypes/Bool.hpp"
#include "ShaderWriter/BaseTypes/Image.hpp"
#include "ShaderWriter/BaseTypes/SampledImage.hpp"
#include "ShaderWriter/BaseTypes/Sampler.hpp"
#include "ShaderWriter/CompositeTypes/Function.hpp"
#include "ShaderWriter/CompositeTypes/FunctionParam.hpp"
#include "ShaderWriter/MatTypes/Mat2.hpp"
#include "ShaderWriter/MatTypes/Mat2x3.hpp"
#include "ShaderWriter/MatTypes/Mat2x4.hpp"
#include "ShaderWriter/MatTypes/Mat3.hpp"
#include "ShaderWriter/MatTypes/Mat3x2.hpp"
#include "ShaderWriter/MatTypes/Mat3x4.hpp"
#include "ShaderWriter/MatTypes/Mat4.hpp"
#include "ShaderWriter/MatTypes/Mat4x2.hpp"
#include "ShaderWriter/MatTypes/Mat4x3.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptional.hpp"

#include <ShaderAST/Expr/MakeIntrinsic.hpp>

namespace sdw
{
#pragma region degrees
	/**
	*name
	*	degrees
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > degrees( MaybeOptional< Float > const & radians );
	SDW_API MaybeOptional< Vec2 > degrees( MaybeOptional< Vec2 > const & radians );
	SDW_API MaybeOptional< Vec3 > degrees( MaybeOptional< Vec3 > const & radians );
	SDW_API MaybeOptional< Vec4 > degrees( MaybeOptional< Vec4 > const & radians );
	/**@}*/
#pragma endregion
#pragma region radians
	/**
	*name
	*	radians
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > radians( MaybeOptional< Float > const & degrees );
	SDW_API MaybeOptional< Vec2 > radians( MaybeOptional< Vec2 > const & degrees );
	SDW_API MaybeOptional< Vec3 > radians( MaybeOptional< Vec3 > const & degrees );
	SDW_API MaybeOptional< Vec4 > radians( MaybeOptional< Vec4 > const & degrees );
	/**@}*/
#pragma endregion
#pragma region cos
	/**
	*name
	*	cos
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > cos( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > cos( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > cos( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > cos( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region sin
	/**
	*name
	*	sin
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > sin( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > sin( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > sin( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > sin( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region tan
	/**
	*name
	*	tan
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > tan( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > tan( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > tan( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > tan( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region cosh
	/**
	*name
	*	cosh
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > cosh( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > cosh( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > cosh( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > cosh( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region sinh
	/**
	*name
	*	sinh
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > sinh( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > sinh( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > sinh( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > sinh( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region tanh
	/**
	*name
	*	tanh
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > tanh( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > tanh( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > tanh( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > tanh( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region acos
	/**
	*name
	*	acos
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > acos( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > acos( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > acos( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > acos( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region asin
	/**
	*name
	*	asin
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > asin( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > asin( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > asin( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > asin( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region atan
	/**
	*name
	*	atan
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > atan( MaybeOptional< Float > const & y_over_x );
	SDW_API MaybeOptional< Vec2 > atan( MaybeOptional< Vec2 > const & y_over_x );
	SDW_API MaybeOptional< Vec3 > atan( MaybeOptional< Vec3 > const & y_over_x );
	SDW_API MaybeOptional< Vec4 > atan( MaybeOptional< Vec4 > const & y_over_x );
	/**@}*/
#pragma endregion
#pragma region atan2
	/**
	*name
	*	atan2
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > atan2( MaybeOptional< Float > const & y, MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > atan2( MaybeOptional< Vec2 > const & y, MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > atan2( MaybeOptional< Vec3 > const & y, MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > atan2( MaybeOptional< Vec4 > const & y, MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region acosh
	/**
	*name
	*	acosh
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > acosh( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > acosh( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > acosh( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > acosh( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region asinh
	/**
	*name
	*	asinh
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > asinh( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > asinh( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > asinh( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > asinh( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region atanh
	/**
	*name
	*	atanh
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > atanh( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > atanh( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > atanh( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > atanh( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region pow
	/**
	*name
	*	pow
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > pow( MaybeOptional< Float > const & x, MaybeOptional< Float > const & y );
	SDW_API MaybeOptional< Vec2 > pow( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y );
	SDW_API MaybeOptional< Vec3 > pow( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< Vec4 > pow( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y );
	/**@}*/
#pragma endregion
#pragma region exp
	/**
	*name
	*	exp
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > exp( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > exp( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > exp( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > exp( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region log
	/**
	*name
	*	log
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > log( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > log( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > log( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > log( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region exp2
	/**
	*name
	*	exp2
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > exp2( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > exp2( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > exp2( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > exp2( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region log2
	/**
	*name
	*	log2
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > log2( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > log2( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > log2( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > log2( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region sqrt
	/**
	*name
	*	sqrt
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > sqrt( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > sqrt( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > sqrt( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > sqrt( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > sqrt( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > sqrt( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > sqrt( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > sqrt( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region inverseSqrt
	/**
	*name
	*	inverseSqrt
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > inverseSqrt( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > inverseSqrt( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > inverseSqrt( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > inverseSqrt( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > inverseSqrt( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > inverseSqrt( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > inverseSqrt( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > inverseSqrt( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region abs
	/**
	*name
	*	abs
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > abs( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > abs( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > abs( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > abs( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Int > abs( MaybeOptional< Int > const & x );
	SDW_API MaybeOptional< IVec2 > abs( MaybeOptional< IVec2 > const & x );
	SDW_API MaybeOptional< IVec3 > abs( MaybeOptional< IVec3 > const & x );
	SDW_API MaybeOptional< IVec4 > abs( MaybeOptional< IVec4 > const & x );
	SDW_API MaybeOptional< Double > abs( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > abs( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > abs( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > abs( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region sign
	/**
	*name
	*	sign
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > sign( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > sign( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > sign( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > sign( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Int > sign( MaybeOptional< Int > const & x );
	SDW_API MaybeOptional< IVec2 > sign( MaybeOptional< IVec2 > const & x );
	SDW_API MaybeOptional< IVec3 > sign( MaybeOptional< IVec3 > const & x );
	SDW_API MaybeOptional< IVec4 > sign( MaybeOptional< IVec4 > const & x );
	SDW_API MaybeOptional< Double > sign( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > sign( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > sign( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > sign( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region floor
	/**
	*name
	*	floor
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > floor( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > floor( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > floor( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > floor( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > floor( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > floor( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > floor( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > floor( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region trunc
	/**
	*name
	*	trunc
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > trunc( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > trunc( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > trunc( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > trunc( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > trunc( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > trunc( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > trunc( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > trunc( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region round
	/**
	*name
	*	round
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > round( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > round( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > round( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > round( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > round( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > round( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > round( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > round( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region roundEven
	/**
	*name
	*	roundEven
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > roundEven( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > roundEven( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > roundEven( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > roundEven( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > roundEven( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > roundEven( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > roundEven( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > roundEven( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region ceil
	/**
	*name
	*	ceil
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > ceil( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > ceil( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > ceil( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > ceil( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > ceil( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > ceil( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > ceil( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > ceil( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region fract
	/**
	*name
	*	fract
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > fract( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > fract( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > fract( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > fract( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > fract( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > fract( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > fract( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > fract( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region mod
	/**
	*name
	*	mod
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > mod( MaybeOptional< Float > const & x, MaybeOptional< Float > const & y );
	SDW_API MaybeOptional< Vec2 > mod( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y );
	SDW_API MaybeOptional< Vec3 > mod( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< Vec4 > mod( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y );
	SDW_API MaybeOptional< Double > mod( MaybeOptional< Double > const & x, MaybeOptional< Double > const & y );
	SDW_API MaybeOptional< DVec2 > mod( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & y );
	SDW_API MaybeOptional< DVec3 > mod( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y );
	SDW_API MaybeOptional< DVec4 > mod( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & y );
	/**@}*/
#pragma endregion
#pragma region modf
	/**
	*name
	*	modf
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > modf( MaybeOptional< Float > const & x, Float & i );
	SDW_API MaybeOptional< Vec2 > modf( MaybeOptional< Vec2 > const & x, Vec2 & i );
	SDW_API MaybeOptional< Vec3 > modf( MaybeOptional< Vec3 > const & x, Vec3 & i );
	SDW_API MaybeOptional< Vec4 > modf( MaybeOptional< Vec4 > const & x, Vec4 & i );
	SDW_API MaybeOptional< Double > modf( MaybeOptional< Double > const & x, Double & i );
	SDW_API MaybeOptional< DVec2 > modf( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & i );
	SDW_API MaybeOptional< DVec3 > modf( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & i );
	SDW_API MaybeOptional< DVec4 > modf( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & i );
	/**@}*/
#pragma endregion
#pragma region min
	/**
	*name
	*	min
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > min( MaybeOptional< Float > const & x, MaybeOptional< Float > const & y );
	SDW_API MaybeOptional< Vec2 > min( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y );
	SDW_API MaybeOptional< Vec3 > min( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< Vec4 > min( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y );
	SDW_API MaybeOptional< Double > min( MaybeOptional< Double > const & x, MaybeOptional< Double > const & y );
	SDW_API MaybeOptional< DVec2 > min( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & y );
	SDW_API MaybeOptional< DVec3 > min( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y );
	SDW_API MaybeOptional< DVec4 > min( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & y );
	SDW_API MaybeOptional< Int > min( MaybeOptional< Int > const & x, MaybeOptional< Int > const & y );
	SDW_API MaybeOptional< IVec2 > min( MaybeOptional< IVec2 > const & x, MaybeOptional< IVec2 > const & y );
	SDW_API MaybeOptional< IVec3 > min( MaybeOptional< IVec3 > const & x, MaybeOptional< IVec3 > const & y );
	SDW_API MaybeOptional< IVec4 > min( MaybeOptional< IVec4 > const & x, MaybeOptional< IVec4 > const & y );
	SDW_API MaybeOptional< UInt > min( MaybeOptional< UInt > const & x, MaybeOptional< UInt > const & y );
	SDW_API MaybeOptional< UVec2 > min( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & y );
	SDW_API MaybeOptional< UVec3 > min( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & y );
	SDW_API MaybeOptional< UVec4 > min( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & y );
	/**@}*/
#pragma endregion
#pragma region max
	/**
	*name
	*	max
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > max( MaybeOptional< Float > const & x, MaybeOptional< Float > const & y );
	SDW_API MaybeOptional< Vec2 > max( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y );
	SDW_API MaybeOptional< Vec3 > max( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< Vec4 > max( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y );
	SDW_API MaybeOptional< Double > max( MaybeOptional< Double > const & x, MaybeOptional< Double > const & y );
	SDW_API MaybeOptional< DVec2 > max( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & y );
	SDW_API MaybeOptional< DVec3 > max( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y );
	SDW_API MaybeOptional< DVec4 > max( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & y );
	SDW_API MaybeOptional< Int > max( MaybeOptional< Int > const & x, MaybeOptional< Int > const & y );
	SDW_API MaybeOptional< IVec2 > max( MaybeOptional< IVec2 > const & x, MaybeOptional< IVec2 > const & y );
	SDW_API MaybeOptional< IVec3 > max( MaybeOptional< IVec3 > const & x, MaybeOptional< IVec3 > const & y );
	SDW_API MaybeOptional< IVec4 > max( MaybeOptional< IVec4 > const & x, MaybeOptional< IVec4 > const & y );
	SDW_API MaybeOptional< UInt > max( MaybeOptional< UInt > const & x, MaybeOptional< UInt > const & y );
	SDW_API MaybeOptional< UVec2 > max( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & y );
	SDW_API MaybeOptional< UVec3 > max( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & y );
	SDW_API MaybeOptional< UVec4 > max( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & y );
	/**@}*/
#pragma endregion
#pragma region clamp
	/**
	*name
	*	clamp
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > clamp( MaybeOptional< Float > const & x, MaybeOptional< Float > const & minVal, MaybeOptional< Float > const & maxVal );
	SDW_API MaybeOptional< Vec2 > clamp( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & minVal, MaybeOptional< Vec2 > const & maxVal );
	SDW_API MaybeOptional< Vec3 > clamp( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & minVal, MaybeOptional< Vec3 > const & maxVal );
	SDW_API MaybeOptional< Vec4 > clamp( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & minVal, MaybeOptional< Vec4 > const & maxVal );
	SDW_API MaybeOptional< Double > clamp( MaybeOptional< Double > const & x, MaybeOptional< Double > const & minVal, MaybeOptional< Double > const & maxVal );
	SDW_API MaybeOptional< DVec2 > clamp( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & minVal, MaybeOptional< DVec2 > const & maxVal );
	SDW_API MaybeOptional< DVec3 > clamp( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & minVal, MaybeOptional< DVec3 > const & maxVal );
	SDW_API MaybeOptional< DVec4 > clamp( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & minVal, MaybeOptional< DVec4 > const & maxVal );
	SDW_API MaybeOptional< Int > clamp( MaybeOptional< Int > const & x, MaybeOptional< Int > const & minVal, MaybeOptional< Int > const & maxVal );
	SDW_API MaybeOptional< IVec2 > clamp( MaybeOptional< IVec2 > const & x, MaybeOptional< IVec2 > const & minVal, MaybeOptional< IVec2 > const & maxVal );
	SDW_API MaybeOptional< IVec3 > clamp( MaybeOptional< IVec3 > const & x, MaybeOptional< IVec3 > const & minVal, MaybeOptional< IVec3 > const & maxVal );
	SDW_API MaybeOptional< IVec4 > clamp( MaybeOptional< IVec4 > const & x, MaybeOptional< IVec4 > const & minVal, MaybeOptional< IVec4 > const & maxVal );
	SDW_API MaybeOptional< UInt > clamp( MaybeOptional< UInt > const & x, MaybeOptional< UInt > const & minVal, MaybeOptional< UInt > const & maxVal );
	SDW_API MaybeOptional< UVec2 > clamp( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & minVal, MaybeOptional< UVec2 > const & maxVal );
	SDW_API MaybeOptional< UVec3 > clamp( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & minVal, MaybeOptional< UVec3 > const & maxVal );
	SDW_API MaybeOptional< UVec4 > clamp( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & minVal, MaybeOptional< UVec4 > const & maxVal );
	/**@}*/
#pragma endregion
#pragma region mix
	/**
	*name
	*	mix
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > mix( MaybeOptional< Float > const & x, MaybeOptional< Float > const & y, MaybeOptional< Float > const & a );
	SDW_API MaybeOptional< Vec2 > mix( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y, MaybeOptional< Vec2 > const & a );
	SDW_API MaybeOptional< Vec3 > mix( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y, MaybeOptional< Vec3 > const & a );
	SDW_API MaybeOptional< Vec4 > mix( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y, MaybeOptional< Vec4 > const & a );
	SDW_API MaybeOptional< Double > mix( MaybeOptional< Double > const & x, MaybeOptional< Double > const & y, MaybeOptional< Double > const & a );
	SDW_API MaybeOptional< DVec2 > mix( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & y, MaybeOptional< DVec2 > const & a );
	SDW_API MaybeOptional< DVec3 > mix( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y, MaybeOptional< DVec3 > const & a );
	SDW_API MaybeOptional< DVec4 > mix( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & y, MaybeOptional< DVec4 > const & a );
	/**@}*/
#pragma endregion
#pragma region step
	/**
	*name
	*	step
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > step( MaybeOptional< Float > const & edge, MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > step( MaybeOptional< Vec2 > const & edge, MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > step( MaybeOptional< Vec3 > const & edge, MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > step( MaybeOptional< Vec4 > const & edge, MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > step( MaybeOptional< Double > const & edge, MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > step( MaybeOptional< DVec2 > const & edge, MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > step( MaybeOptional< DVec3 > const & edge, MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > step( MaybeOptional< DVec4 > const & edge, MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region smoothStep
	/**
	*name
	*	smoothStep
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > smoothStep( MaybeOptional< Float > const & edge0, MaybeOptional< Float > const & edge1, MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > smoothStep( MaybeOptional< Vec2 > const & edge0, MaybeOptional< Vec2 > const & edge1, MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > smoothStep( MaybeOptional< Vec3 > const & edge0, MaybeOptional< Vec3 > const & edge1, MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > smoothStep( MaybeOptional< Vec4 > const & edge0, MaybeOptional< Vec4 > const & edge1, MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > smoothStep( MaybeOptional< Double > const & edge0, MaybeOptional< Double > const & edge1, MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > smoothStep( MaybeOptional< DVec2 > const & edge0, MaybeOptional< DVec2 > const & edge1, MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > smoothStep( MaybeOptional< DVec3 > const & edge0, MaybeOptional< DVec3 > const & edge1, MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > smoothStep( MaybeOptional< DVec4 > const & edge0, MaybeOptional< DVec4 > const & edge1, MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region isnan
	/**
	*name
	*	isnan
	*/
	/**@{*/
	SDW_API MaybeOptional< Boolean > isnan( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< BVec2 > isnan( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< BVec3 > isnan( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< BVec4 > isnan( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Boolean > isnan( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< BVec2 > isnan( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< BVec3 > isnan( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< BVec4 > isnan( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region isinf
	/**
	*name
	*	isinf
	*/
	/**@{*/
	SDW_API MaybeOptional< Boolean > isinf( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< BVec2 > isinf( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< BVec3 > isinf( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< BVec4 > isinf( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Boolean > isinf( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< BVec2 > isinf( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< BVec3 > isinf( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< BVec4 > isinf( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region floatBitsToInt
	/**
	*name
	*	floatBitsToInt
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > floatBitsToInt( MaybeOptional< Float > const & value );
	SDW_API MaybeOptional< IVec2 > floatBitsToInt( MaybeOptional< Vec2 > const & value );
	SDW_API MaybeOptional< IVec3 > floatBitsToInt( MaybeOptional< Vec3 > const & value );
	SDW_API MaybeOptional< IVec4 > floatBitsToInt( MaybeOptional< Vec4 > const & value );
	/**@}*/
#pragma endregion
#pragma region floatBitsToUInt
	/**
	*name
	*	floatBitsToUInt
	*/
	/**@{*/
	SDW_API MaybeOptional< UInt > floatBitsToUInt( MaybeOptional< Float > const & value );
	SDW_API MaybeOptional< UVec2 > floatBitsToUInt( MaybeOptional< Vec2 > const & value );
	SDW_API MaybeOptional< UVec3 > floatBitsToUInt( MaybeOptional< Vec3 > const & value );
	SDW_API MaybeOptional< UVec4 > floatBitsToUInt( MaybeOptional< Vec4 > const & value );
	/**@}*/
#pragma endregion
#pragma region intBitsToFloat
	/**
	*name
	*	intBitsToFloat
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > intBitsToFloat( MaybeOptional< Int > const & x );
	SDW_API MaybeOptional< Vec2 > intBitsToFloat( MaybeOptional< IVec2 > const & x );
	SDW_API MaybeOptional< Vec3 > intBitsToFloat( MaybeOptional< IVec3 > const & x );
	SDW_API MaybeOptional< Vec4 > intBitsToFloat( MaybeOptional< IVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region uintBitsToFloat
	/**
	*name
	*	uintBitsToFloat
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > uintBitsToFloat( MaybeOptional< UInt > const & x );
	SDW_API MaybeOptional< Vec2 > uintBitsToFloat( MaybeOptional< UVec2 > const & x );
	SDW_API MaybeOptional< Vec3 > uintBitsToFloat( MaybeOptional< UVec3 > const & x );
	SDW_API MaybeOptional< Vec4 > uintBitsToFloat( MaybeOptional< UVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region fma
	/**
	*name
	*	fma
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > fma( MaybeOptional< Float > const & a, MaybeOptional< Float > const & b, MaybeOptional< Float > const & c );
	SDW_API MaybeOptional< Vec2 > fma( MaybeOptional< Vec2 > const & a, MaybeOptional< Vec2 > const & b, MaybeOptional< Vec2 > const & c );
	SDW_API MaybeOptional< Vec3 > fma( MaybeOptional< Vec3 > const & a, MaybeOptional< Vec3 > const & b, MaybeOptional< Vec3 > const & c );
	SDW_API MaybeOptional< Vec4 > fma( MaybeOptional< Vec4 > const & a, MaybeOptional< Vec4 > const & b, MaybeOptional< Vec4 > const & c );
	SDW_API MaybeOptional< Double > fma( MaybeOptional< Double > const & a, MaybeOptional< Double > const & b, MaybeOptional< Double > const & c );
	SDW_API MaybeOptional< DVec2 > fma( MaybeOptional< DVec2 > const & a, MaybeOptional< DVec2 > const & b, MaybeOptional< DVec2 > const & c );
	SDW_API MaybeOptional< DVec3 > fma( MaybeOptional< DVec3 > const & a, MaybeOptional< DVec3 > const & b, MaybeOptional< DVec3 > const & c );
	SDW_API MaybeOptional< DVec4 > fma( MaybeOptional< DVec4 > const & a, MaybeOptional< DVec4 > const & b, MaybeOptional< DVec4 > const & c );
	/**@}*/
#pragma endregion
#pragma region frexp
	/**
	*name
	*	frexp
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > frexp( MaybeOptional< Float > const & x, Int & exp );
	SDW_API MaybeOptional< Vec2 > frexp( MaybeOptional< Vec2 > const & x, IVec2 & exp );
	SDW_API MaybeOptional< Vec3 > frexp( MaybeOptional< Vec3 > const & x, IVec3 & exp );
	SDW_API MaybeOptional< Vec4 > frexp( MaybeOptional< Vec4 > const & x, IVec4 & exp );
	SDW_API MaybeOptional< Double > frexp( MaybeOptional< Double > const & x, Int & exp );
	SDW_API MaybeOptional< DVec2 > frexp( MaybeOptional< DVec2 > const & x, IVec2 & exp );
	SDW_API MaybeOptional< DVec3 > frexp( MaybeOptional< DVec3 > const & x, IVec3 & exp );
	SDW_API MaybeOptional< DVec4 > frexp( MaybeOptional< DVec4 > const & x, IVec4 & exp );
	/**@}*/
#pragma endregion
#pragma region ldexp
	/**
	*name
	*	ldexp
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > ldexp( MaybeOptional< Float > const & x, MaybeOptional< Int > const & exp );
	SDW_API MaybeOptional< Vec2 > ldexp( MaybeOptional< Vec2 > const & x, MaybeOptional< IVec2 > const & exp );
	SDW_API MaybeOptional< Vec3 > ldexp( MaybeOptional< Vec3 > const & x, MaybeOptional< IVec3 > const & exp );
	SDW_API MaybeOptional< Vec4 > ldexp( MaybeOptional< Vec4 > const & x, MaybeOptional< IVec4 > const & exp );
	SDW_API MaybeOptional< Double > ldexp( MaybeOptional< Double > const & x, MaybeOptional< Int > const & exp );
	SDW_API MaybeOptional< DVec2 > ldexp( MaybeOptional< DVec2 > const & x, MaybeOptional< IVec2 > const & exp );
	SDW_API MaybeOptional< DVec3 > ldexp( MaybeOptional< DVec3 > const & x, MaybeOptional< IVec3 > const & exp );
	SDW_API MaybeOptional< DVec4 > ldexp( MaybeOptional< DVec4 > const & x, MaybeOptional< IVec4 > const & exp );
	/**@}*/
#pragma endregion
#pragma region packDouble2x32
	/**
	*name
	*	packDouble2x32
	*/
	/**@{*/
	SDW_API MaybeOptional< Double > packDouble2x32( MaybeOptional< UVec2 > const & v );
	/**@}*/
#pragma endregion
#pragma region packHalf2x16
	/**
	*name
	*	packHalf2x16
	*/
	/**@{*/
	SDW_API MaybeOptional< UInt > packHalf2x16( MaybeOptional< Vec2 > const & v );
	/**@}*/
#pragma endregion
#pragma region packSnorm2x16
	/**
	*name
	*	packSnorm2x16
	*/
	/**@{*/
	SDW_API MaybeOptional< UInt > packSnorm2x16( MaybeOptional< Vec2 > const & v );
	/**@}*/
#pragma endregion
#pragma region packSnorm4x8
	/**
	*name
	*	packSnorm4x8
	*/
	/**@{*/
	SDW_API MaybeOptional< UInt > packSnorm4x8( MaybeOptional< Vec4 > const & v );
	/**@}*/
#pragma endregion
#pragma region packUnorm2x16
	/**
	*name
	*	packUnorm2x16
	*/
	/**@{*/
	SDW_API MaybeOptional< UInt > packUnorm2x16( MaybeOptional< Vec2 > const & v );
	/**@}*/
#pragma endregion
#pragma region packUnorm4x8
	/**
	*name
	*	packUnorm4x8
	*/
	/**@{*/
	SDW_API MaybeOptional< UInt > packUnorm4x8( MaybeOptional< Vec4 > const & v );
	/**@}*/
#pragma endregion
#pragma region unpackDouble2x32
	/**
	*name
	*	unpackDouble2x32
	*/
	/**@{*/
	SDW_API MaybeOptional< UVec2 > unpackDouble2x32( MaybeOptional< Double > const & d );
	/**@}*/
#pragma endregion
#pragma region unpackHalf2x16
	/**
	*name
	*	unpackHalf2x16
	*/
	/**@{*/
	SDW_API MaybeOptional< Vec2 > unpackHalf2x16( MaybeOptional< UInt > const & v );
	/**@}*/
#pragma endregion
#pragma region unpackSnorm2x16
	/**
	*name
	*	unpackSnorm2x16
	*/
	/**@{*/
	SDW_API MaybeOptional< Vec2 > unpackSnorm2x16( MaybeOptional< UInt > const & p );
	/**@}*/
#pragma endregion
#pragma region unpackSnorm4x8
	/**
	*name
	*	unpackSnorm4x8
	*/
	/**@{*/
	SDW_API MaybeOptional< Vec4 > unpackSnorm4x8( MaybeOptional< UInt > const & p );
	/**@}*/
#pragma endregion
#pragma region unpackUnorm2x16
	/**
	*name
	*	unpackUnorm2x16
	*/
	/**@{*/
	SDW_API MaybeOptional< Vec2 > unpackUnorm2x16( MaybeOptional< UInt > const & p );
	/**@}*/
#pragma endregion
#pragma region unpackUnorm4x8
	/**
	*name
	*	unpackUnorm4x8
	*/
	/**@{*/
	SDW_API MaybeOptional< Vec4 > unpackUnorm4x8( MaybeOptional< UInt > const & p );
	/**@}*/
#pragma endregion
#pragma region length
	/**
	*name
	*	length
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > length( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Float > length( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Float > length( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Float > length( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > length( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< Double > length( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< Double > length( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< Double > length( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region distance
	/**
	*name
	*	distance
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > distance( MaybeOptional< Float > const & p0, MaybeOptional< Float > const & p1 );
	SDW_API MaybeOptional< Vec2 > distance( MaybeOptional< Vec2 > const & p0, MaybeOptional< Vec2 > const & p1 );
	SDW_API MaybeOptional< Vec3 > distance( MaybeOptional< Vec3 > const & p0, MaybeOptional< Vec3 > const & p1 );
	SDW_API MaybeOptional< Vec4 > distance( MaybeOptional< Vec4 > const & p0, MaybeOptional< Vec4 > const & p1 );
	SDW_API MaybeOptional< Double > distance( MaybeOptional< Double > const & p0, MaybeOptional< Double > const & p1 );
	SDW_API MaybeOptional< Double > distance( MaybeOptional< DVec2 > const & p0, MaybeOptional< DVec2 > const & p1 );
	SDW_API MaybeOptional< Double > distance( MaybeOptional< DVec3 > const & p0, MaybeOptional< DVec3 > const & p1 );
	SDW_API MaybeOptional< Double > distance( MaybeOptional< DVec4 > const & p0, MaybeOptional< DVec4 > const & p1 );
	/**@}*/
#pragma endregion
#pragma region dot
	/**
	*name
	*	dot
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > dot( MaybeOptional< Float > const & x, MaybeOptional< Float > const & y );
	SDW_API MaybeOptional< Float > dot( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y );
	SDW_API MaybeOptional< Float > dot( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< Float > dot( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y );
	SDW_API MaybeOptional< Double > dot( MaybeOptional< Double > const & x, MaybeOptional< Double > const & y );
	SDW_API MaybeOptional< Double > dot( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & y );
	SDW_API MaybeOptional< Double > dot( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y );
	SDW_API MaybeOptional< Double > dot( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & y );
	/**@}*/
#pragma endregion
#pragma region cross
	/**
	*name
	*	cross
	*/
	/**@{*/
	SDW_API MaybeOptional< Vec3 > cross( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< DVec3 > cross( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y );
	/**@}*/
#pragma endregion
#pragma region normalize
	/**
	*name
	*	normalize
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > normalize( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > normalize( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > normalize( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > normalize( MaybeOptional< Vec4 > const & x );
	SDW_API MaybeOptional< Double > normalize( MaybeOptional< Double > const & x );
	SDW_API MaybeOptional< DVec2 > normalize( MaybeOptional< DVec2 > const & x );
	SDW_API MaybeOptional< DVec3 > normalize( MaybeOptional< DVec3 > const & x );
	SDW_API MaybeOptional< DVec4 > normalize( MaybeOptional< DVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region faceForward
	/**
	*name
	*	faceForward
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > faceForward( MaybeOptional< Float > const & N, MaybeOptional< Float > const & I, MaybeOptional< Float > const & Nref );
	SDW_API MaybeOptional< Vec2 > faceForward( MaybeOptional< Vec2 > const & N, MaybeOptional< Vec2 > const & I, MaybeOptional< Vec2 > const & Nref );
	SDW_API MaybeOptional< Vec3 > faceForward( MaybeOptional< Vec3 > const & N, MaybeOptional< Vec3 > const & I, MaybeOptional< Vec3 > const & Nref );
	SDW_API MaybeOptional< Vec4 > faceForward( MaybeOptional< Vec4 > const & N, MaybeOptional< Vec4 > const & I, MaybeOptional< Vec4 > const & Nref );
	SDW_API MaybeOptional< Double > faceForward( MaybeOptional< Double > const & N, MaybeOptional< Double > const & I, MaybeOptional< Double > const & Nref );
	SDW_API MaybeOptional< DVec2 > faceForward( MaybeOptional< DVec2 > const & N, MaybeOptional< DVec2 > const & I, MaybeOptional< DVec2 > const & Nref );
	SDW_API MaybeOptional< DVec3 > faceForward( MaybeOptional< DVec3 > const & N, MaybeOptional< DVec3 > const & I, MaybeOptional< DVec3 > const & Nref );
	SDW_API MaybeOptional< DVec4 > faceForward( MaybeOptional< DVec4 > const & N, MaybeOptional< DVec4 > const & I, MaybeOptional< DVec4 > const & Nref );
	/**@}*/
#pragma endregion
#pragma region reflect
	/**
	*name
	*	reflect
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > reflect( MaybeOptional< Float > const & I, MaybeOptional< Float > const & N );
	SDW_API MaybeOptional< Vec2 > reflect( MaybeOptional< Vec2 > const & I, MaybeOptional< Vec2 > const & N );
	SDW_API MaybeOptional< Vec3 > reflect( MaybeOptional< Vec3 > const & I, MaybeOptional< Vec3 > const & N );
	SDW_API MaybeOptional< Vec4 > reflect( MaybeOptional< Vec4 > const & I, MaybeOptional< Vec4 > const & N );
	SDW_API MaybeOptional< Double > reflect( MaybeOptional< Double > const & I, MaybeOptional< Double > const & N );
	SDW_API MaybeOptional< DVec2 > reflect( MaybeOptional< DVec2 > const & I, MaybeOptional< DVec2 > const & N );
	SDW_API MaybeOptional< DVec3 > reflect( MaybeOptional< DVec3 > const & I, MaybeOptional< DVec3 > const & N );
	SDW_API MaybeOptional< DVec4 > reflect( MaybeOptional< DVec4 > const & I, MaybeOptional< DVec4 > const & N );
	/**@}*/
#pragma endregion
#pragma region refract
	/**
	*name
	*	refract
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > refract( MaybeOptional< Float > const & I, MaybeOptional< Float > const & N, MaybeOptional< Float > const & eta );
	SDW_API MaybeOptional< Vec2 > refract( MaybeOptional< Vec2 > const & I, MaybeOptional< Vec2 > const & N, MaybeOptional< Float > const & eta );
	SDW_API MaybeOptional< Vec3 > refract( MaybeOptional< Vec3 > const & I, MaybeOptional< Vec3 > const & N, MaybeOptional< Float > const & eta );
	SDW_API MaybeOptional< Vec4 > refract( MaybeOptional< Vec4 > const & I, MaybeOptional< Vec4 > const & N, MaybeOptional< Float > const & eta );
	SDW_API MaybeOptional< Double > refract( MaybeOptional< Double > const & I, MaybeOptional< Double > const & N, MaybeOptional< Float > const & eta );
	SDW_API MaybeOptional< DVec2 > refract( MaybeOptional< DVec2 > const & I, MaybeOptional< DVec2 > const & N, MaybeOptional< Float > const & eta );
	SDW_API MaybeOptional< DVec3 > refract( MaybeOptional< DVec3 > const & I, MaybeOptional< DVec3 > const & N, MaybeOptional< Float > const & eta );
	SDW_API MaybeOptional< DVec4 > refract( MaybeOptional< DVec4 > const & I, MaybeOptional< DVec4 > const & N, MaybeOptional< Float > const & eta );
	/**@}*/
#pragma endregion
#pragma region matrixCompMult
	/**
	*name
	*	matrixCompMult
	*/
	/**@{*/
	SDW_API MaybeOptional< Mat2 > matrixCompMult( MaybeOptional< Mat2 > const & x, MaybeOptional< Mat2 > const & y );
	SDW_API MaybeOptional< Mat2x3 > matrixCompMult( MaybeOptional< Mat2x3 > const & x, MaybeOptional< Mat2x3 > const & y );
	SDW_API MaybeOptional< Mat2x4 > matrixCompMult( MaybeOptional< Mat2x4 > const & x, MaybeOptional< Mat2x4 > const & y );
	SDW_API MaybeOptional< Mat3x2 > matrixCompMult( MaybeOptional< Mat3x2 > const & x, MaybeOptional< Mat3x2 > const & y );
	SDW_API MaybeOptional< Mat3 > matrixCompMult( MaybeOptional< Mat3 > const & x, MaybeOptional< Mat3 > const & y );
	SDW_API MaybeOptional< Mat3x4 > matrixCompMult( MaybeOptional< Mat3x4 > const & x, MaybeOptional< Mat3x4 > const & y );
	SDW_API MaybeOptional< Mat4x2 > matrixCompMult( MaybeOptional< Mat4x2 > const & x, MaybeOptional< Mat4x2 > const & y );
	SDW_API MaybeOptional< Mat4x3 > matrixCompMult( MaybeOptional< Mat4x3 > const & x, MaybeOptional< Mat4x3 > const & y );
	SDW_API MaybeOptional< Mat4 > matrixCompMult( MaybeOptional< Mat4 > const & x, MaybeOptional< Mat4 > const & y );
	SDW_API MaybeOptional< DMat2 > matrixCompMult( MaybeOptional< DMat2 > const & x, MaybeOptional< DMat2 > const & y );
	SDW_API MaybeOptional< DMat2x3 > matrixCompMult( MaybeOptional< DMat2x3 > const & x, MaybeOptional< DMat2x3 > const & y );
	SDW_API MaybeOptional< DMat2x4 > matrixCompMult( MaybeOptional< DMat2x4 > const & x, MaybeOptional< DMat2x4 > const & y );
	SDW_API MaybeOptional< DMat3x2 > matrixCompMult( MaybeOptional< DMat3x2 > const & x, MaybeOptional< DMat3x2 > const & y );
	SDW_API MaybeOptional< DMat3 > matrixCompMult( MaybeOptional< DMat3 > const & x, MaybeOptional< DMat3 > const & y );
	SDW_API MaybeOptional< DMat3x4 > matrixCompMult( MaybeOptional< DMat3x4 > const & x, MaybeOptional< DMat3x4 > const & y );
	SDW_API MaybeOptional< DMat4x2 > matrixCompMult( MaybeOptional< DMat4x2 > const & x, MaybeOptional< DMat4x2 > const & y );
	SDW_API MaybeOptional< DMat4x3 > matrixCompMult( MaybeOptional< DMat4x3 > const & x, MaybeOptional< DMat4x3 > const & y );
	SDW_API MaybeOptional< DMat4 > matrixCompMult( MaybeOptional< DMat4 > const & x, MaybeOptional< DMat4 > const & y );
	/**@}*/
#pragma endregion
#pragma region outerProduct
	/**
	*name
	*	outerProduct
	*/
	/**@{*/
	SDW_API MaybeOptional< Mat2 > outerProduct( MaybeOptional< Vec2 > const & c, MaybeOptional< Vec2 > const & r );
	SDW_API MaybeOptional< Mat3 > outerProduct( MaybeOptional< Vec3 > const & c, MaybeOptional< Vec3 > const & r );
	SDW_API MaybeOptional< Mat4 > outerProduct( MaybeOptional< Vec4 > const & c, MaybeOptional< Vec4 > const & r );
	SDW_API MaybeOptional< Mat2x3 > outerProduct( MaybeOptional< Vec3 > const & c, MaybeOptional< Vec2 > const & r );
	SDW_API MaybeOptional< Mat3x2 > outerProduct( MaybeOptional< Vec2 > const & c, MaybeOptional< Vec3 > const & r );
	SDW_API MaybeOptional< Mat2x4 > outerProduct( MaybeOptional< Vec4 > const & c, MaybeOptional< Vec2 > const & r );
	SDW_API MaybeOptional< Mat4x2 > outerProduct( MaybeOptional< Vec2 > const & c, MaybeOptional< Vec4 > const & r );
	SDW_API MaybeOptional< Mat3x4 > outerProduct( MaybeOptional< Vec4 > const & c, MaybeOptional< Vec3 > const & r );
	SDW_API MaybeOptional< Mat4x3 > outerProduct( MaybeOptional< Vec3 > const & c, MaybeOptional< Vec4 > const & r );
	SDW_API MaybeOptional< DMat2 > outerProduct( MaybeOptional< DVec2 > const & c, MaybeOptional< DVec2 > const & r );
	SDW_API MaybeOptional< DMat3 > outerProduct( MaybeOptional< DVec3 > const & c, MaybeOptional< DVec3 > const & r );
	SDW_API MaybeOptional< DMat4 > outerProduct( MaybeOptional< DVec4 > const & c, MaybeOptional< DVec4 > const & r );
	SDW_API MaybeOptional< DMat2x3 > outerProduct( MaybeOptional< DVec3 > const & c, MaybeOptional< DVec2 > const & r );
	SDW_API MaybeOptional< DMat3x2 > outerProduct( MaybeOptional< DVec2 > const & c, MaybeOptional< DVec3 > const & r );
	SDW_API MaybeOptional< DMat2x4 > outerProduct( MaybeOptional< DVec4 > const & c, MaybeOptional< DVec2 > const & r );
	SDW_API MaybeOptional< DMat4x2 > outerProduct( MaybeOptional< DVec2 > const & c, MaybeOptional< DVec4 > const & r );
	SDW_API MaybeOptional< DMat3x4 > outerProduct( MaybeOptional< DVec4 > const & c, MaybeOptional< DVec3 > const & r );
	SDW_API MaybeOptional< DMat4x3 > outerProduct( MaybeOptional< DVec3 > const & c, MaybeOptional< DVec4 > const & r );
	/**@}*/
#pragma endregion
#pragma region transpose
	/**
	*name
	*	transpose
	*/
	/**@{*/
	SDW_API MaybeOptional< Mat2 > transpose( MaybeOptional< Mat2 > const & x );
	SDW_API MaybeOptional< Mat3x2 > transpose( MaybeOptional< Mat2x3 > const & x );
	SDW_API MaybeOptional< Mat4x2 > transpose( MaybeOptional< Mat2x4 > const & x );
	SDW_API MaybeOptional< Mat2x3 > transpose( MaybeOptional< Mat3x2 > const & x );
	SDW_API MaybeOptional< Mat3 > transpose( MaybeOptional< Mat3 > const & x );
	SDW_API MaybeOptional< Mat4x3 > transpose( MaybeOptional< Mat3x4 > const & x );
	SDW_API MaybeOptional< Mat2x4 > transpose( MaybeOptional< Mat4x2 > const & x );
	SDW_API MaybeOptional< Mat3x4 > transpose( MaybeOptional< Mat4x3 > const & x );
	SDW_API MaybeOptional< Mat4 > transpose( MaybeOptional< Mat4 > const & x );
	SDW_API MaybeOptional< DMat2 > transpose( MaybeOptional< DMat2 > const & x );
	SDW_API MaybeOptional< DMat3x2 > transpose( MaybeOptional< DMat2x3 > const & x );
	SDW_API MaybeOptional< DMat4x2 > transpose( MaybeOptional< DMat2x4 > const & x );
	SDW_API MaybeOptional< DMat2x3 > transpose( MaybeOptional< DMat3x2 > const & x );
	SDW_API MaybeOptional< DMat3 > transpose( MaybeOptional< DMat3 > const & x );
	SDW_API MaybeOptional< DMat4x3 > transpose( MaybeOptional< DMat3x4 > const & x );
	SDW_API MaybeOptional< DMat2x4 > transpose( MaybeOptional< DMat4x2 > const & x );
	SDW_API MaybeOptional< DMat3x4 > transpose( MaybeOptional< DMat4x3 > const & x );
	SDW_API MaybeOptional< DMat4 > transpose( MaybeOptional< DMat4 > const & x );
	/**@}*/
#pragma endregion
#pragma region determinant
	/**
	*name
	*	determinant
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > determinant( MaybeOptional< Mat2 > const & m );
	SDW_API MaybeOptional< Float > determinant( MaybeOptional< Mat3 > const & m );
	SDW_API MaybeOptional< Float > determinant( MaybeOptional< Mat4 > const & m );
	SDW_API MaybeOptional< Double > determinant( MaybeOptional< DMat2 > const & m );
	SDW_API MaybeOptional< Double > determinant( MaybeOptional< DMat3 > const & m );
	SDW_API MaybeOptional< Double > determinant( MaybeOptional< DMat4 > const & m );
	/**@}*/
#pragma endregion
#pragma region inverse
	/**
	*name
	*	inverse
	*/
	/**@{*/
	SDW_API MaybeOptional< Mat2 > inverse( MaybeOptional< Mat2 > const & m );
	SDW_API MaybeOptional< Mat3 > inverse( MaybeOptional< Mat3 > const & m );
	SDW_API MaybeOptional< Mat4 > inverse( MaybeOptional< Mat4 > const & m );
	SDW_API MaybeOptional< DMat2 > inverse( MaybeOptional< DMat2 > const & m );
	SDW_API MaybeOptional< DMat3 > inverse( MaybeOptional< DMat3 > const & m );
	SDW_API MaybeOptional< DMat4 > inverse( MaybeOptional< DMat4 > const & m );
	/**@}*/
#pragma endregion
#pragma region lessThan
	/**
	*name
	*	lessThan
	*/
	/**@{*/
	SDW_API MaybeOptional< BVec2 > lessThan( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y );
	SDW_API MaybeOptional< BVec3 > lessThan( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< BVec4 > lessThan( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y );
	SDW_API MaybeOptional< BVec2 > lessThan( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > lessThan( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > lessThan( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > lessThan( MaybeOptional< IVec2 > const & x, MaybeOptional< IVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > lessThan( MaybeOptional< IVec3 > const & x, MaybeOptional< IVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > lessThan( MaybeOptional< IVec4 > const & x, MaybeOptional< IVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > lessThan( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > lessThan( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > lessThan( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & y );
	/**@}*/
#pragma endregion
#pragma region lessThanEqual
	/**
	*name
	*	lessThanEqual
	*/
	/**@{*/
	SDW_API MaybeOptional< BVec2 > lessThanEqual( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y );
	SDW_API MaybeOptional< BVec3 > lessThanEqual( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< BVec4 > lessThanEqual( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y );
	SDW_API MaybeOptional< BVec2 > lessThanEqual( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > lessThanEqual( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > lessThanEqual( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > lessThanEqual( MaybeOptional< IVec2 > const & x, MaybeOptional< IVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > lessThanEqual( MaybeOptional< IVec3 > const & x, MaybeOptional< IVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > lessThanEqual( MaybeOptional< IVec4 > const & x, MaybeOptional< IVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > lessThanEqual( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > lessThanEqual( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > lessThanEqual( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & y );
	/**@}*/
#pragma endregion
#pragma region greaterThan
	/**
	*name
	*	greaterThan
	*/
	/**@{*/
	SDW_API MaybeOptional< BVec2 > greaterThan( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y );
	SDW_API MaybeOptional< BVec3 > greaterThan( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< BVec4 > greaterThan( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y );
	SDW_API MaybeOptional< BVec2 > greaterThan( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > greaterThan( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > greaterThan( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > greaterThan( MaybeOptional< IVec2 > const & x, MaybeOptional< IVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > greaterThan( MaybeOptional< IVec3 > const & x, MaybeOptional< IVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > greaterThan( MaybeOptional< IVec4 > const & x, MaybeOptional< IVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > greaterThan( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > greaterThan( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > greaterThan( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & y );
	/**@}*/
#pragma endregion
#pragma region greaterThanEqual
	/**
	*name
	*	greaterThanEqual
	*/
	/**@{*/
	SDW_API MaybeOptional< BVec2 > greaterThanEqual( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y );
	SDW_API MaybeOptional< BVec3 > greaterThanEqual( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< BVec4 > greaterThanEqual( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y );
	SDW_API MaybeOptional< BVec2 > greaterThanEqual( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > greaterThanEqual( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > greaterThanEqual( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > greaterThanEqual( MaybeOptional< IVec2 > const & x, MaybeOptional< IVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > greaterThanEqual( MaybeOptional< IVec3 > const & x, MaybeOptional< IVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > greaterThanEqual( MaybeOptional< IVec4 > const & x, MaybeOptional< IVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > greaterThanEqual( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > greaterThanEqual( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > greaterThanEqual( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & y );
	/**@}*/
#pragma endregion
#pragma region equal
	/**
	*name
	*	equal
	*/
	/**@{*/
	SDW_API MaybeOptional< BVec2 > equal( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y );
	SDW_API MaybeOptional< BVec3 > equal( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< BVec4 > equal( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y );
	SDW_API MaybeOptional< BVec2 > equal( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > equal( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > equal( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > equal( MaybeOptional< IVec2 > const & x, MaybeOptional< IVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > equal( MaybeOptional< IVec3 > const & x, MaybeOptional< IVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > equal( MaybeOptional< IVec4 > const & x, MaybeOptional< IVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > equal( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > equal( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > equal( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & y );
	/**@}*/
#pragma endregion
#pragma region notEqual
	/**
	*name
	*	notEqual
	*/
	/**@{*/
	SDW_API MaybeOptional< BVec2 > notEqual( MaybeOptional< Vec2 > const & x, MaybeOptional< Vec2 > const & y );
	SDW_API MaybeOptional< BVec3 > notEqual( MaybeOptional< Vec3 > const & x, MaybeOptional< Vec3 > const & y );
	SDW_API MaybeOptional< BVec4 > notEqual( MaybeOptional< Vec4 > const & x, MaybeOptional< Vec4 > const & y );
	SDW_API MaybeOptional< BVec2 > notEqual( MaybeOptional< DVec2 > const & x, MaybeOptional< DVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > notEqual( MaybeOptional< DVec3 > const & x, MaybeOptional< DVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > notEqual( MaybeOptional< DVec4 > const & x, MaybeOptional< DVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > notEqual( MaybeOptional< IVec2 > const & x, MaybeOptional< IVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > notEqual( MaybeOptional< IVec3 > const & x, MaybeOptional< IVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > notEqual( MaybeOptional< IVec4 > const & x, MaybeOptional< IVec4 > const & y );
	SDW_API MaybeOptional< BVec2 > notEqual( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & y );
	SDW_API MaybeOptional< BVec3 > notEqual( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & y );
	SDW_API MaybeOptional< BVec4 > notEqual( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & y );
	/**@}*/
#pragma endregion
#pragma region all
	/**
	*name
	*	all
	*/
	/**@{*/
	SDW_API MaybeOptional< Boolean > all( MaybeOptional< BVec2 > const & x );
	SDW_API MaybeOptional< Boolean > all( MaybeOptional< BVec3 > const & x );
	SDW_API MaybeOptional< Boolean > all( MaybeOptional< BVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region any
	/**
	*name
	*	any
	*/
	/**@{*/
	SDW_API MaybeOptional< Boolean > any( MaybeOptional< BVec2 > const & x );
	SDW_API MaybeOptional< Boolean > any( MaybeOptional< BVec3 > const & x );
	SDW_API MaybeOptional< Boolean > any( MaybeOptional< BVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region binNot
	/**
	*name
	*	binNot
	*/
	/**@{*/
	SDW_API MaybeOptional< BVec2 > binNot( MaybeOptional< BVec2 > const & x );
	SDW_API MaybeOptional< BVec3 > binNot( MaybeOptional< BVec3 > const & x );
	SDW_API MaybeOptional< BVec4 > binNot( MaybeOptional< BVec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region uaddCarry
	/**
	*name
	*	uaddCarry
	*/
	/**@{*/
	SDW_API MaybeOptional< UInt > uaddCarry( MaybeOptional< UInt > const & x, MaybeOptional< UInt > const & y, MaybeOptional< UInt > const & carry );
	SDW_API MaybeOptional< UVec2 > uaddCarry( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & y, MaybeOptional< UVec2 > const & carry );
	SDW_API MaybeOptional< UVec3 > uaddCarry( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & y, MaybeOptional< UVec3 > const & carry );
	SDW_API MaybeOptional< UVec4 > uaddCarry( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & y, MaybeOptional< UVec4 > const & carry );
	/**@}*/
#pragma endregion
#pragma region usubBorrow
	/**
	*name
	*	usubBorrow
	*/
	/**@{*/
	SDW_API MaybeOptional< UInt > usubBorrow( MaybeOptional< UInt > const & x, MaybeOptional< UInt > const & y, MaybeOptional< UInt > const & borrow );
	SDW_API MaybeOptional< UVec2 > usubBorrow( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & y, MaybeOptional< UVec2 > const & borrow );
	SDW_API MaybeOptional< UVec3 > usubBorrow( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & y, MaybeOptional< UVec3 > const & borrow );
	SDW_API MaybeOptional< UVec4 > usubBorrow( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & y, MaybeOptional< UVec4 > const & borrow );
	/**@}*/
#pragma endregion
#pragma region umulExtended
	/**
	*name
	*	umulExtended
	*/
	/**@{*/
	SDW_API MaybeOptional< Void > umulExtended( MaybeOptional< UInt > const & x, MaybeOptional< UInt > const & y, MaybeOptional< UInt > const & msb, MaybeOptional< UInt > const & lsb );
	SDW_API MaybeOptional< Void > umulExtended( MaybeOptional< UVec2 > const & x, MaybeOptional< UVec2 > const & y, MaybeOptional< UVec2 > const & msb, MaybeOptional< UVec2 > const & lsb );
	SDW_API MaybeOptional< Void > umulExtended( MaybeOptional< UVec3 > const & x, MaybeOptional< UVec3 > const & y, MaybeOptional< UVec3 > const & msb, MaybeOptional< UVec3 > const & lsb );
	SDW_API MaybeOptional< Void > umulExtended( MaybeOptional< UVec4 > const & x, MaybeOptional< UVec4 > const & y, MaybeOptional< UVec4 > const & msb, MaybeOptional< UVec4 > const & lsb );
	/**@}*/
#pragma endregion
#pragma region imulExtended
	/**
	*name
	*	imulExtended
	*/
	/**@{*/
	SDW_API MaybeOptional< Void > imulExtended( MaybeOptional< Int > const & x, MaybeOptional< Int > const & y, MaybeOptional< Int > const & msb, MaybeOptional< Int > const & lsb );
	SDW_API MaybeOptional< Void > imulExtended( MaybeOptional< IVec2 > const & x, MaybeOptional< IVec2 > const & y, MaybeOptional< IVec2 > const & msb, MaybeOptional< IVec2 > const & lsb );
	SDW_API MaybeOptional< Void > imulExtended( MaybeOptional< IVec3 > const & x, MaybeOptional< IVec3 > const & y, MaybeOptional< IVec3 > const & msb, MaybeOptional< IVec3 > const & lsb );
	SDW_API MaybeOptional< Void > imulExtended( MaybeOptional< IVec4 > const & x, MaybeOptional< IVec4 > const & y, MaybeOptional< IVec4 > const & msb, MaybeOptional< IVec4 > const & lsb );
	/**@}*/
#pragma endregion
#pragma region bitfieldExtract
	/**
	*name
	*	bitfieldExtract
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > bitfieldExtract( MaybeOptional< Int > const & value, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< IVec2 > bitfieldExtract( MaybeOptional< IVec2 > const & value, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< IVec3 > bitfieldExtract( MaybeOptional< IVec3 > const & value, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< IVec4 > bitfieldExtract( MaybeOptional< IVec4 > const & value, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< UInt > bitfieldExtract( MaybeOptional< UInt > const & value, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< UVec2 > bitfieldExtract( MaybeOptional< UVec2 > const & value, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< UVec3 > bitfieldExtract( MaybeOptional< UVec3 > const & value, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< UVec4 > bitfieldExtract( MaybeOptional< UVec4 > const & value, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	/**@}*/
#pragma endregion
#pragma region bitfieldInsert
	/**
	*name
	*	bitfieldInsert
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > bitfieldInsert( MaybeOptional< Int > const & base, MaybeOptional< Int > const & insert, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< IVec2 > bitfieldInsert( MaybeOptional< IVec2 > const & base, MaybeOptional< IVec2 > const & insert, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< IVec3 > bitfieldInsert( MaybeOptional< IVec3 > const & base, MaybeOptional< IVec3 > const & insert, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< IVec4 > bitfieldInsert( MaybeOptional< IVec4 > const & base, MaybeOptional< IVec4 > const & insert, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< UInt > bitfieldInsert( MaybeOptional< UInt > const & base, MaybeOptional< UInt > const & insert, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< UVec2 > bitfieldInsert( MaybeOptional< UVec2 > const & base, MaybeOptional< UVec2 > const & insert, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< UVec3 > bitfieldInsert( MaybeOptional< UVec3 > const & base, MaybeOptional< UVec3 > const & insert, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	SDW_API MaybeOptional< UVec4 > bitfieldInsert( MaybeOptional< UVec4 > const & base, MaybeOptional< UVec4 > const & insert, MaybeOptional< Int > const & offset, MaybeOptional< Int > const & bits );
	/**@}*/
#pragma endregion
#pragma region bitfieldReverse
	/**
	*name
	*	bitfieldReverse
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > bitfieldReverse( MaybeOptional< Int > const & value );
	SDW_API MaybeOptional< IVec2 > bitfieldReverse( MaybeOptional< IVec2 > const & value );
	SDW_API MaybeOptional< IVec3 > bitfieldReverse( MaybeOptional< IVec3 > const & value );
	SDW_API MaybeOptional< IVec4 > bitfieldReverse( MaybeOptional< IVec4 > const & value );
	SDW_API MaybeOptional< UInt > bitfieldReverse( MaybeOptional< UInt > const & value );
	SDW_API MaybeOptional< UVec2 > bitfieldReverse( MaybeOptional< UVec2 > const & value );
	SDW_API MaybeOptional< UVec3 > bitfieldReverse( MaybeOptional< UVec3 > const & value );
	SDW_API MaybeOptional< UVec4 > bitfieldReverse( MaybeOptional< UVec4 > const & value );
	/**@}*/
#pragma endregion
#pragma region bitCount
	/**
	*name
	*	bitCount
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > bitCount( MaybeOptional< Int > const & value );
	SDW_API MaybeOptional< IVec2 > bitCount( MaybeOptional< IVec2 > const & value );
	SDW_API MaybeOptional< IVec3 > bitCount( MaybeOptional< IVec3 > const & value );
	SDW_API MaybeOptional< IVec4 > bitCount( MaybeOptional< IVec4 > const & value );
	SDW_API MaybeOptional< UInt > bitCount( MaybeOptional< UInt > const & value );
	SDW_API MaybeOptional< UVec2 > bitCount( MaybeOptional< UVec2 > const & value );
	SDW_API MaybeOptional< UVec3 > bitCount( MaybeOptional< UVec3 > const & value );
	SDW_API MaybeOptional< UVec4 > bitCount( MaybeOptional< UVec4 > const & value );
	/**@}*/
#pragma endregion
#pragma region findLSB
	/**
	*name
	*	findLSB
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > findLSB( MaybeOptional< Int > const & value );
	SDW_API MaybeOptional< IVec2 > findLSB( MaybeOptional< IVec2 > const & value );
	SDW_API MaybeOptional< IVec3 > findLSB( MaybeOptional< IVec3 > const & value );
	SDW_API MaybeOptional< IVec4 > findLSB( MaybeOptional< IVec4 > const & value );
	SDW_API MaybeOptional< Int > findLSB( MaybeOptional< UInt > const & value );
	SDW_API MaybeOptional< IVec2 > findLSB( MaybeOptional< UVec2 > const & value );
	SDW_API MaybeOptional< IVec3 > findLSB( MaybeOptional< UVec3 > const & value );
	SDW_API MaybeOptional< IVec4 > findLSB( MaybeOptional< UVec4 > const & value );
	/**@}*/
#pragma endregion
#pragma region findMSB
	/**
	*name
	*	findMSB
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > findMSB( MaybeOptional< Int > const & value );
	SDW_API MaybeOptional< IVec2 > findMSB( MaybeOptional< IVec2 > const & value );
	SDW_API MaybeOptional< IVec3 > findMSB( MaybeOptional< IVec3 > const & value );
	SDW_API MaybeOptional< IVec4 > findMSB( MaybeOptional< IVec4 > const & value );
	SDW_API MaybeOptional< Int > findMSB( MaybeOptional< UInt > const & value );
	SDW_API MaybeOptional< IVec2 > findMSB( MaybeOptional< UVec2 > const & value );
	SDW_API MaybeOptional< IVec3 > findMSB( MaybeOptional< UVec3 > const & value );
	SDW_API MaybeOptional< IVec4 > findMSB( MaybeOptional< UVec4 > const & value );
	/**@}*/
#pragma endregion
#pragma region atomicAdd
	/**
	*name
	*	atomicAdd
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > atomicAdd( MaybeOptional< Int > const & mem, MaybeOptional< Int > const & data );
	SDW_API MaybeOptional< UInt > atomicAdd( MaybeOptional< UInt > const & mem, MaybeOptional< UInt > const & data );
	/**@}*/
#pragma endregion
#pragma region atomicMin
	/**
	*name
	*	atomicMin
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > atomicMin( MaybeOptional< Int > const & mem, MaybeOptional< Int > const & data );
	SDW_API MaybeOptional< UInt > atomicMin( MaybeOptional< UInt > const & mem, MaybeOptional< UInt > const & data );
	/**@}*/
#pragma endregion
#pragma region atomicMax
	/**
	*name
	*	atomicMax
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > atomicMax( MaybeOptional< Int > const & mem, MaybeOptional< Int > const & data );
	SDW_API MaybeOptional< UInt > atomicMax( MaybeOptional< UInt > const & mem, MaybeOptional< UInt > const & data );
	/**@}*/
#pragma endregion
#pragma region atomicAnd
	/**
	*name
	*	atomicAnd
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > atomicAnd( MaybeOptional< Int > const & mem, MaybeOptional< Int > const & data );
	SDW_API MaybeOptional< UInt > atomicAnd( MaybeOptional< UInt > const & mem, MaybeOptional< UInt > const & data );
	/**@}*/
#pragma endregion
#pragma region atomicOr
	/**
	*name
	*	atomicOr
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > atomicOr( MaybeOptional< Int > const & mem, MaybeOptional< Int > const & data );
	SDW_API MaybeOptional< UInt > atomicOr( MaybeOptional< UInt > const & mem, MaybeOptional< UInt > const & data );
	/**@}*/
#pragma endregion
#pragma region atomicXor
	/**
	*name
	*	atomicXor
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > atomicXor( MaybeOptional< Int > const & mem, MaybeOptional< Int > const & data );
	SDW_API MaybeOptional< UInt > atomicXor( MaybeOptional< UInt > const & mem, MaybeOptional< UInt > const & data );
	/**@}*/
#pragma endregion
#pragma region atomicExchange
	/**
	*name
	*	atomicExchange
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > atomicExchange( MaybeOptional< Int > const & mem, MaybeOptional< Int > const & data );
	SDW_API MaybeOptional< UInt > atomicExchange( MaybeOptional< UInt > const & mem, MaybeOptional< UInt > const & data );
	/**@}*/
#pragma endregion
#pragma region atomicCompSwap
	/**
	*name
	*	atomicCompSwap
	*/
	/**@{*/
	SDW_API MaybeOptional< Int > atomicCompSwap( MaybeOptional< Int > const & mem, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	SDW_API MaybeOptional< UInt > atomicCompSwap( MaybeOptional< UInt > const & mem, MaybeOptional< UInt > const & compare, MaybeOptional< UInt > const & data );
	/**@}*/
#pragma endregion
#pragma region dFdx
	/**
	*name
	*	dFdx
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > dFdx( MaybeOptional< Float > const & p );
	SDW_API MaybeOptional< Vec2 > dFdx( MaybeOptional< Vec2 > const & p );
	SDW_API MaybeOptional< Vec3 > dFdx( MaybeOptional< Vec3 > const & p );
	SDW_API MaybeOptional< Vec4 > dFdx( MaybeOptional< Vec4 > const & p );
	/**@}*/
#pragma endregion
#pragma region dFdxCoarse
	/**
	*name
	*	dFdxCoarse
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > dFdxCoarse( MaybeOptional< Float > const & p );
	SDW_API MaybeOptional< Vec2 > dFdxCoarse( MaybeOptional< Vec2 > const & p );
	SDW_API MaybeOptional< Vec3 > dFdxCoarse( MaybeOptional< Vec3 > const & p );
	SDW_API MaybeOptional< Vec4 > dFdxCoarse( MaybeOptional< Vec4 > const & p );
	/**@}*/
#pragma endregion
#pragma region dFdxFine
	/**
	*name
	*	dFdxFine
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > dFdxFine( MaybeOptional< Float > const & p );
	SDW_API MaybeOptional< Vec2 > dFdxFine( MaybeOptional< Vec2 > const & p );
	SDW_API MaybeOptional< Vec3 > dFdxFine( MaybeOptional< Vec3 > const & p );
	SDW_API MaybeOptional< Vec4 > dFdxFine( MaybeOptional< Vec4 > const & p );
	/**@}*/
#pragma endregion
#pragma region dFdy
	/**
	*name
	*	dFdy
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > dFdy( MaybeOptional< Float > const & p );
	SDW_API MaybeOptional< Vec2 > dFdy( MaybeOptional< Vec2 > const & p );
	SDW_API MaybeOptional< Vec3 > dFdy( MaybeOptional< Vec3 > const & p );
	SDW_API MaybeOptional< Vec4 > dFdy( MaybeOptional< Vec4 > const & p );
	/**@}*/
#pragma endregion
#pragma region dFdyCoarse
	/**
	*name
	*	dFdyCoarse
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > dFdyCoarse( MaybeOptional< Float > const & p );
	SDW_API MaybeOptional< Vec2 > dFdyCoarse( MaybeOptional< Vec2 > const & p );
	SDW_API MaybeOptional< Vec3 > dFdyCoarse( MaybeOptional< Vec3 > const & p );
	SDW_API MaybeOptional< Vec4 > dFdyCoarse( MaybeOptional< Vec4 > const & p );
	/**@}*/
#pragma endregion
#pragma region dFdyFine
	/**
	*name
	*	dFdyFine
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > dFdyFine( MaybeOptional< Float > const & p );
	SDW_API MaybeOptional< Vec2 > dFdyFine( MaybeOptional< Vec2 > const & p );
	SDW_API MaybeOptional< Vec3 > dFdyFine( MaybeOptional< Vec3 > const & p );
	SDW_API MaybeOptional< Vec4 > dFdyFine( MaybeOptional< Vec4 > const & p );
	/**@}*/
#pragma endregion
#pragma region fwidth
	/**
	*name
	*	fwidth
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > fwidth( MaybeOptional< Float > const & p );
	SDW_API MaybeOptional< Vec2 > fwidth( MaybeOptional< Vec2 > const & p );
	SDW_API MaybeOptional< Vec3 > fwidth( MaybeOptional< Vec3 > const & p );
	SDW_API MaybeOptional< Vec4 > fwidth( MaybeOptional< Vec4 > const & p );
	/**@}*/
#pragma endregion
#pragma region interpolateAtCentroid
	/**
	*name
	*	interpolateAtCentroid
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > interpolateAtCentroid( MaybeOptional< Float > const & x );
	SDW_API MaybeOptional< Vec2 > interpolateAtCentroid( MaybeOptional< Vec2 > const & x );
	SDW_API MaybeOptional< Vec3 > interpolateAtCentroid( MaybeOptional< Vec3 > const & x );
	SDW_API MaybeOptional< Vec4 > interpolateAtCentroid( MaybeOptional< Vec4 > const & x );
	/**@}*/
#pragma endregion
#pragma region interpolateAtSample
	/**
	*name
	*	interpolateAtSample
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > interpolateAtSample( MaybeOptional< Float > const & interpolant, MaybeOptional< Int > const & sample );
	SDW_API MaybeOptional< Vec2 > interpolateAtSample( MaybeOptional< Vec2 > const & interpolant, MaybeOptional< Int > const & sample );
	SDW_API MaybeOptional< Vec3 > interpolateAtSample( MaybeOptional< Vec3 > const & interpolant, MaybeOptional< Int > const & sample );
	SDW_API MaybeOptional< Vec4 > interpolateAtSample( MaybeOptional< Vec4 > const & interpolant, MaybeOptional< Int > const & sample );
	/**@}*/
#pragma endregion
#pragma region interpolateAtOffset
	/**
	*name
	*	interpolateAtOffset
	*/
	/**@{*/
	SDW_API MaybeOptional< Float > interpolateAtOffset( MaybeOptional< Float > const & interpolant, MaybeOptional< Vec2 > const & offset );
	SDW_API MaybeOptional< Vec2 > interpolateAtOffset( MaybeOptional< Vec2 > const & interpolant, MaybeOptional< Vec2 > const & offset );
	SDW_API MaybeOptional< Vec3 > interpolateAtOffset( MaybeOptional< Vec3 > const & interpolant, MaybeOptional< Vec2 > const & offset );
	SDW_API MaybeOptional< Vec4 > interpolateAtOffset( MaybeOptional< Vec4 > const & interpolant, MaybeOptional< Vec2 > const & offset );
	/**@}*/
#pragma endregion
#pragma region EmitStreamVertex
	/**
	*name
	*	EmitStreamVertex
	*/
	/**@{*/
	SDW_API MaybeOptional< Void > EmitStreamVertex( MaybeOptional< Int > const & stream );
	/**@}*/
#pragma endregion
#pragma region EndStreamPrimitive
	/**
	*name
	*	EndStreamPrimitive
	*/
	/**@{*/
	SDW_API MaybeOptional< Void > EndStreamPrimitive( MaybeOptional< Int > const & stream );
	/**@}*/
#pragma endregion
#pragma region EmitVertex
	/**
	*name
	*	EmitVertex
	*/
	/**@{*/
	SDW_API MaybeOptional< Void > EmitVertex( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region EndPrimitive
	/**
	*name
	*	EndPrimitive
	*/
	/**@{*/
	SDW_API MaybeOptional< Void > EndPrimitive( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region barrier
	/**
	*name
	*	barrier
	*/
	/**@{*/
	SDW_API MaybeOptional< Void > barrier( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region memoryBarrier
	/**
	*name
	*	memoryBarrier
	*/
	/**@{*/
	SDW_API MaybeOptional< UInt > memoryBarrier( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region memoryBarrierBuffer
	/**
	*name
	*	memoryBarrierBuffer
	*/
	/**@{*/
	SDW_API MaybeOptional< Void > memoryBarrierBuffer( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region memoryBarrierShared
	/**
	*name
	*	memoryBarrierShared
	*/
	/**@{*/
	SDW_API MaybeOptional< Void > memoryBarrierShared( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region memoryBarrierImage
	/**
	*name
	*	memoryBarrierImage
	*/
	/**@{*/
	SDW_API MaybeOptional< Void > memoryBarrierImage( ShaderWriter & writer );
	/**@}*/
#pragma endregion
#pragma region groupMemoryBarrier
	/**
	*name
	*	groupMemoryBarrier
	*/
	/**@{*/
	SDW_API MaybeOptional< Void > groupMemoryBarrier( ShaderWriter & writer );
	/**@}*/
#pragma endregion
}

#endif
