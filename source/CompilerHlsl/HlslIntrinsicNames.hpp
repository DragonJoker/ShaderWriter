/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslIntrinsicNames_H___
#define ___AST_HlslIntrinsicNames_H___
#pragma once

#include <ShaderAST/Expr/EnumIntrinsic.hpp>

#pragma warning( push )
#pragma warning( disable: 4365 )
#include <stdexcept>
#include <string>
#pragma warning( pop )

namespace hlsl
{
	inline std::string getHlslName( ast::expr::Intrinsic value )
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

		case ast::expr::Intrinsic::eAtan21:
		case ast::expr::Intrinsic::eAtan22:
		case ast::expr::Intrinsic::eAtan23:
		case ast::expr::Intrinsic::eAtan24:
			result = "atan2";
			break;

		case ast::expr::Intrinsic::eAcosh1:
		case ast::expr::Intrinsic::eAcosh2:
		case ast::expr::Intrinsic::eAcosh3:
		case ast::expr::Intrinsic::eAcosh4:
			result = "SDW_acosh";
			break;

		case ast::expr::Intrinsic::eAsinh1:
		case ast::expr::Intrinsic::eAsinh2:
		case ast::expr::Intrinsic::eAsinh3:
		case ast::expr::Intrinsic::eAsinh4:
			result = "SDW_asinh";
			break;

		case ast::expr::Intrinsic::eAtanh1:
		case ast::expr::Intrinsic::eAtanh2:
		case ast::expr::Intrinsic::eAtanh3:
		case ast::expr::Intrinsic::eAtanh4:
			result = "SDW_atanh";
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


	// Common Functions
		case ast::expr::Intrinsic::eInverseSqrt1F:
		case ast::expr::Intrinsic::eInverseSqrt2F:
		case ast::expr::Intrinsic::eInverseSqrt3F:
		case ast::expr::Intrinsic::eInverseSqrt4F:
		case ast::expr::Intrinsic::eInverseSqrt1D:
		case ast::expr::Intrinsic::eInverseSqrt2D:
		case ast::expr::Intrinsic::eInverseSqrt3D:
		case ast::expr::Intrinsic::eInverseSqrt4D:
			result = "rsqrt";
			break;

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
			result = "SDW_roundEven";
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
			result = "frac";
			break;

		case ast::expr::Intrinsic::eMod1F:
		case ast::expr::Intrinsic::eMod2F:
		case ast::expr::Intrinsic::eMod3F:
		case ast::expr::Intrinsic::eMod4F:
		case ast::expr::Intrinsic::eMod1D:
		case ast::expr::Intrinsic::eMod2D:
		case ast::expr::Intrinsic::eMod3D:
		case ast::expr::Intrinsic::eMod4D:
			result = "fmod";
			break;

		case ast::expr::Intrinsic::eModf1F:
		case ast::expr::Intrinsic::eModf2F:
		case ast::expr::Intrinsic::eModf3F:
		case ast::expr::Intrinsic::eModf4F:
			result = "modf";
			break;

		case ast::expr::Intrinsic::eModf1D:
		case ast::expr::Intrinsic::eModf2D:
		case ast::expr::Intrinsic::eModf3D:
		case ast::expr::Intrinsic::eModf4D:
			result = "SDW_modf";
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
			result = "lerp";
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
			result = "asint";
			break;

		case ast::expr::Intrinsic::eFloatBitsToUInt1:
		case ast::expr::Intrinsic::eFloatBitsToUInt2:
		case ast::expr::Intrinsic::eFloatBitsToUInt3:
		case ast::expr::Intrinsic::eFloatBitsToUInt4:
			result = "asuint";
			break;

		case ast::expr::Intrinsic::eIntBitsToFloat1:
		case ast::expr::Intrinsic::eIntBitsToFloat2:
		case ast::expr::Intrinsic::eIntBitsToFloat3:
		case ast::expr::Intrinsic::eIntBitsToFloat4:
			result = "asfloat";
			break;

		case ast::expr::Intrinsic::eUintBitsToFloat1:
		case ast::expr::Intrinsic::eUintBitsToFloat2:
		case ast::expr::Intrinsic::eUintBitsToFloat3:
		case ast::expr::Intrinsic::eUintBitsToFloat4:
			result = "asfloat";
			break;

		case ast::expr::Intrinsic::eFma1F:
		case ast::expr::Intrinsic::eFma2F:
		case ast::expr::Intrinsic::eFma3F:
		case ast::expr::Intrinsic::eFma4F:
		case ast::expr::Intrinsic::eFma1D:
		case ast::expr::Intrinsic::eFma2D:
		case ast::expr::Intrinsic::eFma3D:
		case ast::expr::Intrinsic::eFma4D:
			result = "mad";
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


	// Floating-point Pack and Unpack Functions
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

		case ast::expr::Intrinsic::ePackDouble2x32:
			result = "SDW_packDouble2x32";
			break;

		case ast::expr::Intrinsic::ePackHalf2x16:
			result = "SDW_packHalf2x16";
			break;

		case ast::expr::Intrinsic::ePackSnorm2x16:
			result = "SDW_packSnorm2x16";
			break;

		case ast::expr::Intrinsic::ePackSnorm4x8:
			result = "SDW_packSnorm4x8";
			break;

		case ast::expr::Intrinsic::ePackUnorm2x16:
			result = "SDW_packUnorm2x16";
			break;

		case ast::expr::Intrinsic::ePackUnorm4x8:
			result = "SDW_packUnorm4x8";
			break;

		case ast::expr::Intrinsic::eUnpackDouble2x32:
			result = "SDW_unpackDouble2x32";
			break;

		case ast::expr::Intrinsic::eUnpackHalf2x16:
			result = "SDW_unpackHalf2x16";
			break;

		case ast::expr::Intrinsic::eUnpackSnorm2x16:
			result = "SDW_unpackSnorm2x16";
			break;

		case ast::expr::Intrinsic::eUnpackSnorm4x8:
			result = "SDW_unpackSnorm4x8";
			break;

		case ast::expr::Intrinsic::eUnpackUnorm2x16:
			result = "SDW_unpackUnorm2x16";
			break;

		case ast::expr::Intrinsic::eUnpackUnorm4x8:
			result = "SDW_unpackUnorm4x8";
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
			result = "*";
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
			result = "mul";
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
			result = "SDW_Inverse";
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
			result = "<";
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
			result = "<=";
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
			result = ">";
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
			result = ">=";
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
			result = "==";
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
			result = "!=";
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
			result = "!";
			break;


	// Integer Functions
		case ast::expr::Intrinsic::eUaddCarry1:
		case ast::expr::Intrinsic::eUaddCarry2:
		case ast::expr::Intrinsic::eUaddCarry3:
		case ast::expr::Intrinsic::eUaddCarry4:
			result = "SDW_uaddCarry";
			break;

		case ast::expr::Intrinsic::eUsubBorrow1:
		case ast::expr::Intrinsic::eUsubBorrow2:
		case ast::expr::Intrinsic::eUsubBorrow3:
		case ast::expr::Intrinsic::eUsubBorrow4:
			result = "SDW_usubBorrow";
			break;

		case ast::expr::Intrinsic::eUmulExtended1:
		case ast::expr::Intrinsic::eUmulExtended2:
		case ast::expr::Intrinsic::eUmulExtended3:
		case ast::expr::Intrinsic::eUmulExtended4:
			result = "SDW_umulExtended";
			break;

		case ast::expr::Intrinsic::eImulExtended1:
		case ast::expr::Intrinsic::eImulExtended2:
		case ast::expr::Intrinsic::eImulExtended3:
		case ast::expr::Intrinsic::eImulExtended4:
			result = "SDW_imulExtended";
			break;

		case ast::expr::Intrinsic::eBitfieldExtract1I:
		case ast::expr::Intrinsic::eBitfieldExtract2I:
		case ast::expr::Intrinsic::eBitfieldExtract3I:
		case ast::expr::Intrinsic::eBitfieldExtract4I:
		case ast::expr::Intrinsic::eBitfieldExtract1U:
		case ast::expr::Intrinsic::eBitfieldExtract2U:
		case ast::expr::Intrinsic::eBitfieldExtract3U:
		case ast::expr::Intrinsic::eBitfieldExtract4U:
			result = "SDW_bitfieldExtract";
			break;

		case ast::expr::Intrinsic::eBitfieldInsert1I:
		case ast::expr::Intrinsic::eBitfieldInsert2I:
		case ast::expr::Intrinsic::eBitfieldInsert3I:
		case ast::expr::Intrinsic::eBitfieldInsert4I:
		case ast::expr::Intrinsic::eBitfieldInsert1U:
		case ast::expr::Intrinsic::eBitfieldInsert2U:
		case ast::expr::Intrinsic::eBitfieldInsert3U:
		case ast::expr::Intrinsic::eBitfieldInsert4U:
			result = "SDW_bitfieldInsert";
			break;

		case ast::expr::Intrinsic::eBitfieldReverse1I:
		case ast::expr::Intrinsic::eBitfieldReverse2I:
		case ast::expr::Intrinsic::eBitfieldReverse3I:
		case ast::expr::Intrinsic::eBitfieldReverse4I:
			result = "SDW_reverseBits";
			break;

		case ast::expr::Intrinsic::eBitfieldReverse1U:
		case ast::expr::Intrinsic::eBitfieldReverse2U:
		case ast::expr::Intrinsic::eBitfieldReverse3U:
		case ast::expr::Intrinsic::eBitfieldReverse4U:
			result = "reversebits";
			break;

		case ast::expr::Intrinsic::eBitCount1I:
		case ast::expr::Intrinsic::eBitCount2I:
		case ast::expr::Intrinsic::eBitCount3I:
		case ast::expr::Intrinsic::eBitCount4I:
		case ast::expr::Intrinsic::eBitCount1U:
		case ast::expr::Intrinsic::eBitCount2U:
		case ast::expr::Intrinsic::eBitCount3U:
		case ast::expr::Intrinsic::eBitCount4U:
			result = "countbits";
			break;

		case ast::expr::Intrinsic::eFindLSB1I:
		case ast::expr::Intrinsic::eFindLSB2I:
		case ast::expr::Intrinsic::eFindLSB3I:
		case ast::expr::Intrinsic::eFindLSB4I:
		case ast::expr::Intrinsic::eFindLSB1U:
		case ast::expr::Intrinsic::eFindLSB2U:
		case ast::expr::Intrinsic::eFindLSB3U:
		case ast::expr::Intrinsic::eFindLSB4U:
			result = "firstbitlow";
			break;

		case ast::expr::Intrinsic::eFindMSB1I:
		case ast::expr::Intrinsic::eFindMSB2I:
		case ast::expr::Intrinsic::eFindMSB3I:
		case ast::expr::Intrinsic::eFindMSB4I:
		case ast::expr::Intrinsic::eFindMSB1U:
		case ast::expr::Intrinsic::eFindMSB2U:
		case ast::expr::Intrinsic::eFindMSB3U:
		case ast::expr::Intrinsic::eFindMSB4U:
			result = "firstbithigh";
			break;


	// Atomic Memory Functions
		case ast::expr::Intrinsic::eAtomicAddI:
		case ast::expr::Intrinsic::eAtomicAddU:
		case ast::expr::Intrinsic::eAtomicAddF:
		case ast::expr::Intrinsic::eAtomicAdd2H:
		case ast::expr::Intrinsic::eAtomicAdd4H:
			result = "InterlockedAdd";
			break;

		case ast::expr::Intrinsic::eAtomicMinI:
		case ast::expr::Intrinsic::eAtomicMinU:
			result = "InterlockedMin";
			break;

		case ast::expr::Intrinsic::eAtomicMaxI:
		case ast::expr::Intrinsic::eAtomicMaxU:
			result = "InterlockedMax";
			break;

		case ast::expr::Intrinsic::eAtomicAndI:
		case ast::expr::Intrinsic::eAtomicAndU:
			result = "InterlockedAnd";
			break;

		case ast::expr::Intrinsic::eAtomicOrI:
		case ast::expr::Intrinsic::eAtomicOrU:
			result = "InterlockedOr";
			break;

		case ast::expr::Intrinsic::eAtomicXorI:
		case ast::expr::Intrinsic::eAtomicXorU:
			result = "InterlockedXor";
			break;

		case ast::expr::Intrinsic::eAtomicExchangeI:
		case ast::expr::Intrinsic::eAtomicExchangeU:
		case ast::expr::Intrinsic::eAtomicExchangeF:
		case ast::expr::Intrinsic::eAtomicExchange2H:
		case ast::expr::Intrinsic::eAtomicExchange4H:
			result = "InterlockedExchange";
			break;

		case ast::expr::Intrinsic::eAtomicCompSwapI:
		case ast::expr::Intrinsic::eAtomicCompSwapU:
			result = "InterlockedCompareExchange";
			break;


	// Derivative Functions
		case ast::expr::Intrinsic::eDFdx1:
		case ast::expr::Intrinsic::eDFdx2:
		case ast::expr::Intrinsic::eDFdx3:
		case ast::expr::Intrinsic::eDFdx4:
			result = "ddx";
			break;

		case ast::expr::Intrinsic::eDFdxCoarse1:
		case ast::expr::Intrinsic::eDFdxCoarse2:
		case ast::expr::Intrinsic::eDFdxCoarse3:
		case ast::expr::Intrinsic::eDFdxCoarse4:
			result = "ddx_coarse";
			break;

		case ast::expr::Intrinsic::eDFdxFine1:
		case ast::expr::Intrinsic::eDFdxFine2:
		case ast::expr::Intrinsic::eDFdxFine3:
		case ast::expr::Intrinsic::eDFdxFine4:
			result = "ddx_fine";
			break;

		case ast::expr::Intrinsic::eDFdy1:
		case ast::expr::Intrinsic::eDFdy2:
		case ast::expr::Intrinsic::eDFdy3:
		case ast::expr::Intrinsic::eDFdy4:
			result = "ddy";
			break;

		case ast::expr::Intrinsic::eDFdyCoarse1:
		case ast::expr::Intrinsic::eDFdyCoarse2:
		case ast::expr::Intrinsic::eDFdyCoarse3:
		case ast::expr::Intrinsic::eDFdyCoarse4:
			result = "ddy_coarse";
			break;

		case ast::expr::Intrinsic::eDFdyFine1:
		case ast::expr::Intrinsic::eDFdyFine2:
		case ast::expr::Intrinsic::eDFdyFine3:
		case ast::expr::Intrinsic::eDFdyFine4:
			result = "ddy_fine";
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
			result = "EvaluateAttributeAtCentroid";
			break;

		case ast::expr::Intrinsic::eInterpolateAtSample1:
		case ast::expr::Intrinsic::eInterpolateAtSample2:
		case ast::expr::Intrinsic::eInterpolateAtSample3:
		case ast::expr::Intrinsic::eInterpolateAtSample4:
			result = "EvaluateAttributeAtSample";
			break;

		case ast::expr::Intrinsic::eInterpolateAtOffset1:
		case ast::expr::Intrinsic::eInterpolateAtOffset2:
		case ast::expr::Intrinsic::eInterpolateAtOffset3:
		case ast::expr::Intrinsic::eInterpolateAtOffset4:
			result = "EvaluateAttributeSnapped";
			break;


	// Geometry Shader Functions
		case ast::expr::Intrinsic::eEmitStreamVertex:
			result = "EmitStreamVertex";
			break;

		case ast::expr::Intrinsic::eEndStreamPrimitive:
			result = "EndStreamPrimitive";
			break;

		case ast::expr::Intrinsic::eEmitVertex:
			result = "Append";
			break;

		case ast::expr::Intrinsic::eEndPrimitive:
			result = "RestartStrip";
			break;


	// Miscellaneous Functions
		case ast::expr::Intrinsic::eHelperInvocation:
			result = "HelperInvocation";
			break;

	// Ray tracing Shader Functions
		case ast::expr::Intrinsic::eTraceRay:
			result = "TraceRay";
			break;

		case ast::expr::Intrinsic::eReportIntersection:
			result = "ReportHit";
			break;

		case ast::expr::Intrinsic::eExecuteCallable:
			result = "CallShader";
			break;

	//Mesh Shader Functions
		case ast::expr::Intrinsic::eSetMeshOutputCountsNV:
		case ast::expr::Intrinsic::eSetMeshOutputCounts:
			result = "SetMeshOutputCounts";
			break;

		case ast::expr::Intrinsic::eDispatchMeshNV:
			result = "DispatchMesh";
			break;


	//Shader Subgroup Functions
		case ast::expr::Intrinsic::eSubgroupElect:
			result = "WaveIsFirstLane";
			break;

		case ast::expr::Intrinsic::eSubgroupAll:
			result = "WaveActiveAllTrue";
			break;

		case ast::expr::Intrinsic::eSubgroupAny:
			result = "WaveActiveAnyTrue";
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual1F:
		case ast::expr::Intrinsic::eSubgroupAllEqual1I:
		case ast::expr::Intrinsic::eSubgroupAllEqual1U:
		case ast::expr::Intrinsic::eSubgroupAllEqual1B:
		case ast::expr::Intrinsic::eSubgroupAllEqual1D:
			result = "WaveActiveAllEqual";
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual2F:
		case ast::expr::Intrinsic::eSubgroupAllEqual3F:
		case ast::expr::Intrinsic::eSubgroupAllEqual4F:
		case ast::expr::Intrinsic::eSubgroupAllEqual2I:
		case ast::expr::Intrinsic::eSubgroupAllEqual3I:
		case ast::expr::Intrinsic::eSubgroupAllEqual4I:
		case ast::expr::Intrinsic::eSubgroupAllEqual2U:
		case ast::expr::Intrinsic::eSubgroupAllEqual3U:
		case ast::expr::Intrinsic::eSubgroupAllEqual4U:
		case ast::expr::Intrinsic::eSubgroupAllEqual2B:
		case ast::expr::Intrinsic::eSubgroupAllEqual3B:
		case ast::expr::Intrinsic::eSubgroupAllEqual4B:
		case ast::expr::Intrinsic::eSubgroupAllEqual2D:
		case ast::expr::Intrinsic::eSubgroupAllEqual3D:
		case ast::expr::Intrinsic::eSubgroupAllEqual4D:
			result = "SDW_subgroupAllEqual";
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
		case ast::expr::Intrinsic::eReadInvocation1D:
		case ast::expr::Intrinsic::eReadInvocation2D:
		case ast::expr::Intrinsic::eReadInvocation3D:
		case ast::expr::Intrinsic::eReadInvocation4D:
			result = "WaveReadLaneAt";
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
		case ast::expr::Intrinsic::eReadFirstInvocation1D:
		case ast::expr::Intrinsic::eReadFirstInvocation2D:
		case ast::expr::Intrinsic::eReadFirstInvocation3D:
		case ast::expr::Intrinsic::eReadFirstInvocation4D:
			result = "WaveReadLaneFirst";
			break;

		case ast::expr::Intrinsic::eSubgroupBallot:
			result = "WaveActiveBallot";
			break;

		case ast::expr::Intrinsic::eSubgroupBallotBitCount:
			result = "WaveActiveCountBits";
			break;

		case ast::expr::Intrinsic::eSubgroupBallotExclusiveBitCount:
			result = "WavePrefixCountBits";
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
			result = "WaveActiveSum";
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
			result = "WaveActiveProduct";
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
			result = "WaveActiveMin";
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
			result = "WaveActiveMax";
			break;

		case ast::expr::Intrinsic::eSubgroupAnd1I:
		case ast::expr::Intrinsic::eSubgroupAnd2I:
		case ast::expr::Intrinsic::eSubgroupAnd3I:
		case ast::expr::Intrinsic::eSubgroupAnd4I:
		case ast::expr::Intrinsic::eSubgroupAnd1B:
		case ast::expr::Intrinsic::eSubgroupAnd2B:
		case ast::expr::Intrinsic::eSubgroupAnd3B:
		case ast::expr::Intrinsic::eSubgroupAnd4B:
			result = "SDW_subgroupAnd";
			break;

		case ast::expr::Intrinsic::eSubgroupAnd1U:
		case ast::expr::Intrinsic::eSubgroupAnd2U:
		case ast::expr::Intrinsic::eSubgroupAnd3U:
		case ast::expr::Intrinsic::eSubgroupAnd4U:
			result = "WaveActiveBitAnd";
			break;

		case ast::expr::Intrinsic::eSubgroupOr1I:
		case ast::expr::Intrinsic::eSubgroupOr2I:
		case ast::expr::Intrinsic::eSubgroupOr3I:
		case ast::expr::Intrinsic::eSubgroupOr4I:
		case ast::expr::Intrinsic::eSubgroupOr1B:
		case ast::expr::Intrinsic::eSubgroupOr2B:
		case ast::expr::Intrinsic::eSubgroupOr3B:
		case ast::expr::Intrinsic::eSubgroupOr4B:
			result = "SDW_subgroupOr";
			break;

		case ast::expr::Intrinsic::eSubgroupOr1U:
		case ast::expr::Intrinsic::eSubgroupOr2U:
		case ast::expr::Intrinsic::eSubgroupOr3U:
		case ast::expr::Intrinsic::eSubgroupOr4U:
			result = "WaveActiveBitOr";
			break;

		case ast::expr::Intrinsic::eSubgroupXor1I:
		case ast::expr::Intrinsic::eSubgroupXor2I:
		case ast::expr::Intrinsic::eSubgroupXor3I:
		case ast::expr::Intrinsic::eSubgroupXor4I:
		case ast::expr::Intrinsic::eSubgroupXor1B:
		case ast::expr::Intrinsic::eSubgroupXor2B:
		case ast::expr::Intrinsic::eSubgroupXor3B:
		case ast::expr::Intrinsic::eSubgroupXor4B:
			result = "SDW_subgroupXor";
			break;

		case ast::expr::Intrinsic::eSubgroupXor1U:
		case ast::expr::Intrinsic::eSubgroupXor2U:
		case ast::expr::Intrinsic::eSubgroupXor3U:
		case ast::expr::Intrinsic::eSubgroupXor4U:
			result = "WaveActiveBitXor";
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
			result = "WavePrefixSum";
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
			result = "WavePrefixProduct";
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
			result = "QuadReadLaneAt";
			break;

		default:
			throw ast::Exception{ "Unsupported Intrinsic type." };
		}

		return result;
	}
}

#endif
