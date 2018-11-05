/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslImageAccessNames_H___
#define ___SDW_GlslImageAccessNames_H___
#pragma once

#include <ASTGenerator/Expr/EnumImageAccess.hpp>

#include <string>

namespace sdw::spirv
{
	inline spv::Op getSpirVName( ast::expr::ImageAccess value )
	{
		spv::Op result;

		switch ( value )
		{
		case ast::expr::ImageAccess::eImageSize1DF:
		case ast::expr::ImageAccess::eImageSize2DF:
		case ast::expr::ImageAccess::eImageSize3DF:
		case ast::expr::ImageAccess::eImageSizeCubeF:
		case ast::expr::ImageAccess::eImageSizeCubeArrayF:
		case ast::expr::ImageAccess::eImageSize2DRectF:
		case ast::expr::ImageAccess::eImageSize1DArrayF:
		case ast::expr::ImageAccess::eImageSize2DArrayF:
		case ast::expr::ImageAccess::eImageSizeBufferF:
		case ast::expr::ImageAccess::eImageSize2DMSF:
		case ast::expr::ImageAccess::eImageSize2DMSArrayF:
		case ast::expr::ImageAccess::eImageSize1DI:
		case ast::expr::ImageAccess::eImageSize2DI:
		case ast::expr::ImageAccess::eImageSize3DI:
		case ast::expr::ImageAccess::eImageSizeCubeI:
		case ast::expr::ImageAccess::eImageSizeCubeArrayI:
		case ast::expr::ImageAccess::eImageSize2DRectI:
		case ast::expr::ImageAccess::eImageSize1DArrayI:
		case ast::expr::ImageAccess::eImageSize2DArrayI:
		case ast::expr::ImageAccess::eImageSizeBufferI:
		case ast::expr::ImageAccess::eImageSize2DMSI:
		case ast::expr::ImageAccess::eImageSize2DMSArrayI:
		case ast::expr::ImageAccess::eImageSize1DU:
		case ast::expr::ImageAccess::eImageSize2DU:
		case ast::expr::ImageAccess::eImageSize3DU:
		case ast::expr::ImageAccess::eImageSizeCubeU:
		case ast::expr::ImageAccess::eImageSizeCubeArrayU:
		case ast::expr::ImageAccess::eImageSize2DRectU:
		case ast::expr::ImageAccess::eImageSize1DArrayU:
		case ast::expr::ImageAccess::eImageSize2DArrayU:
		case ast::expr::ImageAccess::eImageSizeBufferU:
		case ast::expr::ImageAccess::eImageSize2DMSU:
		case ast::expr::ImageAccess::eImageSize2DMSArrayU:
			result = spv::Op::OpImageQuerySize;
			break;

		case ast::expr::ImageAccess::eImageSamples2DMSF:
		case ast::expr::ImageAccess::eImageSamples2DMSArrayF:
		case ast::expr::ImageAccess::eImageSamples2DMSI:
		case ast::expr::ImageAccess::eImageSamples2DMSArrayI:
		case ast::expr::ImageAccess::eImageSamples2DMSU:
		case ast::expr::ImageAccess::eImageSamples2DMSArrayU:
			result = spv::Op::OpImageQuerySamples;
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
			result = spv::Op::OpImageRead;
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DFU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DFU:
		case ast::expr::ImageAccess::eImageAtomicAdd3DFU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DRectFU:
		case ast::expr::ImageAccess::eImageAtomicAddCubeFU:
		case ast::expr::ImageAccess::eImageAtomicAddBufferFU:
		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayFU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSFU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayFU:
		case ast::expr::ImageAccess::eImageAtomicAdd1DIU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DIU:
		case ast::expr::ImageAccess::eImageAtomicAdd3DIU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DRectIU:
		case ast::expr::ImageAccess::eImageAtomicAddCubeIU:
		case ast::expr::ImageAccess::eImageAtomicAddBufferIU:
		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayIU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSIU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayIU:
		case ast::expr::ImageAccess::eImageAtomicAdd1DUU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DUU:
		case ast::expr::ImageAccess::eImageAtomicAdd3DUU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DRectUU:
		case ast::expr::ImageAccess::eImageAtomicAddCubeUU:
		case ast::expr::ImageAccess::eImageAtomicAddBufferUU:
		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayUU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSUU:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayUU:
		case ast::expr::ImageAccess::eImageAtomicAdd1DFI:
		case ast::expr::ImageAccess::eImageAtomicAdd2DFI:
		case ast::expr::ImageAccess::eImageAtomicAdd3DFI:
		case ast::expr::ImageAccess::eImageAtomicAdd2DRectFI:
		case ast::expr::ImageAccess::eImageAtomicAddCubeFI:
		case ast::expr::ImageAccess::eImageAtomicAddBufferFI:
		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayFI:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSFI:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayFI:
		case ast::expr::ImageAccess::eImageAtomicAdd1DII:
		case ast::expr::ImageAccess::eImageAtomicAdd2DII:
		case ast::expr::ImageAccess::eImageAtomicAdd3DII:
		case ast::expr::ImageAccess::eImageAtomicAdd2DRectII:
		case ast::expr::ImageAccess::eImageAtomicAddCubeII:
		case ast::expr::ImageAccess::eImageAtomicAddBufferII:
		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayII:
		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayII:
		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayII:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSII:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayII:
		case ast::expr::ImageAccess::eImageAtomicAdd1DUI:
		case ast::expr::ImageAccess::eImageAtomicAdd2DUI:
		case ast::expr::ImageAccess::eImageAtomicAdd3DUI:
		case ast::expr::ImageAccess::eImageAtomicAdd2DRectUI:
		case ast::expr::ImageAccess::eImageAtomicAddCubeUI:
		case ast::expr::ImageAccess::eImageAtomicAddBufferUI:
		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayUI:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSUI:
		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayUI:
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DFU:
		case ast::expr::ImageAccess::eImageAtomicMin2DFU:
		case ast::expr::ImageAccess::eImageAtomicMin3DFU:
		case ast::expr::ImageAccess::eImageAtomicMin2DRectFU:
		case ast::expr::ImageAccess::eImageAtomicMinCubeFU:
		case ast::expr::ImageAccess::eImageAtomicMinBufferFU:
		case ast::expr::ImageAccess::eImageAtomicMin1DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicMin2DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayFU:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSFU:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayFU:
		case ast::expr::ImageAccess::eImageAtomicMin1DIU:
		case ast::expr::ImageAccess::eImageAtomicMin2DIU:
		case ast::expr::ImageAccess::eImageAtomicMin3DIU:
		case ast::expr::ImageAccess::eImageAtomicMin2DRectIU:
		case ast::expr::ImageAccess::eImageAtomicMinCubeIU:
		case ast::expr::ImageAccess::eImageAtomicMinBufferIU:
		case ast::expr::ImageAccess::eImageAtomicMin1DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicMin2DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayIU:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSIU:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayIU:
		case ast::expr::ImageAccess::eImageAtomicMin1DUU:
		case ast::expr::ImageAccess::eImageAtomicMin2DUU:
		case ast::expr::ImageAccess::eImageAtomicMin3DUU:
		case ast::expr::ImageAccess::eImageAtomicMin2DRectUU:
		case ast::expr::ImageAccess::eImageAtomicMinCubeUU:
		case ast::expr::ImageAccess::eImageAtomicMinBufferUU:
		case ast::expr::ImageAccess::eImageAtomicMin1DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicMin2DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayUU:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSUU:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayUU:
		case ast::expr::ImageAccess::eImageAtomicMin1DFI:
		case ast::expr::ImageAccess::eImageAtomicMin2DFI:
		case ast::expr::ImageAccess::eImageAtomicMin3DFI:
		case ast::expr::ImageAccess::eImageAtomicMin2DRectFI:
		case ast::expr::ImageAccess::eImageAtomicMinCubeFI:
		case ast::expr::ImageAccess::eImageAtomicMinBufferFI:
		case ast::expr::ImageAccess::eImageAtomicMin1DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicMin2DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayFI:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSFI:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayFI:
		case ast::expr::ImageAccess::eImageAtomicMin1DII:
		case ast::expr::ImageAccess::eImageAtomicMin2DII:
		case ast::expr::ImageAccess::eImageAtomicMin3DII:
		case ast::expr::ImageAccess::eImageAtomicMin2DRectII:
		case ast::expr::ImageAccess::eImageAtomicMinCubeII:
		case ast::expr::ImageAccess::eImageAtomicMinBufferII:
		case ast::expr::ImageAccess::eImageAtomicMin1DArrayII:
		case ast::expr::ImageAccess::eImageAtomicMin2DArrayII:
		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayII:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSII:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayII:
		case ast::expr::ImageAccess::eImageAtomicMin1DUI:
		case ast::expr::ImageAccess::eImageAtomicMin2DUI:
		case ast::expr::ImageAccess::eImageAtomicMin3DUI:
		case ast::expr::ImageAccess::eImageAtomicMin2DRectUI:
		case ast::expr::ImageAccess::eImageAtomicMinCubeUI:
		case ast::expr::ImageAccess::eImageAtomicMinBufferUI:
		case ast::expr::ImageAccess::eImageAtomicMin1DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicMin2DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayUI:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSUI:
		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayUI:
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DFU:
		case ast::expr::ImageAccess::eImageAtomicMax2DFU:
		case ast::expr::ImageAccess::eImageAtomicMax3DFU:
		case ast::expr::ImageAccess::eImageAtomicMax2DRectFU:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeFU:
		case ast::expr::ImageAccess::eImageAtomicMaxBufferFU:
		case ast::expr::ImageAccess::eImageAtomicMax1DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicMax2DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayFU:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSFU:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayFU:
		case ast::expr::ImageAccess::eImageAtomicMax1DIU:
		case ast::expr::ImageAccess::eImageAtomicMax2DIU:
		case ast::expr::ImageAccess::eImageAtomicMax3DIU:
		case ast::expr::ImageAccess::eImageAtomicMax2DRectIU:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeIU:
		case ast::expr::ImageAccess::eImageAtomicMaxBufferIU:
		case ast::expr::ImageAccess::eImageAtomicMax1DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicMax2DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayIU:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSIU:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayIU:
		case ast::expr::ImageAccess::eImageAtomicMax1DUU:
		case ast::expr::ImageAccess::eImageAtomicMax2DUU:
		case ast::expr::ImageAccess::eImageAtomicMax3DUU:
		case ast::expr::ImageAccess::eImageAtomicMax2DRectUU:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeUU:
		case ast::expr::ImageAccess::eImageAtomicMaxBufferUU:
		case ast::expr::ImageAccess::eImageAtomicMax1DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicMax2DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayUU:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSUU:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayUU:
		case ast::expr::ImageAccess::eImageAtomicMax1DFI:
		case ast::expr::ImageAccess::eImageAtomicMax2DFI:
		case ast::expr::ImageAccess::eImageAtomicMax3DFI:
		case ast::expr::ImageAccess::eImageAtomicMax2DRectFI:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeFI:
		case ast::expr::ImageAccess::eImageAtomicMaxBufferFI:
		case ast::expr::ImageAccess::eImageAtomicMax1DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicMax2DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayFI:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSFI:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayFI:
		case ast::expr::ImageAccess::eImageAtomicMax1DII:
		case ast::expr::ImageAccess::eImageAtomicMax2DII:
		case ast::expr::ImageAccess::eImageAtomicMax3DII:
		case ast::expr::ImageAccess::eImageAtomicMax2DRectII:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeII:
		case ast::expr::ImageAccess::eImageAtomicMaxBufferII:
		case ast::expr::ImageAccess::eImageAtomicMax1DArrayII:
		case ast::expr::ImageAccess::eImageAtomicMax2DArrayII:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayII:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSII:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayII:
		case ast::expr::ImageAccess::eImageAtomicMax1DUI:
		case ast::expr::ImageAccess::eImageAtomicMax2DUI:
		case ast::expr::ImageAccess::eImageAtomicMax3DUI:
		case ast::expr::ImageAccess::eImageAtomicMax2DRectUI:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeUI:
		case ast::expr::ImageAccess::eImageAtomicMaxBufferUI:
		case ast::expr::ImageAccess::eImageAtomicMax1DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicMax2DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayUI:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSUI:
		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayUI:
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DFU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DFU:
		case ast::expr::ImageAccess::eImageAtomicAnd3DFU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DRectFU:
		case ast::expr::ImageAccess::eImageAtomicAndCubeFU:
		case ast::expr::ImageAccess::eImageAtomicAndBufferFU:
		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayFU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSFU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayFU:
		case ast::expr::ImageAccess::eImageAtomicAnd1DIU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DIU:
		case ast::expr::ImageAccess::eImageAtomicAnd3DIU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DRectIU:
		case ast::expr::ImageAccess::eImageAtomicAndCubeIU:
		case ast::expr::ImageAccess::eImageAtomicAndBufferIU:
		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayIU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSIU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayIU:
		case ast::expr::ImageAccess::eImageAtomicAnd1DUU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DUU:
		case ast::expr::ImageAccess::eImageAtomicAnd3DUU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DRectUU:
		case ast::expr::ImageAccess::eImageAtomicAndCubeUU:
		case ast::expr::ImageAccess::eImageAtomicAndBufferUU:
		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayUU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSUU:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayUU:
		case ast::expr::ImageAccess::eImageAtomicAnd1DFI:
		case ast::expr::ImageAccess::eImageAtomicAnd2DFI:
		case ast::expr::ImageAccess::eImageAtomicAnd3DFI:
		case ast::expr::ImageAccess::eImageAtomicAnd2DRectFI:
		case ast::expr::ImageAccess::eImageAtomicAndCubeFI:
		case ast::expr::ImageAccess::eImageAtomicAndBufferFI:
		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayFI:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSFI:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayFI:
		case ast::expr::ImageAccess::eImageAtomicAnd1DII:
		case ast::expr::ImageAccess::eImageAtomicAnd2DII:
		case ast::expr::ImageAccess::eImageAtomicAnd3DII:
		case ast::expr::ImageAccess::eImageAtomicAnd2DRectII:
		case ast::expr::ImageAccess::eImageAtomicAndCubeII:
		case ast::expr::ImageAccess::eImageAtomicAndBufferII:
		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayII:
		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayII:
		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayII:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSII:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayII:
		case ast::expr::ImageAccess::eImageAtomicAnd1DUI:
		case ast::expr::ImageAccess::eImageAtomicAnd2DUI:
		case ast::expr::ImageAccess::eImageAtomicAnd3DUI:
		case ast::expr::ImageAccess::eImageAtomicAnd2DRectUI:
		case ast::expr::ImageAccess::eImageAtomicAndCubeUI:
		case ast::expr::ImageAccess::eImageAtomicAndBufferUI:
		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayUI:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSUI:
		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayUI:
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DFU:
		case ast::expr::ImageAccess::eImageAtomicOr2DFU:
		case ast::expr::ImageAccess::eImageAtomicOr3DFU:
		case ast::expr::ImageAccess::eImageAtomicOr2DRectFU:
		case ast::expr::ImageAccess::eImageAtomicOrCubeFU:
		case ast::expr::ImageAccess::eImageAtomicOrBufferFU:
		case ast::expr::ImageAccess::eImageAtomicOr1DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicOr2DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayFU:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSFU:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayFU:
		case ast::expr::ImageAccess::eImageAtomicOr1DIU:
		case ast::expr::ImageAccess::eImageAtomicOr2DIU:
		case ast::expr::ImageAccess::eImageAtomicOr3DIU:
		case ast::expr::ImageAccess::eImageAtomicOr2DRectIU:
		case ast::expr::ImageAccess::eImageAtomicOrCubeIU:
		case ast::expr::ImageAccess::eImageAtomicOrBufferIU:
		case ast::expr::ImageAccess::eImageAtomicOr1DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicOr2DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayIU:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSIU:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayIU:
		case ast::expr::ImageAccess::eImageAtomicOr1DUU:
		case ast::expr::ImageAccess::eImageAtomicOr2DUU:
		case ast::expr::ImageAccess::eImageAtomicOr3DUU:
		case ast::expr::ImageAccess::eImageAtomicOr2DRectUU:
		case ast::expr::ImageAccess::eImageAtomicOrCubeUU:
		case ast::expr::ImageAccess::eImageAtomicOrBufferUU:
		case ast::expr::ImageAccess::eImageAtomicOr1DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicOr2DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayUU:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSUU:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayUU:
		case ast::expr::ImageAccess::eImageAtomicOr1DFI:
		case ast::expr::ImageAccess::eImageAtomicOr2DFI:
		case ast::expr::ImageAccess::eImageAtomicOr3DFI:
		case ast::expr::ImageAccess::eImageAtomicOr2DRectFI:
		case ast::expr::ImageAccess::eImageAtomicOrCubeFI:
		case ast::expr::ImageAccess::eImageAtomicOrBufferFI:
		case ast::expr::ImageAccess::eImageAtomicOr1DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicOr2DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayFI:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSFI:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayFI:
		case ast::expr::ImageAccess::eImageAtomicOr1DII:
		case ast::expr::ImageAccess::eImageAtomicOr2DII:
		case ast::expr::ImageAccess::eImageAtomicOr3DII:
		case ast::expr::ImageAccess::eImageAtomicOr2DRectII:
		case ast::expr::ImageAccess::eImageAtomicOrCubeII:
		case ast::expr::ImageAccess::eImageAtomicOrBufferII:
		case ast::expr::ImageAccess::eImageAtomicOr1DArrayII:
		case ast::expr::ImageAccess::eImageAtomicOr2DArrayII:
		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayII:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSII:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayII:
		case ast::expr::ImageAccess::eImageAtomicOr1DUI:
		case ast::expr::ImageAccess::eImageAtomicOr2DUI:
		case ast::expr::ImageAccess::eImageAtomicOr3DUI:
		case ast::expr::ImageAccess::eImageAtomicOr2DRectUI:
		case ast::expr::ImageAccess::eImageAtomicOrCubeUI:
		case ast::expr::ImageAccess::eImageAtomicOrBufferUI:
		case ast::expr::ImageAccess::eImageAtomicOr1DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicOr2DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayUI:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSUI:
		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayUI:
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DFU:
		case ast::expr::ImageAccess::eImageAtomicXor2DFU:
		case ast::expr::ImageAccess::eImageAtomicXor3DFU:
		case ast::expr::ImageAccess::eImageAtomicXor2DRectFU:
		case ast::expr::ImageAccess::eImageAtomicXorCubeFU:
		case ast::expr::ImageAccess::eImageAtomicXorBufferFU:
		case ast::expr::ImageAccess::eImageAtomicXor1DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicXor2DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayFU:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSFU:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayFU:
		case ast::expr::ImageAccess::eImageAtomicXor1DIU:
		case ast::expr::ImageAccess::eImageAtomicXor2DIU:
		case ast::expr::ImageAccess::eImageAtomicXor3DIU:
		case ast::expr::ImageAccess::eImageAtomicXor2DRectIU:
		case ast::expr::ImageAccess::eImageAtomicXorCubeIU:
		case ast::expr::ImageAccess::eImageAtomicXorBufferIU:
		case ast::expr::ImageAccess::eImageAtomicXor1DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicXor2DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayIU:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSIU:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayIU:
		case ast::expr::ImageAccess::eImageAtomicXor1DUU:
		case ast::expr::ImageAccess::eImageAtomicXor2DUU:
		case ast::expr::ImageAccess::eImageAtomicXor3DUU:
		case ast::expr::ImageAccess::eImageAtomicXor2DRectUU:
		case ast::expr::ImageAccess::eImageAtomicXorCubeUU:
		case ast::expr::ImageAccess::eImageAtomicXorBufferUU:
		case ast::expr::ImageAccess::eImageAtomicXor1DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicXor2DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayUU:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSUU:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayUU:
		case ast::expr::ImageAccess::eImageAtomicXor1DFI:
		case ast::expr::ImageAccess::eImageAtomicXor2DFI:
		case ast::expr::ImageAccess::eImageAtomicXor3DFI:
		case ast::expr::ImageAccess::eImageAtomicXor2DRectFI:
		case ast::expr::ImageAccess::eImageAtomicXorCubeFI:
		case ast::expr::ImageAccess::eImageAtomicXorBufferFI:
		case ast::expr::ImageAccess::eImageAtomicXor1DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicXor2DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayFI:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSFI:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayFI:
		case ast::expr::ImageAccess::eImageAtomicXor1DII:
		case ast::expr::ImageAccess::eImageAtomicXor2DII:
		case ast::expr::ImageAccess::eImageAtomicXor3DII:
		case ast::expr::ImageAccess::eImageAtomicXor2DRectII:
		case ast::expr::ImageAccess::eImageAtomicXorCubeII:
		case ast::expr::ImageAccess::eImageAtomicXorBufferII:
		case ast::expr::ImageAccess::eImageAtomicXor1DArrayII:
		case ast::expr::ImageAccess::eImageAtomicXor2DArrayII:
		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayII:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSII:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayII:
		case ast::expr::ImageAccess::eImageAtomicXor1DUI:
		case ast::expr::ImageAccess::eImageAtomicXor2DUI:
		case ast::expr::ImageAccess::eImageAtomicXor3DUI:
		case ast::expr::ImageAccess::eImageAtomicXor2DRectUI:
		case ast::expr::ImageAccess::eImageAtomicXorCubeUI:
		case ast::expr::ImageAccess::eImageAtomicXorBufferUI:
		case ast::expr::ImageAccess::eImageAtomicXor1DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicXor2DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayUI:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSUI:
		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayUI:
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DFU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DFU:
		case ast::expr::ImageAccess::eImageAtomicExchange3DFU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DRectFU:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeFU:
		case ast::expr::ImageAccess::eImageAtomicExchangeBufferFU:
		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayFU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSFU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayFU:
		case ast::expr::ImageAccess::eImageAtomicExchange1DIU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DIU:
		case ast::expr::ImageAccess::eImageAtomicExchange3DIU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DRectIU:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeIU:
		case ast::expr::ImageAccess::eImageAtomicExchangeBufferIU:
		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayIU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSIU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayIU:
		case ast::expr::ImageAccess::eImageAtomicExchange1DUU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DUU:
		case ast::expr::ImageAccess::eImageAtomicExchange3DUU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DRectUU:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeUU:
		case ast::expr::ImageAccess::eImageAtomicExchangeBufferUU:
		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayUU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSUU:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayUU:
		case ast::expr::ImageAccess::eImageAtomicExchange1DFI:
		case ast::expr::ImageAccess::eImageAtomicExchange2DFI:
		case ast::expr::ImageAccess::eImageAtomicExchange3DFI:
		case ast::expr::ImageAccess::eImageAtomicExchange2DRectFI:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeFI:
		case ast::expr::ImageAccess::eImageAtomicExchangeBufferFI:
		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayFI:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSFI:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayFI:
		case ast::expr::ImageAccess::eImageAtomicExchange1DII:
		case ast::expr::ImageAccess::eImageAtomicExchange2DII:
		case ast::expr::ImageAccess::eImageAtomicExchange3DII:
		case ast::expr::ImageAccess::eImageAtomicExchange2DRectII:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeII:
		case ast::expr::ImageAccess::eImageAtomicExchangeBufferII:
		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayII:
		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayII:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayII:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSII:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayII:
		case ast::expr::ImageAccess::eImageAtomicExchange1DUI:
		case ast::expr::ImageAccess::eImageAtomicExchange2DUI:
		case ast::expr::ImageAccess::eImageAtomicExchange3DUI:
		case ast::expr::ImageAccess::eImageAtomicExchange2DRectUI:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeUI:
		case ast::expr::ImageAccess::eImageAtomicExchangeBufferUI:
		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayUI:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSUI:
		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayUI:
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DFU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DFU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap3DFU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectFU:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeFU:
		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferFU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayFU:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayFU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSFU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayFU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap1DIU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DIU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap3DIU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectIU:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeIU:
		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferIU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayIU:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayIU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSIU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayIU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap1DUU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DUU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap3DUU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectUU:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeUU:
		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferUU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayUU:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayUU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSUU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayUU:
		case ast::expr::ImageAccess::eImageAtomicCompSwap1DFI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DFI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap3DFI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectFI:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeFI:
		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferFI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayFI:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayFI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSFI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayFI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap1DII:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DII:
		case ast::expr::ImageAccess::eImageAtomicCompSwap3DII:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectII:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeII:
		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferII:
		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayII:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayII:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayII:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSII:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayII:
		case ast::expr::ImageAccess::eImageAtomicCompSwap1DUI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DUI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap3DUI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectUI:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeUI:
		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferUI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayUI:
		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayUI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSUI:
		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayUI:
			break;

		default:
			throw std::runtime_error{ "Unsupported ImageAccess type." };
		}

		return result;
	}
}

#endif
