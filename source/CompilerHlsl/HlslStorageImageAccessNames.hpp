/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslImageAccessNames_H___
#define ___AST_HlslImageAccessNames_H___
#pragma once

#include <ShaderAST/Expr/EnumStorageImageAccess.hpp>

#include <stdexcept>
#pragma warning( push )
#pragma warning( disable: 4365 )
#include <string>
#pragma warning( pop )

namespace hlsl
{
	inline std::string getHlslName( ast::expr::StorageImageAccess value )
	{
		std::string result;

		switch ( value )
		{
		case ast::expr::StorageImageAccess::eImageSize1DF:
		case ast::expr::StorageImageAccess::eImageSize2DF:
		case ast::expr::StorageImageAccess::eImageSize3DF:
		case ast::expr::StorageImageAccess::eImageSizeCubeF:
		case ast::expr::StorageImageAccess::eImageSizeCubeArrayF:
		case ast::expr::StorageImageAccess::eImageSize1DArrayF:
		case ast::expr::StorageImageAccess::eImageSize2DArrayF:
		case ast::expr::StorageImageAccess::eImageSizeBufferF:
		case ast::expr::StorageImageAccess::eImageSize2DMSF:
		case ast::expr::StorageImageAccess::eImageSize2DMSArrayF:
		case ast::expr::StorageImageAccess::eImageSize1DI:
		case ast::expr::StorageImageAccess::eImageSize2DI:
		case ast::expr::StorageImageAccess::eImageSize3DI:
		case ast::expr::StorageImageAccess::eImageSizeCubeI:
		case ast::expr::StorageImageAccess::eImageSizeCubeArrayI:
		case ast::expr::StorageImageAccess::eImageSize1DArrayI:
		case ast::expr::StorageImageAccess::eImageSize2DArrayI:
		case ast::expr::StorageImageAccess::eImageSizeBufferI:
		case ast::expr::StorageImageAccess::eImageSize2DMSI:
		case ast::expr::StorageImageAccess::eImageSize2DMSArrayI:
		case ast::expr::StorageImageAccess::eImageSize1DU:
		case ast::expr::StorageImageAccess::eImageSize2DU:
		case ast::expr::StorageImageAccess::eImageSize3DU:
		case ast::expr::StorageImageAccess::eImageSizeCubeU:
		case ast::expr::StorageImageAccess::eImageSizeCubeArrayU:
		case ast::expr::StorageImageAccess::eImageSize1DArrayU:
		case ast::expr::StorageImageAccess::eImageSize2DArrayU:
		case ast::expr::StorageImageAccess::eImageSizeBufferU:
		case ast::expr::StorageImageAccess::eImageSize2DMSU:
		case ast::expr::StorageImageAccess::eImageSize2DMSArrayU:
			result = "SDW_imageSize";
			break;

		case ast::expr::StorageImageAccess::eImageSamples2DMSF:
		case ast::expr::StorageImageAccess::eImageSamples2DMSArrayF:
		case ast::expr::StorageImageAccess::eImageSamples2DMSI:
		case ast::expr::StorageImageAccess::eImageSamples2DMSArrayI:
		case ast::expr::StorageImageAccess::eImageSamples2DMSU:
		case ast::expr::StorageImageAccess::eImageSamples2DMSArrayU:
			result = "SDW_imageSamples";
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
			result = "Load";
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
			result = "SDW_imageStore";
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAdd1DU:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DU:
		case ast::expr::StorageImageAccess::eImageAtomicAdd3DU:
		case ast::expr::StorageImageAccess::eImageAtomicAddCubeU:
		case ast::expr::StorageImageAccess::eImageAtomicAddBufferU:
		case ast::expr::StorageImageAccess::eImageAtomicAdd1DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicAddCubeArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSU:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicAdd1DI:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DI:
		case ast::expr::StorageImageAccess::eImageAtomicAdd3DI:
		case ast::expr::StorageImageAccess::eImageAtomicAddCubeI:
		case ast::expr::StorageImageAccess::eImageAtomicAddBufferI:
		case ast::expr::StorageImageAccess::eImageAtomicAdd1DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicAddCubeArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSI:
		case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayI:
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
			result = "SDW_imageAtomicAdd";
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMin1DU:
		case ast::expr::StorageImageAccess::eImageAtomicMin2DU:
		case ast::expr::StorageImageAccess::eImageAtomicMin3DU:
		case ast::expr::StorageImageAccess::eImageAtomicMinCubeU:
		case ast::expr::StorageImageAccess::eImageAtomicMinBufferU:
		case ast::expr::StorageImageAccess::eImageAtomicMin1DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicMin2DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicMinCubeArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicMin2DMSU:
		case ast::expr::StorageImageAccess::eImageAtomicMin2DMSArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicMin1DI:
		case ast::expr::StorageImageAccess::eImageAtomicMin2DI:
		case ast::expr::StorageImageAccess::eImageAtomicMin3DI:
		case ast::expr::StorageImageAccess::eImageAtomicMinCubeI:
		case ast::expr::StorageImageAccess::eImageAtomicMinBufferI:
		case ast::expr::StorageImageAccess::eImageAtomicMin1DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicMin2DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicMinCubeArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicMin2DMSI:
		case ast::expr::StorageImageAccess::eImageAtomicMin2DMSArrayI:
			result = "SDW_imageAtomicMin";
			break;

		case ast::expr::StorageImageAccess::eImageAtomicMax1DU:
		case ast::expr::StorageImageAccess::eImageAtomicMax2DU:
		case ast::expr::StorageImageAccess::eImageAtomicMax3DU:
		case ast::expr::StorageImageAccess::eImageAtomicMaxCubeU:
		case ast::expr::StorageImageAccess::eImageAtomicMaxBufferU:
		case ast::expr::StorageImageAccess::eImageAtomicMax1DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicMax2DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicMaxCubeArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicMax2DMSU:
		case ast::expr::StorageImageAccess::eImageAtomicMax2DMSArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicMax1DI:
		case ast::expr::StorageImageAccess::eImageAtomicMax2DI:
		case ast::expr::StorageImageAccess::eImageAtomicMax3DI:
		case ast::expr::StorageImageAccess::eImageAtomicMaxCubeI:
		case ast::expr::StorageImageAccess::eImageAtomicMaxBufferI:
		case ast::expr::StorageImageAccess::eImageAtomicMax1DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicMax2DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicMaxCubeArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicMax2DMSI:
		case ast::expr::StorageImageAccess::eImageAtomicMax2DMSArrayI:
			result = "SDW_imageAtomicMax";
			break;

		case ast::expr::StorageImageAccess::eImageAtomicAnd1DU:
		case ast::expr::StorageImageAccess::eImageAtomicAnd2DU:
		case ast::expr::StorageImageAccess::eImageAtomicAnd3DU:
		case ast::expr::StorageImageAccess::eImageAtomicAndCubeU:
		case ast::expr::StorageImageAccess::eImageAtomicAndBufferU:
		case ast::expr::StorageImageAccess::eImageAtomicAnd1DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicAnd2DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicAndCubeArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSU:
		case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicAnd1DI:
		case ast::expr::StorageImageAccess::eImageAtomicAnd2DI:
		case ast::expr::StorageImageAccess::eImageAtomicAnd3DI:
		case ast::expr::StorageImageAccess::eImageAtomicAndCubeI:
		case ast::expr::StorageImageAccess::eImageAtomicAndBufferI:
		case ast::expr::StorageImageAccess::eImageAtomicAnd1DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicAnd2DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicAndCubeArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSI:
		case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSArrayI:
			result = "SDW_imageAtomicAnd";
			break;

		case ast::expr::StorageImageAccess::eImageAtomicOr1DU:
		case ast::expr::StorageImageAccess::eImageAtomicOr2DU:
		case ast::expr::StorageImageAccess::eImageAtomicOr3DU:
		case ast::expr::StorageImageAccess::eImageAtomicOrCubeU:
		case ast::expr::StorageImageAccess::eImageAtomicOrBufferU:
		case ast::expr::StorageImageAccess::eImageAtomicOr1DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicOr2DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicOrCubeArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicOr2DMSU:
		case ast::expr::StorageImageAccess::eImageAtomicOr2DMSArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicOr1DI:
		case ast::expr::StorageImageAccess::eImageAtomicOr2DI:
		case ast::expr::StorageImageAccess::eImageAtomicOr3DI:
		case ast::expr::StorageImageAccess::eImageAtomicOrCubeI:
		case ast::expr::StorageImageAccess::eImageAtomicOrBufferI:
		case ast::expr::StorageImageAccess::eImageAtomicOr1DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicOr2DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicOrCubeArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicOr2DMSI:
		case ast::expr::StorageImageAccess::eImageAtomicOr2DMSArrayI:
			result = "SDW_imageAtomicOr";
			break;

		case ast::expr::StorageImageAccess::eImageAtomicXor1DU:
		case ast::expr::StorageImageAccess::eImageAtomicXor2DU:
		case ast::expr::StorageImageAccess::eImageAtomicXor3DU:
		case ast::expr::StorageImageAccess::eImageAtomicXorCubeU:
		case ast::expr::StorageImageAccess::eImageAtomicXorBufferU:
		case ast::expr::StorageImageAccess::eImageAtomicXor1DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicXor2DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicXorCubeArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicXor2DMSU:
		case ast::expr::StorageImageAccess::eImageAtomicXor2DMSArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicXor1DI:
		case ast::expr::StorageImageAccess::eImageAtomicXor2DI:
		case ast::expr::StorageImageAccess::eImageAtomicXor3DI:
		case ast::expr::StorageImageAccess::eImageAtomicXorCubeI:
		case ast::expr::StorageImageAccess::eImageAtomicXorBufferI:
		case ast::expr::StorageImageAccess::eImageAtomicXor1DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicXor2DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicXorCubeArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicXor2DMSI:
		case ast::expr::StorageImageAccess::eImageAtomicXor2DMSArrayI:
			result = "SDW_imageAtomicXor";
			break;

		case ast::expr::StorageImageAccess::eImageAtomicExchange1DU:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DU:
		case ast::expr::StorageImageAccess::eImageAtomicExchange3DU:
		case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeU:
		case ast::expr::StorageImageAccess::eImageAtomicExchangeBufferU:
		case ast::expr::StorageImageAccess::eImageAtomicExchange1DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSU:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicExchange1DI:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DI:
		case ast::expr::StorageImageAccess::eImageAtomicExchange3DI:
		case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeI:
		case ast::expr::StorageImageAccess::eImageAtomicExchangeBufferI:
		case ast::expr::StorageImageAccess::eImageAtomicExchange1DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSI:
		case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayI:
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
			result = "SDW_imageAtomicExchange";
			break;

		case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DU:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DU:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap3DU:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeU:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwapBufferU:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSU:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSArrayU:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DI:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DI:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap3DI:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeI:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwapBufferI:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeArrayI:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSI:
		case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSArrayI:
			result = "SDW_imageAtomicCompSwap";
			break;

		default:
			throw ast::Exception{ "Unsupported StorageImageAccess type." };
		}

		return result;
	}
}

#endif
