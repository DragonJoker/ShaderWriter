/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMakeIntrinsic_H___
#define ___AST_ExprMakeIntrinsic_H___
#pragma once

#include "ExprIntrinsicCall.hpp"

namespace ast::expr
{	// Angle and Trigonometry Functions

	inline IntrinsicCallPtr/*float*/ makeDegrees1( ExprPtr/*float*/ radians )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDegrees1
			, std::move( radians ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeDegrees2( ExprPtr/*vec2f*/ radians )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDegrees2
			, std::move( radians ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeDegrees3( ExprPtr/*vec3f*/ radians )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDegrees3
			, std::move( radians ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeDegrees4( ExprPtr/*vec4f*/ radians )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDegrees4
			, std::move( radians ) );
	}

	inline IntrinsicCallPtr/*float*/ makeRadians1F( ExprPtr/*float*/ degrees )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eRadians1F
			, std::move( degrees ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeRadians2F( ExprPtr/*vec2f*/ degrees )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eRadians2F
			, std::move( degrees ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeRadians3F( ExprPtr/*vec3f*/ degrees )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eRadians3F
			, std::move( degrees ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeRadians4F( ExprPtr/*vec4f*/ degrees )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eRadians4F
			, std::move( degrees ) );
	}

	inline IntrinsicCallPtr/*float*/ makeCos1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eCos1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeCos2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eCos2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeCos3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eCos3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeCos4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eCos4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeSin1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eSin1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeSin2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSin2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeSin3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSin3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeSin4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSin4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeTan1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eTan1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeTan2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eTan2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeTan3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eTan3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeTan4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eTan4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeCosh1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eCosh1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeCosh2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eCosh2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeCosh3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eCosh3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeCosh4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eCosh4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeSinh1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eSinh1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeSinh2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSinh2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeSinh3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSinh3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeSinh4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSinh4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeTanh1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eTanh1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeTanh2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eTanh2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeTanh3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eTanh3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeTanh4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eTanh4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeAcos1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAcos1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeAcos2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAcos2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeAcos3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAcos3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeAcos4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAcos4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeAsin1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAsin1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeAsin2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAsin2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeAsin3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAsin3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeAsin4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAsin4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeAtan1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAtan1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeAtan2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAtan2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeAtan3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAtan3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeAtan4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAtan4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeAcosh1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAcosh1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeAcosh2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAcosh2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeAcosh3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAcosh3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeAcosh4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAcosh4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeAsinh1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAsinh1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeAsinh2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAsinh2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeAsinh3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAsinh3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeAsinh4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAsinh4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeAtanh1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAtanh1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeAtanh2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAtanh2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeAtanh3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAtanh3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeAtanh4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAtanh4
			, std::move( x ) );
	}

	// Exponential Functions

	inline IntrinsicCallPtr/*float*/ makePow1( ExprPtr/*float*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::ePow1
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makePow2( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::ePow2
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makePow3( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::ePow3
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makePow4( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::ePow4
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*float*/ makeExp1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eExp1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeExp2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eExp2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeExp3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eExp3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeExp4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eExp4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeLog1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLog1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeLog2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eLog2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeLog3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eLog3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeLog4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eLog4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeExp21( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eExp21
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeExp22( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eExp22
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeExp23( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eExp23
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeExp24( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eExp24
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeLog21( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLog21
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeLog22( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eLog22
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeLog23( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eLog23
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeLog24( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eLog24
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeSqrt1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eSqrt1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeSqrt2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSqrt2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeSqrt3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSqrt3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeSqrt4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSqrt4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeSqrt1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eSqrt1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeSqrt2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eSqrt2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeSqrt3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eSqrt3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeSqrt4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eSqrt4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeInverseSqrt1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eInverseSqrt1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeInverseSqrt2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eInverseSqrt2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeInverseSqrt3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eInverseSqrt3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeInverseSqrt4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eInverseSqrt4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeInverseSqrt1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eInverseSqrt1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeInverseSqrt2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eInverseSqrt2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeInverseSqrt3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eInverseSqrt3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeInverseSqrt4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eInverseSqrt4D
			, std::move( x ) );
	}

	// Common Functions

	inline IntrinsicCallPtr/*float*/ makeAbs1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAbs1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeAbs2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAbs2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeAbs3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAbs3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeAbs4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAbs4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*int*/ makeAbs1I( ExprPtr/*int*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAbs1I
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeAbs2I( ExprPtr/*vec2i*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eAbs2I
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeAbs3I( ExprPtr/*vec3i*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eAbs3I
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeAbs4I( ExprPtr/*vec4i*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eAbs4I
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeAbs1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eAbs1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeAbs2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eAbs2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeAbs3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eAbs3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeAbs4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eAbs4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeSign1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eSign1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeSign2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSign2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeSign3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSign3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeSign4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSign4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*int*/ makeSign1I( ExprPtr/*int*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eSign1I
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeSign2I( ExprPtr/*vec2i*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eSign2I
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeSign3I( ExprPtr/*vec3i*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eSign3I
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeSign4I( ExprPtr/*vec4i*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eSign4I
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeSign1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eSign1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeSign2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eSign2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeSign3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eSign3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeSign4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eSign4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeFloor1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFloor1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeFloor2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFloor2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeFloor3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFloor3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeFloor4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFloor4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeFloor1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eFloor1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeFloor2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eFloor2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeFloor3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eFloor3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeFloor4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eFloor4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeTrunc1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eTrunc1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeTrunc2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eTrunc2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeTrunc3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eTrunc3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeTrunc4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eTrunc4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeTrunc1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eTrunc1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeTrunc2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eTrunc2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeTrunc3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eTrunc3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeTrunc4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eTrunc4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeRound1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eRound1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeRound2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eRound2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeRound3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eRound3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeRound4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eRound4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeRound1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eRound1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeRound2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eRound2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeRound3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eRound3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeRound4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eRound4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeRoundEven1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eRoundEven1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeRoundEven2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eRoundEven2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeRoundEven3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eRoundEven3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeRoundEven4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eRoundEven4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeRoundEven1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eRoundEven1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeRoundEven2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eRoundEven2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeRoundEven3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eRoundEven3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeRoundEven4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eRoundEven4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeCeil1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eCeil1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeCeil2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eCeil2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeCeil3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eCeil3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeCeil4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eCeil4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeCeil1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eCeil1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeCeil2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eCeil2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeCeil3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eCeil3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeCeil4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eCeil4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeFract1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFract1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeFract2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFract2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeFract3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFract3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeFract4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFract4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeFract1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eFract1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeFract2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eFract2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeFract3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eFract3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeFract4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eFract4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeMod11F( ExprPtr/*float*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eMod11F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeMod22F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMod22F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeMod33F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMod33F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeMod44F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMod44F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeMod21F( ExprPtr/*vec2f*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMod21F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeMod31F( ExprPtr/*vec3f*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMod31F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeMod41F( ExprPtr/*vec4f*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMod41F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*double*/ makeMod11D( ExprPtr/*double*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eMod11D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeMod22D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMod22D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeMod33D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMod33D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeMod44D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMod44D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeMod21D( ExprPtr/*vec2d*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMod21D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeMod31D( ExprPtr/*vec3d*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMod31D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeMod41D( ExprPtr/*vec4d*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMod41D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*float*/ makeModf1F( ExprPtr/*float*/ x
		, ExprPtr/*float*/ i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eModf1F
			, std::move( x )
			, std::move( i ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeModf2F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eModf2F
			, std::move( x )
			, std::move( i ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeModf3F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eModf3F
			, std::move( x )
			, std::move( i ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeModf4F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eModf4F
			, std::move( x )
			, std::move( i ) );
	}

	inline IntrinsicCallPtr/*double*/ makeModf1D( ExprPtr/*double*/ x
		, ExprPtr/*double*/ i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eModf1D
			, std::move( x )
			, std::move( i ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeModf2D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eModf2D
			, std::move( x )
			, std::move( i ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeModf3D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eModf3D
			, std::move( x )
			, std::move( i ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeModf4D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eModf4D
			, std::move( x )
			, std::move( i ) );
	}

	inline IntrinsicCallPtr/*float*/ makeMin11F( ExprPtr/*float*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eMin11F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeMin22F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMin22F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeMin33F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMin33F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeMin44F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMin44F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeMin21F( ExprPtr/*vec2f*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMin21F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeMin31F( ExprPtr/*vec3f*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMin31F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeMin41F( ExprPtr/*vec4f*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMin41F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*double*/ makeMin11D( ExprPtr/*double*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eMin11D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeMin22D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMin22D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeMin33D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMin33D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeMin44D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMin44D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeMin21D( ExprPtr/*vec2d*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMin21D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeMin31D( ExprPtr/*vec3d*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMin31D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeMin41D( ExprPtr/*vec4d*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMin41D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*int*/ makeMin11I( ExprPtr/*int*/ x
		, ExprPtr/*int*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eMin11I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeMin22I( ExprPtr/*vec2i*/ x
		, ExprPtr/*vec2i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eMin22I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeMin33I( ExprPtr/*vec3i*/ x
		, ExprPtr/*vec3i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eMin33I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeMin44I( ExprPtr/*vec4i*/ x
		, ExprPtr/*vec4i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eMin44I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeMin21I( ExprPtr/*vec2i*/ x
		, ExprPtr/*int*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eMin21I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeMin31I( ExprPtr/*vec3i*/ x
		, ExprPtr/*int*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eMin31I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeMin41I( ExprPtr/*vec4i*/ x
		, ExprPtr/*int*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eMin41I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeMin11U( ExprPtr/*uint*/ x
		, ExprPtr/*uint*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eMin11U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeMin22U( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eMin22U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeMin33U( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eMin33U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeMin44U( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eMin44U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeMin21U( ExprPtr/*vec2u*/ x
		, ExprPtr/*uint*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eMin21U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeMin31U( ExprPtr/*vec3u*/ x
		, ExprPtr/*uint*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eMin31U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeMin41U( ExprPtr/*vec4u*/ x
		, ExprPtr/*uint*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eMin41U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*float*/ makeMax11F( ExprPtr/*float*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eMax11F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeMax22F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMax22F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeMax33F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMax33F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeMax44F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMax44F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeMax21F( ExprPtr/*vec2f*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMax21F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeMax31F( ExprPtr/*vec3f*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMax31F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeMax41F( ExprPtr/*vec4f*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMax41F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*double*/ makeMax11D( ExprPtr/*double*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eMax11D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeMax22D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMax22D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeMax33D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMax33D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeMax44D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMax44D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeMax21D( ExprPtr/*vec2d*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMax21D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeMax31D( ExprPtr/*vec3d*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMax31D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeMax41D( ExprPtr/*vec4d*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMax41D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*int*/ makeMax11I( ExprPtr/*int*/ x
		, ExprPtr/*int*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eMax11I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeMax22I( ExprPtr/*vec2i*/ x
		, ExprPtr/*vec2i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eMax22I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeMax33I( ExprPtr/*vec3i*/ x
		, ExprPtr/*vec3i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eMax33I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeMax44I( ExprPtr/*vec4i*/ x
		, ExprPtr/*vec4i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eMax44I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeMax21I( ExprPtr/*vec2i*/ x
		, ExprPtr/*int*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eMax21I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeMax31I( ExprPtr/*vec3i*/ x
		, ExprPtr/*int*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eMax31I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeMax41I( ExprPtr/*vec4i*/ x
		, ExprPtr/*int*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eMax41I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeMax11U( ExprPtr/*uint*/ x
		, ExprPtr/*uint*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eMax11U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeMax22U( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eMax22U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeMax33U( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eMax33U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeMax44U( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eMax44U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeMax21U( ExprPtr/*vec2u*/ x
		, ExprPtr/*uint*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eMax21U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeMax31U( ExprPtr/*vec3u*/ x
		, ExprPtr/*uint*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eMax31U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeMax41U( ExprPtr/*vec4u*/ x
		, ExprPtr/*uint*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eMax41U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*float*/ makeClamp11F( ExprPtr/*float*/ x
		, ExprPtr/*float*/ minVal
		, ExprPtr/*float*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eClamp11F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeClamp22F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ minVal
		, ExprPtr/*vec2f*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eClamp22F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeClamp33F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ minVal
		, ExprPtr/*vec3f*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eClamp33F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeClamp44F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ minVal
		, ExprPtr/*vec4f*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eClamp44F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeClamp21F( ExprPtr/*vec2f*/ x
		, ExprPtr/*float*/ minVal
		, ExprPtr/*float*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eClamp21F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeClamp31F( ExprPtr/*vec3f*/ x
		, ExprPtr/*float*/ minVal
		, ExprPtr/*float*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eClamp31F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeClamp41F( ExprPtr/*vec4f*/ x
		, ExprPtr/*float*/ minVal
		, ExprPtr/*float*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eClamp41F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*double*/ makeClamp11D( ExprPtr/*double*/ x
		, ExprPtr/*double*/ minVal
		, ExprPtr/*double*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eClamp11D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeClamp22D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ minVal
		, ExprPtr/*vec2d*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eClamp22D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeClamp33D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ minVal
		, ExprPtr/*vec3d*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eClamp33D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeClamp44D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ minVal
		, ExprPtr/*vec4d*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eClamp44D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeClamp21D( ExprPtr/*vec2d*/ x
		, ExprPtr/*double*/ minVal
		, ExprPtr/*double*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eClamp21D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeClamp31D( ExprPtr/*vec3d*/ x
		, ExprPtr/*double*/ minVal
		, ExprPtr/*double*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eClamp31D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeClamp41D( ExprPtr/*vec4d*/ x
		, ExprPtr/*double*/ minVal
		, ExprPtr/*double*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eClamp41D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*int*/ makeClamp11I( ExprPtr/*int*/ x
		, ExprPtr/*int*/ minVal
		, ExprPtr/*int*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eClamp11I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeClamp22I( ExprPtr/*vec2i*/ x
		, ExprPtr/*vec2i*/ minVal
		, ExprPtr/*vec2i*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eClamp22I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeClamp33I( ExprPtr/*vec3i*/ x
		, ExprPtr/*vec3i*/ minVal
		, ExprPtr/*vec3i*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eClamp33I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeClamp44I( ExprPtr/*vec4i*/ x
		, ExprPtr/*vec4i*/ minVal
		, ExprPtr/*vec4i*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eClamp44I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeClamp21I( ExprPtr/*vec2i*/ x
		, ExprPtr/*int*/ minVal
		, ExprPtr/*int*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eClamp21I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeClamp31I( ExprPtr/*vec3i*/ x
		, ExprPtr/*int*/ minVal
		, ExprPtr/*int*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eClamp31I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeClamp41I( ExprPtr/*vec4i*/ x
		, ExprPtr/*int*/ minVal
		, ExprPtr/*int*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eClamp41I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeClamp11U( ExprPtr/*uint*/ x
		, ExprPtr/*uint*/ minVal
		, ExprPtr/*uint*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eClamp11U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeClamp22U( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ minVal
		, ExprPtr/*vec2u*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eClamp22U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeClamp33U( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ minVal
		, ExprPtr/*vec3u*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eClamp33U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeClamp44U( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ minVal
		, ExprPtr/*vec4u*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eClamp44U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeClamp21U( ExprPtr/*vec2u*/ x
		, ExprPtr/*uint*/ minVal
		, ExprPtr/*uint*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eClamp21U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeClamp31U( ExprPtr/*vec3u*/ x
		, ExprPtr/*uint*/ minVal
		, ExprPtr/*uint*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eClamp31U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeClamp41U( ExprPtr/*vec4u*/ x
		, ExprPtr/*uint*/ minVal
		, ExprPtr/*uint*/ maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eClamp41U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	inline IntrinsicCallPtr/*float*/ makeMix11F( ExprPtr/*float*/ x
		, ExprPtr/*float*/ y
		, ExprPtr/*float*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eMix11F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeMix22F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y
		, ExprPtr/*vec2f*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMix22F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeMix33F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y
		, ExprPtr/*vec3f*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMix33F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeMix44F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y
		, ExprPtr/*vec4f*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMix44F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeMix21F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y
		, ExprPtr/*float*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMix21F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeMix31F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y
		, ExprPtr/*float*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMix31F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeMix41F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y
		, ExprPtr/*float*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMix41F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*float*/ makeMix11FB( ExprPtr/*float*/ x
		, ExprPtr/*float*/ y
		, ExprPtr/*boolean*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eMix11FB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeMix22FB( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y
		, ExprPtr/*vec2b*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMix22FB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeMix33FB( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y
		, ExprPtr/*vec3b*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMix33FB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeMix44FB( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y
		, ExprPtr/*vec4b*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMix44FB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*double*/ makeMix11D( ExprPtr/*double*/ x
		, ExprPtr/*double*/ y
		, ExprPtr/*double*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eMix11D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeMix22D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y
		, ExprPtr/*vec2d*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMix22D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeMix33D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y
		, ExprPtr/*vec3d*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMix33D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeMix44D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y
		, ExprPtr/*vec4d*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMix44D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeMix21D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y
		, ExprPtr/*double*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMix21D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeMix31D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y
		, ExprPtr/*double*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMix31D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeMix41D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y
		, ExprPtr/*double*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMix41D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*double*/ makeMix11DB( ExprPtr/*double*/ x
		, ExprPtr/*double*/ y
		, ExprPtr/*boolean*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eMix11DB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeMix22DB( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y
		, ExprPtr/*vec2b*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMix22DB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeMix33DB( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y
		, ExprPtr/*vec3b*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMix33DB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeMix44DB( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y
		, ExprPtr/*vec4b*/ a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMix44DB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	inline IntrinsicCallPtr/*float*/ makeStep11F( ExprPtr/*float*/ edge
		, ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eStep11F
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeStep22F( ExprPtr/*vec2f*/ edge
		, ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eStep22F
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeStep33F( ExprPtr/*vec3f*/ edge
		, ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eStep33F
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeStep44F( ExprPtr/*vec4f*/ edge
		, ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eStep44F
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeStep12F( ExprPtr/*float*/ edge
		, ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eStep12F
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeStep13F( ExprPtr/*float*/ edge
		, ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eStep13F
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeStep14F( ExprPtr/*float*/ edge
		, ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eStep14F
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeStep11D( ExprPtr/*double*/ edge
		, ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eStep11D
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeStep22D( ExprPtr/*vec2d*/ edge
		, ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eStep22D
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeStep33D( ExprPtr/*vec3d*/ edge
		, ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eStep33D
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeStep44D( ExprPtr/*vec4d*/ edge
		, ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eStep44D
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeStep12D( ExprPtr/*double*/ edge
		, ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eStep12D
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeStep13D( ExprPtr/*double*/ edge
		, ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eStep13D
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeStep14D( ExprPtr/*double*/ edge
		, ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eStep14D
			, std::move( edge )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeSmoothStep11F( ExprPtr/*float*/ edge0
		, ExprPtr/*float*/ edge1
		, ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eSmoothStep11F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeSmoothStep22F( ExprPtr/*vec2f*/ edge0
		, ExprPtr/*vec2f*/ edge1
		, ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSmoothStep22F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeSmoothStep33F( ExprPtr/*vec3f*/ edge0
		, ExprPtr/*vec3f*/ edge1
		, ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSmoothStep33F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeSmoothStep44F( ExprPtr/*vec4f*/ edge0
		, ExprPtr/*vec4f*/ edge1
		, ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSmoothStep44F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeSmoothStep12F( ExprPtr/*float*/ edge0
		, ExprPtr/*float*/ edge1
		, ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSmoothStep12F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeSmoothStep13F( ExprPtr/*float*/ edge0
		, ExprPtr/*float*/ edge1
		, ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSmoothStep13F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeSmoothStep14F( ExprPtr/*float*/ edge0
		, ExprPtr/*float*/ edge1
		, ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSmoothStep14F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeSmoothStep11D( ExprPtr/*double*/ edge0
		, ExprPtr/*double*/ edge1
		, ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eSmoothStep11D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeSmoothStep22D( ExprPtr/*vec2d*/ edge0
		, ExprPtr/*vec2d*/ edge1
		, ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eSmoothStep22D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeSmoothStep33D( ExprPtr/*vec3d*/ edge0
		, ExprPtr/*vec3d*/ edge1
		, ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eSmoothStep33D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeSmoothStep44D( ExprPtr/*vec4d*/ edge0
		, ExprPtr/*vec4d*/ edge1
		, ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eSmoothStep44D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeSmoothStep12D( ExprPtr/*double*/ edge0
		, ExprPtr/*double*/ edge1
		, ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eSmoothStep12D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeSmoothStep13D( ExprPtr/*double*/ edge0
		, ExprPtr/*double*/ edge1
		, ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eSmoothStep13D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeSmoothStep14D( ExprPtr/*double*/ edge0
		, ExprPtr/*double*/ edge1
		, ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eSmoothStep14D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*boolean*/ makeIsnan1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eIsnan1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeIsnan2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eIsnan2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeIsnan3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eIsnan3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeIsnan4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eIsnan4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*boolean*/ makeIsnan1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eIsnan1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeIsnan2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eIsnan2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeIsnan3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eIsnan3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeIsnan4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eIsnan4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*boolean*/ makeIsinf1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eIsinf1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeIsinf2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eIsinf2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeIsinf3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eIsinf3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeIsinf4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eIsinf4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*boolean*/ makeIsinf1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eIsinf1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeIsinf2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eIsinf2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeIsinf3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eIsinf3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeIsinf4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eIsinf4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*int*/ makeFloatBitsToInt1( ExprPtr/*float*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eFloatBitsToInt1
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeFloatBitsToInt2( ExprPtr/*vec2f*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eFloatBitsToInt2
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeFloatBitsToInt3( ExprPtr/*vec3f*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eFloatBitsToInt3
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeFloatBitsToInt4( ExprPtr/*vec4f*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eFloatBitsToInt4
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeFloatBitsToUInt1( ExprPtr/*float*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eFloatBitsToUInt1
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeFloatBitsToUInt2( ExprPtr/*vec2f*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eFloatBitsToUInt2
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeFloatBitsToUInt3( ExprPtr/*vec3f*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eFloatBitsToUInt3
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeFloatBitsToUInt4( ExprPtr/*vec4f*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eFloatBitsToUInt4
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*float*/ makeIntBitsToFloat1( ExprPtr/*int*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eIntBitsToFloat1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeIntBitsToFloat2( ExprPtr/*vec2i*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eIntBitsToFloat2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeIntBitsToFloat3( ExprPtr/*vec3i*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eIntBitsToFloat3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeIntBitsToFloat4( ExprPtr/*vec4i*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eIntBitsToFloat4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeUintBitsToFloat1( ExprPtr/*uint*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eUintBitsToFloat1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeUintBitsToFloat2( ExprPtr/*vec2u*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eUintBitsToFloat2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeUintBitsToFloat3( ExprPtr/*vec3u*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eUintBitsToFloat3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeUintBitsToFloat4( ExprPtr/*vec4u*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eUintBitsToFloat4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeFma1F( ExprPtr/*float*/ a
		, ExprPtr/*float*/ b
		, ExprPtr/*float*/ c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFma1F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeFma2F( ExprPtr/*vec2f*/ a
		, ExprPtr/*vec2f*/ b
		, ExprPtr/*vec2f*/ c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFma2F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeFma3F( ExprPtr/*vec3f*/ a
		, ExprPtr/*vec3f*/ b
		, ExprPtr/*vec3f*/ c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFma3F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeFma4F( ExprPtr/*vec4f*/ a
		, ExprPtr/*vec4f*/ b
		, ExprPtr/*vec4f*/ c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFma4F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	inline IntrinsicCallPtr/*double*/ makeFma1D( ExprPtr/*double*/ a
		, ExprPtr/*double*/ b
		, ExprPtr/*double*/ c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eFma1D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeFma2D( ExprPtr/*vec2d*/ a
		, ExprPtr/*vec2d*/ b
		, ExprPtr/*vec2d*/ c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eFma2D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeFma3D( ExprPtr/*vec3d*/ a
		, ExprPtr/*vec3d*/ b
		, ExprPtr/*vec3d*/ c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eFma3D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeFma4D( ExprPtr/*vec4d*/ a
		, ExprPtr/*vec4d*/ b
		, ExprPtr/*vec4d*/ c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eFma4D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	inline IntrinsicCallPtr/*float*/ makeFrexp1F( ExprPtr/*float*/ x
		, ExprPtr/*int*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFrexp1F
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeFrexp2F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFrexp2F
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeFrexp3F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFrexp3F
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeFrexp4F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFrexp4F
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*double*/ makeFrexp1D( ExprPtr/*double*/ x
		, ExprPtr/*int*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eFrexp1D
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeFrexp2D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eFrexp2D
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeFrexp3D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eFrexp3D
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeFrexp4D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eFrexp4D
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*float*/ makeLdexp1F( ExprPtr/*float*/ x
		, ExprPtr/*int*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLdexp1F
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeLdexp2F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eLdexp2F
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeLdexp3F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eLdexp3F
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeLdexp4F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eLdexp4F
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*double*/ makeLdexp1D( ExprPtr/*double*/ x
		, ExprPtr/*int*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eLdexp1D
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeLdexp2D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eLdexp2D
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeLdexp3D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eLdexp3D
			, std::move( x )
			, std::move( exp ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeLdexp4D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4i*/ exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eLdexp4D
			, std::move( x )
			, std::move( exp ) );
	}

	// Floating-point Pack and Unpack Functions

	inline IntrinsicCallPtr/*double*/ makePackDouble2x32( ExprPtr/*vec2u*/ v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::ePackDouble2x32
			, std::move( v ) );
	}

	inline IntrinsicCallPtr/*uint*/ makePackHalf2x16( ExprPtr/*vec2f*/ v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::ePackHalf2x16
			, std::move( v ) );
	}

	inline IntrinsicCallPtr/*uint*/ makePackSnorm2x16( ExprPtr/*vec2f*/ v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::ePackSnorm2x16
			, std::move( v ) );
	}

	inline IntrinsicCallPtr/*uint*/ makePackSnorm4x8( ExprPtr/*vec4f*/ v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::ePackSnorm4x8
			, std::move( v ) );
	}

	inline IntrinsicCallPtr/*uint*/ makePackUnorm2x16( ExprPtr/*vec2f*/ v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::ePackUnorm2x16
			, std::move( v ) );
	}

	inline IntrinsicCallPtr/*uint*/ makePackUnorm4x8( ExprPtr/*vec4f*/ v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::ePackUnorm4x8
			, std::move( v ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeUnpackDouble2x32( ExprPtr/*double*/ d )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eUnpackDouble2x32
			, std::move( d ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeUnpackHalf2x16( ExprPtr/*uint*/ v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eUnpackHalf2x16
			, std::move( v ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeUnpackSnorm2x16( ExprPtr/*uint*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eUnpackSnorm2x16
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeUnpackSnorm4x8( ExprPtr/*uint*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eUnpackSnorm4x8
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeUnpackUnorm2x16( ExprPtr/*uint*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eUnpackUnorm2x16
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeUnpackUnorm4x8( ExprPtr/*uint*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eUnpackUnorm4x8
			, std::move( p ) );
	}

	// Geometric Functions

	inline IntrinsicCallPtr/*float*/ makeLength1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLength1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeLength2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLength2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeLength3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLength3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeLength4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLength4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeLength1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eLength1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeLength2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eLength2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeLength3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eLength3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeLength4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eLength4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDistance1F( ExprPtr/*float*/ p0
		, ExprPtr/*float*/ p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDistance1F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeDistance2F( ExprPtr/*vec2f*/ p0
		, ExprPtr/*vec2f*/ p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDistance2F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeDistance3F( ExprPtr/*vec3f*/ p0
		, ExprPtr/*vec3f*/ p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDistance3F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeDistance4F( ExprPtr/*vec4f*/ p0
		, ExprPtr/*vec4f*/ p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDistance4F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	inline IntrinsicCallPtr/*double*/ makeDistance1D( ExprPtr/*double*/ p0
		, ExprPtr/*double*/ p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDistance1D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	inline IntrinsicCallPtr/*double*/ makeDistance2D( ExprPtr/*vec2d*/ p0
		, ExprPtr/*vec2d*/ p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDistance2D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	inline IntrinsicCallPtr/*double*/ makeDistance3D( ExprPtr/*vec3d*/ p0
		, ExprPtr/*vec3d*/ p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDistance3D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	inline IntrinsicCallPtr/*double*/ makeDistance4D( ExprPtr/*vec4d*/ p0
		, ExprPtr/*vec4d*/ p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDistance4D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDot1F( ExprPtr/*float*/ x
		, ExprPtr/*float*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDot1F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDot2F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDot2F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDot3F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDot3F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDot4F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDot4F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*double*/ makeDot1D( ExprPtr/*double*/ x
		, ExprPtr/*double*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDot1D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*double*/ makeDot2D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDot2D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*double*/ makeDot3D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDot3D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*double*/ makeDot4D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDot4D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeCrossF( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eCrossF
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeCrossD( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eCrossD
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*float*/ makeNormalize1F( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eNormalize1F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeNormalize2F( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eNormalize2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeNormalize3F( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eNormalize3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeNormalize4F( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eNormalize4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*double*/ makeNormalize1D( ExprPtr/*double*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eNormalize1D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeNormalize2D( ExprPtr/*vec2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eNormalize2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeNormalize3D( ExprPtr/*vec3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eNormalize3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeNormalize4D( ExprPtr/*vec4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eNormalize4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeFaceForward1F( ExprPtr/*float*/ N
		, ExprPtr/*float*/ I
		, ExprPtr/*float*/ Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFaceForward1F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeFaceForward2F( ExprPtr/*vec2f*/ N
		, ExprPtr/*vec2f*/ I
		, ExprPtr/*vec2f*/ Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFaceForward2F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeFaceForward3F( ExprPtr/*vec3f*/ N
		, ExprPtr/*vec3f*/ I
		, ExprPtr/*vec3f*/ Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFaceForward3F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeFaceForward4F( ExprPtr/*vec4f*/ N
		, ExprPtr/*vec4f*/ I
		, ExprPtr/*vec4f*/ Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFaceForward4F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	inline IntrinsicCallPtr/*double*/ makeFaceForward1D( ExprPtr/*double*/ N
		, ExprPtr/*double*/ I
		, ExprPtr/*double*/ Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eFaceForward1D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeFaceForward2D( ExprPtr/*vec2d*/ N
		, ExprPtr/*vec2d*/ I
		, ExprPtr/*vec2d*/ Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eFaceForward2D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeFaceForward3D( ExprPtr/*vec3d*/ N
		, ExprPtr/*vec3d*/ I
		, ExprPtr/*vec3d*/ Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eFaceForward3D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeFaceForward4D( ExprPtr/*vec4d*/ N
		, ExprPtr/*vec4d*/ I
		, ExprPtr/*vec4d*/ Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eFaceForward4D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	inline IntrinsicCallPtr/*float*/ makeReflect1F( ExprPtr/*float*/ I
		, ExprPtr/*float*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eReflect1F
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeReflect2F( ExprPtr/*vec2f*/ I
		, ExprPtr/*vec2f*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eReflect2F
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeReflect3F( ExprPtr/*vec3f*/ I
		, ExprPtr/*vec3f*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eReflect3F
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeReflect4F( ExprPtr/*vec4f*/ I
		, ExprPtr/*vec4f*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eReflect4F
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*double*/ makeReflect1D( ExprPtr/*float*/ I
		, ExprPtr/*double*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eReflect1D
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeReflect2D( ExprPtr/*vec2d*/ I
		, ExprPtr/*vec2d*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eReflect2D
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeReflect3D( ExprPtr/*vec3d*/ I
		, ExprPtr/*vec3d*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eReflect3D
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeReflect4D( ExprPtr/*vec4d*/ I
		, ExprPtr/*vec4d*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eReflect4D
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*float*/ makeRefract1F( ExprPtr/*float*/ I
		, ExprPtr/*float*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eRefract1F
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeRefract2F( ExprPtr/*vec2f*/ I
		, ExprPtr/*vec2f*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eRefract2F
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeRefract3F( ExprPtr/*vec3f*/ I
		, ExprPtr/*vec3f*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eRefract3F
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeRefract4F( ExprPtr/*vec4f*/ I
		, ExprPtr/*vec4f*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eRefract4F
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*double*/ makeRefract1D( ExprPtr/*double*/ I
		, ExprPtr/*double*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eRefract1D
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec2d*/ makeRefract2D( ExprPtr/*vec2d*/ I
		, ExprPtr/*vec2d*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eRefract2D
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec3d*/ makeRefract3D( ExprPtr/*vec3d*/ I
		, ExprPtr/*vec3d*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eRefract3D
			, std::move( I )
			, std::move( N ) );
	}

	inline IntrinsicCallPtr/*vec4d*/ makeRefract4D( ExprPtr/*vec4d*/ I
		, ExprPtr/*vec4d*/ N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eRefract4D
			, std::move( I )
			, std::move( N ) );
	}

	// Matrix Functions

	inline IntrinsicCallPtr/*mat2x2f*/ makeMatrixCompMult2x2F( ExprPtr/*mat2x2f*/ x
		, ExprPtr/*mat2x2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2F )
			, Intrinsic::eMatrixCompMult2x2F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat2x3f*/ makeMatrixCompMult2x3F( ExprPtr/*mat2x3f*/ x
		, ExprPtr/*mat2x3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3F )
			, Intrinsic::eMatrixCompMult2x3F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat2x4f*/ makeMatrixCompMult2x4F( ExprPtr/*mat2x4f*/ x
		, ExprPtr/*mat2x4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4F )
			, Intrinsic::eMatrixCompMult2x4F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat3x2f*/ makeMatrixCompMult3x2F( ExprPtr/*mat3x2f*/ x
		, ExprPtr/*mat3x2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2F )
			, Intrinsic::eMatrixCompMult3x2F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat3x3f*/ makeMatrixCompMult3x3F( ExprPtr/*mat3x3f*/ x
		, ExprPtr/*mat3x3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3F )
			, Intrinsic::eMatrixCompMult3x3F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat3x4f*/ makeMatrixCompMult3x4F( ExprPtr/*mat3x4f*/ x
		, ExprPtr/*mat3x4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4F )
			, Intrinsic::eMatrixCompMult3x4F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat4x2f*/ makeMatrixCompMult4x2F( ExprPtr/*mat4x2f*/ x
		, ExprPtr/*mat4x2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2F )
			, Intrinsic::eMatrixCompMult4x2F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat4x3f*/ makeMatrixCompMult4x3F( ExprPtr/*mat4x3f*/ x
		, ExprPtr/*mat4x3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3F )
			, Intrinsic::eMatrixCompMult4x3F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat4x4f*/ makeMatrixCompMult4x4F( ExprPtr/*mat4x4f*/ x
		, ExprPtr/*mat4x4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4F )
			, Intrinsic::eMatrixCompMult4x4F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat2x2d*/ makeMatrixCompMult2x2D( ExprPtr/*mat2x2d*/ x
		, ExprPtr/*mat2x2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2D )
			, Intrinsic::eMatrixCompMult2x2D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat2x3d*/ makeMatrixCompMult2x3D( ExprPtr/*mat2x3d*/ x
		, ExprPtr/*mat2x3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3D )
			, Intrinsic::eMatrixCompMult2x3D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat2x4d*/ makeMatrixCompMult2x4D( ExprPtr/*mat2x4d*/ x
		, ExprPtr/*mat2x4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4D )
			, Intrinsic::eMatrixCompMult2x4D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat3x2d*/ makeMatrixCompMult3x2D( ExprPtr/*mat3x2d*/ x
		, ExprPtr/*mat3x2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2D )
			, Intrinsic::eMatrixCompMult3x2D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat3x3d*/ makeMatrixCompMult3x3D( ExprPtr/*mat3x3d*/ x
		, ExprPtr/*mat3x3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3D )
			, Intrinsic::eMatrixCompMult3x3D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat3x4d*/ makeMatrixCompMult3x4D( ExprPtr/*mat3x4d*/ x
		, ExprPtr/*mat3x4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4D )
			, Intrinsic::eMatrixCompMult3x4D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat4x2d*/ makeMatrixCompMult4x2D( ExprPtr/*mat4x2d*/ x
		, ExprPtr/*mat4x2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2D )
			, Intrinsic::eMatrixCompMult4x2D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat4x3d*/ makeMatrixCompMult4x3D( ExprPtr/*mat4x3d*/ x
		, ExprPtr/*mat4x3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3D )
			, Intrinsic::eMatrixCompMult4x3D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat4x4d*/ makeMatrixCompMult4x4D( ExprPtr/*mat4x4d*/ x
		, ExprPtr/*mat4x4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4D )
			, Intrinsic::eMatrixCompMult4x4D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*mat2x2f*/ makeOuterProduct2x2F( ExprPtr/*vec2f*/ c
		, ExprPtr/*vec2f*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2F )
			, Intrinsic::eOuterProduct2x2F
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat3x3f*/ makeOuterProduct3x3F( ExprPtr/*vec3f*/ c
		, ExprPtr/*vec3f*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3F )
			, Intrinsic::eOuterProduct3x3F
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat4x4f*/ makeOuterProduct4x4F( ExprPtr/*vec4f*/ c
		, ExprPtr/*vec4f*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4F )
			, Intrinsic::eOuterProduct4x4F
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat2x3f*/ makeOuterProduct3x2F( ExprPtr/*vec3f*/ c
		, ExprPtr/*vec2f*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3F )
			, Intrinsic::eOuterProduct3x2F
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat3x2f*/ makeOuterProduct2x3F( ExprPtr/*vec2f*/ c
		, ExprPtr/*vec3f*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2F )
			, Intrinsic::eOuterProduct2x3F
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat2x4f*/ makeOuterProduct4x2F( ExprPtr/*vec4f*/ c
		, ExprPtr/*vec2f*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4F )
			, Intrinsic::eOuterProduct4x2F
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat4x2f*/ makeOuterProduct2x4F( ExprPtr/*vec2f*/ c
		, ExprPtr/*vec4f*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2F )
			, Intrinsic::eOuterProduct2x4F
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat3x4f*/ makeOuterProduct4x3F( ExprPtr/*vec4f*/ c
		, ExprPtr/*vec3f*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4F )
			, Intrinsic::eOuterProduct4x3F
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat4x3f*/ makeOuterProduct3x4F( ExprPtr/*vec3f*/ c
		, ExprPtr/*vec4f*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3F )
			, Intrinsic::eOuterProduct3x4F
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat2x2d*/ makeOuterProduct2x2D( ExprPtr/*vec2d*/ c
		, ExprPtr/*vec2d*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2D )
			, Intrinsic::eOuterProduct2x2D
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat3x3d*/ makeOuterProduct3x3D( ExprPtr/*vec3d*/ c
		, ExprPtr/*vec3d*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3D )
			, Intrinsic::eOuterProduct3x3D
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat4x4d*/ makeOuterProduct4x4D( ExprPtr/*vec4d*/ c
		, ExprPtr/*vec4d*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4D )
			, Intrinsic::eOuterProduct4x4D
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat2x3d*/ makeOuterProduct3x2D( ExprPtr/*vec3d*/ c
		, ExprPtr/*vec2d*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3D )
			, Intrinsic::eOuterProduct3x2D
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat3x2d*/ makeOuterProduct2x3D( ExprPtr/*vec2d*/ c
		, ExprPtr/*vec3d*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2D )
			, Intrinsic::eOuterProduct2x3D
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat2x4d*/ makeOuterProduct4x2D( ExprPtr/*vec4d*/ c
		, ExprPtr/*vec2d*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4D )
			, Intrinsic::eOuterProduct4x2D
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat4x2d*/ makeOuterProduct2x4D( ExprPtr/*vec2d*/ c
		, ExprPtr/*vec4d*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2D )
			, Intrinsic::eOuterProduct2x4D
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat3x4d*/ makeOuterProduct4x3D( ExprPtr/*vec4d*/ c
		, ExprPtr/*vec3d*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4D )
			, Intrinsic::eOuterProduct4x3D
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat4x3d*/ makeOuterProduct3x4D( ExprPtr/*vec3d*/ c
		, ExprPtr/*vec4d*/ r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3D )
			, Intrinsic::eOuterProduct3x4D
			, std::move( c )
			, std::move( r ) );
	}

	inline IntrinsicCallPtr/*mat2x2f*/ makeTranspose2x2F( ExprPtr/*mat2x2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2F )
			, Intrinsic::eTranspose2x2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat3x2f*/ makeTranspose2x3F( ExprPtr/*mat2x3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2F )
			, Intrinsic::eTranspose2x3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat4x2f*/ makeTranspose2x4F( ExprPtr/*mat2x4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2F )
			, Intrinsic::eTranspose2x4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat2x3f*/ makeTranspose3x2F( ExprPtr/*mat3x2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3F )
			, Intrinsic::eTranspose3x2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat3x3f*/ makeTranspose3x3F( ExprPtr/*mat3x3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3F )
			, Intrinsic::eTranspose3x3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat4x3f*/ makeTranspose3x4F( ExprPtr/*mat3x4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3F )
			, Intrinsic::eTranspose3x4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat2x4f*/ makeTranspose4x2F( ExprPtr/*mat4x2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4F )
			, Intrinsic::eTranspose4x2F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat3x4f*/ makeTranspose4x3F( ExprPtr/*mat4x3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4F )
			, Intrinsic::eTranspose4x3F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat4x4f*/ makeTranspose4x4F( ExprPtr/*mat4x4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4F )
			, Intrinsic::eTranspose4x4F
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat2x2d*/ makeTranspose2x2D( ExprPtr/*mat2x2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2D )
			, Intrinsic::eTranspose2x2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat3x2d*/ makeTranspose2x3D( ExprPtr/*mat2x3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2D )
			, Intrinsic::eTranspose2x3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat4x2d*/ makeTranspose2x4D( ExprPtr/*mat2x4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2D )
			, Intrinsic::eTranspose2x4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat2x3d*/ makeTranspose3x2D( ExprPtr/*mat3x2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3D )
			, Intrinsic::eTranspose3x2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat3x3d*/ makeTranspose3x3D( ExprPtr/*mat3x3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3D )
			, Intrinsic::eTranspose3x3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat4x3d*/ makeTranspose3x4D( ExprPtr/*mat3x4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3D )
			, Intrinsic::eTranspose3x4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat2x4d*/ makeTranspose4x2D( ExprPtr/*mat4x2d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4D )
			, Intrinsic::eTranspose4x2D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat3x4d*/ makeTranspose4x3D( ExprPtr/*mat4x3d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4D )
			, Intrinsic::eTranspose4x3D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*mat4x4d*/ makeTranspose4x4D( ExprPtr/*mat4x4d*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4D )
			, Intrinsic::eTranspose4x4D
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDeterminant2x2F( ExprPtr/*mat2x2f*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDeterminant2x2F
			, std::move( m ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDeterminant3x3F( ExprPtr/*mat3x3f*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDeterminant3x3F
			, std::move( m ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDeterminant4x4F( ExprPtr/*mat4x4f*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDeterminant4x4F
			, std::move( m ) );
	}

	inline IntrinsicCallPtr/*double*/ makeDeterminant2x2D( ExprPtr/*mat2x2d*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDeterminant2x2D
			, std::move( m ) );
	}

	inline IntrinsicCallPtr/*double*/ makeDeterminant3x3D( ExprPtr/*mat3x3d*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDeterminant3x3D
			, std::move( m ) );
	}

	inline IntrinsicCallPtr/*double*/ makeDeterminant4x4D( ExprPtr/*mat4x4d*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDeterminant4x4D
			, std::move( m ) );
	}

	inline IntrinsicCallPtr/*mat2x2f*/ makeInverse2x2F( ExprPtr/*mat2x2f*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2F )
			, Intrinsic::eInverse2x2F
			, std::move( m ) );
	}

	inline IntrinsicCallPtr/*mat3x3f*/ makeInverse3x3F( ExprPtr/*mat3x3f*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3F )
			, Intrinsic::eInverse3x3F
			, std::move( m ) );
	}

	inline IntrinsicCallPtr/*mat4x4f*/ makeInverse4x4F( ExprPtr/*mat4x4f*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4F )
			, Intrinsic::eInverse4x4F
			, std::move( m ) );
	}

	inline IntrinsicCallPtr/*mat2x2d*/ makeInverse2x2D( ExprPtr/*mat2x2d*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2D )
			, Intrinsic::eInverse2x2D
			, std::move( m ) );
	}

	inline IntrinsicCallPtr/*mat3x3d*/ makeInverse3x3D( ExprPtr/*mat3x3d*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3D )
			, Intrinsic::eInverse3x3D
			, std::move( m ) );
	}

	inline IntrinsicCallPtr/*mat4x4d*/ makeInverse4x4D( ExprPtr/*mat4x4d*/ m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4D )
			, Intrinsic::eInverse4x4D
			, std::move( m ) );
	}

	// Vector Relational Functions

	inline IntrinsicCallPtr/*vec2b*/ makeLessThan2F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeLessThan3F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeLessThan4F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeLessThan2D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeLessThan3D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeLessThan4D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeLessThan2I( ExprPtr/*vec2i*/ x
		, ExprPtr/*vec2i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeLessThan3I( ExprPtr/*vec3i*/ x
		, ExprPtr/*vec3i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeLessThan4I( ExprPtr/*vec4i*/ x
		, ExprPtr/*vec4i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeLessThan2U( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeLessThan3U( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeLessThan4U( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeLessThanEqual2F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeLessThanEqual3F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeLessThanEqual4F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeLessThanEqual2D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeLessThanEqual3D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeLessThanEqual4D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeLessThanEqual2I( ExprPtr/*vec2i*/ x
		, ExprPtr/*vec2i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeLessThanEqual3I( ExprPtr/*vec3i*/ x
		, ExprPtr/*vec3i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeLessThanEqual4I( ExprPtr/*vec4i*/ x
		, ExprPtr/*vec4i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeLessThanEqual2U( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeLessThanEqual3U( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeLessThanEqual4U( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeGreaterThan2F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeGreaterThan3F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeGreaterThan4F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeGreaterThan2D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeGreaterThan3D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeGreaterThan4D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeGreaterThan2I( ExprPtr/*vec2i*/ x
		, ExprPtr/*vec2i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeGreaterThan3I( ExprPtr/*vec3i*/ x
		, ExprPtr/*vec3i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeGreaterThan4I( ExprPtr/*vec4i*/ x
		, ExprPtr/*vec4i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeGreaterThan2U( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeGreaterThan3U( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeGreaterThan4U( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeGreaterThanEqual2F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeGreaterThanEqual3F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeGreaterThanEqual4F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeGreaterThanEqual2D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeGreaterThanEqual3D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeGreaterThanEqual4D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeGreaterThanEqual2I( ExprPtr/*vec2i*/ x
		, ExprPtr/*vec2i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeGreaterThanEqual3I( ExprPtr/*vec3i*/ x
		, ExprPtr/*vec3i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeGreaterThanEqual4I( ExprPtr/*vec4i*/ x
		, ExprPtr/*vec4i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeGreaterThanEqual2U( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeGreaterThanEqual3U( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeGreaterThanEqual4U( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeEqual2F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeEqual3F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeEqual4F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeEqual2D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeEqual3D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeEqual4D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeEqual2I( ExprPtr/*vec2i*/ x
		, ExprPtr/*vec2i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeEqual3I( ExprPtr/*vec3i*/ x
		, ExprPtr/*vec3i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeEqual4I( ExprPtr/*vec4i*/ x
		, ExprPtr/*vec4i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeEqual2U( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeEqual3U( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeEqual4U( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeNotEqual2F( ExprPtr/*vec2f*/ x
		, ExprPtr/*vec2f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeNotEqual3F( ExprPtr/*vec3f*/ x
		, ExprPtr/*vec3f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeNotEqual4F( ExprPtr/*vec4f*/ x
		, ExprPtr/*vec4f*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeNotEqual2D( ExprPtr/*vec2d*/ x
		, ExprPtr/*vec2d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeNotEqual3D( ExprPtr/*vec3d*/ x
		, ExprPtr/*vec3d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeNotEqual4D( ExprPtr/*vec4d*/ x
		, ExprPtr/*vec4d*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeNotEqual2I( ExprPtr/*vec2i*/ x
		, ExprPtr/*vec2i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeNotEqual3I( ExprPtr/*vec3i*/ x
		, ExprPtr/*vec3i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeNotEqual4I( ExprPtr/*vec4i*/ x
		, ExprPtr/*vec4i*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeNotEqual2U( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeNotEqual3U( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeNotEqual4U( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	inline IntrinsicCallPtr/*boolean*/ makeAll2( ExprPtr/*vec2b*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAll2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*boolean*/ makeAll3( ExprPtr/*vec3b*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAll3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*boolean*/ makeAll4( ExprPtr/*vec4b*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAll4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*boolean*/ makeAny2( ExprPtr/*vec2b*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAny2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*boolean*/ makeAny3( ExprPtr/*vec3b*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAny3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*boolean*/ makeAny4( ExprPtr/*vec4b*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAny4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2b*/ makeNot2( ExprPtr/*vec2b*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eNot2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3b*/ makeNot3( ExprPtr/*vec3b*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eNot3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4b*/ makeNot4( ExprPtr/*vec4b*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eNot4
			, std::move( x ) );
	}

	// Integer Functions

	inline IntrinsicCallPtr/*uint*/ makeUaddCarry1( ExprPtr/*uint*/ x
		, ExprPtr/*uint*/ y
		, ExprPtr/*uint*/ carry )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eUaddCarry1
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeUaddCarry2( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ y
		, ExprPtr/*vec2u*/ carry )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eUaddCarry2
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeUaddCarry3( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ y
		, ExprPtr/*vec3u*/ carry )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eUaddCarry3
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeUaddCarry4( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ y
		, ExprPtr/*vec4u*/ carry )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eUaddCarry4
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeUsubBorrow1( ExprPtr/*uint*/ x
		, ExprPtr/*uint*/ y
		, ExprPtr/*uint*/ borrow )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eUsubBorrow1
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeUsubBorrow2( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ y
		, ExprPtr/*vec2u*/ borrow )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eUsubBorrow2
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeUsubBorrow3( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ y
		, ExprPtr/*vec3u*/ borrow )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eUsubBorrow3
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeUsubBorrow4( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ y
		, ExprPtr/*vec4u*/ borrow )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eUsubBorrow4
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	inline IntrinsicCallPtr/*void*/ makeUmulExtended1( ExprPtr/*uint*/ x
		, ExprPtr/*uint*/ y
		, ExprPtr/*uint*/ msb
		, ExprPtr/*uint*/ lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended1
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	inline IntrinsicCallPtr/*void*/ makeUmulExtended2( ExprPtr/*vec2u*/ x
		, ExprPtr/*vec2u*/ y
		, ExprPtr/*vec2u*/ msb
		, ExprPtr/*vec2u*/ lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended2
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	inline IntrinsicCallPtr/*void*/ makeUmulExtended3( ExprPtr/*vec3u*/ x
		, ExprPtr/*vec3u*/ y
		, ExprPtr/*vec3u*/ msb
		, ExprPtr/*vec3u*/ lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended3
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	inline IntrinsicCallPtr/*void*/ makeUmulExtended4( ExprPtr/*vec4u*/ x
		, ExprPtr/*vec4u*/ y
		, ExprPtr/*vec4u*/ msb
		, ExprPtr/*vec4u*/ lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended4
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	inline IntrinsicCallPtr/*void*/ makeImulExtended1( ExprPtr/*int*/ x
		, ExprPtr/*int*/ y
		, ExprPtr/*int*/ msb
		, ExprPtr/*int*/ lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eImulExtended1
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	inline IntrinsicCallPtr/*void*/ makeImulExtended2( ExprPtr/*vec2i*/ x
		, ExprPtr/*vec2i*/ y
		, ExprPtr/*vec2i*/ msb
		, ExprPtr/*vec2i*/ lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eImulExtended2
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	inline IntrinsicCallPtr/*void*/ makeImulExtended3( ExprPtr/*vec3i*/ x
		, ExprPtr/*vec3i*/ y
		, ExprPtr/*vec3i*/ msb
		, ExprPtr/*vec3i*/ lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eImulExtended3
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	inline IntrinsicCallPtr/*void*/ makeImulExtended4( ExprPtr/*vec4i*/ x
		, ExprPtr/*vec4i*/ y
		, ExprPtr/*vec4i*/ msb
		, ExprPtr/*vec4i*/ lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eImulExtended4
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	inline IntrinsicCallPtr/*int*/ makeBitfieldExtract1I( ExprPtr/*int*/ value
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eBitfieldExtract1I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeBitfieldExtract2I( ExprPtr/*vec2i*/ value
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldExtract2I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeBitfieldExtract3I( ExprPtr/*vec3i*/ value
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldExtract3I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeBitfieldExtract4I( ExprPtr/*vec4i*/ value
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldExtract4I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeBitfieldExtract1U( ExprPtr/*uint*/ value
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eBitfieldExtract1U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeBitfieldExtract2U( ExprPtr/*vec2u*/ value
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldExtract2U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeBitfieldExtract3U( ExprPtr/*vec3u*/ value
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldExtract3U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeBitfieldExtract4U( ExprPtr/*vec4u*/ value
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldExtract4U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*int*/ makeBitfieldInsert1I( ExprPtr/*int*/ base
		, ExprPtr/*int*/ insert
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eBitfieldInsert1I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeBitfieldInsert2I( ExprPtr/*vec2i*/ base
		, ExprPtr/*vec2i*/ insert
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldInsert2I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeBitfieldInsert3I( ExprPtr/*vec3i*/ base
		, ExprPtr/*vec3i*/ insert
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldInsert3I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeBitfieldInsert4I( ExprPtr/*vec4i*/ base
		, ExprPtr/*vec4i*/ insert
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldInsert4I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeBitfieldInsert1U( ExprPtr/*uint*/ base
		, ExprPtr/*uint*/ insert
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eBitfieldInsert1U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeBitfieldInsert2U( ExprPtr/*vec2u*/ base
		, ExprPtr/*vec2u*/ insert
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldInsert2U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeBitfieldInsert3U( ExprPtr/*vec3u*/ base
		, ExprPtr/*vec3u*/ insert
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldInsert3U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeBitfieldInsert4U( ExprPtr/*vec4u*/ base
		, ExprPtr/*vec4u*/ insert
		, ExprPtr/*int*/ offset
		, ExprPtr/*int*/ bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldInsert4U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	inline IntrinsicCallPtr/*int*/ makeBitfieldReverse1I( ExprPtr/*int*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eBitfieldReverse1I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeBitfieldReverse2I( ExprPtr/*vec2i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldReverse2I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeBitfieldReverse3I( ExprPtr/*vec3i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldReverse3I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeBitfieldReverse4I( ExprPtr/*vec4i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldReverse4I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeBitfieldReverse1U( ExprPtr/*uint*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eBitfieldReverse1U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeBitfieldReverse2U( ExprPtr/*vec2u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldReverse2U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeBitfieldReverse3U( ExprPtr/*vec3u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldReverse3U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeBitfieldReverse4U( ExprPtr/*vec4u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldReverse4U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*int*/ makeBitCount1I( ExprPtr/*int*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eBitCount1I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeBitCount2I( ExprPtr/*vec2i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eBitCount2I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeBitCount3I( ExprPtr/*vec3i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eBitCount3I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeBitCount4I( ExprPtr/*vec4i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eBitCount4I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeBitCount1U( ExprPtr/*uint*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eBitCount1U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec2u*/ makeBitCount2U( ExprPtr/*vec2u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eBitCount2U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec3u*/ makeBitCount3U( ExprPtr/*vec3u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eBitCount3U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec4u*/ makeBitCount4U( ExprPtr/*vec4u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eBitCount4U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*int*/ makeFindLSB1I( ExprPtr/*int*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eFindLSB1I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeFindLSB2I( ExprPtr/*vec2i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eFindLSB2I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeFindLSB3I( ExprPtr/*vec3i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eFindLSB3I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeFindLSB4I( ExprPtr/*vec4i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eFindLSB4I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*int*/ makeFindLSB1U( ExprPtr/*uint*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eFindLSB1U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeFindLSB2U( ExprPtr/*vec2u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eFindLSB2U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeFindLSB3U( ExprPtr/*vec3u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eFindLSB3U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeFindLSB4U( ExprPtr/*vec4u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eFindLSB4U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*int*/ makeFindMSB1I( ExprPtr/*int*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eFindMSB1I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeFindMSB2I( ExprPtr/*vec2i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eFindMSB2I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeFindMSB3I( ExprPtr/*vec3i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eFindMSB3I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeFindMSB4I( ExprPtr/*vec4i*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eFindMSB4I
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*int*/ makeFindMSB1U( ExprPtr/*uint*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eFindMSB1U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec2i*/ makeFindMSB2U( ExprPtr/*vec2u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eFindMSB2U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec3i*/ makeFindMSB3U( ExprPtr/*vec3u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eFindMSB3U
			, std::move( value ) );
	}

	inline IntrinsicCallPtr/*vec4i*/ makeFindMSB4U( ExprPtr/*vec4u*/ value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eFindMSB4U
			, std::move( value ) );
	}

	// Atomic Memory Functions

	inline IntrinsicCallPtr/*int*/ makeAtomicAddI( ExprPtr/*int*/ mem
		, ExprPtr/*int*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicAddI
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeAtomicAddU( ExprPtr/*uint*/ mem
		, ExprPtr/*uint*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicAddU
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*int*/ makeAtomicMinI( ExprPtr/*int*/ mem
		, ExprPtr/*int*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicMinI
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeAtomicMinU( ExprPtr/*uint*/ mem
		, ExprPtr/*uint*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicMinU
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*int*/ makeAtomicMaxI( ExprPtr/*int*/ mem
		, ExprPtr/*int*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicMaxI
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeAtomicMaxU( ExprPtr/*uint*/ mem
		, ExprPtr/*uint*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicMaxU
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*int*/ makeAtomicAndI( ExprPtr/*int*/ mem
		, ExprPtr/*int*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicAndI
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeAtomicAndU( ExprPtr/*uint*/ mem
		, ExprPtr/*uint*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicAndU
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*int*/ makeAtomicOrI( ExprPtr/*int*/ mem
		, ExprPtr/*int*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicOrI
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeAtomicOrU( ExprPtr/*uint*/ mem
		, ExprPtr/*uint*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicOrU
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*int*/ makeAtomicXorI( ExprPtr/*int*/ mem
		, ExprPtr/*int*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicXorI
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeAtomicXorU( ExprPtr/*uint*/ mem
		, ExprPtr/*uint*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicXorU
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*int*/ makeAtomicExchangeI( ExprPtr/*int*/ mem
		, ExprPtr/*int*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicExchangeI
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeAtomicExchangeU( ExprPtr/*uint*/ mem
		, ExprPtr/*uint*/ data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicExchangeU
			, std::move( mem )
			, std::move( data ) );
	}

	inline IntrinsicCallPtr/*int*/ makeAtomicCompSwapI( ExprPtr/*int*/ mem
		, ExprPtr/*uint*/ compare )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicCompSwapI
			, std::move( mem )
			, std::move( compare ) );
	}

	inline IntrinsicCallPtr/*uint*/ makeAtomicCompSwapU( ExprPtr/*uint*/ mem
		, ExprPtr/*uint*/ compare )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicCompSwapU
			, std::move( mem )
			, std::move( compare ) );
	}

	// Derivative Functions

	inline IntrinsicCallPtr/*float*/ makeDFdx1( ExprPtr/*float*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdx1
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeDFdx2( ExprPtr/*vec2f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdx2
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeDFdx3( ExprPtr/*vec3f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdx3
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeDFdx4( ExprPtr/*vec4f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdx4
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDFdxCoarse1( ExprPtr/*float*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdxCoarse1
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeDFdxCoarse2( ExprPtr/*vec2f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdxCoarse2
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeDFdxCoarse3( ExprPtr/*vec3f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdxCoarse3
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeDFdxCoarse4( ExprPtr/*vec4f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdxCoarse4
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDFdxFine1( ExprPtr/*float*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdxFine1
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeDFdxFine2( ExprPtr/*vec2f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdxFine2
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeDFdxFine3( ExprPtr/*vec3f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdxFine3
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeDFdxFine4( ExprPtr/*vec4f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdxFine4
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDFdy1( ExprPtr/*float*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdy1
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeDFdy2( ExprPtr/*vec2f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdy2
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeDFdy3( ExprPtr/*vec3f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdy3
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeDFdy4( ExprPtr/*vec4f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdy4
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDFdyCoarse1( ExprPtr/*float*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdyCoarse1
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeDFdyCoarse2( ExprPtr/*vec2f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdyCoarse2
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeDFdyCoarse3( ExprPtr/*vec3f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdyCoarse3
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeDFdyCoarse4( ExprPtr/*vec4f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdyCoarse4
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*float*/ makeDFdyFine1( ExprPtr/*float*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdyFine1
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeDFdyFine2( ExprPtr/*vec2f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdyFine2
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeDFdyFine3( ExprPtr/*vec3f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdyFine3
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeDFdyFine4( ExprPtr/*vec4f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdyFine4
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*float*/ makeFwidth1( ExprPtr/*float*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFwidth1
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeFwidth2( ExprPtr/*vec2f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFwidth2
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeFwidth3( ExprPtr/*vec3f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFwidth3
			, std::move( p ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeFwidth4( ExprPtr/*vec4f*/ p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFwidth4
			, std::move( p ) );
	}

	// Interpolation Functions

	inline IntrinsicCallPtr/*float*/ makeInterpolateAtCentroid1( ExprPtr/*float*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtCentroid1
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeInterpolateAtCentroid2( ExprPtr/*vec2f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtCentroid2
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeInterpolateAtCentroid3( ExprPtr/*vec3f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtCentroid3
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeInterpolateAtCentroid4( ExprPtr/*vec4f*/ x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtCentroid4
			, std::move( x ) );
	}

	inline IntrinsicCallPtr/*float*/ makeInterpolateAtSample1( ExprPtr/*float*/ interpolant
		, ExprPtr/*int*/ sample )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtSample1
			, std::move( interpolant )
			, std::move( sample ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeInterpolateAtSample2( ExprPtr/*vec2f*/ interpolant
		, ExprPtr/*int*/ sample )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtSample2
			, std::move( interpolant )
			, std::move( sample ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeInterpolateAtSample3( ExprPtr/*vec3f*/ interpolant
		, ExprPtr/*int*/ sample )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtSample3
			, std::move( interpolant )
			, std::move( sample ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeInterpolateAtSample4( ExprPtr/*vec4f*/ interpolant
		, ExprPtr/*int*/ sample )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtSample4
			, std::move( interpolant )
			, std::move( sample ) );
	}

	inline IntrinsicCallPtr/*float*/ makeInterpolateAtOffset1( ExprPtr/*float*/ interpolant
		, ExprPtr/*vec2f*/ offset )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtOffset1
			, std::move( interpolant )
			, std::move( offset ) );
	}

	inline IntrinsicCallPtr/*vec2f*/ makeInterpolateAtOffset2( ExprPtr/*vec2f*/ interpolant
		, ExprPtr/*vec2f*/ offset )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtOffset2
			, std::move( interpolant )
			, std::move( offset ) );
	}

	inline IntrinsicCallPtr/*vec3f*/ makeInterpolateAtOffset3( ExprPtr/*vec3f*/ interpolant
		, ExprPtr/*vec2f*/ offset )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtOffset3
			, std::move( interpolant )
			, std::move( offset ) );
	}

	inline IntrinsicCallPtr/*vec4f*/ makeInterpolateAtOffset4( ExprPtr/*vec4f*/ interpolant
		, ExprPtr/*vec2f*/ offset )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtOffset4
			, std::move( interpolant )
			, std::move( offset ) );
	}

	// Geometry Shader Functions

	inline IntrinsicCallPtr/*void*/ makeEmitStreamVertex( ExprPtr/*int*/ stream )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eEmitStreamVertex
			, std::move( stream ) );
	}

	inline IntrinsicCallPtr/*void*/ makeEndStreamPrimitive( ExprPtr/*int*/ stream )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eEndStreamPrimitive
			, std::move( stream ) );
	}

	inline IntrinsicCallPtr/*void*/ makeEmitVertex( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eEmitVertex );
	}

	inline IntrinsicCallPtr/*void*/ makeEndPrimitive( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eEndPrimitive );
	}

	// Shader Invocation Control Functions

	inline IntrinsicCallPtr/*void*/ makeBarrier( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eBarrier );
	}

	// Shader Memory Control Functions

	inline IntrinsicCallPtr/*uint*/ makeMemoryBarrier( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eMemoryBarrier );
	}

	inline IntrinsicCallPtr/*void*/ makeMemoryBarrierBuffer( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierBuffer );
	}

	inline IntrinsicCallPtr/*void*/ makeMemoryBarrierShared( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierShared );
	}

	inline IntrinsicCallPtr/*void*/ makeMemoryBarrierImage( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierImage );
	}

	inline IntrinsicCallPtr/*void*/ makeGroupMemoryBarrier( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eGroupMemoryBarrier );
	}
}

#endif
