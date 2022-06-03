/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#ifndef ___AST_ExprGetIntrinsicName_H___
#define ___AST_ExprGetIntrinsicName_H___
#pragma once

#include "EnumIntrinsic.hpp"

#include <string>

namespace ast::expr
{
	inline std::string getName( Intrinsic value )
	{
		std::string result;

		switch ( value )
		{
		case Intrinsic::eUndefined:
			result = "UNDEFINED";
			break;

		case Intrinsic::eCount:
			result = "COUNT";
			break;

		case Intrinsic::eInvalid:
			result = "INVALID";
			break;

	// Angle and Trigonometry Functions
		case Intrinsic::eDegrees1:
			result = "DEGREES1";
			break;

		case Intrinsic::eDegrees2:
			result = "DEGREES2";
			break;

		case Intrinsic::eDegrees3:
			result = "DEGREES3";
			break;

		case Intrinsic::eDegrees4:
			result = "DEGREES4";
			break;

		case Intrinsic::eRadians1F:
			result = "RADIANS1F";
			break;

		case Intrinsic::eRadians2F:
			result = "RADIANS2F";
			break;

		case Intrinsic::eRadians3F:
			result = "RADIANS3F";
			break;

		case Intrinsic::eRadians4F:
			result = "RADIANS4F";
			break;

		case Intrinsic::eCos1:
			result = "COS1";
			break;

		case Intrinsic::eCos2:
			result = "COS2";
			break;

		case Intrinsic::eCos3:
			result = "COS3";
			break;

		case Intrinsic::eCos4:
			result = "COS4";
			break;

		case Intrinsic::eSin1:
			result = "SIN1";
			break;

		case Intrinsic::eSin2:
			result = "SIN2";
			break;

		case Intrinsic::eSin3:
			result = "SIN3";
			break;

		case Intrinsic::eSin4:
			result = "SIN4";
			break;

		case Intrinsic::eTan1:
			result = "TAN1";
			break;

		case Intrinsic::eTan2:
			result = "TAN2";
			break;

		case Intrinsic::eTan3:
			result = "TAN3";
			break;

		case Intrinsic::eTan4:
			result = "TAN4";
			break;

		case Intrinsic::eCosh1:
			result = "COSH1";
			break;

		case Intrinsic::eCosh2:
			result = "COSH2";
			break;

		case Intrinsic::eCosh3:
			result = "COSH3";
			break;

		case Intrinsic::eCosh4:
			result = "COSH4";
			break;

		case Intrinsic::eSinh1:
			result = "SINH1";
			break;

		case Intrinsic::eSinh2:
			result = "SINH2";
			break;

		case Intrinsic::eSinh3:
			result = "SINH3";
			break;

		case Intrinsic::eSinh4:
			result = "SINH4";
			break;

		case Intrinsic::eTanh1:
			result = "TANH1";
			break;

		case Intrinsic::eTanh2:
			result = "TANH2";
			break;

		case Intrinsic::eTanh3:
			result = "TANH3";
			break;

		case Intrinsic::eTanh4:
			result = "TANH4";
			break;

		case Intrinsic::eAcos1:
			result = "ACOS1";
			break;

		case Intrinsic::eAcos2:
			result = "ACOS2";
			break;

		case Intrinsic::eAcos3:
			result = "ACOS3";
			break;

		case Intrinsic::eAcos4:
			result = "ACOS4";
			break;

		case Intrinsic::eAsin1:
			result = "ASIN1";
			break;

		case Intrinsic::eAsin2:
			result = "ASIN2";
			break;

		case Intrinsic::eAsin3:
			result = "ASIN3";
			break;

		case Intrinsic::eAsin4:
			result = "ASIN4";
			break;

		case Intrinsic::eAtan1:
			result = "ATAN1";
			break;

		case Intrinsic::eAtan2:
			result = "ATAN2";
			break;

		case Intrinsic::eAtan3:
			result = "ATAN3";
			break;

		case Intrinsic::eAtan4:
			result = "ATAN4";
			break;

		case Intrinsic::eAtan21:
			result = "ATAN21";
			break;

		case Intrinsic::eAtan22:
			result = "ATAN22";
			break;

		case Intrinsic::eAtan23:
			result = "ATAN23";
			break;

		case Intrinsic::eAtan24:
			result = "ATAN24";
			break;

		case Intrinsic::eAcosh1:
			result = "ACOSH1";
			break;

		case Intrinsic::eAcosh2:
			result = "ACOSH2";
			break;

		case Intrinsic::eAcosh3:
			result = "ACOSH3";
			break;

		case Intrinsic::eAcosh4:
			result = "ACOSH4";
			break;

		case Intrinsic::eAsinh1:
			result = "ASINH1";
			break;

		case Intrinsic::eAsinh2:
			result = "ASINH2";
			break;

		case Intrinsic::eAsinh3:
			result = "ASINH3";
			break;

		case Intrinsic::eAsinh4:
			result = "ASINH4";
			break;

		case Intrinsic::eAtanh1:
			result = "ATANH1";
			break;

		case Intrinsic::eAtanh2:
			result = "ATANH2";
			break;

		case Intrinsic::eAtanh3:
			result = "ATANH3";
			break;

		case Intrinsic::eAtanh4:
			result = "ATANH4";
			break;


	// Exponential Functions
		case Intrinsic::ePow1:
			result = "POW1";
			break;

		case Intrinsic::ePow2:
			result = "POW2";
			break;

		case Intrinsic::ePow3:
			result = "POW3";
			break;

		case Intrinsic::ePow4:
			result = "POW4";
			break;

		case Intrinsic::eExp1:
			result = "EXP1";
			break;

		case Intrinsic::eExp2:
			result = "EXP2";
			break;

		case Intrinsic::eExp3:
			result = "EXP3";
			break;

		case Intrinsic::eExp4:
			result = "EXP4";
			break;

		case Intrinsic::eLog1:
			result = "LOG1";
			break;

		case Intrinsic::eLog2:
			result = "LOG2";
			break;

		case Intrinsic::eLog3:
			result = "LOG3";
			break;

		case Intrinsic::eLog4:
			result = "LOG4";
			break;

		case Intrinsic::eExp21:
			result = "EXP21";
			break;

		case Intrinsic::eExp22:
			result = "EXP22";
			break;

		case Intrinsic::eExp23:
			result = "EXP23";
			break;

		case Intrinsic::eExp24:
			result = "EXP24";
			break;

		case Intrinsic::eLog21:
			result = "LOG21";
			break;

		case Intrinsic::eLog22:
			result = "LOG22";
			break;

		case Intrinsic::eLog23:
			result = "LOG23";
			break;

		case Intrinsic::eLog24:
			result = "LOG24";
			break;

		case Intrinsic::eSqrt1F:
			result = "SQRT1F";
			break;

		case Intrinsic::eSqrt2F:
			result = "SQRT2F";
			break;

		case Intrinsic::eSqrt3F:
			result = "SQRT3F";
			break;

		case Intrinsic::eSqrt4F:
			result = "SQRT4F";
			break;

		case Intrinsic::eSqrt1D:
			result = "SQRT1D";
			break;

		case Intrinsic::eSqrt2D:
			result = "SQRT2D";
			break;

		case Intrinsic::eSqrt3D:
			result = "SQRT3D";
			break;

		case Intrinsic::eSqrt4D:
			result = "SQRT4D";
			break;

		case Intrinsic::eInverseSqrt1F:
			result = "INVERSESQRT1F";
			break;

		case Intrinsic::eInverseSqrt2F:
			result = "INVERSESQRT2F";
			break;

		case Intrinsic::eInverseSqrt3F:
			result = "INVERSESQRT3F";
			break;

		case Intrinsic::eInverseSqrt4F:
			result = "INVERSESQRT4F";
			break;

		case Intrinsic::eInverseSqrt1D:
			result = "INVERSESQRT1D";
			break;

		case Intrinsic::eInverseSqrt2D:
			result = "INVERSESQRT2D";
			break;

		case Intrinsic::eInverseSqrt3D:
			result = "INVERSESQRT3D";
			break;

		case Intrinsic::eInverseSqrt4D:
			result = "INVERSESQRT4D";
			break;


	// Common Functions
		case Intrinsic::eAbs1F:
			result = "ABS1F";
			break;

		case Intrinsic::eAbs2F:
			result = "ABS2F";
			break;

		case Intrinsic::eAbs3F:
			result = "ABS3F";
			break;

		case Intrinsic::eAbs4F:
			result = "ABS4F";
			break;

		case Intrinsic::eAbs1I:
			result = "ABS1I";
			break;

		case Intrinsic::eAbs2I:
			result = "ABS2I";
			break;

		case Intrinsic::eAbs3I:
			result = "ABS3I";
			break;

		case Intrinsic::eAbs4I:
			result = "ABS4I";
			break;

		case Intrinsic::eAbs1D:
			result = "ABS1D";
			break;

		case Intrinsic::eAbs2D:
			result = "ABS2D";
			break;

		case Intrinsic::eAbs3D:
			result = "ABS3D";
			break;

		case Intrinsic::eAbs4D:
			result = "ABS4D";
			break;

		case Intrinsic::eSign1F:
			result = "SIGN1F";
			break;

		case Intrinsic::eSign2F:
			result = "SIGN2F";
			break;

		case Intrinsic::eSign3F:
			result = "SIGN3F";
			break;

		case Intrinsic::eSign4F:
			result = "SIGN4F";
			break;

		case Intrinsic::eSign1I:
			result = "SIGN1I";
			break;

		case Intrinsic::eSign2I:
			result = "SIGN2I";
			break;

		case Intrinsic::eSign3I:
			result = "SIGN3I";
			break;

		case Intrinsic::eSign4I:
			result = "SIGN4I";
			break;

		case Intrinsic::eSign1D:
			result = "SIGN1D";
			break;

		case Intrinsic::eSign2D:
			result = "SIGN2D";
			break;

		case Intrinsic::eSign3D:
			result = "SIGN3D";
			break;

		case Intrinsic::eSign4D:
			result = "SIGN4D";
			break;

		case Intrinsic::eFloor1F:
			result = "FLOOR1F";
			break;

		case Intrinsic::eFloor2F:
			result = "FLOOR2F";
			break;

		case Intrinsic::eFloor3F:
			result = "FLOOR3F";
			break;

		case Intrinsic::eFloor4F:
			result = "FLOOR4F";
			break;

		case Intrinsic::eFloor1D:
			result = "FLOOR1D";
			break;

		case Intrinsic::eFloor2D:
			result = "FLOOR2D";
			break;

		case Intrinsic::eFloor3D:
			result = "FLOOR3D";
			break;

		case Intrinsic::eFloor4D:
			result = "FLOOR4D";
			break;

		case Intrinsic::eTrunc1F:
			result = "TRUNC1F";
			break;

		case Intrinsic::eTrunc2F:
			result = "TRUNC2F";
			break;

		case Intrinsic::eTrunc3F:
			result = "TRUNC3F";
			break;

		case Intrinsic::eTrunc4F:
			result = "TRUNC4F";
			break;

		case Intrinsic::eTrunc1D:
			result = "TRUNC1D";
			break;

		case Intrinsic::eTrunc2D:
			result = "TRUNC2D";
			break;

		case Intrinsic::eTrunc3D:
			result = "TRUNC3D";
			break;

		case Intrinsic::eTrunc4D:
			result = "TRUNC4D";
			break;

		case Intrinsic::eRound1F:
			result = "ROUND1F";
			break;

		case Intrinsic::eRound2F:
			result = "ROUND2F";
			break;

		case Intrinsic::eRound3F:
			result = "ROUND3F";
			break;

		case Intrinsic::eRound4F:
			result = "ROUND4F";
			break;

		case Intrinsic::eRound1D:
			result = "ROUND1D";
			break;

		case Intrinsic::eRound2D:
			result = "ROUND2D";
			break;

		case Intrinsic::eRound3D:
			result = "ROUND3D";
			break;

		case Intrinsic::eRound4D:
			result = "ROUND4D";
			break;

		case Intrinsic::eRoundEven1F:
			result = "ROUNDEVEN1F";
			break;

		case Intrinsic::eRoundEven2F:
			result = "ROUNDEVEN2F";
			break;

		case Intrinsic::eRoundEven3F:
			result = "ROUNDEVEN3F";
			break;

		case Intrinsic::eRoundEven4F:
			result = "ROUNDEVEN4F";
			break;

		case Intrinsic::eRoundEven1D:
			result = "ROUNDEVEN1D";
			break;

		case Intrinsic::eRoundEven2D:
			result = "ROUNDEVEN2D";
			break;

		case Intrinsic::eRoundEven3D:
			result = "ROUNDEVEN3D";
			break;

		case Intrinsic::eRoundEven4D:
			result = "ROUNDEVEN4D";
			break;

		case Intrinsic::eCeil1F:
			result = "CEIL1F";
			break;

		case Intrinsic::eCeil2F:
			result = "CEIL2F";
			break;

		case Intrinsic::eCeil3F:
			result = "CEIL3F";
			break;

		case Intrinsic::eCeil4F:
			result = "CEIL4F";
			break;

		case Intrinsic::eCeil1D:
			result = "CEIL1D";
			break;

		case Intrinsic::eCeil2D:
			result = "CEIL2D";
			break;

		case Intrinsic::eCeil3D:
			result = "CEIL3D";
			break;

		case Intrinsic::eCeil4D:
			result = "CEIL4D";
			break;

		case Intrinsic::eFract1F:
			result = "FRACT1F";
			break;

		case Intrinsic::eFract2F:
			result = "FRACT2F";
			break;

		case Intrinsic::eFract3F:
			result = "FRACT3F";
			break;

		case Intrinsic::eFract4F:
			result = "FRACT4F";
			break;

		case Intrinsic::eFract1D:
			result = "FRACT1D";
			break;

		case Intrinsic::eFract2D:
			result = "FRACT2D";
			break;

		case Intrinsic::eFract3D:
			result = "FRACT3D";
			break;

		case Intrinsic::eFract4D:
			result = "FRACT4D";
			break;

		case Intrinsic::eMod1F:
			result = "MOD1F";
			break;

		case Intrinsic::eMod2F:
			result = "MOD2F";
			break;

		case Intrinsic::eMod3F:
			result = "MOD3F";
			break;

		case Intrinsic::eMod4F:
			result = "MOD4F";
			break;

		case Intrinsic::eMod1D:
			result = "MOD1D";
			break;

		case Intrinsic::eMod2D:
			result = "MOD2D";
			break;

		case Intrinsic::eMod3D:
			result = "MOD3D";
			break;

		case Intrinsic::eMod4D:
			result = "MOD4D";
			break;

		case Intrinsic::eModf1F:
			result = "MODF1F";
			break;

		case Intrinsic::eModf2F:
			result = "MODF2F";
			break;

		case Intrinsic::eModf3F:
			result = "MODF3F";
			break;

		case Intrinsic::eModf4F:
			result = "MODF4F";
			break;

		case Intrinsic::eModf1D:
			result = "MODF1D";
			break;

		case Intrinsic::eModf2D:
			result = "MODF2D";
			break;

		case Intrinsic::eModf3D:
			result = "MODF3D";
			break;

		case Intrinsic::eModf4D:
			result = "MODF4D";
			break;

		case Intrinsic::eMin1F:
			result = "MIN1F";
			break;

		case Intrinsic::eMin2F:
			result = "MIN2F";
			break;

		case Intrinsic::eMin3F:
			result = "MIN3F";
			break;

		case Intrinsic::eMin4F:
			result = "MIN4F";
			break;

		case Intrinsic::eMin1D:
			result = "MIN1D";
			break;

		case Intrinsic::eMin2D:
			result = "MIN2D";
			break;

		case Intrinsic::eMin3D:
			result = "MIN3D";
			break;

		case Intrinsic::eMin4D:
			result = "MIN4D";
			break;

		case Intrinsic::eMin1I:
			result = "MIN1I";
			break;

		case Intrinsic::eMin2I:
			result = "MIN2I";
			break;

		case Intrinsic::eMin3I:
			result = "MIN3I";
			break;

		case Intrinsic::eMin4I:
			result = "MIN4I";
			break;

		case Intrinsic::eMin1U:
			result = "MIN1U";
			break;

		case Intrinsic::eMin2U:
			result = "MIN2U";
			break;

		case Intrinsic::eMin3U:
			result = "MIN3U";
			break;

		case Intrinsic::eMin4U:
			result = "MIN4U";
			break;

		case Intrinsic::eMax1F:
			result = "MAX1F";
			break;

		case Intrinsic::eMax2F:
			result = "MAX2F";
			break;

		case Intrinsic::eMax3F:
			result = "MAX3F";
			break;

		case Intrinsic::eMax4F:
			result = "MAX4F";
			break;

		case Intrinsic::eMax1D:
			result = "MAX1D";
			break;

		case Intrinsic::eMax2D:
			result = "MAX2D";
			break;

		case Intrinsic::eMax3D:
			result = "MAX3D";
			break;

		case Intrinsic::eMax4D:
			result = "MAX4D";
			break;

		case Intrinsic::eMax1I:
			result = "MAX1I";
			break;

		case Intrinsic::eMax2I:
			result = "MAX2I";
			break;

		case Intrinsic::eMax3I:
			result = "MAX3I";
			break;

		case Intrinsic::eMax4I:
			result = "MAX4I";
			break;

		case Intrinsic::eMax1U:
			result = "MAX1U";
			break;

		case Intrinsic::eMax2U:
			result = "MAX2U";
			break;

		case Intrinsic::eMax3U:
			result = "MAX3U";
			break;

		case Intrinsic::eMax4U:
			result = "MAX4U";
			break;

		case Intrinsic::eClamp1F:
			result = "CLAMP1F";
			break;

		case Intrinsic::eClamp2F:
			result = "CLAMP2F";
			break;

		case Intrinsic::eClamp3F:
			result = "CLAMP3F";
			break;

		case Intrinsic::eClamp4F:
			result = "CLAMP4F";
			break;

		case Intrinsic::eClamp1D:
			result = "CLAMP1D";
			break;

		case Intrinsic::eClamp2D:
			result = "CLAMP2D";
			break;

		case Intrinsic::eClamp3D:
			result = "CLAMP3D";
			break;

		case Intrinsic::eClamp4D:
			result = "CLAMP4D";
			break;

		case Intrinsic::eClamp1I:
			result = "CLAMP1I";
			break;

		case Intrinsic::eClamp2I:
			result = "CLAMP2I";
			break;

		case Intrinsic::eClamp3I:
			result = "CLAMP3I";
			break;

		case Intrinsic::eClamp4I:
			result = "CLAMP4I";
			break;

		case Intrinsic::eClamp1U:
			result = "CLAMP1U";
			break;

		case Intrinsic::eClamp2U:
			result = "CLAMP2U";
			break;

		case Intrinsic::eClamp3U:
			result = "CLAMP3U";
			break;

		case Intrinsic::eClamp4U:
			result = "CLAMP4U";
			break;

		case Intrinsic::eMix1F:
			result = "MIX1F";
			break;

		case Intrinsic::eMix2F:
			result = "MIX2F";
			break;

		case Intrinsic::eMix3F:
			result = "MIX3F";
			break;

		case Intrinsic::eMix4F:
			result = "MIX4F";
			break;

		case Intrinsic::eMix1D:
			result = "MIX1D";
			break;

		case Intrinsic::eMix2D:
			result = "MIX2D";
			break;

		case Intrinsic::eMix3D:
			result = "MIX3D";
			break;

		case Intrinsic::eMix4D:
			result = "MIX4D";
			break;

		case Intrinsic::eStep1F:
			result = "STEP1F";
			break;

		case Intrinsic::eStep2F:
			result = "STEP2F";
			break;

		case Intrinsic::eStep3F:
			result = "STEP3F";
			break;

		case Intrinsic::eStep4F:
			result = "STEP4F";
			break;

		case Intrinsic::eStep1D:
			result = "STEP1D";
			break;

		case Intrinsic::eStep2D:
			result = "STEP2D";
			break;

		case Intrinsic::eStep3D:
			result = "STEP3D";
			break;

		case Intrinsic::eStep4D:
			result = "STEP4D";
			break;

		case Intrinsic::eSmoothStep1F:
			result = "SMOOTHSTEP1F";
			break;

		case Intrinsic::eSmoothStep2F:
			result = "SMOOTHSTEP2F";
			break;

		case Intrinsic::eSmoothStep3F:
			result = "SMOOTHSTEP3F";
			break;

		case Intrinsic::eSmoothStep4F:
			result = "SMOOTHSTEP4F";
			break;

		case Intrinsic::eSmoothStep1D:
			result = "SMOOTHSTEP1D";
			break;

		case Intrinsic::eSmoothStep2D:
			result = "SMOOTHSTEP2D";
			break;

		case Intrinsic::eSmoothStep3D:
			result = "SMOOTHSTEP3D";
			break;

		case Intrinsic::eSmoothStep4D:
			result = "SMOOTHSTEP4D";
			break;

		case Intrinsic::eIsnan1F:
			result = "ISNAN1F";
			break;

		case Intrinsic::eIsnan2F:
			result = "ISNAN2F";
			break;

		case Intrinsic::eIsnan3F:
			result = "ISNAN3F";
			break;

		case Intrinsic::eIsnan4F:
			result = "ISNAN4F";
			break;

		case Intrinsic::eIsnan1D:
			result = "ISNAN1D";
			break;

		case Intrinsic::eIsnan2D:
			result = "ISNAN2D";
			break;

		case Intrinsic::eIsnan3D:
			result = "ISNAN3D";
			break;

		case Intrinsic::eIsnan4D:
			result = "ISNAN4D";
			break;

		case Intrinsic::eIsinf1F:
			result = "ISINF1F";
			break;

		case Intrinsic::eIsinf2F:
			result = "ISINF2F";
			break;

		case Intrinsic::eIsinf3F:
			result = "ISINF3F";
			break;

		case Intrinsic::eIsinf4F:
			result = "ISINF4F";
			break;

		case Intrinsic::eIsinf1D:
			result = "ISINF1D";
			break;

		case Intrinsic::eIsinf2D:
			result = "ISINF2D";
			break;

		case Intrinsic::eIsinf3D:
			result = "ISINF3D";
			break;

		case Intrinsic::eIsinf4D:
			result = "ISINF4D";
			break;

		case Intrinsic::eFloatBitsToInt1:
			result = "FLOATBITSTOINT1";
			break;

		case Intrinsic::eFloatBitsToInt2:
			result = "FLOATBITSTOINT2";
			break;

		case Intrinsic::eFloatBitsToInt3:
			result = "FLOATBITSTOINT3";
			break;

		case Intrinsic::eFloatBitsToInt4:
			result = "FLOATBITSTOINT4";
			break;

		case Intrinsic::eFloatBitsToUInt1:
			result = "FLOATBITSTOUINT1";
			break;

		case Intrinsic::eFloatBitsToUInt2:
			result = "FLOATBITSTOUINT2";
			break;

		case Intrinsic::eFloatBitsToUInt3:
			result = "FLOATBITSTOUINT3";
			break;

		case Intrinsic::eFloatBitsToUInt4:
			result = "FLOATBITSTOUINT4";
			break;

		case Intrinsic::eIntBitsToFloat1:
			result = "INTBITSTOFLOAT1";
			break;

		case Intrinsic::eIntBitsToFloat2:
			result = "INTBITSTOFLOAT2";
			break;

		case Intrinsic::eIntBitsToFloat3:
			result = "INTBITSTOFLOAT3";
			break;

		case Intrinsic::eIntBitsToFloat4:
			result = "INTBITSTOFLOAT4";
			break;

		case Intrinsic::eUintBitsToFloat1:
			result = "UINTBITSTOFLOAT1";
			break;

		case Intrinsic::eUintBitsToFloat2:
			result = "UINTBITSTOFLOAT2";
			break;

		case Intrinsic::eUintBitsToFloat3:
			result = "UINTBITSTOFLOAT3";
			break;

		case Intrinsic::eUintBitsToFloat4:
			result = "UINTBITSTOFLOAT4";
			break;

		case Intrinsic::eFma1F:
			result = "FMA1F";
			break;

		case Intrinsic::eFma2F:
			result = "FMA2F";
			break;

		case Intrinsic::eFma3F:
			result = "FMA3F";
			break;

		case Intrinsic::eFma4F:
			result = "FMA4F";
			break;

		case Intrinsic::eFma1D:
			result = "FMA1D";
			break;

		case Intrinsic::eFma2D:
			result = "FMA2D";
			break;

		case Intrinsic::eFma3D:
			result = "FMA3D";
			break;

		case Intrinsic::eFma4D:
			result = "FMA4D";
			break;

		case Intrinsic::eFrexp1F:
			result = "FREXP1F";
			break;

		case Intrinsic::eFrexp2F:
			result = "FREXP2F";
			break;

		case Intrinsic::eFrexp3F:
			result = "FREXP3F";
			break;

		case Intrinsic::eFrexp4F:
			result = "FREXP4F";
			break;

		case Intrinsic::eFrexp1D:
			result = "FREXP1D";
			break;

		case Intrinsic::eFrexp2D:
			result = "FREXP2D";
			break;

		case Intrinsic::eFrexp3D:
			result = "FREXP3D";
			break;

		case Intrinsic::eFrexp4D:
			result = "FREXP4D";
			break;

		case Intrinsic::eLdexp1F:
			result = "LDEXP1F";
			break;

		case Intrinsic::eLdexp2F:
			result = "LDEXP2F";
			break;

		case Intrinsic::eLdexp3F:
			result = "LDEXP3F";
			break;

		case Intrinsic::eLdexp4F:
			result = "LDEXP4F";
			break;

		case Intrinsic::eLdexp1D:
			result = "LDEXP1D";
			break;

		case Intrinsic::eLdexp2D:
			result = "LDEXP2D";
			break;

		case Intrinsic::eLdexp3D:
			result = "LDEXP3D";
			break;

		case Intrinsic::eLdexp4D:
			result = "LDEXP4D";
			break;


	// Floating-point Pack and Unpack Functions
		case Intrinsic::ePackDouble2x32:
			result = "PACKDOUBLE2X32";
			break;

		case Intrinsic::ePackHalf2x16:
			result = "PACKHALF2X16";
			break;

		case Intrinsic::ePackSnorm2x16:
			result = "PACKSNORM2X16";
			break;

		case Intrinsic::ePackSnorm4x8:
			result = "PACKSNORM4X8";
			break;

		case Intrinsic::ePackUnorm2x16:
			result = "PACKUNORM2X16";
			break;

		case Intrinsic::ePackUnorm4x8:
			result = "PACKUNORM4X8";
			break;

		case Intrinsic::eUnpackDouble2x32:
			result = "UNPACKDOUBLE2X32";
			break;

		case Intrinsic::eUnpackHalf2x16:
			result = "UNPACKHALF2X16";
			break;

		case Intrinsic::eUnpackSnorm2x16:
			result = "UNPACKSNORM2X16";
			break;

		case Intrinsic::eUnpackSnorm4x8:
			result = "UNPACKSNORM4X8";
			break;

		case Intrinsic::eUnpackUnorm2x16:
			result = "UNPACKUNORM2X16";
			break;

		case Intrinsic::eUnpackUnorm4x8:
			result = "UNPACKUNORM4X8";
			break;


	// Geometric Functions
		case Intrinsic::eLength1F:
			result = "LENGTH1F";
			break;

		case Intrinsic::eLength2F:
			result = "LENGTH2F";
			break;

		case Intrinsic::eLength3F:
			result = "LENGTH3F";
			break;

		case Intrinsic::eLength4F:
			result = "LENGTH4F";
			break;

		case Intrinsic::eLength1D:
			result = "LENGTH1D";
			break;

		case Intrinsic::eLength2D:
			result = "LENGTH2D";
			break;

		case Intrinsic::eLength3D:
			result = "LENGTH3D";
			break;

		case Intrinsic::eLength4D:
			result = "LENGTH4D";
			break;

		case Intrinsic::eDistance1F:
			result = "DISTANCE1F";
			break;

		case Intrinsic::eDistance2F:
			result = "DISTANCE2F";
			break;

		case Intrinsic::eDistance3F:
			result = "DISTANCE3F";
			break;

		case Intrinsic::eDistance4F:
			result = "DISTANCE4F";
			break;

		case Intrinsic::eDistance1D:
			result = "DISTANCE1D";
			break;

		case Intrinsic::eDistance2D:
			result = "DISTANCE2D";
			break;

		case Intrinsic::eDistance3D:
			result = "DISTANCE3D";
			break;

		case Intrinsic::eDistance4D:
			result = "DISTANCE4D";
			break;

		case Intrinsic::eDot1F:
			result = "DOT1F";
			break;

		case Intrinsic::eDot2F:
			result = "DOT2F";
			break;

		case Intrinsic::eDot3F:
			result = "DOT3F";
			break;

		case Intrinsic::eDot4F:
			result = "DOT4F";
			break;

		case Intrinsic::eDot1D:
			result = "DOT1D";
			break;

		case Intrinsic::eDot2D:
			result = "DOT2D";
			break;

		case Intrinsic::eDot3D:
			result = "DOT3D";
			break;

		case Intrinsic::eDot4D:
			result = "DOT4D";
			break;

		case Intrinsic::eCrossF:
			result = "CROSSF";
			break;

		case Intrinsic::eCrossD:
			result = "CROSSD";
			break;

		case Intrinsic::eNormalize1F:
			result = "NORMALIZE1F";
			break;

		case Intrinsic::eNormalize2F:
			result = "NORMALIZE2F";
			break;

		case Intrinsic::eNormalize3F:
			result = "NORMALIZE3F";
			break;

		case Intrinsic::eNormalize4F:
			result = "NORMALIZE4F";
			break;

		case Intrinsic::eNormalize1D:
			result = "NORMALIZE1D";
			break;

		case Intrinsic::eNormalize2D:
			result = "NORMALIZE2D";
			break;

		case Intrinsic::eNormalize3D:
			result = "NORMALIZE3D";
			break;

		case Intrinsic::eNormalize4D:
			result = "NORMALIZE4D";
			break;

		case Intrinsic::eFaceForward1F:
			result = "FACEFORWARD1F";
			break;

		case Intrinsic::eFaceForward2F:
			result = "FACEFORWARD2F";
			break;

		case Intrinsic::eFaceForward3F:
			result = "FACEFORWARD3F";
			break;

		case Intrinsic::eFaceForward4F:
			result = "FACEFORWARD4F";
			break;

		case Intrinsic::eFaceForward1D:
			result = "FACEFORWARD1D";
			break;

		case Intrinsic::eFaceForward2D:
			result = "FACEFORWARD2D";
			break;

		case Intrinsic::eFaceForward3D:
			result = "FACEFORWARD3D";
			break;

		case Intrinsic::eFaceForward4D:
			result = "FACEFORWARD4D";
			break;

		case Intrinsic::eReflect1F:
			result = "REFLECT1F";
			break;

		case Intrinsic::eReflect2F:
			result = "REFLECT2F";
			break;

		case Intrinsic::eReflect3F:
			result = "REFLECT3F";
			break;

		case Intrinsic::eReflect4F:
			result = "REFLECT4F";
			break;

		case Intrinsic::eReflect1D:
			result = "REFLECT1D";
			break;

		case Intrinsic::eReflect2D:
			result = "REFLECT2D";
			break;

		case Intrinsic::eReflect3D:
			result = "REFLECT3D";
			break;

		case Intrinsic::eReflect4D:
			result = "REFLECT4D";
			break;

		case Intrinsic::eRefract1F:
			result = "REFRACT1F";
			break;

		case Intrinsic::eRefract2F:
			result = "REFRACT2F";
			break;

		case Intrinsic::eRefract3F:
			result = "REFRACT3F";
			break;

		case Intrinsic::eRefract4F:
			result = "REFRACT4F";
			break;

		case Intrinsic::eRefract1D:
			result = "REFRACT1D";
			break;

		case Intrinsic::eRefract2D:
			result = "REFRACT2D";
			break;

		case Intrinsic::eRefract3D:
			result = "REFRACT3D";
			break;

		case Intrinsic::eRefract4D:
			result = "REFRACT4D";
			break;


	// Matrix Functions
		case Intrinsic::eMatrixCompMult2x2F:
			result = "MATRIXCOMPMULT2X2F";
			break;

		case Intrinsic::eMatrixCompMult2x3F:
			result = "MATRIXCOMPMULT2X3F";
			break;

		case Intrinsic::eMatrixCompMult2x4F:
			result = "MATRIXCOMPMULT2X4F";
			break;

		case Intrinsic::eMatrixCompMult3x2F:
			result = "MATRIXCOMPMULT3X2F";
			break;

		case Intrinsic::eMatrixCompMult3x3F:
			result = "MATRIXCOMPMULT3X3F";
			break;

		case Intrinsic::eMatrixCompMult3x4F:
			result = "MATRIXCOMPMULT3X4F";
			break;

		case Intrinsic::eMatrixCompMult4x2F:
			result = "MATRIXCOMPMULT4X2F";
			break;

		case Intrinsic::eMatrixCompMult4x3F:
			result = "MATRIXCOMPMULT4X3F";
			break;

		case Intrinsic::eMatrixCompMult4x4F:
			result = "MATRIXCOMPMULT4X4F";
			break;

		case Intrinsic::eMatrixCompMult2x2D:
			result = "MATRIXCOMPMULT2X2D";
			break;

		case Intrinsic::eMatrixCompMult2x3D:
			result = "MATRIXCOMPMULT2X3D";
			break;

		case Intrinsic::eMatrixCompMult2x4D:
			result = "MATRIXCOMPMULT2X4D";
			break;

		case Intrinsic::eMatrixCompMult3x2D:
			result = "MATRIXCOMPMULT3X2D";
			break;

		case Intrinsic::eMatrixCompMult3x3D:
			result = "MATRIXCOMPMULT3X3D";
			break;

		case Intrinsic::eMatrixCompMult3x4D:
			result = "MATRIXCOMPMULT3X4D";
			break;

		case Intrinsic::eMatrixCompMult4x2D:
			result = "MATRIXCOMPMULT4X2D";
			break;

		case Intrinsic::eMatrixCompMult4x3D:
			result = "MATRIXCOMPMULT4X3D";
			break;

		case Intrinsic::eMatrixCompMult4x4D:
			result = "MATRIXCOMPMULT4X4D";
			break;

		case Intrinsic::eOuterProduct2x2F:
			result = "OUTERPRODUCT2X2F";
			break;

		case Intrinsic::eOuterProduct3x3F:
			result = "OUTERPRODUCT3X3F";
			break;

		case Intrinsic::eOuterProduct4x4F:
			result = "OUTERPRODUCT4X4F";
			break;

		case Intrinsic::eOuterProduct3x2F:
			result = "OUTERPRODUCT3X2F";
			break;

		case Intrinsic::eOuterProduct2x3F:
			result = "OUTERPRODUCT2X3F";
			break;

		case Intrinsic::eOuterProduct4x2F:
			result = "OUTERPRODUCT4X2F";
			break;

		case Intrinsic::eOuterProduct2x4F:
			result = "OUTERPRODUCT2X4F";
			break;

		case Intrinsic::eOuterProduct4x3F:
			result = "OUTERPRODUCT4X3F";
			break;

		case Intrinsic::eOuterProduct3x4F:
			result = "OUTERPRODUCT3X4F";
			break;

		case Intrinsic::eOuterProduct2x2D:
			result = "OUTERPRODUCT2X2D";
			break;

		case Intrinsic::eOuterProduct3x3D:
			result = "OUTERPRODUCT3X3D";
			break;

		case Intrinsic::eOuterProduct4x4D:
			result = "OUTERPRODUCT4X4D";
			break;

		case Intrinsic::eOuterProduct3x2D:
			result = "OUTERPRODUCT3X2D";
			break;

		case Intrinsic::eOuterProduct2x3D:
			result = "OUTERPRODUCT2X3D";
			break;

		case Intrinsic::eOuterProduct4x2D:
			result = "OUTERPRODUCT4X2D";
			break;

		case Intrinsic::eOuterProduct2x4D:
			result = "OUTERPRODUCT2X4D";
			break;

		case Intrinsic::eOuterProduct4x3D:
			result = "OUTERPRODUCT4X3D";
			break;

		case Intrinsic::eOuterProduct3x4D:
			result = "OUTERPRODUCT3X4D";
			break;

		case Intrinsic::eTranspose2x2F:
			result = "TRANSPOSE2X2F";
			break;

		case Intrinsic::eTranspose2x3F:
			result = "TRANSPOSE2X3F";
			break;

		case Intrinsic::eTranspose2x4F:
			result = "TRANSPOSE2X4F";
			break;

		case Intrinsic::eTranspose3x2F:
			result = "TRANSPOSE3X2F";
			break;

		case Intrinsic::eTranspose3x3F:
			result = "TRANSPOSE3X3F";
			break;

		case Intrinsic::eTranspose3x4F:
			result = "TRANSPOSE3X4F";
			break;

		case Intrinsic::eTranspose4x2F:
			result = "TRANSPOSE4X2F";
			break;

		case Intrinsic::eTranspose4x3F:
			result = "TRANSPOSE4X3F";
			break;

		case Intrinsic::eTranspose4x4F:
			result = "TRANSPOSE4X4F";
			break;

		case Intrinsic::eTranspose2x2D:
			result = "TRANSPOSE2X2D";
			break;

		case Intrinsic::eTranspose2x3D:
			result = "TRANSPOSE2X3D";
			break;

		case Intrinsic::eTranspose2x4D:
			result = "TRANSPOSE2X4D";
			break;

		case Intrinsic::eTranspose3x2D:
			result = "TRANSPOSE3X2D";
			break;

		case Intrinsic::eTranspose3x3D:
			result = "TRANSPOSE3X3D";
			break;

		case Intrinsic::eTranspose3x4D:
			result = "TRANSPOSE3X4D";
			break;

		case Intrinsic::eTranspose4x2D:
			result = "TRANSPOSE4X2D";
			break;

		case Intrinsic::eTranspose4x3D:
			result = "TRANSPOSE4X3D";
			break;

		case Intrinsic::eTranspose4x4D:
			result = "TRANSPOSE4X4D";
			break;

		case Intrinsic::eDeterminant2x2F:
			result = "DETERMINANT2X2F";
			break;

		case Intrinsic::eDeterminant3x3F:
			result = "DETERMINANT3X3F";
			break;

		case Intrinsic::eDeterminant4x4F:
			result = "DETERMINANT4X4F";
			break;

		case Intrinsic::eDeterminant2x2D:
			result = "DETERMINANT2X2D";
			break;

		case Intrinsic::eDeterminant3x3D:
			result = "DETERMINANT3X3D";
			break;

		case Intrinsic::eDeterminant4x4D:
			result = "DETERMINANT4X4D";
			break;

		case Intrinsic::eInverse2x2F:
			result = "INVERSE2X2F";
			break;

		case Intrinsic::eInverse3x3F:
			result = "INVERSE3X3F";
			break;

		case Intrinsic::eInverse4x4F:
			result = "INVERSE4X4F";
			break;

		case Intrinsic::eInverse2x2D:
			result = "INVERSE2X2D";
			break;

		case Intrinsic::eInverse3x3D:
			result = "INVERSE3X3D";
			break;

		case Intrinsic::eInverse4x4D:
			result = "INVERSE4X4D";
			break;


	// Vector Relational Functions
		case Intrinsic::eLessThan2F:
			result = "LESSTHAN2F";
			break;

		case Intrinsic::eLessThan3F:
			result = "LESSTHAN3F";
			break;

		case Intrinsic::eLessThan4F:
			result = "LESSTHAN4F";
			break;

		case Intrinsic::eLessThan2D:
			result = "LESSTHAN2D";
			break;

		case Intrinsic::eLessThan3D:
			result = "LESSTHAN3D";
			break;

		case Intrinsic::eLessThan4D:
			result = "LESSTHAN4D";
			break;

		case Intrinsic::eLessThan2I:
			result = "LESSTHAN2I";
			break;

		case Intrinsic::eLessThan3I:
			result = "LESSTHAN3I";
			break;

		case Intrinsic::eLessThan4I:
			result = "LESSTHAN4I";
			break;

		case Intrinsic::eLessThan2U:
			result = "LESSTHAN2U";
			break;

		case Intrinsic::eLessThan3U:
			result = "LESSTHAN3U";
			break;

		case Intrinsic::eLessThan4U:
			result = "LESSTHAN4U";
			break;

		case Intrinsic::eLessThanEqual2F:
			result = "LESSTHANEQUAL2F";
			break;

		case Intrinsic::eLessThanEqual3F:
			result = "LESSTHANEQUAL3F";
			break;

		case Intrinsic::eLessThanEqual4F:
			result = "LESSTHANEQUAL4F";
			break;

		case Intrinsic::eLessThanEqual2D:
			result = "LESSTHANEQUAL2D";
			break;

		case Intrinsic::eLessThanEqual3D:
			result = "LESSTHANEQUAL3D";
			break;

		case Intrinsic::eLessThanEqual4D:
			result = "LESSTHANEQUAL4D";
			break;

		case Intrinsic::eLessThanEqual2I:
			result = "LESSTHANEQUAL2I";
			break;

		case Intrinsic::eLessThanEqual3I:
			result = "LESSTHANEQUAL3I";
			break;

		case Intrinsic::eLessThanEqual4I:
			result = "LESSTHANEQUAL4I";
			break;

		case Intrinsic::eLessThanEqual2U:
			result = "LESSTHANEQUAL2U";
			break;

		case Intrinsic::eLessThanEqual3U:
			result = "LESSTHANEQUAL3U";
			break;

		case Intrinsic::eLessThanEqual4U:
			result = "LESSTHANEQUAL4U";
			break;

		case Intrinsic::eGreaterThan2F:
			result = "GREATERTHAN2F";
			break;

		case Intrinsic::eGreaterThan3F:
			result = "GREATERTHAN3F";
			break;

		case Intrinsic::eGreaterThan4F:
			result = "GREATERTHAN4F";
			break;

		case Intrinsic::eGreaterThan2D:
			result = "GREATERTHAN2D";
			break;

		case Intrinsic::eGreaterThan3D:
			result = "GREATERTHAN3D";
			break;

		case Intrinsic::eGreaterThan4D:
			result = "GREATERTHAN4D";
			break;

		case Intrinsic::eGreaterThan2I:
			result = "GREATERTHAN2I";
			break;

		case Intrinsic::eGreaterThan3I:
			result = "GREATERTHAN3I";
			break;

		case Intrinsic::eGreaterThan4I:
			result = "GREATERTHAN4I";
			break;

		case Intrinsic::eGreaterThan2U:
			result = "GREATERTHAN2U";
			break;

		case Intrinsic::eGreaterThan3U:
			result = "GREATERTHAN3U";
			break;

		case Intrinsic::eGreaterThan4U:
			result = "GREATERTHAN4U";
			break;

		case Intrinsic::eGreaterThanEqual2F:
			result = "GREATERTHANEQUAL2F";
			break;

		case Intrinsic::eGreaterThanEqual3F:
			result = "GREATERTHANEQUAL3F";
			break;

		case Intrinsic::eGreaterThanEqual4F:
			result = "GREATERTHANEQUAL4F";
			break;

		case Intrinsic::eGreaterThanEqual2D:
			result = "GREATERTHANEQUAL2D";
			break;

		case Intrinsic::eGreaterThanEqual3D:
			result = "GREATERTHANEQUAL3D";
			break;

		case Intrinsic::eGreaterThanEqual4D:
			result = "GREATERTHANEQUAL4D";
			break;

		case Intrinsic::eGreaterThanEqual2I:
			result = "GREATERTHANEQUAL2I";
			break;

		case Intrinsic::eGreaterThanEqual3I:
			result = "GREATERTHANEQUAL3I";
			break;

		case Intrinsic::eGreaterThanEqual4I:
			result = "GREATERTHANEQUAL4I";
			break;

		case Intrinsic::eGreaterThanEqual2U:
			result = "GREATERTHANEQUAL2U";
			break;

		case Intrinsic::eGreaterThanEqual3U:
			result = "GREATERTHANEQUAL3U";
			break;

		case Intrinsic::eGreaterThanEqual4U:
			result = "GREATERTHANEQUAL4U";
			break;

		case Intrinsic::eEqual2F:
			result = "EQUAL2F";
			break;

		case Intrinsic::eEqual3F:
			result = "EQUAL3F";
			break;

		case Intrinsic::eEqual4F:
			result = "EQUAL4F";
			break;

		case Intrinsic::eEqual2D:
			result = "EQUAL2D";
			break;

		case Intrinsic::eEqual3D:
			result = "EQUAL3D";
			break;

		case Intrinsic::eEqual4D:
			result = "EQUAL4D";
			break;

		case Intrinsic::eEqual2I:
			result = "EQUAL2I";
			break;

		case Intrinsic::eEqual3I:
			result = "EQUAL3I";
			break;

		case Intrinsic::eEqual4I:
			result = "EQUAL4I";
			break;

		case Intrinsic::eEqual2U:
			result = "EQUAL2U";
			break;

		case Intrinsic::eEqual3U:
			result = "EQUAL3U";
			break;

		case Intrinsic::eEqual4U:
			result = "EQUAL4U";
			break;

		case Intrinsic::eNotEqual2F:
			result = "NOTEQUAL2F";
			break;

		case Intrinsic::eNotEqual3F:
			result = "NOTEQUAL3F";
			break;

		case Intrinsic::eNotEqual4F:
			result = "NOTEQUAL4F";
			break;

		case Intrinsic::eNotEqual2D:
			result = "NOTEQUAL2D";
			break;

		case Intrinsic::eNotEqual3D:
			result = "NOTEQUAL3D";
			break;

		case Intrinsic::eNotEqual4D:
			result = "NOTEQUAL4D";
			break;

		case Intrinsic::eNotEqual2I:
			result = "NOTEQUAL2I";
			break;

		case Intrinsic::eNotEqual3I:
			result = "NOTEQUAL3I";
			break;

		case Intrinsic::eNotEqual4I:
			result = "NOTEQUAL4I";
			break;

		case Intrinsic::eNotEqual2U:
			result = "NOTEQUAL2U";
			break;

		case Intrinsic::eNotEqual3U:
			result = "NOTEQUAL3U";
			break;

		case Intrinsic::eNotEqual4U:
			result = "NOTEQUAL4U";
			break;

		case Intrinsic::eAll2:
			result = "ALL2";
			break;

		case Intrinsic::eAll3:
			result = "ALL3";
			break;

		case Intrinsic::eAll4:
			result = "ALL4";
			break;

		case Intrinsic::eAny2:
			result = "ANY2";
			break;

		case Intrinsic::eAny3:
			result = "ANY3";
			break;

		case Intrinsic::eAny4:
			result = "ANY4";
			break;

		case Intrinsic::eNot2:
			result = "NOT2";
			break;

		case Intrinsic::eNot3:
			result = "NOT3";
			break;

		case Intrinsic::eNot4:
			result = "NOT4";
			break;


	// Integer Functions
		case Intrinsic::eUaddCarry1:
			result = "UADDCARRY1";
			break;

		case Intrinsic::eUaddCarry2:
			result = "UADDCARRY2";
			break;

		case Intrinsic::eUaddCarry3:
			result = "UADDCARRY3";
			break;

		case Intrinsic::eUaddCarry4:
			result = "UADDCARRY4";
			break;

		case Intrinsic::eUsubBorrow1:
			result = "USUBBORROW1";
			break;

		case Intrinsic::eUsubBorrow2:
			result = "USUBBORROW2";
			break;

		case Intrinsic::eUsubBorrow3:
			result = "USUBBORROW3";
			break;

		case Intrinsic::eUsubBorrow4:
			result = "USUBBORROW4";
			break;

		case Intrinsic::eUmulExtended1:
			result = "UMULEXTENDED1";
			break;

		case Intrinsic::eUmulExtended2:
			result = "UMULEXTENDED2";
			break;

		case Intrinsic::eUmulExtended3:
			result = "UMULEXTENDED3";
			break;

		case Intrinsic::eUmulExtended4:
			result = "UMULEXTENDED4";
			break;

		case Intrinsic::eImulExtended1:
			result = "IMULEXTENDED1";
			break;

		case Intrinsic::eImulExtended2:
			result = "IMULEXTENDED2";
			break;

		case Intrinsic::eImulExtended3:
			result = "IMULEXTENDED3";
			break;

		case Intrinsic::eImulExtended4:
			result = "IMULEXTENDED4";
			break;

		case Intrinsic::eBitfieldExtract1I:
			result = "BITFIELDEXTRACT1I";
			break;

		case Intrinsic::eBitfieldExtract2I:
			result = "BITFIELDEXTRACT2I";
			break;

		case Intrinsic::eBitfieldExtract3I:
			result = "BITFIELDEXTRACT3I";
			break;

		case Intrinsic::eBitfieldExtract4I:
			result = "BITFIELDEXTRACT4I";
			break;

		case Intrinsic::eBitfieldExtract1U:
			result = "BITFIELDEXTRACT1U";
			break;

		case Intrinsic::eBitfieldExtract2U:
			result = "BITFIELDEXTRACT2U";
			break;

		case Intrinsic::eBitfieldExtract3U:
			result = "BITFIELDEXTRACT3U";
			break;

		case Intrinsic::eBitfieldExtract4U:
			result = "BITFIELDEXTRACT4U";
			break;

		case Intrinsic::eBitfieldInsert1I:
			result = "BITFIELDINSERT1I";
			break;

		case Intrinsic::eBitfieldInsert2I:
			result = "BITFIELDINSERT2I";
			break;

		case Intrinsic::eBitfieldInsert3I:
			result = "BITFIELDINSERT3I";
			break;

		case Intrinsic::eBitfieldInsert4I:
			result = "BITFIELDINSERT4I";
			break;

		case Intrinsic::eBitfieldInsert1U:
			result = "BITFIELDINSERT1U";
			break;

		case Intrinsic::eBitfieldInsert2U:
			result = "BITFIELDINSERT2U";
			break;

		case Intrinsic::eBitfieldInsert3U:
			result = "BITFIELDINSERT3U";
			break;

		case Intrinsic::eBitfieldInsert4U:
			result = "BITFIELDINSERT4U";
			break;

		case Intrinsic::eBitfieldReverse1I:
			result = "BITFIELDREVERSE1I";
			break;

		case Intrinsic::eBitfieldReverse2I:
			result = "BITFIELDREVERSE2I";
			break;

		case Intrinsic::eBitfieldReverse3I:
			result = "BITFIELDREVERSE3I";
			break;

		case Intrinsic::eBitfieldReverse4I:
			result = "BITFIELDREVERSE4I";
			break;

		case Intrinsic::eBitfieldReverse1U:
			result = "BITFIELDREVERSE1U";
			break;

		case Intrinsic::eBitfieldReverse2U:
			result = "BITFIELDREVERSE2U";
			break;

		case Intrinsic::eBitfieldReverse3U:
			result = "BITFIELDREVERSE3U";
			break;

		case Intrinsic::eBitfieldReverse4U:
			result = "BITFIELDREVERSE4U";
			break;

		case Intrinsic::eBitCount1I:
			result = "BITCOUNT1I";
			break;

		case Intrinsic::eBitCount2I:
			result = "BITCOUNT2I";
			break;

		case Intrinsic::eBitCount3I:
			result = "BITCOUNT3I";
			break;

		case Intrinsic::eBitCount4I:
			result = "BITCOUNT4I";
			break;

		case Intrinsic::eBitCount1U:
			result = "BITCOUNT1U";
			break;

		case Intrinsic::eBitCount2U:
			result = "BITCOUNT2U";
			break;

		case Intrinsic::eBitCount3U:
			result = "BITCOUNT3U";
			break;

		case Intrinsic::eBitCount4U:
			result = "BITCOUNT4U";
			break;

		case Intrinsic::eFindLSB1I:
			result = "FINDLSB1I";
			break;

		case Intrinsic::eFindLSB2I:
			result = "FINDLSB2I";
			break;

		case Intrinsic::eFindLSB3I:
			result = "FINDLSB3I";
			break;

		case Intrinsic::eFindLSB4I:
			result = "FINDLSB4I";
			break;

		case Intrinsic::eFindLSB1U:
			result = "FINDLSB1U";
			break;

		case Intrinsic::eFindLSB2U:
			result = "FINDLSB2U";
			break;

		case Intrinsic::eFindLSB3U:
			result = "FINDLSB3U";
			break;

		case Intrinsic::eFindLSB4U:
			result = "FINDLSB4U";
			break;

		case Intrinsic::eFindMSB1I:
			result = "FINDMSB1I";
			break;

		case Intrinsic::eFindMSB2I:
			result = "FINDMSB2I";
			break;

		case Intrinsic::eFindMSB3I:
			result = "FINDMSB3I";
			break;

		case Intrinsic::eFindMSB4I:
			result = "FINDMSB4I";
			break;

		case Intrinsic::eFindMSB1U:
			result = "FINDMSB1U";
			break;

		case Intrinsic::eFindMSB2U:
			result = "FINDMSB2U";
			break;

		case Intrinsic::eFindMSB3U:
			result = "FINDMSB3U";
			break;

		case Intrinsic::eFindMSB4U:
			result = "FINDMSB4U";
			break;


	// Atomic Memory Functions
		case Intrinsic::eAtomicAddI:
			result = "ATOMICADDI";
			break;

		case Intrinsic::eAtomicAddU:
			result = "ATOMICADDU";
			break;

		case Intrinsic::eAtomicAddF:
			result = "ATOMICADDF";
			break;

		case Intrinsic::eAtomicAdd2H:
			result = "ATOMICADD2H";
			break;

		case Intrinsic::eAtomicAdd4H:
			result = "ATOMICADD4H";
			break;

		case Intrinsic::eAtomicMinI:
			result = "ATOMICMINI";
			break;

		case Intrinsic::eAtomicMinU:
			result = "ATOMICMINU";
			break;

		case Intrinsic::eAtomicMaxI:
			result = "ATOMICMAXI";
			break;

		case Intrinsic::eAtomicMaxU:
			result = "ATOMICMAXU";
			break;

		case Intrinsic::eAtomicAndI:
			result = "ATOMICANDI";
			break;

		case Intrinsic::eAtomicAndU:
			result = "ATOMICANDU";
			break;

		case Intrinsic::eAtomicOrI:
			result = "ATOMICORI";
			break;

		case Intrinsic::eAtomicOrU:
			result = "ATOMICORU";
			break;

		case Intrinsic::eAtomicXorI:
			result = "ATOMICXORI";
			break;

		case Intrinsic::eAtomicXorU:
			result = "ATOMICXORU";
			break;

		case Intrinsic::eAtomicExchangeI:
			result = "ATOMICEXCHANGEI";
			break;

		case Intrinsic::eAtomicExchangeU:
			result = "ATOMICEXCHANGEU";
			break;

		case Intrinsic::eAtomicExchangeF:
			result = "ATOMICEXCHANGEF";
			break;

		case Intrinsic::eAtomicExchange2H:
			result = "ATOMICEXCHANGE2H";
			break;

		case Intrinsic::eAtomicExchange4H:
			result = "ATOMICEXCHANGE4H";
			break;

		case Intrinsic::eAtomicCompSwapI:
			result = "ATOMICCOMPSWAPI";
			break;

		case Intrinsic::eAtomicCompSwapU:
			result = "ATOMICCOMPSWAPU";
			break;


	// Derivative Functions
		case Intrinsic::eDFdx1:
			result = "DFDX1";
			break;

		case Intrinsic::eDFdx2:
			result = "DFDX2";
			break;

		case Intrinsic::eDFdx3:
			result = "DFDX3";
			break;

		case Intrinsic::eDFdx4:
			result = "DFDX4";
			break;

		case Intrinsic::eDFdxCoarse1:
			result = "DFDXCOARSE1";
			break;

		case Intrinsic::eDFdxCoarse2:
			result = "DFDXCOARSE2";
			break;

		case Intrinsic::eDFdxCoarse3:
			result = "DFDXCOARSE3";
			break;

		case Intrinsic::eDFdxCoarse4:
			result = "DFDXCOARSE4";
			break;

		case Intrinsic::eDFdxFine1:
			result = "DFDXFINE1";
			break;

		case Intrinsic::eDFdxFine2:
			result = "DFDXFINE2";
			break;

		case Intrinsic::eDFdxFine3:
			result = "DFDXFINE3";
			break;

		case Intrinsic::eDFdxFine4:
			result = "DFDXFINE4";
			break;

		case Intrinsic::eDFdy1:
			result = "DFDY1";
			break;

		case Intrinsic::eDFdy2:
			result = "DFDY2";
			break;

		case Intrinsic::eDFdy3:
			result = "DFDY3";
			break;

		case Intrinsic::eDFdy4:
			result = "DFDY4";
			break;

		case Intrinsic::eDFdyCoarse1:
			result = "DFDYCOARSE1";
			break;

		case Intrinsic::eDFdyCoarse2:
			result = "DFDYCOARSE2";
			break;

		case Intrinsic::eDFdyCoarse3:
			result = "DFDYCOARSE3";
			break;

		case Intrinsic::eDFdyCoarse4:
			result = "DFDYCOARSE4";
			break;

		case Intrinsic::eDFdyFine1:
			result = "DFDYFINE1";
			break;

		case Intrinsic::eDFdyFine2:
			result = "DFDYFINE2";
			break;

		case Intrinsic::eDFdyFine3:
			result = "DFDYFINE3";
			break;

		case Intrinsic::eDFdyFine4:
			result = "DFDYFINE4";
			break;

		case Intrinsic::eFwidth1:
			result = "FWIDTH1";
			break;

		case Intrinsic::eFwidth2:
			result = "FWIDTH2";
			break;

		case Intrinsic::eFwidth3:
			result = "FWIDTH3";
			break;

		case Intrinsic::eFwidth4:
			result = "FWIDTH4";
			break;


	// Interpolation Functions
		case Intrinsic::eInterpolateAtCentroid1:
			result = "INTERPOLATEATCENTROID1";
			break;

		case Intrinsic::eInterpolateAtCentroid2:
			result = "INTERPOLATEATCENTROID2";
			break;

		case Intrinsic::eInterpolateAtCentroid3:
			result = "INTERPOLATEATCENTROID3";
			break;

		case Intrinsic::eInterpolateAtCentroid4:
			result = "INTERPOLATEATCENTROID4";
			break;

		case Intrinsic::eInterpolateAtSample1:
			result = "INTERPOLATEATSAMPLE1";
			break;

		case Intrinsic::eInterpolateAtSample2:
			result = "INTERPOLATEATSAMPLE2";
			break;

		case Intrinsic::eInterpolateAtSample3:
			result = "INTERPOLATEATSAMPLE3";
			break;

		case Intrinsic::eInterpolateAtSample4:
			result = "INTERPOLATEATSAMPLE4";
			break;

		case Intrinsic::eInterpolateAtOffset1:
			result = "INTERPOLATEATOFFSET1";
			break;

		case Intrinsic::eInterpolateAtOffset2:
			result = "INTERPOLATEATOFFSET2";
			break;

		case Intrinsic::eInterpolateAtOffset3:
			result = "INTERPOLATEATOFFSET3";
			break;

		case Intrinsic::eInterpolateAtOffset4:
			result = "INTERPOLATEATOFFSET4";
			break;


	// Geometry Shader Functions
		case Intrinsic::eEmitStreamVertex:
			result = "EMITSTREAMVERTEX";
			break;

		case Intrinsic::eEndStreamPrimitive:
			result = "ENDSTREAMPRIMITIVE";
			break;

		case Intrinsic::eEmitVertex:
			result = "EMITVERTEX";
			break;

		case Intrinsic::eEndPrimitive:
			result = "ENDPRIMITIVE";
			break;


	// Shader Invocation Control Functions
		case Intrinsic::eBarrier:
			result = "BARRIER";
			break;


	// Miscellaneous FUnctions
		case Intrinsic::eHelperInvocation:
			result = "HELPERINVOCATION";
			break;


	// Shader Memory Control Functions
		case Intrinsic::eMemoryBarrier:
			result = "MEMORYBARRIER";
			break;

		case Intrinsic::eMemoryBarrierBuffer:
			result = "MEMORYBARRIERBUFFER";
			break;

		case Intrinsic::eMemoryBarrierShared:
			result = "MEMORYBARRIERSHARED";
			break;

		case Intrinsic::eMemoryBarrierImage:
			result = "MEMORYBARRIERIMAGE";
			break;

		case Intrinsic::eGroupMemoryBarrier:
			result = "GROUPMEMORYBARRIER";
			break;


	// Ray tracing Shader Functions
		case Intrinsic::eTraceRay:
			result = "TRACERAY";
			break;

		case Intrinsic::eReportIntersection:
			result = "REPORTINTERSECTION";
			break;

		case Intrinsic::eExecuteCallable:
			result = "EXECUTECALLABLE";
			break;


	//Mesh Shader Functions
		case Intrinsic::eSetMeshOutputCounts:
			result = "SETMESHOUTPUTCOUNTS";
			break;

		case Intrinsic::eDispatchMesh:
			result = "DISPATCHMESH";
			break;


	//Shader Subgroup Functions
		case Intrinsic::eSubgroupBarrier:
			result = "SUBGROUPBARRIER";
			break;

		case Intrinsic::eSubgroupMemoryBarrier:
			result = "SUBGROUPMEMORYBARRIER";
			break;

		case Intrinsic::eSubgroupMemoryBarrierBuffer:
			result = "SUBGROUPMEMORYBARRIERBUFFER";
			break;

		case Intrinsic::eSubgroupMemoryBarrierShared:
			result = "SUBGROUPMEMORYBARRIERSHARED";
			break;

		case Intrinsic::eSubgroupMemoryBarrierImage:
			result = "SUBGROUPMEMORYBARRIERIMAGE";
			break;

		case Intrinsic::eSubgroupElect:
			result = "SUBGROUPELECT";
			break;

		case Intrinsic::eSubgroupAll:
			result = "SUBGROUPALL";
			break;

		case Intrinsic::eSubgroupAny:
			result = "SUBGROUPANY";
			break;

		case Intrinsic::eSubgroupAllEqual1F:
			result = "SUBGROUPALLEQUAL1F";
			break;

		case Intrinsic::eSubgroupAllEqual2F:
			result = "SUBGROUPALLEQUAL2F";
			break;

		case Intrinsic::eSubgroupAllEqual3F:
			result = "SUBGROUPALLEQUAL3F";
			break;

		case Intrinsic::eSubgroupAllEqual4F:
			result = "SUBGROUPALLEQUAL4F";
			break;

		case Intrinsic::eSubgroupAllEqual1I:
			result = "SUBGROUPALLEQUAL1I";
			break;

		case Intrinsic::eSubgroupAllEqual2I:
			result = "SUBGROUPALLEQUAL2I";
			break;

		case Intrinsic::eSubgroupAllEqual3I:
			result = "SUBGROUPALLEQUAL3I";
			break;

		case Intrinsic::eSubgroupAllEqual4I:
			result = "SUBGROUPALLEQUAL4I";
			break;

		case Intrinsic::eSubgroupAllEqual1U:
			result = "SUBGROUPALLEQUAL1U";
			break;

		case Intrinsic::eSubgroupAllEqual2U:
			result = "SUBGROUPALLEQUAL2U";
			break;

		case Intrinsic::eSubgroupAllEqual3U:
			result = "SUBGROUPALLEQUAL3U";
			break;

		case Intrinsic::eSubgroupAllEqual4U:
			result = "SUBGROUPALLEQUAL4U";
			break;

		case Intrinsic::eSubgroupAllEqual1B:
			result = "SUBGROUPALLEQUAL1B";
			break;

		case Intrinsic::eSubgroupAllEqual2B:
			result = "SUBGROUPALLEQUAL2B";
			break;

		case Intrinsic::eSubgroupAllEqual3B:
			result = "SUBGROUPALLEQUAL3B";
			break;

		case Intrinsic::eSubgroupAllEqual4B:
			result = "SUBGROUPALLEQUAL4B";
			break;

		case Intrinsic::eSubgroupAllEqual1D:
			result = "SUBGROUPALLEQUAL1D";
			break;

		case Intrinsic::eSubgroupAllEqual2D:
			result = "SUBGROUPALLEQUAL2D";
			break;

		case Intrinsic::eSubgroupAllEqual3D:
			result = "SUBGROUPALLEQUAL3D";
			break;

		case Intrinsic::eSubgroupAllEqual4D:
			result = "SUBGROUPALLEQUAL4D";
			break;

		case Intrinsic::eSubgroupBroadcast1F:
			result = "SUBGROUPBROADCAST1F";
			break;

		case Intrinsic::eSubgroupBroadcast2F:
			result = "SUBGROUPBROADCAST2F";
			break;

		case Intrinsic::eSubgroupBroadcast3F:
			result = "SUBGROUPBROADCAST3F";
			break;

		case Intrinsic::eSubgroupBroadcast4F:
			result = "SUBGROUPBROADCAST4F";
			break;

		case Intrinsic::eSubgroupBroadcast1I:
			result = "SUBGROUPBROADCAST1I";
			break;

		case Intrinsic::eSubgroupBroadcast2I:
			result = "SUBGROUPBROADCAST2I";
			break;

		case Intrinsic::eSubgroupBroadcast3I:
			result = "SUBGROUPBROADCAST3I";
			break;

		case Intrinsic::eSubgroupBroadcast4I:
			result = "SUBGROUPBROADCAST4I";
			break;

		case Intrinsic::eSubgroupBroadcast1U:
			result = "SUBGROUPBROADCAST1U";
			break;

		case Intrinsic::eSubgroupBroadcast2U:
			result = "SUBGROUPBROADCAST2U";
			break;

		case Intrinsic::eSubgroupBroadcast3U:
			result = "SUBGROUPBROADCAST3U";
			break;

		case Intrinsic::eSubgroupBroadcast4U:
			result = "SUBGROUPBROADCAST4U";
			break;

		case Intrinsic::eSubgroupBroadcast1B:
			result = "SUBGROUPBROADCAST1B";
			break;

		case Intrinsic::eSubgroupBroadcast2B:
			result = "SUBGROUPBROADCAST2B";
			break;

		case Intrinsic::eSubgroupBroadcast3B:
			result = "SUBGROUPBROADCAST3B";
			break;

		case Intrinsic::eSubgroupBroadcast4B:
			result = "SUBGROUPBROADCAST4B";
			break;

		case Intrinsic::eSubgroupBroadcast1D:
			result = "SUBGROUPBROADCAST1D";
			break;

		case Intrinsic::eSubgroupBroadcast2D:
			result = "SUBGROUPBROADCAST2D";
			break;

		case Intrinsic::eSubgroupBroadcast3D:
			result = "SUBGROUPBROADCAST3D";
			break;

		case Intrinsic::eSubgroupBroadcast4D:
			result = "SUBGROUPBROADCAST4D";
			break;

		case Intrinsic::eSubgroupBroadcastFirst1F:
			result = "SUBGROUPBROADCASTFIRST1F";
			break;

		case Intrinsic::eSubgroupBroadcastFirst2F:
			result = "SUBGROUPBROADCASTFIRST2F";
			break;

		case Intrinsic::eSubgroupBroadcastFirst3F:
			result = "SUBGROUPBROADCASTFIRST3F";
			break;

		case Intrinsic::eSubgroupBroadcastFirst4F:
			result = "SUBGROUPBROADCASTFIRST4F";
			break;

		case Intrinsic::eSubgroupBroadcastFirst1I:
			result = "SUBGROUPBROADCASTFIRST1I";
			break;

		case Intrinsic::eSubgroupBroadcastFirst2I:
			result = "SUBGROUPBROADCASTFIRST2I";
			break;

		case Intrinsic::eSubgroupBroadcastFirst3I:
			result = "SUBGROUPBROADCASTFIRST3I";
			break;

		case Intrinsic::eSubgroupBroadcastFirst4I:
			result = "SUBGROUPBROADCASTFIRST4I";
			break;

		case Intrinsic::eSubgroupBroadcastFirst1U:
			result = "SUBGROUPBROADCASTFIRST1U";
			break;

		case Intrinsic::eSubgroupBroadcastFirst2U:
			result = "SUBGROUPBROADCASTFIRST2U";
			break;

		case Intrinsic::eSubgroupBroadcastFirst3U:
			result = "SUBGROUPBROADCASTFIRST3U";
			break;

		case Intrinsic::eSubgroupBroadcastFirst4U:
			result = "SUBGROUPBROADCASTFIRST4U";
			break;

		case Intrinsic::eSubgroupBroadcastFirst1B:
			result = "SUBGROUPBROADCASTFIRST1B";
			break;

		case Intrinsic::eSubgroupBroadcastFirst2B:
			result = "SUBGROUPBROADCASTFIRST2B";
			break;

		case Intrinsic::eSubgroupBroadcastFirst3B:
			result = "SUBGROUPBROADCASTFIRST3B";
			break;

		case Intrinsic::eSubgroupBroadcastFirst4B:
			result = "SUBGROUPBROADCASTFIRST4B";
			break;

		case Intrinsic::eSubgroupBroadcastFirst1D:
			result = "SUBGROUPBROADCASTFIRST1D";
			break;

		case Intrinsic::eSubgroupBroadcastFirst2D:
			result = "SUBGROUPBROADCASTFIRST2D";
			break;

		case Intrinsic::eSubgroupBroadcastFirst3D:
			result = "SUBGROUPBROADCASTFIRST3D";
			break;

		case Intrinsic::eSubgroupBroadcastFirst4D:
			result = "SUBGROUPBROADCASTFIRST4D";
			break;

		case Intrinsic::eSubgroupBallot:
			result = "SUBGROUPBALLOT";
			break;

		case Intrinsic::eSubgroupInverseBallot:
			result = "SUBGROUPINVERSEBALLOT";
			break;

		case Intrinsic::eSubgroupBallotBitExtract:
			result = "SUBGROUPBALLOTBITEXTRACT";
			break;

		case Intrinsic::eSubgroupBallotBitCount:
			result = "SUBGROUPBALLOTBITCOUNT";
			break;

		case Intrinsic::eSubgroupBallotInclusiveBitCount:
			result = "SUBGROUPBALLOTINCLUSIVEBITCOUNT";
			break;

		case Intrinsic::eSubgroupBallotExclusiveBitCount:
			result = "SUBGROUPBALLOTEXCLUSIVEBITCOUNT";
			break;

		case Intrinsic::eSubgroupBallotFindLSB:
			result = "SUBGROUPBALLOTFINDLSB";
			break;

		case Intrinsic::eSubgroupBallotFindMSB:
			result = "SUBGROUPBALLOTFINDMSB";
			break;

		case Intrinsic::eSubgroupShuffle1F:
			result = "SUBGROUPSHUFFLE1F";
			break;

		case Intrinsic::eSubgroupShuffle2F:
			result = "SUBGROUPSHUFFLE2F";
			break;

		case Intrinsic::eSubgroupShuffle3F:
			result = "SUBGROUPSHUFFLE3F";
			break;

		case Intrinsic::eSubgroupShuffle4F:
			result = "SUBGROUPSHUFFLE4F";
			break;

		case Intrinsic::eSubgroupShuffle1I:
			result = "SUBGROUPSHUFFLE1I";
			break;

		case Intrinsic::eSubgroupShuffle2I:
			result = "SUBGROUPSHUFFLE2I";
			break;

		case Intrinsic::eSubgroupShuffle3I:
			result = "SUBGROUPSHUFFLE3I";
			break;

		case Intrinsic::eSubgroupShuffle4I:
			result = "SUBGROUPSHUFFLE4I";
			break;

		case Intrinsic::eSubgroupShuffle1U:
			result = "SUBGROUPSHUFFLE1U";
			break;

		case Intrinsic::eSubgroupShuffle2U:
			result = "SUBGROUPSHUFFLE2U";
			break;

		case Intrinsic::eSubgroupShuffle3U:
			result = "SUBGROUPSHUFFLE3U";
			break;

		case Intrinsic::eSubgroupShuffle4U:
			result = "SUBGROUPSHUFFLE4U";
			break;

		case Intrinsic::eSubgroupShuffle1B:
			result = "SUBGROUPSHUFFLE1B";
			break;

		case Intrinsic::eSubgroupShuffle2B:
			result = "SUBGROUPSHUFFLE2B";
			break;

		case Intrinsic::eSubgroupShuffle3B:
			result = "SUBGROUPSHUFFLE3B";
			break;

		case Intrinsic::eSubgroupShuffle4B:
			result = "SUBGROUPSHUFFLE4B";
			break;

		case Intrinsic::eSubgroupShuffle1D:
			result = "SUBGROUPSHUFFLE1D";
			break;

		case Intrinsic::eSubgroupShuffle2D:
			result = "SUBGROUPSHUFFLE2D";
			break;

		case Intrinsic::eSubgroupShuffle3D:
			result = "SUBGROUPSHUFFLE3D";
			break;

		case Intrinsic::eSubgroupShuffle4D:
			result = "SUBGROUPSHUFFLE4D";
			break;

		case Intrinsic::eSubgroupShuffleXor1F:
			result = "SUBGROUPSHUFFLEXOR1F";
			break;

		case Intrinsic::eSubgroupShuffleXor2F:
			result = "SUBGROUPSHUFFLEXOR2F";
			break;

		case Intrinsic::eSubgroupShuffleXor3F:
			result = "SUBGROUPSHUFFLEXOR3F";
			break;

		case Intrinsic::eSubgroupShuffleXor4F:
			result = "SUBGROUPSHUFFLEXOR4F";
			break;

		case Intrinsic::eSubgroupShuffleXor1I:
			result = "SUBGROUPSHUFFLEXOR1I";
			break;

		case Intrinsic::eSubgroupShuffleXor2I:
			result = "SUBGROUPSHUFFLEXOR2I";
			break;

		case Intrinsic::eSubgroupShuffleXor3I:
			result = "SUBGROUPSHUFFLEXOR3I";
			break;

		case Intrinsic::eSubgroupShuffleXor4I:
			result = "SUBGROUPSHUFFLEXOR4I";
			break;

		case Intrinsic::eSubgroupShuffleXor1U:
			result = "SUBGROUPSHUFFLEXOR1U";
			break;

		case Intrinsic::eSubgroupShuffleXor2U:
			result = "SUBGROUPSHUFFLEXOR2U";
			break;

		case Intrinsic::eSubgroupShuffleXor3U:
			result = "SUBGROUPSHUFFLEXOR3U";
			break;

		case Intrinsic::eSubgroupShuffleXor4U:
			result = "SUBGROUPSHUFFLEXOR4U";
			break;

		case Intrinsic::eSubgroupShuffleXor1B:
			result = "SUBGROUPSHUFFLEXOR1B";
			break;

		case Intrinsic::eSubgroupShuffleXor2B:
			result = "SUBGROUPSHUFFLEXOR2B";
			break;

		case Intrinsic::eSubgroupShuffleXor3B:
			result = "SUBGROUPSHUFFLEXOR3B";
			break;

		case Intrinsic::eSubgroupShuffleXor4B:
			result = "SUBGROUPSHUFFLEXOR4B";
			break;

		case Intrinsic::eSubgroupShuffleXor1D:
			result = "SUBGROUPSHUFFLEXOR1D";
			break;

		case Intrinsic::eSubgroupShuffleXor2D:
			result = "SUBGROUPSHUFFLEXOR2D";
			break;

		case Intrinsic::eSubgroupShuffleXor3D:
			result = "SUBGROUPSHUFFLEXOR3D";
			break;

		case Intrinsic::eSubgroupShuffleXor4D:
			result = "SUBGROUPSHUFFLEXOR4D";
			break;

		case Intrinsic::eSubgroupShuffleUp1F:
			result = "SUBGROUPSHUFFLEUP1F";
			break;

		case Intrinsic::eSubgroupShuffleUp2F:
			result = "SUBGROUPSHUFFLEUP2F";
			break;

		case Intrinsic::eSubgroupShuffleUp3F:
			result = "SUBGROUPSHUFFLEUP3F";
			break;

		case Intrinsic::eSubgroupShuffleUp4F:
			result = "SUBGROUPSHUFFLEUP4F";
			break;

		case Intrinsic::eSubgroupShuffleUp1I:
			result = "SUBGROUPSHUFFLEUP1I";
			break;

		case Intrinsic::eSubgroupShuffleUp2I:
			result = "SUBGROUPSHUFFLEUP2I";
			break;

		case Intrinsic::eSubgroupShuffleUp3I:
			result = "SUBGROUPSHUFFLEUP3I";
			break;

		case Intrinsic::eSubgroupShuffleUp4I:
			result = "SUBGROUPSHUFFLEUP4I";
			break;

		case Intrinsic::eSubgroupShuffleUp1U:
			result = "SUBGROUPSHUFFLEUP1U";
			break;

		case Intrinsic::eSubgroupShuffleUp2U:
			result = "SUBGROUPSHUFFLEUP2U";
			break;

		case Intrinsic::eSubgroupShuffleUp3U:
			result = "SUBGROUPSHUFFLEUP3U";
			break;

		case Intrinsic::eSubgroupShuffleUp4U:
			result = "SUBGROUPSHUFFLEUP4U";
			break;

		case Intrinsic::eSubgroupShuffleUp1B:
			result = "SUBGROUPSHUFFLEUP1B";
			break;

		case Intrinsic::eSubgroupShuffleUp2B:
			result = "SUBGROUPSHUFFLEUP2B";
			break;

		case Intrinsic::eSubgroupShuffleUp3B:
			result = "SUBGROUPSHUFFLEUP3B";
			break;

		case Intrinsic::eSubgroupShuffleUp4B:
			result = "SUBGROUPSHUFFLEUP4B";
			break;

		case Intrinsic::eSubgroupShuffleUp1D:
			result = "SUBGROUPSHUFFLEUP1D";
			break;

		case Intrinsic::eSubgroupShuffleUp2D:
			result = "SUBGROUPSHUFFLEUP2D";
			break;

		case Intrinsic::eSubgroupShuffleUp3D:
			result = "SUBGROUPSHUFFLEUP3D";
			break;

		case Intrinsic::eSubgroupShuffleUp4D:
			result = "SUBGROUPSHUFFLEUP4D";
			break;

		case Intrinsic::eSubgroupShuffleDown1F:
			result = "SUBGROUPSHUFFLEDOWN1F";
			break;

		case Intrinsic::eSubgroupShuffleDown2F:
			result = "SUBGROUPSHUFFLEDOWN2F";
			break;

		case Intrinsic::eSubgroupShuffleDown3F:
			result = "SUBGROUPSHUFFLEDOWN3F";
			break;

		case Intrinsic::eSubgroupShuffleDown4F:
			result = "SUBGROUPSHUFFLEDOWN4F";
			break;

		case Intrinsic::eSubgroupShuffleDown1I:
			result = "SUBGROUPSHUFFLEDOWN1I";
			break;

		case Intrinsic::eSubgroupShuffleDown2I:
			result = "SUBGROUPSHUFFLEDOWN2I";
			break;

		case Intrinsic::eSubgroupShuffleDown3I:
			result = "SUBGROUPSHUFFLEDOWN3I";
			break;

		case Intrinsic::eSubgroupShuffleDown4I:
			result = "SUBGROUPSHUFFLEDOWN4I";
			break;

		case Intrinsic::eSubgroupShuffleDown1U:
			result = "SUBGROUPSHUFFLEDOWN1U";
			break;

		case Intrinsic::eSubgroupShuffleDown2U:
			result = "SUBGROUPSHUFFLEDOWN2U";
			break;

		case Intrinsic::eSubgroupShuffleDown3U:
			result = "SUBGROUPSHUFFLEDOWN3U";
			break;

		case Intrinsic::eSubgroupShuffleDown4U:
			result = "SUBGROUPSHUFFLEDOWN4U";
			break;

		case Intrinsic::eSubgroupShuffleDown1B:
			result = "SUBGROUPSHUFFLEDOWN1B";
			break;

		case Intrinsic::eSubgroupShuffleDown2B:
			result = "SUBGROUPSHUFFLEDOWN2B";
			break;

		case Intrinsic::eSubgroupShuffleDown3B:
			result = "SUBGROUPSHUFFLEDOWN3B";
			break;

		case Intrinsic::eSubgroupShuffleDown4B:
			result = "SUBGROUPSHUFFLEDOWN4B";
			break;

		case Intrinsic::eSubgroupShuffleDown1D:
			result = "SUBGROUPSHUFFLEDOWN1D";
			break;

		case Intrinsic::eSubgroupShuffleDown2D:
			result = "SUBGROUPSHUFFLEDOWN2D";
			break;

		case Intrinsic::eSubgroupShuffleDown3D:
			result = "SUBGROUPSHUFFLEDOWN3D";
			break;

		case Intrinsic::eSubgroupShuffleDown4D:
			result = "SUBGROUPSHUFFLEDOWN4D";
			break;

		case Intrinsic::eSubgroupAdd1F:
			result = "SUBGROUPADD1F";
			break;

		case Intrinsic::eSubgroupAdd2F:
			result = "SUBGROUPADD2F";
			break;

		case Intrinsic::eSubgroupAdd3F:
			result = "SUBGROUPADD3F";
			break;

		case Intrinsic::eSubgroupAdd4F:
			result = "SUBGROUPADD4F";
			break;

		case Intrinsic::eSubgroupAdd1I:
			result = "SUBGROUPADD1I";
			break;

		case Intrinsic::eSubgroupAdd2I:
			result = "SUBGROUPADD2I";
			break;

		case Intrinsic::eSubgroupAdd3I:
			result = "SUBGROUPADD3I";
			break;

		case Intrinsic::eSubgroupAdd4I:
			result = "SUBGROUPADD4I";
			break;

		case Intrinsic::eSubgroupAdd1U:
			result = "SUBGROUPADD1U";
			break;

		case Intrinsic::eSubgroupAdd2U:
			result = "SUBGROUPADD2U";
			break;

		case Intrinsic::eSubgroupAdd3U:
			result = "SUBGROUPADD3U";
			break;

		case Intrinsic::eSubgroupAdd4U:
			result = "SUBGROUPADD4U";
			break;

		case Intrinsic::eSubgroupAdd1D:
			result = "SUBGROUPADD1D";
			break;

		case Intrinsic::eSubgroupAdd2D:
			result = "SUBGROUPADD2D";
			break;

		case Intrinsic::eSubgroupAdd3D:
			result = "SUBGROUPADD3D";
			break;

		case Intrinsic::eSubgroupAdd4D:
			result = "SUBGROUPADD4D";
			break;

		case Intrinsic::eSubgroupMul1F:
			result = "SUBGROUPMUL1F";
			break;

		case Intrinsic::eSubgroupMul2F:
			result = "SUBGROUPMUL2F";
			break;

		case Intrinsic::eSubgroupMul3F:
			result = "SUBGROUPMUL3F";
			break;

		case Intrinsic::eSubgroupMul4F:
			result = "SUBGROUPMUL4F";
			break;

		case Intrinsic::eSubgroupMul1I:
			result = "SUBGROUPMUL1I";
			break;

		case Intrinsic::eSubgroupMul2I:
			result = "SUBGROUPMUL2I";
			break;

		case Intrinsic::eSubgroupMul3I:
			result = "SUBGROUPMUL3I";
			break;

		case Intrinsic::eSubgroupMul4I:
			result = "SUBGROUPMUL4I";
			break;

		case Intrinsic::eSubgroupMul1U:
			result = "SUBGROUPMUL1U";
			break;

		case Intrinsic::eSubgroupMul2U:
			result = "SUBGROUPMUL2U";
			break;

		case Intrinsic::eSubgroupMul3U:
			result = "SUBGROUPMUL3U";
			break;

		case Intrinsic::eSubgroupMul4U:
			result = "SUBGROUPMUL4U";
			break;

		case Intrinsic::eSubgroupMul1D:
			result = "SUBGROUPMUL1D";
			break;

		case Intrinsic::eSubgroupMul2D:
			result = "SUBGROUPMUL2D";
			break;

		case Intrinsic::eSubgroupMul3D:
			result = "SUBGROUPMUL3D";
			break;

		case Intrinsic::eSubgroupMul4D:
			result = "SUBGROUPMUL4D";
			break;

		case Intrinsic::eSubgroupMin1F:
			result = "SUBGROUPMIN1F";
			break;

		case Intrinsic::eSubgroupMin2F:
			result = "SUBGROUPMIN2F";
			break;

		case Intrinsic::eSubgroupMin3F:
			result = "SUBGROUPMIN3F";
			break;

		case Intrinsic::eSubgroupMin4F:
			result = "SUBGROUPMIN4F";
			break;

		case Intrinsic::eSubgroupMin1I:
			result = "SUBGROUPMIN1I";
			break;

		case Intrinsic::eSubgroupMin2I:
			result = "SUBGROUPMIN2I";
			break;

		case Intrinsic::eSubgroupMin3I:
			result = "SUBGROUPMIN3I";
			break;

		case Intrinsic::eSubgroupMin4I:
			result = "SUBGROUPMIN4I";
			break;

		case Intrinsic::eSubgroupMin1U:
			result = "SUBGROUPMIN1U";
			break;

		case Intrinsic::eSubgroupMin2U:
			result = "SUBGROUPMIN2U";
			break;

		case Intrinsic::eSubgroupMin3U:
			result = "SUBGROUPMIN3U";
			break;

		case Intrinsic::eSubgroupMin4U:
			result = "SUBGROUPMIN4U";
			break;

		case Intrinsic::eSubgroupMin1D:
			result = "SUBGROUPMIN1D";
			break;

		case Intrinsic::eSubgroupMin2D:
			result = "SUBGROUPMIN2D";
			break;

		case Intrinsic::eSubgroupMin3D:
			result = "SUBGROUPMIN3D";
			break;

		case Intrinsic::eSubgroupMin4D:
			result = "SUBGROUPMIN4D";
			break;

		case Intrinsic::eSubgroupMax1F:
			result = "SUBGROUPMAX1F";
			break;

		case Intrinsic::eSubgroupMax2F:
			result = "SUBGROUPMAX2F";
			break;

		case Intrinsic::eSubgroupMax3F:
			result = "SUBGROUPMAX3F";
			break;

		case Intrinsic::eSubgroupMax4F:
			result = "SUBGROUPMAX4F";
			break;

		case Intrinsic::eSubgroupMax1I:
			result = "SUBGROUPMAX1I";
			break;

		case Intrinsic::eSubgroupMax2I:
			result = "SUBGROUPMAX2I";
			break;

		case Intrinsic::eSubgroupMax3I:
			result = "SUBGROUPMAX3I";
			break;

		case Intrinsic::eSubgroupMax4I:
			result = "SUBGROUPMAX4I";
			break;

		case Intrinsic::eSubgroupMax1U:
			result = "SUBGROUPMAX1U";
			break;

		case Intrinsic::eSubgroupMax2U:
			result = "SUBGROUPMAX2U";
			break;

		case Intrinsic::eSubgroupMax3U:
			result = "SUBGROUPMAX3U";
			break;

		case Intrinsic::eSubgroupMax4U:
			result = "SUBGROUPMAX4U";
			break;

		case Intrinsic::eSubgroupMax1D:
			result = "SUBGROUPMAX1D";
			break;

		case Intrinsic::eSubgroupMax2D:
			result = "SUBGROUPMAX2D";
			break;

		case Intrinsic::eSubgroupMax3D:
			result = "SUBGROUPMAX3D";
			break;

		case Intrinsic::eSubgroupMax4D:
			result = "SUBGROUPMAX4D";
			break;

		case Intrinsic::eSubgroupAnd1I:
			result = "SUBGROUPAND1I";
			break;

		case Intrinsic::eSubgroupAnd2I:
			result = "SUBGROUPAND2I";
			break;

		case Intrinsic::eSubgroupAnd3I:
			result = "SUBGROUPAND3I";
			break;

		case Intrinsic::eSubgroupAnd4I:
			result = "SUBGROUPAND4I";
			break;

		case Intrinsic::eSubgroupAnd1U:
			result = "SUBGROUPAND1U";
			break;

		case Intrinsic::eSubgroupAnd2U:
			result = "SUBGROUPAND2U";
			break;

		case Intrinsic::eSubgroupAnd3U:
			result = "SUBGROUPAND3U";
			break;

		case Intrinsic::eSubgroupAnd4U:
			result = "SUBGROUPAND4U";
			break;

		case Intrinsic::eSubgroupAnd1B:
			result = "SUBGROUPAND1B";
			break;

		case Intrinsic::eSubgroupAnd2B:
			result = "SUBGROUPAND2B";
			break;

		case Intrinsic::eSubgroupAnd3B:
			result = "SUBGROUPAND3B";
			break;

		case Intrinsic::eSubgroupAnd4B:
			result = "SUBGROUPAND4B";
			break;

		case Intrinsic::eSubgroupOr1I:
			result = "SUBGROUPOR1I";
			break;

		case Intrinsic::eSubgroupOr2I:
			result = "SUBGROUPOR2I";
			break;

		case Intrinsic::eSubgroupOr3I:
			result = "SUBGROUPOR3I";
			break;

		case Intrinsic::eSubgroupOr4I:
			result = "SUBGROUPOR4I";
			break;

		case Intrinsic::eSubgroupOr1U:
			result = "SUBGROUPOR1U";
			break;

		case Intrinsic::eSubgroupOr2U:
			result = "SUBGROUPOR2U";
			break;

		case Intrinsic::eSubgroupOr3U:
			result = "SUBGROUPOR3U";
			break;

		case Intrinsic::eSubgroupOr4U:
			result = "SUBGROUPOR4U";
			break;

		case Intrinsic::eSubgroupOr1B:
			result = "SUBGROUPOR1B";
			break;

		case Intrinsic::eSubgroupOr2B:
			result = "SUBGROUPOR2B";
			break;

		case Intrinsic::eSubgroupOr3B:
			result = "SUBGROUPOR3B";
			break;

		case Intrinsic::eSubgroupOr4B:
			result = "SUBGROUPOR4B";
			break;

		case Intrinsic::eSubgroupXor1I:
			result = "SUBGROUPXOR1I";
			break;

		case Intrinsic::eSubgroupXor2I:
			result = "SUBGROUPXOR2I";
			break;

		case Intrinsic::eSubgroupXor3I:
			result = "SUBGROUPXOR3I";
			break;

		case Intrinsic::eSubgroupXor4I:
			result = "SUBGROUPXOR4I";
			break;

		case Intrinsic::eSubgroupXor1U:
			result = "SUBGROUPXOR1U";
			break;

		case Intrinsic::eSubgroupXor2U:
			result = "SUBGROUPXOR2U";
			break;

		case Intrinsic::eSubgroupXor3U:
			result = "SUBGROUPXOR3U";
			break;

		case Intrinsic::eSubgroupXor4U:
			result = "SUBGROUPXOR4U";
			break;

		case Intrinsic::eSubgroupXor1B:
			result = "SUBGROUPXOR1B";
			break;

		case Intrinsic::eSubgroupXor2B:
			result = "SUBGROUPXOR2B";
			break;

		case Intrinsic::eSubgroupXor3B:
			result = "SUBGROUPXOR3B";
			break;

		case Intrinsic::eSubgroupXor4B:
			result = "SUBGROUPXOR4B";
			break;

		case Intrinsic::eSubgroupInclusiveAdd1F:
			result = "SUBGROUPINCLUSIVEADD1F";
			break;

		case Intrinsic::eSubgroupInclusiveAdd2F:
			result = "SUBGROUPINCLUSIVEADD2F";
			break;

		case Intrinsic::eSubgroupInclusiveAdd3F:
			result = "SUBGROUPINCLUSIVEADD3F";
			break;

		case Intrinsic::eSubgroupInclusiveAdd4F:
			result = "SUBGROUPINCLUSIVEADD4F";
			break;

		case Intrinsic::eSubgroupInclusiveAdd1I:
			result = "SUBGROUPINCLUSIVEADD1I";
			break;

		case Intrinsic::eSubgroupInclusiveAdd2I:
			result = "SUBGROUPINCLUSIVEADD2I";
			break;

		case Intrinsic::eSubgroupInclusiveAdd3I:
			result = "SUBGROUPINCLUSIVEADD3I";
			break;

		case Intrinsic::eSubgroupInclusiveAdd4I:
			result = "SUBGROUPINCLUSIVEADD4I";
			break;

		case Intrinsic::eSubgroupInclusiveAdd1U:
			result = "SUBGROUPINCLUSIVEADD1U";
			break;

		case Intrinsic::eSubgroupInclusiveAdd2U:
			result = "SUBGROUPINCLUSIVEADD2U";
			break;

		case Intrinsic::eSubgroupInclusiveAdd3U:
			result = "SUBGROUPINCLUSIVEADD3U";
			break;

		case Intrinsic::eSubgroupInclusiveAdd4U:
			result = "SUBGROUPINCLUSIVEADD4U";
			break;

		case Intrinsic::eSubgroupInclusiveAdd1D:
			result = "SUBGROUPINCLUSIVEADD1D";
			break;

		case Intrinsic::eSubgroupInclusiveAdd2D:
			result = "SUBGROUPINCLUSIVEADD2D";
			break;

		case Intrinsic::eSubgroupInclusiveAdd3D:
			result = "SUBGROUPINCLUSIVEADD3D";
			break;

		case Intrinsic::eSubgroupInclusiveAdd4D:
			result = "SUBGROUPINCLUSIVEADD4D";
			break;

		case Intrinsic::eSubgroupInclusiveMul1F:
			result = "SUBGROUPINCLUSIVEMUL1F";
			break;

		case Intrinsic::eSubgroupInclusiveMul2F:
			result = "SUBGROUPINCLUSIVEMUL2F";
			break;

		case Intrinsic::eSubgroupInclusiveMul3F:
			result = "SUBGROUPINCLUSIVEMUL3F";
			break;

		case Intrinsic::eSubgroupInclusiveMul4F:
			result = "SUBGROUPINCLUSIVEMUL4F";
			break;

		case Intrinsic::eSubgroupInclusiveMul1I:
			result = "SUBGROUPINCLUSIVEMUL1I";
			break;

		case Intrinsic::eSubgroupInclusiveMul2I:
			result = "SUBGROUPINCLUSIVEMUL2I";
			break;

		case Intrinsic::eSubgroupInclusiveMul3I:
			result = "SUBGROUPINCLUSIVEMUL3I";
			break;

		case Intrinsic::eSubgroupInclusiveMul4I:
			result = "SUBGROUPINCLUSIVEMUL4I";
			break;

		case Intrinsic::eSubgroupInclusiveMul1U:
			result = "SUBGROUPINCLUSIVEMUL1U";
			break;

		case Intrinsic::eSubgroupInclusiveMul2U:
			result = "SUBGROUPINCLUSIVEMUL2U";
			break;

		case Intrinsic::eSubgroupInclusiveMul3U:
			result = "SUBGROUPINCLUSIVEMUL3U";
			break;

		case Intrinsic::eSubgroupInclusiveMul4U:
			result = "SUBGROUPINCLUSIVEMUL4U";
			break;

		case Intrinsic::eSubgroupInclusiveMul1D:
			result = "SUBGROUPINCLUSIVEMUL1D";
			break;

		case Intrinsic::eSubgroupInclusiveMul2D:
			result = "SUBGROUPINCLUSIVEMUL2D";
			break;

		case Intrinsic::eSubgroupInclusiveMul3D:
			result = "SUBGROUPINCLUSIVEMUL3D";
			break;

		case Intrinsic::eSubgroupInclusiveMul4D:
			result = "SUBGROUPINCLUSIVEMUL4D";
			break;

		case Intrinsic::eSubgroupInclusiveMin1F:
			result = "SUBGROUPINCLUSIVEMIN1F";
			break;

		case Intrinsic::eSubgroupInclusiveMin2F:
			result = "SUBGROUPINCLUSIVEMIN2F";
			break;

		case Intrinsic::eSubgroupInclusiveMin3F:
			result = "SUBGROUPINCLUSIVEMIN3F";
			break;

		case Intrinsic::eSubgroupInclusiveMin4F:
			result = "SUBGROUPINCLUSIVEMIN4F";
			break;

		case Intrinsic::eSubgroupInclusiveMin1I:
			result = "SUBGROUPINCLUSIVEMIN1I";
			break;

		case Intrinsic::eSubgroupInclusiveMin2I:
			result = "SUBGROUPINCLUSIVEMIN2I";
			break;

		case Intrinsic::eSubgroupInclusiveMin3I:
			result = "SUBGROUPINCLUSIVEMIN3I";
			break;

		case Intrinsic::eSubgroupInclusiveMin4I:
			result = "SUBGROUPINCLUSIVEMIN4I";
			break;

		case Intrinsic::eSubgroupInclusiveMin1U:
			result = "SUBGROUPINCLUSIVEMIN1U";
			break;

		case Intrinsic::eSubgroupInclusiveMin2U:
			result = "SUBGROUPINCLUSIVEMIN2U";
			break;

		case Intrinsic::eSubgroupInclusiveMin3U:
			result = "SUBGROUPINCLUSIVEMIN3U";
			break;

		case Intrinsic::eSubgroupInclusiveMin4U:
			result = "SUBGROUPINCLUSIVEMIN4U";
			break;

		case Intrinsic::eSubgroupInclusiveMin1D:
			result = "SUBGROUPINCLUSIVEMIN1D";
			break;

		case Intrinsic::eSubgroupInclusiveMin2D:
			result = "SUBGROUPINCLUSIVEMIN2D";
			break;

		case Intrinsic::eSubgroupInclusiveMin3D:
			result = "SUBGROUPINCLUSIVEMIN3D";
			break;

		case Intrinsic::eSubgroupInclusiveMin4D:
			result = "SUBGROUPINCLUSIVEMIN4D";
			break;

		case Intrinsic::eSubgroupInclusiveMax1F:
			result = "SUBGROUPINCLUSIVEMAX1F";
			break;

		case Intrinsic::eSubgroupInclusiveMax2F:
			result = "SUBGROUPINCLUSIVEMAX2F";
			break;

		case Intrinsic::eSubgroupInclusiveMax3F:
			result = "SUBGROUPINCLUSIVEMAX3F";
			break;

		case Intrinsic::eSubgroupInclusiveMax4F:
			result = "SUBGROUPINCLUSIVEMAX4F";
			break;

		case Intrinsic::eSubgroupInclusiveMax1I:
			result = "SUBGROUPINCLUSIVEMAX1I";
			break;

		case Intrinsic::eSubgroupInclusiveMax2I:
			result = "SUBGROUPINCLUSIVEMAX2I";
			break;

		case Intrinsic::eSubgroupInclusiveMax3I:
			result = "SUBGROUPINCLUSIVEMAX3I";
			break;

		case Intrinsic::eSubgroupInclusiveMax4I:
			result = "SUBGROUPINCLUSIVEMAX4I";
			break;

		case Intrinsic::eSubgroupInclusiveMax1U:
			result = "SUBGROUPINCLUSIVEMAX1U";
			break;

		case Intrinsic::eSubgroupInclusiveMax2U:
			result = "SUBGROUPINCLUSIVEMAX2U";
			break;

		case Intrinsic::eSubgroupInclusiveMax3U:
			result = "SUBGROUPINCLUSIVEMAX3U";
			break;

		case Intrinsic::eSubgroupInclusiveMax4U:
			result = "SUBGROUPINCLUSIVEMAX4U";
			break;

		case Intrinsic::eSubgroupInclusiveMax1D:
			result = "SUBGROUPINCLUSIVEMAX1D";
			break;

		case Intrinsic::eSubgroupInclusiveMax2D:
			result = "SUBGROUPINCLUSIVEMAX2D";
			break;

		case Intrinsic::eSubgroupInclusiveMax3D:
			result = "SUBGROUPINCLUSIVEMAX3D";
			break;

		case Intrinsic::eSubgroupInclusiveMax4D:
			result = "SUBGROUPINCLUSIVEMAX4D";
			break;

		case Intrinsic::eSubgroupInclusiveAnd1I:
			result = "SUBGROUPINCLUSIVEAND1I";
			break;

		case Intrinsic::eSubgroupInclusiveAnd2I:
			result = "SUBGROUPINCLUSIVEAND2I";
			break;

		case Intrinsic::eSubgroupInclusiveAnd3I:
			result = "SUBGROUPINCLUSIVEAND3I";
			break;

		case Intrinsic::eSubgroupInclusiveAnd4I:
			result = "SUBGROUPINCLUSIVEAND4I";
			break;

		case Intrinsic::eSubgroupInclusiveAnd1U:
			result = "SUBGROUPINCLUSIVEAND1U";
			break;

		case Intrinsic::eSubgroupInclusiveAnd2U:
			result = "SUBGROUPINCLUSIVEAND2U";
			break;

		case Intrinsic::eSubgroupInclusiveAnd3U:
			result = "SUBGROUPINCLUSIVEAND3U";
			break;

		case Intrinsic::eSubgroupInclusiveAnd4U:
			result = "SUBGROUPINCLUSIVEAND4U";
			break;

		case Intrinsic::eSubgroupInclusiveAnd1B:
			result = "SUBGROUPINCLUSIVEAND1B";
			break;

		case Intrinsic::eSubgroupInclusiveAnd2B:
			result = "SUBGROUPINCLUSIVEAND2B";
			break;

		case Intrinsic::eSubgroupInclusiveAnd3B:
			result = "SUBGROUPINCLUSIVEAND3B";
			break;

		case Intrinsic::eSubgroupInclusiveAnd4B:
			result = "SUBGROUPINCLUSIVEAND4B";
			break;

		case Intrinsic::eSubgroupInclusiveOr1I:
			result = "SUBGROUPINCLUSIVEOR1I";
			break;

		case Intrinsic::eSubgroupInclusiveOr2I:
			result = "SUBGROUPINCLUSIVEOR2I";
			break;

		case Intrinsic::eSubgroupInclusiveOr3I:
			result = "SUBGROUPINCLUSIVEOR3I";
			break;

		case Intrinsic::eSubgroupInclusiveOr4I:
			result = "SUBGROUPINCLUSIVEOR4I";
			break;

		case Intrinsic::eSubgroupInclusiveOr1U:
			result = "SUBGROUPINCLUSIVEOR1U";
			break;

		case Intrinsic::eSubgroupInclusiveOr2U:
			result = "SUBGROUPINCLUSIVEOR2U";
			break;

		case Intrinsic::eSubgroupInclusiveOr3U:
			result = "SUBGROUPINCLUSIVEOR3U";
			break;

		case Intrinsic::eSubgroupInclusiveOr4U:
			result = "SUBGROUPINCLUSIVEOR4U";
			break;

		case Intrinsic::eSubgroupInclusiveOr1B:
			result = "SUBGROUPINCLUSIVEOR1B";
			break;

		case Intrinsic::eSubgroupInclusiveOr2B:
			result = "SUBGROUPINCLUSIVEOR2B";
			break;

		case Intrinsic::eSubgroupInclusiveOr3B:
			result = "SUBGROUPINCLUSIVEOR3B";
			break;

		case Intrinsic::eSubgroupInclusiveOr4B:
			result = "SUBGROUPINCLUSIVEOR4B";
			break;

		case Intrinsic::eSubgroupInclusiveXor1I:
			result = "SUBGROUPINCLUSIVEXOR1I";
			break;

		case Intrinsic::eSubgroupInclusiveXor2I:
			result = "SUBGROUPINCLUSIVEXOR2I";
			break;

		case Intrinsic::eSubgroupInclusiveXor3I:
			result = "SUBGROUPINCLUSIVEXOR3I";
			break;

		case Intrinsic::eSubgroupInclusiveXor4I:
			result = "SUBGROUPINCLUSIVEXOR4I";
			break;

		case Intrinsic::eSubgroupInclusiveXor1U:
			result = "SUBGROUPINCLUSIVEXOR1U";
			break;

		case Intrinsic::eSubgroupInclusiveXor2U:
			result = "SUBGROUPINCLUSIVEXOR2U";
			break;

		case Intrinsic::eSubgroupInclusiveXor3U:
			result = "SUBGROUPINCLUSIVEXOR3U";
			break;

		case Intrinsic::eSubgroupInclusiveXor4U:
			result = "SUBGROUPINCLUSIVEXOR4U";
			break;

		case Intrinsic::eSubgroupInclusiveXor1B:
			result = "SUBGROUPINCLUSIVEXOR1B";
			break;

		case Intrinsic::eSubgroupInclusiveXor2B:
			result = "SUBGROUPINCLUSIVEXOR2B";
			break;

		case Intrinsic::eSubgroupInclusiveXor3B:
			result = "SUBGROUPINCLUSIVEXOR3B";
			break;

		case Intrinsic::eSubgroupInclusiveXor4B:
			result = "SUBGROUPINCLUSIVEXOR4B";
			break;

		case Intrinsic::eSubgroupExclusiveAdd1F:
			result = "SUBGROUPEXCLUSIVEADD1F";
			break;

		case Intrinsic::eSubgroupExclusiveAdd2F:
			result = "SUBGROUPEXCLUSIVEADD2F";
			break;

		case Intrinsic::eSubgroupExclusiveAdd3F:
			result = "SUBGROUPEXCLUSIVEADD3F";
			break;

		case Intrinsic::eSubgroupExclusiveAdd4F:
			result = "SUBGROUPEXCLUSIVEADD4F";
			break;

		case Intrinsic::eSubgroupExclusiveAdd1I:
			result = "SUBGROUPEXCLUSIVEADD1I";
			break;

		case Intrinsic::eSubgroupExclusiveAdd2I:
			result = "SUBGROUPEXCLUSIVEADD2I";
			break;

		case Intrinsic::eSubgroupExclusiveAdd3I:
			result = "SUBGROUPEXCLUSIVEADD3I";
			break;

		case Intrinsic::eSubgroupExclusiveAdd4I:
			result = "SUBGROUPEXCLUSIVEADD4I";
			break;

		case Intrinsic::eSubgroupExclusiveAdd1U:
			result = "SUBGROUPEXCLUSIVEADD1U";
			break;

		case Intrinsic::eSubgroupExclusiveAdd2U:
			result = "SUBGROUPEXCLUSIVEADD2U";
			break;

		case Intrinsic::eSubgroupExclusiveAdd3U:
			result = "SUBGROUPEXCLUSIVEADD3U";
			break;

		case Intrinsic::eSubgroupExclusiveAdd4U:
			result = "SUBGROUPEXCLUSIVEADD4U";
			break;

		case Intrinsic::eSubgroupExclusiveAdd1D:
			result = "SUBGROUPEXCLUSIVEADD1D";
			break;

		case Intrinsic::eSubgroupExclusiveAdd2D:
			result = "SUBGROUPEXCLUSIVEADD2D";
			break;

		case Intrinsic::eSubgroupExclusiveAdd3D:
			result = "SUBGROUPEXCLUSIVEADD3D";
			break;

		case Intrinsic::eSubgroupExclusiveAdd4D:
			result = "SUBGROUPEXCLUSIVEADD4D";
			break;

		case Intrinsic::eSubgroupExclusiveMul1F:
			result = "SUBGROUPEXCLUSIVEMUL1F";
			break;

		case Intrinsic::eSubgroupExclusiveMul2F:
			result = "SUBGROUPEXCLUSIVEMUL2F";
			break;

		case Intrinsic::eSubgroupExclusiveMul3F:
			result = "SUBGROUPEXCLUSIVEMUL3F";
			break;

		case Intrinsic::eSubgroupExclusiveMul4F:
			result = "SUBGROUPEXCLUSIVEMUL4F";
			break;

		case Intrinsic::eSubgroupExclusiveMul1I:
			result = "SUBGROUPEXCLUSIVEMUL1I";
			break;

		case Intrinsic::eSubgroupExclusiveMul2I:
			result = "SUBGROUPEXCLUSIVEMUL2I";
			break;

		case Intrinsic::eSubgroupExclusiveMul3I:
			result = "SUBGROUPEXCLUSIVEMUL3I";
			break;

		case Intrinsic::eSubgroupExclusiveMul4I:
			result = "SUBGROUPEXCLUSIVEMUL4I";
			break;

		case Intrinsic::eSubgroupExclusiveMul1U:
			result = "SUBGROUPEXCLUSIVEMUL1U";
			break;

		case Intrinsic::eSubgroupExclusiveMul2U:
			result = "SUBGROUPEXCLUSIVEMUL2U";
			break;

		case Intrinsic::eSubgroupExclusiveMul3U:
			result = "SUBGROUPEXCLUSIVEMUL3U";
			break;

		case Intrinsic::eSubgroupExclusiveMul4U:
			result = "SUBGROUPEXCLUSIVEMUL4U";
			break;

		case Intrinsic::eSubgroupExclusiveMul1D:
			result = "SUBGROUPEXCLUSIVEMUL1D";
			break;

		case Intrinsic::eSubgroupExclusiveMul2D:
			result = "SUBGROUPEXCLUSIVEMUL2D";
			break;

		case Intrinsic::eSubgroupExclusiveMul3D:
			result = "SUBGROUPEXCLUSIVEMUL3D";
			break;

		case Intrinsic::eSubgroupExclusiveMul4D:
			result = "SUBGROUPEXCLUSIVEMUL4D";
			break;

		case Intrinsic::eSubgroupExclusiveMin1F:
			result = "SUBGROUPEXCLUSIVEMIN1F";
			break;

		case Intrinsic::eSubgroupExclusiveMin2F:
			result = "SUBGROUPEXCLUSIVEMIN2F";
			break;

		case Intrinsic::eSubgroupExclusiveMin3F:
			result = "SUBGROUPEXCLUSIVEMIN3F";
			break;

		case Intrinsic::eSubgroupExclusiveMin4F:
			result = "SUBGROUPEXCLUSIVEMIN4F";
			break;

		case Intrinsic::eSubgroupExclusiveMin1I:
			result = "SUBGROUPEXCLUSIVEMIN1I";
			break;

		case Intrinsic::eSubgroupExclusiveMin2I:
			result = "SUBGROUPEXCLUSIVEMIN2I";
			break;

		case Intrinsic::eSubgroupExclusiveMin3I:
			result = "SUBGROUPEXCLUSIVEMIN3I";
			break;

		case Intrinsic::eSubgroupExclusiveMin4I:
			result = "SUBGROUPEXCLUSIVEMIN4I";
			break;

		case Intrinsic::eSubgroupExclusiveMin1U:
			result = "SUBGROUPEXCLUSIVEMIN1U";
			break;

		case Intrinsic::eSubgroupExclusiveMin2U:
			result = "SUBGROUPEXCLUSIVEMIN2U";
			break;

		case Intrinsic::eSubgroupExclusiveMin3U:
			result = "SUBGROUPEXCLUSIVEMIN3U";
			break;

		case Intrinsic::eSubgroupExclusiveMin4U:
			result = "SUBGROUPEXCLUSIVEMIN4U";
			break;

		case Intrinsic::eSubgroupExclusiveMin1D:
			result = "SUBGROUPEXCLUSIVEMIN1D";
			break;

		case Intrinsic::eSubgroupExclusiveMin2D:
			result = "SUBGROUPEXCLUSIVEMIN2D";
			break;

		case Intrinsic::eSubgroupExclusiveMin3D:
			result = "SUBGROUPEXCLUSIVEMIN3D";
			break;

		case Intrinsic::eSubgroupExclusiveMin4D:
			result = "SUBGROUPEXCLUSIVEMIN4D";
			break;

		case Intrinsic::eSubgroupExclusiveMax1F:
			result = "SUBGROUPEXCLUSIVEMAX1F";
			break;

		case Intrinsic::eSubgroupExclusiveMax2F:
			result = "SUBGROUPEXCLUSIVEMAX2F";
			break;

		case Intrinsic::eSubgroupExclusiveMax3F:
			result = "SUBGROUPEXCLUSIVEMAX3F";
			break;

		case Intrinsic::eSubgroupExclusiveMax4F:
			result = "SUBGROUPEXCLUSIVEMAX4F";
			break;

		case Intrinsic::eSubgroupExclusiveMax1I:
			result = "SUBGROUPEXCLUSIVEMAX1I";
			break;

		case Intrinsic::eSubgroupExclusiveMax2I:
			result = "SUBGROUPEXCLUSIVEMAX2I";
			break;

		case Intrinsic::eSubgroupExclusiveMax3I:
			result = "SUBGROUPEXCLUSIVEMAX3I";
			break;

		case Intrinsic::eSubgroupExclusiveMax4I:
			result = "SUBGROUPEXCLUSIVEMAX4I";
			break;

		case Intrinsic::eSubgroupExclusiveMax1U:
			result = "SUBGROUPEXCLUSIVEMAX1U";
			break;

		case Intrinsic::eSubgroupExclusiveMax2U:
			result = "SUBGROUPEXCLUSIVEMAX2U";
			break;

		case Intrinsic::eSubgroupExclusiveMax3U:
			result = "SUBGROUPEXCLUSIVEMAX3U";
			break;

		case Intrinsic::eSubgroupExclusiveMax4U:
			result = "SUBGROUPEXCLUSIVEMAX4U";
			break;

		case Intrinsic::eSubgroupExclusiveMax1D:
			result = "SUBGROUPEXCLUSIVEMAX1D";
			break;

		case Intrinsic::eSubgroupExclusiveMax2D:
			result = "SUBGROUPEXCLUSIVEMAX2D";
			break;

		case Intrinsic::eSubgroupExclusiveMax3D:
			result = "SUBGROUPEXCLUSIVEMAX3D";
			break;

		case Intrinsic::eSubgroupExclusiveMax4D:
			result = "SUBGROUPEXCLUSIVEMAX4D";
			break;

		case Intrinsic::eSubgroupExclusiveAnd1I:
			result = "SUBGROUPEXCLUSIVEAND1I";
			break;

		case Intrinsic::eSubgroupExclusiveAnd2I:
			result = "SUBGROUPEXCLUSIVEAND2I";
			break;

		case Intrinsic::eSubgroupExclusiveAnd3I:
			result = "SUBGROUPEXCLUSIVEAND3I";
			break;

		case Intrinsic::eSubgroupExclusiveAnd4I:
			result = "SUBGROUPEXCLUSIVEAND4I";
			break;

		case Intrinsic::eSubgroupExclusiveAnd1U:
			result = "SUBGROUPEXCLUSIVEAND1U";
			break;

		case Intrinsic::eSubgroupExclusiveAnd2U:
			result = "SUBGROUPEXCLUSIVEAND2U";
			break;

		case Intrinsic::eSubgroupExclusiveAnd3U:
			result = "SUBGROUPEXCLUSIVEAND3U";
			break;

		case Intrinsic::eSubgroupExclusiveAnd4U:
			result = "SUBGROUPEXCLUSIVEAND4U";
			break;

		case Intrinsic::eSubgroupExclusiveAnd1B:
			result = "SUBGROUPEXCLUSIVEAND1B";
			break;

		case Intrinsic::eSubgroupExclusiveAnd2B:
			result = "SUBGROUPEXCLUSIVEAND2B";
			break;

		case Intrinsic::eSubgroupExclusiveAnd3B:
			result = "SUBGROUPEXCLUSIVEAND3B";
			break;

		case Intrinsic::eSubgroupExclusiveAnd4B:
			result = "SUBGROUPEXCLUSIVEAND4B";
			break;

		case Intrinsic::eSubgroupExclusiveOr1I:
			result = "SUBGROUPEXCLUSIVEOR1I";
			break;

		case Intrinsic::eSubgroupExclusiveOr2I:
			result = "SUBGROUPEXCLUSIVEOR2I";
			break;

		case Intrinsic::eSubgroupExclusiveOr3I:
			result = "SUBGROUPEXCLUSIVEOR3I";
			break;

		case Intrinsic::eSubgroupExclusiveOr4I:
			result = "SUBGROUPEXCLUSIVEOR4I";
			break;

		case Intrinsic::eSubgroupExclusiveOr1U:
			result = "SUBGROUPEXCLUSIVEOR1U";
			break;

		case Intrinsic::eSubgroupExclusiveOr2U:
			result = "SUBGROUPEXCLUSIVEOR2U";
			break;

		case Intrinsic::eSubgroupExclusiveOr3U:
			result = "SUBGROUPEXCLUSIVEOR3U";
			break;

		case Intrinsic::eSubgroupExclusiveOr4U:
			result = "SUBGROUPEXCLUSIVEOR4U";
			break;

		case Intrinsic::eSubgroupExclusiveOr1B:
			result = "SUBGROUPEXCLUSIVEOR1B";
			break;

		case Intrinsic::eSubgroupExclusiveOr2B:
			result = "SUBGROUPEXCLUSIVEOR2B";
			break;

		case Intrinsic::eSubgroupExclusiveOr3B:
			result = "SUBGROUPEXCLUSIVEOR3B";
			break;

		case Intrinsic::eSubgroupExclusiveOr4B:
			result = "SUBGROUPEXCLUSIVEOR4B";
			break;

		case Intrinsic::eSubgroupExclusiveXor1I:
			result = "SUBGROUPEXCLUSIVEXOR1I";
			break;

		case Intrinsic::eSubgroupExclusiveXor2I:
			result = "SUBGROUPEXCLUSIVEXOR2I";
			break;

		case Intrinsic::eSubgroupExclusiveXor3I:
			result = "SUBGROUPEXCLUSIVEXOR3I";
			break;

		case Intrinsic::eSubgroupExclusiveXor4I:
			result = "SUBGROUPEXCLUSIVEXOR4I";
			break;

		case Intrinsic::eSubgroupExclusiveXor1U:
			result = "SUBGROUPEXCLUSIVEXOR1U";
			break;

		case Intrinsic::eSubgroupExclusiveXor2U:
			result = "SUBGROUPEXCLUSIVEXOR2U";
			break;

		case Intrinsic::eSubgroupExclusiveXor3U:
			result = "SUBGROUPEXCLUSIVEXOR3U";
			break;

		case Intrinsic::eSubgroupExclusiveXor4U:
			result = "SUBGROUPEXCLUSIVEXOR4U";
			break;

		case Intrinsic::eSubgroupExclusiveXor1B:
			result = "SUBGROUPEXCLUSIVEXOR1B";
			break;

		case Intrinsic::eSubgroupExclusiveXor2B:
			result = "SUBGROUPEXCLUSIVEXOR2B";
			break;

		case Intrinsic::eSubgroupExclusiveXor3B:
			result = "SUBGROUPEXCLUSIVEXOR3B";
			break;

		case Intrinsic::eSubgroupExclusiveXor4B:
			result = "SUBGROUPEXCLUSIVEXOR4B";
			break;

		case Intrinsic::eSubgroupClusterAdd1F:
			result = "SUBGROUPCLUSTERADD1F";
			break;

		case Intrinsic::eSubgroupClusterAdd2F:
			result = "SUBGROUPCLUSTERADD2F";
			break;

		case Intrinsic::eSubgroupClusterAdd3F:
			result = "SUBGROUPCLUSTERADD3F";
			break;

		case Intrinsic::eSubgroupClusterAdd4F:
			result = "SUBGROUPCLUSTERADD4F";
			break;

		case Intrinsic::eSubgroupClusterAdd1I:
			result = "SUBGROUPCLUSTERADD1I";
			break;

		case Intrinsic::eSubgroupClusterAdd2I:
			result = "SUBGROUPCLUSTERADD2I";
			break;

		case Intrinsic::eSubgroupClusterAdd3I:
			result = "SUBGROUPCLUSTERADD3I";
			break;

		case Intrinsic::eSubgroupClusterAdd4I:
			result = "SUBGROUPCLUSTERADD4I";
			break;

		case Intrinsic::eSubgroupClusterAdd1U:
			result = "SUBGROUPCLUSTERADD1U";
			break;

		case Intrinsic::eSubgroupClusterAdd2U:
			result = "SUBGROUPCLUSTERADD2U";
			break;

		case Intrinsic::eSubgroupClusterAdd3U:
			result = "SUBGROUPCLUSTERADD3U";
			break;

		case Intrinsic::eSubgroupClusterAdd4U:
			result = "SUBGROUPCLUSTERADD4U";
			break;

		case Intrinsic::eSubgroupClusterAdd1D:
			result = "SUBGROUPCLUSTERADD1D";
			break;

		case Intrinsic::eSubgroupClusterAdd2D:
			result = "SUBGROUPCLUSTERADD2D";
			break;

		case Intrinsic::eSubgroupClusterAdd3D:
			result = "SUBGROUPCLUSTERADD3D";
			break;

		case Intrinsic::eSubgroupClusterAdd4D:
			result = "SUBGROUPCLUSTERADD4D";
			break;

		case Intrinsic::eSubgroupClusterMul1F:
			result = "SUBGROUPCLUSTERMUL1F";
			break;

		case Intrinsic::eSubgroupClusterMul2F:
			result = "SUBGROUPCLUSTERMUL2F";
			break;

		case Intrinsic::eSubgroupClusterMul3F:
			result = "SUBGROUPCLUSTERMUL3F";
			break;

		case Intrinsic::eSubgroupClusterMul4F:
			result = "SUBGROUPCLUSTERMUL4F";
			break;

		case Intrinsic::eSubgroupClusterMul1I:
			result = "SUBGROUPCLUSTERMUL1I";
			break;

		case Intrinsic::eSubgroupClusterMul2I:
			result = "SUBGROUPCLUSTERMUL2I";
			break;

		case Intrinsic::eSubgroupClusterMul3I:
			result = "SUBGROUPCLUSTERMUL3I";
			break;

		case Intrinsic::eSubgroupClusterMul4I:
			result = "SUBGROUPCLUSTERMUL4I";
			break;

		case Intrinsic::eSubgroupClusterMul1U:
			result = "SUBGROUPCLUSTERMUL1U";
			break;

		case Intrinsic::eSubgroupClusterMul2U:
			result = "SUBGROUPCLUSTERMUL2U";
			break;

		case Intrinsic::eSubgroupClusterMul3U:
			result = "SUBGROUPCLUSTERMUL3U";
			break;

		case Intrinsic::eSubgroupClusterMul4U:
			result = "SUBGROUPCLUSTERMUL4U";
			break;

		case Intrinsic::eSubgroupClusterMul1D:
			result = "SUBGROUPCLUSTERMUL1D";
			break;

		case Intrinsic::eSubgroupClusterMul2D:
			result = "SUBGROUPCLUSTERMUL2D";
			break;

		case Intrinsic::eSubgroupClusterMul3D:
			result = "SUBGROUPCLUSTERMUL3D";
			break;

		case Intrinsic::eSubgroupClusterMul4D:
			result = "SUBGROUPCLUSTERMUL4D";
			break;

		case Intrinsic::eSubgroupClusterMin1F:
			result = "SUBGROUPCLUSTERMIN1F";
			break;

		case Intrinsic::eSubgroupClusterMin2F:
			result = "SUBGROUPCLUSTERMIN2F";
			break;

		case Intrinsic::eSubgroupClusterMin3F:
			result = "SUBGROUPCLUSTERMIN3F";
			break;

		case Intrinsic::eSubgroupClusterMin4F:
			result = "SUBGROUPCLUSTERMIN4F";
			break;

		case Intrinsic::eSubgroupClusterMin1I:
			result = "SUBGROUPCLUSTERMIN1I";
			break;

		case Intrinsic::eSubgroupClusterMin2I:
			result = "SUBGROUPCLUSTERMIN2I";
			break;

		case Intrinsic::eSubgroupClusterMin3I:
			result = "SUBGROUPCLUSTERMIN3I";
			break;

		case Intrinsic::eSubgroupClusterMin4I:
			result = "SUBGROUPCLUSTERMIN4I";
			break;

		case Intrinsic::eSubgroupClusterMin1U:
			result = "SUBGROUPCLUSTERMIN1U";
			break;

		case Intrinsic::eSubgroupClusterMin2U:
			result = "SUBGROUPCLUSTERMIN2U";
			break;

		case Intrinsic::eSubgroupClusterMin3U:
			result = "SUBGROUPCLUSTERMIN3U";
			break;

		case Intrinsic::eSubgroupClusterMin4U:
			result = "SUBGROUPCLUSTERMIN4U";
			break;

		case Intrinsic::eSubgroupClusterMin1D:
			result = "SUBGROUPCLUSTERMIN1D";
			break;

		case Intrinsic::eSubgroupClusterMin2D:
			result = "SUBGROUPCLUSTERMIN2D";
			break;

		case Intrinsic::eSubgroupClusterMin3D:
			result = "SUBGROUPCLUSTERMIN3D";
			break;

		case Intrinsic::eSubgroupClusterMin4D:
			result = "SUBGROUPCLUSTERMIN4D";
			break;

		case Intrinsic::eSubgroupClusterMax1F:
			result = "SUBGROUPCLUSTERMAX1F";
			break;

		case Intrinsic::eSubgroupClusterMax2F:
			result = "SUBGROUPCLUSTERMAX2F";
			break;

		case Intrinsic::eSubgroupClusterMax3F:
			result = "SUBGROUPCLUSTERMAX3F";
			break;

		case Intrinsic::eSubgroupClusterMax4F:
			result = "SUBGROUPCLUSTERMAX4F";
			break;

		case Intrinsic::eSubgroupClusterMax1I:
			result = "SUBGROUPCLUSTERMAX1I";
			break;

		case Intrinsic::eSubgroupClusterMax2I:
			result = "SUBGROUPCLUSTERMAX2I";
			break;

		case Intrinsic::eSubgroupClusterMax3I:
			result = "SUBGROUPCLUSTERMAX3I";
			break;

		case Intrinsic::eSubgroupClusterMax4I:
			result = "SUBGROUPCLUSTERMAX4I";
			break;

		case Intrinsic::eSubgroupClusterMax1U:
			result = "SUBGROUPCLUSTERMAX1U";
			break;

		case Intrinsic::eSubgroupClusterMax2U:
			result = "SUBGROUPCLUSTERMAX2U";
			break;

		case Intrinsic::eSubgroupClusterMax3U:
			result = "SUBGROUPCLUSTERMAX3U";
			break;

		case Intrinsic::eSubgroupClusterMax4U:
			result = "SUBGROUPCLUSTERMAX4U";
			break;

		case Intrinsic::eSubgroupClusterMax1D:
			result = "SUBGROUPCLUSTERMAX1D";
			break;

		case Intrinsic::eSubgroupClusterMax2D:
			result = "SUBGROUPCLUSTERMAX2D";
			break;

		case Intrinsic::eSubgroupClusterMax3D:
			result = "SUBGROUPCLUSTERMAX3D";
			break;

		case Intrinsic::eSubgroupClusterMax4D:
			result = "SUBGROUPCLUSTERMAX4D";
			break;

		case Intrinsic::eSubgroupClusterAnd1I:
			result = "SUBGROUPCLUSTERAND1I";
			break;

		case Intrinsic::eSubgroupClusterAnd2I:
			result = "SUBGROUPCLUSTERAND2I";
			break;

		case Intrinsic::eSubgroupClusterAnd3I:
			result = "SUBGROUPCLUSTERAND3I";
			break;

		case Intrinsic::eSubgroupClusterAnd4I:
			result = "SUBGROUPCLUSTERAND4I";
			break;

		case Intrinsic::eSubgroupClusterAnd1U:
			result = "SUBGROUPCLUSTERAND1U";
			break;

		case Intrinsic::eSubgroupClusterAnd2U:
			result = "SUBGROUPCLUSTERAND2U";
			break;

		case Intrinsic::eSubgroupClusterAnd3U:
			result = "SUBGROUPCLUSTERAND3U";
			break;

		case Intrinsic::eSubgroupClusterAnd4U:
			result = "SUBGROUPCLUSTERAND4U";
			break;

		case Intrinsic::eSubgroupClusterAnd1B:
			result = "SUBGROUPCLUSTERAND1B";
			break;

		case Intrinsic::eSubgroupClusterAnd2B:
			result = "SUBGROUPCLUSTERAND2B";
			break;

		case Intrinsic::eSubgroupClusterAnd3B:
			result = "SUBGROUPCLUSTERAND3B";
			break;

		case Intrinsic::eSubgroupClusterAnd4B:
			result = "SUBGROUPCLUSTERAND4B";
			break;

		case Intrinsic::eSubgroupClusterOr1I:
			result = "SUBGROUPCLUSTEROR1I";
			break;

		case Intrinsic::eSubgroupClusterOr2I:
			result = "SUBGROUPCLUSTEROR2I";
			break;

		case Intrinsic::eSubgroupClusterOr3I:
			result = "SUBGROUPCLUSTEROR3I";
			break;

		case Intrinsic::eSubgroupClusterOr4I:
			result = "SUBGROUPCLUSTEROR4I";
			break;

		case Intrinsic::eSubgroupClusterOr1U:
			result = "SUBGROUPCLUSTEROR1U";
			break;

		case Intrinsic::eSubgroupClusterOr2U:
			result = "SUBGROUPCLUSTEROR2U";
			break;

		case Intrinsic::eSubgroupClusterOr3U:
			result = "SUBGROUPCLUSTEROR3U";
			break;

		case Intrinsic::eSubgroupClusterOr4U:
			result = "SUBGROUPCLUSTEROR4U";
			break;

		case Intrinsic::eSubgroupClusterOr1B:
			result = "SUBGROUPCLUSTEROR1B";
			break;

		case Intrinsic::eSubgroupClusterOr2B:
			result = "SUBGROUPCLUSTEROR2B";
			break;

		case Intrinsic::eSubgroupClusterOr3B:
			result = "SUBGROUPCLUSTEROR3B";
			break;

		case Intrinsic::eSubgroupClusterOr4B:
			result = "SUBGROUPCLUSTEROR4B";
			break;

		case Intrinsic::eSubgroupClusterXor1I:
			result = "SUBGROUPCLUSTERXOR1I";
			break;

		case Intrinsic::eSubgroupClusterXor2I:
			result = "SUBGROUPCLUSTERXOR2I";
			break;

		case Intrinsic::eSubgroupClusterXor3I:
			result = "SUBGROUPCLUSTERXOR3I";
			break;

		case Intrinsic::eSubgroupClusterXor4I:
			result = "SUBGROUPCLUSTERXOR4I";
			break;

		case Intrinsic::eSubgroupClusterXor1U:
			result = "SUBGROUPCLUSTERXOR1U";
			break;

		case Intrinsic::eSubgroupClusterXor2U:
			result = "SUBGROUPCLUSTERXOR2U";
			break;

		case Intrinsic::eSubgroupClusterXor3U:
			result = "SUBGROUPCLUSTERXOR3U";
			break;

		case Intrinsic::eSubgroupClusterXor4U:
			result = "SUBGROUPCLUSTERXOR4U";
			break;

		case Intrinsic::eSubgroupClusterXor1B:
			result = "SUBGROUPCLUSTERXOR1B";
			break;

		case Intrinsic::eSubgroupClusterXor2B:
			result = "SUBGROUPCLUSTERXOR2B";
			break;

		case Intrinsic::eSubgroupClusterXor3B:
			result = "SUBGROUPCLUSTERXOR3B";
			break;

		case Intrinsic::eSubgroupClusterXor4B:
			result = "SUBGROUPCLUSTERXOR4B";
			break;

		case Intrinsic::eSubgroupQuadBroadcast1F:
			result = "SUBGROUPQUADBROADCAST1F";
			break;

		case Intrinsic::eSubgroupQuadBroadcast2F:
			result = "SUBGROUPQUADBROADCAST2F";
			break;

		case Intrinsic::eSubgroupQuadBroadcast3F:
			result = "SUBGROUPQUADBROADCAST3F";
			break;

		case Intrinsic::eSubgroupQuadBroadcast4F:
			result = "SUBGROUPQUADBROADCAST4F";
			break;

		case Intrinsic::eSubgroupQuadBroadcast1I:
			result = "SUBGROUPQUADBROADCAST1I";
			break;

		case Intrinsic::eSubgroupQuadBroadcast2I:
			result = "SUBGROUPQUADBROADCAST2I";
			break;

		case Intrinsic::eSubgroupQuadBroadcast3I:
			result = "SUBGROUPQUADBROADCAST3I";
			break;

		case Intrinsic::eSubgroupQuadBroadcast4I:
			result = "SUBGROUPQUADBROADCAST4I";
			break;

		case Intrinsic::eSubgroupQuadBroadcast1U:
			result = "SUBGROUPQUADBROADCAST1U";
			break;

		case Intrinsic::eSubgroupQuadBroadcast2U:
			result = "SUBGROUPQUADBROADCAST2U";
			break;

		case Intrinsic::eSubgroupQuadBroadcast3U:
			result = "SUBGROUPQUADBROADCAST3U";
			break;

		case Intrinsic::eSubgroupQuadBroadcast4U:
			result = "SUBGROUPQUADBROADCAST4U";
			break;

		case Intrinsic::eSubgroupQuadBroadcast1B:
			result = "SUBGROUPQUADBROADCAST1B";
			break;

		case Intrinsic::eSubgroupQuadBroadcast2B:
			result = "SUBGROUPQUADBROADCAST2B";
			break;

		case Intrinsic::eSubgroupQuadBroadcast3B:
			result = "SUBGROUPQUADBROADCAST3B";
			break;

		case Intrinsic::eSubgroupQuadBroadcast4B:
			result = "SUBGROUPQUADBROADCAST4B";
			break;

		case Intrinsic::eSubgroupQuadBroadcast1D:
			result = "SUBGROUPQUADBROADCAST1D";
			break;

		case Intrinsic::eSubgroupQuadBroadcast2D:
			result = "SUBGROUPQUADBROADCAST2D";
			break;

		case Intrinsic::eSubgroupQuadBroadcast3D:
			result = "SUBGROUPQUADBROADCAST3D";
			break;

		case Intrinsic::eSubgroupQuadBroadcast4D:
			result = "SUBGROUPQUADBROADCAST4D";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal1F:
			result = "SUBGROUPQUADSWAPHORIZONTAL1F";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal2F:
			result = "SUBGROUPQUADSWAPHORIZONTAL2F";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal3F:
			result = "SUBGROUPQUADSWAPHORIZONTAL3F";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal4F:
			result = "SUBGROUPQUADSWAPHORIZONTAL4F";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal1I:
			result = "SUBGROUPQUADSWAPHORIZONTAL1I";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal2I:
			result = "SUBGROUPQUADSWAPHORIZONTAL2I";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal3I:
			result = "SUBGROUPQUADSWAPHORIZONTAL3I";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal4I:
			result = "SUBGROUPQUADSWAPHORIZONTAL4I";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal1U:
			result = "SUBGROUPQUADSWAPHORIZONTAL1U";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal2U:
			result = "SUBGROUPQUADSWAPHORIZONTAL2U";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal3U:
			result = "SUBGROUPQUADSWAPHORIZONTAL3U";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal4U:
			result = "SUBGROUPQUADSWAPHORIZONTAL4U";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal1B:
			result = "SUBGROUPQUADSWAPHORIZONTAL1B";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal2B:
			result = "SUBGROUPQUADSWAPHORIZONTAL2B";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal3B:
			result = "SUBGROUPQUADSWAPHORIZONTAL3B";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal4B:
			result = "SUBGROUPQUADSWAPHORIZONTAL4B";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal1D:
			result = "SUBGROUPQUADSWAPHORIZONTAL1D";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal2D:
			result = "SUBGROUPQUADSWAPHORIZONTAL2D";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal3D:
			result = "SUBGROUPQUADSWAPHORIZONTAL3D";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal4D:
			result = "SUBGROUPQUADSWAPHORIZONTAL4D";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical1F:
			result = "SUBGROUPQUADSWAPVERTICAL1F";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical2F:
			result = "SUBGROUPQUADSWAPVERTICAL2F";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical3F:
			result = "SUBGROUPQUADSWAPVERTICAL3F";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical4F:
			result = "SUBGROUPQUADSWAPVERTICAL4F";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical1I:
			result = "SUBGROUPQUADSWAPVERTICAL1I";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical2I:
			result = "SUBGROUPQUADSWAPVERTICAL2I";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical3I:
			result = "SUBGROUPQUADSWAPVERTICAL3I";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical4I:
			result = "SUBGROUPQUADSWAPVERTICAL4I";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical1U:
			result = "SUBGROUPQUADSWAPVERTICAL1U";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical2U:
			result = "SUBGROUPQUADSWAPVERTICAL2U";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical3U:
			result = "SUBGROUPQUADSWAPVERTICAL3U";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical4U:
			result = "SUBGROUPQUADSWAPVERTICAL4U";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical1B:
			result = "SUBGROUPQUADSWAPVERTICAL1B";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical2B:
			result = "SUBGROUPQUADSWAPVERTICAL2B";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical3B:
			result = "SUBGROUPQUADSWAPVERTICAL3B";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical4B:
			result = "SUBGROUPQUADSWAPVERTICAL4B";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical1D:
			result = "SUBGROUPQUADSWAPVERTICAL1D";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical2D:
			result = "SUBGROUPQUADSWAPVERTICAL2D";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical3D:
			result = "SUBGROUPQUADSWAPVERTICAL3D";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical4D:
			result = "SUBGROUPQUADSWAPVERTICAL4D";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal1F:
			result = "SUBGROUPQUADSWAPDIAGONAL1F";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal2F:
			result = "SUBGROUPQUADSWAPDIAGONAL2F";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal3F:
			result = "SUBGROUPQUADSWAPDIAGONAL3F";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal4F:
			result = "SUBGROUPQUADSWAPDIAGONAL4F";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal1I:
			result = "SUBGROUPQUADSWAPDIAGONAL1I";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal2I:
			result = "SUBGROUPQUADSWAPDIAGONAL2I";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal3I:
			result = "SUBGROUPQUADSWAPDIAGONAL3I";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal4I:
			result = "SUBGROUPQUADSWAPDIAGONAL4I";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal1U:
			result = "SUBGROUPQUADSWAPDIAGONAL1U";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal2U:
			result = "SUBGROUPQUADSWAPDIAGONAL2U";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal3U:
			result = "SUBGROUPQUADSWAPDIAGONAL3U";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal4U:
			result = "SUBGROUPQUADSWAPDIAGONAL4U";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal1B:
			result = "SUBGROUPQUADSWAPDIAGONAL1B";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal2B:
			result = "SUBGROUPQUADSWAPDIAGONAL2B";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal3B:
			result = "SUBGROUPQUADSWAPDIAGONAL3B";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal4B:
			result = "SUBGROUPQUADSWAPDIAGONAL4B";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal1D:
			result = "SUBGROUPQUADSWAPDIAGONAL1D";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal2D:
			result = "SUBGROUPQUADSWAPDIAGONAL2D";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal3D:
			result = "SUBGROUPQUADSWAPDIAGONAL3D";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal4D:
			result = "SUBGROUPQUADSWAPDIAGONAL4D";
			break;

		default:
			throw std::runtime_error{ "Unsupported Intrinsic type." };
		}

		return result;
	}
}

#endif
