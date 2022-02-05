/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#ifndef ___AST_ExprGetStorageImageAccessName_H___
#define ___AST_ExprGetStorageImageAccessName_H___
#pragma once

#include "EnumStorageImageAccess.hpp"

#include <string>

namespace ast::expr
{
	inline std::string getName( StorageImageAccess value )
	{
		std::string result;

		switch ( value )
		{
		case StorageImageAccess::eUndefined:
			result = "UNDEFINED";
			break;

		case StorageImageAccess::eCount:
			result = "COUNT";
			break;

		case StorageImageAccess::eInvalid:
			result = "INVALID";
			break;

	// Image Query Functions
		case StorageImageAccess::eImageSize1DF:
			result = "IMAGESIZE1DF";
			break;

		case StorageImageAccess::eImageSize2DF:
			result = "IMAGESIZE2DF";
			break;

		case StorageImageAccess::eImageSize3DF:
			result = "IMAGESIZE3DF";
			break;

		case StorageImageAccess::eImageSizeCubeF:
			result = "IMAGESIZECUBEF";
			break;

		case StorageImageAccess::eImageSizeCubeArrayF:
			result = "IMAGESIZECUBEARRAYF";
			break;

		case StorageImageAccess::eImageSize2DRectF:
			result = "IMAGESIZE2DRECTF";
			break;

		case StorageImageAccess::eImageSize1DArrayF:
			result = "IMAGESIZE1DARRAYF";
			break;

		case StorageImageAccess::eImageSize2DArrayF:
			result = "IMAGESIZE2DARRAYF";
			break;

		case StorageImageAccess::eImageSizeBufferF:
			result = "IMAGESIZEBUFFERF";
			break;

		case StorageImageAccess::eImageSize2DMSF:
			result = "IMAGESIZE2DMSF";
			break;

		case StorageImageAccess::eImageSize2DMSArrayF:
			result = "IMAGESIZE2DMSARRAYF";
			break;

		case StorageImageAccess::eImageSize1DI:
			result = "IMAGESIZE1DI";
			break;

		case StorageImageAccess::eImageSize2DI:
			result = "IMAGESIZE2DI";
			break;

		case StorageImageAccess::eImageSize3DI:
			result = "IMAGESIZE3DI";
			break;

		case StorageImageAccess::eImageSizeCubeI:
			result = "IMAGESIZECUBEI";
			break;

		case StorageImageAccess::eImageSizeCubeArrayI:
			result = "IMAGESIZECUBEARRAYI";
			break;

		case StorageImageAccess::eImageSize2DRectI:
			result = "IMAGESIZE2DRECTI";
			break;

		case StorageImageAccess::eImageSize1DArrayI:
			result = "IMAGESIZE1DARRAYI";
			break;

		case StorageImageAccess::eImageSize2DArrayI:
			result = "IMAGESIZE2DARRAYI";
			break;

		case StorageImageAccess::eImageSizeBufferI:
			result = "IMAGESIZEBUFFERI";
			break;

		case StorageImageAccess::eImageSize2DMSI:
			result = "IMAGESIZE2DMSI";
			break;

		case StorageImageAccess::eImageSize2DMSArrayI:
			result = "IMAGESIZE2DMSARRAYI";
			break;

		case StorageImageAccess::eImageSize1DU:
			result = "IMAGESIZE1DU";
			break;

		case StorageImageAccess::eImageSize2DU:
			result = "IMAGESIZE2DU";
			break;

		case StorageImageAccess::eImageSize3DU:
			result = "IMAGESIZE3DU";
			break;

		case StorageImageAccess::eImageSizeCubeU:
			result = "IMAGESIZECUBEU";
			break;

		case StorageImageAccess::eImageSizeCubeArrayU:
			result = "IMAGESIZECUBEARRAYU";
			break;

		case StorageImageAccess::eImageSize2DRectU:
			result = "IMAGESIZE2DRECTU";
			break;

		case StorageImageAccess::eImageSize1DArrayU:
			result = "IMAGESIZE1DARRAYU";
			break;

		case StorageImageAccess::eImageSize2DArrayU:
			result = "IMAGESIZE2DARRAYU";
			break;

		case StorageImageAccess::eImageSizeBufferU:
			result = "IMAGESIZEBUFFERU";
			break;

		case StorageImageAccess::eImageSize2DMSU:
			result = "IMAGESIZE2DMSU";
			break;

		case StorageImageAccess::eImageSize2DMSArrayU:
			result = "IMAGESIZE2DMSARRAYU";
			break;

		case StorageImageAccess::eImageSamples2DMSF:
			result = "IMAGESAMPLES2DMSF";
			break;

		case StorageImageAccess::eImageSamples2DMSArrayF:
			result = "IMAGESAMPLES2DMSARRAYF";
			break;

		case StorageImageAccess::eImageSamples2DMSI:
			result = "IMAGESAMPLES2DMSI";
			break;

		case StorageImageAccess::eImageSamples2DMSArrayI:
			result = "IMAGESAMPLES2DMSARRAYI";
			break;

		case StorageImageAccess::eImageSamples2DMSU:
			result = "IMAGESAMPLES2DMSU";
			break;

		case StorageImageAccess::eImageSamples2DMSArrayU:
			result = "IMAGESAMPLES2DMSARRAYU";
			break;


	// Image texel load
		case StorageImageAccess::eImageLoad1DF:
			result = "IMAGELOAD1DF";
			break;

		case StorageImageAccess::eImageLoad2DF:
			result = "IMAGELOAD2DF";
			break;

		case StorageImageAccess::eImageLoad3DF:
			result = "IMAGELOAD3DF";
			break;

		case StorageImageAccess::eImageLoad2DRectF:
			result = "IMAGELOAD2DRECTF";
			break;

		case StorageImageAccess::eImageLoadCubeF:
			result = "IMAGELOADCUBEF";
			break;

		case StorageImageAccess::eImageLoadBufferF:
			result = "IMAGELOADBUFFERF";
			break;

		case StorageImageAccess::eImageLoad1DArrayF:
			result = "IMAGELOAD1DARRAYF";
			break;

		case StorageImageAccess::eImageLoad2DArrayF:
			result = "IMAGELOAD2DARRAYF";
			break;

		case StorageImageAccess::eImageLoadCubeArrayF:
			result = "IMAGELOADCUBEARRAYF";
			break;

		case StorageImageAccess::eImageLoad2DMSF:
			result = "IMAGELOAD2DMSF";
			break;

		case StorageImageAccess::eImageLoad2DMSArrayF:
			result = "IMAGELOAD2DMSARRAYF";
			break;

		case StorageImageAccess::eImageLoad1DI:
			result = "IMAGELOAD1DI";
			break;

		case StorageImageAccess::eImageLoad2DI:
			result = "IMAGELOAD2DI";
			break;

		case StorageImageAccess::eImageLoad3DI:
			result = "IMAGELOAD3DI";
			break;

		case StorageImageAccess::eImageLoad2DRectI:
			result = "IMAGELOAD2DRECTI";
			break;

		case StorageImageAccess::eImageLoadCubeI:
			result = "IMAGELOADCUBEI";
			break;

		case StorageImageAccess::eImageLoadBufferI:
			result = "IMAGELOADBUFFERI";
			break;

		case StorageImageAccess::eImageLoad1DArrayI:
			result = "IMAGELOAD1DARRAYI";
			break;

		case StorageImageAccess::eImageLoad2DArrayI:
			result = "IMAGELOAD2DARRAYI";
			break;

		case StorageImageAccess::eImageLoadCubeArrayI:
			result = "IMAGELOADCUBEARRAYI";
			break;

		case StorageImageAccess::eImageLoad2DMSI:
			result = "IMAGELOAD2DMSI";
			break;

		case StorageImageAccess::eImageLoad2DMSArrayI:
			result = "IMAGELOAD2DMSARRAYI";
			break;

		case StorageImageAccess::eImageLoad1DU:
			result = "IMAGELOAD1DU";
			break;

		case StorageImageAccess::eImageLoad2DU:
			result = "IMAGELOAD2DU";
			break;

		case StorageImageAccess::eImageLoad3DU:
			result = "IMAGELOAD3DU";
			break;

		case StorageImageAccess::eImageLoad2DRectU:
			result = "IMAGELOAD2DRECTU";
			break;

		case StorageImageAccess::eImageLoadCubeU:
			result = "IMAGELOADCUBEU";
			break;

		case StorageImageAccess::eImageLoadBufferU:
			result = "IMAGELOADBUFFERU";
			break;

		case StorageImageAccess::eImageLoad1DArrayU:
			result = "IMAGELOAD1DARRAYU";
			break;

		case StorageImageAccess::eImageLoad2DArrayU:
			result = "IMAGELOAD2DARRAYU";
			break;

		case StorageImageAccess::eImageLoadCubeArrayU:
			result = "IMAGELOADCUBEARRAYU";
			break;

		case StorageImageAccess::eImageLoad2DMSU:
			result = "IMAGELOAD2DMSU";
			break;

		case StorageImageAccess::eImageLoad2DMSArrayU:
			result = "IMAGELOAD2DMSARRAYU";
			break;


	// Image texel store
		case StorageImageAccess::eImageStore1DF:
			result = "IMAGESTORE1DF";
			break;

		case StorageImageAccess::eImageStore2DF:
			result = "IMAGESTORE2DF";
			break;

		case StorageImageAccess::eImageStore3DF:
			result = "IMAGESTORE3DF";
			break;

		case StorageImageAccess::eImageStore2DRectF:
			result = "IMAGESTORE2DRECTF";
			break;

		case StorageImageAccess::eImageStoreCubeF:
			result = "IMAGESTORECUBEF";
			break;

		case StorageImageAccess::eImageStoreBufferF:
			result = "IMAGESTOREBUFFERF";
			break;

		case StorageImageAccess::eImageStore1DArrayF:
			result = "IMAGESTORE1DARRAYF";
			break;

		case StorageImageAccess::eImageStore2DArrayF:
			result = "IMAGESTORE2DARRAYF";
			break;

		case StorageImageAccess::eImageStoreCubeArrayF:
			result = "IMAGESTORECUBEARRAYF";
			break;

		case StorageImageAccess::eImageStore2DMSF:
			result = "IMAGESTORE2DMSF";
			break;

		case StorageImageAccess::eImageStore2DMSArrayF:
			result = "IMAGESTORE2DMSARRAYF";
			break;

		case StorageImageAccess::eImageStore1DI:
			result = "IMAGESTORE1DI";
			break;

		case StorageImageAccess::eImageStore2DI:
			result = "IMAGESTORE2DI";
			break;

		case StorageImageAccess::eImageStore3DI:
			result = "IMAGESTORE3DI";
			break;

		case StorageImageAccess::eImageStore2DRectI:
			result = "IMAGESTORE2DRECTI";
			break;

		case StorageImageAccess::eImageStoreCubeI:
			result = "IMAGESTORECUBEI";
			break;

		case StorageImageAccess::eImageStoreBufferI:
			result = "IMAGESTOREBUFFERI";
			break;

		case StorageImageAccess::eImageStore1DArrayI:
			result = "IMAGESTORE1DARRAYI";
			break;

		case StorageImageAccess::eImageStore2DArrayI:
			result = "IMAGESTORE2DARRAYI";
			break;

		case StorageImageAccess::eImageStoreCubeArrayI:
			result = "IMAGESTORECUBEARRAYI";
			break;

		case StorageImageAccess::eImageStore2DMSI:
			result = "IMAGESTORE2DMSI";
			break;

		case StorageImageAccess::eImageStore2DMSArrayI:
			result = "IMAGESTORE2DMSARRAYI";
			break;

		case StorageImageAccess::eImageStore1DU:
			result = "IMAGESTORE1DU";
			break;

		case StorageImageAccess::eImageStore2DU:
			result = "IMAGESTORE2DU";
			break;

		case StorageImageAccess::eImageStore3DU:
			result = "IMAGESTORE3DU";
			break;

		case StorageImageAccess::eImageStore2DRectU:
			result = "IMAGESTORE2DRECTU";
			break;

		case StorageImageAccess::eImageStoreCubeU:
			result = "IMAGESTORECUBEU";
			break;

		case StorageImageAccess::eImageStoreBufferU:
			result = "IMAGESTOREBUFFERU";
			break;

		case StorageImageAccess::eImageStore1DArrayU:
			result = "IMAGESTORE1DARRAYU";
			break;

		case StorageImageAccess::eImageStore2DArrayU:
			result = "IMAGESTORE2DARRAYU";
			break;

		case StorageImageAccess::eImageStoreCubeArrayU:
			result = "IMAGESTORECUBEARRAYU";
			break;

		case StorageImageAccess::eImageStore2DMSU:
			result = "IMAGESTORE2DMSU";
			break;

		case StorageImageAccess::eImageStore2DMSArrayU:
			result = "IMAGESTORE2DMSARRAYU";
			break;


	// Image atomics
		case StorageImageAccess::eImageAtomicAdd1DU:
			result = "IMAGEATOMICADD1DU";
			break;

		case StorageImageAccess::eImageAtomicAdd2DU:
			result = "IMAGEATOMICADD2DU";
			break;

		case StorageImageAccess::eImageAtomicAdd3DU:
			result = "IMAGEATOMICADD3DU";
			break;

		case StorageImageAccess::eImageAtomicAdd2DRectU:
			result = "IMAGEATOMICADD2DRECTU";
			break;

		case StorageImageAccess::eImageAtomicAddCubeU:
			result = "IMAGEATOMICADDCUBEU";
			break;

		case StorageImageAccess::eImageAtomicAddBufferU:
			result = "IMAGEATOMICADDBUFFERU";
			break;

		case StorageImageAccess::eImageAtomicAdd1DArrayU:
			result = "IMAGEATOMICADD1DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicAdd2DArrayU:
			result = "IMAGEATOMICADD2DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicAddCubeArrayU:
			result = "IMAGEATOMICADDCUBEARRAYU";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSU:
			result = "IMAGEATOMICADD2DMSU";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSArrayU:
			result = "IMAGEATOMICADD2DMSARRAYU";
			break;

		case StorageImageAccess::eImageAtomicAdd1DI:
			result = "IMAGEATOMICADD1DI";
			break;

		case StorageImageAccess::eImageAtomicAdd2DI:
			result = "IMAGEATOMICADD2DI";
			break;

		case StorageImageAccess::eImageAtomicAdd3DI:
			result = "IMAGEATOMICADD3DI";
			break;

		case StorageImageAccess::eImageAtomicAdd2DRectI:
			result = "IMAGEATOMICADD2DRECTI";
			break;

		case StorageImageAccess::eImageAtomicAddCubeI:
			result = "IMAGEATOMICADDCUBEI";
			break;

		case StorageImageAccess::eImageAtomicAddBufferI:
			result = "IMAGEATOMICADDBUFFERI";
			break;

		case StorageImageAccess::eImageAtomicAdd1DArrayI:
			result = "IMAGEATOMICADD1DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicAdd2DArrayI:
			result = "IMAGEATOMICADD2DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicAddCubeArrayI:
			result = "IMAGEATOMICADDCUBEARRAYI";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSI:
			result = "IMAGEATOMICADD2DMSI";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSArrayI:
			result = "IMAGEATOMICADD2DMSARRAYI";
			break;

		case StorageImageAccess::eImageAtomicAdd1DF:
			result = "IMAGEATOMICADD1DF";
			break;

		case StorageImageAccess::eImageAtomicAdd2DF:
			result = "IMAGEATOMICADD2DF";
			break;

		case StorageImageAccess::eImageAtomicAdd3DF:
			result = "IMAGEATOMICADD3DF";
			break;

		case StorageImageAccess::eImageAtomicAdd2DRectF:
			result = "IMAGEATOMICADD2DRECTF";
			break;

		case StorageImageAccess::eImageAtomicAddCubeF:
			result = "IMAGEATOMICADDCUBEF";
			break;

		case StorageImageAccess::eImageAtomicAddBufferF:
			result = "IMAGEATOMICADDBUFFERF";
			break;

		case StorageImageAccess::eImageAtomicAdd1DArrayF:
			result = "IMAGEATOMICADD1DARRAYF";
			break;

		case StorageImageAccess::eImageAtomicAdd2DArrayF:
			result = "IMAGEATOMICADD2DARRAYF";
			break;

		case StorageImageAccess::eImageAtomicAddCubeArrayF:
			result = "IMAGEATOMICADDCUBEARRAYF";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSF:
			result = "IMAGEATOMICADD2DMSF";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSArrayF:
			result = "IMAGEATOMICADD2DMSARRAYF";
			break;

		case StorageImageAccess::eImageAtomicMin1DU:
			result = "IMAGEATOMICMIN1DU";
			break;

		case StorageImageAccess::eImageAtomicMin2DU:
			result = "IMAGEATOMICMIN2DU";
			break;

		case StorageImageAccess::eImageAtomicMin3DU:
			result = "IMAGEATOMICMIN3DU";
			break;

		case StorageImageAccess::eImageAtomicMin2DRectU:
			result = "IMAGEATOMICMIN2DRECTU";
			break;

		case StorageImageAccess::eImageAtomicMinCubeU:
			result = "IMAGEATOMICMINCUBEU";
			break;

		case StorageImageAccess::eImageAtomicMinBufferU:
			result = "IMAGEATOMICMINBUFFERU";
			break;

		case StorageImageAccess::eImageAtomicMin1DArrayU:
			result = "IMAGEATOMICMIN1DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicMin2DArrayU:
			result = "IMAGEATOMICMIN2DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicMinCubeArrayU:
			result = "IMAGEATOMICMINCUBEARRAYU";
			break;

		case StorageImageAccess::eImageAtomicMin2DMSU:
			result = "IMAGEATOMICMIN2DMSU";
			break;

		case StorageImageAccess::eImageAtomicMin2DMSArrayU:
			result = "IMAGEATOMICMIN2DMSARRAYU";
			break;

		case StorageImageAccess::eImageAtomicMin1DI:
			result = "IMAGEATOMICMIN1DI";
			break;

		case StorageImageAccess::eImageAtomicMin2DI:
			result = "IMAGEATOMICMIN2DI";
			break;

		case StorageImageAccess::eImageAtomicMin3DI:
			result = "IMAGEATOMICMIN3DI";
			break;

		case StorageImageAccess::eImageAtomicMin2DRectI:
			result = "IMAGEATOMICMIN2DRECTI";
			break;

		case StorageImageAccess::eImageAtomicMinCubeI:
			result = "IMAGEATOMICMINCUBEI";
			break;

		case StorageImageAccess::eImageAtomicMinBufferI:
			result = "IMAGEATOMICMINBUFFERI";
			break;

		case StorageImageAccess::eImageAtomicMin1DArrayI:
			result = "IMAGEATOMICMIN1DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicMin2DArrayI:
			result = "IMAGEATOMICMIN2DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicMinCubeArrayI:
			result = "IMAGEATOMICMINCUBEARRAYI";
			break;

		case StorageImageAccess::eImageAtomicMin2DMSI:
			result = "IMAGEATOMICMIN2DMSI";
			break;

		case StorageImageAccess::eImageAtomicMin2DMSArrayI:
			result = "IMAGEATOMICMIN2DMSARRAYI";
			break;

		case StorageImageAccess::eImageAtomicMax1DU:
			result = "IMAGEATOMICMAX1DU";
			break;

		case StorageImageAccess::eImageAtomicMax2DU:
			result = "IMAGEATOMICMAX2DU";
			break;

		case StorageImageAccess::eImageAtomicMax3DU:
			result = "IMAGEATOMICMAX3DU";
			break;

		case StorageImageAccess::eImageAtomicMax2DRectU:
			result = "IMAGEATOMICMAX2DRECTU";
			break;

		case StorageImageAccess::eImageAtomicMaxCubeU:
			result = "IMAGEATOMICMAXCUBEU";
			break;

		case StorageImageAccess::eImageAtomicMaxBufferU:
			result = "IMAGEATOMICMAXBUFFERU";
			break;

		case StorageImageAccess::eImageAtomicMax1DArrayU:
			result = "IMAGEATOMICMAX1DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicMax2DArrayU:
			result = "IMAGEATOMICMAX2DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicMaxCubeArrayU:
			result = "IMAGEATOMICMAXCUBEARRAYU";
			break;

		case StorageImageAccess::eImageAtomicMax2DMSU:
			result = "IMAGEATOMICMAX2DMSU";
			break;

		case StorageImageAccess::eImageAtomicMax2DMSArrayU:
			result = "IMAGEATOMICMAX2DMSARRAYU";
			break;

		case StorageImageAccess::eImageAtomicMax1DI:
			result = "IMAGEATOMICMAX1DI";
			break;

		case StorageImageAccess::eImageAtomicMax2DI:
			result = "IMAGEATOMICMAX2DI";
			break;

		case StorageImageAccess::eImageAtomicMax3DI:
			result = "IMAGEATOMICMAX3DI";
			break;

		case StorageImageAccess::eImageAtomicMax2DRectI:
			result = "IMAGEATOMICMAX2DRECTI";
			break;

		case StorageImageAccess::eImageAtomicMaxCubeI:
			result = "IMAGEATOMICMAXCUBEI";
			break;

		case StorageImageAccess::eImageAtomicMaxBufferI:
			result = "IMAGEATOMICMAXBUFFERI";
			break;

		case StorageImageAccess::eImageAtomicMax1DArrayI:
			result = "IMAGEATOMICMAX1DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicMax2DArrayI:
			result = "IMAGEATOMICMAX2DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicMaxCubeArrayI:
			result = "IMAGEATOMICMAXCUBEARRAYI";
			break;

		case StorageImageAccess::eImageAtomicMax2DMSI:
			result = "IMAGEATOMICMAX2DMSI";
			break;

		case StorageImageAccess::eImageAtomicMax2DMSArrayI:
			result = "IMAGEATOMICMAX2DMSARRAYI";
			break;

		case StorageImageAccess::eImageAtomicAnd1DU:
			result = "IMAGEATOMICAND1DU";
			break;

		case StorageImageAccess::eImageAtomicAnd2DU:
			result = "IMAGEATOMICAND2DU";
			break;

		case StorageImageAccess::eImageAtomicAnd3DU:
			result = "IMAGEATOMICAND3DU";
			break;

		case StorageImageAccess::eImageAtomicAnd2DRectU:
			result = "IMAGEATOMICAND2DRECTU";
			break;

		case StorageImageAccess::eImageAtomicAndCubeU:
			result = "IMAGEATOMICANDCUBEU";
			break;

		case StorageImageAccess::eImageAtomicAndBufferU:
			result = "IMAGEATOMICANDBUFFERU";
			break;

		case StorageImageAccess::eImageAtomicAnd1DArrayU:
			result = "IMAGEATOMICAND1DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicAnd2DArrayU:
			result = "IMAGEATOMICAND2DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicAndCubeArrayU:
			result = "IMAGEATOMICANDCUBEARRAYU";
			break;

		case StorageImageAccess::eImageAtomicAnd2DMSU:
			result = "IMAGEATOMICAND2DMSU";
			break;

		case StorageImageAccess::eImageAtomicAnd2DMSArrayU:
			result = "IMAGEATOMICAND2DMSARRAYU";
			break;

		case StorageImageAccess::eImageAtomicAnd1DI:
			result = "IMAGEATOMICAND1DI";
			break;

		case StorageImageAccess::eImageAtomicAnd2DI:
			result = "IMAGEATOMICAND2DI";
			break;

		case StorageImageAccess::eImageAtomicAnd3DI:
			result = "IMAGEATOMICAND3DI";
			break;

		case StorageImageAccess::eImageAtomicAnd2DRectI:
			result = "IMAGEATOMICAND2DRECTI";
			break;

		case StorageImageAccess::eImageAtomicAndCubeI:
			result = "IMAGEATOMICANDCUBEI";
			break;

		case StorageImageAccess::eImageAtomicAndBufferI:
			result = "IMAGEATOMICANDBUFFERI";
			break;

		case StorageImageAccess::eImageAtomicAnd1DArrayI:
			result = "IMAGEATOMICAND1DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicAnd2DArrayI:
			result = "IMAGEATOMICAND2DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicAndCubeArrayI:
			result = "IMAGEATOMICANDCUBEARRAYI";
			break;

		case StorageImageAccess::eImageAtomicAnd2DMSI:
			result = "IMAGEATOMICAND2DMSI";
			break;

		case StorageImageAccess::eImageAtomicAnd2DMSArrayI:
			result = "IMAGEATOMICAND2DMSARRAYI";
			break;

		case StorageImageAccess::eImageAtomicOr1DU:
			result = "IMAGEATOMICOR1DU";
			break;

		case StorageImageAccess::eImageAtomicOr2DU:
			result = "IMAGEATOMICOR2DU";
			break;

		case StorageImageAccess::eImageAtomicOr3DU:
			result = "IMAGEATOMICOR3DU";
			break;

		case StorageImageAccess::eImageAtomicOr2DRectU:
			result = "IMAGEATOMICOR2DRECTU";
			break;

		case StorageImageAccess::eImageAtomicOrCubeU:
			result = "IMAGEATOMICORCUBEU";
			break;

		case StorageImageAccess::eImageAtomicOrBufferU:
			result = "IMAGEATOMICORBUFFERU";
			break;

		case StorageImageAccess::eImageAtomicOr1DArrayU:
			result = "IMAGEATOMICOR1DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicOr2DArrayU:
			result = "IMAGEATOMICOR2DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicOrCubeArrayU:
			result = "IMAGEATOMICORCUBEARRAYU";
			break;

		case StorageImageAccess::eImageAtomicOr2DMSU:
			result = "IMAGEATOMICOR2DMSU";
			break;

		case StorageImageAccess::eImageAtomicOr2DMSArrayU:
			result = "IMAGEATOMICOR2DMSARRAYU";
			break;

		case StorageImageAccess::eImageAtomicOr1DI:
			result = "IMAGEATOMICOR1DI";
			break;

		case StorageImageAccess::eImageAtomicOr2DI:
			result = "IMAGEATOMICOR2DI";
			break;

		case StorageImageAccess::eImageAtomicOr3DI:
			result = "IMAGEATOMICOR3DI";
			break;

		case StorageImageAccess::eImageAtomicOr2DRectI:
			result = "IMAGEATOMICOR2DRECTI";
			break;

		case StorageImageAccess::eImageAtomicOrCubeI:
			result = "IMAGEATOMICORCUBEI";
			break;

		case StorageImageAccess::eImageAtomicOrBufferI:
			result = "IMAGEATOMICORBUFFERI";
			break;

		case StorageImageAccess::eImageAtomicOr1DArrayI:
			result = "IMAGEATOMICOR1DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicOr2DArrayI:
			result = "IMAGEATOMICOR2DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicOrCubeArrayI:
			result = "IMAGEATOMICORCUBEARRAYI";
			break;

		case StorageImageAccess::eImageAtomicOr2DMSI:
			result = "IMAGEATOMICOR2DMSI";
			break;

		case StorageImageAccess::eImageAtomicOr2DMSArrayI:
			result = "IMAGEATOMICOR2DMSARRAYI";
			break;

		case StorageImageAccess::eImageAtomicXor1DU:
			result = "IMAGEATOMICXOR1DU";
			break;

		case StorageImageAccess::eImageAtomicXor2DU:
			result = "IMAGEATOMICXOR2DU";
			break;

		case StorageImageAccess::eImageAtomicXor3DU:
			result = "IMAGEATOMICXOR3DU";
			break;

		case StorageImageAccess::eImageAtomicXor2DRectU:
			result = "IMAGEATOMICXOR2DRECTU";
			break;

		case StorageImageAccess::eImageAtomicXorCubeU:
			result = "IMAGEATOMICXORCUBEU";
			break;

		case StorageImageAccess::eImageAtomicXorBufferU:
			result = "IMAGEATOMICXORBUFFERU";
			break;

		case StorageImageAccess::eImageAtomicXor1DArrayU:
			result = "IMAGEATOMICXOR1DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicXor2DArrayU:
			result = "IMAGEATOMICXOR2DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicXorCubeArrayU:
			result = "IMAGEATOMICXORCUBEARRAYU";
			break;

		case StorageImageAccess::eImageAtomicXor2DMSU:
			result = "IMAGEATOMICXOR2DMSU";
			break;

		case StorageImageAccess::eImageAtomicXor2DMSArrayU:
			result = "IMAGEATOMICXOR2DMSARRAYU";
			break;

		case StorageImageAccess::eImageAtomicXor1DI:
			result = "IMAGEATOMICXOR1DI";
			break;

		case StorageImageAccess::eImageAtomicXor2DI:
			result = "IMAGEATOMICXOR2DI";
			break;

		case StorageImageAccess::eImageAtomicXor3DI:
			result = "IMAGEATOMICXOR3DI";
			break;

		case StorageImageAccess::eImageAtomicXor2DRectI:
			result = "IMAGEATOMICXOR2DRECTI";
			break;

		case StorageImageAccess::eImageAtomicXorCubeI:
			result = "IMAGEATOMICXORCUBEI";
			break;

		case StorageImageAccess::eImageAtomicXorBufferI:
			result = "IMAGEATOMICXORBUFFERI";
			break;

		case StorageImageAccess::eImageAtomicXor1DArrayI:
			result = "IMAGEATOMICXOR1DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicXor2DArrayI:
			result = "IMAGEATOMICXOR2DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicXorCubeArrayI:
			result = "IMAGEATOMICXORCUBEARRAYI";
			break;

		case StorageImageAccess::eImageAtomicXor2DMSI:
			result = "IMAGEATOMICXOR2DMSI";
			break;

		case StorageImageAccess::eImageAtomicXor2DMSArrayI:
			result = "IMAGEATOMICXOR2DMSARRAYI";
			break;

		case StorageImageAccess::eImageAtomicExchange1DU:
			result = "IMAGEATOMICEXCHANGE1DU";
			break;

		case StorageImageAccess::eImageAtomicExchange2DU:
			result = "IMAGEATOMICEXCHANGE2DU";
			break;

		case StorageImageAccess::eImageAtomicExchange3DU:
			result = "IMAGEATOMICEXCHANGE3DU";
			break;

		case StorageImageAccess::eImageAtomicExchange2DRectU:
			result = "IMAGEATOMICEXCHANGE2DRECTU";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeU:
			result = "IMAGEATOMICEXCHANGECUBEU";
			break;

		case StorageImageAccess::eImageAtomicExchangeBufferU:
			result = "IMAGEATOMICEXCHANGEBUFFERU";
			break;

		case StorageImageAccess::eImageAtomicExchange1DArrayU:
			result = "IMAGEATOMICEXCHANGE1DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicExchange2DArrayU:
			result = "IMAGEATOMICEXCHANGE2DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeArrayU:
			result = "IMAGEATOMICEXCHANGECUBEARRAYU";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSU:
			result = "IMAGEATOMICEXCHANGE2DMSU";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSArrayU:
			result = "IMAGEATOMICEXCHANGE2DMSARRAYU";
			break;

		case StorageImageAccess::eImageAtomicExchange1DI:
			result = "IMAGEATOMICEXCHANGE1DI";
			break;

		case StorageImageAccess::eImageAtomicExchange2DI:
			result = "IMAGEATOMICEXCHANGE2DI";
			break;

		case StorageImageAccess::eImageAtomicExchange3DI:
			result = "IMAGEATOMICEXCHANGE3DI";
			break;

		case StorageImageAccess::eImageAtomicExchange2DRectI:
			result = "IMAGEATOMICEXCHANGE2DRECTI";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeI:
			result = "IMAGEATOMICEXCHANGECUBEI";
			break;

		case StorageImageAccess::eImageAtomicExchangeBufferI:
			result = "IMAGEATOMICEXCHANGEBUFFERI";
			break;

		case StorageImageAccess::eImageAtomicExchange1DArrayI:
			result = "IMAGEATOMICEXCHANGE1DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicExchange2DArrayI:
			result = "IMAGEATOMICEXCHANGE2DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeArrayI:
			result = "IMAGEATOMICEXCHANGECUBEARRAYI";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSI:
			result = "IMAGEATOMICEXCHANGE2DMSI";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSArrayI:
			result = "IMAGEATOMICEXCHANGE2DMSARRAYI";
			break;

		case StorageImageAccess::eImageAtomicExchange1DF:
			result = "IMAGEATOMICEXCHANGE1DF";
			break;

		case StorageImageAccess::eImageAtomicExchange2DF:
			result = "IMAGEATOMICEXCHANGE2DF";
			break;

		case StorageImageAccess::eImageAtomicExchange3DF:
			result = "IMAGEATOMICEXCHANGE3DF";
			break;

		case StorageImageAccess::eImageAtomicExchange2DRectF:
			result = "IMAGEATOMICEXCHANGE2DRECTF";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeF:
			result = "IMAGEATOMICEXCHANGECUBEF";
			break;

		case StorageImageAccess::eImageAtomicExchangeBufferF:
			result = "IMAGEATOMICEXCHANGEBUFFERF";
			break;

		case StorageImageAccess::eImageAtomicExchange1DArrayF:
			result = "IMAGEATOMICEXCHANGE1DARRAYF";
			break;

		case StorageImageAccess::eImageAtomicExchange2DArrayF:
			result = "IMAGEATOMICEXCHANGE2DARRAYF";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeArrayF:
			result = "IMAGEATOMICEXCHANGECUBEARRAYF";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSF:
			result = "IMAGEATOMICEXCHANGE2DMSF";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSArrayF:
			result = "IMAGEATOMICEXCHANGE2DMSARRAYF";
			break;

		case StorageImageAccess::eImageAtomicCompSwap1DU:
			result = "IMAGEATOMICCOMPSWAP1DU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DU:
			result = "IMAGEATOMICCOMPSWAP2DU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap3DU:
			result = "IMAGEATOMICCOMPSWAP3DU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DRectU:
			result = "IMAGEATOMICCOMPSWAP2DRECTU";
			break;

		case StorageImageAccess::eImageAtomicCompSwapCubeU:
			result = "IMAGEATOMICCOMPSWAPCUBEU";
			break;

		case StorageImageAccess::eImageAtomicCompSwapBufferU:
			result = "IMAGEATOMICCOMPSWAPBUFFERU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap1DArrayU:
			result = "IMAGEATOMICCOMPSWAP1DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DArrayU:
			result = "IMAGEATOMICCOMPSWAP2DARRAYU";
			break;

		case StorageImageAccess::eImageAtomicCompSwapCubeArrayU:
			result = "IMAGEATOMICCOMPSWAPCUBEARRAYU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DMSU:
			result = "IMAGEATOMICCOMPSWAP2DMSU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DMSArrayU:
			result = "IMAGEATOMICCOMPSWAP2DMSARRAYU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap1DI:
			result = "IMAGEATOMICCOMPSWAP1DI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DI:
			result = "IMAGEATOMICCOMPSWAP2DI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap3DI:
			result = "IMAGEATOMICCOMPSWAP3DI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DRectI:
			result = "IMAGEATOMICCOMPSWAP2DRECTI";
			break;

		case StorageImageAccess::eImageAtomicCompSwapCubeI:
			result = "IMAGEATOMICCOMPSWAPCUBEI";
			break;

		case StorageImageAccess::eImageAtomicCompSwapBufferI:
			result = "IMAGEATOMICCOMPSWAPBUFFERI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap1DArrayI:
			result = "IMAGEATOMICCOMPSWAP1DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DArrayI:
			result = "IMAGEATOMICCOMPSWAP2DARRAYI";
			break;

		case StorageImageAccess::eImageAtomicCompSwapCubeArrayI:
			result = "IMAGEATOMICCOMPSWAPCUBEARRAYI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DMSI:
			result = "IMAGEATOMICCOMPSWAP2DMSI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DMSArrayI:
			result = "IMAGEATOMICCOMPSWAP2DMSARRAYI";
			break;

		default:
			throw std::runtime_error{ "Unsupported StorageImageAccess type." };
		}

		return result;
	}
}

#endif
