/*
See LICENSE file in root folder
*/
#ifndef ___AST_GlslIntrinsicNames_H___
#define ___AST_GlslIntrinsicNames_H___
#pragma once

#include <ShaderAST/Expr/EnumIntrinsic.hpp>

#include <stdexcept>
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
		case ast::expr::Intrinsic::eAtan21:
		case ast::expr::Intrinsic::eAtan22:
		case ast::expr::Intrinsic::eAtan23:
		case ast::expr::Intrinsic::eAtan24:
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
			result = "inversesqrt";
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

		case ast::expr::Intrinsic::eMod1F:
		case ast::expr::Intrinsic::eMod2F:
		case ast::expr::Intrinsic::eMod3F:
		case ast::expr::Intrinsic::eMod4F:
		case ast::expr::Intrinsic::eMod1D:
		case ast::expr::Intrinsic::eMod2D:
		case ast::expr::Intrinsic::eMod3D:
		case ast::expr::Intrinsic::eMod4D:
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

		case ast::expr::Intrinsic::eMin1F:
		case ast::expr::Intrinsic::eMin2F:
		case ast::expr::Intrinsic::eMin3F:
		case ast::expr::Intrinsic::eMin4F:
		case ast::expr::Intrinsic::eMin1D:
		case ast::expr::Intrinsic::eMin2D:
		case ast::expr::Intrinsic::eMin3D:
		case ast::expr::Intrinsic::eMin4D:
		case ast::expr::Intrinsic::eMin1I:
		case ast::expr::Intrinsic::eMin2I:
		case ast::expr::Intrinsic::eMin3I:
		case ast::expr::Intrinsic::eMin4I:
		case ast::expr::Intrinsic::eMin1U:
		case ast::expr::Intrinsic::eMin2U:
		case ast::expr::Intrinsic::eMin3U:
		case ast::expr::Intrinsic::eMin4U:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMax1F:
		case ast::expr::Intrinsic::eMax2F:
		case ast::expr::Intrinsic::eMax3F:
		case ast::expr::Intrinsic::eMax4F:
		case ast::expr::Intrinsic::eMax1D:
		case ast::expr::Intrinsic::eMax2D:
		case ast::expr::Intrinsic::eMax3D:
		case ast::expr::Intrinsic::eMax4D:
		case ast::expr::Intrinsic::eMax1I:
		case ast::expr::Intrinsic::eMax2I:
		case ast::expr::Intrinsic::eMax3I:
		case ast::expr::Intrinsic::eMax4I:
		case ast::expr::Intrinsic::eMax1U:
		case ast::expr::Intrinsic::eMax2U:
		case ast::expr::Intrinsic::eMax3U:
		case ast::expr::Intrinsic::eMax4U:
			result = "max";
			break;

		case ast::expr::Intrinsic::eClamp1F:
		case ast::expr::Intrinsic::eClamp2F:
		case ast::expr::Intrinsic::eClamp3F:
		case ast::expr::Intrinsic::eClamp4F:
		case ast::expr::Intrinsic::eClamp1D:
		case ast::expr::Intrinsic::eClamp2D:
		case ast::expr::Intrinsic::eClamp3D:
		case ast::expr::Intrinsic::eClamp4D:
		case ast::expr::Intrinsic::eClamp1I:
		case ast::expr::Intrinsic::eClamp2I:
		case ast::expr::Intrinsic::eClamp3I:
		case ast::expr::Intrinsic::eClamp4I:
		case ast::expr::Intrinsic::eClamp1U:
		case ast::expr::Intrinsic::eClamp2U:
		case ast::expr::Intrinsic::eClamp3U:
		case ast::expr::Intrinsic::eClamp4U:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eMix1F:
		case ast::expr::Intrinsic::eMix2F:
		case ast::expr::Intrinsic::eMix3F:
		case ast::expr::Intrinsic::eMix4F:
		case ast::expr::Intrinsic::eMix1D:
		case ast::expr::Intrinsic::eMix2D:
		case ast::expr::Intrinsic::eMix3D:
		case ast::expr::Intrinsic::eMix4D:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eStep1F:
		case ast::expr::Intrinsic::eStep2F:
		case ast::expr::Intrinsic::eStep3F:
		case ast::expr::Intrinsic::eStep4F:
		case ast::expr::Intrinsic::eStep1D:
		case ast::expr::Intrinsic::eStep2D:
		case ast::expr::Intrinsic::eStep3D:
		case ast::expr::Intrinsic::eStep4D:
			result = "step";
			break;

		case ast::expr::Intrinsic::eSmoothStep1F:
		case ast::expr::Intrinsic::eSmoothStep2F:
		case ast::expr::Intrinsic::eSmoothStep3F:
		case ast::expr::Intrinsic::eSmoothStep4F:
		case ast::expr::Intrinsic::eSmoothStep1D:
		case ast::expr::Intrinsic::eSmoothStep2D:
		case ast::expr::Intrinsic::eSmoothStep3D:
		case ast::expr::Intrinsic::eSmoothStep4D:
			result = "smoothstep";
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
			result = "floatBitsToUint";
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
			result = "faceforward";
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
		case ast::expr::Intrinsic::eAtomicAddF:
		case ast::expr::Intrinsic::eAtomicAdd2H:
		case ast::expr::Intrinsic::eAtomicAdd4H:
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
		case ast::expr::Intrinsic::eAtomicExchangeF:
		case ast::expr::Intrinsic::eAtomicExchange2H:
		case ast::expr::Intrinsic::eAtomicExchange4H:
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


	// Miscellaneous Functions
		case ast::expr::Intrinsic::eHelperInvocation:
			result = "helperInvocationEXT";
			break;

		case ast::expr::Intrinsic::eTraceRay:
			result = "traceRayEXT";
			break;

		case ast::expr::Intrinsic::eReportIntersection:
			result = "reportIntersectionEXT";
			break;

		case ast::expr::Intrinsic::eExecuteCallable:
			result = "executeCallableEXT";
			break;


	//Mesh Shader Functions
		case ast::expr::Intrinsic::eWritePackedPrimitiveIndices4x8NV:
			result = "writePackedPrimitiveIndices4x8NV";
			break;

		case ast::expr::Intrinsic::eSetMeshOutputCounts:
			result = "SetMeshOutputsEXT";
			break;


	//Shader Subgroup Functions
		case ast::expr::Intrinsic::eSubgroupElect:
			result = "subgroupElect";
			break;

		case ast::expr::Intrinsic::eSubgroupAll:
			result = "subgroupAll";
			break;

		case ast::expr::Intrinsic::eSubgroupAny:
			result = "subgroupAny";
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual1F:
		case ast::expr::Intrinsic::eSubgroupAllEqual2F:
		case ast::expr::Intrinsic::eSubgroupAllEqual3F:
		case ast::expr::Intrinsic::eSubgroupAllEqual4F:
		case ast::expr::Intrinsic::eSubgroupAllEqual1I:
		case ast::expr::Intrinsic::eSubgroupAllEqual2I:
		case ast::expr::Intrinsic::eSubgroupAllEqual3I:
		case ast::expr::Intrinsic::eSubgroupAllEqual4I:
		case ast::expr::Intrinsic::eSubgroupAllEqual1U:
		case ast::expr::Intrinsic::eSubgroupAllEqual2U:
		case ast::expr::Intrinsic::eSubgroupAllEqual3U:
		case ast::expr::Intrinsic::eSubgroupAllEqual4U:
		case ast::expr::Intrinsic::eSubgroupAllEqual1B:
		case ast::expr::Intrinsic::eSubgroupAllEqual2B:
		case ast::expr::Intrinsic::eSubgroupAllEqual3B:
		case ast::expr::Intrinsic::eSubgroupAllEqual4B:
		case ast::expr::Intrinsic::eSubgroupAllEqual1D:
		case ast::expr::Intrinsic::eSubgroupAllEqual2D:
		case ast::expr::Intrinsic::eSubgroupAllEqual3D:
		case ast::expr::Intrinsic::eSubgroupAllEqual4D:
			result = "subgroupAllEqual";
			break;

		case ast::expr::Intrinsic::eSubgroupBroadcast1F:
		case ast::expr::Intrinsic::eSubgroupBroadcast2F:
		case ast::expr::Intrinsic::eSubgroupBroadcast3F:
		case ast::expr::Intrinsic::eSubgroupBroadcast4F:
		case ast::expr::Intrinsic::eSubgroupBroadcast1I:
		case ast::expr::Intrinsic::eSubgroupBroadcast2I:
		case ast::expr::Intrinsic::eSubgroupBroadcast3I:
		case ast::expr::Intrinsic::eSubgroupBroadcast4I:
		case ast::expr::Intrinsic::eSubgroupBroadcast1U:
		case ast::expr::Intrinsic::eSubgroupBroadcast2U:
		case ast::expr::Intrinsic::eSubgroupBroadcast3U:
		case ast::expr::Intrinsic::eSubgroupBroadcast4U:
		case ast::expr::Intrinsic::eSubgroupBroadcast1B:
		case ast::expr::Intrinsic::eSubgroupBroadcast2B:
		case ast::expr::Intrinsic::eSubgroupBroadcast3B:
		case ast::expr::Intrinsic::eSubgroupBroadcast4B:
		case ast::expr::Intrinsic::eSubgroupBroadcast1D:
		case ast::expr::Intrinsic::eSubgroupBroadcast2D:
		case ast::expr::Intrinsic::eSubgroupBroadcast3D:
		case ast::expr::Intrinsic::eSubgroupBroadcast4D:
			result = "subgroupBroadcast";
			break;

		case ast::expr::Intrinsic::eSubgroupBroadcastFirst1F:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst2F:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst3F:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst4F:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst1I:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst2I:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst3I:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst4I:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst1U:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst2U:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst3U:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst4U:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst1B:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst2B:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst3B:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst4B:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst1D:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst2D:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst3D:
		case ast::expr::Intrinsic::eSubgroupBroadcastFirst4D:
			result = "subgroupBroadcastFirst";
			break;

		case ast::expr::Intrinsic::eSubgroupBallot:
			result = "subgroupBallot";
			break;

		case ast::expr::Intrinsic::eSubgroupInverseBallot:
			result = "subgroupInverseBallot";
			break;

		case ast::expr::Intrinsic::eSubgroupBallotBitExtract:
			result = "subgroupBallotBitExtract";
			break;

		case ast::expr::Intrinsic::eSubgroupBallotBitCount:
			result = "subgroupBallotBitCount";
			break;

		case ast::expr::Intrinsic::eSubgroupBallotInclusiveBitCount:
			result = "subgroupBallotInclusiveBitCount";
			break;

		case ast::expr::Intrinsic::eSubgroupBallotExclusiveBitCount:
			result = "subgroupBallotExclusiveBitCount";
			break;

		case ast::expr::Intrinsic::eSubgroupBallotFindLSB:
			result = "subgroupBallotFindLSB";
			break;

		case ast::expr::Intrinsic::eSubgroupBallotFindMSB:
			result = "subgroupBallotFindMSB";
			break;

		case ast::expr::Intrinsic::eSubgroupShuffle1F:
		case ast::expr::Intrinsic::eSubgroupShuffle2F:
		case ast::expr::Intrinsic::eSubgroupShuffle3F:
		case ast::expr::Intrinsic::eSubgroupShuffle4F:
		case ast::expr::Intrinsic::eSubgroupShuffle1I:
		case ast::expr::Intrinsic::eSubgroupShuffle2I:
		case ast::expr::Intrinsic::eSubgroupShuffle3I:
		case ast::expr::Intrinsic::eSubgroupShuffle4I:
		case ast::expr::Intrinsic::eSubgroupShuffle1U:
		case ast::expr::Intrinsic::eSubgroupShuffle2U:
		case ast::expr::Intrinsic::eSubgroupShuffle3U:
		case ast::expr::Intrinsic::eSubgroupShuffle4U:
		case ast::expr::Intrinsic::eSubgroupShuffle1B:
		case ast::expr::Intrinsic::eSubgroupShuffle2B:
		case ast::expr::Intrinsic::eSubgroupShuffle3B:
		case ast::expr::Intrinsic::eSubgroupShuffle4B:
		case ast::expr::Intrinsic::eSubgroupShuffle1D:
		case ast::expr::Intrinsic::eSubgroupShuffle2D:
		case ast::expr::Intrinsic::eSubgroupShuffle3D:
		case ast::expr::Intrinsic::eSubgroupShuffle4D:
			result = "subgroupShuffle";
			break;

		case ast::expr::Intrinsic::eSubgroupShuffleXor1F:
		case ast::expr::Intrinsic::eSubgroupShuffleXor2F:
		case ast::expr::Intrinsic::eSubgroupShuffleXor3F:
		case ast::expr::Intrinsic::eSubgroupShuffleXor4F:
		case ast::expr::Intrinsic::eSubgroupShuffleXor1I:
		case ast::expr::Intrinsic::eSubgroupShuffleXor2I:
		case ast::expr::Intrinsic::eSubgroupShuffleXor3I:
		case ast::expr::Intrinsic::eSubgroupShuffleXor4I:
		case ast::expr::Intrinsic::eSubgroupShuffleXor1U:
		case ast::expr::Intrinsic::eSubgroupShuffleXor2U:
		case ast::expr::Intrinsic::eSubgroupShuffleXor3U:
		case ast::expr::Intrinsic::eSubgroupShuffleXor4U:
		case ast::expr::Intrinsic::eSubgroupShuffleXor1B:
		case ast::expr::Intrinsic::eSubgroupShuffleXor2B:
		case ast::expr::Intrinsic::eSubgroupShuffleXor3B:
		case ast::expr::Intrinsic::eSubgroupShuffleXor4B:
		case ast::expr::Intrinsic::eSubgroupShuffleXor1D:
		case ast::expr::Intrinsic::eSubgroupShuffleXor2D:
		case ast::expr::Intrinsic::eSubgroupShuffleXor3D:
		case ast::expr::Intrinsic::eSubgroupShuffleXor4D:
			result = "subgroupShuffleXor";
			break;

		case ast::expr::Intrinsic::eSubgroupShuffleUp1F:
		case ast::expr::Intrinsic::eSubgroupShuffleUp2F:
		case ast::expr::Intrinsic::eSubgroupShuffleUp3F:
		case ast::expr::Intrinsic::eSubgroupShuffleUp4F:
		case ast::expr::Intrinsic::eSubgroupShuffleUp1I:
		case ast::expr::Intrinsic::eSubgroupShuffleUp2I:
		case ast::expr::Intrinsic::eSubgroupShuffleUp3I:
		case ast::expr::Intrinsic::eSubgroupShuffleUp4I:
		case ast::expr::Intrinsic::eSubgroupShuffleUp1U:
		case ast::expr::Intrinsic::eSubgroupShuffleUp2U:
		case ast::expr::Intrinsic::eSubgroupShuffleUp3U:
		case ast::expr::Intrinsic::eSubgroupShuffleUp4U:
		case ast::expr::Intrinsic::eSubgroupShuffleUp1B:
		case ast::expr::Intrinsic::eSubgroupShuffleUp2B:
		case ast::expr::Intrinsic::eSubgroupShuffleUp3B:
		case ast::expr::Intrinsic::eSubgroupShuffleUp4B:
		case ast::expr::Intrinsic::eSubgroupShuffleUp1D:
		case ast::expr::Intrinsic::eSubgroupShuffleUp2D:
		case ast::expr::Intrinsic::eSubgroupShuffleUp3D:
		case ast::expr::Intrinsic::eSubgroupShuffleUp4D:
			result = "subgroupShuffleUp";
			break;

		case ast::expr::Intrinsic::eSubgroupShuffleDown1F:
		case ast::expr::Intrinsic::eSubgroupShuffleDown2F:
		case ast::expr::Intrinsic::eSubgroupShuffleDown3F:
		case ast::expr::Intrinsic::eSubgroupShuffleDown4F:
		case ast::expr::Intrinsic::eSubgroupShuffleDown1I:
		case ast::expr::Intrinsic::eSubgroupShuffleDown2I:
		case ast::expr::Intrinsic::eSubgroupShuffleDown3I:
		case ast::expr::Intrinsic::eSubgroupShuffleDown4I:
		case ast::expr::Intrinsic::eSubgroupShuffleDown1U:
		case ast::expr::Intrinsic::eSubgroupShuffleDown2U:
		case ast::expr::Intrinsic::eSubgroupShuffleDown3U:
		case ast::expr::Intrinsic::eSubgroupShuffleDown4U:
		case ast::expr::Intrinsic::eSubgroupShuffleDown1B:
		case ast::expr::Intrinsic::eSubgroupShuffleDown2B:
		case ast::expr::Intrinsic::eSubgroupShuffleDown3B:
		case ast::expr::Intrinsic::eSubgroupShuffleDown4B:
		case ast::expr::Intrinsic::eSubgroupShuffleDown1D:
		case ast::expr::Intrinsic::eSubgroupShuffleDown2D:
		case ast::expr::Intrinsic::eSubgroupShuffleDown3D:
		case ast::expr::Intrinsic::eSubgroupShuffleDown4D:
			result = "subgroupShuffleDown";
			break;

		case ast::expr::Intrinsic::eSubgroupAdd1F:
		case ast::expr::Intrinsic::eSubgroupAdd2F:
		case ast::expr::Intrinsic::eSubgroupAdd3F:
		case ast::expr::Intrinsic::eSubgroupAdd4F:
		case ast::expr::Intrinsic::eSubgroupAdd1I:
		case ast::expr::Intrinsic::eSubgroupAdd2I:
		case ast::expr::Intrinsic::eSubgroupAdd3I:
		case ast::expr::Intrinsic::eSubgroupAdd4I:
		case ast::expr::Intrinsic::eSubgroupAdd1U:
		case ast::expr::Intrinsic::eSubgroupAdd2U:
		case ast::expr::Intrinsic::eSubgroupAdd3U:
		case ast::expr::Intrinsic::eSubgroupAdd4U:
		case ast::expr::Intrinsic::eSubgroupAdd1D:
		case ast::expr::Intrinsic::eSubgroupAdd2D:
		case ast::expr::Intrinsic::eSubgroupAdd3D:
		case ast::expr::Intrinsic::eSubgroupAdd4D:
			result = "subgroupAdd";
			break;

		case ast::expr::Intrinsic::eSubgroupMul1F:
		case ast::expr::Intrinsic::eSubgroupMul2F:
		case ast::expr::Intrinsic::eSubgroupMul3F:
		case ast::expr::Intrinsic::eSubgroupMul4F:
		case ast::expr::Intrinsic::eSubgroupMul1I:
		case ast::expr::Intrinsic::eSubgroupMul2I:
		case ast::expr::Intrinsic::eSubgroupMul3I:
		case ast::expr::Intrinsic::eSubgroupMul4I:
		case ast::expr::Intrinsic::eSubgroupMul1U:
		case ast::expr::Intrinsic::eSubgroupMul2U:
		case ast::expr::Intrinsic::eSubgroupMul3U:
		case ast::expr::Intrinsic::eSubgroupMul4U:
		case ast::expr::Intrinsic::eSubgroupMul1D:
		case ast::expr::Intrinsic::eSubgroupMul2D:
		case ast::expr::Intrinsic::eSubgroupMul3D:
		case ast::expr::Intrinsic::eSubgroupMul4D:
			result = "subgroupMul";
			break;

		case ast::expr::Intrinsic::eSubgroupMin1F:
		case ast::expr::Intrinsic::eSubgroupMin2F:
		case ast::expr::Intrinsic::eSubgroupMin3F:
		case ast::expr::Intrinsic::eSubgroupMin4F:
		case ast::expr::Intrinsic::eSubgroupMin1I:
		case ast::expr::Intrinsic::eSubgroupMin2I:
		case ast::expr::Intrinsic::eSubgroupMin3I:
		case ast::expr::Intrinsic::eSubgroupMin4I:
		case ast::expr::Intrinsic::eSubgroupMin1U:
		case ast::expr::Intrinsic::eSubgroupMin2U:
		case ast::expr::Intrinsic::eSubgroupMin3U:
		case ast::expr::Intrinsic::eSubgroupMin4U:
		case ast::expr::Intrinsic::eSubgroupMin1D:
		case ast::expr::Intrinsic::eSubgroupMin2D:
		case ast::expr::Intrinsic::eSubgroupMin3D:
		case ast::expr::Intrinsic::eSubgroupMin4D:
			result = "subgroupMin";
			break;

		case ast::expr::Intrinsic::eSubgroupMax1F:
		case ast::expr::Intrinsic::eSubgroupMax2F:
		case ast::expr::Intrinsic::eSubgroupMax3F:
		case ast::expr::Intrinsic::eSubgroupMax4F:
		case ast::expr::Intrinsic::eSubgroupMax1I:
		case ast::expr::Intrinsic::eSubgroupMax2I:
		case ast::expr::Intrinsic::eSubgroupMax3I:
		case ast::expr::Intrinsic::eSubgroupMax4I:
		case ast::expr::Intrinsic::eSubgroupMax1U:
		case ast::expr::Intrinsic::eSubgroupMax2U:
		case ast::expr::Intrinsic::eSubgroupMax3U:
		case ast::expr::Intrinsic::eSubgroupMax4U:
		case ast::expr::Intrinsic::eSubgroupMax1D:
		case ast::expr::Intrinsic::eSubgroupMax2D:
		case ast::expr::Intrinsic::eSubgroupMax3D:
		case ast::expr::Intrinsic::eSubgroupMax4D:
			result = "subgroupMax";
			break;

		case ast::expr::Intrinsic::eSubgroupAnd1I:
		case ast::expr::Intrinsic::eSubgroupAnd2I:
		case ast::expr::Intrinsic::eSubgroupAnd3I:
		case ast::expr::Intrinsic::eSubgroupAnd4I:
		case ast::expr::Intrinsic::eSubgroupAnd1U:
		case ast::expr::Intrinsic::eSubgroupAnd2U:
		case ast::expr::Intrinsic::eSubgroupAnd3U:
		case ast::expr::Intrinsic::eSubgroupAnd4U:
		case ast::expr::Intrinsic::eSubgroupAnd1B:
		case ast::expr::Intrinsic::eSubgroupAnd2B:
		case ast::expr::Intrinsic::eSubgroupAnd3B:
		case ast::expr::Intrinsic::eSubgroupAnd4B:
			result = "subgroupAnd";
			break;

		case ast::expr::Intrinsic::eSubgroupOr1I:
		case ast::expr::Intrinsic::eSubgroupOr2I:
		case ast::expr::Intrinsic::eSubgroupOr3I:
		case ast::expr::Intrinsic::eSubgroupOr4I:
		case ast::expr::Intrinsic::eSubgroupOr1U:
		case ast::expr::Intrinsic::eSubgroupOr2U:
		case ast::expr::Intrinsic::eSubgroupOr3U:
		case ast::expr::Intrinsic::eSubgroupOr4U:
		case ast::expr::Intrinsic::eSubgroupOr1B:
		case ast::expr::Intrinsic::eSubgroupOr2B:
		case ast::expr::Intrinsic::eSubgroupOr3B:
		case ast::expr::Intrinsic::eSubgroupOr4B:
			result = "subgroupOr";
			break;

		case ast::expr::Intrinsic::eSubgroupXor1I:
		case ast::expr::Intrinsic::eSubgroupXor2I:
		case ast::expr::Intrinsic::eSubgroupXor3I:
		case ast::expr::Intrinsic::eSubgroupXor4I:
		case ast::expr::Intrinsic::eSubgroupXor1U:
		case ast::expr::Intrinsic::eSubgroupXor2U:
		case ast::expr::Intrinsic::eSubgroupXor3U:
		case ast::expr::Intrinsic::eSubgroupXor4U:
		case ast::expr::Intrinsic::eSubgroupXor1B:
		case ast::expr::Intrinsic::eSubgroupXor2B:
		case ast::expr::Intrinsic::eSubgroupXor3B:
		case ast::expr::Intrinsic::eSubgroupXor4B:
			result = "subgroupXor";
			break;

		case ast::expr::Intrinsic::eSubgroupInclusiveAdd1F:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd2F:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd3F:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd4F:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd1I:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd2I:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd3I:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd4I:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd1U:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd2U:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd3U:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd4U:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd1D:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd2D:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd3D:
		case ast::expr::Intrinsic::eSubgroupInclusiveAdd4D:
			result = "subgroupInclusiveAdd";
			break;

		case ast::expr::Intrinsic::eSubgroupInclusiveMul1F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul2F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul3F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul4F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul1I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul2I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul3I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul4I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul1U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul2U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul3U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul4U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul1D:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul2D:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul3D:
		case ast::expr::Intrinsic::eSubgroupInclusiveMul4D:
			result = "subgroupInclusiveMul";
			break;

		case ast::expr::Intrinsic::eSubgroupInclusiveMin1F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin2F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin3F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin4F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin1I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin2I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin3I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin4I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin1U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin2U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin3U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin4U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin1D:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin2D:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin3D:
		case ast::expr::Intrinsic::eSubgroupInclusiveMin4D:
			result = "subgroupInclusiveMin";
			break;

		case ast::expr::Intrinsic::eSubgroupInclusiveMax1F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax2F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax3F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax4F:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax1I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax2I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax3I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax4I:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax1U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax2U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax3U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax4U:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax1D:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax2D:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax3D:
		case ast::expr::Intrinsic::eSubgroupInclusiveMax4D:
			result = "subgroupInclusiveMax";
			break;

		case ast::expr::Intrinsic::eSubgroupInclusiveAnd1I:
		case ast::expr::Intrinsic::eSubgroupInclusiveAnd2I:
		case ast::expr::Intrinsic::eSubgroupInclusiveAnd3I:
		case ast::expr::Intrinsic::eSubgroupInclusiveAnd4I:
		case ast::expr::Intrinsic::eSubgroupInclusiveAnd1U:
		case ast::expr::Intrinsic::eSubgroupInclusiveAnd2U:
		case ast::expr::Intrinsic::eSubgroupInclusiveAnd3U:
		case ast::expr::Intrinsic::eSubgroupInclusiveAnd4U:
		case ast::expr::Intrinsic::eSubgroupInclusiveAnd1B:
		case ast::expr::Intrinsic::eSubgroupInclusiveAnd2B:
		case ast::expr::Intrinsic::eSubgroupInclusiveAnd3B:
		case ast::expr::Intrinsic::eSubgroupInclusiveAnd4B:
			result = "subgroupInclusiveAnd";
			break;

		case ast::expr::Intrinsic::eSubgroupInclusiveOr1I:
		case ast::expr::Intrinsic::eSubgroupInclusiveOr2I:
		case ast::expr::Intrinsic::eSubgroupInclusiveOr3I:
		case ast::expr::Intrinsic::eSubgroupInclusiveOr4I:
		case ast::expr::Intrinsic::eSubgroupInclusiveOr1U:
		case ast::expr::Intrinsic::eSubgroupInclusiveOr2U:
		case ast::expr::Intrinsic::eSubgroupInclusiveOr3U:
		case ast::expr::Intrinsic::eSubgroupInclusiveOr4U:
		case ast::expr::Intrinsic::eSubgroupInclusiveOr1B:
		case ast::expr::Intrinsic::eSubgroupInclusiveOr2B:
		case ast::expr::Intrinsic::eSubgroupInclusiveOr3B:
		case ast::expr::Intrinsic::eSubgroupInclusiveOr4B:
			result = "subgroupInclusiveOr";
			break;

		case ast::expr::Intrinsic::eSubgroupInclusiveXor1I:
		case ast::expr::Intrinsic::eSubgroupInclusiveXor2I:
		case ast::expr::Intrinsic::eSubgroupInclusiveXor3I:
		case ast::expr::Intrinsic::eSubgroupInclusiveXor4I:
		case ast::expr::Intrinsic::eSubgroupInclusiveXor1U:
		case ast::expr::Intrinsic::eSubgroupInclusiveXor2U:
		case ast::expr::Intrinsic::eSubgroupInclusiveXor3U:
		case ast::expr::Intrinsic::eSubgroupInclusiveXor4U:
		case ast::expr::Intrinsic::eSubgroupInclusiveXor1B:
		case ast::expr::Intrinsic::eSubgroupInclusiveXor2B:
		case ast::expr::Intrinsic::eSubgroupInclusiveXor3B:
		case ast::expr::Intrinsic::eSubgroupInclusiveXor4B:
			result = "subgroupInclusiveXor";
			break;

		case ast::expr::Intrinsic::eSubgroupExclusiveAdd1F:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd2F:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd3F:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd4F:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd1I:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd2I:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd3I:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd4I:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd1U:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd2U:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd3U:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd4U:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd1D:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd2D:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd3D:
		case ast::expr::Intrinsic::eSubgroupExclusiveAdd4D:
			result = "subgroupExclusiveAdd";
			break;

		case ast::expr::Intrinsic::eSubgroupExclusiveMul1F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul2F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul3F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul4F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul1I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul2I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul3I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul4I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul1U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul2U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul3U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul4U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul1D:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul2D:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul3D:
		case ast::expr::Intrinsic::eSubgroupExclusiveMul4D:
			result = "subgroupExclusiveMul";
			break;

		case ast::expr::Intrinsic::eSubgroupExclusiveMin1F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin2F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin3F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin4F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin1I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin2I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin3I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin4I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin1U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin2U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin3U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin4U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin1D:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin2D:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin3D:
		case ast::expr::Intrinsic::eSubgroupExclusiveMin4D:
			result = "subgroupExclusiveMin";
			break;

		case ast::expr::Intrinsic::eSubgroupExclusiveMax1F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax2F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax3F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax4F:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax1I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax2I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax3I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax4I:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax1U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax2U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax3U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax4U:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax1D:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax2D:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax3D:
		case ast::expr::Intrinsic::eSubgroupExclusiveMax4D:
			result = "subgroupExclusiveMax";
			break;

		case ast::expr::Intrinsic::eSubgroupExclusiveAnd1I:
		case ast::expr::Intrinsic::eSubgroupExclusiveAnd2I:
		case ast::expr::Intrinsic::eSubgroupExclusiveAnd3I:
		case ast::expr::Intrinsic::eSubgroupExclusiveAnd4I:
		case ast::expr::Intrinsic::eSubgroupExclusiveAnd1U:
		case ast::expr::Intrinsic::eSubgroupExclusiveAnd2U:
		case ast::expr::Intrinsic::eSubgroupExclusiveAnd3U:
		case ast::expr::Intrinsic::eSubgroupExclusiveAnd4U:
		case ast::expr::Intrinsic::eSubgroupExclusiveAnd1B:
		case ast::expr::Intrinsic::eSubgroupExclusiveAnd2B:
		case ast::expr::Intrinsic::eSubgroupExclusiveAnd3B:
		case ast::expr::Intrinsic::eSubgroupExclusiveAnd4B:
			result = "subgroupExclusiveAnd";
			break;

		case ast::expr::Intrinsic::eSubgroupExclusiveOr1I:
		case ast::expr::Intrinsic::eSubgroupExclusiveOr2I:
		case ast::expr::Intrinsic::eSubgroupExclusiveOr3I:
		case ast::expr::Intrinsic::eSubgroupExclusiveOr4I:
		case ast::expr::Intrinsic::eSubgroupExclusiveOr1U:
		case ast::expr::Intrinsic::eSubgroupExclusiveOr2U:
		case ast::expr::Intrinsic::eSubgroupExclusiveOr3U:
		case ast::expr::Intrinsic::eSubgroupExclusiveOr4U:
		case ast::expr::Intrinsic::eSubgroupExclusiveOr1B:
		case ast::expr::Intrinsic::eSubgroupExclusiveOr2B:
		case ast::expr::Intrinsic::eSubgroupExclusiveOr3B:
		case ast::expr::Intrinsic::eSubgroupExclusiveOr4B:
			result = "subgroupExclusiveOr";
			break;

		case ast::expr::Intrinsic::eSubgroupExclusiveXor1I:
		case ast::expr::Intrinsic::eSubgroupExclusiveXor2I:
		case ast::expr::Intrinsic::eSubgroupExclusiveXor3I:
		case ast::expr::Intrinsic::eSubgroupExclusiveXor4I:
		case ast::expr::Intrinsic::eSubgroupExclusiveXor1U:
		case ast::expr::Intrinsic::eSubgroupExclusiveXor2U:
		case ast::expr::Intrinsic::eSubgroupExclusiveXor3U:
		case ast::expr::Intrinsic::eSubgroupExclusiveXor4U:
		case ast::expr::Intrinsic::eSubgroupExclusiveXor1B:
		case ast::expr::Intrinsic::eSubgroupExclusiveXor2B:
		case ast::expr::Intrinsic::eSubgroupExclusiveXor3B:
		case ast::expr::Intrinsic::eSubgroupExclusiveXor4B:
			result = "subgroupExclusiveXor";
			break;

		case ast::expr::Intrinsic::eSubgroupClusterAdd1F:
		case ast::expr::Intrinsic::eSubgroupClusterAdd2F:
		case ast::expr::Intrinsic::eSubgroupClusterAdd3F:
		case ast::expr::Intrinsic::eSubgroupClusterAdd4F:
		case ast::expr::Intrinsic::eSubgroupClusterAdd1I:
		case ast::expr::Intrinsic::eSubgroupClusterAdd2I:
		case ast::expr::Intrinsic::eSubgroupClusterAdd3I:
		case ast::expr::Intrinsic::eSubgroupClusterAdd4I:
		case ast::expr::Intrinsic::eSubgroupClusterAdd1U:
		case ast::expr::Intrinsic::eSubgroupClusterAdd2U:
		case ast::expr::Intrinsic::eSubgroupClusterAdd3U:
		case ast::expr::Intrinsic::eSubgroupClusterAdd4U:
		case ast::expr::Intrinsic::eSubgroupClusterAdd1D:
		case ast::expr::Intrinsic::eSubgroupClusterAdd2D:
		case ast::expr::Intrinsic::eSubgroupClusterAdd3D:
		case ast::expr::Intrinsic::eSubgroupClusterAdd4D:
			result = "subgroupClusterAdd";
			break;

		case ast::expr::Intrinsic::eSubgroupClusterMul1F:
		case ast::expr::Intrinsic::eSubgroupClusterMul2F:
		case ast::expr::Intrinsic::eSubgroupClusterMul3F:
		case ast::expr::Intrinsic::eSubgroupClusterMul4F:
		case ast::expr::Intrinsic::eSubgroupClusterMul1I:
		case ast::expr::Intrinsic::eSubgroupClusterMul2I:
		case ast::expr::Intrinsic::eSubgroupClusterMul3I:
		case ast::expr::Intrinsic::eSubgroupClusterMul4I:
		case ast::expr::Intrinsic::eSubgroupClusterMul1U:
		case ast::expr::Intrinsic::eSubgroupClusterMul2U:
		case ast::expr::Intrinsic::eSubgroupClusterMul3U:
		case ast::expr::Intrinsic::eSubgroupClusterMul4U:
		case ast::expr::Intrinsic::eSubgroupClusterMul1D:
		case ast::expr::Intrinsic::eSubgroupClusterMul2D:
		case ast::expr::Intrinsic::eSubgroupClusterMul3D:
		case ast::expr::Intrinsic::eSubgroupClusterMul4D:
			result = "subgroupClusterMul";
			break;

		case ast::expr::Intrinsic::eSubgroupClusterMin1F:
		case ast::expr::Intrinsic::eSubgroupClusterMin2F:
		case ast::expr::Intrinsic::eSubgroupClusterMin3F:
		case ast::expr::Intrinsic::eSubgroupClusterMin4F:
		case ast::expr::Intrinsic::eSubgroupClusterMin1I:
		case ast::expr::Intrinsic::eSubgroupClusterMin2I:
		case ast::expr::Intrinsic::eSubgroupClusterMin3I:
		case ast::expr::Intrinsic::eSubgroupClusterMin4I:
		case ast::expr::Intrinsic::eSubgroupClusterMin1U:
		case ast::expr::Intrinsic::eSubgroupClusterMin2U:
		case ast::expr::Intrinsic::eSubgroupClusterMin3U:
		case ast::expr::Intrinsic::eSubgroupClusterMin4U:
		case ast::expr::Intrinsic::eSubgroupClusterMin1D:
		case ast::expr::Intrinsic::eSubgroupClusterMin2D:
		case ast::expr::Intrinsic::eSubgroupClusterMin3D:
		case ast::expr::Intrinsic::eSubgroupClusterMin4D:
			result = "subgroupClusterMin";
			break;

		case ast::expr::Intrinsic::eSubgroupClusterMax1F:
		case ast::expr::Intrinsic::eSubgroupClusterMax2F:
		case ast::expr::Intrinsic::eSubgroupClusterMax3F:
		case ast::expr::Intrinsic::eSubgroupClusterMax4F:
		case ast::expr::Intrinsic::eSubgroupClusterMax1I:
		case ast::expr::Intrinsic::eSubgroupClusterMax2I:
		case ast::expr::Intrinsic::eSubgroupClusterMax3I:
		case ast::expr::Intrinsic::eSubgroupClusterMax4I:
		case ast::expr::Intrinsic::eSubgroupClusterMax1U:
		case ast::expr::Intrinsic::eSubgroupClusterMax2U:
		case ast::expr::Intrinsic::eSubgroupClusterMax3U:
		case ast::expr::Intrinsic::eSubgroupClusterMax4U:
		case ast::expr::Intrinsic::eSubgroupClusterMax1D:
		case ast::expr::Intrinsic::eSubgroupClusterMax2D:
		case ast::expr::Intrinsic::eSubgroupClusterMax3D:
		case ast::expr::Intrinsic::eSubgroupClusterMax4D:
			result = "subgroupClusterMax";
			break;

		case ast::expr::Intrinsic::eSubgroupClusterAnd1I:
		case ast::expr::Intrinsic::eSubgroupClusterAnd2I:
		case ast::expr::Intrinsic::eSubgroupClusterAnd3I:
		case ast::expr::Intrinsic::eSubgroupClusterAnd4I:
		case ast::expr::Intrinsic::eSubgroupClusterAnd1U:
		case ast::expr::Intrinsic::eSubgroupClusterAnd2U:
		case ast::expr::Intrinsic::eSubgroupClusterAnd3U:
		case ast::expr::Intrinsic::eSubgroupClusterAnd4U:
		case ast::expr::Intrinsic::eSubgroupClusterAnd1B:
		case ast::expr::Intrinsic::eSubgroupClusterAnd2B:
		case ast::expr::Intrinsic::eSubgroupClusterAnd3B:
		case ast::expr::Intrinsic::eSubgroupClusterAnd4B:
			result = "subgroupClusterAnd";
			break;

		case ast::expr::Intrinsic::eSubgroupClusterOr1I:
		case ast::expr::Intrinsic::eSubgroupClusterOr2I:
		case ast::expr::Intrinsic::eSubgroupClusterOr3I:
		case ast::expr::Intrinsic::eSubgroupClusterOr4I:
		case ast::expr::Intrinsic::eSubgroupClusterOr1U:
		case ast::expr::Intrinsic::eSubgroupClusterOr2U:
		case ast::expr::Intrinsic::eSubgroupClusterOr3U:
		case ast::expr::Intrinsic::eSubgroupClusterOr4U:
		case ast::expr::Intrinsic::eSubgroupClusterOr1B:
		case ast::expr::Intrinsic::eSubgroupClusterOr2B:
		case ast::expr::Intrinsic::eSubgroupClusterOr3B:
		case ast::expr::Intrinsic::eSubgroupClusterOr4B:
			result = "subgroupClusterOr";
			break;

		case ast::expr::Intrinsic::eSubgroupClusterXor1I:
		case ast::expr::Intrinsic::eSubgroupClusterXor2I:
		case ast::expr::Intrinsic::eSubgroupClusterXor3I:
		case ast::expr::Intrinsic::eSubgroupClusterXor4I:
		case ast::expr::Intrinsic::eSubgroupClusterXor1U:
		case ast::expr::Intrinsic::eSubgroupClusterXor2U:
		case ast::expr::Intrinsic::eSubgroupClusterXor3U:
		case ast::expr::Intrinsic::eSubgroupClusterXor4U:
		case ast::expr::Intrinsic::eSubgroupClusterXor1B:
		case ast::expr::Intrinsic::eSubgroupClusterXor2B:
		case ast::expr::Intrinsic::eSubgroupClusterXor3B:
		case ast::expr::Intrinsic::eSubgroupClusterXor4B:
			result = "subgroupClusterXor";
			break;

		case ast::expr::Intrinsic::eSubgroupQuadBroadcast1F:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast2F:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast3F:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast4F:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast1I:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast2I:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast3I:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast4I:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast1U:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast2U:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast3U:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast4U:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast1B:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast2B:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast3B:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast4B:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast1D:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast2D:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast3D:
		case ast::expr::Intrinsic::eSubgroupQuadBroadcast4D:
			result = "subgroupQuadBroadcast";
			break;

		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal2F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal3F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal2I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal3I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal2U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal3U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal2B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal3B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1D:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal2D:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal3D:
		case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4D:
			result = "subgroupQuadSwapHorizontal";
			break;

		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical1F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical2F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical3F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical4F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical1I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical2I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical3I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical4I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical1U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical2U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical3U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical4U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical1B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical2B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical3B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical4B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical1D:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical2D:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical3D:
		case ast::expr::Intrinsic::eSubgroupQuadSwapVertical4D:
			result = "subgroupQuadSwapVertical";
			break;

		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal2F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal3F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4F:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal2I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal3I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4I:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal2U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal3U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4U:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal2B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal3B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4B:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1D:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal2D:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal3D:
		case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4D:
			result = "subgroupQuadSwapDiagonal";
			break;

		case ast::expr::Intrinsic::eReadInvocation1F:
		case ast::expr::Intrinsic::eReadInvocation2F:
		case ast::expr::Intrinsic::eReadInvocation3F:
		case ast::expr::Intrinsic::eReadInvocation4F:
		case ast::expr::Intrinsic::eReadInvocation1I:
		case ast::expr::Intrinsic::eReadInvocation2I:
		case ast::expr::Intrinsic::eReadInvocation3I:
		case ast::expr::Intrinsic::eReadInvocation4I:
		case ast::expr::Intrinsic::eReadInvocation1U:
		case ast::expr::Intrinsic::eReadInvocation2U:
		case ast::expr::Intrinsic::eReadInvocation3U:
		case ast::expr::Intrinsic::eReadInvocation4U:
			result = "readInvocationARB";
			break;

		case ast::expr::Intrinsic::eReadFirstInvocation1F:
		case ast::expr::Intrinsic::eReadFirstInvocation2F:
		case ast::expr::Intrinsic::eReadFirstInvocation3F:
		case ast::expr::Intrinsic::eReadFirstInvocation4F:
		case ast::expr::Intrinsic::eReadFirstInvocation1I:
		case ast::expr::Intrinsic::eReadFirstInvocation2I:
		case ast::expr::Intrinsic::eReadFirstInvocation3I:
		case ast::expr::Intrinsic::eReadFirstInvocation4I:
		case ast::expr::Intrinsic::eReadFirstInvocation1U:
		case ast::expr::Intrinsic::eReadFirstInvocation2U:
		case ast::expr::Intrinsic::eReadFirstInvocation3U:
		case ast::expr::Intrinsic::eReadFirstInvocation4U:
			result = "readFirstInvocationARB";
			break;

		default:
		case ast::expr::Intrinsic::eReadInvocation1D:
		case ast::expr::Intrinsic::eReadInvocation2D:
		case ast::expr::Intrinsic::eReadInvocation3D:
		case ast::expr::Intrinsic::eReadInvocation4D:
		case ast::expr::Intrinsic::eReadFirstInvocation1D:
		case ast::expr::Intrinsic::eReadFirstInvocation2D:
		case ast::expr::Intrinsic::eReadFirstInvocation3D:
		case ast::expr::Intrinsic::eReadFirstInvocation4D:
			throw ast::Exception{ "Unsupported Intrinsic type." };
		}

		return result;
	}
}

#endif
