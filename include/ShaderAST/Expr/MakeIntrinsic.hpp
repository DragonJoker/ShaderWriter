/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMakeIntrinsic_H___
#define ___AST_ExprMakeIntrinsic_H___
#pragma once

#include "ExprIntrinsicCall.hpp"

namespace ast::expr
{	// Angle and Trigonometry Functions

	/**
	*@return
	*	float
	*@param radians
	*	float
	*/
	IntrinsicCallPtr makeDegrees1( type::TypesCache & cache, ExprPtr radians );
	/**
	*@return
	*	vec2f
	*@param radians
	*	vec2f
	*/
	IntrinsicCallPtr makeDegrees2( type::TypesCache & cache, ExprPtr radians );
	/**
	*@return
	*	vec3f
	*@param radians
	*	vec3f
	*/
	IntrinsicCallPtr makeDegrees3( type::TypesCache & cache, ExprPtr radians );
	/**
	*@return
	*	vec4f
	*@param radians
	*	vec4f
	*/
	IntrinsicCallPtr makeDegrees4( type::TypesCache & cache, ExprPtr radians );
	/**
	*@return
	*	float
	*@param degrees
	*	float
	*/
	IntrinsicCallPtr makeRadians1F( type::TypesCache & cache, ExprPtr degrees );
	/**
	*@return
	*	vec2f
	*@param degrees
	*	vec2f
	*/
	IntrinsicCallPtr makeRadians2F( type::TypesCache & cache, ExprPtr degrees );
	/**
	*@return
	*	vec3f
	*@param degrees
	*	vec3f
	*/
	IntrinsicCallPtr makeRadians3F( type::TypesCache & cache, ExprPtr degrees );
	/**
	*@return
	*	vec4f
	*@param degrees
	*	vec4f
	*/
	IntrinsicCallPtr makeRadians4F( type::TypesCache & cache, ExprPtr degrees );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeCos1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeCos2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeCos3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeCos4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeSin1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeSin2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeSin3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeSin4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeTan1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeTan2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeTan3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeTan4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeCosh1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeCosh2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeCosh3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeCosh4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeSinh1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeSinh2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeSinh3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeSinh4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeTanh1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeTanh2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeTanh3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeTanh4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAcos1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAcos2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAcos3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAcos4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAsin1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAsin2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAsin3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAsin4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param y_over_x
	*	float
	*/
	IntrinsicCallPtr makeAtan1( type::TypesCache & cache, ExprPtr y_over_x );
	/**
	*@return
	*	vec2f
	*@param y_over_x
	*	vec2f
	*/
	IntrinsicCallPtr makeAtan2( type::TypesCache & cache, ExprPtr y_over_x );
	/**
	*@return
	*	vec3f
	*@param y_over_x
	*	vec3f
	*/
	IntrinsicCallPtr makeAtan3( type::TypesCache & cache, ExprPtr y_over_x );
	/**
	*@return
	*	vec4f
	*@param y_over_x
	*	vec4f
	*/
	IntrinsicCallPtr makeAtan4( type::TypesCache & cache, ExprPtr y_over_x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAcosh1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAcosh2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAcosh3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAcosh4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAsinh1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAsinh2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAsinh3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAsinh4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAtanh1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAtanh2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAtanh3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAtanh4( type::TypesCache & cache, ExprPtr x );
	// Exponential Functions

	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*/
	IntrinsicCallPtr makePow1( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makePow2( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makePow3( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makePow4( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeExp1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeExp2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeExp3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeExp4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeLog1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeLog2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeLog3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeLog4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeExp21( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeExp22( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeExp23( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeExp24( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeLog21( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeLog22( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeLog23( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeLog24( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeSqrt1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeSqrt2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeSqrt3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeSqrt4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeSqrt1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeSqrt2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeSqrt3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeSqrt4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeInverseSqrt1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeInverseSqrt2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeInverseSqrt3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeInverseSqrt4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeInverseSqrt1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeInverseSqrt2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeInverseSqrt3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeInverseSqrt4D( type::TypesCache & cache, ExprPtr x );
	// Common Functions

	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAbs1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAbs2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAbs3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAbs4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	int
	*@param x
	*	int
	*/
	IntrinsicCallPtr makeAbs1I( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*/
	IntrinsicCallPtr makeAbs2I( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*/
	IntrinsicCallPtr makeAbs3I( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*/
	IntrinsicCallPtr makeAbs4I( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeAbs1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeAbs2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeAbs3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeAbs4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeSign1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeSign2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeSign3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeSign4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	int
	*@param x
	*	int
	*/
	IntrinsicCallPtr makeSign1I( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*/
	IntrinsicCallPtr makeSign2I( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*/
	IntrinsicCallPtr makeSign3I( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*/
	IntrinsicCallPtr makeSign4I( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeSign1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeSign2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeSign3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeSign4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeFloor1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeFloor2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeFloor3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeFloor4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeFloor1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeFloor2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeFloor3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeFloor4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeTrunc1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeTrunc2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeTrunc3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeTrunc4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeTrunc1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeTrunc2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeTrunc3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeTrunc4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeRound1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeRound2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeRound3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeRound4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeRound1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeRound2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeRound3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeRound4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeRoundEven1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeRoundEven2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeRoundEven3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeRoundEven4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeRoundEven1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeRoundEven2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeRoundEven3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeRoundEven4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeCeil1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeCeil2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeCeil3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeCeil4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeCeil1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeCeil2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeCeil3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeCeil4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeFract1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeFract2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeFract3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeFract4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeFract1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeFract2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeFract3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeFract4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMod11F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeMod22F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeMod33F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeMod44F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMod21F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMod31F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMod41F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMod11D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeMod22D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeMod33D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeMod44D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMod21D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMod31D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMod41D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param i
	*	float
	*/
	IntrinsicCallPtr makeModf1F( type::TypesCache & cache, ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param i
	*	vec2f
	*/
	IntrinsicCallPtr makeModf2F( type::TypesCache & cache, ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param i
	*	vec3f
	*/
	IntrinsicCallPtr makeModf3F( type::TypesCache & cache, ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param i
	*	vec4f
	*/
	IntrinsicCallPtr makeModf4F( type::TypesCache & cache, ExprPtr x, ExprPtr i );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param i
	*	double
	*/
	IntrinsicCallPtr makeModf1D( type::TypesCache & cache, ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param i
	*	vec2d
	*/
	IntrinsicCallPtr makeModf2D( type::TypesCache & cache, ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param i
	*	vec3d
	*/
	IntrinsicCallPtr makeModf3D( type::TypesCache & cache, ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param i
	*	vec4d
	*/
	IntrinsicCallPtr makeModf4D( type::TypesCache & cache, ExprPtr x, ExprPtr i );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMin11F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeMin22F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeMin33F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeMin44F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMin21F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMin31F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMin41F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMin11D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeMin22D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeMin33D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeMin44D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMin21D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMin31D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMin41D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	int
	*@param x
	*	int
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMin11I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeMin22I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeMin33I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeMin44I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMin21I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMin31I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMin41I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	uint
	*@param x
	*	uint
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMin11U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeMin22U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeMin33U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeMin44U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMin21U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMin31U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMin41U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMax11F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeMax22F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeMax33F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeMax44F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMax21F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMax31F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMax41F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMax11D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeMax22D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeMax33D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeMax44D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMax21D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMax31D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMax41D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	int
	*@param x
	*	int
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMax11I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeMax22I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeMax33I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeMax44I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMax21I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMax31I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMax41I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	uint
	*@param x
	*	uint
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMax11U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeMax22U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeMax33U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeMax44U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMax21U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMax31U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMax41U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param minVal
	*	float
	*@param maxVal
	*	float
	*/
	IntrinsicCallPtr makeClamp11F( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param minVal
	*	vec2f
	*@param maxVal
	*	vec2f
	*/
	IntrinsicCallPtr makeClamp22F( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param minVal
	*	vec3f
	*@param maxVal
	*	vec3f
	*/
	IntrinsicCallPtr makeClamp33F( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param minVal
	*	vec4f
	*@param maxVal
	*	vec4f
	*/
	IntrinsicCallPtr makeClamp44F( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param minVal
	*	float
	*@param maxVal
	*	float
	*/
	IntrinsicCallPtr makeClamp21F( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param minVal
	*	float
	*@param maxVal
	*	float
	*/
	IntrinsicCallPtr makeClamp31F( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param minVal
	*	float
	*@param maxVal
	*	float
	*/
	IntrinsicCallPtr makeClamp41F( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param minVal
	*	double
	*@param maxVal
	*	double
	*/
	IntrinsicCallPtr makeClamp11D( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param minVal
	*	vec2d
	*@param maxVal
	*	vec2d
	*/
	IntrinsicCallPtr makeClamp22D( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param minVal
	*	vec3d
	*@param maxVal
	*	vec3d
	*/
	IntrinsicCallPtr makeClamp33D( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param minVal
	*	vec4d
	*@param maxVal
	*	vec4d
	*/
	IntrinsicCallPtr makeClamp44D( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param minVal
	*	double
	*@param maxVal
	*	double
	*/
	IntrinsicCallPtr makeClamp21D( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param minVal
	*	double
	*@param maxVal
	*	double
	*/
	IntrinsicCallPtr makeClamp31D( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param minVal
	*	double
	*@param maxVal
	*	double
	*/
	IntrinsicCallPtr makeClamp41D( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	int
	*@param x
	*	int
	*@param minVal
	*	int
	*@param maxVal
	*	int
	*/
	IntrinsicCallPtr makeClamp11I( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*@param minVal
	*	vec2i
	*@param maxVal
	*	vec2i
	*/
	IntrinsicCallPtr makeClamp22I( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*@param minVal
	*	vec3i
	*@param maxVal
	*	vec3i
	*/
	IntrinsicCallPtr makeClamp33I( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*@param minVal
	*	vec4i
	*@param maxVal
	*	vec4i
	*/
	IntrinsicCallPtr makeClamp44I( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*@param minVal
	*	int
	*@param maxVal
	*	int
	*/
	IntrinsicCallPtr makeClamp21I( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*@param minVal
	*	int
	*@param maxVal
	*	int
	*/
	IntrinsicCallPtr makeClamp31I( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*@param minVal
	*	int
	*@param maxVal
	*	int
	*/
	IntrinsicCallPtr makeClamp41I( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	uint
	*@param x
	*	uint
	*@param minVal
	*	uint
	*@param maxVal
	*	uint
	*/
	IntrinsicCallPtr makeClamp11U( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param minVal
	*	vec2u
	*@param maxVal
	*	vec2u
	*/
	IntrinsicCallPtr makeClamp22U( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param minVal
	*	vec3u
	*@param maxVal
	*	vec3u
	*/
	IntrinsicCallPtr makeClamp33U( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param minVal
	*	vec4u
	*@param maxVal
	*	vec4u
	*/
	IntrinsicCallPtr makeClamp44U( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param minVal
	*	uint
	*@param maxVal
	*	uint
	*/
	IntrinsicCallPtr makeClamp21U( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param minVal
	*	uint
	*@param maxVal
	*	uint
	*/
	IntrinsicCallPtr makeClamp31U( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param minVal
	*	uint
	*@param maxVal
	*	uint
	*/
	IntrinsicCallPtr makeClamp41U( type::TypesCache & cache, ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*@param a
	*	float
	*/
	IntrinsicCallPtr makeMix11F( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*@param a
	*	vec2f
	*/
	IntrinsicCallPtr makeMix22F( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*@param a
	*	vec3f
	*/
	IntrinsicCallPtr makeMix33F( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*@param a
	*	vec4f
	*/
	IntrinsicCallPtr makeMix44F( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*@param a
	*	float
	*/
	IntrinsicCallPtr makeMix21F( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*@param a
	*	float
	*/
	IntrinsicCallPtr makeMix31F( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*@param a
	*	float
	*/
	IntrinsicCallPtr makeMix41F( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*@param a
	*	bool
	*/
	IntrinsicCallPtr makeMix11FB( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*@param a
	*	vec2b
	*/
	IntrinsicCallPtr makeMix22FB( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*@param a
	*	vec3b
	*/
	IntrinsicCallPtr makeMix33FB( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*@param a
	*	vec4b
	*/
	IntrinsicCallPtr makeMix44FB( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param y
	*	double
	*@param a
	*	double
	*/
	IntrinsicCallPtr makeMix11D( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*@param a
	*	vec2d
	*/
	IntrinsicCallPtr makeMix22D( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*@param a
	*	vec3d
	*/
	IntrinsicCallPtr makeMix33D( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*@param a
	*	vec4d
	*/
	IntrinsicCallPtr makeMix44D( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*@param a
	*	double
	*/
	IntrinsicCallPtr makeMix21D( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*@param a
	*	double
	*/
	IntrinsicCallPtr makeMix31D( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*@param a
	*	double
	*/
	IntrinsicCallPtr makeMix41D( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param y
	*	double
	*@param a
	*	bool
	*/
	IntrinsicCallPtr makeMix11DB( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*@param a
	*	vec2b
	*/
	IntrinsicCallPtr makeMix22DB( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*@param a
	*	vec3b
	*/
	IntrinsicCallPtr makeMix33DB( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*@param a
	*	vec4b
	*/
	IntrinsicCallPtr makeMix44DB( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	float
	*@param edge
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeStep11F( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param edge
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeStep22F( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param edge
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeStep33F( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param edge
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeStep44F( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param edge
	*	float
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeStep12F( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param edge
	*	float
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeStep13F( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param edge
	*	float
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeStep14F( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	double
	*@param edge
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeStep11D( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param edge
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeStep22D( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param edge
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeStep33D( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param edge
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeStep44D( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param edge
	*	double
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeStep12D( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param edge
	*	double
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeStep13D( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param edge
	*	double
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeStep14D( type::TypesCache & cache, ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	float
	*@param edge0
	*	float
	*@param edge1
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeSmoothStep11F( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param edge0
	*	vec2f
	*@param edge1
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeSmoothStep22F( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param edge0
	*	vec3f
	*@param edge1
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeSmoothStep33F( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param edge0
	*	vec4f
	*@param edge1
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeSmoothStep44F( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param edge0
	*	float
	*@param edge1
	*	float
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeSmoothStep12F( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param edge0
	*	float
	*@param edge1
	*	float
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeSmoothStep13F( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param edge0
	*	float
	*@param edge1
	*	float
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeSmoothStep14F( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	double
	*@param edge0
	*	double
	*@param edge1
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeSmoothStep11D( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param edge0
	*	vec2d
	*@param edge1
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeSmoothStep22D( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param edge0
	*	vec3d
	*@param edge1
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeSmoothStep33D( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param edge0
	*	vec4d
	*@param edge1
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeSmoothStep44D( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param edge0
	*	double
	*@param edge1
	*	double
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeSmoothStep12D( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param edge0
	*	double
	*@param edge1
	*	double
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeSmoothStep13D( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param edge0
	*	double
	*@param edge1
	*	double
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeSmoothStep14D( type::TypesCache & cache, ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	bool
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeIsnan1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeIsnan2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeIsnan3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeIsnan4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	bool
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeIsnan1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeIsnan2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeIsnan3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeIsnan4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	bool
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeIsinf1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeIsinf2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeIsinf3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeIsinf4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	bool
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeIsinf1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeIsinf2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeIsinf3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeIsinf4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	int
	*@param value
	*	float
	*/
	IntrinsicCallPtr makeFloatBitsToInt1( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2f
	*/
	IntrinsicCallPtr makeFloatBitsToInt2( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3f
	*/
	IntrinsicCallPtr makeFloatBitsToInt3( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4f
	*/
	IntrinsicCallPtr makeFloatBitsToInt4( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	uint
	*@param value
	*	float
	*/
	IntrinsicCallPtr makeFloatBitsToUInt1( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec2u
	*@param value
	*	vec2f
	*/
	IntrinsicCallPtr makeFloatBitsToUInt2( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec3u
	*@param value
	*	vec3f
	*/
	IntrinsicCallPtr makeFloatBitsToUInt3( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec4u
	*@param value
	*	vec4f
	*/
	IntrinsicCallPtr makeFloatBitsToUInt4( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	float
	*@param x
	*	int
	*/
	IntrinsicCallPtr makeIntBitsToFloat1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2i
	*/
	IntrinsicCallPtr makeIntBitsToFloat2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3i
	*/
	IntrinsicCallPtr makeIntBitsToFloat3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4i
	*/
	IntrinsicCallPtr makeIntBitsToFloat4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	uint
	*/
	IntrinsicCallPtr makeUintBitsToFloat1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2u
	*/
	IntrinsicCallPtr makeUintBitsToFloat2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3u
	*/
	IntrinsicCallPtr makeUintBitsToFloat3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4u
	*/
	IntrinsicCallPtr makeUintBitsToFloat4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param a
	*	float
	*@param b
	*	float
	*@param c
	*	float
	*/
	IntrinsicCallPtr makeFma1F( type::TypesCache & cache, ExprPtr a, ExprPtr b, ExprPtr c );
	/**
	*@return
	*	vec2f
	*@param a
	*	vec2f
	*@param b
	*	vec2f
	*@param c
	*	vec2f
	*/
	IntrinsicCallPtr makeFma2F( type::TypesCache & cache, ExprPtr a, ExprPtr b, ExprPtr c );
	/**
	*@return
	*	vec3f
	*@param a
	*	vec3f
	*@param b
	*	vec3f
	*@param c
	*	vec3f
	*/
	IntrinsicCallPtr makeFma3F( type::TypesCache & cache, ExprPtr a, ExprPtr b, ExprPtr c );
	/**
	*@return
	*	vec4f
	*@param a
	*	vec4f
	*@param b
	*	vec4f
	*@param c
	*	vec4f
	*/
	IntrinsicCallPtr makeFma4F( type::TypesCache & cache, ExprPtr a, ExprPtr b, ExprPtr c );
	/**
	*@return
	*	double
	*@param a
	*	double
	*@param b
	*	double
	*@param c
	*	double
	*/
	IntrinsicCallPtr makeFma1D( type::TypesCache & cache, ExprPtr a, ExprPtr b, ExprPtr c );
	/**
	*@return
	*	vec2d
	*@param a
	*	vec2d
	*@param b
	*	vec2d
	*@param c
	*	vec2d
	*/
	IntrinsicCallPtr makeFma2D( type::TypesCache & cache, ExprPtr a, ExprPtr b, ExprPtr c );
	/**
	*@return
	*	vec3d
	*@param a
	*	vec3d
	*@param b
	*	vec3d
	*@param c
	*	vec3d
	*/
	IntrinsicCallPtr makeFma3D( type::TypesCache & cache, ExprPtr a, ExprPtr b, ExprPtr c );
	/**
	*@return
	*	vec4d
	*@param a
	*	vec4d
	*@param b
	*	vec4d
	*@param c
	*	vec4d
	*/
	IntrinsicCallPtr makeFma4D( type::TypesCache & cache, ExprPtr a, ExprPtr b, ExprPtr c );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param exp
	*	int
	*/
	IntrinsicCallPtr makeFrexp1F( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param exp
	*	vec2i
	*/
	IntrinsicCallPtr makeFrexp2F( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param exp
	*	vec3i
	*/
	IntrinsicCallPtr makeFrexp3F( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param exp
	*	vec4i
	*/
	IntrinsicCallPtr makeFrexp4F( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param exp
	*	int
	*/
	IntrinsicCallPtr makeFrexp1D( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param exp
	*	vec2i
	*/
	IntrinsicCallPtr makeFrexp2D( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param exp
	*	vec3i
	*/
	IntrinsicCallPtr makeFrexp3D( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param exp
	*	vec4i
	*/
	IntrinsicCallPtr makeFrexp4D( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param exp
	*	int
	*/
	IntrinsicCallPtr makeLdexp1F( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param exp
	*	vec2i
	*/
	IntrinsicCallPtr makeLdexp2F( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param exp
	*	vec3i
	*/
	IntrinsicCallPtr makeLdexp3F( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param exp
	*	vec4i
	*/
	IntrinsicCallPtr makeLdexp4F( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param exp
	*	int
	*/
	IntrinsicCallPtr makeLdexp1D( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param exp
	*	vec2i
	*/
	IntrinsicCallPtr makeLdexp2D( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param exp
	*	vec3i
	*/
	IntrinsicCallPtr makeLdexp3D( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param exp
	*	vec4i
	*/
	IntrinsicCallPtr makeLdexp4D( type::TypesCache & cache, ExprPtr x, ExprPtr exp );
	// Floating-point Pack and Unpack Functions

	/**
	*@return
	*	double
	*@param v
	*	vec2u
	*/
	IntrinsicCallPtr makePackDouble2x32( type::TypesCache & cache, ExprPtr v );
	/**
	*@return
	*	uint
	*@param v
	*	vec2f
	*/
	IntrinsicCallPtr makePackHalf2x16( type::TypesCache & cache, ExprPtr v );
	/**
	*@return
	*	uint
	*@param v
	*	vec2f
	*/
	IntrinsicCallPtr makePackSnorm2x16( type::TypesCache & cache, ExprPtr v );
	/**
	*@return
	*	uint
	*@param v
	*	vec4f
	*/
	IntrinsicCallPtr makePackSnorm4x8( type::TypesCache & cache, ExprPtr v );
	/**
	*@return
	*	uint
	*@param v
	*	vec2f
	*/
	IntrinsicCallPtr makePackUnorm2x16( type::TypesCache & cache, ExprPtr v );
	/**
	*@return
	*	uint
	*@param v
	*	vec4f
	*/
	IntrinsicCallPtr makePackUnorm4x8( type::TypesCache & cache, ExprPtr v );
	/**
	*@return
	*	vec2u
	*@param d
	*	double
	*/
	IntrinsicCallPtr makeUnpackDouble2x32( type::TypesCache & cache, ExprPtr d );
	/**
	*@return
	*	vec2f
	*@param v
	*	uint
	*/
	IntrinsicCallPtr makeUnpackHalf2x16( type::TypesCache & cache, ExprPtr v );
	/**
	*@return
	*	vec2f
	*@param p
	*	uint
	*/
	IntrinsicCallPtr makeUnpackSnorm2x16( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	uint
	*/
	IntrinsicCallPtr makeUnpackSnorm4x8( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	uint
	*/
	IntrinsicCallPtr makeUnpackUnorm2x16( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	uint
	*/
	IntrinsicCallPtr makeUnpackUnorm4x8( type::TypesCache & cache, ExprPtr p );
	// Geometric Functions

	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeLength1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeLength2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeLength3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeLength4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeLength1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeLength2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeLength3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeLength4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param p0
	*	float
	*@param p1
	*	float
	*/
	IntrinsicCallPtr makeDistance1F( type::TypesCache & cache, ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	vec2f
	*@param p0
	*	vec2f
	*@param p1
	*	vec2f
	*/
	IntrinsicCallPtr makeDistance2F( type::TypesCache & cache, ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	vec3f
	*@param p0
	*	vec3f
	*@param p1
	*	vec3f
	*/
	IntrinsicCallPtr makeDistance3F( type::TypesCache & cache, ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	vec4f
	*@param p0
	*	vec4f
	*@param p1
	*	vec4f
	*/
	IntrinsicCallPtr makeDistance4F( type::TypesCache & cache, ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	double
	*@param p0
	*	double
	*@param p1
	*	double
	*/
	IntrinsicCallPtr makeDistance1D( type::TypesCache & cache, ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	double
	*@param p0
	*	vec2d
	*@param p1
	*	vec2d
	*/
	IntrinsicCallPtr makeDistance2D( type::TypesCache & cache, ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	double
	*@param p0
	*	vec3d
	*@param p1
	*	vec3d
	*/
	IntrinsicCallPtr makeDistance3D( type::TypesCache & cache, ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	double
	*@param p0
	*	vec4d
	*@param p1
	*	vec4d
	*/
	IntrinsicCallPtr makeDistance4D( type::TypesCache & cache, ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeDot1F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeDot2F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeDot3F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeDot4F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeDot1D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeDot2D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeDot3D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeDot4D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeCrossF( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeCrossD( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeNormalize1F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeNormalize2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeNormalize3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeNormalize4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeNormalize1D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeNormalize2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeNormalize3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeNormalize4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param N
	*	float
	*@param I
	*	float
	*@param Nref
	*	float
	*/
	IntrinsicCallPtr makeFaceForward1F( type::TypesCache & cache, ExprPtr N, ExprPtr I, ExprPtr Nref );
	/**
	*@return
	*	vec2f
	*@param N
	*	vec2f
	*@param I
	*	vec2f
	*@param Nref
	*	vec2f
	*/
	IntrinsicCallPtr makeFaceForward2F( type::TypesCache & cache, ExprPtr N, ExprPtr I, ExprPtr Nref );
	/**
	*@return
	*	vec3f
	*@param N
	*	vec3f
	*@param I
	*	vec3f
	*@param Nref
	*	vec3f
	*/
	IntrinsicCallPtr makeFaceForward3F( type::TypesCache & cache, ExprPtr N, ExprPtr I, ExprPtr Nref );
	/**
	*@return
	*	vec4f
	*@param N
	*	vec4f
	*@param I
	*	vec4f
	*@param Nref
	*	vec4f
	*/
	IntrinsicCallPtr makeFaceForward4F( type::TypesCache & cache, ExprPtr N, ExprPtr I, ExprPtr Nref );
	/**
	*@return
	*	double
	*@param N
	*	double
	*@param I
	*	double
	*@param Nref
	*	double
	*/
	IntrinsicCallPtr makeFaceForward1D( type::TypesCache & cache, ExprPtr N, ExprPtr I, ExprPtr Nref );
	/**
	*@return
	*	vec2d
	*@param N
	*	vec2d
	*@param I
	*	vec2d
	*@param Nref
	*	vec2d
	*/
	IntrinsicCallPtr makeFaceForward2D( type::TypesCache & cache, ExprPtr N, ExprPtr I, ExprPtr Nref );
	/**
	*@return
	*	vec3d
	*@param N
	*	vec3d
	*@param I
	*	vec3d
	*@param Nref
	*	vec3d
	*/
	IntrinsicCallPtr makeFaceForward3D( type::TypesCache & cache, ExprPtr N, ExprPtr I, ExprPtr Nref );
	/**
	*@return
	*	vec4d
	*@param N
	*	vec4d
	*@param I
	*	vec4d
	*@param Nref
	*	vec4d
	*/
	IntrinsicCallPtr makeFaceForward4D( type::TypesCache & cache, ExprPtr N, ExprPtr I, ExprPtr Nref );
	/**
	*@return
	*	float
	*@param I
	*	float
	*@param N
	*	float
	*/
	IntrinsicCallPtr makeReflect1F( type::TypesCache & cache, ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec2f
	*@param I
	*	vec2f
	*@param N
	*	vec2f
	*/
	IntrinsicCallPtr makeReflect2F( type::TypesCache & cache, ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec3f
	*@param I
	*	vec3f
	*@param N
	*	vec3f
	*/
	IntrinsicCallPtr makeReflect3F( type::TypesCache & cache, ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec4f
	*@param I
	*	vec4f
	*@param N
	*	vec4f
	*/
	IntrinsicCallPtr makeReflect4F( type::TypesCache & cache, ExprPtr I, ExprPtr N );
	/**
	*@return
	*	double
	*@param I
	*	float
	*@param N
	*	double
	*/
	IntrinsicCallPtr makeReflect1D( type::TypesCache & cache, ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec2d
	*@param I
	*	vec2d
	*@param N
	*	vec2d
	*/
	IntrinsicCallPtr makeReflect2D( type::TypesCache & cache, ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec3d
	*@param I
	*	vec3d
	*@param N
	*	vec3d
	*/
	IntrinsicCallPtr makeReflect3D( type::TypesCache & cache, ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec4d
	*@param I
	*	vec4d
	*@param N
	*	vec4d
	*/
	IntrinsicCallPtr makeReflect4D( type::TypesCache & cache, ExprPtr I, ExprPtr N );
	/**
	*@return
	*	float
	*@param I
	*	float
	*@param N
	*	float
	*@param eta
	*	float
	*/
	IntrinsicCallPtr makeRefract1F( type::TypesCache & cache, ExprPtr I, ExprPtr N, ExprPtr eta );
	/**
	*@return
	*	vec2f
	*@param I
	*	vec2f
	*@param N
	*	vec2f
	*@param eta
	*	float
	*/
	IntrinsicCallPtr makeRefract2F( type::TypesCache & cache, ExprPtr I, ExprPtr N, ExprPtr eta );
	/**
	*@return
	*	vec3f
	*@param I
	*	vec3f
	*@param N
	*	vec3f
	*@param eta
	*	float
	*/
	IntrinsicCallPtr makeRefract3F( type::TypesCache & cache, ExprPtr I, ExprPtr N, ExprPtr eta );
	/**
	*@return
	*	vec4f
	*@param I
	*	vec4f
	*@param N
	*	vec4f
	*@param eta
	*	float
	*/
	IntrinsicCallPtr makeRefract4F( type::TypesCache & cache, ExprPtr I, ExprPtr N, ExprPtr eta );
	/**
	*@return
	*	double
	*@param I
	*	double
	*@param N
	*	double
	*@param eta
	*	float
	*/
	IntrinsicCallPtr makeRefract1D( type::TypesCache & cache, ExprPtr I, ExprPtr N, ExprPtr eta );
	/**
	*@return
	*	vec2d
	*@param I
	*	vec2d
	*@param N
	*	vec2d
	*@param eta
	*	float
	*/
	IntrinsicCallPtr makeRefract2D( type::TypesCache & cache, ExprPtr I, ExprPtr N, ExprPtr eta );
	/**
	*@return
	*	vec3d
	*@param I
	*	vec3d
	*@param N
	*	vec3d
	*@param eta
	*	float
	*/
	IntrinsicCallPtr makeRefract3D( type::TypesCache & cache, ExprPtr I, ExprPtr N, ExprPtr eta );
	/**
	*@return
	*	vec4d
	*@param I
	*	vec4d
	*@param N
	*	vec4d
	*@param eta
	*	float
	*/
	IntrinsicCallPtr makeRefract4D( type::TypesCache & cache, ExprPtr I, ExprPtr N, ExprPtr eta );
	// Matrix Functions

	/**
	*@return
	*	mat2x2f
	*@param x
	*	mat2x2f
	*@param y
	*	mat2x2f
	*/
	IntrinsicCallPtr makeMatrixCompMult2x2F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x3f
	*@param x
	*	mat2x3f
	*@param y
	*	mat2x3f
	*/
	IntrinsicCallPtr makeMatrixCompMult2x3F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x4f
	*@param x
	*	mat2x4f
	*@param y
	*	mat2x4f
	*/
	IntrinsicCallPtr makeMatrixCompMult2x4F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x2f
	*@param x
	*	mat3x2f
	*@param y
	*	mat3x2f
	*/
	IntrinsicCallPtr makeMatrixCompMult3x2F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x3f
	*@param x
	*	mat3x3f
	*@param y
	*	mat3x3f
	*/
	IntrinsicCallPtr makeMatrixCompMult3x3F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x4f
	*@param x
	*	mat3x4f
	*@param y
	*	mat3x4f
	*/
	IntrinsicCallPtr makeMatrixCompMult3x4F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x2f
	*@param x
	*	mat4x2f
	*@param y
	*	mat4x2f
	*/
	IntrinsicCallPtr makeMatrixCompMult4x2F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x3f
	*@param x
	*	mat4x3f
	*@param y
	*	mat4x3f
	*/
	IntrinsicCallPtr makeMatrixCompMult4x3F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x4f
	*@param x
	*	mat4x4f
	*@param y
	*	mat4x4f
	*/
	IntrinsicCallPtr makeMatrixCompMult4x4F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x2d
	*@param x
	*	mat2x2d
	*@param y
	*	mat2x2d
	*/
	IntrinsicCallPtr makeMatrixCompMult2x2D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x3d
	*@param x
	*	mat2x3d
	*@param y
	*	mat2x3d
	*/
	IntrinsicCallPtr makeMatrixCompMult2x3D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x4d
	*@param x
	*	mat2x4d
	*@param y
	*	mat2x4d
	*/
	IntrinsicCallPtr makeMatrixCompMult2x4D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x2d
	*@param x
	*	mat3x2d
	*@param y
	*	mat3x2d
	*/
	IntrinsicCallPtr makeMatrixCompMult3x2D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x3d
	*@param x
	*	mat3x3d
	*@param y
	*	mat3x3d
	*/
	IntrinsicCallPtr makeMatrixCompMult3x3D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x4d
	*@param x
	*	mat3x4d
	*@param y
	*	mat3x4d
	*/
	IntrinsicCallPtr makeMatrixCompMult3x4D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x2d
	*@param x
	*	mat4x2d
	*@param y
	*	mat4x2d
	*/
	IntrinsicCallPtr makeMatrixCompMult4x2D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x3d
	*@param x
	*	mat4x3d
	*@param y
	*	mat4x3d
	*/
	IntrinsicCallPtr makeMatrixCompMult4x3D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x4d
	*@param x
	*	mat4x4d
	*@param y
	*	mat4x4d
	*/
	IntrinsicCallPtr makeMatrixCompMult4x4D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x2f
	*@param c
	*	vec2f
	*@param r
	*	vec2f
	*/
	IntrinsicCallPtr makeOuterProduct2x2F( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x3f
	*@param c
	*	vec3f
	*@param r
	*	vec3f
	*/
	IntrinsicCallPtr makeOuterProduct3x3F( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x4f
	*@param c
	*	vec4f
	*@param r
	*	vec4f
	*/
	IntrinsicCallPtr makeOuterProduct4x4F( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x3f
	*@param c
	*	vec3f
	*@param r
	*	vec2f
	*/
	IntrinsicCallPtr makeOuterProduct3x2F( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x2f
	*@param c
	*	vec2f
	*@param r
	*	vec3f
	*/
	IntrinsicCallPtr makeOuterProduct2x3F( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x4f
	*@param c
	*	vec4f
	*@param r
	*	vec2f
	*/
	IntrinsicCallPtr makeOuterProduct4x2F( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x2f
	*@param c
	*	vec2f
	*@param r
	*	vec4f
	*/
	IntrinsicCallPtr makeOuterProduct2x4F( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x4f
	*@param c
	*	vec4f
	*@param r
	*	vec3f
	*/
	IntrinsicCallPtr makeOuterProduct4x3F( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x3f
	*@param c
	*	vec3f
	*@param r
	*	vec4f
	*/
	IntrinsicCallPtr makeOuterProduct3x4F( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x2d
	*@param c
	*	vec2d
	*@param r
	*	vec2d
	*/
	IntrinsicCallPtr makeOuterProduct2x2D( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x3d
	*@param c
	*	vec3d
	*@param r
	*	vec3d
	*/
	IntrinsicCallPtr makeOuterProduct3x3D( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x4d
	*@param c
	*	vec4d
	*@param r
	*	vec4d
	*/
	IntrinsicCallPtr makeOuterProduct4x4D( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x3d
	*@param c
	*	vec3d
	*@param r
	*	vec2d
	*/
	IntrinsicCallPtr makeOuterProduct3x2D( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x2d
	*@param c
	*	vec2d
	*@param r
	*	vec3d
	*/
	IntrinsicCallPtr makeOuterProduct2x3D( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x4d
	*@param c
	*	vec4d
	*@param r
	*	vec2d
	*/
	IntrinsicCallPtr makeOuterProduct4x2D( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x2d
	*@param c
	*	vec2d
	*@param r
	*	vec4d
	*/
	IntrinsicCallPtr makeOuterProduct2x4D( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x4d
	*@param c
	*	vec4d
	*@param r
	*	vec3d
	*/
	IntrinsicCallPtr makeOuterProduct4x3D( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x3d
	*@param c
	*	vec3d
	*@param r
	*	vec4d
	*/
	IntrinsicCallPtr makeOuterProduct3x4D( type::TypesCache & cache, ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x2f
	*@param x
	*	mat2x2f
	*/
	IntrinsicCallPtr makeTranspose2x2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat3x2f
	*@param x
	*	mat2x3f
	*/
	IntrinsicCallPtr makeTranspose2x3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat4x2f
	*@param x
	*	mat2x4f
	*/
	IntrinsicCallPtr makeTranspose2x4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat2x3f
	*@param x
	*	mat3x2f
	*/
	IntrinsicCallPtr makeTranspose3x2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat3x3f
	*@param x
	*	mat3x3f
	*/
	IntrinsicCallPtr makeTranspose3x3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat4x3f
	*@param x
	*	mat3x4f
	*/
	IntrinsicCallPtr makeTranspose3x4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat2x4f
	*@param x
	*	mat4x2f
	*/
	IntrinsicCallPtr makeTranspose4x2F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat3x4f
	*@param x
	*	mat4x3f
	*/
	IntrinsicCallPtr makeTranspose4x3F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat4x4f
	*@param x
	*	mat4x4f
	*/
	IntrinsicCallPtr makeTranspose4x4F( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat2x2d
	*@param x
	*	mat2x2d
	*/
	IntrinsicCallPtr makeTranspose2x2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat3x2d
	*@param x
	*	mat2x3d
	*/
	IntrinsicCallPtr makeTranspose2x3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat4x2d
	*@param x
	*	mat2x4d
	*/
	IntrinsicCallPtr makeTranspose2x4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat2x3d
	*@param x
	*	mat3x2d
	*/
	IntrinsicCallPtr makeTranspose3x2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat3x3d
	*@param x
	*	mat3x3d
	*/
	IntrinsicCallPtr makeTranspose3x3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat4x3d
	*@param x
	*	mat3x4d
	*/
	IntrinsicCallPtr makeTranspose3x4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat2x4d
	*@param x
	*	mat4x2d
	*/
	IntrinsicCallPtr makeTranspose4x2D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat3x4d
	*@param x
	*	mat4x3d
	*/
	IntrinsicCallPtr makeTranspose4x3D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	mat4x4d
	*@param x
	*	mat4x4d
	*/
	IntrinsicCallPtr makeTranspose4x4D( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param m
	*	mat2x2f
	*/
	IntrinsicCallPtr makeDeterminant2x2F( type::TypesCache & cache, ExprPtr m );
	/**
	*@return
	*	float
	*@param m
	*	mat3x3f
	*/
	IntrinsicCallPtr makeDeterminant3x3F( type::TypesCache & cache, ExprPtr m );
	/**
	*@return
	*	float
	*@param m
	*	mat4x4f
	*/
	IntrinsicCallPtr makeDeterminant4x4F( type::TypesCache & cache, ExprPtr m );
	/**
	*@return
	*	double
	*@param m
	*	mat2x2d
	*/
	IntrinsicCallPtr makeDeterminant2x2D( type::TypesCache & cache, ExprPtr m );
	/**
	*@return
	*	double
	*@param m
	*	mat3x3d
	*/
	IntrinsicCallPtr makeDeterminant3x3D( type::TypesCache & cache, ExprPtr m );
	/**
	*@return
	*	double
	*@param m
	*	mat4x4d
	*/
	IntrinsicCallPtr makeDeterminant4x4D( type::TypesCache & cache, ExprPtr m );
	/**
	*@return
	*	mat2x2f
	*@param m
	*	mat2x2f
	*/
	IntrinsicCallPtr makeInverse2x2F( type::TypesCache & cache, ExprPtr m );
	/**
	*@return
	*	mat3x3f
	*@param m
	*	mat3x3f
	*/
	IntrinsicCallPtr makeInverse3x3F( type::TypesCache & cache, ExprPtr m );
	/**
	*@return
	*	mat4x4f
	*@param m
	*	mat4x4f
	*/
	IntrinsicCallPtr makeInverse4x4F( type::TypesCache & cache, ExprPtr m );
	/**
	*@return
	*	mat2x2d
	*@param m
	*	mat2x2d
	*/
	IntrinsicCallPtr makeInverse2x2D( type::TypesCache & cache, ExprPtr m );
	/**
	*@return
	*	mat3x3d
	*@param m
	*	mat3x3d
	*/
	IntrinsicCallPtr makeInverse3x3D( type::TypesCache & cache, ExprPtr m );
	/**
	*@return
	*	mat4x4d
	*@param m
	*	mat4x4d
	*/
	IntrinsicCallPtr makeInverse4x4D( type::TypesCache & cache, ExprPtr m );
	// Vector Relational Functions

	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeLessThan2F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeLessThan3F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeLessThan4F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeLessThan2D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeLessThan3D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeLessThan4D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeLessThan2I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeLessThan3I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeLessThan4I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeLessThan2U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeLessThan3U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeLessThan4U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeLessThanEqual2F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeLessThanEqual3F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeLessThanEqual4F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeLessThanEqual2D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeLessThanEqual3D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeLessThanEqual4D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeLessThanEqual2I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeLessThanEqual3I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeLessThanEqual4I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeLessThanEqual2U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeLessThanEqual3U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeLessThanEqual4U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeGreaterThan2F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeGreaterThan3F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeGreaterThan4F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeGreaterThan2D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeGreaterThan3D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeGreaterThan4D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeGreaterThan2I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeGreaterThan3I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeGreaterThan4I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeGreaterThan2U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeGreaterThan3U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeGreaterThan4U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeGreaterThanEqual2F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeGreaterThanEqual3F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeGreaterThanEqual4F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeGreaterThanEqual2D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeGreaterThanEqual3D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeGreaterThanEqual4D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeGreaterThanEqual2I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeGreaterThanEqual3I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeGreaterThanEqual4I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeGreaterThanEqual2U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeGreaterThanEqual3U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeGreaterThanEqual4U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeEqual2F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeEqual3F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeEqual4F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeEqual2D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeEqual3D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeEqual4D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeEqual2I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeEqual3I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeEqual4I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeEqual2U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeEqual3U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeEqual4U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeNotEqual2F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeNotEqual3F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeNotEqual4F( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeNotEqual2D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeNotEqual3D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeNotEqual4D( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeNotEqual2I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeNotEqual3I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeNotEqual4I( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeNotEqual2U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeNotEqual3U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeNotEqual4U( type::TypesCache & cache, ExprPtr x, ExprPtr y );
	/**
	*@return
	*	bool
	*@param x
	*	vec2b
	*/
	IntrinsicCallPtr makeAll2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	bool
	*@param x
	*	vec3b
	*/
	IntrinsicCallPtr makeAll3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	bool
	*@param x
	*	vec4b
	*/
	IntrinsicCallPtr makeAll4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	bool
	*@param x
	*	vec2b
	*/
	IntrinsicCallPtr makeAny2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	bool
	*@param x
	*	vec3b
	*/
	IntrinsicCallPtr makeAny3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	bool
	*@param x
	*	vec4b
	*/
	IntrinsicCallPtr makeAny4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2b
	*/
	IntrinsicCallPtr makeNot2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3b
	*/
	IntrinsicCallPtr makeNot3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4b
	*/
	IntrinsicCallPtr makeNot4( type::TypesCache & cache, ExprPtr x );
	// Integer Functions

	/**
	*@return
	*	uint
	*@param x
	*	uint
	*@param y
	*	uint
	*@param carry
	*	uint
	*/
	IntrinsicCallPtr makeUaddCarry1( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr carry );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*@param carry
	*	vec2u
	*/
	IntrinsicCallPtr makeUaddCarry2( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr carry );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*@param carry
	*	vec3u
	*/
	IntrinsicCallPtr makeUaddCarry3( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr carry );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*@param carry
	*	vec4u
	*/
	IntrinsicCallPtr makeUaddCarry4( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr carry );
	/**
	*@return
	*	uint
	*@param x
	*	uint
	*@param y
	*	uint
	*@param borrow
	*	uint
	*/
	IntrinsicCallPtr makeUsubBorrow1( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr borrow );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*@param borrow
	*	vec2u
	*/
	IntrinsicCallPtr makeUsubBorrow2( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr borrow );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*@param borrow
	*	vec3u
	*/
	IntrinsicCallPtr makeUsubBorrow3( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr borrow );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*@param borrow
	*	vec4u
	*/
	IntrinsicCallPtr makeUsubBorrow4( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr borrow );
	/**
	*@return
	*	void
	*@param x
	*	uint
	*@param y
	*	uint
	*@param msb
	*	uint
	*@param lsb
	*	uint
	*/
	IntrinsicCallPtr makeUmulExtended1( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
	/**
	*@return
	*	void
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*@param msb
	*	vec2u
	*@param lsb
	*	vec2u
	*/
	IntrinsicCallPtr makeUmulExtended2( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
	/**
	*@return
	*	void
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*@param msb
	*	vec3u
	*@param lsb
	*	vec3u
	*/
	IntrinsicCallPtr makeUmulExtended3( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
	/**
	*@return
	*	void
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*@param msb
	*	vec4u
	*@param lsb
	*	vec4u
	*/
	IntrinsicCallPtr makeUmulExtended4( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
	/**
	*@return
	*	void
	*@param x
	*	int
	*@param y
	*	int
	*@param msb
	*	int
	*@param lsb
	*	int
	*/
	IntrinsicCallPtr makeImulExtended1( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
	/**
	*@return
	*	void
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*@param msb
	*	vec2i
	*@param lsb
	*	vec2i
	*/
	IntrinsicCallPtr makeImulExtended2( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
	/**
	*@return
	*	void
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*@param msb
	*	vec3i
	*@param lsb
	*	vec3i
	*/
	IntrinsicCallPtr makeImulExtended3( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
	/**
	*@return
	*	void
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*@param msb
	*	vec4i
	*@param lsb
	*	vec4i
	*/
	IntrinsicCallPtr makeImulExtended4( type::TypesCache & cache, ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
	/**
	*@return
	*	int
	*@param value
	*	int
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldExtract1I( type::TypesCache & cache, ExprPtr value, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2i
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldExtract2I( type::TypesCache & cache, ExprPtr value, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3i
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldExtract3I( type::TypesCache & cache, ExprPtr value, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4i
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldExtract4I( type::TypesCache & cache, ExprPtr value, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	uint
	*@param value
	*	uint
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldExtract1U( type::TypesCache & cache, ExprPtr value, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec2u
	*@param value
	*	vec2u
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldExtract2U( type::TypesCache & cache, ExprPtr value, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec3u
	*@param value
	*	vec3u
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldExtract3U( type::TypesCache & cache, ExprPtr value, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec4u
	*@param value
	*	vec4u
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldExtract4U( type::TypesCache & cache, ExprPtr value, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	int
	*@param base
	*	int
	*@param insert
	*	int
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldInsert1I( type::TypesCache & cache, ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec2i
	*@param base
	*	vec2i
	*@param insert
	*	vec2i
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldInsert2I( type::TypesCache & cache, ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec3i
	*@param base
	*	vec3i
	*@param insert
	*	vec3i
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldInsert3I( type::TypesCache & cache, ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec4i
	*@param base
	*	vec4i
	*@param insert
	*	vec4i
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldInsert4I( type::TypesCache & cache, ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	uint
	*@param base
	*	uint
	*@param insert
	*	uint
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldInsert1U( type::TypesCache & cache, ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec2u
	*@param base
	*	vec2u
	*@param insert
	*	vec2u
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldInsert2U( type::TypesCache & cache, ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec3u
	*@param base
	*	vec3u
	*@param insert
	*	vec3u
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldInsert3U( type::TypesCache & cache, ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	vec4u
	*@param base
	*	vec4u
	*@param insert
	*	vec4u
	*@param offset
	*	int
	*@param bits
	*	int
	*/
	IntrinsicCallPtr makeBitfieldInsert4U( type::TypesCache & cache, ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	int
	*@param value
	*	int
	*/
	IntrinsicCallPtr makeBitfieldReverse1I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2i
	*/
	IntrinsicCallPtr makeBitfieldReverse2I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3i
	*/
	IntrinsicCallPtr makeBitfieldReverse3I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4i
	*/
	IntrinsicCallPtr makeBitfieldReverse4I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	uint
	*@param value
	*	uint
	*/
	IntrinsicCallPtr makeBitfieldReverse1U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec2u
	*@param value
	*	vec2u
	*/
	IntrinsicCallPtr makeBitfieldReverse2U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec3u
	*@param value
	*	vec3u
	*/
	IntrinsicCallPtr makeBitfieldReverse3U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec4u
	*@param value
	*	vec4u
	*/
	IntrinsicCallPtr makeBitfieldReverse4U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	int
	*@param value
	*	int
	*/
	IntrinsicCallPtr makeBitCount1I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2i
	*/
	IntrinsicCallPtr makeBitCount2I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3i
	*/
	IntrinsicCallPtr makeBitCount3I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4i
	*/
	IntrinsicCallPtr makeBitCount4I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	uint
	*@param value
	*	uint
	*/
	IntrinsicCallPtr makeBitCount1U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec2u
	*@param value
	*	vec2u
	*/
	IntrinsicCallPtr makeBitCount2U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec3u
	*@param value
	*	vec3u
	*/
	IntrinsicCallPtr makeBitCount3U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec4u
	*@param value
	*	vec4u
	*/
	IntrinsicCallPtr makeBitCount4U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	int
	*@param value
	*	int
	*/
	IntrinsicCallPtr makeFindLSB1I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2i
	*/
	IntrinsicCallPtr makeFindLSB2I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3i
	*/
	IntrinsicCallPtr makeFindLSB3I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4i
	*/
	IntrinsicCallPtr makeFindLSB4I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	int
	*@param value
	*	uint
	*/
	IntrinsicCallPtr makeFindLSB1U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2u
	*/
	IntrinsicCallPtr makeFindLSB2U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3u
	*/
	IntrinsicCallPtr makeFindLSB3U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4u
	*/
	IntrinsicCallPtr makeFindLSB4U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	int
	*@param value
	*	int
	*/
	IntrinsicCallPtr makeFindMSB1I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2i
	*/
	IntrinsicCallPtr makeFindMSB2I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3i
	*/
	IntrinsicCallPtr makeFindMSB3I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4i
	*/
	IntrinsicCallPtr makeFindMSB4I( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	int
	*@param value
	*	uint
	*/
	IntrinsicCallPtr makeFindMSB1U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2u
	*/
	IntrinsicCallPtr makeFindMSB2U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3u
	*/
	IntrinsicCallPtr makeFindMSB3U( type::TypesCache & cache, ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4u
	*/
	IntrinsicCallPtr makeFindMSB4U( type::TypesCache & cache, ExprPtr value );
	// Atomic Memory Functions

	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicAddI( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicAddU( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicMinI( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicMinU( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicMaxI( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicMaxU( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicAndI( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicAndU( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicOrI( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicOrU( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicXorI( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicXorU( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicExchangeI( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicExchangeU( type::TypesCache & cache, ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param compare
	*	uint
	*/
	IntrinsicCallPtr makeAtomicCompSwapI( type::TypesCache & cache, ExprPtr mem, ExprPtr compare );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param compare
	*	uint
	*/
	IntrinsicCallPtr makeAtomicCompSwapU( type::TypesCache & cache, ExprPtr mem, ExprPtr compare );
	// Derivative Functions

	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdx1( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdx2( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdx3( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdx4( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdxCoarse1( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdxCoarse2( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdxCoarse3( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdxCoarse4( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdxFine1( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdxFine2( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdxFine3( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdxFine4( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdy1( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdy2( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdy3( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdy4( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdyCoarse1( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdyCoarse2( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdyCoarse3( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdyCoarse4( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdyFine1( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdyFine2( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdyFine3( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdyFine4( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeFwidth1( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeFwidth2( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeFwidth3( type::TypesCache & cache, ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeFwidth4( type::TypesCache & cache, ExprPtr p );
	// Interpolation Functions

	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeInterpolateAtCentroid1( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeInterpolateAtCentroid2( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeInterpolateAtCentroid3( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeInterpolateAtCentroid4( type::TypesCache & cache, ExprPtr x );
	/**
	*@return
	*	float
	*@param interpolant
	*	float
	*@param sample
	*	int
	*/
	IntrinsicCallPtr makeInterpolateAtSample1( type::TypesCache & cache, ExprPtr interpolant, ExprPtr sample );
	/**
	*@return
	*	vec2f
	*@param interpolant
	*	vec2f
	*@param sample
	*	int
	*/
	IntrinsicCallPtr makeInterpolateAtSample2( type::TypesCache & cache, ExprPtr interpolant, ExprPtr sample );
	/**
	*@return
	*	vec3f
	*@param interpolant
	*	vec3f
	*@param sample
	*	int
	*/
	IntrinsicCallPtr makeInterpolateAtSample3( type::TypesCache & cache, ExprPtr interpolant, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param interpolant
	*	vec4f
	*@param sample
	*	int
	*/
	IntrinsicCallPtr makeInterpolateAtSample4( type::TypesCache & cache, ExprPtr interpolant, ExprPtr sample );
	/**
	*@return
	*	float
	*@param interpolant
	*	float
	*@param offset
	*	vec2f
	*/
	IntrinsicCallPtr makeInterpolateAtOffset1( type::TypesCache & cache, ExprPtr interpolant, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param interpolant
	*	vec2f
	*@param offset
	*	vec2f
	*/
	IntrinsicCallPtr makeInterpolateAtOffset2( type::TypesCache & cache, ExprPtr interpolant, ExprPtr offset );
	/**
	*@return
	*	vec3f
	*@param interpolant
	*	vec3f
	*@param offset
	*	vec2f
	*/
	IntrinsicCallPtr makeInterpolateAtOffset3( type::TypesCache & cache, ExprPtr interpolant, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param interpolant
	*	vec4f
	*@param offset
	*	vec2f
	*/
	IntrinsicCallPtr makeInterpolateAtOffset4( type::TypesCache & cache, ExprPtr interpolant, ExprPtr offset );
	// Geometry Shader Functions

	/**
	*@return
	*	void
	*@param stream
	*	int
	*/
	IntrinsicCallPtr makeEmitStreamVertex( type::TypesCache & cache, ExprPtr stream );
	/**
	*@return
	*	void
	*@param stream
	*	int
	*/
	IntrinsicCallPtr makeEndStreamPrimitive( type::TypesCache & cache, ExprPtr stream );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeEmitVertex( type::TypesCache & cache );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeEndPrimitive( type::TypesCache & cache );
	// Shader Invocation Control Functions

	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeBarrier( type::TypesCache & cache );
	// Shader Memory Control Functions

	/**
	*@return
	*	uint
	*/
	IntrinsicCallPtr makeMemoryBarrier( type::TypesCache & cache );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeMemoryBarrierBuffer( type::TypesCache & cache );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeMemoryBarrierShared( type::TypesCache & cache );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeMemoryBarrierImage( type::TypesCache & cache );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeGroupMemoryBarrier( type::TypesCache & cache );}

#endif
