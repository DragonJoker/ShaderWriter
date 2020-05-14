/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprGetImageAccessName_H___
#define ___AST_ExprGetImageAccessName_H___
#pragma once

#include "EnumImageAccess.hpp"

#include <stdexcept>
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

		case ImageAccess::eImageSamples2DMSF:
			result = "IMAGESAMPLES2DMSF";
			break;

		case ImageAccess::eImageSamples2DMSArrayF:
			result = "IMAGESAMPLES2DMSARRAYF";
			break;

		case ImageAccess::eImageSamples2DMSI:
			result = "IMAGESAMPLES2DMSI";
			break;

		case ImageAccess::eImageSamples2DMSArrayI:
			result = "IMAGESAMPLES2DMSARRAYI";
			break;

		case ImageAccess::eImageSamples2DMSU:
			result = "IMAGESAMPLES2DMSU";
			break;

		case ImageAccess::eImageSamples2DMSArrayU:
			result = "IMAGESAMPLES2DMSARRAYU";
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

		case ImageAccess::eImageStore1DF:
			result = "IMAGESTORE1DF";
			break;

		case ImageAccess::eImageStore2DF:
			result = "IMAGESTORE2DF";
			break;

		case ImageAccess::eImageStore3DF:
			result = "IMAGESTORE3DF";
			break;

		case ImageAccess::eImageStore2DRectF:
			result = "IMAGESTORE2DRECTF";
			break;

		case ImageAccess::eImageStoreCubeF:
			result = "IMAGESTORECUBEF";
			break;

		case ImageAccess::eImageStoreBufferF:
			result = "IMAGESTOREBUFFERF";
			break;

		case ImageAccess::eImageStore1DArrayF:
			result = "IMAGESTORE1DARRAYF";
			break;

		case ImageAccess::eImageStore2DArrayF:
			result = "IMAGESTORE2DARRAYF";
			break;

		case ImageAccess::eImageStoreCubeArrayF:
			result = "IMAGESTORECUBEARRAYF";
			break;

		case ImageAccess::eImageStore2DMSF:
			result = "IMAGESTORE2DMSF";
			break;

		case ImageAccess::eImageStore2DMSArrayF:
			result = "IMAGESTORE2DMSARRAYF";
			break;

		case ImageAccess::eImageStore1DI:
			result = "IMAGESTORE1DI";
			break;

		case ImageAccess::eImageStore2DI:
			result = "IMAGESTORE2DI";
			break;

		case ImageAccess::eImageStore3DI:
			result = "IMAGESTORE3DI";
			break;

		case ImageAccess::eImageStore2DRectI:
			result = "IMAGESTORE2DRECTI";
			break;

		case ImageAccess::eImageStoreCubeI:
			result = "IMAGESTORECUBEI";
			break;

		case ImageAccess::eImageStoreBufferI:
			result = "IMAGESTOREBUFFERI";
			break;

		case ImageAccess::eImageStore1DArrayI:
			result = "IMAGESTORE1DARRAYI";
			break;

		case ImageAccess::eImageStore2DArrayI:
			result = "IMAGESTORE2DARRAYI";
			break;

		case ImageAccess::eImageStoreCubeArrayI:
			result = "IMAGESTORECUBEARRAYI";
			break;

		case ImageAccess::eImageStore2DMSI:
			result = "IMAGESTORE2DMSI";
			break;

		case ImageAccess::eImageStore2DMSArrayI:
			result = "IMAGESTORE2DMSARRAYI";
			break;

		case ImageAccess::eImageStore1DU:
			result = "IMAGESTORE1DU";
			break;

		case ImageAccess::eImageStore2DU:
			result = "IMAGESTORE2DU";
			break;

		case ImageAccess::eImageStore3DU:
			result = "IMAGESTORE3DU";
			break;

		case ImageAccess::eImageStore2DRectU:
			result = "IMAGESTORE2DRECTU";
			break;

		case ImageAccess::eImageStoreCubeU:
			result = "IMAGESTORECUBEU";
			break;

		case ImageAccess::eImageStoreBufferU:
			result = "IMAGESTOREBUFFERU";
			break;

		case ImageAccess::eImageStore1DArrayU:
			result = "IMAGESTORE1DARRAYU";
			break;

		case ImageAccess::eImageStore2DArrayU:
			result = "IMAGESTORE2DARRAYU";
			break;

		case ImageAccess::eImageStoreCubeArrayU:
			result = "IMAGESTORECUBEARRAYU";
			break;

		case ImageAccess::eImageStore2DMSU:
			result = "IMAGESTORE2DMSU";
			break;

		case ImageAccess::eImageStore2DMSArrayU:
			result = "IMAGESTORE2DMSARRAYU";
			break;

		case ImageAccess::eImageAtomicAdd1DU:
			result = "IMAGEATOMICADD1DU";
			break;

		case ImageAccess::eImageAtomicAdd2DU:
			result = "IMAGEATOMICADD2DU";
			break;

		case ImageAccess::eImageAtomicAdd3DU:
			result = "IMAGEATOMICADD3DU";
			break;

		case ImageAccess::eImageAtomicAdd2DRectU:
			result = "IMAGEATOMICADD2DRECTU";
			break;

		case ImageAccess::eImageAtomicAddCubeU:
			result = "IMAGEATOMICADDCUBEU";
			break;

		case ImageAccess::eImageAtomicAddBufferU:
			result = "IMAGEATOMICADDBUFFERU";
			break;

		case ImageAccess::eImageAtomicAdd1DArrayU:
			result = "IMAGEATOMICADD1DARRAYU";
			break;

		case ImageAccess::eImageAtomicAdd2DArrayU:
			result = "IMAGEATOMICADD2DARRAYU";
			break;

		case ImageAccess::eImageAtomicAddCubeArrayU:
			result = "IMAGEATOMICADDCUBEARRAYU";
			break;

		case ImageAccess::eImageAtomicAdd2DMSU:
			result = "IMAGEATOMICADD2DMSU";
			break;

		case ImageAccess::eImageAtomicAdd2DMSArrayU:
			result = "IMAGEATOMICADD2DMSARRAYU";
			break;

		case ImageAccess::eImageAtomicAdd1DI:
			result = "IMAGEATOMICADD1DI";
			break;

		case ImageAccess::eImageAtomicAdd2DI:
			result = "IMAGEATOMICADD2DI";
			break;

		case ImageAccess::eImageAtomicAdd3DI:
			result = "IMAGEATOMICADD3DI";
			break;

		case ImageAccess::eImageAtomicAdd2DRectI:
			result = "IMAGEATOMICADD2DRECTI";
			break;

		case ImageAccess::eImageAtomicAddCubeI:
			result = "IMAGEATOMICADDCUBEI";
			break;

		case ImageAccess::eImageAtomicAddBufferI:
			result = "IMAGEATOMICADDBUFFERI";
			break;

		case ImageAccess::eImageAtomicAdd1DArrayI:
			result = "IMAGEATOMICADD1DARRAYI";
			break;

		case ImageAccess::eImageAtomicAdd2DArrayI:
			result = "IMAGEATOMICADD2DARRAYI";
			break;

		case ImageAccess::eImageAtomicAddCubeArrayI:
			result = "IMAGEATOMICADDCUBEARRAYI";
			break;

		case ImageAccess::eImageAtomicAdd2DMSI:
			result = "IMAGEATOMICADD2DMSI";
			break;

		case ImageAccess::eImageAtomicAdd2DMSArrayI:
			result = "IMAGEATOMICADD2DMSARRAYI";
			break;

		case ImageAccess::eImageAtomicMin1DU:
			result = "IMAGEATOMICMIN1DU";
			break;

		case ImageAccess::eImageAtomicMin2DU:
			result = "IMAGEATOMICMIN2DU";
			break;

		case ImageAccess::eImageAtomicMin3DU:
			result = "IMAGEATOMICMIN3DU";
			break;

		case ImageAccess::eImageAtomicMin2DRectU:
			result = "IMAGEATOMICMIN2DRECTU";
			break;

		case ImageAccess::eImageAtomicMinCubeU:
			result = "IMAGEATOMICMINCUBEU";
			break;

		case ImageAccess::eImageAtomicMinBufferU:
			result = "IMAGEATOMICMINBUFFERU";
			break;

		case ImageAccess::eImageAtomicMin1DArrayU:
			result = "IMAGEATOMICMIN1DARRAYU";
			break;

		case ImageAccess::eImageAtomicMin2DArrayU:
			result = "IMAGEATOMICMIN2DARRAYU";
			break;

		case ImageAccess::eImageAtomicMinCubeArrayU:
			result = "IMAGEATOMICMINCUBEARRAYU";
			break;

		case ImageAccess::eImageAtomicMin2DMSU:
			result = "IMAGEATOMICMIN2DMSU";
			break;

		case ImageAccess::eImageAtomicMin2DMSArrayU:
			result = "IMAGEATOMICMIN2DMSARRAYU";
			break;

		case ImageAccess::eImageAtomicMin1DI:
			result = "IMAGEATOMICMIN1DI";
			break;

		case ImageAccess::eImageAtomicMin2DI:
			result = "IMAGEATOMICMIN2DI";
			break;

		case ImageAccess::eImageAtomicMin3DI:
			result = "IMAGEATOMICMIN3DI";
			break;

		case ImageAccess::eImageAtomicMin2DRectI:
			result = "IMAGEATOMICMIN2DRECTI";
			break;

		case ImageAccess::eImageAtomicMinCubeI:
			result = "IMAGEATOMICMINCUBEI";
			break;

		case ImageAccess::eImageAtomicMinBufferI:
			result = "IMAGEATOMICMINBUFFERI";
			break;

		case ImageAccess::eImageAtomicMin1DArrayI:
			result = "IMAGEATOMICMIN1DARRAYI";
			break;

		case ImageAccess::eImageAtomicMin2DArrayI:
			result = "IMAGEATOMICMIN2DARRAYI";
			break;

		case ImageAccess::eImageAtomicMinCubeArrayI:
			result = "IMAGEATOMICMINCUBEARRAYI";
			break;

		case ImageAccess::eImageAtomicMin2DMSI:
			result = "IMAGEATOMICMIN2DMSI";
			break;

		case ImageAccess::eImageAtomicMin2DMSArrayI:
			result = "IMAGEATOMICMIN2DMSARRAYI";
			break;

		case ImageAccess::eImageAtomicMax1DU:
			result = "IMAGEATOMICMAX1DU";
			break;

		case ImageAccess::eImageAtomicMax2DU:
			result = "IMAGEATOMICMAX2DU";
			break;

		case ImageAccess::eImageAtomicMax3DU:
			result = "IMAGEATOMICMAX3DU";
			break;

		case ImageAccess::eImageAtomicMax2DRectU:
			result = "IMAGEATOMICMAX2DRECTU";
			break;

		case ImageAccess::eImageAtomicMaxCubeU:
			result = "IMAGEATOMICMAXCUBEU";
			break;

		case ImageAccess::eImageAtomicMaxBufferU:
			result = "IMAGEATOMICMAXBUFFERU";
			break;

		case ImageAccess::eImageAtomicMax1DArrayU:
			result = "IMAGEATOMICMAX1DARRAYU";
			break;

		case ImageAccess::eImageAtomicMax2DArrayU:
			result = "IMAGEATOMICMAX2DARRAYU";
			break;

		case ImageAccess::eImageAtomicMaxCubeArrayU:
			result = "IMAGEATOMICMAXCUBEARRAYU";
			break;

		case ImageAccess::eImageAtomicMax2DMSU:
			result = "IMAGEATOMICMAX2DMSU";
			break;

		case ImageAccess::eImageAtomicMax2DMSArrayU:
			result = "IMAGEATOMICMAX2DMSARRAYU";
			break;

		case ImageAccess::eImageAtomicMax1DI:
			result = "IMAGEATOMICMAX1DI";
			break;

		case ImageAccess::eImageAtomicMax2DI:
			result = "IMAGEATOMICMAX2DI";
			break;

		case ImageAccess::eImageAtomicMax3DI:
			result = "IMAGEATOMICMAX3DI";
			break;

		case ImageAccess::eImageAtomicMax2DRectI:
			result = "IMAGEATOMICMAX2DRECTI";
			break;

		case ImageAccess::eImageAtomicMaxCubeI:
			result = "IMAGEATOMICMAXCUBEI";
			break;

		case ImageAccess::eImageAtomicMaxBufferI:
			result = "IMAGEATOMICMAXBUFFERI";
			break;

		case ImageAccess::eImageAtomicMax1DArrayI:
			result = "IMAGEATOMICMAX1DARRAYI";
			break;

		case ImageAccess::eImageAtomicMax2DArrayI:
			result = "IMAGEATOMICMAX2DARRAYI";
			break;

		case ImageAccess::eImageAtomicMaxCubeArrayI:
			result = "IMAGEATOMICMAXCUBEARRAYI";
			break;

		case ImageAccess::eImageAtomicMax2DMSI:
			result = "IMAGEATOMICMAX2DMSI";
			break;

		case ImageAccess::eImageAtomicMax2DMSArrayI:
			result = "IMAGEATOMICMAX2DMSARRAYI";
			break;

		case ImageAccess::eImageAtomicAnd1DU:
			result = "IMAGEATOMICAND1DU";
			break;

		case ImageAccess::eImageAtomicAnd2DU:
			result = "IMAGEATOMICAND2DU";
			break;

		case ImageAccess::eImageAtomicAnd3DU:
			result = "IMAGEATOMICAND3DU";
			break;

		case ImageAccess::eImageAtomicAnd2DRectU:
			result = "IMAGEATOMICAND2DRECTU";
			break;

		case ImageAccess::eImageAtomicAndCubeU:
			result = "IMAGEATOMICANDCUBEU";
			break;

		case ImageAccess::eImageAtomicAndBufferU:
			result = "IMAGEATOMICANDBUFFERU";
			break;

		case ImageAccess::eImageAtomicAnd1DArrayU:
			result = "IMAGEATOMICAND1DARRAYU";
			break;

		case ImageAccess::eImageAtomicAnd2DArrayU:
			result = "IMAGEATOMICAND2DARRAYU";
			break;

		case ImageAccess::eImageAtomicAndCubeArrayU:
			result = "IMAGEATOMICANDCUBEARRAYU";
			break;

		case ImageAccess::eImageAtomicAnd2DMSU:
			result = "IMAGEATOMICAND2DMSU";
			break;

		case ImageAccess::eImageAtomicAnd2DMSArrayU:
			result = "IMAGEATOMICAND2DMSARRAYU";
			break;

		case ImageAccess::eImageAtomicAnd1DI:
			result = "IMAGEATOMICAND1DI";
			break;

		case ImageAccess::eImageAtomicAnd2DI:
			result = "IMAGEATOMICAND2DI";
			break;

		case ImageAccess::eImageAtomicAnd3DI:
			result = "IMAGEATOMICAND3DI";
			break;

		case ImageAccess::eImageAtomicAnd2DRectI:
			result = "IMAGEATOMICAND2DRECTI";
			break;

		case ImageAccess::eImageAtomicAndCubeI:
			result = "IMAGEATOMICANDCUBEI";
			break;

		case ImageAccess::eImageAtomicAndBufferI:
			result = "IMAGEATOMICANDBUFFERI";
			break;

		case ImageAccess::eImageAtomicAnd1DArrayI:
			result = "IMAGEATOMICAND1DARRAYI";
			break;

		case ImageAccess::eImageAtomicAnd2DArrayI:
			result = "IMAGEATOMICAND2DARRAYI";
			break;

		case ImageAccess::eImageAtomicAndCubeArrayI:
			result = "IMAGEATOMICANDCUBEARRAYI";
			break;

		case ImageAccess::eImageAtomicAnd2DMSI:
			result = "IMAGEATOMICAND2DMSI";
			break;

		case ImageAccess::eImageAtomicAnd2DMSArrayI:
			result = "IMAGEATOMICAND2DMSARRAYI";
			break;

		case ImageAccess::eImageAtomicOr1DU:
			result = "IMAGEATOMICOR1DU";
			break;

		case ImageAccess::eImageAtomicOr2DU:
			result = "IMAGEATOMICOR2DU";
			break;

		case ImageAccess::eImageAtomicOr3DU:
			result = "IMAGEATOMICOR3DU";
			break;

		case ImageAccess::eImageAtomicOr2DRectU:
			result = "IMAGEATOMICOR2DRECTU";
			break;

		case ImageAccess::eImageAtomicOrCubeU:
			result = "IMAGEATOMICORCUBEU";
			break;

		case ImageAccess::eImageAtomicOrBufferU:
			result = "IMAGEATOMICORBUFFERU";
			break;

		case ImageAccess::eImageAtomicOr1DArrayU:
			result = "IMAGEATOMICOR1DARRAYU";
			break;

		case ImageAccess::eImageAtomicOr2DArrayU:
			result = "IMAGEATOMICOR2DARRAYU";
			break;

		case ImageAccess::eImageAtomicOrCubeArrayU:
			result = "IMAGEATOMICORCUBEARRAYU";
			break;

		case ImageAccess::eImageAtomicOr2DMSU:
			result = "IMAGEATOMICOR2DMSU";
			break;

		case ImageAccess::eImageAtomicOr2DMSArrayU:
			result = "IMAGEATOMICOR2DMSARRAYU";
			break;

		case ImageAccess::eImageAtomicOr1DI:
			result = "IMAGEATOMICOR1DI";
			break;

		case ImageAccess::eImageAtomicOr2DI:
			result = "IMAGEATOMICOR2DI";
			break;

		case ImageAccess::eImageAtomicOr3DI:
			result = "IMAGEATOMICOR3DI";
			break;

		case ImageAccess::eImageAtomicOr2DRectI:
			result = "IMAGEATOMICOR2DRECTI";
			break;

		case ImageAccess::eImageAtomicOrCubeI:
			result = "IMAGEATOMICORCUBEI";
			break;

		case ImageAccess::eImageAtomicOrBufferI:
			result = "IMAGEATOMICORBUFFERI";
			break;

		case ImageAccess::eImageAtomicOr1DArrayI:
			result = "IMAGEATOMICOR1DARRAYI";
			break;

		case ImageAccess::eImageAtomicOr2DArrayI:
			result = "IMAGEATOMICOR2DARRAYI";
			break;

		case ImageAccess::eImageAtomicOrCubeArrayI:
			result = "IMAGEATOMICORCUBEARRAYI";
			break;

		case ImageAccess::eImageAtomicOr2DMSI:
			result = "IMAGEATOMICOR2DMSI";
			break;

		case ImageAccess::eImageAtomicOr2DMSArrayI:
			result = "IMAGEATOMICOR2DMSARRAYI";
			break;

		case ImageAccess::eImageAtomicXor1DU:
			result = "IMAGEATOMICXOR1DU";
			break;

		case ImageAccess::eImageAtomicXor2DU:
			result = "IMAGEATOMICXOR2DU";
			break;

		case ImageAccess::eImageAtomicXor3DU:
			result = "IMAGEATOMICXOR3DU";
			break;

		case ImageAccess::eImageAtomicXor2DRectU:
			result = "IMAGEATOMICXOR2DRECTU";
			break;

		case ImageAccess::eImageAtomicXorCubeU:
			result = "IMAGEATOMICXORCUBEU";
			break;

		case ImageAccess::eImageAtomicXorBufferU:
			result = "IMAGEATOMICXORBUFFERU";
			break;

		case ImageAccess::eImageAtomicXor1DArrayU:
			result = "IMAGEATOMICXOR1DARRAYU";
			break;

		case ImageAccess::eImageAtomicXor2DArrayU:
			result = "IMAGEATOMICXOR2DARRAYU";
			break;

		case ImageAccess::eImageAtomicXorCubeArrayU:
			result = "IMAGEATOMICXORCUBEARRAYU";
			break;

		case ImageAccess::eImageAtomicXor2DMSU:
			result = "IMAGEATOMICXOR2DMSU";
			break;

		case ImageAccess::eImageAtomicXor2DMSArrayU:
			result = "IMAGEATOMICXOR2DMSARRAYU";
			break;

		case ImageAccess::eImageAtomicXor1DI:
			result = "IMAGEATOMICXOR1DI";
			break;

		case ImageAccess::eImageAtomicXor2DI:
			result = "IMAGEATOMICXOR2DI";
			break;

		case ImageAccess::eImageAtomicXor3DI:
			result = "IMAGEATOMICXOR3DI";
			break;

		case ImageAccess::eImageAtomicXor2DRectI:
			result = "IMAGEATOMICXOR2DRECTI";
			break;

		case ImageAccess::eImageAtomicXorCubeI:
			result = "IMAGEATOMICXORCUBEI";
			break;

		case ImageAccess::eImageAtomicXorBufferI:
			result = "IMAGEATOMICXORBUFFERI";
			break;

		case ImageAccess::eImageAtomicXor1DArrayI:
			result = "IMAGEATOMICXOR1DARRAYI";
			break;

		case ImageAccess::eImageAtomicXor2DArrayI:
			result = "IMAGEATOMICXOR2DARRAYI";
			break;

		case ImageAccess::eImageAtomicXorCubeArrayI:
			result = "IMAGEATOMICXORCUBEARRAYI";
			break;

		case ImageAccess::eImageAtomicXor2DMSI:
			result = "IMAGEATOMICXOR2DMSI";
			break;

		case ImageAccess::eImageAtomicXor2DMSArrayI:
			result = "IMAGEATOMICXOR2DMSARRAYI";
			break;

		case ImageAccess::eImageAtomicExchange1DU:
			result = "IMAGEATOMICEXCHANGE1DU";
			break;

		case ImageAccess::eImageAtomicExchange2DU:
			result = "IMAGEATOMICEXCHANGE2DU";
			break;

		case ImageAccess::eImageAtomicExchange3DU:
			result = "IMAGEATOMICEXCHANGE3DU";
			break;

		case ImageAccess::eImageAtomicExchange2DRectU:
			result = "IMAGEATOMICEXCHANGE2DRECTU";
			break;

		case ImageAccess::eImageAtomicExchangeCubeU:
			result = "IMAGEATOMICEXCHANGECUBEU";
			break;

		case ImageAccess::eImageAtomicExchangeBufferU:
			result = "IMAGEATOMICEXCHANGEBUFFERU";
			break;

		case ImageAccess::eImageAtomicExchange1DArrayU:
			result = "IMAGEATOMICEXCHANGE1DARRAYU";
			break;

		case ImageAccess::eImageAtomicExchange2DArrayU:
			result = "IMAGEATOMICEXCHANGE2DARRAYU";
			break;

		case ImageAccess::eImageAtomicExchangeCubeArrayU:
			result = "IMAGEATOMICEXCHANGECUBEARRAYU";
			break;

		case ImageAccess::eImageAtomicExchange2DMSU:
			result = "IMAGEATOMICEXCHANGE2DMSU";
			break;

		case ImageAccess::eImageAtomicExchange2DMSArrayU:
			result = "IMAGEATOMICEXCHANGE2DMSARRAYU";
			break;

		case ImageAccess::eImageAtomicExchange1DI:
			result = "IMAGEATOMICEXCHANGE1DI";
			break;

		case ImageAccess::eImageAtomicExchange2DI:
			result = "IMAGEATOMICEXCHANGE2DI";
			break;

		case ImageAccess::eImageAtomicExchange3DI:
			result = "IMAGEATOMICEXCHANGE3DI";
			break;

		case ImageAccess::eImageAtomicExchange2DRectI:
			result = "IMAGEATOMICEXCHANGE2DRECTI";
			break;

		case ImageAccess::eImageAtomicExchangeCubeI:
			result = "IMAGEATOMICEXCHANGECUBEI";
			break;

		case ImageAccess::eImageAtomicExchangeBufferI:
			result = "IMAGEATOMICEXCHANGEBUFFERI";
			break;

		case ImageAccess::eImageAtomicExchange1DArrayI:
			result = "IMAGEATOMICEXCHANGE1DARRAYI";
			break;

		case ImageAccess::eImageAtomicExchange2DArrayI:
			result = "IMAGEATOMICEXCHANGE2DARRAYI";
			break;

		case ImageAccess::eImageAtomicExchangeCubeArrayI:
			result = "IMAGEATOMICEXCHANGECUBEARRAYI";
			break;

		case ImageAccess::eImageAtomicExchange2DMSI:
			result = "IMAGEATOMICEXCHANGE2DMSI";
			break;

		case ImageAccess::eImageAtomicExchange2DMSArrayI:
			result = "IMAGEATOMICEXCHANGE2DMSARRAYI";
			break;

		case ImageAccess::eImageAtomicCompSwap1DU:
			result = "IMAGEATOMICCOMPSWAP1DU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DU:
			result = "IMAGEATOMICCOMPSWAP2DU";
			break;

		case ImageAccess::eImageAtomicCompSwap3DU:
			result = "IMAGEATOMICCOMPSWAP3DU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DRectU:
			result = "IMAGEATOMICCOMPSWAP2DRECTU";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeU:
			result = "IMAGEATOMICCOMPSWAPCUBEU";
			break;

		case ImageAccess::eImageAtomicCompSwapBufferU:
			result = "IMAGEATOMICCOMPSWAPBUFFERU";
			break;

		case ImageAccess::eImageAtomicCompSwap1DArrayU:
			result = "IMAGEATOMICCOMPSWAP1DARRAYU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DArrayU:
			result = "IMAGEATOMICCOMPSWAP2DARRAYU";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeArrayU:
			result = "IMAGEATOMICCOMPSWAPCUBEARRAYU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSU:
			result = "IMAGEATOMICCOMPSWAP2DMSU";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSArrayU:
			result = "IMAGEATOMICCOMPSWAP2DMSARRAYU";
			break;

		case ImageAccess::eImageAtomicCompSwap1DI:
			result = "IMAGEATOMICCOMPSWAP1DI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DI:
			result = "IMAGEATOMICCOMPSWAP2DI";
			break;

		case ImageAccess::eImageAtomicCompSwap3DI:
			result = "IMAGEATOMICCOMPSWAP3DI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DRectI:
			result = "IMAGEATOMICCOMPSWAP2DRECTI";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeI:
			result = "IMAGEATOMICCOMPSWAPCUBEI";
			break;

		case ImageAccess::eImageAtomicCompSwapBufferI:
			result = "IMAGEATOMICCOMPSWAPBUFFERI";
			break;

		case ImageAccess::eImageAtomicCompSwap1DArrayI:
			result = "IMAGEATOMICCOMPSWAP1DARRAYI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DArrayI:
			result = "IMAGEATOMICCOMPSWAP2DARRAYI";
			break;

		case ImageAccess::eImageAtomicCompSwapCubeArrayI:
			result = "IMAGEATOMICCOMPSWAPCUBEARRAYI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSI:
			result = "IMAGEATOMICCOMPSWAP2DMSI";
			break;

		case ImageAccess::eImageAtomicCompSwap2DMSArrayI:
			result = "IMAGEATOMICCOMPSWAP2DMSARRAYI";
			break;

		default:
			throw std::runtime_error{ "Unsupported ImageAccess type." };
		}

		return result;
	}
}

#endif
