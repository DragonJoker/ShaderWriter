/*
See LICENSE file in root folder
*/
#ifndef ___AST_GlslIntrinsicNames_H___
#define ___AST_GlslIntrinsicNames_H___
#pragma once

#include <ASTGenerator/Expr/EnumIntrinsic.hpp>

#include <string>

namespace sdw
{
	inline std::string getGlslName( ast::expr::Intrinsic value )
	{
		std::string result;

		switch ( value )
		{
	// Angle and Trigonometry Functions
		case ast::expr::Intrinsic::eDegrees1:
			result = "degrees";
			break;

		case ast::expr::Intrinsic::eDegrees2:
			result = "degrees";
			break;

		case ast::expr::Intrinsic::eDegrees3:
			result = "degrees";
			break;

		case ast::expr::Intrinsic::eDegrees4:
			result = "degrees";
			break;

		case ast::expr::Intrinsic::eRadians1F:
			result = "radians";
			break;

		case ast::expr::Intrinsic::eRadians2F:
			result = "radians";
			break;

		case ast::expr::Intrinsic::eRadians3F:
			result = "radians";
			break;

		case ast::expr::Intrinsic::eRadians4F:
			result = "radians";
			break;

		case ast::expr::Intrinsic::eCos1:
			result = "cos";
			break;

		case ast::expr::Intrinsic::eCos2:
			result = "cos";
			break;

		case ast::expr::Intrinsic::eCos3:
			result = "cos";
			break;

		case ast::expr::Intrinsic::eCos4:
			result = "cos";
			break;

		case ast::expr::Intrinsic::eSin1:
			result = "sin";
			break;

		case ast::expr::Intrinsic::eSin2:
			result = "sin";
			break;

		case ast::expr::Intrinsic::eSin3:
			result = "sin";
			break;

		case ast::expr::Intrinsic::eSin4:
			result = "sin";
			break;

		case ast::expr::Intrinsic::eTan1:
			result = "tan";
			break;

		case ast::expr::Intrinsic::eTan2:
			result = "tan";
			break;

		case ast::expr::Intrinsic::eTan3:
			result = "tan";
			break;

		case ast::expr::Intrinsic::eTan4:
			result = "tan";
			break;

		case ast::expr::Intrinsic::eCosh1:
			result = "cosh";
			break;

		case ast::expr::Intrinsic::eCosh2:
			result = "cosh";
			break;

		case ast::expr::Intrinsic::eCosh3:
			result = "cosh";
			break;

		case ast::expr::Intrinsic::eCosh4:
			result = "cosh";
			break;

		case ast::expr::Intrinsic::eSinh1:
			result = "sinh";
			break;

		case ast::expr::Intrinsic::eSinh2:
			result = "sinh";
			break;

		case ast::expr::Intrinsic::eSinh3:
			result = "sinh";
			break;

		case ast::expr::Intrinsic::eSinh4:
			result = "sinh";
			break;

		case ast::expr::Intrinsic::eTanh1:
			result = "tanh";
			break;

		case ast::expr::Intrinsic::eTanh2:
			result = "tanh";
			break;

		case ast::expr::Intrinsic::eTanh3:
			result = "tanh";
			break;

		case ast::expr::Intrinsic::eTanh4:
			result = "tanh";
			break;

		case ast::expr::Intrinsic::eAcos1:
			result = "acos";
			break;

		case ast::expr::Intrinsic::eAcos2:
			result = "acos";
			break;

		case ast::expr::Intrinsic::eAcos3:
			result = "acos";
			break;

		case ast::expr::Intrinsic::eAcos4:
			result = "acos";
			break;

		case ast::expr::Intrinsic::eAsin1:
			result = "asin";
			break;

		case ast::expr::Intrinsic::eAsin2:
			result = "asin";
			break;

		case ast::expr::Intrinsic::eAsin3:
			result = "asin";
			break;

		case ast::expr::Intrinsic::eAsin4:
			result = "asin";
			break;

		case ast::expr::Intrinsic::eAtan1:
			result = "atan";
			break;

		case ast::expr::Intrinsic::eAtan2:
			result = "atan";
			break;

		case ast::expr::Intrinsic::eAtan3:
			result = "atan";
			break;

		case ast::expr::Intrinsic::eAtan4:
			result = "atan";
			break;

		case ast::expr::Intrinsic::eAcosh1:
			result = "acosh";
			break;

		case ast::expr::Intrinsic::eAcosh2:
			result = "acosh";
			break;

		case ast::expr::Intrinsic::eAcosh3:
			result = "acosh";
			break;

		case ast::expr::Intrinsic::eAcosh4:
			result = "acosh";
			break;

		case ast::expr::Intrinsic::eAsinh1:
			result = "asinh";
			break;

		case ast::expr::Intrinsic::eAsinh2:
			result = "asinh";
			break;

		case ast::expr::Intrinsic::eAsinh3:
			result = "asinh";
			break;

		case ast::expr::Intrinsic::eAsinh4:
			result = "asinh";
			break;

		case ast::expr::Intrinsic::eAtanh1:
			result = "atanh";
			break;

		case ast::expr::Intrinsic::eAtanh2:
			result = "atanh";
			break;

		case ast::expr::Intrinsic::eAtanh3:
			result = "atanh";
			break;

		case ast::expr::Intrinsic::eAtanh4:
			result = "atanh";
			break;


	// Exponential Functions
		case ast::expr::Intrinsic::ePow1:
			result = "pow";
			break;

		case ast::expr::Intrinsic::ePow2:
			result = "pow";
			break;

		case ast::expr::Intrinsic::ePow3:
			result = "pow";
			break;

		case ast::expr::Intrinsic::ePow4:
			result = "pow";
			break;

		case ast::expr::Intrinsic::eExp1:
			result = "exp";
			break;

		case ast::expr::Intrinsic::eExp2:
			result = "exp";
			break;

		case ast::expr::Intrinsic::eExp3:
			result = "exp";
			break;

		case ast::expr::Intrinsic::eExp4:
			result = "exp";
			break;

		case ast::expr::Intrinsic::eLog1:
			result = "log";
			break;

		case ast::expr::Intrinsic::eLog2:
			result = "log";
			break;

		case ast::expr::Intrinsic::eLog3:
			result = "log";
			break;

		case ast::expr::Intrinsic::eLog4:
			result = "log";
			break;

		case ast::expr::Intrinsic::eExp21:
			result = "exp2";
			break;

		case ast::expr::Intrinsic::eExp22:
			result = "exp2";
			break;

		case ast::expr::Intrinsic::eExp23:
			result = "exp2";
			break;

		case ast::expr::Intrinsic::eExp24:
			result = "exp2";
			break;

		case ast::expr::Intrinsic::eLog21:
			result = "log2";
			break;

		case ast::expr::Intrinsic::eLog22:
			result = "log2";
			break;

		case ast::expr::Intrinsic::eLog23:
			result = "log2";
			break;

		case ast::expr::Intrinsic::eLog24:
			result = "log2";
			break;

		case ast::expr::Intrinsic::eSqrt1F:
			result = "sqrt";
			break;

		case ast::expr::Intrinsic::eSqrt2F:
			result = "sqrt";
			break;

		case ast::expr::Intrinsic::eSqrt3F:
			result = "sqrt";
			break;

		case ast::expr::Intrinsic::eSqrt4F:
			result = "sqrt";
			break;

		case ast::expr::Intrinsic::eSqrt1D:
			result = "sqrt";
			break;

		case ast::expr::Intrinsic::eSqrt2D:
			result = "sqrt";
			break;

		case ast::expr::Intrinsic::eSqrt3D:
			result = "sqrt";
			break;

		case ast::expr::Intrinsic::eSqrt4D:
			result = "sqrt";
			break;

		case ast::expr::Intrinsic::eInverseSqrt1F:
			result = "inverseSqrt";
			break;

		case ast::expr::Intrinsic::eInverseSqrt2F:
			result = "inverseSqrt";
			break;

		case ast::expr::Intrinsic::eInverseSqrt3F:
			result = "inverseSqrt";
			break;

		case ast::expr::Intrinsic::eInverseSqrt4F:
			result = "inverseSqrt";
			break;

		case ast::expr::Intrinsic::eInverseSqrt1D:
			result = "inverseSqrt";
			break;

		case ast::expr::Intrinsic::eInverseSqrt2D:
			result = "inverseSqrt";
			break;

		case ast::expr::Intrinsic::eInverseSqrt3D:
			result = "inverseSqrt";
			break;

		case ast::expr::Intrinsic::eInverseSqrt4D:
			result = "inverseSqrt";
			break;


	// Common Functions
		case ast::expr::Intrinsic::eAbs1F:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eAbs2F:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eAbs3F:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eAbs4F:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eAbs1I:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eAbs2I:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eAbs3I:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eAbs4I:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eAbs1D:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eAbs2D:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eAbs3D:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eAbs4D:
			result = "abs";
			break;

		case ast::expr::Intrinsic::eSign1F:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eSign2F:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eSign3F:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eSign4F:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eSign1I:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eSign2I:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eSign3I:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eSign4I:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eSign1D:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eSign2D:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eSign3D:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eSign4D:
			result = "sign";
			break;

		case ast::expr::Intrinsic::eFloor1F:
			result = "floor";
			break;

		case ast::expr::Intrinsic::eFloor2F:
			result = "floor";
			break;

		case ast::expr::Intrinsic::eFloor3F:
			result = "floor";
			break;

		case ast::expr::Intrinsic::eFloor4F:
			result = "floor";
			break;

		case ast::expr::Intrinsic::eFloor1D:
			result = "floor";
			break;

		case ast::expr::Intrinsic::eFloor2D:
			result = "floor";
			break;

		case ast::expr::Intrinsic::eFloor3D:
			result = "floor";
			break;

		case ast::expr::Intrinsic::eFloor4D:
			result = "floor";
			break;

		case ast::expr::Intrinsic::eTrunc1F:
			result = "trunc";
			break;

		case ast::expr::Intrinsic::eTrunc2F:
			result = "trunc";
			break;

		case ast::expr::Intrinsic::eTrunc3F:
			result = "trunc";
			break;

		case ast::expr::Intrinsic::eTrunc4F:
			result = "trunc";
			break;

		case ast::expr::Intrinsic::eTrunc1D:
			result = "trunc";
			break;

		case ast::expr::Intrinsic::eTrunc2D:
			result = "trunc";
			break;

		case ast::expr::Intrinsic::eTrunc3D:
			result = "trunc";
			break;

		case ast::expr::Intrinsic::eTrunc4D:
			result = "trunc";
			break;

		case ast::expr::Intrinsic::eRound1F:
			result = "round";
			break;

		case ast::expr::Intrinsic::eRound2F:
			result = "round";
			break;

		case ast::expr::Intrinsic::eRound3F:
			result = "round";
			break;

		case ast::expr::Intrinsic::eRound4F:
			result = "round";
			break;

		case ast::expr::Intrinsic::eRound1D:
			result = "round";
			break;

		case ast::expr::Intrinsic::eRound2D:
			result = "round";
			break;

		case ast::expr::Intrinsic::eRound3D:
			result = "round";
			break;

		case ast::expr::Intrinsic::eRound4D:
			result = "round";
			break;

		case ast::expr::Intrinsic::eRoundEven1F:
			result = "roundEven";
			break;

		case ast::expr::Intrinsic::eRoundEven2F:
			result = "roundEven";
			break;

		case ast::expr::Intrinsic::eRoundEven3F:
			result = "roundEven";
			break;

		case ast::expr::Intrinsic::eRoundEven4F:
			result = "roundEven";
			break;

		case ast::expr::Intrinsic::eRoundEven1D:
			result = "roundEven";
			break;

		case ast::expr::Intrinsic::eRoundEven2D:
			result = "roundEven";
			break;

		case ast::expr::Intrinsic::eRoundEven3D:
			result = "roundEven";
			break;

		case ast::expr::Intrinsic::eRoundEven4D:
			result = "roundEven";
			break;

		case ast::expr::Intrinsic::eCeil1F:
			result = "ceil";
			break;

		case ast::expr::Intrinsic::eCeil2F:
			result = "ceil";
			break;

		case ast::expr::Intrinsic::eCeil3F:
			result = "ceil";
			break;

		case ast::expr::Intrinsic::eCeil4F:
			result = "ceil";
			break;

		case ast::expr::Intrinsic::eCeil1D:
			result = "ceil";
			break;

		case ast::expr::Intrinsic::eCeil2D:
			result = "ceil";
			break;

		case ast::expr::Intrinsic::eCeil3D:
			result = "ceil";
			break;

		case ast::expr::Intrinsic::eCeil4D:
			result = "ceil";
			break;

		case ast::expr::Intrinsic::eFract1F:
			result = "fract";
			break;

		case ast::expr::Intrinsic::eFract2F:
			result = "fract";
			break;

		case ast::expr::Intrinsic::eFract3F:
			result = "fract";
			break;

		case ast::expr::Intrinsic::eFract4F:
			result = "fract";
			break;

		case ast::expr::Intrinsic::eFract1D:
			result = "fract";
			break;

		case ast::expr::Intrinsic::eFract2D:
			result = "fract";
			break;

		case ast::expr::Intrinsic::eFract3D:
			result = "fract";
			break;

		case ast::expr::Intrinsic::eFract4D:
			result = "fract";
			break;

		case ast::expr::Intrinsic::eMod11F:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod22F:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod33F:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod44F:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod21F:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod31F:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod41F:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod11D:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod22D:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod33D:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod44D:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod21D:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod31D:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eMod41D:
			result = "mod";
			break;

		case ast::expr::Intrinsic::eModf1F:
			result = "modf";
			break;

		case ast::expr::Intrinsic::eModf2F:
			result = "modf";
			break;

		case ast::expr::Intrinsic::eModf3F:
			result = "modf";
			break;

		case ast::expr::Intrinsic::eModf4F:
			result = "modf";
			break;

		case ast::expr::Intrinsic::eModf1D:
			result = "modf";
			break;

		case ast::expr::Intrinsic::eModf2D:
			result = "modf";
			break;

		case ast::expr::Intrinsic::eModf3D:
			result = "modf";
			break;

		case ast::expr::Intrinsic::eModf4D:
			result = "modf";
			break;

		case ast::expr::Intrinsic::eMin11F:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin22F:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin33F:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin44F:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin21F:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin31F:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin41F:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin11D:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin22D:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin33D:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin44D:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin21D:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin31D:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin41D:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin11I:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin22I:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin33I:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin44I:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin21I:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin31I:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin41I:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin11U:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin22U:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin33U:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin44U:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin21U:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin31U:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMin41U:
			result = "min";
			break;

		case ast::expr::Intrinsic::eMax11F:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax22F:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax33F:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax44F:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax21F:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax31F:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax41F:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax11D:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax22D:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax33D:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax44D:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax21D:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax31D:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax41D:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax11I:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax22I:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax33I:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax44I:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax21I:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax31I:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax41I:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax11U:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax22U:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax33U:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax44U:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax21U:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax31U:
			result = "max";
			break;

		case ast::expr::Intrinsic::eMax41U:
			result = "max";
			break;

		case ast::expr::Intrinsic::eClamp11F:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp22F:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp33F:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp44F:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp21F:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp31F:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp41F:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp11D:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp22D:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp33D:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp44D:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp21D:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp31D:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp41D:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp11I:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp22I:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp33I:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp44I:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp21I:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp31I:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp41I:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp11U:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp22U:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp33U:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp44U:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp21U:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp31U:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eClamp41U:
			result = "clamp";
			break;

		case ast::expr::Intrinsic::eMix11F:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix22F:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix33F:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix44F:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix21F:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix31F:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix41F:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix11FB:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix22FB:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix33FB:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix44FB:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix11D:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix22D:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix33D:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix44D:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix21D:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix31D:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix41D:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix11DB:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix22DB:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix33DB:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eMix44DB:
			result = "mix";
			break;

		case ast::expr::Intrinsic::eStep11F:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep22F:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep33F:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep44F:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep12F:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep13F:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep14F:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep11D:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep22D:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep33D:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep44D:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep12D:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep13D:
			result = "step";
			break;

		case ast::expr::Intrinsic::eStep14D:
			result = "step";
			break;

		case ast::expr::Intrinsic::eSmoothStep11F:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep22F:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep33F:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep44F:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep12F:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep13F:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep14F:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep11D:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep22D:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep33D:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep44D:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep12D:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep13D:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eSmoothStep14D:
			result = "smoothStep";
			break;

		case ast::expr::Intrinsic::eIsnan1F:
			result = "isnan";
			break;

		case ast::expr::Intrinsic::eIsnan2F:
			result = "isnan";
			break;

		case ast::expr::Intrinsic::eIsnan3F:
			result = "isnan";
			break;

		case ast::expr::Intrinsic::eIsnan4F:
			result = "isnan";
			break;

		case ast::expr::Intrinsic::eIsnan1D:
			result = "isnan";
			break;

		case ast::expr::Intrinsic::eIsnan2D:
			result = "isnan";
			break;

		case ast::expr::Intrinsic::eIsnan3D:
			result = "isnan";
			break;

		case ast::expr::Intrinsic::eIsnan4D:
			result = "isnan";
			break;

		case ast::expr::Intrinsic::eIsinf1F:
			result = "isinf";
			break;

		case ast::expr::Intrinsic::eIsinf2F:
			result = "isinf";
			break;

		case ast::expr::Intrinsic::eIsinf3F:
			result = "isinf";
			break;

		case ast::expr::Intrinsic::eIsinf4F:
			result = "isinf";
			break;

		case ast::expr::Intrinsic::eIsinf1D:
			result = "isinf";
			break;

		case ast::expr::Intrinsic::eIsinf2D:
			result = "isinf";
			break;

		case ast::expr::Intrinsic::eIsinf3D:
			result = "isinf";
			break;

		case ast::expr::Intrinsic::eIsinf4D:
			result = "isinf";
			break;

		case ast::expr::Intrinsic::eFloatBitsToInt1:
			result = "floatBitsToInt";
			break;

		case ast::expr::Intrinsic::eFloatBitsToInt2:
			result = "floatBitsToInt";
			break;

		case ast::expr::Intrinsic::eFloatBitsToInt3:
			result = "floatBitsToInt";
			break;

		case ast::expr::Intrinsic::eFloatBitsToInt4:
			result = "floatBitsToInt";
			break;

		case ast::expr::Intrinsic::eFloatBitsToUInt1:
			result = "floatBitsToUInt";
			break;

		case ast::expr::Intrinsic::eFloatBitsToUInt2:
			result = "floatBitsToUInt";
			break;

		case ast::expr::Intrinsic::eFloatBitsToUInt3:
			result = "floatBitsToUInt";
			break;

		case ast::expr::Intrinsic::eFloatBitsToUInt4:
			result = "floatBitsToUInt";
			break;

		case ast::expr::Intrinsic::eIntBitsToFloat1:
			result = "intBitsToFloat";
			break;

		case ast::expr::Intrinsic::eIntBitsToFloat2:
			result = "intBitsToFloat";
			break;

		case ast::expr::Intrinsic::eIntBitsToFloat3:
			result = "intBitsToFloat";
			break;

		case ast::expr::Intrinsic::eIntBitsToFloat4:
			result = "intBitsToFloat";
			break;

		case ast::expr::Intrinsic::eUintBitsToFloat1:
			result = "uintBitsToFloat";
			break;

		case ast::expr::Intrinsic::eUintBitsToFloat2:
			result = "uintBitsToFloat";
			break;

		case ast::expr::Intrinsic::eUintBitsToFloat3:
			result = "uintBitsToFloat";
			break;

		case ast::expr::Intrinsic::eUintBitsToFloat4:
			result = "uintBitsToFloat";
			break;

		case ast::expr::Intrinsic::eFma1F:
			result = "fma";
			break;

		case ast::expr::Intrinsic::eFma2F:
			result = "fma";
			break;

		case ast::expr::Intrinsic::eFma3F:
			result = "fma";
			break;

		case ast::expr::Intrinsic::eFma4F:
			result = "fma";
			break;

		case ast::expr::Intrinsic::eFma1D:
			result = "fma";
			break;

		case ast::expr::Intrinsic::eFma2D:
			result = "fma";
			break;

		case ast::expr::Intrinsic::eFma3D:
			result = "fma";
			break;

		case ast::expr::Intrinsic::eFma4D:
			result = "fma";
			break;

		case ast::expr::Intrinsic::eFrexp1F:
			result = "frexp";
			break;

		case ast::expr::Intrinsic::eFrexp2F:
			result = "frexp";
			break;

		case ast::expr::Intrinsic::eFrexp3F:
			result = "frexp";
			break;

		case ast::expr::Intrinsic::eFrexp4F:
			result = "frexp";
			break;

		case ast::expr::Intrinsic::eFrexp1D:
			result = "frexp";
			break;

		case ast::expr::Intrinsic::eFrexp2D:
			result = "frexp";
			break;

		case ast::expr::Intrinsic::eFrexp3D:
			result = "frexp";
			break;

		case ast::expr::Intrinsic::eFrexp4D:
			result = "frexp";
			break;

		case ast::expr::Intrinsic::eLdexp1F:
			result = "ldexp";
			break;

		case ast::expr::Intrinsic::eLdexp2F:
			result = "ldexp";
			break;

		case ast::expr::Intrinsic::eLdexp3F:
			result = "ldexp";
			break;

		case ast::expr::Intrinsic::eLdexp4F:
			result = "ldexp";
			break;

		case ast::expr::Intrinsic::eLdexp1D:
			result = "ldexp";
			break;

		case ast::expr::Intrinsic::eLdexp2D:
			result = "ldexp";
			break;

		case ast::expr::Intrinsic::eLdexp3D:
			result = "ldexp";
			break;

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
			result = "length";
			break;

		case ast::expr::Intrinsic::eLength2F:
			result = "length";
			break;

		case ast::expr::Intrinsic::eLength3F:
			result = "length";
			break;

		case ast::expr::Intrinsic::eLength4F:
			result = "length";
			break;

		case ast::expr::Intrinsic::eLength1D:
			result = "length";
			break;

		case ast::expr::Intrinsic::eLength2D:
			result = "length";
			break;

		case ast::expr::Intrinsic::eLength3D:
			result = "length";
			break;

		case ast::expr::Intrinsic::eLength4D:
			result = "length";
			break;

		case ast::expr::Intrinsic::eDistance1F:
			result = "distance";
			break;

		case ast::expr::Intrinsic::eDistance2F:
			result = "distance";
			break;

		case ast::expr::Intrinsic::eDistance3F:
			result = "distance";
			break;

		case ast::expr::Intrinsic::eDistance4F:
			result = "distance";
			break;

		case ast::expr::Intrinsic::eDistance1D:
			result = "distance";
			break;

		case ast::expr::Intrinsic::eDistance2D:
			result = "distance";
			break;

		case ast::expr::Intrinsic::eDistance3D:
			result = "distance";
			break;

		case ast::expr::Intrinsic::eDistance4D:
			result = "distance";
			break;

		case ast::expr::Intrinsic::eDot1F:
			result = "dot";
			break;

		case ast::expr::Intrinsic::eDot2F:
			result = "dot";
			break;

		case ast::expr::Intrinsic::eDot3F:
			result = "dot";
			break;

		case ast::expr::Intrinsic::eDot4F:
			result = "dot";
			break;

		case ast::expr::Intrinsic::eDot1D:
			result = "dot";
			break;

		case ast::expr::Intrinsic::eDot2D:
			result = "dot";
			break;

		case ast::expr::Intrinsic::eDot3D:
			result = "dot";
			break;

		case ast::expr::Intrinsic::eDot4D:
			result = "dot";
			break;

		case ast::expr::Intrinsic::eCrossF:
			result = "cross";
			break;

		case ast::expr::Intrinsic::eCrossD:
			result = "cross";
			break;

		case ast::expr::Intrinsic::eNormalize1F:
			result = "normalize";
			break;

		case ast::expr::Intrinsic::eNormalize2F:
			result = "normalize";
			break;

		case ast::expr::Intrinsic::eNormalize3F:
			result = "normalize";
			break;

		case ast::expr::Intrinsic::eNormalize4F:
			result = "normalize";
			break;

		case ast::expr::Intrinsic::eNormalize1D:
			result = "normalize";
			break;

		case ast::expr::Intrinsic::eNormalize2D:
			result = "normalize";
			break;

		case ast::expr::Intrinsic::eNormalize3D:
			result = "normalize";
			break;

		case ast::expr::Intrinsic::eNormalize4D:
			result = "normalize";
			break;

		case ast::expr::Intrinsic::eFaceForward1F:
			result = "faceForward";
			break;

		case ast::expr::Intrinsic::eFaceForward2F:
			result = "faceForward";
			break;

		case ast::expr::Intrinsic::eFaceForward3F:
			result = "faceForward";
			break;

		case ast::expr::Intrinsic::eFaceForward4F:
			result = "faceForward";
			break;

		case ast::expr::Intrinsic::eFaceForward1D:
			result = "faceForward";
			break;

		case ast::expr::Intrinsic::eFaceForward2D:
			result = "faceForward";
			break;

		case ast::expr::Intrinsic::eFaceForward3D:
			result = "faceForward";
			break;

		case ast::expr::Intrinsic::eFaceForward4D:
			result = "faceForward";
			break;

		case ast::expr::Intrinsic::eReflect1F:
			result = "reflect";
			break;

		case ast::expr::Intrinsic::eReflect2F:
			result = "reflect";
			break;

		case ast::expr::Intrinsic::eReflect3F:
			result = "reflect";
			break;

		case ast::expr::Intrinsic::eReflect4F:
			result = "reflect";
			break;

		case ast::expr::Intrinsic::eReflect1D:
			result = "reflect";
			break;

		case ast::expr::Intrinsic::eReflect2D:
			result = "reflect";
			break;

		case ast::expr::Intrinsic::eReflect3D:
			result = "reflect";
			break;

		case ast::expr::Intrinsic::eReflect4D:
			result = "reflect";
			break;

		case ast::expr::Intrinsic::eRefract1F:
			result = "refract";
			break;

		case ast::expr::Intrinsic::eRefract2F:
			result = "refract";
			break;

		case ast::expr::Intrinsic::eRefract3F:
			result = "refract";
			break;

		case ast::expr::Intrinsic::eRefract4F:
			result = "refract";
			break;

		case ast::expr::Intrinsic::eRefract1D:
			result = "refract";
			break;

		case ast::expr::Intrinsic::eRefract2D:
			result = "refract";
			break;

		case ast::expr::Intrinsic::eRefract3D:
			result = "refract";
			break;

		case ast::expr::Intrinsic::eRefract4D:
			result = "refract";
			break;


	// Matrix Functions
		case ast::expr::Intrinsic::eMatrixCompMult2x2F:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult2x3F:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult2x4F:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult3x2F:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult3x3F:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult3x4F:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult4x2F:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult4x3F:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult4x4F:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult2x2D:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult2x3D:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult2x4D:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult3x2D:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult3x3D:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult3x4D:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult4x2D:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult4x3D:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eMatrixCompMult4x4D:
			result = "matrixCompMult";
			break;

		case ast::expr::Intrinsic::eOuterProduct2x2F:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct3x3F:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct4x4F:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct3x2F:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct2x3F:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct4x2F:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct2x4F:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct4x3F:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct3x4F:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct2x2D:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct3x3D:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct4x4D:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct3x2D:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct2x3D:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct4x2D:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct2x4D:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct4x3D:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eOuterProduct3x4D:
			result = "outerProduct";
			break;

		case ast::expr::Intrinsic::eTranspose2x2F:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose2x3F:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose2x4F:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose3x2F:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose3x3F:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose3x4F:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose4x2F:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose4x3F:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose4x4F:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose2x2D:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose2x3D:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose2x4D:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose3x2D:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose3x3D:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose3x4D:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose4x2D:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose4x3D:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eTranspose4x4D:
			result = "transpose";
			break;

		case ast::expr::Intrinsic::eDeterminant2x2F:
			result = "determinant";
			break;

		case ast::expr::Intrinsic::eDeterminant3x3F:
			result = "determinant";
			break;

		case ast::expr::Intrinsic::eDeterminant4x4F:
			result = "determinant";
			break;

		case ast::expr::Intrinsic::eDeterminant2x2D:
			result = "determinant";
			break;

		case ast::expr::Intrinsic::eDeterminant3x3D:
			result = "determinant";
			break;

		case ast::expr::Intrinsic::eDeterminant4x4D:
			result = "determinant";
			break;

		case ast::expr::Intrinsic::eInverse2x2F:
			result = "inverse";
			break;

		case ast::expr::Intrinsic::eInverse3x3F:
			result = "inverse";
			break;

		case ast::expr::Intrinsic::eInverse4x4F:
			result = "inverse";
			break;

		case ast::expr::Intrinsic::eInverse2x2D:
			result = "inverse";
			break;

		case ast::expr::Intrinsic::eInverse3x3D:
			result = "inverse";
			break;

		case ast::expr::Intrinsic::eInverse4x4D:
			result = "inverse";
			break;


	// Vector Relational Functions
		case ast::expr::Intrinsic::eLessThan2F:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThan3F:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThan4F:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThan2D:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThan3D:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThan4D:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThan2I:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThan3I:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThan4I:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThan2U:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThan3U:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThan4U:
			result = "lessThan";
			break;

		case ast::expr::Intrinsic::eLessThanEqual2F:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eLessThanEqual3F:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eLessThanEqual4F:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eLessThanEqual2D:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eLessThanEqual3D:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eLessThanEqual4D:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eLessThanEqual2I:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eLessThanEqual3I:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eLessThanEqual4I:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eLessThanEqual2U:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eLessThanEqual3U:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eLessThanEqual4U:
			result = "lessThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThan2F:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThan3F:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThan4F:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThan2D:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThan3D:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThan4D:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThan2I:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThan3I:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThan4I:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThan2U:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThan3U:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThan4U:
			result = "greaterThan";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual2F:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual3F:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual4F:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual2D:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual3D:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual4D:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual2I:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual3I:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual4I:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual2U:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual3U:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eGreaterThanEqual4U:
			result = "greaterThanEqual";
			break;

		case ast::expr::Intrinsic::eEqual2F:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eEqual3F:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eEqual4F:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eEqual2D:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eEqual3D:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eEqual4D:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eEqual2I:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eEqual3I:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eEqual4I:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eEqual2U:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eEqual3U:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eEqual4U:
			result = "equal";
			break;

		case ast::expr::Intrinsic::eNotEqual2F:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eNotEqual3F:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eNotEqual4F:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eNotEqual2D:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eNotEqual3D:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eNotEqual4D:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eNotEqual2I:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eNotEqual3I:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eNotEqual4I:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eNotEqual2U:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eNotEqual3U:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eNotEqual4U:
			result = "notEqual";
			break;

		case ast::expr::Intrinsic::eAll2:
			result = "all";
			break;

		case ast::expr::Intrinsic::eAll3:
			result = "all";
			break;

		case ast::expr::Intrinsic::eAll4:
			result = "all";
			break;

		case ast::expr::Intrinsic::eAny2:
			result = "any";
			break;

		case ast::expr::Intrinsic::eAny3:
			result = "any";
			break;

		case ast::expr::Intrinsic::eAny4:
			result = "any";
			break;

		case ast::expr::Intrinsic::eNot2:
			result = "not";
			break;

		case ast::expr::Intrinsic::eNot3:
			result = "not";
			break;

		case ast::expr::Intrinsic::eNot4:
			result = "not";
			break;


	// Integer Functions
		case ast::expr::Intrinsic::eUaddCarry1:
			result = "uaddCarry";
			break;

		case ast::expr::Intrinsic::eUaddCarry2:
			result = "uaddCarry";
			break;

		case ast::expr::Intrinsic::eUaddCarry3:
			result = "uaddCarry";
			break;

		case ast::expr::Intrinsic::eUaddCarry4:
			result = "uaddCarry";
			break;

		case ast::expr::Intrinsic::eUsubBorrow1:
			result = "usubBorrow";
			break;

		case ast::expr::Intrinsic::eUsubBorrow2:
			result = "usubBorrow";
			break;

		case ast::expr::Intrinsic::eUsubBorrow3:
			result = "usubBorrow";
			break;

		case ast::expr::Intrinsic::eUsubBorrow4:
			result = "usubBorrow";
			break;

		case ast::expr::Intrinsic::eUmulExtended1:
			result = "umulExtended";
			break;

		case ast::expr::Intrinsic::eUmulExtended2:
			result = "umulExtended";
			break;

		case ast::expr::Intrinsic::eUmulExtended3:
			result = "umulExtended";
			break;

		case ast::expr::Intrinsic::eUmulExtended4:
			result = "umulExtended";
			break;

		case ast::expr::Intrinsic::eImulExtended1:
			result = "imulExtended";
			break;

		case ast::expr::Intrinsic::eImulExtended2:
			result = "imulExtended";
			break;

		case ast::expr::Intrinsic::eImulExtended3:
			result = "imulExtended";
			break;

		case ast::expr::Intrinsic::eImulExtended4:
			result = "imulExtended";
			break;

		case ast::expr::Intrinsic::eBitfieldExtract1I:
			result = "bitfieldExtract";
			break;

		case ast::expr::Intrinsic::eBitfieldExtract2I:
			result = "bitfieldExtract";
			break;

		case ast::expr::Intrinsic::eBitfieldExtract3I:
			result = "bitfieldExtract";
			break;

		case ast::expr::Intrinsic::eBitfieldExtract4I:
			result = "bitfieldExtract";
			break;

		case ast::expr::Intrinsic::eBitfieldExtract1U:
			result = "bitfieldExtract";
			break;

		case ast::expr::Intrinsic::eBitfieldExtract2U:
			result = "bitfieldExtract";
			break;

		case ast::expr::Intrinsic::eBitfieldExtract3U:
			result = "bitfieldExtract";
			break;

		case ast::expr::Intrinsic::eBitfieldExtract4U:
			result = "bitfieldExtract";
			break;

		case ast::expr::Intrinsic::eBietfieldInsert1I:
			result = "bitfieldInsert";
			break;

		case ast::expr::Intrinsic::eBietfieldInsert2I:
			result = "bitfieldInsert";
			break;

		case ast::expr::Intrinsic::eBietfieldInsert3I:
			result = "bitfieldInsert";
			break;

		case ast::expr::Intrinsic::eBietfieldInsert4I:
			result = "bitfieldInsert";
			break;

		case ast::expr::Intrinsic::eBietfieldInsert1U:
			result = "bitfieldInsert";
			break;

		case ast::expr::Intrinsic::eBietfieldInsert2U:
			result = "bitfieldInsert";
			break;

		case ast::expr::Intrinsic::eBietfieldInsert3U:
			result = "bitfieldInsert";
			break;

		case ast::expr::Intrinsic::eBietfieldInsert4U:
			result = "bitfieldInsert";
			break;

		case ast::expr::Intrinsic::eBitfieldReverse1I:
			result = "bitfieldReverse";
			break;

		case ast::expr::Intrinsic::eBitfieldReverse2I:
			result = "bitfieldReverse";
			break;

		case ast::expr::Intrinsic::eBitfieldReverse3I:
			result = "bitfieldReverse";
			break;

		case ast::expr::Intrinsic::eBitfieldReverse4I:
			result = "bitfieldReverse";
			break;

		case ast::expr::Intrinsic::eBitfieldReverse1U:
			result = "bitfieldReverse";
			break;

		case ast::expr::Intrinsic::eBitfieldReverse2U:
			result = "bitfieldReverse";
			break;

		case ast::expr::Intrinsic::eBitfieldReverse3U:
			result = "bitfieldReverse";
			break;

		case ast::expr::Intrinsic::eBitfieldReverse4U:
			result = "bitfieldReverse";
			break;

		case ast::expr::Intrinsic::eBitCount1I:
			result = "bitCount";
			break;

		case ast::expr::Intrinsic::eBitCount2I:
			result = "bitCount";
			break;

		case ast::expr::Intrinsic::eBitCount3I:
			result = "bitCount";
			break;

		case ast::expr::Intrinsic::eBitCount4I:
			result = "bitCount";
			break;

		case ast::expr::Intrinsic::eBitCount1U:
			result = "bitCount";
			break;

		case ast::expr::Intrinsic::eBitCount2U:
			result = "bitCount";
			break;

		case ast::expr::Intrinsic::eBitCount3U:
			result = "bitCount";
			break;

		case ast::expr::Intrinsic::eBitCount4U:
			result = "bitCount";
			break;

		case ast::expr::Intrinsic::eFindLSB1I:
			result = "findLSB";
			break;

		case ast::expr::Intrinsic::eFindLSB2I:
			result = "findLSB";
			break;

		case ast::expr::Intrinsic::eFindLSB3I:
			result = "findLSB";
			break;

		case ast::expr::Intrinsic::eFindLSB4I:
			result = "findLSB";
			break;

		case ast::expr::Intrinsic::eFindLSB1U:
			result = "findLSB";
			break;

		case ast::expr::Intrinsic::eFindLSB2U:
			result = "findLSB";
			break;

		case ast::expr::Intrinsic::eFindLSB3U:
			result = "findLSB";
			break;

		case ast::expr::Intrinsic::eFindLSB4U:
			result = "findLSB";
			break;

		case ast::expr::Intrinsic::eFindMSB1I:
			result = "findMSB";
			break;

		case ast::expr::Intrinsic::eFindMSB2I:
			result = "findMSB";
			break;

		case ast::expr::Intrinsic::eFindMSB3I:
			result = "findMSB";
			break;

		case ast::expr::Intrinsic::eFindMSB4I:
			result = "findMSB";
			break;

		case ast::expr::Intrinsic::eFindMSB1U:
			result = "findMSB";
			break;

		case ast::expr::Intrinsic::eFindMSB2U:
			result = "findMSB";
			break;

		case ast::expr::Intrinsic::eFindMSB3U:
			result = "findMSB";
			break;

		case ast::expr::Intrinsic::eFindMSB4U:
			result = "findMSB";
			break;


	// Atomic Memory Functions
		case ast::expr::Intrinsic::eAtomicAddI:
			result = "atomicAdd";
			break;

		case ast::expr::Intrinsic::eAtomicAddU:
			result = "atomicAdd";
			break;

		case ast::expr::Intrinsic::eAtomicMinI:
			result = "atomicMin";
			break;

		case ast::expr::Intrinsic::eAtomicMinU:
			result = "atomicMin";
			break;

		case ast::expr::Intrinsic::eAtomicMaxI:
			result = "atomicMax";
			break;

		case ast::expr::Intrinsic::eAtomicMaxU:
			result = "atomicMax";
			break;

		case ast::expr::Intrinsic::eAtomicAndI:
			result = "atomicAnd";
			break;

		case ast::expr::Intrinsic::eAtomicAndU:
			result = "atomicAnd";
			break;

		case ast::expr::Intrinsic::eAtomicOrI:
			result = "atomicOr";
			break;

		case ast::expr::Intrinsic::eAtomicOrU:
			result = "atomicOr";
			break;

		case ast::expr::Intrinsic::eAtomicXorI:
			result = "atomicXor";
			break;

		case ast::expr::Intrinsic::eAtomicXorU:
			result = "atomicXor";
			break;

		case ast::expr::Intrinsic::eAtomicExchangeI:
			result = "atomicExchange";
			break;

		case ast::expr::Intrinsic::eAtomicExchangeU:
			result = "atomicExchange";
			break;

		case ast::expr::Intrinsic::eAtomicCompSwapI:
			result = "atomicCompSwap";
			break;

		case ast::expr::Intrinsic::eAtomicCompSwapU:
			result = "atomicCompSwap";
			break;


	// Derivative Functions
		case ast::expr::Intrinsic::eDFdx1:
			result = "dFdx";
			break;

		case ast::expr::Intrinsic::eDFdx2:
			result = "dFdx";
			break;

		case ast::expr::Intrinsic::eDFdx3:
			result = "dFdx";
			break;

		case ast::expr::Intrinsic::eDFdx4:
			result = "dFdx";
			break;

		case ast::expr::Intrinsic::eDFdxCoarse1:
			result = "dFdxCoarse";
			break;

		case ast::expr::Intrinsic::eDFdxCoarse2:
			result = "dFdxCoarse";
			break;

		case ast::expr::Intrinsic::eDFdxCoarse3:
			result = "dFdxCoarse";
			break;

		case ast::expr::Intrinsic::eDFdxCoarse4:
			result = "dFdxCoarse";
			break;

		case ast::expr::Intrinsic::eDFdxFine1:
			result = "dFdxFine";
			break;

		case ast::expr::Intrinsic::eDFdxFine2:
			result = "dFdxFine";
			break;

		case ast::expr::Intrinsic::eDFdxFine3:
			result = "dFdxFine";
			break;

		case ast::expr::Intrinsic::eDFdxFine4:
			result = "dFdxFine";
			break;

		case ast::expr::Intrinsic::eDFdy1:
			result = "dFdy";
			break;

		case ast::expr::Intrinsic::eDFdy2:
			result = "dFdy";
			break;

		case ast::expr::Intrinsic::eDFdy3:
			result = "dFdy";
			break;

		case ast::expr::Intrinsic::eDFdy4:
			result = "dFdy";
			break;

		case ast::expr::Intrinsic::eDFdyCoarse1:
			result = "dFdyCoarse";
			break;

		case ast::expr::Intrinsic::eDFdyCoarse2:
			result = "dFdyCoarse";
			break;

		case ast::expr::Intrinsic::eDFdyCoarse3:
			result = "dFdyCoarse";
			break;

		case ast::expr::Intrinsic::eDFdyCoarse4:
			result = "dFdyCoarse";
			break;

		case ast::expr::Intrinsic::eDFdyFine1:
			result = "dFdyFine";
			break;

		case ast::expr::Intrinsic::eDFdyFine2:
			result = "dFdyFine";
			break;

		case ast::expr::Intrinsic::eDFdyFine3:
			result = "dFdyFine";
			break;

		case ast::expr::Intrinsic::eDFdyFine4:
			result = "dFdyFine";
			break;

		case ast::expr::Intrinsic::eFwidth1:
			result = "fwidth";
			break;

		case ast::expr::Intrinsic::eFwidth2:
			result = "fwidth";
			break;

		case ast::expr::Intrinsic::eFwidth3:
			result = "fwidth";
			break;

		case ast::expr::Intrinsic::eFwidth4:
			result = "fwidth";
			break;

		case ast::expr::Intrinsic::eFwidthCoarse1:
			result = "fwidthCoarse";
			break;

		case ast::expr::Intrinsic::eFwidthCoarse2:
			result = "fwidthCoarse";
			break;

		case ast::expr::Intrinsic::eFwidthCoarse3:
			result = "fwidthCoarse";
			break;

		case ast::expr::Intrinsic::eFwidthCoarse4:
			result = "fwidthCoarse";
			break;

		case ast::expr::Intrinsic::eFwidthFine1:
			result = "fwidthFine";
			break;

		case ast::expr::Intrinsic::eFwidthFine2:
			result = "fwidthFine";
			break;

		case ast::expr::Intrinsic::eFwidthFine3:
			result = "fwidthFine";
			break;

		case ast::expr::Intrinsic::eFwidthFine4:
			result = "fwidthFine";
			break;


	// Interpolation Functions
		case ast::expr::Intrinsic::eInterpolateAtCentroid1:
			result = "interpolateAtCentroid";
			break;

		case ast::expr::Intrinsic::eInterpolateAtCentroid2:
			result = "interpolateAtCentroid";
			break;

		case ast::expr::Intrinsic::eInterpolateAtCentroid3:
			result = "interpolateAtCentroid";
			break;

		case ast::expr::Intrinsic::eInterpolateAtCentroid4:
			result = "interpolateAtCentroid";
			break;

		case ast::expr::Intrinsic::eInterpolateAtSample1:
			result = "interpolateAtSample";
			break;

		case ast::expr::Intrinsic::eInterpolateAtSample2:
			result = "interpolateAtSample";
			break;

		case ast::expr::Intrinsic::eInterpolateAtSample3:
			result = "interpolateAtSample";
			break;

		case ast::expr::Intrinsic::eInterpolateAtSample4:
			result = "interpolateAtSample";
			break;

		case ast::expr::Intrinsic::eInterpolateAtOffset1:
			result = "interpolateAtOffset";
			break;

		case ast::expr::Intrinsic::eInterpolateAtOffset2:
			result = "interpolateAtOffset";
			break;

		case ast::expr::Intrinsic::eInterpolateAtOffset3:
			result = "interpolateAtOffset";
			break;

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
