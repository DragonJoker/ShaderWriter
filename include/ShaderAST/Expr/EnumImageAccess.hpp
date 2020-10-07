/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprEnumImageAccess_H___
#define ___AST_ExprEnumImageAccess_H___
#pragma once

namespace ast::expr
{
	enum class ImageAccess
	{
	// Image Query Functions
		eImageSize1DF,
		eImageSize2DF,
		eImageSize3DF,
		eImageSizeCubeF,
		eImageSizeCubeArrayF,
		eImageSize2DRectF,
		eImageSize1DArrayF,
		eImageSize2DArrayF,
		eImageSizeBufferF,
		eImageSize2DMSF,
		eImageSize2DMSArrayF,
		eImageSize1DI,
		eImageSize2DI,
		eImageSize3DI,
		eImageSizeCubeI,
		eImageSizeCubeArrayI,
		eImageSize2DRectI,
		eImageSize1DArrayI,
		eImageSize2DArrayI,
		eImageSizeBufferI,
		eImageSize2DMSI,
		eImageSize2DMSArrayI,
		eImageSize1DU,
		eImageSize2DU,
		eImageSize3DU,
		eImageSizeCubeU,
		eImageSizeCubeArrayU,
		eImageSize2DRectU,
		eImageSize1DArrayU,
		eImageSize2DArrayU,
		eImageSizeBufferU,
		eImageSize2DMSU,
		eImageSize2DMSArrayU,
		eImageSamples2DMSF,
		eImageSamples2DMSArrayF,
		eImageSamples2DMSI,
		eImageSamples2DMSArrayI,
		eImageSamples2DMSU,
		eImageSamples2DMSArrayU,

	// Image texel load
		eImageLoad1DF,
		eImageLoad2DF,
		eImageLoad3DF,
		eImageLoad2DRectF,
		eImageLoadCubeF,
		eImageLoadBufferF,
		eImageLoad1DArrayF,
		eImageLoad2DArrayF,
		eImageLoadCubeArrayF,
		eImageLoad2DMSF,
		eImageLoad2DMSArrayF,
		eImageLoad1DI,
		eImageLoad2DI,
		eImageLoad3DI,
		eImageLoad2DRectI,
		eImageLoadCubeI,
		eImageLoadBufferI,
		eImageLoad1DArrayI,
		eImageLoad2DArrayI,
		eImageLoadCubeArrayI,
		eImageLoad2DMSI,
		eImageLoad2DMSArrayI,
		eImageLoad1DU,
		eImageLoad2DU,
		eImageLoad3DU,
		eImageLoad2DRectU,
		eImageLoadCubeU,
		eImageLoadBufferU,
		eImageLoad1DArrayU,
		eImageLoad2DArrayU,
		eImageLoadCubeArrayU,
		eImageLoad2DMSU,
		eImageLoad2DMSArrayU,

	// Image texel store
		eImageStore1DF,
		eImageStore2DF,
		eImageStore3DF,
		eImageStore2DRectF,
		eImageStoreCubeF,
		eImageStoreBufferF,
		eImageStore1DArrayF,
		eImageStore2DArrayF,
		eImageStoreCubeArrayF,
		eImageStore2DMSF,
		eImageStore2DMSArrayF,
		eImageStore1DI,
		eImageStore2DI,
		eImageStore3DI,
		eImageStore2DRectI,
		eImageStoreCubeI,
		eImageStoreBufferI,
		eImageStore1DArrayI,
		eImageStore2DArrayI,
		eImageStoreCubeArrayI,
		eImageStore2DMSI,
		eImageStore2DMSArrayI,
		eImageStore1DU,
		eImageStore2DU,
		eImageStore3DU,
		eImageStore2DRectU,
		eImageStoreCubeU,
		eImageStoreBufferU,
		eImageStore1DArrayU,
		eImageStore2DArrayU,
		eImageStoreCubeArrayU,
		eImageStore2DMSU,
		eImageStore2DMSArrayU,

	// Image atomics
		eImageAtomicAdd1DU,
		eImageAtomicAdd2DU,
		eImageAtomicAdd3DU,
		eImageAtomicAdd2DRectU,
		eImageAtomicAddCubeU,
		eImageAtomicAddBufferU,
		eImageAtomicAdd1DArrayU,
		eImageAtomicAdd2DArrayU,
		eImageAtomicAddCubeArrayU,
		eImageAtomicAdd2DMSU,
		eImageAtomicAdd2DMSArrayU,
		eImageAtomicAdd1DI,
		eImageAtomicAdd2DI,
		eImageAtomicAdd3DI,
		eImageAtomicAdd2DRectI,
		eImageAtomicAddCubeI,
		eImageAtomicAddBufferI,
		eImageAtomicAdd1DArrayI,
		eImageAtomicAdd2DArrayI,
		eImageAtomicAddCubeArrayI,
		eImageAtomicAdd2DMSI,
		eImageAtomicAdd2DMSArrayI,
		eImageAtomicAdd1DF,
		eImageAtomicAdd2DF,
		eImageAtomicAdd3DF,
		eImageAtomicAdd2DRectF,
		eImageAtomicAddCubeF,
		eImageAtomicAddBufferF,
		eImageAtomicAdd1DArrayF,
		eImageAtomicAdd2DArrayF,
		eImageAtomicAddCubeArrayF,
		eImageAtomicAdd2DMSF,
		eImageAtomicAdd2DMSArrayF,
		eImageAtomicMin1DU,
		eImageAtomicMin2DU,
		eImageAtomicMin3DU,
		eImageAtomicMin2DRectU,
		eImageAtomicMinCubeU,
		eImageAtomicMinBufferU,
		eImageAtomicMin1DArrayU,
		eImageAtomicMin2DArrayU,
		eImageAtomicMinCubeArrayU,
		eImageAtomicMin2DMSU,
		eImageAtomicMin2DMSArrayU,
		eImageAtomicMin1DI,
		eImageAtomicMin2DI,
		eImageAtomicMin3DI,
		eImageAtomicMin2DRectI,
		eImageAtomicMinCubeI,
		eImageAtomicMinBufferI,
		eImageAtomicMin1DArrayI,
		eImageAtomicMin2DArrayI,
		eImageAtomicMinCubeArrayI,
		eImageAtomicMin2DMSI,
		eImageAtomicMin2DMSArrayI,
		eImageAtomicMax1DU,
		eImageAtomicMax2DU,
		eImageAtomicMax3DU,
		eImageAtomicMax2DRectU,
		eImageAtomicMaxCubeU,
		eImageAtomicMaxBufferU,
		eImageAtomicMax1DArrayU,
		eImageAtomicMax2DArrayU,
		eImageAtomicMaxCubeArrayU,
		eImageAtomicMax2DMSU,
		eImageAtomicMax2DMSArrayU,
		eImageAtomicMax1DI,
		eImageAtomicMax2DI,
		eImageAtomicMax3DI,
		eImageAtomicMax2DRectI,
		eImageAtomicMaxCubeI,
		eImageAtomicMaxBufferI,
		eImageAtomicMax1DArrayI,
		eImageAtomicMax2DArrayI,
		eImageAtomicMaxCubeArrayI,
		eImageAtomicMax2DMSI,
		eImageAtomicMax2DMSArrayI,
		eImageAtomicAnd1DU,
		eImageAtomicAnd2DU,
		eImageAtomicAnd3DU,
		eImageAtomicAnd2DRectU,
		eImageAtomicAndCubeU,
		eImageAtomicAndBufferU,
		eImageAtomicAnd1DArrayU,
		eImageAtomicAnd2DArrayU,
		eImageAtomicAndCubeArrayU,
		eImageAtomicAnd2DMSU,
		eImageAtomicAnd2DMSArrayU,
		eImageAtomicAnd1DI,
		eImageAtomicAnd2DI,
		eImageAtomicAnd3DI,
		eImageAtomicAnd2DRectI,
		eImageAtomicAndCubeI,
		eImageAtomicAndBufferI,
		eImageAtomicAnd1DArrayI,
		eImageAtomicAnd2DArrayI,
		eImageAtomicAndCubeArrayI,
		eImageAtomicAnd2DMSI,
		eImageAtomicAnd2DMSArrayI,
		eImageAtomicOr1DU,
		eImageAtomicOr2DU,
		eImageAtomicOr3DU,
		eImageAtomicOr2DRectU,
		eImageAtomicOrCubeU,
		eImageAtomicOrBufferU,
		eImageAtomicOr1DArrayU,
		eImageAtomicOr2DArrayU,
		eImageAtomicOrCubeArrayU,
		eImageAtomicOr2DMSU,
		eImageAtomicOr2DMSArrayU,
		eImageAtomicOr1DI,
		eImageAtomicOr2DI,
		eImageAtomicOr3DI,
		eImageAtomicOr2DRectI,
		eImageAtomicOrCubeI,
		eImageAtomicOrBufferI,
		eImageAtomicOr1DArrayI,
		eImageAtomicOr2DArrayI,
		eImageAtomicOrCubeArrayI,
		eImageAtomicOr2DMSI,
		eImageAtomicOr2DMSArrayI,
		eImageAtomicXor1DU,
		eImageAtomicXor2DU,
		eImageAtomicXor3DU,
		eImageAtomicXor2DRectU,
		eImageAtomicXorCubeU,
		eImageAtomicXorBufferU,
		eImageAtomicXor1DArrayU,
		eImageAtomicXor2DArrayU,
		eImageAtomicXorCubeArrayU,
		eImageAtomicXor2DMSU,
		eImageAtomicXor2DMSArrayU,
		eImageAtomicXor1DI,
		eImageAtomicXor2DI,
		eImageAtomicXor3DI,
		eImageAtomicXor2DRectI,
		eImageAtomicXorCubeI,
		eImageAtomicXorBufferI,
		eImageAtomicXor1DArrayI,
		eImageAtomicXor2DArrayI,
		eImageAtomicXorCubeArrayI,
		eImageAtomicXor2DMSI,
		eImageAtomicXor2DMSArrayI,
		eImageAtomicExchange1DU,
		eImageAtomicExchange2DU,
		eImageAtomicExchange3DU,
		eImageAtomicExchange2DRectU,
		eImageAtomicExchangeCubeU,
		eImageAtomicExchangeBufferU,
		eImageAtomicExchange1DArrayU,
		eImageAtomicExchange2DArrayU,
		eImageAtomicExchangeCubeArrayU,
		eImageAtomicExchange2DMSU,
		eImageAtomicExchange2DMSArrayU,
		eImageAtomicExchange1DI,
		eImageAtomicExchange2DI,
		eImageAtomicExchange3DI,
		eImageAtomicExchange2DRectI,
		eImageAtomicExchangeCubeI,
		eImageAtomicExchangeBufferI,
		eImageAtomicExchange1DArrayI,
		eImageAtomicExchange2DArrayI,
		eImageAtomicExchangeCubeArrayI,
		eImageAtomicExchange2DMSI,
		eImageAtomicExchange2DMSArrayI,
		eImageAtomicExchange1DF,
		eImageAtomicExchange2DF,
		eImageAtomicExchange3DF,
		eImageAtomicExchange2DRectF,
		eImageAtomicExchangeCubeF,
		eImageAtomicExchangeBufferF,
		eImageAtomicExchange1DArrayF,
		eImageAtomicExchange2DArrayF,
		eImageAtomicExchangeCubeArrayF,
		eImageAtomicExchange2DMSF,
		eImageAtomicExchange2DMSArrayF,
		eImageAtomicCompSwap1DU,
		eImageAtomicCompSwap2DU,
		eImageAtomicCompSwap3DU,
		eImageAtomicCompSwap2DRectU,
		eImageAtomicCompSwapCubeU,
		eImageAtomicCompSwapBufferU,
		eImageAtomicCompSwap1DArrayU,
		eImageAtomicCompSwap2DArrayU,
		eImageAtomicCompSwapCubeArrayU,
		eImageAtomicCompSwap2DMSU,
		eImageAtomicCompSwap2DMSArrayU,
		eImageAtomicCompSwap1DI,
		eImageAtomicCompSwap2DI,
		eImageAtomicCompSwap3DI,
		eImageAtomicCompSwap2DRectI,
		eImageAtomicCompSwapCubeI,
		eImageAtomicCompSwapBufferI,
		eImageAtomicCompSwap1DArrayI,
		eImageAtomicCompSwap2DArrayI,
		eImageAtomicCompSwapCubeArrayI,
		eImageAtomicCompSwap2DMSI,
		eImageAtomicCompSwap2DMSArrayI,
	};
}

#endif
