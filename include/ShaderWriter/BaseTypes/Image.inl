/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

#include <ShaderAST/Expr/EnumImageAccess.hpp>
#include <ShaderAST/Expr/ExprImageAccessCall.hpp>

#include <array>

namespace sdw
{
	//*****************************************************************************************

	namespace img
	{
		size_t constexpr ImgDimBaseCount = size_t( type::ImageDim::eBuffer ) + 1u;
		size_t constexpr ArrayImgCount = 3u;
		size_t constexpr NonMsImgCount = ImgDimBaseCount + ArrayImgCount;
		size_t constexpr MsImgCount = 2u;
		using ImageAccessIntrList = std::array< expr::ImageAccess, NonMsImgCount + ArrayImgCount >;

		template< type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		constexpr size_t getImgArrayIndex()
		{
			if constexpr ( MsT )
			{
				return NonMsImgCount
					+ ( ArrayedT ? 1u : 0u );
			}
			else if constexpr ( ArrayedT )
			{
				if constexpr ( DimT == type::ImageDim::e1D )
				{
					return ImgDimBaseCount + 0u;
				}
				else if constexpr ( DimT == type::ImageDim::e2D )
				{
					return ImgDimBaseCount + 1u;
				}
				else if constexpr ( DimT == type::ImageDim::eCube )
				{
					return ImgDimBaseCount + 2u;
				}
				else
				{
					assert( false );
					return size_t( expr::ImageAccess::eInvalid );
				}
			}
			else
			{
				return size_t( DimT );
			}
		}

		static constexpr ImageAccessIntrList imageSizeF
		{
			expr::ImageAccess::eImageSize1DF,
			expr::ImageAccess::eImageSize2DF,
			expr::ImageAccess::eImageSize3DF,
			expr::ImageAccess::eImageSizeCubeF,
			expr::ImageAccess::eImageSize2DRectF,
			expr::ImageAccess::eImageSizeBufferF,

			expr::ImageAccess::eImageSize1DArrayF,
			expr::ImageAccess::eImageSize2DArrayF,
			expr::ImageAccess::eImageSizeCubeArrayF,

			expr::ImageAccess::eImageSize2DMSF,
			expr::ImageAccess::eImageSize2DMSArrayF,
		};
		static constexpr ImageAccessIntrList imageSamplesF
		{
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,

			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,

			expr::ImageAccess::eImageSamples2DMSF,
			expr::ImageAccess::eImageSamples2DMSArrayF,
		};
		static constexpr ImageAccessIntrList imageLoadF
		{
			expr::ImageAccess::eImageLoad1DF,
			expr::ImageAccess::eImageLoad2DF,
			expr::ImageAccess::eImageLoad3DF,
			expr::ImageAccess::eImageLoadCubeF,
			expr::ImageAccess::eImageLoad2DRectF,
			expr::ImageAccess::eImageLoadBufferF,

			expr::ImageAccess::eImageLoad1DArrayF,
			expr::ImageAccess::eImageLoad2DArrayF,
			expr::ImageAccess::eImageLoadCubeArrayF,

			expr::ImageAccess::eImageLoad2DMSF,
			expr::ImageAccess::eImageLoad2DMSArrayF,
		};
		static constexpr ImageAccessIntrList imageStoreF
		{
			expr::ImageAccess::eImageStore1DF,
			expr::ImageAccess::eImageStore2DF,
			expr::ImageAccess::eImageStore3DF,
			expr::ImageAccess::eImageStoreCubeF,
			expr::ImageAccess::eImageStore2DRectF,
			expr::ImageAccess::eImageStoreBufferF,

			expr::ImageAccess::eImageStore1DArrayF,
			expr::ImageAccess::eImageStore2DArrayF,
			expr::ImageAccess::eImageStoreCubeArrayF,

			expr::ImageAccess::eImageStore2DMSF,
			expr::ImageAccess::eImageStore2DMSArrayF,
		};
		static constexpr ImageAccessIntrList imageAtomicAddF
		{
			expr::ImageAccess::eImageAtomicAdd1DF,
			expr::ImageAccess::eImageAtomicAdd2DF,
			expr::ImageAccess::eImageAtomicAdd3DF,
			expr::ImageAccess::eImageAtomicAddCubeF,
			expr::ImageAccess::eImageAtomicAdd2DRectF,
			expr::ImageAccess::eImageAtomicAddBufferF,

			expr::ImageAccess::eImageAtomicAdd1DArrayF,
			expr::ImageAccess::eImageAtomicAdd2DArrayF,
			expr::ImageAccess::eImageAtomicAddCubeArrayF,

			expr::ImageAccess::eImageAtomicAdd2DMSF,
			expr::ImageAccess::eImageAtomicAdd2DMSArrayF,
		};
		static constexpr ImageAccessIntrList imageAtomicExchangeF
		{
			expr::ImageAccess::eImageAtomicExchange1DF,
			expr::ImageAccess::eImageAtomicExchange2DF,
			expr::ImageAccess::eImageAtomicExchange3DF,
			expr::ImageAccess::eImageAtomicExchangeCubeF,
			expr::ImageAccess::eImageAtomicExchange2DRectF,
			expr::ImageAccess::eImageAtomicExchangeBufferF,

			expr::ImageAccess::eImageAtomicExchange1DArrayF,
			expr::ImageAccess::eImageAtomicExchange2DArrayF,
			expr::ImageAccess::eImageAtomicExchangeCubeArrayF,

			expr::ImageAccess::eImageAtomicExchange2DMSF,
			expr::ImageAccess::eImageAtomicExchange2DMSArrayF,
		};

		static constexpr ImageAccessIntrList imageSizeI
		{
			expr::ImageAccess::eImageSize1DI,
			expr::ImageAccess::eImageSize2DI,
			expr::ImageAccess::eImageSize3DI,
			expr::ImageAccess::eImageSizeCubeI,
			expr::ImageAccess::eImageSize2DRectI,
			expr::ImageAccess::eImageSizeBufferI,

			expr::ImageAccess::eImageSize1DArrayI,
			expr::ImageAccess::eImageSize2DArrayI,
			expr::ImageAccess::eImageSizeCubeArrayI,

			expr::ImageAccess::eImageSize2DMSI,
			expr::ImageAccess::eImageSize2DMSArrayI,
		};
		static constexpr ImageAccessIntrList imageSamplesI
		{
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,

			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,

			expr::ImageAccess::eImageSamples2DMSI,
			expr::ImageAccess::eImageSamples2DMSArrayI,
		};
		static constexpr ImageAccessIntrList imageLoadI
		{
			expr::ImageAccess::eImageLoad1DI,
			expr::ImageAccess::eImageLoad2DI,
			expr::ImageAccess::eImageLoad3DI,
			expr::ImageAccess::eImageLoadCubeI,
			expr::ImageAccess::eImageLoad2DRectI,
			expr::ImageAccess::eImageLoadBufferI,

			expr::ImageAccess::eImageLoad1DArrayI,
			expr::ImageAccess::eImageLoad2DArrayI,
			expr::ImageAccess::eImageLoadCubeArrayI,

			expr::ImageAccess::eImageLoad2DMSI,
			expr::ImageAccess::eImageLoad2DMSArrayI,
		};
		static constexpr ImageAccessIntrList imageStoreI
		{
			expr::ImageAccess::eImageStore1DI,
			expr::ImageAccess::eImageStore2DI,
			expr::ImageAccess::eImageStore3DI,
			expr::ImageAccess::eImageStoreCubeI,
			expr::ImageAccess::eImageStore2DRectI,
			expr::ImageAccess::eImageStoreBufferI,

			expr::ImageAccess::eImageStore1DArrayI,
			expr::ImageAccess::eImageStore2DArrayI,
			expr::ImageAccess::eImageStoreCubeArrayI,

			expr::ImageAccess::eImageStore2DMSI,
			expr::ImageAccess::eImageStore2DMSArrayI,
		};
		static constexpr ImageAccessIntrList imageAtomicAddI
		{
			expr::ImageAccess::eImageAtomicAdd1DI,
			expr::ImageAccess::eImageAtomicAdd2DI,
			expr::ImageAccess::eImageAtomicAdd3DI,
			expr::ImageAccess::eImageAtomicAddCubeI,
			expr::ImageAccess::eImageAtomicAdd2DRectI,
			expr::ImageAccess::eImageAtomicAddBufferI,

			expr::ImageAccess::eImageAtomicAdd1DArrayI,
			expr::ImageAccess::eImageAtomicAdd2DArrayI,
			expr::ImageAccess::eImageAtomicAddCubeArrayI,

			expr::ImageAccess::eImageAtomicAdd2DMSI,
			expr::ImageAccess::eImageAtomicAdd2DMSArrayI,
		};
		static constexpr ImageAccessIntrList imageAtomicMinI
		{
			expr::ImageAccess::eImageAtomicMin1DI,
			expr::ImageAccess::eImageAtomicMin2DI,
			expr::ImageAccess::eImageAtomicMin3DI,
			expr::ImageAccess::eImageAtomicMinCubeI,
			expr::ImageAccess::eImageAtomicMin2DRectI,
			expr::ImageAccess::eImageAtomicMinBufferI,

			expr::ImageAccess::eImageAtomicMin1DArrayI,
			expr::ImageAccess::eImageAtomicMin2DArrayI,
			expr::ImageAccess::eImageAtomicMinCubeArrayI,

			expr::ImageAccess::eImageAtomicMin2DMSI,
			expr::ImageAccess::eImageAtomicMin2DMSArrayI,
		};
		static constexpr ImageAccessIntrList imageAtomicMaxI
		{
			expr::ImageAccess::eImageAtomicMax1DI,
			expr::ImageAccess::eImageAtomicMax2DI,
			expr::ImageAccess::eImageAtomicMax3DI,
			expr::ImageAccess::eImageAtomicMaxCubeI,
			expr::ImageAccess::eImageAtomicMax2DRectI,
			expr::ImageAccess::eImageAtomicMaxBufferI,

			expr::ImageAccess::eImageAtomicMax1DArrayI,
			expr::ImageAccess::eImageAtomicMax2DArrayI,
			expr::ImageAccess::eImageAtomicMaxCubeArrayI,

			expr::ImageAccess::eImageAtomicMax2DMSI,
			expr::ImageAccess::eImageAtomicMax2DMSArrayI,
		};
		static constexpr ImageAccessIntrList imageAtomicAndI
		{
			expr::ImageAccess::eImageAtomicAnd1DI,
			expr::ImageAccess::eImageAtomicAnd2DI,
			expr::ImageAccess::eImageAtomicAnd3DI,
			expr::ImageAccess::eImageAtomicAndCubeI,
			expr::ImageAccess::eImageAtomicAnd2DRectI,
			expr::ImageAccess::eImageAtomicAndBufferI,

			expr::ImageAccess::eImageAtomicAnd1DArrayI,
			expr::ImageAccess::eImageAtomicAnd2DArrayI,
			expr::ImageAccess::eImageAtomicAndCubeArrayI,

			expr::ImageAccess::eImageAtomicAnd2DMSI,
			expr::ImageAccess::eImageAtomicAnd2DMSArrayI,
		};
		static constexpr ImageAccessIntrList imageAtomicOrI
		{
			expr::ImageAccess::eImageAtomicOr1DI,
			expr::ImageAccess::eImageAtomicOr2DI,
			expr::ImageAccess::eImageAtomicOr3DI,
			expr::ImageAccess::eImageAtomicOrCubeI,
			expr::ImageAccess::eImageAtomicOr2DRectI,
			expr::ImageAccess::eImageAtomicOrBufferI,

			expr::ImageAccess::eImageAtomicOr1DArrayI,
			expr::ImageAccess::eImageAtomicOr2DArrayI,
			expr::ImageAccess::eImageAtomicOrCubeArrayI,

			expr::ImageAccess::eImageAtomicOr2DMSI,
			expr::ImageAccess::eImageAtomicOr2DMSArrayI,
		};
		static constexpr ImageAccessIntrList imageAtomicXorI
		{
			expr::ImageAccess::eImageAtomicXor1DI,
			expr::ImageAccess::eImageAtomicXor2DI,
			expr::ImageAccess::eImageAtomicXor3DI,
			expr::ImageAccess::eImageAtomicXorCubeI,
			expr::ImageAccess::eImageAtomicXor2DRectI,
			expr::ImageAccess::eImageAtomicXorBufferI,

			expr::ImageAccess::eImageAtomicXor1DArrayI,
			expr::ImageAccess::eImageAtomicXor2DArrayI,
			expr::ImageAccess::eImageAtomicXorCubeArrayI,

			expr::ImageAccess::eImageAtomicXor2DMSI,
			expr::ImageAccess::eImageAtomicXor2DMSArrayI,
		};
		static constexpr ImageAccessIntrList imageAtomicExchangeI
		{
			expr::ImageAccess::eImageAtomicExchange1DI,
			expr::ImageAccess::eImageAtomicExchange2DI,
			expr::ImageAccess::eImageAtomicExchange3DI,
			expr::ImageAccess::eImageAtomicExchangeCubeI,
			expr::ImageAccess::eImageAtomicExchange2DRectI,
			expr::ImageAccess::eImageAtomicExchangeBufferI,

			expr::ImageAccess::eImageAtomicExchange1DArrayI,
			expr::ImageAccess::eImageAtomicExchange2DArrayI,
			expr::ImageAccess::eImageAtomicExchangeCubeArrayI,

			expr::ImageAccess::eImageAtomicExchange2DMSI,
			expr::ImageAccess::eImageAtomicExchange2DMSArrayI,
		};
		static constexpr ImageAccessIntrList imageAtomicCompSwapI
		{
			expr::ImageAccess::eImageAtomicCompSwap1DI,
			expr::ImageAccess::eImageAtomicCompSwap2DI,
			expr::ImageAccess::eImageAtomicCompSwap3DI,
			expr::ImageAccess::eImageAtomicCompSwapCubeI,
			expr::ImageAccess::eImageAtomicCompSwap2DRectI,
			expr::ImageAccess::eImageAtomicCompSwapBufferI,

			expr::ImageAccess::eImageAtomicCompSwap1DArrayI,
			expr::ImageAccess::eImageAtomicCompSwap2DArrayI,
			expr::ImageAccess::eImageAtomicCompSwapCubeArrayI,

			expr::ImageAccess::eImageAtomicCompSwap2DMSI,
			expr::ImageAccess::eImageAtomicCompSwap2DMSArrayI,
		};

		static constexpr ImageAccessIntrList imageSizeU
		{
			expr::ImageAccess::eImageSize1DU,
			expr::ImageAccess::eImageSize2DU,
			expr::ImageAccess::eImageSize3DU,
			expr::ImageAccess::eImageSizeCubeU,
			expr::ImageAccess::eImageSize2DRectU,
			expr::ImageAccess::eImageSizeBufferU,

			expr::ImageAccess::eImageSize1DArrayU,
			expr::ImageAccess::eImageSize2DArrayU,
			expr::ImageAccess::eImageSizeCubeArrayU,

			expr::ImageAccess::eImageSize2DMSU,
			expr::ImageAccess::eImageSize2DMSArrayU,
		};
		static constexpr ImageAccessIntrList imageSamplesU
		{
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,

			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,
			expr::ImageAccess::eInvalid,

			expr::ImageAccess::eImageSamples2DMSU,
			expr::ImageAccess::eImageSamples2DMSArrayU,
		};
		static constexpr ImageAccessIntrList imageLoadU
		{
			expr::ImageAccess::eImageLoad1DU,
			expr::ImageAccess::eImageLoad2DU,
			expr::ImageAccess::eImageLoad3DU,
			expr::ImageAccess::eImageLoadCubeU,
			expr::ImageAccess::eImageLoad2DRectU,
			expr::ImageAccess::eImageLoadBufferU,

			expr::ImageAccess::eImageLoad1DArrayU,
			expr::ImageAccess::eImageLoad2DArrayU,
			expr::ImageAccess::eImageLoadCubeArrayU,

			expr::ImageAccess::eImageLoad2DMSU,
			expr::ImageAccess::eImageLoad2DMSArrayU,
		};
		static constexpr ImageAccessIntrList imageStoreU
		{
			expr::ImageAccess::eImageStore1DU,
			expr::ImageAccess::eImageStore2DU,
			expr::ImageAccess::eImageStore3DU,
			expr::ImageAccess::eImageStoreCubeU,
			expr::ImageAccess::eImageStore2DRectU,
			expr::ImageAccess::eImageStoreBufferU,

			expr::ImageAccess::eImageStore1DArrayU,
			expr::ImageAccess::eImageStore2DArrayU,
			expr::ImageAccess::eImageStoreCubeArrayU,

			expr::ImageAccess::eImageStore2DMSU,
			expr::ImageAccess::eImageStore2DMSArrayU,
		};
		static constexpr ImageAccessIntrList imageAtomicAddU
		{
			expr::ImageAccess::eImageAtomicAdd1DU,
			expr::ImageAccess::eImageAtomicAdd2DU,
			expr::ImageAccess::eImageAtomicAdd3DU,
			expr::ImageAccess::eImageAtomicAddCubeU,
			expr::ImageAccess::eImageAtomicAdd2DRectU,
			expr::ImageAccess::eImageAtomicAddBufferU,

			expr::ImageAccess::eImageAtomicAdd1DArrayU,
			expr::ImageAccess::eImageAtomicAdd2DArrayU,
			expr::ImageAccess::eImageAtomicAddCubeArrayU,

			expr::ImageAccess::eImageAtomicAdd2DMSU,
			expr::ImageAccess::eImageAtomicAdd2DMSArrayU,
		};
		static constexpr ImageAccessIntrList imageAtomicMinU
		{
			expr::ImageAccess::eImageAtomicMin1DU,
			expr::ImageAccess::eImageAtomicMin2DU,
			expr::ImageAccess::eImageAtomicMin3DU,
			expr::ImageAccess::eImageAtomicMinCubeU,
			expr::ImageAccess::eImageAtomicMin2DRectU,
			expr::ImageAccess::eImageAtomicMinBufferU,

			expr::ImageAccess::eImageAtomicMin1DArrayU,
			expr::ImageAccess::eImageAtomicMin2DArrayU,
			expr::ImageAccess::eImageAtomicMinCubeArrayU,

			expr::ImageAccess::eImageAtomicMin2DMSU,
			expr::ImageAccess::eImageAtomicMin2DMSArrayU,
		};
		static constexpr ImageAccessIntrList imageAtomicMaxU
		{
			expr::ImageAccess::eImageAtomicMax1DU,
			expr::ImageAccess::eImageAtomicMax2DU,
			expr::ImageAccess::eImageAtomicMax3DU,
			expr::ImageAccess::eImageAtomicMaxCubeU,
			expr::ImageAccess::eImageAtomicMax2DRectU,
			expr::ImageAccess::eImageAtomicMaxBufferU,

			expr::ImageAccess::eImageAtomicMax1DArrayU,
			expr::ImageAccess::eImageAtomicMax2DArrayU,
			expr::ImageAccess::eImageAtomicMaxCubeArrayU,
			expr::ImageAccess::eImageAtomicMax2DMSU,

			expr::ImageAccess::eImageAtomicMax2DMSArrayU,
		};
		static constexpr ImageAccessIntrList imageAtomicAndU
		{
			expr::ImageAccess::eImageAtomicAnd1DU,
			expr::ImageAccess::eImageAtomicAnd2DU,
			expr::ImageAccess::eImageAtomicAnd3DU,
			expr::ImageAccess::eImageAtomicAndCubeU,
			expr::ImageAccess::eImageAtomicAnd2DRectU,
			expr::ImageAccess::eImageAtomicAndBufferU,

			expr::ImageAccess::eImageAtomicAnd1DArrayU,
			expr::ImageAccess::eImageAtomicAnd2DArrayU,
			expr::ImageAccess::eImageAtomicAndCubeArrayU,

			expr::ImageAccess::eImageAtomicAnd2DMSU,
			expr::ImageAccess::eImageAtomicAnd2DMSArrayU,
		};
		static constexpr ImageAccessIntrList imageAtomicOrU
		{
			expr::ImageAccess::eImageAtomicOr1DU,
			expr::ImageAccess::eImageAtomicOr2DU,
			expr::ImageAccess::eImageAtomicOr3DU,
			expr::ImageAccess::eImageAtomicOrCubeU,
			expr::ImageAccess::eImageAtomicOr2DRectU,
			expr::ImageAccess::eImageAtomicOrBufferU,

			expr::ImageAccess::eImageAtomicOr1DArrayU,
			expr::ImageAccess::eImageAtomicOr2DArrayU,
			expr::ImageAccess::eImageAtomicOrCubeArrayU,

			expr::ImageAccess::eImageAtomicOr2DMSU,
			expr::ImageAccess::eImageAtomicOr2DMSArrayU,
		};
		static constexpr ImageAccessIntrList imageAtomicXorU
		{
			expr::ImageAccess::eImageAtomicXor1DU,
			expr::ImageAccess::eImageAtomicXor2DU,
			expr::ImageAccess::eImageAtomicXor3DU,
			expr::ImageAccess::eImageAtomicXorCubeU,
			expr::ImageAccess::eImageAtomicXor2DRectU,
			expr::ImageAccess::eImageAtomicXorBufferU,

			expr::ImageAccess::eImageAtomicXor1DArrayU,
			expr::ImageAccess::eImageAtomicXor2DArrayU,
			expr::ImageAccess::eImageAtomicXorCubeArrayU,

			expr::ImageAccess::eImageAtomicXor2DMSU,
			expr::ImageAccess::eImageAtomicXor2DMSArrayU,
		};
		static constexpr ImageAccessIntrList imageAtomicExchangeU
		{
			expr::ImageAccess::eImageAtomicExchange1DU,
			expr::ImageAccess::eImageAtomicExchange2DU,
			expr::ImageAccess::eImageAtomicExchange3DU,
			expr::ImageAccess::eImageAtomicExchangeCubeU,
			expr::ImageAccess::eImageAtomicExchange2DRectU,
			expr::ImageAccess::eImageAtomicExchangeBufferU,

			expr::ImageAccess::eImageAtomicExchange1DArrayU,
			expr::ImageAccess::eImageAtomicExchange2DArrayU,
			expr::ImageAccess::eImageAtomicExchangeCubeArrayU,

			expr::ImageAccess::eImageAtomicExchange2DMSU,
			expr::ImageAccess::eImageAtomicExchange2DMSArrayU,
		};
		static constexpr ImageAccessIntrList imageAtomicCompSwapU
		{
			expr::ImageAccess::eImageAtomicCompSwap1DU,
			expr::ImageAccess::eImageAtomicCompSwap2DU,
			expr::ImageAccess::eImageAtomicCompSwap3DU,
			expr::ImageAccess::eImageAtomicCompSwapCubeU,
			expr::ImageAccess::eImageAtomicCompSwap2DRectU,
			expr::ImageAccess::eImageAtomicCompSwapBufferU,

			expr::ImageAccess::eImageAtomicCompSwap1DArrayU,
			expr::ImageAccess::eImageAtomicCompSwap2DArrayU,
			expr::ImageAccess::eImageAtomicCompSwapCubeArrayU,

			expr::ImageAccess::eImageAtomicCompSwap2DMSU,
			expr::ImageAccess::eImageAtomicCompSwap2DMSArrayU,
		};
	}

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eUnknown >
	{
		using SampleType = Vec4;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreF;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba32f >
	{
		using SampleType = Vec4;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 128u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreF;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba16f >
	{
		using SampleType = Vec4;
		using FetchType = HVec4;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreF;
		static constexpr img::ImageAccessIntrList const & imageAtomicAdd = img::imageAtomicAddF;
		static constexpr img::ImageAccessIntrList const & imageAtomicExchange = img::imageAtomicExchangeF;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg32f >
	{
		using SampleType = Vec2;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreF;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg16f >
	{
		using SampleType = Vec2;
		using FetchType = HVec2;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreF;
		static constexpr img::ImageAccessIntrList const & imageAtomicAdd = img::imageAtomicAddF;
		static constexpr img::ImageAccessIntrList const & imageAtomicExchange = img::imageAtomicExchangeF;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR32f >
	{
		using SampleType = Float;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 32u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreF;
		static constexpr img::ImageAccessIntrList const & imageAtomicAdd = img::imageAtomicAddF;
		static constexpr img::ImageAccessIntrList const & imageAtomicExchange = img::imageAtomicExchangeF;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR16f >
	{
		using SampleType = Float;
		using FetchType = Half;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 16u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreF;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba32i >
	{
		using SampleType = IVec4;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 128u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba16i >
	{
		using SampleType = IVec4;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba8i >
	{
		using SampleType = IVec4;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg32i >
	{
		using SampleType = IVec2;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg16i >
	{
		using SampleType = IVec2;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg8i >
	{
		using SampleType = IVec2;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 16u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR32i >
	{
		using SampleType = Int;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 32u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreI;
		static constexpr img::ImageAccessIntrList const & imageAtomicAdd = img::imageAtomicAddI;
		static constexpr img::ImageAccessIntrList const & imageAtomicMin = img::imageAtomicMinI;
		static constexpr img::ImageAccessIntrList const & imageAtomicMax = img::imageAtomicMaxI;
		static constexpr img::ImageAccessIntrList const & imageAtomicAnd = img::imageAtomicAndI;
		static constexpr img::ImageAccessIntrList const & imageAtomicOr = img::imageAtomicOrI;
		static constexpr img::ImageAccessIntrList const & imageAtomicXor = img::imageAtomicXorI;
		static constexpr img::ImageAccessIntrList const & imageAtomicExchange = img::imageAtomicExchangeI;
		static constexpr img::ImageAccessIntrList const & imageAtomicCompSwap = img::imageAtomicCompSwapI;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR16i >
	{
		using SampleType = Int;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 16u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR8i >
	{
		using SampleType = Int;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 8u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba32u >
	{
		using SampleType = UVec4;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 128u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba16u >
	{
		using SampleType = UVec4;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba8u >
	{
		using SampleType = UVec4;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg32u >
	{
		using SampleType = UVec2;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg16u >
	{
		using SampleType = UVec2;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg8u >
	{
		using SampleType = UVec2;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 16u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR32u >
	{
		using SampleType = UInt;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 32u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreU;
		static constexpr img::ImageAccessIntrList const & imageAtomicAdd = img::imageAtomicAddU;
		static constexpr img::ImageAccessIntrList const & imageAtomicMin = img::imageAtomicMinU;
		static constexpr img::ImageAccessIntrList const & imageAtomicMax = img::imageAtomicMaxU;
		static constexpr img::ImageAccessIntrList const & imageAtomicAnd = img::imageAtomicAndU;
		static constexpr img::ImageAccessIntrList const & imageAtomicOr = img::imageAtomicOrU;
		static constexpr img::ImageAccessIntrList const & imageAtomicXor = img::imageAtomicXorU;
		static constexpr img::ImageAccessIntrList const & imageAtomicExchange = img::imageAtomicExchangeU;
		static constexpr img::ImageAccessIntrList const & imageAtomicCompSwap = img::imageAtomicCompSwapU;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR16u >
	{
		using SampleType = UInt;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 16u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR8u >
	{
		using SampleType = UInt;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 8u;
		static constexpr img::ImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::ImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::ImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::ImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	//*****************************************************************************************

	template<>
	struct ImageCoordsGetterT< type::ImageDim::e1D, false >
	{
		using CoordsType = Int;
		using SizeType = Int;
	};

	template<>
	struct ImageCoordsGetterT< type::ImageDim::e2D, false >
	{
		using CoordsType = IVec2;
		using SizeType = IVec2;
	};

	template<>
	struct ImageCoordsGetterT< type::ImageDim::e3D, false >
	{
		using CoordsType = IVec3;
		using SizeType = IVec3;
	};

	template<>
	struct ImageCoordsGetterT< type::ImageDim::eCube, false >
	{
		using CoordsType = IVec3;
		using SizeType = IVec2;
	};

	template<>
	struct ImageCoordsGetterT< type::ImageDim::eBuffer, false >
	{
		using CoordsType = Int;
		using SizeType = Int;
	};

	template<>
	struct ImageCoordsGetterT< type::ImageDim::e1D, true >
	{
		using CoordsType = IVec2;
		using SizeType = IVec2;
	};

	template<>
	struct ImageCoordsGetterT< type::ImageDim::e2D, true >
	{
		using CoordsType = IVec3;
		using SizeType = IVec3;
	};

	template<>
	struct ImageCoordsGetterT< type::ImageDim::eCube, true >
	{
		using CoordsType = IVec3;
		using SizeType = IVec3;
	};

	namespace img
	{
		//*****************************************************************************************

		template< typename ReturnT
			, type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT
			, expr::ImageAccess ImageAccessT
			, typename ... ParamsT >
		MaybeOptional< ReturnT > writeImageAccessCall( MaybeOptional< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > > const & image
			, MaybeOptional< ParamsT > const & ... params )
		{
			static_assert( ImageAccessT != expr::ImageAccess::eInvalid );
			static_assert( ImageAccessT != expr::ImageAccess::eUndefined );

			auto & cache = findTypesCache( image, params... );

			if ( isAnyOptional( image, params... ) )
			{
				return Optional< ReturnT >{ findShader( image, params... )
					, expr::makeImageAccessCall( ReturnT::makeType( cache )
						, ImageAccessT
						, makeExpr( image )
						, makeExpr( params )... )
					, areOptionalEnabled( image, params... ) };
			}

			return ReturnT{ findShader( image, params... )
				, expr::makeImageAccessCall( ReturnT::makeType( cache )
					, ImageAccessT
					, makeExpr( image )
					, makeExpr( params )... ) };
		}

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT
			, expr::ImageAccess ImageAccessT
			, typename ... ParamsT >
		void writeVoidImageAccessCall( MaybeOptional< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > > const & image
			, MaybeOptional< ParamsT > const & ... params )
		{
			static_assert( ImageAccessT != expr::ImageAccess::eInvalid );
			static_assert( ImageAccessT != expr::ImageAccess::eUndefined );

			auto & cache = findTypesCache( image, params... );

			if ( ( !isAnyOptional( image, params... ) )
				|| areOptionalEnabled( image, params... ) )
			{
				expr::makeImageAccessCall( Void::makeType( cache )
					, ImageAccessT
					, makeExpr( image )
					, makeExpr( params )... );
			}
		}

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImgSizeFuncT
		{
			using SizeT = ImageSizeT< DimT, ArrayedT >;

			MaybeOptional< SizeT > getSize()const
			{
				return writeImageAccessCall< SizeT, FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
					, ImageFormatTraitsT< FormatT >::imageSize[getImgArrayIndex< DimT, ArrayedT, MsT >()] >( get() );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgSamplesFuncT
		{
			MaybeOptional< Int > getSamples()const
			{
				return writeImageAccessCall< Int, FormatT, AccessT, DimT, ArrayedT, DepthT, true
					, ImageFormatTraitsT< FormatT >::imageSamples[getImgArrayIndex< DimT, ArrayedT, true >()] >( get() );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgLoadFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > load( MaybeOptional< CoordsT > const & coord )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, false
					, ImageFormatTraitsT< FormatT >::imageLoad[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
					, coord );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsLoadFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > load( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, true
					, ImageFormatTraitsT< FormatT >::imageLoad[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
					, coord
					, sample );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgStoreFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			void store( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				writeVoidImageAccessCall<  FormatT, AccessT, DimT, ArrayedT, DepthT, false
					, ImageFormatTraitsT< FormatT >::imageStore[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsStoreFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			void store( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				writeVoidImageAccessCall<  FormatT, AccessT, DimT, ArrayedT, DepthT, true
					, ImageFormatTraitsT< FormatT >::imageStore[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicAddFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicAdd( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, false
					, ImageFormatTraitsT< FormatT >::imageAtomicAdd[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicAddFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicAdd( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, true
					, ImageFormatTraitsT< FormatT >::imageAtomicAdd[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicMinFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicMin( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, false
					, ImageFormatTraitsT< FormatT >::imageAtomicMin[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicMinFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicMin( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, true
					, ImageFormatTraitsT< FormatT >::imageAtomicMin[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicMaxFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicMax( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, false
					, ImageFormatTraitsT< FormatT >::imageAtomicMax[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicMaxFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicMax( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, true
					, ImageFormatTraitsT< FormatT >::imageAtomicMax[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicAndFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicAnd( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, false
					, ImageFormatTraitsT< FormatT >::imageAtomicAnd[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicAndFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicAnd( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, true
					, ImageFormatTraitsT< FormatT >::imageAtomicAnd[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicOrFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicOr( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, false
					, ImageFormatTraitsT< FormatT >::imageAtomicOr[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicOrFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicOr( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, true
					, ImageFormatTraitsT< FormatT >::imageAtomicOr[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicXorFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicXor( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, false
					, ImageFormatTraitsT< FormatT >::imageAtomicXor[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicXorFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicXor( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, true
					, ImageFormatTraitsT< FormatT >::imageAtomicXor[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicExchangeFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicExchange( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, false
					, ImageFormatTraitsT< FormatT >::imageAtomicExchange[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicExchangeFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicExchange( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, true
					, ImageFormatTraitsT< FormatT >::imageAtomicExchange[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicCompSwapFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicCompSwap( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & compare
				, MaybeOptional< FetchT > const & data )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, false
					, ImageFormatTraitsT< FormatT >::imageAtomicCompSwap[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, compare
						, data );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicCompSwapFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< FetchT > atomicCompSwap( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & compare
				, MaybeOptional< FetchT > const & data )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, DepthT, true
					, ImageFormatTraitsT< FormatT >::imageAtomicCompSwap[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, compare
						, data );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( !isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( !isReadableV< AccessT > )
				&& ( isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( !isSingleInt32FormatV< FormatT > && !isFloatFormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isFloatFormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isSingleInt32FormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicMinFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicMaxFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicAndFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicOrFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicXorFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicCompSwapFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( !isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( !isReadableV< AccessT > )
				&& ( isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( !isSingleInt32FormatV< FormatT > && !isFloatFormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isFloatFormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isSingleInt32FormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicMinFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicMaxFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicAndFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicOrFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicXorFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicCompSwapFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*****************************************************************************************
	}

	template< typename T >
	Image & Image::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		auto & shader = *findShader( *this, rhs );
		addStmt( shader
			, makeSimple( makeAssign( getExpr()->getType()
				, makeExpr( shader, getExpr() )
				, makeExpr( shader, rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::ImageT( Shader * shader
		, expr::ExprPtr expr )
		: img::ImageFuncsT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >{ shader, std::move( expr ) }
	{
	}

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::ImageT( ImageT const & rhs )
		: img::ImageFuncsT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >{ rhs }
	{
	}

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	template< typename T >
	ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > & ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::operator=( T const & rhs )
	{
		img::ImageFuncsT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::operator=( rhs );
		return *this;
	}

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	type::ImageConfiguration ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::makeConfig()
	{
		return type::makeConfig< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >( false );
	}

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline type::TypePtr ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::makeType( type::TypesCache & cache )
	{
		return cache.getImage( makeConfig() );
	}

	//*****************************************************************************************
}
