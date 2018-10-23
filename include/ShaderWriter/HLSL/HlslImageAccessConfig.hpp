/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslImageAccessConfig_H___
#define ___AST_HlslImageAccessConfig_H___
#pragma once

#include "HlslHelpers.hpp"

#include <ASTGenerator/Expr/EnumImageAccess.hpp>

#include <string>

namespace sdw::hlsl
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

		case ast::expr::ImageAccess::eImageAtomicAdd1DFU:
			config.requiresImageAtomicAdd1DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DFU:
			config.requiresImageAtomicAdd2DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DFU:
			config.requiresImageAtomicAdd3DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectFU:
			config.requiresImageAtomicAdd2DRectFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeFU:
			config.requiresImageAtomicAddCubeFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferFU:
			config.requiresImageAtomicAddBufferFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayFU:
			config.requiresImageAtomicAdd1DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayFU:
			config.requiresImageAtomicAdd2DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayFU:
			config.requiresImageAtomicAddCubeArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSFU:
			config.requiresImageAtomicAdd2DMSFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayFU:
			config.requiresImageAtomicAdd2DMSArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DIU:
			config.requiresImageAtomicAdd1DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DIU:
			config.requiresImageAtomicAdd2DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DIU:
			config.requiresImageAtomicAdd3DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectIU:
			config.requiresImageAtomicAdd2DRectIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeIU:
			config.requiresImageAtomicAddCubeIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferIU:
			config.requiresImageAtomicAddBufferIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayIU:
			config.requiresImageAtomicAdd1DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayIU:
			config.requiresImageAtomicAdd2DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayIU:
			config.requiresImageAtomicAddCubeArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSIU:
			config.requiresImageAtomicAdd2DMSIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayIU:
			config.requiresImageAtomicAdd2DMSArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DUU:
			config.requiresImageAtomicAdd1DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DUU:
			config.requiresImageAtomicAdd2DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DUU:
			config.requiresImageAtomicAdd3DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectUU:
			config.requiresImageAtomicAdd2DRectUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeUU:
			config.requiresImageAtomicAddCubeUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferUU:
			config.requiresImageAtomicAddBufferUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayUU:
			config.requiresImageAtomicAdd1DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayUU:
			config.requiresImageAtomicAdd2DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayUU:
			config.requiresImageAtomicAddCubeArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSUU:
			config.requiresImageAtomicAdd2DMSUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayUU:
			config.requiresImageAtomicAdd2DMSArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DFI:
			config.requiresImageAtomicAdd1DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DFI:
			config.requiresImageAtomicAdd2DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DFI:
			config.requiresImageAtomicAdd3DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectFI:
			config.requiresImageAtomicAdd2DRectFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeFI:
			config.requiresImageAtomicAddCubeFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferFI:
			config.requiresImageAtomicAddBufferFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayFI:
			config.requiresImageAtomicAdd1DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayFI:
			config.requiresImageAtomicAdd2DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayFI:
			config.requiresImageAtomicAddCubeArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSFI:
			config.requiresImageAtomicAdd2DMSFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayFI:
			config.requiresImageAtomicAdd2DMSArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DII:
			config.requiresImageAtomicAdd1DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DII:
			config.requiresImageAtomicAdd2DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DII:
			config.requiresImageAtomicAdd3DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectII:
			config.requiresImageAtomicAdd2DRectII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeII:
			config.requiresImageAtomicAddCubeII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferII:
			config.requiresImageAtomicAddBufferII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayII:
			config.requiresImageAtomicAdd1DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayII:
			config.requiresImageAtomicAdd2DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayII:
			config.requiresImageAtomicAddCubeArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSII:
			config.requiresImageAtomicAdd2DMSII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayII:
			config.requiresImageAtomicAdd2DMSArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DUI:
			config.requiresImageAtomicAdd1DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DUI:
			config.requiresImageAtomicAdd2DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DUI:
			config.requiresImageAtomicAdd3DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectUI:
			config.requiresImageAtomicAdd2DRectUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeUI:
			config.requiresImageAtomicAddCubeUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferUI:
			config.requiresImageAtomicAddBufferUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayUI:
			config.requiresImageAtomicAdd1DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayUI:
			config.requiresImageAtomicAdd2DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayUI:
			config.requiresImageAtomicAddCubeArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSUI:
			config.requiresImageAtomicAdd2DMSUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayUI:
			config.requiresImageAtomicAdd2DMSArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DFU:
			config.requiresImageAtomicMin1DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DFU:
			config.requiresImageAtomicMin2DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DFU:
			config.requiresImageAtomicMin3DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectFU:
			config.requiresImageAtomicMin2DRectFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeFU:
			config.requiresImageAtomicMinCubeFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferFU:
			config.requiresImageAtomicMinBufferFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayFU:
			config.requiresImageAtomicMin1DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayFU:
			config.requiresImageAtomicMin2DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayFU:
			config.requiresImageAtomicMinCubeArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSFU:
			config.requiresImageAtomicMin2DMSFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayFU:
			config.requiresImageAtomicMin2DMSArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DIU:
			config.requiresImageAtomicMin1DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DIU:
			config.requiresImageAtomicMin2DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DIU:
			config.requiresImageAtomicMin3DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectIU:
			config.requiresImageAtomicMin2DRectIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeIU:
			config.requiresImageAtomicMinCubeIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferIU:
			config.requiresImageAtomicMinBufferIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayIU:
			config.requiresImageAtomicMin1DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayIU:
			config.requiresImageAtomicMin2DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayIU:
			config.requiresImageAtomicMinCubeArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSIU:
			config.requiresImageAtomicMin2DMSIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayIU:
			config.requiresImageAtomicMin2DMSArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DUU:
			config.requiresImageAtomicMin1DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DUU:
			config.requiresImageAtomicMin2DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DUU:
			config.requiresImageAtomicMin3DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectUU:
			config.requiresImageAtomicMin2DRectUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeUU:
			config.requiresImageAtomicMinCubeUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferUU:
			config.requiresImageAtomicMinBufferUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayUU:
			config.requiresImageAtomicMin1DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayUU:
			config.requiresImageAtomicMin2DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayUU:
			config.requiresImageAtomicMinCubeArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSUU:
			config.requiresImageAtomicMin2DMSUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayUU:
			config.requiresImageAtomicMin2DMSArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DFI:
			config.requiresImageAtomicMin1DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DFI:
			config.requiresImageAtomicMin2DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DFI:
			config.requiresImageAtomicMin3DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectFI:
			config.requiresImageAtomicMin2DRectFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeFI:
			config.requiresImageAtomicMinCubeFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferFI:
			config.requiresImageAtomicMinBufferFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayFI:
			config.requiresImageAtomicMin1DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayFI:
			config.requiresImageAtomicMin2DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayFI:
			config.requiresImageAtomicMinCubeArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSFI:
			config.requiresImageAtomicMin2DMSFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayFI:
			config.requiresImageAtomicMin2DMSArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DII:
			config.requiresImageAtomicMin1DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DII:
			config.requiresImageAtomicMin2DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DII:
			config.requiresImageAtomicMin3DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectII:
			config.requiresImageAtomicMin2DRectII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeII:
			config.requiresImageAtomicMinCubeII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferII:
			config.requiresImageAtomicMinBufferII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayII:
			config.requiresImageAtomicMin1DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayII:
			config.requiresImageAtomicMin2DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayII:
			config.requiresImageAtomicMinCubeArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSII:
			config.requiresImageAtomicMin2DMSII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayII:
			config.requiresImageAtomicMin2DMSArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DUI:
			config.requiresImageAtomicMin1DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DUI:
			config.requiresImageAtomicMin2DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DUI:
			config.requiresImageAtomicMin3DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectUI:
			config.requiresImageAtomicMin2DRectUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeUI:
			config.requiresImageAtomicMinCubeUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferUI:
			config.requiresImageAtomicMinBufferUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayUI:
			config.requiresImageAtomicMin1DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayUI:
			config.requiresImageAtomicMin2DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayUI:
			config.requiresImageAtomicMinCubeArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSUI:
			config.requiresImageAtomicMin2DMSUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayUI:
			config.requiresImageAtomicMin2DMSArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DFU:
			config.requiresImageAtomicMax1DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DFU:
			config.requiresImageAtomicMax2DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DFU:
			config.requiresImageAtomicMax3DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectFU:
			config.requiresImageAtomicMax2DRectFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeFU:
			config.requiresImageAtomicMaxCubeFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferFU:
			config.requiresImageAtomicMaxBufferFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayFU:
			config.requiresImageAtomicMax1DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayFU:
			config.requiresImageAtomicMax2DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayFU:
			config.requiresImageAtomicMaxCubeArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSFU:
			config.requiresImageAtomicMax2DMSFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayFU:
			config.requiresImageAtomicMax2DMSArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DIU:
			config.requiresImageAtomicMax1DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DIU:
			config.requiresImageAtomicMax2DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DIU:
			config.requiresImageAtomicMax3DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectIU:
			config.requiresImageAtomicMax2DRectIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeIU:
			config.requiresImageAtomicMaxCubeIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferIU:
			config.requiresImageAtomicMaxBufferIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayIU:
			config.requiresImageAtomicMax1DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayIU:
			config.requiresImageAtomicMax2DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayIU:
			config.requiresImageAtomicMaxCubeArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSIU:
			config.requiresImageAtomicMax2DMSIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayIU:
			config.requiresImageAtomicMax2DMSArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DUU:
			config.requiresImageAtomicMax1DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DUU:
			config.requiresImageAtomicMax2DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DUU:
			config.requiresImageAtomicMax3DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectUU:
			config.requiresImageAtomicMax2DRectUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeUU:
			config.requiresImageAtomicMaxCubeUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferUU:
			config.requiresImageAtomicMaxBufferUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayUU:
			config.requiresImageAtomicMax1DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayUU:
			config.requiresImageAtomicMax2DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayUU:
			config.requiresImageAtomicMaxCubeArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSUU:
			config.requiresImageAtomicMax2DMSUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayUU:
			config.requiresImageAtomicMax2DMSArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DFI:
			config.requiresImageAtomicMax1DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DFI:
			config.requiresImageAtomicMax2DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DFI:
			config.requiresImageAtomicMax3DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectFI:
			config.requiresImageAtomicMax2DRectFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeFI:
			config.requiresImageAtomicMaxCubeFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferFI:
			config.requiresImageAtomicMaxBufferFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayFI:
			config.requiresImageAtomicMax1DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayFI:
			config.requiresImageAtomicMax2DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayFI:
			config.requiresImageAtomicMaxCubeArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSFI:
			config.requiresImageAtomicMax2DMSFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayFI:
			config.requiresImageAtomicMax2DMSArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DII:
			config.requiresImageAtomicMax1DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DII:
			config.requiresImageAtomicMax2DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DII:
			config.requiresImageAtomicMax3DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectII:
			config.requiresImageAtomicMax2DRectII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeII:
			config.requiresImageAtomicMaxCubeII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferII:
			config.requiresImageAtomicMaxBufferII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayII:
			config.requiresImageAtomicMax1DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayII:
			config.requiresImageAtomicMax2DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayII:
			config.requiresImageAtomicMaxCubeArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSII:
			config.requiresImageAtomicMax2DMSII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayII:
			config.requiresImageAtomicMax2DMSArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DUI:
			config.requiresImageAtomicMax1DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DUI:
			config.requiresImageAtomicMax2DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DUI:
			config.requiresImageAtomicMax3DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectUI:
			config.requiresImageAtomicMax2DRectUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeUI:
			config.requiresImageAtomicMaxCubeUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferUI:
			config.requiresImageAtomicMaxBufferUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayUI:
			config.requiresImageAtomicMax1DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayUI:
			config.requiresImageAtomicMax2DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayUI:
			config.requiresImageAtomicMaxCubeArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSUI:
			config.requiresImageAtomicMax2DMSUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayUI:
			config.requiresImageAtomicMax2DMSArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DFU:
			config.requiresImageAtomicAnd1DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DFU:
			config.requiresImageAtomicAnd2DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DFU:
			config.requiresImageAtomicAnd3DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectFU:
			config.requiresImageAtomicAnd2DRectFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeFU:
			config.requiresImageAtomicAndCubeFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferFU:
			config.requiresImageAtomicAndBufferFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayFU:
			config.requiresImageAtomicAnd1DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayFU:
			config.requiresImageAtomicAnd2DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayFU:
			config.requiresImageAtomicAndCubeArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSFU:
			config.requiresImageAtomicAnd2DMSFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayFU:
			config.requiresImageAtomicAnd2DMSArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DIU:
			config.requiresImageAtomicAnd1DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DIU:
			config.requiresImageAtomicAnd2DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DIU:
			config.requiresImageAtomicAnd3DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectIU:
			config.requiresImageAtomicAnd2DRectIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeIU:
			config.requiresImageAtomicAndCubeIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferIU:
			config.requiresImageAtomicAndBufferIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayIU:
			config.requiresImageAtomicAnd1DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayIU:
			config.requiresImageAtomicAnd2DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayIU:
			config.requiresImageAtomicAndCubeArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSIU:
			config.requiresImageAtomicAnd2DMSIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayIU:
			config.requiresImageAtomicAnd2DMSArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DUU:
			config.requiresImageAtomicAnd1DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DUU:
			config.requiresImageAtomicAnd2DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DUU:
			config.requiresImageAtomicAnd3DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectUU:
			config.requiresImageAtomicAnd2DRectUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeUU:
			config.requiresImageAtomicAndCubeUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferUU:
			config.requiresImageAtomicAndBufferUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayUU:
			config.requiresImageAtomicAnd1DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayUU:
			config.requiresImageAtomicAnd2DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayUU:
			config.requiresImageAtomicAndCubeArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSUU:
			config.requiresImageAtomicAnd2DMSUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayUU:
			config.requiresImageAtomicAnd2DMSArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DFI:
			config.requiresImageAtomicAnd1DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DFI:
			config.requiresImageAtomicAnd2DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DFI:
			config.requiresImageAtomicAnd3DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectFI:
			config.requiresImageAtomicAnd2DRectFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeFI:
			config.requiresImageAtomicAndCubeFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferFI:
			config.requiresImageAtomicAndBufferFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayFI:
			config.requiresImageAtomicAnd1DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayFI:
			config.requiresImageAtomicAnd2DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayFI:
			config.requiresImageAtomicAndCubeArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSFI:
			config.requiresImageAtomicAnd2DMSFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayFI:
			config.requiresImageAtomicAnd2DMSArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DII:
			config.requiresImageAtomicAnd1DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DII:
			config.requiresImageAtomicAnd2DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DII:
			config.requiresImageAtomicAnd3DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectII:
			config.requiresImageAtomicAnd2DRectII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeII:
			config.requiresImageAtomicAndCubeII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferII:
			config.requiresImageAtomicAndBufferII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayII:
			config.requiresImageAtomicAnd1DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayII:
			config.requiresImageAtomicAnd2DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayII:
			config.requiresImageAtomicAndCubeArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSII:
			config.requiresImageAtomicAnd2DMSII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayII:
			config.requiresImageAtomicAnd2DMSArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DUI:
			config.requiresImageAtomicAnd1DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DUI:
			config.requiresImageAtomicAnd2DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DUI:
			config.requiresImageAtomicAnd3DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectUI:
			config.requiresImageAtomicAnd2DRectUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeUI:
			config.requiresImageAtomicAndCubeUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferUI:
			config.requiresImageAtomicAndBufferUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayUI:
			config.requiresImageAtomicAnd1DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayUI:
			config.requiresImageAtomicAnd2DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayUI:
			config.requiresImageAtomicAndCubeArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSUI:
			config.requiresImageAtomicAnd2DMSUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayUI:
			config.requiresImageAtomicAnd2DMSArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DFU:
			config.requiresImageAtomicOr1DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DFU:
			config.requiresImageAtomicOr2DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DFU:
			config.requiresImageAtomicOr3DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectFU:
			config.requiresImageAtomicOr2DRectFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeFU:
			config.requiresImageAtomicOrCubeFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferFU:
			config.requiresImageAtomicOrBufferFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayFU:
			config.requiresImageAtomicOr1DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayFU:
			config.requiresImageAtomicOr2DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayFU:
			config.requiresImageAtomicOrCubeArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSFU:
			config.requiresImageAtomicOr2DMSFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayFU:
			config.requiresImageAtomicOr2DMSArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DIU:
			config.requiresImageAtomicOr1DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DIU:
			config.requiresImageAtomicOr2DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DIU:
			config.requiresImageAtomicOr3DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectIU:
			config.requiresImageAtomicOr2DRectIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeIU:
			config.requiresImageAtomicOrCubeIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferIU:
			config.requiresImageAtomicOrBufferIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayIU:
			config.requiresImageAtomicOr1DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayIU:
			config.requiresImageAtomicOr2DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayIU:
			config.requiresImageAtomicOrCubeArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSIU:
			config.requiresImageAtomicOr2DMSIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayIU:
			config.requiresImageAtomicOr2DMSArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DUU:
			config.requiresImageAtomicOr1DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DUU:
			config.requiresImageAtomicOr2DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DUU:
			config.requiresImageAtomicOr3DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectUU:
			config.requiresImageAtomicOr2DRectUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeUU:
			config.requiresImageAtomicOrCubeUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferUU:
			config.requiresImageAtomicOrBufferUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayUU:
			config.requiresImageAtomicOr1DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayUU:
			config.requiresImageAtomicOr2DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayUU:
			config.requiresImageAtomicOrCubeArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSUU:
			config.requiresImageAtomicOr2DMSUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayUU:
			config.requiresImageAtomicOr2DMSArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DFI:
			config.requiresImageAtomicOr1DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DFI:
			config.requiresImageAtomicOr2DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DFI:
			config.requiresImageAtomicOr3DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectFI:
			config.requiresImageAtomicOr2DRectFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeFI:
			config.requiresImageAtomicOrCubeFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferFI:
			config.requiresImageAtomicOrBufferFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayFI:
			config.requiresImageAtomicOr1DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayFI:
			config.requiresImageAtomicOr2DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayFI:
			config.requiresImageAtomicOrCubeArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSFI:
			config.requiresImageAtomicOr2DMSFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayFI:
			config.requiresImageAtomicOr2DMSArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DII:
			config.requiresImageAtomicOr1DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DII:
			config.requiresImageAtomicOr2DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DII:
			config.requiresImageAtomicOr3DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectII:
			config.requiresImageAtomicOr2DRectII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeII:
			config.requiresImageAtomicOrCubeII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferII:
			config.requiresImageAtomicOrBufferII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayII:
			config.requiresImageAtomicOr1DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayII:
			config.requiresImageAtomicOr2DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayII:
			config.requiresImageAtomicOrCubeArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSII:
			config.requiresImageAtomicOr2DMSII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayII:
			config.requiresImageAtomicOr2DMSArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DUI:
			config.requiresImageAtomicOr1DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DUI:
			config.requiresImageAtomicOr2DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DUI:
			config.requiresImageAtomicOr3DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectUI:
			config.requiresImageAtomicOr2DRectUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeUI:
			config.requiresImageAtomicOrCubeUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferUI:
			config.requiresImageAtomicOrBufferUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayUI:
			config.requiresImageAtomicOr1DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayUI:
			config.requiresImageAtomicOr2DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayUI:
			config.requiresImageAtomicOrCubeArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSUI:
			config.requiresImageAtomicOr2DMSUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayUI:
			config.requiresImageAtomicOr2DMSArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DFU:
			config.requiresImageAtomicXor1DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DFU:
			config.requiresImageAtomicXor2DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DFU:
			config.requiresImageAtomicXor3DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectFU:
			config.requiresImageAtomicXor2DRectFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeFU:
			config.requiresImageAtomicXorCubeFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferFU:
			config.requiresImageAtomicXorBufferFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayFU:
			config.requiresImageAtomicXor1DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayFU:
			config.requiresImageAtomicXor2DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayFU:
			config.requiresImageAtomicXorCubeArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSFU:
			config.requiresImageAtomicXor2DMSFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayFU:
			config.requiresImageAtomicXor2DMSArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DIU:
			config.requiresImageAtomicXor1DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DIU:
			config.requiresImageAtomicXor2DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DIU:
			config.requiresImageAtomicXor3DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectIU:
			config.requiresImageAtomicXor2DRectIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeIU:
			config.requiresImageAtomicXorCubeIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferIU:
			config.requiresImageAtomicXorBufferIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayIU:
			config.requiresImageAtomicXor1DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayIU:
			config.requiresImageAtomicXor2DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayIU:
			config.requiresImageAtomicXorCubeArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSIU:
			config.requiresImageAtomicXor2DMSIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayIU:
			config.requiresImageAtomicXor2DMSArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DUU:
			config.requiresImageAtomicXor1DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DUU:
			config.requiresImageAtomicXor2DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DUU:
			config.requiresImageAtomicXor3DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectUU:
			config.requiresImageAtomicXor2DRectUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeUU:
			config.requiresImageAtomicXorCubeUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferUU:
			config.requiresImageAtomicXorBufferUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayUU:
			config.requiresImageAtomicXor1DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayUU:
			config.requiresImageAtomicXor2DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayUU:
			config.requiresImageAtomicXorCubeArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSUU:
			config.requiresImageAtomicXor2DMSUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayUU:
			config.requiresImageAtomicXor2DMSArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DFI:
			config.requiresImageAtomicXor1DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DFI:
			config.requiresImageAtomicXor2DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DFI:
			config.requiresImageAtomicXor3DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectFI:
			config.requiresImageAtomicXor2DRectFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeFI:
			config.requiresImageAtomicXorCubeFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferFI:
			config.requiresImageAtomicXorBufferFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayFI:
			config.requiresImageAtomicXor1DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayFI:
			config.requiresImageAtomicXor2DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayFI:
			config.requiresImageAtomicXorCubeArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSFI:
			config.requiresImageAtomicXor2DMSFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayFI:
			config.requiresImageAtomicXor2DMSArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DII:
			config.requiresImageAtomicXor1DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DII:
			config.requiresImageAtomicXor2DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DII:
			config.requiresImageAtomicXor3DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectII:
			config.requiresImageAtomicXor2DRectII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeII:
			config.requiresImageAtomicXorCubeII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferII:
			config.requiresImageAtomicXorBufferII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayII:
			config.requiresImageAtomicXor1DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayII:
			config.requiresImageAtomicXor2DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayII:
			config.requiresImageAtomicXorCubeArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSII:
			config.requiresImageAtomicXor2DMSII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayII:
			config.requiresImageAtomicXor2DMSArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DUI:
			config.requiresImageAtomicXor1DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DUI:
			config.requiresImageAtomicXor2DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DUI:
			config.requiresImageAtomicXor3DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectUI:
			config.requiresImageAtomicXor2DRectUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeUI:
			config.requiresImageAtomicXorCubeUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferUI:
			config.requiresImageAtomicXorBufferUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayUI:
			config.requiresImageAtomicXor1DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayUI:
			config.requiresImageAtomicXor2DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayUI:
			config.requiresImageAtomicXorCubeArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSUI:
			config.requiresImageAtomicXor2DMSUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayUI:
			config.requiresImageAtomicXor2DMSArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DFU:
			config.requiresImageAtomicExchange1DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DFU:
			config.requiresImageAtomicExchange2DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DFU:
			config.requiresImageAtomicExchange3DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectFU:
			config.requiresImageAtomicExchange2DRectFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeFU:
			config.requiresImageAtomicExchangeCubeFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferFU:
			config.requiresImageAtomicExchangeBufferFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayFU:
			config.requiresImageAtomicExchange1DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayFU:
			config.requiresImageAtomicExchange2DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayFU:
			config.requiresImageAtomicExchangeCubeArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSFU:
			config.requiresImageAtomicExchange2DMSFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayFU:
			config.requiresImageAtomicExchange2DMSArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DIU:
			config.requiresImageAtomicExchange1DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DIU:
			config.requiresImageAtomicExchange2DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DIU:
			config.requiresImageAtomicExchange3DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectIU:
			config.requiresImageAtomicExchange2DRectIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeIU:
			config.requiresImageAtomicExchangeCubeIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferIU:
			config.requiresImageAtomicExchangeBufferIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayIU:
			config.requiresImageAtomicExchange1DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayIU:
			config.requiresImageAtomicExchange2DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayIU:
			config.requiresImageAtomicExchangeCubeArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSIU:
			config.requiresImageAtomicExchange2DMSIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayIU:
			config.requiresImageAtomicExchange2DMSArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DUU:
			config.requiresImageAtomicExchange1DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DUU:
			config.requiresImageAtomicExchange2DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DUU:
			config.requiresImageAtomicExchange3DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectUU:
			config.requiresImageAtomicExchange2DRectUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeUU:
			config.requiresImageAtomicExchangeCubeUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferUU:
			config.requiresImageAtomicExchangeBufferUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayUU:
			config.requiresImageAtomicExchange1DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayUU:
			config.requiresImageAtomicExchange2DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayUU:
			config.requiresImageAtomicExchangeCubeArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSUU:
			config.requiresImageAtomicExchange2DMSUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayUU:
			config.requiresImageAtomicExchange2DMSArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DFI:
			config.requiresImageAtomicExchange1DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DFI:
			config.requiresImageAtomicExchange2DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DFI:
			config.requiresImageAtomicExchange3DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectFI:
			config.requiresImageAtomicExchange2DRectFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeFI:
			config.requiresImageAtomicExchangeCubeFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferFI:
			config.requiresImageAtomicExchangeBufferFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayFI:
			config.requiresImageAtomicExchange1DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayFI:
			config.requiresImageAtomicExchange2DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayFI:
			config.requiresImageAtomicExchangeCubeArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSFI:
			config.requiresImageAtomicExchange2DMSFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayFI:
			config.requiresImageAtomicExchange2DMSArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DII:
			config.requiresImageAtomicExchange1DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DII:
			config.requiresImageAtomicExchange2DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DII:
			config.requiresImageAtomicExchange3DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectII:
			config.requiresImageAtomicExchange2DRectII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeII:
			config.requiresImageAtomicExchangeCubeII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferII:
			config.requiresImageAtomicExchangeBufferII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayII:
			config.requiresImageAtomicExchange1DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayII:
			config.requiresImageAtomicExchange2DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayII:
			config.requiresImageAtomicExchangeCubeArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSII:
			config.requiresImageAtomicExchange2DMSII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayII:
			config.requiresImageAtomicExchange2DMSArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DUI:
			config.requiresImageAtomicExchange1DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DUI:
			config.requiresImageAtomicExchange2DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DUI:
			config.requiresImageAtomicExchange3DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectUI:
			config.requiresImageAtomicExchange2DRectUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeUI:
			config.requiresImageAtomicExchangeCubeUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferUI:
			config.requiresImageAtomicExchangeBufferUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayUI:
			config.requiresImageAtomicExchange1DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayUI:
			config.requiresImageAtomicExchange2DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayUI:
			config.requiresImageAtomicExchangeCubeArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSUI:
			config.requiresImageAtomicExchange2DMSUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayUI:
			config.requiresImageAtomicExchange2DMSArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DFU:
			config.requiresImageAtomicCompSwap1DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DFU:
			config.requiresImageAtomicCompSwap2DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DFU:
			config.requiresImageAtomicCompSwap3DFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectFU:
			config.requiresImageAtomicCompSwap2DRectFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeFU:
			config.requiresImageAtomicCompSwapCubeFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferFU:
			config.requiresImageAtomicCompSwapBufferFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayFU:
			config.requiresImageAtomicCompSwap1DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayFU:
			config.requiresImageAtomicCompSwap2DArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayFU:
			config.requiresImageAtomicCompSwapCubeArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSFU:
			config.requiresImageAtomicCompSwap2DMSFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayFU:
			config.requiresImageAtomicCompSwap2DMSArrayFU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DIU:
			config.requiresImageAtomicCompSwap1DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DIU:
			config.requiresImageAtomicCompSwap2DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DIU:
			config.requiresImageAtomicCompSwap3DIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectIU:
			config.requiresImageAtomicCompSwap2DRectIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeIU:
			config.requiresImageAtomicCompSwapCubeIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferIU:
			config.requiresImageAtomicCompSwapBufferIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayIU:
			config.requiresImageAtomicCompSwap1DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayIU:
			config.requiresImageAtomicCompSwap2DArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayIU:
			config.requiresImageAtomicCompSwapCubeArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSIU:
			config.requiresImageAtomicCompSwap2DMSIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayIU:
			config.requiresImageAtomicCompSwap2DMSArrayIU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DUU:
			config.requiresImageAtomicCompSwap1DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DUU:
			config.requiresImageAtomicCompSwap2DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DUU:
			config.requiresImageAtomicCompSwap3DUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectUU:
			config.requiresImageAtomicCompSwap2DRectUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeUU:
			config.requiresImageAtomicCompSwapCubeUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferUU:
			config.requiresImageAtomicCompSwapBufferUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayUU:
			config.requiresImageAtomicCompSwap1DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayUU:
			config.requiresImageAtomicCompSwap2DArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayUU:
			config.requiresImageAtomicCompSwapCubeArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSUU:
			config.requiresImageAtomicCompSwap2DMSUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayUU:
			config.requiresImageAtomicCompSwap2DMSArrayUU = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DFI:
			config.requiresImageAtomicCompSwap1DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DFI:
			config.requiresImageAtomicCompSwap2DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DFI:
			config.requiresImageAtomicCompSwap3DFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectFI:
			config.requiresImageAtomicCompSwap2DRectFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeFI:
			config.requiresImageAtomicCompSwapCubeFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferFI:
			config.requiresImageAtomicCompSwapBufferFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayFI:
			config.requiresImageAtomicCompSwap1DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayFI:
			config.requiresImageAtomicCompSwap2DArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayFI:
			config.requiresImageAtomicCompSwapCubeArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSFI:
			config.requiresImageAtomicCompSwap2DMSFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayFI:
			config.requiresImageAtomicCompSwap2DMSArrayFI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DII:
			config.requiresImageAtomicCompSwap1DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DII:
			config.requiresImageAtomicCompSwap2DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DII:
			config.requiresImageAtomicCompSwap3DII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectII:
			config.requiresImageAtomicCompSwap2DRectII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeII:
			config.requiresImageAtomicCompSwapCubeII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferII:
			config.requiresImageAtomicCompSwapBufferII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayII:
			config.requiresImageAtomicCompSwap1DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayII:
			config.requiresImageAtomicCompSwap2DArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayII:
			config.requiresImageAtomicCompSwapCubeArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSII:
			config.requiresImageAtomicCompSwap2DMSII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayII:
			config.requiresImageAtomicCompSwap2DMSArrayII = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DUI:
			config.requiresImageAtomicCompSwap1DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DUI:
			config.requiresImageAtomicCompSwap2DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DUI:
			config.requiresImageAtomicCompSwap3DUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectUI:
			config.requiresImageAtomicCompSwap2DRectUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeUI:
			config.requiresImageAtomicCompSwapCubeUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferUI:
			config.requiresImageAtomicCompSwapBufferUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayUI:
			config.requiresImageAtomicCompSwap1DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayUI:
			config.requiresImageAtomicCompSwap2DArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayUI:
			config.requiresImageAtomicCompSwapCubeArrayUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSUI:
			config.requiresImageAtomicCompSwap2DMSUI = true;
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayUI:
			config.requiresImageAtomicCompSwap2DMSArrayUI = true;
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

		default:
			throw std::runtime_error{ "Unsupported ImageAccess type." };
		}
	}
}

#endif
