/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslIntrinsicConfig_H___
#define ___AST_HlslIntrinsicConfig_H___
#pragma once

#include "HlslHelpers.hpp"

#include <ShaderAST/Expr/EnumIntrinsic.hpp>

namespace hlsl
{
	struct InstantChange
	{
		bool toOperator{ false };
		ast::expr::Kind operatorKind;
	};

	inline InstantChange getInstantChange( ast::expr::Intrinsic value )
	{
		InstantChange result;

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
			result.toOperator = true;
			result.operatorKind = ast::expr::Kind::eTimes;
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
			result.toOperator = true;
			result.operatorKind = ast::expr::Kind::eLess;
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
			result.toOperator = true;
			result.operatorKind = ast::expr::Kind::eLessEqual;
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
			result.toOperator = true;
			result.operatorKind = ast::expr::Kind::eGreater;
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
			result.toOperator = true;
			result.operatorKind = ast::expr::Kind::eGreaterEqual;
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
			result.toOperator = true;
			result.operatorKind = ast::expr::Kind::eEqual;
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
			result.toOperator = true;
			result.operatorKind = ast::expr::Kind::eNotEqual;
			break;

		case ast::expr::Intrinsic::eNot2:
		case ast::expr::Intrinsic::eNot3:
		case ast::expr::Intrinsic::eNot4:
			result.toOperator = true;
			result.operatorKind = ast::expr::Kind::eLogNot;
			break;
		}

		return result;
	}

	inline void getHlslConfig( ast::expr::Intrinsic value
		, IntrinsicsConfig & config )
	{
		switch ( value )
		{
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
		}
	}
}

#endif
