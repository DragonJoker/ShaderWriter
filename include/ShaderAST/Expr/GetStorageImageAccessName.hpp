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
#include "ShaderAST/Shader.hpp"

#include <string>

namespace ast::expr
{
	inline std::string getName( StorageImageAccess value )
	{
		std::string result;

		switch ( value )
		{
		case StorageImageAccess::eUndefined:
			result = "Undefined";
			break;

		case StorageImageAccess::eCount:
			result = "Count";
			break;

		case StorageImageAccess::eInvalid:
			result = "Invalid";
			break;

	// Image Query Functions
		case StorageImageAccess::eImageSize1DF:
			result = "ImageSize1DF";
			break;

		case StorageImageAccess::eImageSize2DF:
			result = "ImageSize2DF";
			break;

		case StorageImageAccess::eImageSize3DF:
			result = "ImageSize3DF";
			break;

		case StorageImageAccess::eImageSizeCubeF:
			result = "ImageSizeCubeF";
			break;

		case StorageImageAccess::eImageSizeCubeArrayF:
			result = "ImageSizeCubeArrayF";
			break;

		case StorageImageAccess::eImageSize1DArrayF:
			result = "ImageSize1DArrayF";
			break;

		case StorageImageAccess::eImageSize2DArrayF:
			result = "ImageSize2DArrayF";
			break;

		case StorageImageAccess::eImageSizeBufferF:
			result = "ImageSizeBufferF";
			break;

		case StorageImageAccess::eImageSize2DMSF:
			result = "ImageSize2DMSF";
			break;

		case StorageImageAccess::eImageSize2DMSArrayF:
			result = "ImageSize2DMSArrayF";
			break;

		case StorageImageAccess::eImageSize1DI:
			result = "ImageSize1DI";
			break;

		case StorageImageAccess::eImageSize2DI:
			result = "ImageSize2DI";
			break;

		case StorageImageAccess::eImageSize3DI:
			result = "ImageSize3DI";
			break;

		case StorageImageAccess::eImageSizeCubeI:
			result = "ImageSizeCubeI";
			break;

		case StorageImageAccess::eImageSizeCubeArrayI:
			result = "ImageSizeCubeArrayI";
			break;

		case StorageImageAccess::eImageSize1DArrayI:
			result = "ImageSize1DArrayI";
			break;

		case StorageImageAccess::eImageSize2DArrayI:
			result = "ImageSize2DArrayI";
			break;

		case StorageImageAccess::eImageSizeBufferI:
			result = "ImageSizeBufferI";
			break;

		case StorageImageAccess::eImageSize2DMSI:
			result = "ImageSize2DMSI";
			break;

		case StorageImageAccess::eImageSize2DMSArrayI:
			result = "ImageSize2DMSArrayI";
			break;

		case StorageImageAccess::eImageSize1DU:
			result = "ImageSize1DU";
			break;

		case StorageImageAccess::eImageSize2DU:
			result = "ImageSize2DU";
			break;

		case StorageImageAccess::eImageSize3DU:
			result = "ImageSize3DU";
			break;

		case StorageImageAccess::eImageSizeCubeU:
			result = "ImageSizeCubeU";
			break;

		case StorageImageAccess::eImageSizeCubeArrayU:
			result = "ImageSizeCubeArrayU";
			break;

		case StorageImageAccess::eImageSize1DArrayU:
			result = "ImageSize1DArrayU";
			break;

		case StorageImageAccess::eImageSize2DArrayU:
			result = "ImageSize2DArrayU";
			break;

		case StorageImageAccess::eImageSizeBufferU:
			result = "ImageSizeBufferU";
			break;

		case StorageImageAccess::eImageSize2DMSU:
			result = "ImageSize2DMSU";
			break;

		case StorageImageAccess::eImageSize2DMSArrayU:
			result = "ImageSize2DMSArrayU";
			break;

		case StorageImageAccess::eImageSamples2DMSF:
			result = "ImageSamples2DMSF";
			break;

		case StorageImageAccess::eImageSamples2DMSArrayF:
			result = "ImageSamples2DMSArrayF";
			break;

		case StorageImageAccess::eImageSamples2DMSI:
			result = "ImageSamples2DMSI";
			break;

		case StorageImageAccess::eImageSamples2DMSArrayI:
			result = "ImageSamples2DMSArrayI";
			break;

		case StorageImageAccess::eImageSamples2DMSU:
			result = "ImageSamples2DMSU";
			break;

		case StorageImageAccess::eImageSamples2DMSArrayU:
			result = "ImageSamples2DMSArrayU";
			break;


	// Image texel load
		case StorageImageAccess::eImageLoad1DF:
			result = "ImageLoad1DF";
			break;

		case StorageImageAccess::eImageLoad2DF:
			result = "ImageLoad2DF";
			break;

		case StorageImageAccess::eImageLoad3DF:
			result = "ImageLoad3DF";
			break;

		case StorageImageAccess::eImageLoadCubeF:
			result = "ImageLoadCubeF";
			break;

		case StorageImageAccess::eImageLoadBufferF:
			result = "ImageLoadBufferF";
			break;

		case StorageImageAccess::eImageLoad1DArrayF:
			result = "ImageLoad1DArrayF";
			break;

		case StorageImageAccess::eImageLoad2DArrayF:
			result = "ImageLoad2DArrayF";
			break;

		case StorageImageAccess::eImageLoadCubeArrayF:
			result = "ImageLoadCubeArrayF";
			break;

		case StorageImageAccess::eImageLoad2DMSF:
			result = "ImageLoad2DMSF";
			break;

		case StorageImageAccess::eImageLoad2DMSArrayF:
			result = "ImageLoad2DMSArrayF";
			break;

		case StorageImageAccess::eImageLoad1DI:
			result = "ImageLoad1DI";
			break;

		case StorageImageAccess::eImageLoad2DI:
			result = "ImageLoad2DI";
			break;

		case StorageImageAccess::eImageLoad3DI:
			result = "ImageLoad3DI";
			break;

		case StorageImageAccess::eImageLoadCubeI:
			result = "ImageLoadCubeI";
			break;

		case StorageImageAccess::eImageLoadBufferI:
			result = "ImageLoadBufferI";
			break;

		case StorageImageAccess::eImageLoad1DArrayI:
			result = "ImageLoad1DArrayI";
			break;

		case StorageImageAccess::eImageLoad2DArrayI:
			result = "ImageLoad2DArrayI";
			break;

		case StorageImageAccess::eImageLoadCubeArrayI:
			result = "ImageLoadCubeArrayI";
			break;

		case StorageImageAccess::eImageLoad2DMSI:
			result = "ImageLoad2DMSI";
			break;

		case StorageImageAccess::eImageLoad2DMSArrayI:
			result = "ImageLoad2DMSArrayI";
			break;

		case StorageImageAccess::eImageLoad1DU:
			result = "ImageLoad1DU";
			break;

		case StorageImageAccess::eImageLoad2DU:
			result = "ImageLoad2DU";
			break;

		case StorageImageAccess::eImageLoad3DU:
			result = "ImageLoad3DU";
			break;

		case StorageImageAccess::eImageLoadCubeU:
			result = "ImageLoadCubeU";
			break;

		case StorageImageAccess::eImageLoadBufferU:
			result = "ImageLoadBufferU";
			break;

		case StorageImageAccess::eImageLoad1DArrayU:
			result = "ImageLoad1DArrayU";
			break;

		case StorageImageAccess::eImageLoad2DArrayU:
			result = "ImageLoad2DArrayU";
			break;

		case StorageImageAccess::eImageLoadCubeArrayU:
			result = "ImageLoadCubeArrayU";
			break;

		case StorageImageAccess::eImageLoad2DMSU:
			result = "ImageLoad2DMSU";
			break;

		case StorageImageAccess::eImageLoad2DMSArrayU:
			result = "ImageLoad2DMSArrayU";
			break;


	// Image texel store
		case StorageImageAccess::eImageStore1DF:
			result = "ImageStore1DF";
			break;

		case StorageImageAccess::eImageStore2DF:
			result = "ImageStore2DF";
			break;

		case StorageImageAccess::eImageStore3DF:
			result = "ImageStore3DF";
			break;

		case StorageImageAccess::eImageStoreCubeF:
			result = "ImageStoreCubeF";
			break;

		case StorageImageAccess::eImageStoreBufferF:
			result = "ImageStoreBufferF";
			break;

		case StorageImageAccess::eImageStore1DArrayF:
			result = "ImageStore1DArrayF";
			break;

		case StorageImageAccess::eImageStore2DArrayF:
			result = "ImageStore2DArrayF";
			break;

		case StorageImageAccess::eImageStoreCubeArrayF:
			result = "ImageStoreCubeArrayF";
			break;

		case StorageImageAccess::eImageStore2DMSF:
			result = "ImageStore2DMSF";
			break;

		case StorageImageAccess::eImageStore2DMSArrayF:
			result = "ImageStore2DMSArrayF";
			break;

		case StorageImageAccess::eImageStore1DI:
			result = "ImageStore1DI";
			break;

		case StorageImageAccess::eImageStore2DI:
			result = "ImageStore2DI";
			break;

		case StorageImageAccess::eImageStore3DI:
			result = "ImageStore3DI";
			break;

		case StorageImageAccess::eImageStoreCubeI:
			result = "ImageStoreCubeI";
			break;

		case StorageImageAccess::eImageStoreBufferI:
			result = "ImageStoreBufferI";
			break;

		case StorageImageAccess::eImageStore1DArrayI:
			result = "ImageStore1DArrayI";
			break;

		case StorageImageAccess::eImageStore2DArrayI:
			result = "ImageStore2DArrayI";
			break;

		case StorageImageAccess::eImageStoreCubeArrayI:
			result = "ImageStoreCubeArrayI";
			break;

		case StorageImageAccess::eImageStore2DMSI:
			result = "ImageStore2DMSI";
			break;

		case StorageImageAccess::eImageStore2DMSArrayI:
			result = "ImageStore2DMSArrayI";
			break;

		case StorageImageAccess::eImageStore1DU:
			result = "ImageStore1DU";
			break;

		case StorageImageAccess::eImageStore2DU:
			result = "ImageStore2DU";
			break;

		case StorageImageAccess::eImageStore3DU:
			result = "ImageStore3DU";
			break;

		case StorageImageAccess::eImageStoreCubeU:
			result = "ImageStoreCubeU";
			break;

		case StorageImageAccess::eImageStoreBufferU:
			result = "ImageStoreBufferU";
			break;

		case StorageImageAccess::eImageStore1DArrayU:
			result = "ImageStore1DArrayU";
			break;

		case StorageImageAccess::eImageStore2DArrayU:
			result = "ImageStore2DArrayU";
			break;

		case StorageImageAccess::eImageStoreCubeArrayU:
			result = "ImageStoreCubeArrayU";
			break;

		case StorageImageAccess::eImageStore2DMSU:
			result = "ImageStore2DMSU";
			break;

		case StorageImageAccess::eImageStore2DMSArrayU:
			result = "ImageStore2DMSArrayU";
			break;


	// Image atomics
		case StorageImageAccess::eImageAtomicAdd1DU:
			result = "ImageAtomicAdd1DU";
			break;

		case StorageImageAccess::eImageAtomicAdd2DU:
			result = "ImageAtomicAdd2DU";
			break;

		case StorageImageAccess::eImageAtomicAdd3DU:
			result = "ImageAtomicAdd3DU";
			break;

		case StorageImageAccess::eImageAtomicAddCubeU:
			result = "ImageAtomicAddCubeU";
			break;

		case StorageImageAccess::eImageAtomicAddBufferU:
			result = "ImageAtomicAddBufferU";
			break;

		case StorageImageAccess::eImageAtomicAdd1DArrayU:
			result = "ImageAtomicAdd1DArrayU";
			break;

		case StorageImageAccess::eImageAtomicAdd2DArrayU:
			result = "ImageAtomicAdd2DArrayU";
			break;

		case StorageImageAccess::eImageAtomicAddCubeArrayU:
			result = "ImageAtomicAddCubeArrayU";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSU:
			result = "ImageAtomicAdd2DMSU";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSArrayU:
			result = "ImageAtomicAdd2DMSArrayU";
			break;

		case StorageImageAccess::eImageAtomicAdd1DI:
			result = "ImageAtomicAdd1DI";
			break;

		case StorageImageAccess::eImageAtomicAdd2DI:
			result = "ImageAtomicAdd2DI";
			break;

		case StorageImageAccess::eImageAtomicAdd3DI:
			result = "ImageAtomicAdd3DI";
			break;

		case StorageImageAccess::eImageAtomicAddCubeI:
			result = "ImageAtomicAddCubeI";
			break;

		case StorageImageAccess::eImageAtomicAddBufferI:
			result = "ImageAtomicAddBufferI";
			break;

		case StorageImageAccess::eImageAtomicAdd1DArrayI:
			result = "ImageAtomicAdd1DArrayI";
			break;

		case StorageImageAccess::eImageAtomicAdd2DArrayI:
			result = "ImageAtomicAdd2DArrayI";
			break;

		case StorageImageAccess::eImageAtomicAddCubeArrayI:
			result = "ImageAtomicAddCubeArrayI";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSI:
			result = "ImageAtomicAdd2DMSI";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSArrayI:
			result = "ImageAtomicAdd2DMSArrayI";
			break;

		case StorageImageAccess::eImageAtomicAdd1DF:
			result = "ImageAtomicAdd1DF";
			break;

		case StorageImageAccess::eImageAtomicAdd2DF:
			result = "ImageAtomicAdd2DF";
			break;

		case StorageImageAccess::eImageAtomicAdd3DF:
			result = "ImageAtomicAdd3DF";
			break;

		case StorageImageAccess::eImageAtomicAddCubeF:
			result = "ImageAtomicAddCubeF";
			break;

		case StorageImageAccess::eImageAtomicAddBufferF:
			result = "ImageAtomicAddBufferF";
			break;

		case StorageImageAccess::eImageAtomicAdd1DArrayF:
			result = "ImageAtomicAdd1DArrayF";
			break;

		case StorageImageAccess::eImageAtomicAdd2DArrayF:
			result = "ImageAtomicAdd2DArrayF";
			break;

		case StorageImageAccess::eImageAtomicAddCubeArrayF:
			result = "ImageAtomicAddCubeArrayF";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSF:
			result = "ImageAtomicAdd2DMSF";
			break;

		case StorageImageAccess::eImageAtomicAdd2DMSArrayF:
			result = "ImageAtomicAdd2DMSArrayF";
			break;

		case StorageImageAccess::eImageAtomicMin1DU:
			result = "ImageAtomicMin1DU";
			break;

		case StorageImageAccess::eImageAtomicMin2DU:
			result = "ImageAtomicMin2DU";
			break;

		case StorageImageAccess::eImageAtomicMin3DU:
			result = "ImageAtomicMin3DU";
			break;

		case StorageImageAccess::eImageAtomicMinCubeU:
			result = "ImageAtomicMinCubeU";
			break;

		case StorageImageAccess::eImageAtomicMinBufferU:
			result = "ImageAtomicMinBufferU";
			break;

		case StorageImageAccess::eImageAtomicMin1DArrayU:
			result = "ImageAtomicMin1DArrayU";
			break;

		case StorageImageAccess::eImageAtomicMin2DArrayU:
			result = "ImageAtomicMin2DArrayU";
			break;

		case StorageImageAccess::eImageAtomicMinCubeArrayU:
			result = "ImageAtomicMinCubeArrayU";
			break;

		case StorageImageAccess::eImageAtomicMin2DMSU:
			result = "ImageAtomicMin2DMSU";
			break;

		case StorageImageAccess::eImageAtomicMin2DMSArrayU:
			result = "ImageAtomicMin2DMSArrayU";
			break;

		case StorageImageAccess::eImageAtomicMin1DI:
			result = "ImageAtomicMin1DI";
			break;

		case StorageImageAccess::eImageAtomicMin2DI:
			result = "ImageAtomicMin2DI";
			break;

		case StorageImageAccess::eImageAtomicMin3DI:
			result = "ImageAtomicMin3DI";
			break;

		case StorageImageAccess::eImageAtomicMinCubeI:
			result = "ImageAtomicMinCubeI";
			break;

		case StorageImageAccess::eImageAtomicMinBufferI:
			result = "ImageAtomicMinBufferI";
			break;

		case StorageImageAccess::eImageAtomicMin1DArrayI:
			result = "ImageAtomicMin1DArrayI";
			break;

		case StorageImageAccess::eImageAtomicMin2DArrayI:
			result = "ImageAtomicMin2DArrayI";
			break;

		case StorageImageAccess::eImageAtomicMinCubeArrayI:
			result = "ImageAtomicMinCubeArrayI";
			break;

		case StorageImageAccess::eImageAtomicMin2DMSI:
			result = "ImageAtomicMin2DMSI";
			break;

		case StorageImageAccess::eImageAtomicMin2DMSArrayI:
			result = "ImageAtomicMin2DMSArrayI";
			break;

		case StorageImageAccess::eImageAtomicMax1DU:
			result = "ImageAtomicMax1DU";
			break;

		case StorageImageAccess::eImageAtomicMax2DU:
			result = "ImageAtomicMax2DU";
			break;

		case StorageImageAccess::eImageAtomicMax3DU:
			result = "ImageAtomicMax3DU";
			break;

		case StorageImageAccess::eImageAtomicMaxCubeU:
			result = "ImageAtomicMaxCubeU";
			break;

		case StorageImageAccess::eImageAtomicMaxBufferU:
			result = "ImageAtomicMaxBufferU";
			break;

		case StorageImageAccess::eImageAtomicMax1DArrayU:
			result = "ImageAtomicMax1DArrayU";
			break;

		case StorageImageAccess::eImageAtomicMax2DArrayU:
			result = "ImageAtomicMax2DArrayU";
			break;

		case StorageImageAccess::eImageAtomicMaxCubeArrayU:
			result = "ImageAtomicMaxCubeArrayU";
			break;

		case StorageImageAccess::eImageAtomicMax2DMSU:
			result = "ImageAtomicMax2DMSU";
			break;

		case StorageImageAccess::eImageAtomicMax2DMSArrayU:
			result = "ImageAtomicMax2DMSArrayU";
			break;

		case StorageImageAccess::eImageAtomicMax1DI:
			result = "ImageAtomicMax1DI";
			break;

		case StorageImageAccess::eImageAtomicMax2DI:
			result = "ImageAtomicMax2DI";
			break;

		case StorageImageAccess::eImageAtomicMax3DI:
			result = "ImageAtomicMax3DI";
			break;

		case StorageImageAccess::eImageAtomicMaxCubeI:
			result = "ImageAtomicMaxCubeI";
			break;

		case StorageImageAccess::eImageAtomicMaxBufferI:
			result = "ImageAtomicMaxBufferI";
			break;

		case StorageImageAccess::eImageAtomicMax1DArrayI:
			result = "ImageAtomicMax1DArrayI";
			break;

		case StorageImageAccess::eImageAtomicMax2DArrayI:
			result = "ImageAtomicMax2DArrayI";
			break;

		case StorageImageAccess::eImageAtomicMaxCubeArrayI:
			result = "ImageAtomicMaxCubeArrayI";
			break;

		case StorageImageAccess::eImageAtomicMax2DMSI:
			result = "ImageAtomicMax2DMSI";
			break;

		case StorageImageAccess::eImageAtomicMax2DMSArrayI:
			result = "ImageAtomicMax2DMSArrayI";
			break;

		case StorageImageAccess::eImageAtomicAnd1DU:
			result = "ImageAtomicAnd1DU";
			break;

		case StorageImageAccess::eImageAtomicAnd2DU:
			result = "ImageAtomicAnd2DU";
			break;

		case StorageImageAccess::eImageAtomicAnd3DU:
			result = "ImageAtomicAnd3DU";
			break;

		case StorageImageAccess::eImageAtomicAndCubeU:
			result = "ImageAtomicAndCubeU";
			break;

		case StorageImageAccess::eImageAtomicAndBufferU:
			result = "ImageAtomicAndBufferU";
			break;

		case StorageImageAccess::eImageAtomicAnd1DArrayU:
			result = "ImageAtomicAnd1DArrayU";
			break;

		case StorageImageAccess::eImageAtomicAnd2DArrayU:
			result = "ImageAtomicAnd2DArrayU";
			break;

		case StorageImageAccess::eImageAtomicAndCubeArrayU:
			result = "ImageAtomicAndCubeArrayU";
			break;

		case StorageImageAccess::eImageAtomicAnd2DMSU:
			result = "ImageAtomicAnd2DMSU";
			break;

		case StorageImageAccess::eImageAtomicAnd2DMSArrayU:
			result = "ImageAtomicAnd2DMSArrayU";
			break;

		case StorageImageAccess::eImageAtomicAnd1DI:
			result = "ImageAtomicAnd1DI";
			break;

		case StorageImageAccess::eImageAtomicAnd2DI:
			result = "ImageAtomicAnd2DI";
			break;

		case StorageImageAccess::eImageAtomicAnd3DI:
			result = "ImageAtomicAnd3DI";
			break;

		case StorageImageAccess::eImageAtomicAndCubeI:
			result = "ImageAtomicAndCubeI";
			break;

		case StorageImageAccess::eImageAtomicAndBufferI:
			result = "ImageAtomicAndBufferI";
			break;

		case StorageImageAccess::eImageAtomicAnd1DArrayI:
			result = "ImageAtomicAnd1DArrayI";
			break;

		case StorageImageAccess::eImageAtomicAnd2DArrayI:
			result = "ImageAtomicAnd2DArrayI";
			break;

		case StorageImageAccess::eImageAtomicAndCubeArrayI:
			result = "ImageAtomicAndCubeArrayI";
			break;

		case StorageImageAccess::eImageAtomicAnd2DMSI:
			result = "ImageAtomicAnd2DMSI";
			break;

		case StorageImageAccess::eImageAtomicAnd2DMSArrayI:
			result = "ImageAtomicAnd2DMSArrayI";
			break;

		case StorageImageAccess::eImageAtomicOr1DU:
			result = "ImageAtomicOr1DU";
			break;

		case StorageImageAccess::eImageAtomicOr2DU:
			result = "ImageAtomicOr2DU";
			break;

		case StorageImageAccess::eImageAtomicOr3DU:
			result = "ImageAtomicOr3DU";
			break;

		case StorageImageAccess::eImageAtomicOrCubeU:
			result = "ImageAtomicOrCubeU";
			break;

		case StorageImageAccess::eImageAtomicOrBufferU:
			result = "ImageAtomicOrBufferU";
			break;

		case StorageImageAccess::eImageAtomicOr1DArrayU:
			result = "ImageAtomicOr1DArrayU";
			break;

		case StorageImageAccess::eImageAtomicOr2DArrayU:
			result = "ImageAtomicOr2DArrayU";
			break;

		case StorageImageAccess::eImageAtomicOrCubeArrayU:
			result = "ImageAtomicOrCubeArrayU";
			break;

		case StorageImageAccess::eImageAtomicOr2DMSU:
			result = "ImageAtomicOr2DMSU";
			break;

		case StorageImageAccess::eImageAtomicOr2DMSArrayU:
			result = "ImageAtomicOr2DMSArrayU";
			break;

		case StorageImageAccess::eImageAtomicOr1DI:
			result = "ImageAtomicOr1DI";
			break;

		case StorageImageAccess::eImageAtomicOr2DI:
			result = "ImageAtomicOr2DI";
			break;

		case StorageImageAccess::eImageAtomicOr3DI:
			result = "ImageAtomicOr3DI";
			break;

		case StorageImageAccess::eImageAtomicOrCubeI:
			result = "ImageAtomicOrCubeI";
			break;

		case StorageImageAccess::eImageAtomicOrBufferI:
			result = "ImageAtomicOrBufferI";
			break;

		case StorageImageAccess::eImageAtomicOr1DArrayI:
			result = "ImageAtomicOr1DArrayI";
			break;

		case StorageImageAccess::eImageAtomicOr2DArrayI:
			result = "ImageAtomicOr2DArrayI";
			break;

		case StorageImageAccess::eImageAtomicOrCubeArrayI:
			result = "ImageAtomicOrCubeArrayI";
			break;

		case StorageImageAccess::eImageAtomicOr2DMSI:
			result = "ImageAtomicOr2DMSI";
			break;

		case StorageImageAccess::eImageAtomicOr2DMSArrayI:
			result = "ImageAtomicOr2DMSArrayI";
			break;

		case StorageImageAccess::eImageAtomicXor1DU:
			result = "ImageAtomicXor1DU";
			break;

		case StorageImageAccess::eImageAtomicXor2DU:
			result = "ImageAtomicXor2DU";
			break;

		case StorageImageAccess::eImageAtomicXor3DU:
			result = "ImageAtomicXor3DU";
			break;

		case StorageImageAccess::eImageAtomicXorCubeU:
			result = "ImageAtomicXorCubeU";
			break;

		case StorageImageAccess::eImageAtomicXorBufferU:
			result = "ImageAtomicXorBufferU";
			break;

		case StorageImageAccess::eImageAtomicXor1DArrayU:
			result = "ImageAtomicXor1DArrayU";
			break;

		case StorageImageAccess::eImageAtomicXor2DArrayU:
			result = "ImageAtomicXor2DArrayU";
			break;

		case StorageImageAccess::eImageAtomicXorCubeArrayU:
			result = "ImageAtomicXorCubeArrayU";
			break;

		case StorageImageAccess::eImageAtomicXor2DMSU:
			result = "ImageAtomicXor2DMSU";
			break;

		case StorageImageAccess::eImageAtomicXor2DMSArrayU:
			result = "ImageAtomicXor2DMSArrayU";
			break;

		case StorageImageAccess::eImageAtomicXor1DI:
			result = "ImageAtomicXor1DI";
			break;

		case StorageImageAccess::eImageAtomicXor2DI:
			result = "ImageAtomicXor2DI";
			break;

		case StorageImageAccess::eImageAtomicXor3DI:
			result = "ImageAtomicXor3DI";
			break;

		case StorageImageAccess::eImageAtomicXorCubeI:
			result = "ImageAtomicXorCubeI";
			break;

		case StorageImageAccess::eImageAtomicXorBufferI:
			result = "ImageAtomicXorBufferI";
			break;

		case StorageImageAccess::eImageAtomicXor1DArrayI:
			result = "ImageAtomicXor1DArrayI";
			break;

		case StorageImageAccess::eImageAtomicXor2DArrayI:
			result = "ImageAtomicXor2DArrayI";
			break;

		case StorageImageAccess::eImageAtomicXorCubeArrayI:
			result = "ImageAtomicXorCubeArrayI";
			break;

		case StorageImageAccess::eImageAtomicXor2DMSI:
			result = "ImageAtomicXor2DMSI";
			break;

		case StorageImageAccess::eImageAtomicXor2DMSArrayI:
			result = "ImageAtomicXor2DMSArrayI";
			break;

		case StorageImageAccess::eImageAtomicExchange1DU:
			result = "ImageAtomicExchange1DU";
			break;

		case StorageImageAccess::eImageAtomicExchange2DU:
			result = "ImageAtomicExchange2DU";
			break;

		case StorageImageAccess::eImageAtomicExchange3DU:
			result = "ImageAtomicExchange3DU";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeU:
			result = "ImageAtomicExchangeCubeU";
			break;

		case StorageImageAccess::eImageAtomicExchangeBufferU:
			result = "ImageAtomicExchangeBufferU";
			break;

		case StorageImageAccess::eImageAtomicExchange1DArrayU:
			result = "ImageAtomicExchange1DArrayU";
			break;

		case StorageImageAccess::eImageAtomicExchange2DArrayU:
			result = "ImageAtomicExchange2DArrayU";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeArrayU:
			result = "ImageAtomicExchangeCubeArrayU";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSU:
			result = "ImageAtomicExchange2DMSU";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSArrayU:
			result = "ImageAtomicExchange2DMSArrayU";
			break;

		case StorageImageAccess::eImageAtomicExchange1DI:
			result = "ImageAtomicExchange1DI";
			break;

		case StorageImageAccess::eImageAtomicExchange2DI:
			result = "ImageAtomicExchange2DI";
			break;

		case StorageImageAccess::eImageAtomicExchange3DI:
			result = "ImageAtomicExchange3DI";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeI:
			result = "ImageAtomicExchangeCubeI";
			break;

		case StorageImageAccess::eImageAtomicExchangeBufferI:
			result = "ImageAtomicExchangeBufferI";
			break;

		case StorageImageAccess::eImageAtomicExchange1DArrayI:
			result = "ImageAtomicExchange1DArrayI";
			break;

		case StorageImageAccess::eImageAtomicExchange2DArrayI:
			result = "ImageAtomicExchange2DArrayI";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeArrayI:
			result = "ImageAtomicExchangeCubeArrayI";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSI:
			result = "ImageAtomicExchange2DMSI";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSArrayI:
			result = "ImageAtomicExchange2DMSArrayI";
			break;

		case StorageImageAccess::eImageAtomicExchange1DF:
			result = "ImageAtomicExchange1DF";
			break;

		case StorageImageAccess::eImageAtomicExchange2DF:
			result = "ImageAtomicExchange2DF";
			break;

		case StorageImageAccess::eImageAtomicExchange3DF:
			result = "ImageAtomicExchange3DF";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeF:
			result = "ImageAtomicExchangeCubeF";
			break;

		case StorageImageAccess::eImageAtomicExchangeBufferF:
			result = "ImageAtomicExchangeBufferF";
			break;

		case StorageImageAccess::eImageAtomicExchange1DArrayF:
			result = "ImageAtomicExchange1DArrayF";
			break;

		case StorageImageAccess::eImageAtomicExchange2DArrayF:
			result = "ImageAtomicExchange2DArrayF";
			break;

		case StorageImageAccess::eImageAtomicExchangeCubeArrayF:
			result = "ImageAtomicExchangeCubeArrayF";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSF:
			result = "ImageAtomicExchange2DMSF";
			break;

		case StorageImageAccess::eImageAtomicExchange2DMSArrayF:
			result = "ImageAtomicExchange2DMSArrayF";
			break;

		case StorageImageAccess::eImageAtomicCompSwap1DU:
			result = "ImageAtomicCompSwap1DU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DU:
			result = "ImageAtomicCompSwap2DU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap3DU:
			result = "ImageAtomicCompSwap3DU";
			break;

		case StorageImageAccess::eImageAtomicCompSwapCubeU:
			result = "ImageAtomicCompSwapCubeU";
			break;

		case StorageImageAccess::eImageAtomicCompSwapBufferU:
			result = "ImageAtomicCompSwapBufferU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap1DArrayU:
			result = "ImageAtomicCompSwap1DArrayU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DArrayU:
			result = "ImageAtomicCompSwap2DArrayU";
			break;

		case StorageImageAccess::eImageAtomicCompSwapCubeArrayU:
			result = "ImageAtomicCompSwapCubeArrayU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DMSU:
			result = "ImageAtomicCompSwap2DMSU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DMSArrayU:
			result = "ImageAtomicCompSwap2DMSArrayU";
			break;

		case StorageImageAccess::eImageAtomicCompSwap1DI:
			result = "ImageAtomicCompSwap1DI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DI:
			result = "ImageAtomicCompSwap2DI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap3DI:
			result = "ImageAtomicCompSwap3DI";
			break;

		case StorageImageAccess::eImageAtomicCompSwapCubeI:
			result = "ImageAtomicCompSwapCubeI";
			break;

		case StorageImageAccess::eImageAtomicCompSwapBufferI:
			result = "ImageAtomicCompSwapBufferI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap1DArrayI:
			result = "ImageAtomicCompSwap1DArrayI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DArrayI:
			result = "ImageAtomicCompSwap2DArrayI";
			break;

		case StorageImageAccess::eImageAtomicCompSwapCubeArrayI:
			result = "ImageAtomicCompSwapCubeArrayI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DMSI:
			result = "ImageAtomicCompSwap2DMSI";
			break;

		case StorageImageAccess::eImageAtomicCompSwap2DMSArrayI:
			result = "ImageAtomicCompSwap2DMSArrayI";
			break;

		default:
			throw Exception{ "Unsupported StorageImageAccess type." };
		}

		return result;
	}
}

#endif
