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
#include "ShaderAST/Shader.hpp"

#include <string>

namespace ast::expr
{
	inline std::string getName( Intrinsic value )
	{
		std::string result;

		switch ( value )
		{
		case Intrinsic::eUndefined:
			result = "Undefined";
			break;

		case Intrinsic::eCount:
			result = "Count";
			break;

		case Intrinsic::eInvalid:
			result = "Invalid";
			break;

	// Angle and Trigonometry Functions
		case Intrinsic::eDegrees1:
			result = "Degrees1";
			break;

		case Intrinsic::eDegrees2:
			result = "Degrees2";
			break;

		case Intrinsic::eDegrees3:
			result = "Degrees3";
			break;

		case Intrinsic::eDegrees4:
			result = "Degrees4";
			break;

		case Intrinsic::eRadians1F:
			result = "Radians1F";
			break;

		case Intrinsic::eRadians2F:
			result = "Radians2F";
			break;

		case Intrinsic::eRadians3F:
			result = "Radians3F";
			break;

		case Intrinsic::eRadians4F:
			result = "Radians4F";
			break;

		case Intrinsic::eCos1:
			result = "Cos1";
			break;

		case Intrinsic::eCos2:
			result = "Cos2";
			break;

		case Intrinsic::eCos3:
			result = "Cos3";
			break;

		case Intrinsic::eCos4:
			result = "Cos4";
			break;

		case Intrinsic::eSin1:
			result = "Sin1";
			break;

		case Intrinsic::eSin2:
			result = "Sin2";
			break;

		case Intrinsic::eSin3:
			result = "Sin3";
			break;

		case Intrinsic::eSin4:
			result = "Sin4";
			break;

		case Intrinsic::eTan1:
			result = "Tan1";
			break;

		case Intrinsic::eTan2:
			result = "Tan2";
			break;

		case Intrinsic::eTan3:
			result = "Tan3";
			break;

		case Intrinsic::eTan4:
			result = "Tan4";
			break;

		case Intrinsic::eCosh1:
			result = "Cosh1";
			break;

		case Intrinsic::eCosh2:
			result = "Cosh2";
			break;

		case Intrinsic::eCosh3:
			result = "Cosh3";
			break;

		case Intrinsic::eCosh4:
			result = "Cosh4";
			break;

		case Intrinsic::eSinh1:
			result = "Sinh1";
			break;

		case Intrinsic::eSinh2:
			result = "Sinh2";
			break;

		case Intrinsic::eSinh3:
			result = "Sinh3";
			break;

		case Intrinsic::eSinh4:
			result = "Sinh4";
			break;

		case Intrinsic::eTanh1:
			result = "Tanh1";
			break;

		case Intrinsic::eTanh2:
			result = "Tanh2";
			break;

		case Intrinsic::eTanh3:
			result = "Tanh3";
			break;

		case Intrinsic::eTanh4:
			result = "Tanh4";
			break;

		case Intrinsic::eAcos1:
			result = "Acos1";
			break;

		case Intrinsic::eAcos2:
			result = "Acos2";
			break;

		case Intrinsic::eAcos3:
			result = "Acos3";
			break;

		case Intrinsic::eAcos4:
			result = "Acos4";
			break;

		case Intrinsic::eAsin1:
			result = "Asin1";
			break;

		case Intrinsic::eAsin2:
			result = "Asin2";
			break;

		case Intrinsic::eAsin3:
			result = "Asin3";
			break;

		case Intrinsic::eAsin4:
			result = "Asin4";
			break;

		case Intrinsic::eAtan1:
			result = "Atan1";
			break;

		case Intrinsic::eAtan2:
			result = "Atan2";
			break;

		case Intrinsic::eAtan3:
			result = "Atan3";
			break;

		case Intrinsic::eAtan4:
			result = "Atan4";
			break;

		case Intrinsic::eAtan21:
			result = "Atan21";
			break;

		case Intrinsic::eAtan22:
			result = "Atan22";
			break;

		case Intrinsic::eAtan23:
			result = "Atan23";
			break;

		case Intrinsic::eAtan24:
			result = "Atan24";
			break;

		case Intrinsic::eAcosh1:
			result = "Acosh1";
			break;

		case Intrinsic::eAcosh2:
			result = "Acosh2";
			break;

		case Intrinsic::eAcosh3:
			result = "Acosh3";
			break;

		case Intrinsic::eAcosh4:
			result = "Acosh4";
			break;

		case Intrinsic::eAsinh1:
			result = "Asinh1";
			break;

		case Intrinsic::eAsinh2:
			result = "Asinh2";
			break;

		case Intrinsic::eAsinh3:
			result = "Asinh3";
			break;

		case Intrinsic::eAsinh4:
			result = "Asinh4";
			break;

		case Intrinsic::eAtanh1:
			result = "Atanh1";
			break;

		case Intrinsic::eAtanh2:
			result = "Atanh2";
			break;

		case Intrinsic::eAtanh3:
			result = "Atanh3";
			break;

		case Intrinsic::eAtanh4:
			result = "Atanh4";
			break;


	// Exponential Functions
		case Intrinsic::ePow1:
			result = "Pow1";
			break;

		case Intrinsic::ePow2:
			result = "Pow2";
			break;

		case Intrinsic::ePow3:
			result = "Pow3";
			break;

		case Intrinsic::ePow4:
			result = "Pow4";
			break;

		case Intrinsic::eExp1:
			result = "Exp1";
			break;

		case Intrinsic::eExp2:
			result = "Exp2";
			break;

		case Intrinsic::eExp3:
			result = "Exp3";
			break;

		case Intrinsic::eExp4:
			result = "Exp4";
			break;

		case Intrinsic::eLog1:
			result = "Log1";
			break;

		case Intrinsic::eLog2:
			result = "Log2";
			break;

		case Intrinsic::eLog3:
			result = "Log3";
			break;

		case Intrinsic::eLog4:
			result = "Log4";
			break;

		case Intrinsic::eExp21:
			result = "Exp21";
			break;

		case Intrinsic::eExp22:
			result = "Exp22";
			break;

		case Intrinsic::eExp23:
			result = "Exp23";
			break;

		case Intrinsic::eExp24:
			result = "Exp24";
			break;

		case Intrinsic::eLog21:
			result = "Log21";
			break;

		case Intrinsic::eLog22:
			result = "Log22";
			break;

		case Intrinsic::eLog23:
			result = "Log23";
			break;

		case Intrinsic::eLog24:
			result = "Log24";
			break;

		case Intrinsic::eSqrt1F:
			result = "Sqrt1F";
			break;

		case Intrinsic::eSqrt2F:
			result = "Sqrt2F";
			break;

		case Intrinsic::eSqrt3F:
			result = "Sqrt3F";
			break;

		case Intrinsic::eSqrt4F:
			result = "Sqrt4F";
			break;

		case Intrinsic::eSqrt1D:
			result = "Sqrt1D";
			break;

		case Intrinsic::eSqrt2D:
			result = "Sqrt2D";
			break;

		case Intrinsic::eSqrt3D:
			result = "Sqrt3D";
			break;

		case Intrinsic::eSqrt4D:
			result = "Sqrt4D";
			break;

		case Intrinsic::eInverseSqrt1F:
			result = "InverseSqrt1F";
			break;

		case Intrinsic::eInverseSqrt2F:
			result = "InverseSqrt2F";
			break;

		case Intrinsic::eInverseSqrt3F:
			result = "InverseSqrt3F";
			break;

		case Intrinsic::eInverseSqrt4F:
			result = "InverseSqrt4F";
			break;

		case Intrinsic::eInverseSqrt1D:
			result = "InverseSqrt1D";
			break;

		case Intrinsic::eInverseSqrt2D:
			result = "InverseSqrt2D";
			break;

		case Intrinsic::eInverseSqrt3D:
			result = "InverseSqrt3D";
			break;

		case Intrinsic::eInverseSqrt4D:
			result = "InverseSqrt4D";
			break;


	// Common Functions
		case Intrinsic::eAbs1F:
			result = "Abs1F";
			break;

		case Intrinsic::eAbs2F:
			result = "Abs2F";
			break;

		case Intrinsic::eAbs3F:
			result = "Abs3F";
			break;

		case Intrinsic::eAbs4F:
			result = "Abs4F";
			break;

		case Intrinsic::eAbs1I:
			result = "Abs1I";
			break;

		case Intrinsic::eAbs2I:
			result = "Abs2I";
			break;

		case Intrinsic::eAbs3I:
			result = "Abs3I";
			break;

		case Intrinsic::eAbs4I:
			result = "Abs4I";
			break;

		case Intrinsic::eAbs1D:
			result = "Abs1D";
			break;

		case Intrinsic::eAbs2D:
			result = "Abs2D";
			break;

		case Intrinsic::eAbs3D:
			result = "Abs3D";
			break;

		case Intrinsic::eAbs4D:
			result = "Abs4D";
			break;

		case Intrinsic::eSign1F:
			result = "Sign1F";
			break;

		case Intrinsic::eSign2F:
			result = "Sign2F";
			break;

		case Intrinsic::eSign3F:
			result = "Sign3F";
			break;

		case Intrinsic::eSign4F:
			result = "Sign4F";
			break;

		case Intrinsic::eSign1I:
			result = "Sign1I";
			break;

		case Intrinsic::eSign2I:
			result = "Sign2I";
			break;

		case Intrinsic::eSign3I:
			result = "Sign3I";
			break;

		case Intrinsic::eSign4I:
			result = "Sign4I";
			break;

		case Intrinsic::eSign1D:
			result = "Sign1D";
			break;

		case Intrinsic::eSign2D:
			result = "Sign2D";
			break;

		case Intrinsic::eSign3D:
			result = "Sign3D";
			break;

		case Intrinsic::eSign4D:
			result = "Sign4D";
			break;

		case Intrinsic::eFloor1F:
			result = "Floor1F";
			break;

		case Intrinsic::eFloor2F:
			result = "Floor2F";
			break;

		case Intrinsic::eFloor3F:
			result = "Floor3F";
			break;

		case Intrinsic::eFloor4F:
			result = "Floor4F";
			break;

		case Intrinsic::eFloor1D:
			result = "Floor1D";
			break;

		case Intrinsic::eFloor2D:
			result = "Floor2D";
			break;

		case Intrinsic::eFloor3D:
			result = "Floor3D";
			break;

		case Intrinsic::eFloor4D:
			result = "Floor4D";
			break;

		case Intrinsic::eTrunc1F:
			result = "Trunc1F";
			break;

		case Intrinsic::eTrunc2F:
			result = "Trunc2F";
			break;

		case Intrinsic::eTrunc3F:
			result = "Trunc3F";
			break;

		case Intrinsic::eTrunc4F:
			result = "Trunc4F";
			break;

		case Intrinsic::eTrunc1D:
			result = "Trunc1D";
			break;

		case Intrinsic::eTrunc2D:
			result = "Trunc2D";
			break;

		case Intrinsic::eTrunc3D:
			result = "Trunc3D";
			break;

		case Intrinsic::eTrunc4D:
			result = "Trunc4D";
			break;

		case Intrinsic::eRound1F:
			result = "Round1F";
			break;

		case Intrinsic::eRound2F:
			result = "Round2F";
			break;

		case Intrinsic::eRound3F:
			result = "Round3F";
			break;

		case Intrinsic::eRound4F:
			result = "Round4F";
			break;

		case Intrinsic::eRound1D:
			result = "Round1D";
			break;

		case Intrinsic::eRound2D:
			result = "Round2D";
			break;

		case Intrinsic::eRound3D:
			result = "Round3D";
			break;

		case Intrinsic::eRound4D:
			result = "Round4D";
			break;

		case Intrinsic::eRoundEven1F:
			result = "RoundEven1F";
			break;

		case Intrinsic::eRoundEven2F:
			result = "RoundEven2F";
			break;

		case Intrinsic::eRoundEven3F:
			result = "RoundEven3F";
			break;

		case Intrinsic::eRoundEven4F:
			result = "RoundEven4F";
			break;

		case Intrinsic::eRoundEven1D:
			result = "RoundEven1D";
			break;

		case Intrinsic::eRoundEven2D:
			result = "RoundEven2D";
			break;

		case Intrinsic::eRoundEven3D:
			result = "RoundEven3D";
			break;

		case Intrinsic::eRoundEven4D:
			result = "RoundEven4D";
			break;

		case Intrinsic::eCeil1F:
			result = "Ceil1F";
			break;

		case Intrinsic::eCeil2F:
			result = "Ceil2F";
			break;

		case Intrinsic::eCeil3F:
			result = "Ceil3F";
			break;

		case Intrinsic::eCeil4F:
			result = "Ceil4F";
			break;

		case Intrinsic::eCeil1D:
			result = "Ceil1D";
			break;

		case Intrinsic::eCeil2D:
			result = "Ceil2D";
			break;

		case Intrinsic::eCeil3D:
			result = "Ceil3D";
			break;

		case Intrinsic::eCeil4D:
			result = "Ceil4D";
			break;

		case Intrinsic::eFract1F:
			result = "Fract1F";
			break;

		case Intrinsic::eFract2F:
			result = "Fract2F";
			break;

		case Intrinsic::eFract3F:
			result = "Fract3F";
			break;

		case Intrinsic::eFract4F:
			result = "Fract4F";
			break;

		case Intrinsic::eFract1D:
			result = "Fract1D";
			break;

		case Intrinsic::eFract2D:
			result = "Fract2D";
			break;

		case Intrinsic::eFract3D:
			result = "Fract3D";
			break;

		case Intrinsic::eFract4D:
			result = "Fract4D";
			break;

		case Intrinsic::eMod1F:
			result = "Mod1F";
			break;

		case Intrinsic::eMod2F:
			result = "Mod2F";
			break;

		case Intrinsic::eMod3F:
			result = "Mod3F";
			break;

		case Intrinsic::eMod4F:
			result = "Mod4F";
			break;

		case Intrinsic::eMod1D:
			result = "Mod1D";
			break;

		case Intrinsic::eMod2D:
			result = "Mod2D";
			break;

		case Intrinsic::eMod3D:
			result = "Mod3D";
			break;

		case Intrinsic::eMod4D:
			result = "Mod4D";
			break;

		case Intrinsic::eModf1F:
			result = "Modf1F";
			break;

		case Intrinsic::eModf2F:
			result = "Modf2F";
			break;

		case Intrinsic::eModf3F:
			result = "Modf3F";
			break;

		case Intrinsic::eModf4F:
			result = "Modf4F";
			break;

		case Intrinsic::eModf1D:
			result = "Modf1D";
			break;

		case Intrinsic::eModf2D:
			result = "Modf2D";
			break;

		case Intrinsic::eModf3D:
			result = "Modf3D";
			break;

		case Intrinsic::eModf4D:
			result = "Modf4D";
			break;

		case Intrinsic::eMin1F:
			result = "Min1F";
			break;

		case Intrinsic::eMin2F:
			result = "Min2F";
			break;

		case Intrinsic::eMin3F:
			result = "Min3F";
			break;

		case Intrinsic::eMin4F:
			result = "Min4F";
			break;

		case Intrinsic::eMin1D:
			result = "Min1D";
			break;

		case Intrinsic::eMin2D:
			result = "Min2D";
			break;

		case Intrinsic::eMin3D:
			result = "Min3D";
			break;

		case Intrinsic::eMin4D:
			result = "Min4D";
			break;

		case Intrinsic::eMin1I:
			result = "Min1I";
			break;

		case Intrinsic::eMin2I:
			result = "Min2I";
			break;

		case Intrinsic::eMin3I:
			result = "Min3I";
			break;

		case Intrinsic::eMin4I:
			result = "Min4I";
			break;

		case Intrinsic::eMin1U:
			result = "Min1U";
			break;

		case Intrinsic::eMin2U:
			result = "Min2U";
			break;

		case Intrinsic::eMin3U:
			result = "Min3U";
			break;

		case Intrinsic::eMin4U:
			result = "Min4U";
			break;

		case Intrinsic::eMax1F:
			result = "Max1F";
			break;

		case Intrinsic::eMax2F:
			result = "Max2F";
			break;

		case Intrinsic::eMax3F:
			result = "Max3F";
			break;

		case Intrinsic::eMax4F:
			result = "Max4F";
			break;

		case Intrinsic::eMax1D:
			result = "Max1D";
			break;

		case Intrinsic::eMax2D:
			result = "Max2D";
			break;

		case Intrinsic::eMax3D:
			result = "Max3D";
			break;

		case Intrinsic::eMax4D:
			result = "Max4D";
			break;

		case Intrinsic::eMax1I:
			result = "Max1I";
			break;

		case Intrinsic::eMax2I:
			result = "Max2I";
			break;

		case Intrinsic::eMax3I:
			result = "Max3I";
			break;

		case Intrinsic::eMax4I:
			result = "Max4I";
			break;

		case Intrinsic::eMax1U:
			result = "Max1U";
			break;

		case Intrinsic::eMax2U:
			result = "Max2U";
			break;

		case Intrinsic::eMax3U:
			result = "Max3U";
			break;

		case Intrinsic::eMax4U:
			result = "Max4U";
			break;

		case Intrinsic::eClamp1F:
			result = "Clamp1F";
			break;

		case Intrinsic::eClamp2F:
			result = "Clamp2F";
			break;

		case Intrinsic::eClamp3F:
			result = "Clamp3F";
			break;

		case Intrinsic::eClamp4F:
			result = "Clamp4F";
			break;

		case Intrinsic::eClamp1D:
			result = "Clamp1D";
			break;

		case Intrinsic::eClamp2D:
			result = "Clamp2D";
			break;

		case Intrinsic::eClamp3D:
			result = "Clamp3D";
			break;

		case Intrinsic::eClamp4D:
			result = "Clamp4D";
			break;

		case Intrinsic::eClamp1I:
			result = "Clamp1I";
			break;

		case Intrinsic::eClamp2I:
			result = "Clamp2I";
			break;

		case Intrinsic::eClamp3I:
			result = "Clamp3I";
			break;

		case Intrinsic::eClamp4I:
			result = "Clamp4I";
			break;

		case Intrinsic::eClamp1U:
			result = "Clamp1U";
			break;

		case Intrinsic::eClamp2U:
			result = "Clamp2U";
			break;

		case Intrinsic::eClamp3U:
			result = "Clamp3U";
			break;

		case Intrinsic::eClamp4U:
			result = "Clamp4U";
			break;

		case Intrinsic::eMix1F:
			result = "Mix1F";
			break;

		case Intrinsic::eMix2F:
			result = "Mix2F";
			break;

		case Intrinsic::eMix3F:
			result = "Mix3F";
			break;

		case Intrinsic::eMix4F:
			result = "Mix4F";
			break;

		case Intrinsic::eMix1D:
			result = "Mix1D";
			break;

		case Intrinsic::eMix2D:
			result = "Mix2D";
			break;

		case Intrinsic::eMix3D:
			result = "Mix3D";
			break;

		case Intrinsic::eMix4D:
			result = "Mix4D";
			break;

		case Intrinsic::eStep1F:
			result = "Step1F";
			break;

		case Intrinsic::eStep2F:
			result = "Step2F";
			break;

		case Intrinsic::eStep3F:
			result = "Step3F";
			break;

		case Intrinsic::eStep4F:
			result = "Step4F";
			break;

		case Intrinsic::eStep1D:
			result = "Step1D";
			break;

		case Intrinsic::eStep2D:
			result = "Step2D";
			break;

		case Intrinsic::eStep3D:
			result = "Step3D";
			break;

		case Intrinsic::eStep4D:
			result = "Step4D";
			break;

		case Intrinsic::eSmoothStep1F:
			result = "SmoothStep1F";
			break;

		case Intrinsic::eSmoothStep2F:
			result = "SmoothStep2F";
			break;

		case Intrinsic::eSmoothStep3F:
			result = "SmoothStep3F";
			break;

		case Intrinsic::eSmoothStep4F:
			result = "SmoothStep4F";
			break;

		case Intrinsic::eSmoothStep1D:
			result = "SmoothStep1D";
			break;

		case Intrinsic::eSmoothStep2D:
			result = "SmoothStep2D";
			break;

		case Intrinsic::eSmoothStep3D:
			result = "SmoothStep3D";
			break;

		case Intrinsic::eSmoothStep4D:
			result = "SmoothStep4D";
			break;

		case Intrinsic::eIsnan1F:
			result = "Isnan1F";
			break;

		case Intrinsic::eIsnan2F:
			result = "Isnan2F";
			break;

		case Intrinsic::eIsnan3F:
			result = "Isnan3F";
			break;

		case Intrinsic::eIsnan4F:
			result = "Isnan4F";
			break;

		case Intrinsic::eIsnan1D:
			result = "Isnan1D";
			break;

		case Intrinsic::eIsnan2D:
			result = "Isnan2D";
			break;

		case Intrinsic::eIsnan3D:
			result = "Isnan3D";
			break;

		case Intrinsic::eIsnan4D:
			result = "Isnan4D";
			break;

		case Intrinsic::eIsinf1F:
			result = "Isinf1F";
			break;

		case Intrinsic::eIsinf2F:
			result = "Isinf2F";
			break;

		case Intrinsic::eIsinf3F:
			result = "Isinf3F";
			break;

		case Intrinsic::eIsinf4F:
			result = "Isinf4F";
			break;

		case Intrinsic::eIsinf1D:
			result = "Isinf1D";
			break;

		case Intrinsic::eIsinf2D:
			result = "Isinf2D";
			break;

		case Intrinsic::eIsinf3D:
			result = "Isinf3D";
			break;

		case Intrinsic::eIsinf4D:
			result = "Isinf4D";
			break;

		case Intrinsic::eFloatBitsToInt1:
			result = "FloatBitsToInt1";
			break;

		case Intrinsic::eFloatBitsToInt2:
			result = "FloatBitsToInt2";
			break;

		case Intrinsic::eFloatBitsToInt3:
			result = "FloatBitsToInt3";
			break;

		case Intrinsic::eFloatBitsToInt4:
			result = "FloatBitsToInt4";
			break;

		case Intrinsic::eFloatBitsToUInt1:
			result = "FloatBitsToUInt1";
			break;

		case Intrinsic::eFloatBitsToUInt2:
			result = "FloatBitsToUInt2";
			break;

		case Intrinsic::eFloatBitsToUInt3:
			result = "FloatBitsToUInt3";
			break;

		case Intrinsic::eFloatBitsToUInt4:
			result = "FloatBitsToUInt4";
			break;

		case Intrinsic::eIntBitsToFloat1:
			result = "IntBitsToFloat1";
			break;

		case Intrinsic::eIntBitsToFloat2:
			result = "IntBitsToFloat2";
			break;

		case Intrinsic::eIntBitsToFloat3:
			result = "IntBitsToFloat3";
			break;

		case Intrinsic::eIntBitsToFloat4:
			result = "IntBitsToFloat4";
			break;

		case Intrinsic::eUintBitsToFloat1:
			result = "UintBitsToFloat1";
			break;

		case Intrinsic::eUintBitsToFloat2:
			result = "UintBitsToFloat2";
			break;

		case Intrinsic::eUintBitsToFloat3:
			result = "UintBitsToFloat3";
			break;

		case Intrinsic::eUintBitsToFloat4:
			result = "UintBitsToFloat4";
			break;

		case Intrinsic::eFma1F:
			result = "Fma1F";
			break;

		case Intrinsic::eFma2F:
			result = "Fma2F";
			break;

		case Intrinsic::eFma3F:
			result = "Fma3F";
			break;

		case Intrinsic::eFma4F:
			result = "Fma4F";
			break;

		case Intrinsic::eFma1D:
			result = "Fma1D";
			break;

		case Intrinsic::eFma2D:
			result = "Fma2D";
			break;

		case Intrinsic::eFma3D:
			result = "Fma3D";
			break;

		case Intrinsic::eFma4D:
			result = "Fma4D";
			break;

		case Intrinsic::eFrexp1F:
			result = "Frexp1F";
			break;

		case Intrinsic::eFrexp2F:
			result = "Frexp2F";
			break;

		case Intrinsic::eFrexp3F:
			result = "Frexp3F";
			break;

		case Intrinsic::eFrexp4F:
			result = "Frexp4F";
			break;

		case Intrinsic::eFrexp1D:
			result = "Frexp1D";
			break;

		case Intrinsic::eFrexp2D:
			result = "Frexp2D";
			break;

		case Intrinsic::eFrexp3D:
			result = "Frexp3D";
			break;

		case Intrinsic::eFrexp4D:
			result = "Frexp4D";
			break;

		case Intrinsic::eLdexp1F:
			result = "Ldexp1F";
			break;

		case Intrinsic::eLdexp2F:
			result = "Ldexp2F";
			break;

		case Intrinsic::eLdexp3F:
			result = "Ldexp3F";
			break;

		case Intrinsic::eLdexp4F:
			result = "Ldexp4F";
			break;

		case Intrinsic::eLdexp1D:
			result = "Ldexp1D";
			break;

		case Intrinsic::eLdexp2D:
			result = "Ldexp2D";
			break;

		case Intrinsic::eLdexp3D:
			result = "Ldexp3D";
			break;

		case Intrinsic::eLdexp4D:
			result = "Ldexp4D";
			break;


	// Floating-point Pack and Unpack Functions
		case Intrinsic::ePackDouble2x32:
			result = "PackDouble2x32";
			break;

		case Intrinsic::ePackHalf2x16:
			result = "PackHalf2x16";
			break;

		case Intrinsic::ePackSnorm2x16:
			result = "PackSnorm2x16";
			break;

		case Intrinsic::ePackSnorm4x8:
			result = "PackSnorm4x8";
			break;

		case Intrinsic::ePackUnorm2x16:
			result = "PackUnorm2x16";
			break;

		case Intrinsic::ePackUnorm4x8:
			result = "PackUnorm4x8";
			break;

		case Intrinsic::eUnpackDouble2x32:
			result = "UnpackDouble2x32";
			break;

		case Intrinsic::eUnpackHalf2x16:
			result = "UnpackHalf2x16";
			break;

		case Intrinsic::eUnpackSnorm2x16:
			result = "UnpackSnorm2x16";
			break;

		case Intrinsic::eUnpackSnorm4x8:
			result = "UnpackSnorm4x8";
			break;

		case Intrinsic::eUnpackUnorm2x16:
			result = "UnpackUnorm2x16";
			break;

		case Intrinsic::eUnpackUnorm4x8:
			result = "UnpackUnorm4x8";
			break;


	// Geometric Functions
		case Intrinsic::eLength1F:
			result = "Length1F";
			break;

		case Intrinsic::eLength2F:
			result = "Length2F";
			break;

		case Intrinsic::eLength3F:
			result = "Length3F";
			break;

		case Intrinsic::eLength4F:
			result = "Length4F";
			break;

		case Intrinsic::eLength1D:
			result = "Length1D";
			break;

		case Intrinsic::eLength2D:
			result = "Length2D";
			break;

		case Intrinsic::eLength3D:
			result = "Length3D";
			break;

		case Intrinsic::eLength4D:
			result = "Length4D";
			break;

		case Intrinsic::eDistance1F:
			result = "Distance1F";
			break;

		case Intrinsic::eDistance2F:
			result = "Distance2F";
			break;

		case Intrinsic::eDistance3F:
			result = "Distance3F";
			break;

		case Intrinsic::eDistance4F:
			result = "Distance4F";
			break;

		case Intrinsic::eDistance1D:
			result = "Distance1D";
			break;

		case Intrinsic::eDistance2D:
			result = "Distance2D";
			break;

		case Intrinsic::eDistance3D:
			result = "Distance3D";
			break;

		case Intrinsic::eDistance4D:
			result = "Distance4D";
			break;

		case Intrinsic::eDot1F:
			result = "Dot1F";
			break;

		case Intrinsic::eDot2F:
			result = "Dot2F";
			break;

		case Intrinsic::eDot3F:
			result = "Dot3F";
			break;

		case Intrinsic::eDot4F:
			result = "Dot4F";
			break;

		case Intrinsic::eDot1D:
			result = "Dot1D";
			break;

		case Intrinsic::eDot2D:
			result = "Dot2D";
			break;

		case Intrinsic::eDot3D:
			result = "Dot3D";
			break;

		case Intrinsic::eDot4D:
			result = "Dot4D";
			break;

		case Intrinsic::eCrossF:
			result = "CrossF";
			break;

		case Intrinsic::eCrossD:
			result = "CrossD";
			break;

		case Intrinsic::eNormalize1F:
			result = "Normalize1F";
			break;

		case Intrinsic::eNormalize2F:
			result = "Normalize2F";
			break;

		case Intrinsic::eNormalize3F:
			result = "Normalize3F";
			break;

		case Intrinsic::eNormalize4F:
			result = "Normalize4F";
			break;

		case Intrinsic::eNormalize1D:
			result = "Normalize1D";
			break;

		case Intrinsic::eNormalize2D:
			result = "Normalize2D";
			break;

		case Intrinsic::eNormalize3D:
			result = "Normalize3D";
			break;

		case Intrinsic::eNormalize4D:
			result = "Normalize4D";
			break;

		case Intrinsic::eFaceForward1F:
			result = "FaceForward1F";
			break;

		case Intrinsic::eFaceForward2F:
			result = "FaceForward2F";
			break;

		case Intrinsic::eFaceForward3F:
			result = "FaceForward3F";
			break;

		case Intrinsic::eFaceForward4F:
			result = "FaceForward4F";
			break;

		case Intrinsic::eFaceForward1D:
			result = "FaceForward1D";
			break;

		case Intrinsic::eFaceForward2D:
			result = "FaceForward2D";
			break;

		case Intrinsic::eFaceForward3D:
			result = "FaceForward3D";
			break;

		case Intrinsic::eFaceForward4D:
			result = "FaceForward4D";
			break;

		case Intrinsic::eReflect1F:
			result = "Reflect1F";
			break;

		case Intrinsic::eReflect2F:
			result = "Reflect2F";
			break;

		case Intrinsic::eReflect3F:
			result = "Reflect3F";
			break;

		case Intrinsic::eReflect4F:
			result = "Reflect4F";
			break;

		case Intrinsic::eReflect1D:
			result = "Reflect1D";
			break;

		case Intrinsic::eReflect2D:
			result = "Reflect2D";
			break;

		case Intrinsic::eReflect3D:
			result = "Reflect3D";
			break;

		case Intrinsic::eReflect4D:
			result = "Reflect4D";
			break;

		case Intrinsic::eRefract1F:
			result = "Refract1F";
			break;

		case Intrinsic::eRefract2F:
			result = "Refract2F";
			break;

		case Intrinsic::eRefract3F:
			result = "Refract3F";
			break;

		case Intrinsic::eRefract4F:
			result = "Refract4F";
			break;

		case Intrinsic::eRefract1D:
			result = "Refract1D";
			break;

		case Intrinsic::eRefract2D:
			result = "Refract2D";
			break;

		case Intrinsic::eRefract3D:
			result = "Refract3D";
			break;

		case Intrinsic::eRefract4D:
			result = "Refract4D";
			break;


	// Matrix Functions
		case Intrinsic::eMatrixCompMult2x2F:
			result = "MatrixCompMult2x2F";
			break;

		case Intrinsic::eMatrixCompMult2x3F:
			result = "MatrixCompMult2x3F";
			break;

		case Intrinsic::eMatrixCompMult2x4F:
			result = "MatrixCompMult2x4F";
			break;

		case Intrinsic::eMatrixCompMult3x2F:
			result = "MatrixCompMult3x2F";
			break;

		case Intrinsic::eMatrixCompMult3x3F:
			result = "MatrixCompMult3x3F";
			break;

		case Intrinsic::eMatrixCompMult3x4F:
			result = "MatrixCompMult3x4F";
			break;

		case Intrinsic::eMatrixCompMult4x2F:
			result = "MatrixCompMult4x2F";
			break;

		case Intrinsic::eMatrixCompMult4x3F:
			result = "MatrixCompMult4x3F";
			break;

		case Intrinsic::eMatrixCompMult4x4F:
			result = "MatrixCompMult4x4F";
			break;

		case Intrinsic::eMatrixCompMult2x2D:
			result = "MatrixCompMult2x2D";
			break;

		case Intrinsic::eMatrixCompMult2x3D:
			result = "MatrixCompMult2x3D";
			break;

		case Intrinsic::eMatrixCompMult2x4D:
			result = "MatrixCompMult2x4D";
			break;

		case Intrinsic::eMatrixCompMult3x2D:
			result = "MatrixCompMult3x2D";
			break;

		case Intrinsic::eMatrixCompMult3x3D:
			result = "MatrixCompMult3x3D";
			break;

		case Intrinsic::eMatrixCompMult3x4D:
			result = "MatrixCompMult3x4D";
			break;

		case Intrinsic::eMatrixCompMult4x2D:
			result = "MatrixCompMult4x2D";
			break;

		case Intrinsic::eMatrixCompMult4x3D:
			result = "MatrixCompMult4x3D";
			break;

		case Intrinsic::eMatrixCompMult4x4D:
			result = "MatrixCompMult4x4D";
			break;

		case Intrinsic::eOuterProduct2x2F:
			result = "OuterProduct2x2F";
			break;

		case Intrinsic::eOuterProduct3x3F:
			result = "OuterProduct3x3F";
			break;

		case Intrinsic::eOuterProduct4x4F:
			result = "OuterProduct4x4F";
			break;

		case Intrinsic::eOuterProduct3x2F:
			result = "OuterProduct3x2F";
			break;

		case Intrinsic::eOuterProduct2x3F:
			result = "OuterProduct2x3F";
			break;

		case Intrinsic::eOuterProduct4x2F:
			result = "OuterProduct4x2F";
			break;

		case Intrinsic::eOuterProduct2x4F:
			result = "OuterProduct2x4F";
			break;

		case Intrinsic::eOuterProduct4x3F:
			result = "OuterProduct4x3F";
			break;

		case Intrinsic::eOuterProduct3x4F:
			result = "OuterProduct3x4F";
			break;

		case Intrinsic::eOuterProduct2x2D:
			result = "OuterProduct2x2D";
			break;

		case Intrinsic::eOuterProduct3x3D:
			result = "OuterProduct3x3D";
			break;

		case Intrinsic::eOuterProduct4x4D:
			result = "OuterProduct4x4D";
			break;

		case Intrinsic::eOuterProduct3x2D:
			result = "OuterProduct3x2D";
			break;

		case Intrinsic::eOuterProduct2x3D:
			result = "OuterProduct2x3D";
			break;

		case Intrinsic::eOuterProduct4x2D:
			result = "OuterProduct4x2D";
			break;

		case Intrinsic::eOuterProduct2x4D:
			result = "OuterProduct2x4D";
			break;

		case Intrinsic::eOuterProduct4x3D:
			result = "OuterProduct4x3D";
			break;

		case Intrinsic::eOuterProduct3x4D:
			result = "OuterProduct3x4D";
			break;

		case Intrinsic::eTranspose2x2F:
			result = "Transpose2x2F";
			break;

		case Intrinsic::eTranspose2x3F:
			result = "Transpose2x3F";
			break;

		case Intrinsic::eTranspose2x4F:
			result = "Transpose2x4F";
			break;

		case Intrinsic::eTranspose3x2F:
			result = "Transpose3x2F";
			break;

		case Intrinsic::eTranspose3x3F:
			result = "Transpose3x3F";
			break;

		case Intrinsic::eTranspose3x4F:
			result = "Transpose3x4F";
			break;

		case Intrinsic::eTranspose4x2F:
			result = "Transpose4x2F";
			break;

		case Intrinsic::eTranspose4x3F:
			result = "Transpose4x3F";
			break;

		case Intrinsic::eTranspose4x4F:
			result = "Transpose4x4F";
			break;

		case Intrinsic::eTranspose2x2D:
			result = "Transpose2x2D";
			break;

		case Intrinsic::eTranspose2x3D:
			result = "Transpose2x3D";
			break;

		case Intrinsic::eTranspose2x4D:
			result = "Transpose2x4D";
			break;

		case Intrinsic::eTranspose3x2D:
			result = "Transpose3x2D";
			break;

		case Intrinsic::eTranspose3x3D:
			result = "Transpose3x3D";
			break;

		case Intrinsic::eTranspose3x4D:
			result = "Transpose3x4D";
			break;

		case Intrinsic::eTranspose4x2D:
			result = "Transpose4x2D";
			break;

		case Intrinsic::eTranspose4x3D:
			result = "Transpose4x3D";
			break;

		case Intrinsic::eTranspose4x4D:
			result = "Transpose4x4D";
			break;

		case Intrinsic::eDeterminant2x2F:
			result = "Determinant2x2F";
			break;

		case Intrinsic::eDeterminant3x3F:
			result = "Determinant3x3F";
			break;

		case Intrinsic::eDeterminant4x4F:
			result = "Determinant4x4F";
			break;

		case Intrinsic::eDeterminant2x2D:
			result = "Determinant2x2D";
			break;

		case Intrinsic::eDeterminant3x3D:
			result = "Determinant3x3D";
			break;

		case Intrinsic::eDeterminant4x4D:
			result = "Determinant4x4D";
			break;

		case Intrinsic::eInverse2x2F:
			result = "Inverse2x2F";
			break;

		case Intrinsic::eInverse3x3F:
			result = "Inverse3x3F";
			break;

		case Intrinsic::eInverse4x4F:
			result = "Inverse4x4F";
			break;

		case Intrinsic::eInverse2x2D:
			result = "Inverse2x2D";
			break;

		case Intrinsic::eInverse3x3D:
			result = "Inverse3x3D";
			break;

		case Intrinsic::eInverse4x4D:
			result = "Inverse4x4D";
			break;


	// Vector Relational Functions
		case Intrinsic::eLessThan2F:
			result = "LessThan2F";
			break;

		case Intrinsic::eLessThan3F:
			result = "LessThan3F";
			break;

		case Intrinsic::eLessThan4F:
			result = "LessThan4F";
			break;

		case Intrinsic::eLessThan2D:
			result = "LessThan2D";
			break;

		case Intrinsic::eLessThan3D:
			result = "LessThan3D";
			break;

		case Intrinsic::eLessThan4D:
			result = "LessThan4D";
			break;

		case Intrinsic::eLessThan2I:
			result = "LessThan2I";
			break;

		case Intrinsic::eLessThan3I:
			result = "LessThan3I";
			break;

		case Intrinsic::eLessThan4I:
			result = "LessThan4I";
			break;

		case Intrinsic::eLessThan2U:
			result = "LessThan2U";
			break;

		case Intrinsic::eLessThan3U:
			result = "LessThan3U";
			break;

		case Intrinsic::eLessThan4U:
			result = "LessThan4U";
			break;

		case Intrinsic::eLessThanEqual2F:
			result = "LessThanEqual2F";
			break;

		case Intrinsic::eLessThanEqual3F:
			result = "LessThanEqual3F";
			break;

		case Intrinsic::eLessThanEqual4F:
			result = "LessThanEqual4F";
			break;

		case Intrinsic::eLessThanEqual2D:
			result = "LessThanEqual2D";
			break;

		case Intrinsic::eLessThanEqual3D:
			result = "LessThanEqual3D";
			break;

		case Intrinsic::eLessThanEqual4D:
			result = "LessThanEqual4D";
			break;

		case Intrinsic::eLessThanEqual2I:
			result = "LessThanEqual2I";
			break;

		case Intrinsic::eLessThanEqual3I:
			result = "LessThanEqual3I";
			break;

		case Intrinsic::eLessThanEqual4I:
			result = "LessThanEqual4I";
			break;

		case Intrinsic::eLessThanEqual2U:
			result = "LessThanEqual2U";
			break;

		case Intrinsic::eLessThanEqual3U:
			result = "LessThanEqual3U";
			break;

		case Intrinsic::eLessThanEqual4U:
			result = "LessThanEqual4U";
			break;

		case Intrinsic::eGreaterThan2F:
			result = "GreaterThan2F";
			break;

		case Intrinsic::eGreaterThan3F:
			result = "GreaterThan3F";
			break;

		case Intrinsic::eGreaterThan4F:
			result = "GreaterThan4F";
			break;

		case Intrinsic::eGreaterThan2D:
			result = "GreaterThan2D";
			break;

		case Intrinsic::eGreaterThan3D:
			result = "GreaterThan3D";
			break;

		case Intrinsic::eGreaterThan4D:
			result = "GreaterThan4D";
			break;

		case Intrinsic::eGreaterThan2I:
			result = "GreaterThan2I";
			break;

		case Intrinsic::eGreaterThan3I:
			result = "GreaterThan3I";
			break;

		case Intrinsic::eGreaterThan4I:
			result = "GreaterThan4I";
			break;

		case Intrinsic::eGreaterThan2U:
			result = "GreaterThan2U";
			break;

		case Intrinsic::eGreaterThan3U:
			result = "GreaterThan3U";
			break;

		case Intrinsic::eGreaterThan4U:
			result = "GreaterThan4U";
			break;

		case Intrinsic::eGreaterThanEqual2F:
			result = "GreaterThanEqual2F";
			break;

		case Intrinsic::eGreaterThanEqual3F:
			result = "GreaterThanEqual3F";
			break;

		case Intrinsic::eGreaterThanEqual4F:
			result = "GreaterThanEqual4F";
			break;

		case Intrinsic::eGreaterThanEqual2D:
			result = "GreaterThanEqual2D";
			break;

		case Intrinsic::eGreaterThanEqual3D:
			result = "GreaterThanEqual3D";
			break;

		case Intrinsic::eGreaterThanEqual4D:
			result = "GreaterThanEqual4D";
			break;

		case Intrinsic::eGreaterThanEqual2I:
			result = "GreaterThanEqual2I";
			break;

		case Intrinsic::eGreaterThanEqual3I:
			result = "GreaterThanEqual3I";
			break;

		case Intrinsic::eGreaterThanEqual4I:
			result = "GreaterThanEqual4I";
			break;

		case Intrinsic::eGreaterThanEqual2U:
			result = "GreaterThanEqual2U";
			break;

		case Intrinsic::eGreaterThanEqual3U:
			result = "GreaterThanEqual3U";
			break;

		case Intrinsic::eGreaterThanEqual4U:
			result = "GreaterThanEqual4U";
			break;

		case Intrinsic::eEqual2F:
			result = "Equal2F";
			break;

		case Intrinsic::eEqual3F:
			result = "Equal3F";
			break;

		case Intrinsic::eEqual4F:
			result = "Equal4F";
			break;

		case Intrinsic::eEqual2D:
			result = "Equal2D";
			break;

		case Intrinsic::eEqual3D:
			result = "Equal3D";
			break;

		case Intrinsic::eEqual4D:
			result = "Equal4D";
			break;

		case Intrinsic::eEqual2I:
			result = "Equal2I";
			break;

		case Intrinsic::eEqual3I:
			result = "Equal3I";
			break;

		case Intrinsic::eEqual4I:
			result = "Equal4I";
			break;

		case Intrinsic::eEqual2U:
			result = "Equal2U";
			break;

		case Intrinsic::eEqual3U:
			result = "Equal3U";
			break;

		case Intrinsic::eEqual4U:
			result = "Equal4U";
			break;

		case Intrinsic::eNotEqual2F:
			result = "NotEqual2F";
			break;

		case Intrinsic::eNotEqual3F:
			result = "NotEqual3F";
			break;

		case Intrinsic::eNotEqual4F:
			result = "NotEqual4F";
			break;

		case Intrinsic::eNotEqual2D:
			result = "NotEqual2D";
			break;

		case Intrinsic::eNotEqual3D:
			result = "NotEqual3D";
			break;

		case Intrinsic::eNotEqual4D:
			result = "NotEqual4D";
			break;

		case Intrinsic::eNotEqual2I:
			result = "NotEqual2I";
			break;

		case Intrinsic::eNotEqual3I:
			result = "NotEqual3I";
			break;

		case Intrinsic::eNotEqual4I:
			result = "NotEqual4I";
			break;

		case Intrinsic::eNotEqual2U:
			result = "NotEqual2U";
			break;

		case Intrinsic::eNotEqual3U:
			result = "NotEqual3U";
			break;

		case Intrinsic::eNotEqual4U:
			result = "NotEqual4U";
			break;

		case Intrinsic::eAll2:
			result = "All2";
			break;

		case Intrinsic::eAll3:
			result = "All3";
			break;

		case Intrinsic::eAll4:
			result = "All4";
			break;

		case Intrinsic::eAny2:
			result = "Any2";
			break;

		case Intrinsic::eAny3:
			result = "Any3";
			break;

		case Intrinsic::eAny4:
			result = "Any4";
			break;

		case Intrinsic::eNot2:
			result = "Not2";
			break;

		case Intrinsic::eNot3:
			result = "Not3";
			break;

		case Intrinsic::eNot4:
			result = "Not4";
			break;


	// Integer Functions
		case Intrinsic::eUaddCarry1:
			result = "UaddCarry1";
			break;

		case Intrinsic::eUaddCarry2:
			result = "UaddCarry2";
			break;

		case Intrinsic::eUaddCarry3:
			result = "UaddCarry3";
			break;

		case Intrinsic::eUaddCarry4:
			result = "UaddCarry4";
			break;

		case Intrinsic::eUsubBorrow1:
			result = "UsubBorrow1";
			break;

		case Intrinsic::eUsubBorrow2:
			result = "UsubBorrow2";
			break;

		case Intrinsic::eUsubBorrow3:
			result = "UsubBorrow3";
			break;

		case Intrinsic::eUsubBorrow4:
			result = "UsubBorrow4";
			break;

		case Intrinsic::eUmulExtended1:
			result = "UmulExtended1";
			break;

		case Intrinsic::eUmulExtended2:
			result = "UmulExtended2";
			break;

		case Intrinsic::eUmulExtended3:
			result = "UmulExtended3";
			break;

		case Intrinsic::eUmulExtended4:
			result = "UmulExtended4";
			break;

		case Intrinsic::eImulExtended1:
			result = "ImulExtended1";
			break;

		case Intrinsic::eImulExtended2:
			result = "ImulExtended2";
			break;

		case Intrinsic::eImulExtended3:
			result = "ImulExtended3";
			break;

		case Intrinsic::eImulExtended4:
			result = "ImulExtended4";
			break;

		case Intrinsic::eBitfieldExtract1I:
			result = "BitfieldExtract1I";
			break;

		case Intrinsic::eBitfieldExtract2I:
			result = "BitfieldExtract2I";
			break;

		case Intrinsic::eBitfieldExtract3I:
			result = "BitfieldExtract3I";
			break;

		case Intrinsic::eBitfieldExtract4I:
			result = "BitfieldExtract4I";
			break;

		case Intrinsic::eBitfieldExtract1U:
			result = "BitfieldExtract1U";
			break;

		case Intrinsic::eBitfieldExtract2U:
			result = "BitfieldExtract2U";
			break;

		case Intrinsic::eBitfieldExtract3U:
			result = "BitfieldExtract3U";
			break;

		case Intrinsic::eBitfieldExtract4U:
			result = "BitfieldExtract4U";
			break;

		case Intrinsic::eBitfieldInsert1I:
			result = "BitfieldInsert1I";
			break;

		case Intrinsic::eBitfieldInsert2I:
			result = "BitfieldInsert2I";
			break;

		case Intrinsic::eBitfieldInsert3I:
			result = "BitfieldInsert3I";
			break;

		case Intrinsic::eBitfieldInsert4I:
			result = "BitfieldInsert4I";
			break;

		case Intrinsic::eBitfieldInsert1U:
			result = "BitfieldInsert1U";
			break;

		case Intrinsic::eBitfieldInsert2U:
			result = "BitfieldInsert2U";
			break;

		case Intrinsic::eBitfieldInsert3U:
			result = "BitfieldInsert3U";
			break;

		case Intrinsic::eBitfieldInsert4U:
			result = "BitfieldInsert4U";
			break;

		case Intrinsic::eBitfieldReverse1I:
			result = "BitfieldReverse1I";
			break;

		case Intrinsic::eBitfieldReverse2I:
			result = "BitfieldReverse2I";
			break;

		case Intrinsic::eBitfieldReverse3I:
			result = "BitfieldReverse3I";
			break;

		case Intrinsic::eBitfieldReverse4I:
			result = "BitfieldReverse4I";
			break;

		case Intrinsic::eBitfieldReverse1U:
			result = "BitfieldReverse1U";
			break;

		case Intrinsic::eBitfieldReverse2U:
			result = "BitfieldReverse2U";
			break;

		case Intrinsic::eBitfieldReverse3U:
			result = "BitfieldReverse3U";
			break;

		case Intrinsic::eBitfieldReverse4U:
			result = "BitfieldReverse4U";
			break;

		case Intrinsic::eBitCount1I:
			result = "BitCount1I";
			break;

		case Intrinsic::eBitCount2I:
			result = "BitCount2I";
			break;

		case Intrinsic::eBitCount3I:
			result = "BitCount3I";
			break;

		case Intrinsic::eBitCount4I:
			result = "BitCount4I";
			break;

		case Intrinsic::eBitCount1U:
			result = "BitCount1U";
			break;

		case Intrinsic::eBitCount2U:
			result = "BitCount2U";
			break;

		case Intrinsic::eBitCount3U:
			result = "BitCount3U";
			break;

		case Intrinsic::eBitCount4U:
			result = "BitCount4U";
			break;

		case Intrinsic::eFindLSB1I:
			result = "FindLSB1I";
			break;

		case Intrinsic::eFindLSB2I:
			result = "FindLSB2I";
			break;

		case Intrinsic::eFindLSB3I:
			result = "FindLSB3I";
			break;

		case Intrinsic::eFindLSB4I:
			result = "FindLSB4I";
			break;

		case Intrinsic::eFindLSB1U:
			result = "FindLSB1U";
			break;

		case Intrinsic::eFindLSB2U:
			result = "FindLSB2U";
			break;

		case Intrinsic::eFindLSB3U:
			result = "FindLSB3U";
			break;

		case Intrinsic::eFindLSB4U:
			result = "FindLSB4U";
			break;

		case Intrinsic::eFindMSB1I:
			result = "FindMSB1I";
			break;

		case Intrinsic::eFindMSB2I:
			result = "FindMSB2I";
			break;

		case Intrinsic::eFindMSB3I:
			result = "FindMSB3I";
			break;

		case Intrinsic::eFindMSB4I:
			result = "FindMSB4I";
			break;

		case Intrinsic::eFindMSB1U:
			result = "FindMSB1U";
			break;

		case Intrinsic::eFindMSB2U:
			result = "FindMSB2U";
			break;

		case Intrinsic::eFindMSB3U:
			result = "FindMSB3U";
			break;

		case Intrinsic::eFindMSB4U:
			result = "FindMSB4U";
			break;


	// Atomic Memory Functions
		case Intrinsic::eAtomicAddI:
			result = "AtomicAddI";
			break;

		case Intrinsic::eAtomicAddU:
			result = "AtomicAddU";
			break;

		case Intrinsic::eAtomicAddF:
			result = "AtomicAddF";
			break;

		case Intrinsic::eAtomicAdd2H:
			result = "AtomicAdd2H";
			break;

		case Intrinsic::eAtomicAdd4H:
			result = "AtomicAdd4H";
			break;

		case Intrinsic::eAtomicMinI:
			result = "AtomicMinI";
			break;

		case Intrinsic::eAtomicMinU:
			result = "AtomicMinU";
			break;

		case Intrinsic::eAtomicMaxI:
			result = "AtomicMaxI";
			break;

		case Intrinsic::eAtomicMaxU:
			result = "AtomicMaxU";
			break;

		case Intrinsic::eAtomicAndI:
			result = "AtomicAndI";
			break;

		case Intrinsic::eAtomicAndU:
			result = "AtomicAndU";
			break;

		case Intrinsic::eAtomicOrI:
			result = "AtomicOrI";
			break;

		case Intrinsic::eAtomicOrU:
			result = "AtomicOrU";
			break;

		case Intrinsic::eAtomicXorI:
			result = "AtomicXorI";
			break;

		case Intrinsic::eAtomicXorU:
			result = "AtomicXorU";
			break;

		case Intrinsic::eAtomicExchangeI:
			result = "AtomicExchangeI";
			break;

		case Intrinsic::eAtomicExchangeU:
			result = "AtomicExchangeU";
			break;

		case Intrinsic::eAtomicExchangeF:
			result = "AtomicExchangeF";
			break;

		case Intrinsic::eAtomicExchange2H:
			result = "AtomicExchange2H";
			break;

		case Intrinsic::eAtomicExchange4H:
			result = "AtomicExchange4H";
			break;

		case Intrinsic::eAtomicCompSwapI:
			result = "AtomicCompSwapI";
			break;

		case Intrinsic::eAtomicCompSwapU:
			result = "AtomicCompSwapU";
			break;


	// Derivative Functions
		case Intrinsic::eDFdx1:
			result = "DFdx1";
			break;

		case Intrinsic::eDFdx2:
			result = "DFdx2";
			break;

		case Intrinsic::eDFdx3:
			result = "DFdx3";
			break;

		case Intrinsic::eDFdx4:
			result = "DFdx4";
			break;

		case Intrinsic::eDFdxCoarse1:
			result = "DFdxCoarse1";
			break;

		case Intrinsic::eDFdxCoarse2:
			result = "DFdxCoarse2";
			break;

		case Intrinsic::eDFdxCoarse3:
			result = "DFdxCoarse3";
			break;

		case Intrinsic::eDFdxCoarse4:
			result = "DFdxCoarse4";
			break;

		case Intrinsic::eDFdxFine1:
			result = "DFdxFine1";
			break;

		case Intrinsic::eDFdxFine2:
			result = "DFdxFine2";
			break;

		case Intrinsic::eDFdxFine3:
			result = "DFdxFine3";
			break;

		case Intrinsic::eDFdxFine4:
			result = "DFdxFine4";
			break;

		case Intrinsic::eDFdy1:
			result = "DFdy1";
			break;

		case Intrinsic::eDFdy2:
			result = "DFdy2";
			break;

		case Intrinsic::eDFdy3:
			result = "DFdy3";
			break;

		case Intrinsic::eDFdy4:
			result = "DFdy4";
			break;

		case Intrinsic::eDFdyCoarse1:
			result = "DFdyCoarse1";
			break;

		case Intrinsic::eDFdyCoarse2:
			result = "DFdyCoarse2";
			break;

		case Intrinsic::eDFdyCoarse3:
			result = "DFdyCoarse3";
			break;

		case Intrinsic::eDFdyCoarse4:
			result = "DFdyCoarse4";
			break;

		case Intrinsic::eDFdyFine1:
			result = "DFdyFine1";
			break;

		case Intrinsic::eDFdyFine2:
			result = "DFdyFine2";
			break;

		case Intrinsic::eDFdyFine3:
			result = "DFdyFine3";
			break;

		case Intrinsic::eDFdyFine4:
			result = "DFdyFine4";
			break;

		case Intrinsic::eFwidth1:
			result = "Fwidth1";
			break;

		case Intrinsic::eFwidth2:
			result = "Fwidth2";
			break;

		case Intrinsic::eFwidth3:
			result = "Fwidth3";
			break;

		case Intrinsic::eFwidth4:
			result = "Fwidth4";
			break;


	// Interpolation Functions
		case Intrinsic::eInterpolateAtCentroid1:
			result = "InterpolateAtCentroid1";
			break;

		case Intrinsic::eInterpolateAtCentroid2:
			result = "InterpolateAtCentroid2";
			break;

		case Intrinsic::eInterpolateAtCentroid3:
			result = "InterpolateAtCentroid3";
			break;

		case Intrinsic::eInterpolateAtCentroid4:
			result = "InterpolateAtCentroid4";
			break;

		case Intrinsic::eInterpolateAtSample1:
			result = "InterpolateAtSample1";
			break;

		case Intrinsic::eInterpolateAtSample2:
			result = "InterpolateAtSample2";
			break;

		case Intrinsic::eInterpolateAtSample3:
			result = "InterpolateAtSample3";
			break;

		case Intrinsic::eInterpolateAtSample4:
			result = "InterpolateAtSample4";
			break;

		case Intrinsic::eInterpolateAtOffset1:
			result = "InterpolateAtOffset1";
			break;

		case Intrinsic::eInterpolateAtOffset2:
			result = "InterpolateAtOffset2";
			break;

		case Intrinsic::eInterpolateAtOffset3:
			result = "InterpolateAtOffset3";
			break;

		case Intrinsic::eInterpolateAtOffset4:
			result = "InterpolateAtOffset4";
			break;


	// Geometry Shader Functions
		case Intrinsic::eEmitStreamVertex:
			result = "EmitStreamVertex";
			break;

		case Intrinsic::eEndStreamPrimitive:
			result = "EndStreamPrimitive";
			break;

		case Intrinsic::eEmitVertex:
			result = "EmitVertex";
			break;

		case Intrinsic::eEndPrimitive:
			result = "EndPrimitive";
			break;


	// Miscellaneous Functions
		case Intrinsic::eHelperInvocation:
			result = "HelperInvocation";
			break;


	// Shader Invocation and Memory Control Functions
		case Intrinsic::eControlBarrier:
			result = "ControlBarrier";
			break;

		case Intrinsic::eMemoryBarrier:
			result = "MemoryBarrier";
			break;


	// Ray tracing Shader Functions
		case Intrinsic::eTraceRay:
			result = "TraceRay";
			break;

		case Intrinsic::eReportIntersection:
			result = "ReportIntersection";
			break;

		case Intrinsic::eExecuteCallable:
			result = "ExecuteCallable";
			break;


	//Mesh Shader NV Functions
		case Intrinsic::eSetMeshOutputCountsNV:
			result = "SetMeshOutputCountsNV";
			break;

		case Intrinsic::eDispatchMeshNV:
			result = "DispatchMeshNV";
			break;

		case Intrinsic::eWritePackedPrimitiveIndices4x8NV:
			result = "WritePackedPrimitiveIndices4x8NV";
			break;


	//Mesh Shader Functions
		case Intrinsic::eSetMeshOutputCounts:
			result = "SetMeshOutputCounts";
			break;


	//Shader Subgroup Functions
		case Intrinsic::eSubgroupElect:
			result = "SubgroupElect";
			break;

		case Intrinsic::eSubgroupAll:
			result = "SubgroupAll";
			break;

		case Intrinsic::eSubgroupAny:
			result = "SubgroupAny";
			break;

		case Intrinsic::eSubgroupAllEqual1F:
			result = "SubgroupAllEqual1F";
			break;

		case Intrinsic::eSubgroupAllEqual2F:
			result = "SubgroupAllEqual2F";
			break;

		case Intrinsic::eSubgroupAllEqual3F:
			result = "SubgroupAllEqual3F";
			break;

		case Intrinsic::eSubgroupAllEqual4F:
			result = "SubgroupAllEqual4F";
			break;

		case Intrinsic::eSubgroupAllEqual1I:
			result = "SubgroupAllEqual1I";
			break;

		case Intrinsic::eSubgroupAllEqual2I:
			result = "SubgroupAllEqual2I";
			break;

		case Intrinsic::eSubgroupAllEqual3I:
			result = "SubgroupAllEqual3I";
			break;

		case Intrinsic::eSubgroupAllEqual4I:
			result = "SubgroupAllEqual4I";
			break;

		case Intrinsic::eSubgroupAllEqual1U:
			result = "SubgroupAllEqual1U";
			break;

		case Intrinsic::eSubgroupAllEqual2U:
			result = "SubgroupAllEqual2U";
			break;

		case Intrinsic::eSubgroupAllEqual3U:
			result = "SubgroupAllEqual3U";
			break;

		case Intrinsic::eSubgroupAllEqual4U:
			result = "SubgroupAllEqual4U";
			break;

		case Intrinsic::eSubgroupAllEqual1B:
			result = "SubgroupAllEqual1B";
			break;

		case Intrinsic::eSubgroupAllEqual2B:
			result = "SubgroupAllEqual2B";
			break;

		case Intrinsic::eSubgroupAllEqual3B:
			result = "SubgroupAllEqual3B";
			break;

		case Intrinsic::eSubgroupAllEqual4B:
			result = "SubgroupAllEqual4B";
			break;

		case Intrinsic::eSubgroupAllEqual1D:
			result = "SubgroupAllEqual1D";
			break;

		case Intrinsic::eSubgroupAllEqual2D:
			result = "SubgroupAllEqual2D";
			break;

		case Intrinsic::eSubgroupAllEqual3D:
			result = "SubgroupAllEqual3D";
			break;

		case Intrinsic::eSubgroupAllEqual4D:
			result = "SubgroupAllEqual4D";
			break;

		case Intrinsic::eSubgroupBroadcast1F:
			result = "SubgroupBroadcast1F";
			break;

		case Intrinsic::eSubgroupBroadcast2F:
			result = "SubgroupBroadcast2F";
			break;

		case Intrinsic::eSubgroupBroadcast3F:
			result = "SubgroupBroadcast3F";
			break;

		case Intrinsic::eSubgroupBroadcast4F:
			result = "SubgroupBroadcast4F";
			break;

		case Intrinsic::eSubgroupBroadcast1I:
			result = "SubgroupBroadcast1I";
			break;

		case Intrinsic::eSubgroupBroadcast2I:
			result = "SubgroupBroadcast2I";
			break;

		case Intrinsic::eSubgroupBroadcast3I:
			result = "SubgroupBroadcast3I";
			break;

		case Intrinsic::eSubgroupBroadcast4I:
			result = "SubgroupBroadcast4I";
			break;

		case Intrinsic::eSubgroupBroadcast1U:
			result = "SubgroupBroadcast1U";
			break;

		case Intrinsic::eSubgroupBroadcast2U:
			result = "SubgroupBroadcast2U";
			break;

		case Intrinsic::eSubgroupBroadcast3U:
			result = "SubgroupBroadcast3U";
			break;

		case Intrinsic::eSubgroupBroadcast4U:
			result = "SubgroupBroadcast4U";
			break;

		case Intrinsic::eSubgroupBroadcast1B:
			result = "SubgroupBroadcast1B";
			break;

		case Intrinsic::eSubgroupBroadcast2B:
			result = "SubgroupBroadcast2B";
			break;

		case Intrinsic::eSubgroupBroadcast3B:
			result = "SubgroupBroadcast3B";
			break;

		case Intrinsic::eSubgroupBroadcast4B:
			result = "SubgroupBroadcast4B";
			break;

		case Intrinsic::eSubgroupBroadcast1D:
			result = "SubgroupBroadcast1D";
			break;

		case Intrinsic::eSubgroupBroadcast2D:
			result = "SubgroupBroadcast2D";
			break;

		case Intrinsic::eSubgroupBroadcast3D:
			result = "SubgroupBroadcast3D";
			break;

		case Intrinsic::eSubgroupBroadcast4D:
			result = "SubgroupBroadcast4D";
			break;

		case Intrinsic::eSubgroupBroadcastFirst1F:
			result = "SubgroupBroadcastFirst1F";
			break;

		case Intrinsic::eSubgroupBroadcastFirst2F:
			result = "SubgroupBroadcastFirst2F";
			break;

		case Intrinsic::eSubgroupBroadcastFirst3F:
			result = "SubgroupBroadcastFirst3F";
			break;

		case Intrinsic::eSubgroupBroadcastFirst4F:
			result = "SubgroupBroadcastFirst4F";
			break;

		case Intrinsic::eSubgroupBroadcastFirst1I:
			result = "SubgroupBroadcastFirst1I";
			break;

		case Intrinsic::eSubgroupBroadcastFirst2I:
			result = "SubgroupBroadcastFirst2I";
			break;

		case Intrinsic::eSubgroupBroadcastFirst3I:
			result = "SubgroupBroadcastFirst3I";
			break;

		case Intrinsic::eSubgroupBroadcastFirst4I:
			result = "SubgroupBroadcastFirst4I";
			break;

		case Intrinsic::eSubgroupBroadcastFirst1U:
			result = "SubgroupBroadcastFirst1U";
			break;

		case Intrinsic::eSubgroupBroadcastFirst2U:
			result = "SubgroupBroadcastFirst2U";
			break;

		case Intrinsic::eSubgroupBroadcastFirst3U:
			result = "SubgroupBroadcastFirst3U";
			break;

		case Intrinsic::eSubgroupBroadcastFirst4U:
			result = "SubgroupBroadcastFirst4U";
			break;

		case Intrinsic::eSubgroupBroadcastFirst1B:
			result = "SubgroupBroadcastFirst1B";
			break;

		case Intrinsic::eSubgroupBroadcastFirst2B:
			result = "SubgroupBroadcastFirst2B";
			break;

		case Intrinsic::eSubgroupBroadcastFirst3B:
			result = "SubgroupBroadcastFirst3B";
			break;

		case Intrinsic::eSubgroupBroadcastFirst4B:
			result = "SubgroupBroadcastFirst4B";
			break;

		case Intrinsic::eSubgroupBroadcastFirst1D:
			result = "SubgroupBroadcastFirst1D";
			break;

		case Intrinsic::eSubgroupBroadcastFirst2D:
			result = "SubgroupBroadcastFirst2D";
			break;

		case Intrinsic::eSubgroupBroadcastFirst3D:
			result = "SubgroupBroadcastFirst3D";
			break;

		case Intrinsic::eSubgroupBroadcastFirst4D:
			result = "SubgroupBroadcastFirst4D";
			break;

		case Intrinsic::eSubgroupBallot:
			result = "SubgroupBallot";
			break;

		case Intrinsic::eSubgroupInverseBallot:
			result = "SubgroupInverseBallot";
			break;

		case Intrinsic::eSubgroupBallotBitExtract:
			result = "SubgroupBallotBitExtract";
			break;

		case Intrinsic::eSubgroupBallotBitCount:
			result = "SubgroupBallotBitCount";
			break;

		case Intrinsic::eSubgroupBallotInclusiveBitCount:
			result = "SubgroupBallotInclusiveBitCount";
			break;

		case Intrinsic::eSubgroupBallotExclusiveBitCount:
			result = "SubgroupBallotExclusiveBitCount";
			break;

		case Intrinsic::eSubgroupBallotFindLSB:
			result = "SubgroupBallotFindLSB";
			break;

		case Intrinsic::eSubgroupBallotFindMSB:
			result = "SubgroupBallotFindMSB";
			break;

		case Intrinsic::eSubgroupShuffle1F:
			result = "SubgroupShuffle1F";
			break;

		case Intrinsic::eSubgroupShuffle2F:
			result = "SubgroupShuffle2F";
			break;

		case Intrinsic::eSubgroupShuffle3F:
			result = "SubgroupShuffle3F";
			break;

		case Intrinsic::eSubgroupShuffle4F:
			result = "SubgroupShuffle4F";
			break;

		case Intrinsic::eSubgroupShuffle1I:
			result = "SubgroupShuffle1I";
			break;

		case Intrinsic::eSubgroupShuffle2I:
			result = "SubgroupShuffle2I";
			break;

		case Intrinsic::eSubgroupShuffle3I:
			result = "SubgroupShuffle3I";
			break;

		case Intrinsic::eSubgroupShuffle4I:
			result = "SubgroupShuffle4I";
			break;

		case Intrinsic::eSubgroupShuffle1U:
			result = "SubgroupShuffle1U";
			break;

		case Intrinsic::eSubgroupShuffle2U:
			result = "SubgroupShuffle2U";
			break;

		case Intrinsic::eSubgroupShuffle3U:
			result = "SubgroupShuffle3U";
			break;

		case Intrinsic::eSubgroupShuffle4U:
			result = "SubgroupShuffle4U";
			break;

		case Intrinsic::eSubgroupShuffle1B:
			result = "SubgroupShuffle1B";
			break;

		case Intrinsic::eSubgroupShuffle2B:
			result = "SubgroupShuffle2B";
			break;

		case Intrinsic::eSubgroupShuffle3B:
			result = "SubgroupShuffle3B";
			break;

		case Intrinsic::eSubgroupShuffle4B:
			result = "SubgroupShuffle4B";
			break;

		case Intrinsic::eSubgroupShuffle1D:
			result = "SubgroupShuffle1D";
			break;

		case Intrinsic::eSubgroupShuffle2D:
			result = "SubgroupShuffle2D";
			break;

		case Intrinsic::eSubgroupShuffle3D:
			result = "SubgroupShuffle3D";
			break;

		case Intrinsic::eSubgroupShuffle4D:
			result = "SubgroupShuffle4D";
			break;

		case Intrinsic::eSubgroupShuffleXor1F:
			result = "SubgroupShuffleXor1F";
			break;

		case Intrinsic::eSubgroupShuffleXor2F:
			result = "SubgroupShuffleXor2F";
			break;

		case Intrinsic::eSubgroupShuffleXor3F:
			result = "SubgroupShuffleXor3F";
			break;

		case Intrinsic::eSubgroupShuffleXor4F:
			result = "SubgroupShuffleXor4F";
			break;

		case Intrinsic::eSubgroupShuffleXor1I:
			result = "SubgroupShuffleXor1I";
			break;

		case Intrinsic::eSubgroupShuffleXor2I:
			result = "SubgroupShuffleXor2I";
			break;

		case Intrinsic::eSubgroupShuffleXor3I:
			result = "SubgroupShuffleXor3I";
			break;

		case Intrinsic::eSubgroupShuffleXor4I:
			result = "SubgroupShuffleXor4I";
			break;

		case Intrinsic::eSubgroupShuffleXor1U:
			result = "SubgroupShuffleXor1U";
			break;

		case Intrinsic::eSubgroupShuffleXor2U:
			result = "SubgroupShuffleXor2U";
			break;

		case Intrinsic::eSubgroupShuffleXor3U:
			result = "SubgroupShuffleXor3U";
			break;

		case Intrinsic::eSubgroupShuffleXor4U:
			result = "SubgroupShuffleXor4U";
			break;

		case Intrinsic::eSubgroupShuffleXor1B:
			result = "SubgroupShuffleXor1B";
			break;

		case Intrinsic::eSubgroupShuffleXor2B:
			result = "SubgroupShuffleXor2B";
			break;

		case Intrinsic::eSubgroupShuffleXor3B:
			result = "SubgroupShuffleXor3B";
			break;

		case Intrinsic::eSubgroupShuffleXor4B:
			result = "SubgroupShuffleXor4B";
			break;

		case Intrinsic::eSubgroupShuffleXor1D:
			result = "SubgroupShuffleXor1D";
			break;

		case Intrinsic::eSubgroupShuffleXor2D:
			result = "SubgroupShuffleXor2D";
			break;

		case Intrinsic::eSubgroupShuffleXor3D:
			result = "SubgroupShuffleXor3D";
			break;

		case Intrinsic::eSubgroupShuffleXor4D:
			result = "SubgroupShuffleXor4D";
			break;

		case Intrinsic::eSubgroupShuffleUp1F:
			result = "SubgroupShuffleUp1F";
			break;

		case Intrinsic::eSubgroupShuffleUp2F:
			result = "SubgroupShuffleUp2F";
			break;

		case Intrinsic::eSubgroupShuffleUp3F:
			result = "SubgroupShuffleUp3F";
			break;

		case Intrinsic::eSubgroupShuffleUp4F:
			result = "SubgroupShuffleUp4F";
			break;

		case Intrinsic::eSubgroupShuffleUp1I:
			result = "SubgroupShuffleUp1I";
			break;

		case Intrinsic::eSubgroupShuffleUp2I:
			result = "SubgroupShuffleUp2I";
			break;

		case Intrinsic::eSubgroupShuffleUp3I:
			result = "SubgroupShuffleUp3I";
			break;

		case Intrinsic::eSubgroupShuffleUp4I:
			result = "SubgroupShuffleUp4I";
			break;

		case Intrinsic::eSubgroupShuffleUp1U:
			result = "SubgroupShuffleUp1U";
			break;

		case Intrinsic::eSubgroupShuffleUp2U:
			result = "SubgroupShuffleUp2U";
			break;

		case Intrinsic::eSubgroupShuffleUp3U:
			result = "SubgroupShuffleUp3U";
			break;

		case Intrinsic::eSubgroupShuffleUp4U:
			result = "SubgroupShuffleUp4U";
			break;

		case Intrinsic::eSubgroupShuffleUp1B:
			result = "SubgroupShuffleUp1B";
			break;

		case Intrinsic::eSubgroupShuffleUp2B:
			result = "SubgroupShuffleUp2B";
			break;

		case Intrinsic::eSubgroupShuffleUp3B:
			result = "SubgroupShuffleUp3B";
			break;

		case Intrinsic::eSubgroupShuffleUp4B:
			result = "SubgroupShuffleUp4B";
			break;

		case Intrinsic::eSubgroupShuffleUp1D:
			result = "SubgroupShuffleUp1D";
			break;

		case Intrinsic::eSubgroupShuffleUp2D:
			result = "SubgroupShuffleUp2D";
			break;

		case Intrinsic::eSubgroupShuffleUp3D:
			result = "SubgroupShuffleUp3D";
			break;

		case Intrinsic::eSubgroupShuffleUp4D:
			result = "SubgroupShuffleUp4D";
			break;

		case Intrinsic::eSubgroupShuffleDown1F:
			result = "SubgroupShuffleDown1F";
			break;

		case Intrinsic::eSubgroupShuffleDown2F:
			result = "SubgroupShuffleDown2F";
			break;

		case Intrinsic::eSubgroupShuffleDown3F:
			result = "SubgroupShuffleDown3F";
			break;

		case Intrinsic::eSubgroupShuffleDown4F:
			result = "SubgroupShuffleDown4F";
			break;

		case Intrinsic::eSubgroupShuffleDown1I:
			result = "SubgroupShuffleDown1I";
			break;

		case Intrinsic::eSubgroupShuffleDown2I:
			result = "SubgroupShuffleDown2I";
			break;

		case Intrinsic::eSubgroupShuffleDown3I:
			result = "SubgroupShuffleDown3I";
			break;

		case Intrinsic::eSubgroupShuffleDown4I:
			result = "SubgroupShuffleDown4I";
			break;

		case Intrinsic::eSubgroupShuffleDown1U:
			result = "SubgroupShuffleDown1U";
			break;

		case Intrinsic::eSubgroupShuffleDown2U:
			result = "SubgroupShuffleDown2U";
			break;

		case Intrinsic::eSubgroupShuffleDown3U:
			result = "SubgroupShuffleDown3U";
			break;

		case Intrinsic::eSubgroupShuffleDown4U:
			result = "SubgroupShuffleDown4U";
			break;

		case Intrinsic::eSubgroupShuffleDown1B:
			result = "SubgroupShuffleDown1B";
			break;

		case Intrinsic::eSubgroupShuffleDown2B:
			result = "SubgroupShuffleDown2B";
			break;

		case Intrinsic::eSubgroupShuffleDown3B:
			result = "SubgroupShuffleDown3B";
			break;

		case Intrinsic::eSubgroupShuffleDown4B:
			result = "SubgroupShuffleDown4B";
			break;

		case Intrinsic::eSubgroupShuffleDown1D:
			result = "SubgroupShuffleDown1D";
			break;

		case Intrinsic::eSubgroupShuffleDown2D:
			result = "SubgroupShuffleDown2D";
			break;

		case Intrinsic::eSubgroupShuffleDown3D:
			result = "SubgroupShuffleDown3D";
			break;

		case Intrinsic::eSubgroupShuffleDown4D:
			result = "SubgroupShuffleDown4D";
			break;

		case Intrinsic::eSubgroupAdd1F:
			result = "SubgroupAdd1F";
			break;

		case Intrinsic::eSubgroupAdd2F:
			result = "SubgroupAdd2F";
			break;

		case Intrinsic::eSubgroupAdd3F:
			result = "SubgroupAdd3F";
			break;

		case Intrinsic::eSubgroupAdd4F:
			result = "SubgroupAdd4F";
			break;

		case Intrinsic::eSubgroupAdd1I:
			result = "SubgroupAdd1I";
			break;

		case Intrinsic::eSubgroupAdd2I:
			result = "SubgroupAdd2I";
			break;

		case Intrinsic::eSubgroupAdd3I:
			result = "SubgroupAdd3I";
			break;

		case Intrinsic::eSubgroupAdd4I:
			result = "SubgroupAdd4I";
			break;

		case Intrinsic::eSubgroupAdd1U:
			result = "SubgroupAdd1U";
			break;

		case Intrinsic::eSubgroupAdd2U:
			result = "SubgroupAdd2U";
			break;

		case Intrinsic::eSubgroupAdd3U:
			result = "SubgroupAdd3U";
			break;

		case Intrinsic::eSubgroupAdd4U:
			result = "SubgroupAdd4U";
			break;

		case Intrinsic::eSubgroupAdd1D:
			result = "SubgroupAdd1D";
			break;

		case Intrinsic::eSubgroupAdd2D:
			result = "SubgroupAdd2D";
			break;

		case Intrinsic::eSubgroupAdd3D:
			result = "SubgroupAdd3D";
			break;

		case Intrinsic::eSubgroupAdd4D:
			result = "SubgroupAdd4D";
			break;

		case Intrinsic::eSubgroupMul1F:
			result = "SubgroupMul1F";
			break;

		case Intrinsic::eSubgroupMul2F:
			result = "SubgroupMul2F";
			break;

		case Intrinsic::eSubgroupMul3F:
			result = "SubgroupMul3F";
			break;

		case Intrinsic::eSubgroupMul4F:
			result = "SubgroupMul4F";
			break;

		case Intrinsic::eSubgroupMul1I:
			result = "SubgroupMul1I";
			break;

		case Intrinsic::eSubgroupMul2I:
			result = "SubgroupMul2I";
			break;

		case Intrinsic::eSubgroupMul3I:
			result = "SubgroupMul3I";
			break;

		case Intrinsic::eSubgroupMul4I:
			result = "SubgroupMul4I";
			break;

		case Intrinsic::eSubgroupMul1U:
			result = "SubgroupMul1U";
			break;

		case Intrinsic::eSubgroupMul2U:
			result = "SubgroupMul2U";
			break;

		case Intrinsic::eSubgroupMul3U:
			result = "SubgroupMul3U";
			break;

		case Intrinsic::eSubgroupMul4U:
			result = "SubgroupMul4U";
			break;

		case Intrinsic::eSubgroupMul1D:
			result = "SubgroupMul1D";
			break;

		case Intrinsic::eSubgroupMul2D:
			result = "SubgroupMul2D";
			break;

		case Intrinsic::eSubgroupMul3D:
			result = "SubgroupMul3D";
			break;

		case Intrinsic::eSubgroupMul4D:
			result = "SubgroupMul4D";
			break;

		case Intrinsic::eSubgroupMin1F:
			result = "SubgroupMin1F";
			break;

		case Intrinsic::eSubgroupMin2F:
			result = "SubgroupMin2F";
			break;

		case Intrinsic::eSubgroupMin3F:
			result = "SubgroupMin3F";
			break;

		case Intrinsic::eSubgroupMin4F:
			result = "SubgroupMin4F";
			break;

		case Intrinsic::eSubgroupMin1I:
			result = "SubgroupMin1I";
			break;

		case Intrinsic::eSubgroupMin2I:
			result = "SubgroupMin2I";
			break;

		case Intrinsic::eSubgroupMin3I:
			result = "SubgroupMin3I";
			break;

		case Intrinsic::eSubgroupMin4I:
			result = "SubgroupMin4I";
			break;

		case Intrinsic::eSubgroupMin1U:
			result = "SubgroupMin1U";
			break;

		case Intrinsic::eSubgroupMin2U:
			result = "SubgroupMin2U";
			break;

		case Intrinsic::eSubgroupMin3U:
			result = "SubgroupMin3U";
			break;

		case Intrinsic::eSubgroupMin4U:
			result = "SubgroupMin4U";
			break;

		case Intrinsic::eSubgroupMin1D:
			result = "SubgroupMin1D";
			break;

		case Intrinsic::eSubgroupMin2D:
			result = "SubgroupMin2D";
			break;

		case Intrinsic::eSubgroupMin3D:
			result = "SubgroupMin3D";
			break;

		case Intrinsic::eSubgroupMin4D:
			result = "SubgroupMin4D";
			break;

		case Intrinsic::eSubgroupMax1F:
			result = "SubgroupMax1F";
			break;

		case Intrinsic::eSubgroupMax2F:
			result = "SubgroupMax2F";
			break;

		case Intrinsic::eSubgroupMax3F:
			result = "SubgroupMax3F";
			break;

		case Intrinsic::eSubgroupMax4F:
			result = "SubgroupMax4F";
			break;

		case Intrinsic::eSubgroupMax1I:
			result = "SubgroupMax1I";
			break;

		case Intrinsic::eSubgroupMax2I:
			result = "SubgroupMax2I";
			break;

		case Intrinsic::eSubgroupMax3I:
			result = "SubgroupMax3I";
			break;

		case Intrinsic::eSubgroupMax4I:
			result = "SubgroupMax4I";
			break;

		case Intrinsic::eSubgroupMax1U:
			result = "SubgroupMax1U";
			break;

		case Intrinsic::eSubgroupMax2U:
			result = "SubgroupMax2U";
			break;

		case Intrinsic::eSubgroupMax3U:
			result = "SubgroupMax3U";
			break;

		case Intrinsic::eSubgroupMax4U:
			result = "SubgroupMax4U";
			break;

		case Intrinsic::eSubgroupMax1D:
			result = "SubgroupMax1D";
			break;

		case Intrinsic::eSubgroupMax2D:
			result = "SubgroupMax2D";
			break;

		case Intrinsic::eSubgroupMax3D:
			result = "SubgroupMax3D";
			break;

		case Intrinsic::eSubgroupMax4D:
			result = "SubgroupMax4D";
			break;

		case Intrinsic::eSubgroupAnd1I:
			result = "SubgroupAnd1I";
			break;

		case Intrinsic::eSubgroupAnd2I:
			result = "SubgroupAnd2I";
			break;

		case Intrinsic::eSubgroupAnd3I:
			result = "SubgroupAnd3I";
			break;

		case Intrinsic::eSubgroupAnd4I:
			result = "SubgroupAnd4I";
			break;

		case Intrinsic::eSubgroupAnd1U:
			result = "SubgroupAnd1U";
			break;

		case Intrinsic::eSubgroupAnd2U:
			result = "SubgroupAnd2U";
			break;

		case Intrinsic::eSubgroupAnd3U:
			result = "SubgroupAnd3U";
			break;

		case Intrinsic::eSubgroupAnd4U:
			result = "SubgroupAnd4U";
			break;

		case Intrinsic::eSubgroupAnd1B:
			result = "SubgroupAnd1B";
			break;

		case Intrinsic::eSubgroupAnd2B:
			result = "SubgroupAnd2B";
			break;

		case Intrinsic::eSubgroupAnd3B:
			result = "SubgroupAnd3B";
			break;

		case Intrinsic::eSubgroupAnd4B:
			result = "SubgroupAnd4B";
			break;

		case Intrinsic::eSubgroupOr1I:
			result = "SubgroupOr1I";
			break;

		case Intrinsic::eSubgroupOr2I:
			result = "SubgroupOr2I";
			break;

		case Intrinsic::eSubgroupOr3I:
			result = "SubgroupOr3I";
			break;

		case Intrinsic::eSubgroupOr4I:
			result = "SubgroupOr4I";
			break;

		case Intrinsic::eSubgroupOr1U:
			result = "SubgroupOr1U";
			break;

		case Intrinsic::eSubgroupOr2U:
			result = "SubgroupOr2U";
			break;

		case Intrinsic::eSubgroupOr3U:
			result = "SubgroupOr3U";
			break;

		case Intrinsic::eSubgroupOr4U:
			result = "SubgroupOr4U";
			break;

		case Intrinsic::eSubgroupOr1B:
			result = "SubgroupOr1B";
			break;

		case Intrinsic::eSubgroupOr2B:
			result = "SubgroupOr2B";
			break;

		case Intrinsic::eSubgroupOr3B:
			result = "SubgroupOr3B";
			break;

		case Intrinsic::eSubgroupOr4B:
			result = "SubgroupOr4B";
			break;

		case Intrinsic::eSubgroupXor1I:
			result = "SubgroupXor1I";
			break;

		case Intrinsic::eSubgroupXor2I:
			result = "SubgroupXor2I";
			break;

		case Intrinsic::eSubgroupXor3I:
			result = "SubgroupXor3I";
			break;

		case Intrinsic::eSubgroupXor4I:
			result = "SubgroupXor4I";
			break;

		case Intrinsic::eSubgroupXor1U:
			result = "SubgroupXor1U";
			break;

		case Intrinsic::eSubgroupXor2U:
			result = "SubgroupXor2U";
			break;

		case Intrinsic::eSubgroupXor3U:
			result = "SubgroupXor3U";
			break;

		case Intrinsic::eSubgroupXor4U:
			result = "SubgroupXor4U";
			break;

		case Intrinsic::eSubgroupXor1B:
			result = "SubgroupXor1B";
			break;

		case Intrinsic::eSubgroupXor2B:
			result = "SubgroupXor2B";
			break;

		case Intrinsic::eSubgroupXor3B:
			result = "SubgroupXor3B";
			break;

		case Intrinsic::eSubgroupXor4B:
			result = "SubgroupXor4B";
			break;

		case Intrinsic::eSubgroupInclusiveAdd1F:
			result = "SubgroupInclusiveAdd1F";
			break;

		case Intrinsic::eSubgroupInclusiveAdd2F:
			result = "SubgroupInclusiveAdd2F";
			break;

		case Intrinsic::eSubgroupInclusiveAdd3F:
			result = "SubgroupInclusiveAdd3F";
			break;

		case Intrinsic::eSubgroupInclusiveAdd4F:
			result = "SubgroupInclusiveAdd4F";
			break;

		case Intrinsic::eSubgroupInclusiveAdd1I:
			result = "SubgroupInclusiveAdd1I";
			break;

		case Intrinsic::eSubgroupInclusiveAdd2I:
			result = "SubgroupInclusiveAdd2I";
			break;

		case Intrinsic::eSubgroupInclusiveAdd3I:
			result = "SubgroupInclusiveAdd3I";
			break;

		case Intrinsic::eSubgroupInclusiveAdd4I:
			result = "SubgroupInclusiveAdd4I";
			break;

		case Intrinsic::eSubgroupInclusiveAdd1U:
			result = "SubgroupInclusiveAdd1U";
			break;

		case Intrinsic::eSubgroupInclusiveAdd2U:
			result = "SubgroupInclusiveAdd2U";
			break;

		case Intrinsic::eSubgroupInclusiveAdd3U:
			result = "SubgroupInclusiveAdd3U";
			break;

		case Intrinsic::eSubgroupInclusiveAdd4U:
			result = "SubgroupInclusiveAdd4U";
			break;

		case Intrinsic::eSubgroupInclusiveAdd1D:
			result = "SubgroupInclusiveAdd1D";
			break;

		case Intrinsic::eSubgroupInclusiveAdd2D:
			result = "SubgroupInclusiveAdd2D";
			break;

		case Intrinsic::eSubgroupInclusiveAdd3D:
			result = "SubgroupInclusiveAdd3D";
			break;

		case Intrinsic::eSubgroupInclusiveAdd4D:
			result = "SubgroupInclusiveAdd4D";
			break;

		case Intrinsic::eSubgroupInclusiveMul1F:
			result = "SubgroupInclusiveMul1F";
			break;

		case Intrinsic::eSubgroupInclusiveMul2F:
			result = "SubgroupInclusiveMul2F";
			break;

		case Intrinsic::eSubgroupInclusiveMul3F:
			result = "SubgroupInclusiveMul3F";
			break;

		case Intrinsic::eSubgroupInclusiveMul4F:
			result = "SubgroupInclusiveMul4F";
			break;

		case Intrinsic::eSubgroupInclusiveMul1I:
			result = "SubgroupInclusiveMul1I";
			break;

		case Intrinsic::eSubgroupInclusiveMul2I:
			result = "SubgroupInclusiveMul2I";
			break;

		case Intrinsic::eSubgroupInclusiveMul3I:
			result = "SubgroupInclusiveMul3I";
			break;

		case Intrinsic::eSubgroupInclusiveMul4I:
			result = "SubgroupInclusiveMul4I";
			break;

		case Intrinsic::eSubgroupInclusiveMul1U:
			result = "SubgroupInclusiveMul1U";
			break;

		case Intrinsic::eSubgroupInclusiveMul2U:
			result = "SubgroupInclusiveMul2U";
			break;

		case Intrinsic::eSubgroupInclusiveMul3U:
			result = "SubgroupInclusiveMul3U";
			break;

		case Intrinsic::eSubgroupInclusiveMul4U:
			result = "SubgroupInclusiveMul4U";
			break;

		case Intrinsic::eSubgroupInclusiveMul1D:
			result = "SubgroupInclusiveMul1D";
			break;

		case Intrinsic::eSubgroupInclusiveMul2D:
			result = "SubgroupInclusiveMul2D";
			break;

		case Intrinsic::eSubgroupInclusiveMul3D:
			result = "SubgroupInclusiveMul3D";
			break;

		case Intrinsic::eSubgroupInclusiveMul4D:
			result = "SubgroupInclusiveMul4D";
			break;

		case Intrinsic::eSubgroupInclusiveMin1F:
			result = "SubgroupInclusiveMin1F";
			break;

		case Intrinsic::eSubgroupInclusiveMin2F:
			result = "SubgroupInclusiveMin2F";
			break;

		case Intrinsic::eSubgroupInclusiveMin3F:
			result = "SubgroupInclusiveMin3F";
			break;

		case Intrinsic::eSubgroupInclusiveMin4F:
			result = "SubgroupInclusiveMin4F";
			break;

		case Intrinsic::eSubgroupInclusiveMin1I:
			result = "SubgroupInclusiveMin1I";
			break;

		case Intrinsic::eSubgroupInclusiveMin2I:
			result = "SubgroupInclusiveMin2I";
			break;

		case Intrinsic::eSubgroupInclusiveMin3I:
			result = "SubgroupInclusiveMin3I";
			break;

		case Intrinsic::eSubgroupInclusiveMin4I:
			result = "SubgroupInclusiveMin4I";
			break;

		case Intrinsic::eSubgroupInclusiveMin1U:
			result = "SubgroupInclusiveMin1U";
			break;

		case Intrinsic::eSubgroupInclusiveMin2U:
			result = "SubgroupInclusiveMin2U";
			break;

		case Intrinsic::eSubgroupInclusiveMin3U:
			result = "SubgroupInclusiveMin3U";
			break;

		case Intrinsic::eSubgroupInclusiveMin4U:
			result = "SubgroupInclusiveMin4U";
			break;

		case Intrinsic::eSubgroupInclusiveMin1D:
			result = "SubgroupInclusiveMin1D";
			break;

		case Intrinsic::eSubgroupInclusiveMin2D:
			result = "SubgroupInclusiveMin2D";
			break;

		case Intrinsic::eSubgroupInclusiveMin3D:
			result = "SubgroupInclusiveMin3D";
			break;

		case Intrinsic::eSubgroupInclusiveMin4D:
			result = "SubgroupInclusiveMin4D";
			break;

		case Intrinsic::eSubgroupInclusiveMax1F:
			result = "SubgroupInclusiveMax1F";
			break;

		case Intrinsic::eSubgroupInclusiveMax2F:
			result = "SubgroupInclusiveMax2F";
			break;

		case Intrinsic::eSubgroupInclusiveMax3F:
			result = "SubgroupInclusiveMax3F";
			break;

		case Intrinsic::eSubgroupInclusiveMax4F:
			result = "SubgroupInclusiveMax4F";
			break;

		case Intrinsic::eSubgroupInclusiveMax1I:
			result = "SubgroupInclusiveMax1I";
			break;

		case Intrinsic::eSubgroupInclusiveMax2I:
			result = "SubgroupInclusiveMax2I";
			break;

		case Intrinsic::eSubgroupInclusiveMax3I:
			result = "SubgroupInclusiveMax3I";
			break;

		case Intrinsic::eSubgroupInclusiveMax4I:
			result = "SubgroupInclusiveMax4I";
			break;

		case Intrinsic::eSubgroupInclusiveMax1U:
			result = "SubgroupInclusiveMax1U";
			break;

		case Intrinsic::eSubgroupInclusiveMax2U:
			result = "SubgroupInclusiveMax2U";
			break;

		case Intrinsic::eSubgroupInclusiveMax3U:
			result = "SubgroupInclusiveMax3U";
			break;

		case Intrinsic::eSubgroupInclusiveMax4U:
			result = "SubgroupInclusiveMax4U";
			break;

		case Intrinsic::eSubgroupInclusiveMax1D:
			result = "SubgroupInclusiveMax1D";
			break;

		case Intrinsic::eSubgroupInclusiveMax2D:
			result = "SubgroupInclusiveMax2D";
			break;

		case Intrinsic::eSubgroupInclusiveMax3D:
			result = "SubgroupInclusiveMax3D";
			break;

		case Intrinsic::eSubgroupInclusiveMax4D:
			result = "SubgroupInclusiveMax4D";
			break;

		case Intrinsic::eSubgroupInclusiveAnd1I:
			result = "SubgroupInclusiveAnd1I";
			break;

		case Intrinsic::eSubgroupInclusiveAnd2I:
			result = "SubgroupInclusiveAnd2I";
			break;

		case Intrinsic::eSubgroupInclusiveAnd3I:
			result = "SubgroupInclusiveAnd3I";
			break;

		case Intrinsic::eSubgroupInclusiveAnd4I:
			result = "SubgroupInclusiveAnd4I";
			break;

		case Intrinsic::eSubgroupInclusiveAnd1U:
			result = "SubgroupInclusiveAnd1U";
			break;

		case Intrinsic::eSubgroupInclusiveAnd2U:
			result = "SubgroupInclusiveAnd2U";
			break;

		case Intrinsic::eSubgroupInclusiveAnd3U:
			result = "SubgroupInclusiveAnd3U";
			break;

		case Intrinsic::eSubgroupInclusiveAnd4U:
			result = "SubgroupInclusiveAnd4U";
			break;

		case Intrinsic::eSubgroupInclusiveAnd1B:
			result = "SubgroupInclusiveAnd1B";
			break;

		case Intrinsic::eSubgroupInclusiveAnd2B:
			result = "SubgroupInclusiveAnd2B";
			break;

		case Intrinsic::eSubgroupInclusiveAnd3B:
			result = "SubgroupInclusiveAnd3B";
			break;

		case Intrinsic::eSubgroupInclusiveAnd4B:
			result = "SubgroupInclusiveAnd4B";
			break;

		case Intrinsic::eSubgroupInclusiveOr1I:
			result = "SubgroupInclusiveOr1I";
			break;

		case Intrinsic::eSubgroupInclusiveOr2I:
			result = "SubgroupInclusiveOr2I";
			break;

		case Intrinsic::eSubgroupInclusiveOr3I:
			result = "SubgroupInclusiveOr3I";
			break;

		case Intrinsic::eSubgroupInclusiveOr4I:
			result = "SubgroupInclusiveOr4I";
			break;

		case Intrinsic::eSubgroupInclusiveOr1U:
			result = "SubgroupInclusiveOr1U";
			break;

		case Intrinsic::eSubgroupInclusiveOr2U:
			result = "SubgroupInclusiveOr2U";
			break;

		case Intrinsic::eSubgroupInclusiveOr3U:
			result = "SubgroupInclusiveOr3U";
			break;

		case Intrinsic::eSubgroupInclusiveOr4U:
			result = "SubgroupInclusiveOr4U";
			break;

		case Intrinsic::eSubgroupInclusiveOr1B:
			result = "SubgroupInclusiveOr1B";
			break;

		case Intrinsic::eSubgroupInclusiveOr2B:
			result = "SubgroupInclusiveOr2B";
			break;

		case Intrinsic::eSubgroupInclusiveOr3B:
			result = "SubgroupInclusiveOr3B";
			break;

		case Intrinsic::eSubgroupInclusiveOr4B:
			result = "SubgroupInclusiveOr4B";
			break;

		case Intrinsic::eSubgroupInclusiveXor1I:
			result = "SubgroupInclusiveXor1I";
			break;

		case Intrinsic::eSubgroupInclusiveXor2I:
			result = "SubgroupInclusiveXor2I";
			break;

		case Intrinsic::eSubgroupInclusiveXor3I:
			result = "SubgroupInclusiveXor3I";
			break;

		case Intrinsic::eSubgroupInclusiveXor4I:
			result = "SubgroupInclusiveXor4I";
			break;

		case Intrinsic::eSubgroupInclusiveXor1U:
			result = "SubgroupInclusiveXor1U";
			break;

		case Intrinsic::eSubgroupInclusiveXor2U:
			result = "SubgroupInclusiveXor2U";
			break;

		case Intrinsic::eSubgroupInclusiveXor3U:
			result = "SubgroupInclusiveXor3U";
			break;

		case Intrinsic::eSubgroupInclusiveXor4U:
			result = "SubgroupInclusiveXor4U";
			break;

		case Intrinsic::eSubgroupInclusiveXor1B:
			result = "SubgroupInclusiveXor1B";
			break;

		case Intrinsic::eSubgroupInclusiveXor2B:
			result = "SubgroupInclusiveXor2B";
			break;

		case Intrinsic::eSubgroupInclusiveXor3B:
			result = "SubgroupInclusiveXor3B";
			break;

		case Intrinsic::eSubgroupInclusiveXor4B:
			result = "SubgroupInclusiveXor4B";
			break;

		case Intrinsic::eSubgroupExclusiveAdd1F:
			result = "SubgroupExclusiveAdd1F";
			break;

		case Intrinsic::eSubgroupExclusiveAdd2F:
			result = "SubgroupExclusiveAdd2F";
			break;

		case Intrinsic::eSubgroupExclusiveAdd3F:
			result = "SubgroupExclusiveAdd3F";
			break;

		case Intrinsic::eSubgroupExclusiveAdd4F:
			result = "SubgroupExclusiveAdd4F";
			break;

		case Intrinsic::eSubgroupExclusiveAdd1I:
			result = "SubgroupExclusiveAdd1I";
			break;

		case Intrinsic::eSubgroupExclusiveAdd2I:
			result = "SubgroupExclusiveAdd2I";
			break;

		case Intrinsic::eSubgroupExclusiveAdd3I:
			result = "SubgroupExclusiveAdd3I";
			break;

		case Intrinsic::eSubgroupExclusiveAdd4I:
			result = "SubgroupExclusiveAdd4I";
			break;

		case Intrinsic::eSubgroupExclusiveAdd1U:
			result = "SubgroupExclusiveAdd1U";
			break;

		case Intrinsic::eSubgroupExclusiveAdd2U:
			result = "SubgroupExclusiveAdd2U";
			break;

		case Intrinsic::eSubgroupExclusiveAdd3U:
			result = "SubgroupExclusiveAdd3U";
			break;

		case Intrinsic::eSubgroupExclusiveAdd4U:
			result = "SubgroupExclusiveAdd4U";
			break;

		case Intrinsic::eSubgroupExclusiveAdd1D:
			result = "SubgroupExclusiveAdd1D";
			break;

		case Intrinsic::eSubgroupExclusiveAdd2D:
			result = "SubgroupExclusiveAdd2D";
			break;

		case Intrinsic::eSubgroupExclusiveAdd3D:
			result = "SubgroupExclusiveAdd3D";
			break;

		case Intrinsic::eSubgroupExclusiveAdd4D:
			result = "SubgroupExclusiveAdd4D";
			break;

		case Intrinsic::eSubgroupExclusiveMul1F:
			result = "SubgroupExclusiveMul1F";
			break;

		case Intrinsic::eSubgroupExclusiveMul2F:
			result = "SubgroupExclusiveMul2F";
			break;

		case Intrinsic::eSubgroupExclusiveMul3F:
			result = "SubgroupExclusiveMul3F";
			break;

		case Intrinsic::eSubgroupExclusiveMul4F:
			result = "SubgroupExclusiveMul4F";
			break;

		case Intrinsic::eSubgroupExclusiveMul1I:
			result = "SubgroupExclusiveMul1I";
			break;

		case Intrinsic::eSubgroupExclusiveMul2I:
			result = "SubgroupExclusiveMul2I";
			break;

		case Intrinsic::eSubgroupExclusiveMul3I:
			result = "SubgroupExclusiveMul3I";
			break;

		case Intrinsic::eSubgroupExclusiveMul4I:
			result = "SubgroupExclusiveMul4I";
			break;

		case Intrinsic::eSubgroupExclusiveMul1U:
			result = "SubgroupExclusiveMul1U";
			break;

		case Intrinsic::eSubgroupExclusiveMul2U:
			result = "SubgroupExclusiveMul2U";
			break;

		case Intrinsic::eSubgroupExclusiveMul3U:
			result = "SubgroupExclusiveMul3U";
			break;

		case Intrinsic::eSubgroupExclusiveMul4U:
			result = "SubgroupExclusiveMul4U";
			break;

		case Intrinsic::eSubgroupExclusiveMul1D:
			result = "SubgroupExclusiveMul1D";
			break;

		case Intrinsic::eSubgroupExclusiveMul2D:
			result = "SubgroupExclusiveMul2D";
			break;

		case Intrinsic::eSubgroupExclusiveMul3D:
			result = "SubgroupExclusiveMul3D";
			break;

		case Intrinsic::eSubgroupExclusiveMul4D:
			result = "SubgroupExclusiveMul4D";
			break;

		case Intrinsic::eSubgroupExclusiveMin1F:
			result = "SubgroupExclusiveMin1F";
			break;

		case Intrinsic::eSubgroupExclusiveMin2F:
			result = "SubgroupExclusiveMin2F";
			break;

		case Intrinsic::eSubgroupExclusiveMin3F:
			result = "SubgroupExclusiveMin3F";
			break;

		case Intrinsic::eSubgroupExclusiveMin4F:
			result = "SubgroupExclusiveMin4F";
			break;

		case Intrinsic::eSubgroupExclusiveMin1I:
			result = "SubgroupExclusiveMin1I";
			break;

		case Intrinsic::eSubgroupExclusiveMin2I:
			result = "SubgroupExclusiveMin2I";
			break;

		case Intrinsic::eSubgroupExclusiveMin3I:
			result = "SubgroupExclusiveMin3I";
			break;

		case Intrinsic::eSubgroupExclusiveMin4I:
			result = "SubgroupExclusiveMin4I";
			break;

		case Intrinsic::eSubgroupExclusiveMin1U:
			result = "SubgroupExclusiveMin1U";
			break;

		case Intrinsic::eSubgroupExclusiveMin2U:
			result = "SubgroupExclusiveMin2U";
			break;

		case Intrinsic::eSubgroupExclusiveMin3U:
			result = "SubgroupExclusiveMin3U";
			break;

		case Intrinsic::eSubgroupExclusiveMin4U:
			result = "SubgroupExclusiveMin4U";
			break;

		case Intrinsic::eSubgroupExclusiveMin1D:
			result = "SubgroupExclusiveMin1D";
			break;

		case Intrinsic::eSubgroupExclusiveMin2D:
			result = "SubgroupExclusiveMin2D";
			break;

		case Intrinsic::eSubgroupExclusiveMin3D:
			result = "SubgroupExclusiveMin3D";
			break;

		case Intrinsic::eSubgroupExclusiveMin4D:
			result = "SubgroupExclusiveMin4D";
			break;

		case Intrinsic::eSubgroupExclusiveMax1F:
			result = "SubgroupExclusiveMax1F";
			break;

		case Intrinsic::eSubgroupExclusiveMax2F:
			result = "SubgroupExclusiveMax2F";
			break;

		case Intrinsic::eSubgroupExclusiveMax3F:
			result = "SubgroupExclusiveMax3F";
			break;

		case Intrinsic::eSubgroupExclusiveMax4F:
			result = "SubgroupExclusiveMax4F";
			break;

		case Intrinsic::eSubgroupExclusiveMax1I:
			result = "SubgroupExclusiveMax1I";
			break;

		case Intrinsic::eSubgroupExclusiveMax2I:
			result = "SubgroupExclusiveMax2I";
			break;

		case Intrinsic::eSubgroupExclusiveMax3I:
			result = "SubgroupExclusiveMax3I";
			break;

		case Intrinsic::eSubgroupExclusiveMax4I:
			result = "SubgroupExclusiveMax4I";
			break;

		case Intrinsic::eSubgroupExclusiveMax1U:
			result = "SubgroupExclusiveMax1U";
			break;

		case Intrinsic::eSubgroupExclusiveMax2U:
			result = "SubgroupExclusiveMax2U";
			break;

		case Intrinsic::eSubgroupExclusiveMax3U:
			result = "SubgroupExclusiveMax3U";
			break;

		case Intrinsic::eSubgroupExclusiveMax4U:
			result = "SubgroupExclusiveMax4U";
			break;

		case Intrinsic::eSubgroupExclusiveMax1D:
			result = "SubgroupExclusiveMax1D";
			break;

		case Intrinsic::eSubgroupExclusiveMax2D:
			result = "SubgroupExclusiveMax2D";
			break;

		case Intrinsic::eSubgroupExclusiveMax3D:
			result = "SubgroupExclusiveMax3D";
			break;

		case Intrinsic::eSubgroupExclusiveMax4D:
			result = "SubgroupExclusiveMax4D";
			break;

		case Intrinsic::eSubgroupExclusiveAnd1I:
			result = "SubgroupExclusiveAnd1I";
			break;

		case Intrinsic::eSubgroupExclusiveAnd2I:
			result = "SubgroupExclusiveAnd2I";
			break;

		case Intrinsic::eSubgroupExclusiveAnd3I:
			result = "SubgroupExclusiveAnd3I";
			break;

		case Intrinsic::eSubgroupExclusiveAnd4I:
			result = "SubgroupExclusiveAnd4I";
			break;

		case Intrinsic::eSubgroupExclusiveAnd1U:
			result = "SubgroupExclusiveAnd1U";
			break;

		case Intrinsic::eSubgroupExclusiveAnd2U:
			result = "SubgroupExclusiveAnd2U";
			break;

		case Intrinsic::eSubgroupExclusiveAnd3U:
			result = "SubgroupExclusiveAnd3U";
			break;

		case Intrinsic::eSubgroupExclusiveAnd4U:
			result = "SubgroupExclusiveAnd4U";
			break;

		case Intrinsic::eSubgroupExclusiveAnd1B:
			result = "SubgroupExclusiveAnd1B";
			break;

		case Intrinsic::eSubgroupExclusiveAnd2B:
			result = "SubgroupExclusiveAnd2B";
			break;

		case Intrinsic::eSubgroupExclusiveAnd3B:
			result = "SubgroupExclusiveAnd3B";
			break;

		case Intrinsic::eSubgroupExclusiveAnd4B:
			result = "SubgroupExclusiveAnd4B";
			break;

		case Intrinsic::eSubgroupExclusiveOr1I:
			result = "SubgroupExclusiveOr1I";
			break;

		case Intrinsic::eSubgroupExclusiveOr2I:
			result = "SubgroupExclusiveOr2I";
			break;

		case Intrinsic::eSubgroupExclusiveOr3I:
			result = "SubgroupExclusiveOr3I";
			break;

		case Intrinsic::eSubgroupExclusiveOr4I:
			result = "SubgroupExclusiveOr4I";
			break;

		case Intrinsic::eSubgroupExclusiveOr1U:
			result = "SubgroupExclusiveOr1U";
			break;

		case Intrinsic::eSubgroupExclusiveOr2U:
			result = "SubgroupExclusiveOr2U";
			break;

		case Intrinsic::eSubgroupExclusiveOr3U:
			result = "SubgroupExclusiveOr3U";
			break;

		case Intrinsic::eSubgroupExclusiveOr4U:
			result = "SubgroupExclusiveOr4U";
			break;

		case Intrinsic::eSubgroupExclusiveOr1B:
			result = "SubgroupExclusiveOr1B";
			break;

		case Intrinsic::eSubgroupExclusiveOr2B:
			result = "SubgroupExclusiveOr2B";
			break;

		case Intrinsic::eSubgroupExclusiveOr3B:
			result = "SubgroupExclusiveOr3B";
			break;

		case Intrinsic::eSubgroupExclusiveOr4B:
			result = "SubgroupExclusiveOr4B";
			break;

		case Intrinsic::eSubgroupExclusiveXor1I:
			result = "SubgroupExclusiveXor1I";
			break;

		case Intrinsic::eSubgroupExclusiveXor2I:
			result = "SubgroupExclusiveXor2I";
			break;

		case Intrinsic::eSubgroupExclusiveXor3I:
			result = "SubgroupExclusiveXor3I";
			break;

		case Intrinsic::eSubgroupExclusiveXor4I:
			result = "SubgroupExclusiveXor4I";
			break;

		case Intrinsic::eSubgroupExclusiveXor1U:
			result = "SubgroupExclusiveXor1U";
			break;

		case Intrinsic::eSubgroupExclusiveXor2U:
			result = "SubgroupExclusiveXor2U";
			break;

		case Intrinsic::eSubgroupExclusiveXor3U:
			result = "SubgroupExclusiveXor3U";
			break;

		case Intrinsic::eSubgroupExclusiveXor4U:
			result = "SubgroupExclusiveXor4U";
			break;

		case Intrinsic::eSubgroupExclusiveXor1B:
			result = "SubgroupExclusiveXor1B";
			break;

		case Intrinsic::eSubgroupExclusiveXor2B:
			result = "SubgroupExclusiveXor2B";
			break;

		case Intrinsic::eSubgroupExclusiveXor3B:
			result = "SubgroupExclusiveXor3B";
			break;

		case Intrinsic::eSubgroupExclusiveXor4B:
			result = "SubgroupExclusiveXor4B";
			break;

		case Intrinsic::eSubgroupClusterAdd1F:
			result = "SubgroupClusterAdd1F";
			break;

		case Intrinsic::eSubgroupClusterAdd2F:
			result = "SubgroupClusterAdd2F";
			break;

		case Intrinsic::eSubgroupClusterAdd3F:
			result = "SubgroupClusterAdd3F";
			break;

		case Intrinsic::eSubgroupClusterAdd4F:
			result = "SubgroupClusterAdd4F";
			break;

		case Intrinsic::eSubgroupClusterAdd1I:
			result = "SubgroupClusterAdd1I";
			break;

		case Intrinsic::eSubgroupClusterAdd2I:
			result = "SubgroupClusterAdd2I";
			break;

		case Intrinsic::eSubgroupClusterAdd3I:
			result = "SubgroupClusterAdd3I";
			break;

		case Intrinsic::eSubgroupClusterAdd4I:
			result = "SubgroupClusterAdd4I";
			break;

		case Intrinsic::eSubgroupClusterAdd1U:
			result = "SubgroupClusterAdd1U";
			break;

		case Intrinsic::eSubgroupClusterAdd2U:
			result = "SubgroupClusterAdd2U";
			break;

		case Intrinsic::eSubgroupClusterAdd3U:
			result = "SubgroupClusterAdd3U";
			break;

		case Intrinsic::eSubgroupClusterAdd4U:
			result = "SubgroupClusterAdd4U";
			break;

		case Intrinsic::eSubgroupClusterAdd1D:
			result = "SubgroupClusterAdd1D";
			break;

		case Intrinsic::eSubgroupClusterAdd2D:
			result = "SubgroupClusterAdd2D";
			break;

		case Intrinsic::eSubgroupClusterAdd3D:
			result = "SubgroupClusterAdd3D";
			break;

		case Intrinsic::eSubgroupClusterAdd4D:
			result = "SubgroupClusterAdd4D";
			break;

		case Intrinsic::eSubgroupClusterMul1F:
			result = "SubgroupClusterMul1F";
			break;

		case Intrinsic::eSubgroupClusterMul2F:
			result = "SubgroupClusterMul2F";
			break;

		case Intrinsic::eSubgroupClusterMul3F:
			result = "SubgroupClusterMul3F";
			break;

		case Intrinsic::eSubgroupClusterMul4F:
			result = "SubgroupClusterMul4F";
			break;

		case Intrinsic::eSubgroupClusterMul1I:
			result = "SubgroupClusterMul1I";
			break;

		case Intrinsic::eSubgroupClusterMul2I:
			result = "SubgroupClusterMul2I";
			break;

		case Intrinsic::eSubgroupClusterMul3I:
			result = "SubgroupClusterMul3I";
			break;

		case Intrinsic::eSubgroupClusterMul4I:
			result = "SubgroupClusterMul4I";
			break;

		case Intrinsic::eSubgroupClusterMul1U:
			result = "SubgroupClusterMul1U";
			break;

		case Intrinsic::eSubgroupClusterMul2U:
			result = "SubgroupClusterMul2U";
			break;

		case Intrinsic::eSubgroupClusterMul3U:
			result = "SubgroupClusterMul3U";
			break;

		case Intrinsic::eSubgroupClusterMul4U:
			result = "SubgroupClusterMul4U";
			break;

		case Intrinsic::eSubgroupClusterMul1D:
			result = "SubgroupClusterMul1D";
			break;

		case Intrinsic::eSubgroupClusterMul2D:
			result = "SubgroupClusterMul2D";
			break;

		case Intrinsic::eSubgroupClusterMul3D:
			result = "SubgroupClusterMul3D";
			break;

		case Intrinsic::eSubgroupClusterMul4D:
			result = "SubgroupClusterMul4D";
			break;

		case Intrinsic::eSubgroupClusterMin1F:
			result = "SubgroupClusterMin1F";
			break;

		case Intrinsic::eSubgroupClusterMin2F:
			result = "SubgroupClusterMin2F";
			break;

		case Intrinsic::eSubgroupClusterMin3F:
			result = "SubgroupClusterMin3F";
			break;

		case Intrinsic::eSubgroupClusterMin4F:
			result = "SubgroupClusterMin4F";
			break;

		case Intrinsic::eSubgroupClusterMin1I:
			result = "SubgroupClusterMin1I";
			break;

		case Intrinsic::eSubgroupClusterMin2I:
			result = "SubgroupClusterMin2I";
			break;

		case Intrinsic::eSubgroupClusterMin3I:
			result = "SubgroupClusterMin3I";
			break;

		case Intrinsic::eSubgroupClusterMin4I:
			result = "SubgroupClusterMin4I";
			break;

		case Intrinsic::eSubgroupClusterMin1U:
			result = "SubgroupClusterMin1U";
			break;

		case Intrinsic::eSubgroupClusterMin2U:
			result = "SubgroupClusterMin2U";
			break;

		case Intrinsic::eSubgroupClusterMin3U:
			result = "SubgroupClusterMin3U";
			break;

		case Intrinsic::eSubgroupClusterMin4U:
			result = "SubgroupClusterMin4U";
			break;

		case Intrinsic::eSubgroupClusterMin1D:
			result = "SubgroupClusterMin1D";
			break;

		case Intrinsic::eSubgroupClusterMin2D:
			result = "SubgroupClusterMin2D";
			break;

		case Intrinsic::eSubgroupClusterMin3D:
			result = "SubgroupClusterMin3D";
			break;

		case Intrinsic::eSubgroupClusterMin4D:
			result = "SubgroupClusterMin4D";
			break;

		case Intrinsic::eSubgroupClusterMax1F:
			result = "SubgroupClusterMax1F";
			break;

		case Intrinsic::eSubgroupClusterMax2F:
			result = "SubgroupClusterMax2F";
			break;

		case Intrinsic::eSubgroupClusterMax3F:
			result = "SubgroupClusterMax3F";
			break;

		case Intrinsic::eSubgroupClusterMax4F:
			result = "SubgroupClusterMax4F";
			break;

		case Intrinsic::eSubgroupClusterMax1I:
			result = "SubgroupClusterMax1I";
			break;

		case Intrinsic::eSubgroupClusterMax2I:
			result = "SubgroupClusterMax2I";
			break;

		case Intrinsic::eSubgroupClusterMax3I:
			result = "SubgroupClusterMax3I";
			break;

		case Intrinsic::eSubgroupClusterMax4I:
			result = "SubgroupClusterMax4I";
			break;

		case Intrinsic::eSubgroupClusterMax1U:
			result = "SubgroupClusterMax1U";
			break;

		case Intrinsic::eSubgroupClusterMax2U:
			result = "SubgroupClusterMax2U";
			break;

		case Intrinsic::eSubgroupClusterMax3U:
			result = "SubgroupClusterMax3U";
			break;

		case Intrinsic::eSubgroupClusterMax4U:
			result = "SubgroupClusterMax4U";
			break;

		case Intrinsic::eSubgroupClusterMax1D:
			result = "SubgroupClusterMax1D";
			break;

		case Intrinsic::eSubgroupClusterMax2D:
			result = "SubgroupClusterMax2D";
			break;

		case Intrinsic::eSubgroupClusterMax3D:
			result = "SubgroupClusterMax3D";
			break;

		case Intrinsic::eSubgroupClusterMax4D:
			result = "SubgroupClusterMax4D";
			break;

		case Intrinsic::eSubgroupClusterAnd1I:
			result = "SubgroupClusterAnd1I";
			break;

		case Intrinsic::eSubgroupClusterAnd2I:
			result = "SubgroupClusterAnd2I";
			break;

		case Intrinsic::eSubgroupClusterAnd3I:
			result = "SubgroupClusterAnd3I";
			break;

		case Intrinsic::eSubgroupClusterAnd4I:
			result = "SubgroupClusterAnd4I";
			break;

		case Intrinsic::eSubgroupClusterAnd1U:
			result = "SubgroupClusterAnd1U";
			break;

		case Intrinsic::eSubgroupClusterAnd2U:
			result = "SubgroupClusterAnd2U";
			break;

		case Intrinsic::eSubgroupClusterAnd3U:
			result = "SubgroupClusterAnd3U";
			break;

		case Intrinsic::eSubgroupClusterAnd4U:
			result = "SubgroupClusterAnd4U";
			break;

		case Intrinsic::eSubgroupClusterAnd1B:
			result = "SubgroupClusterAnd1B";
			break;

		case Intrinsic::eSubgroupClusterAnd2B:
			result = "SubgroupClusterAnd2B";
			break;

		case Intrinsic::eSubgroupClusterAnd3B:
			result = "SubgroupClusterAnd3B";
			break;

		case Intrinsic::eSubgroupClusterAnd4B:
			result = "SubgroupClusterAnd4B";
			break;

		case Intrinsic::eSubgroupClusterOr1I:
			result = "SubgroupClusterOr1I";
			break;

		case Intrinsic::eSubgroupClusterOr2I:
			result = "SubgroupClusterOr2I";
			break;

		case Intrinsic::eSubgroupClusterOr3I:
			result = "SubgroupClusterOr3I";
			break;

		case Intrinsic::eSubgroupClusterOr4I:
			result = "SubgroupClusterOr4I";
			break;

		case Intrinsic::eSubgroupClusterOr1U:
			result = "SubgroupClusterOr1U";
			break;

		case Intrinsic::eSubgroupClusterOr2U:
			result = "SubgroupClusterOr2U";
			break;

		case Intrinsic::eSubgroupClusterOr3U:
			result = "SubgroupClusterOr3U";
			break;

		case Intrinsic::eSubgroupClusterOr4U:
			result = "SubgroupClusterOr4U";
			break;

		case Intrinsic::eSubgroupClusterOr1B:
			result = "SubgroupClusterOr1B";
			break;

		case Intrinsic::eSubgroupClusterOr2B:
			result = "SubgroupClusterOr2B";
			break;

		case Intrinsic::eSubgroupClusterOr3B:
			result = "SubgroupClusterOr3B";
			break;

		case Intrinsic::eSubgroupClusterOr4B:
			result = "SubgroupClusterOr4B";
			break;

		case Intrinsic::eSubgroupClusterXor1I:
			result = "SubgroupClusterXor1I";
			break;

		case Intrinsic::eSubgroupClusterXor2I:
			result = "SubgroupClusterXor2I";
			break;

		case Intrinsic::eSubgroupClusterXor3I:
			result = "SubgroupClusterXor3I";
			break;

		case Intrinsic::eSubgroupClusterXor4I:
			result = "SubgroupClusterXor4I";
			break;

		case Intrinsic::eSubgroupClusterXor1U:
			result = "SubgroupClusterXor1U";
			break;

		case Intrinsic::eSubgroupClusterXor2U:
			result = "SubgroupClusterXor2U";
			break;

		case Intrinsic::eSubgroupClusterXor3U:
			result = "SubgroupClusterXor3U";
			break;

		case Intrinsic::eSubgroupClusterXor4U:
			result = "SubgroupClusterXor4U";
			break;

		case Intrinsic::eSubgroupClusterXor1B:
			result = "SubgroupClusterXor1B";
			break;

		case Intrinsic::eSubgroupClusterXor2B:
			result = "SubgroupClusterXor2B";
			break;

		case Intrinsic::eSubgroupClusterXor3B:
			result = "SubgroupClusterXor3B";
			break;

		case Intrinsic::eSubgroupClusterXor4B:
			result = "SubgroupClusterXor4B";
			break;

		case Intrinsic::eSubgroupQuadBroadcast1F:
			result = "SubgroupQuadBroadcast1F";
			break;

		case Intrinsic::eSubgroupQuadBroadcast2F:
			result = "SubgroupQuadBroadcast2F";
			break;

		case Intrinsic::eSubgroupQuadBroadcast3F:
			result = "SubgroupQuadBroadcast3F";
			break;

		case Intrinsic::eSubgroupQuadBroadcast4F:
			result = "SubgroupQuadBroadcast4F";
			break;

		case Intrinsic::eSubgroupQuadBroadcast1I:
			result = "SubgroupQuadBroadcast1I";
			break;

		case Intrinsic::eSubgroupQuadBroadcast2I:
			result = "SubgroupQuadBroadcast2I";
			break;

		case Intrinsic::eSubgroupQuadBroadcast3I:
			result = "SubgroupQuadBroadcast3I";
			break;

		case Intrinsic::eSubgroupQuadBroadcast4I:
			result = "SubgroupQuadBroadcast4I";
			break;

		case Intrinsic::eSubgroupQuadBroadcast1U:
			result = "SubgroupQuadBroadcast1U";
			break;

		case Intrinsic::eSubgroupQuadBroadcast2U:
			result = "SubgroupQuadBroadcast2U";
			break;

		case Intrinsic::eSubgroupQuadBroadcast3U:
			result = "SubgroupQuadBroadcast3U";
			break;

		case Intrinsic::eSubgroupQuadBroadcast4U:
			result = "SubgroupQuadBroadcast4U";
			break;

		case Intrinsic::eSubgroupQuadBroadcast1B:
			result = "SubgroupQuadBroadcast1B";
			break;

		case Intrinsic::eSubgroupQuadBroadcast2B:
			result = "SubgroupQuadBroadcast2B";
			break;

		case Intrinsic::eSubgroupQuadBroadcast3B:
			result = "SubgroupQuadBroadcast3B";
			break;

		case Intrinsic::eSubgroupQuadBroadcast4B:
			result = "SubgroupQuadBroadcast4B";
			break;

		case Intrinsic::eSubgroupQuadBroadcast1D:
			result = "SubgroupQuadBroadcast1D";
			break;

		case Intrinsic::eSubgroupQuadBroadcast2D:
			result = "SubgroupQuadBroadcast2D";
			break;

		case Intrinsic::eSubgroupQuadBroadcast3D:
			result = "SubgroupQuadBroadcast3D";
			break;

		case Intrinsic::eSubgroupQuadBroadcast4D:
			result = "SubgroupQuadBroadcast4D";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal1F:
			result = "SubgroupQuadSwapHorizontal1F";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal2F:
			result = "SubgroupQuadSwapHorizontal2F";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal3F:
			result = "SubgroupQuadSwapHorizontal3F";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal4F:
			result = "SubgroupQuadSwapHorizontal4F";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal1I:
			result = "SubgroupQuadSwapHorizontal1I";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal2I:
			result = "SubgroupQuadSwapHorizontal2I";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal3I:
			result = "SubgroupQuadSwapHorizontal3I";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal4I:
			result = "SubgroupQuadSwapHorizontal4I";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal1U:
			result = "SubgroupQuadSwapHorizontal1U";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal2U:
			result = "SubgroupQuadSwapHorizontal2U";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal3U:
			result = "SubgroupQuadSwapHorizontal3U";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal4U:
			result = "SubgroupQuadSwapHorizontal4U";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal1B:
			result = "SubgroupQuadSwapHorizontal1B";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal2B:
			result = "SubgroupQuadSwapHorizontal2B";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal3B:
			result = "SubgroupQuadSwapHorizontal3B";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal4B:
			result = "SubgroupQuadSwapHorizontal4B";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal1D:
			result = "SubgroupQuadSwapHorizontal1D";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal2D:
			result = "SubgroupQuadSwapHorizontal2D";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal3D:
			result = "SubgroupQuadSwapHorizontal3D";
			break;

		case Intrinsic::eSubgroupQuadSwapHorizontal4D:
			result = "SubgroupQuadSwapHorizontal4D";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical1F:
			result = "SubgroupQuadSwapVertical1F";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical2F:
			result = "SubgroupQuadSwapVertical2F";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical3F:
			result = "SubgroupQuadSwapVertical3F";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical4F:
			result = "SubgroupQuadSwapVertical4F";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical1I:
			result = "SubgroupQuadSwapVertical1I";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical2I:
			result = "SubgroupQuadSwapVertical2I";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical3I:
			result = "SubgroupQuadSwapVertical3I";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical4I:
			result = "SubgroupQuadSwapVertical4I";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical1U:
			result = "SubgroupQuadSwapVertical1U";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical2U:
			result = "SubgroupQuadSwapVertical2U";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical3U:
			result = "SubgroupQuadSwapVertical3U";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical4U:
			result = "SubgroupQuadSwapVertical4U";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical1B:
			result = "SubgroupQuadSwapVertical1B";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical2B:
			result = "SubgroupQuadSwapVertical2B";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical3B:
			result = "SubgroupQuadSwapVertical3B";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical4B:
			result = "SubgroupQuadSwapVertical4B";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical1D:
			result = "SubgroupQuadSwapVertical1D";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical2D:
			result = "SubgroupQuadSwapVertical2D";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical3D:
			result = "SubgroupQuadSwapVertical3D";
			break;

		case Intrinsic::eSubgroupQuadSwapVertical4D:
			result = "SubgroupQuadSwapVertical4D";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal1F:
			result = "SubgroupQuadSwapDiagonal1F";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal2F:
			result = "SubgroupQuadSwapDiagonal2F";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal3F:
			result = "SubgroupQuadSwapDiagonal3F";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal4F:
			result = "SubgroupQuadSwapDiagonal4F";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal1I:
			result = "SubgroupQuadSwapDiagonal1I";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal2I:
			result = "SubgroupQuadSwapDiagonal2I";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal3I:
			result = "SubgroupQuadSwapDiagonal3I";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal4I:
			result = "SubgroupQuadSwapDiagonal4I";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal1U:
			result = "SubgroupQuadSwapDiagonal1U";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal2U:
			result = "SubgroupQuadSwapDiagonal2U";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal3U:
			result = "SubgroupQuadSwapDiagonal3U";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal4U:
			result = "SubgroupQuadSwapDiagonal4U";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal1B:
			result = "SubgroupQuadSwapDiagonal1B";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal2B:
			result = "SubgroupQuadSwapDiagonal2B";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal3B:
			result = "SubgroupQuadSwapDiagonal3B";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal4B:
			result = "SubgroupQuadSwapDiagonal4B";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal1D:
			result = "SubgroupQuadSwapDiagonal1D";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal2D:
			result = "SubgroupQuadSwapDiagonal2D";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal3D:
			result = "SubgroupQuadSwapDiagonal3D";
			break;

		case Intrinsic::eSubgroupQuadSwapDiagonal4D:
			result = "SubgroupQuadSwapDiagonal4D";
			break;


	//Shader Invocation Group Functions
		case Intrinsic::eReadInvocation1F:
			result = "ReadInvocation1F";
			break;

		case Intrinsic::eReadInvocation2F:
			result = "ReadInvocation2F";
			break;

		case Intrinsic::eReadInvocation3F:
			result = "ReadInvocation3F";
			break;

		case Intrinsic::eReadInvocation4F:
			result = "ReadInvocation4F";
			break;

		case Intrinsic::eReadInvocation1I:
			result = "ReadInvocation1I";
			break;

		case Intrinsic::eReadInvocation2I:
			result = "ReadInvocation2I";
			break;

		case Intrinsic::eReadInvocation3I:
			result = "ReadInvocation3I";
			break;

		case Intrinsic::eReadInvocation4I:
			result = "ReadInvocation4I";
			break;

		case Intrinsic::eReadInvocation1U:
			result = "ReadInvocation1U";
			break;

		case Intrinsic::eReadInvocation2U:
			result = "ReadInvocation2U";
			break;

		case Intrinsic::eReadInvocation3U:
			result = "ReadInvocation3U";
			break;

		case Intrinsic::eReadInvocation4U:
			result = "ReadInvocation4U";
			break;

		case Intrinsic::eReadInvocation1D:
			result = "ReadInvocation1D";
			break;

		case Intrinsic::eReadInvocation2D:
			result = "ReadInvocation2D";
			break;

		case Intrinsic::eReadInvocation3D:
			result = "ReadInvocation3D";
			break;

		case Intrinsic::eReadInvocation4D:
			result = "ReadInvocation4D";
			break;

		case Intrinsic::eReadFirstInvocation1F:
			result = "ReadFirstInvocation1F";
			break;

		case Intrinsic::eReadFirstInvocation2F:
			result = "ReadFirstInvocation2F";
			break;

		case Intrinsic::eReadFirstInvocation3F:
			result = "ReadFirstInvocation3F";
			break;

		case Intrinsic::eReadFirstInvocation4F:
			result = "ReadFirstInvocation4F";
			break;

		case Intrinsic::eReadFirstInvocation1I:
			result = "ReadFirstInvocation1I";
			break;

		case Intrinsic::eReadFirstInvocation2I:
			result = "ReadFirstInvocation2I";
			break;

		case Intrinsic::eReadFirstInvocation3I:
			result = "ReadFirstInvocation3I";
			break;

		case Intrinsic::eReadFirstInvocation4I:
			result = "ReadFirstInvocation4I";
			break;

		case Intrinsic::eReadFirstInvocation1U:
			result = "ReadFirstInvocation1U";
			break;

		case Intrinsic::eReadFirstInvocation2U:
			result = "ReadFirstInvocation2U";
			break;

		case Intrinsic::eReadFirstInvocation3U:
			result = "ReadFirstInvocation3U";
			break;

		case Intrinsic::eReadFirstInvocation4U:
			result = "ReadFirstInvocation4U";
			break;

		case Intrinsic::eReadFirstInvocation1D:
			result = "ReadFirstInvocation1D";
			break;

		case Intrinsic::eReadFirstInvocation2D:
			result = "ReadFirstInvocation2D";
			break;

		case Intrinsic::eReadFirstInvocation3D:
			result = "ReadFirstInvocation3D";
			break;

		case Intrinsic::eReadFirstInvocation4D:
			result = "ReadFirstInvocation4D";
			break;

		default:
			throw Exception{ "Unsupported Intrinsic type." };
		}

		return result;
	}
}

#endif
