/*
See LICENSE file in root folder
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

		default:
			throw std::runtime_error{ "Unsupported Intrinsic type." };
		}

		return result;
	}
}

#endif
