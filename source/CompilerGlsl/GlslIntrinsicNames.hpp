/*
See LICENSE file in root folder
*/
#ifndef ___AST_GlslIntrinsicNames_H___
#define ___AST_GlslIntrinsicNames_H___
#pragma once

#include <ShaderAST/Expr/EnumIntrinsic.hpp>

#include <string>

namespace glsl
{
	inline std::string getGlslName( ast::expr::Intrinsic value )
	{
		std::string result;

		switch ( value )
		{
	// Angle and Trigonometry Functions
		case ast::expr::Intrinsic::eDegrees1:
		case ast::expr::Intrinsic::eDegrees2:
		case ast::expr::Intrinsic::eDegrees3:
		case ast::expr::Intrinsic::eDegrees4:
			result = "degrees";
			break;

		case ast::expr::Intrinsic::eRadians1F:
		case ast::expr::Intrinsic::eRadians2F:
		case ast::expr::Intrinsic::eRadians3F:
		case ast::expr::Intrinsic::eRadians4F:
			result = "radians";
			break;

		case ast::expr::Intrinsic::eCos1:
		case ast::expr::Intrinsic::eCos2:
		case ast::expr::Intrinsic::eCos3:
		case ast::expr::Intrinsic::eCos4:
			result = "cos";
			break;

		case ast::expr::Intrinsic::eSin1:
		case ast::expr::Intrinsic::eSin2:
		case ast::expr::Intrinsic::eSin3:
		case ast::expr::Intrinsic::eSin4:
			result = "sin";
			break;

		case ast::expr::Intrinsic::eTan1:
		case ast::expr::Intrinsic::eTan2:
		case ast::expr::Intrinsic::eTan3:
		case ast::expr::Intrinsic::eTan4:
			result = "tan";
			break;

		case ast::expr::Intrinsic::eCosh1:
		case ast::expr::Intrinsic::eCosh2:
		case ast::expr::Intrinsic::eCosh3:
		case ast::expr::Intrinsic::eCosh4:
			result = "cosh";
			break;

		case ast::expr::Intrinsic::eSinh1:
		case ast::expr::Intrinsic::eSinh2:
		case ast::expr::Intrinsic::eSinh3:
		case ast::expr::Intrinsic::eSinh4:
			result = "sinh";
			break;

		case ast::expr::Intrinsic::eTanh1:
		case ast::expr::Intrinsic::eTanh2:
		case ast::expr::Intrinsic::eTanh3:
		case ast::expr::Intrinsic::eTanh4:
			result = "tanh";
			break;

		case ast::expr::Intrinsic::eAcos1:
		case ast::expr::Intrinsic::eAcos2:
		case ast::expr::Intrinsic::eAcos3:
		case ast::expr::Intrinsic::eAcos4:
			result = "acos";
			break;

		case ast::expr::Intrinsic::eAsin1:
		case ast::expr::Intrinsic::eAsin2:
		case ast::expr::Intrinsic::eAsin3:
		case ast::expr::Intrinsic::eAsin4:
			result = "asin";
			break;

		case ast::expr::Intrinsic::eAtan1:
		case ast::expr::Intrinsic::eAtan2:
		case ast::expr::Intrinsic::eAtan3:
		case ast::expr::Intrinsic::eAtan4:
			result = "atan";
			break;

		case ast::expr::Intrinsic::eAcosh1:
		case ast::expr::Intrinsic::eAcosh2:
		case ast::expr::Intrinsic::eAcosh3:
		case ast::expr::Intrinsic::eAcosh4:
			result = "acosh";
			break;

		case ast::expr::Intrinsic::eAsinh1:
		case ast::expr::Intrinsic::eAsinh2:
		case ast::expr::Intrinsic::eAsinh3:
		case ast::expr::Intrinsic::eAsinh4:
			result = "asinh";
			break;

		case ast::expr::Intrinsic::eAtanh1:
		case ast::expr::Intrinsic::eAtanh2:
		case ast::expr::Intrinsic::eAtanh3:
		case ast::expr::Intrinsic::eAtanh4:
			result = "atanh";
			break;


	// Exponential Functions
		case ast::expr::Intrinsic::ePow1:
		case ast::expr::Intrinsic::ePow2:
		case ast::expr::Intrinsic::ePow3:
		case ast::expr::Intrinsic::ePow4:
			result = "pow";
			break;

		case ast::expr::Intrinsic::eExp1:
		case ast::expr::Intrinsic::eExp2:
		case ast::expr::Intrinsic::eExp3:
		case ast::expr::Intrinsic::eExp4:
			result = "exp";
			break;

		case ast::expr::Intrinsic::eLog1:
		case ast::expr::Intrinsic::eLog2:
		case ast::expr::Intrinsic::eLog3:
		case ast::expr::Intrinsic::eLog4:
			result = "log";
			break;

		case ast::expr::Intrinsic::eExp21:
		case ast::expr::Intrinsic::eExp22:
		case ast::expr::Intrinsic::eExp23:
		case ast::expr::Intrinsic::eExp24:
			result = "exp2";
			break;

		case ast::expr::Intrinsic::eLog21:
		case ast::expr::Intrinsic::eLog22:
		case ast::expr::Intrinsic::eLog23:
		case ast::expr::Intrinsic::eLog24:
			result = "log2";
			break;

		case ast::expr::Intrinsic::eSqrt1F:
		case ast::expr::Intrinsic::eSqrt2F:
		case ast::expr::Intrinsic::eSqrt3F:
		case ast::expr::Intrinsic::eSqrt4F:
		case ast::expr::Intrinsic::eSqrt1D:
		case ast::expr::Intrinsic::eSqrt2D:
		case ast::expr::Intrinsic::eSqrt3D:
		case ast::expr::Intrinsic::eSqrt4D:
			result = "sqrt";
			break;

		case ast::expr::Intrinsic::eInverseSqrt1F:
		case ast::expr::Intrinsic::eInverseSqrt2F:
		case ast::expr::Intrinsic::eInverseSqrt3F:
		case ast::expr::Intrinsic::eInverseSqrt4F:
		case ast::expr::Intrinsic::eInverseSqrt1D:
		case ast::expr::Intrinsic::eInverseSqrt2D:
		case ast::expr::Intrinsic::eInverseSqrt3D:
		case ast::expr::Intrinsic::eInverseSqrt4D:
			result = "inverseSqrt";
			break;


	// Common Functions
		case ast::expr::Intrinsic::eAbs1F:
		case ast::expr::Intrinsic::eAbs2F:
		case ast::expr::Intrinsic::eAbs3F:
		case ast::expr::Intrinsic::eAbs4F:
		case ast::expr::Intrinsic::eAbs1I:
		case ast::expr::Intrinsic::eAbs2I:
		case ast::expr::Intrinsic::eAbs3I:
		case ast::expr::Intrinsic::eAbs4I:
		case ast::expr::Intrinsic::eAbs1D:
		case ast::expr::Intrinsic::eAbs2D:
		case ast::expr::Intrinsic::eAbs3D:
		case ast::expr::Intrinsic::eAbs4D:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eSign1F:
		case ast::expr::Intrinsic::eSign2F:
		case ast::expr::Intrinsic::eSign3F:
		case ast::expr::Intrinsic::eSign4F:
		case ast::expr::Intrinsic::eSign1I:
		case ast::expr::Intrinsic::eSign2I:
		case ast::expr::Intrinsic::eSign3I:
		case ast::expr::Intrinsic::eSign4I:
		case ast::expr::Intrinsic::eSign1D:
		case ast::expr::Intrinsic::eSign2D:
		case ast::expr::Intrinsic::eSign3D:
		case ast::expr::Intrinsic::eSign4D:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eFloor1F:
		case ast::expr::Intrinsic::eFloor2F:
		case ast::expr::Intrinsic::eFloor3F:
		case ast::expr::Intrinsic::eFloor4F:
		case ast::expr::Intrinsic::eFloor1D:
		case ast::expr::Intrinsic::eFloor2D:
		case ast::expr::Intrinsic::eFloor3D:
		case ast::expr::Intrinsic::eFloor4D:
			result = "floor";
			break;

		case ast::expr::Intrinsic::eTrunc1F:
		case ast::expr::Intrinsic::eTrunc2F:
		case ast::expr::Intrinsic::eTrunc3F:
		case ast::expr::Intrinsic::eTrunc4F:
		case ast::expr::Intrinsic::eTrunc1D:
		case ast::expr::Intrinsic::eTrunc2D:
		case ast::expr::Intrinsic::eTrunc3D:
		case ast::expr::Intrinsic::eTrunc4D:
			result = "trunc";
			break;

		case ast::expr::Intrinsic::eRound1F:
		case ast::expr::Intrinsic::eRound2F:
		case ast::expr::Intrinsic::eRound3F:
		case ast::expr::Intrinsic::eRound4F:
		case ast::expr::Intrinsic::eRound1D:
		case ast::expr::Intrinsic::eRound2D:
		case ast::expr::Intrinsic::eRound3D:
		case ast::expr::Intrinsic::eRound4D:
			result = "round";
			break;

		case ast::expr::Intrinsic::eRoundEven1F:
		case ast::expr::Intrinsic::eRoundEven2F:
		case ast::expr::Intrinsic::eRoundEven3F:
		case ast::expr::Intrinsic::eRoundEven4F:
		case ast::expr::Intrinsic::eRoundEven1D:
		case ast::expr::Intrinsic::eRoundEven2D:
		case ast::expr::Intrinsic::eRoundEven3D:
		case ast::expr::Intrinsic::eRoundEven4D:
			result = "roundEven";
			break;

		case ast::expr::Intrinsic::eCeil1F:
		case ast::expr::Intrinsic::eCeil2F:
		case ast::expr::Intrinsic::eCeil3F:
		case ast::expr::Intrinsic::eCeil4F:
		case ast::expr::Intrinsic::eCeil1D:
		case ast::expr::Intrinsic::eCeil2D:
		case ast::expr::Intrinsic::eCeil3D:
		case ast::expr::Intrinsic::eCeil4D:
			result = "ceil";
			break;

		case ast::expr::Intrinsic::eFract1F:
		case ast::expr::Intrinsic::eFract2F:
		case ast::expr::Intrinsic::eFract3F:
		case ast::expr::Intrinsic::eFract4F:
		case ast::expr::Intrinsic::eFract1D:
		case ast::expr::Intrinsic::eFract2D:
		case ast::expr::Intrinsic::eFract3D:
		case ast::expr::Intrinsic::eFract4D:
			result = "fract";
			break;

		case ast::expr::Intrinsic::eMod11F:
		case ast::expr::Intrinsic::eMod22F:
		case ast::expr::Intrinsic::eMod33F:
		case ast::expr::Intrinsic::eMod44F:
		case ast::expr::Intrinsic::eMod21F:
		case ast::expr::Intrinsic::eMod31F:
		case ast::expr::Intrinsic::eMod41F:
		case ast::expr::Intrinsic::eMod11D:
		case ast::expr::Intrinsic::eMod22D:
		case ast::expr::Intrinsic::eMod33D:
		case ast::expr::Intrinsic::eMod44D:
		case ast::expr::Intrinsic::eMod21D:
		case ast::expr::Intrinsic::eMod31D:
		case ast::expr::Intrinsic::eMod41D:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eModf1F:
		case ast::expr::Intrinsic::eModf2F:
		case ast::expr::Intrinsic::eModf3F:
		case ast::expr::Intrinsic::eModf4F:
		case ast::expr::Intrinsic::eModf1D:
		case ast::expr::Intrinsic::eModf2D:
		case ast::expr::Intrinsic::eModf3D:
		case ast::expr::Intrinsic::eModf4D:
			result = "modf";
			break;

		case ast::expr::Intrinsic::eMin11F:
		case ast::expr::Intrinsic::eMin22F:
		case ast::expr::Intrinsic::eMin33F:
		case ast::expr::Intrinsic::eMin44F:
		case ast::expr::Intrinsic::eMin21F:
		case ast::expr::Intrinsic::eMin31F:
		case ast::expr::Intrinsic::eMin41F:
		case ast::expr::Intrinsic::eMin11D:
		case ast::expr::Intrinsic::eMin22D:
		case ast::expr::Intrinsic::eMin33D:
		case ast::expr::Intrinsic::eMin44D:
		case ast::expr::Intrinsic::eMin21D:
		case ast::expr::Intrinsic::eMin31D:
		case ast::expr::Intrinsic::eMin41D:
		case ast::expr::Intrinsic::eMin11I:
		case ast::expr::Intrinsic::eMin22I:
		case ast::expr::Intrinsic::eMin33I:
		case ast::expr::Intrinsic::eMin44I:
		case ast::expr::Intrinsic::eMin21I:
		case ast::expr::Intrinsic::eMin31I:
		case ast::expr::Intrinsic::eMin41I:
		case ast::expr::Intrinsic::eMin11U:
		case ast::expr::Intrinsic::eMin22U:
		case ast::expr::Intrinsic::eMin33U:
		case ast::expr::Intrinsic::eMin44U:
		case ast::expr::Intrinsic::eMin21U:
		case ast::expr::Intrinsic::eMin31U:
		case ast::expr::Intrinsic::eMin41U:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMax11F:
		case ast::expr::Intrinsic::eMax22F:
		case ast::expr::Intrinsic::eMax33F:
		case ast::expr::Intrinsic::eMax44F:
		case ast::expr::Intrinsic::eMax21F:
		case ast::expr::Intrinsic::eMax31F:
		case ast::expr::Intrinsic::eMax41F:
		case ast::expr::Intrinsic::eMax11D:
		case ast::expr::Intrinsic::eMax22D:
		case ast::expr::Intrinsic::eMax33D:
		case ast::expr::Intrinsic::eMax44D:
		case ast::expr::Intrinsic::eMax21D:
		case ast::expr::Intrinsic::eMax31D:
		case ast::expr::Intrinsic::eMax41D:
		case ast::expr::Intrinsic::eMax11I:
		case ast::expr::Intrinsic::eMax22I:
		case ast::expr::Intrinsic::eMax33I:
		case ast::expr::Intrinsic::eMax44I:
		case ast::expr::Intrinsic::eMax21I:
		case ast::expr::Intrinsic::eMax31I:
		case ast::expr::Intrinsic::eMax41I:
		case ast::expr::Intrinsic::eMax11U:
		case ast::expr::Intrinsic::eMax22U:
		case ast::expr::Intrinsic::eMax33U:
		case ast::expr::Intrinsic::eMax44U:
		case ast::expr::Intrinsic::eMax21U:
		case ast::expr::Intrinsic::eMax31U:
		case ast::expr::Intrinsic::eMax41U:
			result = "max";
			break;

		case ast::expr::Intrinsic::eClamp11F:
		case ast::expr::Intrinsic::eClamp22F:
		case ast::expr::Intrinsic::eClamp33F:
		case ast::expr::Intrinsic::eClamp44F:
		case ast::expr::Intrinsic::eClamp21F:
		case ast::expr::Intrinsic::eClamp31F:
		case ast::expr::Intrinsic::eClamp41F:
		case ast::expr::Intrinsic::eClamp11D:
		case ast::expr::Intrinsic::eClamp22D:
		case ast::expr::Intrinsic::eClamp33D:
		case ast::expr::Intrinsic::eClamp44D:
		case ast::expr::Intrinsic::eClamp21D:
		case ast::expr::Intrinsic::eClamp31D:
		case ast::expr::Intrinsic::eClamp41D:
		case ast::expr::Intrinsic::eClamp11I:
		case ast::expr::Intrinsic::eClamp22I:
		case ast::expr::Intrinsic::eClamp33I:
		case ast::expr::Intrinsic::eClamp44I:
		case ast::expr::Intrinsic::eClamp21I:
		case ast::expr::Intrinsic::eClamp31I:
		case ast::expr::Intrinsic::eClamp41I:
		case ast::expr::Intrinsic::eClamp11U:
		case ast::expr::Intrinsic::eClamp22U:
		case ast::expr::Intrinsic::eClamp33U:
		case ast::expr::Intrinsic::eClamp44U:
		case ast::expr::Intrinsic::eClamp21U:
		case ast::expr::Intrinsic::eClamp31U:
		case ast::expr::Intrinsic::eClamp41U:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eMix11F:
		case ast::expr::Intrinsic::eMix22F:
		case ast::expr::Intrinsic::eMix33F:
		case ast::expr::Intrinsic::eMix44F:
		case ast::expr::Intrinsic::eMix21F:
		case ast::expr::Intrinsic::eMix31F:
		case ast::expr::Intrinsic::eMix41F:
		case ast::expr::Intrinsic::eMix11FB:
		case ast::expr::Intrinsic::eMix22FB:
		case ast::expr::Intrinsic::eMix33FB:
		case ast::expr::Intrinsic::eMix44FB:
		case ast::expr::Intrinsic::eMix11D:
		case ast::expr::Intrinsic::eMix22D:
		case ast::expr::Intrinsic::eMix33D:
		case ast::expr::Intrinsic::eMix44D:
		case ast::expr::Intrinsic::eMix21D:
		case ast::expr::Intrinsic::eMix31D:
		case ast::expr::Intrinsic::eMix41D:
		case ast::expr::Intrinsic::eMix11DB:
		case ast::expr::Intrinsic::eMix22DB:
		case ast::expr::Intrinsic::eMix33DB:
		case ast::expr::Intrinsic::eMix44DB:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eStep11F:
		case ast::expr::Intrinsic::eStep22F:
		case ast::expr::Intrinsic::eStep33F:
		case ast::expr::Intrinsic::eStep44F:
		case ast::expr::Intrinsic::eStep12F:
		case ast::expr::Intrinsic::eStep13F:
		case ast::expr::Intrinsic::eStep14F:
		case ast::expr::Intrinsic::eStep11D:
		case ast::expr::Intrinsic::eStep22D:
		case ast::expr::Intrinsic::eStep33D:
		case ast::expr::Intrinsic::eStep44D:
		case ast::expr::Intrinsic::eStep12D:
		case ast::expr::Intrinsic::eStep13D:
		case ast::expr::Intrinsic::eStep14D:
			result = "step";
			break;

		case ast::expr::Intrinsic::eSmoothStep11F:
		case ast::expr::Intrinsic::eSmoothStep22F:
		case ast::expr::Intrinsic::eSmoothStep33F:
		case ast::expr::Intrinsic::eSmoothStep44F:
		case ast::expr::Intrinsic::eSmoothStep12F:
		case ast::expr::Intrinsic::eSmoothStep13F:
		case ast::expr::Intrinsic::eSmoothStep14F:
		case ast::expr::Intrinsic::eSmoothStep11D:
		case ast::expr::Intrinsic::eSmoothStep22D:
		case ast::expr::Intrinsic::eSmoothStep33D:
		case ast::expr::Intrinsic::eSmoothStep44D:
		case ast::expr::Intrinsic::eSmoothStep12D:
		case ast::expr::Intrinsic::eSmoothStep13D:
		case ast::expr::Intrinsic::eSmoothStep14D:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eIsnan1F:
		case ast::expr::Intrinsic::eIsnan2F:
		case ast::expr::Intrinsic::eIsnan3F:
		case ast::expr::Intrinsic::eIsnan4F:
		case ast::expr::Intrinsic::eIsnan1D:
		case ast::expr::Intrinsic::eIsnan2D:
		case ast::expr::Intrinsic::eIsnan3D:
		case ast::expr::Intrinsic::eIsnan4D:
			result = "isnan";
			break;

		case ast::expr::Intrinsic::eIsinf1F:
		case ast::expr::Intrinsic::eIsinf2F:
		case ast::expr::Intrinsic::eIsinf3F:
		case ast::expr::Intrinsic::eIsinf4F:
		case ast::expr::Intrinsic::eIsinf1D:
		case ast::expr::Intrinsic::eIsinf2D:
		case ast::expr::Intrinsic::eIsinf3D:
		case ast::expr::Intrinsic::eIsinf4D:
			result = "isinf";
			break;

		case ast::expr::Intrinsic::eFloatBitsToInt1:
		case ast::expr::Intrinsic::eFloatBitsToInt2:
		case ast::expr::Intrinsic::eFloatBitsToInt3:
		case ast::expr::Intrinsic::eFloatBitsToInt4:
			result = "floatBitsToInt";
			break;

		case ast::expr::Intrinsic::eFloatBitsToUInt1:
		case ast::expr::Intrinsic::eFloatBitsToUInt2:
		case ast::expr::Intrinsic::eFloatBitsToUInt3:
		case ast::expr::Intrinsic::eFloatBitsToUInt4:
			result = "floatBitsToUInt";
			break;

		case ast::expr::Intrinsic::eIntBitsToFloat1:
		case ast::expr::Intrinsic::eIntBitsToFloat2:
		case ast::expr::Intrinsic::eIntBitsToFloat3:
		case ast::expr::Intrinsic::eIntBitsToFloat4:
			result = "intBitsToFloat";
			break;

		case ast::expr::Intrinsic::eUintBitsToFloat1:
		case ast::expr::Intrinsic::eUintBitsToFloat2:
		case ast::expr::Intrinsic::eUintBitsToFloat3:
		case ast::expr::Intrinsic::eUintBitsToFloat4:
			result = "uintBitsToFloat";
			break;

		case ast::expr::Intrinsic::eFma1F:
		case ast::expr::Intrinsic::eFma2F:
		case ast::expr::Intrinsic::eFma3F:
		case ast::expr::Intrinsic::eFma4F:
		case ast::expr::Intrinsic::eFma1D:
		case ast::expr::Intrinsic::eFma2D:
		case ast::expr::Intrinsic::eFma3D:
		case ast::expr::Intrinsic::eFma4D:
			result = "fma";
			break;

		case ast::expr::Intrinsic::eFrexp1F:
		case ast::expr::Intrinsic::eFrexp2F:
		case ast::expr::Intrinsic::eFrexp3F:
		case ast::expr::Intrinsic::eFrexp4F:
		case ast::expr::Intrinsic::eFrexp1D:
		case ast::expr::Intrinsic::eFrexp2D:
		case ast::expr::Intrinsic::eFrexp3D:
		case ast::expr::Intrinsic::eFrexp4D:
			result = "frexp";
			break;

		case ast::expr::Intrinsic::eLdexp1F:
		case ast::expr::Intrinsic::eLdexp2F:
		case ast::expr::Intrinsic::eLdexp3F:
		case ast::expr::Intrinsic::eLdexp4F:
		case ast::expr::Intrinsic::eLdexp1D:
		case ast::expr::Intrinsic::eLdexp2D:
		case ast::expr::Intrinsic::eLdexp3D:
		case ast::expr::Intrinsic::eLdexp4D:
			result = "ldexp";
			break;


	// Floating-point Pack and Unpack Functions
		case ast::expr::Intrinsic::ePackDouble2x32:
			result = "packDouble2x32";
			break;

		case ast::expr::Intrinsic::ePackHalf2x16:
			result = "packHalf2x16";
			break;

		case ast::expr::Intrinsic::ePackSnorm2x16:
			result = "packSnorm2x16";
			break;

		case ast::expr::Intrinsic::ePackSnorm4x8:
			result = "packSnorm4x8";
			break;

		case ast::expr::Intrinsic::ePackUnorm2x16:
			result = "packUnorm2x16";
			break;

		case ast::expr::Intrinsic::ePackUnorm4x8:
			result = "packUnorm4x8";
			break;

		case ast::expr::Intrinsic::eUnpackDouble2x32:
			result = "unpackDouble2x32";
			break;

		case ast::expr::Intrinsic::eUnpackHalf2x16:
			result = "unpackHalf2x16";
			break;

		case ast::expr::Intrinsic::eUnpackSnorm2x16:
			result = "unpackSnorm2x16";
			break;

		case ast::expr::Intrinsic::eUnpackSnorm4x8:
			result = "unpackSnorm4x8";
			break;

		case ast::expr::Intrinsic::eUnpackUnorm2x16:
			result = "unpackUnorm2x16";
			break;

		case ast::expr::Intrinsic::eUnpackUnorm4x8:
			result = "unpackUnorm4x8";
			break;


	// Geometric Functions
		case ast::expr::Intrinsic::eLength1F:
		case ast::expr::Intrinsic::eLength2F:
		case ast::expr::Intrinsic::eLength3F:
		case ast::expr::Intrinsic::eLength4F:
		case ast::expr::Intrinsic::eLength1D:
		case ast::expr::Intrinsic::eLength2D:
		case ast::expr::Intrinsic::eLength3D:
		case ast::expr::Intrinsic::eLength4D:
			result = "length";
			break;

		case ast::expr::Intrinsic::eDistance1F:
		case ast::expr::Intrinsic::eDistance2F:
		case ast::expr::Intrinsic::eDistance3F:
		case ast::expr::Intrinsic::eDistance4F:
		case ast::expr::Intrinsic::eDistance1D:
		case ast::expr::Intrinsic::eDistance2D:
		case ast::expr::Intrinsic::eDistance3D:
		case ast::expr::Intrinsic::eDistance4D:
			result = "distance";
			break;

		case ast::expr::Intrinsic::eDot1F:
		case ast::expr::Intrinsic::eDot2F:
		case ast::expr::Intrinsic::eDot3F:
		case ast::expr::Intrinsic::eDot4F:
		case ast::expr::Intrinsic::eDot1D:
		case ast::expr::Intrinsic::eDot2D:
		case ast::expr::Intrinsic::eDot3D:
		case ast::expr::Intrinsic::eDot4D:
			result = "dot";
			break;

		case ast::expr::Intrinsic::eCrossF:
		case ast::expr::Intrinsic::eCrossD:
			result = "cross";
			break;

		case ast::expr::Intrinsic::eNormalize1F:
		case ast::expr::Intrinsic::eNormalize2F:
		case ast::expr::Intrinsic::eNormalize3F:
		case ast::expr::Intrinsic::eNormalize4F:
		case ast::expr::Intrinsic::eNormalize1D:
		case ast::expr::Intrinsic::eNormalize2D:
		case ast::expr::Intrinsic::eNormalize3D:
		case ast::expr::Intrinsic::eNormalize4D:
			result = "normalize";
			break;

		case ast::expr::Intrinsic::eFaceForward1F:
		case ast::expr::Intrinsic::eFaceForward2F:
		case ast::expr::Intrinsic::eFaceForward3F:
		case ast::expr::Intrinsic::eFaceForward4F:
		case ast::expr::Intrinsic::eFaceForward1D:
		case ast::expr::Intrinsic::eFaceForward2D:
		case ast::expr::Intrinsic::eFaceForward3D:
		case ast::expr::Intrinsic::eFaceForward4D:
			result = "faceForward";
			break;

		case ast::expr::Intrinsic::eReflect1F:
		case ast::expr::Intrinsic::eReflect2F:
		case ast::expr::Intrinsic::eReflect3F:
		case ast::expr::Intrinsic::eReflect4F:
		case ast::expr::Intrinsic::eReflect1D:
		case ast::expr::Intrinsic::eReflect2D:
		case ast::expr::Intrinsic::eReflect3D:
		case ast::expr::Intrinsic::eReflect4D:
			result = "reflect";
			break;

		case ast::expr::Intrinsic::eRefract1F:
		case ast::expr::Intrinsic::eRefract2F:
		case ast::expr::Intrinsic::eRefract3F:
		case ast::expr::Intrinsic::eRefract4F:
		case ast::expr::Intrinsic::eRefract1D:
		case ast::expr::Intrinsic::eRefract2D:
		case ast::expr::Intrinsic::eRefract3D:
		case ast::expr::Intrinsic::eRefract4D:
			result = "refract";
			break;


	// Matrix Functions
		case ast::expr::Intrinsic::eMatrixCompMult2x2F:
		case ast::expr::Intrinsic::eMatrixCompMult2x3F:
		case ast::expr::Intrinsic::eMatrixCompMult2x4F:
		case ast::expr::Intrinsic::eMatrixCompMult3x2F:
		case ast::expr::Intrinsic::eMatrixCompMult3x3F:
		case ast::expr::Intrinsic::eMatrixCompMult3x4F:
		case ast::expr::Intrinsic::eMatrixCompMult4x2F:
		case ast::expr::Intrinsic::eMatrixCompMult4x3F:
		case ast::expr::Intrinsic::eMatrixCompMult4x4F:
		case ast::expr::Intrinsic::eMatrixCompMult2x2D:
		case ast::expr::Intrinsic::eMatrixCompMult2x3D:
		case ast::expr::Intrinsic::eMatrixCompMult2x4D:
		case ast::expr::Intrinsic::eMatrixCompMult3x2D:
		case ast::expr::Intrinsic::eMatrixCompMult3x3D:
		case ast::expr::Intrinsic::eMatrixCompMult3x4D:
		case ast::expr::Intrinsic::eMatrixCompMult4x2D:
		case ast::expr::Intrinsic::eMatrixCompMult4x3D:
		case ast::expr::Intrinsic::eMatrixCompMult4x4D:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eOuterProduct2x2F:
		case ast::expr::Intrinsic::eOuterProduct3x3F:
		case ast::expr::Intrinsic::eOuterProduct4x4F:
		case ast::expr::Intrinsic::eOuterProduct3x2F:
		case ast::expr::Intrinsic::eOuterProduct2x3F:
		case ast::expr::Intrinsic::eOuterProduct4x2F:
		case ast::expr::Intrinsic::eOuterProduct2x4F:
		case ast::expr::Intrinsic::eOuterProduct4x3F:
		case ast::expr::Intrinsic::eOuterProduct3x4F:
		case ast::expr::Intrinsic::eOuterProduct2x2D:
		case ast::expr::Intrinsic::eOuterProduct3x3D:
		case ast::expr::Intrinsic::eOuterProduct4x4D:
		case ast::expr::Intrinsic::eOuterProduct3x2D:
		case ast::expr::Intrinsic::eOuterProduct2x3D:
		case ast::expr::Intrinsic::eOuterProduct4x2D:
		case ast::expr::Intrinsic::eOuterProduct2x4D:
		case ast::expr::Intrinsic::eOuterProduct4x3D:
		case ast::expr::Intrinsic::eOuterProduct3x4D:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eTranspose2x2F:
		case ast::expr::Intrinsic::eTranspose2x3F:
		case ast::expr::Intrinsic::eTranspose2x4F:
		case ast::expr::Intrinsic::eTranspose3x2F:
		case ast::expr::Intrinsic::eTranspose3x3F:
		case ast::expr::Intrinsic::eTranspose3x4F:
		case ast::expr::Intrinsic::eTranspose4x2F:
		case ast::expr::Intrinsic::eTranspose4x3F:
		case ast::expr::Intrinsic::eTranspose4x4F:
		case ast::expr::Intrinsic::eTranspose2x2D:
		case ast::expr::Intrinsic::eTranspose2x3D:
		case ast::expr::Intrinsic::eTranspose2x4D:
		case ast::expr::Intrinsic::eTranspose3x2D:
		case ast::expr::Intrinsic::eTranspose3x3D:
		case ast::expr::Intrinsic::eTranspose3x4D:
		case ast::expr::Intrinsic::eTranspose4x2D:
		case ast::expr::Intrinsic::eTranspose4x3D:
		case ast::expr::Intrinsic::eTranspose4x4D:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eDeterminant2x2F:
		case ast::expr::Intrinsic::eDeterminant3x3F:
		case ast::expr::Intrinsic::eDeterminant4x4F:
		case ast::expr::Intrinsic::eDeterminant2x2D:
		case ast::expr::Intrinsic::eDeterminant3x3D:
		case ast::expr::Intrinsic::eDeterminant4x4D:
			result = "determinant";
			break;

		case ast::expr::Intrinsic::eInverse2x2F:
		case ast::expr::Intrinsic::eInverse3x3F:
		case ast::expr::Intrinsic::eInverse4x4F:
		case ast::expr::Intrinsic::eInverse2x2D:
		case ast::expr::Intrinsic::eInverse3x3D:
		case ast::expr::Intrinsic::eInverse4x4D:
			result = "inverse";
			break;


	// Vector Relational Functions
		case ast::expr::Intrinsic::eLessThan2F:
		case ast::expr::Intrinsic::eLessThan3F:
		case ast::expr::Intrinsic::eLessThan4F:
		case ast::expr::Intrinsic::eLessThan2D:
		case ast::expr::Intrinsic::eLessThan3D:
		case ast::expr::Intrinsic::eLessThan4D:
		case ast::expr::Intrinsic::eLessThan2I:
		case ast::expr::Intrinsic::eLessThan3I:
		case ast::expr::Intrinsic::eLessThan4I:
		case ast::expr::Intrinsic::eLessThan2U:
		case ast::expr::Intrinsic::eLessThan3U:
		case ast::expr::Intrinsic::eLessThan4U:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThanEqual2F:
		case ast::expr::Intrinsic::eLessThanEqual3F:
		case ast::expr::Intrinsic::eLessThanEqual4F:
		case ast::expr::Intrinsic::eLessThanEqual2D:
		case ast::expr::Intrinsic::eLessThanEqual3D:
		case ast::expr::Intrinsic::eLessThanEqual4D:
		case ast::expr::Intrinsic::eLessThanEqual2I:
		case ast::expr::Intrinsic::eLessThanEqual3I:
		case ast::expr::Intrinsic::eLessThanEqual4I:
		case ast::expr::Intrinsic::eLessThanEqual2U:
		case ast::expr::Intrinsic::eLessThanEqual3U:
		case ast::expr::Intrinsic::eLessThanEqual4U:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThan2F:
		case ast::expr::Intrinsic::eGreaterThan3F:
		case ast::expr::Intrinsic::eGreaterThan4F:
		case ast::expr::Intrinsic::eGreaterThan2D:
		case ast::expr::Intrinsic::eGreaterThan3D:
		case ast::expr::Intrinsic::eGreaterThan4D:
		case ast::expr::Intrinsic::eGreaterThan2I:
		case ast::expr::Intrinsic::eGreaterThan3I:
		case ast::expr::Intrinsic::eGreaterThan4I:
		case ast::expr::Intrinsic::eGreaterThan2U:
		case ast::expr::Intrinsic::eGreaterThan3U:
		case ast::expr::Intrinsic::eGreaterThan4U:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual2F:
		case ast::expr::Intrinsic::eGreaterThanEqual3F:
		case ast::expr::Intrinsic::eGreaterThanEqual4F:
		case ast::expr::Intrinsic::eGreaterThanEqual2D:
		case ast::expr::Intrinsic::eGreaterThanEqual3D:
		case ast::expr::Intrinsic::eGreaterThanEqual4D:
		case ast::expr::Intrinsic::eGreaterThanEqual2I:
		case ast::expr::Intrinsic::eGreaterThanEqual3I:
		case ast::expr::Intrinsic::eGreaterThanEqual4I:
		case ast::expr::Intrinsic::eGreaterThanEqual2U:
		case ast::expr::Intrinsic::eGreaterThanEqual3U:
		case ast::expr::Intrinsic::eGreaterThanEqual4U:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eEqual2F:
		case ast::expr::Intrinsic::eEqual3F:
		case ast::expr::Intrinsic::eEqual4F:
		case ast::expr::Intrinsic::eEqual2D:
		case ast::expr::Intrinsic::eEqual3D:
		case ast::expr::Intrinsic::eEqual4D:
		case ast::expr::Intrinsic::eEqual2I:
		case ast::expr::Intrinsic::eEqual3I:
		case ast::expr::Intrinsic::eEqual4I:
		case ast::expr::Intrinsic::eEqual2U:
		case ast::expr::Intrinsic::eEqual3U:
		case ast::expr::Intrinsic::eEqual4U:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eNotEqual2F:
		case ast::expr::Intrinsic::eNotEqual3F:
		case ast::expr::Intrinsic::eNotEqual4F:
		case ast::expr::Intrinsic::eNotEqual2D:
		case ast::expr::Intrinsic::eNotEqual3D:
		case ast::expr::Intrinsic::eNotEqual4D:
		case ast::expr::Intrinsic::eNotEqual2I:
		case ast::expr::Intrinsic::eNotEqual3I:
		case ast::expr::Intrinsic::eNotEqual4I:
		case ast::expr::Intrinsic::eNotEqual2U:
		case ast::expr::Intrinsic::eNotEqual3U:
		case ast::expr::Intrinsic::eNotEqual4U:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eAll2:
		case ast::expr::Intrinsic::eAll3:
		case ast::expr::Intrinsic::eAll4:
			result = "all";
			break;

		case ast::expr::Intrinsic::eAny2:
		case ast::expr::Intrinsic::eAny3:
		case ast::expr::Intrinsic::eAny4:
			result = "any";
			break;

		case ast::expr::Intrinsic::eNot2:
		case ast::expr::Intrinsic::eNot3:
		case ast::expr::Intrinsic::eNot4:
			result = "not";
			break;


	// Integer Functions
		case ast::expr::Intrinsic::eUaddCarry1:
		case ast::expr::Intrinsic::eUaddCarry2:
		case ast::expr::Intrinsic::eUaddCarry3:
		case ast::expr::Intrinsic::eUaddCarry4:
			result = "uaddCarry";
			break;

		case ast::expr::Intrinsic::eUsubBorrow1:
		case ast::expr::Intrinsic::eUsubBorrow2:
		case ast::expr::Intrinsic::eUsubBorrow3:
		case ast::expr::Intrinsic::eUsubBorrow4:
			result = "usubBorrow";
			break;

		case ast::expr::Intrinsic::eUmulExtended1:
		case ast::expr::Intrinsic::eUmulExtended2:
		case ast::expr::Intrinsic::eUmulExtended3:
		case ast::expr::Intrinsic::eUmulExtended4:
			result = "umulExtended";
			break;

		case ast::expr::Intrinsic::eImulExtended1:
		case ast::expr::Intrinsic::eImulExtended2:
		case ast::expr::Intrinsic::eImulExtended3:
		case ast::expr::Intrinsic::eImulExtended4:
			result = "imulExtended";
			break;

		case ast::expr::Intrinsic::eBitfieldExtract1I:
		case ast::expr::Intrinsic::eBitfieldExtract2I:
		case ast::expr::Intrinsic::eBitfieldExtract3I:
		case ast::expr::Intrinsic::eBitfieldExtract4I:
		case ast::expr::Intrinsic::eBitfieldExtract1U:
		case ast::expr::Intrinsic::eBitfieldExtract2U:
		case ast::expr::Intrinsic::eBitfieldExtract3U:
		case ast::expr::Intrinsic::eBitfieldExtract4U:
			result = "bitfieldExtract";
			break;

		case ast::expr::Intrinsic::eBitfieldInsert1I:
		case ast::expr::Intrinsic::eBitfieldInsert2I:
		case ast::expr::Intrinsic::eBitfieldInsert3I:
		case ast::expr::Intrinsic::eBitfieldInsert4I:
		case ast::expr::Intrinsic::eBitfieldInsert1U:
		case ast::expr::Intrinsic::eBitfieldInsert2U:
		case ast::expr::Intrinsic::eBitfieldInsert3U:
		case ast::expr::Intrinsic::eBitfieldInsert4U:
			result = "bitfieldInsert";
			break;

		case ast::expr::Intrinsic::eBitfieldReverse1I:
		case ast::expr::Intrinsic::eBitfieldReverse2I:
		case ast::expr::Intrinsic::eBitfieldReverse3I:
		case ast::expr::Intrinsic::eBitfieldReverse4I:
		case ast::expr::Intrinsic::eBitfieldReverse1U:
		case ast::expr::Intrinsic::eBitfieldReverse2U:
		case ast::expr::Intrinsic::eBitfieldReverse3U:
		case ast::expr::Intrinsic::eBitfieldReverse4U:
			result = "bitfieldReverse";
			break;

		case ast::expr::Intrinsic::eBitCount1I:
		case ast::expr::Intrinsic::eBitCount2I:
		case ast::expr::Intrinsic::eBitCount3I:
		case ast::expr::Intrinsic::eBitCount4I:
		case ast::expr::Intrinsic::eBitCount1U:
		case ast::expr::Intrinsic::eBitCount2U:
		case ast::expr::Intrinsic::eBitCount3U:
		case ast::expr::Intrinsic::eBitCount4U:
			result = "bitCount";
			break;

		case ast::expr::Intrinsic::eFindLSB1I:
		case ast::expr::Intrinsic::eFindLSB2I:
		case ast::expr::Intrinsic::eFindLSB3I:
		case ast::expr::Intrinsic::eFindLSB4I:
		case ast::expr::Intrinsic::eFindLSB1U:
		case ast::expr::Intrinsic::eFindLSB2U:
		case ast::expr::Intrinsic::eFindLSB3U:
		case ast::expr::Intrinsic::eFindLSB4U:
			result = "findLSB";
			break;

		case ast::expr::Intrinsic::eFindMSB1I:
		case ast::expr::Intrinsic::eFindMSB2I:
		case ast::expr::Intrinsic::eFindMSB3I:
		case ast::expr::Intrinsic::eFindMSB4I:
		case ast::expr::Intrinsic::eFindMSB1U:
		case ast::expr::Intrinsic::eFindMSB2U:
		case ast::expr::Intrinsic::eFindMSB3U:
		case ast::expr::Intrinsic::eFindMSB4U:
			result = "findMSB";
			break;


	// Atomic Memory Functions
		case ast::expr::Intrinsic::eAtomicAddI:
		case ast::expr::Intrinsic::eAtomicAddU:
			result = "atomicAdd";
			break;

		case ast::expr::Intrinsic::eAtomicMinI:
		case ast::expr::Intrinsic::eAtomicMinU:
			result = "atomicMin";
			break;

		case ast::expr::Intrinsic::eAtomicMaxI:
		case ast::expr::Intrinsic::eAtomicMaxU:
			result = "atomicMax";
			break;

		case ast::expr::Intrinsic::eAtomicAndI:
		case ast::expr::Intrinsic::eAtomicAndU:
			result = "atomicAnd";
			break;

		case ast::expr::Intrinsic::eAtomicOrI:
		case ast::expr::Intrinsic::eAtomicOrU:
			result = "atomicOr";
			break;

		case ast::expr::Intrinsic::eAtomicXorI:
		case ast::expr::Intrinsic::eAtomicXorU:
			result = "atomicXor";
			break;

		case ast::expr::Intrinsic::eAtomicExchangeI:
		case ast::expr::Intrinsic::eAtomicExchangeU:
			result = "atomicExchange";
			break;

		case ast::expr::Intrinsic::eAtomicCompSwapI:
		case ast::expr::Intrinsic::eAtomicCompSwapU:
			result = "atomicCompSwap";
			break;


	// Derivative Functions
		case ast::expr::Intrinsic::eDFdx1:
		case ast::expr::Intrinsic::eDFdx2:
		case ast::expr::Intrinsic::eDFdx3:
		case ast::expr::Intrinsic::eDFdx4:
			result = "dFdx";
			break;

		case ast::expr::Intrinsic::eDFdxCoarse1:
		case ast::expr::Intrinsic::eDFdxCoarse2:
		case ast::expr::Intrinsic::eDFdxCoarse3:
		case ast::expr::Intrinsic::eDFdxCoarse4:
			result = "dFdxCoarse";
			break;

		case ast::expr::Intrinsic::eDFdxFine1:
		case ast::expr::Intrinsic::eDFdxFine2:
		case ast::expr::Intrinsic::eDFdxFine3:
		case ast::expr::Intrinsic::eDFdxFine4:
			result = "dFdxFine";
			break;

		case ast::expr::Intrinsic::eDFdy1:
		case ast::expr::Intrinsic::eDFdy2:
		case ast::expr::Intrinsic::eDFdy3:
		case ast::expr::Intrinsic::eDFdy4:
			result = "dFdy";
			break;

		case ast::expr::Intrinsic::eDFdyCoarse1:
		case ast::expr::Intrinsic::eDFdyCoarse2:
		case ast::expr::Intrinsic::eDFdyCoarse3:
		case ast::expr::Intrinsic::eDFdyCoarse4:
			result = "dFdyCoarse";
			break;

		case ast::expr::Intrinsic::eDFdyFine1:
		case ast::expr::Intrinsic::eDFdyFine2:
		case ast::expr::Intrinsic::eDFdyFine3:
		case ast::expr::Intrinsic::eDFdyFine4:
			result = "dFdyFine";
			break;

		case ast::expr::Intrinsic::eFwidth1:
		case ast::expr::Intrinsic::eFwidth2:
		case ast::expr::Intrinsic::eFwidth3:
		case ast::expr::Intrinsic::eFwidth4:
			result = "fwidth";
			break;


	// Interpolation Functions
		case ast::expr::Intrinsic::eInterpolateAtCentroid1:
		case ast::expr::Intrinsic::eInterpolateAtCentroid2:
		case ast::expr::Intrinsic::eInterpolateAtCentroid3:
		case ast::expr::Intrinsic::eInterpolateAtCentroid4:
			result = "interpolateAtCentroid";
			break;

		case ast::expr::Intrinsic::eInterpolateAtSample1:
		case ast::expr::Intrinsic::eInterpolateAtSample2:
		case ast::expr::Intrinsic::eInterpolateAtSample3:
		case ast::expr::Intrinsic::eInterpolateAtSample4:
			result = "interpolateAtSample";
			break;

		case ast::expr::Intrinsic::eInterpolateAtOffset1:
		case ast::expr::Intrinsic::eInterpolateAtOffset2:
		case ast::expr::Intrinsic::eInterpolateAtOffset3:
		case ast::expr::Intrinsic::eInterpolateAtOffset4:
			result = "interpolateAtOffset";
			break;


	// Geometry Shader Functions
		case ast::expr::Intrinsic::eEmitStreamVertex:
			result = "EmitStreamVertex";
			break;

		case ast::expr::Intrinsic::eEndStreamPrimitive:
			result = "EndStreamPrimitive";
			break;

		case ast::expr::Intrinsic::eEmitVertex:
			result = "EmitVertex";
			break;

		case ast::expr::Intrinsic::eEndPrimitive:
			result = "EndPrimitive";
			break;


	// Shader Invocation Control Functions
		case ast::expr::Intrinsic::eBarrier:
			result = "barrier";
			break;


	// Shader Memory Control Functions
		case ast::expr::Intrinsic::eMemoryBarrier:
			result = "memoryBarrier";
			break;

		case ast::expr::Intrinsic::eMemoryBarrierBuffer:
			result = "memoryBarrierBuffer";
			break;

		case ast::expr::Intrinsic::eMemoryBarrierShared:
			result = "memoryBarrierShared";
			break;

		case ast::expr::Intrinsic::eMemoryBarrierImage:
			result = "memoryBarrierImage";
			break;

		case ast::expr::Intrinsic::eGroupMemoryBarrier:
			result = "groupMemoryBarrier";
			break;

		default:
			throw std::runtime_error{ "Unsupported Intrinsic type." };
		}

		return result;
	}
}

#endif
