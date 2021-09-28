/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslImageAccessConfig_H___
#define ___AST_HlslImageAccessConfig_H___
#pragma once

#include "HlslHelpers.hpp"

#include <ShaderAST/Expr/EnumImageAccess.hpp>

namespace hlsl
{
	inline void getHlslConfig( ast::expr::ImageAccess value
		, IntrinsicsConfig & config )
	{
		std::string result;

		switch ( value )
		{
		case ast::expr::ImageAccess::eImageSize1DF:
			config.requiresImageSize1DF = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DF:
			config.requiresImageSize2DF = true;
			break;

		case ast::expr::ImageAccess::eImageSize3DF:
			config.requiresImageSize3DF = true;
			break;

		case ast::expr::ImageAccess::eImageSizeCubeF:
			config.requiresImageSizeCubeF = true;
			break;

		case ast::expr::ImageAccess::eImageSizeCubeArrayF:
			config.requiresImageSizeCubeArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DRectF:
			config.requiresImageSize2DRectF = true;
			break;

		case ast::expr::ImageAccess::eImageSize1DArrayF:
			config.requiresImageSize1DArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DArrayF:
			config.requiresImageSize2DArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageSizeBufferF:
			config.requiresImageSizeBufferF = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DMSF:
			config.requiresImageSize2DMSF = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DMSArrayF:
			config.requiresImageSize2DMSArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageSize1DI:
			config.requiresImageSize1DI = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DI:
			config.requiresImageSize2DI = true;
			break;

		case ast::expr::ImageAccess::eImageSize3DI:
			config.requiresImageSize3DI = true;
			break;

		case ast::expr::ImageAccess::eImageSizeCubeI:
			config.requiresImageSizeCubeI = true;
			break;

		case ast::expr::ImageAccess::eImageSizeCubeArrayI:
			config.requiresImageSizeCubeArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DRectI:
			config.requiresImageSize2DRectI = true;
			break;

		case ast::expr::ImageAccess::eImageSize1DArrayI:
			config.requiresImageSize1DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DArrayI:
			config.requiresImageSize2DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageSizeBufferI:
			config.requiresImageSizeBufferI = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DMSI:
			config.requiresImageSize2DMSI = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DMSArrayI:
			config.requiresImageSize2DMSArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageSize1DU:
			config.requiresImageSize1DU = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DU:
			config.requiresImageSize2DU = true;
			break;

		case ast::expr::ImageAccess::eImageSize3DU:
			config.requiresImageSize3DU = true;
			break;

		case ast::expr::ImageAccess::eImageSizeCubeU:
			config.requiresImageSizeCubeU = true;
			break;

		case ast::expr::ImageAccess::eImageSizeCubeArrayU:
			config.requiresImageSizeCubeArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DRectU:
			config.requiresImageSize2DRectU = true;
			break;

		case ast::expr::ImageAccess::eImageSize1DArrayU:
			config.requiresImageSize1DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DArrayU:
			config.requiresImageSize2DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageSizeBufferU:
			config.requiresImageSizeBufferU = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DMSU:
			config.requiresImageSize2DMSU = true;
			break;

		case ast::expr::ImageAccess::eImageSize2DMSArrayU:
			config.requiresImageSize2DMSArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageSamples2DMSF:
			config.requiresImageSamples2DMSF = true;
			break;

		case ast::expr::ImageAccess::eImageSamples2DMSArrayF:
			config.requiresImageSamples2DMSArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageSamples2DMSI:
			config.requiresImageSamples2DMSI = true;
			break;

		case ast::expr::ImageAccess::eImageSamples2DMSArrayI:
			config.requiresImageSamples2DMSArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageSamples2DMSU:
			config.requiresImageSamples2DMSU = true;
			break;

		case ast::expr::ImageAccess::eImageSamples2DMSArrayU:
			config.requiresImageSamples2DMSArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DU:
			config.requiresImageAtomicAdd1DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DU:
			config.requiresImageAtomicAdd2DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DU:
			config.requiresImageAtomicAdd3DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectU:
			config.requiresImageAtomicAdd2DRectU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeU:
			config.requiresImageAtomicAddCubeU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferU:
			config.requiresImageAtomicAddBufferU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayU:
			config.requiresImageAtomicAdd1DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayU:
			config.requiresImageAtomicAdd2DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayU:
			config.requiresImageAtomicAddCubeArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSU:
			config.requiresImageAtomicAdd2DMSU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayU:
			config.requiresImageAtomicAdd2DMSArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DI:
			config.requiresImageAtomicAdd1DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DI:
			config.requiresImageAtomicAdd2DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DI:
			config.requiresImageAtomicAdd3DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectI:
			config.requiresImageAtomicAdd2DRectI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeI:
			config.requiresImageAtomicAddCubeI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferI:
			config.requiresImageAtomicAddBufferI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayI:
			config.requiresImageAtomicAdd1DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayI:
			config.requiresImageAtomicAdd2DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayI:
			config.requiresImageAtomicAddCubeArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSI:
			config.requiresImageAtomicAdd2DMSI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayI:
			config.requiresImageAtomicAdd2DMSArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DF:
			config.requiresImageAtomicAdd1DF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DF:
			config.requiresImageAtomicAdd2DF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DF:
			config.requiresImageAtomicAdd3DF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectF:
			config.requiresImageAtomicAdd2DRectF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeF:
			config.requiresImageAtomicAddCubeF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferF:
			config.requiresImageAtomicAddBufferF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayF:
			config.requiresImageAtomicAdd1DArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayF:
			config.requiresImageAtomicAdd2DArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayF:
			config.requiresImageAtomicAddCubeArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSF:
			config.requiresImageAtomicAdd2DMSF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayF:
			config.requiresImageAtomicAdd2DMSArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DU:
			config.requiresImageAtomicMin1DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DU:
			config.requiresImageAtomicMin2DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DU:
			config.requiresImageAtomicMin3DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectU:
			config.requiresImageAtomicMin2DRectU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeU:
			config.requiresImageAtomicMinCubeU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferU:
			config.requiresImageAtomicMinBufferU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayU:
			config.requiresImageAtomicMin1DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayU:
			config.requiresImageAtomicMin2DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayU:
			config.requiresImageAtomicMinCubeArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSU:
			config.requiresImageAtomicMin2DMSU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayU:
			config.requiresImageAtomicMin2DMSArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DI:
			config.requiresImageAtomicMin1DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DI:
			config.requiresImageAtomicMin2DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DI:
			config.requiresImageAtomicMin3DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectI:
			config.requiresImageAtomicMin2DRectI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeI:
			config.requiresImageAtomicMinCubeI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferI:
			config.requiresImageAtomicMinBufferI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayI:
			config.requiresImageAtomicMin1DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayI:
			config.requiresImageAtomicMin2DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayI:
			config.requiresImageAtomicMinCubeArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSI:
			config.requiresImageAtomicMin2DMSI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayI:
			config.requiresImageAtomicMin2DMSArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DU:
			config.requiresImageAtomicMax1DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DU:
			config.requiresImageAtomicMax2DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DU:
			config.requiresImageAtomicMax3DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectU:
			config.requiresImageAtomicMax2DRectU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeU:
			config.requiresImageAtomicMaxCubeU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferU:
			config.requiresImageAtomicMaxBufferU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayU:
			config.requiresImageAtomicMax1DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayU:
			config.requiresImageAtomicMax2DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayU:
			config.requiresImageAtomicMaxCubeArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSU:
			config.requiresImageAtomicMax2DMSU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayU:
			config.requiresImageAtomicMax2DMSArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DI:
			config.requiresImageAtomicMax1DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DI:
			config.requiresImageAtomicMax2DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DI:
			config.requiresImageAtomicMax3DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectI:
			config.requiresImageAtomicMax2DRectI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeI:
			config.requiresImageAtomicMaxCubeI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferI:
			config.requiresImageAtomicMaxBufferI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayI:
			config.requiresImageAtomicMax1DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayI:
			config.requiresImageAtomicMax2DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayI:
			config.requiresImageAtomicMaxCubeArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSI:
			config.requiresImageAtomicMax2DMSI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayI:
			config.requiresImageAtomicMax2DMSArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DU:
			config.requiresImageAtomicAnd1DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DU:
			config.requiresImageAtomicAnd2DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DU:
			config.requiresImageAtomicAnd3DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectU:
			config.requiresImageAtomicAnd2DRectU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeU:
			config.requiresImageAtomicAndCubeU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferU:
			config.requiresImageAtomicAndBufferU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayU:
			config.requiresImageAtomicAnd1DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayU:
			config.requiresImageAtomicAnd2DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayU:
			config.requiresImageAtomicAndCubeArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSU:
			config.requiresImageAtomicAnd2DMSU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayU:
			config.requiresImageAtomicAnd2DMSArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DI:
			config.requiresImageAtomicAnd1DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DI:
			config.requiresImageAtomicAnd2DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DI:
			config.requiresImageAtomicAnd3DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectI:
			config.requiresImageAtomicAnd2DRectI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeI:
			config.requiresImageAtomicAndCubeI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferI:
			config.requiresImageAtomicAndBufferI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayI:
			config.requiresImageAtomicAnd1DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayI:
			config.requiresImageAtomicAnd2DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayI:
			config.requiresImageAtomicAndCubeArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSI:
			config.requiresImageAtomicAnd2DMSI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayI:
			config.requiresImageAtomicAnd2DMSArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DU:
			config.requiresImageAtomicOr1DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DU:
			config.requiresImageAtomicOr2DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DU:
			config.requiresImageAtomicOr3DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectU:
			config.requiresImageAtomicOr2DRectU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeU:
			config.requiresImageAtomicOrCubeU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferU:
			config.requiresImageAtomicOrBufferU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayU:
			config.requiresImageAtomicOr1DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayU:
			config.requiresImageAtomicOr2DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayU:
			config.requiresImageAtomicOrCubeArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSU:
			config.requiresImageAtomicOr2DMSU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayU:
			config.requiresImageAtomicOr2DMSArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DI:
			config.requiresImageAtomicOr1DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DI:
			config.requiresImageAtomicOr2DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DI:
			config.requiresImageAtomicOr3DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectI:
			config.requiresImageAtomicOr2DRectI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeI:
			config.requiresImageAtomicOrCubeI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferI:
			config.requiresImageAtomicOrBufferI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayI:
			config.requiresImageAtomicOr1DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayI:
			config.requiresImageAtomicOr2DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayI:
			config.requiresImageAtomicOrCubeArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSI:
			config.requiresImageAtomicOr2DMSI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayI:
			config.requiresImageAtomicOr2DMSArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DU:
			config.requiresImageAtomicXor1DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DU:
			config.requiresImageAtomicXor2DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DU:
			config.requiresImageAtomicXor3DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectU:
			config.requiresImageAtomicXor2DRectU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeU:
			config.requiresImageAtomicXorCubeU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferU:
			config.requiresImageAtomicXorBufferU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayU:
			config.requiresImageAtomicXor1DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayU:
			config.requiresImageAtomicXor2DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayU:
			config.requiresImageAtomicXorCubeArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSU:
			config.requiresImageAtomicXor2DMSU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayU:
			config.requiresImageAtomicXor2DMSArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DI:
			config.requiresImageAtomicXor1DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DI:
			config.requiresImageAtomicXor2DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DI:
			config.requiresImageAtomicXor3DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectI:
			config.requiresImageAtomicXor2DRectI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeI:
			config.requiresImageAtomicXorCubeI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferI:
			config.requiresImageAtomicXorBufferI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayI:
			config.requiresImageAtomicXor1DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayI:
			config.requiresImageAtomicXor2DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayI:
			config.requiresImageAtomicXorCubeArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSI:
			config.requiresImageAtomicXor2DMSI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayI:
			config.requiresImageAtomicXor2DMSArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DU:
			config.requiresImageAtomicExchange1DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DU:
			config.requiresImageAtomicExchange2DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DU:
			config.requiresImageAtomicExchange3DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectU:
			config.requiresImageAtomicExchange2DRectU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeU:
			config.requiresImageAtomicExchangeCubeU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferU:
			config.requiresImageAtomicExchangeBufferU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayU:
			config.requiresImageAtomicExchange1DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayU:
			config.requiresImageAtomicExchange2DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayU:
			config.requiresImageAtomicExchangeCubeArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSU:
			config.requiresImageAtomicExchange2DMSU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayU:
			config.requiresImageAtomicExchange2DMSArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DI:
			config.requiresImageAtomicExchange1DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DI:
			config.requiresImageAtomicExchange2DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DI:
			config.requiresImageAtomicExchange3DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectI:
			config.requiresImageAtomicExchange2DRectI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeI:
			config.requiresImageAtomicExchangeCubeI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferI:
			config.requiresImageAtomicExchangeBufferI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayI:
			config.requiresImageAtomicExchange1DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayI:
			config.requiresImageAtomicExchange2DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayI:
			config.requiresImageAtomicExchangeCubeArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSI:
			config.requiresImageAtomicExchange2DMSI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayI:
			config.requiresImageAtomicExchange2DMSArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DF:
			config.requiresImageAtomicExchange1DF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DF:
			config.requiresImageAtomicExchange2DF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DF:
			config.requiresImageAtomicExchange3DF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectF:
			config.requiresImageAtomicExchange2DRectF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeF:
			config.requiresImageAtomicExchangeCubeF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferF:
			config.requiresImageAtomicExchangeBufferF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayF:
			config.requiresImageAtomicExchange1DArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayF:
			config.requiresImageAtomicExchange2DArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayF:
			config.requiresImageAtomicExchangeCubeArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSF:
			config.requiresImageAtomicExchange2DMSF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayF:
			config.requiresImageAtomicExchange2DMSArrayF = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DU:
			config.requiresImageAtomicCompSwap1DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DU:
			config.requiresImageAtomicCompSwap2DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DU:
			config.requiresImageAtomicCompSwap3DU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectU:
			config.requiresImageAtomicCompSwap2DRectU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeU:
			config.requiresImageAtomicCompSwapCubeU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferU:
			config.requiresImageAtomicCompSwapBufferU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayU:
			config.requiresImageAtomicCompSwap1DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayU:
			config.requiresImageAtomicCompSwap2DArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayU:
			config.requiresImageAtomicCompSwapCubeArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSU:
			config.requiresImageAtomicCompSwap2DMSU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayU:
			config.requiresImageAtomicCompSwap2DMSArrayU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DI:
			config.requiresImageAtomicCompSwap1DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DI:
			config.requiresImageAtomicCompSwap2DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DI:
			config.requiresImageAtomicCompSwap3DI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectI:
			config.requiresImageAtomicCompSwap2DRectI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeI:
			config.requiresImageAtomicCompSwapCubeI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferI:
			config.requiresImageAtomicCompSwapBufferI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayI:
			config.requiresImageAtomicCompSwap1DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayI:
			config.requiresImageAtomicCompSwap2DArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayI:
			config.requiresImageAtomicCompSwapCubeArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSI:
			config.requiresImageAtomicCompSwap2DMSI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayI:
			config.requiresImageAtomicCompSwap2DMSArrayI = true;
			break;

		case ast::expr::ImageAccess::eImageLoad1DF:
		case ast::expr::ImageAccess::eImageLoad2DF:
		case ast::expr::ImageAccess::eImageLoad3DF:
		case ast::expr::ImageAccess::eImageLoad2DRectF:
		case ast::expr::ImageAccess::eImageLoadCubeF:
		case ast::expr::ImageAccess::eImageLoadBufferF:
		case ast::expr::ImageAccess::eImageLoad1DArrayF:
		case ast::expr::ImageAccess::eImageLoad2DArrayF:
		case ast::expr::ImageAccess::eImageLoadCubeArrayF:
		case ast::expr::ImageAccess::eImageLoad2DMSF:
		case ast::expr::ImageAccess::eImageLoad2DMSArrayF:
		case ast::expr::ImageAccess::eImageLoad1DI:
		case ast::expr::ImageAccess::eImageLoad2DI:
		case ast::expr::ImageAccess::eImageLoad3DI:
		case ast::expr::ImageAccess::eImageLoad2DRectI:
		case ast::expr::ImageAccess::eImageLoadCubeI:
		case ast::expr::ImageAccess::eImageLoadBufferI:
		case ast::expr::ImageAccess::eImageLoad1DArrayI:
		case ast::expr::ImageAccess::eImageLoad2DArrayI:
		case ast::expr::ImageAccess::eImageLoadCubeArrayI:
		case ast::expr::ImageAccess::eImageLoad2DMSI:
		case ast::expr::ImageAccess::eImageLoad2DMSArrayI:
		case ast::expr::ImageAccess::eImageLoad1DU:
		case ast::expr::ImageAccess::eImageLoad2DU:
		case ast::expr::ImageAccess::eImageLoad3DU:
		case ast::expr::ImageAccess::eImageLoad2DRectU:
		case ast::expr::ImageAccess::eImageLoadCubeU:
		case ast::expr::ImageAccess::eImageLoadBufferU:
		case ast::expr::ImageAccess::eImageLoad1DArrayU:
		case ast::expr::ImageAccess::eImageLoad2DArrayU:
		case ast::expr::ImageAccess::eImageLoadCubeArrayU:
		case ast::expr::ImageAccess::eImageLoad2DMSU:
		case ast::expr::ImageAccess::eImageLoad2DMSArrayU:
			break;

		case ast::expr::ImageAccess::eImageStore1DF:
		case ast::expr::ImageAccess::eImageStore2DF:
		case ast::expr::ImageAccess::eImageStore3DF:
		case ast::expr::ImageAccess::eImageStore2DRectF:
		case ast::expr::ImageAccess::eImageStoreCubeF:
		case ast::expr::ImageAccess::eImageStoreBufferF:
		case ast::expr::ImageAccess::eImageStore1DArrayF:
		case ast::expr::ImageAccess::eImageStore2DArrayF:
		case ast::expr::ImageAccess::eImageStoreCubeArrayF:
		case ast::expr::ImageAccess::eImageStore2DMSF:
		case ast::expr::ImageAccess::eImageStore2DMSArrayF:
		case ast::expr::ImageAccess::eImageStore1DI:
		case ast::expr::ImageAccess::eImageStore2DI:
		case ast::expr::ImageAccess::eImageStore3DI:
		case ast::expr::ImageAccess::eImageStore2DRectI:
		case ast::expr::ImageAccess::eImageStoreCubeI:
		case ast::expr::ImageAccess::eImageStoreBufferI:
		case ast::expr::ImageAccess::eImageStore1DArrayI:
		case ast::expr::ImageAccess::eImageStore2DArrayI:
		case ast::expr::ImageAccess::eImageStoreCubeArrayI:
		case ast::expr::ImageAccess::eImageStore2DMSI:
		case ast::expr::ImageAccess::eImageStore2DMSArrayI:
		case ast::expr::ImageAccess::eImageStore1DU:
		case ast::expr::ImageAccess::eImageStore2DU:
		case ast::expr::ImageAccess::eImageStore3DU:
		case ast::expr::ImageAccess::eImageStore2DRectU:
		case ast::expr::ImageAccess::eImageStoreCubeU:
		case ast::expr::ImageAccess::eImageStoreBufferU:
		case ast::expr::ImageAccess::eImageStore1DArrayU:
		case ast::expr::ImageAccess::eImageStore2DArrayU:
		case ast::expr::ImageAccess::eImageStoreCubeArrayU:
		case ast::expr::ImageAccess::eImageStore2DMSU:
		case ast::expr::ImageAccess::eImageStore2DMSArrayU:
			break;

		default:
			AST_Failure( "Unsupported ImageAccess" );
			break;
		}
	}
}

#endif
