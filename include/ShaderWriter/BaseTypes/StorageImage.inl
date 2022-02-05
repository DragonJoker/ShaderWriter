/*
See LICENSE file in root folder
*/
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
		using StorateImageAccessIntrList = std::array< expr::ImageAccess, NonMsImgCount + ArrayImgCount >;

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

		static constexpr StorateImageAccessIntrList imageSizeF
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
		static constexpr StorateImageAccessIntrList imageSamplesF
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
		static constexpr StorateImageAccessIntrList imageLoadF
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
		static constexpr StorateImageAccessIntrList imageStoreF
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
		static constexpr StorateImageAccessIntrList imageAtomicAddF
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
		static constexpr StorateImageAccessIntrList imageAtomicExchangeF
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

		static constexpr StorateImageAccessIntrList imageSizeI
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
		static constexpr StorateImageAccessIntrList imageSamplesI
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
		static constexpr StorateImageAccessIntrList imageLoadI
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
		static constexpr StorateImageAccessIntrList imageStoreI
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
		static constexpr StorateImageAccessIntrList imageAtomicAddI
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
		static constexpr StorateImageAccessIntrList imageAtomicMinI
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
		static constexpr StorateImageAccessIntrList imageAtomicMaxI
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
		static constexpr StorateImageAccessIntrList imageAtomicAndI
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
		static constexpr StorateImageAccessIntrList imageAtomicOrI
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
		static constexpr StorateImageAccessIntrList imageAtomicXorI
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
		static constexpr StorateImageAccessIntrList imageAtomicExchangeI
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
		static constexpr StorateImageAccessIntrList imageAtomicCompSwapI
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

		static constexpr StorateImageAccessIntrList imageSizeU
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
		static constexpr StorateImageAccessIntrList imageSamplesU
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
		static constexpr StorateImageAccessIntrList imageLoadU
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
		static constexpr StorateImageAccessIntrList imageStoreU
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
		static constexpr StorateImageAccessIntrList imageAtomicAddU
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
		static constexpr StorateImageAccessIntrList imageAtomicMinU
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
		static constexpr StorateImageAccessIntrList imageAtomicMaxU
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
		static constexpr StorateImageAccessIntrList imageAtomicAndU
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
		static constexpr StorateImageAccessIntrList imageAtomicOrU
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
		static constexpr StorateImageAccessIntrList imageAtomicXorU
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
		static constexpr StorateImageAccessIntrList imageAtomicExchangeU
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
		static constexpr StorateImageAccessIntrList imageAtomicCompSwapU
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
	struct StorageImageFormatTraitsT< type::ImageFormat::eUnknown >
		: public ImageFormatTraitsT< type::ImageFormat::eUnknown >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba32f >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba32f >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba16f >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba16f >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg32f >
		: public ImageFormatTraitsT< type::ImageFormat::eRg32f >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg16f >
		: public ImageFormatTraitsT< type::ImageFormat::eRg16f >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreF;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicAdd = img::imageAtomicAddF;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicExchange = img::imageAtomicExchangeF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR32f >
		: public ImageFormatTraitsT< type::ImageFormat::eR32f >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreF;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicAdd = img::imageAtomicAddF;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicExchange = img::imageAtomicExchangeF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR16f >
		: public ImageFormatTraitsT< type::ImageFormat::eR16f >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeF;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesF;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadF;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba32i >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba32i >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba16i >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba16i >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba8i >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba8i >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg32i >
		: public ImageFormatTraitsT< type::ImageFormat::eRg32i >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg16i >
		: public ImageFormatTraitsT< type::ImageFormat::eRg16i >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg8i >
		: public ImageFormatTraitsT< type::ImageFormat::eRg8i >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR32i >
		: public ImageFormatTraitsT< type::ImageFormat::eR32i >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreI;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicAdd = img::imageAtomicAddI;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicMin = img::imageAtomicMinI;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicMax = img::imageAtomicMaxI;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicAnd = img::imageAtomicAndI;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicOr = img::imageAtomicOrI;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicXor = img::imageAtomicXorI;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicExchange = img::imageAtomicExchangeI;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicCompSwap = img::imageAtomicCompSwapI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR16i >
		: public ImageFormatTraitsT< type::ImageFormat::eR16i >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR8i >
		: public ImageFormatTraitsT< type::ImageFormat::eR8i >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeI;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesI;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadI;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba32u >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba32u >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba16u >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba16u >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba8u >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba8u >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg32u >
		: public ImageFormatTraitsT< type::ImageFormat::eRg32u >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg16u >
		: public ImageFormatTraitsT< type::ImageFormat::eRg16u >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg8u >
		: public ImageFormatTraitsT< type::ImageFormat::eRg8u >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR32u >
		: public ImageFormatTraitsT< type::ImageFormat::eR32u >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreU;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicAdd = img::imageAtomicAddU;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicMin = img::imageAtomicMinU;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicMax = img::imageAtomicMaxU;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicAnd = img::imageAtomicAndU;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicOr = img::imageAtomicOrU;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicXor = img::imageAtomicXorU;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicExchange = img::imageAtomicExchangeU;
		static constexpr img::StorateImageAccessIntrList const & imageAtomicCompSwap = img::imageAtomicCompSwapU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR16u >
		: public ImageFormatTraitsT< type::ImageFormat::eR16u >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR8u >
		: public ImageFormatTraitsT< type::ImageFormat::eR8u >
	{
		static constexpr img::StorateImageAccessIntrList const & imageSize = img::imageSizeU;
		static constexpr img::StorateImageAccessIntrList const & imageSamples = img::imageSamplesU;
		static constexpr img::StorateImageAccessIntrList const & imageLoad = img::imageLoadU;
		static constexpr img::StorateImageAccessIntrList const & imageStore = img::imageStoreU;
	};

	//*****************************************************************************************

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::e1D, false >
	{
		using CoordsType = Int;
		using SizeType = Int;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::e2D, false >
	{
		using CoordsType = IVec2;
		using SizeType = IVec2;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::e3D, false >
	{
		using CoordsType = IVec3;
		using SizeType = IVec3;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::eCube, false >
	{
		using CoordsType = IVec3;
		using SizeType = IVec2;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::eBuffer, false >
	{
		using CoordsType = Int;
		using SizeType = Int;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::e1D, true >
	{
		using CoordsType = IVec2;
		using SizeType = IVec2;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::e2D, true >
	{
		using CoordsType = IVec3;
		using SizeType = IVec3;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::eCube, true >
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
			, bool MsT
			, expr::ImageAccess ImageAccessT
			, typename ... ParamsT >
		ReturnWrapperT< ReturnT > writeImageAccessCall( StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > const & image
			, ParamsT const & ... params )
		{
			static_assert( ImageAccessT != expr::ImageAccess::eInvalid );
			static_assert( ImageAccessT != expr::ImageAccess::eUndefined );

			auto & cache = findTypesCache( image, params... );
			return ReturnWrapperT< ReturnT >{ findWriterMandat( image, params... )
				, expr::makeImageAccessCall( ReturnT::makeType( cache )
					, ImageAccessT
					, makeExpr( image )
					, makeExpr( params )... )
				, areOptionalEnabled( image, params... ) };
		}

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, expr::ImageAccess ImageAccessT
			, typename ... ParamsT >
		void writeVoidImageAccessCall( StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > const & image
			, ParamsT const & ... params )
		{
			static_assert( ImageAccessT != expr::ImageAccess::eInvalid );
			static_assert( ImageAccessT != expr::ImageAccess::eUndefined );

			auto & writer = findWriterMandat( image, params... );
			auto & cache = findTypesCache( writer );

			if ( areOptionalEnabled( image, params... ) )
			{
				addStmt( writer
					, makeSimple( expr::makeImageAccessCall( Void::makeType( cache )
						, ImageAccessT
						, makeExpr( image )
						, makeExpr( params )... ) ) );
			}
		}

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct ImgSizeFuncT
		{
			using SizeT = StorageImageSizeT< DimT, ArrayedT >;

			auto getSize()const
			{
				return writeImageAccessCall< SizeT, FormatT, AccessT, DimT, ArrayedT, MsT
					, StorageImageFormatTraitsT< FormatT >::imageSize[getImgArrayIndex< DimT, ArrayedT, MsT >()] >( get() );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgSamplesFuncT
		{
			auto getSamples()const
			{
				return writeImageAccessCall< Int, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageSamples[getImgArrayIndex< DimT, ArrayedT, true >()] >( get() );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgLoadFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto load( CoordsT const & coord )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageLoad[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
					, coord );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsLoadFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto load( CoordsT const & coord
				, Int const & sample )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageLoad[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
					, coord
					, sample );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgStoreFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			void store( CoordsT const & coord
				, FetchT const & value )const
			{
				writeVoidImageAccessCall<  FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageStore[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsStoreFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			void store( CoordsT const & coord
				, Int const & sample
				, FetchT const & value )const
			{
				writeVoidImageAccessCall<  FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageStore[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicAddFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicAdd( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicAdd[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicAddFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicAdd( CoordsT const & coord
				, Int const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicAdd[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicMinFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicMin( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicMin[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicMinFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicMin( CoordsT const & coord
				, Int const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicMin[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicMaxFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicMax( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicMax[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicMaxFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicMax( CoordsT const & coord
				, Int const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicMax[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicAndFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicAnd( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicAnd[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicAndFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicAnd( CoordsT const & coord
				, Int const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicAnd[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicOrFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicOr( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicOr[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicOrFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicOr( CoordsT const & coord
				, Int const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicOr[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicXorFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicXor( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicXor[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicXorFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicXor( CoordsT const & coord
				, Int const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicXor[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicExchangeFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicExchange( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicExchange[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicExchangeFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicExchange( CoordsT const & coord
				, Int const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicExchange[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicCompSwapFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicCompSwap( CoordsT const & coord
				, FetchT const & compare
				, FetchT const & data )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicCompSwap[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, compare
						, data );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicCompSwapFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicCompSwap( CoordsT const & coord
				, Int const & sample
				, FetchT const & compare
				, FetchT const & data )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicCompSwap[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, compare
						, data );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( !isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( !isReadableV< AccessT > )
				&& ( isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( !isSingleInt32FormatV< FormatT > && !isFloatFormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		template< type::ImageFormat FormatT >
		struct IsAtomicFloatFormat : std::false_type
		{
		};

		template<>
		struct IsAtomicFloatFormat< type::ImageFormat::eR32f > : std::true_type
		{
		};

		template< type::ImageFormat FormatT >
		static constexpr bool isAtomicFloatFormatV = IsAtomicFloatFormat< FormatT >::value;

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isAtomicFloatFormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isFloatFormatV< FormatT > )
				&& ( !isAtomicFloatFormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isSingleInt32FormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicMinFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicMaxFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicAndFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicOrFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicXorFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicCompSwapFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( !isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( !isReadableV< AccessT > )
				&& ( isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( !isSingleInt32FormatV< FormatT > && !isFloatFormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isFloatFormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isSingleInt32FormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicMinFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicMaxFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicAndFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicOrFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicXorFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicCompSwapFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*****************************************************************************************
	}

	template< typename T >
	StorageImage & StorageImage::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		auto & shader = findWriterMandat( *this, rhs );

		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( shader
				, makeSimple( makeAssign( getExpr()->getType()
					, makeExpr( shader, getExpr() )
					, makeExpr( shader, rhs ) ) ) );
		}

		return *this;
	}

	//*****************************************************************************************

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT >::StorageImageT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: img::StorageImageFuncsT< FormatT, AccessT, DimT, ArrayedT, MsT >{ writer, std::move( expr ), enabled }
	{
	}

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	template< typename T >
	StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > & StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT >::operator=( T const & rhs )
	{
		img::StorageImageFuncsT< FormatT, AccessT, DimT, ArrayedT, MsT >::operator=( rhs );
		return *this;
	}

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	type::ImageConfiguration StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT >::makeConfig()
	{
		return type::makeConfig< FormatT, AccessT, DimT, ArrayedT, MsT >( false );
	}

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline type::TypePtr StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT >::makeType( type::TypesCache & cache )
	{
		return cache.getImage( makeConfig() );
	}

	//*****************************************************************************************
}
