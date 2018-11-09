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
	IntrinsicCallPtr makeDegrees1( ExprPtr radians );
	/**
	*@return
	*	vec2f
	*@param radians
	*	vec2f
	*/
	IntrinsicCallPtr makeDegrees2( ExprPtr radians );
	/**
	*@return
	*	vec3f
	*@param radians
	*	vec3f
	*/
	IntrinsicCallPtr makeDegrees3( ExprPtr radians );
	/**
	*@return
	*	vec4f
	*@param radians
	*	vec4f
	*/
	IntrinsicCallPtr makeDegrees4( ExprPtr radians );
	/**
	*@return
	*	float
	*@param degrees
	*	float
	*/
	IntrinsicCallPtr makeRadians1F( ExprPtr degrees );
	/**
	*@return
	*	vec2f
	*@param degrees
	*	vec2f
	*/
	IntrinsicCallPtr makeRadians2F( ExprPtr degrees );
	/**
	*@return
	*	vec3f
	*@param degrees
	*	vec3f
	*/
	IntrinsicCallPtr makeRadians3F( ExprPtr degrees );
	/**
	*@return
	*	vec4f
	*@param degrees
	*	vec4f
	*/
	IntrinsicCallPtr makeRadians4F( ExprPtr degrees );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeCos1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeCos2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeCos3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeCos4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeSin1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeSin2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeSin3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeSin4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeTan1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeTan2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeTan3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeTan4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeCosh1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeCosh2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeCosh3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeCosh4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeSinh1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeSinh2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeSinh3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeSinh4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeTanh1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeTanh2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeTanh3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeTanh4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAcos1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAcos2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAcos3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAcos4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAsin1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAsin2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAsin3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAsin4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAtan1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAtan2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAtan3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAtan4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAcosh1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAcosh2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAcosh3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAcosh4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAsinh1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAsinh2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAsinh3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAsinh4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAtanh1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAtanh2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAtanh3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAtanh4( ExprPtr x );
	// Exponential Functions

	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*/
	IntrinsicCallPtr makePow1( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makePow2( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makePow3( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makePow4( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeExp1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeExp2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeExp3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeExp4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeLog1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeLog2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeLog3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeLog4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeExp21( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeExp22( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeExp23( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeExp24( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeLog21( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeLog22( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeLog23( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeLog24( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeSqrt1F( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeSqrt2F( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeSqrt3F( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeSqrt4F( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeSqrt1D( ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeSqrt2D( ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeSqrt3D( ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeSqrt4D( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeInverseSqrt1F( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeInverseSqrt2F( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeInverseSqrt3F( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeInverseSqrt4F( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeInverseSqrt1D( ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeInverseSqrt2D( ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeInverseSqrt3D( ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeInverseSqrt4D( ExprPtr x );
	// Common Functions

	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeAbs1F( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeAbs2F( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeAbs3F( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeAbs4F( ExprPtr x );
	/**
	*@return
	*	int
	*@param x
	*	int
	*/
	IntrinsicCallPtr makeAbs1I( ExprPtr x );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*/
	IntrinsicCallPtr makeAbs2I( ExprPtr x );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*/
	IntrinsicCallPtr makeAbs3I( ExprPtr x );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*/
	IntrinsicCallPtr makeAbs4I( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeAbs1D( ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeAbs2D( ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeAbs3D( ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeAbs4D( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeSign1F( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeSign2F( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeSign3F( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeSign4F( ExprPtr x );
	/**
	*@return
	*	int
	*@param x
	*	int
	*/
	IntrinsicCallPtr makeSign1I( ExprPtr x );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*/
	IntrinsicCallPtr makeSign2I( ExprPtr x );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*/
	IntrinsicCallPtr makeSign3I( ExprPtr x );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*/
	IntrinsicCallPtr makeSign4I( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeSign1D( ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeSign2D( ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeSign3D( ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeSign4D( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeFloor1F( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeFloor2F( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeFloor3F( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeFloor4F( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeFloor1D( ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeFloor2D( ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeFloor3D( ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeFloor4D( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeTrunc1F( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeTrunc2F( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeTrunc3F( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeTrunc4F( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeTrunc1D( ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeTrunc2D( ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeTrunc3D( ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeTrunc4D( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeRound1F( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeRound2F( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeRound3F( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeRound4F( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeRound1D( ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeRound2D( ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeRound3D( ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeRound4D( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeRoundEven1F( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeRoundEven2F( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeRoundEven3F( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeRoundEven4F( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeRoundEven1D( ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeRoundEven2D( ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeRoundEven3D( ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeRoundEven4D( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeCeil1F( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeCeil2F( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeCeil3F( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeCeil4F( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeCeil1D( ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeCeil2D( ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeCeil3D( ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeCeil4D( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeFract1F( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeFract2F( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeFract3F( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeFract4F( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeFract1D( ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeFract2D( ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeFract3D( ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeFract4D( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMod11F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeMod22F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeMod33F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeMod44F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMod21F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMod31F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMod41F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMod11D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeMod22D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeMod33D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeMod44D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMod21D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMod31D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMod41D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param i
	*	float
	*/
	IntrinsicCallPtr makeModf1F( ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param i
	*	vec2f
	*/
	IntrinsicCallPtr makeModf2F( ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param i
	*	vec3f
	*/
	IntrinsicCallPtr makeModf3F( ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param i
	*	vec4f
	*/
	IntrinsicCallPtr makeModf4F( ExprPtr x, ExprPtr i );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param i
	*	double
	*/
	IntrinsicCallPtr makeModf1D( ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param i
	*	vec2d
	*/
	IntrinsicCallPtr makeModf2D( ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param i
	*	vec3d
	*/
	IntrinsicCallPtr makeModf3D( ExprPtr x, ExprPtr i );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param i
	*	vec4d
	*/
	IntrinsicCallPtr makeModf4D( ExprPtr x, ExprPtr i );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMin11F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeMin22F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeMin33F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeMin44F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMin21F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMin31F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMin41F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMin11D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeMin22D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeMin33D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeMin44D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMin21D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMin31D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMin41D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	int
	*@param x
	*	int
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMin11I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeMin22I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeMin33I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeMin44I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMin21I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMin31I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMin41I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	uint
	*@param x
	*	uint
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMin11U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeMin22U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeMin33U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeMin44U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMin21U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMin31U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMin41U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMax11F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeMax22F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeMax33F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeMax44F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMax21F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMax31F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeMax41F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMax11D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeMax22D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeMax33D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeMax44D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMax21D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMax31D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeMax41D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	int
	*@param x
	*	int
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMax11I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeMax22I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeMax33I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeMax44I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2i
	*@param x
	*	vec2i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMax21I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3i
	*@param x
	*	vec3i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMax31I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4i
	*@param x
	*	vec4i
	*@param y
	*	int
	*/
	IntrinsicCallPtr makeMax41I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	uint
	*@param x
	*	uint
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMax11U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeMax22U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeMax33U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeMax44U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2u
	*@param x
	*	vec2u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMax21U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3u
	*@param x
	*	vec3u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMax31U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4u
	*@param x
	*	vec4u
	*@param y
	*	uint
	*/
	IntrinsicCallPtr makeMax41U( ExprPtr x, ExprPtr y );
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
	IntrinsicCallPtr makeClamp11F( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp22F( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp33F( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp44F( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp21F( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp31F( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp41F( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp11D( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp22D( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp33D( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp44D( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp21D( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp31D( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp41D( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp11I( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp22I( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp33I( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp44I( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp21I( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp31I( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp41I( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp11U( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp22U( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp33U( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp44U( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp21U( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp31U( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeClamp41U( ExprPtr x, ExprPtr minVal, ExprPtr maxVal );
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
	IntrinsicCallPtr makeMix11F( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix22F( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix33F( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix44F( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix21F( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix31F( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix41F( ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*@param a
	*	boolean
	*/
	IntrinsicCallPtr makeMix11FB( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix22FB( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix33FB( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix44FB( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix11D( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix22D( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix33D( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix44D( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix21D( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix31D( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix41D( ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param y
	*	double
	*@param a
	*	boolean
	*/
	IntrinsicCallPtr makeMix11DB( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix22DB( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix33DB( ExprPtr x, ExprPtr y, ExprPtr a );
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
	IntrinsicCallPtr makeMix44DB( ExprPtr x, ExprPtr y, ExprPtr a );
	/**
	*@return
	*	float
	*@param edge
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeStep11F( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param edge
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeStep22F( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param edge
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeStep33F( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param edge
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeStep44F( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param edge
	*	float
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeStep12F( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param edge
	*	float
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeStep13F( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param edge
	*	float
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeStep14F( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	double
	*@param edge
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeStep11D( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param edge
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeStep22D( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param edge
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeStep33D( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param edge
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeStep44D( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param edge
	*	double
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeStep12D( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param edge
	*	double
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeStep13D( ExprPtr edge, ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param edge
	*	double
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeStep14D( ExprPtr edge, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep11F( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep22F( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep33F( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep44F( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep12F( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep13F( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep14F( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep11D( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep22D( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep33D( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep44D( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep12D( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep13D( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
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
	IntrinsicCallPtr makeSmoothStep14D( ExprPtr edge0, ExprPtr edge1, ExprPtr x );
	/**
	*@return
	*	boolean
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeIsnan1F( ExprPtr x );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeIsnan2F( ExprPtr x );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeIsnan3F( ExprPtr x );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeIsnan4F( ExprPtr x );
	/**
	*@return
	*	boolean
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeIsnan1D( ExprPtr x );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeIsnan2D( ExprPtr x );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeIsnan3D( ExprPtr x );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeIsnan4D( ExprPtr x );
	/**
	*@return
	*	boolean
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeIsinf1F( ExprPtr x );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeIsinf2F( ExprPtr x );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeIsinf3F( ExprPtr x );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeIsinf4F( ExprPtr x );
	/**
	*@return
	*	boolean
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeIsinf1D( ExprPtr x );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeIsinf2D( ExprPtr x );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeIsinf3D( ExprPtr x );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeIsinf4D( ExprPtr x );
	/**
	*@return
	*	int
	*@param value
	*	float
	*/
	IntrinsicCallPtr makeFloatBitsToInt1( ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2f
	*/
	IntrinsicCallPtr makeFloatBitsToInt2( ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3f
	*/
	IntrinsicCallPtr makeFloatBitsToInt3( ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4f
	*/
	IntrinsicCallPtr makeFloatBitsToInt4( ExprPtr value );
	/**
	*@return
	*	uint
	*@param value
	*	float
	*/
	IntrinsicCallPtr makeFloatBitsToUInt1( ExprPtr value );
	/**
	*@return
	*	vec2u
	*@param value
	*	vec2f
	*/
	IntrinsicCallPtr makeFloatBitsToUInt2( ExprPtr value );
	/**
	*@return
	*	vec3u
	*@param value
	*	vec3f
	*/
	IntrinsicCallPtr makeFloatBitsToUInt3( ExprPtr value );
	/**
	*@return
	*	vec4u
	*@param value
	*	vec4f
	*/
	IntrinsicCallPtr makeFloatBitsToUInt4( ExprPtr value );
	/**
	*@return
	*	float
	*@param x
	*	int
	*/
	IntrinsicCallPtr makeIntBitsToFloat1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2i
	*/
	IntrinsicCallPtr makeIntBitsToFloat2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3i
	*/
	IntrinsicCallPtr makeIntBitsToFloat3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4i
	*/
	IntrinsicCallPtr makeIntBitsToFloat4( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	uint
	*/
	IntrinsicCallPtr makeUintBitsToFloat1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2u
	*/
	IntrinsicCallPtr makeUintBitsToFloat2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3u
	*/
	IntrinsicCallPtr makeUintBitsToFloat3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4u
	*/
	IntrinsicCallPtr makeUintBitsToFloat4( ExprPtr x );
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
	IntrinsicCallPtr makeFma1F( ExprPtr a, ExprPtr b, ExprPtr c );
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
	IntrinsicCallPtr makeFma2F( ExprPtr a, ExprPtr b, ExprPtr c );
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
	IntrinsicCallPtr makeFma3F( ExprPtr a, ExprPtr b, ExprPtr c );
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
	IntrinsicCallPtr makeFma4F( ExprPtr a, ExprPtr b, ExprPtr c );
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
	IntrinsicCallPtr makeFma1D( ExprPtr a, ExprPtr b, ExprPtr c );
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
	IntrinsicCallPtr makeFma2D( ExprPtr a, ExprPtr b, ExprPtr c );
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
	IntrinsicCallPtr makeFma3D( ExprPtr a, ExprPtr b, ExprPtr c );
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
	IntrinsicCallPtr makeFma4D( ExprPtr a, ExprPtr b, ExprPtr c );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param exp
	*	int
	*/
	IntrinsicCallPtr makeFrexp1F( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param exp
	*	vec2i
	*/
	IntrinsicCallPtr makeFrexp2F( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param exp
	*	vec3i
	*/
	IntrinsicCallPtr makeFrexp3F( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param exp
	*	vec4i
	*/
	IntrinsicCallPtr makeFrexp4F( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param exp
	*	int
	*/
	IntrinsicCallPtr makeFrexp1D( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param exp
	*	vec2i
	*/
	IntrinsicCallPtr makeFrexp2D( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param exp
	*	vec3i
	*/
	IntrinsicCallPtr makeFrexp3D( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param exp
	*	vec4i
	*/
	IntrinsicCallPtr makeFrexp4D( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param exp
	*	int
	*/
	IntrinsicCallPtr makeLdexp1F( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*@param exp
	*	vec2i
	*/
	IntrinsicCallPtr makeLdexp2F( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param exp
	*	vec3i
	*/
	IntrinsicCallPtr makeLdexp3F( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*@param exp
	*	vec4i
	*/
	IntrinsicCallPtr makeLdexp4F( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param exp
	*	int
	*/
	IntrinsicCallPtr makeLdexp1D( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*@param exp
	*	vec2i
	*/
	IntrinsicCallPtr makeLdexp2D( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param exp
	*	vec3i
	*/
	IntrinsicCallPtr makeLdexp3D( ExprPtr x, ExprPtr exp );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*@param exp
	*	vec4i
	*/
	IntrinsicCallPtr makeLdexp4D( ExprPtr x, ExprPtr exp );
	// Floating-point Pack and Unpack Functions

	/**
	*@return
	*	double
	*@param v
	*	vec2u
	*/
	IntrinsicCallPtr makePackDouble2x32( ExprPtr v );
	/**
	*@return
	*	uint
	*@param v
	*	vec2f
	*/
	IntrinsicCallPtr makePackHalf2x16( ExprPtr v );
	/**
	*@return
	*	uint
	*@param v
	*	vec2f
	*/
	IntrinsicCallPtr makePackSnorm2x16( ExprPtr v );
	/**
	*@return
	*	uint
	*@param v
	*	vec4f
	*/
	IntrinsicCallPtr makePackSnorm4x8( ExprPtr v );
	/**
	*@return
	*	uint
	*@param v
	*	vec2f
	*/
	IntrinsicCallPtr makePackUnorm2x16( ExprPtr v );
	/**
	*@return
	*	uint
	*@param v
	*	vec4f
	*/
	IntrinsicCallPtr makePackUnorm4x8( ExprPtr v );
	/**
	*@return
	*	vec2u
	*@param d
	*	double
	*/
	IntrinsicCallPtr makeUnpackDouble2x32( ExprPtr d );
	/**
	*@return
	*	vec2f
	*@param v
	*	uint
	*/
	IntrinsicCallPtr makeUnpackHalf2x16( ExprPtr v );
	/**
	*@return
	*	vec2f
	*@param p
	*	uint
	*/
	IntrinsicCallPtr makeUnpackSnorm2x16( ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	uint
	*/
	IntrinsicCallPtr makeUnpackSnorm4x8( ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	uint
	*/
	IntrinsicCallPtr makeUnpackUnorm2x16( ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	uint
	*/
	IntrinsicCallPtr makeUnpackUnorm4x8( ExprPtr p );
	// Geometric Functions

	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeLength1F( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeLength2F( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeLength3F( ExprPtr x );
	/**
	*@return
	*	float
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeLength4F( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeLength1D( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeLength2D( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeLength3D( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeLength4D( ExprPtr x );
	/**
	*@return
	*	float
	*@param p0
	*	float
	*@param p1
	*	float
	*/
	IntrinsicCallPtr makeDistance1F( ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	vec2f
	*@param p0
	*	vec2f
	*@param p1
	*	vec2f
	*/
	IntrinsicCallPtr makeDistance2F( ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	vec3f
	*@param p0
	*	vec3f
	*@param p1
	*	vec3f
	*/
	IntrinsicCallPtr makeDistance3F( ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	vec4f
	*@param p0
	*	vec4f
	*@param p1
	*	vec4f
	*/
	IntrinsicCallPtr makeDistance4F( ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	double
	*@param p0
	*	double
	*@param p1
	*	double
	*/
	IntrinsicCallPtr makeDistance1D( ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	double
	*@param p0
	*	vec2d
	*@param p1
	*	vec2d
	*/
	IntrinsicCallPtr makeDistance2D( ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	double
	*@param p0
	*	vec3d
	*@param p1
	*	vec3d
	*/
	IntrinsicCallPtr makeDistance3D( ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	double
	*@param p0
	*	vec4d
	*@param p1
	*	vec4d
	*/
	IntrinsicCallPtr makeDistance4D( ExprPtr p0, ExprPtr p1 );
	/**
	*@return
	*	float
	*@param x
	*	float
	*@param y
	*	float
	*/
	IntrinsicCallPtr makeDot1F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeDot2F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeDot3F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeDot4F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	double
	*@param y
	*	double
	*/
	IntrinsicCallPtr makeDot1D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeDot2D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeDot3D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	double
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeDot4D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeCrossF( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeCrossD( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeNormalize1F( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeNormalize2F( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeNormalize3F( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeNormalize4F( ExprPtr x );
	/**
	*@return
	*	double
	*@param x
	*	double
	*/
	IntrinsicCallPtr makeNormalize1D( ExprPtr x );
	/**
	*@return
	*	vec2d
	*@param x
	*	vec2d
	*/
	IntrinsicCallPtr makeNormalize2D( ExprPtr x );
	/**
	*@return
	*	vec3d
	*@param x
	*	vec3d
	*/
	IntrinsicCallPtr makeNormalize3D( ExprPtr x );
	/**
	*@return
	*	vec4d
	*@param x
	*	vec4d
	*/
	IntrinsicCallPtr makeNormalize4D( ExprPtr x );
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
	IntrinsicCallPtr makeFaceForward1F( ExprPtr N, ExprPtr I, ExprPtr Nref );
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
	IntrinsicCallPtr makeFaceForward2F( ExprPtr N, ExprPtr I, ExprPtr Nref );
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
	IntrinsicCallPtr makeFaceForward3F( ExprPtr N, ExprPtr I, ExprPtr Nref );
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
	IntrinsicCallPtr makeFaceForward4F( ExprPtr N, ExprPtr I, ExprPtr Nref );
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
	IntrinsicCallPtr makeFaceForward1D( ExprPtr N, ExprPtr I, ExprPtr Nref );
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
	IntrinsicCallPtr makeFaceForward2D( ExprPtr N, ExprPtr I, ExprPtr Nref );
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
	IntrinsicCallPtr makeFaceForward3D( ExprPtr N, ExprPtr I, ExprPtr Nref );
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
	IntrinsicCallPtr makeFaceForward4D( ExprPtr N, ExprPtr I, ExprPtr Nref );
	/**
	*@return
	*	float
	*@param I
	*	float
	*@param N
	*	float
	*/
	IntrinsicCallPtr makeReflect1F( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec2f
	*@param I
	*	vec2f
	*@param N
	*	vec2f
	*/
	IntrinsicCallPtr makeReflect2F( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec3f
	*@param I
	*	vec3f
	*@param N
	*	vec3f
	*/
	IntrinsicCallPtr makeReflect3F( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec4f
	*@param I
	*	vec4f
	*@param N
	*	vec4f
	*/
	IntrinsicCallPtr makeReflect4F( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	double
	*@param I
	*	float
	*@param N
	*	double
	*/
	IntrinsicCallPtr makeReflect1D( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec2d
	*@param I
	*	vec2d
	*@param N
	*	vec2d
	*/
	IntrinsicCallPtr makeReflect2D( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec3d
	*@param I
	*	vec3d
	*@param N
	*	vec3d
	*/
	IntrinsicCallPtr makeReflect3D( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec4d
	*@param I
	*	vec4d
	*@param N
	*	vec4d
	*/
	IntrinsicCallPtr makeReflect4D( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	float
	*@param I
	*	float
	*@param N
	*	float
	*/
	IntrinsicCallPtr makeRefract1F( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec2f
	*@param I
	*	vec2f
	*@param N
	*	vec2f
	*/
	IntrinsicCallPtr makeRefract2F( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec3f
	*@param I
	*	vec3f
	*@param N
	*	vec3f
	*/
	IntrinsicCallPtr makeRefract3F( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec4f
	*@param I
	*	vec4f
	*@param N
	*	vec4f
	*/
	IntrinsicCallPtr makeRefract4F( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	double
	*@param I
	*	double
	*@param N
	*	double
	*/
	IntrinsicCallPtr makeRefract1D( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec2d
	*@param I
	*	vec2d
	*@param N
	*	vec2d
	*/
	IntrinsicCallPtr makeRefract2D( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec3d
	*@param I
	*	vec3d
	*@param N
	*	vec3d
	*/
	IntrinsicCallPtr makeRefract3D( ExprPtr I, ExprPtr N );
	/**
	*@return
	*	vec4d
	*@param I
	*	vec4d
	*@param N
	*	vec4d
	*/
	IntrinsicCallPtr makeRefract4D( ExprPtr I, ExprPtr N );
	// Matrix Functions

	/**
	*@return
	*	mat2x2f
	*@param x
	*	mat2x2f
	*@param y
	*	mat2x2f
	*/
	IntrinsicCallPtr makeMatrixCompMult2x2F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x3f
	*@param x
	*	mat2x3f
	*@param y
	*	mat2x3f
	*/
	IntrinsicCallPtr makeMatrixCompMult2x3F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x4f
	*@param x
	*	mat2x4f
	*@param y
	*	mat2x4f
	*/
	IntrinsicCallPtr makeMatrixCompMult2x4F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x2f
	*@param x
	*	mat3x2f
	*@param y
	*	mat3x2f
	*/
	IntrinsicCallPtr makeMatrixCompMult3x2F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x3f
	*@param x
	*	mat3x3f
	*@param y
	*	mat3x3f
	*/
	IntrinsicCallPtr makeMatrixCompMult3x3F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x4f
	*@param x
	*	mat3x4f
	*@param y
	*	mat3x4f
	*/
	IntrinsicCallPtr makeMatrixCompMult3x4F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x2f
	*@param x
	*	mat4x2f
	*@param y
	*	mat4x2f
	*/
	IntrinsicCallPtr makeMatrixCompMult4x2F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x3f
	*@param x
	*	mat4x3f
	*@param y
	*	mat4x3f
	*/
	IntrinsicCallPtr makeMatrixCompMult4x3F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x4f
	*@param x
	*	mat4x4f
	*@param y
	*	mat4x4f
	*/
	IntrinsicCallPtr makeMatrixCompMult4x4F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x2d
	*@param x
	*	mat2x2d
	*@param y
	*	mat2x2d
	*/
	IntrinsicCallPtr makeMatrixCompMult2x2D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x3d
	*@param x
	*	mat2x3d
	*@param y
	*	mat2x3d
	*/
	IntrinsicCallPtr makeMatrixCompMult2x3D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x4d
	*@param x
	*	mat2x4d
	*@param y
	*	mat2x4d
	*/
	IntrinsicCallPtr makeMatrixCompMult2x4D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x2d
	*@param x
	*	mat3x2d
	*@param y
	*	mat3x2d
	*/
	IntrinsicCallPtr makeMatrixCompMult3x2D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x3d
	*@param x
	*	mat3x3d
	*@param y
	*	mat3x3d
	*/
	IntrinsicCallPtr makeMatrixCompMult3x3D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat3x4d
	*@param x
	*	mat3x4d
	*@param y
	*	mat3x4d
	*/
	IntrinsicCallPtr makeMatrixCompMult3x4D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x2d
	*@param x
	*	mat4x2d
	*@param y
	*	mat4x2d
	*/
	IntrinsicCallPtr makeMatrixCompMult4x2D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x3d
	*@param x
	*	mat4x3d
	*@param y
	*	mat4x3d
	*/
	IntrinsicCallPtr makeMatrixCompMult4x3D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat4x4d
	*@param x
	*	mat4x4d
	*@param y
	*	mat4x4d
	*/
	IntrinsicCallPtr makeMatrixCompMult4x4D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	mat2x2f
	*@param c
	*	vec2f
	*@param r
	*	vec2f
	*/
	IntrinsicCallPtr makeOuterProduct2x2F( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x3f
	*@param c
	*	vec3f
	*@param r
	*	vec3f
	*/
	IntrinsicCallPtr makeOuterProduct3x3F( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x4f
	*@param c
	*	vec4f
	*@param r
	*	vec4f
	*/
	IntrinsicCallPtr makeOuterProduct4x4F( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x3f
	*@param c
	*	vec3f
	*@param r
	*	vec2f
	*/
	IntrinsicCallPtr makeOuterProduct3x2F( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x2f
	*@param c
	*	vec2f
	*@param r
	*	vec3f
	*/
	IntrinsicCallPtr makeOuterProduct2x3F( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x4f
	*@param c
	*	vec4f
	*@param r
	*	vec2f
	*/
	IntrinsicCallPtr makeOuterProduct4x2F( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x2f
	*@param c
	*	vec2f
	*@param r
	*	vec4f
	*/
	IntrinsicCallPtr makeOuterProduct2x4F( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x4f
	*@param c
	*	vec4f
	*@param r
	*	vec3f
	*/
	IntrinsicCallPtr makeOuterProduct4x3F( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x3f
	*@param c
	*	vec3f
	*@param r
	*	vec4f
	*/
	IntrinsicCallPtr makeOuterProduct3x4F( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x2d
	*@param c
	*	vec2d
	*@param r
	*	vec2d
	*/
	IntrinsicCallPtr makeOuterProduct2x2D( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x3d
	*@param c
	*	vec3d
	*@param r
	*	vec3d
	*/
	IntrinsicCallPtr makeOuterProduct3x3D( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x4d
	*@param c
	*	vec4d
	*@param r
	*	vec4d
	*/
	IntrinsicCallPtr makeOuterProduct4x4D( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x3d
	*@param c
	*	vec3d
	*@param r
	*	vec2d
	*/
	IntrinsicCallPtr makeOuterProduct3x2D( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x2d
	*@param c
	*	vec2d
	*@param r
	*	vec3d
	*/
	IntrinsicCallPtr makeOuterProduct2x3D( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x4d
	*@param c
	*	vec4d
	*@param r
	*	vec2d
	*/
	IntrinsicCallPtr makeOuterProduct4x2D( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x2d
	*@param c
	*	vec2d
	*@param r
	*	vec4d
	*/
	IntrinsicCallPtr makeOuterProduct2x4D( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat3x4d
	*@param c
	*	vec4d
	*@param r
	*	vec3d
	*/
	IntrinsicCallPtr makeOuterProduct4x3D( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat4x3d
	*@param c
	*	vec3d
	*@param r
	*	vec4d
	*/
	IntrinsicCallPtr makeOuterProduct3x4D( ExprPtr c, ExprPtr r );
	/**
	*@return
	*	mat2x2f
	*@param x
	*	mat2x2f
	*/
	IntrinsicCallPtr makeTranspose2x2F( ExprPtr x );
	/**
	*@return
	*	mat3x2f
	*@param x
	*	mat2x3f
	*/
	IntrinsicCallPtr makeTranspose2x3F( ExprPtr x );
	/**
	*@return
	*	mat4x2f
	*@param x
	*	mat2x4f
	*/
	IntrinsicCallPtr makeTranspose2x4F( ExprPtr x );
	/**
	*@return
	*	mat2x3f
	*@param x
	*	mat3x2f
	*/
	IntrinsicCallPtr makeTranspose3x2F( ExprPtr x );
	/**
	*@return
	*	mat3x3f
	*@param x
	*	mat3x3f
	*/
	IntrinsicCallPtr makeTranspose3x3F( ExprPtr x );
	/**
	*@return
	*	mat4x3f
	*@param x
	*	mat3x4f
	*/
	IntrinsicCallPtr makeTranspose3x4F( ExprPtr x );
	/**
	*@return
	*	mat2x4f
	*@param x
	*	mat4x2f
	*/
	IntrinsicCallPtr makeTranspose4x2F( ExprPtr x );
	/**
	*@return
	*	mat3x4f
	*@param x
	*	mat4x3f
	*/
	IntrinsicCallPtr makeTranspose4x3F( ExprPtr x );
	/**
	*@return
	*	mat4x4f
	*@param x
	*	mat4x4f
	*/
	IntrinsicCallPtr makeTranspose4x4F( ExprPtr x );
	/**
	*@return
	*	mat2x2d
	*@param x
	*	mat2x2d
	*/
	IntrinsicCallPtr makeTranspose2x2D( ExprPtr x );
	/**
	*@return
	*	mat3x2d
	*@param x
	*	mat2x3d
	*/
	IntrinsicCallPtr makeTranspose2x3D( ExprPtr x );
	/**
	*@return
	*	mat4x2d
	*@param x
	*	mat2x4d
	*/
	IntrinsicCallPtr makeTranspose2x4D( ExprPtr x );
	/**
	*@return
	*	mat2x3d
	*@param x
	*	mat3x2d
	*/
	IntrinsicCallPtr makeTranspose3x2D( ExprPtr x );
	/**
	*@return
	*	mat3x3d
	*@param x
	*	mat3x3d
	*/
	IntrinsicCallPtr makeTranspose3x3D( ExprPtr x );
	/**
	*@return
	*	mat4x3d
	*@param x
	*	mat3x4d
	*/
	IntrinsicCallPtr makeTranspose3x4D( ExprPtr x );
	/**
	*@return
	*	mat2x4d
	*@param x
	*	mat4x2d
	*/
	IntrinsicCallPtr makeTranspose4x2D( ExprPtr x );
	/**
	*@return
	*	mat3x4d
	*@param x
	*	mat4x3d
	*/
	IntrinsicCallPtr makeTranspose4x3D( ExprPtr x );
	/**
	*@return
	*	mat4x4d
	*@param x
	*	mat4x4d
	*/
	IntrinsicCallPtr makeTranspose4x4D( ExprPtr x );
	/**
	*@return
	*	float
	*@param m
	*	mat2x2f
	*/
	IntrinsicCallPtr makeDeterminant2x2F( ExprPtr m );
	/**
	*@return
	*	float
	*@param m
	*	mat3x3f
	*/
	IntrinsicCallPtr makeDeterminant3x3F( ExprPtr m );
	/**
	*@return
	*	float
	*@param m
	*	mat4x4f
	*/
	IntrinsicCallPtr makeDeterminant4x4F( ExprPtr m );
	/**
	*@return
	*	double
	*@param m
	*	mat2x2d
	*/
	IntrinsicCallPtr makeDeterminant2x2D( ExprPtr m );
	/**
	*@return
	*	double
	*@param m
	*	mat3x3d
	*/
	IntrinsicCallPtr makeDeterminant3x3D( ExprPtr m );
	/**
	*@return
	*	double
	*@param m
	*	mat4x4d
	*/
	IntrinsicCallPtr makeDeterminant4x4D( ExprPtr m );
	/**
	*@return
	*	mat2x2f
	*@param m
	*	mat2x2f
	*/
	IntrinsicCallPtr makeInverse2x2F( ExprPtr m );
	/**
	*@return
	*	mat3x3f
	*@param m
	*	mat3x3f
	*/
	IntrinsicCallPtr makeInverse3x3F( ExprPtr m );
	/**
	*@return
	*	mat4x4f
	*@param m
	*	mat4x4f
	*/
	IntrinsicCallPtr makeInverse4x4F( ExprPtr m );
	/**
	*@return
	*	mat2x2d
	*@param m
	*	mat2x2d
	*/
	IntrinsicCallPtr makeInverse2x2D( ExprPtr m );
	/**
	*@return
	*	mat3x3d
	*@param m
	*	mat3x3d
	*/
	IntrinsicCallPtr makeInverse3x3D( ExprPtr m );
	/**
	*@return
	*	mat4x4d
	*@param m
	*	mat4x4d
	*/
	IntrinsicCallPtr makeInverse4x4D( ExprPtr m );
	// Vector Relational Functions

	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeLessThan2F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeLessThan3F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeLessThan4F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeLessThan2D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeLessThan3D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeLessThan4D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeLessThan2I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeLessThan3I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeLessThan4I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeLessThan2U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeLessThan3U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeLessThan4U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeLessThanEqual2F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeLessThanEqual3F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeLessThanEqual4F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeLessThanEqual2D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeLessThanEqual3D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeLessThanEqual4D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeLessThanEqual2I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeLessThanEqual3I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeLessThanEqual4I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeLessThanEqual2U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeLessThanEqual3U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeLessThanEqual4U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeGreaterThan2F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeGreaterThan3F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeGreaterThan4F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeGreaterThan2D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeGreaterThan3D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeGreaterThan4D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeGreaterThan2I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeGreaterThan3I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeGreaterThan4I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeGreaterThan2U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeGreaterThan3U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeGreaterThan4U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeGreaterThanEqual2F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeGreaterThanEqual3F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeGreaterThanEqual4F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeGreaterThanEqual2D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeGreaterThanEqual3D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeGreaterThanEqual4D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeGreaterThanEqual2I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeGreaterThanEqual3I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeGreaterThanEqual4I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeGreaterThanEqual2U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeGreaterThanEqual3U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeGreaterThanEqual4U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeEqual2F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeEqual3F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeEqual4F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeEqual2D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeEqual3D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeEqual4D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeEqual2I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeEqual3I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeEqual4I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeEqual2U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeEqual3U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeEqual4U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2f
	*@param y
	*	vec2f
	*/
	IntrinsicCallPtr makeNotEqual2F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3f
	*@param y
	*	vec3f
	*/
	IntrinsicCallPtr makeNotEqual3F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4f
	*@param y
	*	vec4f
	*/
	IntrinsicCallPtr makeNotEqual4F( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2d
	*@param y
	*	vec2d
	*/
	IntrinsicCallPtr makeNotEqual2D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3d
	*@param y
	*	vec3d
	*/
	IntrinsicCallPtr makeNotEqual3D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4d
	*@param y
	*	vec4d
	*/
	IntrinsicCallPtr makeNotEqual4D( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2i
	*@param y
	*	vec2i
	*/
	IntrinsicCallPtr makeNotEqual2I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3i
	*@param y
	*	vec3i
	*/
	IntrinsicCallPtr makeNotEqual3I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4i
	*@param y
	*	vec4i
	*/
	IntrinsicCallPtr makeNotEqual4I( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2u
	*@param y
	*	vec2u
	*/
	IntrinsicCallPtr makeNotEqual2U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3u
	*@param y
	*	vec3u
	*/
	IntrinsicCallPtr makeNotEqual3U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4u
	*@param y
	*	vec4u
	*/
	IntrinsicCallPtr makeNotEqual4U( ExprPtr x, ExprPtr y );
	/**
	*@return
	*	boolean
	*@param x
	*	vec2b
	*/
	IntrinsicCallPtr makeAll2( ExprPtr x );
	/**
	*@return
	*	boolean
	*@param x
	*	vec3b
	*/
	IntrinsicCallPtr makeAll3( ExprPtr x );
	/**
	*@return
	*	boolean
	*@param x
	*	vec4b
	*/
	IntrinsicCallPtr makeAll4( ExprPtr x );
	/**
	*@return
	*	boolean
	*@param x
	*	vec2b
	*/
	IntrinsicCallPtr makeAny2( ExprPtr x );
	/**
	*@return
	*	boolean
	*@param x
	*	vec3b
	*/
	IntrinsicCallPtr makeAny3( ExprPtr x );
	/**
	*@return
	*	boolean
	*@param x
	*	vec4b
	*/
	IntrinsicCallPtr makeAny4( ExprPtr x );
	/**
	*@return
	*	vec2b
	*@param x
	*	vec2b
	*/
	IntrinsicCallPtr makeNot2( ExprPtr x );
	/**
	*@return
	*	vec3b
	*@param x
	*	vec3b
	*/
	IntrinsicCallPtr makeNot3( ExprPtr x );
	/**
	*@return
	*	vec4b
	*@param x
	*	vec4b
	*/
	IntrinsicCallPtr makeNot4( ExprPtr x );
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
	IntrinsicCallPtr makeUaddCarry1( ExprPtr x, ExprPtr y, ExprPtr carry );
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
	IntrinsicCallPtr makeUaddCarry2( ExprPtr x, ExprPtr y, ExprPtr carry );
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
	IntrinsicCallPtr makeUaddCarry3( ExprPtr x, ExprPtr y, ExprPtr carry );
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
	IntrinsicCallPtr makeUaddCarry4( ExprPtr x, ExprPtr y, ExprPtr carry );
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
	IntrinsicCallPtr makeUsubBorrow1( ExprPtr x, ExprPtr y, ExprPtr borrow );
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
	IntrinsicCallPtr makeUsubBorrow2( ExprPtr x, ExprPtr y, ExprPtr borrow );
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
	IntrinsicCallPtr makeUsubBorrow3( ExprPtr x, ExprPtr y, ExprPtr borrow );
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
	IntrinsicCallPtr makeUsubBorrow4( ExprPtr x, ExprPtr y, ExprPtr borrow );
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
	IntrinsicCallPtr makeUmulExtended1( ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
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
	IntrinsicCallPtr makeUmulExtended2( ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
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
	IntrinsicCallPtr makeUmulExtended3( ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
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
	IntrinsicCallPtr makeUmulExtended4( ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
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
	IntrinsicCallPtr makeImulExtended1( ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
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
	IntrinsicCallPtr makeImulExtended2( ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
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
	IntrinsicCallPtr makeImulExtended3( ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
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
	IntrinsicCallPtr makeImulExtended4( ExprPtr x, ExprPtr y, ExprPtr msb, ExprPtr lsb );
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
	IntrinsicCallPtr makeBitfieldExtract1I( ExprPtr value, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldExtract2I( ExprPtr value, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldExtract3I( ExprPtr value, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldExtract4I( ExprPtr value, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldExtract1U( ExprPtr value, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldExtract2U( ExprPtr value, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldExtract3U( ExprPtr value, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldExtract4U( ExprPtr value, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldInsert1I( ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldInsert2I( ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldInsert3I( ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldInsert4I( ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldInsert1U( ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldInsert2U( ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldInsert3U( ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
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
	IntrinsicCallPtr makeBitfieldInsert4U( ExprPtr base, ExprPtr insert, ExprPtr offset, ExprPtr bits );
	/**
	*@return
	*	int
	*@param value
	*	int
	*/
	IntrinsicCallPtr makeBitfieldReverse1I( ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2i
	*/
	IntrinsicCallPtr makeBitfieldReverse2I( ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3i
	*/
	IntrinsicCallPtr makeBitfieldReverse3I( ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4i
	*/
	IntrinsicCallPtr makeBitfieldReverse4I( ExprPtr value );
	/**
	*@return
	*	uint
	*@param value
	*	uint
	*/
	IntrinsicCallPtr makeBitfieldReverse1U( ExprPtr value );
	/**
	*@return
	*	vec2u
	*@param value
	*	vec2u
	*/
	IntrinsicCallPtr makeBitfieldReverse2U( ExprPtr value );
	/**
	*@return
	*	vec3u
	*@param value
	*	vec3u
	*/
	IntrinsicCallPtr makeBitfieldReverse3U( ExprPtr value );
	/**
	*@return
	*	vec4u
	*@param value
	*	vec4u
	*/
	IntrinsicCallPtr makeBitfieldReverse4U( ExprPtr value );
	/**
	*@return
	*	int
	*@param value
	*	int
	*/
	IntrinsicCallPtr makeBitCount1I( ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2i
	*/
	IntrinsicCallPtr makeBitCount2I( ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3i
	*/
	IntrinsicCallPtr makeBitCount3I( ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4i
	*/
	IntrinsicCallPtr makeBitCount4I( ExprPtr value );
	/**
	*@return
	*	uint
	*@param value
	*	uint
	*/
	IntrinsicCallPtr makeBitCount1U( ExprPtr value );
	/**
	*@return
	*	vec2u
	*@param value
	*	vec2u
	*/
	IntrinsicCallPtr makeBitCount2U( ExprPtr value );
	/**
	*@return
	*	vec3u
	*@param value
	*	vec3u
	*/
	IntrinsicCallPtr makeBitCount3U( ExprPtr value );
	/**
	*@return
	*	vec4u
	*@param value
	*	vec4u
	*/
	IntrinsicCallPtr makeBitCount4U( ExprPtr value );
	/**
	*@return
	*	int
	*@param value
	*	int
	*/
	IntrinsicCallPtr makeFindLSB1I( ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2i
	*/
	IntrinsicCallPtr makeFindLSB2I( ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3i
	*/
	IntrinsicCallPtr makeFindLSB3I( ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4i
	*/
	IntrinsicCallPtr makeFindLSB4I( ExprPtr value );
	/**
	*@return
	*	int
	*@param value
	*	uint
	*/
	IntrinsicCallPtr makeFindLSB1U( ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2u
	*/
	IntrinsicCallPtr makeFindLSB2U( ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3u
	*/
	IntrinsicCallPtr makeFindLSB3U( ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4u
	*/
	IntrinsicCallPtr makeFindLSB4U( ExprPtr value );
	/**
	*@return
	*	int
	*@param value
	*	int
	*/
	IntrinsicCallPtr makeFindMSB1I( ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2i
	*/
	IntrinsicCallPtr makeFindMSB2I( ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3i
	*/
	IntrinsicCallPtr makeFindMSB3I( ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4i
	*/
	IntrinsicCallPtr makeFindMSB4I( ExprPtr value );
	/**
	*@return
	*	int
	*@param value
	*	uint
	*/
	IntrinsicCallPtr makeFindMSB1U( ExprPtr value );
	/**
	*@return
	*	vec2i
	*@param value
	*	vec2u
	*/
	IntrinsicCallPtr makeFindMSB2U( ExprPtr value );
	/**
	*@return
	*	vec3i
	*@param value
	*	vec3u
	*/
	IntrinsicCallPtr makeFindMSB3U( ExprPtr value );
	/**
	*@return
	*	vec4i
	*@param value
	*	vec4u
	*/
	IntrinsicCallPtr makeFindMSB4U( ExprPtr value );
	// Atomic Memory Functions

	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicAddI( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicAddU( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicMinI( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicMinU( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicMaxI( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicMaxU( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicAndI( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicAndU( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicOrI( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicOrU( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicXorI( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicXorU( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param data
	*	int
	*/
	IntrinsicCallPtr makeAtomicExchangeI( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param data
	*	uint
	*/
	IntrinsicCallPtr makeAtomicExchangeU( ExprPtr mem, ExprPtr data );
	/**
	*@return
	*	int
	*@param mem
	*	int
	*@param compare
	*	uint
	*/
	IntrinsicCallPtr makeAtomicCompSwapI( ExprPtr mem, ExprPtr compare );
	/**
	*@return
	*	uint
	*@param mem
	*	uint
	*@param compare
	*	uint
	*/
	IntrinsicCallPtr makeAtomicCompSwapU( ExprPtr mem, ExprPtr compare );
	// Derivative Functions

	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdx1( ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdx2( ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdx3( ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdx4( ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdxCoarse1( ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdxCoarse2( ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdxCoarse3( ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdxCoarse4( ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdxFine1( ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdxFine2( ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdxFine3( ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdxFine4( ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdy1( ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdy2( ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdy3( ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdy4( ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdyCoarse1( ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdyCoarse2( ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdyCoarse3( ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdyCoarse4( ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeDFdyFine1( ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeDFdyFine2( ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeDFdyFine3( ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeDFdyFine4( ExprPtr p );
	/**
	*@return
	*	float
	*@param p
	*	float
	*/
	IntrinsicCallPtr makeFwidth1( ExprPtr p );
	/**
	*@return
	*	vec2f
	*@param p
	*	vec2f
	*/
	IntrinsicCallPtr makeFwidth2( ExprPtr p );
	/**
	*@return
	*	vec3f
	*@param p
	*	vec3f
	*/
	IntrinsicCallPtr makeFwidth3( ExprPtr p );
	/**
	*@return
	*	vec4f
	*@param p
	*	vec4f
	*/
	IntrinsicCallPtr makeFwidth4( ExprPtr p );
	// Interpolation Functions

	/**
	*@return
	*	float
	*@param x
	*	float
	*/
	IntrinsicCallPtr makeInterpolateAtCentroid1( ExprPtr x );
	/**
	*@return
	*	vec2f
	*@param x
	*	vec2f
	*/
	IntrinsicCallPtr makeInterpolateAtCentroid2( ExprPtr x );
	/**
	*@return
	*	vec3f
	*@param x
	*	vec3f
	*/
	IntrinsicCallPtr makeInterpolateAtCentroid3( ExprPtr x );
	/**
	*@return
	*	vec4f
	*@param x
	*	vec4f
	*/
	IntrinsicCallPtr makeInterpolateAtCentroid4( ExprPtr x );
	/**
	*@return
	*	float
	*@param interpolant
	*	float
	*@param sample
	*	int
	*/
	IntrinsicCallPtr makeInterpolateAtSample1( ExprPtr interpolant, ExprPtr sample );
	/**
	*@return
	*	vec2f
	*@param interpolant
	*	vec2f
	*@param sample
	*	int
	*/
	IntrinsicCallPtr makeInterpolateAtSample2( ExprPtr interpolant, ExprPtr sample );
	/**
	*@return
	*	vec3f
	*@param interpolant
	*	vec3f
	*@param sample
	*	int
	*/
	IntrinsicCallPtr makeInterpolateAtSample3( ExprPtr interpolant, ExprPtr sample );
	/**
	*@return
	*	vec4f
	*@param interpolant
	*	vec4f
	*@param sample
	*	int
	*/
	IntrinsicCallPtr makeInterpolateAtSample4( ExprPtr interpolant, ExprPtr sample );
	/**
	*@return
	*	float
	*@param interpolant
	*	float
	*@param offset
	*	vec2f
	*/
	IntrinsicCallPtr makeInterpolateAtOffset1( ExprPtr interpolant, ExprPtr offset );
	/**
	*@return
	*	vec2f
	*@param interpolant
	*	vec2f
	*@param offset
	*	vec2f
	*/
	IntrinsicCallPtr makeInterpolateAtOffset2( ExprPtr interpolant, ExprPtr offset );
	/**
	*@return
	*	vec3f
	*@param interpolant
	*	vec3f
	*@param offset
	*	vec2f
	*/
	IntrinsicCallPtr makeInterpolateAtOffset3( ExprPtr interpolant, ExprPtr offset );
	/**
	*@return
	*	vec4f
	*@param interpolant
	*	vec4f
	*@param offset
	*	vec2f
	*/
	IntrinsicCallPtr makeInterpolateAtOffset4( ExprPtr interpolant, ExprPtr offset );
	// Geometry Shader Functions

	/**
	*@return
	*	void
	*@param stream
	*	int
	*/
	IntrinsicCallPtr makeEmitStreamVertex( ExprPtr stream );
	/**
	*@return
	*	void
	*@param stream
	*	int
	*/
	IntrinsicCallPtr makeEndStreamPrimitive( ExprPtr stream );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeEmitVertex( );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeEndPrimitive( );
	// Shader Invocation Control Functions

	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeBarrier( );
	// Shader Memory Control Functions

	/**
	*@return
	*	uint
	*/
	IntrinsicCallPtr makeMemoryBarrier( );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeMemoryBarrierBuffer( );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeMemoryBarrierShared( );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeMemoryBarrierImage( );
	/**
	*@return
	*	void
	*/
	IntrinsicCallPtr makeGroupMemoryBarrier( );}

#endif
