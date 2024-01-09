/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslIntrinsicConfig_H___
#define ___AST_HlslIntrinsicConfig_H___
#pragma once

#include "HlslHelpers.hpp"

#include <ShaderAST/Expr/EnumIntrinsic.hpp>

#include <stdexcept>

namespace hlsl
{
	struct IntrinsicAdaptationInfo
	{
		struct OperatorChange
		{
			bool toOperator{};
			ast::expr::Kind operatorKind{};
		};
		struct AtomicChange
		{
			bool isAtomic{};
			uint32_t outputIndex{};
		};
		OperatorChange operatorChange{};
		AtomicChange atomicChange{};
		bool isStrictFloat{};
	};

	inline IntrinsicAdaptationInfo getAdaptationInfo( ast::expr::Intrinsic value )
	{
		IntrinsicAdaptationInfo result;

		switch ( value )
		{
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
			result.operatorChange.toOperator = true;
			result.operatorChange.operatorKind = ast::expr::Kind::eTimes;
			break;

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
			result.operatorChange.toOperator = true;
			result.operatorChange.operatorKind = ast::expr::Kind::eLess;
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
			result.operatorChange.toOperator = true;
			result.operatorChange.operatorKind = ast::expr::Kind::eLessEqual;
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
			result.operatorChange.toOperator = true;
			result.operatorChange.operatorKind = ast::expr::Kind::eGreater;
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
			result.operatorChange.toOperator = true;
			result.operatorChange.operatorKind = ast::expr::Kind::eGreaterEqual;
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
			result.operatorChange.toOperator = true;
			result.operatorChange.operatorKind = ast::expr::Kind::eEqual;
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
			result.operatorChange.toOperator = true;
			result.operatorChange.operatorKind = ast::expr::Kind::eNotEqual;
			break;

		case ast::expr::Intrinsic::eNot2:
		case ast::expr::Intrinsic::eNot3:
		case ast::expr::Intrinsic::eNot4:
			result.operatorChange.toOperator = true;
			result.operatorChange.operatorKind = ast::expr::Kind::eLogNot;
			break;

		case ast::expr::Intrinsic::eAtomicAddI:
		case ast::expr::Intrinsic::eAtomicAddU:
		case ast::expr::Intrinsic::eAtomicAddF:
		case ast::expr::Intrinsic::eAtomicAdd2H:
		case ast::expr::Intrinsic::eAtomicAdd4H:
		case ast::expr::Intrinsic::eAtomicMinI:
		case ast::expr::Intrinsic::eAtomicMinU:
		case ast::expr::Intrinsic::eAtomicMaxI:
		case ast::expr::Intrinsic::eAtomicMaxU:
		case ast::expr::Intrinsic::eAtomicAndI:
		case ast::expr::Intrinsic::eAtomicAndU:
		case ast::expr::Intrinsic::eAtomicOrI:
		case ast::expr::Intrinsic::eAtomicOrU:
		case ast::expr::Intrinsic::eAtomicXorI:
		case ast::expr::Intrinsic::eAtomicXorU:
		case ast::expr::Intrinsic::eAtomicExchangeI:
		case ast::expr::Intrinsic::eAtomicExchangeU:
		case ast::expr::Intrinsic::eAtomicExchangeF:
		case ast::expr::Intrinsic::eAtomicExchange2H:
		case ast::expr::Intrinsic::eAtomicExchange4H:
			result.atomicChange.isAtomic = true;
			result.atomicChange.outputIndex = 2u;
			break;

		case ast::expr::Intrinsic::eAtomicCompSwapI:
		case ast::expr::Intrinsic::eAtomicCompSwapU:
			result.atomicChange.isAtomic = true;
			result.atomicChange.outputIndex = 3u;
			break;

		case ast::expr::Intrinsic::eSqrt1D:
		case ast::expr::Intrinsic::eSqrt2D:
		case ast::expr::Intrinsic::eSqrt3D:
		case ast::expr::Intrinsic::eSqrt4D:
		case ast::expr::Intrinsic::eInverseSqrt1D:
		case ast::expr::Intrinsic::eInverseSqrt2D:
		case ast::expr::Intrinsic::eInverseSqrt3D:
		case ast::expr::Intrinsic::eInverseSqrt4D:
		case ast::expr::Intrinsic::eFloor1D:
		case ast::expr::Intrinsic::eFloor2D:
		case ast::expr::Intrinsic::eFloor3D:
		case ast::expr::Intrinsic::eFloor4D:
		case ast::expr::Intrinsic::eTrunc1D:
		case ast::expr::Intrinsic::eTrunc2D:
		case ast::expr::Intrinsic::eTrunc3D:
		case ast::expr::Intrinsic::eTrunc4D:
		case ast::expr::Intrinsic::eRound1D:
		case ast::expr::Intrinsic::eRound2D:
		case ast::expr::Intrinsic::eRound3D:
		case ast::expr::Intrinsic::eRound4D:
		case ast::expr::Intrinsic::eCeil1D:
		case ast::expr::Intrinsic::eCeil2D:
		case ast::expr::Intrinsic::eCeil3D:
		case ast::expr::Intrinsic::eCeil4D:
		case ast::expr::Intrinsic::eFract1D:
		case ast::expr::Intrinsic::eFract2D:
		case ast::expr::Intrinsic::eFract3D:
		case ast::expr::Intrinsic::eFract4D:
		case ast::expr::Intrinsic::eMod1D:
		case ast::expr::Intrinsic::eMod2D:
		case ast::expr::Intrinsic::eMod3D:
		case ast::expr::Intrinsic::eMod4D:
		case ast::expr::Intrinsic::eMix1D:
		case ast::expr::Intrinsic::eMix2D:
		case ast::expr::Intrinsic::eMix3D:
		case ast::expr::Intrinsic::eMix4D:
		case ast::expr::Intrinsic::eStep1D:
		case ast::expr::Intrinsic::eStep2D:
		case ast::expr::Intrinsic::eStep3D:
		case ast::expr::Intrinsic::eStep4D:
		case ast::expr::Intrinsic::eSmoothStep1D:
		case ast::expr::Intrinsic::eSmoothStep2D:
		case ast::expr::Intrinsic::eSmoothStep3D:
		case ast::expr::Intrinsic::eSmoothStep4D:
		case ast::expr::Intrinsic::eFrexp1D:
		case ast::expr::Intrinsic::eFrexp2D:
		case ast::expr::Intrinsic::eFrexp3D:
		case ast::expr::Intrinsic::eFrexp4D:
		case ast::expr::Intrinsic::eLdexp1D:
		case ast::expr::Intrinsic::eLdexp2D:
		case ast::expr::Intrinsic::eLdexp3D:
		case ast::expr::Intrinsic::eLdexp4D:
			result.isStrictFloat = true;
			break;

		default:
			break;
		}

		return result;
	}

	inline void getHlslConfig( ast::expr::Intrinsic value
		, IntrinsicsConfig & config )
	{
		switch ( value )
		{
		case ast::expr::Intrinsic::eAcosh1:
			config.requiresACosh1F = true;
			break;

		case ast::expr::Intrinsic::eAcosh2:
			config.requiresACosh2F = true;
			break;

		case ast::expr::Intrinsic::eAcosh3:
			config.requiresACosh3F = true;
			break;

		case ast::expr::Intrinsic::eAcosh4:
			config.requiresACosh4F = true;
			break;
			
		case ast::expr::Intrinsic::eAsinh1:
			config.requiresASinh1F = true;
			break;

		case ast::expr::Intrinsic::eAsinh2:
			config.requiresASinh2F = true;
			break;

		case ast::expr::Intrinsic::eAsinh3:
			config.requiresASinh3F = true;
			break;

		case ast::expr::Intrinsic::eAsinh4:
			config.requiresASinh4F = true;
			break;
			
		case ast::expr::Intrinsic::eAtanh1:
			config.requiresATanh1F = true;
			break;

		case ast::expr::Intrinsic::eAtanh2:
			config.requiresATanh2F = true;
			break;

		case ast::expr::Intrinsic::eAtanh3:
			config.requiresATanh3F = true;
			break;

		case ast::expr::Intrinsic::eAtanh4:
			config.requiresATanh4F = true;
			break;
			
		case ast::expr::Intrinsic::eRoundEven1F:
			config.requiresRoundEven1F = true;
			break;

		case ast::expr::Intrinsic::eRoundEven2F:
			config.requiresRoundEven2F = true;
			break;

		case ast::expr::Intrinsic::eRoundEven3F:
			config.requiresRoundEven3F = true;
			break;

		case ast::expr::Intrinsic::eRoundEven4F:
			config.requiresRoundEven4F = true;
			break;

		case ast::expr::Intrinsic::eRoundEven1D:
			config.requiresRoundEven1D = true;
			break;

		case ast::expr::Intrinsic::eRoundEven2D:
			config.requiresRoundEven2D = true;
			break;

		case ast::expr::Intrinsic::eRoundEven3D:
			config.requiresRoundEven3D = true;
			break;

		case ast::expr::Intrinsic::eRoundEven4D:
			config.requiresRoundEven4D = true;
			break;

		case ast::expr::Intrinsic::ePackDouble2x32:
			config.requiresPackDouble2x32 = true;
			break;

		case ast::expr::Intrinsic::ePackHalf2x16:
			config.requiresPackHalf2x16 = true;
			break;

		case ast::expr::Intrinsic::ePackSnorm2x16:
			config.requiresPackSnorm2x16 = true;
			break;

		case ast::expr::Intrinsic::ePackSnorm4x8:
			config.requiresPackSnorm4x8 = true;
			break;

		case ast::expr::Intrinsic::ePackUnorm2x16:
			config.requiresPackUnorm2x16 = true;
			break;

		case ast::expr::Intrinsic::ePackUnorm4x8:
			config.requiresPackUnorm4x8 = true;
			break;

		case ast::expr::Intrinsic::eUnpackDouble2x32:
			config.requiresUnpackDouble2x32 = true;
			break;

		case ast::expr::Intrinsic::eUnpackHalf2x16:
			config.requiresUnpackHalf2x16 = true;
			break;

		case ast::expr::Intrinsic::eUnpackSnorm2x16:
			config.requiresUnpackSnorm2x16 = true;
			break;

		case ast::expr::Intrinsic::eUnpackSnorm4x8:
			config.requiresUnpackSnorm4x8 = true;
			break;

		case ast::expr::Intrinsic::eUnpackUnorm2x16:
			config.requiresUnpackUnorm2x16 = true;
			break;

		case ast::expr::Intrinsic::eUnpackUnorm4x8:
			config.requiresUnpackUnorm4x8 = true;
			break;

		case ast::expr::Intrinsic::eInverse2x2F:
			config.requiresInverse2x2F = true;
			break;

		case ast::expr::Intrinsic::eInverse3x3F:
			config.requiresInverse3x3F = true;
			break;

		case ast::expr::Intrinsic::eInverse4x4F:
			config.requiresInverse4x4F = true;
			break;

		case ast::expr::Intrinsic::eInverse2x2D:
			config.requiresInverse2x2D = true;
			break;

		case ast::expr::Intrinsic::eInverse3x3D:
			config.requiresInverse3x3D = true;
			break;

		case ast::expr::Intrinsic::eInverse4x4D:
			config.requiresInverse4x4D = true;
			break;

		case ast::expr::Intrinsic::eUaddCarry1:
			config.requiresUaddCarry1 = true;
			break;

		case ast::expr::Intrinsic::eUaddCarry2:
			config.requiresUaddCarry2 = true;
			break;

		case ast::expr::Intrinsic::eUaddCarry3:
			config.requiresUaddCarry3 = true;
			break;

		case ast::expr::Intrinsic::eUaddCarry4:
			config.requiresUaddCarry4 = true;
			break;

		case ast::expr::Intrinsic::eUsubBorrow1:
			config.requiresUsubBorrow1 = true;
			break;

		case ast::expr::Intrinsic::eUsubBorrow2:
			config.requiresUsubBorrow2 = true;
			break;

		case ast::expr::Intrinsic::eUsubBorrow3:
			config.requiresUsubBorrow3 = true;
			break;

		case ast::expr::Intrinsic::eUsubBorrow4:
			config.requiresUsubBorrow4 = true;
			break;

		case ast::expr::Intrinsic::eUmulExtended1:
			config.requiresUmulExtended1 = true;
			break;

		case ast::expr::Intrinsic::eUmulExtended2:
			config.requiresUmulExtended2 = true;
			break;

		case ast::expr::Intrinsic::eUmulExtended3:
			config.requiresUmulExtended3 = true;
			break;

		case ast::expr::Intrinsic::eUmulExtended4:
			config.requiresUmulExtended4 = true;
			break;

		case ast::expr::Intrinsic::eImulExtended1:
			config.requiresImulExtended1 = true;
			break;

		case ast::expr::Intrinsic::eImulExtended2:
			config.requiresImulExtended2 = true;
			break;

		case ast::expr::Intrinsic::eImulExtended3:
			config.requiresImulExtended3 = true;
			break;

		case ast::expr::Intrinsic::eImulExtended4:
			config.requiresImulExtended4 = true;
			break;

		case ast::expr::Intrinsic::eBitfieldExtract1I:
			config.requiresBitfieldExtract1I = true;
			break;

		case ast::expr::Intrinsic::eBitfieldExtract2I:
			config.requiresBitfieldExtract2I = true;
			break;

		case ast::expr::Intrinsic::eBitfieldExtract3I:
			config.requiresBitfieldExtract3I = true;
			break;

		case ast::expr::Intrinsic::eBitfieldExtract4I:
			config.requiresBitfieldExtract4I = true;
			break;

		case ast::expr::Intrinsic::eBitfieldExtract1U:
			config.requiresBitfieldExtract1U = true;
			break;

		case ast::expr::Intrinsic::eBitfieldExtract2U:
			config.requiresBitfieldExtract2U = true;
			break;

		case ast::expr::Intrinsic::eBitfieldExtract3U:
			config.requiresBitfieldExtract3U = true;
			break;

		case ast::expr::Intrinsic::eBitfieldExtract4U:
			config.requiresBitfieldExtract4U = true;
			break;

		case ast::expr::Intrinsic::eBitfieldInsert1I:
			config.requiresBitfieldInsert1I = true;
			break;

		case ast::expr::Intrinsic::eBitfieldInsert2I:
			config.requiresBitfieldInsert2I = true;
			break;

		case ast::expr::Intrinsic::eBitfieldInsert3I:
			config.requiresBitfieldInsert3I = true;
			break;

		case ast::expr::Intrinsic::eBitfieldInsert4I:
			config.requiresBitfieldInsert4I = true;
			break;

		case ast::expr::Intrinsic::eBitfieldInsert1U:
			config.requiresBitfieldInsert1U = true;
			break;

		case ast::expr::Intrinsic::eBitfieldInsert2U:
			config.requiresBitfieldInsert2U = true;
			break;

		case ast::expr::Intrinsic::eBitfieldInsert3U:
			config.requiresBitfieldInsert3U = true;
			break;

		case ast::expr::Intrinsic::eBitfieldInsert4U:
			config.requiresBitfieldInsert4U = true;
			break;

		case ast::expr::Intrinsic::eBitfieldReverse1I:
			config.requiresBitfieldReverse1I = true;
			break;

		case ast::expr::Intrinsic::eBitfieldReverse2I:
			config.requiresBitfieldReverse2I = true;
			break;

		case ast::expr::Intrinsic::eBitfieldReverse3I:
			config.requiresBitfieldReverse3I = true;
			break;

		case ast::expr::Intrinsic::eBitfieldReverse4I:
			config.requiresBitfieldReverse4I = true;
			break;

		case ast::expr::Intrinsic::eModf1D:
			config.requiresModf1D = true;
			break;

		case ast::expr::Intrinsic::eModf2D:
			config.requiresModf2D = true;
			break;

		case ast::expr::Intrinsic::eModf3D:
			config.requiresModf3D = true;
			break;

		case ast::expr::Intrinsic::eModf4D:
			config.requiresModf4D = true;
			break;

		case ast::expr::Intrinsic::eInterpolateAtCentroid1:
		case ast::expr::Intrinsic::eInterpolateAtCentroid2:
		case ast::expr::Intrinsic::eInterpolateAtCentroid3:
		case ast::expr::Intrinsic::eInterpolateAtCentroid4:
		case ast::expr::Intrinsic::eInterpolateAtSample1:
		case ast::expr::Intrinsic::eInterpolateAtSample2:
		case ast::expr::Intrinsic::eInterpolateAtSample3:
		case ast::expr::Intrinsic::eInterpolateAtSample4:
		case ast::expr::Intrinsic::eInterpolateAtOffset1:
		case ast::expr::Intrinsic::eInterpolateAtOffset2:
		case ast::expr::Intrinsic::eInterpolateAtOffset3:
		case ast::expr::Intrinsic::eInterpolateAtOffset4:
			config.requiresInterpolate = true;
			break;


	//Shader Subgroup Functions
		case ast::expr::Intrinsic::eSubgroupElect:
		case ast::expr::Intrinsic::eSubgroupAll:
		case ast::expr::Intrinsic::eSubgroupAny:
		case ast::expr::Intrinsic::eSubgroupAllEqual1F:
		case ast::expr::Intrinsic::eSubgroupAllEqual1I:
		case ast::expr::Intrinsic::eSubgroupAllEqual1U:
		case ast::expr::Intrinsic::eSubgroupAllEqual1B:
		case ast::expr::Intrinsic::eSubgroupAllEqual1D:
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
		case ast::expr::Intrinsic::eSubgroupBallot:
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
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual2F:
			config.requiresSubgroupAllEqual2F = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual3F:
			config.requiresSubgroupAllEqual3F = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual4F:
			config.requiresSubgroupAllEqual4F = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual2I:
			config.requiresSubgroupAllEqual2I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual3I:
			config.requiresSubgroupAllEqual3I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual4I:
			config.requiresSubgroupAllEqual4I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual2U:
			config.requiresSubgroupAllEqual2U = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual3U:
			config.requiresSubgroupAllEqual3U = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual4U:
			config.requiresSubgroupAllEqual4U = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual2B:
			config.requiresSubgroupAllEqual2B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual3B:
			config.requiresSubgroupAllEqual3B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual4B:
			config.requiresSubgroupAllEqual4B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual2D:
			config.requiresSubgroupAllEqual2D = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual3D:
			config.requiresSubgroupAllEqual3D = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAllEqual4D:
			config.requiresSubgroupAllEqual4D = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAnd1I:
			config.requiresSubgroupAnd1I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAnd2I:
			config.requiresSubgroupAnd2I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAnd3I:
			config.requiresSubgroupAnd3I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAnd4I:
			config.requiresSubgroupAnd4I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAnd1U:
		case ast::expr::Intrinsic::eSubgroupAnd2U:
		case ast::expr::Intrinsic::eSubgroupAnd3U:
		case ast::expr::Intrinsic::eSubgroupAnd4U:
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAnd1B:
			config.requiresSubgroupAnd1B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAnd2B:
			config.requiresSubgroupAnd2B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAnd3B:
			config.requiresSubgroupAnd3B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupAnd4B:
			config.requiresSubgroupAnd4B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupOr1I:
			config.requiresSubgroupOr1I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupOr2I:
			config.requiresSubgroupOr2I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupOr3I:
			config.requiresSubgroupOr3I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupOr4I:
			config.requiresSubgroupOr4I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupOr1U:
		case ast::expr::Intrinsic::eSubgroupOr2U:
		case ast::expr::Intrinsic::eSubgroupOr3U:
		case ast::expr::Intrinsic::eSubgroupOr4U:
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupOr1B:
			config.requiresSubgroupOr1B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupOr2B:
			config.requiresSubgroupOr2B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupOr3B:
			config.requiresSubgroupOr3B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupOr4B:
			config.requiresSubgroupOr4B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupXor1I:
			config.requiresSubgroupXor1I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupXor2I:
			config.requiresSubgroupXor2I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupXor3I:
			config.requiresSubgroupXor3I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupXor4I:
			config.requiresSubgroupXor4I = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupXor1U:
		case ast::expr::Intrinsic::eSubgroupXor2U:
		case ast::expr::Intrinsic::eSubgroupXor3U:
		case ast::expr::Intrinsic::eSubgroupXor4U:
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupXor1B:
			config.requiresSubgroupXor1B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupXor2B:
			config.requiresSubgroupXor2B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupXor3B:
			config.requiresSubgroupXor3B = true;
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eSubgroupXor4B:
			config.requiresSubgroupXor4B = true;
			config.requiresWaveOps = true;
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
			config.requiresWaveOps = true;
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
		case ast::expr::Intrinsic::eReadInvocation1D:
		case ast::expr::Intrinsic::eReadInvocation2D:
		case ast::expr::Intrinsic::eReadInvocation3D:
		case ast::expr::Intrinsic::eReadInvocation4D:
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
			config.requiresWaveOps = true;
			break;

		case ast::expr::Intrinsic::eAtomicAddF:
		case ast::expr::Intrinsic::eAtomicAdd2H:
		case ast::expr::Intrinsic::eAtomicAdd4H:
		case ast::expr::Intrinsic::eAtomicExchangeF:
		case ast::expr::Intrinsic::eAtomicExchange2H:
		case ast::expr::Intrinsic::eAtomicExchange4H:
		case ast::expr::Intrinsic::eSubgroupInverseBallot:
		case ast::expr::Intrinsic::eSubgroupBallotBitCount:
		case ast::expr::Intrinsic::eSubgroupBallotBitExtract:
		case ast::expr::Intrinsic::eSubgroupBallotExclusiveBitCount:
		case ast::expr::Intrinsic::eSubgroupBallotInclusiveBitCount:
		case ast::expr::Intrinsic::eSubgroupBallotFindLSB:
		case ast::expr::Intrinsic::eSubgroupBallotFindMSB:
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
			throw ast::Exception{ "Unsupported Intrinsic type in HLSL." };

		default:
			break;
		}
	}
}

#endif
