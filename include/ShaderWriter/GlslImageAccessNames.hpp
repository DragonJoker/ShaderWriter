/*
See LICENSE file in root folder
*/
#ifndef ___AST_GlslImageAccessNames_H___
#define ___AST_GlslImageAccessNames_H___
#pragma once

#include <ASTGenerator/Expr/EnumImageAccess.hpp>

#include <string>

namespace sdw
{
	inline std::string getGlslName( ast::expr::ImageAccess value )
	{
		std::string result;

		switch ( value )
		{
		case ast::expr::ImageAccess::eImageSize1DF:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DF:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize3DF:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSizeCubeF:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSizeCubeArrayF:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DRectF:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize1DArrayF:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DArrayF:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSizeBufferF:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DMSF:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DMSArrayF:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize1DI:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DI:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize3DI:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSizeCubeI:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSizeCubeArrayI:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DRectI:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize1DArrayI:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DArrayI:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSizeBufferI:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DMSI:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DMSArrayI:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize1DU:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DU:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize3DU:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSizeCubeU:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSizeCubeArrayU:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DRectU:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize1DArrayU:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DArrayU:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSizeBufferU:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DMSU:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSize2DMSArrayU:
			result = "imageSize";
			break;

		case ast::expr::ImageAccess::eImageSample2DMSF:
			result = "imageSample";
			break;

		case ast::expr::ImageAccess::eImageSample2DMSArrayF:
			result = "imageSample";
			break;

		case ast::expr::ImageAccess::eImageSample2DMSI:
			result = "imageSample";
			break;

		case ast::expr::ImageAccess::eImageSample2DMSArrayI:
			result = "imageSample";
			break;

		case ast::expr::ImageAccess::eImageSample2DMSU:
			result = "imageSample";
			break;

		case ast::expr::ImageAccess::eImageSample2DMSArrayU:
			result = "imageSample";
			break;

		case ast::expr::ImageAccess::eImageLoad1DF:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DF:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad3DF:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DRectF:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoadCubeF:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoadBufferF:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad1DArrayF:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DArrayF:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoadCubeArrayF:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DMSF:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DMSArrayF:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad1DI:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DI:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad3DI:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DRectI:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoadCubeI:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoadBufferI:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad1DArrayI:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DArrayI:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoadCubeArrayI:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DMSI:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DMSArrayI:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad1DU:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DU:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad3DU:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DRectU:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoadCubeU:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoadBufferU:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad1DArrayU:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DArrayU:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoadCubeArrayU:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DMSU:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageLoad2DMSArrayU:
			result = "imageLoad";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DFU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DFU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DFU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectFU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeFU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferFU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayFU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayFU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayFU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSFU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayFU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DIU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DIU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DIU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectIU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeIU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferIU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayIU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayIU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayIU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSIU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayIU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DUU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DUU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DUU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectUU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeUU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferUU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayUU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayUU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayUU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSUU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayUU:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DFI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DFI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DFI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectFI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeFI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferFI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayFI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayFI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayFI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSFI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayFI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DII:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DII:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DII:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectII:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeII:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferII:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayII:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayII:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayII:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSII:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayII:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DUI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DUI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd3DUI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DRectUI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeUI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddBufferUI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd1DArrayUI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DArrayUI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAddCubeArrayUI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSUI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayUI:
			result = "imageAtomicAdd";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DFU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DFU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DFU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectFU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeFU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferFU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayFU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayFU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayFU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSFU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayFU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DIU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DIU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DIU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectIU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeIU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferIU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayIU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayIU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayIU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSIU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayIU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DUU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DUU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DUU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectUU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeUU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferUU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayUU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayUU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayUU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSUU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayUU:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DFI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DFI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DFI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectFI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeFI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferFI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayFI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayFI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayFI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSFI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayFI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DII:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DII:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DII:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectII:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeII:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferII:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayII:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayII:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayII:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSII:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayII:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DUI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DUI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin3DUI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DRectUI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeUI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinBufferUI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin1DArrayUI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DArrayUI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMinCubeArrayUI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSUI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMin2DMSArrayUI:
			result = "imageAtomicMin";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DFU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DFU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DFU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectFU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeFU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferFU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayFU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayFU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayFU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSFU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayFU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DIU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DIU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DIU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectIU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeIU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferIU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayIU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayIU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayIU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSIU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayIU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DUU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DUU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DUU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectUU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeUU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferUU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayUU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayUU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayUU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSUU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayUU:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DFI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DFI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DFI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectFI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeFI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferFI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayFI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayFI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayFI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSFI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayFI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DII:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DII:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DII:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectII:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeII:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferII:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayII:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayII:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayII:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSII:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayII:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DUI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DUI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax3DUI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DRectUI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeUI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxBufferUI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax1DArrayUI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DArrayUI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMaxCubeArrayUI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSUI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicMax2DMSArrayUI:
			result = "imageAtomicMax";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DFU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DFU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DFU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectFU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeFU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferFU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayFU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayFU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayFU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSFU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayFU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DIU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DIU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DIU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectIU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeIU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferIU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayIU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayIU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayIU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSIU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayIU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DUU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DUU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DUU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectUU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeUU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferUU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayUU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayUU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayUU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSUU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayUU:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DFI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DFI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DFI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectFI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeFI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferFI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayFI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayFI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayFI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSFI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayFI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DII:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DII:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DII:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectII:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeII:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferII:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayII:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayII:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayII:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSII:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayII:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DUI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DUI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd3DUI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DRectUI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeUI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndBufferUI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd1DArrayUI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DArrayUI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAndCubeArrayUI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSUI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayUI:
			result = "imageAtomicAnd";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DFU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DFU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DFU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectFU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeFU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferFU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayFU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayFU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayFU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSFU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayFU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DIU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DIU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DIU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectIU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeIU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferIU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayIU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayIU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayIU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSIU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayIU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DUU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DUU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DUU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectUU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeUU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferUU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayUU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayUU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayUU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSUU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayUU:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DFI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DFI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DFI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectFI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeFI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferFI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayFI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayFI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayFI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSFI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayFI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DII:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DII:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DII:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectII:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeII:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferII:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayII:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayII:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayII:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSII:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayII:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DUI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DUI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr3DUI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DRectUI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeUI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrBufferUI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr1DArrayUI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DArrayUI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOrCubeArrayUI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSUI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicOr2DMSArrayUI:
			result = "imageAtomicOr";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DFU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DFU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DFU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectFU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeFU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferFU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayFU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayFU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayFU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSFU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayFU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DIU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DIU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DIU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectIU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeIU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferIU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayIU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayIU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayIU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSIU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayIU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DUU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DUU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DUU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectUU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeUU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferUU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayUU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayUU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayUU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSUU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayUU:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DFI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DFI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DFI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectFI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeFI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferFI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayFI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayFI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayFI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSFI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayFI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DII:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DII:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DII:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectII:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeII:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferII:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayII:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayII:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayII:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSII:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayII:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DUI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DUI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor3DUI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DRectUI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeUI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorBufferUI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor1DArrayUI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DArrayUI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXorCubeArrayUI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSUI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicXor2DMSArrayUI:
			result = "imageAtomicXor";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DFU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DFU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DFU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectFU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeFU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferFU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayFU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayFU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayFU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSFU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayFU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DIU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DIU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DIU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectIU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeIU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferIU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayIU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayIU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayIU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSIU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayIU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DUU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DUU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DUU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectUU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeUU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferUU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayUU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayUU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayUU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSUU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayUU:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DFI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DFI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DFI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectFI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeFI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferFI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayFI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayFI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayFI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSFI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayFI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DII:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DII:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DII:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectII:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeII:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferII:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayII:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayII:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayII:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSII:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayII:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DUI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DUI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange3DUI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DRectUI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeUI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeBufferUI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange1DArrayUI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DArrayUI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchangeCubeArrayUI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSUI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayUI:
			result = "imageAtomicExchange";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DFU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DFU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DFU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectFU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeFU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferFU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayFU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayFU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayFU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSFU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayFU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DIU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DIU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DIU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectIU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeIU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferIU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayIU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayIU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayIU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSIU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayIU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DUU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DUU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DUU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectUU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeUU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferUU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayUU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayUU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayUU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSUU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayUU:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DFI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DFI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DFI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectFI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeFI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferFI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayFI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayFI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayFI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSFI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayFI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DII:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DII:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DII:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectII:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeII:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferII:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayII:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayII:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayII:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSII:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayII:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DUI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DUI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap3DUI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DRectUI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeUI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapBufferUI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap1DArrayUI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DArrayUI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwapCubeArrayUI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSUI:
			result = "imageAtomicCompSwap";
			break;

		case ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayUI:
			result = "imageAtomicCompSwap";
			break;

		default:
			throw std::runtime_error{ "Unsupported ImageAccess type." };
		}

		return result;
	}
}

#endif
