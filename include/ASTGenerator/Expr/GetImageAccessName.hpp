/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprGetImageAccessName_H___
#define ___AST_ExprGetImageAccessName_H___
#pragma once

#include "EnumImageAccess.hpp"

#include <string>

namespace ast::expr
{
	inline std::string getName( ImageAccess value )
	{
		std::string result;

		switch ( value )
		{
		case ImageAccess::eImageSize1DF:
			result = "IMAGESIZE1DF";
			break;

		case ImageAccess::eImageSize2DF:
			result = "IMAGESIZE2DF";
			break;

		case ImageAccess::eImageSize3DF:
			result = "IMAGESIZE3DF";
			break;

		case ImageAccess::eImageSizeCubeF:
			result = "IMAGESIZECUBEF";
			break;

		case ImageAccess::eImageSizeCubeArrayF:
			result = "IMAGESIZECUBEARRAYF";
			break;

		case ImageAccess::eImageSize2DRectF:
			result = "IMAGESIZE2DRECTF";
			break;

		case ImageAccess::eImageSize1DArrayF:
			result = "IMAGESIZE1DARRAYF";
			break;

		case ImageAccess::eImageSize2DArrayF:
			result = "IMAGESIZE2DARRAYF";
			break;

		case ImageAccess::eImageSizeBufferF:
			result = "IMAGESIZEBUFFERF";
			break;

		case ImageAccess::eImageSize2DMSF:
			result = "IMAGESIZE2DMSF";
			break;

		case ImageAccess::eImageSize2DMSArrayF:
			result = "IMAGESIZE2DMSARRAYF";
			break;

		case ImageAccess::eImageSize1DI:
			result = "IMAGESIZE1DI";
			break;

		case ImageAccess::eImageSize2DI:
			result = "IMAGESIZE2DI";
			break;

		case ImageAccess::eImageSize3DI:
			result = "IMAGESIZE3DI";
			break;

		case ImageAccess::eImageSizeCubeI:
			result = "IMAGESIZECUBEI";
			break;

		case ImageAccess::eImageSizeCubeArrayI:
			result = "IMAGESIZECUBEARRAYI";
			break;

		case ImageAccess::eImageSize2DRectI:
			result = "IMAGESIZE2DRECTI";
			break;

		case ImageAccess::eImageSize1DArrayI:
			result = "IMAGESIZE1DARRAYI";
			break;

		case ImageAccess::eImageSize2DArrayI:
			result = "IMAGESIZE2DARRAYI";
			break;

		case ImageAccess::eImageSizeBufferI:
			result = "IMAGESIZEBUFFERI";
			break;

		case ImageAccess::eImageSize2DMSI:
			result = "IMAGESIZE2DMSI";
			break;

		case ImageAccess::eImageSize2DMSArrayI:
			result = "IMAGESIZE2DMSARRAYI";
			break;

		case ImageAccess::eImageSize1DU:
			result = "IMAGESIZE1DU";
			break;

		case ImageAccess::eImageSize2DU:
			result = "IMAGESIZE2DU";
			break;

		case ImageAccess::eImageSize3DU:
			result = "IMAGESIZE3DU";
			break;

		case ImageAccess::eImageSizeCubeU:
			result = "IMAGESIZECUBEU";
			break;

		case ImageAccess::eImageSizeCubeArrayU:
			result = "IMAGESIZECUBEARRAYU";
			break;

		case ImageAccess::eImageSize2DRectU:
			result = "IMAGESIZE2DRECTU";
			break;

		case ImageAccess::eImageSize1DArrayU:
			result = "IMAGESIZE1DARRAYU";
			break;

		case ImageAccess::eImageSize2DArrayU:
			result = "IMAGESIZE2DARRAYU";
			break;

		case ImageAccess::eImageSizeBufferU:
			result = "IMAGESIZEBUFFERU";
			break;

		case ImageAccess::eImageSize2DMSU:
			result = "IMAGESIZE2DMSU";
			break;

		case ImageAccess::eImageSize2DMSArrayU:
			result = "IMAGESIZE2DMSARRAYU";
			break;

		case ImageAccess::eImageSample2DMSF:
			result = "IMAGESAMPLE2DMSF";
			break;

		case ImageAccess::eImageSample2DMSArrayF:
			result = "IMAGESAMPLE2DMSARRAYF";
			break;

		case ImageAccess::eImageSample2DMSI:
			result = "IMAGESAMPLE2DMSI";
			break;

		case ImageAccess::eImageSample2DMSArrayI:
			result = "IMAGESAMPLE2DMSARRAYI";
			break;

		case ImageAccess::eImageSample2DMSU:
			result = "IMAGESAMPLE2DMSU";
			break;

		case ImageAccess::eImageSample2DMSArrayU:
			result = "IMAGESAMPLE2DMSARRAYU";
			break;

		case ImageAccess::eImageLoad1DF:
			result = "IMAGELOAD1DF";
			break;

		case ImageAccess::eImageLoad2DF:
			result = "IMAGELOAD2DF";
			break;

		case ImageAccess::eImageLoad3DF:
			result = "IMAGELOAD3DF";
			break;

		case ImageAccess::eImageLoad2DRectF:
			result = "IMAGELOAD2DRECTF";
			break;

		case ImageAccess::eImageLoadCubeF:
			result = "IMAGELOADCUBEF";
			break;

		case ImageAccess::eImageLoadBufferF:
			result = "IMAGELOADBUFFERF";
			break;

		case ImageAccess::eImageLoad1DArrayF:
			result = "IMAGELOAD1DARRAYF";
			break;

		case ImageAccess::eImageLoad2DArrayF:
			result = "IMAGELOAD2DARRAYF";
			break;

		case ImageAccess::eImageLoadCubeArrayF:
			result = "IMAGELOADCUBEARRAYF";
			break;

		case ImageAccess::eImageLoad2DMSF:
			result = "IMAGELOAD2DMSF";
			break;

		case ImageAccess::eImageLoad2DMSArrayF:
			result = "IMAGELOAD2DMSARRAYF";
			break;

		case ImageAccess::eImageLoad1DI:
			result = "IMAGELOAD1DI";
			break;

		case ImageAccess::eImageLoad2DI:
			result = "IMAGELOAD2DI";
			break;

		case ImageAccess::eImageLoad3DI:
			result = "IMAGELOAD3DI";
			break;

		case ImageAccess::eImageLoad2DRectI:
			result = "IMAGELOAD2DRECTI";
			break;

		case ImageAccess::eImageLoadCubeI:
			result = "IMAGELOADCUBEI";
			break;

		case ImageAccess::eImageLoadBufferI:
			result = "IMAGELOADBUFFERI";
			break;

		case ImageAccess::eImageLoad1DArrayI:
			result = "IMAGELOAD1DARRAYI";
			break;

		case ImageAccess::eImageLoad2DArrayI:
			result = "IMAGELOAD2DARRAYI";
			break;

		case ImageAccess::eImageLoadCubeArrayI:
			result = "IMAGELOADCUBEARRAYI";
			break;

		case ImageAccess::eImageLoad2DMSI:
			result = "IMAGELOAD2DMSI";
			break;

		case ImageAccess::eImageLoad2DMSArrayI:
			result = "IMAGELOAD2DMSARRAYI";
			break;

		case ImageAccess::eImageLoad1DU:
			result = "IMAGELOAD1DU";
			break;

		case ImageAccess::eImageLoad2DU:
			result = "IMAGELOAD2DU";
			break;

		case ImageAccess::eImageLoad3DU:
			result = "IMAGELOAD3DU";
			break;

		case ImageAccess::eImageLoad2DRectU:
			result = "IMAGELOAD2DRECTU";
			break;

		case ImageAccess::eImageLoadCubeU:
			result = "IMAGELOADCUBEU";
			break;

		case ImageAccess::eImageLoadBufferU:
			result = "IMAGELOADBUFFERU";
			break;

		case ImageAccess::eImageLoad1DArrayU:
			result = "IMAGELOAD1DARRAYU";
			break;

		case ImageAccess::eImageLoad2DArrayU:
			result = "IMAGELOAD2DARRAYU";
			break;

		case ImageAccess::eImageLoadCubeArrayU:
			result = "IMAGELOADCUBEARRAYU";
			break;

		case ImageAccess::eImageLoad2DMSU:
			result = "IMAGELOAD2DMSU";
			break;

		case ImageAccess::eImageLoad2DMSArrayU:
			result = "IMAGELOAD2DMSARRAYU";
			break;

		case ImageAccess::eImageAtomicAdd1DFU:
			result = "IMAGEATOMICADD1DFU";
			break;

		case ImageAccess::eImageAtomicAdd2DFU:
			result = "IMAGEATOMICADD2DFU";
			break;

		case ImageAccess::eImageAtomicAdd3DFU:
			result = "IMAGEATOMICADD3DFU";
			break;

		case ImageAccess::eImageAtomicAdd2DRectFU:
			result = "IMAGEATOMICADD2DRECTFU";
			break;

		case ImageAccess::eImageAtomicAddCubeFU:
			result = "IMAGEATOMICADDCUBEFU";
			break;

		case ImageAccess::eImageAtomicAddBufferFU:
			result = "IMAGEATOMICADDBUFFERFU";
			break;

		case ImageAccess::eImageAtomicAdd1DArrayFU:
			result = "IMAGEATOMICADD1DARRAYFU";
			break;

		case ImageAccess::eImageAtomicAdd2DArrayFU:
			result = "IMAGEATOMICADD2DARRAYFU";
			break;

		case ImageAccess::eImageAtomicAddCubeArrayFU:
			result = "IMAGEATOMICADDCUBEARRAYFU";
			break;

		case ImageAccess::eImageAtomicAdd2DMSFU:
			result = "IMAGEATOMICADD2DMSFU";
			break;

		case ImageAccess::eImageAtomicAdd2DMSArrayFU:
			result = "IMAGEATOMICADD2DMSARRAYFU";
			break;

		case ImageAccess::eImageAtomicAdd1DIU:
			result = "IMAGEATOMICADD1DIU";
			break;

		case ImageAccess::eImageAtomicAdd2DIU:
			result = "IMAGEATOMICADD2DIU";
			break;

		case ImageAccess::eImageAtomicAdd3DIU:
			result = "IMAGEATOMICADD3DIU";
			break;

		case ImageAccess::eImageAtomicAdd2DRectIU:
			result = "IMAGEATOMICADD2DRECTIU";
			break;

		case ImageAccess::eImageAtomicAddCubeIU:
			result = "IMAGEATOMICADDCUBEIU";
			break;

		case ImageAccess::eImageAtomicAddBufferIU:
			result = "IMAGEATOMICADDBUFFERIU";
			break;

		case ImageAccess::eImageAtomicAdd1DArrayIU:
			result = "IMAGEATOMICADD1DARRAYIU";
			break;

		case ImageAccess::eImageAtomicAdd2DArrayIU:
			result = "IMAGEATOMICADD2DARRAYIU";
			break;

		case ImageAccess::eImageAtomicAddCubeArrayIU:
			result = "IMAGEATOMICADDCUBEARRAYIU";
			break;

		case ImageAccess::eImageAtomicAdd2DMSIU:
			result = "IMAGEATOMICADD2DMSIU";
			break;

		case ImageAccess::eImageAtomicAdd2DMSArrayIU:
			result = "IMAGEATOMICADD2DMSARRAYIU";
			break;

		case ImageAccess::eImageAtomicAdd1DUU:
			result = "IMAGEATOMICADD1DUU";
			break;

		case ImageAccess::eImageAtomicAdd2DUU:
			result = "IMAGEATOMICADD2DUU";
			break;

		case ImageAccess::eImageAtomicAdd3DUU:
			result = "IMAGEATOMICADD3DUU";
			break;

		case ImageAccess::eImageAtomicAdd2DRectUU:
			result = "IMAGEATOMICADD2DRECTUU";
			break;

		case ImageAccess::eImageAtomicAddCubeUU:
			result = "IMAGEATOMICADDCUBEUU";
			break;

		case ImageAccess::eImageAtomicAddBufferUU:
			result = "IMAGEATOMICADDBUFFERUU";
			break;

		case ImageAccess::eImageAtomicAdd1DArrayUU:
			result = "IMAGEATOMICADD1DARRAYUU";
			break;

		case ImageAccess::eImageAtomicAdd2DArrayUU:
			result = "IMAGEATOMICADD2DARRAYUU";
			break;

		case ImageAccess::eImageAtomicAddCubeArrayUU:
			result = "IMAGEATOMICADDCUBEARRAYUU";
			break;

		case ImageAccess::eImageAtomicAdd2DMSUU:
			result = "IMAGEATOMICADD2DMSUU";
			break;

		case ImageAccess::eImageAtomicAdd2DMSArrayUU:
			result = "IMAGEATOMICADD2DMSARRAYUU";
			break;

		case ImageAccess::eImageAtomicAdd1DFI:
			result = "IMAGEATOMICADD1DFI";
			break;

		case ImageAccess::eImageAtomicAdd2DFI:
			result = "IMAGEATOMICADD2DFI";
			break;

		case ImageAccess::eImageAtomicAdd3DFI:
			result = "IMAGEATOMICADD3DFI";
			break;

		case ImageAccess::eImageAtomicAdd2DRectFI:
			result = "IMAGEATOMICADD2DRECTFI";
			break;

		case ImageAccess::eImageAtomicAddCubeFI:
			result = "IMAGEATOMICADDCUBEFI";
			break;

		case ImageAccess::eImageAtomicAddBufferFI:
			result = "IMAGEATOMICADDBUFFERFI";
			break;

		case ImageAccess::eImageAtomicAdd1DArrayFI:
			result = "IMAGEATOMICADD1DARRAYFI";
			break;

		case ImageAccess::eImageAtomicAdd2DArrayFI:
			result = "IMAGEATOMICADD2DARRAYFI";
			break;

		case ImageAccess::eImageAtomicAddCubeArrayFI:
			result = "IMAGEATOMICADDCUBEARRAYFI";
			break;

		case ImageAccess::eImageAtomicAdd2DMSFI:
			result = "IMAGEATOMICADD2DMSFI";
			break;

		case ImageAccess::eImageAtomicAdd2DMSArrayFI:
			result = "IMAGEATOMICADD2DMSARRAYFI";
			break;

		case ImageAccess::eImageAtomicAdd1DII:
			result = "IMAGEATOMICADD1DII";
			break;

		case ImageAccess::eImageAtomicAdd2DII:
			result = "IMAGEATOMICADD2DII";
			break;

		case ImageAccess::eImageAtomicAdd3DII:
			result = "IMAGEATOMICADD3DII";
			break;

		case ImageAccess::eImageAtomicAdd2DRectII:
			result = "IMAGEATOMICADD2DRECTII";
			break;

		case ImageAccess::eImageAtomicAddCubeII:
			result = "IMAGEATOMICADDCUBEII";
			break;

		case ImageAccess::eImageAtomicAddBufferII:
			result = "IMAGEATOMICADDBUFFERII";
			break;

		case ImageAccess::eImageAtomicAdd1DArrayII:
			result = "IMAGEATOMICADD1DARRAYII";
			break;

		case ImageAccess::eImageAtomicAdd2DArrayII:
			result = "IMAGEATOMICADD2DARRAYII";
			break;

		case ImageAccess::eImageAtomicAddCubeArrayII:
			result = "IMAGEATOMICADDCUBEARRAYII";
			break;

		case ImageAccess::eImageAtomicAdd2DMSII:
			result = "IMAGEATOMICADD2DMSII";
			break;

		case ImageAccess::eImageAtomicAdd2DMSArrayII:
			result = "IMAGEATOMICADD2DMSARRAYII";
			break;

		case ImageAccess::eImageAtomicAdd1DUI:
			result = "IMAGEATOMICADD1DUI";
			break;

		case ImageAccess::eImageAtomicAdd2DUI:
			result = "IMAGEATOMICADD2DUI";
			break;

		case ImageAccess::eImageAtomicAdd3DUI:
			result = "IMAGEATOMICADD3DUI";
			break;

		case ImageAccess::eImageAtomicAdd2DRectUI:
			result = "IMAGEATOMICADD2DRECTUI";
			break;

		case ImageAccess::eImageAtomicAddCubeUI:
			result = "IMAGEATOMICADDCUBEUI";
			break;

		case ImageAccess::eImageAtomicAddBufferUI:
			result = "IMAGEATOMICADDBUFFERUI";
			break;

		case ImageAccess::eImageAtomicAdd1DArrayUI:
			result = "IMAGEATOMICADD1DARRAYUI";
			break;

		case ImageAccess::eImageAtomicAdd2DArrayUI:
			result = "IMAGEATOMICADD2DARRAYUI";
			break;

		case ImageAccess::eImageAtomicAddCubeArrayUI:
			result = "IMAGEATOMICADDCUBEARRAYUI";
			break;

		case ImageAccess::eImageAtomicAdd2DMSUI:
			result = "IMAGEATOMICADD2DMSUI";
			break;

		case ImageAccess::eImageAtomicAdd2DMSArrayUI:
			result = "IMAGEATOMICADD2DMSARRAYUI";
			break;

		case ImageAccess::eImageAtomicMin1DFU:
			result = "IMAGEATOMICMIN1DFU";
			break;

		case ImageAccess::eImageAtomicMin2DFU:
			result = "IMAGEATOMICMIN2DFU";
			break;

		case ImageAccess::eImageAtomicMin3DFU:
			result = "IMAGEATOMICMIN3DFU";
			break;

		case ImageAccess::eImageAtomicMin2DRectFU:
			result = "IMAGEATOMICMIN2DRECTFU";
			break;

		case ImageAccess::eImageAtomicMinCubeFU:
			result = "IMAGEATOMICMINCUBEFU";
			break;

		case ImageAccess::eImageAtomicMinBufferFU:
			result = "IMAGEATOMICMINBUFFERFU";
			break;

		case ImageAccess::eImageAtomicMin1DArrayFU:
			result = "IMAGEATOMICMIN1DARRAYFU";
			break;

		case ImageAccess::eImageAtomicMin2DArrayFU:
			result = "IMAGEATOMICMIN2DARRAYFU";
			break;

		case ImageAccess::eImageAtomicMinCubeArrayFU:
			result = "IMAGEATOMICMINCUBEARRAYFU";
			break;

		case ImageAccess::eImageAtomicMin2DMSFU:
			result = "IMAGEATOMICMIN2DMSFU";
			break;

		case ImageAccess::eImageAtomicMin2DMSArrayFU:
			result = "IMAGEATOMICMIN2DMSARRAYFU";
			break;

		case ImageAccess::eImageAtomicMin1DIU:
			result = "IMAGEATOMICMIN1DIU";
			break;

		case ImageAccess::eImageAtomicMin2DIU:
			result = "IMAGEATOMICMIN2DIU";
			break;

		case ImageAccess::eImageAtomicMin3DIU:
			result = "IMAGEATOMICMIN3DIU";
			break;

		case ImageAccess::eImageAtomicMin2DRectIU:
			result = "IMAGEATOMICMIN2DRECTIU";
			break;

		case ImageAccess::eImageAtomicMinCubeIU:
			result = "IMAGEATOMICMINCUBEIU";
			break;

		case ImageAccess::eImageAtomicMinBufferIU:
			result = "IMAGEATOMICMINBUFFERIU";
			break;

		case ImageAccess::eImageAtomicMin1DArrayIU:
			result = "IMAGEATOMICMIN1DARRAYIU";
			break;

		case ImageAccess::eImageAtomicMin2DArrayIU:
			result = "IMAGEATOMICMIN2DARRAYIU";
			break;

		case ImageAccess::eImageAtomicMinCubeArrayIU:
			result = "IMAGEATOMICMINCUBEARRAYIU";
			break;

		case ImageAccess::eImageAtomicMin2DMSIU:
			result = "IMAGEATOMICMIN2DMSIU";
			break;

		case ImageAccess::eImageAtomicMin2DMSArrayIU:
			result = "IMAGEATOMICMIN2DMSARRAYIU";
			break;

		case ImageAccess::eImageAtomicMin1DUU:
			result = "IMAGEATOMICMIN1DUU";
			break;

		case ImageAccess::eImageAtomicMin2DUU:
			result = "IMAGEATOMICMIN2DUU";
			break;

		case ImageAccess::eImageAtomicMin3DUU:
			result = "IMAGEATOMICMIN3DUU";
			break;

		case ImageAccess::eImageAtomicMin2DRectUU:
			result = "IMAGEATOMICMIN2DRECTUU";
			break;

		case ImageAccess::eImageAtomicMinCubeUU:
			result = "IMAGEATOMICMINCUBEUU";
			break;

		case ImageAccess::eImageAtomicMinBufferUU:
			result = "IMAGEATOMICMINBUFFERUU";
			break;

		case ImageAccess::eImageAtomicMin1DArrayUU:
			result = "IMAGEATOMICMIN1DARRAYUU";
			break;

		case ImageAccess::eImageAtomicMin2DArrayUU:
			result = "IMAGEATOMICMIN2DARRAYUU";
			break;

		case ImageAccess::eImageAtomicMinCubeArrayUU:
			result = "IMAGEATOMICMINCUBEARRAYUU";
			break;

		case ImageAccess::eImageAtomicMin2DMSUU:
			result = "IMAGEATOMICMIN2DMSUU";
			break;

		case ImageAccess::eImageAtomicMin2DMSArrayUU:
			result = "IMAGEATOMICMIN2DMSARRAYUU";
			break;

		case ImageAccess::eImageAtomicMin1DFI:
			result = "IMAGEATOMICMIN1DFI";
			break;

		case ImageAccess::eImageAtomicMin2DFI:
			result = "IMAGEATOMICMIN2DFI";
			break;

		case ImageAccess::eImageAtomicMin3DFI:
			result = "IMAGEATOMICMIN3DFI";
			break;

		case ImageAccess::eImageAtomicMin2DRectFI:
			result = "IMAGEATOMICMIN2DRECTFI";
			break;

		case ImageAccess::eImageAtomicMinCubeFI:
			result = "IMAGEATOMICMINCUBEFI";
			break;

		case ImageAccess::eImageAtomicMinBufferFI:
			result = "IMAGEATOMICMINBUFFERFI";
			break;

		case ImageAccess::eImageAtomicMin1DArrayFI:
			result = "IMAGEATOMICMIN1DARRAYFI";
			break;

		case ImageAccess::eImageAtomicMin2DArrayFI:
			result = "IMAGEATOMICMIN2DARRAYFI";
			break;

		case ImageAccess::eImageAtomicMinCubeArrayFI:
			result = "IMAGEATOMICMINCUBEARRAYFI";
			break;

		case ImageAccess::eImageAtomicMin2DMSFI:
			result = "IMAGEATOMICMIN2DMSFI";
			break;

		case ImageAccess::eImageAtomicMin2DMSArrayFI:
			result = "IMAGEATOMICMIN2DMSARRAYFI";
			break;

		case ImageAccess::eImageAtomicMin1DII:
			result = "IMAGEATOMICMIN1DII";
			break;

		case ImageAccess::eImageAtomicMin2DII:
			result = "IMAGEATOMICMIN2DII";
			break;

		case ImageAccess::eImageAtomicMin3DII:
			result = "IMAGEATOMICMIN3DII";
			break;

		case ImageAccess::eImageAtomicMin2DRectII:
			result = "IMAGEATOMICMIN2DRECTII";
			break;

		case ImageAccess::eImageAtomicMinCubeII:
			result = "IMAGEATOMICMINCUBEII";
			break;

		case ImageAccess::eImageAtomicMinBufferII:
			result = "IMAGEATOMICMINBUFFERII";
			break;

		case ImageAccess::eImageAtomicMin1DArrayII:
			result = "IMAGEATOMICMIN1DARRAYII";
			break;

		case ImageAccess::eImageAtomicMin2DArrayII:
			result = "IMAGEATOMICMIN2DARRAYII";
			break;

		case ImageAccess::eImageAtomicMinCubeArrayII:
			result = "IMAGEATOMICMINCUBEARRAYII";
			break;

		case ImageAccess::eImageAtomicMin2DMSII:
			result = "IMAGEATOMICMIN2DMSII";
			break;

		case ImageAccess::eImageAtomicMin2DMSArrayII:
			result = "IMAGEATOMICMIN2DMSARRAYII";
			break;

		case ImageAccess::eImageAtomicMin1DUI:
			result = "IMAGEATOMICMIN1DUI";
			break;

		case ImageAccess::eImageAtomicMin2DUI:
			result = "IMAGEATOMICMIN2DUI";
			break;

		case ImageAccess::eImageAtomicMin3DUI:
			result = "IMAGEATOMICMIN3DUI";
			break;

		case ImageAccess::eImageAtomicMin2DRectUI:
			result = "IMAGEATOMICMIN2DRECTUI";
			break;

		case ImageAccess::eImageAtomicMinCubeUI:
			result = "IMAGEATOMICMINCUBEUI";
			break;

		case ImageAccess::eImageAtomicMinBufferUI:
			result = "IMAGEATOMICMINBUFFERUI";
			break;

		case ImageAccess::eImageAtomicMin1DArrayUI:
			result = "IMAGEATOMICMIN1DARRAYUI";
			break;

		case ImageAccess::eImageAtomicMin2DArrayUI:
			result = "IMAGEATOMICMIN2DARRAYUI";
			break;

		case ImageAccess::eImageAtomicMinCubeArrayUI:
			result = "IMAGEATOMICMINCUBEARRAYUI";
			break;

		case ImageAccess::eImageAtomicMin2DMSUI:
			result = "IMAGEATOMICMIN2DMSUI";
			break;

		case ImageAccess::eImageAtomicMin2DMSArrayUI:
			result = "IMAGEATOMICMIN2DMSARRAYUI";
			break;

		case ImageAccess::eImageAtomicMax1DFU:
			result = "IMAGEATOMICMAX1DFU";
			break;

		case ImageAccess::eImageAtomicMax2DFU:
			result = "IMAGEATOMICMAX2DFU";
			break;

		case ImageAccess::eImageAtomicMax3DFU:
			result = "IMAGEATOMICMAX3DFU";
			break;

		case ImageAccess::eImageAtomicMax2DRectFU:
			result = "IMAGEATOMICMAX2DRECTFU";
			break;

		case ImageAccess::eImageAtomicMaxCubeFU:
			result = "IMAGEATOMICMAXCUBEFU";
			break;

		case ImageAccess::eImageAtomicMaxBufferFU:
			result = "IMAGEATOMICMAXBUFFERFU";
			break;

		case ImageAccess::eImageAtomicMax1DArrayFU:
			result = "IMAGEATOMICMAX1DARRAYFU";
			break;

		case ImageAccess::eImageAtomicMax2DArrayFU:
			result = "IMAGEATOMICMAX2DARRAYFU";
			break;

		case ImageAccess::eImageAtomicMaxCubeArrayFU:
			result = "IMAGEATOMICMAXCUBEARRAYFU";
			break;

		case ImageAccess::eImageAtomicMax2DMSFU:
			result = "IMAGEATOMICMAX2DMSFU";
			break;

		case ImageAccess::eImageAtomicMax2DMSArrayFU:
			result = "IMAGEATOMICMAX2DMSARRAYFU";
			break;

		case ImageAccess::eImageAtomicMax1DIU:
			result = "IMAGEATOMICMAX1DIU";
			break;

		case ImageAccess::eImageAtomicMax2DIU:
			result = "IMAGEATOMICMAX2DIU";
			break;

		case ImageAccess::eImageAtomicMax3DIU:
			result = "IMAGEATOMICMAX3DIU";
			break;

		case ImageAccess::eImageAtomicMax2DRectIU:
			result = "IMAGEATOMICMAX2DRECTIU";
			break;

		case ImageAccess::eImageAtomicMaxCubeIU:
			result = "IMAGEATOMICMAXCUBEIU";
			break;

		case ImageAccess::eImageAtomicMaxBufferIU:
			result = "IMAGEATOMICMAXBUFFERIU";
			break;

		case ImageAccess::eImageAtomicMax1DArrayIU:
			result = "IMAGEATOMICMAX1DARRAYIU";
			break;

		case ImageAccess::eImageAtomicMax2DArrayIU:
			result = "IMAGEATOMICMAX2DARRAYIU";
			break;

		case ImageAccess::eImageAtomicMaxCubeArrayIU:
			result = "IMAGEATOMICMAXCUBEARRAYIU";
			break;

		case ImageAccess::eImageAtomicMax2DMSIU:
			result = "IMAGEATOMICMAX2DMSIU";
			break;

		case ImageAccess::eImageAtomicMax2DMSArrayIU:
			result = "IMAGEATOMICMAX2DMSARRAYIU";
			break;

		case ImageAccess::eImageAtomicMax1DUU:
			result = "IMAGEATOMICMAX1DUU";
			break;

		case ImageAccess::eImageAtomicMax2DUU:
			result = "IMAGEATOMICMAX2DUU";
			break;

		case ImageAccess::eImageAtomicMax3DUU:
			result = "IMAGEATOMICMAX3DUU";
			break;

		case ImageAccess::eImageAtomicMax2DRectUU:
			result = "IMAGEATOMICMAX2DRECTUU";
			break;

		case ImageAccess::eImageAtomicMaxCubeUU:
			result = "IMAGEATOMICMAXCUBEUU";
			break;

		case ImageAccess::eImageAtomicMaxBufferUU:
			result = "IMAGEATOMICMAXBUFFERUU";
			break;

		case ImageAccess::eImageAtomicMax1DArrayUU:
			result = "IMAGEATOMICMAX1DARRAYUU";
			break;

		case ImageAccess::eImageAtomicMax2DArrayUU:
			result = "IMAGEATOMICMAX2DARRAYUU";
			break;

		case ImageAccess::eImageAtomicMaxCubeArrayUU:
			result = "IMAGEATOMICMAXCUBEARRAYUU";
			break;

		case ImageAccess::eImageAtomicMax2DMSUU:
			result = "IMAGEATOMICMAX2DMSUU";
			break;

		case ImageAccess::eImageAtomicMax2DMSArrayUU:
			result = "IMAGEATOMICMAX2DMSARRAYUU";
			break;

		case ImageAccess::eImageAtomicMax1DFI:
			result = "IMAGEATOMICMAX1DFI";
			break;

		case ImageAccess::eImageAtomicMax2DFI:
			result = "IMAGEATOMICMAX2DFI";
			break;

		case ImageAccess::eImageAtomicMax3DFI:
			result = "IMAGEATOMICMAX3DFI";
			break;

		case ImageAccess::eImageAtomicMax2DRectFI:
			result = "IMAGEATOMICMAX2DRECTFI";
			break;

		case ImageAccess::eImageAtomicMaxCubeFI:
			result = "IMAGEATOMICMAXCUBEFI";
			break;

		case ImageAccess::eImageAtomicMaxBufferFI:
			result = "IMAGEATOMICMAXBUFFERFI";
			break;

		case ImageAccess::eImageAtomicMax1DArrayFI:
			result = "IMAGEATOMICMAX1DARRAYFI";
			break;

		case ImageAccess::eImageAtomicMax2DArrayFI:
			result = "IMAGEATOMICMAX2DARRAYFI";
			break;

		case ImageAccess::eImageAtomicMaxCubeArrayFI:
			result = "IMAGEATOMICMAXCUBEARRAYFI";
			break;

		case ImageAccess::eImageAtomicMax2DMSFI:
			result = "IMAGEATOMICMAX2DMSFI";
			break;

		case ImageAccess::eImageAtomicMax2DMSArrayFI:
			result = "IMAGEATOMICMAX2DMSARRAYFI";
			break;

		case ImageAccess::eImageAtomicMax1DII:
			result = "IMAGEATOMICMAX1DII";
			break;

		case ImageAccess::eImageAtomicMax2DII:
			result = "IMAGEATOMICMAX2DII";
			break;

		case ImageAccess::eImageAtomicMax3DII:
			result = "IMAGEATOMICMAX3DII";
			break;

		case ImageAccess::eImageAtomicMax2DRectII:
			result = "IMAGEATOMICMAX2DRECTII";
			break;

		case ImageAccess::eImageAtomicMaxCubeII:
			result = "IMAGEATOMICMAXCUBEII";
			break;

		case ImageAccess::eImageAtomicMaxBufferII:
			result = "IMAGEATOMICMAXBUFFERII";
			break;

		case ImageAccess::eImageAtomicMax1DArrayII:
			result = "IMAGEATOMICMAX1DARRAYII";
			break;

		case ImageAccess::eImageAtomicMax2DArrayII:
			result = "IMAGEATOMICMAX2DARRAYII";
			break;

		case ImageAccess::eImageAtomicMaxCubeArrayII:
			result = "IMAGEATOMICMAXCUBEARRAYII";
			break;

		case ImageAccess::eImageAtomicMax2DMSII:
			result = "IMAGEATOMICMAX2DMSII";
			break;

		case ImageAccess::eImageAtomicMax2DMSArrayII:
			result = "IMAGEATOMICMAX2DMSARRAYII";
			break;

		case ImageAccess::eImageAtomicMax1DUI:
			result = "IMAGEATOMICMAX1DUI";
			break;

		case ImageAccess::eImageAtomicMax2DUI:
			result = "IMAGEATOMICMAX2DUI";
			break;

		case ImageAccess::eImageAtomicMax3DUI:
			result = "IMAGEATOMICMAX3DUI";
			break;

		case ImageAccess::eImageAtomicMax2DRectUI:
			result = "IMAGEATOMICMAX2DRECTUI";
			break;

		case ImageAccess::eImageAtomicMaxCubeUI:
			result = "IMAGEATOMICMAXCUBEUI";
			break;

		case ImageAccess::eImageAtomicMaxBufferUI:
			result = "IMAGEATOMICMAXBUFFERUI";
			break;

		case ImageAccess::eImageAtomicMax1DArrayUI:
			result = "IMAGEATOMICMAX1DARRAYUI";
			break;

		case ImageAccess::eImageAtomicMax2DArrayUI:
			result = "IMAGEATOMICMAX2DARRAYUI";
			break;

		case ImageAccess::eImageAtomicMaxCubeArrayUI:
			result = "IMAGEATOMICMAXCUBEARRAYUI";
			break;

		case ImageAccess::eImageAtomicMax2DMSUI:
			result = "IMAGEATOMICMAX2DMSUI";
			break;

		case ImageAccess::eImageAtomicMax2DMSArrayUI:
			result = "IMAGEATOMICMAX2DMSARRAYUI";
			break;

		case ImageAccess::eImageAtomicAnd1DFU:
			result = "IMAGEATOMICAND1DFU";
			break;

		case ImageAccess::eImageAtomicAnd2DFU:
			result = "IMAGEATOMICAND2DFU";
			break;

		case ImageAccess::eImageAtomicAnd3DFU:
			result = "IMAGEATOMICAND3DFU";
			break;

		case ImageAccess::eImageAtomicAnd2DRectFU:
			result = "IMAGEATOMICAND2DRECTFU";
			break;

		case ImageAccess::eImageAtomicAndCubeFU:
			result = "IMAGEATOMICANDCUBEFU";
			break;

		case ImageAccess::eImageAtomicAndBufferFU:
			result = "IMAGEATOMICANDBUFFERFU";
			break;

		case ImageAccess::eImageAtomicAnd1DArrayFU:
			result = "IMAGEATOMICAND1DARRAYFU";
			break;

		case ImageAccess::eImageAtomicAnd2DArrayFU:
			result = "IMAGEATOMICAND2DARRAYFU";
			break;

		case ImageAccess::eImageAtomicAndCubeArrayFU:
			result = "IMAGEATOMICANDCUBEARRAYFU";
			break;

		case ImageAccess::eImageAtomicAnd2DMSFU:
			result = "IMAGEATOMICAND2DMSFU";
			break;

		case ImageAccess::eImageAtomicAnd2DMSArrayFU:
			result = "IMAGEATOMICAND2DMSARRAYFU";
			break;

		case ImageAccess::eImageAtomicAnd1DIU:
			result = "IMAGEATOMICAND1DIU";
			break;

		case ImageAccess::eImageAtomicAnd2DIU:
			result = "IMAGEATOMICAND2DIU";
			break;

		case ImageAccess::eImageAtomicAnd3DIU:
			result = "IMAGEATOMICAND3DIU";
			break;

		case ImageAccess::eImageAtomicAnd2DRectIU:
			result = "IMAGEATOMICAND2DRECTIU";
			break;

		case ImageAccess::eImageAtomicAndCubeIU:
			result = "IMAGEATOMICANDCUBEIU";
			break;

		case ImageAccess::eImageAtomicAndBufferIU:
			result = "IMAGEATOMICANDBUFFERIU";
			break;

		case ImageAccess::eImageAtomicAnd1DArrayIU:
			result = "IMAGEATOMICAND1DARRAYIU";
			break;

		case ImageAccess::eImageAtomicAnd2DArrayIU:
			result = "IMAGEATOMICAND2DARRAYIU";
			break;

		case ImageAccess::eImageAtomicAndCubeArrayIU:
			result = "IMAGEATOMICANDCUBEARRAYIU";
			break;

		case ImageAccess::eImageAtomicAnd2DMSIU:
			result = "IMAGEATOMICAND2DMSIU";
			break;

		case ImageAccess::eImageAtomicAnd2DMSArrayIU:
			result = "IMAGEATOMICAND2DMSARRAYIU";
			break;

		case ImageAccess::eImageAtomicAnd1DUU:
			result = "IMAGEATOMICAND1DUU";
			break;

		case ImageAccess::eImageAtomicAnd2DUU:
			result = "IMAGEATOMICAND2DUU";
			break;

		case ImageAccess::eImageAtomicAnd3DUU:
			result = "IMAGEATOMICAND3DUU";
			break;

		case ImageAccess::eImageAtomicAnd2DRectUU:
			result = "IMAGEATOMICAND2DRECTUU";
			break;

		case ImageAccess::eImageAtomicAndCubeUU:
			result = "IMAGEATOMICANDCUBEUU";
			break;

		case ImageAccess::eImageAtomicAndBufferUU:
			result = "IMAGEATOMICANDBUFFERUU";
			break;

		case ImageAccess::eImageAtomicAnd1DArrayUU:
			result = "IMAGEATOMICAND1DARRAYUU";
			break;

		case ImageAccess::eImageAtomicAnd2DArrayUU:
			result = "IMAGEATOMICAND2DARRAYUU";
			break;

		case ImageAccess::eImageAtomicAndCubeArrayUU:
			result = "IMAGEATOMICANDCUBEARRAYUU";
			break;

		case ImageAccess::eImageAtomicAnd2DMSUU:
			result = "IMAGEATOMICAND2DMSUU";
			break;

		case ImageAccess::eImageAtomicAnd2DMSArrayUU:
			result = "IMAGEATOMICAND2DMSARRAYUU";
			break;

		case ImageAccess::eImageAtomicAnd1DFI:
			result = "IMAGEATOMICAND1DFI";
			break;

		case ImageAccess::eImageAtomicAnd2DFI:
			result = "IMAGEATOMICAND2DFI";
			break;

		case ImageAccess::eImageAtomicAnd3DFI:
			result = "IMAGEATOMICAND3DFI";
			break;

		case ImageAccess::eImageAtomicAnd2DRectFI:
			result = "IMAGEATOMICAND2DRECTFI";
			break;

		case ImageAccess::eImageAtomicAndCubeFI:
			result = "IMAGEATOMICANDCUBEFI";
			break;

		case ImageAccess::eImageAtomicAndBufferFI:
			result = "IMAGEATOMICANDBUFFERFI";
			break;

		case ImageAccess::eImageAtomicAnd1DArrayFI:
			result = "IMAGEATOMICAND1DARRAYFI";
			break;

		case ImageAccess::eImageAtomicAnd2DArrayFI:
			result = "IMAGEATOMICAND2DARRAYFI";
			break;

		case ImageAccess::eImageAtomicAndCubeArrayFI:
			result = "IMAGEATOMICANDCUBEARRAYFI";
			break;

		case ImageAccess::eImageAtomicAnd2DMSFI:
			result = "IMAGEATOMICAND2DMSFI";
			break;

		case ImageAccess::eImageAtomicAnd2DMSArrayFI:
			result = "IMAGEATOMICAND2DMSARRAYFI";
			break;

		case ImageAccess::eImageAtomicAnd1DII:
			result = "IMAGEATOMICAND1DII";
			break;

		case ImageAccess::eImageAtomicAnd2DII:
			result = "IMAGEATOMICAND2DII";
			break;

		case ImageAccess::eImageAtomicAnd3DII:
			result = "IMAGEATOMICAND3DII";
			break;

		case ImageAccess::eImageAtomicAnd2DRectII:
			result = "IMAGEATOMICAND2DRECTII";
			break;

		case ImageAccess::eImageAtomicAndCubeII:
			result = "IMAGEATOMICANDCUBEII";
			break;

		case ImageAccess::eImageAtomicAndBufferII:
			result = "IMAGEATOMICANDBUFFERII";
			break;

		case ImageAccess::eImageAtomicAnd1DArrayII:
			result = "IMAGEATOMICAND1DARRAYII";
			break;

		case ImageAccess::eImageAtomicAnd2DArrayII:
			result = "IMAGEATOMICAND2DARRAYII";
			break;

		case ImageAccess::eImageAtomicAndCubeArrayII:
			result = "IMAGEATOMICANDCUBEARRAYII";
			break;

		case ImageAccess::eImageAtomicAnd2DMSII:
			result = "IMAGEATOMICAND2DMSII";
			break;

		case ImageAccess::eImageAtomicAnd2DMSArrayII:
			result = "IMAGEATOMICAND2DMSARRAYII";
			break;

		case ImageAccess::eImageAtomicAnd1DUI:
			result = "IMAGEATOMICAND1DUI";
			break;

		case ImageAccess::eImageAtomicAnd2DUI:
			result = "IMAGEATOMICAND2DUI";
			break;

		case ImageAccess::eImageAtomicAnd3DUI:
			result = "IMAGEATOMICAND3DUI";
			break;

		case ImageAccess::eImageAtomicAnd2DRectUI:
			result = "IMAGEATOMICAND2DRECTUI";
			break;

		case ImageAccess::eImageAtomicAndCubeUI:
			result = "IMAGEATOMICANDCUBEUI";
			break;

		case ImageAccess::eImageAtomicAndBufferUI:
			result = "IMAGEATOMICANDBUFFERUI";
			break;

		case ImageAccess::eImageAtomicAnd1DArrayUI:
			result = "IMAGEATOMICAND1DARRAYUI";
			break;

		case ImageAccess::eImageAtomicAnd2DArrayUI:
			result = "IMAGEATOMICAND2DARRAYUI";
			break;

		case ImageAccess::eImageAtomicAndCubeArrayUI:
			result = "IMAGEATOMICANDCUBEARRAYUI";
			break;

		case ImageAccess::eImageAtomicAnd2DMSUI:
			result = "IMAGEATOMICAND2DMSUI";
			break;

		case ImageAccess::eImageAtomicAnd2DMSArrayUI:
			result = "IMAGEATOMICAND2DMSARRAYUI";
			break;

		case ImageAccess::eImageAtomicOr1DFU:
			result = "IMAGEATOMICOR1DFU";
			break;

		case ImageAccess::eImageAtomicOr2DFU:
			result = "IMAGEATOMICOR2DFU";
			break;

		case ImageAccess::eImageAtomicOr3DFU:
			result = "IMAGEATOMICOR3DFU";
			break;

		case ImageAccess::eImageAtomicOr2DRectFU:
			result = "IMAGEATOMICOR2DRECTFU";
			break;

		case ImageAccess::eImageAtomicOrCubeFU:
			result = "IMAGEATOMICORCUBEFU";
			break;

		case ImageAccess::eImageAtomicOrBufferFU:
			result = "IMAGEATOMICORBUFFERFU";
			break;

		case ImageAccess::eImageAtomicOr1DArrayFU:
			result = "IMAGEATOMICOR1DARRAYFU";
			break;

		case ImageAccess::eImageAtomicOr2DArrayFU:
			result = "IMAGEATOMICOR2DARRAYFU";
			break;

		case ImageAccess::eImageAtomicOrCubeArrayFU:
			result = "IMAGEATOMICORCUBEARRAYFU";
			break;

		case ImageAccess::eImageAtomicOr2DMSFU:
			result = "IMAGEATOMICOR2DMSFU";
			break;

		case ImageAccess::eImageAtomicOr2DMSArrayFU:
			result = "IMAGEATOMICOR2DMSARRAYFU";
			break;

		case ImageAccess::eImageAtomicOr1DIU:
			result = "IMAGEATOMICOR1DIU";
			break;

		case ImageAccess::eImageAtomicOr2DIU:
			result = "IMAGEATOMICOR2DIU";
			break;

		case ImageAccess::eImageAtomicOr3DIU:
			result = "IMAGEATOMICOR3DIU";
			break;

		case ImageAccess::eImageAtomicOr2DRectIU:
			result = "IMAGEATOMICOR2DRECTIU";
			break;

		case ImageAccess::eImageAtomicOrCubeIU:
			result = "IMAGEATOMICORCUBEIU";
			break;

		case ImageAccess::eImageAtomicOrBufferIU:
			result = "IMAGEATOMICORBUFFERIU";
			break;

		case ImageAccess::eImageAtomicOr1DArrayIU:
			result = "IMAGEATOMICOR1DARRAYIU";
			break;

		case ImageAccess::eImageAtomicOr2DArrayIU:
			result = "IMAGEATOMICOR2DARRAYIU";
			break;

		case ImageAccess::eImageAtomicOrCubeArrayIU:
			result = "IMAGEATOMICORCUBEARRAYIU";
			break;

		case ImageAccess::eImageAtomicOr2DMSIU:
			result = "IMAGEATOMICOR2DMSIU";
			break;

		case ImageAccess::eImageAtomicOr2DMSArrayIU:
			result = "IMAGEATOMICOR2DMSARRAYIU";
			break;

		case ImageAccess::eImageAtomicOr1DUU:
			result = "IMAGEATOMICOR1DUU";
			break;

		case ImageAccess::eImageAtomicOr2DUU:
			result = "IMAGEATOMICOR2DUU";
			break;

		case ImageAccess::eImageAtomicOr3DUU:
			result = "IMAGEATOMICOR3DUU";
			break;

		case ImageAccess::eImageAtomicOr2DRectUU:
			result = "IMAGEATOMICOR2DRECTUU";
			break;

		case ImageAccess::eImageAtomicOrCubeUU:
			result = "IMAGEATOMICORCUBEUU";
			break;

		case ImageAccess::eImageAtomicOrBufferUU:
			result = "IMAGEATOMICORBUFFERUU";
			break;

		case ImageAccess::eImageAtomicOr1DArrayUU:
			result = "IMAGEATOMICOR1DARRAYUU";
			break;

		case ImageAccess::eImageAtomicOr2DArrayUU:
			result = "IMAGEATOMICOR2DARRAYUU";
			break;

		case ImageAccess::eImageAtomicOrCubeArrayUU:
			result = "IMAGEATOMICORCUBEARRAYUU";
			break;

		case ImageAccess::eImageAtomicOr2DMSUU:
			result = "IMAGEATOMICOR2DMSUU";
			break;

		case ImageAccess::eImageAtomicOr2DMSArrayUU:
			result = "IMAGEATOMICOR2DMSARRAYUU";
			break;

		case ImageAccess::eImageAtomicOr1DFI:
			result = "IMAGEATOMICOR1DFI";
			break;

		case ImageAccess::eImageAtomicOr2DFI:
			result = "IMAGEATOMICOR2DFI";
			break;

		case ImageAccess::eImageAtomicOr3DFI:
			result = "IMAGEATOMICOR3DFI";
			break;

		case ImageAccess::eImageAtomicOr2DRectFI:
			result = "IMAGEATOMICOR2DRECTFI";
			break;

		case ImageAccess::eImageAtomicOrCubeFI:
			result = "IMAGEATOMICORCUBEFI";
			break;

		case ImageAccess::eImageAtomicOrBufferFI:
			result = "IMAGEATOMICORBUFFERFI";
			break;

		case ImageAccess::eImageAtomicOr1DArrayFI:
			result = "IMAGEATOMICOR1DARRAYFI";
			break;

		case ImageAccess::eImageAtomicOr2DArrayFI:
			result = "IMAGEATOMICOR2DARRAYFI";
			break;

		case ImageAccess::eImageAtomicOrCubeArrayFI:
			result = "IMAGEATOMICORCUBEARRAYFI";
			break;

		case ImageAccess::eImageAtomicOr2DMSFI:
			result = "IMAGEATOMICOR2DMSFI";
			break;

		case ImageAccess::eImageAtomicOr2DMSArrayFI:
			result = "IMAGEATOMICOR2DMSARRAYFI";
			break;

		case ImageAccess::eImageAtomicOr1DII:
			result = "IMAGEATOMICOR1DII";
			break;

		case ImageAccess::eImageAtomicOr2DII:
			result = "IMAGEATOMICOR2DII";
			break;

		case ImageAccess::eImageAtomicOr3DII:
			result = "IMAGEATOMICOR3DII";
			break;

		case ImageAccess::eImageAtomicOr2DRectII:
			result = "IMAGEATOMICOR2DRECTII";
			break;

		case ImageAccess::eImageAtomicOrCubeII:
			result = "IMAGEATOMICORCUBEII";
			break;

		case ImageAccess::eImageAtomicOrBufferII:
			result = "IMAGEATOMICORBUFFERII";
			break;

		case ImageAccess::eImageAtomicOr1DArrayII:
			result = "IMAGEATOMICOR1DARRAYII";
			break;

		case ImageAccess::eImageAtomicOr2DArrayII:
			result = "IMAGEATOMICOR2DARRAYII";
			break;

		case ImageAccess::eImageAtomicOrCubeArrayII:
			result = "IMAGEATOMICORCUBEARRAYII";
			break;

		case ImageAccess::eImageAtomicOr2DMSII:
			result = "IMAGEATOMICOR2DMSII";
			break;

		case ImageAccess::eImageAtomicOr2DMSArrayII:
			result = "IMAGEATOMICOR2DMSARRAYII";
			break;

		case ImageAccess::eImageAtomicOr1DUI:
			result = "IMAGEATOMICOR1DUI";
			break;

		case ImageAccess::eImageAtomicOr2DUI:
			result = "IMAGEATOMICOR2DUI";
			break;

		case ImageAccess::eImageAtomicOr3DUI:
			result = "IMAGEATOMICOR3DUI";
			break;

		case ImageAccess::eImageAtomicOr2DRectUI:
			result = "IMAGEATOMICOR2DRECTUI";
			break;

		case ImageAccess::eImageAtomicOrCubeUI:
			result = "IMAGEATOMICORCUBEUI";
			break;

		case ImageAccess::eImageAtomicOrBufferUI:
			result = "IMAGEATOMICORBUFFERUI";
			break;

		case ImageAccess::eImageAtomicOr1DArrayUI:
			result = "IMAGEATOMICOR1DARRAYUI";
			break;

		case ImageAccess::eImageAtomicOr2DArrayUI:
			result = "IMAGEATOMICOR2DARRAYUI";
			break;

		case ImageAccess::eImageAtomicOrCubeArrayUI:
			result = "IMAGEATOMICORCUBEARRAYUI";
			break;

		case ImageAccess::eImageAtomicOr2DMSUI:
			result = "IMAGEATOMICOR2DMSUI";
			break;

		case ImageAccess::eImageAtomicOr2DMSArrayUI:
			result = "IMAGEATOMICOR2DMSARRAYUI";
			break;

		case ImageAccess::eImageAtomicXor1DFU:
			result = "IMAGEATOMICXOR1DFU";
			break;

		case ImageAccess::eImageAtomicXor2DFU:
			result = "IMAGEATOMICXOR2DFU";
			break;

		case ImageAccess::eImageAtomicXor3DFU:
			result = "IMAGEATOMICXOR3DFU";
			break;

		case ImageAccess::eImageAtomicXor2DRectFU:
			result = "IMAGEATOMICXOR2DRECTFU";
			break;

		case ImageAccess::eImageAtomicXorCubeFU:
			result = "IMAGEATOMICXORCUBEFU";
			break;

		case ImageAccess::eImageAtomicXorBufferFU:
			result = "IMAGEATOMICXORBUFFERFU";
			break;

		case ImageAccess::eImageAtomicXor1DArrayFU:
			result = "IMAGEATOMICXOR1DARRAYFU";
			break;

		case ImageAccess::eImageAtomicXor2DArrayFU:
			result = "IMAGEATOMICXOR2DARRAYFU";
			break;

		case ImageAccess::eImageAtomicXorCubeArrayFU:
			result = "IMAGEATOMICXORCUBEARRAYFU";
			break;

		case ImageAccess::eImageAtomicXor2DMSFU:
			result = "IMAGEATOMICXOR2DMSFU";
			break;

		case ImageAccess::eImageAtomicXor2DMSArrayFU:
			result = "IMAGEATOMICXOR2DMSARRAYFU";
			break;

		case ImageAccess::eImageAtomicXor1DIU:
			result = "IMAGEATOMICXOR1DIU";
			break;

		case ImageAccess::eImageAtomicXor2DIU:
			result = "IMAGEATOMICXOR2DIU";
			break;

		case ImageAccess::eImageAtomicXor3DIU:
			result = "IMAGEATOMICXOR3DIU";
			break;

		case ImageAccess::eImageAtomicXor2DRectIU:
			result = "IMAGEATOMICXOR2DRECTIU";
			break;

		case ImageAccess::eImageAtomicXorCubeIU:
			result = "IMAGEATOMICXORCUBEIU";
			break;

		case ImageAccess::eImageAtomicXorBufferIU:
			result = "IMAGEATOMICXORBUFFERIU";
			break;

		case ImageAccess::eImageAtomicXor1DArrayIU:
			result = "IMAGEATOMICXOR1DARRAYIU";
			break;

		case ImageAccess::eImageAtomicXor2DArrayIU:
			result = "IMAGEATOMICXOR2DARRAYIU";
			break;

		case ImageAccess::eImageAtomicXorCubeArrayIU:
			result = "IMAGEATOMICXORCUBEARRAYIU";
			break;

		case ImageAccess::eImageAtomicXor2DMSIU:
			result = "IMAGEATOMICXOR2DMSIU";
			break;

		case ImageAccess::eImageAtomicXor2DMSArrayIU:
			result = "IMAGEATOMICXOR2DMSARRAYIU";
			break;

		case ImageAccess::eImageAtomicXor1DUU:
			result = "IMAGEATOMICXOR1DUU";
			break;

		case ImageAccess::eImageAtomicXor2DUU:
			result = "IMAGEATOMICXOR2DUU";
			break;

		case ImageAccess::eImageAtomicXor3DUU:
			result = "IMAGEATOMICXOR3DUU";
			break;

		case ImageAccess::eImageAtomicXor2DRectUU:
			result = "IMAGEATOMICXOR2DRECTUU";
			break;

		case ImageAccess::eImageAtomicXorCubeUU:
			result = "IMAGEATOMICXORCUBEUU";
			break;

		case ImageAccess::eImageAtomicXorBufferUU:
			result = "IMAGEATOMICXORBUFFERUU";
			break;

		case ImageAccess::eImageAtomicXor1DArrayUU:
			result = "IMAGEATOMICXOR1DARRAYUU";
			break;

		case ImageAccess::eImageAtomicXor2DArrayUU:
			result = "IMAGEATOMICXOR2DARRAYUU";
			break;

		case ImageAccess::eImageAtomicXorCubeArrayUU:
			result = "IMAGEATOMICXORCUBEARRAYUU";
			break;

		case ImageAccess::eImageAtomicXor2DMSUU:
			result = "IMAGEATOMICXOR2DMSUU";
			break;

		case ImageAccess::eImageAtomicXor2DMSArrayUU:
			result = "IMAGEATOMICXOR2DMSARRAYUU";
			break;

		case ImageAccess::eImageAtomicXor1DFI:
			result = "IMAGEATOMICXOR1DFI";
			break;

		case ImageAccess::eImageAtomicXor2DFI:
			result = "IMAGEATOMICXOR2DFI";
			break;

		case ImageAccess::eImageAtomicXor3DFI:
			result = "IMAGEATOMICXOR3DFI";
			break;

		case ImageAccess::eImageAtomicXor2DRectFI:
			result = "IMAGEATOMICXOR2DRECTFI";
			break;

		case ImageAccess::eImageAtomicXorCubeFI:
			result = "IMAGEATOMICXORCUBEFI";
			break;

		case ImageAccess::eImageAtomicXorBufferFI:
			result = "IMAGEATOMICXORBUFFERFI";
			break;

		case ImageAccess::eImageAtomicXor1DArrayFI:
			result = "IMAGEATOMICXOR1DARRAYFI";
			break;

		case ImageAccess::eImageAtomicXor2DArrayFI:
			result = "IMAGEATOMICXOR2DARRAYFI";
			break;

		case ImageAccess::eImageAtomicXorCubeArrayFI:
			result = "IMAGEATOMICXORCUBEARRAYFI";
			break;

		case ImageAccess::eImageAtomicXor2DMSFI:
			result = "IMAGEATOMICXOR2DMSFI";
			break;

		case ImageAccess::eImageAtomicXor2DMSArrayFI:
			result = "IMAGEATOMICXOR2DMSARRAYFI";
			break;

		case ImageAccess::eImageAtomicXor1DII:
			result = "IMAGEATOMICXOR1DII";
			break;

		case ImageAccess::eImageAtomicXor2DII:
			result = "IMAGEATOMICXOR2DII";
			break;

		case ImageAccess::eImageAtomicXor3DII:
			result = "IMAGEATOMICXOR3DII";
			break;

		case ImageAccess::eImageAtomicXor2DRectII:
			result = "IMAGEATOMICXOR2DRECTII";
			break;

		case ImageAccess::eImageAtomicXorCubeII:
			result = "IMAGEATOMICXORCUBEII";
			break;

		case ImageAccess::eImageAtomicXorBufferII:
			result = "IMAGEATOMICXORBUFFERII";
			break;

		case ImageAccess::eImageAtomicXor1DArrayII:
			result = "IMAGEATOMICXOR1DARRAYII";
			break;

		case ImageAccess::eImageAtomicXor2DArrayII:
			result = "IMAGEATOMICXOR2DARRAYII";
			break;

		case ImageAccess::eImageAtomicXorCubeArrayII:
			result = "IMAGEATOMICXORCUBEARRAYII";
			break;

		case ImageAccess::eImageAtomicXor2DMSII:
			result = "IMAGEATOMICXOR2DMSII";
			break;

		case ImageAccess::eImageAtomicXor2DMSArrayII:
			result = "IMAGEATOMICXOR2DMSARRAYII";
			break;

		case ImageAccess::eImageAtomicXor1DUI:
			result = "IMAGEATOMICXOR1DUI";
			break;

		case ImageAccess::eImageAtomicXor2DUI:
			result = "IMAGEATOMICXOR2DUI";
			break;

		case ImageAccess::eImageAtomicXor3DUI:
			result = "IMAGEATOMICXOR3DUI";
			break;

		case ImageAccess::eImageAtomicXor2DRectUI:
			result = "IMAGEATOMICXOR2DRECTUI";
			break;

		case ImageAccess::eImageAtomicXorCubeUI:
			result = "IMAGEATOMICXORCUBEUI";
			break;

		case ImageAccess::eImageAtomicXorBufferUI:
			result = "IMAGEATOMICXORBUFFERUI";
			break;

		case ImageAccess::eImageAtomicXor1DArrayUI:
			result = "IMAGEATOMICXOR1DARRAYUI";
			break;

		case ImageAccess::eImageAtomicXor2DArrayUI:
			result = "IMAGEATOMICXOR2DARRAYUI";
			break;

		case ImageAccess::eImageAtomicXorCubeArrayUI:
			result = "IMAGEATOMICXORCUBEARRAYUI";
			break;

		case ImageAccess::eImageAtomicXor2DMSUI:
			result = "IMAGEATOMICXOR2DMSUI";
			break;

		case ImageAccess::eImageAtomicXor2DMSArrayUI:
			result = "IMAGEATOMICXOR2DMSARRAYUI";
			break;

		case ImageAccess::eImageAtomicExchange1DFU:
			result = "IMAGEATOMICEXCHANGE1DFU";
			break;

		case ImageAccess::eImageAtomicExchange2DFU:
			result = "IMAGEATOMICEXCHANGE2DFU";
			break;

		case ImageAccess::eImageAtomicExchange3DFU:
			result = "IMAGEATOMICEXCHANGE3DFU";
			break;

		case ImageAccess::eImageAtomicExchange2DRectFU:
			result = "IMAGEATOMICEXCHANGE2DRECTFU";
			break;

		case ImageAccess::eImageAtomicExchangeCubeFU:
			result = "IMAGEATOMICEXCHANGECUBEFU";
			break;

		case ImageAccess::eImageAtomicExchangeBufferFU:
			result = "IMAGEATOMICEXCHANGEBUFFERFU";
			break;

		case ImageAccess::eImageAtomicExchange1DArrayFU:
			result = "IMAGEATOMICEXCHANGE1DARRAYFU";
			break;

		case ImageAccess::eImageAtomicExchange2DArrayFU:
			result = "IMAGEATOMICEXCHANGE2DARRAYFU";
			break;

		case ImageAccess::eImageAtomicExchangeCubeArrayFU:
			result = "IMAGEATOMICEXCHANGECUBEARRAYFU";
			break;

		case ImageAccess::eImageAtomicExchange2DMSFU:
			result = "IMAGEATOMICEXCHANGE2DMSFU";
			break;

		case ImageAccess::eImageAtomicExchange2DMSArrayFU:
			result = "IMAGEATOMICEXCHANGE2DMSARRAYFU";
			break;

		case ImageAccess::eImageAtomicExchange1DIU:
			result = "IMAGEATOMICEXCHANGE1DIU";
			break;

		case ImageAccess::eImageAtomicExchange2DIU:
			result = "IMAGEATOMICEXCHANGE2DIU";
			break;

		case ImageAccess::eImageAtomicExchange3DIU:
			result = "IMAGEATOMICEXCHANGE3DIU";
			break;

		case ImageAccess::eImageAtomicExchange2DRectIU:
			result = "IMAGEATOMICEXCHANGE2DRECTIU";
			break;

		case ImageAccess::eImageAtomicExchangeCubeIU:
			result = "IMAGEATOMICEXCHANGECUBEIU";
			break;

		case ImageAccess::eImageAtomicExchangeBufferIU:
			result = "IMAGEATOMICEXCHANGEBUFFERIU";
			break;

		case ImageAccess::eImageAtomicExchange1DArrayIU:
			result = "IMAGEATOMICEXCHANGE1DARRAYIU";
			break;

		case ImageAccess::eImageAtomicExchange2DArrayIU:
			result = "IMAGEATOMICEXCHANGE2DARRAYIU";
			break;

		case ImageAccess::eImageAtomicExchangeCubeArrayIU:
			result = "IMAGEATOMICEXCHANGECUBEARRAYIU";
			break;

		case ImageAccess::eImageAtomicExchange2DMSIU:
			result = "IMAGEATOMICEXCHANGE2DMSIU";
			break;

		case ImageAccess::eImageAtomicExchange2DMSArrayIU:
			result = "IMAGEATOMICEXCHANGE2DMSARRAYIU";
			break;

		case ImageAccess::eImageAtomicExchange1DUU:
			result = "IMAGEATOMICEXCHANGE1DUU";
			break;

		case ImageAccess::eImageAtomicExchange2DUU:
			result = "IMAGEATOMICEXCHANGE2DUU";
			break;

		case ImageAccess::eImageAtomicExchange3DUU:
			result = "IMAGEATOMICEXCHANGE3DUU";
			break;

		case ImageAccess::eImageAtomicExchange2DRectUU:
			result = "IMAGEATOMICEXCHANGE2DRECTUU";
			break;

		case ImageAccess::eImageAtomicExchangeCubeUU:
			result = "IMAGEATOMICEXCHANGECUBEUU";
			break;

		case ImageAccess::eImageAtomicExchangeBufferUU:
			result = "IMAGEATOMICEXCHANGEBUFFERUU";
			break;

		case ImageAccess::eImageAtomicExchange1DArrayUU:
			result = "IMAGEATOMICEXCHANGE1DARRAYUU";
			break;

		case ImageAccess::eImageAtomicExchange2DArrayUU:
			result = "IMAGEATOMICEXCHANGE2DARRAYUU";
			break;

		case ImageAccess::eImageAtomicExchangeCubeArrayUU:
			result = "IMAGEATOMICEXCHANGECUBEARRAYUU";
			break;

		case ImageAccess::eImageAtomicExchange2DMSUU:
			result = "IMAGEATOMICEXCHANGE2DMSUU";
			break;

		case ImageAccess::eImageAtomicExchange2DMSArrayUU:
			result = "IMAGEATOMICEXCHANGE2DMSARRAYUU";
			break;

		case ImageAccess::eImageAtomicExchange1DFI:
			result = "IMAGEATOMICEXCHANGE1DFI";
			break;

		case ImageAccess::eImageAtomicExchange2DFI:
			result = "IMAGEATOMICEXCHANGE2DFI";
			break;

		case ImageAccess::eImageAtomicExchange3DFI:
			result = "IMAGEATOMICEXCHANGE3DFI";
			break;

		case ImageAccess::eImageAtomicExchange2DRectFI:
			result = "IMAGEATOMICEXCHANGE2DRECTFI";
			break;

		case ImageAccess::eImageAtomicExchangeCubeFI:
			result = "IMAGEATOMICEXCHANGECUBEFI";
			break;

		case ImageAccess::eImageAtomicExchangeBufferFI:
			result = "IMAGEATOMICEXCHANGEBUFFERFI";
			break;

		case ImageAccess::eImageAtomicExchange1DArrayFI:
			result = "IMAGEATOMICEXCHANGE1DARRAYFI";
			break;

		case ImageAccess::eImageAtomicExchange2DArrayFI:
			result = "IMAGEATOMICEXCHANGE2DARRAYFI";
			break;

		case ImageAccess::eImageAtomicExchangeCubeArrayFI:
			result = "IMAGEATOMICEXCHANGECUBEARRAYFI";
			break;

		case ImageAccess::eImageAtomicExchange2DMSFI:
			result = "IMAGEATOMICEXCHANGE2DMSFI";
			break;

		case ImageAccess::eImageAtomicExchange2DMSArrayFI:
			result = "IMAGEATOMICEXCHANGE2DMSARRAYFI";
			break;

		case ImageAccess::eImageAtomicExchange1DII:
			result = "IMAGEATOMICEXCHANGE1DII";
			break;

		case ImageAccess::eImageAtomicExchange2DII:
			result = "IMAGEATOMICEXCHANGE2DII";
			break;

		case ImageAccess::eImageAtomicExchange3DII:
			result = "IMAGEATOMICEXCHANGE3DII";
			break;

		case ImageAccess::eImageAtomicExchange2DRectII:
			result = "IMAGEATOMICEXCHANGE2DRECTII";
			break;

		case ImageAccess::eImageAtomicExchangeCubeII:
			result = "IMAGEATOMICEXCHANGECUBEII";
			break;

		case ImageAccess::eImageAtomicExchangeBufferII:
			result = "IMAGEATOMICEXCHANGEBUFFERII";
			break;

		case ImageAccess::eImageAtomicExchange1DArrayII:
			result = "IMAGEATOMICEXCHANGE1DARRAYII";
			break;

		case ImageAccess::eImageAtomicExchange2DArrayII:
			result = "IMAGEATOMICEXCHANGE2DARRAYII";
			break;

		case ImageAccess::eImageAtomicExchangeCubeArrayII:
			result = "IMAGEATOMICEXCHANGECUBEARRAYII";
			break;

		case ImageAccess::eImageAtomicExchange2DMSII:
			result = "IMAGEATOMICEXCHANGE2DMSII";
			break;

		case ImageAccess::eImageAtomicExchange2DMSArrayII:
			result = "IMAGEATOMICEXCHANGE2DMSARRAYII";
			break;

		case ImageAccess::eImageAtomicExchange1DUI:
			result = "IMAGEATOMICEXCHANGE1DUI";
			break;

		case ImageAccess::eImageAtomicExchange2DUI:
			result = "IMAGEATOMICEXCHANGE2DUI";
			break;

		case ImageAccess::eImageAtomicExchange3DUI:
			result = "IMAGEATOMICEXCHANGE3DUI";
			break;

		case ImageAccess::eImageAtomicExchange2DRectUI:
			result = "IMAGEATOMICEXCHANGE2DRECTUI";
			break;

		case ImageAccess::eImageAtomicExchangeCubeUI:
			result = "IMAGEATOMICEXCHANGECUBEUI";
			break;

		case ImageAccess::eImageAtomicExchangeBufferUI:
			result = "IMAGEATOMICEXCHANGEBUFFERUI";
			break;

		case ImageAccess::eImageAtomicExchange1DArrayUI:
			result = "IMAGEATOMICEXCHANGE1DARRAYUI";
			break;

		case ImageAccess::eImageAtomicExchange2DArrayUI:
			result = "IMAGEATOMICEXCHANGE2DARRAYUI";
			break;

		case ImageAccess::eImageAtomicExchangeCubeArrayUI:
			result = "IMAGEATOMICEXCHANGECUBEARRAYUI";
			break;

		case ImageAccess::eImageAtomicExchange2DMSUI:
			result = "IMAGEATOMICEXCHANGE2DMSUI";
			break;

		case ImageAccess::eImageAtomicExchange2DMSArrayUI:
			result = "IMAGEATOMICEXCHANGE2DMSARRAYUI";
			break;

		case ImageAccess::eImageAtomicCompSwap1DFU:
			result = "IMAGEATOMICCOMPSWAP1DFU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DFU:
			result = "IMAGEATOMICCOMPSWAP2DFU";
			break;

		case ImageAccess::eImageAtomicCompSwap3DFU:
			result = "IMAGEATOMICCOMPSWAP3DFU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DRectFU:
			result = "IMAGEATOMICCOMPSWAP2DRECTFU";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeFU:
			result = "IMAGEATOMICCOMPSWAPCUBEFU";
			break;

		case ImageAccess::eImageAtomicCompSwapBufferFU:
			result = "IMAGEATOMICCOMPSWAPBUFFERFU";
			break;

		case ImageAccess::eImageAtomicCompSwap1DArrayFU:
			result = "IMAGEATOMICCOMPSWAP1DARRAYFU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DArrayFU:
			result = "IMAGEATOMICCOMPSWAP2DARRAYFU";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeArrayFU:
			result = "IMAGEATOMICCOMPSWAPCUBEARRAYFU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSFU:
			result = "IMAGEATOMICCOMPSWAP2DMSFU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSArrayFU:
			result = "IMAGEATOMICCOMPSWAP2DMSARRAYFU";
			break;

		case ImageAccess::eImageAtomicCompSwap1DIU:
			result = "IMAGEATOMICCOMPSWAP1DIU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DIU:
			result = "IMAGEATOMICCOMPSWAP2DIU";
			break;

		case ImageAccess::eImageAtomicCompSwap3DIU:
			result = "IMAGEATOMICCOMPSWAP3DIU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DRectIU:
			result = "IMAGEATOMICCOMPSWAP2DRECTIU";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeIU:
			result = "IMAGEATOMICCOMPSWAPCUBEIU";
			break;

		case ImageAccess::eImageAtomicCompSwapBufferIU:
			result = "IMAGEATOMICCOMPSWAPBUFFERIU";
			break;

		case ImageAccess::eImageAtomicCompSwap1DArrayIU:
			result = "IMAGEATOMICCOMPSWAP1DARRAYIU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DArrayIU:
			result = "IMAGEATOMICCOMPSWAP2DARRAYIU";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeArrayIU:
			result = "IMAGEATOMICCOMPSWAPCUBEARRAYIU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSIU:
			result = "IMAGEATOMICCOMPSWAP2DMSIU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSArrayIU:
			result = "IMAGEATOMICCOMPSWAP2DMSARRAYIU";
			break;

		case ImageAccess::eImageAtomicCompSwap1DUU:
			result = "IMAGEATOMICCOMPSWAP1DUU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DUU:
			result = "IMAGEATOMICCOMPSWAP2DUU";
			break;

		case ImageAccess::eImageAtomicCompSwap3DUU:
			result = "IMAGEATOMICCOMPSWAP3DUU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DRectUU:
			result = "IMAGEATOMICCOMPSWAP2DRECTUU";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeUU:
			result = "IMAGEATOMICCOMPSWAPCUBEUU";
			break;

		case ImageAccess::eImageAtomicCompSwapBufferUU:
			result = "IMAGEATOMICCOMPSWAPBUFFERUU";
			break;

		case ImageAccess::eImageAtomicCompSwap1DArrayUU:
			result = "IMAGEATOMICCOMPSWAP1DARRAYUU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DArrayUU:
			result = "IMAGEATOMICCOMPSWAP2DARRAYUU";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeArrayUU:
			result = "IMAGEATOMICCOMPSWAPCUBEARRAYUU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSUU:
			result = "IMAGEATOMICCOMPSWAP2DMSUU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSArrayUU:
			result = "IMAGEATOMICCOMPSWAP2DMSARRAYUU";
			break;

		case ImageAccess::eImageAtomicCompSwap1DFI:
			result = "IMAGEATOMICCOMPSWAP1DFI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DFI:
			result = "IMAGEATOMICCOMPSWAP2DFI";
			break;

		case ImageAccess::eImageAtomicCompSwap3DFI:
			result = "IMAGEATOMICCOMPSWAP3DFI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DRectFI:
			result = "IMAGEATOMICCOMPSWAP2DRECTFI";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeFI:
			result = "IMAGEATOMICCOMPSWAPCUBEFI";
			break;

		case ImageAccess::eImageAtomicCompSwapBufferFI:
			result = "IMAGEATOMICCOMPSWAPBUFFERFI";
			break;

		case ImageAccess::eImageAtomicCompSwap1DArrayFI:
			result = "IMAGEATOMICCOMPSWAP1DARRAYFI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DArrayFI:
			result = "IMAGEATOMICCOMPSWAP2DARRAYFI";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeArrayFI:
			result = "IMAGEATOMICCOMPSWAPCUBEARRAYFI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSFI:
			result = "IMAGEATOMICCOMPSWAP2DMSFI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSArrayFI:
			result = "IMAGEATOMICCOMPSWAP2DMSARRAYFI";
			break;

		case ImageAccess::eImageAtomicCompSwap1DII:
			result = "IMAGEATOMICCOMPSWAP1DII";
			break;

		case ImageAccess::eImageAtomicCompSwap2DII:
			result = "IMAGEATOMICCOMPSWAP2DII";
			break;

		case ImageAccess::eImageAtomicCompSwap3DII:
			result = "IMAGEATOMICCOMPSWAP3DII";
			break;

		case ImageAccess::eImageAtomicCompSwap2DRectII:
			result = "IMAGEATOMICCOMPSWAP2DRECTII";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeII:
			result = "IMAGEATOMICCOMPSWAPCUBEII";
			break;

		case ImageAccess::eImageAtomicCompSwapBufferII:
			result = "IMAGEATOMICCOMPSWAPBUFFERII";
			break;

		case ImageAccess::eImageAtomicCompSwap1DArrayII:
			result = "IMAGEATOMICCOMPSWAP1DARRAYII";
			break;

		case ImageAccess::eImageAtomicCompSwap2DArrayII:
			result = "IMAGEATOMICCOMPSWAP2DARRAYII";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeArrayII:
			result = "IMAGEATOMICCOMPSWAPCUBEARRAYII";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSII:
			result = "IMAGEATOMICCOMPSWAP2DMSII";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSArrayII:
			result = "IMAGEATOMICCOMPSWAP2DMSARRAYII";
			break;

		case ImageAccess::eImageAtomicCompSwap1DUI:
			result = "IMAGEATOMICCOMPSWAP1DUI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DUI:
			result = "IMAGEATOMICCOMPSWAP2DUI";
			break;

		case ImageAccess::eImageAtomicCompSwap3DUI:
			result = "IMAGEATOMICCOMPSWAP3DUI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DRectUI:
			result = "IMAGEATOMICCOMPSWAP2DRECTUI";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeUI:
			result = "IMAGEATOMICCOMPSWAPCUBEUI";
			break;

		case ImageAccess::eImageAtomicCompSwapBufferUI:
			result = "IMAGEATOMICCOMPSWAPBUFFERUI";
			break;

		case ImageAccess::eImageAtomicCompSwap1DArrayUI:
			result = "IMAGEATOMICCOMPSWAP1DARRAYUI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DArrayUI:
			result = "IMAGEATOMICCOMPSWAP2DARRAYUI";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeArrayUI:
			result = "IMAGEATOMICCOMPSWAPCUBEARRAYUI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSUI:
			result = "IMAGEATOMICCOMPSWAP2DMSUI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSArrayUI:
			result = "IMAGEATOMICCOMPSWAP2DMSARRAYUI";
			break;

		default:
			throw std::runtime_error{ "Unsupported ImageAccess type." };
		}

		return result;
	}
}

#endif
