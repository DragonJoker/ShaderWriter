/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslImageAccessConfig_H___
#define ___AST_HlslImageAccessConfig_H___
#pragma once

#include "HlslHelpers.hpp"

#include <ShaderAST/Expr/EnumStorageImageAccess.hpp>

namespace hlsl
{
	inline void getHlslConfig( ast::expr::StorageImageAccess value
		, IntrinsicsConfig & config )
	{
		std::string result;

		switch ( value )
		{
		case ast::expr::StorageImageAccess::eImageSize1DF:
			config.requiresImageSize1DF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DF:
			config.requiresImageSize2DF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize3DF:
			config.requiresImageSize3DF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSizeCubeF:
			config.requiresImageSizeCubeF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSizeCubeArrayF:
			config.requiresImageSizeCubeArrayF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize1DArrayF:
			config.requiresImageSize1DArrayF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DArrayF:
			config.requiresImageSize2DArrayF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSizeBufferF:
			config.requiresImageSizeBufferF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DMSF:
			config.requiresImageSize2DMSF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DMSArrayF:
			config.requiresImageSize2DMSArrayF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize1DI:
			config.requiresImageSize1DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DI:
			config.requiresImageSize2DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize3DI:
			config.requiresImageSize3DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSizeCubeI:
			config.requiresImageSizeCubeI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSizeCubeArrayI:
			config.requiresImageSizeCubeArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize1DArrayI:
			config.requiresImageSize1DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DArrayI:
			config.requiresImageSize2DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSizeBufferI:
			config.requiresImageSizeBufferI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DMSI:
			config.requiresImageSize2DMSI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DMSArrayI:
			config.requiresImageSize2DMSArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize1DU:
			config.requiresImageSize1DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DU:
			config.requiresImageSize2DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize3DU:
			config.requiresImageSize3DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageSizeCubeU:
			config.requiresImageSizeCubeU = true;
			break;

		case ast::expr::StorageImageAccess::eImageSizeCubeArrayU:
			config.requiresImageSizeCubeArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize1DArrayU:
			config.requiresImageSize1DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DArrayU:
			config.requiresImageSize2DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageSizeBufferU:
			config.requiresImageSizeBufferU = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DMSU:
			config.requiresImageSize2DMSU = true;
			break;

		case ast::expr::StorageImageAccess::eImageSize2DMSArrayU:
			config.requiresImageSize2DMSArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageSamples2DMSF:
			config.requiresImageSamples2DMSF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSamples2DMSArrayF:
			config.requiresImageSamples2DMSArrayF = true;
			break;

		case ast::expr::StorageImageAccess::eImageSamples2DMSI:
			config.requiresImageSamples2DMSI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSamples2DMSArrayI:
			config.requiresImageSamples2DMSArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageSamples2DMSU:
			config.requiresImageSamples2DMSU = true;
			break;

		case ast::expr::StorageImageAccess::eImageSamples2DMSArrayU:
			config.requiresImageSamples2DMSArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd1DU:
			config.requiresImageAtomicAdd1DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd2DU:
			config.requiresImageAtomicAdd2DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd3DU:
			config.requiresImageAtomicAdd3DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAddCubeU:
			config.requiresImageAtomicAddCubeU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAddBufferU:
			config.requiresImageAtomicAddBufferU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd1DArrayU:
			config.requiresImageAtomicAdd1DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd2DArrayU:
			config.requiresImageAtomicAdd2DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAddCubeArrayU:
			config.requiresImageAtomicAddCubeArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSU:
			config.requiresImageAtomicAdd2DMSU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayU:
			config.requiresImageAtomicAdd2DMSArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd1DI:
			config.requiresImageAtomicAdd1DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd2DI:
			config.requiresImageAtomicAdd2DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd3DI:
			config.requiresImageAtomicAdd3DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAddCubeI:
			config.requiresImageAtomicAddCubeI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAddBufferI:
			config.requiresImageAtomicAddBufferI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd1DArrayI:
			config.requiresImageAtomicAdd1DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd2DArrayI:
			config.requiresImageAtomicAdd2DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAddCubeArrayI:
			config.requiresImageAtomicAddCubeArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSI:
			config.requiresImageAtomicAdd2DMSI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayI:
			config.requiresImageAtomicAdd2DMSArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin1DU:
			config.requiresImageAtomicMin1DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin2DU:
			config.requiresImageAtomicMin2DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin3DU:
			config.requiresImageAtomicMin3DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMinCubeU:
			config.requiresImageAtomicMinCubeU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMinBufferU:
			config.requiresImageAtomicMinBufferU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin1DArrayU:
			config.requiresImageAtomicMin1DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin2DArrayU:
			config.requiresImageAtomicMin2DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMinCubeArrayU:
			config.requiresImageAtomicMinCubeArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin2DMSU:
			config.requiresImageAtomicMin2DMSU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin2DMSArrayU:
			config.requiresImageAtomicMin2DMSArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin1DI:
			config.requiresImageAtomicMin1DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin2DI:
			config.requiresImageAtomicMin2DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin3DI:
			config.requiresImageAtomicMin3DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMinCubeI:
			config.requiresImageAtomicMinCubeI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMinBufferI:
			config.requiresImageAtomicMinBufferI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin1DArrayI:
			config.requiresImageAtomicMin1DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin2DArrayI:
			config.requiresImageAtomicMin2DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMinCubeArrayI:
			config.requiresImageAtomicMinCubeArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin2DMSI:
			config.requiresImageAtomicMin2DMSI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin2DMSArrayI:
			config.requiresImageAtomicMin2DMSArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax1DU:
			config.requiresImageAtomicMax1DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax2DU:
			config.requiresImageAtomicMax2DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax3DU:
			config.requiresImageAtomicMax3DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMaxCubeU:
			config.requiresImageAtomicMaxCubeU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMaxBufferU:
			config.requiresImageAtomicMaxBufferU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax1DArrayU:
			config.requiresImageAtomicMax1DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax2DArrayU:
			config.requiresImageAtomicMax2DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMaxCubeArrayU:
			config.requiresImageAtomicMaxCubeArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax2DMSU:
			config.requiresImageAtomicMax2DMSU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax2DMSArrayU:
			config.requiresImageAtomicMax2DMSArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax1DI:
			config.requiresImageAtomicMax1DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax2DI:
			config.requiresImageAtomicMax2DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax3DI:
			config.requiresImageAtomicMax3DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMaxCubeI:
			config.requiresImageAtomicMaxCubeI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMaxBufferI:
			config.requiresImageAtomicMaxBufferI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax1DArrayI:
			config.requiresImageAtomicMax1DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax2DArrayI:
			config.requiresImageAtomicMax2DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMaxCubeArrayI:
			config.requiresImageAtomicMaxCubeArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax2DMSI:
			config.requiresImageAtomicMax2DMSI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax2DMSArrayI:
			config.requiresImageAtomicMax2DMSArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd1DU:
			config.requiresImageAtomicAnd1DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd2DU:
			config.requiresImageAtomicAnd2DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd3DU:
			config.requiresImageAtomicAnd3DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAndCubeU:
			config.requiresImageAtomicAndCubeU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAndBufferU:
			config.requiresImageAtomicAndBufferU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd1DArrayU:
			config.requiresImageAtomicAnd1DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd2DArrayU:
			config.requiresImageAtomicAnd2DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAndCubeArrayU:
			config.requiresImageAtomicAndCubeArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSU:
			config.requiresImageAtomicAnd2DMSU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSArrayU:
			config.requiresImageAtomicAnd2DMSArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd1DI:
			config.requiresImageAtomicAnd1DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd2DI:
			config.requiresImageAtomicAnd2DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd3DI:
			config.requiresImageAtomicAnd3DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAndCubeI:
			config.requiresImageAtomicAndCubeI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAndBufferI:
			config.requiresImageAtomicAndBufferI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd1DArrayI:
			config.requiresImageAtomicAnd1DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd2DArrayI:
			config.requiresImageAtomicAnd2DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAndCubeArrayI:
			config.requiresImageAtomicAndCubeArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSI:
			config.requiresImageAtomicAnd2DMSI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSArrayI:
			config.requiresImageAtomicAnd2DMSArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr1DU:
			config.requiresImageAtomicOr1DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr2DU:
			config.requiresImageAtomicOr2DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr3DU:
			config.requiresImageAtomicOr3DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOrCubeU:
			config.requiresImageAtomicOrCubeU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOrBufferU:
			config.requiresImageAtomicOrBufferU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr1DArrayU:
			config.requiresImageAtomicOr1DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr2DArrayU:
			config.requiresImageAtomicOr2DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOrCubeArrayU:
			config.requiresImageAtomicOrCubeArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr2DMSU:
			config.requiresImageAtomicOr2DMSU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr2DMSArrayU:
			config.requiresImageAtomicOr2DMSArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr1DI:
			config.requiresImageAtomicOr1DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr2DI:
			config.requiresImageAtomicOr2DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr3DI:
			config.requiresImageAtomicOr3DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOrCubeI:
			config.requiresImageAtomicOrCubeI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOrBufferI:
			config.requiresImageAtomicOrBufferI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr1DArrayI:
			config.requiresImageAtomicOr1DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr2DArrayI:
			config.requiresImageAtomicOr2DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOrCubeArrayI:
			config.requiresImageAtomicOrCubeArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr2DMSI:
			config.requiresImageAtomicOr2DMSI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr2DMSArrayI:
			config.requiresImageAtomicOr2DMSArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor1DU:
			config.requiresImageAtomicXor1DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor2DU:
			config.requiresImageAtomicXor2DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor3DU:
			config.requiresImageAtomicXor3DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXorCubeU:
			config.requiresImageAtomicXorCubeU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXorBufferU:
			config.requiresImageAtomicXorBufferU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor1DArrayU:
			config.requiresImageAtomicXor1DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor2DArrayU:
			config.requiresImageAtomicXor2DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXorCubeArrayU:
			config.requiresImageAtomicXorCubeArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor2DMSU:
			config.requiresImageAtomicXor2DMSU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor2DMSArrayU:
			config.requiresImageAtomicXor2DMSArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor1DI:
			config.requiresImageAtomicXor1DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor2DI:
			config.requiresImageAtomicXor2DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor3DI:
			config.requiresImageAtomicXor3DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXorCubeI:
			config.requiresImageAtomicXorCubeI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXorBufferI:
			config.requiresImageAtomicXorBufferI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor1DArrayI:
			config.requiresImageAtomicXor1DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor2DArrayI:
			config.requiresImageAtomicXor2DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXorCubeArrayI:
			config.requiresImageAtomicXorCubeArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor2DMSI:
			config.requiresImageAtomicXor2DMSI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor2DMSArrayI:
			config.requiresImageAtomicXor2DMSArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange1DU:
			config.requiresImageAtomicExchange1DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange2DU:
			config.requiresImageAtomicExchange2DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange3DU:
			config.requiresImageAtomicExchange3DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeU:
			config.requiresImageAtomicExchangeCubeU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchangeBufferU:
			config.requiresImageAtomicExchangeBufferU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange1DArrayU:
			config.requiresImageAtomicExchange1DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange2DArrayU:
			config.requiresImageAtomicExchange2DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeArrayU:
			config.requiresImageAtomicExchangeCubeArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSU:
			config.requiresImageAtomicExchange2DMSU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayU:
			config.requiresImageAtomicExchange2DMSArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange1DI:
			config.requiresImageAtomicExchange1DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange2DI:
			config.requiresImageAtomicExchange2DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange3DI:
			config.requiresImageAtomicExchange3DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeI:
			config.requiresImageAtomicExchangeCubeI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchangeBufferI:
			config.requiresImageAtomicExchangeBufferI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange1DArrayI:
			config.requiresImageAtomicExchange1DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange2DArrayI:
			config.requiresImageAtomicExchange2DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeArrayI:
			config.requiresImageAtomicExchangeCubeArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSI:
			config.requiresImageAtomicExchange2DMSI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayI:
			config.requiresImageAtomicExchange2DMSArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DU:
			config.requiresImageAtomicCompSwap1DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DU:
			config.requiresImageAtomicCompSwap2DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap3DU:
			config.requiresImageAtomicCompSwap3DU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeU:
			config.requiresImageAtomicCompSwapCubeU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwapBufferU:
			config.requiresImageAtomicCompSwapBufferU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DArrayU:
			config.requiresImageAtomicCompSwap1DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DArrayU:
			config.requiresImageAtomicCompSwap2DArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeArrayU:
			config.requiresImageAtomicCompSwapCubeArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSU:
			config.requiresImageAtomicCompSwap2DMSU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSArrayU:
			config.requiresImageAtomicCompSwap2DMSArrayU = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DI:
			config.requiresImageAtomicCompSwap1DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DI:
			config.requiresImageAtomicCompSwap2DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap3DI:
			config.requiresImageAtomicCompSwap3DI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeI:
			config.requiresImageAtomicCompSwapCubeI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwapBufferI:
			config.requiresImageAtomicCompSwapBufferI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DArrayI:
			config.requiresImageAtomicCompSwap1DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DArrayI:
			config.requiresImageAtomicCompSwap2DArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeArrayI:
			config.requiresImageAtomicCompSwapCubeArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSI:
			config.requiresImageAtomicCompSwap2DMSI = true;
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSArrayI:
			config.requiresImageAtomicCompSwap2DMSArrayI = true;
			break;

		case ast::expr::StorageImageAccess::eImageLoad1DF:
		case ast::expr::StorageImageAccess::eImageLoad2DF:
		case ast::expr::StorageImageAccess::eImageLoad3DF:
		case ast::expr::StorageImageAccess::eImageLoadCubeF:
		case ast::expr::StorageImageAccess::eImageLoadBufferF:
		case ast::expr::StorageImageAccess::eImageLoad1DArrayF:
		case ast::expr::StorageImageAccess::eImageLoad2DArrayF:
		case ast::expr::StorageImageAccess::eImageLoadCubeArrayF:
		case ast::expr::StorageImageAccess::eImageLoad2DMSF:
		case ast::expr::StorageImageAccess::eImageLoad2DMSArrayF:
		case ast::expr::StorageImageAccess::eImageLoad1DI:
		case ast::expr::StorageImageAccess::eImageLoad2DI:
		case ast::expr::StorageImageAccess::eImageLoad3DI:
		case ast::expr::StorageImageAccess::eImageLoadCubeI:
		case ast::expr::StorageImageAccess::eImageLoadBufferI:
		case ast::expr::StorageImageAccess::eImageLoad1DArrayI:
		case ast::expr::StorageImageAccess::eImageLoad2DArrayI:
		case ast::expr::StorageImageAccess::eImageLoadCubeArrayI:
		case ast::expr::StorageImageAccess::eImageLoad2DMSI:
		case ast::expr::StorageImageAccess::eImageLoad2DMSArrayI:
		case ast::expr::StorageImageAccess::eImageLoad1DU:
		case ast::expr::StorageImageAccess::eImageLoad2DU:
		case ast::expr::StorageImageAccess::eImageLoad3DU:
		case ast::expr::StorageImageAccess::eImageLoadCubeU:
		case ast::expr::StorageImageAccess::eImageLoadBufferU:
		case ast::expr::StorageImageAccess::eImageLoad1DArrayU:
		case ast::expr::StorageImageAccess::eImageLoad2DArrayU:
		case ast::expr::StorageImageAccess::eImageLoadCubeArrayU:
		case ast::expr::StorageImageAccess::eImageLoad2DMSU:
		case ast::expr::StorageImageAccess::eImageLoad2DMSArrayU:
			break;

		case ast::expr::StorageImageAccess::eImageStore1DF:
		case ast::expr::StorageImageAccess::eImageStore2DF:
		case ast::expr::StorageImageAccess::eImageStore3DF:
		case ast::expr::StorageImageAccess::eImageStoreCubeF:
		case ast::expr::StorageImageAccess::eImageStoreBufferF:
		case ast::expr::StorageImageAccess::eImageStore1DArrayF:
		case ast::expr::StorageImageAccess::eImageStore2DArrayF:
		case ast::expr::StorageImageAccess::eImageStoreCubeArrayF:
		case ast::expr::StorageImageAccess::eImageStore2DMSF:
		case ast::expr::StorageImageAccess::eImageStore2DMSArrayF:
		case ast::expr::StorageImageAccess::eImageStore1DI:
		case ast::expr::StorageImageAccess::eImageStore2DI:
		case ast::expr::StorageImageAccess::eImageStore3DI:
		case ast::expr::StorageImageAccess::eImageStoreCubeI:
		case ast::expr::StorageImageAccess::eImageStoreBufferI:
		case ast::expr::StorageImageAccess::eImageStore1DArrayI:
		case ast::expr::StorageImageAccess::eImageStore2DArrayI:
		case ast::expr::StorageImageAccess::eImageStoreCubeArrayI:
		case ast::expr::StorageImageAccess::eImageStore2DMSI:
		case ast::expr::StorageImageAccess::eImageStore2DMSArrayI:
		case ast::expr::StorageImageAccess::eImageStore1DU:
		case ast::expr::StorageImageAccess::eImageStore2DU:
		case ast::expr::StorageImageAccess::eImageStore3DU:
		case ast::expr::StorageImageAccess::eImageStoreCubeU:
		case ast::expr::StorageImageAccess::eImageStoreBufferU:
		case ast::expr::StorageImageAccess::eImageStore1DArrayU:
		case ast::expr::StorageImageAccess::eImageStore2DArrayU:
		case ast::expr::StorageImageAccess::eImageStoreCubeArrayU:
		case ast::expr::StorageImageAccess::eImageStore2DMSU:
		case ast::expr::StorageImageAccess::eImageStore2DMSArrayU:
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd1DF:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DF:
		case ast::expr::StorageImageAccess::eImageAtomicAdd3DF:
		case ast::expr::StorageImageAccess::eImageAtomicAddCubeF:
		case ast::expr::StorageImageAccess::eImageAtomicAddBufferF:
		case ast::expr::StorageImageAccess::eImageAtomicAdd1DArrayF:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DArrayF:
		case ast::expr::StorageImageAccess::eImageAtomicAddCubeArrayF:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSF:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayF:
		case ast::expr::StorageImageAccess::eImageAtomicExchange1DF:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DF:
		case ast::expr::StorageImageAccess::eImageAtomicExchange3DF:
		case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeF:
		case ast::expr::StorageImageAccess::eImageAtomicExchangeBufferF:
		case ast::expr::StorageImageAccess::eImageAtomicExchange1DArrayF:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DArrayF:
		case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeArrayF:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSF:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayF:
			throw ast::Exception{ "Unsupported Intrinsic type in HLSL." };

		default:
			AST_Failure( "Unsupported StorageImageAccess" );
			break;
		}
	}
}

#endif
